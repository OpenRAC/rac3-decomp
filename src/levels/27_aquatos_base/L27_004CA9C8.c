#include "common.h"

/* localdecomp:start func_L27_004CA9C8 */
/* func_L27_004CA9C8: the hero's per-frame state machine, small variant (family A1 root,
   docs/contributing/large-function-families.md), a 178-way switch on the state at
   D_001A4BE0+0x25C4.  21992 bytes, one function, one prologue/epilogue.

   PROVENANCE.  Ported from the matched A1 root src/levels/08_aquatos/L08_004D6580.c (which
   matches retail byte for byte) by aligning the two level-27/level-08 retail bodies: they are
   0.991 the same instruction stream (retail-to-retail: L27 has 44 instructions L08 lacks and
   lacks 50 L08 has).  tools/align.py + tools/relmap.py in the scratch directory produced the
   name map; tools/port.py + tools/port2.py applied it.  What had to change beyond the names:

   - Group 0x00/0x01/... (0x4CAA48): L08 starts it with an `if (b[0x25EA]) func_004BBAE0(0xF,0x1E);`
     that level 27 does not have.
   - Case 0x02/0x75 (0x4CD378): L08 starts it with the `flag`/`b[0x1476]`/`b[0x25EA]` lead-in
     (0xB0 bytes) that level 27 does not have; level 27 starts at the `h[0x1434]` test.
   - Cases 0x6A (0x4CF108) and 0x7D (0x4CF180) exist only in level 27; both were written from
     the level-27 asm in the surrounding style `(s32)D_001A4BE0 + 0xF0`.
   - Two data symbols resolve to another base than the address splat prints at the use site:
     the hero tunables array is D_001DBD84[] (the `%hi` at the reference is 8 higher), and the
     level-27 object that L08 names D_L08_001E1D58 is D_001E1698 (its uses are +0x368 / -0x368
     around it, i.e. 0x001E1A00 and 0x001E1688).

   BUILD NEEDS (repo files, not edited here):
   - config/levels/text_parts.txt:1632 needs "@ps2as -mvu0-use-vf0-vf2" added (whole file):
     @ps2as because retail builds every float constant inline lui/ori/mtc1 and leaves the $gp
     loads in delay slots (the default assembler gives 4959 diff, the GNU as 4960); the VU0 flag
     because include/vu0.h's helpers use "j" (without it cc1 fails: vf17 spilled for VU_REGS).
   - config/levels/divs_nops.txt:38 currently reads "2 0 2 0 0 2 0 1 0 2 0 2" and must read
     "2 0 2 0 0 2 0 0 0 2 0 2": the 8th div.s follows an mtc1 directly, and Ps2EeAs adds that
     mtc1-hazard nop itself (Matching-Patterns, "div.s right after mtc1 under @ps2as"), so the
     table entry is retail's count (1) minus one.  With the wrong entry the check reports 3210
     diff through a one-word shift from 0x4CB390 on.
   - include/vu0.h: qzero() 19 times (the `sq $0` stores), fabs_asm() 19 times (every abs.s),
     vec_sub_ab/ba and vec_add_ab/ba (28 VU0 triples).  No other asm, no volatile, no #define.
   - The level's hero tunables are one small-data array, D_001DBD84[] (docs/build/globals.md).
   Notes carried from the L08 file (still true here):
   - Callee prototypes with the float parameters where the original had them.  The EABI gives
     ints and floats their own registers, so the order is invisible to the callee, but the caller
     loads its argument registers in prototype order, which is what the scheduler keeps on ties:
     func_0041E820 (ptr, f, ptr, int, f, f, int, int, int; as src/levels/shared/L01_004463D0.c
     declares it), func_003D4D00 (ptr, int, f, ptr, int; as src/levels/01_veldin/L01_003B8190.c),
     func_0041E800 (ptr, ptr, int, f, ptr), func_0043F380 (ptr, ptr, f, f, int) and
     func_004207F8 (ptr, f, ptr, f, f, f, int).
   - qzero() as a macro (include/vu0.h): two identical `qzero(p); break;` case tails stay apart.
   - Statement order where sched2 emits independent stores in reverse (0x14, 0x2, 0x32, 0x80),
     a fresh local where a reused variable pinned a register (0x13, 0x35, 0x40), and duplicated
     tail statements where retail cross-jumps them (0x66). */
typedef int u128_t __attribute__((mode(TI)));
typedef union { u8 b[0x2600]; s8 c[0x2600]; s16 h[0x1300]; u16 uh[0x1300]; s32 i[0x980]; u32 u[0x980]; f32 f[0x980]; void *ptr[0x980]; long d[0x4C0]; u128_t q[0x260]; } Hero;
typedef struct { s32 x0[7]; s32 x1C; u8 x20[0xC0]; } LevelInfo;
typedef struct { s32 w[11]; } Rec2C;
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4;
extern void func_0041E820(s32, f32, s32, s32, f32, f32, s32, s32, s32);
extern void func_004C7210(void);
extern Hero *D_001D52FC;
extern u8 D_001A30B0[];
extern char D_001A4BE0[];
extern char D_001A4CD0[];
extern char D_001A7C10[];
extern u8 D_001A7F08[];
extern u32 D_001D4C38;
extern s32 D_001D545C;
extern u8 D_00142CAD[];
extern u8 D_001439F4[];
extern u8 D_00142CBA[];
extern s32 D_001D673C;
extern s32 D_001DE8C0;
extern s32 D_001DFD90;
extern s32 D_001DFD98;
extern u8 D_001E1680[];
extern u8 D_001E1698[];
extern u8 D_001EC440[];
extern u8 D_002F6CC0[];
extern Rec2C D_002F8A50[];
extern u8 D_002F8D70[];
extern s32 func_003D3CB0(s32, s32, s32, s32, s32);
extern s32 func_003D4D00(s32, s32, f32, s32, s32);
extern s32 func_0038CAD0(s32);
extern s32 func_0038CB00(s32);
extern void func_004C9A80(f32);
extern void func_0038D000(s32, s32, s32);
extern void func_0038CE20(s32, s32, f32);
extern void func_0038CE90(s32, s32, s32);
extern f32 func_0038CEA8(s32);
extern f32 func_0038CED8(s32);
extern f32 func_0038CF38(s32, s32);
extern f32 func_0038CF00(s32, s32);
extern void func_0038CF68(s32, s32, f32);
extern void func_0038CFB8(s32, s32, f32);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern f32 func_0038D160(f32, f32);
extern f32 func_0038DAB8(f32, f32);
extern f32 func_0038DB00(f32, f32);
extern f32 func_0038DBA0(f32, f32);
extern void func_003C2F58(s32, s32, s32);
extern s32 func_00382468(s32);
extern s32 func_00382498(s32, s32);
extern f32 func_003824E0(f32, f32);
extern void func_0041E800(s32, s32, s32, f32, s32);
extern void func_0041EB10(s32, s32, s32, s32, s32, f32);
extern f32 func_003C4138(s32, f32, f32);
extern f32 func_00420370(s32, s32, f32, f32, f32, f32);
extern f32 func_00420410(s32, s32, s32, f32, f32, f32);
extern f32 func_004206B0(s32, f32, f32);
extern void func_00420760(s32, s32, f32, f32);
extern f32 func_004207F8(s32, f32, s32, f32, f32, f32, s32);
extern s32 func_003C4B50(s32);
extern void func_003C4BB0(s32, f32);
extern void func_00382760(s32, f32, f32, f32);
extern s32 func_0043F380(s32, s32, f32, f32, s32);
extern void func_003A4F28(s32);
extern void func_0049CCB8(s32, s32, void *, f32, f32, f32, f32);
extern void func_004BB2C8(s32, s32, f32);
extern void func_004BB3C8(f32, f32, f32, f32);
extern f32 func_004BB4C8(s32, s32);
extern void func_004BB628(f32, f32, f32);
extern void func_004BBAE0(s32, s32);
extern void func_004BBBD8(s32, s32);
extern void func_004BBDB8(s32, s32);
extern void func_004BBFA0(s32, s32, s32);
extern void func_004BC250(s32, s32, s32);
extern void func_004BC480(f32, f32);
extern void func_004BC498(f32, f32);
extern void func_004BC4B0(f32, f32);
extern void func_004BC4C8(f32, f32);
extern void func_004BD870(void);
extern s32 func_004BEA50(s32);
extern s32 func_004373F0(s32, s32, s32, s32);
extern void func_004D1568(s32, s32);
extern void func_004CA618(void);
extern void func_004CA340(void);

extern void func_004C3B20(void);
extern s32 func_004C3F18(f32);
extern void func_004C3F70(f32, s32);
extern void func_004C42C8(void);
extern void func_004C4368(f32, f32, f32);
extern void func_004C44A0(s32, f32, f32, f32);
extern void func_004C4590(void);
extern void func_004C47F8(f32, f32);
extern void func_004C4848(f32);
extern void func_004C4908(s32);
extern void func_004C4938(void);
extern void func_004C5BC0(f32, f32);
extern f32 func_004C5C58(s32);
extern void func_004C67B0(f32);
extern void func_004C6BC0(void);
extern void func_004C7BD0(f32, f32, f32);
extern void func_004C81B8(void);
extern void func_004C8F30(void);
extern void func_004C9290(void);
extern f32 func_004C9B40(s32, s32);
extern s32 func_004C9B90(s32, s32);
extern void func_004C9C38(s32, s32, s32);
extern s32 func_004CA000(f32, f32, f32);
extern s32 func_004E02C8(s32);
extern void func_004D5780(void);
extern s32 func_004D7448(void);
extern void func_004DE428(s32, s32, f32);
extern void func_004DF7F0(s32, s32, f32);
extern void func_004DF9D0(s32, s32, f32, f32, f32);
extern void func_004DFA40(s32, s32, f32);
extern void func_004DFA60(s32, s32, f32);
extern void func_004DFB68(s32, s32, f32);
extern void func_004DFC08(s32, s32);
extern f32 func_004DFCF0(s32);
extern f32 func_004DFD98(s32);
extern void func_004DFDF0(s32, s32, f32);
extern void func_004DFE70(s32, s32, f32);
extern s32 func_003CC0E0(s32, s32);
extern s32 func_003E7DA0(s32, s32, f32);
extern void func_00426510(s32, s32);
extern void func_00427CE8(s32, s32, f32, f32, f32);
extern f32 func_00437520(s32, s32);
extern s32 func_004BE168(s32, s32, s32);
extern f32 D_002F2380[];
extern f32 D_001DBD84[] __attribute__((section(".sdata")));
extern s32 D_001D66B0[2];
extern f32 func_0038CE68(s32, s32);
extern void func_004C81B8(void);
extern void func_004C8F30(void);

extern f32 D_001DA540[];
extern s32 func_004B6260(s32);
extern void func_004C4A78(s32);

#include "vu0.h"

void func_L27_004CA9C8(void) {
    f32 v0[4] __attribute__((aligned(16)));
    f32 v10[4] __attribute__((aligned(16)));
    f32 v20[4] __attribute__((aligned(16)));
    f32 v30[4] __attribute__((aligned(16)));
    f32 v40[4] __attribute__((aligned(16)));
    f32 v50[4] __attribute__((aligned(16)));
    f32 v60[4] __attribute__((aligned(16)));
    s32 lim;
    s32 lim2;

    s32 sp114;
    s32 sp118;
    f32 temp_f0;
    f32 var_f12;
    f32 var_f12_4;
    f32 var_f1;
    f32 var_f20;
    s32 temp_a0_3;
    s32 var_a0_2;
    u32 temp_v1;
    u32 temp_v1_3;
    u8 temp_a0_2;
    void* temp_a0_4;
    void* temp_fp;

    sp114 = ((Hero *)D_001A4BE0)->i[0x25C8/4];
    temp_fp = ((Hero *)D_001A4BE0)->ptr[0x25C0/4];
    sp118 = (s32) (*(u8 *)((u8 *)(temp_fp) + 0x43));
    switch (((Hero *)D_001A4BE0)->u[0x25C4/4]) {                              /* switch 1 */
    case 0x0:
    case 0x1:
    case 0x3:
    case 0x4:
    case 0x1C:
    case 0x1D:
    case 0x1E:
    case 0x39:
    case 0x72:
    case 0x74:
    case 0x82:
        func_004C5BC0(0.5f, 0.040000003f);
        func_004CA000(3.7f, 0.0f, 0.35f);
        func_004C3F70(1.0f, 0);
        temp_v1 = ((Hero *)D_001A4BE0)->u[0x25C4/4];
        if ((temp_v1 == 1) || (temp_v1 == 0x1D)) {
            if (((Hero *)D_001A4BE0)->b[0x25E5] != 0) {
                (*(u128_t*)v0) = 0;
                v0[0] = 1.0f;
                func_0038D000((s32) (((void*)D_001A4BE0) + 0x190), (s32)((u128_t*)v0), (s32)&D_001E1698[0x368]);
                ((Hero *)D_001A4BE0)->f[0x1A0/4] = ((Hero *)D_001E1698)->f[0];
                func_004C44A0(0, 1.44f, 0.0f, 3.4906588f);
                if ((((Hero *)D_001A4BE0)->b[0x25EC] != 0) && (((Hero *)D_001A4BE0)->i[0x1B8/4] == 100)) {
                    if (((Hero *)D_001A7C10)->uh[0xD8/2] < 0xFFFF) {
                        ((Hero *)D_001A7C10)->uh[0xD8/2]++;
                    }
                    lim = ((s32)D_001D4C38 * 5 + 2) / 6;
                    if (((Hero *)D_001A7C10)->u[0xDC/4] < lim) {
                        ((Hero *)D_001A7C10)->u[0xDC/4] = lim;
                    }
                    ((Hero *)D_001A7C10)->u[0xE0/4] = ((Hero *)D_001A7C10)->u[0xE0/4] | (1 << D_001D545C) | 0x80000000;
                }
            }
        }
        if (((Hero *)D_001A4BE0)->u[0x25C4/4] == 3) {
            if (func_004D7448() != 0) {
                break;
            }
        }
        if (((Hero *)D_001A4BE0)->u[0x25C4/4] == 4) {
            if ((((Hero *)D_001A4BE0)->f[0x2838/4] > 0.2f) || (temp_a0_2 = (*(u8 *)((u8 *)(((Hero *)D_001A4BE0)->ptr[0x25C0/4]) + 0x43)), (temp_a0_2 == 0xE)) || (temp_a0_2 == 0xF)) {
                if (((Hero *)D_001A4BE0)->u[0x25C4/4] == 4) {
                    func_004C44A0(0, 0.0028800003f, 0.10080001f, 0.19896755f);
                }
                if (fabs_asm(((Hero *)D_001A4BE0)->f[0x1A4/4]) > 0.0069813174f) {
                    temp_a0_3 = ((Hero *)D_001A4BE0)->f[0x1A4/4] < 0.0f;
                    temp_a0_3 += 0xE;
                    if ((*(u8 *)((u8 *)(((Hero *)D_001A4BE0)->ptr[0x25C0/4]) + 0x43)) != temp_a0_3) {
                        func_004DE428(temp_a0_3, 0, 4.0f);
                    }
                    temp_f0 = fabs_asm(((Hero *)D_001A4BE0)->f[0x1A4/4]) * 5.0f / 6.0f / 0.06632252f;
                    ((Hero *)D_001A4BE0)->f[0xC00/4] = temp_f0;
                    if (temp_f0 < 0.55f) {
                        ((Hero *)D_001A4BE0)->f[0xC00/4] = 0.55f;
                    }
                    if (((Hero *)D_001A4BE0)->f[0xC00/4] > 2.5f) {
                        ((Hero *)D_001A4BE0)->f[0xC00/4] = 2.5f;
                    }
                } else if (((Hero *)D_001A4BE0)->f[0x1A4/4] == 0.0f) {
                    if ((*(u8 *)((u8 *)(((Hero *)D_001A4BE0)->ptr[0x25C0/4]) + 0x43)) != 0xD) {
                        func_004DE428(0xD, 0, 6.0f);
                    }
                }
            }
        }
            temp_v1_3 = ((Hero *)D_001A4BE0)->u[0x25C4/4];
            ((Hero *)D_001A4BE0)->f[0x1B0/4] = 0.0f;
            if (temp_v1_3 == 3) {
                var_f12 = ((Hero *)D_001A4BE0)->f[0x17C/4] + 1.0f;
                if (var_f12 > 1.0f) {
                    var_f12 = 1.0f;
                }
                temp_a0_4 = ((Hero *)D_001A4BE0)->ptr[0x25C0/4];
                var_f20 = var_f12 * 0.0108f;
                ((Hero *)D_001A4BE0)->f[0x282C/4] = var_f20;
                if ((*(u8 *)((u8 *)(temp_a0_4) + 0x42)) == (*(u8 *)((u8 *)(temp_a0_4) + 0x43))) {
                    var_f1 = ((Hero *)D_001A4BE0)->f[0x174/4] / var_f20;
                    if ((var_f1 > 4.0f) && ((f32) (*(u8 *)((u8 *)(temp_a0_4) + 0x41)) < 5.5f)) {
                        func_004BB3C8(13.0f, var_f1, 0.5f, -1.0f);
                        if (((Hero *)D_001A4BE0)->f[0xC00/4] > 1.1f) {
                            ((Hero *)D_001A4BE0)->f[0xC00/4] = 1.1f;
                        }
                    } else if ((f32) (*(u8 *)((u8 *)(((Hero *)D_001A4BE0)->ptr[0x25C0/4]) + 0x41)) > 6.5f) {
                        ((Hero *)D_001A4BE0)->f[0xC00/4] = 1.0f;
                    }
                }
            } else {
                var_f20 = (temp_v1_3 == 4) ? 0.0108f : 0.007080001f;
            }
            func_004C47F8(0.0f, var_f20);
            qzero((V4 *)(D_001A4BE0 + 0xF0));
            func_004C9A80(var_f20);
            if ((((Hero *)D_001A4BE0)->b[0x1479] != 0) && (D_00142CAD[0] != 0)) {
                var_a0_2 = (s32)(D_001A4BE0 + 0xF0);
                if (((Hero *)D_001A4BE0)->f[0x33C/4] > 0.2f) {
                    func_004DF7F0(var_a0_2, var_a0_2 + 0x30, 0.0088f);
                } else {
                    func_004DF7F0((s32)(D_001A4BE0 + 0xF0), (s32)(D_001A4BE0 + 0xF0), 0.0216f);
                    if (((Hero *)D_001A4BE0)->i[0x35C/4] != 0) {
                        *(u128_t *)(&((Hero *)D_001A4BE0)->q[0x80/16]) = *(u128_t *)(&((Hero *)D_001A4BE0)->q[0x2F0/16]);
                        ((Hero *)D_001A4BE0)->f[0x33C/4] = 0.0f;
                        ((Hero *)D_001A4BE0)->h[0x36E/2] = 0;
                    }
                }
            } else {
                func_004C4A78(0);
                if (((Hero *)D_001A4BE0)->h[0x36E/2] == 0) {
                    func_004DF7F0((s32) ((void*)D_001A4BE0) + 0xF0, (s32) ((void*)D_001A4BE0) + 0xF0, 0.0216f);
                } else {
                    func_004DF7F0((s32) ((void*)D_001A4BE0) + 0xF0, (s32) ((void*)D_001A4BE0) + 0x130, 0.010000001f);
                    func_004C4938();
                }
            }
        break;
    case 0x32:
    case 0x33:
    case 0x34:
        {
        f32 turn;
        s32 st32;
        f32 spE0;
        f32 m;
        f32 sp;
        f32 h94;
        f32 dh;
        f32 yaw;
        f32 roll;
        s32 a;
        s32 b;
        s32 tA2;
        void *obj;
        s32 i;
        if (((Hero *)D_001A4BE0)->u[0x25C4/4] == 0x34) {
            if (((Hero *)D_001A4BE0)->i[0x1B8/4] >= 0x3B) {
                (*(u16*)&D_001A7F08) = 0xFFFF;
            }
            func_004C9C38(5, (s32) ((Hero *)D_001A4BE0)->ptr[0x25C0/4], 0xF);
            func_003CC0E0(0x16, 0);
        } else {
            {
            s32 t27A0 = ((Hero *)D_001A4BE0)->i[0x27A0/4];
            if (t27A0 != -1) {
                u8 *o = (u8 *)D_001A30B0 + (t27A0 << 7);
                if (*(void **)(o + 0xDC) == ((Hero *)D_001A4BE0)->ptr[0x25C0/4]) {
                    if (*(u8 *)(o + 0xD0) != 0) {
                        func_003A4F28(t27A0);
                    }
                }
            }
            }
            ((Hero *)D_001A4BE0)->i[0x27A0/4] = -1;
        }
        if (((Hero *)D_001A4BE0)->h[0x9CA/2] != 0) {
            s32 t9CA;
            func_0038CB00((s32) (((void*)D_001A4BE0) + 0x9CA));
            t9CA = (s32) ((u16) ((Hero *)D_001A4BE0)->h[0x9CA/2] << 0x10) >> 0x12;
            func_004BBFA0((t9CA >= 9) ? 8 : t9CA, 0, 0);
        }
        if ((((Hero *)D_001A4BE0)->u[0x25C4/4] == 0x32) && (((Hero *)D_001A4BE0)->i[0xC0C/4] == 0)) {
            f32 tC18 = ((Hero *)D_001A4BE0)->f[0xC18/4];
            if (tC18 > 0.0f) {
                if (tC18 < 10.0f) {
                    func_004BBFA0(4, 1, 0);
                }
            }
        }
        if (((Hero *)D_001A4BE0)->u[0x25C4/4] == 0x33) {
            if (((Hero *)D_001A4BE0)->i[0x25D0/4] == 0x34) {
                s32 t1B8 = ((Hero *)D_001A4BE0)->i[0x1B8/4];
                if (t1B8 < 0xC) {
                    func_004BBFA0(((s32) (0x11 - t1B8) / 3) + 1, 1, 0);
                }
            }
        }
        {
        s32 t25C8 = ((Hero *)D_001A4BE0)->i[0x25C8/4];
        if (t25C8 == 1) {
            s32 t9A0;
            if (((Hero *)D_001A4BE0)->i[0x1B8/4] == t25C8) {
                func_004BC250(3, 0x10, 0);
                if (D_001DFD90 != 0) {
                    func_0049CCB8(D_001DFD90, D_001DFD98, 0, ((Hero *)D_001A4BE0)->f[0x80/4], ((Hero *)D_001A4BE0)->f[0x84/4], 0.4f, -0.3f);
                }
                ((Hero *)D_001A4BE0)->h[0x9CA/2] = 0x3A;
            }
            t9A0 = ((Hero *)D_001A4BE0)->i[0x9A0/4] + 1;
            ((Hero *)D_001A4BE0)->i[0x9A0/4] = t9A0;
            if (t9A0 >= 0x22) {
                ((Hero *)D_001A4BE0)->i[0x25C8/4] = 0;
            }
        }
        }
        {
        f32 x128;
        f32 x12C;
        var_f12_4 = 0.0f;
        turn = 0.013962635f;
        if (D_001D52FC->f[0x128/4] < D_001D52FC->f[0x12C/4]) {
            m = D_001D52FC->f[0x12C/4];
        } else {
            m = D_001D52FC->f[0x128/4];
        }
        turn += m * 0.010471976f;
        if (((D_001D52FC->d[0x1A0/8] & 0xC0) == 0x80) || (((Hero *)D_001A4BE0)->i[0x25C8/4] == 1)) {
            var_f12_4 = D_001D52FC->f[0x12C/4] * 1.5f;
            if (var_f12_4 > 1.0f) {
                var_f12_4 = 1.0f;
            }
            if (var_f12_4 < 0.2f) {
                var_f12_4 = 0.2f;
            }
            if (D_001D52FC->i[0x1DC/4] != 0x79) {
                s32 c9C2 = ((Hero *)D_001A4BE0)->uh[0x9C2/2] + 1;
                ((Hero *)D_001A4BE0)->uh[0x9C0/2] = 0;
                var_f12_4 = (f32) (s16) c9C2 * 0.5f / 17.0f + 0.5f;
                ((Hero *)D_001A4BE0)->uh[0x9C2/2] = c9C2;
                if (var_f12_4 > 1.0f) {
                    var_f12_4 = 1.0f;
                }
            }
            if ((((Hero *)D_001A4BE0)->i[0x25C8/4] == 1) && (var_f12_4 < 0.35f)) {
                var_f12_4 = 0.35f;
            }
            var_f12_4 = var_f12_4 * 1.3613569f;
        } else if (D_001D52FC->i[0x1A0/4] & 0x40) {
            var_f12_4 = D_001D52FC->f[0x128/4] * 1.5f;
            if (var_f12_4 > 1.0f) {
                var_f12_4 = 1.0f;
            }
            if (var_f12_4 < 0.2f) {
                var_f12_4 = 0.2f;
            }
            if (D_001D52FC->i[0x1DC/4] != 0x79) {
                s32 c9C0 = ((Hero *)D_001A4BE0)->uh[0x9C0/2] + 1;
                ((Hero *)D_001A4BE0)->uh[0x9C2/2] = 0;
                ((Hero *)D_001A4BE0)->uh[0x9C0/2] = c9C0;
                var_f12_4 = (f32) (s16) c9C0 * 0.5f / 17.0f + 0.5f;
                if (var_f12_4 > 1.0f) {
                    var_f12_4 = 1.0f;
                }
            }
            var_f12_4 = var_f12_4 * -1.3613569f;
        } else {
            ((Hero *)D_001A4BE0)->uh[0x9C0/2] = 0;
            ((Hero *)D_001A4BE0)->uh[0x9C2/2] = 0;
        }
        }
        if (D_001D52FC->i[0x1A0/4] & 0x40) {
            ((Hero *)D_001A4BE0)->uh[0x9CE/2]++;
            if (D_001D52FC->f[0x128/4] > 0.75f) {
                s32 c9CC = ((Hero *)D_001A4BE0)->uh[0x9CC/2] + 1;
                ((Hero *)D_001A4BE0)->uh[0x9CC/2] = c9CC;
                if ((s16) c9CC >= 0x4C) {
                    if (((Hero *)D_001A7C10)->uh[0x84/2] < 0xFFFF) {
                        ((Hero *)D_001A7C10)->uh[0x84/2]++;
                    }
                }
                lim = ((s32)D_001D4C38 * 5 + 2) / 6;
                if (((Hero *)D_001A7C10)->u[0x88/4] < lim) {
                    ((Hero *)D_001A7C10)->u[0x88/4] = lim;
                }
                ((Hero *)D_001A7C10)->u[0x8C/4] = ((Hero *)D_001A7C10)->u[0x8C/4] | (1 << D_001D545C) | 0x80000000;
            } else {
                ((Hero *)D_001A4BE0)->uh[0x9CC/2] = 0;
            }
        } else {
            ((Hero *)D_001A4BE0)->uh[0x9CE/2] = 0;
            ((Hero *)D_001A4BE0)->uh[0x9CC/2] = 0;
        }
        if (D_001D52FC->i[0x1A4/4] & 0x40) {
            if ((D_001DE8C0 - ((Hero *)D_001A4BE0)->i[0x9D4/4]) < 0x3A) {
                ((Hero *)D_001A4BE0)->i[0x9D0/4]++;
            }
            ((Hero *)D_001A4BE0)->i[0x9D4/4] = D_001DE8C0;
        }
        if (((Hero *)D_001A4BE0)->h[0x9CE/2] >= 0x3B) {
            ((Hero *)D_001A4BE0)->i[0x9D0/4] = 0;
        }
        if (D_001D52FC->i[0x1A0/4] & 0x80) {
            ((Hero *)D_001A4BE0)->i[0x9D0/4] = 0;
        }
        if (((Hero *)D_001A4BE0)->u[0x25C4/4] == 0x33) {
            var_f12_4 = 0.0f;
        }
        h94 = ((Hero *)D_001A4BE0)->f[0x94/4];
        func_004207F8((s32) (D_001A4BE0 + 0x94), var_f12_4, (s32) (D_001A4BE0 + 0x9A8), 0.0216f, 0.28800002f, turn, 0);
        dh = func_0038DB00(((Hero *)D_001A4BE0)->f[0x94/4], h94);
        func_004C3F70(1.0f, 0);
        func_004C44A0(0, 0.01008f, 0.115200005f, 0.10471976f);
        ((Hero *)D_001A4BE0)->f[0x9AC/4] = ((Hero *)D_001A4BE0)->f[0x1A4/4];
        func_0038CAD0((s32) (D_001A4BE0 + 0x9B4));
        if (((Hero *)D_001A4BE0)->i[0x25C8/4] == 1) {
            ((Hero *)D_001A4BE0)->f[0x1B0/4] = 0.120000005f;
        } else if (((Hero *)D_001A4BE0)->u[0x25C4/4] == 0x34) {
            if (D_001D52FC->i[0x1A0/4] & 0xA) {
                ((Hero *)D_001A4BE0)->f[0x1B0/4] = 0.14000002f;
            } else {
                ((Hero *)D_001A4BE0)->f[0x1B0/4] = 0.056000005f;
            }
        } else {
            ((Hero *)D_001A4BE0)->f[0x1B0/4] = 0.060000002f;
        }
        {
        f32 sc;
        f32 lo;
        sc = ((Hero *)D_001A4BE0)->f[0x2838/4];
        if ((D_001D52FC->i[0x1A0/4] & 0xC0) || (((Hero *)D_001A4BE0)->i[0x25C8/4] == 1)) {
            if (sc < 1.0f) {
                sc = 1.0f;
            }
        }
        if (((Hero *)D_001A4BE0)->f[0x2838/4] > 0.15f) {
            lo = 0.35f;
            if (((Hero *)D_001A4BE0)->u[0x25C4/4] == 0x34) {
                lo = 0.4f;
            }
            if (sc < lo) {
                sc = lo;
            }
        }
        if ((((Hero *)D_001A4BE0)->u[0x25C4/4] != 0x34) || !(D_001D52FC->i[0x1A0/4] & 0xA)) {
            ((Hero *)D_001A4BE0)->f[0x1B0/4] = ((Hero *)D_001A4BE0)->f[0x1B0/4] * sc;
        }
        }
        if (func_0038CAD0((s32)(D_001A4BE0 + 0x9B0)) != 0) {
            Hero *h9 = (Hero *)D_001A4BE0;
            func_003C2F58((s32) ((Hero *)D_001A4BE0)->ptr[0x25C0/4], 4, (s32)v0);
            (*(u128_t*)v20) = 0;
            v20[0] = 0.4f;
            func_0038D000((s32)v20, (s32)v20, (s32) (((Hero *)D_001A4BE0)->ptr[0x25C0/4] + 0xC0));
            vec_add_ba((V4 *)v0, (V4 *)v0, (V4 *)v20);
            *(u128_t *)(v10) = *(u128_t *)(&((Hero *)D_001A4BE0)->q[0x110/16]);
            func_0038CF68((s32)v20, (s32)v20, 0.030000001f);
            vec_add_ab((V4 *)v10, (V4 *)v10, (V4 *)v20);
            v10[2] += 0.040000003f;
            func_0043F380((s32)v0, (s32)v10, 25200.0f, -1.0f, 0x88A0A0A0);
            if ((f32) func_00382468(100) < 40.0f) {
                a = 3;
                b = 9;
            } else {
                a = 0x21;
                b = 0x4B;
            }
            h9->i[0x9B0/4] = func_00382498(a, b);
        }
        if (((Hero *)D_001A4BE0)->u[0x25C4/4] == 0x34) {
            if (func_0038CB00((s32) (D_001A4BE0 + 0x9B8)) != 0) {
                obj = ((Hero *)D_001A4BE0)->ptr[0x12F0/4];
                if (obj != 0) {
                    if (*(s16 *)((u8 *)obj + 0xAA) == 0x261) {
                        for (i = 0; i < 4; i++) {
                            func_003C2F58((s32) obj, i % 2, (s32)v0);
                            (*(u128_t*)v20) = 0;
                            v20[0] = -0.15f;
                            func_0038D000((s32)v20, (s32)v20, (s32) (((Hero *)D_001A4BE0)->ptr[0x25C0/4] + 0xC0));
                            vec_add_ab((V4 *)v0, (V4 *)v0, (V4 *)v20);
                            v0[0] += func_003824E0(0.0f, 0.03f);
                            v0[1] += func_003824E0(0.0f, 0.03f);
                            v0[2] += func_003824E0(0.0f, 0.03f);
                            *(u128_t *)(v10) = *(u128_t *)(&((Hero *)D_001A4BE0)->q[0x110/16]);
                            func_00427CE8((s32)v10, (s32)v10, -0.015000001f, ((Hero *)D_001A4BE0)->f[0x98/4], ((Hero *)D_001A4BE0)->f[0x94/4]);
                            ((Hero *)D_001A4BE0)->h[0x9B8/2] = (0.14000002f - ((Hero *)D_001A4BE0)->f[0x1B4/4]) / 0.14000002f * 4.0f;
                            func_0043F380((s32)v0, (s32)v10, func_003824E0(6300.0f, 9450.0f), -1.0f, 0x88A0A0A0);
                        }
                    }
                }
            }
        }
        if (((Hero *)D_001A4BE0)->u[0x25C4/4] == 0x34) {
            func_004C47F8(0.0052000005f, 0.0032000002f);
        } else {
            func_004C47F8(0.0028000001f, 0.0016000001f);
        }
        yaw = func_0038DAB8(-((Hero *)D_001A4BE0)->f[0x94/4], 0.0f);
        st32 = ((Hero *)D_001A4BE0)->u[0x25C4/4];
        if (st32 == 0x34) {
            func_00382760((s32)D_001A4BE0 + 0xF0, ((Hero *)D_001A4BE0)->f[0x1B4/4], ((Hero *)D_001A4BE0)->f[0x98/4], yaw);
        } else if (st32 == 0x32) {
            sp = ((Hero *)D_001A4BE0)->f[0x1B4/4] * func_004BB4C8((s32)D_002F8D70, 0x1E) * 5.0f;
            if ((((Hero *)D_001A4BE0)->i[0x25D0/4] == 0x34) && (((Hero *)D_001A4BE0)->i[0x1B8/4] < 0xC) && (sp < 0.09f)) {
                sp = 0.09f;
            }
            func_00382760((s32)(D_001A4BE0 + 0xF0), sp, ((Hero *)D_001A4BE0)->f[0x98/4], yaw);
        } else if (st32 == 0x33) {
            spE0 = func_0038CEA8((s32) (D_001A4BE0 + 0x160));
            if (((Hero *)D_001A4BE0)->i[0x25D0/4] == 0x34) {
                func_003C4138((s32) &spE0, 0.0f, 0.0032000002f);
            } else {
                func_003C4138((s32) &spE0, 0.0f, 0.0016000001f);
            }
            func_0038CF68((s32)(D_001A4BE0 + 0x160), (s32)(D_001A4BE0 + 0x160), spE0);
            *(u128_t *)(&((Hero *)D_001A4BE0)->q[0xF0/16]) = *(u128_t *)(&((Hero *)D_001A4BE0)->q[0x160/16]);
        }
        func_004C4A78(0);
        roll = ((Hero *)D_001A4BE0)->f[0x9AC/4] * func_0038D098(yaw) * -7.0f;
        func_004207F8((s32) (D_001A4BE0 + 0x90), roll, (s32) (D_001A4BE0 + 0x9A4), 0.007f, 0.17f, 0.024434611f, 0);
        func_004BC498(0.009f, 0.22f);
        func_004BC4B0(0.04f, 0.2f);
        func_004BC4C8(0.02f, 0.2f);
        {
        f32 pit = dh * 47.0f;
        f32 yw;
        f32 rl;
        ((Hero *)D_002F6CC0)->f[0x114/4] = pit;
        ((Hero *)D_002F6CC0)->f[0x118/4] = roll * 1.5f;
        ((Hero *)D_002F6CC0)->f[0x110/4] = roll * 1.4f;
        if (pit > 0.87266463f) {
            ((Hero *)D_002F6CC0)->f[0x114/4] = 0.87266463f;
        } else if (pit < -0.87266463f) {
            ((Hero *)D_002F6CC0)->f[0x114/4] = -0.87266463f;
        }
        yw = dh * 40.0f;
        rl = roll * 1.1f;
        ((Hero *)D_002F6CC0)->f[0x364/4] = 0.03f;
        ((Hero *)D_002F6CC0)->f[0x368/4] = 0.22f;
        ((Hero *)D_002F6CC0)->f[0x324/4] = yw;
        ((Hero *)D_002F6CC0)->f[0x328/4] = rl;
        ((Hero *)D_002F6CC0)->f[0x414/4] = 0.03f;
        ((Hero *)D_002F6CC0)->f[0x418/4] = 0.22f;
        ((Hero *)D_002F6CC0)->f[0x3D4/4] = yw;
        ((Hero *)D_002F6CC0)->f[0x3D8/4] = rl;
        }
        }
        break;
    case 0x78:
        {
        s32 t78;
        t78 = 0xA - (((Hero *)D_001A4BE0)->i[0x1B8/4] / 3);
        func_004BBFA0((t78 >= 9) ? 8 : t78, 0, 0);
        ((Hero *)D_001A4BE0)->f[0xF8/4] = 0.0f;
        func_003E7DA0((s32)D_001A4BE0 + 0xF0, (s32)D_001A4BE0 + 0xF0, func_0038CED8((s32)D_001A4BE0 + 0xF0) * 0.90400004f);
        func_004C4A78(0);
        }
        break;
    case 0x77:
        func_004BBAE0(0xF, 0x1E);
        ((Hero *)D_001A4BE0)->f[0xF8/4] = 0.0f;
        func_003E7DA0((s32)D_001A4BE0 + 0xF0, (s32)D_001A4BE0 + 0xF0, func_0038CED8((s32)D_001A4BE0 + 0xF0) * 0.90400004f);
        func_004C4A78(0);
        func_004D5780();
        break;
    case 0x6C:
    case 0x84:
        {
        f32 sp6C;
        s32 t6C;
        sp6C = func_0038CEA8((s32)(D_001A4BE0 + 0x160));
        func_003C4138((s32)&sp6C, 0.0f, 0.0016000001f);
        func_0038CF68((s32)(D_001A4BE0 + 0x160), (s32)(D_001A4BE0 + 0x160), sp6C);
        *(u128_t *)(&((Hero *)D_001A4BE0)->q[0xF0/16]) = *(u128_t *)(&((Hero *)D_001A4BE0)->q[0x160/16]);
        if (func_0038CAD0((s32)(D_001A4BE0 + 0x9B0)) == 2) {
            func_003C2F58((s32) ((Hero *)D_001A4BE0)->ptr[0x25C0/4], 4, (s32)v0);
            (*(u128_t*)v20) = 0;
            v20[0] = 0.4f;
            func_0038D000((s32)v20, (s32)v20, (s32) (((Hero *)D_001A4BE0)->ptr[0x25C0/4] + 0xC0));
            vec_add_ba((V4 *)v0, (V4 *)v0, (V4 *)v20);
            *(u128_t *)(v10) = *(u128_t *)(&((Hero *)D_001A4BE0)->q[0x110/16]);
            func_0038CF68((s32)v20, (s32)v20, 0.030000001f);
            vec_add_ab((V4 *)v10, (V4 *)v10, (V4 *)v20);
            v10[2] += 0.040000003f;
            func_0043F380((s32)v0, (s32)v10, 25200.0f, -1.0f, 0x88A0A0A0);
            t6C = ((Hero *)D_001A4BE0)->i[0x1B8/4];
            if (t6C < 0x21) {
                ((Hero *)D_001A4BE0)->i[0x9B0/4] = func_00382498(2, 4) + (((Hero *)D_001A4BE0)->i[0x1B8/4] / 5);
            } else if (t6C >= 0x3B) {
                ((Hero *)D_001A4BE0)->i[0x9B0/4] = func_00382498(8, 0x11);
            }
        }
        if (((Hero *)D_001A4BE0)->f[0x9BC/4] > 0.0f) {
            ((Hero *)D_001A4BE0)->f[0x9BC/4] = 0.0f;
        }
        func_003C4138((s32)D_001A4BE0 + 0x9BC, -0.030000001f, 0.0006f);
        ((Hero *)D_001A4BE0)->f[0xF8/4] = ((Hero *)D_001A4BE0)->f[0x9BC/4];
        }
        break;
    case 0x35:
    case 0x36:
        {
        s32 t35;
        f32 sp35;
        f32 v35;
        if (((Hero *)D_001A4BE0)->u[0x25C4/4] == 0x36) {
            func_004BBAE0(0xF, 0x1E);
        }
        if (((Hero *)D_001A4BE0)->f[0x174/4] > 0.030000001f) {
            func_004BBDB8(4, 0xC);
        }
        if ((((Hero *)D_001A4BE0)->u[0x25C4/4] == 0x35) && (((Hero *)D_001A4BE0)->f[0x174/4] > 0.020000001f)) {
            func_004BBBD8(0, 1);
        }
        if (((Hero *)D_001A4BE0)->h[0x9CA/2] != 0) {
            ((Hero *)D_001A4BE0)->h[0x9CA/2] -= 1;
            t35 = ((Hero *)D_001A4BE0)->h[0x9CA/2] >> 3;
            func_004BBFA0((t35 >= 7) ? 6 : t35, 0, 0);
        }
        ((Hero *)D_001A4BE0)->f[0xC00/4] = 0.6f;
        func_004C3F70(0.060000002f, 0);
        if ((D_001D52FC->i[0x1D4/4] == 0) && (((Hero *)D_001A4BE0)->f[0x1B0/4] < 0.030000001f)) {
            ((Hero *)D_001A4BE0)->f[0x1B0/4] = 0.030000001f;
        }
        func_004C44A0(0, 0.01008f, 0.115200005f, 0.10471976f);
        func_0038CAD0((s32)(D_001A4BE0 + 0x728));
        if (((Hero *)D_001A4BE0)->u[0x25C4/4] == 0x35) {
            if ((D_001D52FC->i[0x1D4/4] != 0) && (((Hero *)D_001A4BE0)->i[0x728/4] != 0)) {
                ((Hero *)D_001A4BE0)->f[0x1B0/4] = 0.060000002f;
            }
            if (fabs_asm(((Hero *)D_001A4BE0)->f[0x1A8/4]) > 0.7853982f) {
                ((Hero *)D_001A4BE0)->f[0x1B0/4] = 0.0f;
            }
            func_004C47F8(0.0016000001f, 0.002f);
            sp35 = ((Hero *)D_001A4BE0)->f[0x1B4/4] * func_004BB4C8((s32)D_002F8D70, 0x1E) * 5.5f;
            ((Hero *)D_001A4BE0)->f[0xF0/4] = func_0038D098(((Hero *)D_001A4BE0)->f[0x98/4]) * sp35;
            {
            f32 w35 = func_0038D0B0(((Hero *)D_001A4BE0)->f[0x98/4]) * sp35;
            ((Hero *)D_001A4BE0)->f[0xF8/4] = 0.0f;
            ((Hero *)D_001A4BE0)->f[0xF4/4] = w35;
            }
        } else {
            ((Hero *)D_001A4BE0)->f[0x1B4/4] = 0.0f;
            qzero((V4 *)(D_001A4BE0 + 0xF0));
        }
        if ((((Hero *)D_001A4BE0)->u[0x25C4/4] == 0x35) && (((Hero *)D_001A4BE0)->i[0xC0C/4] == 0)) {
            v35 = ((Hero *)D_001A4BE0)->f[0xC18/4];
            if ((v35 > 0.0f) && (v35 < 10.0f)) {
                func_004BBFA0(4, 1, 0);
            }
        }
        func_004C9A80(0.00168f);
        func_004C4A78(0);
        func_004D5780();
        }
        break;
    case 0x2F:
        {
        s32 anim;
        s32 blend;
        anim = -1;
        blend = 0;
        if (((Hero *)D_001A4BE0)->b[0x1474] != 0) {
            func_004C5BC0(0.7f, 0.0f);
        } else {
            func_004C5BC0(0.5f, 0.040000003f);
        }
        func_004CA000(3.7f, 0.0f, 0.35f);
        func_004C3F70(1.0f, 0);
        func_004C47F8(0.007080001f, 0.007080001f);
        qzero((V4 *)(D_001A4BE0 + 0xF0));
        func_004C9A80(0.007080001f);
        if (((Hero *)D_001A4BE0)->h[0x36E/2] != 0) {
            func_004DF7F0((s32)(D_001A4BE0 + 0xF0), (s32)(D_001A4BE0 + 0xF0) + 0x20, 0.010000001f);
            func_004C4938();
        } else {
            func_004DF7F0((s32)(D_001A4BE0 + 0xF0), (s32)(D_001A4BE0 + 0xF0), 0.0216f);
        }
        if ((anim != -1) && (*(u8 *)((u8 *)((Hero *)D_001A4BE0)->ptr[0x25C0/4] + 0x42) != 0x31)) {
            func_004DE428(anim, 0, (f32) blend);
        } else if ((*(u8 *)((u8 *)((Hero *)D_001A4BE0)->ptr[0x25C0/4] + 0x60) & 2) && (*(u8 *)((u8 *)((Hero *)D_001A4BE0)->ptr[0x25C0/4] + 0x42) == 0x31)) {
            func_004DE428(func_004B6260(0), 0, 4.0f);
        }
        }
        break;
    case 0x14:
        {
        s32 hit;
        s32 lim14;
        s32 t14;
        f32 spF8;
        f32 d14;
        f32 rise;
        f32 vy;
        f32 cap;
        if ((((Hero *)D_001A4BE0)->i[0xC0C/4] != 0) || (((Hero *)D_001A4BE0)->f[0xC18/4] < (f32) D_002F8A50[((Hero *)D_001A4BE0)->h[0xBDC/2]].w[0x18/4])) {
            ((Hero *)D_001A4BE0)->c[0x1219] = 2;
        }
        hit = 0;
        ((Hero *)D_001A4BE0)->f[0x1B0/4] = 0.0f;
        if ((((Hero *)D_001A4BE0)->b[0x1478] != 0) || (((Hero *)D_001A4BE0)->b[0x1477] != 0) || (((Hero *)D_001A4BE0)->b[0x147D] != 0) || (((Hero *)D_001A4BE0)->f[0x33C/4] > 4.0f)) {
            hit = 1;
        }
        if (((Hero *)D_001A4BE0)->i[0xBC4/4] != 0) {
            vec_sub_ab((V4 *)v0, (V4 *)(((Hero *)D_001A4BE0)->i[0xBC4/4] + 0x10), (V4 *)(D_001A4BE0 + 0x80));
            d14 = func_004DFCF0((s32)v0);
            if (((d14 > 2.0f) && (d14 < 5.0f)) || (hit != 0)) {
                ((Hero *)D_001A4BE0)->f[0x1B0/4] = 0.09f;
            }
            func_004C47F8(0.010000001f, 0.010000001f);
            func_0038CF68((s32)v10, (s32)D_001A4BE0, ((Hero *)D_001A4BE0)->f[0x1B4/4]);
            func_004DFE70((s32)(D_001A4BE0 + 0xF0), (s32)(D_001A4BE0 + 0xF0), 0.0f);
            vec_add_ab((V4 *)(D_001A4BE0 + 0xF0), (V4 *)(D_001A4BE0 + 0xF0), (V4 *)v10);
        } else {
            if ((hit != 0) && (((Hero *)D_001A4BE0)->i[0x1B8/4] < 0x3A)) {
                ((Hero *)D_001A4BE0)->f[0x1B0/4] = 0.09f;
            }
            func_004C47F8(0.006f, 0.006f);
            func_004DFE70((s32)(D_001A4BE0 + 0xF0), (s32)(D_001A4BE0 + 0xF0), ((Hero *)D_001A4BE0)->f[0x1B4/4]);
        }
        if ((((Hero *)D_001A4BE0)->i[0xBC8/4] != 0) || (((Hero *)D_001A4BE0)->i[0xBC4/4] != 0)) {
            ((Hero *)D_001A4BE0)->f[0x1A0/4] = ((Hero *)D_001A4BE0)->f[0xBCC/4];
            *(u128_t *)(&((Hero *)D_001A4BE0)->q[0x190/16]) = *(u128_t *)(&((Hero *)D_001A4BE0)->q[0xBA0/16]);
            func_004C44A0(0, 0.072000004f, 0.28800002f, 0.3385939f);
        } else if (((Hero *)D_001A4BE0)->f[0xC18/4] < 25.0f) {
            func_004C7BD0(8.0f, 1.0471976f, 1.0471976f);
        }
        rise = 0.15400001f;
        if (((Hero *)D_001A4BE0)->f[0x33C/4] > 2.25f) {
            rise = 0.07700001f;
        } else if (((Hero *)D_001A4BE0)->f[0x33C/4] > 1.8f) {
            rise = 0.10780001f;
        }
        if ((((Hero *)D_001A4BE0)->i[0xC0C/4] == 0) && (((Hero *)D_001A4BE0)->f[0xC18/4] > 23.5f) && (((Hero *)D_001A4BE0)->f[0x118/4] < 0.0f) && (((Hero *)D_001A4BE0)->h[0x36E/2] != 0)) {
            *(u128_t *)(v0) = *(u128_t *)(&((Hero *)D_001A4BE0)->q[0x80/16]);
            func_004DFA40((s32)v0, (s32)v0, -0.5f);
            func_0038CF68((s32)v10, (s32)D_001A4BE0, 2.0f);
            func_0041E800((s32)v30, (s32)((Hero *)D_001A4BE0)->ptr[0x25C0/4], 0x10000, 2.0f, (s32)v10);
            v30[3] = 5627.925f;
            (*(u8*)((u8*)v40+9)) = 1;
            (*(u16*)((u8*)v40+10)) = 0x47;
            (*(u8*)((u8*)v40+8)) = 0;
            func_003D4D00((s32)v0, 0x10, 0.4f, (s32)((Hero *)D_001A4BE0)->ptr[0x25C0/4], (s32)v30);
        }
        if (func_004C3F18(25.7f) != 0) {
            func_003CC0E0(0x19, 0);
            ((Hero *)D_001A4BE0)->h[0x1FA/2] = 0x2A;
            if (D_00142CBA[0] != 0) {
                ((Hero *)D_001E1680)->i[0x2C/4] = 0;
                ((Hero *)D_001E1680)->i[0x48/4] = 0x19;
                ((Hero *)D_001A4BE0)->h[0x224/2] = 0x1D;
                ((Hero *)D_001E1680)->f[0x40/4] = 0.1f;
            }
        }
        lim14 = 0xC;
        t14 = ((Hero *)D_001A4BE0)->i[0x1B8/4];
        if (t14 < 7) {
            vy = func_004DFD98((s32)(D_001A4BE0 + 0xF0));
            spF8 = vy;
            func_003C4138((s32)&spF8, rise, 0.060000002f);
            func_004DFDF0((s32)(D_001A4BE0 + 0xF0), (s32)(D_001A4BE0 + 0xF0), spF8);
        } else if (t14 > lim14) {
            func_004DF7F0((s32)(D_001A4BE0 + 0xF0), (s32)(D_001A4BE0 + 0xF0), 0.052f);
            if (func_004DFD98((s32)(D_001A4BE0 + 0xF0)) < 0.0f) {
                ((Hero *)D_001A4BE0)->f[0xBE0/4] = 1.0f;
            }
            cap = -0.74000007f;
            if (D_001D673C != 0) {
                cap = -1.4000001f;
            }
            if (func_004DFD98((s32)(D_001A4BE0 + 0xF0)) < cap) {
                func_004DFDF0((s32)(D_001A4BE0 + 0xF0), (s32)(D_001A4BE0 + 0xF0), cap);
            }
        }
        }
        break;
    case 0x15:
    case 0x88:
        {
        s32 near;
        s32 go;
        f32 dyaw;
        f32 dist;
        s32 lane;
        ((Hero *)D_001A4BE0)->f[0x1B0/4] = 0.0f;
        if ((((Hero *)D_001A4BE0)->i[0xC0C/4] != 0) || (((Hero *)D_001A4BE0)->f[0xC18/4] < (f32) D_002F8A50[((Hero *)D_001A4BE0)->h[0xBDC/2]].w[0x18/4])) {
            ((Hero *)D_001A4BE0)->c[0x1219] = 2;
        }
        go = (((Hero *)D_001A4BE0)->i[0x25D0/4] == 1) && (((Hero *)D_001A4BE0)->i[0x25D8/4] >= 0x12);
        if (go == 0) {
            if ((((Hero *)D_001A4BE0)->i[0xBC8/4] != 0) || (((Hero *)D_001A4BE0)->i[0xBC4/4] != 0)) {
                near = 0;
                if (((Hero *)D_001A4BE0)->b[0x25F4] != 0) {
                    dyaw = func_004C9B40((s32)(D_001A4BE0 + 0xBA0), 0);
                    dist = func_004C9B40((s32)(D_001A4BE0 + 0xBA0), 1);
                } else {
                    dyaw = func_0038DB00(((Hero *)D_001A4BE0)->f[0xBCC/4], ((Hero *)D_001A4BE0)->f[0x98/4]);
                    dist = func_004206B0(1, ((Hero *)D_001A4BE0)->f[0xBCC/4], ((Hero *)D_001A4BE0)->f[0x98/4]);
                }
                if (dist < 4.363323f) {
                    near = 1;
                }
                if (dyaw > 0.0f) {
                    ((Hero *)D_001A4BE0)->f[0xC00/4] = 1.0f / (dist + 1.0f);
                }
                ((Hero *)D_001A4BE0)->f[0x1A0/4] = ((Hero *)D_001A4BE0)->f[0xBCC/4];
                *(u128_t *)(&((Hero *)D_001A4BE0)->q[0x190/16]) = *(u128_t *)(&((Hero *)D_001A4BE0)->q[0xBA0/16]);
                if (near != 0) {
                    func_004C44A0(1, 0.08208001f, 0.28800002f, 0.3385939f);
                } else {
                    func_004C44A0(0, 0.08208001f, 0.28800002f, 0.3385939f);
                }
            } else {
                go = 1;
                if ((((Hero *)D_001A4BE0)->u[0x25C4/4] == 0x88) && (((Hero *)D_001A4BE0)->i[0x1B8/4] >= 0xA)) {
                    go = 0;
                } else if ((((Hero *)D_001A4BE0)->i[0xC0C/4] == 0) && (((Hero *)D_001A4BE0)->f[0xC18/4] > 6.0f)) {
                    go = 0;
                }
                if (go != 0) {
                    if (((Hero *)D_001A4BE0)->u[0x25C4/4] == 0x15) {
                        func_004C7BD0(14.0f, 0.5235988f, 0.7853982f);
                    }
                }
            }
        }
        if ((((Hero *)D_001A4BE0)->i[0xC0C/4] == 0) && (*(u8 *)((u8 *)((Hero *)D_001A4BE0)->ptr[0x25C0/4] + 0x43) == 0x1A) && (func_004C3F18(33.0f) != 0) && (((Hero *)D_001A4BE0)->u[0x25C4/4] == 0x15)) {
            lane = ((Hero *)D_001A4BE0)->i[0x1228/4];
            if ((lane == 0x7F) && (func_004E02C8(-1) != 0)) {
                func_004CA618();
            } else if ((lane == 0x7F) && (((Hero *)D_001A4BE0)->i[0x1228/4] == lane) && (func_004E02C8(-1) == 0)) {
                func_004D1568(0, 1);
            } else {
                func_004CA340();
            }
        }
        func_004C47F8(0.014800001f, 0.0112000005f);
        func_004C4848(99999.0f);
        if (((Hero *)D_001A4BE0)->h[0x36E/2] != 0) {
            func_004DF7F0((s32)(D_001A4BE0 + 0xF0), (s32)D_001A4BE0 + 0x130, 0.010000001f);
        } else {
            func_004DF7F0((s32)D_001A4BE0 + 0xF0, (s32)D_001A4BE0 + 0xF0, 0.0216f);
        }
        }
        break;
    case 0x13:
        {
        Rec2C *rec13;
        s32 tgt13;
        f32 d13;
        f32 lo13;
        f32 off13;
        f32 hi13;
        f32 r13;
        f32 dy13;
        f32 e13;
        s32 go13;
        if ((((Hero *)D_001A4BE0)->i[0xC0C/4] != 0) || (((Hero *)D_001A4BE0)->f[0xC18/4] < (f32) D_002F8A50[((Hero *)D_001A4BE0)->h[0xBDC/2]].w[0x20/4])) {
            ((Hero *)D_001A4BE0)->c[0x1219] = 2;
        }
        tgt13 = ((Hero *)D_001A4BE0)->i[0xBC4/4];
        ((Hero *)D_001A4BE0)->f[0x1B0/4] = 0.0f;
        rec13 = &D_002F8A50[((Hero *)D_001A4BE0)->h[0xBDC/2]];
        if ((tgt13 != 0) && (((Hero *)D_001A4BE0)->i[0x1B8/4] < 3)) {
            d13 = func_0038CF38(tgt13 + 0x10, (s32)D_001A4BE0 + 0x80);
            if (D_001D673C != 0) {
                d13 = func_0038CF00(((Hero *)D_001A4BE0)->i[0xBC4/4] + 0x10, (s32)D_001A4BE0 + 0x80);
            }
            d13 = d13 - 0.5f;
            if (d13 < 0.0f) {
                d13 = 0.0f;
            }
            if (rec13->w[1] == 0) {
                off13 = 0.75f;
                lo13 = 0.8f;
                hi13 = 4.0f;
            } else if (rec13->w[1] == 1) {
                off13 = 0.6f;
                lo13 = 1.7f;
                hi13 = 4.0f;
            } else {
                off13 = 1.3f;
                lo13 = 1.7f;
                hi13 = 1.9f;
            }
            if (((Hero *)D_001A4BE0)->i[0x234/4] != 0) {
                lo13 *= 3.0f;
            }
            e13 = d13 - off13;
            if (fabs_asm(e13) < lo13 + 3.0f) {
                r13 = e13 / 0.9f;
                if (r13 > hi13) {
                    r13 = hi13;
                }
                if (((Hero *)D_001A4BE0)->i[0x234/4] != 0) {
                    r13 *= 2.5f;
                }
                if (r13 > 1.0f) {
                    ((Hero *)D_001A4BE0)->f[0xBD4/4] = r13;
                }
            }
        }
        switch (rec13->w[1]) {
        case 0:
            if (((Hero *)D_001A4BE0)->f[0xC18/4] < 18.0f) {
                ((Hero *)D_001A4BE0)->f[0x1B0/4] = ((Hero *)D_001A4BE0)->f[0xBD4/4] * 0.08800001f;
            }
            break;
        case 1:
            if ((((Hero *)D_001A4BE0)->i[0xC0C/4] != 0) || (((Hero *)D_001A4BE0)->f[0xC18/4] < 9.0f)) {
                if (((Hero *)D_001A4BE0)->f[0xC18/4] > 8.0f) {
                    ((Hero *)D_001A4BE0)->f[0x1B0/4] = ((Hero *)D_001A4BE0)->f[0xBD4/4] * 0.060000002f;
                } else if (((Hero *)D_001A4BE0)->f[0xC18/4] > 7.0f) {
                    ((Hero *)D_001A4BE0)->f[0x1B0/4] = ((Hero *)D_001A4BE0)->f[0xBD4/4] * 0.09f;
                } else {
                    ((Hero *)D_001A4BE0)->f[0x1B0/4] = ((Hero *)D_001A4BE0)->f[0xBD4/4] * 0.11400001f;
                }
            }
            break;
        case 2:
            if ((((Hero *)D_001A4BE0)->i[0xC0C/4] != 0) || (((Hero *)D_001A4BE0)->f[0xC18/4] < 12.0f)) {
                ((Hero *)D_001A4BE0)->f[0x1B0/4] = ((Hero *)D_001A4BE0)->f[0xBD4/4] * 0.07400001f;
            }
            break;
        }
        func_003C4138((s32)D_001A4BE0 + 0xC00, 1.0f, 0.2f);
        if ((((Hero *)D_001A4BE0)->i[0xBC8/4] != 0) || (((Hero *)D_001A4BE0)->i[0xBC4/4] != 0)) {
            if (((Hero *)D_001A4BE0)->b[0x25F4] != 0) {
                dy13 = func_004C9B40((s32)D_001A4BE0 + 0xBA0, 0);
            } else {
                dy13 = func_0038DB00(((Hero *)D_001A4BE0)->f[0xBCC/4], ((Hero *)D_001A4BE0)->f[0x98/4]);
            }
            r13 = fabs_asm(dy13);
            if ((rec13->w[1] == 1) && (dy13 > 0.0f)) {
                ((Hero *)D_001A4BE0)->f[0xC00/4] = 1.0f / (r13 + 1.0f);
            }
            ((Hero *)D_001A4BE0)->f[0x1A0/4] = ((Hero *)D_001A4BE0)->f[0xBCC/4];
            *(u128_t *)(&((Hero *)D_001A4BE0)->q[0x190/16]) = *(u128_t *)(&((Hero *)D_001A4BE0)->q[0xBA0/16]);
            func_004C44A0(0, 0.072000004f, 0.28800002f, 0.3385939f);
        } else {
            go13 = 1;
            if ((rec13->w[1] == 1) && (((Hero *)D_001A4BE0)->i[0xC0C/4] == 0) && (((Hero *)D_001A4BE0)->f[0xC18/4] > 7.0f)) {
                go13 = 0;
            }
            if (go13 != 0) {
                func_004C7BD0(5.0f, 0.7853982f, 0.7853982f);
            }
        }
        func_004C47F8(0.014800001f, 0.0112000005f);
        if (((Hero *)D_001A4BE0)->i[0xBC8/4] != 0) {
            if (((Hero *)D_001A4BE0)->b[0x25F4] != 0) {
                func_004C4908((s32)D_001A4BE0 + 0xBA0);
            } else {
                func_004C4848(((Hero *)D_001A4BE0)->f[0xBCC/4]);
            }
        } else {
            func_004C4848(99999.0f);
        }
        if (((Hero *)D_001A4BE0)->h[0x36E/2] != 0) {
            func_004DF7F0((s32)D_001A4BE0 + 0xF0, (s32)D_001A4BE0 + 0x130, 0.010000001f);
        } else {
            func_004DF7F0((s32)D_001A4BE0 + 0xF0, (s32)D_001A4BE0 + 0xF0, 0.0216f);
        }
        func_004CA000(3.7f, 0.0f, 0.35f);
        }
        break;
    case 0x7C:
        func_003C4138((s32)(D_001A4BE0 + 0x1B4), 0.0f, 0.0096f);
        if (D_001D673C != 0) {
            func_0038CF68((s32)(D_001A4BE0 + 0xF0), (s32)(D_001A4BE0 + 0xBB0), ((Hero *)D_001A4BE0)->f[0x1B4/4]);
            if (((Hero *)D_001A4BE0)->f[0x33C/4] > 0.0f) {
                func_004DF7F0((s32)(D_001A4BE0 + 0xF0), (s32)(D_001A4BE0 + 0x130), 0.010000001f);
            } else {
                func_004DFDF0((s32)(D_001A4BE0 + 0xF0), (s32)(D_001A4BE0 + 0xF0), 0.0f);
            }
            func_0038CE20((s32)(D_001A4BE0 + 0x190), (s32)(D_001A4BE0 + 0x190) + 0xA20, -1.0f);
        } else {
            ((Hero *)D_001A4BE0)->f[0xF0/4] = func_0038D098(((Hero *)D_001A4BE0)->f[0xBD0/4]) * ((Hero *)D_001A4BE0)->f[0x1B4/4];
            ((Hero *)D_001A4BE0)->f[0xF4/4] = func_0038D0B0(((Hero *)D_001A4BE0)->f[0xBD0/4]) * ((Hero *)D_001A4BE0)->f[0x1B4/4];
            if (((Hero *)D_001A4BE0)->f[0x33C/4] > 0.0f) {
                ((Hero *)D_001A4BE0)->f[0xF8/4] = ((Hero *)D_001A4BE0)->f[0x128/4] - 0.010000001f;
            } else {
                ((Hero *)D_001A4BE0)->f[0xF8/4] = 0.0f;
            }
            ((Hero *)D_001A4BE0)->f[0x1A0/4] = func_0038DAB8(((Hero *)D_001A4BE0)->f[0xBD0/4], 3.1415927f);
        }
        func_004C44A0(0, 0.072000004f, 0.28800002f, 0.3385939f);
        break;
    case 0x22:
        ((Hero *)D_001A4BE0)->f[0x1B0/4] = 0.0f;
        if (((Hero *)D_001A4BE0)->i[0xBC8/4] != 0) {
            ((Hero *)D_001A4BE0)->f[0x1A0/4] = ((Hero *)D_001A4BE0)->f[0xBCC/4];
            *(u128_t *)(&((Hero *)D_001A4BE0)->q[0x190/16]) = *(u128_t *)(&((Hero *)D_001A4BE0)->q[0xBA0/16]);
            func_004C44A0(0, 0.057600003f, 0.28800002f, 0.3385939f);
        } else {
            func_004C7BD0(11.0f, 0.87266463f, -1.0f);
        }
        func_004C47F8(0.012f, 0.014f);
        func_004C4848(99999.0f);
        if (((Hero *)D_001A4BE0)->h[0x36E/2] != 0) {
            func_004DF7F0((s32)D_001A4BE0 + 0xF0, (s32)D_001A4BE0 + 0x110, 0.0216f);
            func_004C4938();
        } else {
            func_004DF7F0((s32)D_001A4BE0 + 0xF0, (s32)D_001A4BE0 + 0xF0, 0.0216f);
        }
        break;
    case 0x2:
    case 0x75:
        {
        f32 f1a;
        f32 f1b;
        f32 scale;
        f32 lim2;
        f32 k13;
        f32 ab;
        f32 ab2;
        f32 lim2b;
        f32 lim2c;
        f32 spd;
        if (!((((Hero *)D_001A4BE0)->h[0x1434/2] != 0) || ((((Hero *)D_001A4BE0)->i[0x16B0/4] == 1) && (func_004373F0(0x28, 2, 0, 0) != 0)))) {
            if (((Hero *)D_001A4BE0)->f[0x174/4] < 0.034f) {
                ((Hero *)D_001A4BE0)->b[0x3EC] = 1;
                if (fabs_asm(((Hero *)D_001A4BE0)->f[0x1A8/4]) > 2.0943952f) {
                    if (((Hero *)D_001A4BE0)->f[0x2838/4] == 1.0f) {
                        ((Hero *)D_001A4BE0)->b[0x3EF] = 1;
                    }
                }
            }
            f1b = func_00437520(1, 0);
            if (func_0038DBA0(f1b, func_00437520(7, 0)) > 1.9198622f) {
                if (fabs_asm(((Hero *)D_001A4BE0)->f[0x1A8/4]) > 1.2217305f) {
                    if (((Hero *)D_001A4BE0)->f[0x2838/4] == 1.0f) {
                        ((Hero *)D_001A4BE0)->b[0x3EF] = 1;
                        ((Hero *)D_001A4BE0)->b[0x3EC] = 1;
                    }
                }
            }
            if (fabs_asm(((Hero *)D_001A4BE0)->f[0x1A8/4]) < 0.08726646f) {
                ((Hero *)D_001A4BE0)->b[0x3EC] = 0;
            }
        }
        if ((((Hero *)D_001A4BE0)->i[0x1E8/4] < 2) && (fabs_asm(((Hero *)D_001A4BE0)->f[0x1A8/4]) > 1.5707964f) && (((Hero *)D_001A4BE0)->b[0x1436] != 0)) {
            ((Hero *)D_001A4BE0)->b[0x3EF] = 1;
            ((Hero *)D_001A4BE0)->b[0x3EC] = 1;
        }
        if ((((Hero *)D_001A4BE0)->b[0x3EF] != 0) && (fabs_asm(((Hero *)D_001A4BE0)->f[0x1A8/4]) < 0.06981317f)) {
            ((Hero *)D_001A4BE0)->b[0x3EF] = 0;
        }
        if (((Hero *)D_001A4BE0)->f[0x2838/4] < 0.2f) {
            if (((Hero *)D_001A4BE0)->i[0x3F0/4] != 0) {
                ((Hero *)D_001A4BE0)->b[0x3EF] = 1;
            }
            *(u128_t *)(&((Hero *)D_001A4BE0)->q[0x190/16]) = *(u128_t *)(&((Hero *)D_001A4BE0)->q[0x3D0/16]);
            ((Hero *)D_001A4BE0)->f[0x1A0/4] = ((Hero *)D_001A4BE0)->f[0x3E8/4];
            ((Hero *)D_001A4BE0)->f[0x1B0/4] = 0.0f;
        } else {
            func_004C42C8();
            if ((func_004BEA50(0) == 9) && ((((Hero *)D_001A4BE0)->f[0x283C/4] == 1.0f) || (((Hero *)D_001A4BE0)->i[0x3F0/4] != 0)) && (((Hero *)D_001A4BE0)->b[0x25EB] == 0)) {
                *(u128_t *)(&((Hero *)D_001A4BE0)->q[0x3D0/16]) = *(u128_t *)(&((Hero *)D_001A4BE0)->q[0x190/16]);
                ((Hero *)D_001A4BE0)->f[0x3E8/4] = ((Hero *)D_001A4BE0)->f[0x1A0/4];
                ((Hero *)D_001A4BE0)->i[0x3F0/4] = 1;
            } else {
                *(u128_t *)(&((Hero *)D_001A4BE0)->q[0x3D0/16]) = *(u128_t *)(&((Hero *)D_001A4BE0)->q[0x0/16]);
                ((Hero *)D_001A4BE0)->f[0x3E8/4] = ((Hero *)D_001A4BE0)->f[0x98/4];
            }
        }
        if (((Hero *)D_001A4BE0)->f[0x9F0/4] > 0.0f) {
            func_004C5BC0(0.7f, 0.0f);
            (*(u128_t*)v0) = ((Hero *)D_001A4BE0)->q[0x9E0/16];
            f1a = ((Hero *)D_001A4BE0)->f[0x1B0/4] + func_004C5C58((s32)v0);
            ((Hero *)D_001A4BE0)->f[0x1B0/4] = f1a;
            if (f1a < 0.014f) {
                ((Hero *)D_001A4BE0)->f[0x1B0/4] = 0.014f;
            }
            qzero((V4 *)(D_001A4BE0 + 0x9E0));
        }
        scale = 1.0f;
        if ((((Hero *)D_001A4BE0)->h[0x1434/2] != 0) || ((((Hero *)D_001A4BE0)->i[0x16B0/4] == 1) && (func_004373F0(0x28, 2, 0, 0) != 0))) {
            func_004C3B20();
        } else {
            ((Hero *)D_001A4BE0)->f[0x1438/4] = ((Hero *)D_001A4BE0)->f[0x98/4];
            *(u128_t *)(&((Hero *)D_001A4BE0)->q[0x1420/16]) = *(u128_t *)(&((Hero *)D_001A4BE0)->q[0x0/16]);
            if ((((Hero *)D_001A4BE0)->i[0x25C8/4] == 1) && (((Hero *)D_001A4BE0)->b[0x3EF] == 0) && (((Hero *)D_001A4BE0)->b[0x25EB] == 0)) {
                func_004C44A0(0, 0.053280003f, 0.1872f, 0.2443461f);
            } else {
                ab = fabs_asm(((Hero *)D_001A4BE0)->f[0x1A8/4]);
                if (((((Hero *)D_001A4BE0)->f[0x2838/4] < 0.9f) || ((((Hero *)D_001A4BE0)->b[0x25EB] != 0) && (((Hero *)D_001A4BE0)->b[0x3EF] == 0))) && (ab > 0.7853982f)) {
                    scale = 0.0f;
                }
                func_004C4590();
            }
        }
        func_004C81B8();
        func_004C9290();
        if (((Hero *)D_001A4BE0)->b[0x3EF] != 0) {
            lim2 = 0.12340001f - fabs_asm(((Hero *)D_001A4BE0)->f[0x1A8/4]) * 0.11000001f / 3.1415927f;
            if (lim2 < 0.0f) {
                lim2 = 0.0f;
            }
            if (lim2 < ((Hero *)D_001A4BE0)->f[0x1B0/4]) {
                ((Hero *)D_001A4BE0)->f[0x1B0/4] = lim2;
            }
        }
        spd = scale * 0.014800001f;
        k13 = 0.012f;
        if (((Hero *)D_001A4BE0)->b[0x3EF] != 0) {
            lim2b = 2.6179938f - ((Hero *)D_001A4BE0)->f[0x1A8/4];
            if (lim2b > 1.0f) {
                lim2b = 1.0f;
            }
            if (lim2b < 0.2f) {
                lim2b = 0.2f;
            }
            k13 = 0.0068000006f;
            ((Hero *)D_001A4BE0)->f[0x1B0/4] = ((Hero *)D_001A4BE0)->f[0x1B0/4] * lim2b;
        }
        ab2 = fabs_asm(((Hero *)D_001A4BE0)->f[0x1A8/4]);
        if ((((Hero *)D_001A4BE0)->f[0x2838/4] < 0.75f) && (ab2 > 0.61086524f)) {
            lim2c = 1.0f - ab2 * 0.4f;
            if (lim2c < 0.0f) {
                lim2c = 0.0f;
            }
            ((Hero *)D_001A4BE0)->f[0x1B0/4] = ((Hero *)D_001A4BE0)->f[0x1B0/4] * lim2c;
        }
        func_004C47F8(spd, k13);
        if ((((Hero *)D_001A4BE0)->b[0x3EC] != 0) || (((Hero *)D_001A4BE0)->h[0x1434/2] != 0) || ((((Hero *)D_001A4BE0)->i[0x16B0/4] == 1) && (func_004373F0(0x28, 2, 0, 0) != 0))) {
            if (((Hero *)D_001A4BE0)->b[0x25F4] == 0) {
                if ((((Hero *)D_001A4BE0)->h[0x1434/2] != 0) || ((((Hero *)D_001A4BE0)->i[0x16B0/4] == 1) && (func_004373F0(0x28, 2, 0, 0) != 0))) {
                    func_004C4848(((Hero *)D_001A4BE0)->f[0x1438/4]);
                } else {
                    func_004C4848(((Hero *)D_001A4BE0)->f[0x1A0/4]);
                }
            } else if ((((Hero *)D_001A4BE0)->h[0x1434/2] != 0) || ((((Hero *)D_001A4BE0)->i[0x16B0/4] == 1) && (func_004373F0(0x28, 2, 0, 0) != 0))) {
                func_004C4908((s32) (D_001A4BE0 + 0x1420));
            } else {
                func_004C4908((s32) (D_001A4BE0 + 0x190));
            }
        } else {
            func_004C4848(99999.0f);
        }
        func_004C4A78(0);
        if (((Hero *)D_001A4BE0)->h[0x214/2] != 0) {
            func_004CA000(5.0f, 0.2f, 0.35f);
        }
        if (((Hero *)D_001A4BE0)->h[0x36E/2] != 0) {
            func_004DF7F0((s32)D_001A4BE0 + 0xF0, (s32)D_001A4BE0 + 0x130, 0.010000001f);
            func_004C4938();
        } else {
            func_004DF7F0((s32)D_001A4BE0 + 0xF0, (s32)D_001A4BE0 + 0xF0, 0.0216f);
        }
        }
        break;
    case 0x80:
        {
        f32 tilt;
        s32 n80;
        s32 lim80;
        s32 cnt80;
        s32 i80;
        f32 cl80;
        func_004C9C38(4, (s32) ((Hero *)D_001A4BE0)->ptr[0x25C0/4], 0xD);
        func_003CC0E0(0x16, 0);
        func_004C3F70(1.0f, 0);
        ((Hero *)D_001A4BE0)->f[0x1B0/4] = 0.23000002f;
        func_004BB2C8((s32)v0, (s32) (D_001A4BE0 + 0x970), 0.24480002f);
        tilt = ((Hero *)D_001A4BE0)->f[0x2838/4] * 0.024434611f * v0[0];
        if ((D_001D673C == 0) && (((Hero *)D_001A4BE0)->i[0x1B8/4] < 0x32)) {
            ((Hero *)D_001A4BE0)->f[0x1B0/4] = 0.6f;
        }
        n80 = ((Hero *)D_001A4BE0)->i[0x1B8/4];
        lim80 = 0x2A;
        if (n80 < lim80) {
            tilt *= (f32)n80 / (f32)lim80;
        }
        if ((n80 >= 0x12) && (func_004CA000(2.5f, 0.0f, 1.5f) != 0)) {
            ((Hero *)D_001A4BE0)->i[0x984/4] = 1;
        }
        if (((Hero *)D_001A4BE0)->f[0x2838/4] > 0.2f) {
            func_004C4368(0.0f, 0.0f, tilt);
        }
        func_004C47F8(0.040000003f, 0.006f);
        func_004C4848(99999.0f);
        if (D_001D673C != 0) {
            *(u128_t *)(v10) = *(u128_t *)(&((Hero *)D_001A4BE0)->q[0x2F0/16]);
            func_004DFA40((s32)v10, (s32)v10, 0.17f);
            func_00420410((s32) (D_001A4BE0 + 0x80), (s32)v10, (s32) (D_001A4BE0 + 0x980), 0.057600003f, 0.43200004f, 0.15f);
        } else {
            func_00420370((s32) (D_001A4BE0 + 0x88), (s32) (D_001A4BE0 + 0x980), ((Hero *)D_001A4BE0)->f[0x338/4] + 0.17f, 0.057600003f, 0.43200004f, 0.15f);
        }
        func_0038CE20((s32)v10, (s32)(D_001A4BE0 + 0x110), 3.0f);
        vec_add_ab((V4 *)v10, (V4 *)v10, (V4 *)(D_001A4BE0 + 0xE0));
        cnt80 = func_003D4D00((s32)v10, 0, 0.57f, (s32) ((Hero *)D_001A4BE0)->ptr[0x25C0/4], 0);
        if (cnt80 != 0) {
            func_0038CE20((s32)v20, (s32)(D_001A4BE0 + 0x110), 7.0f);
            for (i80 = 0; i80 < cnt80; i80++) {
                if (func_003C4B50(((s32 *)D_001EC440)[i80]) != 0) {
                    func_0041EB10(((s32 *)D_001EC440)[i80], (s32) ((Hero *)D_001A4BE0)->ptr[0x25C0/4], 0x10000, (s32) (D_001A4BE0 + 0x80), (s32)v20, 1.0f);
                }
            }
        }
        func_004BC480(0.024480002f, 0.43200004f);
        func_004BC4B0(0.036000002f, 0.43200004f);
        func_004BC4C8(0.0432f, 0.38880002f);
        cl80 = tilt * 27.0f;
        if (cl80 > 1.7f) {
            cl80 = 1.7f;
        } else if (cl80 < -1.7f) {
            cl80 = -1.7f;
        }
        ((Hero *)D_002F6CC0)->f[0x60/4] = -cl80;
        ((Hero *)D_002F6CC0)->f[0x278/4] = cl80 * 0.5f;
        ((Hero *)D_002F6CC0)->f[0x1C8/4] = cl80 * 0.5f;
        }
        break;
    case 0x17:
    case 0x18:
        {
        vec_sub_ba((V4 *)(D_001A4BE0 + 0x190), (V4 *)(D_001A4BE0 + 0x510), (V4 *)(D_001A4BE0 + 0x500));
        ((Hero *)D_001A4BE0)->f[0x1A0/4] = func_0038D160(((Hero *)D_001A4BE0)->f[0x190/4], ((Hero *)D_001A4BE0)->f[0x194/4]);
        func_004C44A0(0, 0.057600003f, 0.28800002f, 0.12566371f);
        if (((Hero *)D_001A4BE0)->b[0x25F4] != 2) {
            func_00420760((s32)(D_001A4BE0 + 0x94), 0, 0.0f, 0.09424779f);
        }
        vec_sub_ab((V4 *)(D_001A4BE0 + 0xF0), (V4 *)(D_001A4BE0 + 0x500), (V4 *)(D_001A4BE0 + 0x80));
        func_003C4BB0((s32)(D_001A4BE0 + 0xF0), 0.080000006f);
        func_003C4138((s32)(D_001A4BE0 + 0x530), ((Hero *)D_001A4BE0)->f[0x88/4], 0.060000002f);
        }
        break;
    case 0x46:
    case 0x47:
        {
        vec_sub_ba((V4 *)(D_001A4BE0 + 0x190), (V4 *)(D_001A4BE0 + 0x510), (V4 *)(D_001A4BE0 + 0x500));
        ((Hero *)D_001A4BE0)->f[0x1A0/4] = func_0038D160(((Hero *)D_001A4BE0)->f[0x190/4], ((Hero *)D_001A4BE0)->f[0x194/4]);
        func_004C44A0(0, 0.028800001f, 0.28800002f, 0.09424779f);
        vec_sub_ab((V4 *)(D_001A4BE0 + 0xF0), (V4 *)(D_001A4BE0 + 0x500), (V4 *)(D_001A4BE0 + 0x80));
        func_003C4BB0((s32)(D_001A4BE0 + 0xF0), 0.034f);
        func_003C4138((s32)(D_001A4BE0 + 0x530), ((Hero *)D_001A4BE0)->f[0x88/4], 0.060000002f);
        }
        break;
    case 0x19:
    case 0x1A:
        {
        vec_sub_ba((V4 *)(D_001A4BE0 + 0x190), (V4 *)(D_001A4BE0 + 0x510), (V4 *)(D_001A4BE0 + 0x500));
        ((Hero *)D_001A4BE0)->f[0x1A0/4] = func_0038D160(((Hero *)D_001A4BE0)->f[0x190/4], ((Hero *)D_001A4BE0)->f[0x194/4]);
        func_004C44A0(0, 0.028800001f, 0.28800002f, 0.09424779f);
        vec_sub_ab((V4 *)v60, (V4 *)(D_001A4BE0 + 0x510), (V4 *)(D_001A4BE0 + 0x500));
        qzero((V4 *)(D_001A4BE0 + 0xF0));
        if (((Hero *)D_001A4BE0)->u[0x25C4/4] == 0x19) {
            func_0038CE90((s32)v40, (s32)D_001A4BE0 + 0x2E0, (s32)v60);
        } else {
            func_0038CE90((s32)v40, (s32)v60, (s32)D_001A4BE0 + 0x2E0);
        }
        func_0038CF68((s32)v40, (s32)v40, 0.2f);
        vec_add_ba((V4 *)v50, (V4 *)(D_001A4BE0 + 0x80), (V4 *)v40);
        if (func_004BE168((s32)D_001A4BE0 + 0x80, (s32)D_001A4BE0 + 0x90, 0) == 0) {
            break;
        }
        if (func_004BE168((s32)v50, (s32)D_001A4BE0 + 0x90, (s32)v0) != 0) {
            vec_sub_ba((V4 *)(D_001A4BE0 + 0xF0), (V4 *)v0, (V4 *)(D_001A4BE0 + 0x80));
            func_0038CF68((s32)D_001A4BE0 + 0xF0, (s32)D_001A4BE0 + 0xF0, D_001DA540[(s32)((Hero *)D_001A4BE0)->f[0xC18/4]] * 0.5f);
        }
        }
        break;
    case 0x6:
    case 0x2C:
        func_004C42C8();
        if (((Hero *)D_001A4BE0)->h[0x1E0/2] == 0) {
            func_004C7210();
        }
        func_004C81B8();
        func_004C5BC0(0.7f, 0.0f);
        func_004DF7F0((s32)D_001A4BE0 + 0xF0, (s32)D_001A4BE0 + 0xF0, ((Hero *)D_001A4BE0)->f[0xA00/4]);
        if (func_004DFD98((s32)D_001A4BE0 + 0xF0) < -1.0000001f) {
            func_004DFDF0((s32)D_001A4BE0 + 0xF0, (s32)D_001A4BE0 + 0xF0, -1.0000001f);
        }
        break;
    case 0x79:
        ((Hero *)D_001A4BE0)->c[0x25ED] = 1;
        func_003C4138((s32)D_001A4BE0 + 0xA08, ((Hero *)D_001A4BE0)->f[0xA10/4], 0.0034906587f);
        func_003C4138((s32)D_001A4BE0 + 0xA0C, ((Hero *)D_001A4BE0)->f[0xA14/4], 0.0034906587f);
        func_004BB628(((Hero *)D_001A4BE0)->f[0xA08/4], ((Hero *)D_001A4BE0)->f[0xA0C/4], 0.0f);
        func_003E7DA0((s32)D_001A4BE0 + 0xF0, (s32)D_001A4BE0 + 0xF0, func_0038CED8((s32)D_001A4BE0 + 0xF0) * 0.88f);
        func_004DF7F0((s32)D_001A4BE0 + 0xF0, (s32)D_001A4BE0 + 0xF0, ((Hero *)D_001A4BE0)->f[0xA00/4]);
        if (func_004DFD98((s32)D_001A4BE0 + 0xF0) < -1.0000001f) {
            func_004DFDF0((s32)D_001A4BE0 + 0xF0, (s32)D_001A4BE0 + 0xF0, -1.0000001f);
        }
        break;
    case 0x8:
        {
        f32 g8;
        f32 m8;
        f32 h8;
        f32 sp8;
        if (func_004BEA50(3) == 2) {
            s32 t279C = ((Hero *)D_001A4BE0)->i[0x279C/4];
            if (t279C != -1) {
                u8 *o = (u8 *)D_001A30B0 + (t279C << 7);
                if ((*(void **)(o + 0xDC) == ((Hero *)D_001A4BE0)->ptr[0x25C0/4]) && (*(u8 *)(o + 0xD0) != 0)) {
                    func_003A4F28(t279C);
                }
            }
            ((Hero *)D_001A4BE0)->i[0x279C/4] = -1;
            func_004C9C38(3, (s32) ((Hero *)D_001A4BE0)->ptr[0x25C0/4], 2);
        } else {
            s32 t2798 = ((Hero *)D_001A4BE0)->i[0x2798/4];
            if (t2798 != -1) {
                u8 *o = (u8 *)D_001A30B0 + (t2798 << 7);
                if ((*(void **)(o + 0xDC) == ((Hero *)D_001A4BE0)->ptr[0x25C0/4]) && (*(u8 *)(o + 0xD0) != 0)) {
                    func_003A4F28(t2798);
                }
            }
            ((Hero *)D_001A4BE0)->i[0x2798/4] = -1;
            func_004C9C38(4, (s32) ((Hero *)D_001A4BE0)->ptr[0x25C0/4], 0xD);
        }
        g8 = 0.060000002f;
        if (((Hero *)D_001A4BE0)->i[0x1318/4] == 3) {
            g8 = 0.10000001f;
        }
        h8 = ((Hero *)D_001A4BE0)->f[0x284C/4];
        m8 = 0.72f;
        if (h8 != 0.0f) {
            m8 = h8;
        }
        sp8 = func_004DFD98((s32)D_001A4BE0 + 0xF0);
        func_004C3F70(g8, 0);
        func_004C44A0(0, 0.036000002f, 0.43200004f, 0.25132743f);
        func_004C47F8(0.006f, 0.0028000001f);
        func_004C4848(99999.0f);
        func_004C81B8();
        func_004DFC08((s32)D_001A4BE0 + 0xF0, (s32)D_001A4BE0 + 0xF0);
        func_00420370((s32)&sp8, (s32)D_001A4BE0 + 0xA18, -g8 * m8, 0.036000002f, 0.43200004f, 0.34000003f);
        func_004DF7F0((s32)D_001A4BE0 + 0xF0, (s32)D_001A4BE0 + 0xF0, -sp8);
        if (((Hero *)D_001A4BE0)->f[0x88/4] < ((Hero *)D_001A4BE0)->f[0x460/4]) {
            func_003C4138((s32)D_001A4BE0 + 0x460, ((Hero *)D_001A4BE0)->f[0x88/4], 0.080000006f);
        }
        func_004BD870();
        }
        break;
    case 0x7:
    case 0x9:
    case 0xA:
    case 0xB:
    case 0xC:
    case 0xD:
    case 0xE:
    case 0xF:
    case 0x10:
    case 0x11:
    case 0x12:
    case 0x1B:
    case 0x38:
    case 0x45:
    case 0x48:
    case 0x54:
    case 0x5F:
    case 0x69:
    case 0x6B:
    case 0x73:
    case 0x86:
    case 0xA2:
    case 0xA7:
    case 0xAC:
        {
        s32 end7;
        s32 t7;
        s32 st7;
        f32 keep7;
        f32 v7;
        f32 cap7;
        s32 n7;
        s32 i7;
        if ((((Hero *)D_001A4BE0)->u[0x25C4/4] == 0x1B) && (((Hero *)D_001A4BE0)->h[0x2884/2] == 0) && (((Hero *)D_001A4BE0)->i[0x1318/4] == 3)) {
            if (func_004C3F18(10.0f) != 0) {
                func_004C9B90(4, 0);
            }
        }
        if ((((Hero *)D_001A4BE0)->h[0x4F8/2] != 0) && (((Hero *)D_001A4BE0)->b[0x1474] != 0)) {
            ((Hero *)D_001A4BE0)->f[0x1B0/4] = ((Hero *)D_001A4BE0)->f[0x1B4/4];
        } else if (((Hero *)D_001A4BE0)->u[0x25C4/4] == 0x69) {
            ((Hero *)D_001A4BE0)->f[0x1B0/4] = ((Hero *)D_001A4BE0)->f[0x1B4/4];
            if ((((Hero *)D_001A4BE0)->b[0x46C] != 0) && (((Hero *)D_001A4BE0)->f[0x1B4/4] > 0.12340001f)) {
                ((Hero *)D_001A4BE0)->f[0x1B0/4] = 0.12340001f;
            }
        } else {
            if (((Hero *)D_001A4BE0)->b[0x46C] != 0) {
                func_004C3F70(0.12340001f, 0);
            }
            func_004C3F70(((Hero *)D_001A4BE0)->f[0x474/4], 0);
        }
        if (((Hero *)D_001A4BE0)->u[0x25C4/4] == 0x12) {
            if (((Hero *)D_001A4BE0)->i[0x1B8/4] == 0x11) {
                func_004BC250(3, 0x10, 1);
                if (D_001DFD90 != 0) {
                    func_0049CCB8(D_001DFD90, D_001DFD98, 0, ((Hero *)D_001A4BE0)->f[0x80/4], ((Hero *)D_001A4BE0)->f[0x84/4], 0.4f, 0.35f);
                }
            }
            v7 = ((Hero *)D_001A4BE0)->f[0xC18/4];
            if ((v7 >= 4.0f) && (v7 <= 7.0f)) {
                func_004BBFA0(7, 0, 0);
            }
        }
        end7 = ((Hero *)D_001A4BE0)->h[0x47C/2];
        t7 = ((Hero *)D_001A4BE0)->i[0x1B8/4];
        if (t7 == end7) {
            *(u128_t *)(&((Hero *)D_001A4BE0)->q[0x430/16]) = *(u128_t *)(&((Hero *)D_001A4BE0)->q[0x80/16]);
        }
        if ((((Hero *)D_001A4BE0)->b[0x46C] != 0) || ((t7 < end7) && (st7 = ((Hero *)D_001A4BE0)->u[0x25C4/4], (st7 != 0xB)) && (st7 != 0x10) && (st7 != 0xC) && (st7 != 0x11) && (st7 != 0x1B) && (st7 != 0x48))) {
            if (((Hero *)D_001A4BE0)->b[0x25E4] != 5) {
                func_004C44A0(0, 0.0216f, 0.28800002f, 0.30019665f);
            }
            keep7 = ((Hero *)D_001A4BE0)->f[0x1B4/4];
            if (((Hero *)D_001A4BE0)->b[0x46C] >= 2) {
                ((Hero *)D_001A4BE0)->f[0x1B4/4] = keep7 * 0.4f;
            }
            if ((((Hero *)D_001A4BE0)->h[0x1434/2] != 0) || ((((Hero *)D_001A4BE0)->i[0x16B0/4] == 1) && (func_004373F0(0x28, 2, 0, 0) != 0))) {
                func_004C4848(((Hero *)D_001A4BE0)->f[0x1438/4]);
            } else {
                func_004C4848(99999.0f);
            }
            ((Hero *)D_001A4BE0)->f[0x1B4/4] = keep7;
            if (((Hero *)D_001A4BE0)->b[0x46C] != 1) {
                func_004C47F8(((Hero *)D_001A4BE0)->f[0x4D0/4], ((Hero *)D_001A4BE0)->f[0x4D4/4]);
            }
            if (((Hero *)D_001A4BE0)->b[0x46C] != 0) {
                if (D_001D52FC->i[0x1D4/4] != 0) {
                    if (((Hero *)D_001A4BE0)->h[0x36A/2] != 0) {
                        ((Hero *)D_001A4BE0)->f[0x1B4/4] = 0.0f;
                    }
                }
                if (((Hero *)D_001A4BE0)->b[0x46C] != 0) {
                    func_004C9A80(((Hero *)D_001A4BE0)->f[0x4D4/4]);
                }
            }
            func_004C5BC0(0.5f, 0.040000003f);
            if (((Hero *)D_001A4BE0)->u[0x25C4/4] == 9) {
                s32 c9 = ((Hero *)D_001A4BE0)->i[0x1B8/4];
                if (c9 < (((Hero *)D_001A4BE0)->h[0x47C/2] + 3)) {
                    func_004DFA60((s32)(D_001A4BE0 + 0xF0), (s32)(D_001A4BE0 + 0xF0), (f32) c9 * 0.0064000003f);
                }
            }
            if (((Hero *)D_001A4BE0)->u[0x25C4/4] == 0xA) {
                s32 cA = ((Hero *)D_001A4BE0)->i[0x1B8/4];
                if (cA < 0x1C) {
                    func_004DFA60((s32)(D_001A4BE0 + 0xF0), (s32)(D_001A4BE0 + 0xF0), (f32) cA * 0.021200001f);
                }
            }
            if ((((Hero *)D_001A4BE0)->i[0x1B8/4] < 8) && (((Hero *)D_001A4BE0)->f[0x2838/4] > 0.2f)) {
                *(u128_t *)(v0) = *(u128_t *)(&((Hero *)D_001A4BE0)->q[0x80/16]);
                func_004DFB68((s32)v0, (s32)v0, 0.5f);
                func_004DFA60((s32)v10, (s32)v0, 0.95f);
                if (func_003D3CB0((s32)v0, (s32)v10, 4, (s32) ((Hero *)D_001A4BE0)->ptr[0x25C0/4], 0) != 0) {
                    ((Hero *)D_001A4BE0)->h[0x4F4/2] = 1;
                }
            }
        } else {
            func_004C7210();
            if (((Hero *)D_001A4BE0)->u[0x25C4/4] == 0x12) {
                cap7 = func_0038CED8((s32)(D_001A4BE0 + 0xF0));
                if (cap7 > 0.07400001f) {
                    cap7 = 0.07400001f;
                }
                func_0038CFB8((s32)(D_001A4BE0 + 0xF0), (s32)(D_001A4BE0 + 0xF0), cap7);
            }
        }
        {
        f32 a338 = ((Hero *)D_001A4BE0)->f[0x338/4];
        f32 a460 = ((Hero *)D_001A4BE0)->f[0x460/4];
        if (a460 < a338) {
            f32 n460 = a460 + 0.120000005f;
            ((Hero *)D_001A4BE0)->f[0x460/4] = n460;
            if (a338 < n460) {
                ((Hero *)D_001A4BE0)->f[0x460/4] = a338;
            }
        }
        }
        {
        f32 a88 = ((Hero *)D_001A4BE0)->f[0x88/4];
        if (a88 < ((Hero *)D_001A4BE0)->f[0x460/4]) {
            ((Hero *)D_001A4BE0)->f[0x460/4] = a88;
        }
        }
        if ((((Hero *)D_001A4BE0)->h[0x47C/2] < ((Hero *)D_001A4BE0)->i[0x1B8/4]) && (func_004DFD98((s32)(D_001A4BE0 + 0xF0)) < 0.001f) && ((((Hero *)D_001A4BE0)->b[0x46D] == 0) || (((Hero *)D_001A4BE0)->i[0x1B8/4] > ((Hero *)D_001A4BE0)->i[0x404/4])) && ((((Hero *)D_001A4BE0)->u[0x25C4/4] != 0xE) || (((Hero *)D_001A4BE0)->i[0x1B8/4] >= 0xF))) {
            f32 a428 = ((Hero *)D_001A4BE0)->f[0x428/4];
            ((Hero *)D_001A4BE0)->b[0x46E] = 1;
            if (a428 != 0.0f) {
                ((Hero *)D_001A4BE0)->f[0x4F0/4] = a428;
            }
        }
        if (((Hero *)D_001A4BE0)->b[0x25E4] == 0) {
            func_004C81B8();
        }
        if (((Hero *)D_001A4BE0)->b[0x25E4] == 1) {
            func_004C8F30();
        }
        st7 = ((Hero *)D_001A4BE0)->u[0x25C4/4];
        if ((st7 == 0x10) || (st7 == 0xD)) {
            if (D_001439F4[0] != 2) {
                func_00426510((s32)(D_001A4BE0 + 0x1B90), (((Hero *)D_001A4BE0)->i[0x1B8/4] < 0xB) ? 0 : 2);
            }
        }
        if (((Hero *)D_001A4BE0)->u[0x25C4/4] == 0x86) {
            func_00426510((s32)(D_001A4BE0 + 0x1B90), (((Hero *)D_001A4BE0)->i[0x1B8/4] < 0xC) ? 0 : 2);
        }
        if ((((Hero *)D_001A4BE0)->u[0x25C4/4] == 0x10) && (((Hero *)D_001A4BE0)->i[0x1B8/4] >= 8) && (((Hero *)D_001A4BE0)->f[0xC18/4] < 28.0f)) {
            func_004DF9D0((s32)v0, 1, 0.8f, 0.0f, 0.3f);
            n7 = func_003D4D00((s32)v0, 0, 0.9f, (s32) ((Hero *)D_001A4BE0)->ptr[0x25C0/4], 0);
            if (n7 != 0) {
                func_0038CE20((s32)v10, (s32)D_001A4BE0 + 0x110, 7.0f);
                for (i7 = 0; i7 < n7; i7++) {
                    if (func_003C4B50(((s32 *)D_001EC440)[i7]) != 0) {
                        func_0041EB10(((s32 *)D_001EC440)[i7], (s32) ((Hero *)D_001A4BE0)->ptr[0x25C0/4], 0x10000, (s32)D_001A4BE0 + 0x80, (s32)v10, 1.0f);
                    }
                }
            }
        }
        func_004C6BC0();
        func_004BD870();
        }
        break;
    case 0x16:
    case 0xB1:
        {
        f32 sp16;
        f32 dec16;
        sp16 = func_004DFCF0((s32)(D_001A4BE0 + 0xF0));
        dec16 = 0.0016000001f;
        if ((((Hero *)D_001A4BE0)->h[0x36E/2] == 0) && (((Hero *)D_001A4BE0)->i[0x1B8/4] >= 9)) {
            dec16 = 0.004f;
        }
        sp16 = sp16 - dec16;
        if (sp16 < 0.0f) {
            sp16 = 0.0f;
        }
        if (((Hero *)D_001A4BE0)->b[0x1479] != 0) {
            func_004CA000(3.7f, 0.0f, 0.35f);
        }
        func_004DFE70((s32)D_001A4BE0 + 0xF0, (s32)D_001A4BE0 + 0xF0, sp16);
        func_004DF7F0((s32)D_001A4BE0 + 0xF0, (s32)D_001A4BE0 + 0xF0, 0.004f);
        }
        break;
    case 0x91:
        qzero((V4 *)(D_001A4BE0 + 0xF0));
        if (((Hero *)D_001A4BE0)->h[0x36E/2] != 0) {
            ((Hero *)D_001A4BE0)->f[0xF8/4] = -0.46000004f;
        }
        break;
    case 0x66:
        {
        f32 len66;
        f32 sc66;
        s32 n66;
        s32 i66;
        void *o66;
        vec_sub_ab((V4 *)v0, (V4 *)(D_001A4BE0 + 0x1B40), (V4 *)(D_001A4BE0 + 0x80));
        ((Hero *)D_001A4BE0)->f[0x1A0/4] = func_0038D160(v0[0], v0[1]);
        if (D_001D673C != 0) {
            len66 = func_0038CEA8((s32)v0);
        } else {
            len66 = func_0038CED8((s32)v0);
        }
        if (len66 > 0.3f) {
            if (D_001D673C != 0) {
                Hero *g66 = (Hero *)D_001A4BE0;
                g66->f[0x2838/4] = 1.0f;
                *(u128_t *)(&g66->q[0x190/16]) = *(u128_t *)(&g66->q[0x1B60/16]);
                g66->f[0x1B0/4] = len66;
                if (len66 < D_001DBD84[2]) {
                    g66->f[0x1B0/4] = D_001DBD84[1] * 0.020000001f;
                } else {
                    g66->f[0x1B0/4] = D_001DBD84[5] * 0.020000001f;
                }
            } else {
                Hero *h66 = (Hero *)D_001A4BE0;
                h66->f[0x2838/4] = 1.0f;
                h66->f[0x1A0/4] = func_0038D160(v0[0], v0[1]);
                h66->f[0x1B0/4] = len66;
                if (len66 < D_001DBD84[2]) {
                    h66->f[0x1B0/4] = D_001DBD84[1] * 0.020000001f;
                } else {
                    h66->f[0x1B0/4] = D_001DBD84[5] * 0.020000001f;
                }
            }
            if (((Hero *)D_001A4BE0)->b[0x25E4] == 1) {
                ((Hero *)D_001A4BE0)->f[0x1B0/4] = 0.018000001f;
            }
        } else {
            if (D_001D673C != 0) {
                ((Hero *)D_001A4BE0)->f[0x2838/4] = 1.0f;
                *(u128_t *)(&((Hero *)D_001A4BE0)->q[0x190/16]) = *(u128_t *)(&((Hero *)D_001A4BE0)->q[0x1B60/16]);
                ((Hero *)D_001A4BE0)->f[0x1B0/4] = 0.0f;
            } else {
                ((Hero *)D_001A4BE0)->f[0x2838/4] = 1.0f;
                ((Hero *)D_001A4BE0)->f[0x1A0/4] = ((Hero *)D_001A4BE0)->f[0x1B4C/4];
                ((Hero *)D_001A4BE0)->f[0x1B0/4] = 0.0f;
            }
        }
        sc66 = 1.0f;
        if (((Hero *)D_001A4BE0)->b[0x25E4] == 3) {
            func_004C44A0(0, 0.0432f, 0.43200004f, 0.16406097f);
        } else if (((Hero *)D_001A4BE0)->b[0x25E4] == 1) {
            func_004C44A0(0, 0.0432f, 0.43200004f, 0.15707964f);
        } else if (((Hero *)D_001A4BE0)->b[0x25E4] == 0) {
            func_004C44A0(0, 0.0432f, 0.43200004f, 0.15707964f);
        }
        if (((Hero *)D_001A4BE0)->b[0x25E4] == 0) {
            func_004C81B8();
        }
        func_004C47F8(sc66 * 0.014800001f, 0.012f);
        if (D_001D673C != 0) {
            func_004C4908((s32)(D_001A4BE0 + 0x190));
        } else {
            func_004C4848(99999.0f);
        }
        if (((Hero *)D_001A4BE0)->b[0x25E4] == 0) {
            func_004C4A78(0);
        }
        if (((Hero *)D_001A4BE0)->h[0x36E/2] != 0) {
            func_004DF7F0((s32)D_001A4BE0 + 0xF0, (s32)D_001A4BE0 + 0x110, 0.010000001f);
            func_004C4938();
        } else {
            func_004DF7F0((s32)D_001A4BE0 + 0xF0, (s32)D_001A4BE0 + 0xF0, 0.0216f);
        }
        *(u128_t *)v10 = *(u128_t *)(&((Hero *)D_001A4BE0)->q[0xE0/16]);
        n66 = func_003D4D00((s32)v10, 0, ((Hero *)D_001A4BE0)->f[0x284/4] + 0.2f, (s32) ((Hero *)D_001A4BE0)->ptr[0x25C0/4], 0);
        for (i66 = 0; i66 < n66; i66++) {
            o66 = ((void **)D_001EC440)[i66];
            if ((o66 != 0) && (*(s16 *)((u8 *)o66 + 0xAA) == 0xCB)) {
                func_0041EB10((s32)o66, (s32) ((Hero *)D_001A4BE0)->ptr[0x25C0/4], 0x10000, (s32)D_001A4BE0 + 0xE0, (s32)D_001D66B0, 100.0f);
            }
        }
        }
        break;
    case 0x67:
        vec_sub_ab((V4 *)v0, (V4 *)(D_001A4BE0 + 0x1B40), (V4 *)(D_001A4BE0 + 0x80));
        if (func_0038CE68((s32)v0, (s32)(D_001A4BE0 + 0x160)) < 0.0f) {
            qzero((V4 *)(D_001A4BE0 + 0x160));
        }
        qzero((V4 *)(D_001A4BE0 + 0xF0));
        func_004C9A80(0.0108f);
        func_004C4A78(0);
        if (((Hero *)D_001A4BE0)->h[0x36E/2] != 0) {
            func_004DF7F0((s32)D_001A4BE0 + 0xF0, (s32)D_001A4BE0 + 0x110, 0.010000001f);
            func_004C4938();
        } else {
            func_004DF7F0((s32)D_001A4BE0 + 0xF0, (s32)D_001A4BE0 + 0xF0, 0.0216f);
        }
        break;
    case 0x68:
        qzero((V4 *)(D_001A4BE0 + 0xF0));
        ((Hero *)D_001A4BE0)->i[0x1B4/4] = 0;
        func_004C4848(99999.0f);
        if (((Hero *)D_001A4BE0)->b[0x25E4] == 0) {
            func_004C4A78(0);
        }
        if (((Hero *)D_001A4BE0)->h[0x36E/2] != 0) {
            func_004DF7F0((s32)D_001A4BE0 + 0xF0, (s32)D_001A4BE0 + 0x110, 0.010000001f);
            func_004C4938();
        } else {
            func_004DF7F0((s32)D_001A4BE0 + 0xF0, (s32)D_001A4BE0 + 0xF0, 0.0216f);
        }
        break;
    case 0x6A:
        {
        f32 a;
        f32 b;
        qzero((V4 *)(D_001A4BE0 + 0xF0));
        a = ((Hero *)D_001A4BE0)->f[0x354/4];
        b = ((Hero *)D_001A4BE0)->f[0x88/4];
        if ((0.5f * (f32)((Hero *)D_001A4BE0)->i[0x1B70/4]) < (a - b)) {
            func_004DFC08((s32)D_001A4BE0 + 0xF0, (s32)D_001A4BE0 + 0xF0);
            func_004DF7F0((s32)D_001A4BE0 + 0xF0, (s32)D_001A4BE0 + 0xF0, 0.0050000004f);
        } else {
            func_004DFC08((s32)D_001A4BE0 + 0xF0, (s32)D_001A4BE0 + 0xF0);
            func_004DF7F0((s32)D_001A4BE0 + 0xF0, (s32)D_001A4BE0 + 0xF0, 0.020000001f);
        }
        }
        break;
    case 0x7D:
        qzero((V4 *)(D_001A4BE0 + 0xF0));
        func_004DFC08((s32)D_001A4BE0 + 0xF0, (s32)D_001A4BE0 + 0xF0);
        func_004DF7F0((s32)D_001A4BE0 + 0xF0, (s32)D_001A4BE0 + 0xF0, 0.020000001f);
        break;
    case 0x3F:
    case 0x43:
        func_004CA000(3.7f, 0.0f, 0.35f);
        func_004C3F70(1.0f, 0);
        ((Hero *)D_001A4BE0)->f[0x1B0/4] = 0.0f;
        func_004C47F8(0.0f, 0.00504f);
        qzero((V4 *)(D_001A4BE0 + 0xF0));
        func_004C4A78(0);
        if (((Hero *)D_001A4BE0)->h[0x36E/2] != 0) {
            func_004DF7F0((s32)D_001A4BE0 + 0xF0, (s32)D_001A4BE0 + 0x130, 0.010000001f);
            func_004C4938();
        } else {
            func_004DF7F0((s32)D_001A4BE0 + 0xF0, (s32)D_001A4BE0 + 0xF0, 0.0216f);
        }
        break;
    case 0x4D:
        {
        Rec2C *rec;
        s32 tgt;
        f32 d;
        s32 side;
        f32 sp4D;
        tgt = ((Hero *)D_001A4BE0)->i[0xBC4/4];
        rec = &D_002F8A50[((Hero *)D_001A4BE0)->h[0xBDC/2]];
        ((Hero *)D_001A4BE0)->f[0x1B0/4] = 0.0f;
        sp4D = 0.09f;
        if (tgt != 0) {
            d = func_0038CF38((s32)D_001A4BE0 + 0x80, tgt + 0x10);
            if (d > 1.1f) {
                sp4D = 0.15f;
            }
            if (d > 0.7f) {
                sp4D = 0.11400001f;
            }
        }
        if (rec->w[1] == 0) {
            if (((Hero *)D_001A4BE0)->f[0xC18/4] < 7.5f) {
                ((Hero *)D_001A4BE0)->f[0x1B0/4] = sp4D;
            }
        } else if (rec->w[1] == 1) {
            if (((Hero *)D_001A4BE0)->f[0xC18/4] < 7.5f) {
                ((Hero *)D_001A4BE0)->f[0x1B0/4] = sp4D;
            }
        }
        if ((((Hero *)D_001A4BE0)->i[0xC0C/4] == 0) && ((f32)rec->w[7] <= ((Hero *)D_001A4BE0)->f[0xC18/4]) && (((Hero *)D_001A4BE0)->f[0xC18/4] <= (f32)rec->w[8])) {
            side = 2;
            if (rec->w[1] == 1) {
                side = 0;
            }
            func_003C2F58((s32)((Hero *)D_001A4BE0)->ptr[0x25C0/4], side, (s32)v10);
            func_003C2F58((s32)((Hero *)D_001A4BE0)->ptr[0x25C0/4], side | 1, (s32)v20);
            vec_add_ab((V4 *)v0, (V4 *)v10, (V4 *)v20);
            func_0038CE20((s32)v0, (s32)v0, 0.5f);
            func_0041E820((s32)((Hero *)D_001A4BE0)->ptr[0x25C0/4], 0.25f, (s32)v0, 0x10000, 1.0f, 1.0f, 0, 1, 0);
        }
        func_003C4138((s32)D_001A4BE0 + 0xC00, 1.0f, 0.2f);
        if ((((Hero *)D_001A4BE0)->i[0xBC8/4] != 0) || (((Hero *)D_001A4BE0)->i[0xBC4/4] != 0)) {
            ((Hero *)D_001A4BE0)->f[0x1A0/4] = ((Hero *)D_001A4BE0)->f[0xBCC/4];
            func_004C44A0(0, 0.072000004f, 0.28800002f, 0.3385939f);
        } else {
            func_004C7BD0(3.0f, 0.7853982f, 0.7853982f);
        }
        func_004C47F8(0.014800001f, 0.0112000005f);
        if (((Hero *)D_001A4BE0)->i[0xBC8/4] != 0) {
            if (((Hero *)D_001A4BE0)->b[0x25F4] == 2) {
                func_004C4908((s32)D_001A4BE0 + 0xBA0);
            } else {
                func_004C4848(((Hero *)D_001A4BE0)->f[0xBCC/4]);
            }
        } else {
            func_004C4848(99999.0f);
        }
        if (((Hero *)D_001A4BE0)->h[0x36E/2] != 0) {
            ((Hero *)D_001A4BE0)->f[0xF8/4] = ((Hero *)D_001A4BE0)->f[0x118/4] - 0.010000001f;
            func_004C4938();
        } else {
            ((Hero *)D_001A4BE0)->f[0xF8/4] = ((Hero *)D_001A4BE0)->f[0xF8/4] - 0.0216f;
        }
        func_004CA000(0.7f, 0.0f, 0.3f);
        }
        break;
    case 0x4B:
        func_004C3F70(0.040000003f, 0);
        func_004C44A0(0, 0.057600003f, 0.28800002f, 0.19896755f);
        func_004C47F8(0.006f, 0.0028000001f);
        func_004C4848(99999.0f);
        func_004DFC08((s32)(D_001A4BE0 + 0xF0), (s32)(D_001A4BE0 + 0xF0));
        func_004DF7F0((s32)(D_001A4BE0 + 0xF0), (s32)(D_001A4BE0 + 0xF0), 0.028800003f);
        break;
    case 0x4E:
    case 0x7B:
        ((Hero *)D_001A4BE0)->f[0x1A0/4] = ((Hero *)D_001A4BE0)->f[0x34C/4];
        ((Hero *)D_001A4BE0)->f[0x1B0/4] = 0.11000001f;
        func_004C67B0(0.010000001f);
        func_004DF7F0((s32)D_001A4BE0 + 0xF0, (s32)D_001A4BE0 + 0x130, 0.0072000003f);
        break;
    case 0x4F:
        qzero((V4 *)(D_001A4BE0 + 0xF0));
        func_004DF7F0((s32)(D_001A4BE0 + 0xF0), (s32)(D_001A4BE0 + 0xF0), 0.0048f);
        break;
    case 0x41:
        func_004C3F70(0.06600001f, 0);
        if (((Hero *)D_001A4BE0)->h[0x1E0/2] == 0) {
            func_004C7210();
        }
        func_004DF7F0((s32)D_001A4BE0 + 0xF0, (s32)D_001A4BE0 + 0xF0, 0.0048f);
        if (((Hero *)D_001A4BE0)->f[0xF8/4] < -0.20000002f) {
            ((Hero *)D_001A4BE0)->f[0xF8/4] = -0.20000002f;
        }
        break;
    case 0x44:
        if (((Hero *)D_001A4BE0)->f[0xF8/4] > 0.0f) {
            func_004BB628(0.0f, 0.25132743f, 0.0f);
        }
        func_004DF7F0((s32)D_001A4BE0 + 0xF0, (s32)D_001A4BE0 + 0xF0, 0.008f);
        break;
    case 0x40:
    case 0x4C:
        {
        f32 a40;
        f32 c40;
        f32 m40;
        f32 b40;
        func_004C3F70(0.06600001f, 0);
        c40 = 0.19896755f;
        a40 = 0.04752f;
        if (((Hero *)D_001A4BE0)->b[0x3EF] != 0) {
            c40 = 0.23387413f;
            a40 = 0.053280003f;
        }
        func_004C44A0(0, a40, 0.21600002f, c40);
        func_004C47F8(0.014800001f, 0.012f);
        if (((Hero *)D_001A4BE0)->f[0x174/4] < 0.014f) {
            ((Hero *)D_001A4BE0)->b[0x3EC] = 1;
            if ((fabs_asm(((Hero *)D_001A4BE0)->f[0x1A8/4]) > 1.7453293f) && (((Hero *)D_001A4BE0)->f[0x2838/4] > 0.8f)) {
                ((Hero *)D_001A4BE0)->b[0x3EF] = 1;
            }
        }
        m40 = func_00437520(0, 0);
        if (func_0038DBA0(m40, func_00437520(2, 0)) > 2.6179938f) {
            if ((fabs_asm(((Hero *)D_001A4BE0)->f[0x1A8/4]) > 1.2217305f) && (((Hero *)D_001A4BE0)->f[0x2838/4] > 0.8f)) {
                ((Hero *)D_001A4BE0)->b[0x3EF] = 1;
                ((Hero *)D_001A4BE0)->b[0x3EC] = 1;
            }
        }
        if (fabs_asm(((Hero *)D_001A4BE0)->f[0x1A8/4]) < 0.08726646f) {
            ((Hero *)D_001A4BE0)->b[0x3EC] = 0;
        }
        if (((Hero *)D_001A4BE0)->b[0x3EF] != 0) {
            if (fabs_asm(((Hero *)D_001A4BE0)->f[0x1A8/4]) < 0.06981317f) {
                ((Hero *)D_001A4BE0)->b[0x3EF] = 0;
            }
            if (((Hero *)D_001A4BE0)->b[0x3EF] != 0) {
                b40 = 0.06600001f - fabs_asm(((Hero *)D_001A4BE0)->f[0x1A8/4]) * 0.080000006f / 3.1415927f;
                if (b40 < 0.0f) {
                    b40 = 0.0f;
                }
                if (b40 < ((Hero *)D_001A4BE0)->f[0x1B0/4]) {
                    ((Hero *)D_001A4BE0)->f[0x1B0/4] = b40;
                }
            }
        }
        if (((Hero *)D_001A4BE0)->b[0x3EC] != 0) {
            func_004C4848(((Hero *)D_001A4BE0)->f[0x1A0/4]);
        } else {
            func_004C4848(99999.0f);
        }
        func_004C4A78(0);
        if (((Hero *)D_001A4BE0)->h[0x36E/2] != 0) {
            func_004DF7F0((s32)D_001A4BE0 + 0xF0, (s32)D_001A4BE0 + 0x130, 0.010000001f);
            func_004C4938();
        } else {
            func_004DF7F0((s32)D_001A4BE0 + 0xF0, (s32)D_001A4BE0 + 0xF0, 0.0216f);
        }
        }
        break;
    case 0x42:
        {
        f32 var_f12_r4;
        var_f12_r4 = func_0038CED8((s32)(D_001A4BE0 + 0xF0));
        if (((Hero *)D_001A4BE0)->h[0x36E/2] != 0) {
            var_f12_r4 *= 0.94f;
        } else {
            var_f12_r4 *= 0.76f;
        }
        func_003E7DA0((s32)(D_001A4BE0 + 0xF0), (s32)(D_001A4BE0 + 0xF0), var_f12_r4);
        ((Hero *)D_001A4BE0)->i[0xF8/4] = 0;
        if (((Hero *)D_001A4BE0)->h[0x36E/2] != 0) {
            func_004DF7F0((s32)(D_001A4BE0 + 0xF0), (s32)(D_001A4BE0 + 0xF0) + 0x30, 0.0088f);
        } else {
            func_004DF7F0((s32)(D_001A4BE0 + 0xF0), (s32)(D_001A4BE0 + 0xF0), 0.004f);
        }
        }
        break;
    case 0x49:
    case 0x4A:
        {
        ((Hero *)D_001A4BE0)->f[0xC00/4] = 1.3f;
        vec_sub_ba((V4 *)(D_001A4BE0 + 0x190), (V4 *)(D_001A4BE0 + 0x510), (V4 *)(D_001A4BE0 + 0x500));
        ((Hero *)D_001A4BE0)->f[0x1A0/4] = func_0038D160(((Hero *)D_001A4BE0)->f[0x190/4], ((Hero *)D_001A4BE0)->f[0x194/4]);
        func_004C44A0(0, 0.028800001f, 0.28800002f, 0.09424779f);
        vec_sub_ab((V4 *)v60, (V4 *)(D_001A4BE0 + 0x510), (V4 *)(D_001A4BE0 + 0x500));
        qzero((V4 *)(D_001A4BE0 + 0xF0));
        if (((Hero *)D_001A4BE0)->u[0x25C4/4] == 0x49) {
            func_0038CE90((s32)v40, (s32)D_001A4BE0 + 0x2E0, (s32)v60);
        } else {
            func_0038CE90((s32)v40, (s32)v60, (s32)D_001A4BE0 + 0x2E0);
        }
        func_0038CF68((s32)v40, (s32)v40, 0.2f);
        vec_add_ba((V4 *)v50, (V4 *)(D_001A4BE0 + 0x80), (V4 *)v40);
        if (func_004BE168((s32)D_001A4BE0 + 0x80, (s32)D_001A4BE0 + 0x90, 0) == 0) {
            break;
        }
        if (func_004BE168((s32)v50, (s32)D_001A4BE0 + 0x90, (s32)v0) != 0) {
            vec_sub_ba((V4 *)(D_001A4BE0 + 0xF0), (V4 *)v0, (V4 *)(D_001A4BE0 + 0x80));
            func_0038CF68((s32)D_001A4BE0 + 0xF0, (s32)D_001A4BE0 + 0xF0, D_002F2380[(s32)((Hero *)D_001A4BE0)->f[0xC18/4]] * 0.5f);
        }
        }
        break;
    case 0x51:
    case 0x56:
    case 0x59:
        func_004CA000(3.7f, 0.0f, 0.35f);
        func_004C3F70(1.0f, 0);
        ((Hero *)D_001A4BE0)->f[0x1B0/4] = 0.0f;
        func_004C47F8(0.0f, 0.007080001f);
        qzero((V4 *)(D_001A4BE0 + 0xF0));
        func_004C9A80(0.007080001f);
        func_004C4A78(0);
        if (((Hero *)D_001A4BE0)->h[0x36E/2] != 0) {
            func_004DF7F0((s32)D_001A4BE0 + 0xF0, (s32)D_001A4BE0 + 0x130, 0.010000001f);
            func_004C4938();
        } else {
            func_004DF7F0((s32)D_001A4BE0 + 0xF0, (s32)D_001A4BE0 + 0xF0, 0.0216f);
        }
        break;
    case 0x57:
        ((Hero *)D_001A4BE0)->f[0x1A0/4] = ((Hero *)D_001A4BE0)->f[0x34C/4];
        ((Hero *)D_001A4BE0)->f[0x1B0/4] = 0.11000001f;
        func_004C67B0(0.010000001f);
        func_004DF7F0((s32)(D_001A4BE0 + 0xF0), (s32)D_001A4BE0 + 0x130, 0.0072000003f);
        break;
    case 0x58:
        qzero((V4 *)(D_001A4BE0 + 0xF0));
        break;
    case 0x53:
        func_004C3F70(0.10000001f, 0);
        if (((Hero *)D_001A4BE0)->h[0x1E0/2] == 0) {
            func_004C7210();
        }
        if (((Hero *)D_001A4BE0)->h[0x202/2] >= 0x12) {
            func_0041E820((s32)((Hero *)D_001A4BE0)->ptr[0x25C0/4], 1.0f, (s32)D_001A4BE0 + 0x80, 0xA, 1.0f, 1.0f, 0, 1, 0);
        }
        func_004DF7F0((s32)D_001A4BE0 + 0xF0, (s32)D_001A4BE0 + 0xF0, 0.008400001f);
        if (((Hero *)D_001A4BE0)->f[0xF8/4] < -0.3f) {
            ((Hero *)D_001A4BE0)->f[0xF8/4] = -0.3f;
        }
        break;
    case 0x52:
        {
        f32 var_f21_r3;
        f32 var_f20_r3;
        f32 var_f2_r3;
        var_f21_r3 = func_0038DBA0(((Hero *)D_001A4BE0)->f[0x98/4], ((Hero *)D_001A4BE0)->f[0x1A0/4]);
        func_004C3F70(0.10000001f, 0);
        if (((Hero *)D_001A4BE0)->f[0x1B0/4] < 0.055000007f) {
            ((Hero *)D_001A4BE0)->f[0x1B0/4] = 0.055000007f;
        }
        var_f20_r3 = 1.0f;
        var_f20_r3 -= var_f21_r3 * 0.3f;
        var_f2_r3 = ((Hero *)D_001A4BE0)->f[0x2838/4] + 0.35f;
        if (var_f20_r3 < 0.0f) {
            var_f20_r3 = 0.0f;
        }
        func_004C44A0(0, var_f2_r3 * 0.050400004f, 0.14400001f, var_f2_r3 * 0.16406097f);
        func_004C47F8(var_f20_r3 * 0.014800001f, 0.012f);
        if ((((Hero *)D_001A4BE0)->b[0x3EC] != 0) && (((Hero *)D_001A4BE0)->h[0x368/2] == 0)) {
            func_004C4848(((Hero *)D_001A4BE0)->f[0x1A0/4]);
        } else {
            func_004C4848(99999.0f);
        }
        func_004C4A78(0);
        if (((Hero *)D_001A4BE0)->h[0x36E/2] != 0) {
            func_004DF7F0((s32)D_001A4BE0 + 0xF0, (s32)D_001A4BE0 + 0x130, 0.010000001f);
            func_004C4938();
        } else {
            func_004DF7F0((s32)D_001A4BE0 + 0xF0, (s32)D_001A4BE0 + 0xF0, 0.0216f);
        }
        }
        break;
    case 0x55:
        {
        f32 var_f12_r3;
        var_f12_r3 = func_0038CED8((s32)(D_001A4BE0 + 0xF0));
        if (((Hero *)D_001A4BE0)->h[0x36E/2] != 0) {
            var_f12_r3 *= 0.98800004f;
        } else {
            var_f12_r3 *= 0.90400004f;
        }
        func_003E7DA0((s32)(D_001A4BE0 + 0xF0), (s32)(D_001A4BE0 + 0xF0), var_f12_r3);
        ((Hero *)D_001A4BE0)->i[0xF8/4] = 0;
        if (((Hero *)D_001A4BE0)->h[0x36E/2] != 0) {
            func_004DF7F0((s32)(D_001A4BE0 + 0xF0), (s32)(D_001A4BE0 + 0xF0) + 0x30, 0.0088f);
        } else {
            func_004DF7F0((s32)(D_001A4BE0 + 0xF0), (s32)(D_001A4BE0 + 0xF0), 0.004f);
        }
        }
        break;
    case 0x3C:
    case 0x64:
    case 0x65:
        qzero((V4 *)(D_001A4BE0 + 0xF0));
        break;
    }
    if (sp114 != ((Hero *)D_001A4BE0)->i[0x25C8/4]) {
        ((Hero *)D_001A4BE0)->i[0x1C0/4] = 0;
    }
    if (sp118 != (*(u8 *)((u8 *)(temp_fp) + 0x43))) {
        ((Hero *)D_001A4BE0)->i[0x1C4/4] = 0;
    }
}
/* localdecomp:end func_L27_004CA9C8 */

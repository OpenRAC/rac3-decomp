/* func_L30_004C4318: hero per-frame state machine on the vidcomic levels (family A2 member, 7 places,
   docs/contributing/large-function-families.md), func_L01_004F5E98 plus this level's states 0x9A-0xAE.
   Near miss, Opus family A, fourth pass of 2026-11-08: 9457 instructions as retail; 9451 lines
   (99.9 percent) and 9453 opcodes equal (kit/famA/c.sh). Two of the 8 differing rows are the
   jump-table %hi/%lo the checker leaves unresolved in a non-matching function.
   Fourth pass: the level's states written from retail (004CC5C8-004CD224): 0x9D, 0x9A/0x9F/0xA0/
   0xA3/0xAE, 0xAB (the 0x1B30 rail: lean, end check, the 0x36/0x3D/0x37/0x39 animations), 0xAD (the
   0x690 path follower, as 0x76's tail), 0xA8/0xA9, 0x9C/0xA1 (the 0x1B3E ledge test), 0x9B, 0xA6
   (the two func_003D3CB0 probes) and 0x9E; with them the 0x17/0x18, 0x46/0x47, 0x19/0x1A, 0x8F/0x90
   and frame differences went away. Details that mattered:
   - func_L01_005110E8's int flag last in the prototype (s32, f32, f32, f32, s32): retail loads it
     after the floats at 0xA6's calls; the other call site still matches;
   - 0xAB's last-point offset through a local, iAB = (count - 1) * 16, else fold distributes it;
   - 0x9E's decrement through a local preset to 0.002f, raised to 0.004f;
   - the 0x27 group's lean calls func_L30_004BCB20 (the root's func_L01_004EE850 has no L30 place);
   - D_L30_001DBC4C is a $gp scalar: extern f32 plus `.extern D_L30_001DBC4C, 4`;
   - func_L01_00446780 returns s32 as its definition does.
   Left (6 rows, both sched2/reorg argument order):
   - 0x9C/0xA1, second func_L01_004E63F0 call: retail fills the beqz slot with mov.s $f13 and the
     jal slot with move $a0; mine the reverse. Making the &sp9C pointer live past the call (all uses
     through a pointer) gives retail's order there, so retail's sched1 saw that pseudo live on; the
     form that keeps the later sp+0x11C load has not been found.
   - 0xAD's func_L01_00476B98 call: retail loads $f12 (999.0) before $a1/$t1; mine $t1, $a1 first.
     Prototype float/int reorders break the other three call sites.
   Needs "-mvu0-use-vf0-vf2 -O2 -G8 -fopt-stack -mno-check-zero-division @ps2as" on its file,
   include/vu0.h, its config/levels/divs_nops.txt row WITH ITS 12th ENTRY AT 0 (as the root's:
   "func_L30_004C4318 2 0 2 0 0 2 1 0 2 2 0 0 0 2 0 0 1 2 1 2 2"), and sqrt_asm at both sqrt.s of
   case 0x2B. The hero tunables are one small-data array (docs/build/globals.md).
   Measure: kit/famA/c.sh FILE FUNC 30_vidcomic_unnamed:jtbl_002BC500 --cases. */
typedef int u128_t __attribute__((mode(TI)));
typedef union { u8 b[0x2600]; s8 c[0x2600]; s16 h[0x1300]; u16 uh[0x1300]; s32 i[0x980]; u32 u[0x980]; f32 f[0x980]; void *ptr[0x980]; long d[0x4C0]; u128_t q[0x260]; } Hero;
typedef struct { s32 x0[7]; s32 x1C; u8 x20[0xC0]; } LevelInfo;
typedef struct { s32 w[11]; } Rec2C;
typedef struct { u8 x0[0x18]; s32 x18; u8 x1C[0xD4]; } ItemDef;
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4;
extern s32 func_L01_00446780(s32, f32, s32, s32, f32, f32, s32, s32, s32);
extern void func_L30_004C0028(void);
extern void func_L01_004E60E8(void);
extern Hero *D_001D52FC;
extern u8 D_001425C0[];
extern ItemDef D_L30_002C3E80[];
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
extern s32 D_L30_001D673C;
extern s32 D_L30_001DF2C0;
extern s32 D_L30_001E0790;
extern s32 D_L30_001E0798;
extern u8 D_L30_001E22C0[];
extern u8 D_L30_001E22D8[];
extern u8 D_L30_001ED080[];
extern u8 D_L30_002F2EE0[];
extern Rec2C D_L30_002F4C70[];
extern u8 D_L30_002F4F90[];
extern s32 func_003D3CB0(s32, s32, s32, s32, s32);
extern s32 func_003D4D00(s32, s32, f32, s32, s32);
extern s32 func_0038CAD0(s32);
extern s32 func_0038CB00(s32);
extern void func_L01_004F4730(f32);
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
extern void func_L01_0046ADE0(s32, s32, f32);
extern void func_L01_004E9090(s32);
extern f32 func_L01_00443A18(f32, f32);
extern void func_L01_00466F50(s32, s32, s32, f32, f32);
extern s32 func_L01_00476B98(s32, s32, s32, s32, s32, s32, f32, f32, f32);
extern s32 func_L01_00476498(s32, s32, s32, s32, f32, s32);
extern s32 func_L01_00476440(s32, s32, s32, s32);
extern void func_L01_004F5540(void);
extern void func_L01_004F47F0(void);
extern void *func_003C24B0(s32, s32);
extern void func_003C7C38(void *);
extern s32 func_003A52A0(s32, s32, void *);
extern void func_0038D328(s32, s32);
extern void func_0038D5B0(s32, s32);
extern void func_0038D028(s32, s32, s32);
extern s32 func_L01_004461B8(f32 *, f32 *, f32, f32, f32);
extern f32 func_0038DAB8(f32, f32);
extern f32 func_0038DB00(f32, f32);
extern f32 func_0038DBA0(f32, f32);
extern void func_003C2F58(s32, s32, s32);
extern s32 func_00382468(s32);
extern s32 func_00382498(s32, s32);
extern f32 func_003824E0(f32, f32);
extern void func_L01_00446760(s32, s32, s32, f32, s32);
extern void func_L01_00446A70(s32, s32, s32, s32, s32, f32);
extern f32 func_003C4138(s32, f32, f32);
extern f32 func_L01_004482A0(s32, s32, f32, f32, f32, f32);
extern f32 func_L01_00448340(s32, s32, s32, f32, f32, f32);
extern f32 func_L01_004485E0(s32, f32, f32);
extern void func_L01_00448690(s32, s32, f32, f32);
extern f32 func_L01_00448728(s32, f32, s32, f32, f32, f32, s32);
extern s32 func_003C4B50(s32);
extern void func_003C4BB0(s32, f32);
extern void func_00382760(s32, f32, f32, f32);
extern s32 func_L01_00468678(s32, s32, f32, f32, s32);
extern void func_003A4F28(s32);
extern void func_L01_004C67A0(s32, s32, void *, f32, f32, f32, f32);
extern void func_L01_004E4F30(s32, s32, f32);
extern void func_L01_004E5030(f32, f32, f32, f32);
extern f32 func_L01_004E5130(s32, s32);
extern void func_L01_004E5290(f32, f32, f32);
extern void func_L01_004E5748(s32, s32);
extern void func_L01_004E5840(s32, s32);
extern void func_L01_004E5A20(s32, s32);
extern void func_L01_004E5C08(s32, s32, s32);
extern void func_L01_004E5EB8(s32, s32, s32);
extern void func_L01_004E6390(f32, f32);
extern void func_L01_004E63A8(f32, f32);
extern void func_L01_004E63C0(f32, f32);
extern void func_L01_004E63D8(f32, f32);
extern void func_L01_004E7780(void);
extern s32 func_L01_004E9238(s32);
extern s32 func_L01_004606E8(s32, s32, s32, s32);
extern void func_L30_004CF4B0(s32, s32);
extern void func_L01_004F5AE8(void);
extern void func_L01_004F5810(void);

extern void func_L01_004EE400(void);
extern s32 func_L01_004EE7F8(f32);
extern s32 func_003A3BB8(s32, s32);
extern void func_L30_004BCB20(f32, s32);
extern void func_L01_004EEBA8(void);
extern void func_L01_004EEC98(f32, f32, f32);
extern void func_L01_004EEDD0(s32, f32, f32, f32);
extern void func_L01_004EEEC0(void);
extern void func_L01_004EF128(f32, f32);
extern void func_L01_004EF178(f32);
extern void func_L01_004EF238(s32);
extern void func_L01_004EF268(void);
extern void func_L01_004F0558(f32, f32);
extern f32 func_L01_004F05F0(s32);
extern void func_L01_004F1220(f32);
extern void func_L01_004F1638(void);
extern void func_L01_004F2880(f32, f32, f32);
extern void func_L01_004F2E68(void);
extern void func_L01_004F3BE0(void);
extern void func_L01_004F3F40(void);
extern f32 func_L01_004F4E20(s32, s32);
extern s32 func_L01_004F4E70(s32, s32);
extern void func_L01_004F4F18(s32, s32, s32);
extern s32 func_L01_004F52E0(f32, f32, f32);
extern s32 func_L01_005119E0(s32);
extern void func_L01_00505380(void);
extern s32 func_L01_00507268(void);
extern void func_L01_0050FB40(s32, s32, f32);
extern void func_L01_00510F08(s32, s32, f32);
extern void func_L01_005110E8(s32, f32, f32, f32, s32);
extern void func_L01_00511158(s32, s32, f32);
extern void func_L01_00511178(s32, s32, f32);
extern void func_L01_00511280(s32, s32, f32);
extern void func_L01_00511320(s32, s32);
extern f32 func_L01_00511408(s32);
extern f32 func_L01_005114B0(s32);
extern void func_L01_00511508(s32, s32, f32);
extern void func_L01_00511588(s32, s32, f32);
extern s32 func_L01_003F1F20(s32, s32);
extern s32 func_L01_0040E728(s32, s32, f32);
extern void func_L01_0044E468(s32, s32);
extern void func_L01_0044FB80(s32, s32, f32, f32, f32);
extern f32 func_L01_00460818(s32, s32);
extern s32 func_L01_004E8318(s32, s32, s32);
extern f32 D_L30_002EE300[];
extern f32 D_L30_001DBC94[] __attribute__((section(".sdata")));
extern s32 D_L30_001D66B0[2];
extern f32 func_0038CE68(s32, s32);
extern void func_L01_004F2E68(void);
extern void func_L01_004F3BE0(void);

extern f32 D_L30_001DA440[];
extern s32 func_L30_004AD910(s32);
extern void func_L30_004BD6C0(s32);

extern f32 D_L30_001DBC4C;
__asm__(".extern D_L30_001DBC4C, 4");
extern void func_L30_004E5598(void);
extern void func_L30_004E5158(void);
extern void func_L30_004E5F28(s32);
extern void func_L30_004E6E50(void);
extern s32 func_L01_004E63F0(f32 *, f32, f32);
#include "vu0.h"


void func_L30_004C4318(void) {
    f32 v0[4] __attribute__((aligned(16)));
    f32 v10[4] __attribute__((aligned(16)));
    f32 v20[4] __attribute__((aligned(16)));
    f32 v30[4] __attribute__((aligned(16)));
    f32 v40[16] __attribute__((aligned(16)));
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
        if (((Hero *)D_001A4BE0)->b[0x25EA] != 0) {
            func_L01_004E5748(0xF, 0x1E);
        }
        if (((Hero *)D_001A4BE0)->b[0x1474] != 0) {
            func_L01_004F0558(0.7f, 0.0f);
        } else {
            func_L01_004F0558(0.5f, 0.040000003f);
        }
        func_L01_004F52E0(3.7f, 0.0f, 0.35f);
        func_L30_004BCB20(1.0f, 0);
        temp_v1 = ((Hero *)D_001A4BE0)->u[0x25C4/4];
        if ((temp_v1 == 1) || (temp_v1 == 0x1D)) {
            if (((Hero *)D_001A4BE0)->b[0x25E5] != 0) {
                (*(u128_t*)v0) = 0;
                v0[0] = 1.0f;
                func_0038D000((s32) (((void*)D_001A4BE0) + 0x190), (s32)((u128_t*)v0), (s32)&D_L30_001E22D8[0x368]);
                ((Hero *)D_001A4BE0)->f[0x1A0/4] = ((Hero *)D_L30_001E22D8)->f[0];
                func_L01_004EEDD0(0, 1.44f, 0.0f, 3.4906588f);
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
            if (func_L01_00507268() != 0) {
                break;
            }
        }
        if (((Hero *)D_001A4BE0)->u[0x25C4/4] == 4) {
            if ((((Hero *)D_001A4BE0)->f[0x2838/4] > 0.2f) || (temp_a0_2 = (*(u8 *)((u8 *)(((Hero *)D_001A4BE0)->ptr[0x25C0/4]) + 0x43)), (temp_a0_2 == 0xE)) || (temp_a0_2 == 0xF)) {
                if (((Hero *)D_001A4BE0)->u[0x25C4/4] == 4) {
                    func_L01_004EEDD0(0, 0.0028800003f, 0.10080001f, 0.19896755f);
                }
                if (fabs_asm(((Hero *)D_001A4BE0)->f[0x1A4/4]) > 0.0069813174f) {
                    temp_a0_3 = ((Hero *)D_001A4BE0)->f[0x1A4/4] < 0.0f;
                    temp_a0_3 += 0xE;
                    if ((*(u8 *)((u8 *)(((Hero *)D_001A4BE0)->ptr[0x25C0/4]) + 0x43)) != temp_a0_3) {
                        func_L01_0050FB40(temp_a0_3, 0, 4.0f);
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
                        func_L01_0050FB40(0xD, 0, 6.0f);
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
                        func_L01_004E5030(13.0f, var_f1, 0.5f, -1.0f);
                        if (((Hero *)D_001A4BE0)->f[0xC00/4] > 1.1f) {
                            ((Hero *)D_001A4BE0)->f[0xC00/4] = 1.1f;
                        }
                    } else if ((f32) (*(u8 *)((u8 *)(((Hero *)D_001A4BE0)->ptr[0x25C0/4]) + 0x41)) > 6.5f) {
                        ((Hero *)D_001A4BE0)->f[0xC00/4] = 1.0f;
                    }
                }
            } else if (temp_v1_3 == 4) {
                var_f20 = 0.0108f;
                if (((Hero *)D_001A4BE0)->b[0x1474] != 0) {
                    var_f20 = 0.00068000006f;
                }
            } else {
                var_f20 = 0.007080001f;
            }
            func_L01_004EF128(0.0f, var_f20);
            qzero((V4 *)(D_001A4BE0 + 0xF0));
            func_L01_004F4730(var_f20);
            if ((((Hero *)D_001A4BE0)->b[0x1479] != 0) && (D_00142CAD[0] != 0)) {
                var_a0_2 = (s32)(D_001A4BE0 + 0xF0);
                if (((Hero *)D_001A4BE0)->f[0x33C/4] > 0.2f) {
                    func_L01_00510F08(var_a0_2, var_a0_2 + 0x30, 0.0088f);
                } else {
                    func_L01_00510F08((s32)(D_001A4BE0 + 0xF0), (s32)(D_001A4BE0 + 0xF0), 0.0216f);
                    if (((Hero *)D_001A4BE0)->i[0x35C/4] != 0) {
                        *(u128_t *)(&((Hero *)D_001A4BE0)->q[0x80/16]) = *(u128_t *)(&((Hero *)D_001A4BE0)->q[0x2F0/16]);
                        ((Hero *)D_001A4BE0)->f[0x33C/4] = 0.0f;
                        ((Hero *)D_001A4BE0)->h[0x36E/2] = 0;
                    }
                }
            } else {
                func_L30_004BD6C0(0);
                if (((Hero *)D_001A4BE0)->h[0x36E/2] == 0) {
                    func_L01_00510F08((s32) ((void*)D_001A4BE0) + 0xF0, (s32) ((void*)D_001A4BE0) + 0xF0, 0.0216f);
                } else {
                    func_L01_00510F08((s32) ((void*)D_001A4BE0) + 0xF0, (s32) ((void*)D_001A4BE0) + 0x130, 0.010000001f);
                    func_L01_004EF268();
                }
            }
        break;
    case 0x81:
        if (((Hero *)D_001A4BE0)->ptr[0x734/4] == 0) {
            ((Hero *)D_001A4BE0)->ptr[0x734/4] = func_003C24B0(0x52A, 0x80);
            if (((Hero *)D_001A4BE0)->ptr[0x734/4] == 0) {
                goto end81;
            }
            *(u128_t *)((u8 *)((Hero *)D_001A4BE0)->ptr[0x734/4] + 0x10) = ((Hero *)D_001A4BE0)->q[0x80/16];
            *(u128_t *)((u8 *)((Hero *)D_001A4BE0)->ptr[0x734/4] + 0xF0) = ((Hero *)D_001A4BE0)->q[0x90/16];
            *(s16 *)((u8 *)((Hero *)D_001A4BE0)->ptr[0x734/4] + 0x32) = 0x40;
            *(u8 *)((u8 *)((Hero *)D_001A4BE0)->ptr[0x734/4] + 0x31) = 1;
            *(u8 *)((u8 *)((Hero *)D_001A4BE0)->ptr[0x734/4] + 0x30) = 0;
            *(u8 *)((u8 *)((Hero *)D_001A4BE0)->ptr[0x734/4] + 0x23) = 0;
            *(u16 *)((u8 *)((Hero *)D_001A4BE0)->ptr[0x734/4] + 0x34) |= 0x800;
            func_003C7C38(((Hero *)D_001A4BE0)->ptr[0x734/4]);
            func_003A52A0(0, 0, ((Hero *)D_001A4BE0)->ptr[0x734/4]);
            if (((Hero *)D_001A4BE0)->ptr[0x734/4] == 0) {
                goto end81;
            }
        }
        *(u8 *)((u8 *)((Hero *)D_001A4BE0)->ptr[0x734/4] + 0x23) += 6;
        if (*(u8 *)((u8 *)((Hero *)D_001A4BE0)->ptr[0x734/4] + 0x23) > 0x80) {
            *(u8 *)((u8 *)((Hero *)D_001A4BE0)->ptr[0x734/4] + 0x23) = 0x80;
        }
        *(u128_t *)((u8 *)((Hero *)D_001A4BE0)->ptr[0x734/4] + 0x10) = *(u128_t *)((u8 *)((Hero *)D_001A4BE0)->ptr[0x25C0/4] + 0x10);
        *(u128_t *)((u8 *)((Hero *)D_001A4BE0)->ptr[0x734/4] + 0xF0) = *(u128_t *)((u8 *)((Hero *)D_001A4BE0)->ptr[0x25C0/4] + 0xF0);
        func_003C7C38(((Hero *)D_001A4BE0)->ptr[0x734/4]);
    end81:
        ((Hero *)D_001A4BE0)->i[0xF8/4] = 0;
        func_L01_0040E728((s32)(D_001A4BE0 + 0xF0), (s32)(D_001A4BE0 + 0xF0), func_0038CED8((s32)(D_001A4BE0 + 0xF0)) * 0.90400004f);
        func_L01_00505380();
        break;
    case 0x50:
        if (((Hero *)D_001A4BE0)->ptr[0x734/4] == 0) {
            ((Hero *)D_001A4BE0)->ptr[0x734/4] = func_003C24B0(0x52A, 0x80);
            if (((Hero *)D_001A4BE0)->ptr[0x734/4] == 0) {
                goto end50;
            }
            *(f32 *)((u8 *)((Hero *)D_001A4BE0)->ptr[0x734/4] + 0x2C) *= 0.5f;
            *(u128_t *)((u8 *)((Hero *)D_001A4BE0)->ptr[0x734/4] + 0x10) = ((Hero *)D_001A4BE0)->q[0x80/16];
            *(u128_t *)((u8 *)((Hero *)D_001A4BE0)->ptr[0x734/4] + 0xF0) = ((Hero *)D_001A4BE0)->q[0x90/16];
            *(s16 *)((u8 *)((Hero *)D_001A4BE0)->ptr[0x734/4] + 0x32) = 0x40;
            *(u8 *)((u8 *)((Hero *)D_001A4BE0)->ptr[0x734/4] + 0x31) = 1;
            *(u8 *)((u8 *)((Hero *)D_001A4BE0)->ptr[0x734/4] + 0x30) = 0;
            *(u8 *)((u8 *)((Hero *)D_001A4BE0)->ptr[0x734/4] + 0x23) = 0;
            *(u16 *)((u8 *)((Hero *)D_001A4BE0)->ptr[0x734/4] + 0x34) |= 0x800;
            func_003C7C38(((Hero *)D_001A4BE0)->ptr[0x734/4]);
            func_003A52A0(0, 0, ((Hero *)D_001A4BE0)->ptr[0x734/4]);
            if (((Hero *)D_001A4BE0)->ptr[0x734/4] == 0) {
                goto end50;
            }
        }
        *(u8 *)((u8 *)((Hero *)D_001A4BE0)->ptr[0x734/4] + 0x23) += 6;
        if (*(u8 *)((u8 *)((Hero *)D_001A4BE0)->ptr[0x734/4] + 0x23) > 0x80) {
            *(u8 *)((u8 *)((Hero *)D_001A4BE0)->ptr[0x734/4] + 0x23) = 0x80;
        }
        *(u128_t *)((u8 *)((Hero *)D_001A4BE0)->ptr[0x734/4] + 0x10) = *(u128_t *)((u8 *)((Hero *)D_001A4BE0)->ptr[0x25C0/4] + 0x10);
        *(u128_t *)((u8 *)((Hero *)D_001A4BE0)->ptr[0x734/4] + 0xF0) = *(u128_t *)((u8 *)((Hero *)D_001A4BE0)->ptr[0x25C0/4] + 0xF0);
        func_003C7C38(((Hero *)D_001A4BE0)->ptr[0x734/4]);
    end50:
        ((Hero *)D_001A4BE0)->i[0xF8/4] = 0;
        func_L01_0040E728((s32)(D_001A4BE0 + 0xF0), (s32)(D_001A4BE0 + 0xF0), func_0038CED8((s32)(D_001A4BE0 + 0xF0)) * 0.90400004f);
        func_L01_00505380();
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
            func_L01_004F4F18(5, (s32) ((Hero *)D_001A4BE0)->ptr[0x25C0/4], 0xF);
            func_L01_003F1F20(0x16, 0);
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
            func_L01_004E5C08((t9CA >= 9) ? 8 : t9CA, 0, 0);
        }
        if ((((Hero *)D_001A4BE0)->u[0x25C4/4] == 0x32) && (((Hero *)D_001A4BE0)->i[0xC0C/4] == 0)) {
            f32 tC18 = ((Hero *)D_001A4BE0)->f[0xC18/4];
            if (tC18 > 0.0f) {
                if (tC18 < 10.0f) {
                    func_L01_004E5C08(4, 1, 0);
                }
            }
        }
        if (((Hero *)D_001A4BE0)->u[0x25C4/4] == 0x33) {
            if (((Hero *)D_001A4BE0)->i[0x25D0/4] == 0x34) {
                s32 t1B8 = ((Hero *)D_001A4BE0)->i[0x1B8/4];
                if (t1B8 < 0xC) {
                    func_L01_004E5C08(((s32) (0x11 - t1B8) / 3) + 1, 1, 0);
                }
            }
        }
        {
        s32 t25C8 = ((Hero *)D_001A4BE0)->i[0x25C8/4];
        if (t25C8 == 1) {
            s32 t9A0;
            if (((Hero *)D_001A4BE0)->i[0x1B8/4] == t25C8) {
                func_L01_004E5EB8(3, 0x10, 0);
                if (D_L30_001E0790 != 0) {
                    func_L01_004C67A0(D_L30_001E0790, D_L30_001E0798, 0, ((Hero *)D_001A4BE0)->f[0x80/4], ((Hero *)D_001A4BE0)->f[0x84/4], 0.4f, -0.3f);
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
            if ((D_L30_001DF2C0 - ((Hero *)D_001A4BE0)->i[0x9D4/4]) < 0x3A) {
                ((Hero *)D_001A4BE0)->i[0x9D0/4]++;
            }
            ((Hero *)D_001A4BE0)->i[0x9D4/4] = D_L30_001DF2C0;
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
        func_L01_00448728((s32) (D_001A4BE0 + 0x94), var_f12_4, (s32) (D_001A4BE0 + 0x9A8), 0.0216f, 0.28800002f, turn, 0);
        dh = func_0038DB00(((Hero *)D_001A4BE0)->f[0x94/4], h94);
        func_L30_004BCB20(1.0f, 0);
        func_L01_004EEDD0(0, 0.01008f, 0.115200005f, 0.10471976f);
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
            func_L01_00468678((s32)v0, (s32)v10, 25200.0f, -1.0f, 0x88A0A0A0);
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
                            func_L01_0044FB80((s32)v10, (s32)v10, -0.015000001f, ((Hero *)D_001A4BE0)->f[0x98/4], ((Hero *)D_001A4BE0)->f[0x94/4]);
                            ((Hero *)D_001A4BE0)->h[0x9B8/2] = (0.14000002f - ((Hero *)D_001A4BE0)->f[0x1B4/4]) / 0.14000002f * 4.0f;
                            func_L01_00468678((s32)v0, (s32)v10, func_003824E0(6300.0f, 9450.0f), -1.0f, 0x88A0A0A0);
                        }
                    }
                }
            }
        }
        if (((Hero *)D_001A4BE0)->u[0x25C4/4] == 0x34) {
            func_L01_004EF128(0.0052000005f, 0.0032000002f);
        } else {
            func_L01_004EF128(0.0028000001f, 0.0016000001f);
        }
        yaw = func_0038DAB8(-((Hero *)D_001A4BE0)->f[0x94/4], 0.0f);
        st32 = ((Hero *)D_001A4BE0)->u[0x25C4/4];
        if (st32 == 0x34) {
            func_00382760((s32)D_001A4BE0 + 0xF0, ((Hero *)D_001A4BE0)->f[0x1B4/4], ((Hero *)D_001A4BE0)->f[0x98/4], yaw);
        } else if (st32 == 0x32) {
            sp = ((Hero *)D_001A4BE0)->f[0x1B4/4] * func_L01_004E5130((s32)D_L30_002F4F90, 0x1E) * 5.0f;
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
        func_L30_004BD6C0(0);
        roll = ((Hero *)D_001A4BE0)->f[0x9AC/4] * func_0038D098(yaw) * -7.0f;
        func_L01_00448728((s32) (D_001A4BE0 + 0x90), roll, (s32) (D_001A4BE0 + 0x9A4), 0.007f, 0.17f, 0.024434611f, 0);
        func_L01_004E63A8(0.009f, 0.22f);
        func_L01_004E63C0(0.04f, 0.2f);
        func_L01_004E63D8(0.02f, 0.2f);
        {
        f32 pit = dh * 47.0f;
        f32 yw;
        f32 rl;
        ((Hero *)D_L30_002F2EE0)->f[0x114/4] = pit;
        ((Hero *)D_L30_002F2EE0)->f[0x118/4] = roll * 1.5f;
        ((Hero *)D_L30_002F2EE0)->f[0x110/4] = roll * 1.4f;
        if (pit > 0.87266463f) {
            ((Hero *)D_L30_002F2EE0)->f[0x114/4] = 0.87266463f;
        } else if (pit < -0.87266463f) {
            ((Hero *)D_L30_002F2EE0)->f[0x114/4] = -0.87266463f;
        }
        yw = dh * 40.0f;
        rl = roll * 1.1f;
        ((Hero *)D_L30_002F2EE0)->f[0x364/4] = 0.03f;
        ((Hero *)D_L30_002F2EE0)->f[0x368/4] = 0.22f;
        ((Hero *)D_L30_002F2EE0)->f[0x324/4] = yw;
        ((Hero *)D_L30_002F2EE0)->f[0x328/4] = rl;
        ((Hero *)D_L30_002F2EE0)->f[0x414/4] = 0.03f;
        ((Hero *)D_L30_002F2EE0)->f[0x418/4] = 0.22f;
        ((Hero *)D_L30_002F2EE0)->f[0x3D4/4] = yw;
        ((Hero *)D_L30_002F2EE0)->f[0x3D8/4] = rl;
        }
        }
        break;
    case 0x78:
        {
        s32 t78;
        t78 = 0xA - (((Hero *)D_001A4BE0)->i[0x1B8/4] / 3);
        func_L01_004E5C08((t78 >= 9) ? 8 : t78, 0, 0);
        ((Hero *)D_001A4BE0)->f[0xF8/4] = 0.0f;
        func_L01_0040E728((s32)D_001A4BE0 + 0xF0, (s32)D_001A4BE0 + 0xF0, func_0038CED8((s32)D_001A4BE0 + 0xF0) * 0.90400004f);
        func_L30_004BD6C0(0);
        }
        break;
    case 0x77:
        func_L01_004E5748(0xF, 0x1E);
        ((Hero *)D_001A4BE0)->f[0xF8/4] = 0.0f;
        func_L01_0040E728((s32)D_001A4BE0 + 0xF0, (s32)D_001A4BE0 + 0xF0, func_0038CED8((s32)D_001A4BE0 + 0xF0) * 0.90400004f);
        func_L30_004BD6C0(0);
        func_L01_00505380();
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
            func_L01_00468678((s32)v0, (s32)v10, 25200.0f, -1.0f, 0x88A0A0A0);
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
            func_L01_004E5748(0xF, 0x1E);
        }
        if (((Hero *)D_001A4BE0)->f[0x174/4] > 0.030000001f) {
            func_L01_004E5A20(4, 0xC);
        }
        if ((((Hero *)D_001A4BE0)->u[0x25C4/4] == 0x35) && (((Hero *)D_001A4BE0)->f[0x174/4] > 0.020000001f)) {
            func_L01_004E5840(0, 1);
        }
        if (((Hero *)D_001A4BE0)->h[0x9CA/2] != 0) {
            ((Hero *)D_001A4BE0)->h[0x9CA/2] -= 1;
            t35 = ((Hero *)D_001A4BE0)->h[0x9CA/2] >> 3;
            func_L01_004E5C08((t35 >= 7) ? 6 : t35, 0, 0);
        }
        ((Hero *)D_001A4BE0)->f[0xC00/4] = 0.6f;
        func_L30_004BCB20(0.060000002f, 0);
        if ((D_001D52FC->i[0x1D4/4] == 0) && (((Hero *)D_001A4BE0)->f[0x1B0/4] < 0.030000001f)) {
            ((Hero *)D_001A4BE0)->f[0x1B0/4] = 0.030000001f;
        }
        func_L01_004EEDD0(0, 0.01008f, 0.115200005f, 0.10471976f);
        func_0038CAD0((s32)(D_001A4BE0 + 0x728));
        if (((Hero *)D_001A4BE0)->u[0x25C4/4] == 0x35) {
            if ((D_001D52FC->i[0x1D4/4] != 0) && (((Hero *)D_001A4BE0)->i[0x728/4] != 0)) {
                ((Hero *)D_001A4BE0)->f[0x1B0/4] = 0.060000002f;
            }
            if (fabs_asm(((Hero *)D_001A4BE0)->f[0x1A8/4]) > 0.7853982f) {
                ((Hero *)D_001A4BE0)->f[0x1B0/4] = 0.0f;
            }
            func_L01_004EF128(0.0016000001f, 0.002f);
            sp35 = ((Hero *)D_001A4BE0)->f[0x1B4/4] * func_L01_004E5130((s32)D_L30_002F4F90, 0x1E) * 5.5f;
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
                func_L01_004E5C08(4, 1, 0);
            }
        }
        func_L01_004F4730(0.00168f);
        func_L30_004BD6C0(0);
        func_L01_00505380();
        }
        break;
    case 0x2F:
        {
        s32 anim;
        s32 blend;
        anim = -1;
        blend = 0;
        if (((Hero *)D_001A4BE0)->b[0x1474] != 0) {
            func_L01_004F0558(0.7f, 0.0f);
        } else {
            func_L01_004F0558(0.5f, 0.040000003f);
        }
        func_L01_004F52E0(3.7f, 0.0f, 0.35f);
        func_L30_004BCB20(1.0f, 0);
        func_L01_004EF128(0.007080001f, 0.007080001f);
        qzero((V4 *)(D_001A4BE0 + 0xF0));
        func_L01_004F4730(0.007080001f);
        if (((Hero *)D_001A4BE0)->h[0x36E/2] != 0) {
            func_L01_00510F08((s32)(D_001A4BE0 + 0xF0), (s32)(D_001A4BE0 + 0xF0) + 0x20, 0.010000001f);
            func_L01_004EF268();
        } else {
            func_L01_00510F08((s32)(D_001A4BE0 + 0xF0), (s32)(D_001A4BE0 + 0xF0), 0.0216f);
        }
        if ((anim != -1) && (*(u8 *)((u8 *)((Hero *)D_001A4BE0)->ptr[0x25C0/4] + 0x42) != 0x31)) {
            func_L01_0050FB40(anim, 0, (f32) blend);
        } else if ((*(u8 *)((u8 *)((Hero *)D_001A4BE0)->ptr[0x25C0/4] + 0x60) & 2) && (*(u8 *)((u8 *)((Hero *)D_001A4BE0)->ptr[0x25C0/4] + 0x42) == 0x31)) {
            func_L01_0050FB40(func_L30_004AD910(0), 0, 4.0f);
        }
        }
        break;
    case 0x8F:
    case 0x90:
        func_L01_004F52E0(3.7f, 0.0f, 0.35f);
        ((Hero *)D_001A4BE0)->f[0x1B0/4] = 0.0f;
        func_L01_004EF128(0.007080001f, 0.007080001f);
        qzero((V4 *)(D_001A4BE0 + 0xF0));
        func_L01_004F4730(0.007080001f);
        if (((Hero *)D_001A4BE0)->h[0x36E/2] != 0) {
            func_L01_00510F08((s32)(D_001A4BE0 + 0xF0), (s32)(D_001A4BE0 + 0x120), 0.0088f);
            func_L01_004EF268();
        } else {
            func_L01_00510F08((s32)(D_001A4BE0 + 0xF0), (s32)(D_001A4BE0 + 0xF0), 0.0216f);
        }
        if (((Hero *)D_001A4BE0)->ptr[0xA90/4] != 0) {
            ((Hero *)D_001A4BE0)->f[0x1A0/4] = func_0038D160(*(f32 *)((u8 *)((Hero *)D_001A4BE0)->ptr[0xA90/4] + 0x10) - *(f32 *)((u8 *)temp_fp + 0x10), *(f32 *)((u8 *)((Hero *)D_001A4BE0)->ptr[0xA90/4] + 0x14) - *(f32 *)((u8 *)temp_fp + 0x14));
            func_L01_004EEDD0(0, 0.028800001f, 0.21600002f, 0.12566371f);
        }
        break;
    case 0x23:
        func_L01_004F52E0(3.7f, 0.0f, 0.35f);
        ((Hero *)D_001A4BE0)->f[0x1B0/4] = 0.0f;
        func_L01_004EF128(0.007080001f, 0.007080001f);
        qzero((V4 *)(D_001A4BE0 + 0xF0));
        func_L01_004F4730(0.007080001f);
        if (((Hero *)D_001A4BE0)->h[0x36E/2] != 0) {
            func_L01_00510F08((s32)(D_001A4BE0 + 0xF0), (s32)(D_001A4BE0 + 0x120), 0.0088f);
            func_L01_004EF268();
        } else {
            func_L01_00510F08((s32)(D_001A4BE0 + 0xF0), (s32)(D_001A4BE0 + 0xF0), 0.0216f);
        }
        if (((Hero *)D_001A4BE0)->ptr[0xA24/4] != 0) {
            ((Hero *)D_001A4BE0)->f[0x1A0/4] = func_0038D160(*(f32 *)((u8 *)((Hero *)D_001A4BE0)->ptr[0xA24/4] + 0x10) - *(f32 *)((u8 *)temp_fp + 0x10), *(f32 *)((u8 *)((Hero *)D_001A4BE0)->ptr[0xA24/4] + 0x14) - *(f32 *)((u8 *)temp_fp + 0x14));
            func_L01_004EEDD0(0, 0.028800001f, 0.21600002f, 0.12566371f);
        }
        break;
    case 0x24:
        {
        f32 dist24;
        f32 yaw24;
        f32 hitE8;
        f32 hitEC;
        s32 st24;
        *(u128_t *)v0 = *(u128_t *)((u8 *)((Hero *)D_001A4BE0)->ptr[0xA24/4] + 0x10);
        dist24 = func_0038CF00((s32)(D_001A4BE0 + 0x80), (s32)v0);
        ((Hero *)D_001A4BE0)->f[0xA30/4] = dist24;
        ((Hero *)D_001A4BE0)->f[0xA2C/4] = 50.0f;
        if (((Hero *)D_001A4BE0)->f[0xA20/4] > 0.0f) {
            ((Hero *)D_001A4BE0)->f[0xA2C/4] = dist24 / ((Hero *)D_001A4BE0)->f[0x170/4];
        }
        st24 = ((Hero *)D_001A4BE0)->i[0x25C8/4];
        if (st24 == 0) {
            func_003C4138((s32)(D_001A4BE0 + 0xA20), 0.54f, 0.032f);
            yaw24 = func_0038D160(*(f32 *)((u8 *)((Hero *)D_001A4BE0)->ptr[0xA24/4] + 0x10) - *(f32 *)((u8 *)temp_fp + 0x10), *(f32 *)((u8 *)((Hero *)D_001A4BE0)->ptr[0xA24/4] + 0x14) - *(f32 *)((u8 *)temp_fp + 0x14));
            if (((Hero *)D_001A4BE0)->i[0x3C0/4] != 0) {
                if (func_0038DBA0(((Hero *)D_001A4BE0)->f[0x98/4], yaw24) > 1.5707964f) {
                    yaw24 = func_0038DAB8(yaw24, 3.1415927f);
                }
            }
            ((Hero *)D_001A4BE0)->f[0x1A0/4] = yaw24;
            func_L01_004EEDD0(0, 0.0432f, 0.21600002f, 0.14660767f);
        } else if (st24 == 1) {
            func_003C4138((s32)(D_001A4BE0 + 0xA20), 0.0f, 0.016800001f);
        }
        if ((func_L01_004461B8(&hitE8, &hitEC, -0.008400001f, ((Hero *)D_001A4BE0)->f[0xA20/4], -(((Hero *)D_001A4BE0)->f[0xA30/4] - 1.9f)) > 0) && (hitE8 > 0.0f)) {
            ((Hero *)D_001A4BE0)->f[0xA2C/4] = hitE8;
            ((Hero *)D_001A4BE0)->i[0x25C8/4] = 1;
        }
        ((Hero *)D_001A4BE0)->h[0x226/2] = 3;
        if (((Hero *)D_001A4BE0)->f[0xA2C/4] < 17.0f) {
            ((Hero *)D_001A4BE0)->i[0xA34/4] = 1;
        }
        if (((Hero *)D_001A4BE0)->i[0xA34/4] != 0) {
            func_L01_00448690((s32)(D_001A4BE0 + 0x94), 0, 0.0f, 0.07679449f);
        } else {
            f32 a24 = func_0038DAB8(-func_0038D160(func_0038CF38((s32)(D_001A4BE0 + 0x80), (s32)v0), v0[2] - ((Hero *)D_001A4BE0)->f[0x88/4]), 1.5707964f);
            func_L01_00448690((s32)(D_001A4BE0 + 0x94), 0, a24, 0.12915437f);
        }
        v20[0] = func_0038D098(func_0038DAB8(((Hero *)D_001A4BE0)->f[0x98/4], -1.5707964f)) * -0.57f;
        v20[1] = func_0038D0B0(func_0038DAB8(((Hero *)D_001A4BE0)->f[0x98/4], -1.5707964f)) * -0.57f;
        *(s32 *)&v20[2] = 0;
        vec_add_ba((V4 *)v20, (V4 *)v20, (V4 *)(D_001A4BE0 + 0x80));
        vec_sub_ab((V4 *)v10, (V4 *)((u8 *)((Hero *)D_001A4BE0)->ptr[0xA24/4] + 0x10), (V4 *)v20);
        func_0038CF68((s32)(D_001A4BE0 + 0xF0), (s32)v10, ((Hero *)D_001A4BE0)->f[0xA20/4]);
        if (((Hero *)D_001A4BE0)->f[0xA2C/4] < 25.0f) {
            ((Hero *)D_001A4BE0)->f[0xF8/4] = ((Hero *)D_001A4BE0)->f[0xF8/4] - (25.0f - ((Hero *)D_001A4BE0)->f[0xA2C/4]) * 0.011600001f;
        }
        }
        break;
    case 0x25:
        func_003C4138((s32)(D_001A4BE0 + 0xA3C), ((Hero *)D_001A4BE0)->f[0xA40/4], 0.20000002f);
        *(u128_t *)(D_001A4BE0 + 0xF0) = *(u128_t *)(D_001A4BE0 + 0x110);
        func_0038CE20((s32)(D_001A4BE0 + 0xF0), (s32)(D_001A4BE0 + 0xF0), 0.9f);
        ((Hero *)D_001A4BE0)->f[0xF8/4] = ((Hero *)D_001A4BE0)->f[0xF8/4] - 0.006f;
        *(u128_t *)v0 = *(u128_t *)((u8 *)((Hero *)D_001A4BE0)->ptr[0xA24/4] + 0x10);
        ((Hero *)D_001A4BE0)->f[0xA30/4] = func_0038CF00((s32)(D_001A4BE0 + 0x80), (s32)v0);
        vec_add_ba((V4 *)v10, (V4 *)(D_001A4BE0 + 0x80), (V4 *)(D_001A4BE0 + 0xF0));
        vec_sub_ba((V4 *)v30, (V4 *)v10, (V4 *)v0);
        func_0038CF68((s32)v30, (s32)v30, ((Hero *)D_001A4BE0)->f[0xA3C/4]);
        vec_add_ba((V4 *)v20, (V4 *)v0, (V4 *)v30);
        vec_sub_ab((V4 *)(D_001A4BE0 + 0xF0), (V4 *)v20, (V4 *)(D_001A4BE0 + 0x80));
        break;
    case 0x2B:
        {
        f32 vz2B;
        f32 ang2B;
        f32 rate2B;
        f32 old2B;
        f32 lenF0;
        f32 lenF4;
        s32 below2B;
        s32 up2B;
        s32 a7c;
        void *obj2B;
        void *lim2B;
        f32 min2B;
        f32 side2B;
        f32 m80[16] __attribute__((aligned(16)));
        f32 vC0[4] __attribute__((aligned(16)));
        f32 vD0[4] __attribute__((aligned(16)));
        if ((((Hero *)D_001A4BE0)->i[0xC08/4] & 2) && ((*(u8 *)((u8 *)temp_fp + 0x43)) == 0x2F)) {
            func_L01_0050FB40(0x30, 0xA, 10.0f);
            ((Hero *)D_001A4BE0)->f[0xC00/4] = 0.3f;
        }
        obj2B = ((Hero *)D_001A4BE0)->ptr[0xA54/4];
        vz2B = ((Hero *)D_001A4BE0)->f[0xF8/4];
        if (obj2B != 0) {
            if ((*(void **)((u8 *)obj2B + 0x68) != 0) && (*(s32 *)((u8 *)*(void **)((u8 *)obj2B + 0x68) + 0x34) != 0)) {
                ang2B = *(f32 *)((u8 *)obj2B + 0xF8);
                if (func_0038DBA0(ang2B, ((Hero *)D_001A4BE0)->f[0x98/4]) > 90.0f) {
                    ang2B = func_0038DAB8(ang2B, 3.1415927f);
                }
                func_L01_00448728((s32)(D_001A4BE0 + 0xA6C), ang2B, (s32)(D_001A4BE0 + 0xA78), 0.028800001f, 0.43200004f, 0.0f, 0);
            }
        }
        ((Hero *)D_001A4BE0)->f[0x1A0/4] = ((Hero *)D_001A4BE0)->f[0xA6C/4];
        func_L01_004EEDD0(0, 0.028800001f, 0.43200004f, 0.09424779f);
        vec_sub_ba((V4 *)v0, (V4 *)((u8 *)((Hero *)D_001A4BE0)->ptr[0xA54/4] + 0x10), (V4 *)(D_001A4BE0 + 0x80));
        func_0038CF68((s32)v0, (s32)v0, 1.0f);
        if (v0[2] < 0.23f) {
            v0[2] = 0.23f;
        }
        qzero((V4 *)v20);
        v20[2] = ((Hero *)D_001A4BE0)->f[0x98/4];
        func_0038D328((s32)v40, (s32)v20);
        func_0038D5B0((s32)m80, (s32)v40);
        func_0038D028((s32)v0, (s32)v0, (s32)m80);
        v10[0] = -func_0038D160(sqrt_asm(v0[0] * v0[0] + v0[2] * v0[2]), v0[1]);
        v10[1] = func_0038D160(v0[2], v0[0]);
        func_L01_00448728((s32)(D_001A4BE0 + 0x94), v10[1], (s32)(D_001A4BE0 + 0xA4), 0.057600003f, 0.28800002f, 0.19198623f, 0);
        func_L01_00448728((s32)(D_001A4BE0 + 0x90), v10[0], (s32)(D_001A4BE0 + 0xA0), 0.057600003f, 0.28800002f, 0.19198623f, 0);
        below2B = ((Hero *)D_001A4BE0)->f[0x88/4] < *(f32 *)((u8 *)((Hero *)D_001A4BE0)->ptr[0xA54/4] + 0x18);
        if (((Hero *)D_001A4BE0)->h[0xA5C/2] != 0) {
            if ((below2B != 0) && (((Hero *)D_001A4BE0)->i[0x1B8/4] >= 0x22) && (((Hero *)D_001A4BE0)->f[0x2838/4] > 0.25f)) {
                func_L30_004BCB20(1.0f, 0);
                rate2B = ((Hero *)D_001A4BE0)->f[0x2838/4] * 0.0042000003f;
                if (rate2B > 0.10000001f) {
                    rate2B = 0.10000001f;
                }
                v30[0] = func_0038D098(((Hero *)D_001A4BE0)->f[0x1A0/4]) * rate2B;
                v30[1] = func_0038D0B0(((Hero *)D_001A4BE0)->f[0x1A0/4]) * rate2B;
                *(s32 *)&v30[2] = 0;
                vec_add_ab((V4 *)(D_001A4BE0 + 0xF0), (V4 *)(D_001A4BE0 + 0xF0), (V4 *)v30);
            }
            if (((Hero *)D_001A4BE0)->h[0xA5C/2] != 0) {
                if ((func_0038CF38((s32)(D_001A4BE0 + 0x80), (s32)((u8 *)((Hero *)D_001A4BE0)->ptr[0xA54/4] + 0x10)) < (((Hero *)D_001A4BE0)->f[0xA60/4] * 1.57f)) || (((Hero *)D_001A4BE0)->f[0x33C/4] > 1.5f)) {
                    func_L01_00510F08((s32)(D_001A4BE0 + 0xF0), (s32)(D_001A4BE0 + 0x110), 0.016f);
                    if ((((Hero *)D_001A4BE0)->h[0xA7E/2] != 0) && (func_L01_005114B0((s32)(D_001A4BE0 + 0xF0)) > 0.0f)) {
                        vec_sub_ab((V4 *)v30, (V4 *)(D_001A4BE0 + 0x80), (V4 *)((u8 *)((Hero *)D_001A4BE0)->ptr[0xA54/4] + 0x10));
                        func_L01_00510F08((s32)(D_001A4BE0 + 0xF0), (s32)(D_001A4BE0 + 0xF0), 0.0228f);
                    }
                }
                rate2B = func_0038CEA8((s32)D_001A4CD0) * 0.0003f;
                func_0038CE20((s32)v30, (s32)D_001A4CD0, -1.0f);
                func_0038CF68((s32)v30, (s32)v30, rate2B);
                vec_add_ab((V4 *)D_001A4CD0, (V4 *)D_001A4CD0, (V4 *)v30);
            }
        }
        if (((Hero *)D_001A4BE0)->ptr[0xA54/4] != 0) {
            lim2B = *(void **)((u8 *)((Hero *)D_001A4BE0)->ptr[0xA54/4] + 0x68);
            if (lim2B != 0) {
                lenF0 = func_0038CEA8((s32)(D_001A4BE0 + 0xF0));
                if (((Hero *)lim2B)->f[0xC/4] < lenF0) {
                    func_003C4138((s32)&lenF0, ((Hero *)lim2B)->f[0xC/4], 0.006f);
                    func_0038CF68((s32)(D_001A4BE0 + 0xF0), (s32)(D_001A4BE0 + 0xF0), lenF0);
                }
            }
        }
        side2B = func_0038DAB8(((Hero *)D_001A4BE0)->f[0x98/4], -1.5707964f);
        vD0[0] = func_0038D098(side2B) * 0.15f;
        vD0[1] = func_0038D0B0(side2B) * 0.15f;
        *(s32 *)&vD0[2] = 0;
        vec_add_ba((V4 *)vD0, (V4 *)vD0, (V4 *)(D_001A4BE0 + 0x80));
        vec_add_ba((V4 *)v30, (V4 *)vD0, (V4 *)(D_001A4BE0 + 0xF0));
        vec_sub_ba((V4 *)vC0, (V4 *)v30, (V4 *)((u8 *)((Hero *)D_001A4BE0)->ptr[0xA54/4] + 0x10));
        func_0038CF68((s32)vC0, (s32)vC0, ((Hero *)D_001A4BE0)->f[0xA64/4]);
        vec_add_ba((V4 *)v30, (V4 *)((u8 *)((Hero *)D_001A4BE0)->ptr[0xA54/4] + 0x10), (V4 *)vC0);
        vec_sub_ab((V4 *)(D_001A4BE0 + 0xF0), (V4 *)v30, (V4 *)vD0);
        old2B = ((Hero *)D_001A4BE0)->f[0xA64/4];
        func_L01_004482A0((s32)(D_001A4BE0 + 0xA64), (s32)(D_001A4BE0 + 0xA68), ((Hero *)D_001A4BE0)->f[0xA60/4], ((Hero *)D_001A4BE0)->f[0xA84/4], ((Hero *)D_001A4BE0)->f[0xA88/4], ((Hero *)D_001A4BE0)->f[0xA8C/4]);
        old2B = ((Hero *)D_001A4BE0)->f[0xA64/4] - old2B;
        if (((Hero *)D_001A4BE0)->f[0xA64/4] < func_0038CEA8((s32)vC0)) {
            func_0038CF68((s32)vC0, (s32)vC0, old2B);
            vec_add_ab((V4 *)(D_001A4BE0 + 0x80), (V4 *)(D_001A4BE0 + 0x80), (V4 *)vC0);
        }
        if ((((Hero *)D_001A4BE0)->h[0xA7E/2] != 0) && (below2B != 0)) {
            min2B = 0.28000003f;
            lenF4 = func_0038CED8((s32)(D_001A4BE0 + 0xF0));
            if (lenF4 < min2B) {
                func_L01_004482A0((s32)&lenF4, (s32)(D_001A4BE0 + 0xA74), min2B, 0.06768f, 0.43200004f, 0.0f);
                v30[0] = func_0038D098(((Hero *)D_001A4BE0)->f[0xA6C/4]) * ((Hero *)D_001A4BE0)->f[0xA74/4];
                v30[1] = func_0038D0B0(((Hero *)D_001A4BE0)->f[0xA6C/4]) * ((Hero *)D_001A4BE0)->f[0xA74/4];
                v30[2] = 0.0f;
                vec_add_ab((V4 *)(D_001A4BE0 + 0xF0), (V4 *)(D_001A4BE0 + 0xF0), (V4 *)v30);
            }
        }
        if ((((Hero *)D_001A4BE0)->h[0xA5C/2] != 0) && (((Hero *)D_001A4BE0)->h[0x36E/2] != 0) && (((vz2B < 0.0f) && (((Hero *)D_001A4BE0)->f[0xF8/4] > 0.0f)) || (((Hero *)D_001A4BE0)->h[0xA7C/2] != 0))) {
            ((Hero *)D_001A4BE0)->h[0xA7E/2] = 0;
            ang2B = sqrt_asm(((Hero *)D_001A4BE0)->f[0xA60/4] / ((Hero *)D_001A4BE0)->f[0xA70/4]) * 3.1415927f;
            a7c = ((Hero *)D_001A4BE0)->h[0xA7C/2];
            if (a7c != 0) {
                up2B = a7c == 1;
            } else {
                *(u128_t *)v30 = ((Hero *)D_001A4BE0)->q[0x110/16];
                up2B = func_L01_004F05F0((s32)v30) > 0.0f;
            }
            if (up2B != 0) {
                if ((*(u8 *)((u8 *)temp_fp + 0x43)) != 0x30) {
                    func_L01_0050FB40(0x30, 6, 14.0f);
                    ((Hero *)D_001A4BE0)->h[0xA7C/2] = 1;
                } else if (*(u8 *)((u8 *)((Hero *)D_001A4BE0)->ptr[0x25C0/4] + 0x42) == *(u8 *)((u8 *)((Hero *)D_001A4BE0)->ptr[0x25C0/4] + 0x43)) {
                    func_L01_004E5030(42.0f, ang2B, 0.5f, -1.0f);
                    ((Hero *)D_001A4BE0)->h[0xA7C/2] = 0;
                }
            } else if ((*(u8 *)((u8 *)temp_fp + 0x43)) != 0x30) {
                func_L01_0050FB40(0x30, 0x15, 7.0f);
                ((Hero *)D_001A4BE0)->h[0xA7C/2] = 2;
            } else if (*(u8 *)((u8 *)((Hero *)D_001A4BE0)->ptr[0x25C0/4] + 0x42) == *(u8 *)((u8 *)((Hero *)D_001A4BE0)->ptr[0x25C0/4] + 0x43)) {
                func_L01_004E5030(12.0f, ang2B, 0.5f, -1.0f);
                ((Hero *)D_001A4BE0)->h[0xA7C/2] = 0;
            }
        }
        }
        break;
    case 0x14:
        {
        s32 hit;
        s32 hitw;
        s32 lim14;
        s32 t14;
        f32 spF8;
        f32 d14;
        f32 rise;
        f32 vy;
        f32 cap;
        if ((((Hero *)D_001A4BE0)->i[0xC0C/4] != 0) || (((Hero *)D_001A4BE0)->f[0xC18/4] < (f32) D_L30_002F4C70[((Hero *)D_001A4BE0)->h[0xBDC/2]].w[0x18/4])) {
            ((Hero *)D_001A4BE0)->c[0x1219] = 2;
        }
        ((Hero *)D_001A4BE0)->f[0x1B0/4] = 0.0f;
        if (((Hero *)D_001A4BE0)->b[0x1474] != 0) {
            if (((Hero *)D_001A4BE0)->i[0xBC4/4] != 0) {
                f32 dw14 = func_0038CF38((s32)(D_001A4BE0 + 0x80), ((Hero *)D_001A4BE0)->i[0xBC4/4] + 0x10);
                hitw = 0;
                if ((((Hero *)D_001A4BE0)->b[0x1478] != 0) || (((Hero *)D_001A4BE0)->b[0x147D] != 0) || (((Hero *)D_001A4BE0)->b[0x1477] != 0)) {
                    hitw = 1;
                }
                if (((dw14 > 2.0f) && (dw14 < 5.0f)) || (hitw != 0)) {
                    ((Hero *)D_001A4BE0)->f[0x1B0/4] = 0.09f;
                }
                func_L01_004EF128(0.0016000001f, 0.0016000001f);
                ((Hero *)D_001A4BE0)->f[0xF0/4] = func_0038D098(((Hero *)D_001A4BE0)->f[0x98/4]) * ((Hero *)D_001A4BE0)->f[0x1B4/4];
                ((Hero *)D_001A4BE0)->f[0xF4/4] = func_0038D0B0(((Hero *)D_001A4BE0)->f[0x98/4]) * ((Hero *)D_001A4BE0)->f[0x1B4/4];
            } else {
                func_L01_004EF128(0.00080000004f, 0.00080000004f);
                func_L01_00511588((s32)(D_001A4BE0 + 0xF0), (s32)(D_001A4BE0 + 0xF0), ((Hero *)D_001A4BE0)->f[0x1B4/4]);
            }
        } else {
            hit = 0;
            if ((((Hero *)D_001A4BE0)->b[0x1478] != 0) || (((Hero *)D_001A4BE0)->b[0x1477] != 0) || (((Hero *)D_001A4BE0)->b[0x147D] != 0) || (((Hero *)D_001A4BE0)->f[0x33C/4] > 4.0f)) {
                hit = 1;
            }
            if (((Hero *)D_001A4BE0)->i[0xBC4/4] != 0) {
                vec_sub_ab((V4 *)v0, (V4 *)(((Hero *)D_001A4BE0)->i[0xBC4/4] + 0x10), (V4 *)(D_001A4BE0 + 0x80));
                d14 = func_L01_00511408((s32)v0);
                if (((d14 > 2.0f) && (d14 < 5.0f)) || (hit != 0)) {
                    ((Hero *)D_001A4BE0)->f[0x1B0/4] = 0.09f;
                }
                func_L01_004EF128(0.010000001f, 0.010000001f);
                func_0038CF68((s32)v10, (s32)D_001A4BE0, ((Hero *)D_001A4BE0)->f[0x1B4/4]);
                func_L01_00511588((s32)(D_001A4BE0 + 0xF0), (s32)(D_001A4BE0 + 0xF0), 0.0f);
                vec_add_ab((V4 *)(D_001A4BE0 + 0xF0), (V4 *)(D_001A4BE0 + 0xF0), (V4 *)v10);
            } else {
                if ((hit != 0) && (((Hero *)D_001A4BE0)->i[0x1B8/4] < 0x3A)) {
                    ((Hero *)D_001A4BE0)->f[0x1B0/4] = 0.09f;
                }
                func_L01_004EF128(0.006f, 0.006f);
                func_L01_00511588((s32)(D_001A4BE0 + 0xF0), (s32)(D_001A4BE0 + 0xF0), ((Hero *)D_001A4BE0)->f[0x1B4/4]);
            }
        }
        if ((((Hero *)D_001A4BE0)->i[0xBC8/4] != 0) || (((Hero *)D_001A4BE0)->i[0xBC4/4] != 0)) {
            ((Hero *)D_001A4BE0)->f[0x1A0/4] = ((Hero *)D_001A4BE0)->f[0xBCC/4];
            *(u128_t *)(&((Hero *)D_001A4BE0)->q[0x190/16]) = *(u128_t *)(&((Hero *)D_001A4BE0)->q[0xBA0/16]);
            func_L01_004EEDD0(0, 0.072000004f, 0.28800002f, 0.3385939f);
        } else if (((Hero *)D_001A4BE0)->f[0xC18/4] < 25.0f) {
            func_L01_004F2880(8.0f, 1.0471976f, 1.0471976f);
        }
        rise = 0.15400001f;
        if (((Hero *)D_001A4BE0)->f[0x33C/4] > 2.25f) {
            rise = 0.07700001f;
        } else if (((Hero *)D_001A4BE0)->f[0x33C/4] > 1.8f) {
            rise = 0.10780001f;
        }
        if ((((Hero *)D_001A4BE0)->i[0xC0C/4] == 0) && (((Hero *)D_001A4BE0)->f[0xC18/4] > 23.5f) && (((Hero *)D_001A4BE0)->f[0x118/4] < 0.0f) && (((Hero *)D_001A4BE0)->h[0x36E/2] != 0)) {
            *(u128_t *)(v0) = *(u128_t *)(&((Hero *)D_001A4BE0)->q[0x80/16]);
            func_L01_00511158((s32)v0, (s32)v0, -0.5f);
            func_0038CF68((s32)v40, (s32)D_001A4BE0, 2.0f);
            func_L01_00446760((s32)v10, (s32)((Hero *)D_001A4BE0)->ptr[0x25C0/4], 0x10000, 2.0f, (s32)v40);
            v10[3] = 5627.925f;
            (*(u8*)((u8*)v20+9)) = 1;
            (*(u16*)((u8*)v20+10)) = 0x47;
            (*(u8*)((u8*)v20+8)) = 0;
            func_003D4D00((s32)v0, 0x10, 0.4f, (s32)((Hero *)D_001A4BE0)->ptr[0x25C0/4], (s32)v10);
        }
        if (func_L01_004EE7F8(25.7f) != 0) {
            func_L01_003F1F20(0x19, 0);
            ((Hero *)D_001A4BE0)->h[0x1FA/2] = 0x2A;
            if (D_00142CBA[0] != 0) {
                ((Hero *)D_L30_001E22C0)->i[0x2C/4] = 0;
                ((Hero *)D_L30_001E22C0)->i[0x48/4] = 0x19;
                ((Hero *)D_001A4BE0)->h[0x224/2] = 0x1D;
                ((Hero *)D_L30_001E22C0)->f[0x40/4] = 0.1f;
            }
        }
        lim14 = 0xC;
        t14 = ((Hero *)D_001A4BE0)->i[0x1B8/4];
        if (t14 < 7) {
            vy = func_L01_005114B0((s32)(D_001A4BE0 + 0xF0));
            spF8 = vy;
            func_003C4138((s32)&spF8, rise, 0.060000002f);
            func_L01_00511508((s32)(D_001A4BE0 + 0xF0), (s32)(D_001A4BE0 + 0xF0), spF8);
        } else if (t14 > lim14) {
            func_L01_00510F08((s32)(D_001A4BE0 + 0xF0), (s32)(D_001A4BE0 + 0xF0), 0.052f);
            if (func_L01_005114B0((s32)(D_001A4BE0 + 0xF0)) < 0.0f) {
                ((Hero *)D_001A4BE0)->f[0xBE0/4] = 1.0f;
            }
            cap = -0.74000007f;
            if (D_L30_001D673C != 0) {
                cap = -1.4000001f;
            }
            if (func_L01_005114B0((s32)(D_001A4BE0 + 0xF0)) < cap) {
                func_L01_00511508((s32)(D_001A4BE0 + 0xF0), (s32)(D_001A4BE0 + 0xF0), cap);
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
        if ((((Hero *)D_001A4BE0)->i[0xC0C/4] != 0) || (((Hero *)D_001A4BE0)->f[0xC18/4] < (f32) D_L30_002F4C70[((Hero *)D_001A4BE0)->h[0xBDC/2]].w[0x18/4])) {
            ((Hero *)D_001A4BE0)->c[0x1219] = 2;
        }
        go = (((Hero *)D_001A4BE0)->i[0x25D0/4] == 1) && (((Hero *)D_001A4BE0)->i[0x25D8/4] >= 0x12);
        if (go == 0) {
            if ((((Hero *)D_001A4BE0)->i[0xBC8/4] != 0) || (((Hero *)D_001A4BE0)->i[0xBC4/4] != 0)) {
                near = 0;
                if (((Hero *)D_001A4BE0)->b[0x25F4] != 0) {
                    dyaw = func_L01_004F4E20((s32)(D_001A4BE0 + 0xBA0), 0);
                    dist = func_L01_004F4E20((s32)(D_001A4BE0 + 0xBA0), 1);
                } else {
                    dyaw = func_0038DB00(((Hero *)D_001A4BE0)->f[0xBCC/4], ((Hero *)D_001A4BE0)->f[0x98/4]);
                    dist = func_L01_004485E0(1, ((Hero *)D_001A4BE0)->f[0xBCC/4], ((Hero *)D_001A4BE0)->f[0x98/4]);
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
                    func_L01_004EEDD0(1, 0.08208001f, 0.28800002f, 0.3385939f);
                } else {
                    func_L01_004EEDD0(0, 0.08208001f, 0.28800002f, 0.3385939f);
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
                        func_L01_004F2880(14.0f, 0.5235988f, 0.7853982f);
                    }
                }
            }
        }
        if ((((Hero *)D_001A4BE0)->i[0xC0C/4] == 0) && (*(u8 *)((u8 *)((Hero *)D_001A4BE0)->ptr[0x25C0/4] + 0x43) == 0x1A) && (func_L01_004EE7F8(33.0f) != 0)) {
            if ((((Hero *)D_001A4BE0)->b[0x1474] != 0) && (((Hero *)D_001A4BE0)->f[0x170/4] < 0.040000003f)) {
                f32 push = 0.026f;
                ((Hero *)D_001A4BE0)->f[0xF0/4] += func_0038D098(((Hero *)D_001A4BE0)->f[0x98/4]) * push;
                ((Hero *)D_001A4BE0)->f[0xF4/4] += func_0038D0B0(((Hero *)D_001A4BE0)->f[0x98/4]) * push;
                ((Hero *)D_001A4BE0)->q[0x140/16] = ((Hero *)D_001A4BE0)->q[0xF0/16];
            }
            if (((Hero *)D_001A4BE0)->u[0x25C4/4] == 0x15) {
            lane = ((Hero *)D_001A4BE0)->i[0x1228/4];
            if ((lane == 0x7F) && (func_L01_005119E0(-1) != 0)) {
                func_L01_004F5AE8();
            } else if ((lane == 0x7F) && (((Hero *)D_001A4BE0)->i[0x1228/4] == lane) && (func_L01_005119E0(-1) == 0)) {
                func_L30_004CF4B0(0, 1);
            } else {
                func_L01_004F5810();
            }
            }
        }
        if (((Hero *)D_001A4BE0)->b[0x1474] != 0) {
            if (func_L01_004EE7F8(84.0f) != 0) {
                f32 a15 = func_0038DAB8(((Hero *)D_001A4BE0)->f[0x98/4], 3.1415927f);
                f32 k15 = 0.050000004f;
                if (D_001D52FC->i[0x1A0/4] & func_003A3BB8(8, 0)) {
                    k15 = 0.060000002f;
                }
                ((Hero *)D_001A4BE0)->f[0xF0/4] += func_0038D098(a15) * k15;
                ((Hero *)D_001A4BE0)->f[0xF4/4] += func_0038D0B0(a15) * k15;
                ((Hero *)D_001A4BE0)->q[0x140/16] = ((Hero *)D_001A4BE0)->q[0xF0/16];
            }
            func_L01_004F47F0();
        } else {
        func_L01_004EF128(0.014800001f, 0.0112000005f);
        func_L01_004EF178(99999.0f);
        if (((Hero *)D_001A4BE0)->h[0x36E/2] != 0) {
            func_L01_00510F08((s32)(D_001A4BE0 + 0xF0), (s32)D_001A4BE0 + 0x130, 0.010000001f);
        } else {
            func_L01_00510F08((s32)D_001A4BE0 + 0xF0, (s32)D_001A4BE0 + 0xF0, 0.0216f);
        }
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
        if ((((Hero *)D_001A4BE0)->i[0xC0C/4] != 0) || (((Hero *)D_001A4BE0)->f[0xC18/4] < (f32) D_L30_002F4C70[((Hero *)D_001A4BE0)->h[0xBDC/2]].w[0x20/4])) {
            ((Hero *)D_001A4BE0)->c[0x1219] = 2;
        }
        if (((Hero *)D_001A4BE0)->b[0x1474] != 0) {
            func_L01_004F47F0();
            break;
        }
        tgt13 = ((Hero *)D_001A4BE0)->i[0xBC4/4];
        ((Hero *)D_001A4BE0)->f[0x1B0/4] = 0.0f;
        rec13 = &D_L30_002F4C70[((Hero *)D_001A4BE0)->h[0xBDC/2]];
        if ((tgt13 != 0) && (((Hero *)D_001A4BE0)->i[0x1B8/4] < 3)) {
            d13 = func_0038CF38(tgt13 + 0x10, (s32)D_001A4BE0 + 0x80);
            if (D_L30_001D673C != 0) {
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
                dy13 = func_L01_004F4E20((s32)D_001A4BE0 + 0xBA0, 0);
            } else {
                dy13 = func_0038DB00(((Hero *)D_001A4BE0)->f[0xBCC/4], ((Hero *)D_001A4BE0)->f[0x98/4]);
            }
            r13 = fabs_asm(dy13);
            if ((rec13->w[1] == 1) && (dy13 > 0.0f)) {
                ((Hero *)D_001A4BE0)->f[0xC00/4] = 1.0f / (r13 + 1.0f);
            }
            ((Hero *)D_001A4BE0)->f[0x1A0/4] = ((Hero *)D_001A4BE0)->f[0xBCC/4];
            *(u128_t *)(&((Hero *)D_001A4BE0)->q[0x190/16]) = *(u128_t *)(&((Hero *)D_001A4BE0)->q[0xBA0/16]);
            func_L01_004EEDD0(0, 0.072000004f, 0.28800002f, 0.3385939f);
        } else {
            go13 = 1;
            if ((rec13->w[1] == 1) && (((Hero *)D_001A4BE0)->i[0xC0C/4] == 0) && (((Hero *)D_001A4BE0)->f[0xC18/4] > 7.0f)) {
                go13 = 0;
            }
            if (go13 != 0) {
                func_L01_004F2880(5.0f, 0.7853982f, 0.7853982f);
            }
        }
        func_L01_004EF128(0.014800001f, 0.0112000005f);
        if (((Hero *)D_001A4BE0)->i[0xBC8/4] != 0) {
            if (((Hero *)D_001A4BE0)->b[0x25F4] != 0) {
                func_L01_004EF238((s32)D_001A4BE0 + 0xBA0);
            } else {
                func_L01_004EF178(((Hero *)D_001A4BE0)->f[0xBCC/4]);
            }
        } else {
            func_L01_004EF178(99999.0f);
        }
        if (((Hero *)D_001A4BE0)->h[0x36E/2] != 0) {
            func_L01_00510F08((s32)D_001A4BE0 + 0xF0, (s32)D_001A4BE0 + 0x130, 0.010000001f);
        } else {
            func_L01_00510F08((s32)D_001A4BE0 + 0xF0, (s32)D_001A4BE0 + 0xF0, 0.0216f);
        }
        func_L01_004F52E0(3.7f, 0.0f, 0.35f);
        }
        break;
    case 0x7C:
        func_003C4138((s32)(D_001A4BE0 + 0x1B4), 0.0f, 0.0096f);
        if (D_L30_001D673C != 0) {
            func_0038CF68((s32)(D_001A4BE0 + 0xF0), (s32)(D_001A4BE0 + 0xBB0), ((Hero *)D_001A4BE0)->f[0x1B4/4]);
            if (((Hero *)D_001A4BE0)->f[0x33C/4] > 0.0f) {
                func_L01_00510F08((s32)(D_001A4BE0 + 0xF0), (s32)(D_001A4BE0 + 0x130), 0.010000001f);
            } else {
                func_L01_00511508((s32)(D_001A4BE0 + 0xF0), (s32)(D_001A4BE0 + 0xF0), 0.0f);
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
        func_L01_004EEDD0(0, 0.072000004f, 0.28800002f, 0.3385939f);
        break;
    case 0x22:
        ((Hero *)D_001A4BE0)->f[0x1B0/4] = 0.0f;
        if (((Hero *)D_001A4BE0)->i[0xBC8/4] != 0) {
            ((Hero *)D_001A4BE0)->f[0x1A0/4] = ((Hero *)D_001A4BE0)->f[0xBCC/4];
            *(u128_t *)(&((Hero *)D_001A4BE0)->q[0x190/16]) = *(u128_t *)(&((Hero *)D_001A4BE0)->q[0xBA0/16]);
            func_L01_004EEDD0(0, 0.057600003f, 0.28800002f, 0.3385939f);
        } else {
            func_L01_004F2880(11.0f, 0.87266463f, -1.0f);
        }
        func_L01_004EF128(0.012f, 0.014f);
        func_L01_004EF178(99999.0f);
        if (((Hero *)D_001A4BE0)->h[0x36E/2] != 0) {
            func_L01_00510F08((s32)D_001A4BE0 + 0xF0, (s32)D_001A4BE0 + 0x110, 0.0216f);
            func_L01_004EF268();
        } else {
            func_L01_00510F08((s32)D_001A4BE0 + 0xF0, (s32)D_001A4BE0 + 0xF0, 0.0216f);
        }
        break;
    case 0x2:
    case 0x75:
        {
        s32 flag;
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
        flag = 0;
        if ((((Hero *)D_001A4BE0)->b[0x1476] != 0) && (((Hero *)D_001A4BE0)->f[0x2848/4] < 0.25f)) {
            flag = 1;
        }
        if ((((Hero *)D_001A4BE0)->b[0x25EA] != 0) || (flag != 0)) {
            if (((Hero *)D_001A4BE0)->f[0x174/4] > 0.020000001f) {
                func_L01_004E5840(0, 2);
            }
            if (((Hero *)D_001A4BE0)->f[0x174/4] > 0.010000001f) {
                func_L01_004E5A20(2, 4);
            }
            func_L01_004E5C08(5, 2, 0);
        }
        if (!((((Hero *)D_001A4BE0)->h[0x1434/2] != 0) || ((((Hero *)D_001A4BE0)->i[0x16B0/4] == 1) && (func_L01_004606E8(0x28, 2, 0, 0) != 0)))) {
            if (((Hero *)D_001A4BE0)->f[0x174/4] < 0.034f) {
                ((Hero *)D_001A4BE0)->b[0x3EC] = 1;
                if (fabs_asm(((Hero *)D_001A4BE0)->f[0x1A8/4]) > 2.0943952f) {
                    if (((Hero *)D_001A4BE0)->f[0x2838/4] == 1.0f) {
                        ((Hero *)D_001A4BE0)->b[0x3EF] = 1;
                    }
                }
            }
            f1b = func_L01_00460818(1, 0);
            if (func_0038DBA0(f1b, func_L01_00460818(7, 0)) > 1.9198622f) {
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
            func_L01_004EEBA8();
            if ((func_L01_004E9238(0) == 9) && ((((Hero *)D_001A4BE0)->f[0x283C/4] == 1.0f) || (((Hero *)D_001A4BE0)->i[0x3F0/4] != 0)) && (((Hero *)D_001A4BE0)->b[0x25EB] == 0)) {
                *(u128_t *)(&((Hero *)D_001A4BE0)->q[0x3D0/16]) = *(u128_t *)(&((Hero *)D_001A4BE0)->q[0x190/16]);
                ((Hero *)D_001A4BE0)->f[0x3E8/4] = ((Hero *)D_001A4BE0)->f[0x1A0/4];
                ((Hero *)D_001A4BE0)->i[0x3F0/4] = 1;
            } else {
                *(u128_t *)(&((Hero *)D_001A4BE0)->q[0x3D0/16]) = *(u128_t *)(&((Hero *)D_001A4BE0)->q[0x0/16]);
                ((Hero *)D_001A4BE0)->f[0x3E8/4] = ((Hero *)D_001A4BE0)->f[0x98/4];
            }
        }
        if (((Hero *)D_001A4BE0)->f[0x9F0/4] > 0.0f) {
            func_L01_004F0558(0.7f, 0.0f);
            (*(u128_t*)v0) = ((Hero *)D_001A4BE0)->q[0x9E0/16];
            f1a = ((Hero *)D_001A4BE0)->f[0x1B0/4] + func_L01_004F05F0((s32)v0);
            ((Hero *)D_001A4BE0)->f[0x1B0/4] = f1a;
            if (f1a < 0.014f) {
                ((Hero *)D_001A4BE0)->f[0x1B0/4] = 0.014f;
            }
            qzero((V4 *)(D_001A4BE0 + 0x9E0));
        }
        scale = 1.0f;
        if ((((Hero *)D_001A4BE0)->h[0x1434/2] != 0) || ((((Hero *)D_001A4BE0)->i[0x16B0/4] == 1) && (func_L01_004606E8(0x28, 2, 0, 0) != 0))) {
            func_L01_004EE400();
        } else {
            ((Hero *)D_001A4BE0)->f[0x1438/4] = ((Hero *)D_001A4BE0)->f[0x98/4];
            *(u128_t *)(&((Hero *)D_001A4BE0)->q[0x1420/16]) = *(u128_t *)(&((Hero *)D_001A4BE0)->q[0x0/16]);
            if ((((Hero *)D_001A4BE0)->i[0x25C8/4] == 1) && (((Hero *)D_001A4BE0)->b[0x3EF] == 0) && (((Hero *)D_001A4BE0)->b[0x25EB] == 0)) {
                func_L01_004EEDD0(0, 0.053280003f, 0.1872f, 0.2443461f);
            } else {
                ab = fabs_asm(((Hero *)D_001A4BE0)->f[0x1A8/4]);
                if (((((Hero *)D_001A4BE0)->f[0x2838/4] < 0.9f) || ((((Hero *)D_001A4BE0)->b[0x25EB] != 0) && (((Hero *)D_001A4BE0)->b[0x3EF] == 0))) && (ab > 0.7853982f)) {
                    scale = 0.0f;
                }
                func_L01_004EEEC0();
            }
        }
        func_L01_004F2E68();
        func_L01_004F3F40();
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
        func_L01_004EF128(spd, k13);
        if ((((Hero *)D_001A4BE0)->b[0x3EC] != 0) || (((Hero *)D_001A4BE0)->h[0x1434/2] != 0) || ((((Hero *)D_001A4BE0)->i[0x16B0/4] == 1) && (func_L01_004606E8(0x28, 2, 0, 0) != 0))) {
            if (((Hero *)D_001A4BE0)->b[0x25F4] == 0) {
                if ((((Hero *)D_001A4BE0)->h[0x1434/2] != 0) || ((((Hero *)D_001A4BE0)->i[0x16B0/4] == 1) && (func_L01_004606E8(0x28, 2, 0, 0) != 0))) {
                    func_L01_004EF178(((Hero *)D_001A4BE0)->f[0x1438/4]);
                } else {
                    func_L01_004EF178(((Hero *)D_001A4BE0)->f[0x1A0/4]);
                }
            } else if ((((Hero *)D_001A4BE0)->h[0x1434/2] != 0) || ((((Hero *)D_001A4BE0)->i[0x16B0/4] == 1) && (func_L01_004606E8(0x28, 2, 0, 0) != 0))) {
                func_L01_004EF238((s32) (D_001A4BE0 + 0x1420));
            } else {
                func_L01_004EF238((s32) (D_001A4BE0 + 0x190));
            }
        } else {
            func_L01_004EF178(99999.0f);
        }
        func_L30_004BD6C0(0);
        if (((Hero *)D_001A4BE0)->h[0x214/2] != 0) {
            func_L01_004F52E0(5.0f, 0.2f, 0.35f);
        }
        if (((Hero *)D_001A4BE0)->h[0x36E/2] != 0) {
            func_L01_00510F08((s32)D_001A4BE0 + 0xF0, (s32)D_001A4BE0 + 0x130, 0.010000001f);
            func_L01_004EF268();
        } else {
            func_L01_00510F08((s32)D_001A4BE0 + 0xF0, (s32)D_001A4BE0 + 0xF0, 0.0216f);
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
        func_L01_004F4F18(4, (s32) ((Hero *)D_001A4BE0)->ptr[0x25C0/4], 0xD);
        func_L01_003F1F20(0x16, 0);
        func_L30_004BCB20(1.0f, 0);
        ((Hero *)D_001A4BE0)->f[0x1B0/4] = 0.23000002f;
        func_L01_004E4F30((s32)v0, (s32) (D_001A4BE0 + 0x970), 0.24480002f);
        tilt = ((Hero *)D_001A4BE0)->f[0x2838/4] * 0.024434611f * v0[0];
        if ((D_L30_001D673C == 0) && (((Hero *)D_001A4BE0)->i[0x1B8/4] < 0x32)) {
            ((Hero *)D_001A4BE0)->f[0x1B0/4] = 0.6f;
        }
        n80 = ((Hero *)D_001A4BE0)->i[0x1B8/4];
        lim80 = 0x2A;
        if (n80 < lim80) {
            tilt *= (f32)n80 / (f32)lim80;
        }
        if ((n80 >= 0x12) && (func_L01_004F52E0(2.5f, 0.0f, 1.5f) != 0)) {
            ((Hero *)D_001A4BE0)->i[0x984/4] = 1;
        }
        if (((Hero *)D_001A4BE0)->f[0x2838/4] > 0.2f) {
            func_L01_004EEC98(0.0f, 0.0f, tilt);
        }
        func_L01_004EF128(0.040000003f, 0.006f);
        func_L01_004EF178(99999.0f);
        if (D_L30_001D673C != 0) {
            *(u128_t *)(v10) = *(u128_t *)(&((Hero *)D_001A4BE0)->q[0x2F0/16]);
            func_L01_00511158((s32)v10, (s32)v10, 0.17f);
            func_L01_00448340((s32) (D_001A4BE0 + 0x80), (s32)v10, (s32) (D_001A4BE0 + 0x980), 0.057600003f, 0.43200004f, 0.15f);
        } else {
            func_L01_004482A0((s32) (D_001A4BE0 + 0x88), (s32) (D_001A4BE0 + 0x980), ((Hero *)D_001A4BE0)->f[0x338/4] + 0.17f, 0.057600003f, 0.43200004f, 0.15f);
        }
        func_0038CE20((s32)v10, (s32)(D_001A4BE0 + 0x110), 3.0f);
        vec_add_ab((V4 *)v10, (V4 *)v10, (V4 *)(D_001A4BE0 + 0xE0));
        cnt80 = func_003D4D00((s32)v10, 0, 0.57f, (s32) ((Hero *)D_001A4BE0)->ptr[0x25C0/4], 0);
        if (cnt80 != 0) {
            func_0038CE20((s32)v20, (s32)(D_001A4BE0 + 0x110), 7.0f);
            for (i80 = 0; i80 < cnt80; i80++) {
                if (func_003C4B50(((s32 *)D_L30_001ED080)[i80]) != 0) {
                    func_L01_00446A70(((s32 *)D_L30_001ED080)[i80], (s32) ((Hero *)D_001A4BE0)->ptr[0x25C0/4], 0x10000, (s32) (D_001A4BE0 + 0x80), (s32)v20, 1.0f);
                }
            }
        }
        func_L01_004E6390(0.024480002f, 0.43200004f);
        func_L01_004E63C0(0.036000002f, 0.43200004f);
        func_L01_004E63D8(0.0432f, 0.38880002f);
        cl80 = tilt * 27.0f;
        if (cl80 > 1.7f) {
            cl80 = 1.7f;
        } else if (cl80 < -1.7f) {
            cl80 = -1.7f;
        }
        ((Hero *)D_L30_002F2EE0)->f[0x60/4] = -cl80;
        ((Hero *)D_L30_002F2EE0)->f[0x278/4] = cl80 * 0.5f;
        ((Hero *)D_L30_002F2EE0)->f[0x1C8/4] = cl80 * 0.5f;
        }
        break;
    case 0x2E:
        func_L01_004F47F0();
        if (!((((Hero *)D_001A4BE0)->h[0x1434/2] != 0) || ((((Hero *)D_001A4BE0)->i[0x16B0/4] == 1) && (func_L01_004606E8(0x28, 2, 0, 0) != 0)))) {
            f32 a2E;
            f32 b2E;
            f32 r2E;
            f32 y2E;
            f32 s2E;
            a2E = 0.2f;
            b2E = 0.04f;
            func_L01_004E6390(b2E, a2E);
            func_L01_004E63A8(b2E, a2E);
            func_L01_004E63C0(b2E, a2E);
            func_L01_004E63D8(0.02f, a2E);
            if ((*(u8 *)((u8 *)temp_fp + 0x43)) == 0x32) {
                r2E = ((Hero *)D_001A4BE0)->f[0x1A8/4];
                if (r2E > 1.4f) {
                    r2E = 1.4f;
                } else if (r2E < -1.4f) {
                    r2E = -1.4f;
                }
                ((Hero *)D_L30_002F2EE0)->f[0x60/4] = r2E * -0.14f;
                ((Hero *)D_L30_002F2EE0)->f[0x118/4] = r2E * 0.3f;
                ((Hero *)D_L30_002F2EE0)->f[0x1C0/4] = r2E * -0.22f;
                ((Hero *)D_L30_002F2EE0)->f[0x278/4] = r2E * 0.4f;
                ((Hero *)D_L30_002F2EE0)->f[0x274/4] = fabs_asm(r2E) * -0.09f;
                ((Hero *)D_L30_002F2EE0)->f[0x270/4] = fabs_asm(r2E) * 0.08f;
            } else if ((*(u8 *)((u8 *)temp_fp + 0x43)) == 0x54) {
                y2E = func_0038DAB8(func_0038DB00(func_0038D160(((Hero *)D_001A4BE0)->f[0x110/4], ((Hero *)D_001A4BE0)->f[0x114/4]), ((Hero *)D_001A4BE0)->f[0x98/4]), 3.1415927f);
                s2E = ((Hero *)D_001A4BE0)->f[0x174/4] / 0.060000002f * 0.34906584f;
                if (s2E > 0.43633232f) {
                    s2E = 0.43633232f;
                }
                {
                f32 sn2E = func_0038D098(y2E) * s2E;
                f32 cn2E = -func_0038D0B0(y2E) * s2E;
                ((Hero *)D_L30_002F2EE0)->f[0x114/4] = sn2E;
                ((Hero *)D_L30_002F2EE0)->f[0x110/4] = cn2E;
                }
            }
        }
        if (((Hero *)D_001A4BE0)->h[0x36E/2] != 0) {
            func_L01_00510F08((s32)D_001A4BE0 + 0xF0, (s32)D_001A4BE0 + 0x110, 0.010000001f);
        } else {
            ((Hero *)D_001A4BE0)->i[0xF8/4] = 0;
            func_L01_00510F08((s32)(D_001A4BE0 + 0xF0), (s32)(D_001A4BE0 + 0xF0), 0.060000002f);
        }
        break;
    case 0x30:
        {
        f32 yaw30;
        f32 d30;
        f32 t30;
        f32 vz30;
        func_L01_004F4F18(2, (s32)((Hero *)D_001A4BE0)->ptr[0x25C0/4], 6);
        func_L01_004E5C08(4, 2, 0);
        v0[0] = ((Hero *)D_001A4BE0)->f[0x80/4] + func_003824E0(-0.25f, 0.25f);
        v0[1] = ((Hero *)D_001A4BE0)->f[0x84/4] + func_003824E0(-0.25f, 0.25f);
        v0[2] = ((Hero *)D_001A4BE0)->f[0x88/4] + func_003824E0(-0.1f, 0.4f);
        func_0038CE20((s32)v10, (s32)(D_001A4BE0 + 0x110), 0.9f);
        v10[0] += func_003824E0(-0.014f, 0.014f);
        v10[1] += func_003824E0(-0.014f, 0.014f);
        v10[2] += func_003824E0(0.020000001f, 0.040000003f);
        func_L01_0046ADE0((s32)v0, (s32)v10, func_003824E0(37800.0f, 75600.0f));
        ((Hero *)D_001A4BE0)->f[0x1A0/4] = ((Hero *)D_001A4BE0)->f[0xB20/4];
        yaw30 = ((Hero *)D_001A4BE0)->f[0x98/4];
        func_L01_004EEDD0(0, 0.04752f, 0.43200004f, 0.08377581f);
        d30 = func_0038DBA0(((Hero *)D_001A4BE0)->f[0x98/4], yaw30);
        qzero((V4 *)(D_001A4BE0 + 0xF0));
        func_L01_004F4730(0.0028000001f);
        vz30 = ((Hero *)D_001A4BE0)->f[0x118/4] - 0.020000001f;
        ((Hero *)D_001A4BE0)->f[0xF8/4] = vz30;
        if (vz30 > -0.016f) {
            ((Hero *)D_001A4BE0)->f[0xF8/4] = -0.016f;
        }
        if (d30 > 0.02792527f) {
            d30 = 0.02792527f;
        }
        t30 = d30 * 9.0f;
        func_L01_00448728((s32)(D_001A4BE0 + 0x90), t30 * 0.5f, (s32)(D_001A4BE0 + 0xB34), 0.007f, 0.17f, 0.024434611f, 0);
        func_L01_00448728((s32)(D_001A4BE0 + 0x94), -((Hero *)D_001A4BE0)->f[0xB24/4], (s32)(D_001A4BE0 + 0xB38), 0.050400004f, 0.43200004f, 0.038397245f, 0);
        func_L01_004E63A8(0.009f, 0.22f);
        func_L01_004E63C0(0.04f, 0.2f);
        func_L01_004E63D8(0.02f, 0.2f);
        ((Hero *)D_L30_002F2EE0)->f[0x118/4] = t30 * 2.1f;
        ((Hero *)D_L30_002F2EE0)->f[0x110/4] = t30 * 3.5f;
        }
        break;
    case 0x27:
    case 0x28:
    case 0x29:
    case 0x2A:
    case 0x3E:
        {
        u32 st27;
        s32 t278C;
        s32 lane27;
        s32 def27;
        s32 sel27;
        s32 go27;
        s32 t5E0;
        s32 k27;
        s32 n27;
        s32 c27;
        f32 a27;
        f32 r27;
        f32 m27;
        f32 x27;
        f32 spd27;
        f32 aK;
        f32 aL;
        f32 rL;
        f32 lL;
        s32 nI;
        f32 b27;
        f32 c578;
        s32 spFC;
        f32 sp100;
        s32 sp104;
        f32 sp108;
        f32 sp10C;
        st27 = ((Hero *)D_001A4BE0)->u[0x25C4/4];
        if (((u32)(st27 - 0x28) >= 2U) && (st27 != 0x3E)) {
            func_L01_004F4F18(0, (s32)((Hero *)D_001A4BE0)->ptr[0x25C0/4], 0);
        } else {
            t278C = ((Hero *)D_001A4BE0)->i[0x278C/4];
            if (t278C != -1) {
                u8 *o = (u8 *)D_001A30B0 + (t278C << 7);
                if ((*(void **)(o + 0xDC) == ((Hero *)D_001A4BE0)->ptr[0x25C0/4]) && (*(u8 *)(o + 0xD0) != 0)) {
                    func_003A4F28(t278C);
                }
            }
            ((Hero *)D_001A4BE0)->i[0x278C/4] = -1;
        }
        st27 = ((Hero *)D_001A4BE0)->u[0x25C4/4];
        if ((st27 == 0x27) || (st27 == 0x2A)) {
            f32 aB;
            f32 rB;
            *(u128_t *)v0 = ((Hero *)D_001A4BE0)->q[0x80/16];
            aB = func_0038DAB8(((Hero *)D_001A4BE0)->f[0x5EC/4], func_L01_00443A18(0.0f, 0.5235988f));
            rB = func_003824E0(0.080000006f, 0.14000002f);
            v10[0] = func_0038D098(aB) * rB;
            v10[1] = func_0038D0B0(aB) * rB;
            v10[2] = 0.0f;
            v10[2] = func_003824E0(0.060000002f, 0.10000001f);
            v10[3] = -0.012f;
            func_L01_00466F50((s32)v0, (s32)v10, 0, -1.0f, 0.0f);
        }
        lane27 = ((Hero *)D_001A4BE0)->i[0x1228/4];
        def27 = (((ItemDef *)D_L30_002C3E80)[D_001425C0[lane27]].x18 != 0);
        if (lane27 == 0xB) {
            def27 = 0;
        }
        sel27 = 0;
        if (def27 != 0) {
            sel27 = ((Hero *)D_001A4BE0)->b[0x25EB] != 0;
        }
        func_L01_00476B98(((Hero *)D_001A4BE0)->i[0x5D0/4], (s32)(D_001A4BE0 + 0x80), (s32)(D_001A4BE0 + 0x570), (s32)(D_001A4BE0 + 0x5D4), (s32)(D_001A4BE0 + 0x5D8), ((Hero *)D_001A4BE0)->i[0x5F4/4], 999.0f, 2.0f, 2.5f);
        if (((Hero *)D_001A4BE0)->i[0x600/4] != 0) {
            func_L01_00476B98(((Hero *)D_001A4BE0)->i[0x604/4], (s32)(D_001A4BE0 + 0x80), (s32)(D_001A4BE0 + 0x5B0), (s32)(D_001A4BE0 + 0x608), (s32)(D_001A4BE0 + 0x60C), ((Hero *)D_001A4BE0)->i[0x610/4], 999.0f, 2.0f, 2.5f);
        }
        go27 = 0;
        if (((Hero *)D_001A4BE0)->f[0x33C/4] > 1.0699999f) {
            st27 = ((Hero *)D_001A4BE0)->u[0x25C4/4];
            if ((st27 != 0x28) && (st27 != 0x3E) && (((Hero *)D_001A4BE0)->i[0x600/4] == 0)) {
                go27 = ((Hero *)D_001A4BE0)->i[0x1BC/4] >= 0x1A;
            }
        }
        if (go27 != 0) {
            ((Hero *)D_001A4BE0)->i[0x668/4]++;
        } else {
            ((Hero *)D_001A4BE0)->i[0x668/4] = 0;
        }
        t5E0 = ((Hero *)D_001A4BE0)->i[0x5E0/4];
        if (((t5E0 != 0) && ((((Hero *)D_001A4BE0)->i[0x5E0/4] = t5E0 + 1) != 0)) || (go27 != 0)) {
            *(u128_t *)(D_001A4BE0 + 0xF0) = *(u128_t *)(D_001A4BE0 + 0x120);
            if ((u32)(((Hero *)D_001A4BE0)->u[0x25C4/4] - 0x28) < 2U) {
                func_L01_004F1638();
                break;
            }
            if (func_0038CED8((s32)(D_001A4BE0 + 0xF0)) < 0.050000004f) {
                func_003C4138((s32)(D_001A4BE0 + 0x1B4), 0.080000006f, 0.016f);
                ((Hero *)D_001A4BE0)->f[0xF0/4] = func_0038D098(((Hero *)D_001A4BE0)->f[0x5EC/4]) * ((Hero *)D_001A4BE0)->f[0x1B4/4];
                ((Hero *)D_001A4BE0)->f[0xF4/4] = func_0038D0B0(((Hero *)D_001A4BE0)->f[0x5EC/4]) * ((Hero *)D_001A4BE0)->f[0x1B4/4];
            }
            ((Hero *)D_001A4BE0)->f[0xF8/4] = ((Hero *)D_001A4BE0)->f[0xF8/4] - 0.0088f;
            break;
        }
        b27 = (f32)((Hero *)D_001A4BE0)->i[0x5E8/4];
        spd27 = ((Hero *)D_001A4BE0)->f[0x5E4/4] * b27;
        if (((Hero *)D_001A4BE0)->u[0x25C4/4] == 0x3E) {
            spd27 = ((Hero *)D_001A4BE0)->f[0x63C/4] * b27;
        }
        func_L01_00476498(((Hero *)D_001A4BE0)->i[0x5D0/4], (s32)v0, (s32)(D_001A4BE0 + 0x5D4), (s32)(D_001A4BE0 + 0x5D8), spd27, ((Hero *)D_001A4BE0)->i[0x5F4/4]);
        if (((Hero *)D_001A4BE0)->i[0x600/4] != 0) {
            func_L01_00476498(((Hero *)D_001A4BE0)->i[0x604/4], (s32)v10, (s32)(D_001A4BE0 + 0x608), (s32)(D_001A4BE0 + 0x60C), spd27, ((Hero *)D_001A4BE0)->i[0x610/4]);
        }
        if (((Hero *)D_001A4BE0)->i[0x1BC/4] >= 0x4C) {
            f32 rS = ((Hero *)D_001A4BE0)->f[0x170/4] * 25.333334f;
            f32 aS;
            *(u128_t *)v20 = ((Hero *)D_001A4BE0)->q[0x80/16];
            spFC = ((Hero *)D_001A4BE0)->i[0x5D4/4];
            sp100 = ((Hero *)D_001A4BE0)->f[0x5D8/4];
            k27 = func_L01_00476498(((Hero *)D_001A4BE0)->i[0x5D0/4], (s32)v20, (s32)&spFC, (s32)&sp100, rS, ((Hero *)D_001A4BE0)->i[0x5F4/4]);
            *(u128_t *)v30 = ((Hero *)D_001A4BE0)->q[0x80/16];
            spFC = ((Hero *)D_001A4BE0)->i[0x5D4/4];
            sp100 = ((Hero *)D_001A4BE0)->f[0x5D8/4];
            k27 |= func_L01_00476498(((Hero *)D_001A4BE0)->i[0x5D0/4], (s32)v30, (s32)&spFC, (s32)&sp100, rS + 0.1f, ((Hero *)D_001A4BE0)->i[0x5F4/4]);
            if (((k27 == 0) || (((Hero *)D_001A4BE0)->i[0x5F4/4] != 0)) && (((Hero *)D_001A4BE0)->u[0x25C4/4] == 0x27)) {
                aS = func_0038DB00(((Hero *)D_001A4BE0)->f[0x5EC/4], func_0038D160(v30[0] - v20[0], v30[1] - v20[1])) * 0.47f;
                if (aS > 0.7853982f) {
                    aS = 0.7853982f;
                }
                if (aS < -0.7853982f) {
                    aS = -0.7853982f;
                }
                func_L01_004E6390(0.03f, 0.2f);
                if (((Hero *)D_001A4BE0)->i[0x5FC/4] != 0) {
                    ((Hero *)D_L30_002F2EE0)->f[0x64/4] = -aS;
                } else {
                    ((Hero *)D_L30_002F2EE0)->f[0x64/4] = aS;
                }
            }
        }
        st27 = ((Hero *)D_001A4BE0)->u[0x25C4/4];
        if ((st27 != 0x28) && (st27 != 0x3E) && (st27 != 0x29)) {
            ((Hero *)D_L30_002F2EE0)->f[0x60/4] = func_0038D160(func_0038CED8((s32)(D_001A4BE0 + 0x110)), ((Hero *)D_001A4BE0)->f[0x118/4]);
        }
        if (def27 != 0) {
            m27 = 0.43200004f;
            func_L01_004E63D8(0.024480002f, m27);
            func_L01_004E63A8(0.03888f, m27);
            func_L01_004E63C0(0.03888f, m27);
            if (((Hero *)D_001A4BE0)->i[0x648/4] != 0) {
                f32 aH;
                vec_sub_ab((V4 *)v20, (V4 *)(((Hero *)D_001A4BE0)->i[0x648/4] + 0x10), (V4 *)(D_001A4BE0 + 0x80));
                func_0038D000((s32)v20, (s32)v20, (s32)(D_001A4BE0 + 0x40));
                aH = func_0038D160(v20[0], v20[1]);
                if ((*(u8 *)((u8 *)((Hero *)D_001A4BE0)->ptr[0x25C0/4] + 0x42)) == 0x2C) {
                    aH = func_0038DB00(aH, 1.5707964f);
                    ((Hero *)D_L30_002F2EE0)->f[0x278/4] = aH * 0.3f;
                    ((Hero *)D_L30_002F2EE0)->f[0x1C8/4] = aH * 0.2f;
                } else {
                    aH = func_0038DB00(aH, -1.5707964f);
                    ((Hero *)D_L30_002F2EE0)->f[0x278/4] = aH * 0.3f;
                    ((Hero *)D_L30_002F2EE0)->f[0x1C8/4] = aH * 0.5f;
                }
            } else {
                f32 rH;
                f32 xH;
                c27 = *(u8 *)((u8 *)((Hero *)D_001A4BE0)->ptr[0x25C0/4] + 0x43);
                if (c27 == 0x2C) {
                    rH = 1.7f;
                    xH = 0.7330383f;
                    ((Hero *)D_L30_002F2EE0)->f[0x278/4] = func_0038DAB8(-0.82030475f, ((Hero *)D_001A4BE0)->f[0x640/4]);
                    ((Hero *)D_L30_002F2EE0)->f[0x118/4] = func_0038DAB8(xH, ((Hero *)D_001A4BE0)->f[0x640/4] / rH);
                    ((Hero *)D_L30_002F2EE0)->f[0x1C8/4] = func_0038DAB8(xH, ((Hero *)D_001A4BE0)->f[0x640/4] / rH);
                } else if (c27 == 0x43) {
                    rH = 0.5f;
                    xH = -0.06981317f;
                    ((Hero *)D_L30_002F2EE0)->f[0x278/4] = func_0038DAB8(0.13962634f, ((Hero *)D_001A4BE0)->f[0x640/4]);
                    ((Hero *)D_L30_002F2EE0)->f[0x118/4] = func_0038DAB8(xH, ((Hero *)D_001A4BE0)->f[0x640/4] * rH);
                    ((Hero *)D_L30_002F2EE0)->f[0x1C8/4] = func_0038DAB8(xH, ((Hero *)D_001A4BE0)->f[0x640/4] * rH);
                } else if (c27 == 0x42) {
                    rH = 1.7f;
                    xH = 0.7330383f;
                    ((Hero *)D_L30_002F2EE0)->f[0x278/4] = func_0038DAB8(-0.82030475f, ((Hero *)D_001A4BE0)->f[0x640/4]);
                    ((Hero *)D_L30_002F2EE0)->f[0x118/4] = func_0038DAB8(xH, ((Hero *)D_001A4BE0)->f[0x640/4] / rH);
                    ((Hero *)D_L30_002F2EE0)->f[0x1C8/4] = func_0038DAB8(xH, ((Hero *)D_001A4BE0)->f[0x640/4] / rH);
                }
            }
        }
        nI = func_L01_00476440(((Hero *)D_001A4BE0)->i[0x5D0/4], ((Hero *)D_001A4BE0)->i[0x5D4/4], ((Hero *)D_001A4BE0)->i[0x5E8/4], ((Hero *)D_001A4BE0)->i[0x5F4/4]);
        vec_sub_ba((V4 *)v20, (V4 *)((u8 *)((Hero *)D_001A4BE0)->i[0x5D0/4] + nI * 16 + 0x10), (V4 *)v0);
        if (func_0038CEA8((s32)v20) < 0.001f) {
            if (((Hero *)D_001A4BE0)->i[0x5D4/4] == nI) {
                ((Hero *)D_001A4BE0)->i[0x5E0/4] = 1;
                break;
            }
        } else {
            ((Hero *)D_001A4BE0)->f[0x5EC/4] = func_0038D160(v20[0], v20[1]);
            ((Hero *)D_001A4BE0)->f[0x5F0/4] = func_0038D160(func_0038CED8((s32)v20), v20[2]);
        }
        ((Hero *)D_001A4BE0)->f[0x1A0/4] = func_0038DAB8(((Hero *)D_001A4BE0)->f[0x5EC/4], ((Hero *)D_001A4BE0)->f[0x5F8/4]);
        func_L01_004EEDD0(0, 0.0216f, 0.21600002f, 0.12566371f);
        st27 = ((Hero *)D_001A4BE0)->u[0x25C4/4];
        if ((((u32)(st27 - 0x28) < 2U) && (((Hero *)D_001A4BE0)->b[0x46C] == 0)) || (st27 == 0x3E)) {
            if (((Hero *)D_001A4BE0)->i[0x634/4] != 0) {
                f32 aJ;
                aJ = func_0038D160(((Hero *)D_001A4BE0)->f[0x5C0/4] - ((Hero *)D_001A4BE0)->f[0x80/4], ((Hero *)D_001A4BE0)->f[0x5C4/4] - ((Hero *)D_001A4BE0)->f[0x84/4]);
                if (func_0038DBA0(((Hero *)D_001A4BE0)->f[0x98/4], aJ) < 1.5707964f) {
                    ((Hero *)D_001A4BE0)->f[0x1A0/4] = aJ;
                    func_L01_004EEDD0(0, 0.057600003f, 0.28800002f, 0.12566371f);
                }
            }
            if ((((Hero *)D_001A4BE0)->i[0x600/4] != 0) && (((Hero *)D_001A4BE0)->i[0x618/4] < 0x29)) {
                f32 a578;
                f32 a88;
                s32 n618;
                n618 = ((Hero *)D_001A4BE0)->i[0x618/4] + 1;
                vec_sub_ba((V4 *)v20, (V4 *)v0, (V4 *)v10);
                ((Hero *)D_001A4BE0)->i[0x618/4] = n618;
                func_0038CE20((s32)v20, (s32)v20, (f32)n618 / 40.0f);
                vec_sub_ba((V4 *)v30, (V4 *)v0, (V4 *)v10);
                func_0038CE20((s32)v30, (s32)v30, (f32)(((Hero *)D_001A4BE0)->i[0x618/4] - 1) / 40.0f);
                ((Hero *)D_001A4BE0)->f[0x88/4] = ((Hero *)D_001A4BE0)->f[0x88/4] + (v20[2] - v30[2]);
                vec_add_ba((V4 *)v30, (V4 *)v10, (V4 *)v20);
                vec_sub_ab((V4 *)v20, (V4 *)v30, (V4 *)(D_001A4BE0 + 0x80));
                ((Hero *)D_001A4BE0)->f[0xF0/4] = v20[0];
                ((Hero *)D_001A4BE0)->f[0xF4/4] = v20[1];
                vec_sub_ab((V4 *)v20, (V4 *)v0, (V4 *)(D_001A4BE0 + 0x570));
                a578 = ((Hero *)D_001A4BE0)->f[0x578/4];
                a88 = ((Hero *)D_001A4BE0)->f[0x88/4] + v20[2];
                ((Hero *)D_001A4BE0)->f[0x88/4] = a88;
                if (a88 < a578) {
                    if (((Hero *)D_001A4BE0)->i[0x618/4] < 0x29) {
                        if (a88 < a578) {
                            ((Hero *)D_001A4BE0)->f[0x88/4] = a578;
                        }
                    }
                }
            } else {
                vec_sub_ab((V4 *)v20, (V4 *)v0, (V4 *)(D_001A4BE0 + 0x570));
                ((Hero *)D_001A4BE0)->f[0xF0/4] = v20[0];
                ((Hero *)D_001A4BE0)->f[0xF4/4] = v20[1];
                ((Hero *)D_001A4BE0)->f[0x88/4] = ((Hero *)D_001A4BE0)->f[0x88/4] + v20[2];
                vec_sub_ba((V4 *)v30, (V4 *)(D_001A4BE0 + 0x570), (V4 *)(D_001A4BE0 + 0x80));
                v30[2] = 0.0f;
                if (func_0038CEA8((s32)v30) > 0.020000001f) {
                    func_0038CF68((s32)v30, (s32)v30, 0.020000001f);
                }
                ((Hero *)D_001A4BE0)->f[0x80/4] = ((Hero *)D_001A4BE0)->f[0x80/4] + v30[0];
                ((Hero *)D_001A4BE0)->f[0x84/4] = ((Hero *)D_001A4BE0)->f[0x84/4] + v30[1];
            }
            if (((Hero *)D_001A4BE0)->u[0x25C4/4] == 0x3E) {
                ((Hero *)D_001A4BE0)->f[0xF8/4] = ((Hero *)D_001A4BE0)->f[0xF8/4] - 0.0092f;
            } else {
                func_L01_004F1638();
            }
        } else {
            ((Hero *)D_001A4BE0)->i[0x600/4] = 0;
            aK = 0.0f;
            if ((((Hero *)D_001A4BE0)->f[0x2838/4] > 0.2f) && (sel27 != 0)) {
                func_L30_004BCB20(1.0f, 0);
                aK = func_0038DB00(((Hero *)D_001A4BE0)->f[0x1A0/4], ((Hero *)D_001A4BE0)->f[0x5EC/4]);
                if (aK > 0.7853982f) {
                    aK = 0.7853982f;
                } else if (aK < -0.7853982f) {
                    aK = -0.7853982f;
                }
            }
            func_L01_00448728((s32)(D_001A4BE0 + 0x640), aK, (s32)(D_001A4BE0 + 0x644), 0.0216f, 0.43200004f, 0.0f, 0);
            func_003C4138((s32)(D_001A4BE0 + 0x620), 0.24000001f, 0.006f);
            sp104 = ((Hero *)D_001A4BE0)->i[0x5D4/4];
            sp108 = ((Hero *)D_001A4BE0)->f[0x5D8/4];
            *(u128_t *)v20 = ((Hero *)D_001A4BE0)->q[0x80/16];
            func_L01_00476498(((Hero *)D_001A4BE0)->i[0x5D0/4], (s32)v20, (s32)&sp104, (s32)&sp108, 0.3f, ((Hero *)D_001A4BE0)->i[0x5F4/4]);
            aL = func_0038D160(func_0038CF38((s32)(D_001A4BE0 + 0x570), (s32)v20), v20[2] - ((Hero *)D_001A4BE0)->f[0x578/4]);
            if (aL > 0.0f) {
                rL = aL * 1.9098593f * -0.050000004f;
                if (aL > 0.2617994f) {
                    ((Hero *)D_001A4BE0)->i[0x61C/4] = 0;
                } else if ((aL < 0.13962634f) && (((Hero *)D_001A4BE0)->i[0x61C/4] == 0)) {
                    ((Hero *)D_001A4BE0)->i[0x61C/4] = -1;
                }
            } else {
                rL = -aL * 2.864789f * 0.16000001f;
                if (aL < -0.19198622f) {
                    ((Hero *)D_001A4BE0)->i[0x61C/4] = 1;
                } else if ((aL > -0.12217305f) && (((Hero *)D_001A4BE0)->i[0x61C/4] == 1)) {
                    ((Hero *)D_001A4BE0)->i[0x61C/4] = -1;
                }
            }
            if (((Hero *)D_001A4BE0)->f[0x614/4] < rL) {
                func_003C4138((s32)(D_001A4BE0 + 0x614), rL, 0.0032000002f);
            } else {
                func_003C4138((s32)(D_001A4BE0 + 0x614), rL, 0.00080000004f);
            }
            if (((Hero *)D_001A4BE0)->f[0x614/4] > 0.24000001f) {
                ((Hero *)D_001A4BE0)->f[0x614/4] = 0.24000001f;
            }
            if (((Hero *)D_001A4BE0)->f[0x614/4] < -0.050000004f) {
                ((Hero *)D_001A4BE0)->f[0x614/4] = -0.050000004f;
            }
            ((Hero *)D_001A4BE0)->f[0x5E4/4] = ((Hero *)D_001A4BE0)->f[0x620/4] + ((Hero *)D_001A4BE0)->f[0x614/4];
            if (((Hero *)D_001A4BE0)->f[0x5E4/4] < 0.0f) {
                ((Hero *)D_001A4BE0)->f[0x5E4/4] = 0.0f;
            }
            do {
            vec_sub_ab((V4 *)(D_001A4BE0 + 0xF0), (V4 *)v0, (V4 *)(D_001A4BE0 + 0x570));
            vec_sub_ba((V4 *)v20, (V4 *)(D_001A4BE0 + 0x570), (V4 *)(D_001A4BE0 + 0x80));
            sp10C = -func_0038CEA8((s32)v20);
            func_L01_004482A0((s32)&sp10C, (s32)(D_001A4BE0 + 0x64C), 0.0f, 0.0432f, 0.43200004f, 0.14000002f);
            {
            f32 l2 = func_0038CEA8((s32)v20);
            if (l2 < ((Hero *)D_001A4BE0)->f[0x64C/4]) {
                ((Hero *)D_001A4BE0)->f[0x64C/4] = l2;
            }
            if (((Hero *)D_001A4BE0)->f[0x64C/4] < l2) {
                func_0038CF68((s32)v20, (s32)v20, ((Hero *)D_001A4BE0)->f[0x64C/4]);
            }
            }
            vec_add_ab((V4 *)(D_001A4BE0 + 0x80), (V4 *)(D_001A4BE0 + 0x80), (V4 *)v20);
            } while (0);
            {
            f32 a88 = ((Hero *)D_001A4BE0)->f[0x88/4];
            f32 a578 = ((Hero *)D_001A4BE0)->f[0x578/4];
            if (a88 < a578) {
                if (((Hero *)D_001A4BE0)->f[0x33C/4] < 1.0f) {
                    if (a88 < a578) {
                        ((Hero *)D_001A4BE0)->f[0x88/4] = a578;
                    }
                }
            }
            }
        }
        if (((Hero *)D_001A4BE0)->u[0x25C4/4] == 0x2A) {
            if (((Hero *)D_001A4BE0)->i[0x1B8/4] < 0x11) {
                f32 aM;
                aM = func_0038DAB8(((Hero *)D_001A4BE0)->f[0x5EC/4], func_L01_00443A18(0.34906584f, 0.61086524f));
                v40[4] = func_0038D098(aM);
                v40[5] = func_0038D0B0(aM);
                v40[6] = 0.0f;
                func_L01_00446760((s32)v20, (s32)((Hero *)D_001A4BE0)->ptr[0x25C0/4], 0x10000, 1.0f, (s32)&v40[4]);
                *(u128_t *)&v40[8] = ((Hero *)D_001A4BE0)->q[0x80/16];
                v40[10] += 0.6f;
                func_003D4D00((s32)&v40[8], 0x10, 1.0f, (s32)((Hero *)D_001A4BE0)->ptr[0x25C0/4], (s32)v20);
            }
        }
        }
        break;
    case 0x76:
        {
        s32 n76;
        f32 a76;
        f32 r76;
        f32 l76;
        f32 spFC;
        func_L01_004E9090((s32)v0);
        if ((*(u8 *)((u8 *)((Hero *)D_001A4BE0)->ptr[0x25C0/4] + 0x43)) == 0x53) {
            if (D_001D545C != 2) {
                func_L01_004F4F18(0, (s32)((Hero *)D_001A4BE0)->ptr[0x25C0/4], 0);
            } else {
                func_L01_004F4F18(0, (s32)((Hero *)D_001A4BE0)->ptr[0x25C0/4], 0x17);
            }
            if (D_L30_001DF2C0 & 1) {
                *(u128_t *)v10 = *(u128_t *)v0;
                func_0038CE20((s32)v20, (s32)(D_001A4BE0 + 0x110), 0.4f);
                a76 = func_0038DAB8(((Hero *)D_001A4BE0)->f[0x6B0/4], func_L01_00443A18(0.0f, 0.5235988f));
                r76 = func_003824E0(0.0f, 0.080000006f);
                v20[0] += func_0038D098(a76) * r76;
                v20[1] += func_0038D0B0(a76) * r76;
                v20[2] = func_003824E0(0.060000002f, 0.10000001f);
                v20[3] = -0.014f;
                func_L01_00466F50((s32)v10, (s32)v20, 0, -1.0f, 0.0f);
            }
        }
        func_L01_00476B98(((Hero *)D_001A4BE0)->i[0x690/4], (s32)v0, (s32)(D_001A4BE0 + 0x670), (s32)(D_001A4BE0 + 0x694), (s32)(D_001A4BE0 + 0x698), ((Hero *)D_001A4BE0)->i[0x6AC/4], 999.0f, 8.0f, 2.5f);
        if (((Hero *)D_001A4BE0)->i[0x6A0/4] != 0) {
            ((Hero *)D_001A4BE0)->i[0x6A0/4]++;
            *(u128_t *)(D_001A4BE0 + 0xF0) = *(u128_t *)(D_001A4BE0 + 0x120);
            ((Hero *)D_001A4BE0)->f[0xF8/4] = ((Hero *)D_001A4BE0)->f[0xF8/4] - 0.0088f;
            break;
        }
        func_L01_00476498(((Hero *)D_001A4BE0)->i[0x690/4], (s32)v10, (s32)(D_001A4BE0 + 0x694), (s32)(D_001A4BE0 + 0x698), ((Hero *)D_001A4BE0)->f[0x6A4/4], ((Hero *)D_001A4BE0)->i[0x6AC/4]);
        n76 = func_L01_00476440(((Hero *)D_001A4BE0)->i[0x690/4], ((Hero *)D_001A4BE0)->i[0x694/4], 1, ((Hero *)D_001A4BE0)->i[0x6AC/4]);
        vec_sub_ba((V4 *)v20, (V4 *)((u8 *)((Hero *)D_001A4BE0)->i[0x690/4] + n76 * 16 + 0x10), (V4 *)v10);
        if (func_0038CEA8((s32)v20) < 0.001f) {
            if (((Hero *)D_001A4BE0)->i[0x694/4] == n76) {
                ((Hero *)D_001A4BE0)->i[0x6A0/4] = 1;
                break;
            }
        } else {
            ((Hero *)D_001A4BE0)->f[0x6B0/4] = func_0038D160(v20[0], v20[1]);
            ((Hero *)D_001A4BE0)->f[0x6B4/4] = func_0038D160(func_0038CED8((s32)v20), v20[2]);
        }
        *(u128_t *)(D_001A4BE0 + 0x680) = *(u128_t *)v20;
        ((Hero *)D_001A4BE0)->q[0x190/16] = *(u128_t *)v20;
        ((Hero *)D_001A4BE0)->f[0x1A0/4] = ((Hero *)D_001A4BE0)->f[0x6B0/4];
        func_L01_004EEDD0(0, 0.02592f, 0.28800002f, 0.12915437f);
        func_003C4138((s32)(D_001A4BE0 + 0x6A4), 0.28000003f, 0.0036000002f);
        vec_sub_ab((V4 *)(D_001A4BE0 + 0xF0), (V4 *)v10, (V4 *)(D_001A4BE0 + 0x670));
        vec_sub_ba((V4 *)v20, (V4 *)(D_001A4BE0 + 0x670), (V4 *)v0);
        spFC = -func_0038CEA8((s32)v20);
        func_L01_004482A0((s32)&spFC, (s32)(D_001A4BE0 + 0x6B8), 0.0f, 0.072000004f, 0.43200004f, 0.20000002f);
        l76 = func_0038CEA8((s32)v20);
        if (l76 < ((Hero *)D_001A4BE0)->f[0x6B8/4]) {
            ((Hero *)D_001A4BE0)->f[0x6B8/4] = l76;
        }
        if (((Hero *)D_001A4BE0)->f[0x6B8/4] < l76) {
            func_0038CF68((s32)v20, (s32)v20, ((Hero *)D_001A4BE0)->f[0x6B8/4]);
        }
        vec_add_ab((V4 *)(D_001A4BE0 + 0x80), (V4 *)(D_001A4BE0 + 0x80), (V4 *)v20);
        }
        break;
    case 0x17:
    case 0x18:
        {
        vec_sub_ba((V4 *)(D_001A4BE0 + 0x190), (V4 *)(D_001A4BE0 + 0x510), (V4 *)(D_001A4BE0 + 0x500));
        ((Hero *)D_001A4BE0)->f[0x1A0/4] = func_0038D160(((Hero *)D_001A4BE0)->f[0x190/4], ((Hero *)D_001A4BE0)->f[0x194/4]);
        func_L01_004EEDD0(0, 0.057600003f, 0.28800002f, 0.12566371f);
        if (((Hero *)D_001A4BE0)->b[0x25F4] != 2) {
            func_L01_00448690((s32)(D_001A4BE0 + 0x94), 0, 0.0f, 0.09424779f);
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
        func_L01_004EEDD0(0, 0.028800001f, 0.28800002f, 0.09424779f);
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
        func_L01_004EEDD0(0, 0.028800001f, 0.28800002f, 0.09424779f);
        vec_sub_ab((V4 *)(&v40[8]), (V4 *)(D_001A4BE0 + 0x510), (V4 *)(D_001A4BE0 + 0x500));
        qzero((V4 *)(D_001A4BE0 + 0xF0));
        if (((Hero *)D_001A4BE0)->u[0x25C4/4] == 0x19) {
            func_0038CE90((s32)v40, (s32)D_001A4BE0 + 0x2E0, (s32)(&v40[8]));
        } else {
            func_0038CE90((s32)v40, (s32)(&v40[8]), (s32)D_001A4BE0 + 0x2E0);
        }
        func_0038CF68((s32)v40, (s32)v40, 0.2f);
        vec_add_ba((V4 *)(&v40[4]), (V4 *)(D_001A4BE0 + 0x80), (V4 *)v40);
        if (func_L01_004E8318((s32)D_001A4BE0 + 0x80, (s32)D_001A4BE0 + 0x90, 0) == 0) {
            break;
        }
        if (func_L01_004E8318((s32)(&v40[4]), (s32)D_001A4BE0 + 0x90, (s32)v0) != 0) {
            vec_sub_ba((V4 *)(D_001A4BE0 + 0xF0), (V4 *)v0, (V4 *)(D_001A4BE0 + 0x80));
            func_0038CF68((s32)D_001A4BE0 + 0xF0, (s32)D_001A4BE0 + 0xF0, D_L30_001DA440[(s32)((Hero *)D_001A4BE0)->f[0xC18/4]] * 0.5f);
        }
        }
        break;
    case 0x6:
    case 0x2C:
        if (((Hero *)D_001A4BE0)->u[0x25C4/4] == 0x2C) {
            f32 p2C;
            p2C = 0.0f;
            if (((Hero *)D_001A4BE0)->f[0x33C/4] > 4.0f) {
                p2C = 0.43633232f;
            }
            *(u128_t *)v0 = ((Hero *)D_001A4BE0)->q[0x90/16];
            func_L01_00448728((s32)&v0[1], p2C, (s32)(D_001A4BE0 + 0xA4), 0.028800001f, 0.43200004f, 0.05235988f, 0);
            func_L01_00448728((s32)v0, 0.0f, (s32)(D_001A4BE0 + 0xA0), 0.028800001f, 0.43200004f, 0.05235988f, 0);
            func_L01_004E5290(((Hero *)D_001A4BE0)->f[0xA0/4], ((Hero *)D_001A4BE0)->f[0xA4/4], 0.0f);
            if (((Hero *)D_001A4BE0)->f[0x33C/4] > 1.0f) {
                ((Hero *)D_001A4BE0)->i[0x25C8/4] = 1;
            }
        }
        func_L01_004EEBA8();
        if (((Hero *)D_001A4BE0)->h[0x1E0/2] == 0) {
            func_L30_004C0028();
        }
        func_L01_004F2E68();
        func_L01_004F0558(0.7f, 0.0f);
        func_L01_00510F08((s32)D_001A4BE0 + 0xF0, (s32)D_001A4BE0 + 0xF0, ((Hero *)D_001A4BE0)->f[0xA00/4]);
        if (func_L01_005114B0((s32)D_001A4BE0 + 0xF0) < -1.0000001f) {
            func_L01_00511508((s32)D_001A4BE0 + 0xF0, (s32)D_001A4BE0 + 0xF0, -1.0000001f);
        }
        break;
    case 0x79:
        ((Hero *)D_001A4BE0)->c[0x25ED] = 1;
        func_003C4138((s32)D_001A4BE0 + 0xA08, ((Hero *)D_001A4BE0)->f[0xA10/4], 0.0034906587f);
        func_003C4138((s32)D_001A4BE0 + 0xA0C, ((Hero *)D_001A4BE0)->f[0xA14/4], 0.0034906587f);
        func_L01_004E5290(((Hero *)D_001A4BE0)->f[0xA08/4], ((Hero *)D_001A4BE0)->f[0xA0C/4], 0.0f);
        func_L01_0040E728((s32)D_001A4BE0 + 0xF0, (s32)D_001A4BE0 + 0xF0, func_0038CED8((s32)D_001A4BE0 + 0xF0) * 0.88f);
        func_L01_00510F08((s32)D_001A4BE0 + 0xF0, (s32)D_001A4BE0 + 0xF0, ((Hero *)D_001A4BE0)->f[0xA00/4]);
        if (func_L01_005114B0((s32)D_001A4BE0 + 0xF0) < -1.0000001f) {
            func_L01_00511508((s32)D_001A4BE0 + 0xF0, (s32)D_001A4BE0 + 0xF0, -1.0000001f);
        }
        break;
    case 0xB0:
        {
        f32 dB0;
        f32 sB0;
        f32 tB0;
        f32 yB0;
        f32 kB0;
        f32 qB0;
        f32 oB0;
        qB0 = 0.25f;
        func_L30_004BCB20(0.16000001f, 0);
        kB0 = 0.015f;
        oB0 = ((Hero *)D_001A4BE0)->f[0x1A0/4];
        ((Hero *)D_001A4BE0)->f[0x1A0/4] = ((Hero *)D_L30_001E22D8)->f[0];
        func_L01_004EEDD0(0, 0.011520001f, 0.43200004f, 0.08726647f);
        ((Hero *)D_001A4BE0)->f[0x1A0/4] = oB0;
        func_L01_004F1220(0.006f);
        func_L01_004E6390(0.017f, 0.33f);
        func_L01_004E63A8(kB0, qB0);
        func_L01_004E63C0(kB0, qB0);
        func_L01_004E63D8(0.008f, qB0);
        dB0 = ((Hero *)D_001A4BE0)->f[0x1A8/4] * 0.7f;
        if (dB0 > 1.2f) {
            dB0 = 1.2f;
        } else if (dB0 < -1.2f) {
            dB0 = -1.2f;
        }
        ((Hero *)D_L30_002F2EE0)->f[0x60/4] = -dB0 * 0.52f;
        if (((Hero *)D_L30_002F2EE0)->f[0x60/4] > 0.28f) {
            ((Hero *)D_L30_002F2EE0)->f[0x60/4] = 0.28f;
        } else if (((Hero *)D_L30_002F2EE0)->f[0x60/4] < -0.28f) {
            ((Hero *)D_L30_002F2EE0)->f[0x60/4] = -0.28f;
        }
        ((Hero *)D_L30_002F2EE0)->f[0x278/4] = dB0 * 1.2f;
        ((Hero *)D_L30_002F2EE0)->f[0x118/4] = dB0 * 0.58f;
        ((Hero *)D_L30_002F2EE0)->f[0x1C0/4] = dB0 * -0.28f;
        if (((Hero *)D_L30_002F2EE0)->f[0x278/4] > 0.6f) {
            ((Hero *)D_L30_002F2EE0)->f[0x278/4] = 0.6f;
        } else if (((Hero *)D_L30_002F2EE0)->f[0x278/4] < -0.6f) {
            ((Hero *)D_L30_002F2EE0)->f[0x278/4] = -0.6f;
        }
        ((Hero *)D_L30_002F2EE0)->f[0x270/4] = fabs_asm(dB0) * 0.16f;
        ((Hero *)D_L30_002F2EE0)->f[0x64/4] = func_0038DAB8(((Hero *)D_L30_002F2EE0)->f[0x64/4], -0.12217305f);
        if (((Hero *)D_001A4BE0)->f[0x2838/4] > 0.1f) {
            yB0 = func_0038DB00(((Hero *)D_001A4BE0)->f[0x1A0/4], ((Hero *)D_001A4BE0)->f[0x98/4]);
            sB0 = ((Hero *)D_001A4BE0)->f[0x2838/4] * 0.61086524f;
            ((Hero *)D_L30_002F2EE0)->f[0x60/4] = -func_0038D0B0(yB0) * sB0;
            ((Hero *)D_L30_002F2EE0)->f[0x64/4] = func_0038DAB8(((Hero *)D_L30_002F2EE0)->f[0x64/4], func_0038D098(yB0) * sB0);
            if (((Hero *)D_L30_002F2EE0)->f[0x60/4] > 0.47123888f) {
                ((Hero *)D_L30_002F2EE0)->f[0x60/4] = 0.47123888f;
            } else if (((Hero *)D_L30_002F2EE0)->f[0x60/4] < -0.47123888f) {
                ((Hero *)D_L30_002F2EE0)->f[0x60/4] = -0.47123888f;
            }
            if (((Hero *)D_L30_002F2EE0)->f[0x64/4] > 0.47123888f) {
                ((Hero *)D_L30_002F2EE0)->f[0x64/4] = 0.47123888f;
            } else if (((Hero *)D_L30_002F2EE0)->f[0x64/4] < -0.47123888f) {
                ((Hero *)D_L30_002F2EE0)->f[0x64/4] = -0.47123888f;
            }
        }
        func_L01_00510F08((s32)D_001A4BE0 + 0xF0, (s32)D_001A4BE0 + 0xF0, 0.028f);
        if (func_L01_005114B0((s32)D_001A4BE0 + 0xF0) < -0.22000001f) {
            func_L01_00511508((s32)D_001A4BE0 + 0xF0, (s32)D_001A4BE0 + 0xF0, -0.22000001f);
        }
        }
        break;
    case 0x8:
        {
        f32 g8;
        f32 m8;
        f32 h8;
        f32 sp8;
        if (func_L01_004E9238(3) == 2) {
            s32 t279C = ((Hero *)D_001A4BE0)->i[0x279C/4];
            if (t279C != -1) {
                u8 *o = (u8 *)D_001A30B0 + (t279C << 7);
                if ((*(void **)(o + 0xDC) == ((Hero *)D_001A4BE0)->ptr[0x25C0/4]) && (*(u8 *)(o + 0xD0) != 0)) {
                    func_003A4F28(t279C);
                }
            }
            ((Hero *)D_001A4BE0)->i[0x279C/4] = -1;
            func_L01_004F4F18(3, (s32) ((Hero *)D_001A4BE0)->ptr[0x25C0/4], 2);
        } else {
            s32 t2798 = ((Hero *)D_001A4BE0)->i[0x2798/4];
            if (t2798 != -1) {
                u8 *o = (u8 *)D_001A30B0 + (t2798 << 7);
                if ((*(void **)(o + 0xDC) == ((Hero *)D_001A4BE0)->ptr[0x25C0/4]) && (*(u8 *)(o + 0xD0) != 0)) {
                    func_003A4F28(t2798);
                }
            }
            ((Hero *)D_001A4BE0)->i[0x2798/4] = -1;
            func_L01_004F4F18(4, (s32) ((Hero *)D_001A4BE0)->ptr[0x25C0/4], 0xD);
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
        sp8 = func_L01_005114B0((s32)D_001A4BE0 + 0xF0);
        func_L30_004BCB20(g8, 0);
        func_L01_004EEDD0(0, 0.036000002f, 0.43200004f, 0.25132743f);
        func_L01_004EF128(0.006f, 0.0028000001f);
        func_L01_004EF178(99999.0f);
        func_L01_004F2E68();
        func_L01_00511320((s32)D_001A4BE0 + 0xF0, (s32)D_001A4BE0 + 0xF0);
        func_L01_004482A0((s32)&sp8, (s32)D_001A4BE0 + 0xA18, -g8 * m8, 0.036000002f, 0.43200004f, 0.34000003f);
        func_L01_00510F08((s32)D_001A4BE0 + 0xF0, (s32)D_001A4BE0 + 0xF0, -sp8);
        if (((Hero *)D_001A4BE0)->f[0x88/4] < ((Hero *)D_001A4BE0)->f[0x460/4]) {
            func_003C4138((s32)D_001A4BE0 + 0x460, ((Hero *)D_001A4BE0)->f[0x88/4], 0.080000006f);
        }
        func_L01_004E7780();
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
            if (func_L01_004EE7F8(10.0f) != 0) {
                func_L01_004F4E70(4, 0);
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
                func_L30_004BCB20(0.12340001f, 0);
            }
            func_L30_004BCB20(((Hero *)D_001A4BE0)->f[0x474/4], 0);
        }
        if (((Hero *)D_001A4BE0)->u[0x25C4/4] == 0x12) {
            if (((Hero *)D_001A4BE0)->i[0x1B8/4] == 0x11) {
                func_L01_004E5EB8(3, 0x10, 1);
                if (D_L30_001E0790 != 0) {
                    func_L01_004C67A0(D_L30_001E0790, D_L30_001E0798, 0, ((Hero *)D_001A4BE0)->f[0x80/4], ((Hero *)D_001A4BE0)->f[0x84/4], 0.4f, 0.35f);
                }
            }
            v7 = ((Hero *)D_001A4BE0)->f[0xC18/4];
            if ((v7 >= 4.0f) && (v7 <= 7.0f)) {
                func_L01_004E5C08(7, 0, 0);
            }
        }
        end7 = ((Hero *)D_001A4BE0)->h[0x47C/2];
        t7 = ((Hero *)D_001A4BE0)->i[0x1B8/4];
        if (t7 == end7) {
            *(u128_t *)(&((Hero *)D_001A4BE0)->q[0x430/16]) = *(u128_t *)(&((Hero *)D_001A4BE0)->q[0x80/16]);
        }
        if ((((Hero *)D_001A4BE0)->b[0x46C] != 0) || ((t7 < end7) && (st7 = ((Hero *)D_001A4BE0)->u[0x25C4/4], (st7 != 0xB)) && (st7 != 0x10) && (st7 != 0xC) && (st7 != 0x11) && (st7 != 0x1B) && (st7 != 0x48))) {
            if (((Hero *)D_001A4BE0)->h[0x4F8/2] != 0) {
                func_L01_004F47F0();
                if ((((Hero *)D_001A4BE0)->u[0x25C4/4] == 0xA) && (((Hero *)D_001A4BE0)->i[0x1B8/4] < 8) && (((Hero *)D_001A4BE0)->f[0x178/4] < 0.14000001f)) {
                    f32 push7 = 0.014f;
                    ((Hero *)D_001A4BE0)->f[0xF0/4] += func_0038D098(((Hero *)D_001A4BE0)->f[0x98/4]) * push7;
                    ((Hero *)D_001A4BE0)->f[0xF4/4] += func_0038D0B0(((Hero *)D_001A4BE0)->f[0x98/4]) * push7;
                    ((Hero *)D_001A4BE0)->q[0x140/16] = ((Hero *)D_001A4BE0)->q[0xF0/16];
                }
            } else {
            if (((Hero *)D_001A4BE0)->b[0x25E4] != 5) {
                func_L01_004EEDD0(0, 0.0216f, 0.28800002f, 0.30019665f);
            }
            keep7 = ((Hero *)D_001A4BE0)->f[0x1B4/4];
            if (((Hero *)D_001A4BE0)->b[0x46C] >= 2) {
                ((Hero *)D_001A4BE0)->f[0x1B4/4] = keep7 * 0.4f;
            }
            if ((((Hero *)D_001A4BE0)->h[0x1434/2] != 0) || ((((Hero *)D_001A4BE0)->i[0x16B0/4] == 1) && (func_L01_004606E8(0x28, 2, 0, 0) != 0))) {
                func_L01_004EF178(((Hero *)D_001A4BE0)->f[0x1438/4]);
            } else {
                func_L01_004EF178(99999.0f);
            }
            ((Hero *)D_001A4BE0)->f[0x1B4/4] = keep7;
            if (((Hero *)D_001A4BE0)->b[0x46C] != 1) {
                func_L01_004EF128(((Hero *)D_001A4BE0)->f[0x4D0/4], ((Hero *)D_001A4BE0)->f[0x4D4/4]);
            }
            if (((Hero *)D_001A4BE0)->b[0x46C] != 0) {
                if (D_001D52FC->i[0x1D4/4] != 0) {
                    if (((Hero *)D_001A4BE0)->h[0x36A/2] != 0) {
                        ((Hero *)D_001A4BE0)->f[0x1B4/4] = 0.0f;
                    }
                }
                if (((Hero *)D_001A4BE0)->b[0x46C] != 0) {
                    func_L01_004F4730(((Hero *)D_001A4BE0)->f[0x4D4/4]);
                }
            }
            func_L01_004F0558(0.5f, 0.040000003f);
            if (((Hero *)D_001A4BE0)->u[0x25C4/4] == 9) {
                s32 c9 = ((Hero *)D_001A4BE0)->i[0x1B8/4];
                if (c9 < (((Hero *)D_001A4BE0)->h[0x47C/2] + 3)) {
                    func_L01_00511178((s32)(D_001A4BE0 + 0xF0), (s32)(D_001A4BE0 + 0xF0), (f32) c9 * 0.0064000003f);
                }
            }
            if (((Hero *)D_001A4BE0)->u[0x25C4/4] == 0xA) {
                s32 cA = ((Hero *)D_001A4BE0)->i[0x1B8/4];
                if (cA < 0x1C) {
                    func_L01_00511178((s32)(D_001A4BE0 + 0xF0), (s32)(D_001A4BE0 + 0xF0), (f32) cA * 0.021200001f);
                }
            }
            if ((((Hero *)D_001A4BE0)->i[0x1B8/4] < 8) && (((Hero *)D_001A4BE0)->f[0x2838/4] > 0.2f)) {
                *(u128_t *)(v0) = *(u128_t *)(&((Hero *)D_001A4BE0)->q[0x80/16]);
                func_L01_00511280((s32)v0, (s32)v0, 0.5f);
                func_L01_00511178((s32)v10, (s32)v0, 0.95f);
                if (func_003D3CB0((s32)v0, (s32)v10, 4, (s32) ((Hero *)D_001A4BE0)->ptr[0x25C0/4], 0) != 0) {
                    ((Hero *)D_001A4BE0)->h[0x4F4/2] = 1;
                }
            }
            }
        } else {
            func_L30_004C0028();
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
        if ((((Hero *)D_001A4BE0)->h[0x47C/2] < ((Hero *)D_001A4BE0)->i[0x1B8/4]) && (func_L01_005114B0((s32)(D_001A4BE0 + 0xF0)) < 0.001f) && ((((Hero *)D_001A4BE0)->b[0x46D] == 0) || (((Hero *)D_001A4BE0)->i[0x1B8/4] > ((Hero *)D_001A4BE0)->i[0x404/4])) && ((((Hero *)D_001A4BE0)->u[0x25C4/4] != 0xE) || (((Hero *)D_001A4BE0)->i[0x1B8/4] >= 0xF))) {
            f32 a428 = ((Hero *)D_001A4BE0)->f[0x428/4];
            ((Hero *)D_001A4BE0)->b[0x46E] = 1;
            if (a428 != 0.0f) {
                ((Hero *)D_001A4BE0)->f[0x4F0/4] = a428;
            }
        }
        if (((Hero *)D_001A4BE0)->b[0x25E4] == 0) {
            func_L01_004F2E68();
        }
        if (((Hero *)D_001A4BE0)->b[0x25E4] == 1) {
            func_L01_004F3BE0();
        }
        st7 = ((Hero *)D_001A4BE0)->u[0x25C4/4];
        if ((st7 == 0x10) || (st7 == 0xD)) {
            if (D_001439F4[0] != 2) {
                func_L01_0044E468((s32)(D_001A4BE0 + 0x1B90), (((Hero *)D_001A4BE0)->i[0x1B8/4] < 0xB) ? 0 : 2);
            }
        }
        if (((Hero *)D_001A4BE0)->u[0x25C4/4] == 0x86) {
            func_L01_0044E468((s32)(D_001A4BE0 + 0x1B90), (((Hero *)D_001A4BE0)->i[0x1B8/4] < 0xC) ? 0 : 2);
        }
        if ((((Hero *)D_001A4BE0)->u[0x25C4/4] == 0x10) && (((Hero *)D_001A4BE0)->i[0x1B8/4] >= 8) && (((Hero *)D_001A4BE0)->f[0xC18/4] < 28.0f)) {
            func_L01_005110E8((s32)v0, 0.8f, 0.0f, 0.3f, 1);
            n7 = func_003D4D00((s32)v0, 0, 0.9f, (s32) ((Hero *)D_001A4BE0)->ptr[0x25C0/4], 0);
            if (n7 != 0) {
                func_0038CE20((s32)v10, (s32)D_001A4BE0 + 0x110, 7.0f);
                for (i7 = 0; i7 < n7; i7++) {
                    if (func_003C4B50(((s32 *)D_L30_001ED080)[i7]) != 0) {
                        func_L01_00446A70(((s32 *)D_L30_001ED080)[i7], (s32) ((Hero *)D_001A4BE0)->ptr[0x25C0/4], 0x10000, (s32)D_001A4BE0 + 0x80, (s32)v10, 1.0f);
                    }
                }
            }
        }
        if ((((Hero *)D_001A4BE0)->u[0x25C4/4] == 0x38) && (((Hero *)D_001A4BE0)->b[0x46E] == 0) && (((Hero *)D_001A4BE0)->f[0xF8/4] > 0.030000001f)) {
            func_L01_004E60E8();
        }
        func_L01_004F1638();
        func_L01_004E7780();
        }
        break;
    case 0x16:
    case 0xB1:
        {
        f32 sp16;
        f32 dec16;
        sp16 = func_L01_00511408((s32)(D_001A4BE0 + 0xF0));
        dec16 = 0.0016000001f;
        if ((((Hero *)D_001A4BE0)->h[0x36E/2] == 0) && (((Hero *)D_001A4BE0)->i[0x1B8/4] >= 9)) {
            dec16 = 0.004f;
        }
        sp16 = sp16 - dec16;
        if (sp16 < 0.0f) {
            sp16 = 0.0f;
        }
        if (((Hero *)D_001A4BE0)->b[0x1479] != 0) {
            func_L01_004F52E0(3.7f, 0.0f, 0.35f);
        }
        func_L01_00511588((s32)D_001A4BE0 + 0xF0, (s32)D_001A4BE0 + 0xF0, sp16);
        func_L01_00510F08((s32)D_001A4BE0 + 0xF0, (s32)D_001A4BE0 + 0xF0, 0.004f);
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
        if (D_L30_001D673C != 0) {
            len66 = func_0038CEA8((s32)v0);
        } else {
            len66 = func_0038CED8((s32)v0);
        }
        if (len66 > 0.3f) {
            if (D_L30_001D673C != 0) {
                Hero *g66 = (Hero *)D_001A4BE0;
                g66->f[0x2838/4] = 1.0f;
                *(u128_t *)(&g66->q[0x190/16]) = *(u128_t *)(&g66->q[0x1B60/16]);
                g66->f[0x1B0/4] = len66;
                if (len66 < D_L30_001DBC94[2]) {
                    g66->f[0x1B0/4] = D_L30_001DBC94[1] * 0.020000001f;
                } else {
                    g66->f[0x1B0/4] = D_L30_001DBC94[5] * 0.020000001f;
                }
            } else {
                Hero *h66 = (Hero *)D_001A4BE0;
                h66->f[0x2838/4] = 1.0f;
                h66->f[0x1A0/4] = func_0038D160(v0[0], v0[1]);
                h66->f[0x1B0/4] = len66;
                if (len66 < D_L30_001DBC94[2]) {
                    h66->f[0x1B0/4] = D_L30_001DBC94[1] * 0.020000001f;
                } else {
                    h66->f[0x1B0/4] = D_L30_001DBC94[5] * 0.020000001f;
                }
            }
            if (((Hero *)D_001A4BE0)->b[0x25E4] == 1) {
                ((Hero *)D_001A4BE0)->f[0x1B0/4] = 0.018000001f;
            }
        } else {
            if (D_L30_001D673C != 0) {
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
            func_L01_004EEDD0(0, 0.0432f, 0.43200004f, 0.16406097f);
        } else if (((Hero *)D_001A4BE0)->b[0x25E4] == 1) {
            func_L01_004EEDD0(0, 0.0432f, 0.43200004f, 0.15707964f);
        } else if (((Hero *)D_001A4BE0)->b[0x25E4] == 0) {
            func_L01_004EEDD0(0, 0.0432f, 0.43200004f, 0.15707964f);
        }
        if (((Hero *)D_001A4BE0)->b[0x25E4] == 0) {
            func_L01_004F2E68();
        }
        func_L01_004EF128(sc66 * 0.014800001f, 0.012f);
        if (D_L30_001D673C != 0) {
            func_L01_004EF238((s32)(D_001A4BE0 + 0x190));
        } else {
            func_L01_004EF178(99999.0f);
        }
        if (((Hero *)D_001A4BE0)->b[0x25E4] == 0) {
            func_L30_004BD6C0(0);
        }
        if (((Hero *)D_001A4BE0)->h[0x36E/2] != 0) {
            func_L01_00510F08((s32)D_001A4BE0 + 0xF0, (s32)D_001A4BE0 + 0x110, 0.010000001f);
            func_L01_004EF268();
        } else {
            func_L01_00510F08((s32)D_001A4BE0 + 0xF0, (s32)D_001A4BE0 + 0xF0, 0.0216f);
        }
        *(u128_t *)v10 = *(u128_t *)(&((Hero *)D_001A4BE0)->q[0xE0/16]);
        n66 = func_003D4D00((s32)v10, 0, ((Hero *)D_001A4BE0)->f[0x284/4] + 0.2f, (s32) ((Hero *)D_001A4BE0)->ptr[0x25C0/4], 0);
        for (i66 = 0; i66 < n66; i66++) {
            o66 = ((void **)D_L30_001ED080)[i66];
            if ((o66 != 0) && (*(s16 *)((u8 *)o66 + 0xAA) == 0xCB)) {
                func_L01_00446A70((s32)o66, (s32) ((Hero *)D_001A4BE0)->ptr[0x25C0/4], 0x10000, (s32)D_001A4BE0 + 0xE0, (s32)D_L30_001D66B0, 100.0f);
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
        func_L01_004F4730(0.0108f);
        func_L30_004BD6C0(0);
        if (((Hero *)D_001A4BE0)->h[0x36E/2] != 0) {
            func_L01_00510F08((s32)D_001A4BE0 + 0xF0, (s32)D_001A4BE0 + 0x110, 0.010000001f);
            func_L01_004EF268();
        } else {
            func_L01_00510F08((s32)D_001A4BE0 + 0xF0, (s32)D_001A4BE0 + 0xF0, 0.0216f);
        }
        break;
    case 0x68:
        qzero((V4 *)(D_001A4BE0 + 0xF0));
        ((Hero *)D_001A4BE0)->i[0x1B4/4] = 0;
        func_L01_004EF178(99999.0f);
        if (((Hero *)D_001A4BE0)->b[0x25E4] == 0) {
            func_L30_004BD6C0(0);
        }
        if (((Hero *)D_001A4BE0)->h[0x36E/2] != 0) {
            func_L01_00510F08((s32)D_001A4BE0 + 0xF0, (s32)D_001A4BE0 + 0x110, 0.010000001f);
            func_L01_004EF268();
        } else {
            func_L01_00510F08((s32)D_001A4BE0 + 0xF0, (s32)D_001A4BE0 + 0xF0, 0.0216f);
        }
        break;
    case 0x6A:
        qzero((V4 *)D_001A4CD0);
        if (((Hero *)(D_001A4CD0 - 0xF0))->f[0x354/4] - ((Hero *)(D_001A4CD0 - 0xF0))->f[0x88/4] > (f32)((Hero *)(D_001A4CD0 - 0xF0))->i[0x1B70/4] * 0.5f) {
            func_L01_00511320((s32)D_001A4CD0, (s32)D_001A4CD0);
            func_L01_00510F08((s32)D_001A4CD0, (s32)D_001A4CD0, 0.0050000004f);
        } else {
            func_L01_00511320((s32)D_001A4CD0, (s32)D_001A4CD0);
            func_L01_00510F08((s32)D_001A4CD0, (s32)D_001A4CD0, 0.020000001f);
        }
        break;
    case 0x7D:
        qzero((V4 *)D_001A4CD0);
        func_L01_00511320((s32)D_001A4CD0, (s32)D_001A4CD0);
        func_L01_00510F08((s32)D_001A4CD0, (s32)D_001A4CD0, 0.020000001f);
        break;
    case 0x7E:
        func_L01_004F5540();
        qzero((V4 *)D_001A4CD0);
        func_L01_00511320((s32)D_001A4CD0, (s32)D_001A4CD0);
        func_L01_00510F08((s32)D_001A4CD0, (s32)D_001A4CD0, 0.020000001f);
        break;
    case 0x7F:
        qzero((V4 *)D_001A4CD0);
        ((f32 *)D_001A4CD0)[2] = -0.007f;
        break;
    case 0x3F:
    case 0x43:
        func_L01_004F52E0(3.7f, 0.0f, 0.35f);
        func_L30_004BCB20(1.0f, 0);
        ((Hero *)D_001A4BE0)->f[0x1B0/4] = 0.0f;
        func_L01_004EF128(0.0f, 0.00504f);
        qzero((V4 *)(D_001A4BE0 + 0xF0));
        func_L30_004BD6C0(0);
        if (((Hero *)D_001A4BE0)->h[0x36E/2] != 0) {
            func_L01_00510F08((s32)D_001A4BE0 + 0xF0, (s32)D_001A4BE0 + 0x130, 0.010000001f);
            func_L01_004EF268();
        } else {
            func_L01_00510F08((s32)D_001A4BE0 + 0xF0, (s32)D_001A4BE0 + 0xF0, 0.0216f);
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
        rec = &D_L30_002F4C70[((Hero *)D_001A4BE0)->h[0xBDC/2]];
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
            func_L01_00446780((s32)((Hero *)D_001A4BE0)->ptr[0x25C0/4], 0.25f, (s32)v0, 0x10000, 1.0f, 1.0f, 0, 1, 0);
        }
        func_003C4138((s32)D_001A4BE0 + 0xC00, 1.0f, 0.2f);
        if ((((Hero *)D_001A4BE0)->i[0xBC8/4] != 0) || (((Hero *)D_001A4BE0)->i[0xBC4/4] != 0)) {
            ((Hero *)D_001A4BE0)->f[0x1A0/4] = ((Hero *)D_001A4BE0)->f[0xBCC/4];
            func_L01_004EEDD0(0, 0.072000004f, 0.28800002f, 0.3385939f);
        } else {
            func_L01_004F2880(3.0f, 0.7853982f, 0.7853982f);
        }
        func_L01_004EF128(0.014800001f, 0.0112000005f);
        if (((Hero *)D_001A4BE0)->i[0xBC8/4] != 0) {
            if (((Hero *)D_001A4BE0)->b[0x25F4] == 2) {
                func_L01_004EF238((s32)D_001A4BE0 + 0xBA0);
            } else {
                func_L01_004EF178(((Hero *)D_001A4BE0)->f[0xBCC/4]);
            }
        } else {
            func_L01_004EF178(99999.0f);
        }
        if (((Hero *)D_001A4BE0)->h[0x36E/2] != 0) {
            ((Hero *)D_001A4BE0)->f[0xF8/4] = ((Hero *)D_001A4BE0)->f[0x118/4] - 0.010000001f;
            func_L01_004EF268();
        } else {
            ((Hero *)D_001A4BE0)->f[0xF8/4] = ((Hero *)D_001A4BE0)->f[0xF8/4] - 0.0216f;
        }
        func_L01_004F52E0(0.7f, 0.0f, 0.3f);
        }
        break;
    case 0x4B:
        func_L30_004BCB20(0.040000003f, 0);
        func_L01_004EEDD0(0, 0.057600003f, 0.28800002f, 0.19896755f);
        func_L01_004EF128(0.006f, 0.0028000001f);
        func_L01_004EF178(99999.0f);
        func_L01_00511320((s32)(D_001A4BE0 + 0xF0), (s32)(D_001A4BE0 + 0xF0));
        func_L01_00510F08((s32)(D_001A4BE0 + 0xF0), (s32)(D_001A4BE0 + 0xF0), 0.028800003f);
        break;
    case 0x4E:
        ((Hero *)D_001A4BE0)->f[0x1A0/4] = ((Hero *)D_001A4BE0)->f[0x34C/4];
        ((Hero *)D_001A4BE0)->f[0x1B0/4] = 0.11000001f;
        func_L01_004F1220(0.010000001f);
        func_L01_00510F08((s32)D_001A4BE0 + 0xF0, (s32)D_001A4BE0 + 0x130, 0.0072000003f);
        break;
    case 0x4F:
        qzero((V4 *)(D_001A4BE0 + 0xF0));
        func_L01_00510F08((s32)(D_001A4BE0 + 0xF0), (s32)(D_001A4BE0 + 0xF0), 0.0048f);
        break;
    case 0x41:
        func_L30_004BCB20(0.06600001f, 0);
        if (((Hero *)D_001A4BE0)->h[0x1E0/2] == 0) {
            func_L30_004C0028();
        }
        func_L01_00510F08((s32)D_001A4BE0 + 0xF0, (s32)D_001A4BE0 + 0xF0, 0.0048f);
        if (((Hero *)D_001A4BE0)->f[0xF8/4] < -0.20000002f) {
            ((Hero *)D_001A4BE0)->f[0xF8/4] = -0.20000002f;
        }
        break;
    case 0x44:
        if (((Hero *)D_001A4BE0)->f[0xF8/4] > 0.0f) {
            func_L01_004E5290(0.0f, 0.25132743f, 0.0f);
        }
        func_L01_00510F08((s32)D_001A4BE0 + 0xF0, (s32)D_001A4BE0 + 0xF0, 0.008f);
        break;
    case 0x40:
    case 0x4C:
        {
        f32 a40;
        f32 c40;
        f32 m40;
        f32 b40;
        func_L30_004BCB20(0.06600001f, 0);
        c40 = 0.19896755f;
        a40 = 0.04752f;
        if (((Hero *)D_001A4BE0)->b[0x3EF] != 0) {
            c40 = 0.23387413f;
            a40 = 0.053280003f;
        }
        func_L01_004EEDD0(0, a40, 0.21600002f, c40);
        func_L01_004EF128(0.014800001f, 0.012f);
        if (((Hero *)D_001A4BE0)->f[0x174/4] < 0.014f) {
            ((Hero *)D_001A4BE0)->b[0x3EC] = 1;
            if ((fabs_asm(((Hero *)D_001A4BE0)->f[0x1A8/4]) > 1.7453293f) && (((Hero *)D_001A4BE0)->f[0x2838/4] > 0.8f)) {
                ((Hero *)D_001A4BE0)->b[0x3EF] = 1;
            }
        }
        m40 = func_L01_00460818(0, 0);
        if (func_0038DBA0(m40, func_L01_00460818(2, 0)) > 2.6179938f) {
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
            func_L01_004EF178(((Hero *)D_001A4BE0)->f[0x1A0/4]);
        } else {
            func_L01_004EF178(99999.0f);
        }
        func_L30_004BD6C0(0);
        if (((Hero *)D_001A4BE0)->h[0x36E/2] != 0) {
            func_L01_00510F08((s32)D_001A4BE0 + 0xF0, (s32)D_001A4BE0 + 0x130, 0.010000001f);
            func_L01_004EF268();
        } else {
            func_L01_00510F08((s32)D_001A4BE0 + 0xF0, (s32)D_001A4BE0 + 0xF0, 0.0216f);
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
        func_L01_0040E728((s32)(D_001A4BE0 + 0xF0), (s32)(D_001A4BE0 + 0xF0), var_f12_r4);
        ((Hero *)D_001A4BE0)->i[0xF8/4] = 0;
        if (((Hero *)D_001A4BE0)->h[0x36E/2] != 0) {
            func_L01_00510F08((s32)(D_001A4BE0 + 0xF0), (s32)(D_001A4BE0 + 0xF0) + 0x30, 0.0088f);
        } else {
            func_L01_00510F08((s32)(D_001A4BE0 + 0xF0), (s32)(D_001A4BE0 + 0xF0), 0.004f);
        }
        }
        break;
    case 0x49:
    case 0x4A:
        {
        ((Hero *)D_001A4BE0)->f[0xC00/4] = 1.3f;
        vec_sub_ba((V4 *)(D_001A4BE0 + 0x190), (V4 *)(D_001A4BE0 + 0x510), (V4 *)(D_001A4BE0 + 0x500));
        ((Hero *)D_001A4BE0)->f[0x1A0/4] = func_0038D160(((Hero *)D_001A4BE0)->f[0x190/4], ((Hero *)D_001A4BE0)->f[0x194/4]);
        func_L01_004EEDD0(0, 0.028800001f, 0.28800002f, 0.09424779f);
        vec_sub_ab((V4 *)(&v40[8]), (V4 *)(D_001A4BE0 + 0x510), (V4 *)(D_001A4BE0 + 0x500));
        qzero((V4 *)(D_001A4BE0 + 0xF0));
        if (((Hero *)D_001A4BE0)->u[0x25C4/4] == 0x49) {
            func_0038CE90((s32)v40, (s32)D_001A4BE0 + 0x2E0, (s32)(&v40[8]));
        } else {
            func_0038CE90((s32)v40, (s32)(&v40[8]), (s32)D_001A4BE0 + 0x2E0);
        }
        func_0038CF68((s32)v40, (s32)v40, 0.2f);
        vec_add_ba((V4 *)(&v40[4]), (V4 *)(D_001A4BE0 + 0x80), (V4 *)v40);
        if (func_L01_004E8318((s32)D_001A4BE0 + 0x80, (s32)D_001A4BE0 + 0x90, 0) == 0) {
            break;
        }
        if (func_L01_004E8318((s32)(&v40[4]), (s32)D_001A4BE0 + 0x90, (s32)v0) != 0) {
            vec_sub_ba((V4 *)(D_001A4BE0 + 0xF0), (V4 *)v0, (V4 *)(D_001A4BE0 + 0x80));
            func_0038CF68((s32)D_001A4BE0 + 0xF0, (s32)D_001A4BE0 + 0xF0, D_L30_002EE300[(s32)((Hero *)D_001A4BE0)->f[0xC18/4]] * 0.5f);
        }
        }
        break;
    case 0x9D:
        qzero((V4 *)(D_001A4BE0 + 0xF0));
        func_L30_004BD6C0(0);
        if (((Hero *)D_001A4BE0)->h[0x36E/2] != 0) {
            func_L01_00510F08((s32)D_001A4BE0 + 0xF0, (s32)D_001A4BE0 + 0x130, 0.010000001f);
            func_L01_004EF268();
        } else {
            func_L01_00510F08((s32)D_001A4BE0 + 0xF0, (s32)D_001A4BE0 + 0xF0, 0.0216f);
        }
        func_L30_004E5598();
        func_L30_004E5158();
        func_L01_004F52E0(2.0f, 0.0f, 1.4f);
        break;
    case 0x9A:
    case 0x9F:
    case 0xA0:
    case 0xA3:
    case 0xAE:
        if (func_0038DBA0(((Hero *)D_001A4BE0)->f[0x98/4], 0.0f) < 1.5707964f) {
            ((Hero *)D_001A4BE0)->f[0x1A0/4] = 0.0f;
        } else {
            ((Hero *)D_001A4BE0)->f[0x1A0/4] = 3.1415927f;
        }
        func_L01_004EEDD0(0, 0.08208001f, 0.38880002f, 0.47822025f);
        func_L01_004F52E0(3.7f, 0.0f, 0.35f);
        func_L30_004BCB20(1.0f, 0);
        ((Hero *)D_001A4BE0)->f[0x1B0/4] = 0.0f;
        func_L01_004EF128(0.0f, 0.00504f);
        qzero((V4 *)(D_001A4BE0 + 0xF0));
        func_L30_004BD6C0(0);
        if (((Hero *)D_001A4BE0)->h[0x36E/2] != 0) {
            func_L01_00510F08((s32)D_001A4BE0 + 0xF0, (s32)D_001A4BE0 + 0x130, 0.010000001f);
            func_L01_004EF268();
        } else {
            func_L01_00510F08((s32)D_001A4BE0 + 0xF0, (s32)D_001A4BE0 + 0xF0, 0.0216f);
        }
        break;
    case 0xAB:
        {
        f32 vAB;
        f32 sAB;
        s32 rAB;
        func_003C4138((s32)(D_001A4BE0 + 0x80), *(f32 *)((u8 *)((Hero *)D_001A4BE0)->ptr[0x1B30/4] + 0x10), 0.22000001f);
        sAB = ((Hero *)D_001A4BE0)->f[0x2264/4];
        qzero((V4 *)(D_001A4BE0 + 0xF0));
        vAB = D_L30_001DBC4C * 0.020000001f;
        rAB = 0;
        if (fabs_asm(sAB) > 0.3f) {
            if (sAB > 0.0f) {
                s32 *pAB;
                s32 iAB;
                ((Hero *)D_001A4BE0)->f[0xF8/4] = vAB;
                pAB = (s32 *)((Hero *)D_001A4BE0)->ptr[0x1B30/4];
                rAB = 1;
                iAB = (pAB[0] - 1) * 16;
                if (*(f32 *)((u8 *)pAB + iAB + 0x18) - 0.1f < ((Hero *)D_001A4BE0)->f[0x88/4]) {
                    ((Hero *)D_001A4BE0)->f[0xF8/4] = 0.0f;
                }
            } else {
                rAB = -1;
                ((Hero *)D_001A4BE0)->f[0xF8/4] = -vAB * 2.0f;
            }
        }
        if (rAB == 0) {
            u8 cAB = *(u8 *)((u8 *)((Hero *)D_001A4BE0)->ptr[0x25C0/4] + 0x43);
            if ((cAB != 0x36) && (cAB != 0x3D)) {
                func_L01_0050FB40(0x36, 0, 7.0f);
            }
            if (((Hero *)D_001A4BE0)->i[0xC08/4] & 2) {
                if (*(u8 *)((u8 *)((Hero *)D_001A4BE0)->ptr[0x25C0/4] + 0x43) == 0x36) {
                    if (func_00382498(0, 100) > 0x46) {
                        func_L01_0050FB40(0x3D, 0, 9.0f);
                    }
                } else {
                    if (func_00382498(0, 100) > 0x46) {
                        func_L01_0050FB40(0x36, 0, 9.0f);
                    }
                }
            }
        } else if (rAB == 1) {
            if (*(u8 *)((u8 *)((Hero *)D_001A4BE0)->ptr[0x25C0/4] + 0x43) != 0x37) {
                func_L01_0050FB40(0x37, 7, 4.0f);
            }
        } else if (rAB == -1) {
            if (*(u8 *)((u8 *)((Hero *)D_001A4BE0)->ptr[0x25C0/4] + 0x43) != 0x37) {
                func_L01_0050FB40(0x39, 7, 4.0f);
            }
        }
        }
        break;
    case 0xAD:
        {
        s32 nAD;
        f32 lAD;
        f32 spAD;
        func_L30_004E5F28((s32)v0);
        func_L01_00476B98(((Hero *)D_001A4BE0)->i[0x690/4], (s32)v0, (s32)(D_001A4BE0 + 0x670), (s32)(D_001A4BE0 + 0x694), (s32)(D_001A4BE0 + 0x698), ((Hero *)D_001A4BE0)->i[0x6AC/4], 999.0f, 8.0f, 2.5f);
        if (((Hero *)D_001A4BE0)->i[0x6A0/4] != 0) {
            ((Hero *)D_001A4BE0)->i[0x6A0/4]++;
            *(u128_t *)(D_001A4BE0 + 0xF0) = *(u128_t *)(D_001A4BE0 + 0x120);
            ((Hero *)D_001A4BE0)->f[0xF8/4] = ((Hero *)D_001A4BE0)->f[0xF8/4] - 0.0088f;
            break;
        }
        func_L01_00476498(((Hero *)D_001A4BE0)->i[0x690/4], (s32)v10, (s32)(D_001A4BE0 + 0x694), (s32)(D_001A4BE0 + 0x698), ((Hero *)D_001A4BE0)->f[0x6A4/4], ((Hero *)D_001A4BE0)->i[0x6AC/4]);
        nAD = func_L01_00476440(((Hero *)D_001A4BE0)->i[0x690/4], ((Hero *)D_001A4BE0)->i[0x694/4], 1, ((Hero *)D_001A4BE0)->i[0x6AC/4]);
        vec_sub_ba((V4 *)v20, (V4 *)((u8 *)((Hero *)D_001A4BE0)->i[0x690/4] + nAD * 16 + 0x10), (V4 *)v10);
        if (func_0038CEA8((s32)v20) < 0.001f) {
            if (((Hero *)D_001A4BE0)->i[0x694/4] == nAD) {
                ((Hero *)D_001A4BE0)->i[0x6A0/4] = 1;
                break;
            }
        } else {
            ((Hero *)D_001A4BE0)->f[0x6B0/4] = func_0038D160(v20[0], v20[1]);
            ((Hero *)D_001A4BE0)->f[0x6B4/4] = func_0038D160(func_0038CED8((s32)v20), v20[2]);
        }
        ((Hero *)D_001A4BE0)->f[0x1A0/4] = ((Hero *)D_001A4BE0)->f[0x6B0/4];
        func_L01_004EEDD0(0, 0.053280003f, 0.28800002f, 0.19896755f);
        func_003C4138((s32)(D_001A4BE0 + 0x6A4), 0.36f, 0.0036000002f);
        vec_sub_ab((V4 *)(D_001A4BE0 + 0xF0), (V4 *)v10, (V4 *)(D_001A4BE0 + 0x670));
        vec_sub_ba((V4 *)v20, (V4 *)(D_001A4BE0 + 0x670), (V4 *)v0);
        spAD = -func_0038CEA8((s32)v20);
        func_L01_004482A0((s32)&spAD, (s32)(D_001A4BE0 + 0x6B8), 0.0f, 0.08208001f, 0.28800002f, 0.40000004f);
        lAD = func_0038CEA8((s32)v20);
        if (lAD < ((Hero *)D_001A4BE0)->f[0x6B8/4]) {
            ((Hero *)D_001A4BE0)->f[0x6B8/4] = lAD;
        }
        if (((Hero *)D_001A4BE0)->f[0x6B8/4] < lAD) {
            func_0038CF68((s32)v20, (s32)v20, ((Hero *)D_001A4BE0)->f[0x6B8/4]);
        }
        vec_add_ab((V4 *)(D_001A4BE0 + 0x80), (V4 *)(D_001A4BE0 + 0x80), (V4 *)v20);
        }
        break;
    case 0xA8:
    case 0xA9:
        ((Hero *)D_001A4BE0)->h[0x1B2A/2] = 2;
        vec_sub_ba((V4 *)(D_001A4BE0 + 0x190), (V4 *)(D_001A4BE0 + 0x510), (V4 *)(D_001A4BE0 + 0x500));
        ((Hero *)D_001A4BE0)->f[0x1A0/4] = func_0038D160(((Hero *)D_001A4BE0)->f[0x190/4], ((Hero *)D_001A4BE0)->f[0x194/4]);
        func_L01_004EEDD0(0, 0.057600003f, 0.28800002f, 0.12566371f);
        if (((Hero *)D_001A4BE0)->b[0x25F4] != 2) {
            func_L01_00448690((s32)(D_001A4BE0 + 0x94), 0, 0.0f, 0.09424779f);
        }
        vec_sub_ab((V4 *)(D_001A4BE0 + 0xF0), (V4 *)(D_001A4BE0 + 0x500), (V4 *)(D_001A4BE0 + 0x80));
        func_003C4BB0((s32)(D_001A4BE0 + 0xF0), 0.080000006f);
        func_003C4138((s32)(D_001A4BE0 + 0x530), ((Hero *)D_001A4BE0)->f[0x88/4], 0.060000002f);
        break;
    case 0x9C:
    case 0xA1:
        {
        f32 sp9C;
        f32 lim9C;
        func_L30_004BCB20(0.18f, 0);
        if (((Hero *)D_001A4BE0)->h[0x1E0/2] == 0) {
            func_L30_004BCB20(0.18f, 0);
            func_L01_004F1220(0.028f);
        }
        if (((Hero *)D_001A4BE0)->h[0x1B3E/2] != 0) {
            func_L01_00510F08((s32)D_001A4BE0 + 0xF0, (s32)D_001A4BE0 + 0xF0, 0.0044f);
        } else {
            func_L01_00510F08((s32)D_001A4BE0 + 0xF0, (s32)D_001A4BE0 + 0xF0, 0.0228f);
        }
        if ((((Hero *)D_001A4BE0)->f[0x33C/4] > 0.4f) || (((Hero *)D_001A4BE0)->f[0xF8/4] > 0.0f)) {
            if ((*(u8 *)((u8 *)((Hero *)D_001A4BE0)->ptr[0x25C0/4] + 0x43) != 0x3A) || ((((Hero *)D_001A4BE0)->i[0xC0C/4] == 0) && (((Hero *)D_001A4BE0)->f[0xC18/4] > 27.0f))) {
                if (func_L01_004606E8(0x80, 7, 0, 0) != 0) {
                    func_L30_004E6E50();
                }
            }
        }
        if (*(u8 *)((u8 *)((Hero *)D_001A4BE0)->ptr[0x25C0/4] + 0x43) != 0x3A) {
            if ((func_L01_004E63F0(&sp9C, 2.5f, 2.0f) != 0) && (func_L01_004E63F0(&sp9C, 0.5f, 2.0f) != 0) && (sp9C < 0.1f) && (((Hero *)D_001A4BE0)->b[0x2A7] != 0) && (((Hero *)D_001A4BE0)->f[0x2838/4] > 0.8f)) {
                ((Hero *)D_001A4BE0)->h[0x1B3E/2] = 1;
            } else {
                ((Hero *)D_001A4BE0)->h[0x1B3E/2] = 0;
            }
            if (((Hero *)D_001A4BE0)->h[0x1B3E/2] != 0) {
                if (*(u8 *)((u8 *)((Hero *)D_001A4BE0)->ptr[0x25C0/4] + 0x43) != 0x2A) {
                    func_L01_0050FB40(0x2A, 0, 6.0f);
                }
            } else {
                if (*(u8 *)((u8 *)((Hero *)D_001A4BE0)->ptr[0x25C0/4] + 0x43) != 0x2D) {
                    func_L01_0050FB40(0x2D, 0, 7.0f);
                }
            }
        }
        lim9C = -0.6f;
        if (((Hero *)D_001A4BE0)->h[0x1B3E/2] != 0) {
            lim9C = -0.20000002f;
        }
        if (((Hero *)D_001A4BE0)->f[0xF8/4] < lim9C) {
            ((Hero *)D_001A4BE0)->f[0xF8/4] = lim9C;
        }
        }
        break;
    case 0x9B:
        func_L30_004BCB20(0.18f, 0);
        func_L01_004EEDD0(0, 0.08208001f, 0.38880002f, 0.47822025f);
        func_L01_004EF128(0.040000003f, 0.040000003f);
        func_L01_004EF178(((Hero *)D_001A4BE0)->f[0x1A0/4]);
        if (((Hero *)D_001A4BE0)->h[0x36E/2] != 0) {
            func_L01_00510F08((s32)D_001A4BE0 + 0xF0, (s32)D_001A4BE0 + 0x130, 0.010000001f);
            func_L01_004EF268();
        } else {
            func_L01_00510F08((s32)D_001A4BE0 + 0xF0, (s32)D_001A4BE0 + 0xF0, 0.0216f);
        }
        break;
    case 0xA6:
        {
        f32 rA6;
        ((Hero *)D_001A4BE0)->f[0x1B0/4] = 0.54f;
        ((Hero *)D_001A4BE0)->h[0x1B20/2] = 0;
        func_L01_005110E8((s32)v10, 2.7f, 0.0f, 0.5f, 1);
        func_L01_005110E8((s32)v0, 2.7f, 0.0f, 2.2f, 1);
        if (func_003D3CB0((s32)v10, (s32)v0, 2, 0, 0) != 0) {
            ((Hero *)D_001A4BE0)->h[0x1B20/2] = 1;
        }
        rA6 = 0.028f;
        if (((Hero *)D_001A4BE0)->i[0x1B8/4] >= 5) {
            func_L01_005110E8((s32)v0, 2.7f, 0.0f, 0.5f, 1);
            func_L01_005110E8((s32)v10, 2.7f, 0.0f, -1.0f, 1);
            if (func_003D3CB0((s32)v0, (s32)v10, 2, 0, 0) == 0) {
                ((Hero *)D_001A4BE0)->f[0x1B0/4] = 0.0f;
                rA6 = 0.068f;
            }
        }
        if (func_L01_004F52E0(1.5f, 0.0f, 1.0f) != 0) {
            ((Hero *)D_001A4BE0)->h[0x1B22/2] = 1;
        }
        if ((((Hero *)D_001A4BE0)->i[0x1B8/4] >= 7) && (((Hero *)D_001A4BE0)->b[0x2A7] != 0) && (((Hero *)D_001A4BE0)->f[0x170/4] < 0.010000001f)) {
            ((Hero *)D_001A4BE0)->h[0x1B22/2] = 1;
        }
        if ((((Hero *)D_001A4BE0)->h[0x1B20/2] == 0) && (((Hero *)D_001A4BE0)->i[0x1B8/4] >= 7)) {
            ((Hero *)D_001A4BE0)->f[0x1B0/4] = 0.0f;
        }
        func_L01_004EF128(0.22800002f, rA6);
        func_L01_004EF178(((Hero *)D_001A4BE0)->f[0x98/4]);
        if (((Hero *)D_001A4BE0)->h[0x36E/2] != 0) {
            func_L01_00510F08((s32)D_001A4BE0 + 0xF0, (s32)D_001A4BE0 + 0x130, 0.010000001f);
            func_L01_004EF268();
        } else {
            func_L01_00510F08((s32)D_001A4BE0 + 0xF0, (s32)D_001A4BE0 + 0xF0, 0.0216f);
        }
        }
        break;
    case 0x9E:
        {
        f32 s9E;
        f32 d9E;
        s9E = func_L01_00511408((s32)(D_001A4BE0 + 0xF0));
        d9E = 0.002f;
        if ((((Hero *)D_001A4BE0)->h[0x36E/2] == 0) && (((Hero *)D_001A4BE0)->i[0x1B8/4] >= 9)) {
            d9E = 0.004f;
        }
        s9E -= d9E;
        if (s9E < 0.0f) {
            s9E = 0.0f;
        }
        func_L01_00511588((s32)(D_001A4BE0 + 0xF0), (s32)(D_001A4BE0 + 0xF0), s9E);
        if (((Hero *)D_001A4BE0)->h[0x36E/2] != 0) {
            func_L01_00510F08((s32)D_001A4BE0 + 0xF0, (s32)D_001A4BE0 + 0x130, 0.016f);
            func_L01_004EF268();
        } else {
            ((Hero *)D_001A4BE0)->f[0xF8/4] = -0.012f;
        }
        }
        break;
    case 0x51:
    case 0x56:
    case 0x59:
        func_L01_004F52E0(3.7f, 0.0f, 0.35f);
        func_L30_004BCB20(1.0f, 0);
        ((Hero *)D_001A4BE0)->f[0x1B0/4] = 0.0f;
        func_L01_004EF128(0.0f, 0.007080001f);
        qzero((V4 *)(D_001A4BE0 + 0xF0));
        func_L01_004F4730(0.007080001f);
        func_L30_004BD6C0(0);
        if (((Hero *)D_001A4BE0)->h[0x36E/2] != 0) {
            func_L01_00510F08((s32)D_001A4BE0 + 0xF0, (s32)D_001A4BE0 + 0x130, 0.010000001f);
            func_L01_004EF268();
        } else {
            func_L01_00510F08((s32)D_001A4BE0 + 0xF0, (s32)D_001A4BE0 + 0xF0, 0.0216f);
        }
        break;
    case 0x57:
    case 0x7B:
        ((Hero *)D_001A4BE0)->f[0x1A0/4] = ((Hero *)D_001A4BE0)->f[0x34C/4];
        ((Hero *)D_001A4BE0)->f[0x1B0/4] = 0.11000001f;
        func_L01_004F1220(0.010000001f);
        func_L01_00510F08((s32)(D_001A4BE0 + 0xF0), (s32)D_001A4BE0 + 0x130, 0.0072000003f);
        break;
    case 0x58:
        qzero((V4 *)(D_001A4BE0 + 0xF0));
        break;
    case 0x53:
        func_L30_004BCB20(0.10000001f, 0);
        if (((Hero *)D_001A4BE0)->h[0x1E0/2] == 0) {
            func_L30_004C0028();
        }
        if (((Hero *)D_001A4BE0)->h[0x202/2] >= 0x12) {
            func_L01_00446780((s32)((Hero *)D_001A4BE0)->ptr[0x25C0/4], 1.0f, (s32)D_001A4BE0 + 0x80, 0xA, 1.0f, 1.0f, 0, 1, 0);
        }
        func_L01_00510F08((s32)D_001A4BE0 + 0xF0, (s32)D_001A4BE0 + 0xF0, 0.008400001f);
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
        func_L30_004BCB20(0.10000001f, 0);
        if (((Hero *)D_001A4BE0)->f[0x1B0/4] < 0.055000007f) {
            ((Hero *)D_001A4BE0)->f[0x1B0/4] = 0.055000007f;
        }
        var_f20_r3 = 1.0f;
        var_f20_r3 -= var_f21_r3 * 0.3f;
        var_f2_r3 = ((Hero *)D_001A4BE0)->f[0x2838/4] + 0.35f;
        if (var_f20_r3 < 0.0f) {
            var_f20_r3 = 0.0f;
        }
        func_L01_004EEDD0(0, var_f2_r3 * 0.050400004f, 0.14400001f, var_f2_r3 * 0.16406097f);
        func_L01_004EF128(var_f20_r3 * 0.014800001f, 0.012f);
        if ((((Hero *)D_001A4BE0)->b[0x3EC] != 0) && (((Hero *)D_001A4BE0)->h[0x368/2] == 0)) {
            func_L01_004EF178(((Hero *)D_001A4BE0)->f[0x1A0/4]);
        } else {
            func_L01_004EF178(99999.0f);
        }
        func_L30_004BD6C0(0);
        if (((Hero *)D_001A4BE0)->h[0x36E/2] != 0) {
            func_L01_00510F08((s32)D_001A4BE0 + 0xF0, (s32)D_001A4BE0 + 0x130, 0.010000001f);
            func_L01_004EF268();
        } else {
            func_L01_00510F08((s32)D_001A4BE0 + 0xF0, (s32)D_001A4BE0 + 0xF0, 0.0216f);
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
        func_L01_0040E728((s32)(D_001A4BE0 + 0xF0), (s32)(D_001A4BE0 + 0xF0), var_f12_r3);
        ((Hero *)D_001A4BE0)->i[0xF8/4] = 0;
        if (((Hero *)D_001A4BE0)->h[0x36E/2] != 0) {
            func_L01_00510F08((s32)(D_001A4BE0 + 0xF0), (s32)(D_001A4BE0 + 0xF0) + 0x30, 0.0088f);
        } else {
            func_L01_00510F08((s32)(D_001A4BE0 + 0xF0), (s32)(D_001A4BE0 + 0xF0), 0.004f);
        }
        }
        break;
    case 0x37:
        if (*(u8 *)((u8 *)((Hero *)D_001A4BE0)->ptr[0x25C0/4] + 0x43) == 0x3F) {
            func_L01_004EEDD0(0, 0.19728f, 0.36f, 0.2443461f);
        } else {
            func_L01_004EEDD0(0, 1.44f, 0.14400001f, 0.4886922f);
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


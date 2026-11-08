/* func_L19_004F9D80: the 0x110 dispatcher (family B2 root, docs/prep/FAMILIES.md), Opus pass 2026-11-08.
   Written from the retail asm case by case (rac2 twin func_L20_002DEBE0 for structure).
   File flags needed: -mvu0-use-vf0-vf2 -O2 -G8 -fopt-stack -mno-check-zero-division @ps2as
   (the file holds only this function; @ps2as gives the inline lui/ori float constants and the
   mixed gp/lui global accesses, -mvu0-use-vf0-vf2 the j-form VU0 statements of case 0x27).
   Level div.s padding: one div.s (case 0x7 group, rate = 7.0f / C00) has 2 nops in retail;
   it needs `func_L19_004F9D80 2` in the level divs_nops table (config/levels/divs_nops.txt).

   Measured (tools/check.py --as ps2as --flags=-mvu0-use-vf0-vf2, level 19, with the divs_nops row):
   7248 of 7251 words, opcode-aligned 7239 equal (99.83%), after switching to include/vu0.h (qzero,
   fabs_asm, vec_add_*), which closed items 1 and the abs.s part of 3 below, and restructuring case 0x16
   (item 4, closed). Original measurement: 7250 of 7251 words, opcode-aligned 7222 equal (99.6%) with registers, frame (0x140), stack layout and all 178
   cases right. What still differs:
   1. Case 0x27/0x28 (`hit` block): retail zeroes v10 with `sq $zero, 0x10($sp)`; C only gives
      `por $tN,$zero,$zero; sq $tN` (every TI zero spelling tried: cast store, union, memset,
      struct literal, shared local). With `__asm__("sq $0, %0" : "=m"(*(V4 *)v10))` the whole
      region and the following two zero stores' registers match (99.79%), but that asm is not
      allowed (ordinary EE instruction). Toolchain gap: SN cc1's movti only prints `sq %1,%0`.
   2. Case 0x28 loop success block: retail builds the `pos` argument of func_L01_00476B98 with a
      fresh `lui $a1,0x1A; addiu $a1,$a1,0x4C60`; this C gets `addiu $a1,$s0,0x80` (cse related
      value). A `pos` local at the loop top gives the lui/addiu but shifts the global allocation
      ($s3 -> $s4). One word short, so the loop label lands without retail's alignment nop.
   3. Case 0x7 group: `D_L19_001DBD58` is loaded in a bc1f delay slot ($gp form) where retail puts
      `addiu $a0,$zero,7` and loads it after with `lui $at`; same group, `abs.s` is scheduled
      right after the call instead of after the constant (2 words); and the shared
      `setstate(7,1)` tail keeps its `addiu $a0,7` (one extra word).
   4. Case 0x16: retail `bnel $v1,0xB0 -> tail (a0=6)`; this C `beql` around `b tail`.
   Still open: item 2 (pos lui/addiu, plus the loop-alignment nop it costs) and item 3's
   D_L19_001DBD58 delay slot and the extra `addiu $a0,7` in the shared setstate(7,1) tail.
   Members (func_L01_00507AF8 20 places, func_L23_004EAE60, func_L30_004D7368) are not ported yet;
   they are this C with the 0x32-0x36 states etc. added (FAMILIES.md), and inherit the same open spots.
   The H()/F() macros are a drafting convenience (FLD-style field access through the char
   array, which gives retail's `addiu $x,$s3,%lo(D_001A4BE0)` per block); expand them before
   landing (no #define in matched C). The VU0 adds are j-form statements; vector copies use the
   inline qcopy() (it creates the pointer pseudo retail keeps in $s0/$s1 across calls). */
#include "vu0.h"
typedef int u128_t __attribute__((mode(TI)));
typedef u128_t s128;
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4;
#define H(T, off) (((struct { u8 pad[off]; T v; } *)D_001A4BE0)->v)
#define F(p, T, off) (((struct { u8 pad[off]; T v; } *)(p))->v)
extern u8 *D_001D52FC;
extern u8 D_001425C0[];
extern u8 D_001A4BE0[];
extern u8 D_001439F4[];
extern u8 D_00143A05[];
extern s32 D_L19_001D6780;
extern f32 D_L19_001DF330;
extern s32 D_L19_002D4030 __attribute__((section(".data")));
extern s32 D_L19_001DF248;
extern u8 D_L19_002F6C30[];
extern u8 D_L19_002F6E40[];
extern u8 D_L19_002C8040[];
extern u8 D_L19_001E2100[];
s32 func_0038CAD0(void *);
f32 func_0038CF00(void *, void *);
f32 func_0038DBA0(f32 a0, f32 a1);
void func_00393348(s32, s32, void *, void *, void *, s32, s32);
void func_00393BE8(u8 *object);
void func_00393C40(s8 *);
s32 func_00394620(s8 *);
void func_00394F48(void *a0);
void func_00394F90(u8 *object);
void func_00395478();
void func_003C3A10(u8 *object, s32 animation, s32 frame, s32 rate);
s32 func_00382498(s32 a0, s32 a1);
s32 func_003A3BB8(s32, s32);
void func_003E54E0(s32 argument);
void func_003E4D10(s32 argument);
s32 func_L01_003EB2D8(s32);
s32 func_L01_004606E8(s32, s32, void *, s32);
s32 func_L01_004DFDB0(s32 arg);
u32 func_L01_004DFE80(u32 param_1);
void func_L01_004E11C0(s32 kind, s32 side, s32 play_sound, s32 duration);
void func_L01_004E1560(void);
s32 func_L01_004E9238(s32 index);
void func_L01_004EAA80(void);
s32 func_L01_004EDFC8(f32 x);
void func_L01_004EE850(s32, f32);
s32 func_L01_00504EC0(void);
s32 func_L01_005055A0(void);
s32 func_L01_00506298(s32 arg0, s32 arg1);
void func_L01_00506820(void);
s32 func_L01_00506888(s32 *selected);
void func_L01_00507380(void);
void func_L01_005075D8(void);
void func_L01_00507738(void);
void func_L01_0050F368(void);
void func_L01_0050FB40(s32 a0, s32 a1, f32 f12);
void func_L01_0050FED0(void);
s32 func_L01_00512DF8(s32);
s32 func_L19_004E1D60(s32);
s32 func_L19_004F32A0(s32, s32);
void func_0038CB00(void *);
void func_L01_004EDE10(void);
s32 func_L01_004EDFA8(u8 *);
s32 func_L01_00513EF0(void);
void func_L01_00504E38(s32);
void func_L01_004EEBA8(void);
f32 func_L19_00501FE0(f32 time, f32 acceleration, f32 height);
void func_L01_004E5030(f32 arg0, f32 arg1, f32 arg2, f32 arg3);
s32 func_L01_00506E30(void);
void func_L01_0050FEE8(s32 value);
typedef struct { s32 w[11]; } Rec2C;
extern Rec2C D_L19_002F8BD0[];
extern s32 D_L19_001DBD70[2];
__asm__(".extern D_L19_001DBD70, 8");
s32 func_L01_005070E0(void);
f32 func_0038CED8(void *);
s32 func_L01_00507268(void);
void func_L01_005063E8(void);
void func_003C4BB0(f32 *, f32);
s32 func_L01_004F4E70(s32 index, s32 flags);
f32 func_0038CEA8(void *);
s32 func_L01_004E63F0(f32 *out, f32 scale, f32 amount);
void func_003C2F58(s8 *a0, s32 a1, s8 *a2);
void *func_L01_0046E078(s8 *object, void *position, f32 *velocity, s32 *config, s32 flag);
f32 func_0038CF38(void *, void *);
extern s32 D_L19_001DBC10[2];
__asm__(".extern D_L19_001DBC10, 8");
extern s32 D_L19_001DBC20[2];
__asm__(".extern D_L19_001DBC20, 8");
extern s32 D_L19_001D677C;
extern u8 D_001A30B0[];
void func_003A4F28(s32 a0);
void func_L01_00456230(u8 *entity, s32 enabled);
void func_0038D308(f32 *, f32 *);
void func_0038D000(f32 *, f32 *, f32 *);
s32 func_L01_003FB640(void *, s32, void *, f32);
f32 func_0038D098(f32);
f32 func_0038D0B0(f32);
s32 func_003D3CB0(void *, void *, s32, void *, s32);
void func_0038CF68(void *, void *, f32);
f32 func_L01_00447878(f32 *a, f32 *b, f32 *out, f32 d, f32 e);
f32 func_L01_00445EE0(f32 *a0, f32 *a1, s32 *a2, f32 factor);
f32 func_0038DAB8(f32 a0, f32 a1);
s32 func_L01_00476498(void *path, void *out, s32 *index, f32 *offset, s32 wrap, f32 step);
void func_0038CE20(void *, void *, f32);
s32 func_L01_004E8BC8(s8 *, void **, s128 *, void *, void *, s32 *, void *, s32, s32);
s32 func_L01_00476B98(void *, void *, void *, s32 *, f32 *, s32, f32, f32, f32);
f32 func_L01_005114B0(s8 *in);
f32 func_L01_00511748(f32 *a0, f32 *a1, s32 *out, f32 scale);
s32 func_L01_004EE7F8(f32);
extern s32 D_001D545C;
void func_L01_00337F38(void *, s32);
s32 func_L01_004E8318(s8 *, s8 *, s8 *);
void func_L01_004E1180(void);
void func_L01_00510CA0(s16, u8, u8, u8, f32, f32);
void func_L01_00511508(void *dst, void *src, f32 k);
extern u8 D_00142CA0[];
extern f32 D_L19_001DBD4C;
extern s32 D_L19_001DBD74;
s32 func_L01_004FF5D8(void);
s32 func_L01_004FF610(void);
void func_L01_004F4ED0(s32);
void func_L01_004E5EB8(s32 dust, s32 debris, s32 model);
f32 func_003C4138(f32 *value, f32 target, f32 step);
void func_L01_00506BB0(void);
extern f32 D_L19_001DBD58;
f32 func_003824E0(f32 a0, f32 a1);
void func_L01_004EC600(s32);
extern f32 D_L19_001DBC90;
__asm__(".extern D_L19_001DBC90, 4");
extern u8 D_L19_001D60F8;


static __inline__ void qcopy(void *dst, void *src) {
    *(s128 *)dst = *(s128 *)src;
}

void func_L19_004F9D80(void) {
    f32 v10[4] __attribute__((aligned(16)));
    f32 v20[4] __attribute__((aligned(16)));
    f32 v30[4] __attribute__((aligned(16)));
    f32 v40[4] __attribute__((aligned(16)));
    f32 v50[4] __attribute__((aligned(16)));
    f32 v60[4] __attribute__((aligned(16)));
    s32 sp70;
    s32 sp74;
    f32 sp78;
    void *sp7C;
    s32 sp80;
    s32 sp84;
    s32 sp88;
    s32 sp8C;
    s32 sp90;
    s32 sp94;
    s32 sp98;
    s32 sp9C;
    s32 spA0;
    u8 *cur;
    s32 state0;
    s32 sub0;
    s32 anim0;

    cur = H(u8 *, 0x25C0);
    state0 = H(s32, 0x25CC);
    sub0 = H(s32, 0x25C8);
    anim0 = F(cur, u8, 0x43);
    if (H(s32, 0x234) != 0) {
        func_L19_004E1D60(0);
    } else if (func_L19_004E1D60(1) != 0) {
        goto end;
    }
    func_L01_00507380();
    if (H(s32, 0x2850) <= 0) {
        if ((H(u32, 0x25C4) == 0) || (H(u32, 0x25C4) == 2)) {
            func_L19_004F32A0(0x39, 1);
            goto end;
        }
    }
    if (func_L01_005055A0() != 0) {
        goto end;
    }
    if (func_L01_00504EC0() != 0) {
        goto end;
    }
    if (((F(D_001D52FC, s32, 0x1A4) & 0x10) || (F(D_001D52FC, s32, 0x1C4) & 0x10)) && (H(u8, 0x121C) != 2) && (D_L19_002D4030 == 0) && (D_00143A05[1] == 0) && (D_L19_001DF248 >= 8) && (H(u32, 0x25C4) != 0x58)) {
        if (((H(u8, 0x25ED) == 0) || (H(u8, 0x25E4) == 1) || (H(s16, 0x1D2) != 0))
            && ((H(u8, 0x25E8) == 0) || (H(u8, 0x25E4) == 1) || (H(s16, 0x1D2) != 0))) {
            switch (H(u8, 0x25E4)) {
            case 0:
            case 3:
                if (H(s16, 0x2882) != 0) {
                    H(s16, 0x287E) = 0x16;
                } else {
                    H(s16, 0x287E) = 0xC;
                }
                func_00393348(0x23, 0, func_00393BE8, func_00393C40, func_00394620, 0, 0);
                func_003E4D10(0x12C);
                func_003E54E0(0x96);
                break;
            case 1:
                func_00393348(0x23, 0, func_00394F48, func_00394F90, func_00395478, 0, 0);
                break;
            }
        }
    }
    func_L01_005075D8();
    func_L01_00507738();
    if (H(f32, 0x88) < D_L19_001DF330) {
        if ((H(f32, 0x33C) > 2.0f) && (H(u8, 0x25E4) != 2) && (H(u32, 0x25C4) != 0x79)) {
            func_L19_004F32A0(0x79, 1);
            goto end;
        }
    }
    switch (H(u32, 0x25C4)) {
    case 0x0:
    {
        s32 notcrouch;
        s32 anim;
        u8 *obj;
        if ((F(D_001D52FC, s32, 0x1A0) & func_L01_00512DF8(func_003A3BB8(4, 0)))
            && ((H(u8, 0x25E4) != 0) || (D_001439F4[0] != 2) || (H(s32, 0x1228) == 0x6F))
            && (func_L01_003EB2D8(0) == 0)) {
            func_L19_004F32A0(1, 1);
            break;
        }
        func_L01_0050FED0();
        if (H(u8, 0x2877) != 0) {
            func_L19_004F32A0(0x87, 1);
            break;
        }
        notcrouch = H(u8, 0x1474) == 0;
        {
        s32 one = 1;
        H(s8, 0x1436) = 0;
        if (H(s32, 0x1314) == 2) {
            obj = H(u8 *, 0x12F0);
            if ((obj != 0) && (F(obj, u8, 0x60) & 2) && (F(obj, u8, 0x43) != one)) {
                func_003C3A10(obj, one, 0, 6);
            }
            obj = H(u8 *, 0x12F4);
            if ((obj != 0) && (F(obj, u8, 0x60) & 2) && (F(obj, u8, 0x43) != 1)) {
                func_003C3A10(obj, 1, 0, 6);
            }
        }
        }
        if ((F(D_L19_002F6E40, f32, 0x258) > 0.61086524f) || (F(D_L19_002F6E40, f32, 0x254) > 0.43633232f)) {
            obj = H(u8 *, 0x12F0);
            if ((obj != 0) && (F(obj, u8, 0x43) != 1)) {
                func_003C3A10(obj, 1, 0, 0xA);
            }
            obj = H(u8 *, 0x12F4);
            if ((obj != 0) && (F(obj, u8, 0x43) != 1)) {
                func_003C3A10(obj, 1, 0, 0xA);
            }
        }
        anim = func_L01_004DFE80(F(cur, u8, 0x43));
        if ((anim == func_L01_004DFDB0(0)) && notcrouch && (H(s32, 0x1228) != 0x12)) {
            if (func_L01_00506888(&sp70) != 0) {
                u8 *rec;
                H(s32, 0x27F8) = sp70;
                H(s16, 0x208) = 0x64;
                rec = D_L19_002F6C30 + sp70 * 0x70;
                F(rec, s32, 0x60) = F(rec, f32, 0x5C) * 50.0f;
                if (F(rec, s32, 0x44) != 0) {
                    func_L19_004F32A0(0x3C, 1);
                } else {
                    func_L01_0050FB40(F(rec, s32, 0x48), 0, 10.0f);
                }
            }
        } else if (H(s32, 0xC08) & 2) {
            s32 keep = 0;
            if ((H(u8, 0x25E9) != 0) && (H(u8, 0x25EB) != 0) && ((F(H(u8 *, 0x25C0), u8, 0x43) == H(s32, 0x2830)) || (H(s32, 0xE78) != 0))) {
                keep = 1;
            }
            if (keep == 0) {
                H(s8, 0x25E9) = 0;
                if (func_L01_004DFDB0(0) == 0x4A) {
                    func_L01_0050FB40(func_L01_004DFDB0(0), 0, 15.0f);
                } else {
                    func_L01_0050FB40(func_L01_004DFDB0(0), 0, -2.0f);
                }
            }
        }
        if (H(s32, 0x1B8) >= 9) {
            u8 *o2 = H(u8 *, 0x12F4);
            if ((o2 != 0) && (F(o2, u8, 0x43) == 1) && (func_0038CAD0(D_001A4BE0 + 0x2870) != 0) && (F(D_L19_002F6E40, f32, 0x258) < 0.55850536f) && (F(D_L19_002F6E40, f32, 0x254) < 0.34906584f) && (H(s32, 0x1314) == 2)) {
                H(s32, 0x2870) = func_00382498(0x5C, 0xE1);
                func_L01_0050F368();
            }
        }
        if ((H(u8, 0x25E9) != 0) && (H(s32, 0xC0C) == 0) && (H(u8, 0x25EB) != 0) && (H(s16, 0x2874) == 0)
            && ((D_001439F4[0] != 1) || (__builtin_fabsf(H(f32, 0x15A0)) < 0.17453292f))) {
            s32 slot = func_L01_004E9238(0);
            if (slot != H(s32, 0x2834)) {
                func_L01_004EAA80();
            } else {
                s32 want = F(D_L19_002C8040 + D_001425C0[slot] * 0xF0, s32, 0x24);
                if (F(H(u8 *, 0x25C0), u8, 0x43) != want) {
                    if (H(s32, 0xE78) != 0) {
                        H(s32, 0xE84) = 1;
                    }
                    H(s32, 0x2830) = want;
                    func_L01_0050FB40(want, 0, -4.0f);
                }
            }
        }
        func_L01_004EE850(0, 1.0f);
        if ((H(u8, 0x147C) != 0) && (H(s16, 0x36C) == 0)) {
            func_L19_004F32A0(0x7B, 1);
            break;
        }
        if ((H(s16, 0x36E) >= 4) && (H(f32, 0x33C) > 0.4f)) {
            if ((H(s32, 0x25D0) != 8) || (H(s32, 0x1B8) >= 0xC)) {
                func_L19_004F32A0(6, 1);
            }
            break;
        }
        if (H(s16, 0x1E0) != 0) {
            break;
        }
        {
            s32 ok = 1;
            if ((H(s32, 0x25D0) == 1) || (H(s32, 0x25D0) == 0x1D)) {
                if (H(s32, 0x1B8) <= 3) {
                    ok = 0;
                }
            }
            if (ok && (H(s16, 0x368) != 1)) {
                if (func_L01_00506298((H(s16, 0x1EE) != 0) ? 1 : 6, 0) != 0) {
                    break;
                }
            }
        }
        if ((H(s16, 0x368) == 1) && (D_L19_001D6780 == 0) && (func_L01_004606E8(func_003A3BB8(0x40, 0), 6, 0, 0) != 0)) {
            func_L19_004F32A0(0x73, 1);
            break;
        }
        if ((F(D_001D52FC, s32, 0x1A0) & func_003A3BB8(8, 0)) && (H(s32, 0x360) != 0)) {
            if ((F(H(u8 *, 0x25C0), u8, 0x43) != 0x1A) || !(H(f32, 0xC18) < 108.0f)) {
                func_L19_004F32A0(4, 1);
                break;
            }
        }
        if (H(s32, 0x5DC) != 0) {
            func_L19_004F32A0(0x27, 1);
            break;
        }
        if ((H(u8, 0x1474) != 0) && (H(f32, 0x340) > 0.08726646f)) {
            func_L19_004F32A0(0x2E, 1);
            break;
        }
        {
            s32 go = 1;
            s32 turned;
            if (((H(s32, 0x25D0) == 1) || (H(s32, 0x25D0) == 0x1D)) && (H(s32, 0x1B8) < 0x14) && (H(s16, 0x368) != 1)) {
                func_L01_004EE850(0, 1.0f);
                if ((func_0038DBA0(H(f32, 0x1A0), F(D_L19_001E2100, f32, 0x18)) > 1.2217305f) && (func_0038CF00(D_001A4BE0 + 0x80, D_L19_001E2100) < 2.5f)) {
                    go = 0;
                }
            }
            turned = func_L01_004EDFC8(0.17453292f);
            if (go == 0) {
                break;
            }
            if ((turned != 0) || (H(f32, 0x2838) > 0.22f)) {
                s32 side = H(u8, 0x147F);
                func_L01_004E11C0(side, 0, 0, 0x1E);
                func_L01_004E11C0(side, 1, 0, 0x1E);
                func_L19_004F32A0(2, 1);
            }
        }
        break;
    }
    case 0x3C:
        if ((F(D_001D52FC, s32, 0x1A0) & func_L01_00512DF8(func_003A3BB8(4, 0)))
            && ((H(u8, 0x25E4) != 0) || (D_001439F4[0] != 2) || (H(s32, 0x1228) == 0x6F))
            && (func_L01_003EB2D8(0) == 0)) {
            func_L19_004F32A0(1, 1);
            break;
        }
        if ((H(s16, 0x36E) != 0) || (F(D_001D52FC, s32, 0x1A0) & func_003A3BB8(0x40, 0)) || (F(D_001D52FC, s32, 0x1A0) & func_003A3BB8(8, 0))) {
            func_L19_004F32A0(0x3D, 1);
            break;
        }
        func_L01_004EEBA8();
        if (H(f32, 0x1B0) > 0.0f) {
            func_L19_004F32A0(0x3D, 1);
            break;
        }
        if (H(s32, 0xC08) & 2) {
            func_L01_00506820();
            func_L19_004F32A0(0, 1);
        }
        break;
    case 0x3D:
        if (H(s32, 0x1B8) < 8) {
            break;
        }
        func_L01_00506820();
        if (H(s16, 0x36E) != 0) {
            func_L19_004F32A0(6, 1);
            break;
        }
        if (func_L01_00506298(6, 0) != 0) {
            break;
        }
        if (F(D_001D52FC, s32, 0x1A0) & func_003A3BB8(8, 0)) {
            func_L19_004F32A0(4, 1);
            break;
        }
        func_L01_004EEBA8();
        if (H(f32, 0x1B0) > 0.0f) {
            func_L19_004F32A0(2, 1);
            break;
        }
        func_L19_004F32A0(0, 1);
        break;
    case 0x39:
    case 0x43:
    case 0x56:
    case 0x63:
    case 0x6C:
    case 0x82:
    case 0x84:
    case 0x9F:
    case 0xA0:
        if ((H(s32, 0xC08) & 2) || (H(u8, 0x25F1) != 0)) {
            if (H(s16, 0x21E) != 0) {
                H(u8, 0x25F1) = 1;
                H(s32, 0xC00) = 0;
                func_0038CB00(D_001A4BE0 + 0x21E);
                return;
            }
            if ((H(u32, 0x25C4) == 0xA0) && (H(s32, 0x1B8) < 0x44)) {
                return;
            }
            func_L01_004EDE10();
            return;
        }
        if (func_0038CAD0(D_001A4BE0 + 0x23C) == 2) {
            func_L01_004EDE10();
        }
        break;
    case 0x81:
        if (H(s32, 0x1B8) < 0xB8) {
            break;
        }
        func_L01_004EDE10();
        return;
    case 0x50:
        if (H(s32, 0x1B8) < 0xB8) {
            break;
        }
        func_L01_004EDE10();
        return;
    case 0x1:
    {
        u8 *p;
        s32 ok;
        s32 late;
        s32 anim;
        if ((H(u8, 0x25E4) == 0) && ((H(u8, 0x25EB) == 0) || (H(u8, 0x25E5) != 0))) {
            if (F(D_001D52FC, s32, 0x1A0) & func_003A3BB8(8, 0)) {
                func_L01_0050FB40(0xD, 0, 7.0f);
            } else {
                s32 a = func_L01_004DFDB0(1);
                if (F(H(u8 *, 0x25C0), u8, 0x43) != a) {
                    func_L01_0050FB40(a, 0, 7.0f);
                }
            }
        }
        p = H(u8 *, 0x1200);
        ok = 1;
        if ((p != 0) && (func_L01_004EDFA8(p) != 0)) {
            if (F(p, u8, 0x20) != 0) {
                if (func_L01_00513EF0() == 0) {
                    ok = 0;
                }
            }
        }
        late = 0;
        if (H(u8, 0x25E5) == 0) {
            late = H(s32, 0x1B8) >= 0x1A;
        }
        if ((!(F(D_001D52FC, s32, 0x1A0) & func_003A3BB8(4, 0)) && ok) || late) {
            if (H(u8, 0x25E4) != 0) {
                func_L01_00504E38(0);
            } else if (F(D_001D52FC, s32, 0x1A0) & func_003A3BB8(8, 0)) {
                func_L19_004F32A0(4, 1);
            } else {
                func_L19_004F32A0(0, 0);
                anim = func_L01_004DFDB0(1);
                if (F(H(u8 *, 0x25C0), u8, 0x43) != anim) {
                    func_L01_0050FB40(anim, 0, 7.0f);
                }
            }
        }
        break;
    }
    case 0x2F:
        if (!(F(D_001D52FC, s32, 0x1A0) & H(s32, 0x1210)) && (H(s16, 0x1EC) == 0)) {
            if (F(H(u8 *, 0x25C0), u8, 0x43) == 0x31) {
                func_L19_004F32A0(0, 0);
            } else {
                func_L19_004F32A0(0, 1);
            }
        }
        break;
    case 0x14:
    {
        u8 *rec;
        s32 frames;
        if (H(u32, 0x25C4) == 0x14) {
            s32 n = func_L19_00501FE0(60.0f, 0.052f, -1.0f);
            f32 c00 = H(f32, 0xBE0);
            s32 top = 0x1A;
            if (c00 == 0.0f) {
                H(f32, 0xC00) = 0.33f;
            } else if ((c00 != 0.0f) && (H(s16, 0x36E) != 0) && (n != 0) && (((f32)top - H(f32, 0xC18)) > 1.0f)) {
                func_L01_004E5030((f32)top, (f32)n, 0.5f, -1.0f);
                if ((H(f32, 0x33C) < 0.7f) && (H(f32, 0xC00) < 0.75f)) {
                    H(f32, 0xC00) = 0.75f;
                }
            } else if ((H(s16, 0x36E) == 0) && (H(f32, 0xC18) < (f32)top)) {
                H(f32, 0xC00) = 2.0f;
            } else {
                H(f32, 0xC00) = 1.0f;
            }
        }
        rec = (u8 *)&D_L19_002F8BD0[H(s16, 0xBDC)];
        frames = ((s32)H(f32, 0xC18) - F(rec, s32, 0xC)) * 2;
        if ((f32)F(rec, s32, 0x14) < H(f32, 0xC18)) {
            if (H(s32, 0xC0C) != 0) {
                break;
            }
            if (func_L01_004606E8(func_003A3BB8(0x40, 0), frames, 0, 0) != 0) {
                if (!(F(D_001D52FC, s32, 0x1A0) & func_003A3BB8(8, 0))) {
                    func_L19_004F32A0(7, 1);
                    break;
                }
                if (func_L01_00506E30() != 0) {
                    break;
                }
            }
        }
        if ((H(s32, 0xC0C) == 0) && ((f32)F(rec, s32, 0x18) < H(f32, 0xC18))) {
            func_L19_004F32A0(0, 0);
        }
        break;
    }
    case 0x13:
    case 0x15:
    {
        u8 *rec = (u8 *)&D_L19_002F8BD0[H(s16, 0xBDC)];
        s32 frames = ((s32)H(f32, 0xC18) - F(rec, s32, 0xC)) * 2;
        u32 st = H(u32, 0x25C4);
        s32 lim;
        f32 h;
        if (st == 0x15) {
            frames = 7;
        }
        if ((f32)F(rec, s32, 0x14) < H(f32, 0xC18)) {
            if (H(s32, 0xC0C) != 0) {
                goto tail13;
            }
            if ((st != 0x15) || (H(s16, 0x368) != 1)) {
                if (func_L01_004606E8(func_003A3BB8(0x40, 0), frames, 0, 0) != 0) {
                    if (!(F(D_001D52FC, s32, 0x1A0) & func_003A3BB8(8, 0))) {
                        func_L19_004F32A0(7, 1);
                        break;
                    }
                    if (func_L01_00506E30() != 0) {
                        break;
                    }
                }
            }
        }
        if (H(s32, 0xC0C) != 0) {
            goto tail13;
        }
        if ((H(f32, 0xC18) > 34.0f) && (H(f32, 0x2838) > 0.9f)) {
            func_L19_004F32A0(2, 0);
            if (H(u32, 0x25C4) == 2) {
                func_L01_0050FB40(3, D_L19_001DBD70[H(s32, 0x25C8)], 11.0f);
            }
            break;
        }
        if (H(s32, 0xC0C) != 0) {
            goto tail13;
        }
        lim = F(rec, s32, 0x18);
        h = H(f32, 0xC18);
        if ((f32)lim < h) {
            if (H(f32, 0x2838) > 0.8f) {
                func_L19_004F32A0(2, 1);
                break;
            }
            if ((f32)(lim + 5) < h) {
                func_L19_004F32A0(0, 0);
                break;
            }
            if (H(s32, 0xC08) & 2) {
                func_L19_004F32A0(0, 0);
            }
            break;
        }
    tail13:
        if ((H(u32, 0x25C4) == 0x15) && (H(s32, 0x1228) != 9) && (H(s32, 0x1228) != 0x7F)) {
            func_L19_004F32A0(0, 1);
            break;
        }
        if ((H(u32, 0x25C4) == 0x15) && (H(s32, 0x1B8) >= 0x54) && (H(s32, 0xC24) < 0x1A)) {
            func_L01_0050FEE8(2);
            H(s32, 0xC24) = 0x1A;
        }
        break;
    }
    case 0x88:
        if (H(f32, 0xC18) > 37.0f) {
            if (H(s32, 0xC0C) != 0) {
                goto tail88;
            }
            if (func_L01_004606E8(func_003A3BB8(0x40, 0), 6, 0, 0) != 0) {
                if (!(F(D_001D52FC, s32, 0x1A0) & func_003A3BB8(8, 0))) {
                    func_L19_004F32A0(7, 1);
                    break;
                }
                if (func_L01_00506E30() != 0) {
                    break;
                }
            }
        }
        if ((H(s32, 0xC0C) == 0) && (H(f32, 0xC18) > 37.0f)) {
            func_L19_004F32A0(0, 0);
            func_L01_0050FB40(func_L01_004DFDB0(0), 0, 12.0f);
            break;
        }
    tail88:
        if ((H(u32, 0x25C4) == 0x15) && (H(s32, 0x1B8) >= 0x54) && (H(s32, 0xC24) < 0x1A)) {
            func_L01_0050FEE8(2);
            H(s32, 0xC24) = 0x1A;
        }
        break;
    case 0x7C:
        if (H(s32, 0xC08) & 2) {
            func_L19_004F32A0(0, 1);
        }
        break;
    case 0x2:
    case 0x2E:
    case 0x75:
    {
        s32 n;
        s32 turned;
        u32 st;
        if ((H(u8, 0x3EE) != 0) && ((F(cur, f32, 0x44) > 0.9f) || (F(cur, u8, 0x42) != 0xFF))) {
            H(u8, 0x3EE) = 0;
        }
        if ((H(u8, 0x147C) != 0) && (H(s16, 0x36C) == 0)) {
            func_L19_004F32A0(0x7B, 1);
            break;
        }
        if ((H(s16, 0x36E) >= 6) && ((H(s32, 0x25D4) != 0x12) || (H(u8, 0x25EA) == 0)) && (H(f32, 0x33C) > 1.35f) && (func_L01_005070E0() == 0)) {
            func_L19_004F32A0(6, 1);
            break;
        }
        n = 7;
        if (H(s16, 0x1EE) != 0) {
            n = 1;
        }
        if ((func_L01_004606E8(func_003A3BB8(0x40, 0), n, 0, 0) != 0) && ((H(s16, 0x36E) < 7) || (H(f32, 0x33C) < 0.5f) || (H(s16, 0x202) != 0))) {
            func_L01_004EE850(0, 1.0f);
            if (func_L01_00506298(n, 1) != 0) {
                break;
            }
            if (H(f32, 0x2838) > 0.85f) {
                if ((H(s16, 0x1434) == 0) && ((H(s32, 0x16B0) != 1) || (func_L01_004606E8(0x28, 2, 0, 0) == 0))) {
                    func_L19_004F32A0(9, 1);
                } else {
                    func_L19_004F32A0(7, 1);
                }
            } else {
                func_L19_004F32A0(7, 1);
            }
            break;
        }
        if (H(s16, 0x36E) != 0) {
            break;
        }
        if (((H(u8, 0x1474) == 0) || ((H(f32, 0x174) < 0.040000003f) && (H(f32, 0x340) < 0.08726646f)))
            && (F(D_001D52FC, s32, 0x1A0) & func_L01_00512DF8(func_003A3BB8(4, 0)))
            && ((H(u8, 0x25E4) != 0) || (D_001439F4[0] != 2) || (H(s32, 0x1228) == 0x6F))
            && (func_L01_003EB2D8(0) == 0)) {
            func_L19_004F32A0(1, 1);
            break;
        }
        if (F(D_001D52FC, s32, 0x1A0) & func_003A3BB8(8, 0)) {
            func_L19_004F32A0(4, 1);
            break;
        }
        if ((H(u8, 0x1474) != 0) && (H(u32, 0x25C4) == 0x2E)) {
            f32 speed = func_0038CED8(D_001A4BE0 + 0x110);
            s32 anim;
            if ((H(f32, 0x2838) < 0.17f) && ((F(H(u8 *, 0x25C0), u8, 0x43) == 0x32) || (F(H(u8 *, 0x25C0), u8, 0x43) == 0x7B) || (((anim = F(H(u8 *, 0x25C0), u8, 0x43)) == func_L01_004DFDB0(0)) && (H(f32, 0x340) > 0.08726646f))) && (H(s32, 0x1CC) >= 8) && (H(s32, 0xC0C) == 0)) {
                func_L01_0050FB40(0x54, 0, 12.0f);
            } else if ((H(f32, 0x2838) > 0.3f) && (F(H(u8 *, 0x25C0), u8, 0x43) != 0x32) && (F(H(u8 *, 0x25C0), u8, 0x43) != 0x7B) && (H(s32, 0xC0C) == 0)) {
                if (((H(s16, 0x1434) != 0) || ((H(s32, 0x16B0) == 1) && (func_L01_004606E8(0x28, 2, 0, 0) != 0))) && (H(u8, 0x1436) != 0)) {
                    func_L01_0050FB40(0x7B, 0, 12.0f);
                } else {
                    func_L01_0050FB40(0x32, 0, 12.0f);
                }
            } else if ((F(H(u8 *, 0x25C0), u8, 0x43) == 0x54) && (H(s32, 0xC0C) == 0) && (H(f32, 0x2838) < 0.17f) && (H(f32, 0x340) < 0.08726646f) && (speed < 0.034f)) {
                func_L01_0050FB40(func_L01_004DFDB0(0), 0, 17.0f);
            }
        }
        st = H(u32, 0x25C4);
        if ((st == 2) || (st == 0x80)) {
            if (H(u8, 0x1474) != 0) {
                func_L19_004F32A0(0x2E, 1);
            }
        } else if (st == 0x2E) {
            if (H(u8, 0x1474) == 0) {
                func_L19_004F32A0(2, 1);
            }
        }
        if (H(u8, 0x1474) != 0) {
            if (((H(s16, 0x1434) != 0) || ((H(s32, 0x16B0) == 1) && (func_L01_004606E8(0x28, 2, 0, 0) != 0))) && (H(u8, 0x1436) != 0)) {
                if (F(H(u8 *, 0x25C0), u8, 0x43) == 0x32) {
                    func_L01_0050FB40(0x7B, 0, 7.0f);
                }
            } else {
                if (F(H(u8 *, 0x25C0), u8, 0x43) == 0x7B) {
                    func_L01_0050FB40(0x32, 0, 6.0f);
                }
            }
        }
        st = H(u32, 0x25C4);
        if (st == 2) {
            if (H(u8, 0x25EA) != 0) {
                func_L19_004F32A0(0x75, 1);
            }
        } else if (st == 0x75) {
            if (H(u8, 0x25EA) == 0) {
                func_L19_004F32A0(2, 1);
            }
        }
        if (H(s32, 0x5DC) != 0) {
            func_L19_004F32A0(0x27, 1);
            break;
        }
        turned = func_L01_004EDFC8(0.034906585f);
        st = H(u32, 0x25C4);
        if (st == 2) {
            if (((H(f32, 0x2838) < 0.17f) || (H(s16, 0x1E0) != 0)) && (turned == 0) && ((H(s32, 0x3F0) == 0) || (__builtin_fabsf(H(f32, 0x1A8)) < 0.017453292f))) {
                s32 anim;
                if (func_L01_00507268() != 0) {
                    break;
                }
                if (func_L19_004F32A0(0, 0) != 0) {
                    func_003C4BB0((f32 *)(D_001A4BE0 + 0x160), 0.030000001f);
                    if (H(f32, 0x1B4) > 0.030000001f) {
                        H(f32, 0x1B4) = 0.030000001f;
                    }
                    anim = func_L01_004DFDB0(1);
                    if (anim == 0x4A) {
                        func_L01_0050FB40(0x4A, 0, 12.0f);
                    } else {
                        func_L01_0050FB40(anim, 0, -1.0f);
                    }
                }
            } else {
                func_L01_005063E8();
            }
        } else if (st == 0x2E) {
            if ((F(D_001D52FC, s32, 0x1D4) != 0) && (func_0038CED8(D_001A4BE0 + 0xF0) < 0.001f) && (H(f32, 0x340) < 0.08726646f) && (func_L19_004F32A0(0, 0) != 0)) {
                func_L01_0050FB40(func_L01_004DFDB0(0), 0, 14.0f);
            }
            if ((F(cur, u8, 0x43) == 0x32) || (F(cur, u8, 0x43) == 0x7B)) {
                H(f32, 0xC00) = (1.0f - H(f32, 0x3E0)) * 2.0f;
                if (H(f32, 0xC00) > 1.7f) {
                    H(f32, 0xC00) = 1.7f;
                }
                if (H(f32, 0xC00) < 0.75f) {
                    H(f32, 0xC00) = 0.75f;
                }
            } else if (F(cur, u8, 0x43) == 0x54) {
                H(f32, 0xC00) = H(f32, 0x170) * 8.333333f;
                if (H(f32, 0xC00) > 1.1f) {
                    H(f32, 0xC00) = 1.1f;
                }
                if (H(f32, 0xC00) < 0.3f) {
                    H(f32, 0xC00) = 0.3f;
                }
            }
        } else if (st == 0x75) {
            if ((F(D_001D52FC, s32, 0x1D4) != 0) && (func_0038CED8(D_001A4BE0 + 0xF0) < 0.064f) && (func_L19_004F32A0(0, 0) != 0)) {
                func_L01_0050FB40(func_L01_004DFDB0(0), 0, 14.0f);
            }
            H(f32, 0xC00) = H(f32, 0x170) * 29.166666f;
            if (H(f32, 0xC00) < 0.6f) {
                H(f32, 0xC00) = 0.6f;
            }
            if (H(f32, 0xC00) > 1.05f) {
                H(f32, 0xC00) = 1.05f;
            }
        }
        if ((H(s16, 0x368) == 0) && (H(s32, 0x1278) == 0xD) && (H(s32, 0x2634) != 0)) {
            H(s32, 0x2650) = 1;
        }
        break;
    }
    case 0x80:
    {
        s32 one = 1;
        s32 flag = 0;
        if (H(s16, 0x368) != 0) {
            flag = 1;
        }
        if (!(F(D_001D52FC, s32, 0x1A0) & func_003A3BB8(8, 0))) {
            if (H(s32, 0x1B8) >= 0x33) {
                flag = one;
            }
        }
        if (H(u8, 0x25E9) != 0) {
            flag = one;
        }
        if (flag != 0) {
            if (H(s32, 0x2634) != 0) {
                H(s32, 0x2650) = one;
            }
            func_L01_004F4E70(9, 0);
            H(s16, 0x1E0) = 0x19;
            func_L19_004F32A0(3, 0);
            func_L01_0050FB40(6, 4, 9.0f);
        } else if (H(s32, 0x984) != 0) {
            func_L19_004F32A0(0, 0);
            func_L01_0050FB40(func_L01_004DFDB0(0), 0, -2.0f);
        } else {
            if (H(u8, 0x2A7) != 0) {
                f32 a = func_0038CEA8(D_001A4BE0 + 0x110);
                if (a < func_0038CEA8(D_001A4BE0 + 0xF0) * 0.75f) {
                    func_L19_004F32A0(0x7C, 1);
                    break;
                }
                if (func_L01_004E63F0(0, 1.0f, 1.25f) != 0) {
                    func_L19_004F32A0(0x7C, 1);
                    break;
                }
            }
            *(s128 *)v30 = 0;
            v30[0] = -0.10000001f;
            func_003C2F58(H(s8 *, 0x25C0), 0x16, (s8 *)v10);
            func_003C2F58(H(s8 *, 0x25C0), 0x17, (s8 *)v20);
            func_L01_0046E078(H(s8 *, 0x25C0), v10, v30, (s32 *)D_L19_001DBC10, 1);
            func_L01_0046E078(H(s8 *, 0x25C0), v10, v30, (s32 *)D_L19_001DBC20, 1);
            func_L01_0046E078(H(s8 *, 0x25C0), v20, v30, (s32 *)D_L19_001DBC10, 1);
            func_L01_0046E078(H(s8 *, 0x25C0), v20, v30, (s32 *)D_L19_001DBC20, 1);
        }
        break;
    }
    case 0x66:
        if (D_L19_001D677C != 0) {
            if (func_0038CF00(D_001A4BE0 + 0x80, D_001A4BE0 + 0x1B40) < 0.4f) {
                if (H(f32, 0x170) < 0.054000005f) {
                    func_L19_004F32A0(0x68, 1);
                    break;
                }
                if ((H(u8, 0x25E4) != 0) && (H(f32, 0x170) >= 0.054000005f)) {
                    func_L19_004F32A0(0x67, 1);
                }
                break;
            }
        } else {
            if (func_0038CF38(D_001A4BE0 + 0x80, D_001A4BE0 + 0x1B40) < 0.3f) {
                if ((H(f32, 0x170) < 0.054000005f) && (func_0038DBA0(H(f32, 0x98), H(f32, 0x1B4C)) < 0.034906585f)) {
                    func_L19_004F32A0(0x68, 1);
                    break;
                }
                if ((H(u8, 0x25E4) != 0) && (H(f32, 0x170) >= 0.054000005f)) {
                    func_L19_004F32A0(0x67, 1);
                }
                break;
            }
        }
        func_L01_005063E8();
        break;
    case 0x67:
        if (H(s32, 0xC08) & 2) {
            func_L19_004F32A0(0x66, 1);
        }
        break;
    case 0x68:
        if ((H(s32, 0xC08) & 2) || (H(s32, 0x1B50) != 0)) {
            func_L19_004F32A0(0, 1);
        }
        if (D_L19_001D677C != 0) {
            if (func_0038CF00(D_001A4BE0 + 0x80, D_001A4BE0 + 0x1B40) > 0.4f) {
                func_L19_004F32A0(0x66, 1);
            }
        } else {
            if (func_0038CF38(D_001A4BE0 + 0x80, D_001A4BE0 + 0x1B40) > 0.3f) {
                func_L19_004F32A0(0x66, 1);
            }
        }
        break;
    case 0x7E:
        if (H(f32, 0x88) < (H(f32, 0x354) - 1.2f)) {
            func_L01_004EDE10();
            return;
        }
        if (H(s32, 0x1B8) < 0x54) {
            break;
        }
        func_L01_004EDE10();
        return;
    case 0x7F:
        if (H(f32, 0x88) < (H(f32, 0x354) - 0.8f)) {
            func_L01_004EDE10();
            return;
        }
        if (H(s32, 0x1B8) < 0x7E) {
            break;
        }
        func_L01_004EDE10();
        return;
    case 0x72:
        if ((f32)D_L19_002F8BD0[H(s16, 0xBDC)].w[6] < H(f32, 0xC18)) {
            func_L19_004F32A0(0, 1);
        }
        break;
    case 0x30:
        if (((H(u8, 0x1475) == 0) && (H(s16, 0x200) == 0)) || (H(f32, 0x33C) > 1.0f)) {
            s32 slot = H(s32, 0x2794);
            if (slot != -1) {
                u8 *ent = D_001A30B0 + slot * 0x80;
                if ((F(ent, s32, 0xDC) == H(s32, 0x25C0)) && (F(ent, u8, 0xD0) != 0)) {
                    func_003A4F28(slot);
                }
            }
            H(s32, 0x2794) = -1;
            if (func_L19_004F32A0(0, 0) != 0) {
                func_L01_0050FB40(func_L01_004DFDB0(0), 0, 14.0f);
                H(s128, 0x160) = H(s128, 0x150);
            }
        }
        break;
    case 0x3:
        if ((F(D_001D52FC, s32, 0x1A0) & func_L01_00512DF8(func_003A3BB8(4, 0)))
            && ((H(u8, 0x25E4) != 0) || (D_001439F4[0] != 2) || (H(s32, 0x1228) == 0x6F))
            && (func_L01_003EB2D8(0) == 0)) {
            func_L19_004F32A0(1, 1);
            break;
        }
        if ((H(s16, 0x1E0) == 0) && (F(D_001D52FC, s32, 0x1A4) & func_003A3BB8(0x40, 0))) {
            func_L19_004F32A0(7, 1);
            break;
        }
        if ((H(s16, 0x1E0) == 0) && (F(D_001D52FC, s32, 0x1A0) & func_003A3BB8(8, 0))) {
            func_L19_004F32A0(4, 1);
            break;
        }
        if ((H(s16, 0x36E) >= 8) && (H(f32, 0x33C) > 0.3f)) {
            func_L19_004F32A0(6, 1);
            break;
        }
        if (H(s32, 0xC08) & 2) {
            func_L19_004F32A0(0, 1);
            break;
        }
        if (H(s32, 0x5DC) != 0) {
            func_L19_004F32A0(0x27, 1);
            break;
        }
        if (!(H(f32, 0x2838) > 0.2f) || (H(s16, 0x1E0) != 0)) {
            break;
        }
        if (func_L01_004DFDB0(0) != 0x4A) {
            if (H(f32, 0x1B4) == 0.0f) {
                func_L19_004F32A0(0, 0);
                break;
            }
        } else if ((H(f32, 0xC18) > 10.0f) && (func_L19_004F32A0(0, 0) != 0)) {
            func_L01_0050FB40(func_L01_004DFDB0(0), 0, 14.0f);
        }
        if (H(f32, 0x2838) > 0.5f) {
            func_L19_004F32A0(2, 1);
        }
        break;
    case 0x4:
        if ((F(D_001D52FC, s32, 0x1A0) & func_L01_00512DF8(func_003A3BB8(4, 0)))
            && ((H(u8, 0x25E4) != 0) || (D_001439F4[0] != 2) || (H(s32, 0x1228) == 0x6F))
            && (func_L01_003EB2D8(0) == 0)) {
            func_L19_004F32A0(1, 1);
            break;
        }
        if ((H(s32, 0x1B8) >= 0xA) && !(F(D_001D52FC, s32, 0x1A0) & func_003A3BB8(8, 0))) {
            func_L19_004F32A0(0, 0);
            func_L01_0050FB40(func_L01_004DFDB0(0), 0, -2.0f);
            break;
        }
        if (H(u8, 0x147C) != 0) {
            if (H(s16, 0x36C) == 0) {
                func_L19_004F32A0(0x7B, 1);
                break;
            }
        } else if (func_L01_00506E30() != 0) {
            break;
        }
        if ((func_L01_004606E8(0x80, 0xC, 0, 0) != 0) && (H(u8, 0x121A) == 0) && (H(s32, 0x1228) == 9)) {
            func_L19_004F32A0(0x15, 1);
        }
        if (H(s16, 0x36E) >= 8) {
            if ((H(s32, 0x25D0) != 8) || (H(s32, 0x1B8) >= 0xC)) {
                func_L19_004F32A0(6, 1);
            }
        }
        break;
    case 0x8F:
        if (H(s32, 0x1228) != 0xB) {
            func_L19_004F32A0(0, 1);
            break;
        }
        if (H(s32, 0xA9C) != 0) {
            u8 *obj = H(u8 *, 0xA90);
            if (obj != 0) {
                func_L01_00456230(obj, 1);
            }
            func_L19_004F32A0(0x90, 1);
        }
        break;
    case 0x90:
        if (H(s32, 0x1B8) >= 0x4C) {
            func_L19_004F32A0(0, 1);
        }
        break;
    case 0x23:
        if (H(s32, 0x1228) != 0xB) {
            func_L19_004F32A0(0, 1);
        }
        break;
    case 0x24:
    {
        s32 go;
        func_L01_004E5030(10.0f, H(f32, 0xA2C), 0.5f, -1.0f);
        if ((H(f32, 0xA2C) < 18.0f) && (H(f32, 0xA2C) < 25.0f)) {
            func_L01_0050FB40(0xA, 0, 13.0f);
        }
        go = 0;
        if (!(F(D_001D52FC, s32, 0x1A0) & H(s32, 0x1210))) {
            if (H(f32, 0xA2C) > 21.0f) {
                H(s32, 0xA48) = 1;
            }
            go = 1;
        }
        if ((H(s32, 0x25C8) == 1) && (H(f32, 0xA20) < 0.080000006f)) {
            go = 1;
        }
        if (go != 0) {
            H(f32, 0x1B4) = H(f32, 0xA20);
            if (H(f32, 0x1B4) > 0.14000002f) {
                H(f32, 0x1B4) = 0.14000002f;
            }
            if (H(f32, 0x33C) < 0.3f) {
                func_L19_004F32A0(0, 0);
                func_L01_0050FB40(func_L01_004DFDB0(0), 0, 25.0f);
                break;
            }
            if (F(H(u8 *, 0x25C0), u8, 0x43) == 0xA) {
                func_L19_004F32A0(6, 0);
            } else {
                func_L19_004F32A0(6, 0);
                func_L01_0050FB40(0xA, 0, 14.0f);
            }
            H(f32, 0xA04) = 0.016800001f;
            H(f32, 0xA00) = 0.011600001f;
            H(s32, 0x280C) = 0;
        }
        break;
    }
    case 0x25:
        if (!(F(D_001D52FC, s32, 0x1A0) & H(s32, 0x1210))) {
            H(f32, 0x1B4) = H(f32, 0xA20);
            if (H(f32, 0x1B4) > 0.14000002f) {
                H(f32, 0x1B4) = 0.14000002f;
            }
            if (H(f32, 0x33C) < 0.4f) {
                func_L19_004F32A0(0, 1);
            } else {
                func_L19_004F32A0(6, 1);
                H(s32, 0x280C) = 0;
            }
        }
        break;
    case 0x2B:
        if (!(F(D_001D52FC, s32, 0x1A0) & H(s32, 0x1210))) {
            s32 t = H(s32, 0x1B8);
            if (t >= 9) {
                if (t < 0x21) {
                    H(s32, 0xA48) = 1;
                }
                func_L19_004F32A0(0x2C, 1);
                H(f32, 0xA04) = 0.0028000001f;
                H(f32, 0xA00) = 0.0108f;
            }
        }
        break;
    case 0x27:
    case 0x28:
    case 0x29:
    case 0x2A:
    case 0x3E:
    {
        u32 st;
        if (H(u32, 0x25C4) == 0x3E) {
            H(s16, 0x62E) = 0;
        }
        if (H(u32, 0x25C4) == 0x2A) {
            H(s8, 0x1219) = 2;
        }
        if (H(u32, 0x25C4) != 0x3E) {
            s32 hit = 0;
            if (H(u8, 0x2A7) != 0) {
                f32 half = 0.5f;
                f32 up = 0.02f;
                if ((u32)(H(u32, 0x25C4) - 0x28) < 2) {
                    up = 0.45f;
                }
                qzero(v10);
                v10[1] = -H(f32, 0x5F0);
                v10[2] = H(f32, 0x5EC);
                func_0038D308(v40, v10);
                *(s128 *)v20 = 0;
                v20[0] = 0.25f;
                v20[2] = up + half;
                func_0038D000(v20, v20, v40);
                vec_add_ba(v20, v20, D_001A4BE0 + 0x80);
                hit = func_L01_003FB640(v20, 2, 0, half) != 0;
            }
            if ((hit != 0) || (H(s16, 0x62E) != 0)) {
                s32 clear = 1;
                if (H(u8, 0x2A7) != 0) {
                    qcopy(v10, D_001A4BE0 + 0x570);
                    v10[2] += 1.5f;
                    v20[0] = func_0038D098(H(f32, 0x5EC)) * 5.0f;
                    v20[1] = func_0038D0B0(H(f32, 0x5EC)) * 5.0f;
                    v20[2] = 0.0f;
                    vec_add_ab(v20, v20, v10);
                    if (func_003D3CB0(v10, v20, 2, 0, 0) != 0) {
                        clear = 0;
                    }
                }
                H(s16, 0x62E) = 0;
                if (clear == 0) {
                    func_0038CF68(D_001A4BE0 + 0x120, D_001A4BE0 + 0x10, 0.26000002f);
                    H(f32, 0x128) = 0.20000002f;
                    func_L19_004F32A0(0x16, 1);
                    H(s16, 0x1F4) = 0x3A;
                    H(s16, 0x1D0) = 0x3A;
                } else {
                    func_L19_004F32A0(0x3E, 1);
                }
                break;
            }
        }
        st = H(u32, 0x25C4);
        if (st == 0x27) {
            s32 a;
            s32 b;
            if (func_L01_004606E8(func_003A3BB8(0x40, 0), 6, 0, 0) != 0) {
                if (H(s32, 0x628) != 0) {
                    H(s32, 0x630) = 1;
                } else {
                    func_L19_004F32A0(0x28, 1);
                }
                break;
            }
            a = H(s32, 0x5E0);
            if ((a >= 5) || ((b = H(s32, 0x668)) >= 5)) {
                if (H(f32, 0x33C) > 8.0f) {
                    H(s16, 0x1E0) = 0x3A;
                }
                H(s16, 0x1D0) = 0x3A;
                func_L19_004F32A0(6, 1);
                H(s16, 0x1F4) = 7;
                H(s16, 0x1D0) = 0x3A;
                break;
            }
            if ((a == 0) && (b == 0) && (func_L01_004606E8(0x80, 8, 0, 0) != 0)) {
                func_L19_004F32A0(0x2A, 1);
                break;
            }
            if (H(s32, 0x61C) == -1) {
                s32 anim = H(s32, 0x5FC) + 0x2C;
                if (F(H(u8 *, 0x25C0), u8, 0x43) != anim) {
                    func_L01_0050FB40(anim, 0, 10.0f);
                }
            } else {
                s32 anim = H(s32, 0x61C) + 0x42;
                if (F(H(u8 *, 0x25C0), u8, 0x43) != anim) {
                    func_L01_0050FB40(anim, 0, 10.0f);
                }
            }
            if ((H(s16, 0x62C) != 0) && (H(s32, 0x630) != 0)) {
                f32 h;
                f32 t;
                func_L19_004F32A0(0x28, 1);
                H(s32, 0x634) = 1;
                h = func_L01_00447878((f32 *)(D_001A4BE0 + 0x80), (f32 *)(D_001A4BE0 + 0x5C0), 0, H(f32, 0x174), -H(f32, 0x4F0));
                *(s128 *)v20 = 0;
                v20[2] = h;
                *(s128 *)v10 = 0;
                t = func_L01_00445EE0(v10, v20, 0, H(f32, 0x4F0));
                H(f32, 0x4D8) = t;
                H(f32, 0x4F0) = H(f32, 0x638);
                H(f32, 0x478) = t;
                H(f32, 0x4DC) = t + 0.05f;
            }
            H(s32, 0x628) = 0;
            H(s16, 0x62C) = 0;
        } else if (st == 0x2A) {
            s32 top;
            if ((func_L01_004606E8(func_003A3BB8(0x40, 0), 4, 0, 0) != 0) && ((f32)D_L19_002F8BD0[H(s16, 0xBDC)].w[5] <= H(f32, 0xC18))) {
                func_L19_004F32A0(0x28, 1);
                break;
            }
            top = 0xE;
            if (H(s16, 0xBDC) == 0) {
                top = 0x17;
            }
            if ((H(s32, 0x5E0) == 0) && (H(s32, 0x668) == 0) && (func_L01_004606E8(0x80, 8, 0, 0) != 0)) {
                if ((f32)top < H(f32, 0xC18)) {
                    func_L19_004F32A0(0x2A, 1);
                }
                break;
            }
            if ((f32)D_L19_002F8BD0[H(s16, 0xBDC)].w[6] < H(f32, 0xC18)) {
                func_L19_004F32A0(0x27, 1);
                break;
            }
            if ((H(s32, 0x5E0) >= 5) || (H(s32, 0x668) >= 5)) {
                func_L19_004F32A0(6, 1);
                H(s16, 0x1F4) = 7;
                H(s16, 0x1D0) = 0x3A;
            }
        } else if ((u32)(st - 0x28) < 2) {
            s32 lo;
            s32 now;
            if (((H(s32, 0x5E0) >= 5) || (H(s32, 0x634) != 0)) && (H(s32, 0x5DC) != 0) && ((H(f32, 0x88) - H(f32, 0x578)) < 0.35f)) {
                func_L19_004F32A0(0x27, 1);
                break;
            }
            if (H(s32, 0x5E0) >= 5) {
                func_L19_004F32A0(6, 1);
                break;
            }
            if ((H(u32, 0x25C4) == 0x28) && (H(s32, 0x1B8) < 8) && (H(u8, 0x46E) == 0) && (H(f32, 0x2838) > 0.5f) && (H(s32, 0x600) == 0)) {
                func_L01_004EE850(0, 1.0f);
                if (func_0038DBA0(func_0038DBA0(H(f32, 0x1A0), H(f32, 0x5EC)), 1.5707964f) < 1.2217305f) {
                    f32 ang;
                    f32 d;
                    f32 lim;
                    f32 *pw;
                    f32 *pv;
                    ang = func_0038DAB8(H(f32, 0x5EC), 1.5707964f);
                    if (func_0038DBA0(H(f32, 0x1A0), ang) > 1.5707964f) {
                        ang = func_0038DAB8(H(f32, 0x5EC), -1.5707964f);
                    }
                    lim = 4.5f;
                    pw = v20;
                    pv = v10;
                    for (d = 2.0f; d <= lim; d += 0.75f) {
                        *(s128 *)v10 = H(s128, 0x80);
                        sp74 = H(s32, 0x5D4);
                        sp78 = H(f32, 0x5D8);
                        if (func_L01_00476498(H(void *, 0x5D0), pv, &sp74, &sp78, H(s32, 0x5F4), H(f32, 0x170) * 0.0f) != 0) {
                            func_0038CE20(pw, D_001A4BE0 + 0x110, 40.0f);
                            vec_add_ba(v10, D_001A4BE0 + 0x80, v20);
                        }
                        v10[0] += func_0038D098(ang) * d;
                        v10[1] += func_0038D0B0(ang) * d;
                        if (func_L01_004E8BC8((s8 *)pv, &sp7C, (s128 *)pw, &sp80, &sp84, &sp88, H(void *, 0x5D0), 0, 1) != 0) {
                            H(void *, 0x604) = H(void *, 0x5D0);
                            H(s32, 0x608) = H(s32, 0x5D4);
                            H(f32, 0x60C) = H(f32, 0x5D8);
                            H(s32, 0x610) = H(s32, 0x5F4);
                            H(s128, 0x5B0) = H(s128, 0x570);
                            H(void *, 0x5D0) = sp7C;
                            H(s32, 0x5F4) = sp88;
                            func_L01_00476B98(sp7C, D_001A4BE0 + 0x80, D_001A4BE0 + 0x570, (s32 *)(D_001A4BE0 + 0x5D4), (f32 *)(D_001A4BE0 + 0x5D8), sp88, 999.0f, 2.0f, 0.0f);
                            H(s32, 0x600) = 1;
                            H(s32, 0x618) = 0;
                            func_L19_004F32A0(0x29, 1);
                            break;
                        }
                    }
                }
            }
            if ((H(s16, 0x47C) < H(s32, 0x1B8)) && (func_L01_005114B0((s8 *)(D_001A4BE0 + 0xF0)) < 0.001f)) {
                H(s8, 0x46E) = 1;
            }
            lo = H(s16, 0x47C);
            now = H(s32, 0x1B8);
            if ((now >= lo + 1) && (now < lo + 7) && (H(u8, 0x46E) == 0) && (H(s32, 0xC0C) == 0)) {
                func_L01_00511748((f32 *)(D_001A4BE0 + 0x80), (f32 *)(D_001A4BE0 + 0xF0), &sp8C, H(f32, 0x4F0));
                func_L01_004E5030(H(f32, 0x498), (f32)sp8C, 0.5f, 0.36f);
                if (H(s32, 0x600) != 0) {
                    if (H(f32, 0xC00) > 2.0f) {
                        H(f32, 0xC00) = 2.0f;
                    }
                    if (H(f32, 0xC00) < 0.5f) {
                        H(f32, 0xC00) = 0.5f;
                    }
                }
            } else if ((H(u8, 0x46E) != 0) && (H(u8, 0x46C) == 0)) {
                H(s16, 0x47E) = 0x19;
                if (H(s32, 0x5E0) == 0) {
                    H(s16, 0x47E) = (s32)func_L19_00501FE0(60.0f, H(f32, 0x4F0), H(f32, 0x578));
                }
                if (H(s16, 0x47E) != 0) {
                    func_L01_004E5030(H(f32, 0x49C), (f32)H(s16, 0x47E), 0.5f, 0.36f);
                }
                if (H(s32, 0x600) != 0) {
                    if (H(f32, 0xC00) > 2.0f) {
                        H(f32, 0xC00) = 2.0f;
                    }
                    if (H(f32, 0xC00) < 0.5f) {
                        H(f32, 0xC00) = 0.5f;
                    }
                }
                if ((H(s32, 0x5E0) == 0) && (H(s32, 0x668) == 0) && (H(f32, 0x33C) < 0.5f)) {
                    f32 y = H(f32, 0x88);
                    f32 floor = H(f32, 0x578);
                    if (y + H(f32, 0xF8) < floor) {
                        H(u8, 0x46C) = 1;
                        H(f32, 0xF8) = floor - y;
                        H(f32, 0xC00) = 1.0f;
                    }
                }
                if ((H(f32, 0x88) - H(f32, 0x578)) < -2.5f) {
                    func_L19_004F32A0(6, 1);
                    H(s16, 0x1E0) = 0x3A;
                    H(s16, 0x1F4) = 7;
                    H(s16, 0x1D0) = 0x3A;
                    break;
                }
            }
            if (H(s32, 0x69C) != 0) {
                func_L19_004F32A0(0x76, 1);
                break;
            }
            if (H(u8, 0x46C) != 0) {
                if (++H(u8, 0x46C) >= 3) {
                    H(s32, 0x25C4) = 0x27;
                    func_L01_0050FB40(H(s32, 0x5FC) + 0x2C, 0, 6.0f);
                    break;
                }
            }
            if ((H(s32, 0x5E0) != 0) && (H(s16, 0x36E) == 0) && (func_L19_004F32A0(0, 0) != 0)) {
                func_L01_0050FB40(0xC, 4, 5.0f);
            }
        } else if (st == 0x3E) {
            if (H(f32, 0xF8) > 0.0f) {
                func_L01_00511748((f32 *)(D_001A4BE0 + 0x80), (f32 *)(D_001A4BE0 + 0xF0), &sp90, 0.0092f);
                func_L01_004E5030(9.0f, (f32)sp90, 0.5f, -1.0f);
            }
            if ((H(s32, 0x5E0) != 0) && (H(s32, 0x360) != 0)) {
                if (func_L19_004F32A0(0, 0) != 0) {
                    func_L01_0050FB40(0xC, 4, 5.0f);
                }
                break;
            }
            if (H(s32, 0xC08) & 2) {
                func_L19_004F32A0(0x27, 1);
                break;
            }
            if (H(s32, 0x1B8) < 9) {
                break;
            }
            if ((H(f32, 0xF8) < 0.0f) && (__builtin_fabsf(H(f32, 0x88) - H(f32, 0x578)) < 0.3f)) {
                func_L19_004F32A0(0x27, 1);
            }
        }
        break;
    }
    case 0x76:
        if (F(H(u8 *, 0x25C0), u8, 0x43) == 0x5A) {
            if (func_L01_004EE7F8(11.0f) != 0) {
                if (D_001D545C != 2) {
                    func_L01_004F4E70(0xA, 0);
                } else {
                    func_L01_004F4E70(0x16, 0);
                }
                func_L01_00337F38(D_001A4BE0 + 0x670, 4);
            }
            if (H(s32, 0xC08) & 2) {
                func_L01_0050FB40(0x53, 0, 25.0f);
            }
        }
        if (H(s32, 0x6A0) >= 5) {
            func_L19_004F32A0(6, 1);
            H(s16, 0x204) = 0x19;
        }
        break;
    case 0x17:
        if (H(f32, 0xC18) > 12.0f) {
            func_L19_004F32A0(0x18, 0);
        }
        break;
    case 0x18:
        if ((H(s32, 0xC08) & 2) && (F(H(u8 *, 0x25C0), u8, 0x43) == 0x20)) {
            func_L01_0050FB40(0x21, 0, 4.0f);
        }
        func_L01_004EE850(0, 1.0f);
        if (func_L01_004E8318((s8 *)(D_001A4BE0 + 0x80), (s8 *)(D_001A4BE0 + 0x90), 0) == 0) {
            func_L19_004F32A0(6, 1);
            H(s16, 0x1D0) = 8;
            break;
        }
        if (((H(f32, 0x2838) > 0.5f) && (func_L01_004606E8(func_003A3BB8(0x40, 0), 7, 0, 0) != 0) && (func_0038DBA0(H(f32, 0x1A0), H(f32, 0x98)) > 2.3561945f)) || (F(D_001D52FC, s32, 0x1A4) & func_003A3BB8(8, 0))) {
            func_L19_004F32A0(6, 1);
            H(s8, 0x25F0) = 1;
            H(s16, 0x1D0) = 8;
            break;
        }
        if (func_L01_004606E8(func_003A3BB8(0x40, 0), 0xE, 0, 0) != 0) {
            func_L19_004F32A0(0x1B, 1);
            break;
        }
        if (H(f32, 0x2838) > 0.5f) {
            if (func_0038DBA0(H(f32, 0x1A0), func_0038DAB8(H(f32, 0x98), 1.5707964f)) < 0.7853982f) {
                qcopy(v10, D_001A4BE0 + 0x80);
                v10[0] += func_0038D098(func_0038DAB8(H(f32, 0x98), 1.5707964f)) * 0.3f;
                v10[1] += func_0038D0B0(func_0038DAB8(H(f32, 0x98), 1.5707964f)) * 0.3f;
                if (func_L01_004E8318((s8 *)v10, (s8 *)(D_001A4BE0 + 0x90), 0) != 0) {
                    func_L19_004F32A0(0x19, 1);
                }
                break;
            }
        }
        if (H(f32, 0x2838) > 0.5f) {
            if (func_0038DBA0(H(f32, 0x1A0), func_0038DAB8(H(f32, 0x98), -1.5707964f)) < 0.7853982f) {
                qcopy(v10, D_001A4BE0 + 0x80);
                v10[0] += func_0038D098(func_0038DAB8(H(f32, 0x98), -1.5707964f)) * 0.3f;
                v10[1] += func_0038D0B0(func_0038DAB8(H(f32, 0x98), -1.5707964f)) * 0.3f;
                if (func_L01_004E8318((s8 *)v10, (s8 *)(D_001A4BE0 + 0x90), 0) != 0) {
                    func_L19_004F32A0(0x1A, 1);
                }
            }
        }
        break;
    case 0x19:
    case 0x1A:
    {
        f32 side;
        qcopy(v10, D_001A4BE0 + 0x80);
        side = 1.5707964f;
        if (H(u32, 0x25C4) == 0x1A) {
            side = -1.5707964f;
        }
        v10[0] += func_0038D098(func_0038DAB8(H(f32, 0x98), side)) * 0.3f;
        v10[1] += func_0038D0B0(func_0038DAB8(H(f32, 0x98), side)) * 0.3f;
        func_L01_004EE850(0, 1.0f);
        if ((H(f32, 0x2838) < 0.5f) || (func_0038DBA0(H(f32, 0x1A0), func_0038DAB8(H(f32, 0x98), side)) > 0.7853982f) || (func_L01_004E8318((s8 *)v10, (s8 *)(D_001A4BE0 + 0x90), 0) == 0)) {
            if (H(s32, 0xC08) & 2) {
                func_L19_004F32A0(0x18, 1);
                break;
            }
        }
        if ((H(f32, 0x2838) > 0.5f) && (func_L01_004606E8(func_003A3BB8(0x40, 0), 7, 0, 0) != 0) && (func_0038DBA0(H(f32, 0x1A0), H(f32, 0x98)) > 2.3561945f)) {
            func_L19_004F32A0(6, 1);
            H(s8, 0x25F0) = 1;
            H(s16, 0x1D0) = 0x21;
            break;
        }
        if (func_L01_004606E8(func_003A3BB8(0x40, 0), 7, 0, 0) != 0) {
            func_L19_004F32A0(0x1B, 1);
        }
        break;
    }
    case 0x7B:
        if (H(s32, 0x1B8) >= 0xFB) {
            func_L01_004EDE10();
        }
        if (H(u8, 0x147C) == 0) {
            if (H(s16, 0x36E) != 0) {
                func_L19_004F32A0(6, 1);
            } else {
                func_L19_004F32A0(0, 1);
            }
        }
        break;
    case 0x6:
    case 0x2C:
        if ((H(s32, 0x25C8) == 0) && ((H(s32, 0x1B8) >= 0xF) || (H(f32, 0x33C) > 1.75f))) {
            func_L01_0050FB40(0xB, 0, 13.0f);
            H(s32, 0x25C8) = 1;
            if (H(u32, 0x25C4) == 0x2C) {
                H(s32, 0x280C) = 7;
            } else {
                H(s32, 0x280C) = 0;
            }
        }
        if (H(s16, 0x36E) == 0) {
            func_L01_004E1180();
            if (H(f32, 0x118) < -0.18f) {
                H(f32, 0x118) = -0.18f;
            }
            if (H(f32, 0xF8) < -0.18f) {
                H(f32, 0xF8) = -0.18f;
            }
            if (H(s32, 0x2850) <= 0) {
                func_L19_004F32A0(0x39, 1);
            } else {
                s32 one = 1;
                s32 low = H(s32, 0x35C) == 0;
                if (H(s32, 0x1B8) >= 0x4B) {
                    if (func_L19_004F32A0(0, 0) != 0) {
                        func_L01_0050FB40(0xC, 4, 5.0f);
                    }
                    if (low != 0) {
                        H(s16, 0x1E0) = 0x12;
                    }
                    func_L01_00510CA0(0xA, 4, 0, 1, 0.022f, 0.004f);
                } else if (H(s32, 0x25C8) == one) {
                    if (func_L19_004F32A0(0, 0) != 0) {
                        func_L01_0050FB40(0xC, 9, -1.0f);
                    }
                    func_L01_00511508(D_001A4BE0 + 0x160, D_001A4BE0 + 0x160, 0.0f);
                    func_003C4BB0((f32 *)(D_001A4BE0 + 0x160), 0.14000002f);
                    H(s16, 0x1E0) = 6;
                    if (H(s32, 0x25D0) == 0x2C) {
                        H(s16, 0x1E0) = 8;
                    }
                    if ((low != 0) && (H(s32, 0x1B8) >= 0x2B)) {
                        H(s16, 0x1E0) = 0xF;
                    }
                    func_L01_00510CA0(0xA, 2, 0, 1, 0.019f, 0.002f);
                } else if ((H(f32, 0x2838) > 0.5f) && (H(s16, 0x1E0) == 0)) {
                    func_L19_004F32A0(2, 1);
                    func_L01_00510CA0(7, 2, 0, 1, 0.016f, 0.002f);
                } else if (H(f32, 0x174) > 0.060000002f) {
                    if (func_L19_004F32A0(3, 0) != 0) {
                        func_L01_0050FB40(6, 0, 10.0f);
                        func_003C4BB0((f32 *)(D_001A4BE0 + 0x160), 0.15400001f);
                    }
                } else {
                    func_L19_004F32A0(0, 1);
                    func_L01_00510CA0(5, 2, 0, 1, 0.016f, 0.002f);
                }
            }
        } else if (H(s32, 0x2850) > 0) {
            if ((F(D_001D52FC, s32, 0x1A0) & func_003A3BB8(0x40, 0)) && (D_00142CA0[2] != 0) && (func_L01_004E9238(3) != 4) && (H(s16, 0x2884) == 0) && (H(s16, 0x1E0) == 0) && (H(f32, 0x33C) > 0.6f)) {
                func_L19_004F32A0(8, 1);
                break;
            }
            if ((H(s16, 0x202) >= 0x22) && (func_L01_00506298((H(s16, 0x1EE) != 0) ? 1 : 5, 0) != 0)) {
                break;
            }
            if (H(s32, 0x528) != 0) {
                func_L19_004F32A0(0x17, 1);
                break;
            }
            if (H(s32, 0x5DC) != 0) {
                func_L19_004F32A0(0x27, 1);
                break;
            }
            if (H(s32, 0x69C) != 0) {
                func_L19_004F32A0(0x76, 1);
                break;
            }
        }
        break;
    case 0x79:
        if (H(s32, 0x1B8) < 0x65) {
            break;
        }
        func_L01_004EDE10();
        return;
    case 0xB0:
        if (H(f32, 0x33C) < 3.0f) {
            func_L19_004F32A0(8, 1);
        }
        break;
    case 0x8:
        if ((H(s32, 0x1D4) != 0) && (H(s32, 0x1B8) < 7)) {
            s32 prev = H(s32, 0x25D0);
            s32 ok = 0;
            if ((prev == 7) || (prev == 9) || (prev == 0xE) || (prev == 0x11)) {
                ok = 1;
            }
            if (ok != 0) {
                func_L19_004F32A0(0x11, 1);
            }
            break;
        }
        if ((H(s32, 0x1B8) >= 0x1A) && (H(s16, 0x22C) == 0) && !(F(D_001D52FC, s32, 0x1A0) & func_003A3BB8(0x40, 0)) && !(F(D_001D52FC, s32, 0x1C0) & func_003A3BB8(0x40, 0))) {
            func_L19_004F32A0(6, 1);
            break;
        }
        if (H(s32, 0x528) != 0) {
            func_L19_004F32A0(0x17, 1);
            break;
        }
        if ((H(s16, 0x36E) != 0) && !(H(f32, 0x33C) < 0.4f)) {
            break;
        }
        if (H(s32, 0x1B8) < 8) {
            H(s16, 0x1EE) = 0xA - H(u16, 0x1B8);
        }
        func_L01_004EE850(0, 1.0f);
        if ((H(s32, 0x25D0) == 0x10) && (H(s32, 0x1B8) < 3)) {
            if (func_L19_004F32A0(3, 0) != 0) {
                func_L01_0050FB40(5, 0, -1.0f);
                H(s16, 0x1E0) = 0x1C;
            }
            break;
        }
        if (F(D_001D52FC, s32, 0x1A0) & func_003A3BB8(8, 0)) {
            func_L19_004F32A0(4, 1);
            func_L01_00510CA0(5, 2, 0, 1, 0.016f, 0.002f);
            break;
        }
        if ((D_L19_001DBD4C < H(f32, 0x1B0)) && (func_0038DBA0(H(f32, 0x1A0), H(f32, 0x98)) < 1.5707964f)) {
            if ((H(u8, 0x1474) != 0) || (H(u8, 0x25EA) != 0)) {
                func_L19_004F32A0(2, 1);
                break;
            }
            func_L19_004F32A0(2, 0);
            if (H(u32, 0x25C4) == 2) {
                H(s32, 0x25C8) = 1;
                func_L01_0050FB40(4, 2, 7.0f);
                H(s8, 0x3EE) = 1;
            }
            func_L01_00510CA0(5, 2, 1, 0, 0.016f, 0.002f);
        } else if (D_L19_001DBD4C < H(f32, 0x1B0)) {
            if ((H(u8, 0x1474) != 0) || (H(u8, 0x25EA) != 0)) {
                func_L19_004F32A0(2, 1);
                break;
            }
            func_L19_004F32A0(2, 0);
            if (H(u32, 0x25C4) == 2) {
                H(s32, 0x25C8) = 1;
                func_L01_0050FB40(4, D_L19_001DBD74, 10.0f);
            }
            func_L01_00510CA0(5, 2, 1, 0, 0.016f, 0.002f);
        } else if (H(s16, 0x36E) == 0) {
            if (func_L19_004F32A0(0, 0) != 0) {
                func_L01_0050FB40(func_L01_004DFDB0(0), 0, -2.0f);
                func_L01_00510CA0(5, 2, 0, 1, 0.016f, 0.002f);
            }
        } else if (func_L19_004F32A0(0, 0) != 0) {
            func_L01_0050FB40(7, 0x17, 7.0f);
            func_L01_00510CA0(5, 2, 0, 1, 0.016f, 0.002f);
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
    case 0x6B:
    case 0x73:
    case 0x86:
    {
        s32 near;
        s16 lo;
        s32 now;
        u32 sa;
        u32 sc;
        s32 lim;
        s32 frames;
        if (H(u8, 0x4FE) != 0) {
            s32 n = func_L01_004FF5D8();
            if ((n > 0) && ((H(s32, 0x1B8) < n) || (H(u8, 0x46C) != 0)) && (H(s32, 0x360) != 0)) {
                if ((H(u32, 0x25C4) != 0xB) || (func_L01_004606E8(func_003A3BB8(0x40, 0), 6, 0, 0) != 0)) {
                    s32 go = 1;
                    if ((H(u32, 0x25C4) == 0x1B) || (H(u8, 0x46C) != 0)) {
                        if (func_L01_004606E8(func_003A3BB8(0x40, 0), 6, 0, 0) == 0) {
                            go = 0;
                        }
                    }
                    if (H(u32, 0x25C4) == 0xB) {
                        if (H(u8, 0x46C) == 0) {
                            go = 0;
                        }
                    }
                    if ((go != 0) && (func_L01_004606E8(0x1F000, 4, 0, 0) != 0) && (F(D_001D52FC, s32, 0x1A0) & func_003A3BB8(8, 0))) {
                        func_L19_004F32A0(0xB, 1);
                        break;
                    }
                }
            }
        }
        if ((H(u32, 0x25C4) == 0x1B) && (H(s32, 0x1B8) >= 0xC) && (H(f32, 0x298) > 1.3f)) {
            H(s8, 0x25F0) = 0;
            H(s8, 0x25ED) = 0;
        }
        if ((H(s32, 0x1B8) < 2) && (func_L01_004606E8(func_003A3BB8(8, 0), 2, 0, 0) != 0) && ((sa = H(u32, 0x25C4)) != 0x10) && (sa != 0xA) && (sa != 0x12) && (sa != 0x38) && (sa != 0x11) && (sa != 0xE) && (sa != 0x6B)) {
            if ((func_L01_004E9238(3) == 2) && (D_00142CA0[2] != 0) && (H(s16, 0x2884) == 0) && (H(f32, 0x178) > 0.018000001f)) {
                func_L19_004F32A0(0xA, 1);
            } else if ((func_L01_004E9238(3) == 3) && (H(s16, 0x2884) == 0) && (H(f32, 0x178) > 0.018000001f) && (H(s16, 0x1E4) == 0)) {
                func_L19_004F32A0(0x10, 1);
            }
        }
        if (H(s32, 0x5DC) != 0) {
            func_L19_004F32A0(0x27, 1);
            break;
        }
        if (H(s32, 0x69C) != 0) {
            func_L19_004F32A0(0x76, 1);
            break;
        }
        if (H(s16, 0x4EA) < H(s32, 0x1B8)) {
            if (H(u8, 0x46C) == 0) {
                func_L19_004F32A0(6, 1);
                break;
            }
        } else if ((H(u8, 0x46C) == 0) && ((H(u32, 0x25C4) == 0xA) || (H(u32, 0x25C4) == 0x10)) && (H(f32, 0x298) < 0.9f) && (H(u8, 0x2A7) != 0) && (func_0038CEA8(D_001A4BE0 + 0xF0) > 0.14000002f)) {
            f32 a = func_0038CEA8(D_001A4BE0 + 0x110);
            if ((a < func_0038CEA8(D_001A4BE0 + 0xF0) * 0.5f) && (H(s32, 0x528) == 0) && (H(f32, 0x33C) < 2.0f)) {
                func_L01_004F4ED0(0x19);
                func_L19_004F32A0(0x7C, 1);
                break;
            }
        }
        near = 0;
        if ((H(u32, 0x25C4) == 0xE) && (H(f32, 0xC18) < 35.0f)) {
            near = 1;
        }
        lo = H(s16, 0x47C);
        now = H(s32, 0x1B8);
        if (!(lo < now)) {
            break;
        }
        if (now == lo + 1) {
            if (H(u8, 0x46D) != 0) {
                f32 left = (f32)(H(s32, 0x400) - now);
                if (left > 0.0f) {
                    func_L01_004E5030(H(f32, 0x408), left, H(f32, 0x4E4), -1.0f);
                }
            } else if (H(u32, 0x25C4) != 0xE) {
                func_L01_00511748((f32 *)(D_001A4BE0 + 0x80), (f32 *)(D_001A4BE0 + 0xF0), &sp94, H(f32, 0x4F0));
                func_L01_004E5030(H(f32, 0x498), (f32)sp94, H(f32, 0x4E4), -1.0f);
                if (H(f32, 0xC00) > 1.5f) {
                    H(f32, 0xC00) = 1.5f;
                }
            }
            break;
        }
        if ((H(u8, 0x46D) != 0) && (now >= H(s32, 0x400)) && (now < H(s32, 0x404))) {
            f32 left = (f32)(H(s32, 0x410) - H(s32, 0x400));
            if (left > 0.0f) {
                func_L01_004E5030(H(f32, 0x498), left, H(f32, 0x4E4), -1.0f);
            }
            break;
        }
        if (H(s32, 0x358) == 1) {
            func_L01_004F4E70(0xC, 0);
            func_L01_004E5EB8(3, 0x18, 1);
        }
        {
            u8 c = H(u8, 0x46C);
            if (c != 0) {
                H(u8, 0x46C) = c + 1;
            } else if ((H(s16, 0x36E) == 0) && (H(u8, 0x46E) != 0) && (near == 0)) {
                func_L01_004E1180();
                H(u8, 0x46C) = 1;
                H(s8, 0x285F) = 0;
                if ((H(f32, 0x2838) < 0.2f) && (H(f32, 0x1B4) > 0.050000004f)) {
                    H(f32, 0x1B4) = 0.050000004f;
                }
                func_L01_00510CA0(5, 2, 0, 1, 0.016f, 0.002f);
                if (near == 0) {
                    s32 k = (s32)H(f32, 0x4A0) + 2;
                    if (H(f32, 0xC18) < H(f32, 0x49C) - 1.5f) {
                        func_L01_0050FB40(func_L01_004DFE80(F(cur, u8, 0x43)), k, 6.0f);
                    }
                }
            }
        }
        if (H(u8, 0x46C) != 0) {
            H(f32, 0xC00) = 1.0f;
        } else if (H(u8, 0x46E) != 0) {
            u32 st9;
            if ((s32)F(cur, u8, 0x41) < (s32)H(f32, 0x4A0)) {
                if ((H(u32, 0x25C4) == 0xE) && (H(f32, 0xC18) < 37.0f)) {
                    func_003C4138((f32 *)(D_001A4BE0 + 0xC00), 1.0f, 0.21600002f);
                } else {
                    H(s16, 0x47E) = (s32)func_L19_00501FE0(60.0f, H(f32, 0x4F0), -1.0f);
                    func_L01_004E5030(H(f32, 0x49C), (f32)H(s16, 0x47E), H(f32, 0x4E4), 0.28800002f);
                }
                if (near == 0) {
                    s32 k = (s32)H(f32, 0x4A0) + 2;
                    if (H(f32, 0xC00) > 1.8f) {
                        func_L01_0050FB40(func_L01_004DFE80(F(cur, u8, 0x43)), k, (f32)(H(s16, 0x47E) + 3));
                    }
                }
                if (H(f32, 0xC00) < 0.2f) {
                    H(f32, 0xC00) = 0.2f;
                }
                if (H(f32, 0xC00) > 2.7f) {
                    H(f32, 0xC00) = 2.7f;
                }
            }
            st9 = H(u32, 0x25C4);
            if ((st9 == 9) && ((H(f32, 0x49C) - H(f32, 0xC18)) > 6.0f) && ((func_L01_004DFE80(F(cur, u8, 0x42)) == 8) || (func_L01_004DFE80(F(cur, u8, 0x42)) == st9)) && (F(cur, u8, 0x42) == F(cur, u8, 0x43)) && (H(f32, 0x1B0) < D_L19_001DBD58 * 0.020000001f * 0.1f) && (H(f32, 0x174) < 0.050000004f)) {
                f32 rate = 7.0f / H(f32, 0xC00);
                s32 at;
                if (rate > 8.0f) {
                    rate = 8.0f;
                }
                at = (s32)H(f32, 0xC18) + 4;
                func_L01_0050FB40(7, at / 2, rate);
                H(s32, 0x25C4) = 7;
            }
            if ((s32)H(f32, 0xC18) == (s32)H(f32, 0x49C)) {
                H(s32, 0xC00) = 0;
            }
        }
        if (H(u8, 0x46C) != 0) {
            if (H(u32, 0x25C4) == 0xA) {
                if (func_L19_004F32A0(3, 0) != 0) {
                    func_L01_0050FB40(5, 0, -2.0f);
                    func_0038CE20(D_001A4BE0 + 0x160, D_001A4BE0 + 0x160, 0.8f);
                }
                break;
            }
            if ((H(u8, 0x147C) == 0) && (H(s16, 0x1E0) == 0) && (func_L01_004606E8(func_003A3BB8(0x40, 0), 7, 0, 0) != 0) && (H(s16, 0x36E) < 7)) {
                if (((H(s16, 0x1434) != 0) || ((H(s32, 0x16B0) == 1) && (func_L01_004606E8(0x28, 2, 0, 0) != 0))) && (H(f32, 0x2838) > 0.9f) && (func_L01_004FF610() != 2)) {
                    func_L19_004F32A0(0xB, 1);
                } else if (!(H(f32, 0x1B0) > D_L19_001DBD4C)) {
                    func_L19_004F32A0(7, 1);
                } else if (!(func_0038DBA0(H(f32, 0x1A0), H(f32, 0x98)) < 1.0471976f)) {
                    func_L19_004F32A0(7, 1);
                } else if (D_L19_001DBD58 * 0.020000001f * 0.85f < H(f32, 0x174)) {
                    func_L19_004F32A0(9, 1);
                } else {
                    func_L19_004F32A0(7, 1);
                }
                break;
            }
        }
        if ((H(u8, 0x46C) >= 2) && (H(u32, 0x25C4) != 0xA)) {
            func_L01_00506BB0();
        } else if ((H(u8, 0x46E) != 0) && (H(s32, 0x1B8) >= H(s16, 0x4FA)) && (H(f32, 0x33C) > H(f32, 0x4E0))) {
            func_L19_004F32A0(6, 1);
        }
        if ((H(u32, 0x25C4) == 0x10) && (H(s32, 0x1B8) >= 0x33) && (H(f32, 0x33C) > 1.5f)) {
            func_L19_004F32A0(6, 1);
            break;
        }
        {
            u32 s = H(u32, 0x25C4);
            s32 ok = 0;
            if ((s == 7) || (s == 9) || (s == 0x11)) {
                ok = 1;
            }
            if ((H(s32, 0x1D4) != 0) && (H(u8, 0x46C) == 0) && (ok != 0) && ((H(u32, 0x25C4) != 0x11) || (H(s32, 0x1B8) >= 0x16)) && (func_L01_004606E8(func_003A3BB8(0x40, 0), 6, &sp98, 0) != 0) && (sp98 < H(s32, 0x1B8))) {
                func_L19_004F32A0(0x11, 1);
                break;
            }
        }
        if (((H(u32, 0x25C4) == 0xA) || (H(u32, 0x25C4) == 0x10)) && (H(s32, 0x1B8) >= 0x16) && (H(s16, 0x36A) != 0)) {
            H(s16, 0x4F6) = 0x11;
        }
        sc = H(u32, 0x25C4);
        lim = 0x11;
        if (sc == 0x10) {
            lim = 7;
        }
        if ((sc == 0xE) && (H(f32, 0x33C) > 4.0f)) {
            if ((H(u8, 0x46E) == 0) && (H(f32, 0xC00) < 1.3f)) {
                func_003C4138((f32 *)(D_001A4BE0 + 0xC00), 1.3f, 0.120000005f);
            }
            lim = 0xE;
            H(s16, 0x4F6) = lim;
        }
        frames = H(s32, 0x1B8) - 4;
        if (frames <= 1) {
            frames = 2;
        }
        if (frames >= 0x1A) {
            frames = 0x19;
        }
        if (!(H(long, 0x468) & 0xFF0000FF00000000L)) {
            if ((func_L01_004606E8(func_003A3BB8(0x40, 0), frames, 0, 0) != 0) || (H(u32, 0x25C4) == 0xE) || (H(u32, 0x25C4) == 0xF) || (H(u32, 0x25C4) == 0xD)) {
                if ((H(u32, 0x25C4) != 0xE) && (H(u8, 0x25E9) == 0) && ((H(u8, 0x147C) == 0) || !(H(f32, 0x33C) < 0.4f)) && (H(u8, 0x4FF) != 0) && (H(s32, 0x1B8) >= 0xD) && ((H(u8, 0x46E) == 0) || ((H(f32, 0x33C) > 0.7f) && (fabs_asm(func_L01_005114B0((s8 *)(D_001A4BE0 + 0xF0))) < 0.11600001f)))) {
                    func_L19_004F32A0(0xE, 1);
                } else if ((D_00142CA0[2] != 0) && (func_L01_004E9238(3) != 4) && (H(s16, 0x2884) == 0) && (F(D_001D52FC, s32, 0x1A0) & func_003A3BB8(0x40, 0)) && (lim < H(s32, 0x1B8)) && (H(s16, 0x4F6) < H(s32, 0x1B8))) {
                    f32 need = 0.6f;
                    if ((H(u32, 0x25C4) == 9) || (H(u32, 0x25C4) == 7)) {
                        need = 1.0f;
                    }
                    if (H(u32, 0x25C4) == 0xE) {
                        need = 1.5f;
                    }
                    if (need < H(f32, 0x33C)) {
                        func_L19_004F32A0(8, 1);
                    }
                }
            }
        }
        if ((H(s32, 0x528) != 0) && (H(u32, 0x25C4) != 0xB)) {
            func_L19_004F32A0(0x17, 1);
        }
        break;
    }
    case 0xB1:
        if (H(s32, 0x1B8) < 0x22) {
            break;
        }
        if (H(s32, 0x2850) <= 0) {
            func_L19_004F32A0(0x39, 1);
        } else {
            func_L19_004F32A0(0, 1);
        }
        break;
    case 0x16:
        if ((H(f32, 0xC18) > 12.5f) && (H(u8, 0x2877) == 0) && (H(s16, 0x36E) != 0) && (H(f32, 0x33C) > 1.0f)) {
            if (H(s32, 0x25D0) == 0xB0) {
                if (H(s32, 0x2850) <= 0) {
                    func_L19_004F32A0(0x79, 1);
                } else {
                    func_L19_004F32A0(0xB0, 0);
                    func_L01_0050FB40(0x7A, 0, 9.0f);
                }
            } else {
                func_L19_004F32A0(6, 1);
            }
            break;
        }
        if (H(s32, 0x1B8) >= 0x17) {
            if (H(s32, 0x2850) <= 0) {
                if (H(u8, 0x1477) != 0) {
                    func_L19_004F32A0(0x7E, 1);
                } else if (H(s32, 0x25D0) == 0xB0) {
                    func_L19_004F32A0(0x79, 1);
                } else {
                    func_L19_004F32A0(0x39, 1);
                }
            } else if (H(u8, 0x2877) != 0) {
                func_L19_004F32A0(0x87, 1);
            } else if (H(s32, 0x25D0) == 0xB0) {
                func_L19_004F32A0(0xB0, 1);
            } else {
                func_L19_004F32A0(0, 0);
            }
        }
        break;
    case 0x91:
        if (H(s32, 0xC08) & 2) {
            func_L01_0050FB40(0x75, 0, 2.0f);
        }
        if ((H(s32, 0x1B8) >= 0x2B) && (H(s16, 0x1E0) == 0)) {
            if (H(s32, 0x2850) <= 0) {
                func_L19_004F32A0(0x39, 1);
            } else if (func_L19_004F32A0(0, 0) != 0) {
                func_L01_0050FB40(func_L01_004DFDB0(0), 0, 11.0f);
            }
        }
        break;
    case 0x3F:
    {
        s16 t = H(s16, 0x28A8);
        if (t >= 0x24) {
            func_L01_0050FB40(0x12, 0, 8.0f);
            break;
        }
        if ((t == 0) && (H(s32, 0xC08) & 2)) {
            if (F(H(u8 *, 0x25C0), u8, 0x43) != func_L01_004DFDB0(0)) {
                func_L01_0050FB40(func_L01_004DFDB0(0), 0, 10.0f);
            } else if (func_003824E0(0.0f, 1.0f) < 0.15f) {
                func_L01_0050FB40(0x15, 0, 7.0f);
            }
        }
        if (H(u8, 0x147C) != 0) {
            func_L19_004F32A0(0x4E, 1);
            break;
        }
        if ((F(D_001D52FC, s32, 0x1A0) & func_L01_00512DF8(func_003A3BB8(4, 0)))
            && ((H(u8, 0x25E4) != 0) || (D_001439F4[0] != 2) || (H(s32, 0x1228) == 0x6F))
            && (func_L01_003EB2D8(0) == 0)) {
            func_L19_004F32A0(1, 1);
            break;
        }
        if (H(s16, 0x36E) != 0) {
            func_L19_004F32A0(0x41, 1);
            break;
        }
        if (func_L01_004606E8(func_003A3BB8(0x40, 0), 7, 0, 0) != 0) {
            func_L19_004F32A0(0x45, 1);
            break;
        }
        if (func_L01_004606E8(0x80, 7, 0, 0) != 0) {
            func_L19_004F32A0(0x4D, 1);
            break;
        }
        func_L01_004EE850(0, 1.0f);
        if ((H(f32, 0x2838) > 0.2f) && (H(f32, 0x1B0) > 0.0f)) {
            func_L19_004F32A0(0x40, 1);
            break;
        }
        if ((H(s16, 0x28A8) == 0) && (F(H(u8 *, 0x25C0), u8, 0x43) == 0x12)) {
            func_L01_0050FB40(func_L01_004DFDB0(0), 0, 10.0f);
        }
        break;
    }
    case 0x4D:
    {
        u8 *rec;
        s32 frames;
        if (H(u8, 0x147C) != 0) {
            func_L19_004F32A0(0x4E, 1);
            break;
        }
        rec = (u8 *)&D_L19_002F8BD0[H(s16, 0xBDC)];
        if (H(s32, 0xC0C) == 0) {
            s32 busy;
            if ((f32)F(rec, s32, 0x18) < H(f32, 0xC18)) {
                func_L19_004F32A0(0x3F, 0);
            }
            busy = H(s32, 0xC0C);
            if ((busy == 0) && ((f32)F(rec, s32, 0x10) <= H(f32, 0xC18))) {
                s32 n = (s32)H(f32, 0xC18) - F(rec, s32, 0xC);
                if (n < 1) {
                    n = 1;
                }
                if (func_L01_004606E8(0x80, (n < 0xD) ? n : 0xC, 0, 0) != 0) {
                    func_L19_004F32A0(0x4D, 1);
                }
            }
        }
        frames = ((s32)H(f32, 0xC18) - F(rec, s32, 0xC)) * 2;
        if (((f32)F(rec, s32, 0x14) < H(f32, 0xC18)) && (H(s32, 0xC0C) == 0) && (func_L01_004606E8(func_003A3BB8(0x40, 0), frames, 0, 0) != 0)) {
            func_L19_004F32A0(0x45, 1);
        }
        break;
    }
    case 0x45:
    case 0x48:
    {
        s16 lo = H(s16, 0x47C);
        s32 now = H(s32, 0x1B8);
        if (!(lo < now)) {
            break;
        }
        if (now == lo + 1) {
            func_L01_00511748((f32 *)(D_001A4BE0 + 0x80), (f32 *)(D_001A4BE0 + 0xF0), &sp9C, H(f32, 0x4F0));
            func_L01_004E5030(H(f32, 0x498), (f32)sp9C, H(f32, 0x4E4), 0.36f);
            break;
        }
        if ((H(u8, 0x46D) != 0) && (now >= H(s32, 0x400)) && (now < H(s32, 0x404))) {
            f32 left = (f32)(H(s32, 0x410) - H(s32, 0x400));
            if (left > 0.0f) {
                func_L01_004E5030(H(f32, 0x498), left, H(f32, 0x4E4), -1.0f);
            }
            break;
        }
        {
            u8 c = H(u8, 0x46C);
            if (c != 0) {
                H(u8, 0x46C) = c + 1;
            } else if ((H(s16, 0x36E) == 0) && (H(u8, 0x46E) != 0)) {
                s32 k;
                H(u8, 0x46C) = 1;
                k = (s32)H(f32, 0x4A0) + 3;
                if (H(f32, 0xC18) < H(f32, 0x49C)) {
                    func_L01_0050FB40(F(cur, u8, 0x43), k, 5.0f);
                }
            }
        }
        if (H(u8, 0x46C) != 0) {
            H(f32, 0xC00) = 1.0f;
        } else if (H(u8, 0x46E) != 0) {
            if ((s32)F(cur, u8, 0x41) < (s32)H(f32, 0x4A0)) {
                s32 k;
                H(s16, 0x47E) = (s32)func_L19_00501FE0(60.0f, H(f32, 0x4F0), -1.0f);
                func_L01_004E5030(H(f32, 0x49C), (f32)H(s16, 0x47E), H(f32, 0x4E4), -1.0f);
                k = (s32)H(f32, 0x4A0) + 1;
                if (H(f32, 0xC00) > 1.8f) {
                    func_L01_0050FB40(F(cur, u8, 0x43), k, (f32)(H(s16, 0x47E) + 2));
                }
                if (H(f32, 0xC00) < 0.2f) {
                    H(f32, 0xC00) = 0.2f;
                }
                if (H(f32, 0xC00) > 2.7f) {
                    H(f32, 0xC00) = 2.7f;
                }
            }
            if ((s32)H(f32, 0xC18) == (s32)H(f32, 0x49C)) {
                H(s32, 0xC00) = 0;
            }
        }
        if ((H(u8, 0x46C) != 0) && (H(s16, 0x1E0) == 0) && (H(u8, 0x147C) == 0) && (func_L01_004606E8(func_003A3BB8(0x40, 0), 3, 0, 0) != 0) && (H(s16, 0x36E) < 3)) {
            func_L01_004EE850(0, 1.0f);
            func_L19_004F32A0(0x45, 1);
            break;
        }
        if (H(u8, 0x46C) >= 2) {
            H(s32, 0x280C) = 0;
            func_L01_004EE850(0, 1.0f);
            if ((H(f32, 0x1B0) > D_L19_001DBD4C) && (H(f32, 0x2838) > 0.5f) && (H(u8, 0x147C) == 0) && (H(s16, 0x1E0) == 0) && (func_0038DBA0(H(f32, 0x1A0), H(f32, 0x98)) < 1.5707964f)) {
                func_L19_004F32A0(0x40, 1);
            } else if (H(u8, 0x46C) >= 0xB) {
                func_L19_004F32A0(0x3F, 1);
            }
        }
        if ((H(f32, 0x33C) > 2.0f) && (H(u8, 0x46E) != 0) && (H(s32, 0x1B8) >= 0x22)) {
            func_L19_004F32A0(0x41, 1);
            break;
        }
        if ((H(u8, 0x46E) != 0) && (H(f32, 0x33C) < 0.2f) && (func_L01_004606E8(0x80, 4, 0, 0) != 0)) {
            func_L19_004F32A0(0x4D, 1);
            break;
        }
        if (H(s32, 0x528) != 0) {
            func_L19_004F32A0(0x46, 1);
            break;
        }
        if ((H(u32, 0x25C4) != 0x48) && (func_L01_004606E8(func_003A3BB8(0x40, 0), 4, 0, 0) != 0) && (H(f32, 0x33C) > 0.55f)) {
            func_L19_004F32A0(0x4B, 1);
        }
        break;
    }
    case 0x4B:
        if ((H(s32, 0x1B8) >= 0x1A) && !(F(D_001D52FC, s32, 0x1A0) & func_003A3BB8(0x40, 0))) {
            func_L19_004F32A0(0x41, 1);
            break;
        }
        if (H(s32, 0x528) != 0) {
            func_L19_004F32A0(0x46, 1);
            break;
        }
        if ((H(s16, 0x36E) != 0) && !((H(f32, 0x88) - H(f32, 0x338)) < 0.0f)) {
            break;
        }
        if (H(s32, 0x1B8) < 8) {
            H(s16, 0x1EE) = 0xA - H(u16, 0x1B8);
        }
        if (H(f32, 0x2838) > 0.3f) {
            func_L19_004F32A0(0x40, 1);
            break;
        }
        if (H(s16, 0x36E) == 0) {
            func_L19_004F32A0(0x3F, 1);
        }
        break;
    case 0x4F:
        if (H(f32, 0xC18) > 23.0f) {
            func_L19_004F32A0(0x3F, 0);
            func_L01_0050FB40(0x21, 7, 4.0f);
        }
        break;
    case 0x41:
        if (H(s16, 0x36E) == 0) {
            if (H(f32, 0x118) < -0.18f) {
                H(f32, 0x118) = -0.18f;
            }
            if (H(f32, 0xF8) < -0.18f) {
                H(f32, 0xF8) = -0.18f;
            }
            if (H(s32, 0x2850) <= 0) {
                func_L19_004F32A0(0x43, 1);
            } else if (H(f32, 0x2838) > 0.5f) {
                if (H(s16, 0x1E0) == 0) {
                    func_L19_004F32A0(0x40, 1);
                } else {
                    func_L19_004F32A0(0x3F, 1);
                }
            } else {
                func_L19_004F32A0(0x3F, 1);
            }
        } else if (H(s32, 0x2850) > 0) {
            if (H(s32, 0x528) != 0) {
                func_L19_004F32A0(0x46, 1);
                break;
            }
            if ((func_L01_004606E8(func_003A3BB8(0x40, 0), 4, 0, 0) != 0) && (H(f32, 0x33C) > 0.6f)) {
                func_L19_004F32A0(0x4B, 1);
            }
        }
        break;
    case 0x44:
        if ((H(f32, 0xF8) < 0.0f) && (H(s32, 0x360) != 0)) {
            func_L19_004F32A0(0x3F, 1);
        }
        break;
    case 0x4E:
        if (H(s32, 0x1B8) >= 0xFB) {
            func_L01_004EDE10();
        }
        if (H(u8, 0x147C) == 0) {
            if (H(s16, 0x36E) != 0) {
                func_L19_004F32A0(0x41, 1);
            } else {
                func_L19_004F32A0(0x3F, 1);
            }
        }
        break;
    case 0x40:
    {
        f32 speed;
        u8 *o;
        s32 anim;
        if (H(u8, 0x147C) != 0) {
            func_L19_004F32A0(0x4E, 1);
            break;
        }
        if ((H(s32, 0xC0C) == 0) && (H(f32, 0x170) < 0.033000004f) && (F(o = H(u8 *, 0x25C0), u8, 0x43) != 0x19)) {
            u8 *info = F(o, u8 *, 0x24);
            s32 n = F(F(info, u8 *, 0xAC), u8, 0x10);
            func_L01_0050FB40(0x19, (F(o, u8, 0x41) * n / F(F(info, u8 *, 0xB0), u8, 0x10) + 1) % n, 7.0f);
        } else if ((H(s32, 0xC0C) == 0) && (H(f32, 0x170) > 0.039600007f) && (F(o = H(u8 *, 0x25C0), u8, 0x43) != 0x1A)) {
            u8 *info = F(o, u8 *, 0x24);
            s32 n = F(F(info, u8 *, 0xB0), u8, 0x10);
            func_L01_0050FB40(0x1A, (F(o, u8, 0x41) * n / F(F(info, u8 *, 0xAC), u8, 0x10) + 7) % n, 7.0f);
        }
        speed = H(f32, 0x170);
        if (H(u8, 0x3EF) != 0) {
            speed = 0.06600001f;
        }
        anim = F(H(u8 *, 0x25C0), u8, 0x43);
        if (anim == 0x19) {
            H(f32, 0xC00) = speed * 75.0f;
        } else if (anim == 0x1A) {
            H(f32, 0xC00) = speed * 16.666666f;
        }
        if (H(f32, 0xC00) < 0.57f) {
            H(f32, 0xC00) = 0.57f;
        }
        if (func_L01_004606E8(func_003A3BB8(0x40, 0), 7, 0, 0) != 0) {
            func_L19_004F32A0(0x45, 1);
            break;
        }
        if (func_L01_004606E8(0x80, 7, 0, 0) != 0) {
            func_L19_004F32A0(0x4D, 1);
            break;
        }
        if ((H(s16, 0x36E) >= 4) && ((H(f32, 0x33C) > 0.8f) || (H(f32, 0x340) > 0.87266463f))) {
            func_L19_004F32A0(0x41, 1);
            break;
        }
        if ((H(s16, 0x36E) == 0) && (H(f32, 0x2838) < 0.17f)) {
            func_L19_004F32A0(0x3F, 1);
        }
        break;
    }
    case 0x42:
        if ((H(s32, 0x1B8) >= 0x1B) && (H(s16, 0x36E) != 0) && (H(f32, 0x33C) > 1.0f)) {
            func_L19_004F32A0(0x41, 1);
            break;
        }
        if (H(s32, 0x1B8) >= 0x16) {
            if (H(s32, 0x2850) <= 0) {
                func_L19_004F32A0(0x43, 1);
            } else {
                func_L19_004F32A0(0x3F, 0);
            }
        }
        break;
    case 0x46:
        if (H(s32, 0xC08) & 2) {
            func_L19_004F32A0(0x47, 1);
        }
        break;
    case 0x47:
        func_L01_004EE850(0, 1.0f);
        qcopy(v10, D_001A4BE0 + 0x80);
        if (func_L01_004E8318((s8 *)v10, (s8 *)(D_001A4BE0 + 0x90), 0) == 0) {
            func_L19_004F32A0(0x41, 1);
            H(s16, 0x1D0) = 8;
            break;
        }
        if (((H(f32, 0x2838) > 0.5f) && (func_L01_004606E8(func_003A3BB8(0x40, 0), 7, 0, 0) != 0) && (func_0038DBA0(H(f32, 0x1A0), H(f32, 0x98)) > 2.3561945f)) || (F(D_001D52FC, s32, 0x1A0) & func_003A3BB8(8, 0))) {
            func_L19_004F32A0(0x41, 1);
            H(s16, 0x1D0) = 8;
            break;
        }
        if (func_L01_004606E8(func_003A3BB8(0x40, 0), 7, 0, 0) != 0) {
            func_L19_004F32A0(0x48, 1);
            break;
        }
        if (H(f32, 0x2838) > 0.5f) {
            if (func_0038DBA0(H(f32, 0x1A0), func_0038DAB8(H(f32, 0x98), 1.5707964f)) < 0.7853982f) {
                qcopy(v20, D_001A4BE0 + 0x80);
                v20[0] += func_0038D098(func_0038DAB8(H(f32, 0x98), 1.5707964f)) * 0.3f;
                v20[1] += func_0038D0B0(func_0038DAB8(H(f32, 0x98), 1.5707964f)) * 0.3f;
                if (func_L01_004E8318((s8 *)v20, (s8 *)(D_001A4BE0 + 0x90), 0) != 0) {
                    func_L19_004F32A0(0x49, 1);
                }
                break;
            }
        }
        if (H(f32, 0x2838) > 0.5f) {
            if (func_0038DBA0(H(f32, 0x1A0), func_0038DAB8(H(f32, 0x98), -1.5707964f)) < 0.7853982f) {
                qcopy(v20, D_001A4BE0 + 0x80);
                v20[0] += func_0038D098(func_0038DAB8(H(f32, 0x98), -1.5707964f)) * 0.3f;
                v20[1] += func_0038D0B0(func_0038DAB8(H(f32, 0x98), -1.5707964f)) * 0.3f;
                if (func_L01_004E8318((s8 *)v20, (s8 *)(D_001A4BE0 + 0x90), 0) != 0) {
                    func_L19_004F32A0(0x4A, 1);
                }
            }
        }
        break;
    case 0x49:
    case 0x4A:
    {
        f32 side;
        qcopy(v10, D_001A4BE0 + 0x80);
        side = 1.5707964f;
        if (H(u32, 0x25C4) == 0x4A) {
            side = -1.5707964f;
        }
        v10[0] += func_0038D098(func_0038DAB8(H(f32, 0x98), side)) * 0.3f;
        v10[1] += func_0038D0B0(func_0038DAB8(H(f32, 0x98), side)) * 0.3f;
        func_L01_004EE850(0, 1.0f);
        if ((H(f32, 0x2838) < 0.5f) || (func_0038DBA0(H(f32, 0x1A0), func_0038DAB8(H(f32, 0x98), side)) > 0.7853982f) || (func_L01_004E8318((s8 *)v10, (s8 *)(D_001A4BE0 + 0x90), 0) == 0)) {
            if (H(s32, 0xC08) & 2) {
                func_L19_004F32A0(0x47, 1);
                break;
            }
        }
        if ((H(f32, 0x2838) > 0.5f) && (func_L01_004606E8(func_003A3BB8(0x40, 0), 7, 0, 0) != 0) && (func_0038DBA0(H(f32, 0x1A0), H(f32, 0x98)) > 2.3561945f)) {
            func_L19_004F32A0(0x41, 1);
            H(s16, 0x1D0) = 0x21;
            break;
        }
        if (func_L01_004606E8(func_003A3BB8(0x40, 0), 7, 0, 0) != 0) {
            func_L19_004F32A0(0x48, 1);
        }
        break;
    }
    case 0x51:
        if (H(s32, 0xC08) & 2) {
            if (F(H(u8 *, 0x25C0), u8, 0x43) != 1) {
                func_L01_0050FB40(1, 0, 10.0f);
            } else if (func_003824E0(0.0f, 1.0f) < 0.5f) {
                func_L01_0050FB40(2, 0, 7.0f);
            }
        }
        if ((F(D_001D52FC, s32, 0x1A0) & func_L01_00512DF8(func_003A3BB8(4, 0)))
            && ((H(u8, 0x25E4) != 0) || (D_001439F4[0] != 2) || (H(s32, 0x1228) == 0x6F))
            && (func_L01_003EB2D8(0) == 0)) {
            func_L19_004F32A0(1, 1);
            break;
        }
        if (H(s16, 0x36E) != 0) {
            func_L19_004F32A0(0x53, 1);
            break;
        }
        if (H(s16, 0x1E0) != 0) {
            break;
        }
        if (func_L01_004606E8(func_003A3BB8(0x40, 0), 7, 0, 0) != 0) {
            func_L19_004F32A0(0x54, 1);
            break;
        }
        if (F(D_001D52FC, s32, 0x1A4) & 0x20) {
            func_L19_004F32A0(0x59, 1);
            break;
        }
        if (func_L01_004606E8(0x80, 6, 0, 0) != 0) {
            if (H(s16, 0x288C) == 0) {
                H(s16, 0x2888) = 1;
                H(s16, 0x288C) = 0x12;
                H(s16, 0x288A) = 1;
            }
            func_L01_004EC600(0);
            break;
        }
        func_L01_004EE850(0, 1.0f);
        if (!(H(f32, 0x2838) > 0.22f)) {
            break;
        }
        if (H(f32, 0x1B0) > 0.0f) {
            func_L19_004F32A0(0x52, 1);
        }
        break;
    case 0x57:
        if (H(s32, 0x1B8) >= 0xFB) {
            func_L01_004EDE10();
        }
        if (H(u8, 0x147C) == 0) {
            if (H(s16, 0x36E) != 0) {
                func_L19_004F32A0(0x53, 1);
            } else {
                func_L19_004F32A0(0x51, 1);
            }
        }
        break;
    case 0x59:
        if ((H(s32, 0x1B8) >= 0x26) && !(F(D_001D52FC, s32, 0x1A0) & 0x20)) {
            func_L19_004F32A0(0x51, 0);
            func_L01_0050FB40(1, 0, 17.0f);
            break;
        }
        if (func_L01_004606E8(func_003A3BB8(0x40, 0), 7, 0, 0) != 0) {
            func_L19_004F32A0(0x54, 1);
        }
        break;
    case 0x58:
        H(u8, 0x25ED) = 1;
        break;
    case 0x54:
    {
        s16 lo = H(s16, 0x47C);
        s32 now = H(s32, 0x1B8);
        if (!(lo < now)) {
            break;
        }
        if (now == lo + 1) {
            func_L01_00511748((f32 *)(D_001A4BE0 + 0x80), (f32 *)(D_001A4BE0 + 0xF0), &spA0, H(f32, 0x4F0));
            func_L01_004E5030(H(f32, 0x498), (f32)spA0, H(f32, 0x4E4), 0.36f);
            break;
        }
        if ((H(u8, 0x46D) != 0) && (now >= H(s32, 0x400)) && (now < H(s32, 0x404))) {
            f32 left = (f32)(H(s32, 0x410) - H(s32, 0x400));
            if (left > 0.0f) {
                func_L01_004E5030(H(f32, 0x498), left, H(f32, 0x4E4), -1.0f);
            }
            break;
        }
        {
            u8 c = H(u8, 0x46C);
            if (c != 0) {
                H(u8, 0x46C) = c + 1;
            } else if ((H(s16, 0x36E) == 0) && (H(u8, 0x46E) != 0)) {
                s32 k;
                H(u8, 0x46C) = 1;
                k = (s32)H(f32, 0x4A0) + 3;
                if (H(f32, 0xC18) < H(f32, 0x49C)) {
                    func_L01_0050FB40(F(cur, u8, 0x43), k, 5.0f);
                }
            }
        }
        if (H(u8, 0x46C) != 0) {
            H(f32, 0xC00) = 1.0f;
        } else if (H(u8, 0x46E) != 0) {
            if ((s32)F(cur, u8, 0x41) < (s32)H(f32, 0x4A0)) {
                s32 k;
                H(s16, 0x47E) = (s32)func_L19_00501FE0(60.0f, H(f32, 0x4F0), -1.0f);
                func_L01_004E5030(H(f32, 0x49C), (f32)H(s16, 0x47E), H(f32, 0x4E4), -1.0f);
                k = (s32)H(f32, 0x4A0) + 1;
                if (H(f32, 0xC00) > 1.8f) {
                    func_L01_0050FB40(F(cur, u8, 0x43), k, (f32)(H(s16, 0x47E) + 2));
                }
                if (H(f32, 0xC00) < 0.2f) {
                    H(f32, 0xC00) = 0.2f;
                }
                if (H(f32, 0xC00) > 2.7f) {
                    H(f32, 0xC00) = 2.7f;
                }
            }
            if ((s32)H(f32, 0xC18) == (s32)H(f32, 0x49C)) {
                H(s32, 0xC00) = 0;
            }
        }
        if ((H(u8, 0x46C) != 0) && (H(s16, 0x1E0) == 0) && (H(u8, 0x147C) == 0) && (func_L01_004606E8(func_003A3BB8(0x40, 0), 3, 0, 0) != 0) && (H(s16, 0x36E) < 3)) {
            func_L01_004EE850(0, 1.0f);
            func_L19_004F32A0(0x54, 1);
            break;
        }
        if (H(u8, 0x46C) >= 2) {
            H(s32, 0x280C) = 0;
            func_L01_004EE850(0, 1.0f);
            if ((H(f32, 0x1B0) > D_L19_001DBD4C) && (H(f32, 0x2838) > 0.5f) && (H(u8, 0x147C) == 0) && (H(s16, 0x1E0) == 0) && (func_0038DBA0(H(f32, 0x1A0), H(f32, 0x98)) < 1.5707964f)) {
                func_L19_004F32A0(0x52, 1);
            } else if (H(u8, 0x46C) >= 0xB) {
                func_L19_004F32A0(0x51, 1);
            }
        }
        if ((H(f32, 0x33C) > 2.0f) && (H(u8, 0x46E) != 0) && (H(s32, 0x1B8) >= 0x22)) {
            func_L19_004F32A0(0x53, 1);
        }
        break;
    }
    case 0x53:
        if (H(s16, 0x36E) == 0) {
            if (H(f32, 0x118) < -0.18f) {
                H(f32, 0x118) = -0.18f;
            }
            if (H(f32, 0xF8) < -0.18f) {
                H(f32, 0xF8) = -0.18f;
            }
            if (H(s32, 0x2850) <= 0) {
                func_L19_004F32A0(0x56, 1);
            } else if ((H(f32, 0x2838) > 0.5f) && (H(s32, 0x1B8) < 0x21) && (H(s16, 0x1E0) == 0)) {
                func_L19_004F32A0(0x52, 1);
            } else {
                func_L19_004F32A0(0x51, 0);
                func_L01_0050FB40(0x16, 0, -1.0f);
                H(f32, 0xC00) = 0.35f;
                H(s16, 0x1E0) = 0x11;
            }
        }
        break;
    case 0x52:
        H(f32, 0xC00) = H(f32, 0x170) * D_L19_001DBC90;
        if (H(f32, 0xC00) < 1.0f) {
            H(f32, 0xC00) = 1.0f;
        }
        if ((H(s16, 0x36E) >= 4) && ((H(f32, 0x33C) > 0.8f) || (H(f32, 0x340) > 0.87266463f))) {
            func_L19_004F32A0(0x53, 1);
            break;
        }
        if (H(s16, 0x1E0) != 0) {
            func_L19_004F32A0(0x51, 1);
        }
        if (func_L01_004606E8(func_003A3BB8(0x40, 0), 7, 0, 0) != 0) {
            func_L19_004F32A0(0x54, 1);
            break;
        }
        if (func_L01_004606E8(0x80, 6, 0, 0) != 0) {
            if (H(s16, 0x288C) == 0) {
                H(s16, 0x2888) = 1;
                H(s16, 0x288C) = 0x12;
                H(s16, 0x288A) = 1;
            }
            func_L01_004EC600(0);
            break;
        }
        if (F(D_001D52FC, s32, 0x1A4) & 0x20) {
            func_L19_004F32A0(0x59, 1);
            break;
        }
        if ((H(s16, 0x36E) == 0) && (H(f32, 0x2838) < 0.17f)) {
            func_L19_004F32A0(0x51, 1);
        }
        break;
    case 0x55:
        if ((H(s32, 0x1B8) >= 0x1B) && (H(s16, 0x36E) != 0) && (H(f32, 0x33C) > 1.0f)) {
            func_L19_004F32A0(0x53, 1);
            break;
        }
        if (H(s32, 0xC08) & 2) {
            func_L19_004F32A0(0x51, 1);
            break;
        }
        if (H(s32, 0x1B8) >= 0x26) {
            if (H(s32, 0x2850) <= 0) {
                func_L19_004F32A0(0x56, 1);
            } else {
                func_L19_004F32A0(0x51, 0);
            }
        }
        break;
    case 0x1D:
        if ((H(u8, 0x25E4) == 0) && ((H(u8, 0x25EB) == 0) || (H(u8, 0x25E5) != 0))) {
            if (F(D_001D52FC, s32, 0x1A0) & func_003A3BB8(8, 0)) {
                func_L01_0050FB40(0xD, 0, 7.0f);
            } else {
                func_L01_0050FB40(func_L01_004DFDB0(1), 0, 7.0f);
            }
        }
        if (!(F(D_001D52FC, s32, 0x1A0) & func_003A3BB8(4, 0))) {
            if (H(u32, 0x25C4) == 0x1D) {
                s32 anim;
                func_L19_004F32A0(0, 0);
                anim = func_L01_004DFDB0(1);
                if (F(H(u8 *, 0x25C0), u8, 0x43) != anim) {
                    func_L01_0050FB40(anim, 0, 7.0f);
                }
            }
            D_L19_001D60F8 = 0;
        }
        break;
    case 0x22:
        if (H(f32, 0xC18) > 19.0f) {
            if (func_L01_004606E8(func_003A3BB8(0x40, 0), 9, 0, 0) != 0) {
                if (F(D_001D52FC, s32, 0x1A0) & func_003A3BB8(8, 0)) {
                    func_L01_00506E30();
                    break;
                }
                func_L19_004F32A0(7, 1);
                break;
            }
        }
        if (H(f32, 0xC18) >= 21.0f) {
            func_L19_004F32A0(0, 0);
        }
        break;
/*NEXT*/
    default:
        break;
    }
end:
    if (state0 != H(s32, 0x25CC)) {
        func_L01_004E1560();
    }
    {
        s32 prev = H(s32, 0x25D0);
        if (((prev == 0x3C) && (H(s32, 0x25C4) != 0x3D)) || ((prev == 0x3D) && (H(s32, 0x1A04) != 0))) {
            func_L01_00506820();
        }
    }
    if (sub0 != H(s32, 0x25C8)) {
        H(s32, 0x1C0) = 0;
    }
    if (anim0 != F(cur, u8, 0x43)) {
        H(s32, 0x1C4) = 0;
    }
}

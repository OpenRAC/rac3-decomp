#include "common.h"

#include "vu0.h"

/* localdecomp:start func_L09_00518BB8 */
/* func_L09_00518BB8: the hero's state decider (Tyhrranosis), a 178-way switch on the state at D_001A4BE0+0x25C4
   (Opus family B, 2026-11-08; built from retail and the rac2 decider twins, case bodies in retail's order).
   The file needs @ps2as and its div.s padding row (config/levels/divs_nops.txt). The tuning floats at
   0x1DBxxx are read as a small-data array (docs/GLOBALS.md); abs.s is fabs_asm() at every site (vu0.h). */
typedef int u128_t __attribute__((mode(TI)));
typedef u128_t s128;
#define NULL ((void *)0)
#define FLD(base, T, off) (((struct { u8 pad[off]; T v; } *)(base))->v)
extern u8 *D_001D52FC;
__asm__(".extern D_001D52FC, 16");
extern u8 D_001425C0[];
extern char D_001A4BE0[];
extern u8 D_00143A06[];
extern u8 D_00142CA2[];
extern f32 D_L09_001DBD50;
__asm__(".extern D_L09_001DBD50, 4");
extern f32 D_L09_001DBE0C[] __attribute__((section(".sdata")));
__asm__(".extern D_L09_001DBE0C, 16");
extern s32 D_L09_001DBE34;
__asm__(".extern D_L09_001DBE34, 16");
extern s32 D_L09_001D6740;
__asm__(".extern D_L09_001D6740, 16");
extern s32 D_L09_001D673C;
__asm__(".extern D_L09_001D673C, 16");
extern u8 D_001439F4[];
extern f32 D_L09_001DFD30;
__asm__(".extern D_L09_001DFD30, 16");
extern s32 D_L09_002D1E70[];
extern s32 D_L09_001DFC48;
extern u8 D_L09_001D60F8;
extern s32 D_L09_001DBCD0[2];
__asm__(".extern D_L09_001DBCD0, 8");
extern s32 D_L09_001DBCE0[2];
__asm__(".extern D_L09_001DBCE0, 8");
extern s32 D_L09_001DBE30[2];
__asm__(".extern D_L09_001DBE30, 8");
extern char D_L09_002F4BF0[];
extern char D_L09_002F4E00[];
typedef struct { s32 w[11]; } Rec2C;
extern Rec2C D_L09_002F6B90[];
extern char D_L09_002C5E80[];
extern char D_L09_001E2C00[];
s32 func_002761F8(void *, void *, s32, void *, s32);
s32 func_00277258(void *, s32, void *, f32);
s32 func_00388398(void *);
s32 func_003883C8(s16 *);
void func_00282CC0(void *, void *, void *);
void func_003886E8(void *, void *, f32);
f32 func_00388770(void *);
f32 func_00282E20(void *);
f32 func_003887A0(void *);
f32 func_003887C8(void *, void *);
f32 func_00388800(void *, void *);
void func_00282F20(void *, void *, f32);
f32 func_00388960(f32);
f32 func_00388978(f32);
f32 func_00389380(f32 a0, f32 a1);
f32 func_00389468(f32 a0, f32 a1);
void func_0038EB10(s32, s32, void *, void *, void *, s32, s32);
void func_0038F3A0(u8 *object);
void func_0038F3F8(s8 *);
s32 func_0038FDC0(s8 *);
void func_00394F48(void *a0);
void func_00394F90(u8 *object);
void func_00395478();
void func_003BDA38(s8 *a0, s32 a1, s8 *a2);
void func_003BE4F0(u8 *object, s32 animation, s32 frame, s32 rate);
s32 func_0037E208(s32 a0, s32 a1);
f32 func_0037E250(f32 a0, f32 a1);
f32 func_003BEBF8(f32 *value, f32 target, f32 step);
void func_003BF640(f32 *, f32);
s32 func_0039E928(s32 a0, s32 a1);
s32 func_L01_0050EE20(s32 a0);
s32 func_L02_004B21A8(s32 arg);
u32 func_L01_004DC1A0(u32 param_1);
void func_L01_004DD470(void);
void func_L01_004DD4B0(s32 kind, s32 side, s32 play_sound, s32 duration);
void func_L01_004DD850(void);
void func_L01_004E1268(f32 arg0, f32 arg1, f32 arg2, f32 arg3);
void func_L01_004E20F0(s32 dust, s32 debris, s32 model);
s32 func_L01_004E2628(f32 *out, f32 scale, f32 amount);
s32 func_L02_004B9D90(s8 *, s8 *, s8 *);
s32 func_L01_004E5470(s32 index);
void func_L01_004E6CB0(void);
void func_L01_004EA040(void);
s32 func_L01_004EA1D8(u8 *object);
s32 func_L01_0050FF18(void);
s32 func_L01_004EA1F8(f32 x);
s32 func_L00_002B3998(f32 value);
void func_L01_004EAA78(s32, f32);
void func_L01_004EADD0(void);
s32 func_L01_004F1068(s32 index, s32 flags);
s32 func_L01_004FB720(void);
s32 func_L01_004FB758(void);
void func_L01_004F10C8(s32);
void func_L01_004E8830(s32);
s32 func_L09_00512408(s32, s32);
void func_L02_004D31B8(s32 a0);
s32 func_L01_00500F98(void);
s32 func_L01_00501048(void);
s32 func_L01_005010B8(void);
s32 func_L01_00501678(void);
s32 func_L01_00502368(s32 arg0, s32 arg1);
void func_L01_005024B8(void);
void func_L01_005028C8(void);
s32 func_L01_00502930(s32 *selected);
void func_L01_00502C58(void);
s32 func_L01_00502ED8(void);
s32 func_L01_00503188(void);
s32 func_L01_00503310(void);
void func_L01_00503428(void);
void func_L01_00503668(void);
void func_L01_005037C0(void);
void func_L01_0050B3C0(void);
void func_L01_0050BB98(s32 a0, s32 a1, f32 f12);
void func_L01_0050BF28(void);
void func_L01_0050BF40(s32 value);
f32 func_L01_0050C4A0(f32 time, f32 acceleration, f32 height);
void func_L01_0050CCC8(s16, u8, u8, u8, f32, f32);
void func_L00_002D36E0(f32 *p, s32 flag, f32 x, f32 y, f32 z);
f32 func_L01_0050D4D8(s8 *in);
void func_L01_0050D530(void *dst, void *src, f32 k);
f32 func_L01_0050D770(f32 *a0, f32 *a1, s32 *out, f32 scale);
void func_003DFF90(s32 argument);
void func_003DF7C0(s32 argument);
f32 func_L00_0031B9F8(f32 *a0, f32 *a1, s32 *a2, f32 factor);
f32 func_L00_0031CDD0(f32 *a, f32 *b, f32 *out, f32 d, f32 e);
void func_L01_00452F40(u8 *entity, s32 enabled);
s32 func_L01_0045D358(s32 mask, s32 arg1, s32 a2, s32 a3);
void func_002E59F8(s32 a0);
void *func_L01_0046A9C8(s8 *object,void *position,f32 *velocity,s32 *config,s32 flag);
s32 func_L00_00341820(void *path, void *out, s32 *index, f32 *offset, s32 wrap, f32 step);
s32 func_L00_00341FA8(void *, void *, void *, s32 *, f32 *, s32, f32, f32, f32);
void func_L00_0038B888(void *position,s32 count);
s32 func_L01_003E9428(s32);
s32 func_L02_004BEC88(s32);
s32 func_L00_002AD868(s8 *, void **, s128 *, void *, void *, s32 *, void *, s32, s32);

void func_L18_002C4000(void);
void func_L09_00518BB8(void) {
    f32 v10[4] __attribute__((aligned(16)));
    f32 v20[4] __attribute__((aligned(16)));
    f32 v30[4] __attribute__((aligned(16)));
    s32 sp30;
    s32 sp34;
    s32 sp38;
    s32 sp3C;
    s32 sp40;
    u8 *hero;
    s32 mode;
    s32 sub;
    s32 anim;
    s32 sel;

    hero = FLD(D_001A4BE0, u8 *, 0x25C0);
    mode = FLD(D_001A4BE0, s32, 0x25CC);
    sub = FLD(D_001A4BE0, s32, 0x25C8);
    anim = FLD(hero, u8, 0x43);
    if (FLD(D_001A4BE0, s32, 0x234) != 0) {
        func_L02_004BEC88(0);
    } else if (func_L02_004BEC88(1) != 0) {
        goto end;
    }
    func_L01_00503428();
    if ((FLD(D_001A4BE0, s32, 0x2850) <= 0) && ((FLD(D_001A4BE0, s32, 0x25C4) == 0) || (FLD(D_001A4BE0, s32, 0x25C4) == 2))) {
        func_L09_00512408(0x39, 1);
        goto end;
    }
    if (func_L01_00501678() != 0) {
        goto end;
    }
    if ((func_L01_005010B8() != 0) || (func_L01_00501048() != 0) || (func_L01_00500F98() != 0)) {
        goto end;
    }
    if (((FLD(D_001D52FC, s32, 0x1A4) & 0x10) || (FLD(D_001D52FC, s32, 0x1C4) & 0x10)) && (FLD(D_001A4BE0, u8, 0x121C) != 2)
        && (D_L09_002D1E70[0] == 0) && (D_00143A06[0] == 0) && (D_L09_001DFC48 >= 8) && (FLD(D_001A4BE0, s32, 0x25C4) != 0x58)) {
        if (((FLD(D_001A4BE0, u8, 0x25ED) == 0) || (FLD(D_001A4BE0, u8, 0x25E4) == 1) || (FLD(D_001A4BE0, s16, 0x1D2) != 0))
            && ((FLD(D_001A4BE0, u8, 0x25E8) == 0) || (FLD(D_001A4BE0, u8, 0x25E4) == 1) || (FLD(D_001A4BE0, s16, 0x1D2) != 0))
            && ((FLD(D_001A4BE0, u8, 0x25E4) == 0) || (FLD(D_001A4BE0, u8, 0x25E4) == 3))) {
            if (FLD(D_001A4BE0, s16, 0x2882) != 0) {
                FLD(D_001A4BE0, s16, 0x287E) = 0x1B;
            } else {
                FLD(D_001A4BE0, s16, 0x287E) = 0xF;
            }
            func_0038EB10(0x23, 0, func_0038F3A0, func_0038F3F8, func_0038FDC0, 0, 0);
            func_003DF7C0(0x168);
            func_003DFF90(0xB4);
        }
    }
    func_L01_00503668();
    func_L01_005037C0();
    if ((FLD(D_001A4BE0, f32, 0x88) < D_L09_001DFD30) && (FLD(D_001A4BE0, f32, 0x33C) > 2.0f) && (FLD(D_001A4BE0, u8, 0x25E4) != 2)
        && (FLD(D_001A4BE0, s32, 0x25C4) != 0x79)) {
        func_L09_00512408(0x79, 1);
        goto end;
    }
    switch (FLD(D_001A4BE0, u32, 0x25C4)) {
    case 0x0:
    {
        s32 notcrouch;
        s32 cur;
        u8 *obj;
        if ((FLD(D_001D52FC, s32, 0x1A0) & func_L01_0050EE20(func_0039E928(4, 0)))
            && ((FLD(D_001A4BE0, u8, 0x25E4) != 0) || (D_001439F4[0] != 2) || (FLD(D_001A4BE0, s32, 0x1228) == 0x6F))
            && (func_L01_003E9428(0) == 0)) {
            func_L09_00512408(1, 1);
            goto end;
        }
        func_L01_0050BF28();
        if (FLD(D_001A4BE0, u8, 0x2877) != 0) {
            func_L09_00512408(0x87, 1);
            goto end;
        }
        notcrouch = FLD(D_001A4BE0, u8, 0x1474) == 0;
        {
        s32 one = 1;
        FLD(D_001A4BE0, s8, 0x1436) = 0;
        if (FLD(D_001A4BE0, s32, 0x1314) == 2) {
            obj = FLD(D_001A4BE0, u8 *, 0x12F0);
            if ((obj != NULL) && (FLD(obj, u8, 0x60) & 2) && (FLD(obj, u8, 0x43) != one)) {
                func_003BE4F0(obj, one, 0, 7);
            }
            obj = FLD(D_001A4BE0, u8 *, 0x12F4);
            if ((obj != NULL) && (FLD(obj, u8, 0x60) & 2) && (FLD(obj, u8, 0x43) != 1)) {
                func_003BE4F0(obj, 1, 0, 7);
            }
        }
        }
        if ((FLD(D_L09_002F4E00, f32, 0x258) > 0.61086524f) || (FLD(D_L09_002F4E00, f32, 0x254) > 0.43633232f)) {
            obj = FLD(D_001A4BE0, u8 *, 0x12F0);
            if ((obj != NULL) && (FLD(obj, u8, 0x43) != 1)) {
                func_003BE4F0(obj, 1, 0, 0xC);
            }
            obj = FLD(D_001A4BE0, u8 *, 0x12F4);
            if ((obj != NULL) && (FLD(obj, u8, 0x43) != 1)) {
                func_003BE4F0(obj, 1, 0, 0xC);
            }
        }
        cur = func_L01_004DC1A0(FLD(hero, u8, 0x43));
        if ((cur == func_L02_004B21A8(0)) && notcrouch && (FLD(D_001A4BE0, s32, 0x1228) != 0x12)) {
            if (func_L01_00502930(&sp30) != 0) {
                u8 *rec;
                FLD(D_001A4BE0, s16, 0x208) = 0x78;
                FLD(D_001A4BE0, s32, 0x27F8) = sp30;
                rec = D_L09_002F4BF0 + sp30 * 0x70;
                FLD(rec, s32, 0x60) = FLD(rec, f32, 0x5C) * 60.0f;
                if (FLD(rec, s32, 0x44) != 0) {
                    func_L09_00512408(0x3C, 1);
                } else {
                    func_L01_0050BB98(FLD(rec, s32, 0x48), 0, 12.0f);
                }
            }
        } else if (FLD(D_001A4BE0, s32, 0xC08) & 2) {
            s32 keep = 0;
            if ((FLD(D_001A4BE0, u8, 0x25E9) != 0) && (FLD(D_001A4BE0, u8, 0x25EB) != 0) && ((FLD(FLD(D_001A4BE0, u8 *, 0x25C0), u8, 0x43) == FLD(D_001A4BE0, s32, 0x2830)) || (FLD(D_001A4BE0, s32, 0xE78) != 0))) {
                keep = 1;
            }
            if (keep == 0) {
                FLD(D_001A4BE0, s8, 0x25E9) = 0;
                if (func_L02_004B21A8(0) == 0x4A) {
                    func_L01_0050BB98(func_L02_004B21A8(0), 0, 18.0f);
                } else {
                    func_L01_0050BB98(func_L02_004B21A8(0), 0, -2.0f);
                }
            }
        }
        if (FLD(D_001A4BE0, s32, 0x1B8) >= 11) {
            u8 *o2 = FLD(D_001A4BE0, u8 *, 0x12F4);
            if ((o2 != NULL) && (FLD(o2, u8, 0x43) == 1) && (func_00388398(D_001A4BE0 + 0x2870) != 0) && (FLD(D_L09_002F4E00, f32, 0x258) < 0.55850536f) && (FLD(D_L09_002F4E00, f32, 0x254) < 0.34906584f) && (FLD(D_001A4BE0, s32, 0x1314) == 2)) {
                FLD(D_001A4BE0, s32, 0x2870) = func_0037E208(0x6E, 0x10E);
                func_L01_0050B3C0();
            }
        }
        if ((FLD(D_001A4BE0, u8, 0x25E9) != 0) && (FLD(D_001A4BE0, s32, 0xC0C) == 0) && (FLD(D_001A4BE0, u8, 0x25EB) != 0) && (FLD(D_001A4BE0, s16, 0x2874) == 0)
            && ((D_001439F4[0] != 1) || (fabs_asm(FLD(D_001A4BE0, f32, 0x15A0)) < 0.17453292f))) {
            s32 idx = func_L01_004E5470(0);
            if (idx != FLD(D_001A4BE0, s32, 0x2834)) {
                func_L01_004E6CB0();
            } else {
                s32 a = FLD(D_L09_002C5E80 + D_001425C0[idx] * 0xF0, s32, 0x24);
                if (FLD(FLD(D_001A4BE0, u8 *, 0x25C0), u8, 0x43) != a) {
                    if (FLD(D_001A4BE0, s32, 0xE78) != 0) {
                        FLD(D_001A4BE0, s32, 0xE84) = 1;
                    }
                    FLD(D_001A4BE0, s32, 0x2830) = a;
                    func_L01_0050BB98(a, 0, -4.0f);
                }
            }
        }
        func_L01_004EAA78(0, 1.0f);
        if ((FLD(D_001A4BE0, u8, 0x147C) != 0) && (FLD(D_001A4BE0, s16, 0x36C) == 0)) {
            func_L09_00512408(0x7B, 1);
            goto end;
        }
        if ((FLD(D_001A4BE0, s16, 0x36E) >= 5) && (FLD(D_001A4BE0, f32, 0x33C) > 0.4f)) {
            if ((FLD(D_001A4BE0, s32, 0x25D0) != 8) || (FLD(D_001A4BE0, s32, 0x1B8) >= 0xF)) {
                func_L09_00512408(6, 1);
                goto end;
            }
            break;
        }
        if (FLD(D_001A4BE0, s16, 0x1E0) != 0) {
            break;
        }
        {
            s32 ok = 1;
            if ((FLD(D_001A4BE0, s32, 0x25D0) == 1) || (FLD(D_001A4BE0, s32, 0x25D0) == 0x1D)) {
                if (FLD(D_001A4BE0, s32, 0x1B8) <= 4) {
                    ok = 0;
                }
            }
            if (ok && (FLD(D_001A4BE0, s16, 0x368) != 1)) {
                if (func_L01_00502368((FLD(D_001A4BE0, s16, 0x1EE) != 0) ? 1 : 7, 0) != 0) {
                    break;
                }
            }
        }
        if ((FLD(D_001A4BE0, s16, 0x368) == 1) && (D_L09_001D6740 == 0) && (func_L01_0045D358(func_0039E928(0x40, 0), 7, 0, 0) != 0)) {
            func_L09_00512408(0x73, 1);
            goto end;
        }
        if ((FLD(D_001D52FC, s32, 0x1A0) & func_0039E928(8, 0)) && (FLD(D_001A4BE0, s32, 0x360) != 0)) {
            if ((FLD(FLD(D_001A4BE0, u8 *, 0x25C0), u8, 0x43) != 0x1A) || !(FLD(D_001A4BE0, f32, 0xC18) < 108.0f)) {
                func_L09_00512408(4, 1);
                goto end;
            }
        }
        if ((FLD(D_001A4BE0, u8, 0x1474) != 0) && (FLD(D_001A4BE0, f32, 0x340) > 0.08726646f)) {
            func_L09_00512408(0x2E, 1);
            goto end;
        }
        {
            s32 go = 1;
            s32 turned;
            if (((FLD(D_001A4BE0, s32, 0x25D0) == 1) || (FLD(D_001A4BE0, s32, 0x25D0) == 0x1D)) && (FLD(D_001A4BE0, s32, 0x1B8) < 0x18) && (FLD(D_001A4BE0, s16, 0x368) != 1)) {
                func_L01_004EAA78(0, 1.0f);
                if ((func_00389468(FLD(D_001A4BE0, f32, 0x1A0), FLD(D_L09_001E2C00, f32, 0x18)) > 1.2217305f) && (func_003887C8(D_001A4BE0 + 0x80, D_L09_001E2C00) < 2.5f)) {
                    go = 0;
                }
            }
            turned = func_L01_004EA1F8(0.17453292f);
            if (go == 0) {
                break;
            }
            if ((turned != 0) || (FLD(D_001A4BE0, f32, 0x2838) > 0.22f)) {
                s32 side = FLD(D_001A4BE0, u8, 0x147F);
                func_L01_004DD4B0(side, 0, 0, 0x1E);
                func_L01_004DD4B0(side, 1, 0, 0x1E);
                func_L09_00512408(2, 1);
                goto end;
            }
        }
        break;
    }
    case 0x3C:
        if ((FLD(D_001D52FC, s32, 0x1A0) & func_L01_0050EE20(func_0039E928(4, 0))) && ((FLD(D_001A4BE0, u8, 0x25E4) != 0) || (D_001439F4[0] != 2) || (FLD(D_001A4BE0, s32, 0x1228) == 0x6F)) && (func_L01_003E9428(0) == 0)) {
            func_L09_00512408(1, 1);
            break;
        }
        if ((FLD(D_001A4BE0, s16, 0x36E) != 0) || (FLD(D_001D52FC, s32, 0x1A0) & func_0039E928(0x40, 0)) || (FLD(D_001D52FC, s32, 0x1A0) & func_0039E928(8, 0))) {
            func_L09_00512408(0x3D, 1);
            break;
        }
        func_L01_004EADD0();
        if (FLD(D_001A4BE0, f32, 0x1B0) > 0.0f) {
            func_L09_00512408(0x3D, 1);
            break;
        }
        if (FLD(D_001A4BE0, s32, 0xC08) & 2) {
            func_L01_005028C8();
            func_L09_00512408(0, 1);
        }
        break;

    case 0x3D:
        if (FLD(D_001A4BE0, s32, 0x1B8) < 9) {
            break;
        }
        func_L01_005028C8();
        if (FLD(D_001A4BE0, s16, 0x36E) != 0) {
            func_L09_00512408(6, 1);
            break;
        }
        if (func_L01_00502368(7, 0) != 0) {
            break;
        }
        if (FLD(D_001D52FC, s32, 0x1A0) & func_0039E928(8, 0)) {
            func_L09_00512408(4, 1);
            break;
        }
        func_L01_004EADD0();
        if (FLD(D_001A4BE0, f32, 0x1B0) > 0.0f) {
            func_L09_00512408(2, 1);
            break;
        }
        func_L09_00512408(0, 1);
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
        if ((FLD(D_001A4BE0, s32, 0xC08) & 2) || (FLD(D_001A4BE0, u8, 0x25F1) != 0)) {
            if (FLD(D_001A4BE0, s16, 0x21E) != 0) {
                FLD(D_001A4BE0, u8, 0x25F1) = 1;
                FLD(D_001A4BE0, s32, 0xC00) = 0;
                func_003883C8(D_001A4BE0 + 0x21E);
                return;
            }
            if ((FLD(D_001A4BE0, s32, 0x25C4) == 0xA0) && (FLD(D_001A4BE0, s32, 0x1B8) < 0x51)) {
                return;
            }
            func_L01_004EA040();
            return;
        }
        if (func_00388398(D_001A4BE0 + 0x23C) == 2) {
            func_L01_004EA040();
        }
        break;
    case 0x81:
        if (FLD(D_001A4BE0, s32, 0x1B8) < 0xDD) {
            break;
        }
        func_L01_004EA040();
        return;
    case 0x50:
        if (FLD(D_001A4BE0, s32, 0x1B8) < 0xDD) {
            break;
        }
        func_L01_004EA040();
        return;
    case 0x32:
    case 0x34:
    {
        u32 st = FLD(D_001A4BE0, u32, 0x25C4);
        if (st == 0x32) {
            f32 h;
            FLD(D_001A4BE0, f32, 0xC00) = FLD(D_001A4BE0, f32, 0x1B4) * 15.0f;
            if (FLD(D_001A4BE0, f32, 0xC00) < 0.25f) {
                FLD(D_001A4BE0, f32, 0xC00) = 0.25f;
            }
            if (FLD(D_001A4BE0, f32, 0xC00) > 0.75f) {
                FLD(D_001A4BE0, f32, 0xC00) = 0.75f;
            }
            if ((FLD(D_001A4BE0, u32, 0x25C4) == st) && !(FLD(D_001D52FC, s32, 0x1A0) & 0xC0) && ((h = FLD(D_001A4BE0, f32, 0xC18)) > 9.0f) && (h < 19.0f) && (FLD(D_001A4BE0, s32, 0x25C8) != 1) && (FLD(D_001A4BE0, f32, 0x2838) < 0.1f) && (FLD(D_001A4BE0, f32, 0x1B4) < 0.0333333351f)) {
                func_L09_00512408(0x33, 1);
                break;
            }
        }
        if ((FLD(D_001A4BE0, s16, 0x2884) == 0) && (FLD(D_001D52FC, s32, 0x1A0) & 0xA)) {
            if ((FLD(D_001A4BE0, u32, 0x25C4) == 0x32) && (FLD(D_001A4BE0, s32, 0x1B8) >= 0x15)) {
                func_L09_00512408(0x34, 1);
                break;
            }
        } else if (FLD(D_001A4BE0, u32, 0x25C4) == 0x34) {
            if (FLD(D_001A4BE0, f32, 0x2838) > 0.5f) {
                func_L09_00512408(0x32, 1);
                break;
            }
        }
        if (FLD(D_001A4BE0, u32, 0x25C4) == 0x34) {
            s32 pad = FLD(D_001D52FC, s32, 0x1A0);
            if (!(pad & 0xC0) && (FLD(D_001A4BE0, s32, 0x25C8) != 1) && (FLD(D_001A4BE0, f32, 0x2838) < 0.7f) && !(pad & 0xA)) {
                func_L09_00512408(0x33, 1);
            }
        }
        break;
    }

    case 0x33:
    {
        s32 pad;
        if ((FLD(D_001A4BE0, s32, 0xC08) & 2) && (FLD(FLD(D_001A4BE0, u8 *, 0x25C0), u8, 0x43) != 0x37)) {
            func_L01_0050BB98(0x37, 0, 11.0f);
        }
        if ((FLD(D_001A4BE0, f32, 0x2838) > 0.2f) || ((pad = FLD(D_001D52FC, s32, 0x1A0)) & 0xC0) || ((FLD(D_001A4BE0, s16, 0x2884) == 0) && (pad & 0xA))) {
            if (FLD(D_001A4BE0, s16, 0x2884) != 0) {
                func_L09_00512408(0x32, 1);
            } else if (FLD(D_001D52FC, s32, 0x1A0) & 0xA) {
                func_L09_00512408(0x34, 1);
            } else {
                func_L09_00512408(0x32, 1);
            }
        }
        break;
    }

    case 0x36:
        if ((FLD(D_001A4BE0, s16, 0x1F8) == 0) && (func_L01_0045D358(func_0039E928(0x40, 0), 8, 0, 0) != 0) && (FLD(D_001A4BE0, s32, 0x1B8) >= 11)) {
            func_L09_00512408(0x12, 1);
            break;
        }
        FLD(D_001A4BE0, u8, 0x25E8) = 1;
        if ((FLD(D_001A4BE0, s16, 0x1FE) == 0) && (FLD(FLD(FLD(D_001A4BE0, u8 *, 0x25C0), u8 *, 0x24), s32, 0x120) != 0)) {
            if ((func_L01_0045D358(0x80, 7, 0, 0) != 0) || ((FLD(D_001A4BE0, s16, 0x2884) == 0) && (func_L01_0045D358(0xA, 7, 0, 0) != 0))) {
                if (FLD(D_001A4BE0, s16, 0x2884) != 0) {
                    func_L09_00512408(0x32, 1);
                } else if (FLD(D_001D52FC, s32, 0x1A0) & 0xA) {
                    func_L09_00512408(0x34, 1);
                } else {
                    func_L09_00512408(0x32, 1);
                }
                break;
            }
        }
        if ((FLD(D_001A4BE0, u8, 0x25EA) != 0) && (FLD(D_001A4BE0, f32, 0x2848) < 0.4f) && (func_L09_00512408(0, 0) != 0)) {
            func_L01_0050BB98(func_L02_004B21A8(0), 0, 18.0f);
        }
        if ((FLD(D_001A4BE0, f32, 0x2838) > 0.2f) && (FLD(D_001A4BE0, s32, 0x1B8) >= 11)) {
            func_L09_00512408(0x35, 1);
        }
        break;

    case 0x35:
        if ((FLD(D_001A4BE0, s16, 0x1F8) == 0) && (func_L01_0045D358(func_0039E928(0x40, 0), 8, 0, 0) != 0)) {
            func_L09_00512408(0x12, 1);
            break;
        }
        if ((FLD(D_001A4BE0, s16, 0x1FE) == 0) && (FLD(FLD(FLD(D_001A4BE0, u8 *, 0x25C0), u8 *, 0x24), s32, 0x120) != 0) && (func_L01_0045D358(0x80, 7, 0, 0) != 0)) {
            if (FLD(D_001A4BE0, s16, 0x2884) != 0) {
                func_L09_00512408(0x32, 1);
            } else if (FLD(D_001D52FC, s32, 0x1A0) & 0xA) {
                func_L09_00512408(0x34, 1);
            } else {
                func_L09_00512408(0x32, 1);
            }
            break;
        }
        if ((FLD(D_001A4BE0, u8, 0x25EA) != 0) && (FLD(D_001A4BE0, f32, 0x2848) < 0.7f)) {
            func_L09_00512408(0x75, 0);
            func_L01_0050BB98((FLD(FLD(FLD(D_001A4BE0, u8 *, 0x25C0), u8 *, 0x24), s32, 0x188) == 0) ? 3 : 0x50, 0, 17.0f);
            FLD(D_001A4BE0, s32, 0xF8) = 0;
            FLD(D_001A4BE0, s32, 0x118) = 0;
        }
        if ((FLD(D_001A4BE0, f32, 0x2838) < 0.1f) && (FLD(D_001A4BE0, f32, 0x1B4) == 0.0f) && (FLD(D_001A4BE0, s32, 0x728) == 0)) {
            func_L09_00512408(0x36, 1);
        }
        break;

    case 0x78:
        if (FLD(D_001A4BE0, s32, 0x2850) <= 0) {
            func_L09_00512408(0x6C, 1);
            func_L01_0050BB98(0x4F, 0x28, 18.0f);
        } else if (FLD(D_001A4BE0, s32, 0xC08) & 2) {
            func_L09_00512408(0x33, 1);
        } else if (FLD(D_001A4BE0, s32, 0x1B8) >= 0x33) {
            func_L09_00512408(0x33, 0);
        }
        break;
    case 0x77:
        if (FLD(D_001A4BE0, s32, 0x2850) <= 0) {
            func_L09_00512408(0x6C, 1);
            func_L01_0050BB98(0x4F, 0x25, 18.0f);
        } else if (FLD(D_001A4BE0, s32, 0x1B8) >= 0x33) {
            func_L09_00512408(0x36, 0);
        }
        break;
    case 0x1:
    {
        u8 *p;
        s32 ok;
        s32 late;
        s32 anim;
        if ((FLD(D_001A4BE0, u8, 0x25E4) == 0) && ((FLD(D_001A4BE0, u8, 0x25EB) == 0) || (FLD(D_001A4BE0, u8, 0x25E5) != 0))) {
            if (FLD(D_001D52FC, s32, 0x1A0) & func_0039E928(8, 0)) {
                func_L01_0050BB98(0xD, 0, 8.0f);
            } else {
                s32 a = func_L02_004B21A8(1);
                if (FLD(FLD(D_001A4BE0, u8 *, 0x25C0), u8, 0x43) != a) {
                    func_L01_0050BB98(a, 0, 8.0f);
                }
            }
        }
        p = FLD(D_001A4BE0, u8 *, 0x1200);
        ok = 1;
        if ((p != NULL) && (func_L01_004EA1D8(p) != 0)) {
            if ((FLD(p, u8, 0x20) != 0) && (func_L01_0050FF18() == 0)) {
                ok = 0;
            }
        }
        late = 0;
        if (FLD(D_001A4BE0, u8, 0x25E5) == 0) {
            late = FLD(D_001A4BE0, s32, 0x1B8) >= 0x1F;
        }
        if ((!(FLD(D_001D52FC, s32, 0x1A0) & func_0039E928(4, 0)) && ok) || late) {
            if (FLD(D_001A4BE0, u8, 0x25E4) != 0) {
                func_L02_004D31B8(0);
            } else if (FLD(D_001D52FC, s32, 0x1A0) & func_0039E928(8, 0)) {
                func_L09_00512408(4, 1);
            } else {
                func_L09_00512408(0, 0);
                anim = func_L02_004B21A8(1);
                if (FLD(FLD(D_001A4BE0, u8 *, 0x25C0), u8, 0x43) != anim) {
                    func_L01_0050BB98(anim, 0, 8.0f);
                }
            }
        }
        break;
    }

    case 0x2F:
        if (!(FLD(D_001D52FC, s32, 0x1A0) & FLD(D_001A4BE0, s32, 0x1210)) && (FLD(D_001A4BE0, s16, 0x1EC) == 0)) {
            if (FLD(FLD(D_001A4BE0, u8 *, 0x25C0), u8, 0x43) == 0x31) {
                func_L09_00512408(0, 0);
            } else {
                func_L09_00512408(0, 1);
            }
        }
        break;

    case 0x14:
    {
        u8 *rec;
        s32 frames;
        if (FLD(D_001A4BE0, u32, 0x25C4) == 0x14) {
            s32 n = (s32)(func_L01_0050C4A0(60.0f, 0.0361111127f, -1.0f));
            f32 c00 = FLD(D_001A4BE0, f32, 0xBE0);
            s32 top = 0x1A;
            if (c00 == 0.0f) {
                FLD(D_001A4BE0, f32, 0xC00) = 0.33f;
            } else if ((c00 != 0.0f) && (FLD(D_001A4BE0, s16, 0x36E) != 0) && (n != 0) && (((f32)top - FLD(D_001A4BE0, f32, 0xC18)) > 1.0f)) {
                func_L01_004E1268((f32)top, (f32)n, 0.5f, -1.0f);
                if ((FLD(D_001A4BE0, f32, 0x33C) < 0.7f) && (FLD(D_001A4BE0, f32, 0xC00) < 0.75f)) {
                    FLD(D_001A4BE0, f32, 0xC00) = 0.75f;
                }
            } else if ((FLD(D_001A4BE0, s16, 0x36E) == 0) && (FLD(D_001A4BE0, f32, 0xC18) < (f32)top)) {
                FLD(D_001A4BE0, f32, 0xC00) = 2.0f;
            } else {
                FLD(D_001A4BE0, f32, 0xC00) = 1.0f;
            }
        }
        rec = (u8 *)&D_L09_002F6B90[FLD(D_001A4BE0, s16, 0xBDC)];
        frames = ((s32)(FLD(D_001A4BE0, f32, 0xC18)) - FLD(rec, s32, 0xC)) * 2;
        if ((f32)FLD(rec, s32, 0x14) < FLD(D_001A4BE0, f32, 0xC18)) {
            if (FLD(D_001A4BE0, s32, 0xC0C) != 0) {
                break;
            }
            if (func_L01_0045D358(func_0039E928(0x40, 0), frames, 0, 0) != 0) {
                if (!(FLD(D_001D52FC, s32, 0x1A0) & func_0039E928(8, 0))) {
                    func_L09_00512408(7, 1);
                    break;
                }
                if (func_L01_00502ED8() != 0) {
                    break;
                }
            }
        }
        if ((FLD(D_001A4BE0, s32, 0xC0C) == 0) && ((f32)FLD(rec, s32, 0x18) < FLD(D_001A4BE0, f32, 0xC18))) {
            func_L09_00512408(0, 0);
        }
        break;
    }

    case 0x13:
    case 0x15:
    {
        u8 *rec = (u8 *)&D_L09_002F6B90[FLD(D_001A4BE0, s16, 0xBDC)];
        s32 frames = ((s32)(FLD(D_001A4BE0, f32, 0xC18)) - FLD(rec, s32, 0xC)) * 2;
        u32 st = FLD(D_001A4BE0, u32, 0x25C4);
        s32 lim;
        f32 h;
        if (st == 0x15) {
            frames = 8;
        }
        if ((f32)FLD(rec, s32, 0x14) < FLD(D_001A4BE0, f32, 0xC18)) {
            if (FLD(D_001A4BE0, s32, 0xC0C) != 0) {
                goto tail13;
            }
            if ((st != 0x15) || (FLD(D_001A4BE0, s16, 0x368) != 1)) {
                if (func_L01_0045D358(func_0039E928(0x40, 0), frames, 0, 0) != 0) {
                    if (!(FLD(D_001D52FC, s32, 0x1A0) & func_0039E928(8, 0))) {
                        func_L09_00512408(7, 1);
                        break;
                    }
                    if (func_L01_00502ED8() != 0) {
                        break;
                    }
                }
            }
        }
        if (FLD(D_001A4BE0, s32, 0xC0C) != 0) {
            goto tail13;
        }
        if (FLD(D_001A4BE0, f32, 0xC18) > 34.0f) {
            if (FLD(D_001A4BE0, f32, 0x2838) > 0.9f) {
                func_L09_00512408(2, 0);
                if (FLD(D_001A4BE0, u32, 0x25C4) == 2) {
                    func_L01_0050BB98(3, D_L09_001DBE30[FLD(D_001A4BE0, s32, 0x25C8)], 13.0f);
                }
                break;
            }
        }
        if (FLD(D_001A4BE0, s32, 0xC0C) != 0) {
            goto tail13;
        }
        lim = FLD(rec, s32, 0x18);
        h = FLD(D_001A4BE0, f32, 0xC18);
        if ((f32)lim < h) {
            if (FLD(D_001A4BE0, f32, 0x2838) > 0.8f) {
                func_L09_00512408(2, 1);
                break;
            }
            if (((f32)(lim + 5) < h) || (FLD(D_001A4BE0, s32, 0xC08) & 2)) {
                func_L09_00512408(0, 0);
            }
            break;
        }
    tail13:
        if (FLD(D_001A4BE0, u32, 0x25C4) == 0x15) {
            if ((FLD(D_001A4BE0, s32, 0x1228) != 9) && (FLD(D_001A4BE0, s32, 0x1228) != 0x7F)) {
                func_L09_00512408(0, 1);
                break;
            }
            if ((FLD(D_001A4BE0, u32, 0x25C4) == 0x15) && (FLD(D_001A4BE0, s32, 0x1B8) >= 0x65) && (FLD(D_001A4BE0, s32, 0xC24) < 0x1A)) {
                func_L01_0050BF40(2);
                FLD(D_001A4BE0, s32, 0xC24) = 0x1A;
            }
        }
        break;
    }

    case 0x88:
        if (FLD(D_001A4BE0, f32, 0xC18) > 37.0f) {
            if (FLD(D_001A4BE0, s32, 0xC0C) != 0) {
                goto tail88;
            }
            if (func_L01_0045D358(func_0039E928(0x40, 0), 7, 0, 0) != 0) {
                if (!(FLD(D_001D52FC, s32, 0x1A0) & func_0039E928(8, 0))) {
                    func_L09_00512408(7, 1);
                    break;
                }
                if (func_L01_00502ED8() != 0) {
                    break;
                }
            }
        }
        if (FLD(D_001A4BE0, s32, 0xC0C) != 0) {
            goto tail88;
        }
        if (FLD(D_001A4BE0, f32, 0xC18) > 37.0f) {
            func_L09_00512408(0, 0);
            func_L01_0050BB98(func_L02_004B21A8(0), 0, 15.0f);
            break;
        }
    tail88:
        if ((FLD(D_001A4BE0, u32, 0x25C4) == 0x15) && (FLD(D_001A4BE0, s32, 0x1B8) >= 0x65) && (FLD(D_001A4BE0, s32, 0xC24) < 0x1A)) {
            func_L01_0050BF40(2);
            FLD(D_001A4BE0, s32, 0xC24) = 0x1A;
        }
        break;
    case 0x7C:
        if (FLD(D_001A4BE0, s32, 0xC08) & 2) {
            func_L09_00512408(0, 1);
        }
        break;
    case 0x2:
    case 0x2E:
    case 0x75:
    {
        s32 n;
        s32 turned;
        u32 st;
        if ((FLD(D_001A4BE0, u8, 0x3EE) != 0) && ((FLD(hero, f32, 0x44) > 0.9f) || (FLD(hero, u8, 0x42) != 0xFF))) {
            FLD(D_001A4BE0, u8, 0x3EE) = 0;
        }
        if ((FLD(D_001A4BE0, u8, 0x147C) != 0) && (FLD(D_001A4BE0, s16, 0x36C) == 0)) {
            func_L09_00512408(0x7B, 1);
            break;
        }
        if ((FLD(D_001A4BE0, s16, 0x36E) >= 7) && ((FLD(D_001A4BE0, s32, 0x25D4) != 0x12) || (FLD(D_001A4BE0, u8, 0x25EA) == 0)) && (FLD(D_001A4BE0, f32, 0x33C) > 1.35f) && (func_L01_00503188() == 0)) {
            func_L09_00512408(6, 1);
            break;
        }
        n = 9;
        if (FLD(D_001A4BE0, s16, 0x1EE) != 0) {
            n = 1;
        }
        if ((func_L01_0045D358(func_0039E928(0x40, 0), n, 0, 0) != 0) && ((FLD(D_001A4BE0, s16, 0x36E) < 8) || (FLD(D_001A4BE0, f32, 0x33C) < 0.5f) || (FLD(D_001A4BE0, s16, 0x202) != 0))) {
            func_L01_004EAA78(0, 1.0f);
            if (func_L01_00502368(n, 1) != 0) {
                break;
            }
            if ((FLD(D_001A4BE0, f32, 0x2838) > 0.85f) && (FLD(D_001A4BE0, s16, 0x1434) == 0) && ((FLD(D_001A4BE0, s32, 0x16B0) != 1) || (func_L01_0045D358(0x28, 2, 0, 0) == 0))) {
                func_L09_00512408(9, 1);
            } else {
                func_L09_00512408(7, 1);
            }
            break;
        }
        if (FLD(D_001A4BE0, s16, 0x36E) != 0) {
            break;
        }
        if (((FLD(D_001A4BE0, u8, 0x1474) == 0) || ((FLD(D_001A4BE0, f32, 0x174) < 0.0333333351f) && (FLD(D_001A4BE0, f32, 0x340) < 0.08726646f))) && (FLD(D_001D52FC, s32, 0x1A0) & func_L01_0050EE20(func_0039E928(4, 0))) && ((FLD(D_001A4BE0, u8, 0x25E4) != 0) || (D_001439F4[0] != 2) || (FLD(D_001A4BE0, s32, 0x1228) == 0x6F)) && (func_L01_003E9428(0) == 0)) {
            func_L09_00512408(1, 1);
            break;
        }
        if (FLD(D_001D52FC, s32, 0x1A0) & func_0039E928(8, 0)) {
            func_L09_00512408(4, 1);
            break;
        }
        if ((FLD(D_001A4BE0, u8, 0x1474) != 0) && (FLD(D_001A4BE0, u32, 0x25C4) == 0x2E)) {
            f32 speed = func_003887A0(D_001A4BE0 + 0x110);
            s32 anim;
            if ((FLD(D_001A4BE0, f32, 0x2838) < 0.17f) && ((FLD(FLD(D_001A4BE0, u8 *, 0x25C0), u8, 0x43) == 0x32) || (FLD(FLD(D_001A4BE0, u8 *, 0x25C0), u8, 0x43) == 0x7B) || ((FLD(FLD(D_001A4BE0, u8 *, 0x25C0), u8, 0x43) == func_L02_004B21A8(0)) && (FLD(D_001A4BE0, f32, 0x340) > 0.08726646f))) && (FLD(D_001A4BE0, s32, 0x1CC) >= 9) && (FLD(D_001A4BE0, s32, 0xC0C) == 0)) {
                func_L01_0050BB98(0x54, 0, 14.0f);
            } else if ((FLD(D_001A4BE0, f32, 0x2838) > 0.3f) && (FLD(FLD(D_001A4BE0, u8 *, 0x25C0), u8, 0x43) != 0x32) && (FLD(FLD(D_001A4BE0, u8 *, 0x25C0), u8, 0x43) != 0x7B) && (FLD(D_001A4BE0, s32, 0xC0C) == 0)) {
                if (((FLD(D_001A4BE0, s16, 0x1434) != 0) || ((FLD(D_001A4BE0, s32, 0x16B0) == 1) && (func_L01_0045D358(0x28, 2, 0, 0) != 0))) && (FLD(D_001A4BE0, u8, 0x1436) != 0)) {
                    func_L01_0050BB98(0x7B, 0, 14.0f);
                } else {
                    func_L01_0050BB98(0x32, 0, 14.0f);
                }
            } else if ((FLD(FLD(D_001A4BE0, u8 *, 0x25C0), u8, 0x43) == 0x54) && (FLD(D_001A4BE0, s32, 0xC0C) == 0) && (FLD(D_001A4BE0, f32, 0x2838) < 0.17f) && (FLD(D_001A4BE0, f32, 0x340) < 0.08726646f) && (speed < 0.0283333361f)) {
                func_L01_0050BB98(func_L02_004B21A8(0), 0, 20.0f);
            }
        }
        st = FLD(D_001A4BE0, u32, 0x25C4);
        if ((st == 2) || (st == 0x80)) {
            if (FLD(D_001A4BE0, u8, 0x1474) != 0) {
                func_L09_00512408(0x2E, 1);
            }
        } else if (st == 0x2E) {
            if (FLD(D_001A4BE0, u8, 0x1474) == 0) {
                func_L09_00512408(2, 1);
            }
        }
        if (FLD(D_001A4BE0, u8, 0x1474) != 0) {
            if (((FLD(D_001A4BE0, s16, 0x1434) != 0) || ((FLD(D_001A4BE0, s32, 0x16B0) == 1) && (func_L01_0045D358(0x28, 2, 0, 0) != 0))) && (FLD(D_001A4BE0, u8, 0x1436) != 0)) {
                if (FLD(FLD(D_001A4BE0, u8 *, 0x25C0), u8, 0x43) == 0x32) {
                    func_L01_0050BB98(0x7B, 0, 9.0f);
                }
            } else if (FLD(FLD(D_001A4BE0, u8 *, 0x25C0), u8, 0x43) == 0x7B) {
                func_L01_0050BB98(0x32, 0, 7.0f);
            }
        }
        st = FLD(D_001A4BE0, u32, 0x25C4);
        if (st == 2) {
            if (FLD(D_001A4BE0, u8, 0x25EA) != 0) {
                func_L09_00512408(0x75, 1);
            }
        } else if (st == 0x75) {
            if (FLD(D_001A4BE0, u8, 0x25EA) == 0) {
                func_L09_00512408(2, 1);
            }
        }
        turned = func_L01_004EA1F8(0.034906585f);
        st = FLD(D_001A4BE0, u32, 0x25C4);
        if (st == 2) {
            if (((FLD(D_001A4BE0, f32, 0x2838) < 0.17f) || (FLD(D_001A4BE0, s16, 0x1E0) != 0)) && (turned == 0) && ((FLD(D_001A4BE0, s32, 0x3F0) == 0) || (fabs_asm(FLD(D_001A4BE0, f32, 0x1A8)) < 0.017453292f))) {
                s32 anim;
                if (func_L01_00503310() != 0) {
                    break;
                }
                if (func_L09_00512408(0, 0) != 0) {
                    func_003BF640(D_001A4BE0 + 0x160, 0.0250000022f);
                    if (FLD(D_001A4BE0, f32, 0x1B4) > 0.0250000022f) {
                        FLD(D_001A4BE0, f32, 0x1B4) = 0.0250000022f;
                    }
                    anim = func_L02_004B21A8(1);
                    if (anim == 0x4A) {
                        func_L01_0050BB98(0x4A, 0, 15.0f);
                    } else {
                        func_L01_0050BB98(anim, 0, -1.0f);
                    }
                }
            } else {
                func_L01_005024B8();
            }
        } else if (st == 0x2E) {
            if ((FLD(D_001D52FC, s32, 0x1D4) != 0) && (func_003887A0(D_001A4BE0 + 0xF0) < 0.000833333412f) && (FLD(D_001A4BE0, f32, 0x340) < 0.08726646f) && (func_L09_00512408(0, 0) != 0)) {
                func_L01_0050BB98(func_L02_004B21A8(0), 0, 17.0f);
            }
            if ((FLD(hero, u8, 0x43) == 0x32) || (FLD(hero, u8, 0x43) == 0x7B)) {
                FLD(D_001A4BE0, f32, 0xC00) = (1.0f - FLD(D_001A4BE0, f32, 0x3E0)) * 2.0f;
                if (FLD(D_001A4BE0, f32, 0xC00) > 1.7f) {
                    FLD(D_001A4BE0, f32, 0xC00) = 1.7f;
                }
                if (FLD(D_001A4BE0, f32, 0xC00) < 0.75f) {
                    FLD(D_001A4BE0, f32, 0xC00) = 0.75f;
                }
            } else if (FLD(hero, u8, 0x43) == 0x54) {
                FLD(D_001A4BE0, f32, 0xC00) = FLD(D_001A4BE0, f32, 0x170) * 10.0f;
                if (FLD(D_001A4BE0, f32, 0xC00) > 1.1f) {
                    FLD(D_001A4BE0, f32, 0xC00) = 1.1f;
                }
                if (FLD(D_001A4BE0, f32, 0xC00) < 0.3f) {
                    FLD(D_001A4BE0, f32, 0xC00) = 0.3f;
                }
            }
        } else if (st == 0x75) {
            if ((FLD(D_001D52FC, s32, 0x1D4) != 0) && (func_003887A0(D_001A4BE0 + 0xF0) < 0.0533333384f) && (func_L09_00512408(0, 0) != 0)) {
                func_L01_0050BB98(func_L02_004B21A8(0), 0, 17.0f);
            }
            FLD(D_001A4BE0, f32, 0xC00) = FLD(D_001A4BE0, f32, 0x170) * 35.0f;
            if (FLD(D_001A4BE0, f32, 0xC00) < 0.6f) {
                FLD(D_001A4BE0, f32, 0xC00) = 0.6f;
            }
            if (FLD(D_001A4BE0, f32, 0xC00) > 1.05f) {
                FLD(D_001A4BE0, f32, 0xC00) = 1.05f;
            }
        }
        if ((FLD(D_001A4BE0, s16, 0x368) == 0) && (FLD(D_001A4BE0, s32, 0x1278) == 0xD) && (FLD(D_001A4BE0, s32, 0x2634) != 0)) {
            FLD(D_001A4BE0, s32, 0x2650) = 1;
        }
        break;
    }
    case 0x80:
    {
        s32 one = 1;
        s32 flag = 0;
        if (FLD(D_001A4BE0, s16, 0x368) != 0) {
            flag = 1;
        }
        if (!(FLD(D_001D52FC, s32, 0x1A0) & func_0039E928(8, 0))) {
            if (FLD(D_001A4BE0, s32, 0x1B8) >= 0x3D) {
                flag = one;
            }
        }
        if (FLD(D_001A4BE0, u8, 0x25E9) != 0) {
            flag = one;
        }
        if (flag != 0) {
            if (FLD(D_001A4BE0, s32, 0x2634) != 0) {
                FLD(D_001A4BE0, s32, 0x2650) = one;
            }
            func_L01_004F1068(9, 0);
            FLD(D_001A4BE0, s16, 0x1E0) = 0x1E;
            func_L09_00512408(3, 0);
            func_L01_0050BB98(6, 4, 11.0f);
        } else if (FLD(D_001A4BE0, s32, 0x984) != 0) {
            func_L09_00512408(0, 0);
            func_L01_0050BB98(func_L02_004B21A8(0), 0, -2.0f);
        } else {
            if (FLD(D_001A4BE0, u8, 0x2A7) != 0) {
                f32 a = func_00388770(D_001A4BE0 + 0x110);
                if (a < func_00388770(D_001A4BE0 + 0xF0) * 0.75f) {
                    func_L09_00512408(0x7C, 1);
                    break;
                }
                if (func_L01_004E2628(NULL, 1.0f, 1.25f) != 0) {
                    func_L09_00512408(0x7C, 1);
                    break;
                }
            }
            *(s128 *)v30 = 0;
            v30[0] = -0.0833333358f;
            func_003BDA38(FLD(D_001A4BE0, s8 *, 0x25C0), 0x16, (s8 *)v10);
            func_003BDA38(FLD(D_001A4BE0, s8 *, 0x25C0), 0x17, (s8 *)v20);
            func_L01_0046A9C8(FLD(D_001A4BE0, s8 *, 0x25C0), v10, v30, (s32 *)D_L09_001DBCD0, 1);
            func_L01_0046A9C8(FLD(D_001A4BE0, s8 *, 0x25C0), v10, v30, (s32 *)D_L09_001DBCE0, 1);
            func_L01_0046A9C8(FLD(D_001A4BE0, s8 *, 0x25C0), v20, v30, (s32 *)D_L09_001DBCD0, 1);
            func_L01_0046A9C8(FLD(D_001A4BE0, s8 *, 0x25C0), v20, v30, (s32 *)D_L09_001DBCE0, 1);
        }
        break;
    }
    case 0x66:
        if (D_L09_001D673C != 0) {
            if (func_003887C8(D_001A4BE0 + 0x80, D_001A4BE0 + 0x80 + 0x1AC0) < 0.4f) {
                if (FLD(D_001A4BE0, f32, 0x170) < 0.0450000018f) {
                    func_L09_00512408(0x68, 1);
                } else if ((FLD(D_001A4BE0, u8, 0x25E4) != 0) && (FLD(D_001A4BE0, f32, 0x170) >= 0.0450000018f)) {
                    func_L09_00512408(0x67, 1);
                }
                break;
            }
        } else if (func_00388800(D_001A4BE0 + 0x80, D_001A4BE0 + 0x80 + 0x1AC0) < 0.3f) {
            if ((FLD(D_001A4BE0, f32, 0x170) < 0.0450000018f) && (func_00389468(FLD(D_001A4BE0, f32, 0x98), FLD(D_001A4BE0, f32, 0x1B4C)) < 0.034906585f)) {
                func_L09_00512408(0x68, 1);
            } else if ((FLD(D_001A4BE0, u8, 0x25E4) != 0) && (FLD(D_001A4BE0, f32, 0x170) >= 0.0450000018f)) {
                func_L09_00512408(0x67, 1);
            }
            break;
        }
        func_L01_005024B8();
        break;
    case 0x67:
        if (FLD(D_001A4BE0, s32, 0xC08) & 2) {
            func_L09_00512408(0x66, 1);
        }
        break;
    case 0x68:
    {
        if ((FLD(D_001A4BE0, s32, 0xC08) & 2) || (FLD(D_001A4BE0, s32, 0x1B50) != 0)) {
            func_L09_00512408(0, 1);
        }
        if (D_L09_001D673C != 0) {
            if (func_003887C8(D_001A4BE0 + 0x80, D_001A4BE0 + 0x80 + 0x1AC0) > 0.4f) {
                func_L09_00512408(0x66, 1);
            }
        } else if (func_00388800(D_001A4BE0 + 0x80, D_001A4BE0 + 0x80 + 0x1AC0) > 0.3f) {
            func_L09_00512408(0x66, 1);
        }
        break;
    }
    case 0x6A:
        if ((FLD(D_001A4BE0, s32, 0x1B70) < 3) && ((FLD(D_001A4BE0, s32, 0x1B70) * 7 + 10) < FLD(D_001A4BE0, s32, 0x1B8)) && (func_L01_0045D358(func_0039E928(0x40, 0), 7, &sp34, 0) != 0)) {
            func_L09_00512408(0x6B, 1);
        }
        if (!(FLD(D_001A4BE0, f32, 0x88) < (FLD(D_001A4BE0, f32, 0x354) - 1.2f)) && (FLD(D_001A4BE0, s32, 0x1B8) < 0xAB)) {
            break;
        }
        func_L01_004EA040();
        return;
    case 0x7D:
        if (!(FLD(D_001A4BE0, f32, 0x88) < (FLD(D_001A4BE0, f32, 0x354) - 1.2f)) && (FLD(D_001A4BE0, s32, 0x1B8) < 0x97)) {
            break;
        }
        func_L01_004EA040();
        return;
    case 0x3:
        if ((FLD(D_001D52FC, s32, 0x1A0) & func_L01_0050EE20(func_0039E928(4, 0))) && ((FLD(D_001A4BE0, u8, 0x25E4) != 0) || (D_001439F4[0] != 2) || (FLD(D_001A4BE0, s32, 0x1228) == 0x6F)) && (func_L01_003E9428(0) == 0)) {
            func_L09_00512408(1, 1);
            break;
        }
        if ((FLD(D_001A4BE0, s16, 0x1E0) == 0) && (FLD(D_001D52FC, s32, 0x1A4) & func_0039E928(0x40, 0))) {
            func_L09_00512408(7, 1);
            break;
        }
        if ((FLD(D_001A4BE0, s16, 0x1E0) == 0) && (FLD(D_001D52FC, s32, 0x1A0) & func_0039E928(8, 0))) {
            func_L09_00512408(4, 1);
            break;
        }
        if ((FLD(D_001A4BE0, s16, 0x36E) >= 9) && (FLD(D_001A4BE0, f32, 0x33C) > 0.3f)) {
            func_L09_00512408(6, 1);
            break;
        }
        if (FLD(D_001A4BE0, s32, 0xC08) & 2) {
            func_L09_00512408(0, 1);
            break;
        }
        if (!(FLD(D_001A4BE0, f32, 0x2838) > 0.2f) || (FLD(D_001A4BE0, s16, 0x1E0) != 0)) {
            break;
        }
        if (func_L02_004B21A8(0) != 0x4A) {
            if (FLD(D_001A4BE0, f32, 0x1B4) == 0.0f) {
                func_L09_00512408(0, 0);
                break;
            }
        } else if ((FLD(D_001A4BE0, f32, 0xC18) > 10.0f) && (func_L09_00512408(0, 0) != 0)) {
            func_L01_0050BB98(func_L02_004B21A8(0), 0, 17.0f);
        }
        if (FLD(D_001A4BE0, f32, 0x2838) > 0.5f) {
            func_L09_00512408(2, 1);
        }
        break;

    case 0x4:
        if ((FLD(D_001D52FC, s32, 0x1A0) & func_L01_0050EE20(func_0039E928(4, 0))) && ((FLD(D_001A4BE0, u8, 0x25E4) != 0) || (D_001439F4[0] != 2) || (FLD(D_001A4BE0, s32, 0x1228) == 0x6F)) && (func_L01_003E9428(0) == 0)) {
            func_L09_00512408(1, 1);
            break;
        }
        if ((FLD(D_001A4BE0, s32, 0x1B8) >= 0xC) && !(FLD(D_001D52FC, s32, 0x1A0) & func_0039E928(8, 0))) {
            func_L09_00512408(0, 0);
            func_L01_0050BB98(func_L02_004B21A8(0), 0, -2.0f);
            break;
        }
        if (FLD(D_001A4BE0, u8, 0x147C) != 0) {
            if (FLD(D_001A4BE0, s16, 0x36C) == 0) {
                func_L09_00512408(0x7B, 1);
                break;
            }
        } else if (func_L01_00502ED8() != 0) {
            break;
        }
        if ((func_L01_0045D358(0x80, 0xF, 0, 0) != 0) && (FLD(D_001A4BE0, u8, 0x121A) == 0) && (FLD(D_001A4BE0, s32, 0x1228) == 9)) {
            func_L09_00512408(0x15, 1);
        }
        if (FLD(D_001A4BE0, s16, 0x36E) >= 9) {
            if ((FLD(D_001A4BE0, s32, 0x25D0) != 8) || (FLD(D_001A4BE0, s32, 0x1B8) >= 0xF)) {
                func_L09_00512408(6, 1);
            }
        }
        break;

    case 0x8F:
        if (FLD(D_001A4BE0, s32, 0x1228) != 0xB) {
            func_L09_00512408(0, 1);
            break;
        }
        if (FLD(D_001A4BE0, s32, 0xA9C) != 0) {
            if (FLD(D_001A4BE0, u8 *, 0xA90) != NULL) {
                func_L01_00452F40(FLD(D_001A4BE0, u8 *, 0xA90), 1);
            }
            func_L09_00512408(0x90, 1);
        }
        break;
    case 0x90:
        if (FLD(D_001A4BE0, s32, 0x1B8) >= 0x5B) {
            func_L09_00512408(0, 1);
        }
        break;
    case 0x23:
        if (FLD(D_001A4BE0, s32, 0x1228) != 0xB) {
            func_L09_00512408(0, 1);
        }
        break;
    case 0x24:
    {
        s32 go;
        func_L01_004E1268(10.0f, FLD(D_001A4BE0, f32, 0xA2C), 0.5f, -1.0f);
        if ((FLD(D_001A4BE0, f32, 0xA2C) < 22.0f) && (FLD(D_001A4BE0, f32, 0xA2C) < 30.0f)) {
            func_L01_0050BB98(0xA, 0, 16.0f);
        }
        go = 0;
        if (!(FLD(D_001D52FC, s32, 0x1A0) & FLD(D_001A4BE0, s32, 0x1210))) {
            if (FLD(D_001A4BE0, f32, 0xA2C) > 25.0f) {
                FLD(D_001A4BE0, s32, 0xA48) = 1;
            }
            go = 1;
        }
        if ((FLD(D_001A4BE0, s32, 0x25C8) == 1) && (FLD(D_001A4BE0, f32, 0xA20) < 0.0666666701f)) {
            go = 1;
        }
        if (go != 0) {
            FLD(D_001A4BE0, f32, 0x1B4) = FLD(D_001A4BE0, f32, 0xA20);
            if (FLD(D_001A4BE0, f32, 0x1B4) > 0.116666675f) {
                FLD(D_001A4BE0, f32, 0x1B4) = 0.116666675f;
            }
            if (FLD(D_001A4BE0, f32, 0x33C) < 0.3f) {
                func_L09_00512408(0, 0);
                func_L01_0050BB98(func_L02_004B21A8(0), 0, 30.0f);
                break;
            }
            if (FLD(FLD(D_001A4BE0, u8 *, 0x25C0), u8, 0x43) == 0xA) {
                func_L09_00512408(6, 0);
            } else {
                func_L09_00512408(6, 0);
                func_L01_0050BB98(0xA, 0, 17.0f);
            }
            FLD(D_001A4BE0, f32, 0xA04) = 0.0116666667f;
            FLD(D_001A4BE0, f32, 0xA00) = 0.00805555563f;
            FLD(D_001A4BE0, s32, 0x280C) = 0;
        }
        break;
    }

    case 0x25:
        if (!(FLD(D_001D52FC, s32, 0x1A0) & FLD(D_001A4BE0, s32, 0x1210))) {
            FLD(D_001A4BE0, f32, 0x1B4) = FLD(D_001A4BE0, f32, 0xA20);
            if (FLD(D_001A4BE0, f32, 0x1B4) > 0.116666675f) {
                FLD(D_001A4BE0, f32, 0x1B4) = 0.116666675f;
            }
            if (FLD(D_001A4BE0, f32, 0x33C) < 0.4f) {
                func_L09_00512408(0, 1);
            } else {
                func_L09_00512408(6, 1);
                FLD(D_001A4BE0, s32, 0x280C) = 0;
            }
        }
        break;

    case 0x2B:
        if (!(FLD(D_001D52FC, s32, 0x1A0) & FLD(D_001A4BE0, s32, 0x1210))) {
            s32 t = FLD(D_001A4BE0, s32, 0x1B8);
            if (t >= 11) {
                if (t < 0x28) {
                    FLD(D_001A4BE0, s32, 0xA48) = 1;
                }
                func_L09_00512408(0x2C, 1);
                FLD(D_001A4BE0, f32, 0xA04) = 0.00194444449f;
                FLD(D_001A4BE0, f32, 0xA00) = 0.0075000003f;
            }
        }
        break;

    case 0x17:
        if (FLD(D_001A4BE0, f32, 0xC18) > 12.0f) {
            func_L09_00512408(0x18, 0);
        }
        break;

    case 0x18:
        if ((FLD(D_001A4BE0, s32, 0xC08) & 2) && (FLD(FLD(D_001A4BE0, u8 *, 0x25C0), u8, 0x43) == 0x20)) {
            func_L01_0050BB98(0x21, 0, 5.0f);
        }
        func_L01_004EAA78(0, 1.0f);
        if (func_L02_004B9D90((s8 *)(D_001A4BE0 + 0x80), (s8 *)(D_001A4BE0 + 0x90), NULL) == 0) {
            func_L09_00512408(6, 1);
            FLD(D_001A4BE0, s16, 0x1D0) = 10;
            break;
        }
        if (((FLD(D_001A4BE0, f32, 0x2838) > 0.5f) && (func_L01_0045D358(func_0039E928(0x40, 0), 9, 0, 0) != 0) && (func_00389468(FLD(D_001A4BE0, f32, 0x1A0), FLD(D_001A4BE0, f32, 0x98)) > 2.3561945f)) || (FLD(D_001D52FC, s32, 0x1A4) & func_0039E928(8, 0))) {
            func_L09_00512408(6, 1);
            FLD(D_001A4BE0, s8, 0x25F0) = 1;
            FLD(D_001A4BE0, s16, 0x1D0) = 10;
            break;
        }
        if (func_L01_0045D358(func_0039E928(0x40, 0), 0x11, 0, 0) != 0) {
            func_L09_00512408(0x1B, 1);
            break;
        }
        if (FLD(D_001A4BE0, f32, 0x2838) > 0.5f) {
            if (func_00389468(FLD(D_001A4BE0, f32, 0x1A0), func_00389380(FLD(D_001A4BE0, f32, 0x98), 1.57079637f)) < 0.785398185f) {
                *(s128 *)v10 = *(s128 *)(D_001A4BE0 + 0x80);
                v10[0] += func_00388960(func_00389380(FLD(D_001A4BE0, f32, 0x98), 1.57079637f)) * 0.3f;
                v10[1] += func_00388978(func_00389380(FLD(D_001A4BE0, f32, 0x98), 1.57079637f)) * 0.3f;
                if (func_L02_004B9D90((s8 *)v10, (s8 *)(D_001A4BE0 + 0x90), NULL) != 0) {
                    func_L09_00512408(0x19, 1);
                }
                break;
            }
        }
        if (FLD(D_001A4BE0, f32, 0x2838) > 0.5f) {
            if (func_00389468(FLD(D_001A4BE0, f32, 0x1A0), func_00389380(FLD(D_001A4BE0, f32, 0x98), -1.57079637f)) < 0.785398185f) {
                *(s128 *)v10 = *(s128 *)(D_001A4BE0 + 0x80);
                v10[0] += func_00388960(func_00389380(FLD(D_001A4BE0, f32, 0x98), -1.57079637f)) * 0.3f;
                v10[1] += func_00388978(func_00389380(FLD(D_001A4BE0, f32, 0x98), -1.57079637f)) * 0.3f;
                if (func_L02_004B9D90((s8 *)v10, (s8 *)(D_001A4BE0 + 0x90), NULL) != 0) {
                    func_L09_00512408(0x1A, 1);
                }
            }
        }
        break;

    case 0x19:
    case 0x1A:
    {
        f32 side;
        *(s128 *)v10 = FLD(D_001A4BE0 + 0x80, s128, 0);
        side = 1.57079637f;
        if (FLD(D_001A4BE0, u32, 0x25C4) == 0x1A) {
            side = -1.57079637f;
        }
        v10[0] += func_00388960(func_00389380(FLD(D_001A4BE0, f32, 0x98), side)) * 0.3f;
        v10[1] += func_00388978(func_00389380(FLD(D_001A4BE0, f32, 0x98), side)) * 0.3f;
        func_L01_004EAA78(0, 1.0f);
        if ((FLD(D_001A4BE0, f32, 0x2838) < 0.5f) || (func_00389468(FLD(D_001A4BE0, f32, 0x1A0), func_00389380(FLD(D_001A4BE0, f32, 0x98), side)) > 0.785398185f) || (func_L02_004B9D90((s8 *)v10, (s8 *)(D_001A4BE0 + 0x90), NULL) == 0)) {
            if (FLD(D_001A4BE0, s32, 0xC08) & 2) {
                func_L09_00512408(0x18, 1);
                break;
            }
        }
        if ((FLD(D_001A4BE0, f32, 0x2838) > 0.5f) && (func_L01_0045D358(func_0039E928(0x40, 0), 9, 0, 0) != 0) && (func_00389468(FLD(D_001A4BE0, f32, 0x1A0), FLD(D_001A4BE0, f32, 0x98)) > 2.3561945f)) {
            func_L09_00512408(6, 1);
            FLD(D_001A4BE0, s8, 0x25F0) = 1;
            FLD(D_001A4BE0, s16, 0x1D0) = 0x28;
            break;
        }
        if (func_L01_0045D358(func_0039E928(0x40, 0), 9, 0, 0) != 0) {
            func_L09_00512408(0x1B, 1);
        }
        break;
    }

    case 0x7B:
        if (FLD(D_001A4BE0, s32, 0x1B8) >= 0x12D) {
            func_L01_004EA040();
        }
        if (FLD(D_001A4BE0, u8, 0x147C) == 0) {
            if (FLD(D_001A4BE0, s16, 0x36E) != 0) {
                func_L09_00512408(6, 1);
            } else {
                func_L09_00512408(0, 1);
            }
        }
        break;
    case 0x6:
    case 0x2C:
        if ((FLD(D_001A4BE0, s32, 0x25C8) == 0) && ((FLD(D_001A4BE0, s32, 0x1B8) >= 0x12) || (FLD(D_001A4BE0, f32, 0x33C) > 1.75f))) {
            func_L01_0050BB98(0xB, 0, 16.0f);
            FLD(D_001A4BE0, s32, 0x25C8) = 1;
            if (FLD(D_001A4BE0, u32, 0x25C4) == 0x2C) {
                FLD(D_001A4BE0, s32, 0x280C) = 7;
            } else {
                FLD(D_001A4BE0, s32, 0x280C) = 0;
            }
        }
        if (FLD(D_001A4BE0, s16, 0x36E) == 0) {
            func_L01_004DD470();
            if (FLD(D_001A4BE0, f32, 0x118) < -0.150000006f) {
                FLD(D_001A4BE0, f32, 0x118) = -0.150000006f;
            }
            if (FLD(D_001A4BE0, f32, 0xF8) < -0.150000006f) {
                FLD(D_001A4BE0, f32, 0xF8) = -0.150000006f;
            }
            if (FLD(D_001A4BE0, s32, 0x2850) <= 0) {
                func_L09_00512408(0x39, 1);
            } else {
                s32 one = 1;
                s32 low = FLD(D_001A4BE0, s32, 0x35C) == 0;
                if (FLD(D_001A4BE0, s32, 0x1B8) >= 0x5A) {
                    if (func_L09_00512408(0, 0) != 0) {
                        func_L01_0050BB98(0xC, 4, 6.0f);
                    }
                    if (low != 0) {
                        FLD(D_001A4BE0, s16, 0x1E0) = 0x16;
                    }
                    func_L01_0050CCC8(0xA, 4, 0, 1, 0.022f, 0.004f);
                } else if (FLD(D_001A4BE0, s32, 0x25C8) == one) {
                    if (func_L09_00512408(0, 0) != 0) {
                        func_L01_0050BB98(0xC, 9, -1.0f);
                    }
                    func_L01_0050D530(D_001A4BE0 + 0x160, D_001A4BE0 + 0x160, 0.0f);
                    func_003BF640((f32 *)(D_001A4BE0 + 0x160), 0.116666675f);
                    FLD(D_001A4BE0, s16, 0x1E0) = 7;
                    if (FLD(D_001A4BE0, s32, 0x25D0) == 0x2C) {
                        FLD(D_001A4BE0, s16, 0x1E0) = 10;
                    }
                    if ((low != 0) && (FLD(D_001A4BE0, s32, 0x1B8) >= 0x33)) {
                        FLD(D_001A4BE0, s16, 0x1E0) = 0x12;
                    }
                    func_L01_0050CCC8(0xA, 2, 0, 1, 0.019f, 0.002f);
                } else if ((FLD(D_001A4BE0, f32, 0x2838) > 0.5f) && (FLD(D_001A4BE0, s16, 0x1E0) == 0)) {
                    func_L09_00512408(2, 1);
                    func_L01_0050CCC8(7, 2, 0, 1, 0.016f, 0.002f);
                } else if (FLD(D_001A4BE0, f32, 0x174) > 0.0500000045f) {
                    if (func_L09_00512408(3, 0) != 0) {
                        func_L01_0050BB98(6, 0, 12.0f);
                        func_003BF640((f32 *)(D_001A4BE0 + 0x160), 0.12833333f);
                    }
                } else {
                    func_L09_00512408(0, 1);
                    func_L01_0050CCC8(5, 2, 0, 1, 0.016f, 0.002f);
                }
            }
        } else if (FLD(D_001A4BE0, s32, 0x2850) > 0) {
            if ((FLD(D_001D52FC, s32, 0x1A0) & func_0039E928(0x40, 0)) && (D_00142CA2[0] != 0) && (func_L01_004E5470(3) != 4) && (FLD(D_001A4BE0, s16, 0x2884) == 0) && (FLD(D_001A4BE0, s16, 0x1E0) == 0) && (FLD(D_001A4BE0, f32, 0x33C) > 0.6f)) {
                func_L09_00512408(8, 1);
                break;
            }
            if ((FLD(D_001A4BE0, s16, 0x202) >= 0x29) && (func_L01_00502368((FLD(D_001A4BE0, s16, 0x1EE) != 0) ? 1 : 6, 0) != 0)) {
                break;
            }
            if (FLD(D_001A4BE0, s32, 0x528) != 0) {
                func_L09_00512408(0x17, 1);
                break;
            }
        }
        break;

    case 0x79:
        if (FLD(D_001A4BE0, s32, 0x1B8) < 0x79) {
            break;
        }
        func_L01_004EA040();
        return;
    case 0xB0:
        if (FLD(D_001A4BE0, f32, 0x33C) < 3.0f) {
            func_L09_00512408(8, 1);
            goto end;
        }
        break;
    case 0x8:
        if ((FLD(D_001A4BE0, s32, 0x1D4) != 0) && (FLD(D_001A4BE0, s32, 0x1B8) < 9)) {
            s32 prev = FLD(D_001A4BE0, s32, 0x25D0);
            s32 ok = 0;
            if ((prev == 7) || (prev == 9) || (prev == 0xE) || (prev == 0x11)) {
                ok = 1;
            }
            if (ok != 0) {
                func_L09_00512408(0x11, 1);
            }
            break;
        }
        if ((FLD(D_001A4BE0, s32, 0x1B8) >= 0x1F) && (FLD(D_001A4BE0, s16, 0x22C) == 0) && !(FLD(D_001D52FC, s32, 0x1A0) & func_0039E928(0x40, 0)) && !(FLD(D_001D52FC, s32, 0x1C0) & func_0039E928(0x40, 0))) {
            func_L09_00512408(6, 1);
            break;
        }
        if (FLD(D_001A4BE0, s32, 0x528) != 0) {
            func_L09_00512408(0x17, 1);
            break;
        }
        if ((FLD(D_001A4BE0, s16, 0x36E) != 0) && !(FLD(D_001A4BE0, f32, 0x33C) < 0.4f)) {
            break;
        }
        if (FLD(D_001A4BE0, s32, 0x1B8) < 10) {
            FLD(D_001A4BE0, s16, 0x1EE) = 0xC - FLD(D_001A4BE0, u16, 0x1B8);
        }
        func_L01_004EAA78(0, 1.0f);
        if ((FLD(D_001A4BE0, s32, 0x25D0) == 0x10) && (FLD(D_001A4BE0, s32, 0x1B8) < 4)) {
            if (func_L09_00512408(3, 0) != 0) {
                func_L01_0050BB98(5, 0, -1.0f);
                FLD(D_001A4BE0, s16, 0x1E0) = 0x22;
            }
            break;
        }
        if (FLD(D_001D52FC, s32, 0x1A0) & func_0039E928(8, 0)) {
            func_L09_00512408(4, 1);
            func_L01_0050CCC8(5, 2, 0, 1, 0.016f, 0.002f);
            break;
        }
        if ((D_L09_001DBE0C[0] < FLD(D_001A4BE0, f32, 0x1B0)) && (func_00389468(FLD(D_001A4BE0, f32, 0x1A0), FLD(D_001A4BE0, f32, 0x98)) < 1.5707964f)) {
            if ((FLD(D_001A4BE0, u8, 0x1474) != 0) || (FLD(D_001A4BE0, u8, 0x25EA) != 0)) {
                func_L09_00512408(2, 1);
                break;
            }
            func_L09_00512408(2, 0);
            if (FLD(D_001A4BE0, u32, 0x25C4) == 2) {
                FLD(D_001A4BE0, s32, 0x25C8) = 1;
                func_L01_0050BB98(4, 2, 8.0f);
                FLD(D_001A4BE0, s8, 0x3EE) = 1;
            }
            func_L01_0050CCC8(5, 2, 1, 0, 0.016f, 0.002f);
        } else if (D_L09_001DBE0C[0] < FLD(D_001A4BE0, f32, 0x1B0)) {
            if ((FLD(D_001A4BE0, u8, 0x1474) != 0) || (FLD(D_001A4BE0, u8, 0x25EA) != 0)) {
                func_L09_00512408(2, 1);
                break;
            }
            func_L09_00512408(2, 0);
            if (FLD(D_001A4BE0, u32, 0x25C4) == 2) {
                FLD(D_001A4BE0, s32, 0x25C8) = 1;
                func_L01_0050BB98(4, D_L09_001DBE34, 12.0f);
            }
            func_L01_0050CCC8(5, 2, 1, 0, 0.016f, 0.002f);
        } else if (FLD(D_001A4BE0, s16, 0x36E) == 0) {
            if (func_L09_00512408(0, 0) != 0) {
                func_L01_0050BB98(func_L02_004B21A8(0), 0, -2.0f);
                func_L01_0050CCC8(5, 2, 0, 1, 0.016f, 0.002f);
            }
        } else if (func_L09_00512408(0, 0) != 0) {
            func_L01_0050BB98(7, 0x17, 9.0f);
            func_L01_0050CCC8(5, 2, 0, 1, 0.016f, 0.002f);
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
        if (FLD(D_001A4BE0, u8, 0x4FE) != 0) {
            s32 n = func_L01_004FB720();
            if ((n > 0) && ((FLD(D_001A4BE0, s32, 0x1B8) < n) || (FLD(D_001A4BE0, u8, 0x46C) != 0)) && (FLD(D_001A4BE0, s32, 0x360) != 0)) {
                if ((FLD(D_001A4BE0, u32, 0x25C4) != 0xB) || (func_L01_0045D358(func_0039E928(0x40, 0), 7, 0, 0) != 0)) {
                    s32 go = 1;
                    if ((FLD(D_001A4BE0, u32, 0x25C4) == 0x1B) || (FLD(D_001A4BE0, u8, 0x46C) != 0)) {
                        if (func_L01_0045D358(func_0039E928(0x40, 0), 7, 0, 0) == 0) {
                            go = 0;
                        }
                    }
                    if (FLD(D_001A4BE0, u32, 0x25C4) == 0xB) {
                        if (FLD(D_001A4BE0, u8, 0x46C) == 0) {
                            go = 0;
                        }
                    }
                    if ((go != 0) && (func_L01_0045D358(0x1F000, 5, 0, 0) != 0) && (FLD(D_001D52FC, s32, 0x1A0) & func_0039E928(8, 0))) {
                        func_L09_00512408(0xB, 1);
                        break;
                    }
                }
            }
        }
        if ((FLD(D_001A4BE0, u32, 0x25C4) == 0x1B) && (FLD(D_001A4BE0, s32, 0x1B8) >= 0xE) && (FLD(D_001A4BE0, f32, 0x298) > 1.3f)) {
            FLD(D_001A4BE0, s8, 0x25F0) = 0;
            FLD(D_001A4BE0, s8, 0x25ED) = 0;
        }
        if ((FLD(D_001A4BE0, s32, 0x1B8) < 3) && (func_L01_0045D358(func_0039E928(8, 0), 2, 0, 0) != 0) && ((sa = FLD(D_001A4BE0, u32, 0x25C4)) != 0x10) && (sa != 0xA) && (sa != 0x12) && (sa != 0x38) && (sa != 0x11) && (sa != 0xE) && (sa != 0x6B)) {
            if ((func_L01_004E5470(3) == 2) && (D_00142CA2[0] != 0) && (FLD(D_001A4BE0, s16, 0x2884) == 0) && (FLD(D_001A4BE0, f32, 0x178) > 0.0150000006f)) {
                func_L09_00512408(0xA, 1);
            } else if ((func_L01_004E5470(3) == 3) && (FLD(D_001A4BE0, s16, 0x2884) == 0) && (FLD(D_001A4BE0, f32, 0x178) > 0.0150000006f) && (FLD(D_001A4BE0, s16, 0x1E4) == 0)) {
                func_L09_00512408(0x10, 1);
            }
        }
        if (FLD(D_001A4BE0, s16, 0x4EA) < FLD(D_001A4BE0, s32, 0x1B8)) {
            if (FLD(D_001A4BE0, u8, 0x46C) == 0) {
                func_L09_00512408(6, 1);
                break;
            }
        } else if ((FLD(D_001A4BE0, u8, 0x46C) == 0) && ((FLD(D_001A4BE0, u32, 0x25C4) == 0xA) || (FLD(D_001A4BE0, u32, 0x25C4) == 0x10)) && (FLD(D_001A4BE0, f32, 0x298) < 0.9f) && (FLD(D_001A4BE0, u8, 0x2A7) != 0) && (func_00388770(D_001A4BE0 + 0xF0) > 0.116666675f)) {
            f32 a = func_00388770(D_001A4BE0 + 0x110);
            if ((a < func_00388770(D_001A4BE0 + 0xF0) * 0.5f) && (FLD(D_001A4BE0, s32, 0x528) == 0) && (FLD(D_001A4BE0, f32, 0x33C) < 2.0f)) {
                func_L01_004F10C8(0x19);
                func_L09_00512408(0x7C, 1);
                break;
            }
        }
        near = 0;
        if ((FLD(D_001A4BE0, u32, 0x25C4) == 0xE) && (FLD(D_001A4BE0, f32, 0xC18) < 35.0f)) {
            near = 1;
        }
        lo = FLD(D_001A4BE0, s16, 0x47C);
        now = FLD(D_001A4BE0, s32, 0x1B8);
        if (!(lo < now)) {
            break;
        }
        if (now == lo + 1) {
            if (FLD(D_001A4BE0, u8, 0x46D) != 0) {
                f32 left = (f32)(FLD(D_001A4BE0, s32, 0x400) - now);
                if (left > 0.0f) {
                    func_L01_004E1268(FLD(D_001A4BE0, f32, 0x408), left, FLD(D_001A4BE0, f32, 0x4E4), -1.0f);
                }
            } else if (FLD(D_001A4BE0, u32, 0x25C4) != 0xE) {
                func_L01_0050D770((f32 *)(D_001A4BE0 + 0x80), (f32 *)(D_001A4BE0 + 0xF0), &sp38, FLD(D_001A4BE0, f32, 0x4F0));
                func_L01_004E1268(FLD(D_001A4BE0, f32, 0x498), (f32)sp38, FLD(D_001A4BE0, f32, 0x4E4), -1.0f);
                if (FLD(D_001A4BE0, f32, 0xC00) > 1.5f) {
                    FLD(D_001A4BE0, f32, 0xC00) = 1.5f;
                }
            }
            break;
        }
        if ((FLD(D_001A4BE0, u8, 0x46D) != 0) && (now >= FLD(D_001A4BE0, s32, 0x400)) && (now < FLD(D_001A4BE0, s32, 0x404))) {
            f32 left = (f32)(FLD(D_001A4BE0, s32, 0x410) - FLD(D_001A4BE0, s32, 0x400));
            if (left > 0.0f) {
                func_L01_004E1268(FLD(D_001A4BE0, f32, 0x498), left, FLD(D_001A4BE0, f32, 0x4E4), -1.0f);
            }
            break;
        }
        if (FLD(D_001A4BE0, s32, 0x358) == 1) {
            func_L01_004F1068(0xC, 0);
            func_L01_004E20F0(3, 0x18, 1);
        }
        {
            u8 c = FLD(D_001A4BE0, u8, 0x46C);
            if (c != 0) {
                FLD(D_001A4BE0, u8, 0x46C) = c + 1;
            } else if ((FLD(D_001A4BE0, s16, 0x36E) == 0) && (FLD(D_001A4BE0, u8, 0x46E) != 0) && (near == 0)) {
                func_L01_004DD470();
                FLD(D_001A4BE0, u8, 0x46C) = 1;
                FLD(D_001A4BE0, s8, 0x285F) = 0;
                if ((FLD(D_001A4BE0, f32, 0x2838) < 0.2f) && (FLD(D_001A4BE0, f32, 0x1B4) > 0.0416666679f)) {
                    FLD(D_001A4BE0, f32, 0x1B4) = 0.0416666679f;
                }
                func_L01_0050CCC8(5, 2, 0, 1, 0.016f, 0.002f);
                if (near == 0) {
                    s32 k = (s32)(FLD(D_001A4BE0, f32, 0x4A0)) + 2;
                    if (FLD(D_001A4BE0, f32, 0xC18) < FLD(D_001A4BE0, f32, 0x49C) - 1.5f) {
                        func_L01_0050BB98(func_L01_004DC1A0(FLD(hero, u8, 0x43)), k, 7.0f);
                    }
                }
            }
        }
        if (FLD(D_001A4BE0, u8, 0x46C) != 0) {
            FLD(D_001A4BE0, f32, 0xC00) = 1.0f;
        } else if (FLD(D_001A4BE0, u8, 0x46E) != 0) {
            s32 cur;
            if ((s32)FLD(hero, u8, 0x41) < (s32)(FLD(D_001A4BE0, f32, 0x4A0))) {
                if ((FLD(D_001A4BE0, u32, 0x25C4) == 0xE) && (FLD(D_001A4BE0, f32, 0xC18) < 37.0f)) {
                    func_003BEBF8((f32 *)(D_001A4BE0 + 0xC00), 1.0f, 0.150000006f);
                } else {
                    FLD(D_001A4BE0, s16, 0x47E) = (s32)(func_L01_0050C4A0(60.0f, FLD(D_001A4BE0, f32, 0x4F0), -1.0f));
                    func_L01_004E1268(FLD(D_001A4BE0, f32, 0x49C), (f32)FLD(D_001A4BE0, s16, 0x47E), FLD(D_001A4BE0, f32, 0x4E4), 0.200000003f);
                }
                if (near == 0) {
                    s32 k = (s32)(FLD(D_001A4BE0, f32, 0x4A0)) + 2;
                    if (FLD(D_001A4BE0, f32, 0xC00) > 1.8f) {
                        func_L01_0050BB98(func_L01_004DC1A0(FLD(hero, u8, 0x43)), k, (f32)(FLD(D_001A4BE0, s16, 0x47E) + 3));
                    }
                }
                if (FLD(D_001A4BE0, f32, 0xC00) < 0.2f) {
                    FLD(D_001A4BE0, f32, 0xC00) = 0.2f;
                }
                if (FLD(D_001A4BE0, f32, 0xC00) > 2.7f) {
                    FLD(D_001A4BE0, f32, 0xC00) = 2.7f;
                }
            }
            cur = FLD(D_001A4BE0, u32, 0x25C4);
            if ((cur == 9) && ((FLD(D_001A4BE0, f32, 0x49C) - FLD(D_001A4BE0, f32, 0xC18)) > 6.0f) && ((func_L01_004DC1A0(FLD(hero, u8, 0x42)) == 8) || (func_L01_004DC1A0(FLD(hero, u8, 0x42)) == cur)) && (FLD(hero, u8, 0x42) == FLD(hero, u8, 0x43)) && (FLD(D_001A4BE0, f32, 0x1B0) < D_L09_001DBE0C[3] * 0.0166666675f * 0.1f) && (FLD(D_001A4BE0, f32, 0x174) < 0.0416666679f)) {
                f32 rate = 9.0f / FLD(D_001A4BE0, f32, 0xC00);
                s32 at;
                if (rate > 10.0f) {
                    rate = 10.0f;
                }
                at = (s32)(FLD(D_001A4BE0, f32, 0xC18)) + 4;
                func_L01_0050BB98(7, at / 2, rate);
                FLD(D_001A4BE0, s32, 0x25C4) = 7;
            }
            {
                s32 a = (s32)(FLD(D_001A4BE0, f32, 0xC18));
                if (a == (s32)(FLD(D_001A4BE0, f32, 0x49C))) {
                    FLD(D_001A4BE0, s32, 0xC00) = 0;
                }
            }
        }
        if (FLD(D_001A4BE0, u8, 0x46C) != 0) {
            if (FLD(D_001A4BE0, u32, 0x25C4) == 0xA) {
                if (func_L09_00512408(3, 0) != 0) {
                    func_L01_0050BB98(5, 0, -2.0f);
                    func_003886E8(D_001A4BE0 + 0x160, D_001A4BE0 + 0x160, 0.8f);
                }
                break;
            }
            if ((FLD(D_001A4BE0, u8, 0x147C) == 0) && (FLD(D_001A4BE0, s16, 0x1E0) == 0) && (func_L01_0045D358(func_0039E928(0x40, 0), 8, 0, 0) != 0) && (FLD(D_001A4BE0, s16, 0x36E) < 8)) {
                if (((FLD(D_001A4BE0, s16, 0x1434) != 0) || ((FLD(D_001A4BE0, s32, 0x16B0) == 1) && (func_L01_0045D358(0x28, 2, 0, 0) != 0))) && (FLD(D_001A4BE0, f32, 0x2838) > 0.9f) && (func_L01_004FB758() != 2)) {
                    func_L09_00512408(0xB, 1);
                } else if (!(FLD(D_001A4BE0, f32, 0x1B0) > D_L09_001DBE0C[0])) {
                    func_L09_00512408(7, 1);
                } else if (func_00389468(FLD(D_001A4BE0, f32, 0x1A0), FLD(D_001A4BE0, f32, 0x98)) < 1.04719758f) {
                    if (D_L09_001DBE0C[3] * 0.0166666675f * 0.85f < FLD(D_001A4BE0, f32, 0x174)) {
                        func_L09_00512408(9, 1);
                    } else {
                        func_L09_00512408(7, 1);
                    }
                } else {
                    func_L09_00512408(7, 1);
                }
                break;
            }
        }
        if ((FLD(D_001A4BE0, u8, 0x46C) >= 2) && (FLD(D_001A4BE0, u32, 0x25C4) != 0xA)) {
            func_L01_00502C58();
        } else if ((FLD(D_001A4BE0, u8, 0x46E) != 0) && (FLD(D_001A4BE0, s32, 0x1B8) >= FLD(D_001A4BE0, s16, 0x4FA)) && (FLD(D_001A4BE0, f32, 0x33C) > FLD(D_001A4BE0, f32, 0x4E0))) {
            func_L09_00512408(6, 1);
        }
        if ((FLD(D_001A4BE0, u32, 0x25C4) == 0x10) && (FLD(D_001A4BE0, s32, 0x1B8) >= 0x3D) && (FLD(D_001A4BE0, f32, 0x33C) > 1.5f)) {
            func_L09_00512408(6, 1);
            break;
        }
        {
            u32 s = FLD(D_001A4BE0, u32, 0x25C4);
            s32 ok = 0;
            if ((s == 7) || (s == 9) || (s == 0x11)) {
                ok = 1;
            }
            if ((FLD(D_001A4BE0, s32, 0x1D4) != 0) && (FLD(D_001A4BE0, u8, 0x46C) == 0) && (ok != 0) && ((FLD(D_001A4BE0, u32, 0x25C4) != 0x11) || (FLD(D_001A4BE0, s32, 0x1B8) >= 0x1A)) && (func_L01_0045D358(func_0039E928(0x40, 0), 7, &sp3C, 0) != 0) && (sp3C < FLD(D_001A4BE0, s32, 0x1B8))) {
                func_L09_00512408(0x11, 1);
                break;
            }
        }
        if (((FLD(D_001A4BE0, u32, 0x25C4) == 0xA) || (FLD(D_001A4BE0, u32, 0x25C4) == 0x10)) && (FLD(D_001A4BE0, s32, 0x1B8) >= 0x1A) && (FLD(D_001A4BE0, s16, 0x36A) != 0)) {
            FLD(D_001A4BE0, s16, 0x4F6) = 0x14;
        }
        sc = FLD(D_001A4BE0, u32, 0x25C4);
        lim = 0x14;
        if (sc == 0x10) {
            lim = 8;
        }
        if ((sc == 0xE) && (FLD(D_001A4BE0, f32, 0x33C) > 4.0f)) {
            if ((FLD(D_001A4BE0, u8, 0x46E) == 0) && (FLD(D_001A4BE0, f32, 0xC00) < 1.3f)) {
                func_003BEBF8((f32 *)(D_001A4BE0 + 0xC00), 1.3f, 0.100000001f);
            }
            lim = 0x11;
            FLD(D_001A4BE0, s16, 0x4F6) = lim;
        }
        frames = FLD(D_001A4BE0, s32, 0x1B8) - 4;
        if (frames <= 1) {
            frames = 2;
        }
        if (frames >= 0x1F) {
            frames = 0x1E;
        }
        if (!(FLD(D_001A4BE0, long, 0x468) & 0xFF0000FF00000000L)) {
            if ((func_L01_0045D358(func_0039E928(0x40, 0), frames, 0, 0) != 0) || (FLD(D_001A4BE0, u32, 0x25C4) == 0xE) || (FLD(D_001A4BE0, u32, 0x25C4) == 0xF) || (FLD(D_001A4BE0, u32, 0x25C4) == 0xD)) {
                if ((FLD(D_001A4BE0, u32, 0x25C4) != 0xE) && (FLD(D_001A4BE0, u8, 0x25E9) == 0) && ((FLD(D_001A4BE0, u8, 0x147C) == 0) || !(FLD(D_001A4BE0, f32, 0x33C) < 0.4f)) && (FLD(D_001A4BE0, u8, 0x4FF) != 0) && (FLD(D_001A4BE0, s32, 0x1B8) >= 0xF) && ((FLD(D_001A4BE0, u8, 0x46E) == 0) || ((FLD(D_001A4BE0, f32, 0x33C) > 0.7f) && (fabs_asm(func_L01_0050D4D8((s8 *)(D_001A4BE0 + 0xF0))) < 0.0966666713f)))) {
                    func_L09_00512408(0xE, 1);
                } else if ((D_00142CA2[0] != 0) && (func_L01_004E5470(3) != 4) && (FLD(D_001A4BE0, s16, 0x2884) == 0) && (FLD(D_001D52FC, s32, 0x1A0) & func_0039E928(0x40, 0)) && (lim < FLD(D_001A4BE0, s32, 0x1B8)) && (FLD(D_001A4BE0, s16, 0x4F6) < FLD(D_001A4BE0, s32, 0x1B8))) {
                    f32 need = 0.6f;
                    if ((FLD(D_001A4BE0, u32, 0x25C4) == 9) || (FLD(D_001A4BE0, u32, 0x25C4) == 7)) {
                        need = 1.0f;
                    }
                    if (FLD(D_001A4BE0, u32, 0x25C4) == 0xE) {
                        need = 1.5f;
                    }
                    if (need < FLD(D_001A4BE0, f32, 0x33C)) {
                        func_L09_00512408(8, 1);
                    }
                }
            }
        }
        if ((FLD(D_001A4BE0, s32, 0x528) != 0) && (FLD(D_001A4BE0, u32, 0x25C4) != 0xB)) {
            func_L09_00512408(0x17, 1);
        }
        break;
    }
    case 0xB1:
        if (FLD(D_001A4BE0, s32, 0x1B8) >= 0x29) {
            if (FLD(D_001A4BE0, s32, 0x2850) <= 0) {
                func_L09_00512408(0x39, 1);
            } else {
                func_L09_00512408(0, 1);
            }
        }
        break;
    case 0x16:
        if ((FLD(D_001A4BE0, f32, 0xC18) > 12.5f) && (FLD(D_001A4BE0, u8, 0x2877) == 0) && (FLD(D_001A4BE0, s16, 0x36E) != 0) && (FLD(D_001A4BE0, f32, 0x33C) > 1.0f)) {
            if (FLD(D_001A4BE0, s32, 0x25D0) == 0xB0) {
                if (FLD(D_001A4BE0, s32, 0x2850) <= 0) {
                    func_L09_00512408(0x79, 1);
                } else {
                    func_L09_00512408(0xB0, 0);
                    func_L01_0050BB98(0x7A, 0, 11.0f);
                }
            } else {
                func_L09_00512408(6, 1);
            }
            break;
        }
        if (FLD(D_001A4BE0, s32, 0x1B8) >= 0x1C) {
            if (FLD(D_001A4BE0, s32, 0x2850) <= 0) {
                if (FLD(D_001A4BE0, s32, 0x25D0) == 0xB0) {
                    func_L09_00512408(0x79, 1);
                } else {
                    func_L09_00512408(0x39, 1);
                }
            } else if (FLD(D_001A4BE0, u8, 0x2877) != 0) {
                func_L09_00512408(0x87, 1);
            } else if (FLD(D_001A4BE0, s32, 0x25D0) == 0xB0) {
                func_L09_00512408(0xB0, 1);
            } else {
                func_L09_00512408(0, 0);
            }
        }
        break;
    case 0x91:
        if (FLD(D_001A4BE0, s32, 0xC08) & 2) {
            func_L01_0050BB98(0x75, 0, 2.0f);
        }
        if ((FLD(D_001A4BE0, s32, 0x1B8) >= 0x33) && (FLD(D_001A4BE0, s16, 0x1E0) == 0)) {
            if (FLD(D_001A4BE0, s32, 0x2850) <= 0) {
                func_L09_00512408(0x39, 1);
            } else if (func_L09_00512408(0, 0) != 0) {
                func_L01_0050BB98(func_L02_004B21A8(0), 0, 13.0f);
            }
        }
        break;
    case 0x51:
        if (FLD(D_001A4BE0, s32, 0xC08) & 2) {
            if (FLD(FLD(D_001A4BE0, u8 *, 0x25C0), u8, 0x43) != 1) {
                func_L01_0050BB98(1, 0, 12.0f);
            } else if (func_0037E250(0.0f, 1.0f) < 0.5f) {
                func_L01_0050BB98(2, 0, 8.0f);
            }
        }
        if ((FLD(D_001D52FC, s32, 0x1A0) & func_L01_0050EE20(func_0039E928(4, 0))) && ((FLD(D_001A4BE0, u8, 0x25E4) != 0) || (D_001439F4[0] != 2) || (FLD(D_001A4BE0, s32, 0x1228) == 0x6F)) && (func_L01_003E9428(0) == 0)) {
            func_L09_00512408(1, 1);
            break;
        }
        if (FLD(D_001A4BE0, s16, 0x36E) != 0) {
            func_L09_00512408(0x53, 1);
            break;
        }
        if (FLD(D_001A4BE0, s16, 0x1E0) != 0) {
            break;
        }
        if (func_L01_0045D358(func_0039E928(0x40, 0), 8, 0, 0) != 0) {
            func_L09_00512408(0x54, 1);
            break;
        }
        if (FLD(D_001D52FC, s32, 0x1A4) & 0x20) {
            func_L09_00512408(0x59, 1);
            break;
        }
        if (func_L01_0045D358(0x80, 7, 0, 0) != 0) {
            if (FLD(D_001A4BE0, s16, 0x288C) == 0) {
                FLD(D_001A4BE0, s16, 0x2888) = 1;
                FLD(D_001A4BE0, s16, 0x288C) = 0x12;
                FLD(D_001A4BE0, s16, 0x288A) = 1;
            }
            func_L01_004E8830(0);
            break;
        }
        func_L01_004EAA78(0, 1.0f);
        if ((FLD(D_001A4BE0, f32, 0x2838) > 0.22f) && (FLD(D_001A4BE0, f32, 0x1B0) > 0.0f)) {
            func_L09_00512408(0x52, 1);
        }
        break;
    case 0x57:
        if (FLD(D_001A4BE0, s32, 0x1B8) >= 0x12D) {
            func_L01_004EA040();
        }
        if (FLD(D_001A4BE0, u8, 0x147C) == 0) {
            if (FLD(D_001A4BE0, s16, 0x36E) != 0) {
                func_L09_00512408(0x53, 1);
            } else {
                func_L09_00512408(0x51, 1);
            }
        }
        break;
    case 0x59:
        if ((FLD(D_001A4BE0, s32, 0x1B8) >= 0x2E) && !(FLD(D_001D52FC, s32, 0x1A0) & 0x20)) {
            func_L09_00512408(0x51, 0);
            func_L01_0050BB98(1, 0, 20.0f);
            break;
        }
        if (func_L01_0045D358(func_0039E928(0x40, 0), 8, 0, 0) != 0) {
            func_L09_00512408(0x54, 1);
        }
        break;
    case 0x58:
        FLD(D_001A4BE0, s8, 0x25ED) = 1;
        break;
    case 0x54:
    {
        s16 lo = FLD(D_001A4BE0, s16, 0x47C);
        s32 now = FLD(D_001A4BE0, s32, 0x1B8);
        if (!(lo < now)) {
            break;
        }
        if (now == lo + 1) {
            func_L01_0050D770((f32 *)(D_001A4BE0 + 0x80), (f32 *)(D_001A4BE0 + 0xF0), &sp40, FLD(D_001A4BE0, f32, 0x4F0));
            func_L01_004E1268(FLD(D_001A4BE0, f32, 0x498), (f32)sp40, FLD(D_001A4BE0, f32, 0x4E4), 0.25f);
            break;
        }
        if ((FLD(D_001A4BE0, u8, 0x46D) != 0) && (now >= FLD(D_001A4BE0, s32, 0x400)) && (now < FLD(D_001A4BE0, s32, 0x404))) {
            f32 left = (f32)(FLD(D_001A4BE0, s32, 0x410) - FLD(D_001A4BE0, s32, 0x400));
            if (left > 0.0f) {
                func_L01_004E1268(FLD(D_001A4BE0, f32, 0x498), left, FLD(D_001A4BE0, f32, 0x4E4), -1.0f);
            }
            break;
        }
        {
            u8 c = FLD(D_001A4BE0, u8, 0x46C);
            if (c != 0) {
                FLD(D_001A4BE0, u8, 0x46C) = c + 1;
            } else if ((FLD(D_001A4BE0, s16, 0x36E) == 0) && (FLD(D_001A4BE0, u8, 0x46E) != 0)) {
                s32 k = (s32)(FLD(D_001A4BE0, f32, 0x4A0)) + 3;
                FLD(D_001A4BE0, u8, 0x46C) = 1;
                if (FLD(D_001A4BE0, f32, 0xC18) < FLD(D_001A4BE0, f32, 0x49C)) {
                    func_L01_0050BB98(FLD(hero, u8, 0x43), k, 6.0f);
                }
            }
        }
        if (FLD(D_001A4BE0, u8, 0x46C) != 0) {
            FLD(D_001A4BE0, f32, 0xC00) = 1.0f;
        } else if (FLD(D_001A4BE0, u8, 0x46E) != 0) {
            if ((s32)FLD(hero, u8, 0x41) < (s32)(FLD(D_001A4BE0, f32, 0x4A0))) {
                s32 k;
                FLD(D_001A4BE0, s16, 0x47E) = (s32)(func_L01_0050C4A0(60.0f, FLD(D_001A4BE0, f32, 0x4F0), -1.0f));
                func_L01_004E1268(FLD(D_001A4BE0, f32, 0x49C), (f32)FLD(D_001A4BE0, s16, 0x47E), FLD(D_001A4BE0, f32, 0x4E4), -1.0f);
                k = (s32)(FLD(D_001A4BE0, f32, 0x4A0)) + 1;
                if (FLD(D_001A4BE0, f32, 0xC00) > 1.8f) {
                    func_L01_0050BB98(FLD(hero, u8, 0x43), k, (f32)(FLD(D_001A4BE0, s16, 0x47E) + 2));
                }
                if (FLD(D_001A4BE0, f32, 0xC00) < 0.2f) {
                    FLD(D_001A4BE0, f32, 0xC00) = 0.2f;
                }
                if (FLD(D_001A4BE0, f32, 0xC00) > 2.7f) {
                    FLD(D_001A4BE0, f32, 0xC00) = 2.7f;
                }
            }
            {
                s32 a = (s32)(FLD(D_001A4BE0, f32, 0xC18));
                if (a == (s32)(FLD(D_001A4BE0, f32, 0x49C))) {
                    FLD(D_001A4BE0, s32, 0xC00) = 0;
                }
            }
        }
        if ((FLD(D_001A4BE0, u8, 0x46C) != 0) && (FLD(D_001A4BE0, s16, 0x1E0) == 0) && (FLD(D_001A4BE0, u8, 0x147C) == 0) && (func_L01_0045D358(func_0039E928(0x40, 0), 4, 0, 0) != 0) && (FLD(D_001A4BE0, s16, 0x36E) < 4)) {
            func_L01_004EAA78(0, 1.0f);
            func_L09_00512408(0x54, 1);
            break;
        }
        if (FLD(D_001A4BE0, u8, 0x46C) >= 2) {
            FLD(D_001A4BE0, s32, 0x280C) = 0;
            func_L01_004EAA78(0, 1.0f);
            if ((FLD(D_001A4BE0, f32, 0x1B0) > D_L09_001DBE0C[0]) && (FLD(D_001A4BE0, f32, 0x2838) > 0.5f) && (FLD(D_001A4BE0, u8, 0x147C) == 0) && (FLD(D_001A4BE0, s16, 0x1E0) == 0) && (func_00389468(FLD(D_001A4BE0, f32, 0x1A0), FLD(D_001A4BE0, f32, 0x98)) < 1.57079637f)) {
                func_L09_00512408(0x52, 1);
            } else if (FLD(D_001A4BE0, u8, 0x46C) >= 0xD) {
                func_L09_00512408(0x51, 1);
            }
        }
        if ((FLD(D_001A4BE0, f32, 0x33C) > 2.0f) && (FLD(D_001A4BE0, u8, 0x46E) != 0) && (FLD(D_001A4BE0, s32, 0x1B8) >= 0x29)) {
            func_L09_00512408(0x53, 1);
        }
        break;
    }
    case 0x53:
        if (FLD(D_001A4BE0, s16, 0x36E) == 0) {
            if (FLD(D_001A4BE0, f32, 0x118) < -0.150000006f) {
                FLD(D_001A4BE0, f32, 0x118) = -0.150000006f;
            }
            if (FLD(D_001A4BE0, f32, 0xF8) < -0.150000006f) {
                FLD(D_001A4BE0, f32, 0xF8) = -0.150000006f;
            }
            if (FLD(D_001A4BE0, s32, 0x2850) <= 0) {
                func_L09_00512408(0x56, 1);
                break;
            }
            if ((FLD(D_001A4BE0, f32, 0x2838) > 0.5f) && (FLD(D_001A4BE0, s32, 0x1B8) < 0x28) && (FLD(D_001A4BE0, s16, 0x1E0) == 0)) {
                func_L09_00512408(0x52, 1);
                break;
            }
            func_L09_00512408(0x51, 0);
            func_L01_0050BB98(0x16, 0, -1.0f);
            FLD(D_001A4BE0, f32, 0xC00) = 0.35f;
            FLD(D_001A4BE0, s16, 0x1E0) = 0x14;
        }
        break;
    case 0x52:
        FLD(D_001A4BE0, f32, 0xC00) = FLD(D_001A4BE0, f32, 0x170) * D_L09_001DBD50;
        if (FLD(D_001A4BE0, f32, 0xC00) < 1.0f) {
            FLD(D_001A4BE0, f32, 0xC00) = 1.0f;
        }
        if ((FLD(D_001A4BE0, s16, 0x36E) >= 5) && ((FLD(D_001A4BE0, f32, 0x33C) > 0.8f) || (FLD(D_001A4BE0, f32, 0x340) > 0.87266463f))) {
            func_L09_00512408(0x53, 1);
            break;
        }
        if (FLD(D_001A4BE0, s16, 0x1E0) != 0) {
            func_L09_00512408(0x51, 1);
        }
        if (func_L01_0045D358(func_0039E928(0x40, 0), 8, 0, 0) != 0) {
            func_L09_00512408(0x54, 1);
            break;
        }
        if (func_L01_0045D358(0x80, 7, 0, 0) != 0) {
            if (FLD(D_001A4BE0, s16, 0x288C) == 0) {
                FLD(D_001A4BE0, s16, 0x2888) = 1;
                FLD(D_001A4BE0, s16, 0x288C) = 0x12;
                FLD(D_001A4BE0, s16, 0x288A) = 1;
            }
            func_L01_004E8830(0);
            break;
        }
        if (FLD(D_001D52FC, s32, 0x1A4) & 0x20) {
            func_L09_00512408(0x59, 1);
            break;
        }
        if ((FLD(D_001A4BE0, s16, 0x36E) == 0) && (FLD(D_001A4BE0, f32, 0x2838) < 0.17f)) {
            func_L09_00512408(0x51, 1);
        }
        break;
    case 0x55:
        if ((FLD(D_001A4BE0, s32, 0x1B8) >= 0x20) && (FLD(D_001A4BE0, s16, 0x36E) != 0) && (FLD(D_001A4BE0, f32, 0x33C) > 1.0f)) {
            func_L09_00512408(0x53, 1);
            break;
        }
        if (FLD(D_001A4BE0, s32, 0xC08) & 2) {
            func_L09_00512408(0x51, 1);
            break;
        }
        if (FLD(D_001A4BE0, s32, 0x1B8) >= 0x2E) {
            if (FLD(D_001A4BE0, s32, 0x2850) <= 0) {
                func_L09_00512408(0x56, 1);
            } else {
                func_L09_00512408(0x51, 0);
            }
        }
        break;
    case 0x1D:
        if ((FLD(D_001A4BE0, u8, 0x25E4) == 0) && ((FLD(D_001A4BE0, u8, 0x25EB) == 0) || (FLD(D_001A4BE0, u8, 0x25E5) != 0))) {
            if (FLD(D_001D52FC, s32, 0x1A0) & func_0039E928(8, 0)) {
                func_L01_0050BB98(0xD, 0, 8.0f);
            } else {
                func_L01_0050BB98(func_L02_004B21A8(1), 0, 8.0f);
            }
        }
        if (!(FLD(D_001D52FC, s32, 0x1A0) & func_0039E928(4, 0))) {
            if (FLD(D_001A4BE0, u32, 0x25C4) == 0x1D) {
                s32 anim;
                func_L09_00512408(0, 0);
                anim = func_L02_004B21A8(1);
                if (FLD(FLD(D_001A4BE0, u8 *, 0x25C0), u8, 0x43) != anim) {
                    func_L01_0050BB98(anim, 0, 8.0f);
                }
            }
            D_L09_001D60F8 = 0;
        }
        break;

    case 0x22:
        if (FLD(D_001A4BE0, f32, 0xC18) > 19.0f) {
            if (func_L01_0045D358(func_0039E928(0x40, 0), 11, 0, 0) != 0) {
                if (FLD(D_001D52FC, s32, 0x1A0) & func_0039E928(8, 0)) {
                    func_L01_00502ED8();
                    break;
                }
                func_L09_00512408(7, 1);
                break;
            }
        }
        if (FLD(D_001A4BE0, f32, 0xC18) >= 21.0f) {
            func_L09_00512408(0, 0);
        }
        break;

    default:
        break;
    }
end:
    if (mode != FLD(D_001A4BE0, s32, 0x25CC)) {
        func_L01_004DD850();
    }
    sel = FLD(D_001A4BE0, s32, 0x25D0);
    if (((sel == 0x3C) && (FLD(D_001A4BE0, s32, 0x25C4) != 0x3D)) || ((sel == 0x3D) && (FLD(D_001A4BE0, s32, 0x1A04) != 0))) {
        func_L01_005028C8();
    }
    if (sub != FLD(D_001A4BE0, s32, 0x25C8)) {
        FLD(D_001A4BE0, s32, 0x1C0) = 0;
    }
    if (anim != FLD(hero, u8, 0x43)) {
        FLD(D_001A4BE0, s32, 0x1C4) = 0;
    }
}
/* localdecomp:end func_L09_00518BB8 */

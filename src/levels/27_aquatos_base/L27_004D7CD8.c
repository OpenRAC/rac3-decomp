#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L27_004D7CD8 */
/* func_L27_004D7CD8: the hero's state decider (Aquatos), a 178-way switch on the state at D_001A4BE0+0x25C4
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
extern char D_00188660[];
extern char D_001A4BE0[];
extern char D_00189F10[];
extern u8 D_00143A06[];
extern u8 D_00142CA2[];
extern s32 D_001A79F0;
extern f32 D_L27_001DBD84[] __attribute__((section(".sdata")));
extern f32 D_L27_001DBCD0;
__asm__(".extern D_L27_001DBCD0, 4");
extern s32 D_L27_001DBDB4;
__asm__(".extern D_L27_001DBDB4, 16");
extern s32 D_L27_001D6740;
__asm__(".extern D_L27_001D6740, 16");
extern s32 D_L27_001D673C;
__asm__(".extern D_L27_001D673C, 16");
extern u8 D_001439F4[];
extern f32 D_L27_001DE9B0;
__asm__(".extern D_L27_001DE9B0, 16");
extern s32 D_L27_002D3EF0[];
extern s32 D_L27_001DE8C8;
extern u8 D_001D60F8;
extern s32 D_L27_001DBC50[2];
__asm__(".extern D_L27_001DBC50, 8");
extern s32 D_L27_001DBC60[2];
__asm__(".extern D_L27_001DBC60, 8");
extern s32 D_L27_001DBDB0[2];
__asm__(".extern D_L27_001DBDB0, 8");
extern char D_L27_002F6AB0[];
extern char D_L27_002F6CC0[];
typedef struct { s32 w[11]; } Rec2C;
extern Rec2C D_L27_002F8A50[];
extern char D_L27_002C7F00[];
extern char D_L27_001E1680[];
s32 func_002761F8(void *, void *, s32, void *, s32);
s32 func_00277258(void *, s32, void *, f32);
s32 func_0038CAD0(void *);
s32 func_0038CB00(s16 *);
void func_00282CC0(void *, void *, void *);
void func_0038CE20(void *, void *, f32);
f32 func_0038CEA8(void *);
f32 func_00282E20(void *);
f32 func_0038CED8(void *);
f32 func_0038CF00(void *, void *);
f32 func_0038CF38(void *, void *);
void func_00282F20(void *, void *, f32);
f32 func_0038D098(f32);
f32 func_0038D0B0(f32);
f32 func_0038DAB8(f32 a0, f32 a1);
f32 func_0038DBA0(f32 a0, f32 a1);
void func_00393348(s32, s32, void *, void *, void *, s32, s32);
void func_00393BE8(u8 *object);
void func_00393C40(s8 *);
s32 func_00394620(s8 *);
void func_00394F48(void *a0);
void func_00394F90(u8 *object);
void func_00395478();
void func_003C2F58(s8 *a0, s32 a1, s8 *a2);
void func_003C3A10(u8 *object, s32 animation, s32 frame, s32 rate);
s32 func_00382498(s32 a0, s32 a1);
f32 func_003824E0(f32 a0, f32 a1);
f32 func_003C4138(f32 *value, f32 target, f32 step);
void func_003C4BB0(f32 *, f32);
s32 func_003A3BB8(s32 a0, s32 a1);
s32 func_L01_00512DF8(s32 a0);
s32 func_L04_004EFEC0(s32 arg);
u32 func_L01_004DFE80(u32 param_1);
void func_L01_004E1180(void);
void func_L01_004E11C0(s32 kind, s32 side, s32 play_sound, s32 duration);
void func_L01_004E1560(void);
void func_L01_004E5030(f32 arg0, f32 arg1, f32 arg2, f32 arg3);
void func_L01_004E5EB8(s32 dust, s32 debris, s32 model);
s32 func_L01_004E63F0(f32 *out, f32 scale, f32 amount);
s32 func_L01_004E8318(s8 *, s8 *, s8 *);
s32 func_L01_004E9238(s32 index);
void func_L01_004EAA80(void);
void func_L01_004EDE10(void);
s32 func_L01_004EDFA8(u8 *object);
s32 func_L01_00513EF0(void);
s32 func_L01_004EDFC8(f32 x);
s32 func_L00_002B3998(f32 value);
void func_L01_004EE850(s32, f32);
void func_L01_004EEBA8(void);
s32 func_L01_004F4E70(s32 index, s32 flags);
s32 func_L01_004FF5D8(void);
s32 func_L01_004FF610(void);
void func_L01_004F4ED0(s32);
void func_L01_004EC600(s32);
s32 func_L27_004D1568(s32, s32);
void func_L01_00504E38(s32 a0);
s32 func_L01_00504EC0(void);
s32 func_L01_00504F70(void);
s32 func_L01_00504FE0(void);
s32 func_L27_004D59A0(void);
s32 func_L01_00506298(s32 arg0, s32 arg1);
void func_L01_005063E8(void);
void func_L01_00506820(void);
s32 func_L01_00506888(s32 *selected);
void func_L04_00512970(void);
s32 func_L01_00506E30(void);
s32 func_L01_005070E0(void);
s32 func_L01_00507268(void);
void func_L01_00507380(void);
void func_L01_005075D8(void);
void func_L01_00507738(void);
void func_L01_0050F368(void);
void func_L01_0050FB40(s32 a0, s32 a1, f32 f12);
void func_L01_0050FED0(void);
void func_L01_0050FEE8(s32 value);
f32 func_L01_00510478(f32 time, f32 acceleration, f32 height);
void func_L01_00510CA0(s16, u8, u8, u8, f32, f32);
void func_L00_002D36E0(f32 *p, s32 flag, f32 x, f32 y, f32 z);
f32 func_L01_005114B0(s8 *in);
void func_L01_00511508(void *dst, void *src, f32 k);
f32 func_L01_00511748(f32 *a0, f32 *a1, s32 *out, f32 scale);
void func_003E54E0(s32 argument);
void func_003E4D10(s32 argument);
f32 func_L00_0031B9F8(f32 *a0, f32 *a1, s32 *a2, f32 factor);
f32 func_L00_0031CDD0(f32 *a, f32 *b, f32 *out, f32 d, f32 e);
void func_L01_00456230(u8 *entity, s32 enabled);
s32 func_L01_004606E8(s32 mask, s32 arg1, s32 a2, s32 a3);
void func_002E59F8(s32 a0);
void *func_L01_0046E078(s8 *object,void *position,f32 *velocity,s32 *config,s32 flag);
s32 func_L00_00341820(void *path, void *out, s32 *index, f32 *offset, s32 wrap, f32 step);
s32 func_L00_00341FA8(void *, void *, void *, s32 *, f32 *, s32, f32, f32, f32);
void func_L00_0038B888(void *position,s32 count);
s32 func_L01_003EB2D8(s32);
s32 func_L04_004FCAF0(s32);
s32 func_L00_002AD868(s8 *, void **, s128 *, void *, void *, s32 *, void *, s32, s32);

void func_L18_002C4000(void);
void func_L27_004D7CD8(void) {
    f32 v10[4] __attribute__((aligned(16)));
    f32 v20[4] __attribute__((aligned(16)));
    f32 v30[4] __attribute__((aligned(16)));
    s32 sp30;
    s32 sp34;
    s32 sp38;
    s32 sp3C;
    s32 sp40;
    s32 sp44;
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
        func_L04_004FCAF0(0);
    } else if (func_L04_004FCAF0(1) != 0) {
        goto end;
    }
    func_L01_00507380();
    if ((FLD(D_001A4BE0, s32, 0x2850) <= 0) && ((FLD(D_001A4BE0, s32, 0x25C4) == 0) || (FLD(D_001A4BE0, s32, 0x25C4) == 2))) {
        func_L27_004D1568(0x39, 1);
        goto end;
    }
    if (func_L27_004D59A0() != 0) {
        goto end;
    }
    if ((func_L01_00504FE0() != 0) || (func_L01_00504F70() != 0) || (func_L01_00504EC0() != 0)) {
        goto end;
    }
    if (((FLD(D_001D52FC, s32, 0x1A4) & 0x10) || (FLD(D_001D52FC, s32, 0x1C4) & 0x10)) && (FLD(D_001A4BE0, u8, 0x121C) != 2)
        && (D_L27_002D3EF0[0] == 0) && (D_00143A06[0] == 0) && (D_L27_001DE8C8 >= 8) && (FLD(D_001A4BE0, s32, 0x25C4) != 0x58)) {
        if (((FLD(D_001A4BE0, u8, 0x25ED) == 0) || (FLD(D_001A4BE0, u8, 0x25E4) == 1) || (FLD(D_001A4BE0, s16, 0x1D2) != 0))
            && ((FLD(D_001A4BE0, u8, 0x25E8) == 0) || (FLD(D_001A4BE0, u8, 0x25E4) == 1) || (FLD(D_001A4BE0, s16, 0x1D2) != 0))
            ) {
            switch (FLD(D_001A4BE0, u8, 0x25E4)) {
            case 0:
            case 3:
                if (FLD(D_001A4BE0, s16, 0x2882) != 0) {
                    FLD(D_001A4BE0, s16, 0x287E) = 0x16;
                } else {
                    FLD(D_001A4BE0, s16, 0x287E) = 0xC;
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
    if ((FLD(D_001A4BE0, f32, 0x88) < D_L27_001DE9B0) && (FLD(D_001A4BE0, f32, 0x33C) > 2.0f) && (FLD(D_001A4BE0, u8, 0x25E4) != 2)
        && (FLD(D_001A4BE0, s32, 0x25C4) != 0x79)) {
        func_L27_004D1568(0x79, 1);
        goto end;
    }
    switch (FLD(D_001A4BE0, u32, 0x25C4)) {
    case 0x0:
    {
        s32 cur;
        u8 *obj;
        if ((FLD(D_001D52FC, s32, 0x1A0) & func_L01_00512DF8(func_003A3BB8(4, 0)))
            && ((FLD(D_001A4BE0, u8, 0x25E4) != 0) || (D_001439F4[0] != 2) || (FLD(D_001A4BE0, s32, 0x1228) == 0x6F))
            && (func_L01_003EB2D8(0) == 0)) {
            func_L27_004D1568(1, 1);
            goto end;
        }
        func_L01_0050FED0();
        if (FLD(D_001A4BE0, u8, 0x2877) != 0) {
            func_L27_004D1568(0x87, 1);
            goto end;
        }
        {
        s32 one = 1;
        FLD(D_001A4BE0, s8, 0x1436) = 0;
        if (FLD(D_001A4BE0, s32, 0x1314) == 2) {
            obj = FLD(D_001A4BE0, u8 *, 0x12F0);
            if ((obj != NULL) && (FLD(obj, u8, 0x60) & 2) && (FLD(obj, u8, 0x43) != one)) {
                func_003C3A10(obj, one, 0, 6);
            }
            obj = FLD(D_001A4BE0, u8 *, 0x12F4);
            if ((obj != NULL) && (FLD(obj, u8, 0x60) & 2) && (FLD(obj, u8, 0x43) != 1)) {
                func_003C3A10(obj, 1, 0, 6);
            }
        }
        }
        if ((FLD(D_L27_002F6CC0, f32, 0x258) > 0.61086524f) || (FLD(D_L27_002F6CC0, f32, 0x254) > 0.43633232f)) {
            obj = FLD(D_001A4BE0, u8 *, 0x12F0);
            if ((obj != NULL) && (FLD(obj, u8, 0x43) != 1)) {
                func_003C3A10(obj, 1, 0, 0xA);
            }
            obj = FLD(D_001A4BE0, u8 *, 0x12F4);
            if ((obj != NULL) && (FLD(obj, u8, 0x43) != 1)) {
                func_003C3A10(obj, 1, 0, 0xA);
            }
        }
        cur = func_L01_004DFE80(FLD(hero, u8, 0x43));
        if ((cur == func_L04_004EFEC0(0)) && (FLD(D_001A4BE0, s32, 0x1228) != 0x12)) {
            if (func_L01_00506888(&sp30) != 0) {
                u8 *rec;
                FLD(D_001A4BE0, s16, 0x208) = 0x64;
                FLD(D_001A4BE0, s32, 0x27F8) = sp30;
                rec = D_L27_002F6AB0 + sp30 * 0x70;
                FLD(rec, s32, 0x60) = FLD(rec, f32, 0x5C) * 50.0f;
                if (FLD(rec, s32, 0x44) != 0) {
                    func_L27_004D1568(0x3C, 1);
                } else {
                    func_L01_0050FB40(FLD(rec, s32, 0x48), 0, 10.0f);
                }
            }
        } else if (FLD(D_001A4BE0, s32, 0xC08) & 2) {
            s32 keep = 0;
            if ((FLD(D_001A4BE0, u8, 0x25E9) != 0) && (FLD(D_001A4BE0, u8, 0x25EB) != 0) && ((FLD(FLD(D_001A4BE0, u8 *, 0x25C0), u8, 0x43) == FLD(D_001A4BE0, s32, 0x2830)) || (FLD(D_001A4BE0, s32, 0xE78) != 0))) {
                keep = 1;
            }
            if (keep == 0) {
                FLD(D_001A4BE0, s8, 0x25E9) = 0;
                if (func_L04_004EFEC0(0) == 0x4A) {
                    func_L01_0050FB40(func_L04_004EFEC0(0), 0, 15.0f);
                } else {
                    func_L01_0050FB40(func_L04_004EFEC0(0), 0, -2.0f);
                }
            }
        }
        if (FLD(D_001A4BE0, s32, 0x1B8) >= 9) {
            u8 *o2 = FLD(D_001A4BE0, u8 *, 0x12F4);
            if ((o2 != NULL) && (FLD(o2, u8, 0x43) == 1) && (func_0038CAD0(D_001A4BE0 + 0x2870) != 0) && (FLD(D_L27_002F6CC0, f32, 0x258) < 0.55850536f) && (FLD(D_L27_002F6CC0, f32, 0x254) < 0.34906584f) && (FLD(D_001A4BE0, s32, 0x1314) == 2)) {
                FLD(D_001A4BE0, s32, 0x2870) = func_00382498(0x5C, 0xE1);
                func_L01_0050F368();
            }
        }
        if ((FLD(D_001A4BE0, u8, 0x25E9) != 0) && (FLD(D_001A4BE0, s32, 0xC0C) == 0) && (FLD(D_001A4BE0, u8, 0x25EB) != 0) && (FLD(D_001A4BE0, s16, 0x2874) == 0)
            && ((D_001439F4[0] != 1) || (fabs_asm(FLD(D_001A4BE0, f32, 0x15A0)) < 0.17453292f))) {
            s32 idx = func_L01_004E9238(0);
            if (idx != FLD(D_001A4BE0, s32, 0x2834)) {
                func_L01_004EAA80();
            } else {
                s32 a = FLD(D_L27_002C7F00 + D_001425C0[idx] * 0xF0, s32, 0x24);
                if (FLD(FLD(D_001A4BE0, u8 *, 0x25C0), u8, 0x43) != a) {
                    if (FLD(D_001A4BE0, s32, 0xE78) != 0) {
                        FLD(D_001A4BE0, s32, 0xE84) = 1;
                    }
                    FLD(D_001A4BE0, s32, 0x2830) = a;
                    func_L01_0050FB40(a, 0, -4.0f);
                }
            }
        }
        func_L01_004EE850(0, 1.0f);
        if ((FLD(D_001A4BE0, u8, 0x147C) != 0) && (FLD(D_001A4BE0, s16, 0x36C) == 0)) {
            func_L27_004D1568(0x7B, 1);
            goto end;
        }
        if ((FLD(D_001A4BE0, s16, 0x36E) >= 4) && (FLD(D_001A4BE0, f32, 0x33C) > 0.4f)) {
            if ((FLD(D_001A4BE0, s32, 0x25D0) != 8) || (FLD(D_001A4BE0, s32, 0x1B8) >= 0xC)) {
                func_L27_004D1568(6, 1);
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
                if (FLD(D_001A4BE0, s32, 0x1B8) <= 3) {
                    ok = 0;
                }
            }
            if (ok && (FLD(D_001A4BE0, s16, 0x368) != 1)) {
                if (func_L01_00506298((FLD(D_001A4BE0, s16, 0x1EE) != 0) ? 1 : 6, 0) != 0) {
                    break;
                }
            }
        }
        if ((FLD(D_001A4BE0, s16, 0x368) == 1) && (D_L27_001D6740 == 0) && (func_L01_004606E8(func_003A3BB8(0x40, 0), 6, 0, 0) != 0)) {
            func_L27_004D1568(0x73, 1);
            goto end;
        }
        if ((FLD(D_001D52FC, s32, 0x1A0) & func_003A3BB8(8, 0)) && (FLD(D_001A4BE0, s32, 0x360) != 0)) {
            if ((FLD(FLD(D_001A4BE0, u8 *, 0x25C0), u8, 0x43) != 0x1A) || !(FLD(D_001A4BE0, f32, 0xC18) < 108.0f)) {
                func_L27_004D1568(4, 1);
                goto end;
            }
        }
        {
            s32 go = 1;
            s32 turned;
            if (((FLD(D_001A4BE0, s32, 0x25D0) == 1) || (FLD(D_001A4BE0, s32, 0x25D0) == 0x1D)) && (FLD(D_001A4BE0, s32, 0x1B8) < 0x14) && (FLD(D_001A4BE0, s16, 0x368) != 1)) {
                func_L01_004EE850(0, 1.0f);
                if ((func_0038DBA0(FLD(D_001A4BE0, f32, 0x1A0), FLD(D_L27_001E1680, f32, 0x18)) > 1.2217305f) && (func_0038CF00(D_001A4BE0 + 0x80, D_L27_001E1680) < 2.5f)) {
                    go = 0;
                }
            }
            turned = func_L01_004EDFC8(0.17453292f);
            if (go == 0) {
                break;
            }
            if ((turned != 0) || (FLD(D_001A4BE0, f32, 0x2838) > 0.22f)) {
                s32 side = FLD(D_001A4BE0, u8, 0x147F);
                func_L01_004E11C0(side, 0, 0, 0x1E);
                func_L01_004E11C0(side, 1, 0, 0x1E);
                func_L27_004D1568(2, 1);
                goto end;
            }
        }
        break;
    }
    case 0x3C:
        if ((FLD(D_001D52FC, s32, 0x1A0) & func_L01_00512DF8(func_003A3BB8(4, 0))) && ((FLD(D_001A4BE0, u8, 0x25E4) != 0) || (D_001439F4[0] != 2) || (FLD(D_001A4BE0, s32, 0x1228) == 0x6F)) && (func_L01_003EB2D8(0) == 0)) {
            func_L27_004D1568(1, 1);
            break;
        }
        if ((FLD(D_001A4BE0, s16, 0x36E) != 0) || (FLD(D_001D52FC, s32, 0x1A0) & func_003A3BB8(0x40, 0)) || (FLD(D_001D52FC, s32, 0x1A0) & func_003A3BB8(8, 0))) {
            func_L27_004D1568(0x3D, 1);
            break;
        }
        func_L01_004EEBA8();
        if (FLD(D_001A4BE0, f32, 0x1B0) > 0.0f) {
            func_L27_004D1568(0x3D, 1);
            break;
        }
        if (FLD(D_001A4BE0, s32, 0xC08) & 2) {
            func_L01_00506820();
            func_L27_004D1568(0, 1);
        }
        break;

    case 0x3D:
        if (FLD(D_001A4BE0, s32, 0x1B8) < 8) {
            break;
        }
        func_L01_00506820();
        if (FLD(D_001A4BE0, s16, 0x36E) != 0) {
            func_L27_004D1568(6, 1);
            break;
        }
        if (func_L01_00506298(6, 0) != 0) {
            break;
        }
        if (FLD(D_001D52FC, s32, 0x1A0) & func_003A3BB8(8, 0)) {
            func_L27_004D1568(4, 1);
            break;
        }
        func_L01_004EEBA8();
        if (FLD(D_001A4BE0, f32, 0x1B0) > 0.0f) {
            func_L27_004D1568(2, 1);
            break;
        }
        func_L27_004D1568(0, 1);
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
                func_0038CB00(D_001A4BE0 + 0x21E);
                return;
            }
            if ((FLD(D_001A4BE0, s32, 0x25C4) == 0xA0) && (FLD(D_001A4BE0, s32, 0x1B8) < 0x44)) {
                return;
            }
            func_L01_004EDE10();
            return;
        }
        if (func_0038CAD0(D_001A4BE0 + 0x23C) == 2) {
            func_L01_004EDE10();
        }
        break;
    case 0x32:
    case 0x34:
    {
        u32 st = FLD(D_001A4BE0, u32, 0x25C4);
        if (st == 0x32) {
            f32 h;
            FLD(D_001A4BE0, f32, 0xC00) = FLD(D_001A4BE0, f32, 0x1B4) * 12.5f;
            if (FLD(D_001A4BE0, f32, 0xC00) < 0.25f) {
                FLD(D_001A4BE0, f32, 0xC00) = 0.25f;
            }
            if (FLD(D_001A4BE0, f32, 0xC00) > 0.75f) {
                FLD(D_001A4BE0, f32, 0xC00) = 0.75f;
            }
            if ((FLD(D_001A4BE0, u32, 0x25C4) == st) && !(FLD(D_001D52FC, s32, 0x1A0) & 0xC0) && ((h = FLD(D_001A4BE0, f32, 0xC18)) > 9.0f) && (h < 19.0f) && (FLD(D_001A4BE0, s32, 0x25C8) != 1) && (FLD(D_001A4BE0, f32, 0x2838) < 0.1f) && (FLD(D_001A4BE0, f32, 0x1B4) < 0.040000003f)) {
                func_L27_004D1568(0x33, 1);
                break;
            }
        }
        if ((FLD(D_001A4BE0, s16, 0x2884) == 0) && (FLD(D_001D52FC, s32, 0x1A0) & 0xA)) {
            if ((FLD(D_001A4BE0, u32, 0x25C4) == 0x32) && (FLD(D_001A4BE0, s32, 0x1B8) >= 0x12)) {
                func_L27_004D1568(0x34, 1);
                break;
            }
        } else if (FLD(D_001A4BE0, u32, 0x25C4) == 0x34) {
            if (FLD(D_001A4BE0, f32, 0x2838) > 0.5f) {
                func_L27_004D1568(0x32, 1);
                break;
            }
        }
        if (FLD(D_001A4BE0, u32, 0x25C4) == 0x34) {
            s32 pad = FLD(D_001D52FC, s32, 0x1A0);
            if (!(pad & 0xC0) && (FLD(D_001A4BE0, s32, 0x25C8) != 1) && (FLD(D_001A4BE0, f32, 0x2838) < 0.7f) && !(pad & 0xA)) {
                func_L27_004D1568(0x33, 1);
            }
        }
        break;
    }

    case 0x33:
    {
        s32 pad;
        if ((FLD(D_001A4BE0, s32, 0xC08) & 2) && (FLD(FLD(D_001A4BE0, u8 *, 0x25C0), u8, 0x43) != 0x37)) {
            func_L01_0050FB40(0x37, 0, 9.0f);
        }
        if ((FLD(D_001A4BE0, f32, 0x2838) > 0.2f) || ((pad = FLD(D_001D52FC, s32, 0x1A0)) & 0xC0) || ((FLD(D_001A4BE0, s16, 0x2884) == 0) && (pad & 0xA))) {
            if (FLD(D_001A4BE0, s16, 0x2884) != 0) {
                func_L27_004D1568(0x32, 1);
            } else if (FLD(D_001D52FC, s32, 0x1A0) & 0xA) {
                func_L27_004D1568(0x34, 1);
            } else {
                func_L27_004D1568(0x32, 1);
            }
        }
        break;
    }

    case 0x36:
        if ((FLD(D_001A4BE0, s16, 0x1F8) == 0) && (func_L01_004606E8(func_003A3BB8(0x40, 0), 7, 0, 0) != 0) && (FLD(D_001A4BE0, s32, 0x1B8) >= 9)) {
            func_L27_004D1568(0x12, 1);
            break;
        }
        FLD(D_001A4BE0, u8, 0x25E8) = 1;
        if ((FLD(D_001A4BE0, s16, 0x1FE) == 0) && (FLD(FLD(FLD(D_001A4BE0, u8 *, 0x25C0), u8 *, 0x24), s32, 0x120) != 0)) {
            if ((func_L01_004606E8(0x80, 6, 0, 0) != 0) || ((FLD(D_001A4BE0, s16, 0x2884) == 0) && (func_L01_004606E8(0xA, 6, 0, 0) != 0))) {
                if (FLD(D_001A4BE0, s16, 0x2884) != 0) {
                    func_L27_004D1568(0x32, 1);
                } else if (FLD(D_001D52FC, s32, 0x1A0) & 0xA) {
                    func_L27_004D1568(0x34, 1);
                } else {
                    func_L27_004D1568(0x32, 1);
                }
                break;
            }
        }
        if ((FLD(D_001A4BE0, u8, 0x25EA) != 0) && (FLD(D_001A4BE0, f32, 0x2848) < 0.4f) && (func_L27_004D1568(0, 0) != 0)) {
            func_L01_0050FB40(func_L04_004EFEC0(0), 0, 15.0f);
        }
        if ((FLD(D_001A4BE0, f32, 0x2838) > 0.2f) && (FLD(D_001A4BE0, s32, 0x1B8) >= 9)) {
            func_L27_004D1568(0x35, 1);
        }
        break;

    case 0x35:
        if ((FLD(D_001A4BE0, s16, 0x1F8) == 0) && (func_L01_004606E8(func_003A3BB8(0x40, 0), 7, 0, 0) != 0)) {
            func_L27_004D1568(0x12, 1);
            break;
        }
        if ((FLD(D_001A4BE0, s16, 0x1FE) == 0) && (FLD(FLD(FLD(D_001A4BE0, u8 *, 0x25C0), u8 *, 0x24), s32, 0x120) != 0) && (func_L01_004606E8(0x80, 6, 0, 0) != 0)) {
            if (FLD(D_001A4BE0, s16, 0x2884) != 0) {
                func_L27_004D1568(0x32, 1);
            } else if (FLD(D_001D52FC, s32, 0x1A0) & 0xA) {
                func_L27_004D1568(0x34, 1);
            } else {
                func_L27_004D1568(0x32, 1);
            }
            break;
        }
        if ((FLD(D_001A4BE0, f32, 0x2838) < 0.1f) && (FLD(D_001A4BE0, f32, 0x1B4) == 0.0f) && (FLD(D_001A4BE0, s32, 0x728) == 0)) {
            func_L27_004D1568(0x36, 1);
        }
        break;

    case 0x78:
        if (FLD(D_001A4BE0, s32, 0x2850) <= 0) {
            func_L27_004D1568(0x6C, 1);
            func_L01_0050FB40(0x4F, 0x28, 15.0f);
        } else if (FLD(D_001A4BE0, s32, 0xC08) & 2) {
            func_L27_004D1568(0x33, 1);
        } else if (FLD(D_001A4BE0, s32, 0x1B8) >= 0x2B) {
            func_L27_004D1568(0x33, 0);
        }
        break;
    case 0x77:
        if (FLD(D_001A4BE0, s32, 0x2850) <= 0) {
            func_L27_004D1568(0x6C, 1);
            func_L01_0050FB40(0x4F, 0x25, 15.0f);
        } else if (FLD(D_001A4BE0, s32, 0x1B8) >= 0x2B) {
            func_L27_004D1568(0x36, 0);
        }
        break;
    case 0x1:
    {
        u8 *p;
        s32 ok;
        s32 late;
        s32 anim;
        if ((FLD(D_001A4BE0, u8, 0x25E4) == 0) && ((FLD(D_001A4BE0, u8, 0x25EB) == 0) || (FLD(D_001A4BE0, u8, 0x25E5) != 0))) {
            if (FLD(D_001D52FC, s32, 0x1A0) & func_003A3BB8(8, 0)) {
                func_L01_0050FB40(0xD, 0, 7.0f);
            } else {
                s32 a = func_L04_004EFEC0(1);
                if (FLD(FLD(D_001A4BE0, u8 *, 0x25C0), u8, 0x43) != a) {
                    func_L01_0050FB40(a, 0, 7.0f);
                }
            }
        }
        p = FLD(D_001A4BE0, u8 *, 0x1200);
        ok = 1;
        if ((p != NULL) && (func_L01_004EDFA8(p) != 0)) {
            if ((FLD(p, u8, 0x20) != 0) && (func_L01_00513EF0() == 0)) {
                ok = 0;
            }
        }
        late = 0;
        if (FLD(D_001A4BE0, u8, 0x25E5) == 0) {
            late = FLD(D_001A4BE0, s32, 0x1B8) >= 0x1A;
        }
        if ((!(FLD(D_001D52FC, s32, 0x1A0) & func_003A3BB8(4, 0)) && ok) || late) {
            if (FLD(D_001A4BE0, u8, 0x25E4) != 0) {
                func_L01_00504E38(0);
            } else if (FLD(D_001D52FC, s32, 0x1A0) & func_003A3BB8(8, 0)) {
                func_L27_004D1568(4, 1);
            } else {
                func_L27_004D1568(0, 0);
                anim = func_L04_004EFEC0(1);
                if (FLD(FLD(D_001A4BE0, u8 *, 0x25C0), u8, 0x43) != anim) {
                    func_L01_0050FB40(anim, 0, 7.0f);
                }
            }
        }
        break;
    }

    case 0x2F:
        if (!(FLD(D_001D52FC, s32, 0x1A0) & FLD(D_001A4BE0, s32, 0x1210)) && (FLD(D_001A4BE0, s16, 0x1EC) == 0)) {
            if (FLD(FLD(D_001A4BE0, u8 *, 0x25C0), u8, 0x43) == 0x31) {
                func_L27_004D1568(0, 0);
            } else {
                func_L27_004D1568(0, 1);
            }
        }
        break;

    case 0x14:
    {
        u8 *rec;
        s32 frames;
        if (FLD(D_001A4BE0, u32, 0x25C4) == 0x14) {
            s32 n = (s32)(func_L01_00510478(60.0f, 0.052f, -1.0f));
            f32 c00 = FLD(D_001A4BE0, f32, 0xBE0);
            s32 top = 0x1A;
            if (c00 == 0.0f) {
                FLD(D_001A4BE0, f32, 0xC00) = 0.33f;
            } else if ((c00 != 0.0f) && (FLD(D_001A4BE0, s16, 0x36E) != 0) && (n != 0) && (((f32)top - FLD(D_001A4BE0, f32, 0xC18)) > 1.0f)) {
                func_L01_004E5030((f32)top, (f32)n, 0.5f, -1.0f);
                if ((FLD(D_001A4BE0, f32, 0x33C) < 0.7f) && (FLD(D_001A4BE0, f32, 0xC00) < 0.75f)) {
                    FLD(D_001A4BE0, f32, 0xC00) = 0.75f;
                }
            } else if ((FLD(D_001A4BE0, s16, 0x36E) == 0) && (FLD(D_001A4BE0, f32, 0xC18) < (f32)top)) {
                FLD(D_001A4BE0, f32, 0xC00) = 2.0f;
            } else {
                FLD(D_001A4BE0, f32, 0xC00) = 1.0f;
            }
        }
        rec = (u8 *)&D_L27_002F8A50[FLD(D_001A4BE0, s16, 0xBDC)];
        frames = ((s32)(FLD(D_001A4BE0, f32, 0xC18)) - FLD(rec, s32, 0xC)) * 2;
        if ((f32)FLD(rec, s32, 0x14) < FLD(D_001A4BE0, f32, 0xC18)) {
            if (FLD(D_001A4BE0, s32, 0xC0C) != 0) {
                break;
            }
            if (func_L01_004606E8(func_003A3BB8(0x40, 0), frames, 0, 0) != 0) {
                if (!(FLD(D_001D52FC, s32, 0x1A0) & func_003A3BB8(8, 0))) {
                    func_L27_004D1568(7, 1);
                    break;
                }
                if (func_L01_00506E30() != 0) {
                    break;
                }
            }
        }
        if ((FLD(D_001A4BE0, s32, 0xC0C) == 0) && ((f32)FLD(rec, s32, 0x18) < FLD(D_001A4BE0, f32, 0xC18))) {
            func_L27_004D1568(0, 0);
        }
        break;
    }

    case 0x13:
    case 0x15:
    {
        u8 *rec = (u8 *)&D_L27_002F8A50[FLD(D_001A4BE0, s16, 0xBDC)];
        s32 frames = ((s32)(FLD(D_001A4BE0, f32, 0xC18)) - FLD(rec, s32, 0xC)) * 2;
        u32 st = FLD(D_001A4BE0, u32, 0x25C4);
        s32 lim;
        f32 h;
        if (st == 0x15) {
            frames = 7;
        }
        if ((f32)FLD(rec, s32, 0x14) < FLD(D_001A4BE0, f32, 0xC18)) {
            if (FLD(D_001A4BE0, s32, 0xC0C) != 0) {
                goto tail13;
            }
            if ((st != 0x15) || (FLD(D_001A4BE0, s16, 0x368) != 1)) {
                if (func_L01_004606E8(func_003A3BB8(0x40, 0), frames, 0, 0) != 0) {
                    if (!(FLD(D_001D52FC, s32, 0x1A0) & func_003A3BB8(8, 0))) {
                        func_L27_004D1568(7, 1);
                        break;
                    }
                    if (func_L01_00506E30() != 0) {
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
                func_L27_004D1568(2, 0);
                if (FLD(D_001A4BE0, u32, 0x25C4) == 2) {
                    func_L01_0050FB40(3, D_L27_001DBDB0[FLD(D_001A4BE0, s32, 0x25C8)], 11.0f);
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
                func_L27_004D1568(2, 1);
                break;
            }
            if (((f32)(lim + 5) < h) || (FLD(D_001A4BE0, s32, 0xC08) & 2)) {
                func_L27_004D1568(0, 0);
            }
            break;
        }
    tail13:
        if (FLD(D_001A4BE0, u32, 0x25C4) == 0x15) {
            if ((FLD(D_001A4BE0, s32, 0x1228) != 9) && (FLD(D_001A4BE0, s32, 0x1228) != 0x7F)) {
                func_L27_004D1568(0, 1);
                break;
            }
            if ((FLD(D_001A4BE0, u32, 0x25C4) == 0x15) && (FLD(D_001A4BE0, s32, 0x1B8) >= 0x54) && (FLD(D_001A4BE0, s32, 0xC24) < 0x1A)) {
                func_L01_0050FEE8(2);
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
            if (func_L01_004606E8(func_003A3BB8(0x40, 0), 6, 0, 0) != 0) {
                if (!(FLD(D_001D52FC, s32, 0x1A0) & func_003A3BB8(8, 0))) {
                    func_L27_004D1568(7, 1);
                    break;
                }
                if (func_L01_00506E30() != 0) {
                    break;
                }
            }
        }
        if (FLD(D_001A4BE0, s32, 0xC0C) != 0) {
            goto tail88;
        }
        if (FLD(D_001A4BE0, f32, 0xC18) > 37.0f) {
            func_L27_004D1568(0, 0);
            func_L01_0050FB40(func_L04_004EFEC0(0), 0, 12.0f);
            break;
        }
    tail88:
        if ((FLD(D_001A4BE0, u32, 0x25C4) == 0x15) && (FLD(D_001A4BE0, s32, 0x1B8) >= 0x54) && (FLD(D_001A4BE0, s32, 0xC24) < 0x1A)) {
            func_L01_0050FEE8(2);
            FLD(D_001A4BE0, s32, 0xC24) = 0x1A;
        }
        break;
    case 0x7C:
        if (FLD(D_001A4BE0, s32, 0xC08) & 2) {
            func_L27_004D1568(0, 1);
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
            func_L27_004D1568(0x7B, 1);
            break;
        }
        if ((FLD(D_001A4BE0, s16, 0x36E) >= 6) && ((FLD(D_001A4BE0, s32, 0x25D4) != 0x12) || (FLD(D_001A4BE0, u8, 0x25EA) == 0)) && (FLD(D_001A4BE0, f32, 0x33C) > 1.35f) && (func_L01_005070E0() == 0)) {
            func_L27_004D1568(6, 1);
            break;
        }
        n = 7;
        if (FLD(D_001A4BE0, s16, 0x1EE) != 0) {
            n = 1;
        }
        if ((func_L01_004606E8(func_003A3BB8(0x40, 0), n, 0, 0) != 0) && ((FLD(D_001A4BE0, s16, 0x36E) < 7) || (FLD(D_001A4BE0, f32, 0x33C) < 0.5f) || (FLD(D_001A4BE0, s16, 0x202) != 0))) {
            func_L01_004EE850(0, 1.0f);
            if (func_L01_00506298(n, 1) != 0) {
                break;
            }
            if ((FLD(D_001A4BE0, f32, 0x2838) > 0.85f) && (FLD(D_001A4BE0, s16, 0x1434) == 0) && ((FLD(D_001A4BE0, s32, 0x16B0) != 1) || (func_L01_004606E8(0x28, 2, 0, 0) == 0))) {
                func_L27_004D1568(9, 1);
            } else {
                func_L27_004D1568(7, 1);
            }
            break;
        }
        if (FLD(D_001A4BE0, s16, 0x36E) != 0) {
            break;
        }
        if (((FLD(D_001A4BE0, u8, 0x1474) == 0) || ((FLD(D_001A4BE0, f32, 0x174) < 0.040000003f) && (FLD(D_001A4BE0, f32, 0x340) < 0.08726646f))) && (FLD(D_001D52FC, s32, 0x1A0) & func_L01_00512DF8(func_003A3BB8(4, 0))) && ((FLD(D_001A4BE0, u8, 0x25E4) != 0) || (D_001439F4[0] != 2) || (FLD(D_001A4BE0, s32, 0x1228) == 0x6F)) && (func_L01_003EB2D8(0) == 0)) {
            func_L27_004D1568(1, 1);
            break;
        }
        if (FLD(D_001D52FC, s32, 0x1A0) & func_003A3BB8(8, 0)) {
            func_L27_004D1568(4, 1);
            break;
        }
        turned = func_L01_004EDFC8(0.034906585f);
        st = FLD(D_001A4BE0, u32, 0x25C4);
        if (st == 2) {
            if (((FLD(D_001A4BE0, f32, 0x2838) < 0.17f) || (FLD(D_001A4BE0, s16, 0x1E0) != 0)) && (turned == 0) && ((FLD(D_001A4BE0, s32, 0x3F0) == 0) || (fabs_asm(FLD(D_001A4BE0, f32, 0x1A8)) < 0.017453292f))) {
                s32 anim;
                if (func_L01_00507268() != 0) {
                    break;
                }
                if (func_L27_004D1568(0, 0) != 0) {
                    func_003C4BB0(D_001A4BE0 + 0x160, 0.030000001f);
                    if (FLD(D_001A4BE0, f32, 0x1B4) > 0.030000001f) {
                        FLD(D_001A4BE0, f32, 0x1B4) = 0.030000001f;
                    }
                    anim = func_L04_004EFEC0(1);
                    if (anim == 0x4A) {
                        func_L01_0050FB40(0x4A, 0, 12.0f);
                    } else {
                        func_L01_0050FB40(anim, 0, -1.0f);
                    }
                }
            } else {
                func_L01_005063E8();
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
        if (!(FLD(D_001D52FC, s32, 0x1A0) & func_003A3BB8(8, 0))) {
            if (FLD(D_001A4BE0, s32, 0x1B8) >= 0x33) {
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
            func_L01_004F4E70(9, 0);
            FLD(D_001A4BE0, s16, 0x1E0) = 0x19;
            func_L27_004D1568(3, 0);
            func_L01_0050FB40(6, 4, 9.0f);
        } else if (FLD(D_001A4BE0, s32, 0x984) != 0) {
            func_L27_004D1568(0, 0);
            func_L01_0050FB40(func_L04_004EFEC0(0), 0, -2.0f);
        } else {
            if (FLD(D_001A4BE0, u8, 0x2A7) != 0) {
                f32 a = func_0038CEA8(D_001A4BE0 + 0x110);
                if (a < func_0038CEA8(D_001A4BE0 + 0xF0) * 0.75f) {
                    func_L27_004D1568(0x7C, 1);
                    break;
                }
                if (func_L01_004E63F0(NULL, 1.0f, 1.25f) != 0) {
                    func_L27_004D1568(0x7C, 1);
                    break;
                }
            }
            *(s128 *)v30 = 0;
            v30[0] = -0.10000001f;
            func_003C2F58(FLD(D_001A4BE0, s8 *, 0x25C0), 0x16, (s8 *)v10);
            func_003C2F58(FLD(D_001A4BE0, s8 *, 0x25C0), 0x17, (s8 *)v20);
            func_L01_0046E078(FLD(D_001A4BE0, s8 *, 0x25C0), v10, v30, (s32 *)D_L27_001DBC50, 1);
            func_L01_0046E078(FLD(D_001A4BE0, s8 *, 0x25C0), v10, v30, (s32 *)D_L27_001DBC60, 1);
            func_L01_0046E078(FLD(D_001A4BE0, s8 *, 0x25C0), v20, v30, (s32 *)D_L27_001DBC50, 1);
            func_L01_0046E078(FLD(D_001A4BE0, s8 *, 0x25C0), v20, v30, (s32 *)D_L27_001DBC60, 1);
        }
        break;
    }
    case 0x66:
        if (D_L27_001D673C != 0) {
            if (func_0038CF00(D_001A4BE0 + 0x80, D_001A4BE0 + 0x80 + 0x1AC0) < 0.4f) {
                if (FLD(D_001A4BE0, f32, 0x170) < 0.054000005f) {
                    func_L27_004D1568(0x68, 1);
                } else if ((FLD(D_001A4BE0, u8, 0x25E4) != 0) && (FLD(D_001A4BE0, f32, 0x170) >= 0.054000005f)) {
                    func_L27_004D1568(0x67, 1);
                }
                break;
            }
        } else if (func_0038CF38(D_001A4BE0 + 0x80, D_001A4BE0 + 0x80 + 0x1AC0) < 0.3f) {
            if ((FLD(D_001A4BE0, f32, 0x170) < 0.054000005f) && (func_0038DBA0(FLD(D_001A4BE0, f32, 0x98), FLD(D_001A4BE0, f32, 0x1B4C)) < 0.034906585f)) {
                func_L27_004D1568(0x68, 1);
            } else if ((FLD(D_001A4BE0, u8, 0x25E4) != 0) && (FLD(D_001A4BE0, f32, 0x170) >= 0.054000005f)) {
                func_L27_004D1568(0x67, 1);
            }
            break;
        }
        func_L01_005063E8();
        break;
    case 0x67:
        if (FLD(D_001A4BE0, s32, 0xC08) & 2) {
            func_L27_004D1568(0x66, 1);
        }
        break;
    case 0x68:
    {
        if ((FLD(D_001A4BE0, s32, 0xC08) & 2) || (FLD(D_001A4BE0, s32, 0x1B50) != 0)) {
            func_L27_004D1568(0, 1);
        }
        if (D_L27_001D673C != 0) {
            if (func_0038CF00(D_001A4BE0 + 0x80, D_001A4BE0 + 0x80 + 0x1AC0) > 0.4f) {
                func_L27_004D1568(0x66, 1);
            }
        } else if (func_0038CF38(D_001A4BE0 + 0x80, D_001A4BE0 + 0x80 + 0x1AC0) > 0.3f) {
            func_L27_004D1568(0x66, 1);
        }
        break;
    }
    case 0x6A:
        if ((FLD(D_001A4BE0, s32, 0x1B70) < 3) && ((FLD(D_001A4BE0, s32, 0x1B70) * 6 + 8) < FLD(D_001A4BE0, s32, 0x1B8)) && (func_L01_004606E8(func_003A3BB8(0x40, 0), 6, &sp34, 0) != 0)) {
            func_L27_004D1568(0x6B, 1);
        }
        if (!(FLD(D_001A4BE0, f32, 0x88) < (FLD(D_001A4BE0, f32, 0x354) - 1.2f)) && (FLD(D_001A4BE0, s32, 0x1B8) < 0x8F)) {
            break;
        }
        func_L01_004EDE10();
        return;
    case 0x7D:
        if (!(FLD(D_001A4BE0, f32, 0x88) < (FLD(D_001A4BE0, f32, 0x354) - 1.2f)) && (FLD(D_001A4BE0, s32, 0x1B8) < 0x7E)) {
            break;
        }
        func_L01_004EDE10();
        return;
    case 0x3:
        if ((FLD(D_001D52FC, s32, 0x1A0) & func_L01_00512DF8(func_003A3BB8(4, 0))) && ((FLD(D_001A4BE0, u8, 0x25E4) != 0) || (D_001439F4[0] != 2) || (FLD(D_001A4BE0, s32, 0x1228) == 0x6F)) && (func_L01_003EB2D8(0) == 0)) {
            func_L27_004D1568(1, 1);
            break;
        }
        if ((FLD(D_001A4BE0, s16, 0x1E0) == 0) && (FLD(D_001D52FC, s32, 0x1A4) & func_003A3BB8(0x40, 0))) {
            func_L27_004D1568(7, 1);
            break;
        }
        if ((FLD(D_001A4BE0, s16, 0x1E0) == 0) && (FLD(D_001D52FC, s32, 0x1A0) & func_003A3BB8(8, 0))) {
            func_L27_004D1568(4, 1);
            break;
        }
        if ((FLD(D_001A4BE0, s16, 0x36E) >= 8) && (FLD(D_001A4BE0, f32, 0x33C) > 0.3f)) {
            func_L27_004D1568(6, 1);
            break;
        }
        if (FLD(D_001A4BE0, s32, 0xC08) & 2) {
            func_L27_004D1568(0, 1);
            break;
        }
        if (!(FLD(D_001A4BE0, f32, 0x2838) > 0.2f) || (FLD(D_001A4BE0, s16, 0x1E0) != 0)) {
            break;
        }
        if (func_L04_004EFEC0(0) != 0x4A) {
            if (FLD(D_001A4BE0, f32, 0x1B4) == 0.0f) {
                func_L27_004D1568(0, 0);
                break;
            }
        } else if ((FLD(D_001A4BE0, f32, 0xC18) > 10.0f) && (func_L27_004D1568(0, 0) != 0)) {
            func_L01_0050FB40(func_L04_004EFEC0(0), 0, 14.0f);
        }
        if (FLD(D_001A4BE0, f32, 0x2838) > 0.5f) {
            func_L27_004D1568(2, 1);
        }
        break;

    case 0x4:
        if ((FLD(D_001D52FC, s32, 0x1A0) & func_L01_00512DF8(func_003A3BB8(4, 0))) && ((FLD(D_001A4BE0, u8, 0x25E4) != 0) || (D_001439F4[0] != 2) || (FLD(D_001A4BE0, s32, 0x1228) == 0x6F)) && (func_L01_003EB2D8(0) == 0)) {
            func_L27_004D1568(1, 1);
            break;
        }
        if ((FLD(D_001A4BE0, s32, 0x1B8) >= 0xA) && !(FLD(D_001D52FC, s32, 0x1A0) & func_003A3BB8(8, 0))) {
            func_L27_004D1568(0, 0);
            func_L01_0050FB40(func_L04_004EFEC0(0), 0, -2.0f);
            break;
        }
        if (FLD(D_001A4BE0, u8, 0x147C) != 0) {
            if (FLD(D_001A4BE0, s16, 0x36C) == 0) {
                func_L27_004D1568(0x7B, 1);
                break;
            }
        } else if (func_L01_00506E30() != 0) {
            break;
        }
        if ((func_L01_004606E8(0x80, 0xC, 0, 0) != 0) && (FLD(D_001A4BE0, u8, 0x121A) == 0) && (FLD(D_001A4BE0, s32, 0x1228) == 9)) {
            func_L27_004D1568(0x15, 1);
        }
        if (FLD(D_001A4BE0, s16, 0x36E) >= 8) {
            if ((FLD(D_001A4BE0, s32, 0x25D0) != 8) || (FLD(D_001A4BE0, s32, 0x1B8) >= 0xC)) {
                func_L27_004D1568(6, 1);
            }
        }
        break;

    case 0x17:
        if (FLD(D_001A4BE0, f32, 0xC18) > 12.0f) {
            func_L27_004D1568(0x18, 0);
        }
        break;

    case 0x18:
        if ((FLD(D_001A4BE0, s32, 0xC08) & 2) && (FLD(FLD(D_001A4BE0, u8 *, 0x25C0), u8, 0x43) == 0x20)) {
            func_L01_0050FB40(0x21, 0, 4.0f);
        }
        func_L01_004EE850(0, 1.0f);
        if (func_L01_004E8318((s8 *)(D_001A4BE0 + 0x80), (s8 *)(D_001A4BE0 + 0x90), NULL) == 0) {
            func_L27_004D1568(6, 1);
            FLD(D_001A4BE0, s16, 0x1D0) = 8;
            break;
        }
        if (((FLD(D_001A4BE0, f32, 0x2838) > 0.5f) && (func_L01_004606E8(func_003A3BB8(0x40, 0), 7, 0, 0) != 0) && (func_0038DBA0(FLD(D_001A4BE0, f32, 0x1A0), FLD(D_001A4BE0, f32, 0x98)) > 2.3561945f)) || (FLD(D_001D52FC, s32, 0x1A4) & func_003A3BB8(8, 0))) {
            func_L27_004D1568(6, 1);
            FLD(D_001A4BE0, s8, 0x25F0) = 1;
            FLD(D_001A4BE0, s16, 0x1D0) = 8;
            break;
        }
        if (func_L01_004606E8(func_003A3BB8(0x40, 0), 0xE, 0, 0) != 0) {
            func_L27_004D1568(0x1B, 1);
            break;
        }
        if (FLD(D_001A4BE0, f32, 0x2838) > 0.5f) {
            if (func_0038DBA0(FLD(D_001A4BE0, f32, 0x1A0), func_0038DAB8(FLD(D_001A4BE0, f32, 0x98), 1.57079637f)) < 0.785398185f) {
                *(s128 *)v10 = *(s128 *)(D_001A4BE0 + 0x80);
                v10[0] += func_0038D098(func_0038DAB8(FLD(D_001A4BE0, f32, 0x98), 1.57079637f)) * 0.3f;
                v10[1] += func_0038D0B0(func_0038DAB8(FLD(D_001A4BE0, f32, 0x98), 1.57079637f)) * 0.3f;
                if (func_L01_004E8318((s8 *)v10, (s8 *)(D_001A4BE0 + 0x90), NULL) != 0) {
                    func_L27_004D1568(0x19, 1);
                }
                break;
            }
        }
        if (FLD(D_001A4BE0, f32, 0x2838) > 0.5f) {
            if (func_0038DBA0(FLD(D_001A4BE0, f32, 0x1A0), func_0038DAB8(FLD(D_001A4BE0, f32, 0x98), -1.57079637f)) < 0.785398185f) {
                *(s128 *)v10 = *(s128 *)(D_001A4BE0 + 0x80);
                v10[0] += func_0038D098(func_0038DAB8(FLD(D_001A4BE0, f32, 0x98), -1.57079637f)) * 0.3f;
                v10[1] += func_0038D0B0(func_0038DAB8(FLD(D_001A4BE0, f32, 0x98), -1.57079637f)) * 0.3f;
                if (func_L01_004E8318((s8 *)v10, (s8 *)(D_001A4BE0 + 0x90), NULL) != 0) {
                    func_L27_004D1568(0x1A, 1);
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
        v10[0] += func_0038D098(func_0038DAB8(FLD(D_001A4BE0, f32, 0x98), side)) * 0.3f;
        v10[1] += func_0038D0B0(func_0038DAB8(FLD(D_001A4BE0, f32, 0x98), side)) * 0.3f;
        func_L01_004EE850(0, 1.0f);
        if ((FLD(D_001A4BE0, f32, 0x2838) < 0.5f) || (func_0038DBA0(FLD(D_001A4BE0, f32, 0x1A0), func_0038DAB8(FLD(D_001A4BE0, f32, 0x98), side)) > 0.785398185f) || (func_L01_004E8318((s8 *)v10, (s8 *)(D_001A4BE0 + 0x90), NULL) == 0)) {
            if (FLD(D_001A4BE0, s32, 0xC08) & 2) {
                func_L27_004D1568(0x18, 1);
                break;
            }
        }
        if ((FLD(D_001A4BE0, f32, 0x2838) > 0.5f) && (func_L01_004606E8(func_003A3BB8(0x40, 0), 7, 0, 0) != 0) && (func_0038DBA0(FLD(D_001A4BE0, f32, 0x1A0), FLD(D_001A4BE0, f32, 0x98)) > 2.3561945f)) {
            func_L27_004D1568(6, 1);
            FLD(D_001A4BE0, s8, 0x25F0) = 1;
            FLD(D_001A4BE0, s16, 0x1D0) = 0x21;
            break;
        }
        if (func_L01_004606E8(func_003A3BB8(0x40, 0), 7, 0, 0) != 0) {
            func_L27_004D1568(0x1B, 1);
        }
        break;
    }

    case 0x7B:
        if (FLD(D_001A4BE0, s32, 0x1B8) >= 0xFB) {
            func_L01_004EDE10();
        }
        if (FLD(D_001A4BE0, u8, 0x147C) == 0) {
            if (FLD(D_001A4BE0, s16, 0x36E) != 0) {
                func_L27_004D1568(6, 1);
            } else {
                func_L27_004D1568(0, 1);
            }
        }
        break;
    case 0x6:
    case 0x2C:
        if ((FLD(D_001A4BE0, s32, 0x25C8) == 0) && ((FLD(D_001A4BE0, s32, 0x1B8) >= 0xF) || (FLD(D_001A4BE0, f32, 0x33C) > 1.75f))) {
            func_L01_0050FB40(0xB, 0, 13.0f);
            FLD(D_001A4BE0, s32, 0x25C8) = 1;
            if (FLD(D_001A4BE0, u32, 0x25C4) == 0x2C) {
                FLD(D_001A4BE0, s32, 0x280C) = 7;
            } else {
                FLD(D_001A4BE0, s32, 0x280C) = 0;
            }
        }
        if (FLD(D_001A4BE0, s16, 0x36E) == 0) {
            func_L01_004E1180();
            if (FLD(D_001A4BE0, f32, 0x118) < -0.180000007f) {
                FLD(D_001A4BE0, f32, 0x118) = -0.180000007f;
            }
            if (FLD(D_001A4BE0, f32, 0xF8) < -0.180000007f) {
                FLD(D_001A4BE0, f32, 0xF8) = -0.180000007f;
            }
            if (FLD(D_001A4BE0, s32, 0x2850) <= 0) {
                func_L27_004D1568(0x39, 1);
            } else {
                s32 one = 1;
                s32 low = FLD(D_001A4BE0, s32, 0x35C) == 0;
                if (FLD(D_001A4BE0, s32, 0x1B8) >= 0x4B) {
                    if (func_L27_004D1568(0, 0) != 0) {
                        func_L01_0050FB40(0xC, 4, 5.0f);
                    }
                    if (low != 0) {
                        FLD(D_001A4BE0, s16, 0x1E0) = 0x12;
                    }
                    func_L01_00510CA0(0xA, 4, 0, 1, 0.022f, 0.004f);
                } else if (FLD(D_001A4BE0, s32, 0x25C8) == one) {
                    if (func_L27_004D1568(0, 0) != 0) {
                        func_L01_0050FB40(0xC, 9, -1.0f);
                    }
                    func_L01_00511508(D_001A4BE0 + 0x160, D_001A4BE0 + 0x160, 0.0f);
                    func_003C4BB0((f32 *)(D_001A4BE0 + 0x160), 0.140000015f);
                    FLD(D_001A4BE0, s16, 0x1E0) = 6;
                    if (FLD(D_001A4BE0, s32, 0x25D0) == 0x2C) {
                        FLD(D_001A4BE0, s16, 0x1E0) = 8;
                    }
                    if ((low != 0) && (FLD(D_001A4BE0, s32, 0x1B8) >= 0x2B)) {
                        FLD(D_001A4BE0, s16, 0x1E0) = 0xF;
                    }
                    func_L01_00510CA0(0xA, 2, 0, 1, 0.019f, 0.002f);
                } else if ((FLD(D_001A4BE0, f32, 0x2838) > 0.5f) && (FLD(D_001A4BE0, s16, 0x1E0) == 0)) {
                    func_L27_004D1568(2, 1);
                    func_L01_00510CA0(7, 2, 0, 1, 0.016f, 0.002f);
                } else if (FLD(D_001A4BE0, f32, 0x174) > 0.0600000024f) {
                    if (func_L27_004D1568(3, 0) != 0) {
                        func_L01_0050FB40(6, 0, 10.0f);
                        func_003C4BB0((f32 *)(D_001A4BE0 + 0x160), 0.154000014f);
                    }
                } else {
                    func_L27_004D1568(0, 1);
                    func_L01_00510CA0(5, 2, 0, 1, 0.016f, 0.002f);
                }
            }
        } else if (FLD(D_001A4BE0, s32, 0x2850) > 0) {
            if ((FLD(D_001D52FC, s32, 0x1A0) & func_003A3BB8(0x40, 0)) && (D_00142CA2[0] != 0) && (func_L01_004E9238(3) != 4) && (FLD(D_001A4BE0, s16, 0x2884) == 0) && (FLD(D_001A4BE0, s16, 0x1E0) == 0) && (FLD(D_001A4BE0, f32, 0x33C) > 0.6f)) {
                func_L27_004D1568(8, 1);
                break;
            }
            if ((FLD(D_001A4BE0, s16, 0x202) >= 0x22) && (func_L01_00506298((FLD(D_001A4BE0, s16, 0x1EE) != 0) ? 1 : 5, 0) != 0)) {
                break;
            }
            if (FLD(D_001A4BE0, s32, 0x528) != 0) {
                func_L27_004D1568(0x17, 1);
                break;
            }
        }
        break;

    case 0x79:
        if (FLD(D_001A4BE0, s32, 0x1B8) < 0x65) {
            break;
        }
        func_L01_004EDE10();
        return;
    case 0x8:
        if ((FLD(D_001A4BE0, s32, 0x1D4) != 0) && (FLD(D_001A4BE0, s32, 0x1B8) < 7)) {
            s32 prev = FLD(D_001A4BE0, s32, 0x25D0);
            s32 ok = 0;
            if ((prev == 7) || (prev == 9) || (prev == 0xE) || (prev == 0x11)) {
                ok = 1;
            }
            if (ok != 0) {
                func_L27_004D1568(0x11, 1);
            }
            break;
        }
        if ((FLD(D_001A4BE0, s32, 0x1B8) >= 0x1A) && (FLD(D_001A4BE0, s16, 0x22C) == 0) && !(FLD(D_001D52FC, s32, 0x1A0) & func_003A3BB8(0x40, 0)) && !(FLD(D_001D52FC, s32, 0x1C0) & func_003A3BB8(0x40, 0))) {
            func_L27_004D1568(6, 1);
            break;
        }
        if (FLD(D_001A4BE0, s32, 0x528) != 0) {
            func_L27_004D1568(0x17, 1);
            break;
        }
        if ((FLD(D_001A4BE0, s16, 0x36E) != 0) && !(FLD(D_001A4BE0, f32, 0x33C) < 0.4f)) {
            break;
        }
        if (FLD(D_001A4BE0, s32, 0x1B8) < 8) {
            FLD(D_001A4BE0, s16, 0x1EE) = 0xA - FLD(D_001A4BE0, u16, 0x1B8);
        }
        func_L01_004EE850(0, 1.0f);
        if ((FLD(D_001A4BE0, s32, 0x25D0) == 0x10) && (FLD(D_001A4BE0, s32, 0x1B8) < 3)) {
            if (func_L27_004D1568(3, 0) != 0) {
                func_L01_0050FB40(5, 0, -1.0f);
                FLD(D_001A4BE0, s16, 0x1E0) = 0x1C;
            }
            break;
        }
        if (FLD(D_001D52FC, s32, 0x1A0) & func_003A3BB8(8, 0)) {
            func_L27_004D1568(4, 1);
            func_L01_00510CA0(5, 2, 0, 1, 0.016f, 0.002f);
            break;
        }
        if ((D_L27_001DBD84[2] < FLD(D_001A4BE0, f32, 0x1B0)) && (func_0038DBA0(FLD(D_001A4BE0, f32, 0x1A0), FLD(D_001A4BE0, f32, 0x98)) < 1.5707964f)) {
            if ((FLD(D_001A4BE0, u8, 0x1474) != 0) || (FLD(D_001A4BE0, u8, 0x25EA) != 0)) {
                func_L27_004D1568(2, 1);
                break;
            }
            func_L27_004D1568(2, 0);
            if (FLD(D_001A4BE0, u32, 0x25C4) == 2) {
                FLD(D_001A4BE0, s32, 0x25C8) = 1;
                func_L01_0050FB40(4, 2, 7.0f);
                FLD(D_001A4BE0, s8, 0x3EE) = 1;
            }
            func_L01_00510CA0(5, 2, 1, 0, 0.016f, 0.002f);
        } else if (D_L27_001DBD84[2] < FLD(D_001A4BE0, f32, 0x1B0)) {
            if ((FLD(D_001A4BE0, u8, 0x1474) != 0) || (FLD(D_001A4BE0, u8, 0x25EA) != 0)) {
                func_L27_004D1568(2, 1);
                break;
            }
            func_L27_004D1568(2, 0);
            if (FLD(D_001A4BE0, u32, 0x25C4) == 2) {
                FLD(D_001A4BE0, s32, 0x25C8) = 1;
                func_L01_0050FB40(4, D_L27_001DBDB4, 10.0f);
            }
            func_L01_00510CA0(5, 2, 1, 0, 0.016f, 0.002f);
        } else if (FLD(D_001A4BE0, s16, 0x36E) == 0) {
            if (func_L27_004D1568(0, 0) != 0) {
                func_L01_0050FB40(func_L04_004EFEC0(0), 0, -2.0f);
                func_L01_00510CA0(5, 2, 0, 1, 0.016f, 0.002f);
            }
        } else if (func_L27_004D1568(0, 0) != 0) {
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
        if (FLD(D_001A4BE0, u8, 0x4FE) != 0) {
            s32 n = func_L01_004FF5D8();
            if ((n > 0) && ((FLD(D_001A4BE0, s32, 0x1B8) < n) || (FLD(D_001A4BE0, u8, 0x46C) != 0)) && (FLD(D_001A4BE0, s32, 0x360) != 0)) {
                if ((FLD(D_001A4BE0, u32, 0x25C4) != 0xB) || (func_L01_004606E8(func_003A3BB8(0x40, 0), 6, 0, 0) != 0)) {
                    s32 go = 1;
                    if ((FLD(D_001A4BE0, u32, 0x25C4) == 0x1B) || (FLD(D_001A4BE0, u8, 0x46C) != 0)) {
                        if (func_L01_004606E8(func_003A3BB8(0x40, 0), 6, 0, 0) == 0) {
                            go = 0;
                        }
                    }
                    if (FLD(D_001A4BE0, u32, 0x25C4) == 0xB) {
                        if (FLD(D_001A4BE0, u8, 0x46C) == 0) {
                            go = 0;
                        }
                    }
                    if ((go != 0) && (func_L01_004606E8(0x1F000, 4, 0, 0) != 0) && (FLD(D_001D52FC, s32, 0x1A0) & func_003A3BB8(8, 0))) {
                        func_L27_004D1568(0xB, 1);
                        break;
                    }
                }
            }
        }
        if ((FLD(D_001A4BE0, u32, 0x25C4) == 0x1B) && (FLD(D_001A4BE0, s32, 0x1B8) >= 0xC) && (FLD(D_001A4BE0, f32, 0x298) > 1.3f)) {
            FLD(D_001A4BE0, s8, 0x25F0) = 0;
            FLD(D_001A4BE0, s8, 0x25ED) = 0;
        }
        if ((FLD(D_001A4BE0, s32, 0x1B8) < 2) && (func_L01_004606E8(func_003A3BB8(8, 0), 2, 0, 0) != 0) && ((sa = FLD(D_001A4BE0, u32, 0x25C4)) != 0x10) && (sa != 0xA) && (sa != 0x12) && (sa != 0x38) && (sa != 0x11) && (sa != 0xE) && (sa != 0x6B)) {
            if ((func_L01_004E9238(3) == 2) && (D_00142CA2[0] != 0) && (FLD(D_001A4BE0, s16, 0x2884) == 0) && (FLD(D_001A4BE0, f32, 0x178) > 0.0180000011f)) {
                func_L27_004D1568(0xA, 1);
            } else if ((func_L01_004E9238(3) == 3) && (FLD(D_001A4BE0, s16, 0x2884) == 0) && (FLD(D_001A4BE0, f32, 0x178) > 0.0180000011f) && (FLD(D_001A4BE0, s16, 0x1E4) == 0)) {
                func_L27_004D1568(0x10, 1);
            }
        }
        if (FLD(D_001A4BE0, s16, 0x4EA) < FLD(D_001A4BE0, s32, 0x1B8)) {
            if (FLD(D_001A4BE0, u8, 0x46C) == 0) {
                func_L27_004D1568(6, 1);
                break;
            }
        } else if ((FLD(D_001A4BE0, u8, 0x46C) == 0) && ((FLD(D_001A4BE0, u32, 0x25C4) == 0xA) || (FLD(D_001A4BE0, u32, 0x25C4) == 0x10)) && (FLD(D_001A4BE0, f32, 0x298) < 0.9f) && (FLD(D_001A4BE0, u8, 0x2A7) != 0) && (func_0038CEA8(D_001A4BE0 + 0xF0) > 0.140000015f)) {
            f32 a = func_0038CEA8(D_001A4BE0 + 0x110);
            if ((a < func_0038CEA8(D_001A4BE0 + 0xF0) * 0.5f) && (FLD(D_001A4BE0, s32, 0x528) == 0) && (FLD(D_001A4BE0, f32, 0x33C) < 2.0f)) {
                func_L01_004F4ED0(0x19);
                func_L27_004D1568(0x7C, 1);
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
                    func_L01_004E5030(FLD(D_001A4BE0, f32, 0x408), left, FLD(D_001A4BE0, f32, 0x4E4), -1.0f);
                }
            } else if (FLD(D_001A4BE0, u32, 0x25C4) != 0xE) {
                func_L01_00511748((f32 *)(D_001A4BE0 + 0x80), (f32 *)(D_001A4BE0 + 0xF0), &sp38, FLD(D_001A4BE0, f32, 0x4F0));
                func_L01_004E5030(FLD(D_001A4BE0, f32, 0x498), (f32)sp38, FLD(D_001A4BE0, f32, 0x4E4), -1.0f);
                if (FLD(D_001A4BE0, f32, 0xC00) > 1.5f) {
                    FLD(D_001A4BE0, f32, 0xC00) = 1.5f;
                }
            }
            break;
        }
        if ((FLD(D_001A4BE0, u8, 0x46D) != 0) && (now >= FLD(D_001A4BE0, s32, 0x400)) && (now < FLD(D_001A4BE0, s32, 0x404))) {
            f32 left = (f32)(FLD(D_001A4BE0, s32, 0x410) - FLD(D_001A4BE0, s32, 0x400));
            if (left > 0.0f) {
                func_L01_004E5030(FLD(D_001A4BE0, f32, 0x498), left, FLD(D_001A4BE0, f32, 0x4E4), -1.0f);
            }
            break;
        }
        if (FLD(D_001A4BE0, s32, 0x358) == 1) {
            func_L01_004F4E70(0xC, 0);
            func_L01_004E5EB8(3, 0x18, 1);
        }
        {
            u8 c = FLD(D_001A4BE0, u8, 0x46C);
            if (c != 0) {
                FLD(D_001A4BE0, u8, 0x46C) = c + 1;
            } else if ((FLD(D_001A4BE0, s16, 0x36E) == 0) && (FLD(D_001A4BE0, u8, 0x46E) != 0) && (near == 0)) {
                func_L01_004E1180();
                FLD(D_001A4BE0, u8, 0x46C) = 1;
                FLD(D_001A4BE0, s8, 0x285F) = 0;
                if ((FLD(D_001A4BE0, f32, 0x2838) < 0.2f) && (FLD(D_001A4BE0, f32, 0x1B4) > 0.050000004f)) {
                    FLD(D_001A4BE0, f32, 0x1B4) = 0.050000004f;
                }
                func_L01_00510CA0(5, 2, 0, 1, 0.016f, 0.002f);
                if (near == 0) {
                    s32 k = (s32)(FLD(D_001A4BE0, f32, 0x4A0)) + 2;
                    if (FLD(D_001A4BE0, f32, 0xC18) < FLD(D_001A4BE0, f32, 0x49C) - 1.5f) {
                        func_L01_0050FB40(func_L01_004DFE80(FLD(hero, u8, 0x43)), k, 6.0f);
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
                    func_003C4138((f32 *)(D_001A4BE0 + 0xC00), 1.0f, 0.216000021f);
                } else {
                    FLD(D_001A4BE0, s16, 0x47E) = (s32)(func_L01_00510478(60.0f, FLD(D_001A4BE0, f32, 0x4F0), -1.0f));
                    func_L01_004E5030(FLD(D_001A4BE0, f32, 0x49C), (f32)FLD(D_001A4BE0, s16, 0x47E), FLD(D_001A4BE0, f32, 0x4E4), 0.288000017f);
                }
                if (near == 0) {
                    s32 k = (s32)(FLD(D_001A4BE0, f32, 0x4A0)) + 2;
                    if (FLD(D_001A4BE0, f32, 0xC00) > 1.8f) {
                        func_L01_0050FB40(func_L01_004DFE80(FLD(hero, u8, 0x43)), k, (f32)(FLD(D_001A4BE0, s16, 0x47E) + 3));
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
            if ((cur == 9) && ((FLD(D_001A4BE0, f32, 0x49C) - FLD(D_001A4BE0, f32, 0xC18)) > 6.0f) && ((func_L01_004DFE80(FLD(hero, u8, 0x42)) == 8) || (func_L01_004DFE80(FLD(hero, u8, 0x42)) == cur)) && (FLD(hero, u8, 0x42) == FLD(hero, u8, 0x43)) && (FLD(D_001A4BE0, f32, 0x1B0) < D_L27_001DBD84[5] * 0.0200000014f * 0.1f) && (FLD(D_001A4BE0, f32, 0x174) < 0.050000004f)) {
                f32 rate = 7.0f / FLD(D_001A4BE0, f32, 0xC00);
                s32 at;
                if (rate > 8.0f) {
                    rate = 8.0f;
                }
                at = (s32)(FLD(D_001A4BE0, f32, 0xC18)) + 4;
                func_L01_0050FB40(7, at / 2, rate);
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
                if (func_L27_004D1568(3, 0) != 0) {
                    func_L01_0050FB40(5, 0, -2.0f);
                    func_0038CE20(D_001A4BE0 + 0x160, D_001A4BE0 + 0x160, 0.8f);
                }
                break;
            }
            if ((FLD(D_001A4BE0, u8, 0x147C) == 0) && (FLD(D_001A4BE0, s16, 0x1E0) == 0) && (func_L01_004606E8(func_003A3BB8(0x40, 0), 7, 0, 0) != 0) && (FLD(D_001A4BE0, s16, 0x36E) < 7)) {
                if (((FLD(D_001A4BE0, s16, 0x1434) != 0) || ((FLD(D_001A4BE0, s32, 0x16B0) == 1) && (func_L01_004606E8(0x28, 2, 0, 0) != 0))) && (FLD(D_001A4BE0, f32, 0x2838) > 0.9f) && (func_L01_004FF610() != 2)) {
                    func_L27_004D1568(0xB, 1);
                } else if (!(FLD(D_001A4BE0, f32, 0x1B0) > D_L27_001DBD84[2])) {
                    func_L27_004D1568(7, 1);
                } else if (func_0038DBA0(FLD(D_001A4BE0, f32, 0x1A0), FLD(D_001A4BE0, f32, 0x98)) < 1.04719758f) {
                    if (D_L27_001DBD84[5] * 0.0200000014f * 0.85f < FLD(D_001A4BE0, f32, 0x174)) {
                        func_L27_004D1568(9, 1);
                    } else {
                        func_L27_004D1568(7, 1);
                    }
                } else {
                    func_L27_004D1568(7, 1);
                }
                break;
            }
        }
        if ((FLD(D_001A4BE0, u8, 0x46C) >= 2) && (FLD(D_001A4BE0, u32, 0x25C4) != 0xA)) {
            func_L04_00512970();
        } else if ((FLD(D_001A4BE0, u8, 0x46E) != 0) && (FLD(D_001A4BE0, s32, 0x1B8) >= FLD(D_001A4BE0, s16, 0x4FA)) && (FLD(D_001A4BE0, f32, 0x33C) > FLD(D_001A4BE0, f32, 0x4E0))) {
            func_L27_004D1568(6, 1);
        }
        if ((FLD(D_001A4BE0, u32, 0x25C4) == 0x10) && (FLD(D_001A4BE0, s32, 0x1B8) >= 0x33) && (FLD(D_001A4BE0, f32, 0x33C) > 1.5f)) {
            func_L27_004D1568(6, 1);
            break;
        }
        {
            u32 s = FLD(D_001A4BE0, u32, 0x25C4);
            s32 ok = 0;
            if ((s == 7) || (s == 9) || (s == 0x11)) {
                ok = 1;
            }
            if ((FLD(D_001A4BE0, s32, 0x1D4) != 0) && (FLD(D_001A4BE0, u8, 0x46C) == 0) && (ok != 0) && ((FLD(D_001A4BE0, u32, 0x25C4) != 0x11) || (FLD(D_001A4BE0, s32, 0x1B8) >= 0x16)) && (func_L01_004606E8(func_003A3BB8(0x40, 0), 6, &sp3C, 0) != 0) && (sp3C < FLD(D_001A4BE0, s32, 0x1B8))) {
                func_L27_004D1568(0x11, 1);
                break;
            }
        }
        if (((FLD(D_001A4BE0, u32, 0x25C4) == 0xA) || (FLD(D_001A4BE0, u32, 0x25C4) == 0x10)) && (FLD(D_001A4BE0, s32, 0x1B8) >= 0x16) && (FLD(D_001A4BE0, s16, 0x36A) != 0)) {
            FLD(D_001A4BE0, s16, 0x4F6) = 0x11;
        }
        sc = FLD(D_001A4BE0, u32, 0x25C4);
        lim = 0x11;
        if (sc == 0x10) {
            lim = 7;
        }
        if ((sc == 0xE) && (FLD(D_001A4BE0, f32, 0x33C) > 4.0f)) {
            if ((FLD(D_001A4BE0, u8, 0x46E) == 0) && (FLD(D_001A4BE0, f32, 0xC00) < 1.3f)) {
                func_003C4138((f32 *)(D_001A4BE0 + 0xC00), 1.3f, 0.120000005f);
            }
            lim = 0xE;
            FLD(D_001A4BE0, s16, 0x4F6) = lim;
        }
        frames = FLD(D_001A4BE0, s32, 0x1B8) - 4;
        if (frames <= 1) {
            frames = 2;
        }
        if (frames >= 0x1A) {
            frames = 0x19;
        }
        if (!(FLD(D_001A4BE0, long, 0x468) & 0xFF0000FF00000000L)) {
            if ((func_L01_004606E8(func_003A3BB8(0x40, 0), frames, 0, 0) != 0) || (FLD(D_001A4BE0, u32, 0x25C4) == 0xE) || (FLD(D_001A4BE0, u32, 0x25C4) == 0xF) || (FLD(D_001A4BE0, u32, 0x25C4) == 0xD)) {
                if ((FLD(D_001A4BE0, u32, 0x25C4) != 0xE) && (FLD(D_001A4BE0, u8, 0x25E9) == 0) && ((FLD(D_001A4BE0, u8, 0x147C) == 0) || !(FLD(D_001A4BE0, f32, 0x33C) < 0.4f)) && (FLD(D_001A4BE0, u8, 0x4FF) != 0) && (FLD(D_001A4BE0, s32, 0x1B8) >= 0xD) && ((FLD(D_001A4BE0, u8, 0x46E) == 0) || ((FLD(D_001A4BE0, f32, 0x33C) > 0.7f) && (fabs_asm(func_L01_005114B0((s8 *)(D_001A4BE0 + 0xF0))) < 0.116000012f)))) {
                    func_L27_004D1568(0xE, 1);
                } else if ((D_00142CA2[0] != 0) && (func_L01_004E9238(3) != 4) && (FLD(D_001A4BE0, s16, 0x2884) == 0) && (FLD(D_001D52FC, s32, 0x1A0) & func_003A3BB8(0x40, 0)) && (lim < FLD(D_001A4BE0, s32, 0x1B8)) && (FLD(D_001A4BE0, s16, 0x4F6) < FLD(D_001A4BE0, s32, 0x1B8))) {
                    f32 need = 0.6f;
                    if ((FLD(D_001A4BE0, u32, 0x25C4) == 9) || (FLD(D_001A4BE0, u32, 0x25C4) == 7)) {
                        need = 1.0f;
                    }
                    if (FLD(D_001A4BE0, u32, 0x25C4) == 0xE) {
                        need = 1.5f;
                    }
                    if (need < FLD(D_001A4BE0, f32, 0x33C)) {
                        func_L27_004D1568(8, 1);
                    }
                }
            }
        }
        if ((FLD(D_001A4BE0, s32, 0x528) != 0) && (FLD(D_001A4BE0, u32, 0x25C4) != 0xB)) {
            func_L27_004D1568(0x17, 1);
        }
        break;
    }
    case 0xB1:
        if (FLD(D_001A4BE0, s32, 0x1B8) >= 0x22) {
            if (FLD(D_001A4BE0, s32, 0x2850) <= 0) {
                func_L27_004D1568(0x39, 1);
            } else {
                func_L27_004D1568(0, 1);
            }
        }
        break;
    case 0x16:
        if ((FLD(D_001A4BE0, f32, 0xC18) > 12.5f) && (FLD(D_001A4BE0, u8, 0x2877) == 0) && (FLD(D_001A4BE0, s16, 0x36E) != 0) && (FLD(D_001A4BE0, f32, 0x33C) > 1.0f)) {
            if (FLD(D_001A4BE0, s32, 0x25D0) == 0xB0) {
                if (FLD(D_001A4BE0, s32, 0x2850) <= 0) {
                    func_L27_004D1568(0x79, 1);
                } else {
                    func_L27_004D1568(0xB0, 0);
                    func_L01_0050FB40(0x7A, 0, 9.0f);
                }
            } else {
                func_L27_004D1568(6, 1);
            }
            break;
        }
        if (FLD(D_001A4BE0, s32, 0x1B8) >= 0x17) {
            if (FLD(D_001A4BE0, s32, 0x2850) <= 0) {
                if (FLD(D_001A4BE0, s32, 0x25D0) == 0xB0) {
                    func_L27_004D1568(0x79, 1);
                } else {
                    func_L27_004D1568(0x39, 1);
                }
            } else if (FLD(D_001A4BE0, u8, 0x2877) != 0) {
                func_L27_004D1568(0x87, 1);
            } else if (FLD(D_001A4BE0, s32, 0x25D0) == 0xB0) {
                func_L27_004D1568(0xB0, 1);
            } else {
                func_L27_004D1568(0, 0);
            }
        }
        break;
    case 0x91:
        if (FLD(D_001A4BE0, s32, 0xC08) & 2) {
            func_L01_0050FB40(0x75, 0, 2.0f);
        }
        if ((FLD(D_001A4BE0, s32, 0x1B8) >= 0x2B) && (FLD(D_001A4BE0, s16, 0x1E0) == 0)) {
            if (FLD(D_001A4BE0, s32, 0x2850) <= 0) {
                func_L27_004D1568(0x39, 1);
            } else if (func_L27_004D1568(0, 0) != 0) {
                func_L01_0050FB40(func_L04_004EFEC0(0), 0, 11.0f);
            }
        }
        break;
    case 0x3F:
    {
        s16 s = FLD(D_001A4BE0, s16, 0x28A8);
        if (s >= 0x24) {
            func_L01_0050FB40(0x12, 0, 8.0f);
            break;
        }
        if ((s == 0) && (FLD(D_001A4BE0, s32, 0xC08) & 2)) {
            if (FLD(FLD(D_001A4BE0, u8 *, 0x25C0), u8, 0x43) != func_L04_004EFEC0(0)) {
                func_L01_0050FB40(func_L04_004EFEC0(0), 0, 10.0f);
            } else if (func_003824E0(0.0f, 1.0f) < 0.15f) {
                func_L01_0050FB40(0x15, 0, 7.0f);
            }
        }
        if (FLD(D_001A4BE0, u8, 0x147C) != 0) {
            func_L27_004D1568(0x4E, 1);
            break;
        }
        if ((FLD(D_001D52FC, s32, 0x1A0) & func_L01_00512DF8(func_003A3BB8(4, 0))) && ((FLD(D_001A4BE0, u8, 0x25E4) != 0) || (D_001439F4[0] != 2) || (FLD(D_001A4BE0, s32, 0x1228) == 0x6F)) && (func_L01_003EB2D8(0) == 0)) {
            func_L27_004D1568(1, 1);
            break;
        }
        if (FLD(D_001A4BE0, s16, 0x36E) != 0) {
            func_L27_004D1568(0x41, 1);
            break;
        }
        if (func_L01_004606E8(func_003A3BB8(0x40, 0), 7, 0, 0) != 0) {
            func_L27_004D1568(0x45, 1);
            break;
        }
        if (func_L01_004606E8(0x80, 7, 0, 0) != 0) {
            func_L27_004D1568(0x4D, 1);
            break;
        }
        func_L01_004EE850(0, 1.0f);
        if ((FLD(D_001A4BE0, f32, 0x2838) > 0.2f) && (FLD(D_001A4BE0, f32, 0x1B0) > 0.0f)) {
            func_L27_004D1568(0x40, 1);
            break;
        }
        if ((FLD(D_001A4BE0, s16, 0x28A8) == 0) && (FLD(FLD(D_001A4BE0, u8 *, 0x25C0), u8, 0x43) == 0x12)) {
            func_L01_0050FB40(func_L04_004EFEC0(0), 0, 10.0f);
        }
        break;
    }
    case 0x4D:
    {
        u8 *rec;
        s32 frames;
        if (FLD(D_001A4BE0, u8, 0x147C) != 0) {
            func_L27_004D1568(0x4E, 1);
            break;
        }
        rec = (u8 *)&D_L27_002F8A50[FLD(D_001A4BE0, s16, 0xBDC)];
        if (FLD(D_001A4BE0, s32, 0xC0C) == 0) {
            if ((f32)FLD(rec, s32, 0x18) < FLD(D_001A4BE0, f32, 0xC18)) {
                func_L27_004D1568(0x3F, 0);
            }
            if ((FLD(D_001A4BE0, s32, 0xC0C) == 0) && ((f32)FLD(rec, s32, 0x10) <= FLD(D_001A4BE0, f32, 0xC18))) {
                s32 n = (s32)FLD(D_001A4BE0, f32, 0xC18) - FLD(rec, s32, 0xC);
                if (n <= 0) {
                    n = 1;
                }
                if (n >= 0xD) {
                    n = 0xC;
                }
                if (func_L01_004606E8(0x80, n, 0, 0) != 0) {
                    func_L27_004D1568(0x4D, 1);
                }
            }
        }
        frames = ((s32)FLD(D_001A4BE0, f32, 0xC18) - FLD(rec, s32, 0xC)) * 2;
        if (((f32)FLD(rec, s32, 0x14) < FLD(D_001A4BE0, f32, 0xC18)) && (FLD(D_001A4BE0, s32, 0xC0C) == 0) && (func_L01_004606E8(func_003A3BB8(0x40, 0), frames, 0, 0) != 0)) {
            func_L27_004D1568(0x45, 1);
        }
        break;
    }
    case 0x45:
    case 0x48:
    {
        s16 lo = FLD(D_001A4BE0, s16, 0x47C);
        s32 now = FLD(D_001A4BE0, s32, 0x1B8);
        if (!(lo < now)) {
            break;
        }
        if (now == lo + 1) {
            func_L01_00511748((f32 *)(D_001A4BE0 + 0x80), (f32 *)(D_001A4BE0 + 0xF0), &sp40, FLD(D_001A4BE0, f32, 0x4F0));
            func_L01_004E5030(FLD(D_001A4BE0, f32, 0x498), (f32)sp40, FLD(D_001A4BE0, f32, 0x4E4), 0.36f);
            break;
        }
        if ((FLD(D_001A4BE0, u8, 0x46D) != 0) && (now >= FLD(D_001A4BE0, s32, 0x400)) && (now < FLD(D_001A4BE0, s32, 0x404))) {
            f32 left = (f32)(FLD(D_001A4BE0, s32, 0x410) - FLD(D_001A4BE0, s32, 0x400));
            if (left > 0.0f) {
                func_L01_004E5030(FLD(D_001A4BE0, f32, 0x498), left, FLD(D_001A4BE0, f32, 0x4E4), -1.0f);
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
                    func_L01_0050FB40(FLD(hero, u8, 0x43), k, 5.0f);
                }
            }
        }
        if (FLD(D_001A4BE0, u8, 0x46C) != 0) {
            FLD(D_001A4BE0, f32, 0xC00) = 1.0f;
        } else if (FLD(D_001A4BE0, u8, 0x46E) != 0) {
            if ((s32)FLD(hero, u8, 0x41) < (s32)(FLD(D_001A4BE0, f32, 0x4A0))) {
                s32 k;
                FLD(D_001A4BE0, s16, 0x47E) = (s32)(func_L01_00510478(60.0f, FLD(D_001A4BE0, f32, 0x4F0), -1.0f));
                func_L01_004E5030(FLD(D_001A4BE0, f32, 0x49C), (f32)FLD(D_001A4BE0, s16, 0x47E), FLD(D_001A4BE0, f32, 0x4E4), -1.0f);
                k = (s32)(FLD(D_001A4BE0, f32, 0x4A0)) + 1;
                if (FLD(D_001A4BE0, f32, 0xC00) > 1.8f) {
                    func_L01_0050FB40(FLD(hero, u8, 0x43), k, (f32)(FLD(D_001A4BE0, s16, 0x47E) + 2));
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
        if ((FLD(D_001A4BE0, u8, 0x46C) != 0) && (FLD(D_001A4BE0, s16, 0x1E0) == 0) && (FLD(D_001A4BE0, u8, 0x147C) == 0) && (func_L01_004606E8(func_003A3BB8(0x40, 0), 3, 0, 0) != 0) && (FLD(D_001A4BE0, s16, 0x36E) < 3)) {
            func_L01_004EE850(0, 1.0f);
            func_L27_004D1568(0x45, 1);
            break;
        }
        if (FLD(D_001A4BE0, u8, 0x46C) >= 2) {
            FLD(D_001A4BE0, s32, 0x280C) = 0;
            func_L01_004EE850(0, 1.0f);
            if ((FLD(D_001A4BE0, f32, 0x1B0) > D_L27_001DBD84[2]) && (FLD(D_001A4BE0, f32, 0x2838) > 0.5f) && (FLD(D_001A4BE0, u8, 0x147C) == 0) && (FLD(D_001A4BE0, s16, 0x1E0) == 0) && (func_0038DBA0(FLD(D_001A4BE0, f32, 0x1A0), FLD(D_001A4BE0, f32, 0x98)) < 1.57079637f)) {
                func_L27_004D1568(0x40, 1);
            } else if (FLD(D_001A4BE0, u8, 0x46C) >= 0xB) {
                func_L27_004D1568(0x3F, 1);
            }
        }
        if ((FLD(D_001A4BE0, f32, 0x33C) > 2.0f) && (FLD(D_001A4BE0, u8, 0x46E) != 0) && (FLD(D_001A4BE0, s32, 0x1B8) >= 0x22)) {
            func_L27_004D1568(0x41, 1);
            break;
        }
        if ((FLD(D_001A4BE0, u8, 0x46E) != 0) && (FLD(D_001A4BE0, f32, 0x33C) < 0.2f) && (func_L01_004606E8(0x80, 4, 0, 0) != 0)) {
            func_L27_004D1568(0x4D, 1);
            break;
        }
        if (FLD(D_001A4BE0, s32, 0x528) != 0) {
            func_L27_004D1568(0x46, 1);
            break;
        }
        if (FLD(D_001A4BE0, u32, 0x25C4) == 0x48) {
            break;
        }
        if ((func_L01_004606E8(func_003A3BB8(0x40, 0), 4, 0, 0) != 0) && (FLD(D_001A4BE0, f32, 0x33C) > 0.55f)) {
            func_L27_004D1568(0x4B, 1);
        }
        break;
    }
    case 0x4B:
        if ((FLD(D_001A4BE0, s32, 0x1B8) >= 0x1A) && !(FLD(D_001D52FC, s32, 0x1A0) & func_003A3BB8(0x40, 0))) {
            func_L27_004D1568(0x41, 1);
            break;
        }
        if (FLD(D_001A4BE0, s32, 0x528) != 0) {
            func_L27_004D1568(0x46, 1);
            break;
        }
        if ((FLD(D_001A4BE0, s16, 0x36E) != 0) && !((FLD(D_001A4BE0, f32, 0x88) - FLD(D_001A4BE0, f32, 0x338)) < 0.0f)) {
            break;
        }
        if (FLD(D_001A4BE0, s32, 0x1B8) < 8) {
            FLD(D_001A4BE0, s16, 0x1EE) = 0xA - FLD(D_001A4BE0, u16, 0x1B8);
        }
        if (FLD(D_001A4BE0, f32, 0x2838) > 0.3f) {
            func_L27_004D1568(0x40, 1);
            break;
        }
        if (FLD(D_001A4BE0, s16, 0x36E) == 0) {
            func_L27_004D1568(0x3F, 1);
        }
        break;
    case 0x4F:
        if (FLD(D_001A4BE0, f32, 0xC18) > 23.0f) {
            func_L27_004D1568(0x3F, 0);
            func_L01_0050FB40(0x21, 7, 4.0f);
        }
        break;
    case 0x41:
        if (FLD(D_001A4BE0, s16, 0x36E) == 0) {
            if (FLD(D_001A4BE0, f32, 0x118) < -0.180000007f) {
                FLD(D_001A4BE0, f32, 0x118) = -0.180000007f;
            }
            if (FLD(D_001A4BE0, f32, 0xF8) < -0.180000007f) {
                FLD(D_001A4BE0, f32, 0xF8) = -0.180000007f;
            }
            if (FLD(D_001A4BE0, s32, 0x2850) <= 0) {
                func_L27_004D1568(0x43, 1);
            } else if ((FLD(D_001A4BE0, f32, 0x2838) > 0.5f) && (FLD(D_001A4BE0, s16, 0x1E0) == 0)) {
                func_L27_004D1568(0x40, 1);
            } else {
                func_L27_004D1568(0x3F, 1);
            }
            break;
        }
        if (FLD(D_001A4BE0, s32, 0x2850) <= 0) {
            break;
        }
        if (FLD(D_001A4BE0, s32, 0x528) != 0) {
            func_L27_004D1568(0x46, 1);
            break;
        }
        if ((func_L01_004606E8(func_003A3BB8(0x40, 0), 4, 0, 0) != 0) && (FLD(D_001A4BE0, f32, 0x33C) > 0.6f)) {
            func_L27_004D1568(0x4B, 1);
        }
        break;
    case 0x44:
        if ((FLD(D_001A4BE0, f32, 0xF8) < 0.0f) && (FLD(D_001A4BE0, s32, 0x360) != 0)) {
            func_L27_004D1568(0x3F, 1);
        }
        break;
    case 0x4E:
        if (FLD(D_001A4BE0, s32, 0x1B8) >= 0xFB) {
            func_L01_004EDE10();
        }
        if (FLD(D_001A4BE0, u8, 0x147C) == 0) {
            if (FLD(D_001A4BE0, s16, 0x36E) != 0) {
                func_L27_004D1568(0x41, 1);
            } else {
                func_L27_004D1568(0x3F, 1);
            }
        }
        break;
    case 0x40:
    {
        f32 spd;
        if (FLD(D_001A4BE0, u8, 0x147C) != 0) {
            func_L27_004D1568(0x4E, 1);
            break;
        }
        if ((FLD(D_001A4BE0, s32, 0xC0C) == 0) && (FLD(D_001A4BE0, f32, 0x170) < 0.0330000035f) && (FLD(FLD(D_001A4BE0, u8 *, 0x25C0), u8, 0x43) != 0x19)) {
            u8 *h = FLD(D_001A4BE0, u8 *, 0x25C0);
            u8 *t = FLD(h, u8 *, 0x24);
            s32 n = FLD(FLD(t, u8 *, 0xAC), u8, 0x10);
            func_L01_0050FB40(0x19, (FLD(h, u8, 0x41) * n / FLD(FLD(t, u8 *, 0xB0), u8, 0x10) + 1) % n, 7.0f);
        } else if ((FLD(D_001A4BE0, s32, 0xC0C) == 0) && (FLD(D_001A4BE0, f32, 0x170) > 0.0396000072f) && (FLD(FLD(D_001A4BE0, u8 *, 0x25C0), u8, 0x43) != 0x1A)) {
            u8 *h = FLD(D_001A4BE0, u8 *, 0x25C0);
            u8 *t = FLD(h, u8 *, 0x24);
            s32 n = FLD(FLD(t, u8 *, 0xB0), u8, 0x10);
            func_L01_0050FB40(0x1A, (FLD(h, u8, 0x41) * n / FLD(FLD(t, u8 *, 0xAC), u8, 0x10) + 7) % n, 7.0f);
        }
        spd = FLD(D_001A4BE0, f32, 0x170);
        if (FLD(D_001A4BE0, u8, 0x3EF) != 0) {
            spd = 0.0660000071f;
        }
        if (FLD(FLD(D_001A4BE0, u8 *, 0x25C0), u8, 0x43) == 0x19) {
            FLD(D_001A4BE0, f32, 0xC00) = spd * 75.0f;
        } else if (FLD(FLD(D_001A4BE0, u8 *, 0x25C0), u8, 0x43) == 0x1A) {
            FLD(D_001A4BE0, f32, 0xC00) = spd * 16.666666f;
        }
        if (FLD(D_001A4BE0, f32, 0xC00) < 0.569999993f) {
            FLD(D_001A4BE0, f32, 0xC00) = 0.569999993f;
        }
        if (func_L01_004606E8(func_003A3BB8(0x40, 0), 7, 0, 0) != 0) {
            func_L27_004D1568(0x45, 1);
            break;
        }
        if (func_L01_004606E8(0x80, 7, 0, 0) != 0) {
            func_L27_004D1568(0x4D, 1);
            break;
        }
        if ((FLD(D_001A4BE0, s16, 0x36E) >= 4) && ((FLD(D_001A4BE0, f32, 0x33C) > 0.8f) || (FLD(D_001A4BE0, f32, 0x340) > 0.87266463f))) {
            func_L27_004D1568(0x41, 1);
            break;
        }
        if ((FLD(D_001A4BE0, s16, 0x36E) == 0) && (FLD(D_001A4BE0, f32, 0x2838) < 0.17f)) {
            func_L27_004D1568(0x3F, 1);
        }
        break;
    }
    case 0x42:
        if ((FLD(D_001A4BE0, s32, 0x1B8) >= 0x1B) && (FLD(D_001A4BE0, s16, 0x36E) != 0) && (FLD(D_001A4BE0, f32, 0x33C) > 1.0f)) {
            func_L27_004D1568(0x41, 1);
            break;
        }
        if (FLD(D_001A4BE0, s32, 0x1B8) >= 0x16) {
            if (FLD(D_001A4BE0, s32, 0x2850) <= 0) {
                func_L27_004D1568(0x43, 1);
            } else {
                func_L27_004D1568(0x3F, 0);
            }
        }
        break;
    case 0x46:
        if (FLD(D_001A4BE0, s32, 0xC08) & 2) {
            func_L27_004D1568(0x47, 1);
        }
        break;
    case 0x47:
        func_L01_004EE850(0, 1.0f);
        *(s128 *)v10 = *(s128 *)(D_001A4BE0 + 0x80);
        if (func_L01_004E8318((s8 *)v10, (s8 *)(D_001A4BE0 + 0x90), NULL) == 0) {
            func_L27_004D1568(0x41, 1);
            FLD(D_001A4BE0, s16, 0x1D0) = 8;
            break;
        }
        if (((FLD(D_001A4BE0, f32, 0x2838) > 0.5f) && (func_L01_004606E8(func_003A3BB8(0x40, 0), 7, 0, 0) != 0) && (func_0038DBA0(FLD(D_001A4BE0, f32, 0x1A0), FLD(D_001A4BE0, f32, 0x98)) > 2.3561945f)) || (FLD(D_001D52FC, s32, 0x1A0) & func_003A3BB8(8, 0))) {
            func_L27_004D1568(0x41, 1);
            FLD(D_001A4BE0, s16, 0x1D0) = 8;
            break;
        }
        if (func_L01_004606E8(func_003A3BB8(0x40, 0), 7, 0, 0) != 0) {
            func_L27_004D1568(0x48, 1);
            break;
        }
        if (FLD(D_001A4BE0, f32, 0x2838) > 0.5f) {
            if (func_0038DBA0(FLD(D_001A4BE0, f32, 0x1A0), func_0038DAB8(FLD(D_001A4BE0, f32, 0x98), 1.57079637f)) < 0.785398185f) {
                *(s128 *)v20 = *(s128 *)(D_001A4BE0 + 0x80);
                v20[0] += func_0038D098(func_0038DAB8(FLD(D_001A4BE0, f32, 0x98), 1.57079637f)) * 0.3f;
                v20[1] += func_0038D0B0(func_0038DAB8(FLD(D_001A4BE0, f32, 0x98), 1.57079637f)) * 0.3f;
                if (func_L01_004E8318((s8 *)v20, (s8 *)(D_001A4BE0 + 0x90), NULL) != 0) {
                    func_L27_004D1568(0x49, 1);
                }
                break;
            }
        }
        if (FLD(D_001A4BE0, f32, 0x2838) > 0.5f) {
            if (func_0038DBA0(FLD(D_001A4BE0, f32, 0x1A0), func_0038DAB8(FLD(D_001A4BE0, f32, 0x98), -1.57079637f)) < 0.785398185f) {
                *(s128 *)v20 = *(s128 *)(D_001A4BE0 + 0x80);
                v20[0] += func_0038D098(func_0038DAB8(FLD(D_001A4BE0, f32, 0x98), -1.57079637f)) * 0.3f;
                v20[1] += func_0038D0B0(func_0038DAB8(FLD(D_001A4BE0, f32, 0x98), -1.57079637f)) * 0.3f;
                if (func_L01_004E8318((s8 *)v20, (s8 *)(D_001A4BE0 + 0x90), NULL) != 0) {
                    func_L27_004D1568(0x4A, 1);
                }
            }
        }
        break;
    case 0x49:
    case 0x4A:
    {
        f32 side;
        *(s128 *)v10 = FLD(D_001A4BE0 + 0x80, s128, 0);
        side = 1.57079637f;
        if (FLD(D_001A4BE0, u32, 0x25C4) == 0x4A) {
            side = -1.57079637f;
        }
        v10[0] += func_0038D098(func_0038DAB8(FLD(D_001A4BE0, f32, 0x98), side)) * 0.3f;
        v10[1] += func_0038D0B0(func_0038DAB8(FLD(D_001A4BE0, f32, 0x98), side)) * 0.3f;
        func_L01_004EE850(0, 1.0f);
        if ((FLD(D_001A4BE0, f32, 0x2838) < 0.5f) || (func_0038DBA0(FLD(D_001A4BE0, f32, 0x1A0), func_0038DAB8(FLD(D_001A4BE0, f32, 0x98), side)) > 0.785398185f) || (func_L01_004E8318((s8 *)v10, (s8 *)(D_001A4BE0 + 0x90), NULL) == 0)) {
            if (FLD(D_001A4BE0, s32, 0xC08) & 2) {
                func_L27_004D1568(0x47, 1);
                break;
            }
        }
        if ((FLD(D_001A4BE0, f32, 0x2838) > 0.5f) && (func_L01_004606E8(func_003A3BB8(0x40, 0), 7, 0, 0) != 0) && (func_0038DBA0(FLD(D_001A4BE0, f32, 0x1A0), FLD(D_001A4BE0, f32, 0x98)) > 2.3561945f)) {
            func_L27_004D1568(0x41, 1);
            FLD(D_001A4BE0, s16, 0x1D0) = 0x21;
            break;
        }
        if (func_L01_004606E8(func_003A3BB8(0x40, 0), 7, 0, 0) != 0) {
            func_L27_004D1568(0x48, 1);
        }
        break;
    }
    case 0x51:
        if (FLD(D_001A4BE0, s32, 0xC08) & 2) {
            if (FLD(FLD(D_001A4BE0, u8 *, 0x25C0), u8, 0x43) != 1) {
                func_L01_0050FB40(1, 0, 10.0f);
            } else if (func_003824E0(0.0f, 1.0f) < 0.5f) {
                func_L01_0050FB40(2, 0, 7.0f);
            }
        }
        if ((FLD(D_001D52FC, s32, 0x1A0) & func_L01_00512DF8(func_003A3BB8(4, 0))) && ((FLD(D_001A4BE0, u8, 0x25E4) != 0) || (D_001439F4[0] != 2) || (FLD(D_001A4BE0, s32, 0x1228) == 0x6F)) && (func_L01_003EB2D8(0) == 0)) {
            func_L27_004D1568(1, 1);
            break;
        }
        if (FLD(D_001A4BE0, s16, 0x36E) != 0) {
            func_L27_004D1568(0x53, 1);
            break;
        }
        if (FLD(D_001A4BE0, s16, 0x1E0) != 0) {
            break;
        }
        if (func_L01_004606E8(func_003A3BB8(0x40, 0), 7, 0, 0) != 0) {
            func_L27_004D1568(0x54, 1);
            break;
        }
        if (FLD(D_001D52FC, s32, 0x1A4) & 0x20) {
            func_L27_004D1568(0x59, 1);
            break;
        }
        if (func_L01_004606E8(0x80, 6, 0, 0) != 0) {
            if (FLD(D_001A4BE0, s16, 0x288C) == 0) {
                FLD(D_001A4BE0, s16, 0x2888) = 1;
                FLD(D_001A4BE0, s16, 0x288C) = 0x12;
                FLD(D_001A4BE0, s16, 0x288A) = 1;
            }
            func_L01_004EC600(0);
            break;
        }
        func_L01_004EE850(0, 1.0f);
        if ((FLD(D_001A4BE0, f32, 0x2838) > 0.22f) && (FLD(D_001A4BE0, f32, 0x1B0) > 0.0f)) {
            func_L27_004D1568(0x52, 1);
        }
        break;
    case 0x57:
        if (FLD(D_001A4BE0, s32, 0x1B8) >= 0xFB) {
            func_L01_004EDE10();
        }
        if (FLD(D_001A4BE0, u8, 0x147C) == 0) {
            if (FLD(D_001A4BE0, s16, 0x36E) != 0) {
                func_L27_004D1568(0x53, 1);
            } else {
                func_L27_004D1568(0x51, 1);
            }
        }
        break;
    case 0x59:
        if ((FLD(D_001A4BE0, s32, 0x1B8) >= 0x26) && !(FLD(D_001D52FC, s32, 0x1A0) & 0x20)) {
            func_L27_004D1568(0x51, 0);
            func_L01_0050FB40(1, 0, 17.0f);
            break;
        }
        if (func_L01_004606E8(func_003A3BB8(0x40, 0), 7, 0, 0) != 0) {
            func_L27_004D1568(0x54, 1);
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
            func_L01_00511748((f32 *)(D_001A4BE0 + 0x80), (f32 *)(D_001A4BE0 + 0xF0), &sp44, FLD(D_001A4BE0, f32, 0x4F0));
            func_L01_004E5030(FLD(D_001A4BE0, f32, 0x498), (f32)sp44, FLD(D_001A4BE0, f32, 0x4E4), 0.36f);
            break;
        }
        if ((FLD(D_001A4BE0, u8, 0x46D) != 0) && (now >= FLD(D_001A4BE0, s32, 0x400)) && (now < FLD(D_001A4BE0, s32, 0x404))) {
            f32 left = (f32)(FLD(D_001A4BE0, s32, 0x410) - FLD(D_001A4BE0, s32, 0x400));
            if (left > 0.0f) {
                func_L01_004E5030(FLD(D_001A4BE0, f32, 0x498), left, FLD(D_001A4BE0, f32, 0x4E4), -1.0f);
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
                    func_L01_0050FB40(FLD(hero, u8, 0x43), k, 5.0f);
                }
            }
        }
        if (FLD(D_001A4BE0, u8, 0x46C) != 0) {
            FLD(D_001A4BE0, f32, 0xC00) = 1.0f;
        } else if (FLD(D_001A4BE0, u8, 0x46E) != 0) {
            if ((s32)FLD(hero, u8, 0x41) < (s32)(FLD(D_001A4BE0, f32, 0x4A0))) {
                s32 k;
                FLD(D_001A4BE0, s16, 0x47E) = (s32)(func_L01_00510478(60.0f, FLD(D_001A4BE0, f32, 0x4F0), -1.0f));
                func_L01_004E5030(FLD(D_001A4BE0, f32, 0x49C), (f32)FLD(D_001A4BE0, s16, 0x47E), FLD(D_001A4BE0, f32, 0x4E4), -1.0f);
                k = (s32)(FLD(D_001A4BE0, f32, 0x4A0)) + 1;
                if (FLD(D_001A4BE0, f32, 0xC00) > 1.8f) {
                    func_L01_0050FB40(FLD(hero, u8, 0x43), k, (f32)(FLD(D_001A4BE0, s16, 0x47E) + 2));
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
        if ((FLD(D_001A4BE0, u8, 0x46C) != 0) && (FLD(D_001A4BE0, s16, 0x1E0) == 0) && (FLD(D_001A4BE0, u8, 0x147C) == 0) && (func_L01_004606E8(func_003A3BB8(0x40, 0), 3, 0, 0) != 0) && (FLD(D_001A4BE0, s16, 0x36E) < 3)) {
            func_L01_004EE850(0, 1.0f);
            func_L27_004D1568(0x54, 1);
            break;
        }
        if (FLD(D_001A4BE0, u8, 0x46C) >= 2) {
            FLD(D_001A4BE0, s32, 0x280C) = 0;
            func_L01_004EE850(0, 1.0f);
            if ((FLD(D_001A4BE0, f32, 0x1B0) > D_L27_001DBD84[2]) && (FLD(D_001A4BE0, f32, 0x2838) > 0.5f) && (FLD(D_001A4BE0, u8, 0x147C) == 0) && (FLD(D_001A4BE0, s16, 0x1E0) == 0) && (func_0038DBA0(FLD(D_001A4BE0, f32, 0x1A0), FLD(D_001A4BE0, f32, 0x98)) < 1.57079637f)) {
                func_L27_004D1568(0x52, 1);
            } else if (FLD(D_001A4BE0, u8, 0x46C) >= 0xB) {
                func_L27_004D1568(0x51, 1);
            }
        }
        if ((FLD(D_001A4BE0, f32, 0x33C) > 2.0f) && (FLD(D_001A4BE0, u8, 0x46E) != 0) && (FLD(D_001A4BE0, s32, 0x1B8) >= 0x22)) {
            func_L27_004D1568(0x53, 1);
        }
        break;
    }
    case 0x53:
        if (FLD(D_001A4BE0, s16, 0x36E) == 0) {
            if (FLD(D_001A4BE0, f32, 0x118) < -0.180000007f) {
                FLD(D_001A4BE0, f32, 0x118) = -0.180000007f;
            }
            if (FLD(D_001A4BE0, f32, 0xF8) < -0.180000007f) {
                FLD(D_001A4BE0, f32, 0xF8) = -0.180000007f;
            }
            if (FLD(D_001A4BE0, s32, 0x2850) <= 0) {
                func_L27_004D1568(0x56, 1);
                break;
            }
            if ((FLD(D_001A4BE0, f32, 0x2838) > 0.5f) && (FLD(D_001A4BE0, s32, 0x1B8) < 0x21) && (FLD(D_001A4BE0, s16, 0x1E0) == 0)) {
                func_L27_004D1568(0x52, 1);
                break;
            }
            func_L27_004D1568(0x51, 0);
            func_L01_0050FB40(0x16, 0, -1.0f);
            FLD(D_001A4BE0, f32, 0xC00) = 0.35f;
            FLD(D_001A4BE0, s16, 0x1E0) = 0x11;
        }
        break;
    case 0x52:
        FLD(D_001A4BE0, f32, 0xC00) = FLD(D_001A4BE0, f32, 0x170) * D_L27_001DBCD0;
        if (FLD(D_001A4BE0, f32, 0xC00) < 1.0f) {
            FLD(D_001A4BE0, f32, 0xC00) = 1.0f;
        }
        if ((FLD(D_001A4BE0, s16, 0x36E) >= 4) && ((FLD(D_001A4BE0, f32, 0x33C) > 0.8f) || (FLD(D_001A4BE0, f32, 0x340) > 0.87266463f))) {
            func_L27_004D1568(0x53, 1);
            break;
        }
        if (FLD(D_001A4BE0, s16, 0x1E0) != 0) {
            func_L27_004D1568(0x51, 1);
        }
        if (func_L01_004606E8(func_003A3BB8(0x40, 0), 7, 0, 0) != 0) {
            func_L27_004D1568(0x54, 1);
            break;
        }
        if (func_L01_004606E8(0x80, 6, 0, 0) != 0) {
            if (FLD(D_001A4BE0, s16, 0x288C) == 0) {
                FLD(D_001A4BE0, s16, 0x2888) = 1;
                FLD(D_001A4BE0, s16, 0x288C) = 0x12;
                FLD(D_001A4BE0, s16, 0x288A) = 1;
            }
            func_L01_004EC600(0);
            break;
        }
        if (FLD(D_001D52FC, s32, 0x1A4) & 0x20) {
            func_L27_004D1568(0x59, 1);
            break;
        }
        if ((FLD(D_001A4BE0, s16, 0x36E) == 0) && (FLD(D_001A4BE0, f32, 0x2838) < 0.17f)) {
            func_L27_004D1568(0x51, 1);
        }
        break;
    case 0x55:
        if ((FLD(D_001A4BE0, s32, 0x1B8) >= 0x1B) && (FLD(D_001A4BE0, s16, 0x36E) != 0) && (FLD(D_001A4BE0, f32, 0x33C) > 1.0f)) {
            func_L27_004D1568(0x53, 1);
            break;
        }
        if (FLD(D_001A4BE0, s32, 0xC08) & 2) {
            func_L27_004D1568(0x51, 1);
            break;
        }
        if (FLD(D_001A4BE0, s32, 0x1B8) >= 0x26) {
            if (FLD(D_001A4BE0, s32, 0x2850) <= 0) {
                func_L27_004D1568(0x56, 1);
            } else {
                func_L27_004D1568(0x51, 0);
            }
        }
        break;
    case 0x1D:
        if ((FLD(D_001A4BE0, u8, 0x25E4) == 0) && ((FLD(D_001A4BE0, u8, 0x25EB) == 0) || (FLD(D_001A4BE0, u8, 0x25E5) != 0))) {
            if (FLD(D_001D52FC, s32, 0x1A0) & func_003A3BB8(8, 0)) {
                func_L01_0050FB40(0xD, 0, 7.0f);
            } else {
                func_L01_0050FB40(func_L04_004EFEC0(1), 0, 7.0f);
            }
        }
        if (!(FLD(D_001D52FC, s32, 0x1A0) & func_003A3BB8(4, 0))) {
            if (FLD(D_001A4BE0, u32, 0x25C4) == 0x1D) {
                s32 anim;
                func_L27_004D1568(0, 0);
                anim = func_L04_004EFEC0(1);
                if (FLD(FLD(D_001A4BE0, u8 *, 0x25C0), u8, 0x43) != anim) {
                    func_L01_0050FB40(anim, 0, 7.0f);
                }
            }
            D_001D60F8 = 0;
        }
        break;

    case 0x22:
        if (FLD(D_001A4BE0, f32, 0xC18) > 19.0f) {
            if (func_L01_004606E8(func_003A3BB8(0x40, 0), 9, 0, 0) != 0) {
                if (FLD(D_001D52FC, s32, 0x1A0) & func_003A3BB8(8, 0)) {
                    func_L01_00506E30();
                    break;
                }
                func_L27_004D1568(7, 1);
                break;
            }
        }
        if (FLD(D_001A4BE0, f32, 0xC18) >= 21.0f) {
            func_L27_004D1568(0, 0);
        }
        break;

    default:
        break;
    }
end:
    if (mode != FLD(D_001A4BE0, s32, 0x25CC)) {
        func_L01_004E1560();
    }
    sel = FLD(D_001A4BE0, s32, 0x25D0);
    if (((sel == 0x3C) && (FLD(D_001A4BE0, s32, 0x25C4) != 0x3D)) || ((sel == 0x3D) && (FLD(D_001A4BE0, s32, 0x1A04) != 0))) {
        func_L01_00506820();
    }
    if (sub != FLD(D_001A4BE0, s32, 0x25C8)) {
        FLD(D_001A4BE0, s32, 0x1C0) = 0;
    }
    if (anim != FLD(hero, u8, 0x43)) {
        FLD(D_001A4BE0, s32, 0x1C4) = 0;
    }
}
/* localdecomp:end func_L27_004D7CD8 */

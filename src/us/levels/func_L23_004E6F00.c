#include "common.h"

/* NTSC-U counterpart of func_L23_004EAE60 (src/levels/23_holostar_studios_clank/L23_004EAE60.c) */
/* localdecomp:start func_L23_004E6F00 */
/* func_L23_004E6F00 (Holostar Studios, Clank): the hero's per-frame state dispatcher,
 * func_L01_00507AF8 plus Clank's states 0x5A-0x62; a member of the 0x110 dispatcher family (docs/prep/FAMILIES.md; rac2 twin
 * func_L20_002DEBE0). Hero fields are read through the D_001A4BE0 array, which gives retail's
 * per-block `addiu $x,$s3,%lo(D_001A4BE0)`; the vector library's VU0 adds, quadword zero and
 * abs.s come from include/vu0.h, and qcopy is the library's plain quadword copy (its pointer
 * parameters are what keeps &v10 in a saved register across calls). D_001A4C60 (the hero's
 * position, +0x80) and D_L23_001DBE14 are small-data symbols (docs/GLOBALS.md). The file needs
 * -mvu0-use-vf0-vf2 and @ps2as, and its div.s padding row (config/levels/divs_nops.txt). */
#include "vu0.h"
extern u8 *D_001D52FC;
extern u8 D_001425C0[];
extern u8 D_001A4BE0[];
extern u8 D_001A4C60[] __attribute__((section(".sdata")));
extern u8 D_001439F4[];
extern u8 D_00143A05[];
extern s32 D_L23_001D6740_004E6F00;
extern f32 D_L23_001DEDB0;
extern s32 D_L23_002D2770 __attribute__((section(".data")));
extern s32 D_L23_001DECC8;
extern u8 D_L23_002F53B0[];
extern u8 D_L23_002F55C0[];
extern u8 D_L23_002C6780[];
extern u8 D_L23_001E1AC0[];
s32 func_00388398(void *);
f32 func_003887C8(void *, void *);
f32 func_00389468(f32 a0, f32 a1);
void func_0038EB10(s32, s32, void *, void *, void *, s32, s32);
void func_0038F3A0(u8 *object);
void func_0038F3F8(s8 *);
s32 func_0038FDC0(s8 *);
void func_003906E8(void *a0);
void func_00390730(u8 *object);
void func_00390C18();
void func_003BE4F0(u8 *object, s32 animation, s32 frame, s32 rate);
s32 func_0037E208(s32 a0, s32 a1);
s32 func_0039E928(s32, s32);
void func_003DFF90(s32 argument);
void func_003DF7C0(s32 argument);
s32 func_L01_003E9428(s32);
s32 func_L01_0045D358(s32, s32, void *, s32);
s32 func_L23_004BDA28(s32 arg);
u32 func_L01_004DC1A0(u32 param_1);
void func_L01_004DD4B0(s32 kind, s32 side, s32 play_sound, s32 duration);
void func_L01_004DD850(void);
s32 func_L01_004E5470(s32 index);
void func_L01_004E6CB0(void);
s32 func_L01_004EA1F8(f32 x);
void func_L01_004EAA78(s32, f32);
s32 func_L01_00500F98(void);
s32 func_L01_00501678(void);
s32 func_L01_00502368(s32 arg0, s32 arg1);
void func_L01_005028C8(void);
s32 func_L01_00502930(s32 *selected);
void func_L01_00503428(void);
void func_L01_00503668(void);
void func_L01_005037C0(void);
void func_L01_0050B3C0(void);
void func_L01_0050BB98(s32 a0, s32 a1, f32 f12);
void func_L01_0050BF28(void);
s32 func_L01_0050EE20(s32);
s32 func_L23_004CBD00(s32);
s32 func_L23_004DF5A8(s32, s32);
void func_003883C8(void *);
void func_L01_004EA040(void);
s32 func_L01_004EA1D8(u8 *);
s32 func_L01_0050FF18(void);
void func_L23_004E4290(s32);
void func_L01_004EADD0(void);
f32 func_L01_0050C4A0(f32 time, f32 acceleration, f32 height);
void func_L01_004E1268(f32 arg0, f32 arg1, f32 arg2, f32 arg3);
s32 func_L01_00502ED8(void);
void func_L01_0050BF40(s32 value);
typedef struct { s32 w[11]; } Rec2C_4EAE60;
extern Rec2C_4EAE60 D_L23_002F7350[];
extern s32 D_L23_001DBE30[2];
__asm__(".extern D_L23_001DBE30, 8");
s32 func_L01_00503188(void);
f32 func_003887A0(void *);
s32 func_L01_00503310(void);
void func_L01_005024B8(void);
void func_003BF640(f32 *, f32);
s32 func_L01_004F1068(s32 index, s32 flags);
f32 func_00388770(void *);
s32 func_L01_004E2628(f32 *out, f32 scale, f32 amount);
void func_003BDA38(s8 *a0, s32 a1, s8 *a2);
void *func_L01_0046A9C8(s8 *object, void *position, f32 *velocity, s32 *config, s32 flag);
f32 func_00388800(void *, void *);
extern s32 D_L23_001DBCD0[2];
__asm__(".extern D_L23_001DBCD0, 8");
extern s32 D_L23_001DBCE0[2];
__asm__(".extern D_L23_001DBCE0, 8");
extern s32 D_L23_001D673C_004E6F00;
extern u8 D_001A30B0[];
void func_0039FB08(s32 a0);
void func_L01_00452F40(u8 *entity, s32 enabled);
void func_00388BD0(f32 *, f32 *);
void func_003888C8(f32 *, f32 *, f32 *);
s32 func_L01_003F9498(void *, s32, void *, f32);
f32 func_00388960(f32);
f32 func_00388978(f32);
s32 func_003CE740(void *, void *, s32, void *, s32);
void func_00388830(void *, void *, f32);
f32 func_L01_00444740(f32 *a, f32 *b, f32 *out, f32 d, f32 e);
f32 func_L01_00442DA8(f32 *a0, f32 *a1, s32 *a2, f32 factor);
f32 func_00389380(f32 a0, f32 a1);
s32 func_L01_00472C40(void *path, void *out, s32 *index, f32 *offset, s32 wrap, f32 step);
void func_003886E8(void *, void *, f32);
s32 func_L01_004E4E00(s8 *, void **, vu0_q *, void *, void *, s32 *, void *, s32, s32);
s32 func_L01_00473340(void *, void *, void *, s32 *, f32 *, s32, f32, f32, f32);
f32 func_L01_0050D4D8(s8 *in);
f32 func_L01_0050D770(f32 *a0, f32 *a1, s32 *out, f32 scale);
s32 func_L01_004EAA20(f32);
extern s32 D_001D545C;
void func_L01_003378E0(void *, s32);
s32 func_L01_004E4550(s8 *, s8 *, s8 *);
void func_L01_004DD470(void);
void func_L01_0050CCC8(s16, u8, u8, u8, f32, f32);
void func_L01_0050D530(void *dst, void *src, f32 k);
extern u8 D_00142CA0[];
extern f32 D_L23_001DBE0C;
extern s32 D_L23_001DBE34;
s32 func_L01_004FB720(void);
s32 func_L01_004FB758(void);
void func_L01_004F10C8(s32);
void func_L01_004E20F0(s32 dust, s32 debris, s32 model);
f32 func_003BEBF8(f32 *value, f32 target, f32 step);
void func_L01_00502C58(void);
extern f32 D_L23_001DBE14[2];
f32 func_0037E250(f32 a0, f32 a1);
void func_L01_004E8830(s32);
extern f32 D_L23_001DBD50;
__asm__(".extern D_L23_001DBD50, 4");
extern u8 D_L23_001D60F8_004E6F00;


s32 func_L01_005010B8(void);
s32 func_L01_00501048(void);

s32 func_L23_00309720(void *);
s32 func_L01_00443648(void *, f32 *, s32, s32, s32, s32, f32, f32, f32);
extern f32 D_L23_001DBD0C;
__asm__(".extern D_L23_001DBD0C, 4");

static __inline__ void qcopy_4EAE60(void *dst, void *src) {
    *(vu0_q *)dst = *(vu0_q *)src;
}

void func_L23_004E6F00(void) {
    f32 v10[4] __attribute__((aligned(16)));
    f32 v20[4] __attribute__((aligned(16)));
    f32 v30[4] __attribute__((aligned(16)));
    f32 v40[4] __attribute__((aligned(16)));
    f32 v50[4] __attribute__((aligned(16)));
    f32 v60[4] __attribute__((aligned(16)));
    s32 sp70;
    s32 frames6A;
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
    s32 spA4;
    u8 *cur;
    s32 state0;
    s32 sub0;
    s32 anim0;

    cur = (((struct { u8 pad[0x25C0]; u8 * v; } *)D_001A4BE0)->v);
    state0 = (((struct { u8 pad[0x25CC]; s32 v; } *)D_001A4BE0)->v);
    sub0 = (((struct { u8 pad[0x25C8]; s32 v; } *)D_001A4BE0)->v);
    anim0 = (((struct { u8 pad[0x43]; u8 v; } *)cur)->v);
    if ((((struct { u8 pad[0x234]; s32 v; } *)D_001A4BE0)->v) != 0) {
        func_L23_004CBD00(0);
    } else if (func_L23_004CBD00(1) != 0) {
        goto end;
    }
    func_L01_00503428();
    if ((((struct { u8 pad[0x2850]; s32 v; } *)D_001A4BE0)->v) <= 0) {
        if (((((struct { u8 pad[0x25C4]; u32 v; } *)D_001A4BE0)->v) == 0) || ((((struct { u8 pad[0x25C4]; u32 v; } *)D_001A4BE0)->v) == 2)) {
            func_L23_004DF5A8(0x39, 1);
            goto end;
        }
    }
    if (func_L01_00501678() != 0) {
        goto end;
    }
    if (func_L01_005010B8() != 0) {
        goto end;
    }
    if (func_L01_00501048() != 0) {
        goto end;
    }
    if (func_L01_00500F98() != 0) {
        goto end;
    }
    if ((((((struct { u8 pad[0x1A4]; s32 v; } *)D_001D52FC)->v) & 0x10) || ((((struct { u8 pad[0x1C4]; s32 v; } *)D_001D52FC)->v) & 0x10)) && ((((struct { u8 pad[0x121C]; u8 v; } *)D_001A4BE0)->v) != 2) && (D_L23_002D2770 == 0) && (D_00143A05[1] == 0) && (D_L23_001DECC8 >= 8) && ((((struct { u8 pad[0x25C4]; u32 v; } *)D_001A4BE0)->v) != 0x58)) {
        if ((((((struct { u8 pad[0x25ED]; u8 v; } *)D_001A4BE0)->v) == 0) || ((((struct { u8 pad[0x25E4]; u8 v; } *)D_001A4BE0)->v) == 1) || ((((struct { u8 pad[0x1D2]; s16 v; } *)D_001A4BE0)->v) != 0))
            && (((((struct { u8 pad[0x25E8]; u8 v; } *)D_001A4BE0)->v) == 0) || ((((struct { u8 pad[0x25E4]; u8 v; } *)D_001A4BE0)->v) == 1) || ((((struct { u8 pad[0x1D2]; s16 v; } *)D_001A4BE0)->v) != 0))) {
            switch ((((struct { u8 pad[0x25E4]; u8 v; } *)D_001A4BE0)->v)) {
            case 0:
            case 3:
                if ((((struct { u8 pad[0x2882]; s16 v; } *)D_001A4BE0)->v) != 0) {
                    (((struct { u8 pad[0x287E]; s16 v; } *)D_001A4BE0)->v) = 0x1b;
                } else {
                    (((struct { u8 pad[0x287E]; s16 v; } *)D_001A4BE0)->v) = 0xf;
                }
                func_0038EB10(0x23, 0, func_0038F3A0, func_0038F3F8, func_0038FDC0, 0, 0);
                func_003DF7C0(0x168);
                func_003DFF90(0xb4);
                break;
            case 1:
                func_0038EB10(0x23, 0, func_003906E8, func_00390730, func_00390C18, 0, 0);
                break;
            }
        }
    }
    func_L01_00503668();
    func_L01_005037C0();
    if ((((struct { u8 pad[0x88]; f32 v; } *)D_001A4BE0)->v) < D_L23_001DEDB0) {
        if (((((struct { u8 pad[0x33C]; f32 v; } *)D_001A4BE0)->v) > 2.0f) && ((((struct { u8 pad[0x25E4]; u8 v; } *)D_001A4BE0)->v) != 2) && ((((struct { u8 pad[0x25C4]; u32 v; } *)D_001A4BE0)->v) != 0x79)) {
            func_L23_004DF5A8(0x79, 1);
            goto end;
        }
    }
    switch ((((struct { u8 pad[0x25C4]; u32 v; } *)D_001A4BE0)->v)) {
    case 0x0:
    {
        s32 notcrouch;
        s32 anim;
        u8 *obj;
        if (((((struct { u8 pad[0x1A0]; s32 v; } *)D_001D52FC)->v) & func_L01_0050EE20(func_0039E928(4, 0)))
            && (((((struct { u8 pad[0x25E4]; u8 v; } *)D_001A4BE0)->v) != 0) || (D_001439F4[0] != 2) || ((((struct { u8 pad[0x1228]; s32 v; } *)D_001A4BE0)->v) == 0x6F))
            && (func_L01_003E9428(0) == 0)) {
            func_L23_004DF5A8(1, 1);
            break;
        }
        func_L01_0050BF28();
        if ((((struct { u8 pad[0x2877]; u8 v; } *)D_001A4BE0)->v) != 0) {
            func_L23_004DF5A8(0x87, 1);
            break;
        }
        notcrouch = (((struct { u8 pad[0x1474]; u8 v; } *)D_001A4BE0)->v) == 0;
        {
        s32 one = 1;
        (((struct { u8 pad[0x1436]; s8 v; } *)D_001A4BE0)->v) = 0;
        if ((((struct { u8 pad[0x1314]; s32 v; } *)D_001A4BE0)->v) == 2) {
            obj = (((struct { u8 pad[0x12F0]; u8 * v; } *)D_001A4BE0)->v);
            if ((obj != 0) && ((((struct { u8 pad[0x60]; u8 v; } *)obj)->v) & 2) && ((((struct { u8 pad[0x43]; u8 v; } *)obj)->v) != one)) {
                func_003BE4F0(obj, one, 0, 7);
            }
            obj = (((struct { u8 pad[0x12F4]; u8 * v; } *)D_001A4BE0)->v);
            if ((obj != 0) && ((((struct { u8 pad[0x60]; u8 v; } *)obj)->v) & 2) && ((((struct { u8 pad[0x43]; u8 v; } *)obj)->v) != 1)) {
                func_003BE4F0(obj, 1, 0, 7);
            }
        }
        }
        if (((((struct { u8 pad[0x258]; f32 v; } *)D_L23_002F55C0)->v) > 0.61086524f) || ((((struct { u8 pad[0x254]; f32 v; } *)D_L23_002F55C0)->v) > 0.43633232f)) {
            obj = (((struct { u8 pad[0x12F0]; u8 * v; } *)D_001A4BE0)->v);
            if ((obj != 0) && ((((struct { u8 pad[0x43]; u8 v; } *)obj)->v) != 1)) {
                func_003BE4F0(obj, 1, 0, 0xc);
            }
            obj = (((struct { u8 pad[0x12F4]; u8 * v; } *)D_001A4BE0)->v);
            if ((obj != 0) && ((((struct { u8 pad[0x43]; u8 v; } *)obj)->v) != 1)) {
                func_003BE4F0(obj, 1, 0, 0xc);
            }
        }
        anim = func_L01_004DC1A0((((struct { u8 pad[0x43]; u8 v; } *)cur)->v));
        if ((anim == func_L23_004BDA28(0)) && notcrouch && ((((struct { u8 pad[0x1228]; s32 v; } *)D_001A4BE0)->v) != 0x12)) {
            if (func_L01_00502930(&sp70) != 0) {
                u8 *rec;
                (((struct { u8 pad[0x27F8]; s32 v; } *)D_001A4BE0)->v) = sp70;
                (((struct { u8 pad[0x208]; s16 v; } *)D_001A4BE0)->v) = 0x78;
                rec = D_L23_002F53B0 + sp70 * 0x70;
                (((struct { u8 pad[0x60]; s32 v; } *)rec)->v) = (((struct { u8 pad[0x5C]; f32 v; } *)rec)->v) * 60.0f;
                if ((((struct { u8 pad[0x44]; s32 v; } *)rec)->v) != 0) {
                    func_L23_004DF5A8(0x3C, 1);
                } else {
                    func_L01_0050BB98((((struct { u8 pad[0x48]; s32 v; } *)rec)->v), 0, 12.0f);
                }
            }
        } else if ((((struct { u8 pad[0xC08]; s32 v; } *)D_001A4BE0)->v) & 2) {
            s32 keep = 0;
            if (((((struct { u8 pad[0x25E9]; u8 v; } *)D_001A4BE0)->v) != 0) && ((((struct { u8 pad[0x25EB]; u8 v; } *)D_001A4BE0)->v) != 0) && (((((struct { u8 pad[0x43]; u8 v; } *)((((struct { u8 pad[0x25C0]; u8 * v; } *)D_001A4BE0)->v)))->v) == (((struct { u8 pad[0x2830]; s32 v; } *)D_001A4BE0)->v)) || ((((struct { u8 pad[0xE78]; s32 v; } *)D_001A4BE0)->v) != 0))) {
                keep = 1;
            }
            if (keep == 0) {
                (((struct { u8 pad[0x25E9]; s8 v; } *)D_001A4BE0)->v) = 0;
                if (func_L23_004BDA28(0) == 0x4A) {
                    func_L01_0050BB98(func_L23_004BDA28(0), 0, 18.0f);
                } else {
                    func_L01_0050BB98(func_L23_004BDA28(0), 0, -2.0f);
                }
            }
        }
        if ((((struct { u8 pad[0x1B8]; s32 v; } *)D_001A4BE0)->v) >= 11) {
            u8 *o2 = (((struct { u8 pad[0x12F4]; u8 * v; } *)D_001A4BE0)->v);
            if ((o2 != 0) && ((((struct { u8 pad[0x43]; u8 v; } *)o2)->v) == 1) && (func_00388398(D_001A4BE0 + 0x2870) != 0) && ((((struct { u8 pad[0x258]; f32 v; } *)D_L23_002F55C0)->v) < 0.55850536f) && ((((struct { u8 pad[0x254]; f32 v; } *)D_L23_002F55C0)->v) < 0.34906584f) && ((((struct { u8 pad[0x1314]; s32 v; } *)D_001A4BE0)->v) == 2)) {
                (((struct { u8 pad[0x2870]; s32 v; } *)D_001A4BE0)->v) = func_0037E208(0x6e, 0x10e);
                func_L01_0050B3C0();
            }
        }
        if (((((struct { u8 pad[0x25E9]; u8 v; } *)D_001A4BE0)->v) != 0) && ((((struct { u8 pad[0xC0C]; s32 v; } *)D_001A4BE0)->v) == 0) && ((((struct { u8 pad[0x25EB]; u8 v; } *)D_001A4BE0)->v) != 0) && ((((struct { u8 pad[0x2874]; s16 v; } *)D_001A4BE0)->v) == 0)
            && ((D_001439F4[0] != 1) || (fabs_asm((((struct { u8 pad[0x15A0]; f32 v; } *)D_001A4BE0)->v)) < 0.17453292f))) {
            s32 slot = func_L01_004E5470(0);
            if (slot != (((struct { u8 pad[0x2834]; s32 v; } *)D_001A4BE0)->v)) {
                func_L01_004E6CB0();
            } else {
                s32 want = (((struct { u8 pad[0x24]; s32 v; } *)(D_L23_002C6780 + D_001425C0[slot] * 0xF0))->v);
                if ((((struct { u8 pad[0x43]; u8 v; } *)((((struct { u8 pad[0x25C0]; u8 * v; } *)D_001A4BE0)->v)))->v) != want) {
                    if ((((struct { u8 pad[0xE78]; s32 v; } *)D_001A4BE0)->v) != 0) {
                        (((struct { u8 pad[0xE84]; s32 v; } *)D_001A4BE0)->v) = 1;
                    }
                    (((struct { u8 pad[0x2830]; s32 v; } *)D_001A4BE0)->v) = want;
                    func_L01_0050BB98(want, 0, -4.0f);
                }
            }
        }
        func_L01_004EAA78(0, 1.0f);
        if (((((struct { u8 pad[0x147C]; u8 v; } *)D_001A4BE0)->v) != 0) && ((((struct { u8 pad[0x36C]; s16 v; } *)D_001A4BE0)->v) == 0)) {
            func_L23_004DF5A8(0x7B, 1);
            break;
        }
        if (((((struct { u8 pad[0x36E]; s16 v; } *)D_001A4BE0)->v) >= 5) && ((((struct { u8 pad[0x33C]; f32 v; } *)D_001A4BE0)->v) > 0.4f)) {
            if (((((struct { u8 pad[0x25D0]; s32 v; } *)D_001A4BE0)->v) != 8) || ((((struct { u8 pad[0x1B8]; s32 v; } *)D_001A4BE0)->v) >= 0xf)) {
                func_L23_004DF5A8(6, 1);
            }
            break;
        }
        if ((((struct { u8 pad[0x1E0]; s16 v; } *)D_001A4BE0)->v) != 0) {
            break;
        }
        {
            s32 ok = 1;
            if (((((struct { u8 pad[0x25D0]; s32 v; } *)D_001A4BE0)->v) == 1) || ((((struct { u8 pad[0x25D0]; s32 v; } *)D_001A4BE0)->v) == 0x1D)) {
                if ((((struct { u8 pad[0x1B8]; s32 v; } *)D_001A4BE0)->v) <= 4) {
                    ok = 0;
                }
            }
            if (ok && ((((struct { u8 pad[0x368]; s16 v; } *)D_001A4BE0)->v) != 1)) {
                if (func_L01_00502368(((((struct { u8 pad[0x1EE]; s16 v; } *)D_001A4BE0)->v) != 0) ? 1 : 7, 0) != 0) {
                    break;
                }
            }
        }
        if (((((struct { u8 pad[0x368]; s16 v; } *)D_001A4BE0)->v) == 1) && (D_L23_001D6740_004E6F00 == 0) && (func_L01_0045D358(func_0039E928(0x40, 0), 7, 0, 0) != 0)) {
            func_L23_004DF5A8(0x73, 1);
            break;
        }
        if (((((struct { u8 pad[0x1A0]; s32 v; } *)D_001D52FC)->v) & func_0039E928(8, 0)) && ((((struct { u8 pad[0x360]; s32 v; } *)D_001A4BE0)->v) != 0)) {
            if (((((struct { u8 pad[0x43]; u8 v; } *)((((struct { u8 pad[0x25C0]; u8 * v; } *)D_001A4BE0)->v)))->v) != 0x1A) || !((((struct { u8 pad[0xC18]; f32 v; } *)D_001A4BE0)->v) < 108.0f)) {
                func_L23_004DF5A8(4, 1);
                break;
            }
        }
        if ((((struct { u8 pad[0x5DC]; s32 v; } *)D_001A4BE0)->v) != 0) {
            func_L23_004DF5A8(0x27, 1);
            break;
        }
        if (((((struct { u8 pad[0x1474]; u8 v; } *)D_001A4BE0)->v) != 0) && ((((struct { u8 pad[0x340]; f32 v; } *)D_001A4BE0)->v) > 0.08726646f)) {
            func_L23_004DF5A8(0x2E, 1);
            break;
        }
        {
            s32 go = 1;
            s32 turned;
            if ((((((struct { u8 pad[0x25D0]; s32 v; } *)D_001A4BE0)->v) == 1) || ((((struct { u8 pad[0x25D0]; s32 v; } *)D_001A4BE0)->v) == 0x1D)) && ((((struct { u8 pad[0x1B8]; s32 v; } *)D_001A4BE0)->v) < 0x18) && ((((struct { u8 pad[0x368]; s16 v; } *)D_001A4BE0)->v) != 1)) {
                func_L01_004EAA78(0, 1.0f);
                if ((func_00389468((((struct { u8 pad[0x1A0]; f32 v; } *)D_001A4BE0)->v), (((struct { u8 pad[0x18]; f32 v; } *)D_L23_001E1AC0)->v)) > 1.2217305f) && (func_003887C8(D_001A4BE0 + 0x80, D_L23_001E1AC0) < 2.5f)) {
                    go = 0;
                }
            }
            turned = func_L01_004EA1F8(0.17453292f);
            if (go == 0) {
                break;
            }
            if ((turned != 0) || ((((struct { u8 pad[0x2838]; f32 v; } *)D_001A4BE0)->v) > 0.22f)) {
                s32 side = (((struct { u8 pad[0x147F]; u8 v; } *)D_001A4BE0)->v);
                func_L01_004DD4B0(side, 0, 0, 0x1E);
                func_L01_004DD4B0(side, 1, 0, 0x1E);
                func_L23_004DF5A8(2, 1);
            }
        }
        break;
    }
    case 0x3C:
        if (((((struct { u8 pad[0x1A0]; s32 v; } *)D_001D52FC)->v) & func_L01_0050EE20(func_0039E928(4, 0)))
            && (((((struct { u8 pad[0x25E4]; u8 v; } *)D_001A4BE0)->v) != 0) || (D_001439F4[0] != 2) || ((((struct { u8 pad[0x1228]; s32 v; } *)D_001A4BE0)->v) == 0x6F))
            && (func_L01_003E9428(0) == 0)) {
            func_L23_004DF5A8(1, 1);
            break;
        }
        if (((((struct { u8 pad[0x36E]; s16 v; } *)D_001A4BE0)->v) != 0) || ((((struct { u8 pad[0x1A0]; s32 v; } *)D_001D52FC)->v) & func_0039E928(0x40, 0)) || ((((struct { u8 pad[0x1A0]; s32 v; } *)D_001D52FC)->v) & func_0039E928(8, 0))) {
            func_L23_004DF5A8(0x3D, 1);
            break;
        }
        func_L01_004EADD0();
        if ((((struct { u8 pad[0x1B0]; f32 v; } *)D_001A4BE0)->v) > 0.0f) {
            func_L23_004DF5A8(0x3D, 1);
            break;
        }
        if ((((struct { u8 pad[0xC08]; s32 v; } *)D_001A4BE0)->v) & 2) {
            func_L01_005028C8();
            func_L23_004DF5A8(0, 1);
        }
        break;
    case 0x3D:
        if ((((struct { u8 pad[0x1B8]; s32 v; } *)D_001A4BE0)->v) < 9) {
            break;
        }
        func_L01_005028C8();
        if ((((struct { u8 pad[0x36E]; s16 v; } *)D_001A4BE0)->v) != 0) {
            func_L23_004DF5A8(6, 1);
            break;
        }
        if (func_L01_00502368(7, 0) != 0) {
            break;
        }
        if ((((struct { u8 pad[0x1A0]; s32 v; } *)D_001D52FC)->v) & func_0039E928(8, 0)) {
            func_L23_004DF5A8(4, 1);
            break;
        }
        func_L01_004EADD0();
        if ((((struct { u8 pad[0x1B0]; f32 v; } *)D_001A4BE0)->v) > 0.0f) {
            func_L23_004DF5A8(2, 1);
            break;
        }
        func_L23_004DF5A8(0, 1);
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
        if (((((struct { u8 pad[0xC08]; s32 v; } *)D_001A4BE0)->v) & 2) || ((((struct { u8 pad[0x25F1]; u8 v; } *)D_001A4BE0)->v) != 0)) {
            if ((((struct { u8 pad[0x21E]; s16 v; } *)D_001A4BE0)->v) != 0) {
                (((struct { u8 pad[0x25F1]; u8 v; } *)D_001A4BE0)->v) = 1;
                (((struct { u8 pad[0xC00]; s32 v; } *)D_001A4BE0)->v) = 0;
                func_003883C8(D_001A4BE0 + 0x21E);
                return;
            }
            if (((((struct { u8 pad[0x25C4]; u32 v; } *)D_001A4BE0)->v) == 0xA0) && ((((struct { u8 pad[0x1B8]; s32 v; } *)D_001A4BE0)->v) < 0x51)) {
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
        if ((((struct { u8 pad[0x1B8]; s32 v; } *)D_001A4BE0)->v) < 0xdd) {
            break;
        }
        func_L01_004EA040();
        return;
    case 0x50:
        if ((((struct { u8 pad[0x1B8]; s32 v; } *)D_001A4BE0)->v) < 0xdd) {
            break;
        }
        func_L01_004EA040();
        return;
    case 0x32:
    case 0x34:
    {
        u32 st = (((struct { u8 pad[0x25C4]; u32 v; } *)D_001A4BE0)->v);
        if (st == 0x32) {
            f32 h;
            (((struct { u8 pad[0xC00]; f32 v; } *)D_001A4BE0)->v) = (((struct { u8 pad[0x1B4]; f32 v; } *)D_001A4BE0)->v) * 15.0f;
            if ((((struct { u8 pad[0xC00]; f32 v; } *)D_001A4BE0)->v) < 0.25f) {
                (((struct { u8 pad[0xC00]; f32 v; } *)D_001A4BE0)->v) = 0.25f;
            }
            if ((((struct { u8 pad[0xC00]; f32 v; } *)D_001A4BE0)->v) > 0.75f) {
                (((struct { u8 pad[0xC00]; f32 v; } *)D_001A4BE0)->v) = 0.75f;
            }
            if (((((struct { u8 pad[0x25C4]; u32 v; } *)D_001A4BE0)->v) == st) && !((((struct { u8 pad[0x1A0]; s32 v; } *)D_001D52FC)->v) & 0xC0) && ((h = (((struct { u8 pad[0xC18]; f32 v; } *)D_001A4BE0)->v)) > 9.0f) && (h < 19.0f) && ((((struct { u8 pad[0x25C8]; s32 v; } *)D_001A4BE0)->v) != 1) && ((((struct { u8 pad[0x2838]; f32 v; } *)D_001A4BE0)->v) < 0.1f) && ((((struct { u8 pad[0x1B4]; f32 v; } *)D_001A4BE0)->v) < 0.033333335f)) {
                func_L23_004DF5A8(0x33, 1);
                break;
            }
        }
        if (((((struct { u8 pad[0x2884]; s16 v; } *)D_001A4BE0)->v) == 0) && ((((struct { u8 pad[0x1A0]; s32 v; } *)D_001D52FC)->v) & 0xA)) {
            if (((((struct { u8 pad[0x25C4]; u32 v; } *)D_001A4BE0)->v) == 0x32) && ((((struct { u8 pad[0x1B8]; s32 v; } *)D_001A4BE0)->v) >= 0x15)) {
                func_L23_004DF5A8(0x34, 1);
                break;
            }
        } else if ((((struct { u8 pad[0x25C4]; u32 v; } *)D_001A4BE0)->v) == 0x34) {
            if ((((struct { u8 pad[0x2838]; f32 v; } *)D_001A4BE0)->v) > 0.5f) {
                func_L23_004DF5A8(0x32, 1);
                break;
            }
        }
        if ((((struct { u8 pad[0x25C4]; u32 v; } *)D_001A4BE0)->v) == 0x34) {
            s32 pad = (((struct { u8 pad[0x1A0]; s32 v; } *)D_001D52FC)->v);
            if (!(pad & 0xC0) && ((((struct { u8 pad[0x25C8]; s32 v; } *)D_001A4BE0)->v) != 1) && ((((struct { u8 pad[0x2838]; f32 v; } *)D_001A4BE0)->v) < 0.7f) && !(pad & 0xA)) {
                func_L23_004DF5A8(0x33, 1);
            }
        }
        break;
    }
    case 0x33:
    {
        s32 pad;
        if (((((struct { u8 pad[0xC08]; s32 v; } *)D_001A4BE0)->v) & 2) && ((((struct { u8 pad[0x43]; u8 v; } *)((((struct { u8 pad[0x25C0]; u8 * v; } *)D_001A4BE0)->v)))->v) != 0x37)) {
            func_L01_0050BB98(0x37, 0, 11.0f);
        }
        if (((((struct { u8 pad[0x2838]; f32 v; } *)D_001A4BE0)->v) > 0.2f) || ((pad = (((struct { u8 pad[0x1A0]; s32 v; } *)D_001D52FC)->v)) & 0xC0) || (((((struct { u8 pad[0x2884]; s16 v; } *)D_001A4BE0)->v) == 0) && (pad & 0xA))) {
            if ((((struct { u8 pad[0x2884]; s16 v; } *)D_001A4BE0)->v) != 0) {
                func_L23_004DF5A8(0x32, 1);
            } else if ((((struct { u8 pad[0x1A0]; s32 v; } *)D_001D52FC)->v) & 0xA) {
                func_L23_004DF5A8(0x34, 1);
            } else {
                func_L23_004DF5A8(0x32, 1);
            }
        }
        break;
    }
    case 0x36:
        if (((((struct { u8 pad[0x1F8]; s16 v; } *)D_001A4BE0)->v) == 0) && (func_L01_0045D358(func_0039E928(0x40, 0), 8, 0, 0) != 0) && ((((struct { u8 pad[0x1B8]; s32 v; } *)D_001A4BE0)->v) >= 11)) {
            func_L23_004DF5A8(0x12, 1);
            break;
        }
        (((struct { u8 pad[0x25E8]; u8 v; } *)D_001A4BE0)->v) = 1;
        if (((((struct { u8 pad[0x1FE]; s16 v; } *)D_001A4BE0)->v) == 0) && ((((struct { u8 pad[0x120]; s32 v; } *)((((struct { u8 pad[0x24]; u8 * v; } *)((((struct { u8 pad[0x25C0]; u8 * v; } *)D_001A4BE0)->v)))->v)))->v) != 0)) {
            if ((func_L01_0045D358(0x80, 7, 0, 0) != 0) || (((((struct { u8 pad[0x2884]; s16 v; } *)D_001A4BE0)->v) == 0) && (func_L01_0045D358(0xA, 7, 0, 0) != 0))) {
                if ((((struct { u8 pad[0x2884]; s16 v; } *)D_001A4BE0)->v) != 0) {
                    func_L23_004DF5A8(0x32, 1);
                } else if ((((struct { u8 pad[0x1A0]; s32 v; } *)D_001D52FC)->v) & 0xA) {
                    func_L23_004DF5A8(0x34, 1);
                } else {
                    func_L23_004DF5A8(0x32, 1);
                }
                break;
            }
        }
        if (((((struct { u8 pad[0x25EA]; u8 v; } *)D_001A4BE0)->v) != 0) && ((((struct { u8 pad[0x2848]; f32 v; } *)D_001A4BE0)->v) < 0.4f) && (func_L23_004DF5A8(0, 0) != 0)) {
            func_L01_0050BB98(func_L23_004BDA28(0), 0, 18.0f);
        }
        if (((((struct { u8 pad[0x2838]; f32 v; } *)D_001A4BE0)->v) > 0.2f) && ((((struct { u8 pad[0x1B8]; s32 v; } *)D_001A4BE0)->v) >= 11)) {
            func_L23_004DF5A8(0x35, 1);
        }
        break;
    case 0x35:
        if (((((struct { u8 pad[0x1F8]; s16 v; } *)D_001A4BE0)->v) == 0) && (func_L01_0045D358(func_0039E928(0x40, 0), 8, 0, 0) != 0)) {
            func_L23_004DF5A8(0x12, 1);
            break;
        }
        if (((((struct { u8 pad[0x1FE]; s16 v; } *)D_001A4BE0)->v) == 0) && ((((struct { u8 pad[0x120]; s32 v; } *)((((struct { u8 pad[0x24]; u8 * v; } *)((((struct { u8 pad[0x25C0]; u8 * v; } *)D_001A4BE0)->v)))->v)))->v) != 0) && (func_L01_0045D358(0x80, 7, 0, 0) != 0)) {
            if ((((struct { u8 pad[0x2884]; s16 v; } *)D_001A4BE0)->v) != 0) {
                func_L23_004DF5A8(0x32, 1);
            } else if ((((struct { u8 pad[0x1A0]; s32 v; } *)D_001D52FC)->v) & 0xA) {
                func_L23_004DF5A8(0x34, 1);
            } else {
                func_L23_004DF5A8(0x32, 1);
            }
            break;
        }
        if (((((struct { u8 pad[0x25EA]; u8 v; } *)D_001A4BE0)->v) != 0) && ((((struct { u8 pad[0x2848]; f32 v; } *)D_001A4BE0)->v) < 0.7f)) {
            func_L23_004DF5A8(0x75, 0);
            func_L01_0050BB98(((((struct { u8 pad[0x188]; s32 v; } *)((((struct { u8 pad[0x24]; u8 * v; } *)((((struct { u8 pad[0x25C0]; u8 * v; } *)D_001A4BE0)->v)))->v)))->v) == 0) ? 3 : 0x50, 0, 17.0f);
            (((struct { u8 pad[0xF8]; s32 v; } *)D_001A4BE0)->v) = 0;
            (((struct { u8 pad[0x118]; s32 v; } *)D_001A4BE0)->v) = 0;
        }
        if (((((struct { u8 pad[0x2838]; f32 v; } *)D_001A4BE0)->v) < 0.1f) && ((((struct { u8 pad[0x1B4]; f32 v; } *)D_001A4BE0)->v) == 0.0f) && ((((struct { u8 pad[0x728]; s32 v; } *)D_001A4BE0)->v) == 0)) {
            func_L23_004DF5A8(0x36, 1);
        }
        break;
    case 0x78:
        if ((((struct { u8 pad[0x2850]; s32 v; } *)D_001A4BE0)->v) <= 0) {
            func_L23_004DF5A8(0x6C, 1);
            func_L01_0050BB98(0x4F, 0x28, 18.0f);
        } else if ((((struct { u8 pad[0xC08]; s32 v; } *)D_001A4BE0)->v) & 2) {
            func_L23_004DF5A8(0x33, 1);
        } else if ((((struct { u8 pad[0x1B8]; s32 v; } *)D_001A4BE0)->v) >= 0x33) {
            func_L23_004DF5A8(0x33, 0);
        }
        break;
    case 0x77:
        if ((((struct { u8 pad[0x2850]; s32 v; } *)D_001A4BE0)->v) <= 0) {
            func_L23_004DF5A8(0x6C, 1);
            func_L01_0050BB98(0x4F, 0x25, 18.0f);
        } else if ((((struct { u8 pad[0x1B8]; s32 v; } *)D_001A4BE0)->v) >= 0x33) {
            func_L23_004DF5A8(0x36, 0);
        }
        break;
    case 0x1:
    {
        u8 *p;
        s32 ok;
        s32 late;
        s32 anim;
        if (((((struct { u8 pad[0x25E4]; u8 v; } *)D_001A4BE0)->v) == 0) && (((((struct { u8 pad[0x25EB]; u8 v; } *)D_001A4BE0)->v) == 0) || ((((struct { u8 pad[0x25E5]; u8 v; } *)D_001A4BE0)->v) != 0))) {
            if ((((struct { u8 pad[0x1A0]; s32 v; } *)D_001D52FC)->v) & func_0039E928(8, 0)) {
                func_L01_0050BB98(0xD, 0, 8.0f);
            } else {
                s32 a = func_L23_004BDA28(1);
                if ((((struct { u8 pad[0x43]; u8 v; } *)((((struct { u8 pad[0x25C0]; u8 * v; } *)D_001A4BE0)->v)))->v) != a) {
                    func_L01_0050BB98(a, 0, 8.0f);
                }
            }
        }
        p = (((struct { u8 pad[0x1200]; u8 * v; } *)D_001A4BE0)->v);
        ok = 1;
        if ((p != 0) && (func_L01_004EA1D8(p) != 0)) {
            if ((((struct { u8 pad[0x20]; u8 v; } *)p)->v) != 0) {
                if (func_L01_0050FF18() == 0) {
                    ok = 0;
                }
            }
        }
        late = 0;
        if ((((struct { u8 pad[0x25E5]; u8 v; } *)D_001A4BE0)->v) == 0) {
            late = (((struct { u8 pad[0x1B8]; s32 v; } *)D_001A4BE0)->v) >= 0x1f;
        }
        if ((!((((struct { u8 pad[0x1A0]; s32 v; } *)D_001D52FC)->v) & func_0039E928(4, 0)) && ok) || late) {
            if ((((struct { u8 pad[0x25E4]; u8 v; } *)D_001A4BE0)->v) != 0) {
                func_L23_004E4290(0);
            } else if ((((struct { u8 pad[0x1A0]; s32 v; } *)D_001D52FC)->v) & func_0039E928(8, 0)) {
                func_L23_004DF5A8(4, 1);
            } else {
                func_L23_004DF5A8(0, 0);
                anim = func_L23_004BDA28(1);
                if ((((struct { u8 pad[0x43]; u8 v; } *)((((struct { u8 pad[0x25C0]; u8 * v; } *)D_001A4BE0)->v)))->v) != anim) {
                    func_L01_0050BB98(anim, 0, 8.0f);
                }
            }
        }
        break;
    }
    case 0x2F:
        if (!((((struct { u8 pad[0x1A0]; s32 v; } *)D_001D52FC)->v) & (((struct { u8 pad[0x1210]; s32 v; } *)D_001A4BE0)->v)) && ((((struct { u8 pad[0x1EC]; s16 v; } *)D_001A4BE0)->v) == 0)) {
            if ((((struct { u8 pad[0x43]; u8 v; } *)((((struct { u8 pad[0x25C0]; u8 * v; } *)D_001A4BE0)->v)))->v) == 0x31) {
                func_L23_004DF5A8(0, 0);
            } else {
                func_L23_004DF5A8(0, 1);
            }
        }
        break;
    case 0x14:
    {
        u8 *rec;
        s32 frames;
        if ((((struct { u8 pad[0x25C4]; u32 v; } *)D_001A4BE0)->v) == 0x14) {
            s32 n = func_L01_0050C4A0(60.0f, 0.036111113f, -1.0f);
            f32 c00 = (((struct { u8 pad[0xBE0]; f32 v; } *)D_001A4BE0)->v);
            s32 top = 0x1A;
            if (c00 == 0.0f) {
                (((struct { u8 pad[0xC00]; f32 v; } *)D_001A4BE0)->v) = 0.33f;
            } else if ((c00 != 0.0f) && ((((struct { u8 pad[0x36E]; s16 v; } *)D_001A4BE0)->v) != 0) && (n != 0) && (((f32)top - (((struct { u8 pad[0xC18]; f32 v; } *)D_001A4BE0)->v)) > 1.0f)) {
                func_L01_004E1268((f32)top, (f32)n, 0.5f, -1.0f);
                if (((((struct { u8 pad[0x33C]; f32 v; } *)D_001A4BE0)->v) < 0.7f) && ((((struct { u8 pad[0xC00]; f32 v; } *)D_001A4BE0)->v) < 0.75f)) {
                    (((struct { u8 pad[0xC00]; f32 v; } *)D_001A4BE0)->v) = 0.75f;
                }
            } else if (((((struct { u8 pad[0x36E]; s16 v; } *)D_001A4BE0)->v) == 0) && ((((struct { u8 pad[0xC18]; f32 v; } *)D_001A4BE0)->v) < (f32)top)) {
                (((struct { u8 pad[0xC00]; f32 v; } *)D_001A4BE0)->v) = 2.0f;
            } else {
                (((struct { u8 pad[0xC00]; f32 v; } *)D_001A4BE0)->v) = 1.0f;
            }
        }
        rec = (u8 *)&D_L23_002F7350[(((struct { u8 pad[0xBDC]; s16 v; } *)D_001A4BE0)->v)];
        frames = ((s32)(((struct { u8 pad[0xC18]; f32 v; } *)D_001A4BE0)->v) - (((struct { u8 pad[0xC]; s32 v; } *)rec)->v)) * 2;
        if ((f32)(((struct { u8 pad[0x14]; s32 v; } *)rec)->v) < (((struct { u8 pad[0xC18]; f32 v; } *)D_001A4BE0)->v)) {
            if ((((struct { u8 pad[0xC0C]; s32 v; } *)D_001A4BE0)->v) != 0) {
                break;
            }
            if (func_L01_0045D358(func_0039E928(0x40, 0), frames, 0, 0) != 0) {
                if (!((((struct { u8 pad[0x1A0]; s32 v; } *)D_001D52FC)->v) & func_0039E928(8, 0))) {
                    func_L23_004DF5A8(7, 1);
                    break;
                }
                if (func_L01_00502ED8() != 0) {
                    break;
                }
            }
        }
        if (((((struct { u8 pad[0xC0C]; s32 v; } *)D_001A4BE0)->v) == 0) && ((f32)(((struct { u8 pad[0x18]; s32 v; } *)rec)->v) < (((struct { u8 pad[0xC18]; f32 v; } *)D_001A4BE0)->v))) {
            func_L23_004DF5A8(0, 0);
        }
        break;
    }
    case 0x13:
    case 0x15:
    {
        u8 *rec = (u8 *)&D_L23_002F7350[(((struct { u8 pad[0xBDC]; s16 v; } *)D_001A4BE0)->v)];
        s32 frames = ((s32)(((struct { u8 pad[0xC18]; f32 v; } *)D_001A4BE0)->v) - (((struct { u8 pad[0xC]; s32 v; } *)rec)->v)) * 2;
        u32 st = (((struct { u8 pad[0x25C4]; u32 v; } *)D_001A4BE0)->v);
        s32 lim;
        f32 h;
        if (st == 0x15) {
            frames = 8;
        }
        if ((f32)(((struct { u8 pad[0x14]; s32 v; } *)rec)->v) < (((struct { u8 pad[0xC18]; f32 v; } *)D_001A4BE0)->v)) {
            if ((((struct { u8 pad[0xC0C]; s32 v; } *)D_001A4BE0)->v) != 0) {
                goto tail13;
            }
            if ((st != 0x15) || ((((struct { u8 pad[0x368]; s16 v; } *)D_001A4BE0)->v) != 1)) {
                if (func_L01_0045D358(func_0039E928(0x40, 0), frames, 0, 0) != 0) {
                    if (!((((struct { u8 pad[0x1A0]; s32 v; } *)D_001D52FC)->v) & func_0039E928(8, 0))) {
                        func_L23_004DF5A8(7, 1);
                        break;
                    }
                    if (func_L01_00502ED8() != 0) {
                        break;
                    }
                }
            }
        }
        if ((((struct { u8 pad[0xC0C]; s32 v; } *)D_001A4BE0)->v) != 0) {
            goto tail13;
        }
        if (((((struct { u8 pad[0xC18]; f32 v; } *)D_001A4BE0)->v) > 34.0f) && ((((struct { u8 pad[0x2838]; f32 v; } *)D_001A4BE0)->v) > 0.9f)) {
            func_L23_004DF5A8(2, 0);
            if ((((struct { u8 pad[0x25C4]; u32 v; } *)D_001A4BE0)->v) == 2) {
                func_L01_0050BB98(3, D_L23_001DBE30[(((struct { u8 pad[0x25C8]; s32 v; } *)D_001A4BE0)->v)], 13.0f);
            }
            break;
        }
        if ((((struct { u8 pad[0xC0C]; s32 v; } *)D_001A4BE0)->v) != 0) {
            goto tail13;
        }
        lim = (((struct { u8 pad[0x18]; s32 v; } *)rec)->v);
        h = (((struct { u8 pad[0xC18]; f32 v; } *)D_001A4BE0)->v);
        if ((f32)lim < h) {
            if ((((struct { u8 pad[0x2838]; f32 v; } *)D_001A4BE0)->v) > 0.8f) {
                func_L23_004DF5A8(2, 1);
                break;
            }
            if ((f32)(lim + 5) < h) {
                func_L23_004DF5A8(0, 0);
                break;
            }
            if ((((struct { u8 pad[0xC08]; s32 v; } *)D_001A4BE0)->v) & 2) {
                func_L23_004DF5A8(0, 0);
            }
            break;
        }
    tail13:
        if (((((struct { u8 pad[0x25C4]; u32 v; } *)D_001A4BE0)->v) == 0x15) && ((((struct { u8 pad[0x1228]; s32 v; } *)D_001A4BE0)->v) != 9) && ((((struct { u8 pad[0x1228]; s32 v; } *)D_001A4BE0)->v) != 0x7F)) {
            func_L23_004DF5A8(0, 1);
            break;
        }
        if (((((struct { u8 pad[0x25C4]; u32 v; } *)D_001A4BE0)->v) == 0x15) && ((((struct { u8 pad[0x1B8]; s32 v; } *)D_001A4BE0)->v) >= 0x65) && ((((struct { u8 pad[0xC24]; s32 v; } *)D_001A4BE0)->v) < 0x1A)) {
            func_L01_0050BF40(2);
            (((struct { u8 pad[0xC24]; s32 v; } *)D_001A4BE0)->v) = 0x1A;
        }
        break;
    }
    case 0x88:
        if ((((struct { u8 pad[0xC18]; f32 v; } *)D_001A4BE0)->v) > 37.0f) {
            if ((((struct { u8 pad[0xC0C]; s32 v; } *)D_001A4BE0)->v) != 0) {
                goto tail88;
            }
            if (func_L01_0045D358(func_0039E928(0x40, 0), 7, 0, 0) != 0) {
                if (!((((struct { u8 pad[0x1A0]; s32 v; } *)D_001D52FC)->v) & func_0039E928(8, 0))) {
                    func_L23_004DF5A8(7, 1);
                    break;
                }
                if (func_L01_00502ED8() != 0) {
                    break;
                }
            }
        }
        if (((((struct { u8 pad[0xC0C]; s32 v; } *)D_001A4BE0)->v) == 0) && ((((struct { u8 pad[0xC18]; f32 v; } *)D_001A4BE0)->v) > 37.0f)) {
            func_L23_004DF5A8(0, 0);
            func_L01_0050BB98(func_L23_004BDA28(0), 0, 15.0f);
            break;
        }
    tail88:
        if (((((struct { u8 pad[0x25C4]; u32 v; } *)D_001A4BE0)->v) == 0x15) && ((((struct { u8 pad[0x1B8]; s32 v; } *)D_001A4BE0)->v) >= 0x65) && ((((struct { u8 pad[0xC24]; s32 v; } *)D_001A4BE0)->v) < 0x1A)) {
            func_L01_0050BF40(2);
            (((struct { u8 pad[0xC24]; s32 v; } *)D_001A4BE0)->v) = 0x1A;
        }
        break;
    case 0x7C:
        if ((((struct { u8 pad[0xC08]; s32 v; } *)D_001A4BE0)->v) & 2) {
            func_L23_004DF5A8(0, 1);
        }
        break;
    case 0x2:
    case 0x2E:
    case 0x75:
    {
        s32 n;
        s32 turned;
        u32 st;
        if (((((struct { u8 pad[0x3EE]; u8 v; } *)D_001A4BE0)->v) != 0) && (((((struct { u8 pad[0x44]; f32 v; } *)cur)->v) > 0.9f) || ((((struct { u8 pad[0x42]; u8 v; } *)cur)->v) != 0xFF))) {
            (((struct { u8 pad[0x3EE]; u8 v; } *)D_001A4BE0)->v) = 0;
        }
        if (((((struct { u8 pad[0x147C]; u8 v; } *)D_001A4BE0)->v) != 0) && ((((struct { u8 pad[0x36C]; s16 v; } *)D_001A4BE0)->v) == 0)) {
            func_L23_004DF5A8(0x7B, 1);
            break;
        }
        if (((((struct { u8 pad[0x36E]; s16 v; } *)D_001A4BE0)->v) >= 7) && (((((struct { u8 pad[0x25D4]; s32 v; } *)D_001A4BE0)->v) != 0x12) || ((((struct { u8 pad[0x25EA]; u8 v; } *)D_001A4BE0)->v) == 0)) && ((((struct { u8 pad[0x33C]; f32 v; } *)D_001A4BE0)->v) > 1.35f) && (func_L01_00503188() == 0)) {
            func_L23_004DF5A8(6, 1);
            break;
        }
        n = 9;
        if ((((struct { u8 pad[0x1EE]; s16 v; } *)D_001A4BE0)->v) != 0) {
            n = 1;
        }
        if ((func_L01_0045D358(func_0039E928(0x40, 0), n, 0, 0) != 0) && (((((struct { u8 pad[0x36E]; s16 v; } *)D_001A4BE0)->v) < 8) || ((((struct { u8 pad[0x33C]; f32 v; } *)D_001A4BE0)->v) < 0.5f) || ((((struct { u8 pad[0x202]; s16 v; } *)D_001A4BE0)->v) != 0))) {
            func_L01_004EAA78(0, 1.0f);
            if (func_L01_00502368(n, 1) != 0) {
                break;
            }
            if ((((struct { u8 pad[0x2838]; f32 v; } *)D_001A4BE0)->v) > 0.85f) {
                if (((((struct { u8 pad[0x1434]; s16 v; } *)D_001A4BE0)->v) == 0) && (((((struct { u8 pad[0x16B0]; s32 v; } *)D_001A4BE0)->v) != 1) || (func_L01_0045D358(0x28, 2, 0, 0) == 0))) {
                    func_L23_004DF5A8(9, 1);
                } else {
                    func_L23_004DF5A8(7, 1);
                }
            } else {
                func_L23_004DF5A8(7, 1);
            }
            break;
        }
        if ((((struct { u8 pad[0x36E]; s16 v; } *)D_001A4BE0)->v) != 0) {
            break;
        }
        if ((((((struct { u8 pad[0x1474]; u8 v; } *)D_001A4BE0)->v) == 0) || (((((struct { u8 pad[0x174]; f32 v; } *)D_001A4BE0)->v) < 0.033333335f) && ((((struct { u8 pad[0x340]; f32 v; } *)D_001A4BE0)->v) < 0.08726646f)))
            && ((((struct { u8 pad[0x1A0]; s32 v; } *)D_001D52FC)->v) & func_L01_0050EE20(func_0039E928(4, 0)))
            && (((((struct { u8 pad[0x25E4]; u8 v; } *)D_001A4BE0)->v) != 0) || (D_001439F4[0] != 2) || ((((struct { u8 pad[0x1228]; s32 v; } *)D_001A4BE0)->v) == 0x6F))
            && (func_L01_003E9428(0) == 0)) {
            func_L23_004DF5A8(1, 1);
            break;
        }
        if ((((struct { u8 pad[0x1A0]; s32 v; } *)D_001D52FC)->v) & func_0039E928(8, 0)) {
            func_L23_004DF5A8(4, 1);
            break;
        }
        if (((((struct { u8 pad[0x1474]; u8 v; } *)D_001A4BE0)->v) != 0) && ((((struct { u8 pad[0x25C4]; u32 v; } *)D_001A4BE0)->v) == 0x2E)) {
            f32 speed = func_003887A0(D_001A4BE0 + 0x110);
            s32 anim;
            if (((((struct { u8 pad[0x2838]; f32 v; } *)D_001A4BE0)->v) < 0.17f) && (((((struct { u8 pad[0x43]; u8 v; } *)((((struct { u8 pad[0x25C0]; u8 * v; } *)D_001A4BE0)->v)))->v) == 0x32) || ((((struct { u8 pad[0x43]; u8 v; } *)((((struct { u8 pad[0x25C0]; u8 * v; } *)D_001A4BE0)->v)))->v) == 0x7B) || (((anim = (((struct { u8 pad[0x43]; u8 v; } *)((((struct { u8 pad[0x25C0]; u8 * v; } *)D_001A4BE0)->v)))->v)) == func_L23_004BDA28(0)) && ((((struct { u8 pad[0x340]; f32 v; } *)D_001A4BE0)->v) > 0.08726646f))) && ((((struct { u8 pad[0x1CC]; s32 v; } *)D_001A4BE0)->v) >= 9) && ((((struct { u8 pad[0xC0C]; s32 v; } *)D_001A4BE0)->v) == 0)) {
                func_L01_0050BB98(0x54, 0, 14.0f);
            } else if (((((struct { u8 pad[0x2838]; f32 v; } *)D_001A4BE0)->v) > 0.3f) && ((((struct { u8 pad[0x43]; u8 v; } *)((((struct { u8 pad[0x25C0]; u8 * v; } *)D_001A4BE0)->v)))->v) != 0x32) && ((((struct { u8 pad[0x43]; u8 v; } *)((((struct { u8 pad[0x25C0]; u8 * v; } *)D_001A4BE0)->v)))->v) != 0x7B) && ((((struct { u8 pad[0xC0C]; s32 v; } *)D_001A4BE0)->v) == 0)) {
                if ((((((struct { u8 pad[0x1434]; s16 v; } *)D_001A4BE0)->v) != 0) || (((((struct { u8 pad[0x16B0]; s32 v; } *)D_001A4BE0)->v) == 1) && (func_L01_0045D358(0x28, 2, 0, 0) != 0))) && ((((struct { u8 pad[0x1436]; u8 v; } *)D_001A4BE0)->v) != 0)) {
                    func_L01_0050BB98(0x7B, 0, 14.0f);
                } else {
                    func_L01_0050BB98(0x32, 0, 14.0f);
                }
            } else if (((((struct { u8 pad[0x43]; u8 v; } *)((((struct { u8 pad[0x25C0]; u8 * v; } *)D_001A4BE0)->v)))->v) == 0x54) && ((((struct { u8 pad[0xC0C]; s32 v; } *)D_001A4BE0)->v) == 0) && ((((struct { u8 pad[0x2838]; f32 v; } *)D_001A4BE0)->v) < 0.17f) && ((((struct { u8 pad[0x340]; f32 v; } *)D_001A4BE0)->v) < 0.08726646f) && (speed < 0.028333336f)) {
                func_L01_0050BB98(func_L23_004BDA28(0), 0, 20.0f);
            }
        }
        st = (((struct { u8 pad[0x25C4]; u32 v; } *)D_001A4BE0)->v);
        if ((st == 2) || (st == 0x80)) {
            if ((((struct { u8 pad[0x1474]; u8 v; } *)D_001A4BE0)->v) != 0) {
                func_L23_004DF5A8(0x2E, 1);
            }
        } else if (st == 0x2E) {
            if ((((struct { u8 pad[0x1474]; u8 v; } *)D_001A4BE0)->v) == 0) {
                func_L23_004DF5A8(2, 1);
            }
        }
        if ((((struct { u8 pad[0x1474]; u8 v; } *)D_001A4BE0)->v) != 0) {
            if ((((((struct { u8 pad[0x1434]; s16 v; } *)D_001A4BE0)->v) != 0) || (((((struct { u8 pad[0x16B0]; s32 v; } *)D_001A4BE0)->v) == 1) && (func_L01_0045D358(0x28, 2, 0, 0) != 0))) && ((((struct { u8 pad[0x1436]; u8 v; } *)D_001A4BE0)->v) != 0)) {
                if ((((struct { u8 pad[0x43]; u8 v; } *)((((struct { u8 pad[0x25C0]; u8 * v; } *)D_001A4BE0)->v)))->v) == 0x32) {
                    func_L01_0050BB98(0x7B, 0, 9.0f);
                }
            } else {
                if ((((struct { u8 pad[0x43]; u8 v; } *)((((struct { u8 pad[0x25C0]; u8 * v; } *)D_001A4BE0)->v)))->v) == 0x7B) {
                    func_L01_0050BB98(0x32, 0, 7.0f);
                }
            }
        }
        st = (((struct { u8 pad[0x25C4]; u32 v; } *)D_001A4BE0)->v);
        if (st == 2) {
            if ((((struct { u8 pad[0x25EA]; u8 v; } *)D_001A4BE0)->v) != 0) {
                func_L23_004DF5A8(0x75, 1);
            }
        } else if (st == 0x75) {
            if ((((struct { u8 pad[0x25EA]; u8 v; } *)D_001A4BE0)->v) == 0) {
                func_L23_004DF5A8(2, 1);
            }
        }
        if ((((struct { u8 pad[0x5DC]; s32 v; } *)D_001A4BE0)->v) != 0) {
            func_L23_004DF5A8(0x27, 1);
            break;
        }
        turned = func_L01_004EA1F8(0.034906585f);
        st = (((struct { u8 pad[0x25C4]; u32 v; } *)D_001A4BE0)->v);
        if (st == 2) {
            if ((((((struct { u8 pad[0x2838]; f32 v; } *)D_001A4BE0)->v) < 0.17f) || ((((struct { u8 pad[0x1E0]; s16 v; } *)D_001A4BE0)->v) != 0)) && (turned == 0) && (((((struct { u8 pad[0x3F0]; s32 v; } *)D_001A4BE0)->v) == 0) || (fabs_asm((((struct { u8 pad[0x1A8]; f32 v; } *)D_001A4BE0)->v)) < 0.017453292f))) {
                s32 anim;
                if (func_L01_00503310() != 0) {
                    break;
                }
                if (func_L23_004DF5A8(0, 0) != 0) {
                    func_003BF640((f32 *)(D_001A4BE0 + 0x160), 0.025000002f);
                    if ((((struct { u8 pad[0x1B4]; f32 v; } *)D_001A4BE0)->v) > 0.025000002f) {
                        (((struct { u8 pad[0x1B4]; f32 v; } *)D_001A4BE0)->v) = 0.025000002f;
                    }
                    anim = func_L23_004BDA28(1);
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
            if (((((struct { u8 pad[0x1D4]; s32 v; } *)D_001D52FC)->v) != 0) && (func_003887A0(D_001A4BE0 + 0xF0) < 0.0008333334f) && ((((struct { u8 pad[0x340]; f32 v; } *)D_001A4BE0)->v) < 0.08726646f) && (func_L23_004DF5A8(0, 0) != 0)) {
                func_L01_0050BB98(func_L23_004BDA28(0), 0, 17.0f);
            }
            if (((((struct { u8 pad[0x43]; u8 v; } *)cur)->v) == 0x32) || ((((struct { u8 pad[0x43]; u8 v; } *)cur)->v) == 0x7B)) {
                (((struct { u8 pad[0xC00]; f32 v; } *)D_001A4BE0)->v) = (1.0f - (((struct { u8 pad[0x3E0]; f32 v; } *)D_001A4BE0)->v)) * 2.0f;
                if ((((struct { u8 pad[0xC00]; f32 v; } *)D_001A4BE0)->v) > 1.7f) {
                    (((struct { u8 pad[0xC00]; f32 v; } *)D_001A4BE0)->v) = 1.7f;
                }
                if ((((struct { u8 pad[0xC00]; f32 v; } *)D_001A4BE0)->v) < 0.75f) {
                    (((struct { u8 pad[0xC00]; f32 v; } *)D_001A4BE0)->v) = 0.75f;
                }
            } else if ((((struct { u8 pad[0x43]; u8 v; } *)cur)->v) == 0x54) {
                (((struct { u8 pad[0xC00]; f32 v; } *)D_001A4BE0)->v) = (((struct { u8 pad[0x170]; f32 v; } *)D_001A4BE0)->v) * 10.0f;
                if ((((struct { u8 pad[0xC00]; f32 v; } *)D_001A4BE0)->v) > 1.1f) {
                    (((struct { u8 pad[0xC00]; f32 v; } *)D_001A4BE0)->v) = 1.1f;
                }
                if ((((struct { u8 pad[0xC00]; f32 v; } *)D_001A4BE0)->v) < 0.3f) {
                    (((struct { u8 pad[0xC00]; f32 v; } *)D_001A4BE0)->v) = 0.3f;
                }
            }
        } else if (st == 0x75) {
            if (((((struct { u8 pad[0x1D4]; s32 v; } *)D_001D52FC)->v) != 0) && (func_003887A0(D_001A4BE0 + 0xF0) < 0.05333334f) && (func_L23_004DF5A8(0, 0) != 0)) {
                func_L01_0050BB98(func_L23_004BDA28(0), 0, 17.0f);
            }
            (((struct { u8 pad[0xC00]; f32 v; } *)D_001A4BE0)->v) = (((struct { u8 pad[0x170]; f32 v; } *)D_001A4BE0)->v) * 35.0f;
            if ((((struct { u8 pad[0xC00]; f32 v; } *)D_001A4BE0)->v) < 0.6f) {
                (((struct { u8 pad[0xC00]; f32 v; } *)D_001A4BE0)->v) = 0.6f;
            }
            if ((((struct { u8 pad[0xC00]; f32 v; } *)D_001A4BE0)->v) > 1.05f) {
                (((struct { u8 pad[0xC00]; f32 v; } *)D_001A4BE0)->v) = 1.05f;
            }
        }
        if (((((struct { u8 pad[0x368]; s16 v; } *)D_001A4BE0)->v) == 0) && ((((struct { u8 pad[0x1278]; s32 v; } *)D_001A4BE0)->v) == 0xD) && ((((struct { u8 pad[0x2634]; s32 v; } *)D_001A4BE0)->v) != 0)) {
            (((struct { u8 pad[0x2650]; s32 v; } *)D_001A4BE0)->v) = 1;
        }
        break;
    }
    case 0x80:
    {
        s32 one = 1;
        s32 flag = 0;
        if ((((struct { u8 pad[0x368]; s16 v; } *)D_001A4BE0)->v) != 0) {
            flag = 1;
        }
        if (!((((struct { u8 pad[0x1A0]; s32 v; } *)D_001D52FC)->v) & func_0039E928(8, 0))) {
            if ((((struct { u8 pad[0x1B8]; s32 v; } *)D_001A4BE0)->v) >= 0x3d) {
                flag = one;
            }
        }
        if ((((struct { u8 pad[0x25E9]; u8 v; } *)D_001A4BE0)->v) != 0) {
            flag = one;
        }
        if (flag != 0) {
            if ((((struct { u8 pad[0x2634]; s32 v; } *)D_001A4BE0)->v) != 0) {
                (((struct { u8 pad[0x2650]; s32 v; } *)D_001A4BE0)->v) = one;
            }
            func_L01_004F1068(9, 0);
            (((struct { u8 pad[0x1E0]; s16 v; } *)D_001A4BE0)->v) = 0x1e;
            func_L23_004DF5A8(3, 0);
            func_L01_0050BB98(6, 4, 11.0f);
        } else if ((((struct { u8 pad[0x984]; s32 v; } *)D_001A4BE0)->v) != 0) {
            func_L23_004DF5A8(0, 0);
            func_L01_0050BB98(func_L23_004BDA28(0), 0, -2.0f);
        } else {
            if ((((struct { u8 pad[0x2A7]; u8 v; } *)D_001A4BE0)->v) != 0) {
                f32 a = func_00388770(D_001A4BE0 + 0x110);
                if (a < func_00388770(D_001A4BE0 + 0xF0) * 0.75f) {
                    func_L23_004DF5A8(0x7C, 1);
                    break;
                }
                if (func_L01_004E2628(0, 1.0f, 1.25f) != 0) {
                    func_L23_004DF5A8(0x7C, 1);
                    break;
                }
            }
            *(vu0_q *)v30 = 0;
            v30[0] = -0.083333336f;
            func_003BDA38((((struct { u8 pad[0x25C0]; s8 * v; } *)D_001A4BE0)->v), 0x16, (s8 *)v10);
            func_003BDA38((((struct { u8 pad[0x25C0]; s8 * v; } *)D_001A4BE0)->v), 0x17, (s8 *)v20);
            func_L01_0046A9C8((((struct { u8 pad[0x25C0]; s8 * v; } *)D_001A4BE0)->v), v10, v30, (s32 *)D_L23_001DBCD0, 1);
            func_L01_0046A9C8((((struct { u8 pad[0x25C0]; s8 * v; } *)D_001A4BE0)->v), v10, v30, (s32 *)D_L23_001DBCE0, 1);
            func_L01_0046A9C8((((struct { u8 pad[0x25C0]; s8 * v; } *)D_001A4BE0)->v), v20, v30, (s32 *)D_L23_001DBCD0, 1);
            func_L01_0046A9C8((((struct { u8 pad[0x25C0]; s8 * v; } *)D_001A4BE0)->v), v20, v30, (s32 *)D_L23_001DBCE0, 1);
        }
        break;
    }
    case 0x66:
        if (D_L23_001D673C_004E6F00 != 0) {
            if (func_003887C8(D_001A4BE0 + 0x80, D_001A4BE0 + 0x1B40) < 0.4f) {
                if ((((struct { u8 pad[0x170]; f32 v; } *)D_001A4BE0)->v) < 0.045f) {
                    func_L23_004DF5A8(0x68, 1);
                    break;
                }
                if (((((struct { u8 pad[0x25E4]; u8 v; } *)D_001A4BE0)->v) != 0) && ((((struct { u8 pad[0x170]; f32 v; } *)D_001A4BE0)->v) >= 0.045f)) {
                    func_L23_004DF5A8(0x67, 1);
                }
                break;
            }
        } else {
            if (func_00388800(D_001A4BE0 + 0x80, D_001A4BE0 + 0x1B40) < 0.3f) {
                if (((((struct { u8 pad[0x170]; f32 v; } *)D_001A4BE0)->v) < 0.045f) && (func_00389468((((struct { u8 pad[0x98]; f32 v; } *)D_001A4BE0)->v), (((struct { u8 pad[0x1B4C]; f32 v; } *)D_001A4BE0)->v)) < 0.034906585f)) {
                    func_L23_004DF5A8(0x68, 1);
                    break;
                }
                if (((((struct { u8 pad[0x25E4]; u8 v; } *)D_001A4BE0)->v) != 0) && ((((struct { u8 pad[0x170]; f32 v; } *)D_001A4BE0)->v) >= 0.045f)) {
                    func_L23_004DF5A8(0x67, 1);
                }
                break;
            }
        }
        func_L01_005024B8();
        break;
    case 0x67:
        if ((((struct { u8 pad[0xC08]; s32 v; } *)D_001A4BE0)->v) & 2) {
            func_L23_004DF5A8(0x66, 1);
        }
        break;
    case 0x68:
        if (((((struct { u8 pad[0xC08]; s32 v; } *)D_001A4BE0)->v) & 2) || ((((struct { u8 pad[0x1B50]; s32 v; } *)D_001A4BE0)->v) != 0)) {
            func_L23_004DF5A8(0, 1);
        }
        if (D_L23_001D673C_004E6F00 != 0) {
            if (func_003887C8(D_001A4BE0 + 0x80, D_001A4BE0 + 0x1B40) > 0.4f) {
                func_L23_004DF5A8(0x66, 1);
            }
        } else {
            if (func_00388800(D_001A4BE0 + 0x80, D_001A4BE0 + 0x1B40) > 0.3f) {
                func_L23_004DF5A8(0x66, 1);
            }
        }
        break;
    case 0x6A:
    {
        s32 t = (((struct { u8 pad[0x1B70]; s32 v; } *)D_001A4BE0)->v);
        if ((t < 3) && (((t * 7) + 10) < (((struct { u8 pad[0x1B8]; s32 v; } *)D_001A4BE0)->v)) && (func_L01_0045D358(func_0039E928(0x40, 0), 7, &frames6A, 0) != 0)) {
            func_L23_004DF5A8(0x6B, 1);
        }
        if ((((struct { u8 pad[0x88]; f32 v; } *)D_001A4BE0)->v) < ((((struct { u8 pad[0x354]; f32 v; } *)D_001A4BE0)->v) - 1.2f)) {
            func_L01_004EA040();
            return;
        }
        if ((((struct { u8 pad[0x1B8]; s32 v; } *)D_001A4BE0)->v) < 0xab) {
            break;
        }
        func_L01_004EA040();
        return;
    }
    case 0x7D:
        if ((((struct { u8 pad[0x88]; f32 v; } *)D_001A4BE0)->v) < ((((struct { u8 pad[0x354]; f32 v; } *)D_001A4BE0)->v) - 1.2f)) {
            func_L01_004EA040();
            return;
        }
        if ((((struct { u8 pad[0x1B8]; s32 v; } *)D_001A4BE0)->v) < 0x97) {
            break;
        }
        func_L01_004EA040();
        return;
    case 0x7E:
        if ((((struct { u8 pad[0x88]; f32 v; } *)D_001A4BE0)->v) < ((((struct { u8 pad[0x354]; f32 v; } *)D_001A4BE0)->v) - 1.2f)) {
            func_L01_004EA040();
            return;
        }
        if ((((struct { u8 pad[0x1B8]; s32 v; } *)D_001A4BE0)->v) < 0x65) {
            break;
        }
        func_L01_004EA040();
        return;
    case 0x7F:
        if ((((struct { u8 pad[0x88]; f32 v; } *)D_001A4BE0)->v) < ((((struct { u8 pad[0x354]; f32 v; } *)D_001A4BE0)->v) - 0.8f)) {
            func_L01_004EA040();
            return;
        }
        if ((((struct { u8 pad[0x1B8]; s32 v; } *)D_001A4BE0)->v) < 0x97) {
            break;
        }
        func_L01_004EA040();
        return;
    case 0x72:
        if ((f32)D_L23_002F7350[(((struct { u8 pad[0xBDC]; s16 v; } *)D_001A4BE0)->v)].w[6] < (((struct { u8 pad[0xC18]; f32 v; } *)D_001A4BE0)->v)) {
            func_L23_004DF5A8(0, 1);
        }
        break;
    case 0x30:
        if ((((((struct { u8 pad[0x1475]; u8 v; } *)D_001A4BE0)->v) == 0) && ((((struct { u8 pad[0x200]; s16 v; } *)D_001A4BE0)->v) == 0)) || ((((struct { u8 pad[0x33C]; f32 v; } *)D_001A4BE0)->v) > 1.0f)) {
            s32 slot = (((struct { u8 pad[0x2794]; s32 v; } *)D_001A4BE0)->v);
            if (slot != -1) {
                u8 *ent = D_001A30B0 + slot * 0x80;
                if (((((struct { u8 pad[0xDC]; s32 v; } *)ent)->v) == (((struct { u8 pad[0x25C0]; s32 v; } *)D_001A4BE0)->v)) && ((((struct { u8 pad[0xD0]; u8 v; } *)ent)->v) != 0)) {
                    func_0039FB08(slot);
                }
            }
            (((struct { u8 pad[0x2794]; s32 v; } *)D_001A4BE0)->v) = -1;
            if (func_L23_004DF5A8(0, 0) != 0) {
                func_L01_0050BB98(func_L23_004BDA28(0), 0, 17.0f);
                (((struct { u8 pad[0x160]; vu0_q v; } *)D_001A4BE0)->v) = (((struct { u8 pad[0x150]; vu0_q v; } *)D_001A4BE0)->v);
            }
        }
        break;
    case 0x3:
        if (((((struct { u8 pad[0x1A0]; s32 v; } *)D_001D52FC)->v) & func_L01_0050EE20(func_0039E928(4, 0)))
            && (((((struct { u8 pad[0x25E4]; u8 v; } *)D_001A4BE0)->v) != 0) || (D_001439F4[0] != 2) || ((((struct { u8 pad[0x1228]; s32 v; } *)D_001A4BE0)->v) == 0x6F))
            && (func_L01_003E9428(0) == 0)) {
            func_L23_004DF5A8(1, 1);
            break;
        }
        if (((((struct { u8 pad[0x1E0]; s16 v; } *)D_001A4BE0)->v) == 0) && ((((struct { u8 pad[0x1A4]; s32 v; } *)D_001D52FC)->v) & func_0039E928(0x40, 0))) {
            func_L23_004DF5A8(7, 1);
            break;
        }
        if (((((struct { u8 pad[0x1E0]; s16 v; } *)D_001A4BE0)->v) == 0) && ((((struct { u8 pad[0x1A0]; s32 v; } *)D_001D52FC)->v) & func_0039E928(8, 0))) {
            func_L23_004DF5A8(4, 1);
            break;
        }
        if (((((struct { u8 pad[0x36E]; s16 v; } *)D_001A4BE0)->v) >= 9) && ((((struct { u8 pad[0x33C]; f32 v; } *)D_001A4BE0)->v) > 0.3f)) {
            func_L23_004DF5A8(6, 1);
            break;
        }
        if ((((struct { u8 pad[0xC08]; s32 v; } *)D_001A4BE0)->v) & 2) {
            func_L23_004DF5A8(0, 1);
            break;
        }
        if ((((struct { u8 pad[0x5DC]; s32 v; } *)D_001A4BE0)->v) != 0) {
            func_L23_004DF5A8(0x27, 1);
            break;
        }
        if (!((((struct { u8 pad[0x2838]; f32 v; } *)D_001A4BE0)->v) > 0.2f) || ((((struct { u8 pad[0x1E0]; s16 v; } *)D_001A4BE0)->v) != 0)) {
            break;
        }
        if (func_L23_004BDA28(0) != 0x4A) {
            if ((((struct { u8 pad[0x1B4]; f32 v; } *)D_001A4BE0)->v) == 0.0f) {
                func_L23_004DF5A8(0, 0);
                break;
            }
        } else if (((((struct { u8 pad[0xC18]; f32 v; } *)D_001A4BE0)->v) > 10.0f) && (func_L23_004DF5A8(0, 0) != 0)) {
            func_L01_0050BB98(func_L23_004BDA28(0), 0, 17.0f);
        }
        if ((((struct { u8 pad[0x2838]; f32 v; } *)D_001A4BE0)->v) > 0.5f) {
            func_L23_004DF5A8(2, 1);
        }
        break;
    case 0x4:
        if (((((struct { u8 pad[0x1A0]; s32 v; } *)D_001D52FC)->v) & func_L01_0050EE20(func_0039E928(4, 0)))
            && (((((struct { u8 pad[0x25E4]; u8 v; } *)D_001A4BE0)->v) != 0) || (D_001439F4[0] != 2) || ((((struct { u8 pad[0x1228]; s32 v; } *)D_001A4BE0)->v) == 0x6F))
            && (func_L01_003E9428(0) == 0)) {
            func_L23_004DF5A8(1, 1);
            break;
        }
        if (((((struct { u8 pad[0x1B8]; s32 v; } *)D_001A4BE0)->v) >= 0xc) && !((((struct { u8 pad[0x1A0]; s32 v; } *)D_001D52FC)->v) & func_0039E928(8, 0))) {
            func_L23_004DF5A8(0, 0);
            func_L01_0050BB98(func_L23_004BDA28(0), 0, -2.0f);
            break;
        }
        if ((((struct { u8 pad[0x147C]; u8 v; } *)D_001A4BE0)->v) != 0) {
            if ((((struct { u8 pad[0x36C]; s16 v; } *)D_001A4BE0)->v) == 0) {
                func_L23_004DF5A8(0x7B, 1);
                break;
            }
        } else if (func_L01_00502ED8() != 0) {
            break;
        }
        if ((func_L01_0045D358(0x80, 0xf, 0, 0) != 0) && ((((struct { u8 pad[0x121A]; u8 v; } *)D_001A4BE0)->v) == 0) && ((((struct { u8 pad[0x1228]; s32 v; } *)D_001A4BE0)->v) == 9)) {
            func_L23_004DF5A8(0x15, 1);
        }
        if ((((struct { u8 pad[0x36E]; s16 v; } *)D_001A4BE0)->v) >= 9) {
            if (((((struct { u8 pad[0x25D0]; s32 v; } *)D_001A4BE0)->v) != 8) || ((((struct { u8 pad[0x1B8]; s32 v; } *)D_001A4BE0)->v) >= 0xf)) {
                func_L23_004DF5A8(6, 1);
            }
        }
        break;
    case 0x8F:
        if ((((struct { u8 pad[0x1228]; s32 v; } *)D_001A4BE0)->v) != 0xB) {
            func_L23_004DF5A8(0, 1);
            break;
        }
        if ((((struct { u8 pad[0xA9C]; s32 v; } *)D_001A4BE0)->v) != 0) {
            u8 *obj = (((struct { u8 pad[0xA90]; u8 * v; } *)D_001A4BE0)->v);
            if (obj != 0) {
                func_L01_00452F40(obj, 1);
            }
            func_L23_004DF5A8(0x90, 1);
        }
        break;
    case 0x90:
        if ((((struct { u8 pad[0x1B8]; s32 v; } *)D_001A4BE0)->v) >= 0x5b) {
            func_L23_004DF5A8(0, 1);
        }
        break;
    case 0x23:
        if ((((struct { u8 pad[0x1228]; s32 v; } *)D_001A4BE0)->v) != 0xB) {
            func_L23_004DF5A8(0, 1);
        }
        break;
    case 0x24:
    {
        s32 go;
        func_L01_004E1268(10.0f, (((struct { u8 pad[0xA2C]; f32 v; } *)D_001A4BE0)->v), 0.5f, -1.0f);
        if (((((struct { u8 pad[0xA2C]; f32 v; } *)D_001A4BE0)->v) < 22.0f) && ((((struct { u8 pad[0xA2C]; f32 v; } *)D_001A4BE0)->v) < 30.0f)) {
            func_L01_0050BB98(0xA, 0, 16.0f);
        }
        go = 0;
        if (!((((struct { u8 pad[0x1A0]; s32 v; } *)D_001D52FC)->v) & (((struct { u8 pad[0x1210]; s32 v; } *)D_001A4BE0)->v))) {
            if ((((struct { u8 pad[0xA2C]; f32 v; } *)D_001A4BE0)->v) > 25.0f) {
                (((struct { u8 pad[0xA48]; s32 v; } *)D_001A4BE0)->v) = 1;
            }
            go = 1;
        }
        if (((((struct { u8 pad[0x25C8]; s32 v; } *)D_001A4BE0)->v) == 1) && ((((struct { u8 pad[0xA20]; f32 v; } *)D_001A4BE0)->v) < 0.06666667f)) {
            go = 1;
        }
        if (go != 0) {
            (((struct { u8 pad[0x1B4]; f32 v; } *)D_001A4BE0)->v) = (((struct { u8 pad[0xA20]; f32 v; } *)D_001A4BE0)->v);
            if ((((struct { u8 pad[0x1B4]; f32 v; } *)D_001A4BE0)->v) > 0.116666675f) {
                (((struct { u8 pad[0x1B4]; f32 v; } *)D_001A4BE0)->v) = 0.116666675f;
            }
            if ((((struct { u8 pad[0x33C]; f32 v; } *)D_001A4BE0)->v) < 0.3f) {
                func_L23_004DF5A8(0, 0);
                func_L01_0050BB98(func_L23_004BDA28(0), 0, 30.0f);
                break;
            }
            if ((((struct { u8 pad[0x43]; u8 v; } *)((((struct { u8 pad[0x25C0]; u8 * v; } *)D_001A4BE0)->v)))->v) == 0xA) {
                func_L23_004DF5A8(6, 0);
            } else {
                func_L23_004DF5A8(6, 0);
                func_L01_0050BB98(0xA, 0, 17.0f);
            }
            (((struct { u8 pad[0xA04]; f32 v; } *)D_001A4BE0)->v) = 0.011666667f;
            (((struct { u8 pad[0xA00]; f32 v; } *)D_001A4BE0)->v) = 0.008055556f;
            (((struct { u8 pad[0x280C]; s32 v; } *)D_001A4BE0)->v) = 0;
        }
        break;
    }
    case 0x25:
        if (!((((struct { u8 pad[0x1A0]; s32 v; } *)D_001D52FC)->v) & (((struct { u8 pad[0x1210]; s32 v; } *)D_001A4BE0)->v))) {
            (((struct { u8 pad[0x1B4]; f32 v; } *)D_001A4BE0)->v) = (((struct { u8 pad[0xA20]; f32 v; } *)D_001A4BE0)->v);
            if ((((struct { u8 pad[0x1B4]; f32 v; } *)D_001A4BE0)->v) > 0.116666675f) {
                (((struct { u8 pad[0x1B4]; f32 v; } *)D_001A4BE0)->v) = 0.116666675f;
            }
            if ((((struct { u8 pad[0x33C]; f32 v; } *)D_001A4BE0)->v) < 0.4f) {
                func_L23_004DF5A8(0, 1);
            } else {
                func_L23_004DF5A8(6, 1);
                (((struct { u8 pad[0x280C]; s32 v; } *)D_001A4BE0)->v) = 0;
            }
        }
        break;
    case 0x2B:
        if (!((((struct { u8 pad[0x1A0]; s32 v; } *)D_001D52FC)->v) & (((struct { u8 pad[0x1210]; s32 v; } *)D_001A4BE0)->v))) {
            s32 t = (((struct { u8 pad[0x1B8]; s32 v; } *)D_001A4BE0)->v);
            if (t >= 11) {
                if (t < 0x28) {
                    (((struct { u8 pad[0xA48]; s32 v; } *)D_001A4BE0)->v) = 1;
                }
                func_L23_004DF5A8(0x2C, 1);
                (((struct { u8 pad[0xA04]; f32 v; } *)D_001A4BE0)->v) = 0.0019444445f;
                (((struct { u8 pad[0xA00]; f32 v; } *)D_001A4BE0)->v) = 0.0075000003f;
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
        if ((((struct { u8 pad[0x25C4]; u32 v; } *)D_001A4BE0)->v) == 0x3E) {
            (((struct { u8 pad[0x62E]; s16 v; } *)D_001A4BE0)->v) = 0;
        }
        if ((((struct { u8 pad[0x25C4]; u32 v; } *)D_001A4BE0)->v) == 0x2A) {
            (((struct { u8 pad[0x1219]; s8 v; } *)D_001A4BE0)->v) = 2;
        }
        if ((((struct { u8 pad[0x25C4]; u32 v; } *)D_001A4BE0)->v) != 0x3E) {
            s32 hit = 0;
            if ((((struct { u8 pad[0x2A7]; u8 v; } *)D_001A4BE0)->v) != 0) {
                f32 half = 0.5f;
                f32 up = 0.02f;
                if ((u32)((((struct { u8 pad[0x25C4]; u32 v; } *)D_001A4BE0)->v) - 0x28) < 2) {
                    up = 0.45f;
                }
                qzero(v10);
                v10[1] = -(((struct { u8 pad[0x5F0]; f32 v; } *)D_001A4BE0)->v);
                v10[2] = (((struct { u8 pad[0x5EC]; f32 v; } *)D_001A4BE0)->v);
                func_00388BD0(v40, v10);
                *(vu0_q *)v20 = 0;
                v20[0] = 0.25f;
                v20[2] = up + half;
                func_003888C8(v20, v20, v40);
                vec_add_ba(v20, v20, D_001A4BE0 + 0x80);
                hit = func_L01_003F9498(v20, 2, 0, half) != 0;
            }
            if ((hit != 0) || ((((struct { u8 pad[0x62E]; s16 v; } *)D_001A4BE0)->v) != 0)) {
                s32 clear = 1;
                if ((((struct { u8 pad[0x2A7]; u8 v; } *)D_001A4BE0)->v) != 0) {
                    qcopy_4EAE60(v10, D_001A4BE0 + 0x570);
                    v10[2] += 1.5f;
                    v20[0] = func_00388960((((struct { u8 pad[0x5EC]; f32 v; } *)D_001A4BE0)->v)) * 5.0f;
                    v20[1] = func_00388978((((struct { u8 pad[0x5EC]; f32 v; } *)D_001A4BE0)->v)) * 5.0f;
                    v20[2] = 0.0f;
                    vec_add_ab(v20, v20, v10);
                    if (func_003CE740(v10, v20, 2, 0, 0) != 0) {
                        clear = 0;
                    }
                }
                (((struct { u8 pad[0x62E]; s16 v; } *)D_001A4BE0)->v) = 0;
                if (clear == 0) {
                    func_00388830(D_001A4BE0 + 0x120, D_001A4BE0 + 0x10, 0.21666668f);
                    (((struct { u8 pad[0x128]; f32 v; } *)D_001A4BE0)->v) = 0.16666667f;
                    func_L23_004DF5A8(0x16, 1);
                    (((struct { u8 pad[0x1F4]; s16 v; } *)D_001A4BE0)->v) = 0x46;
                    (((struct { u8 pad[0x1D0]; s16 v; } *)D_001A4BE0)->v) = 0x46;
                } else {
                    func_L23_004DF5A8(0x3E, 1);
                }
                break;
            }
        }
        st = (((struct { u8 pad[0x25C4]; u32 v; } *)D_001A4BE0)->v);
        if (st == 0x27) {
            s32 a;
            s32 b;
            if (func_L01_0045D358(func_0039E928(0x40, 0), 7, 0, 0) != 0) {
                if ((((struct { u8 pad[0x628]; s32 v; } *)D_001A4BE0)->v) != 0) {
                    (((struct { u8 pad[0x630]; s32 v; } *)D_001A4BE0)->v) = 1;
                } else {
                    func_L23_004DF5A8(0x28, 1);
                }
                break;
            }
            a = (((struct { u8 pad[0x5E0]; s32 v; } *)D_001A4BE0)->v);
            if ((a >= 6) || ((b = (((struct { u8 pad[0x668]; s32 v; } *)D_001A4BE0)->v)) >= 6)) {
                if ((((struct { u8 pad[0x33C]; f32 v; } *)D_001A4BE0)->v) > 8.0f) {
                    (((struct { u8 pad[0x1E0]; s16 v; } *)D_001A4BE0)->v) = 0x46;
                }
                (((struct { u8 pad[0x1D0]; s16 v; } *)D_001A4BE0)->v) = 0x46;
                func_L23_004DF5A8(6, 1);
                (((struct { u8 pad[0x1F4]; s16 v; } *)D_001A4BE0)->v) = 8;
                (((struct { u8 pad[0x1D0]; s16 v; } *)D_001A4BE0)->v) = 0x46;
                break;
            }
            if ((a == 0) && (b == 0) && (func_L01_0045D358(0x80, 10, 0, 0) != 0)) {
                func_L23_004DF5A8(0x2A, 1);
                break;
            }
            if ((((struct { u8 pad[0x61C]; s32 v; } *)D_001A4BE0)->v) == -1) {
                s32 anim = (((struct { u8 pad[0x5FC]; s32 v; } *)D_001A4BE0)->v) + 0x2C;
                if ((((struct { u8 pad[0x43]; u8 v; } *)((((struct { u8 pad[0x25C0]; u8 * v; } *)D_001A4BE0)->v)))->v) != anim) {
                    func_L01_0050BB98(anim, 0, 12.0f);
                }
            } else {
                s32 anim = (((struct { u8 pad[0x61C]; s32 v; } *)D_001A4BE0)->v) + 0x42;
                if ((((struct { u8 pad[0x43]; u8 v; } *)((((struct { u8 pad[0x25C0]; u8 * v; } *)D_001A4BE0)->v)))->v) != anim) {
                    func_L01_0050BB98(anim, 0, 12.0f);
                }
            }
            if (((((struct { u8 pad[0x62C]; s16 v; } *)D_001A4BE0)->v) != 0) && ((((struct { u8 pad[0x630]; s32 v; } *)D_001A4BE0)->v) != 0)) {
                f32 h;
                f32 t;
                func_L23_004DF5A8(0x28, 1);
                (((struct { u8 pad[0x634]; s32 v; } *)D_001A4BE0)->v) = 1;
                h = func_L01_00444740((f32 *)(D_001A4BE0 + 0x80), (f32 *)(D_001A4BE0 + 0x5C0), 0, (((struct { u8 pad[0x174]; f32 v; } *)D_001A4BE0)->v), -(((struct { u8 pad[0x4F0]; f32 v; } *)D_001A4BE0)->v));
                *(vu0_q *)v20 = 0;
                v20[2] = h;
                *(vu0_q *)v10 = 0;
                t = func_L01_00442DA8(v10, v20, 0, (((struct { u8 pad[0x4F0]; f32 v; } *)D_001A4BE0)->v));
                (((struct { u8 pad[0x4D8]; f32 v; } *)D_001A4BE0)->v) = t;
                (((struct { u8 pad[0x4F0]; f32 v; } *)D_001A4BE0)->v) = (((struct { u8 pad[0x638]; f32 v; } *)D_001A4BE0)->v);
                (((struct { u8 pad[0x478]; f32 v; } *)D_001A4BE0)->v) = t;
                (((struct { u8 pad[0x4DC]; f32 v; } *)D_001A4BE0)->v) = t + 0.05f;
            }
            (((struct { u8 pad[0x628]; s32 v; } *)D_001A4BE0)->v) = 0;
            (((struct { u8 pad[0x62C]; s16 v; } *)D_001A4BE0)->v) = 0;
        } else if (st == 0x2A) {
            s32 top;
            if ((func_L01_0045D358(func_0039E928(0x40, 0), 5, 0, 0) != 0) && ((f32)D_L23_002F7350[(((struct { u8 pad[0xBDC]; s16 v; } *)D_001A4BE0)->v)].w[5] <= (((struct { u8 pad[0xC18]; f32 v; } *)D_001A4BE0)->v))) {
                func_L23_004DF5A8(0x28, 1);
                break;
            }
            top = 0xE;
            if ((((struct { u8 pad[0xBDC]; s16 v; } *)D_001A4BE0)->v) == 0) {
                top = 0x17;
            }
            if (((((struct { u8 pad[0x5E0]; s32 v; } *)D_001A4BE0)->v) == 0) && ((((struct { u8 pad[0x668]; s32 v; } *)D_001A4BE0)->v) == 0) && (func_L01_0045D358(0x80, 10, 0, 0) != 0)) {
                if ((f32)top < (((struct { u8 pad[0xC18]; f32 v; } *)D_001A4BE0)->v)) {
                    func_L23_004DF5A8(0x2A, 1);
                }
                break;
            }
            if ((f32)D_L23_002F7350[(((struct { u8 pad[0xBDC]; s16 v; } *)D_001A4BE0)->v)].w[6] < (((struct { u8 pad[0xC18]; f32 v; } *)D_001A4BE0)->v)) {
                func_L23_004DF5A8(0x27, 1);
                break;
            }
            if (((((struct { u8 pad[0x5E0]; s32 v; } *)D_001A4BE0)->v) >= 6) || ((((struct { u8 pad[0x668]; s32 v; } *)D_001A4BE0)->v) >= 6)) {
                func_L23_004DF5A8(6, 1);
                (((struct { u8 pad[0x1F4]; s16 v; } *)D_001A4BE0)->v) = 8;
                (((struct { u8 pad[0x1D0]; s16 v; } *)D_001A4BE0)->v) = 0x46;
            }
        } else if ((u32)(st - 0x28) < 2) {
            s32 lo;
            s32 now;
            if ((((((struct { u8 pad[0x5E0]; s32 v; } *)D_001A4BE0)->v) >= 6) || ((((struct { u8 pad[0x634]; s32 v; } *)D_001A4BE0)->v) != 0)) && ((((struct { u8 pad[0x5DC]; s32 v; } *)D_001A4BE0)->v) != 0) && (((((struct { u8 pad[0x88]; f32 v; } *)D_001A4BE0)->v) - (((struct { u8 pad[0x578]; f32 v; } *)D_001A4BE0)->v)) < 0.35f)) {
                func_L23_004DF5A8(0x27, 1);
                break;
            }
            if ((((struct { u8 pad[0x5E0]; s32 v; } *)D_001A4BE0)->v) >= 6) {
                func_L23_004DF5A8(6, 1);
                break;
            }
            if (((((struct { u8 pad[0x25C4]; u32 v; } *)D_001A4BE0)->v) == 0x28) && ((((struct { u8 pad[0x1B8]; s32 v; } *)D_001A4BE0)->v) < 10) && ((((struct { u8 pad[0x46E]; u8 v; } *)D_001A4BE0)->v) == 0) && ((((struct { u8 pad[0x2838]; f32 v; } *)D_001A4BE0)->v) > 0.5f) && ((((struct { u8 pad[0x600]; s32 v; } *)D_001A4BE0)->v) == 0)) {
                func_L01_004EAA78(0, 1.0f);
                if (func_00389468(func_00389468((((struct { u8 pad[0x1A0]; f32 v; } *)D_001A4BE0)->v), (((struct { u8 pad[0x5EC]; f32 v; } *)D_001A4BE0)->v)), 1.5707964f) < 1.2217305f) {
                    f32 ang;
                    f32 d;
                    f32 lim;
                    f32 *pw;
                    f32 *pv;
                    ang = func_00389380((((struct { u8 pad[0x5EC]; f32 v; } *)D_001A4BE0)->v), 1.5707964f);
                    if (func_00389468((((struct { u8 pad[0x1A0]; f32 v; } *)D_001A4BE0)->v), ang) > 1.5707964f) {
                        ang = func_00389380((((struct { u8 pad[0x5EC]; f32 v; } *)D_001A4BE0)->v), -1.5707964f);
                    }
                    lim = 4.5f;
                    pw = v20;
                    pv = v10;
                    for (d = 2.0f; d <= lim; d += 0.75f) {
                        *(vu0_q *)v10 = (((struct { u8 pad[0x80]; vu0_q v; } *)D_001A4BE0)->v);
                        sp74 = (((struct { u8 pad[0x5D4]; s32 v; } *)D_001A4BE0)->v);
                        sp78 = (((struct { u8 pad[0x5D8]; f32 v; } *)D_001A4BE0)->v);
                        if (func_L01_00472C40((((struct { u8 pad[0x5D0]; void * v; } *)D_001A4BE0)->v), pv, &sp74, &sp78, (((struct { u8 pad[0x5F4]; s32 v; } *)D_001A4BE0)->v), (((struct { u8 pad[0x170]; f32 v; } *)D_001A4BE0)->v) * 0.0f) != 0) {
                            func_003886E8(pw, D_001A4BE0 + 0x110, 48.0f);
                            vec_add_ba(v10, D_001A4BE0 + 0x80, v20);
                        }
                        v10[0] += func_00388960(ang) * d;
                        v10[1] += func_00388978(ang) * d;
                        if (func_L01_004E4E00((s8 *)pv, &sp7C, (vu0_q *)pw, &sp80, &sp84, &sp88, (((struct { u8 pad[0x5D0]; void * v; } *)D_001A4BE0)->v), 0, 1) != 0) {
                            (((struct { u8 pad[0x604]; void * v; } *)D_001A4BE0)->v) = (((struct { u8 pad[0x5D0]; void * v; } *)D_001A4BE0)->v);
                            (((struct { u8 pad[0x608]; s32 v; } *)D_001A4BE0)->v) = (((struct { u8 pad[0x5D4]; s32 v; } *)D_001A4BE0)->v);
                            (((struct { u8 pad[0x60C]; f32 v; } *)D_001A4BE0)->v) = (((struct { u8 pad[0x5D8]; f32 v; } *)D_001A4BE0)->v);
                            (((struct { u8 pad[0x610]; s32 v; } *)D_001A4BE0)->v) = (((struct { u8 pad[0x5F4]; s32 v; } *)D_001A4BE0)->v);
                            (((struct { u8 pad[0x5B0]; vu0_q v; } *)D_001A4BE0)->v) = (((struct { u8 pad[0x570]; vu0_q v; } *)D_001A4BE0)->v);
                            (((struct { u8 pad[0x5D0]; void * v; } *)D_001A4BE0)->v) = sp7C;
                            (((struct { u8 pad[0x5F4]; s32 v; } *)D_001A4BE0)->v) = sp88;
                            func_L01_00473340(sp7C, D_001A4C60, D_001A4BE0 + 0x570, (s32 *)(D_001A4BE0 + 0x5D4), (f32 *)(D_001A4BE0 + 0x5D8), sp88, 999.0f, 2.0f, 0.0f);
                            (((struct { u8 pad[0x600]; s32 v; } *)D_001A4BE0)->v) = 1;
                            (((struct { u8 pad[0x618]; s32 v; } *)D_001A4BE0)->v) = 0;
                            func_L23_004DF5A8(0x29, 1);
                            break;
                        }
                    }
                }
            }
            if (((((struct { u8 pad[0x47C]; s16 v; } *)D_001A4BE0)->v) < (((struct { u8 pad[0x1B8]; s32 v; } *)D_001A4BE0)->v)) && (func_L01_0050D4D8((s8 *)(D_001A4BE0 + 0xF0)) < 0.001f)) {
                (((struct { u8 pad[0x46E]; s8 v; } *)D_001A4BE0)->v) = 1;
            }
            lo = (((struct { u8 pad[0x47C]; s16 v; } *)D_001A4BE0)->v);
            now = (((struct { u8 pad[0x1B8]; s32 v; } *)D_001A4BE0)->v);
            if ((now >= lo + 1) && (now < lo + 9) && ((((struct { u8 pad[0x46E]; u8 v; } *)D_001A4BE0)->v) == 0) && ((((struct { u8 pad[0xC0C]; s32 v; } *)D_001A4BE0)->v) == 0)) {
                func_L01_0050D770((f32 *)(D_001A4BE0 + 0x80), (f32 *)(D_001A4BE0 + 0xF0), &sp8C, (((struct { u8 pad[0x4F0]; f32 v; } *)D_001A4BE0)->v));
                func_L01_004E1268((((struct { u8 pad[0x498]; f32 v; } *)D_001A4BE0)->v), (f32)sp8C, 0.5f, 0.25f);
                if ((((struct { u8 pad[0x600]; s32 v; } *)D_001A4BE0)->v) != 0) {
                    if ((((struct { u8 pad[0xC00]; f32 v; } *)D_001A4BE0)->v) > 2.0f) {
                        (((struct { u8 pad[0xC00]; f32 v; } *)D_001A4BE0)->v) = 2.0f;
                    }
                    if ((((struct { u8 pad[0xC00]; f32 v; } *)D_001A4BE0)->v) < 0.5f) {
                        (((struct { u8 pad[0xC00]; f32 v; } *)D_001A4BE0)->v) = 0.5f;
                    }
                }
            } else if (((((struct { u8 pad[0x46E]; u8 v; } *)D_001A4BE0)->v) != 0) && ((((struct { u8 pad[0x46C]; u8 v; } *)D_001A4BE0)->v) == 0)) {
                (((struct { u8 pad[0x47E]; s16 v; } *)D_001A4BE0)->v) = 0x1e;
                if ((((struct { u8 pad[0x5E0]; s32 v; } *)D_001A4BE0)->v) == 0) {
                    (((struct { u8 pad[0x47E]; s16 v; } *)D_001A4BE0)->v) = (s32)func_L01_0050C4A0(60.0f, (((struct { u8 pad[0x4F0]; f32 v; } *)D_001A4BE0)->v), (((struct { u8 pad[0x578]; f32 v; } *)D_001A4BE0)->v));
                }
                if ((((struct { u8 pad[0x47E]; s16 v; } *)D_001A4BE0)->v) != 0) {
                    func_L01_004E1268((((struct { u8 pad[0x49C]; f32 v; } *)D_001A4BE0)->v), (f32)(((struct { u8 pad[0x47E]; s16 v; } *)D_001A4BE0)->v), 0.5f, 0.25f);
                }
                if ((((struct { u8 pad[0x600]; s32 v; } *)D_001A4BE0)->v) != 0) {
                    if ((((struct { u8 pad[0xC00]; f32 v; } *)D_001A4BE0)->v) > 2.0f) {
                        (((struct { u8 pad[0xC00]; f32 v; } *)D_001A4BE0)->v) = 2.0f;
                    }
                    if ((((struct { u8 pad[0xC00]; f32 v; } *)D_001A4BE0)->v) < 0.5f) {
                        (((struct { u8 pad[0xC00]; f32 v; } *)D_001A4BE0)->v) = 0.5f;
                    }
                }
                if (((((struct { u8 pad[0x5E0]; s32 v; } *)D_001A4BE0)->v) == 0) && ((((struct { u8 pad[0x668]; s32 v; } *)D_001A4BE0)->v) == 0) && ((((struct { u8 pad[0x33C]; f32 v; } *)D_001A4BE0)->v) < 0.5f)) {
                    f32 y = (((struct { u8 pad[0x88]; f32 v; } *)D_001A4BE0)->v);
                    f32 floor = (((struct { u8 pad[0x578]; f32 v; } *)D_001A4BE0)->v);
                    if (y + (((struct { u8 pad[0xF8]; f32 v; } *)D_001A4BE0)->v) < floor) {
                        (((struct { u8 pad[0x46C]; u8 v; } *)D_001A4BE0)->v) = 1;
                        (((struct { u8 pad[0xF8]; f32 v; } *)D_001A4BE0)->v) = floor - y;
                        (((struct { u8 pad[0xC00]; f32 v; } *)D_001A4BE0)->v) = 1.0f;
                    }
                }
                if (((((struct { u8 pad[0x88]; f32 v; } *)D_001A4BE0)->v) - (((struct { u8 pad[0x578]; f32 v; } *)D_001A4BE0)->v)) < -2.5f) {
                    func_L23_004DF5A8(6, 1);
                    (((struct { u8 pad[0x1E0]; s16 v; } *)D_001A4BE0)->v) = 0x46;
                    (((struct { u8 pad[0x1F4]; s16 v; } *)D_001A4BE0)->v) = 8;
                    (((struct { u8 pad[0x1D0]; s16 v; } *)D_001A4BE0)->v) = 0x46;
                    break;
                }
            }
            if ((((struct { u8 pad[0x69C]; s32 v; } *)D_001A4BE0)->v) != 0) {
                func_L23_004DF5A8(0x76, 1);
                break;
            }
            if ((((struct { u8 pad[0x46C]; u8 v; } *)D_001A4BE0)->v) != 0) {
                if (++(((struct { u8 pad[0x46C]; u8 v; } *)D_001A4BE0)->v) >= 3) {
                    (((struct { u8 pad[0x25C4]; s32 v; } *)D_001A4BE0)->v) = 0x27;
                    func_L01_0050BB98((((struct { u8 pad[0x5FC]; s32 v; } *)D_001A4BE0)->v) + 0x2C, 0, 7.0f);
                    break;
                }
            }
            if (((((struct { u8 pad[0x5E0]; s32 v; } *)D_001A4BE0)->v) != 0) && ((((struct { u8 pad[0x36E]; s16 v; } *)D_001A4BE0)->v) == 0) && (func_L23_004DF5A8(0, 0) != 0)) {
                func_L01_0050BB98(0xC, 4, 6.0f);
            }
        } else if (st == 0x3E) {
            if ((((struct { u8 pad[0xF8]; f32 v; } *)D_001A4BE0)->v) > 0.0f) {
                func_L01_0050D770((f32 *)(D_001A4BE0 + 0x80), (f32 *)(D_001A4BE0 + 0xF0), &sp90, 0.006388889f);
                func_L01_004E1268(9.0f, (f32)sp90, 0.5f, -1.0f);
            }
            if (((((struct { u8 pad[0x5E0]; s32 v; } *)D_001A4BE0)->v) != 0) && ((((struct { u8 pad[0x360]; s32 v; } *)D_001A4BE0)->v) != 0)) {
                if (func_L23_004DF5A8(0, 0) != 0) {
                    func_L01_0050BB98(0xC, 4, 6.0f);
                }
                break;
            }
            if ((((struct { u8 pad[0xC08]; s32 v; } *)D_001A4BE0)->v) & 2) {
                func_L23_004DF5A8(0x27, 1);
                break;
            }
            if ((((struct { u8 pad[0x1B8]; s32 v; } *)D_001A4BE0)->v) < 11) {
                break;
            }
            if (((((struct { u8 pad[0xF8]; f32 v; } *)D_001A4BE0)->v) < 0.0f) && (fabs_asm((((struct { u8 pad[0x88]; f32 v; } *)D_001A4BE0)->v) - (((struct { u8 pad[0x578]; f32 v; } *)D_001A4BE0)->v)) < 0.3f)) {
                func_L23_004DF5A8(0x27, 1);
            }
        }
        break;
    }
    case 0x76:
        if ((((struct { u8 pad[0x43]; u8 v; } *)((((struct { u8 pad[0x25C0]; u8 * v; } *)D_001A4BE0)->v)))->v) == 0x5A) {
            if (func_L01_004EAA20(11.0f) != 0) {
                if (D_001D545C != 2) {
                    func_L01_004F1068(0xA, 0);
                } else {
                    func_L01_004F1068(0x16, 0);
                }
                func_L01_003378E0(D_001A4BE0 + 0x670, 4);
            }
            if ((((struct { u8 pad[0xC08]; s32 v; } *)D_001A4BE0)->v) & 2) {
                func_L01_0050BB98(0x53, 0, 30.0f);
            }
        }
        if ((((struct { u8 pad[0x6A0]; s32 v; } *)D_001A4BE0)->v) >= 6) {
            func_L23_004DF5A8(6, 1);
            (((struct { u8 pad[0x204]; s16 v; } *)D_001A4BE0)->v) = 0x1e;
        }
        break;
    case 0x17:
        if ((((struct { u8 pad[0xC18]; f32 v; } *)D_001A4BE0)->v) > 12.0f) {
            func_L23_004DF5A8(0x18, 0);
        }
        break;
    case 0x18:
        if (((((struct { u8 pad[0xC08]; s32 v; } *)D_001A4BE0)->v) & 2) && ((((struct { u8 pad[0x43]; u8 v; } *)((((struct { u8 pad[0x25C0]; u8 * v; } *)D_001A4BE0)->v)))->v) == 0x20)) {
            func_L01_0050BB98(0x21, 0, 5.0f);
        }
        func_L01_004EAA78(0, 1.0f);
        if (func_L01_004E4550((s8 *)(D_001A4BE0 + 0x80), (s8 *)(D_001A4BE0 + 0x90), 0) == 0) {
            func_L23_004DF5A8(6, 1);
            (((struct { u8 pad[0x1D0]; s16 v; } *)D_001A4BE0)->v) = 10;
            break;
        }
        if ((((((struct { u8 pad[0x2838]; f32 v; } *)D_001A4BE0)->v) > 0.5f) && (func_L01_0045D358(func_0039E928(0x40, 0), 9, 0, 0) != 0) && (func_00389468((((struct { u8 pad[0x1A0]; f32 v; } *)D_001A4BE0)->v), (((struct { u8 pad[0x98]; f32 v; } *)D_001A4BE0)->v)) > 2.3561945f)) || ((((struct { u8 pad[0x1A4]; s32 v; } *)D_001D52FC)->v) & func_0039E928(8, 0))) {
            func_L23_004DF5A8(6, 1);
            (((struct { u8 pad[0x25F0]; s8 v; } *)D_001A4BE0)->v) = 1;
            (((struct { u8 pad[0x1D0]; s16 v; } *)D_001A4BE0)->v) = 10;
            break;
        }
        if (func_L01_0045D358(func_0039E928(0x40, 0), 0x11, 0, 0) != 0) {
            func_L23_004DF5A8(0x1B, 1);
            break;
        }
        if ((((struct { u8 pad[0x2838]; f32 v; } *)D_001A4BE0)->v) > 0.5f) {
            if (func_00389468((((struct { u8 pad[0x1A0]; f32 v; } *)D_001A4BE0)->v), func_00389380((((struct { u8 pad[0x98]; f32 v; } *)D_001A4BE0)->v), 1.5707964f)) < 0.7853982f) {
                qcopy_4EAE60(v10, D_001A4BE0 + 0x80);
                v10[0] += func_00388960(func_00389380((((struct { u8 pad[0x98]; f32 v; } *)D_001A4BE0)->v), 1.5707964f)) * 0.3f;
                v10[1] += func_00388978(func_00389380((((struct { u8 pad[0x98]; f32 v; } *)D_001A4BE0)->v), 1.5707964f)) * 0.3f;
                if (func_L01_004E4550((s8 *)v10, (s8 *)(D_001A4BE0 + 0x90), 0) != 0) {
                    func_L23_004DF5A8(0x19, 1);
                }
                break;
            }
        }
        if ((((struct { u8 pad[0x2838]; f32 v; } *)D_001A4BE0)->v) > 0.5f) {
            if (func_00389468((((struct { u8 pad[0x1A0]; f32 v; } *)D_001A4BE0)->v), func_00389380((((struct { u8 pad[0x98]; f32 v; } *)D_001A4BE0)->v), -1.5707964f)) < 0.7853982f) {
                qcopy_4EAE60(v10, D_001A4BE0 + 0x80);
                v10[0] += func_00388960(func_00389380((((struct { u8 pad[0x98]; f32 v; } *)D_001A4BE0)->v), -1.5707964f)) * 0.3f;
                v10[1] += func_00388978(func_00389380((((struct { u8 pad[0x98]; f32 v; } *)D_001A4BE0)->v), -1.5707964f)) * 0.3f;
                if (func_L01_004E4550((s8 *)v10, (s8 *)(D_001A4BE0 + 0x90), 0) != 0) {
                    func_L23_004DF5A8(0x1A, 1);
                }
            }
        }
        break;
    case 0x19:
    case 0x1A:
    {
        f32 side;
        qcopy_4EAE60(v10, D_001A4BE0 + 0x80);
        side = 1.5707964f;
        if ((((struct { u8 pad[0x25C4]; u32 v; } *)D_001A4BE0)->v) == 0x1A) {
            side = -1.5707964f;
        }
        v10[0] += func_00388960(func_00389380((((struct { u8 pad[0x98]; f32 v; } *)D_001A4BE0)->v), side)) * 0.3f;
        v10[1] += func_00388978(func_00389380((((struct { u8 pad[0x98]; f32 v; } *)D_001A4BE0)->v), side)) * 0.3f;
        func_L01_004EAA78(0, 1.0f);
        if (((((struct { u8 pad[0x2838]; f32 v; } *)D_001A4BE0)->v) < 0.5f) || (func_00389468((((struct { u8 pad[0x1A0]; f32 v; } *)D_001A4BE0)->v), func_00389380((((struct { u8 pad[0x98]; f32 v; } *)D_001A4BE0)->v), side)) > 0.7853982f) || (func_L01_004E4550((s8 *)v10, (s8 *)(D_001A4BE0 + 0x90), 0) == 0)) {
            if ((((struct { u8 pad[0xC08]; s32 v; } *)D_001A4BE0)->v) & 2) {
                func_L23_004DF5A8(0x18, 1);
                break;
            }
        }
        if (((((struct { u8 pad[0x2838]; f32 v; } *)D_001A4BE0)->v) > 0.5f) && (func_L01_0045D358(func_0039E928(0x40, 0), 9, 0, 0) != 0) && (func_00389468((((struct { u8 pad[0x1A0]; f32 v; } *)D_001A4BE0)->v), (((struct { u8 pad[0x98]; f32 v; } *)D_001A4BE0)->v)) > 2.3561945f)) {
            func_L23_004DF5A8(6, 1);
            (((struct { u8 pad[0x25F0]; s8 v; } *)D_001A4BE0)->v) = 1;
            (((struct { u8 pad[0x1D0]; s16 v; } *)D_001A4BE0)->v) = 0x28;
            break;
        }
        if (func_L01_0045D358(func_0039E928(0x40, 0), 9, 0, 0) != 0) {
            func_L23_004DF5A8(0x1B, 1);
        }
        break;
    }
    case 0x7B:
        if ((((struct { u8 pad[0x1B8]; s32 v; } *)D_001A4BE0)->v) >= 0x12d) {
            func_L01_004EA040();
        }
        if ((((struct { u8 pad[0x147C]; u8 v; } *)D_001A4BE0)->v) == 0) {
            if ((((struct { u8 pad[0x36E]; s16 v; } *)D_001A4BE0)->v) != 0) {
                func_L23_004DF5A8(6, 1);
            } else {
                func_L23_004DF5A8(0, 1);
            }
        }
        break;
    case 0x6:
    case 0x2C:
        if (((((struct { u8 pad[0x25C8]; s32 v; } *)D_001A4BE0)->v) == 0) && (((((struct { u8 pad[0x1B8]; s32 v; } *)D_001A4BE0)->v) >= 0x12) || ((((struct { u8 pad[0x33C]; f32 v; } *)D_001A4BE0)->v) > 1.75f))) {
            func_L01_0050BB98(0xB, 0, 16.0f);
            (((struct { u8 pad[0x25C8]; s32 v; } *)D_001A4BE0)->v) = 1;
            if ((((struct { u8 pad[0x25C4]; u32 v; } *)D_001A4BE0)->v) == 0x2C) {
                (((struct { u8 pad[0x280C]; s32 v; } *)D_001A4BE0)->v) = 7;
            } else {
                (((struct { u8 pad[0x280C]; s32 v; } *)D_001A4BE0)->v) = 0;
            }
        }
        if ((((struct { u8 pad[0x36E]; s16 v; } *)D_001A4BE0)->v) == 0) {
            func_L01_004DD470();
            if ((((struct { u8 pad[0x118]; f32 v; } *)D_001A4BE0)->v) < -0.15f) {
                (((struct { u8 pad[0x118]; f32 v; } *)D_001A4BE0)->v) = -0.15f;
            }
            if ((((struct { u8 pad[0xF8]; f32 v; } *)D_001A4BE0)->v) < -0.15f) {
                (((struct { u8 pad[0xF8]; f32 v; } *)D_001A4BE0)->v) = -0.15f;
            }
            if ((((struct { u8 pad[0x2850]; s32 v; } *)D_001A4BE0)->v) <= 0) {
                func_L23_004DF5A8(0x39, 1);
            } else {
                s32 one = 1;
                s32 low = (((struct { u8 pad[0x35C]; s32 v; } *)D_001A4BE0)->v) == 0;
                if ((((struct { u8 pad[0x1B8]; s32 v; } *)D_001A4BE0)->v) >= 0x5a) {
                    if (func_L23_004DF5A8(0, 0) != 0) {
                        func_L01_0050BB98(0xC, 4, 6.0f);
                    }
                    if (low != 0) {
                        (((struct { u8 pad[0x1E0]; s16 v; } *)D_001A4BE0)->v) = 0x16;
                    }
                    func_L01_0050CCC8(0xA, 4, 0, 1, 0.022f, 0.004f);
                } else if ((((struct { u8 pad[0x25C8]; s32 v; } *)D_001A4BE0)->v) == one) {
                    if (func_L23_004DF5A8(0, 0) != 0) {
                        func_L01_0050BB98(0xC, 9, -1.0f);
                    }
                    func_L01_0050D530(D_001A4BE0 + 0x160, D_001A4BE0 + 0x160, 0.0f);
                    func_003BF640((f32 *)(D_001A4BE0 + 0x160), 0.116666675f);
                    (((struct { u8 pad[0x1E0]; s16 v; } *)D_001A4BE0)->v) = 7;
                    if ((((struct { u8 pad[0x25D0]; s32 v; } *)D_001A4BE0)->v) == 0x2C) {
                        (((struct { u8 pad[0x1E0]; s16 v; } *)D_001A4BE0)->v) = 10;
                    }
                    if ((low != 0) && ((((struct { u8 pad[0x1B8]; s32 v; } *)D_001A4BE0)->v) >= 0x33)) {
                        (((struct { u8 pad[0x1E0]; s16 v; } *)D_001A4BE0)->v) = 0x12;
                    }
                    func_L01_0050CCC8(0xA, 2, 0, 1, 0.019f, 0.002f);
                } else if (((((struct { u8 pad[0x2838]; f32 v; } *)D_001A4BE0)->v) > 0.5f) && ((((struct { u8 pad[0x1E0]; s16 v; } *)D_001A4BE0)->v) == 0)) {
                    func_L23_004DF5A8(2, 1);
                    func_L01_0050CCC8(7, 2, 0, 1, 0.016f, 0.002f);
                } else if ((((struct { u8 pad[0x174]; f32 v; } *)D_001A4BE0)->v) > 0.050000004f) {
                    if (func_L23_004DF5A8(3, 0) != 0) {
                        func_L01_0050BB98(6, 0, 12.0f);
                        func_003BF640((f32 *)(D_001A4BE0 + 0x160), 0.12833333f);
                    }
                } else {
                    func_L23_004DF5A8(0, 1);
                    func_L01_0050CCC8(5, 2, 0, 1, 0.016f, 0.002f);
                }
            }
        } else if ((((struct { u8 pad[0x2850]; s32 v; } *)D_001A4BE0)->v) > 0) {
            if (((((struct { u8 pad[0x1A0]; s32 v; } *)D_001D52FC)->v) & func_0039E928(0x40, 0)) && (D_00142CA0[2] != 0) && (func_L01_004E5470(3) != 4) && ((((struct { u8 pad[0x2884]; s16 v; } *)D_001A4BE0)->v) == 0) && ((((struct { u8 pad[0x1E0]; s16 v; } *)D_001A4BE0)->v) == 0) && ((((struct { u8 pad[0x33C]; f32 v; } *)D_001A4BE0)->v) > 0.6f)) {
                func_L23_004DF5A8(8, 1);
                break;
            }
            if (((((struct { u8 pad[0x202]; s16 v; } *)D_001A4BE0)->v) >= 0x29) && (func_L01_00502368(((((struct { u8 pad[0x1EE]; s16 v; } *)D_001A4BE0)->v) != 0) ? 1 : 6, 0) != 0)) {
                break;
            }
            if ((((struct { u8 pad[0x528]; s32 v; } *)D_001A4BE0)->v) != 0) {
                func_L23_004DF5A8(0x17, 1);
                break;
            }
            if ((((struct { u8 pad[0x5DC]; s32 v; } *)D_001A4BE0)->v) != 0) {
                func_L23_004DF5A8(0x27, 1);
                break;
            }
            if ((((struct { u8 pad[0x69C]; s32 v; } *)D_001A4BE0)->v) != 0) {
                func_L23_004DF5A8(0x76, 1);
                break;
            }
        }
        break;
    case 0x79:
        if ((((struct { u8 pad[0x1B8]; s32 v; } *)D_001A4BE0)->v) < 0x79) {
            break;
        }
        func_L01_004EA040();
        return;
    case 0xB0:
        if ((((struct { u8 pad[0x33C]; f32 v; } *)D_001A4BE0)->v) < 3.0f) {
            func_L23_004DF5A8(8, 1);
        }
        break;
    case 0x8:
        if (((((struct { u8 pad[0x1D4]; s32 v; } *)D_001A4BE0)->v) != 0) && ((((struct { u8 pad[0x1B8]; s32 v; } *)D_001A4BE0)->v) < 9)) {
            s32 prev = (((struct { u8 pad[0x25D0]; s32 v; } *)D_001A4BE0)->v);
            s32 ok = 0;
            if ((prev == 7) || (prev == 9) || (prev == 0xE) || (prev == 0x11)) {
                ok = 1;
            }
            if (ok != 0) {
                func_L23_004DF5A8(0x11, 1);
            }
            break;
        }
        if (((((struct { u8 pad[0x1B8]; s32 v; } *)D_001A4BE0)->v) >= 0x1f) && ((((struct { u8 pad[0x22C]; s16 v; } *)D_001A4BE0)->v) == 0) && !((((struct { u8 pad[0x1A0]; s32 v; } *)D_001D52FC)->v) & func_0039E928(0x40, 0)) && !((((struct { u8 pad[0x1C0]; s32 v; } *)D_001D52FC)->v) & func_0039E928(0x40, 0))) {
            func_L23_004DF5A8(6, 1);
            break;
        }
        if ((((struct { u8 pad[0x528]; s32 v; } *)D_001A4BE0)->v) != 0) {
            func_L23_004DF5A8(0x17, 1);
            break;
        }
        if (((((struct { u8 pad[0x36E]; s16 v; } *)D_001A4BE0)->v) != 0) && !((((struct { u8 pad[0x33C]; f32 v; } *)D_001A4BE0)->v) < 0.4f)) {
            break;
        }
        if ((((struct { u8 pad[0x1B8]; s32 v; } *)D_001A4BE0)->v) < 10) {
            (((struct { u8 pad[0x1EE]; s16 v; } *)D_001A4BE0)->v) = 0xc - (((struct { u8 pad[0x1B8]; u16 v; } *)D_001A4BE0)->v);
        }
        func_L01_004EAA78(0, 1.0f);
        if (((((struct { u8 pad[0x25D0]; s32 v; } *)D_001A4BE0)->v) == 0x10) && ((((struct { u8 pad[0x1B8]; s32 v; } *)D_001A4BE0)->v) < 4)) {
            if (func_L23_004DF5A8(3, 0) != 0) {
                func_L01_0050BB98(5, 0, -1.0f);
                (((struct { u8 pad[0x1E0]; s16 v; } *)D_001A4BE0)->v) = 0x22;
            }
            break;
        }
        if ((((struct { u8 pad[0x1A0]; s32 v; } *)D_001D52FC)->v) & func_0039E928(8, 0)) {
            func_L23_004DF5A8(4, 1);
            func_L01_0050CCC8(5, 2, 0, 1, 0.016f, 0.002f);
            break;
        }
        if ((D_L23_001DBE0C < (((struct { u8 pad[0x1B0]; f32 v; } *)D_001A4BE0)->v)) && (func_00389468((((struct { u8 pad[0x1A0]; f32 v; } *)D_001A4BE0)->v), (((struct { u8 pad[0x98]; f32 v; } *)D_001A4BE0)->v)) < 1.5707964f)) {
            if (((((struct { u8 pad[0x1474]; u8 v; } *)D_001A4BE0)->v) != 0) || ((((struct { u8 pad[0x25EA]; u8 v; } *)D_001A4BE0)->v) != 0)) {
                func_L23_004DF5A8(2, 1);
                break;
            }
            func_L23_004DF5A8(2, 0);
            if ((((struct { u8 pad[0x25C4]; u32 v; } *)D_001A4BE0)->v) == 2) {
                (((struct { u8 pad[0x25C8]; s32 v; } *)D_001A4BE0)->v) = 1;
                func_L01_0050BB98(4, 2, 8.0f);
                (((struct { u8 pad[0x3EE]; s8 v; } *)D_001A4BE0)->v) = 1;
            }
            func_L01_0050CCC8(5, 2, 1, 0, 0.016f, 0.002f);
        } else if (D_L23_001DBE0C < (((struct { u8 pad[0x1B0]; f32 v; } *)D_001A4BE0)->v)) {
            if (((((struct { u8 pad[0x1474]; u8 v; } *)D_001A4BE0)->v) != 0) || ((((struct { u8 pad[0x25EA]; u8 v; } *)D_001A4BE0)->v) != 0)) {
                func_L23_004DF5A8(2, 1);
                break;
            }
            func_L23_004DF5A8(2, 0);
            if ((((struct { u8 pad[0x25C4]; u32 v; } *)D_001A4BE0)->v) == 2) {
                (((struct { u8 pad[0x25C8]; s32 v; } *)D_001A4BE0)->v) = 1;
                func_L01_0050BB98(4, D_L23_001DBE34, 12.0f);
            }
            func_L01_0050CCC8(5, 2, 1, 0, 0.016f, 0.002f);
        } else if ((((struct { u8 pad[0x36E]; s16 v; } *)D_001A4BE0)->v) == 0) {
            if (func_L23_004DF5A8(0, 0) != 0) {
                func_L01_0050BB98(func_L23_004BDA28(0), 0, -2.0f);
                func_L01_0050CCC8(5, 2, 0, 1, 0.016f, 0.002f);
            }
        } else if (func_L23_004DF5A8(0, 0) != 0) {
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
        if ((((struct { u8 pad[0x4FE]; u8 v; } *)D_001A4BE0)->v) != 0) {
            s32 n = func_L01_004FB720();
            if ((n > 0) && (((((struct { u8 pad[0x1B8]; s32 v; } *)D_001A4BE0)->v) < n) || ((((struct { u8 pad[0x46C]; u8 v; } *)D_001A4BE0)->v) != 0)) && ((((struct { u8 pad[0x360]; s32 v; } *)D_001A4BE0)->v) != 0)) {
                if (((((struct { u8 pad[0x25C4]; u32 v; } *)D_001A4BE0)->v) != 0xB) || (func_L01_0045D358(func_0039E928(0x40, 0), 7, 0, 0) != 0)) {
                    s32 go = 1;
                    if (((((struct { u8 pad[0x25C4]; u32 v; } *)D_001A4BE0)->v) == 0x1B) || ((((struct { u8 pad[0x46C]; u8 v; } *)D_001A4BE0)->v) != 0)) {
                        if (func_L01_0045D358(func_0039E928(0x40, 0), 7, 0, 0) == 0) {
                            go = 0;
                        }
                    }
                    if ((((struct { u8 pad[0x25C4]; u32 v; } *)D_001A4BE0)->v) == 0xB) {
                        if ((((struct { u8 pad[0x46C]; u8 v; } *)D_001A4BE0)->v) == 0) {
                            go = 0;
                        }
                    }
                    if ((go != 0) && (func_L01_0045D358(0x1F000, 5, 0, 0) != 0) && ((((struct { u8 pad[0x1A0]; s32 v; } *)D_001D52FC)->v) & func_0039E928(8, 0))) {
                        func_L23_004DF5A8(0xB, 1);
                        break;
                    }
                }
            }
        }
        if (((((struct { u8 pad[0x25C4]; u32 v; } *)D_001A4BE0)->v) == 0x1B) && ((((struct { u8 pad[0x1B8]; s32 v; } *)D_001A4BE0)->v) >= 0xe) && ((((struct { u8 pad[0x298]; f32 v; } *)D_001A4BE0)->v) > 1.3f)) {
            (((struct { u8 pad[0x25F0]; s8 v; } *)D_001A4BE0)->v) = 0;
            (((struct { u8 pad[0x25ED]; s8 v; } *)D_001A4BE0)->v) = 0;
        }
        if (((((struct { u8 pad[0x1B8]; s32 v; } *)D_001A4BE0)->v) < 3) && (func_L01_0045D358(func_0039E928(8, 0), 2, 0, 0) != 0) && ((sa = (((struct { u8 pad[0x25C4]; u32 v; } *)D_001A4BE0)->v)) != 0x10) && (sa != 0xA) && (sa != 0x12) && (sa != 0x38) && (sa != 0x11) && (sa != 0xE) && (sa != 0x6B)) {
            if ((func_L01_004E5470(3) == 2) && (D_00142CA0[2] != 0) && ((((struct { u8 pad[0x2884]; s16 v; } *)D_001A4BE0)->v) == 0) && ((((struct { u8 pad[0x178]; f32 v; } *)D_001A4BE0)->v) > 0.015000001f)) {
                func_L23_004DF5A8(0xA, 1);
            } else if ((func_L01_004E5470(3) == 3) && ((((struct { u8 pad[0x2884]; s16 v; } *)D_001A4BE0)->v) == 0) && ((((struct { u8 pad[0x178]; f32 v; } *)D_001A4BE0)->v) > 0.015000001f) && ((((struct { u8 pad[0x1E4]; s16 v; } *)D_001A4BE0)->v) == 0)) {
                func_L23_004DF5A8(0x10, 1);
            }
        }
        if ((((struct { u8 pad[0x5DC]; s32 v; } *)D_001A4BE0)->v) != 0) {
            func_L23_004DF5A8(0x27, 1);
            break;
        }
        if ((((struct { u8 pad[0x69C]; s32 v; } *)D_001A4BE0)->v) != 0) {
            func_L23_004DF5A8(0x76, 1);
            break;
        }
        if ((((struct { u8 pad[0x4EA]; s16 v; } *)D_001A4BE0)->v) < (((struct { u8 pad[0x1B8]; s32 v; } *)D_001A4BE0)->v)) {
            if ((((struct { u8 pad[0x46C]; u8 v; } *)D_001A4BE0)->v) == 0) {
                func_L23_004DF5A8(6, 1);
                break;
            }
        } else if (((((struct { u8 pad[0x46C]; u8 v; } *)D_001A4BE0)->v) == 0) && (((((struct { u8 pad[0x25C4]; u32 v; } *)D_001A4BE0)->v) == 0xA) || ((((struct { u8 pad[0x25C4]; u32 v; } *)D_001A4BE0)->v) == 0x10)) && ((((struct { u8 pad[0x298]; f32 v; } *)D_001A4BE0)->v) < 0.9f) && ((((struct { u8 pad[0x2A7]; u8 v; } *)D_001A4BE0)->v) != 0) && (func_00388770(D_001A4BE0 + 0xF0) > 0.116666675f)) {
            f32 a = func_00388770(D_001A4BE0 + 0x110);
            if ((a < func_00388770(D_001A4BE0 + 0xF0) * 0.5f) && ((((struct { u8 pad[0x528]; s32 v; } *)D_001A4BE0)->v) == 0) && ((((struct { u8 pad[0x33C]; f32 v; } *)D_001A4BE0)->v) < 2.0f)) {
                func_L01_004F10C8(0x19);
                func_L23_004DF5A8(0x7C, 1);
                break;
            }
        }
        near = 0;
        if (((((struct { u8 pad[0x25C4]; u32 v; } *)D_001A4BE0)->v) == 0xE) && ((((struct { u8 pad[0xC18]; f32 v; } *)D_001A4BE0)->v) < 35.0f)) {
            near = 1;
        }
        lo = (((struct { u8 pad[0x47C]; s16 v; } *)D_001A4BE0)->v);
        now = (((struct { u8 pad[0x1B8]; s32 v; } *)D_001A4BE0)->v);
        if (!(lo < now)) {
            break;
        }
        if (now == lo + 1) {
            if ((((struct { u8 pad[0x46D]; u8 v; } *)D_001A4BE0)->v) != 0) {
                f32 left = (f32)((((struct { u8 pad[0x400]; s32 v; } *)D_001A4BE0)->v) - now);
                if (left > 0.0f) {
                    func_L01_004E1268((((struct { u8 pad[0x408]; f32 v; } *)D_001A4BE0)->v), left, (((struct { u8 pad[0x4E4]; f32 v; } *)D_001A4BE0)->v), -1.0f);
                }
            } else if ((((struct { u8 pad[0x25C4]; u32 v; } *)D_001A4BE0)->v) != 0xE) {
                func_L01_0050D770((f32 *)(D_001A4BE0 + 0x80), (f32 *)(D_001A4BE0 + 0xF0), &sp94, (((struct { u8 pad[0x4F0]; f32 v; } *)D_001A4BE0)->v));
                func_L01_004E1268((((struct { u8 pad[0x498]; f32 v; } *)D_001A4BE0)->v), (f32)sp94, (((struct { u8 pad[0x4E4]; f32 v; } *)D_001A4BE0)->v), -1.0f);
                if ((((struct { u8 pad[0xC00]; f32 v; } *)D_001A4BE0)->v) > 1.5f) {
                    (((struct { u8 pad[0xC00]; f32 v; } *)D_001A4BE0)->v) = 1.5f;
                }
            }
            break;
        }
        if (((((struct { u8 pad[0x46D]; u8 v; } *)D_001A4BE0)->v) != 0) && (now >= (((struct { u8 pad[0x400]; s32 v; } *)D_001A4BE0)->v)) && (now < (((struct { u8 pad[0x404]; s32 v; } *)D_001A4BE0)->v))) {
            f32 left = (f32)((((struct { u8 pad[0x410]; s32 v; } *)D_001A4BE0)->v) - (((struct { u8 pad[0x400]; s32 v; } *)D_001A4BE0)->v));
            if (left > 0.0f) {
                func_L01_004E1268((((struct { u8 pad[0x498]; f32 v; } *)D_001A4BE0)->v), left, (((struct { u8 pad[0x4E4]; f32 v; } *)D_001A4BE0)->v), -1.0f);
            }
            break;
        }
        if ((((struct { u8 pad[0x358]; s32 v; } *)D_001A4BE0)->v) == 1) {
            func_L01_004F1068(0xC, 0);
            func_L01_004E20F0(3, 0x18, 1);
        }
        {
            u8 c = (((struct { u8 pad[0x46C]; u8 v; } *)D_001A4BE0)->v);
            if (c != 0) {
                (((struct { u8 pad[0x46C]; u8 v; } *)D_001A4BE0)->v) = c + 1;
            } else if (((((struct { u8 pad[0x36E]; s16 v; } *)D_001A4BE0)->v) == 0) && ((((struct { u8 pad[0x46E]; u8 v; } *)D_001A4BE0)->v) != 0) && (near == 0)) {
                func_L01_004DD470();
                (((struct { u8 pad[0x46C]; u8 v; } *)D_001A4BE0)->v) = 1;
                (((struct { u8 pad[0x285F]; s8 v; } *)D_001A4BE0)->v) = 0;
                if (((((struct { u8 pad[0x2838]; f32 v; } *)D_001A4BE0)->v) < 0.2f) && ((((struct { u8 pad[0x1B4]; f32 v; } *)D_001A4BE0)->v) > 0.041666668f)) {
                    (((struct { u8 pad[0x1B4]; f32 v; } *)D_001A4BE0)->v) = 0.041666668f;
                }
                func_L01_0050CCC8(5, 2, 0, 1, 0.016f, 0.002f);
                if (near == 0) {
                    s32 k = (s32)(((struct { u8 pad[0x4A0]; f32 v; } *)D_001A4BE0)->v) + 2;
                    if ((((struct { u8 pad[0xC18]; f32 v; } *)D_001A4BE0)->v) < (((struct { u8 pad[0x49C]; f32 v; } *)D_001A4BE0)->v) - 1.5f) {
                        func_L01_0050BB98(func_L01_004DC1A0((((struct { u8 pad[0x43]; u8 v; } *)cur)->v)), k, 7.0f);
                    }
                }
            }
        }
        if ((((struct { u8 pad[0x46C]; u8 v; } *)D_001A4BE0)->v) != 0) {
            (((struct { u8 pad[0xC00]; f32 v; } *)D_001A4BE0)->v) = 1.0f;
        } else if ((((struct { u8 pad[0x46E]; u8 v; } *)D_001A4BE0)->v) != 0) {
            u32 st9;
            if ((s32)(((struct { u8 pad[0x41]; u8 v; } *)cur)->v) < (s32)(((struct { u8 pad[0x4A0]; f32 v; } *)D_001A4BE0)->v)) {
                if (((((struct { u8 pad[0x25C4]; u32 v; } *)D_001A4BE0)->v) == 0xE) && ((((struct { u8 pad[0xC18]; f32 v; } *)D_001A4BE0)->v) < 37.0f)) {
                    func_003BEBF8((f32 *)(D_001A4BE0 + 0xC00), 1.0f, 0.15f);
                } else {
                    (((struct { u8 pad[0x47E]; s16 v; } *)D_001A4BE0)->v) = (s32)func_L01_0050C4A0(60.0f, (((struct { u8 pad[0x4F0]; f32 v; } *)D_001A4BE0)->v), -1.0f);
                    func_L01_004E1268((((struct { u8 pad[0x49C]; f32 v; } *)D_001A4BE0)->v), (f32)(((struct { u8 pad[0x47E]; s16 v; } *)D_001A4BE0)->v), (((struct { u8 pad[0x4E4]; f32 v; } *)D_001A4BE0)->v), 0.2f);
                }
                if (near == 0) {
                    s32 k = (s32)(((struct { u8 pad[0x4A0]; f32 v; } *)D_001A4BE0)->v) + 2;
                    if ((((struct { u8 pad[0xC00]; f32 v; } *)D_001A4BE0)->v) > 1.8f) {
                        func_L01_0050BB98(func_L01_004DC1A0((((struct { u8 pad[0x43]; u8 v; } *)cur)->v)), k, (f32)((((struct { u8 pad[0x47E]; s16 v; } *)D_001A4BE0)->v) + 3));
                    }
                }
                if ((((struct { u8 pad[0xC00]; f32 v; } *)D_001A4BE0)->v) < 0.2f) {
                    (((struct { u8 pad[0xC00]; f32 v; } *)D_001A4BE0)->v) = 0.2f;
                }
                if ((((struct { u8 pad[0xC00]; f32 v; } *)D_001A4BE0)->v) > 2.7f) {
                    (((struct { u8 pad[0xC00]; f32 v; } *)D_001A4BE0)->v) = 2.7f;
                }
            }
            st9 = (((struct { u8 pad[0x25C4]; u32 v; } *)D_001A4BE0)->v);
            if ((st9 == 9) && (((((struct { u8 pad[0x49C]; f32 v; } *)D_001A4BE0)->v) - (((struct { u8 pad[0xC18]; f32 v; } *)D_001A4BE0)->v)) > 6.0f) && ((func_L01_004DC1A0((((struct { u8 pad[0x42]; u8 v; } *)cur)->v)) == 8) || (func_L01_004DC1A0((((struct { u8 pad[0x42]; u8 v; } *)cur)->v)) == st9)) && ((((struct { u8 pad[0x42]; u8 v; } *)cur)->v) == (((struct { u8 pad[0x43]; u8 v; } *)cur)->v)) && ((((struct { u8 pad[0x1B0]; f32 v; } *)D_001A4BE0)->v) < D_L23_001DBE14[1] * 0.016666668f * 0.1f) && ((((struct { u8 pad[0x174]; f32 v; } *)D_001A4BE0)->v) < 0.041666668f)) {
                f32 rate = 9.0f / (((struct { u8 pad[0xC00]; f32 v; } *)D_001A4BE0)->v);
                s32 at;
                if (rate > 10.0f) {
                    rate = 10.0f;
                }
                at = (s32)(((struct { u8 pad[0xC18]; f32 v; } *)D_001A4BE0)->v) + 4;
                func_L01_0050BB98(7, at / 2, rate);
                (((struct { u8 pad[0x25C4]; s32 v; } *)D_001A4BE0)->v) = 7;
            }
            if ((s32)(((struct { u8 pad[0xC18]; f32 v; } *)D_001A4BE0)->v) == (s32)(((struct { u8 pad[0x49C]; f32 v; } *)D_001A4BE0)->v)) {
                (((struct { u8 pad[0xC00]; s32 v; } *)D_001A4BE0)->v) = 0;
            }
        }
        if ((((struct { u8 pad[0x46C]; u8 v; } *)D_001A4BE0)->v) != 0) {
            if ((((struct { u8 pad[0x25C4]; u32 v; } *)D_001A4BE0)->v) == 0xA) {
                if (func_L23_004DF5A8(3, 0) != 0) {
                    func_L01_0050BB98(5, 0, -2.0f);
                    func_003886E8(D_001A4BE0 + 0x160, D_001A4BE0 + 0x160, 0.8f);
                }
                break;
            }
            if (((((struct { u8 pad[0x147C]; u8 v; } *)D_001A4BE0)->v) == 0) && ((((struct { u8 pad[0x1E0]; s16 v; } *)D_001A4BE0)->v) == 0) && (func_L01_0045D358(func_0039E928(0x40, 0), 8, 0, 0) != 0) && ((((struct { u8 pad[0x36E]; s16 v; } *)D_001A4BE0)->v) < 8)) {
                if ((((((struct { u8 pad[0x1434]; s16 v; } *)D_001A4BE0)->v) != 0) || (((((struct { u8 pad[0x16B0]; s32 v; } *)D_001A4BE0)->v) == 1) && (func_L01_0045D358(0x28, 2, 0, 0) != 0))) && ((((struct { u8 pad[0x2838]; f32 v; } *)D_001A4BE0)->v) > 0.9f) && (func_L01_004FB758() != 2)) {
                    func_L23_004DF5A8(0xB, 1);
                } else if (!((((struct { u8 pad[0x1B0]; f32 v; } *)D_001A4BE0)->v) > D_L23_001DBE0C)) {
                    func_L23_004DF5A8(7, 1);
                } else if (!(func_00389468((((struct { u8 pad[0x1A0]; f32 v; } *)D_001A4BE0)->v), (((struct { u8 pad[0x98]; f32 v; } *)D_001A4BE0)->v)) < 1.0471976f)) {
                    func_L23_004DF5A8(7, 1);
                } else if (D_L23_001DBE14[1] * 0.016666668f * 0.85f < (((struct { u8 pad[0x174]; f32 v; } *)D_001A4BE0)->v)) {
                    func_L23_004DF5A8(9, 1);
                } else {
                    func_L23_004DF5A8(7, 1);
                }
                break;
            }
        }
        if (((((struct { u8 pad[0x46C]; u8 v; } *)D_001A4BE0)->v) >= 2) && ((((struct { u8 pad[0x25C4]; u32 v; } *)D_001A4BE0)->v) != 0xA)) {
            func_L01_00502C58();
        } else if (((((struct { u8 pad[0x46E]; u8 v; } *)D_001A4BE0)->v) != 0) && ((((struct { u8 pad[0x1B8]; s32 v; } *)D_001A4BE0)->v) >= (((struct { u8 pad[0x4FA]; s16 v; } *)D_001A4BE0)->v)) && ((((struct { u8 pad[0x33C]; f32 v; } *)D_001A4BE0)->v) > (((struct { u8 pad[0x4E0]; f32 v; } *)D_001A4BE0)->v))) {
            func_L23_004DF5A8(6, 1);
        }
        if (((((struct { u8 pad[0x25C4]; u32 v; } *)D_001A4BE0)->v) == 0x10) && ((((struct { u8 pad[0x1B8]; s32 v; } *)D_001A4BE0)->v) >= 0x3d) && ((((struct { u8 pad[0x33C]; f32 v; } *)D_001A4BE0)->v) > 1.5f)) {
            func_L23_004DF5A8(6, 1);
            break;
        }
        {
            u32 s = (((struct { u8 pad[0x25C4]; u32 v; } *)D_001A4BE0)->v);
            s32 ok = 0;
            if ((s == 7) || (s == 9) || (s == 0x11)) {
                ok = 1;
            }
            if (((((struct { u8 pad[0x1D4]; s32 v; } *)D_001A4BE0)->v) != 0) && ((((struct { u8 pad[0x46C]; u8 v; } *)D_001A4BE0)->v) == 0) && (ok != 0) && (((((struct { u8 pad[0x25C4]; u32 v; } *)D_001A4BE0)->v) != 0x11) || ((((struct { u8 pad[0x1B8]; s32 v; } *)D_001A4BE0)->v) >= 0x1a)) && (func_L01_0045D358(func_0039E928(0x40, 0), 7, &sp98, 0) != 0) && (sp98 < (((struct { u8 pad[0x1B8]; s32 v; } *)D_001A4BE0)->v))) {
                func_L23_004DF5A8(0x11, 1);
                break;
            }
        }
        if ((((((struct { u8 pad[0x25C4]; u32 v; } *)D_001A4BE0)->v) == 0xA) || ((((struct { u8 pad[0x25C4]; u32 v; } *)D_001A4BE0)->v) == 0x10)) && ((((struct { u8 pad[0x1B8]; s32 v; } *)D_001A4BE0)->v) >= 0x1a) && ((((struct { u8 pad[0x36A]; s16 v; } *)D_001A4BE0)->v) != 0)) {
            (((struct { u8 pad[0x4F6]; s16 v; } *)D_001A4BE0)->v) = 0x14;
        }
        sc = (((struct { u8 pad[0x25C4]; u32 v; } *)D_001A4BE0)->v);
        lim = 0x14;
        if (sc == 0x10) {
            lim = 8;
        }
        if ((sc == 0xe) && ((((struct { u8 pad[0x33C]; f32 v; } *)D_001A4BE0)->v) > 4.0f)) {
            if (((((struct { u8 pad[0x46E]; u8 v; } *)D_001A4BE0)->v) == 0) && ((((struct { u8 pad[0xC00]; f32 v; } *)D_001A4BE0)->v) < 1.3f)) {
                func_003BEBF8((f32 *)(D_001A4BE0 + 0xC00), 1.3f, 0.1f);
            }
            lim = 0x11;
            (((struct { u8 pad[0x4F6]; s16 v; } *)D_001A4BE0)->v) = lim;
        }
        frames = (((struct { u8 pad[0x1B8]; s32 v; } *)D_001A4BE0)->v) - 4;
        if (frames <= 1) {
            frames = 2;
        }
        if (frames >= 0x1f) {
            frames = 0x1e;
        }
        if (!((((struct { u8 pad[0x468]; long v; } *)D_001A4BE0)->v) & 0xFF0000FF00000000L)) {
            if ((func_L01_0045D358(func_0039E928(0x40, 0), frames, 0, 0) != 0) || ((((struct { u8 pad[0x25C4]; u32 v; } *)D_001A4BE0)->v) == 0xE) || ((((struct { u8 pad[0x25C4]; u32 v; } *)D_001A4BE0)->v) == 0xF) || ((((struct { u8 pad[0x25C4]; u32 v; } *)D_001A4BE0)->v) == 0xD)) {
                if (((((struct { u8 pad[0x25C4]; u32 v; } *)D_001A4BE0)->v) != 0xE) && ((((struct { u8 pad[0x25E9]; u8 v; } *)D_001A4BE0)->v) == 0) && (((((struct { u8 pad[0x147C]; u8 v; } *)D_001A4BE0)->v) == 0) || !((((struct { u8 pad[0x33C]; f32 v; } *)D_001A4BE0)->v) < 0.4f)) && ((((struct { u8 pad[0x4FF]; u8 v; } *)D_001A4BE0)->v) != 0) && ((((struct { u8 pad[0x1B8]; s32 v; } *)D_001A4BE0)->v) >= 0xf) && (((((struct { u8 pad[0x46E]; u8 v; } *)D_001A4BE0)->v) == 0) || (((((struct { u8 pad[0x33C]; f32 v; } *)D_001A4BE0)->v) > 0.7f) && (fabs_asm(func_L01_0050D4D8((s8 *)(D_001A4BE0 + 0xF0))) < 0.09666667f)))) {
                    func_L23_004DF5A8(0xE, 1);
                } else if ((D_00142CA0[2] != 0) && (func_L01_004E5470(3) != 4) && ((((struct { u8 pad[0x2884]; s16 v; } *)D_001A4BE0)->v) == 0) && ((((struct { u8 pad[0x1A0]; s32 v; } *)D_001D52FC)->v) & func_0039E928(0x40, 0)) && (lim < (((struct { u8 pad[0x1B8]; s32 v; } *)D_001A4BE0)->v)) && ((((struct { u8 pad[0x4F6]; s16 v; } *)D_001A4BE0)->v) < (((struct { u8 pad[0x1B8]; s32 v; } *)D_001A4BE0)->v))) {
                    f32 need = 0.6f;
                    if (((((struct { u8 pad[0x25C4]; u32 v; } *)D_001A4BE0)->v) == 9) || ((((struct { u8 pad[0x25C4]; u32 v; } *)D_001A4BE0)->v) == 7)) {
                        need = 1.0f;
                    }
                    if ((((struct { u8 pad[0x25C4]; u32 v; } *)D_001A4BE0)->v) == 0xE) {
                        need = 1.5f;
                    }
                    if (need < (((struct { u8 pad[0x33C]; f32 v; } *)D_001A4BE0)->v)) {
                        func_L23_004DF5A8(8, 1);
                    }
                }
            }
        }
        if (((((struct { u8 pad[0x528]; s32 v; } *)D_001A4BE0)->v) != 0) && ((((struct { u8 pad[0x25C4]; u32 v; } *)D_001A4BE0)->v) != 0xB)) {
            func_L23_004DF5A8(0x17, 1);
        }
        break;
    }
    case 0xB1:
        if ((((struct { u8 pad[0x1B8]; s32 v; } *)D_001A4BE0)->v) < 0x29) {
            break;
        }
        if ((((struct { u8 pad[0x2850]; s32 v; } *)D_001A4BE0)->v) <= 0) {
            func_L23_004DF5A8(0x39, 1);
        } else {
            func_L23_004DF5A8(0, 1);
        }
        break;
    case 0x16:
        if (((((struct { u8 pad[0xC18]; f32 v; } *)D_001A4BE0)->v) > 12.5f) && ((((struct { u8 pad[0x2877]; u8 v; } *)D_001A4BE0)->v) == 0) && ((((struct { u8 pad[0x36E]; s16 v; } *)D_001A4BE0)->v) != 0) && ((((struct { u8 pad[0x33C]; f32 v; } *)D_001A4BE0)->v) > 1.0f)) {
            if ((((struct { u8 pad[0x25D0]; s32 v; } *)D_001A4BE0)->v) == 0xB0) {
                if ((((struct { u8 pad[0x2850]; s32 v; } *)D_001A4BE0)->v) <= 0) {
                    func_L23_004DF5A8(0x79, 1);
                } else {
                    func_L23_004DF5A8(0xB0, 0);
                    func_L01_0050BB98(0x7A, 0, 11.0f);
                }
            } else {
                func_L23_004DF5A8(6, 1);
            }
            break;
        }
        if ((((struct { u8 pad[0x1B8]; s32 v; } *)D_001A4BE0)->v) >= 0x1c) {
            if ((((struct { u8 pad[0x2850]; s32 v; } *)D_001A4BE0)->v) <= 0) {
                if ((((struct { u8 pad[0x1477]; u8 v; } *)D_001A4BE0)->v) != 0) {
                    func_L23_004DF5A8(0x7E, 1);
                } else if ((((struct { u8 pad[0x25D0]; s32 v; } *)D_001A4BE0)->v) == 0xB0) {
                    func_L23_004DF5A8(0x79, 1);
                } else {
                    func_L23_004DF5A8(0x39, 1);
                }
            } else if ((((struct { u8 pad[0x2877]; u8 v; } *)D_001A4BE0)->v) != 0) {
                func_L23_004DF5A8(0x87, 1);
            } else if ((((struct { u8 pad[0x25D0]; s32 v; } *)D_001A4BE0)->v) == 0xB0) {
                func_L23_004DF5A8(0xB0, 1);
            } else {
                func_L23_004DF5A8(0, 0);
            }
        }
        break;
    case 0x91:
        if ((((struct { u8 pad[0xC08]; s32 v; } *)D_001A4BE0)->v) & 2) {
            func_L01_0050BB98(0x75, 0, 2.0f);
        }
        if (((((struct { u8 pad[0x1B8]; s32 v; } *)D_001A4BE0)->v) >= 0x33) && ((((struct { u8 pad[0x1E0]; s16 v; } *)D_001A4BE0)->v) == 0)) {
            if ((((struct { u8 pad[0x2850]; s32 v; } *)D_001A4BE0)->v) <= 0) {
                func_L23_004DF5A8(0x39, 1);
            } else if (func_L23_004DF5A8(0, 0) != 0) {
                func_L01_0050BB98(func_L23_004BDA28(0), 0, 13.0f);
            }
        }
        break;
    case 0x3F:
    {
        s16 t = (((struct { u8 pad[0x28A8]; s16 v; } *)D_001A4BE0)->v);
        if (t >= 0x2b) {
            func_L01_0050BB98(0x12, 0, 10.0f);
            break;
        }
        if ((t == 0) && ((((struct { u8 pad[0xC08]; s32 v; } *)D_001A4BE0)->v) & 2)) {
            if ((((struct { u8 pad[0x43]; u8 v; } *)((((struct { u8 pad[0x25C0]; u8 * v; } *)D_001A4BE0)->v)))->v) != func_L23_004BDA28(0)) {
                func_L01_0050BB98(func_L23_004BDA28(0), 0, 12.0f);
            } else if (func_0037E250(0.0f, 1.0f) < 0.15f) {
                func_L01_0050BB98(0x15, 0, 8.0f);
            }
        }
        if ((((struct { u8 pad[0x147C]; u8 v; } *)D_001A4BE0)->v) != 0) {
            func_L23_004DF5A8(0x4E, 1);
            break;
        }
        if (((((struct { u8 pad[0x1A0]; s32 v; } *)D_001D52FC)->v) & func_L01_0050EE20(func_0039E928(4, 0)))
            && (((((struct { u8 pad[0x25E4]; u8 v; } *)D_001A4BE0)->v) != 0) || (D_001439F4[0] != 2) || ((((struct { u8 pad[0x1228]; s32 v; } *)D_001A4BE0)->v) == 0x6F))
            && (func_L01_003E9428(0) == 0)) {
            func_L23_004DF5A8(1, 1);
            break;
        }
        if ((((struct { u8 pad[0x36E]; s16 v; } *)D_001A4BE0)->v) != 0) {
            func_L23_004DF5A8(0x41, 1);
            break;
        }
        if (func_L01_0045D358(func_0039E928(0x40, 0), 8, 0, 0) != 0) {
            func_L23_004DF5A8(0x45, 1);
            break;
        }
        if (func_L01_0045D358(0x80, 9, 0, 0) != 0) {
            func_L23_004DF5A8(0x4D, 1);
            break;
        }
        func_L01_004EAA78(0, 1.0f);
        if (((((struct { u8 pad[0x2838]; f32 v; } *)D_001A4BE0)->v) > 0.2f) && ((((struct { u8 pad[0x1B0]; f32 v; } *)D_001A4BE0)->v) > 0.0f)) {
            func_L23_004DF5A8(0x40, 1);
            break;
        }
        if (((((struct { u8 pad[0x28A8]; s16 v; } *)D_001A4BE0)->v) == 0) && ((((struct { u8 pad[0x43]; u8 v; } *)((((struct { u8 pad[0x25C0]; u8 * v; } *)D_001A4BE0)->v)))->v) == 0x12)) {
            func_L01_0050BB98(func_L23_004BDA28(0), 0, 12.0f);
        }
        break;
    }
    case 0x4D:
    {
        u8 *rec;
        s32 frames;
        if ((((struct { u8 pad[0x147C]; u8 v; } *)D_001A4BE0)->v) != 0) {
            func_L23_004DF5A8(0x4E, 1);
            break;
        }
        rec = (u8 *)&D_L23_002F7350[(((struct { u8 pad[0xBDC]; s16 v; } *)D_001A4BE0)->v)];
        if ((((struct { u8 pad[0xC0C]; s32 v; } *)D_001A4BE0)->v) == 0) {
            s32 busy;
            if ((f32)(((struct { u8 pad[0x18]; s32 v; } *)rec)->v) < (((struct { u8 pad[0xC18]; f32 v; } *)D_001A4BE0)->v)) {
                func_L23_004DF5A8(0x3F, 0);
            }
            busy = (((struct { u8 pad[0xC0C]; s32 v; } *)D_001A4BE0)->v);
            if ((busy == 0) && ((f32)(((struct { u8 pad[0x10]; s32 v; } *)rec)->v) <= (((struct { u8 pad[0xC18]; f32 v; } *)D_001A4BE0)->v))) {
                s32 n = (s32)(((struct { u8 pad[0xC18]; f32 v; } *)D_001A4BE0)->v) - (((struct { u8 pad[0xC]; s32 v; } *)rec)->v);
                if (n < 1) {
                    n = 1;
                }
                if (func_L01_0045D358(0x80, (n < 0x10) ? n : 0xf, 0, 0) != 0) {
                    func_L23_004DF5A8(0x4D, 1);
                }
            }
        }
        frames = ((s32)(((struct { u8 pad[0xC18]; f32 v; } *)D_001A4BE0)->v) - (((struct { u8 pad[0xC]; s32 v; } *)rec)->v)) * 2;
        if (((f32)(((struct { u8 pad[0x14]; s32 v; } *)rec)->v) < (((struct { u8 pad[0xC18]; f32 v; } *)D_001A4BE0)->v)) && ((((struct { u8 pad[0xC0C]; s32 v; } *)D_001A4BE0)->v) == 0) && (func_L01_0045D358(func_0039E928(0x40, 0), frames, 0, 0) != 0)) {
            func_L23_004DF5A8(0x45, 1);
        }
        break;
    }
    case 0x45:
    case 0x48:
    {
        s16 lo = (((struct { u8 pad[0x47C]; s16 v; } *)D_001A4BE0)->v);
        s32 now = (((struct { u8 pad[0x1B8]; s32 v; } *)D_001A4BE0)->v);
        if (!(lo < now)) {
            break;
        }
        if (now == lo + 1) {
            func_L01_0050D770((f32 *)(D_001A4BE0 + 0x80), (f32 *)(D_001A4BE0 + 0xF0), &sp9C, (((struct { u8 pad[0x4F0]; f32 v; } *)D_001A4BE0)->v));
            func_L01_004E1268((((struct { u8 pad[0x498]; f32 v; } *)D_001A4BE0)->v), (f32)sp9C, (((struct { u8 pad[0x4E4]; f32 v; } *)D_001A4BE0)->v), 0.25f);
            break;
        }
        if (((((struct { u8 pad[0x46D]; u8 v; } *)D_001A4BE0)->v) != 0) && (now >= (((struct { u8 pad[0x400]; s32 v; } *)D_001A4BE0)->v)) && (now < (((struct { u8 pad[0x404]; s32 v; } *)D_001A4BE0)->v))) {
            f32 left = (f32)((((struct { u8 pad[0x410]; s32 v; } *)D_001A4BE0)->v) - (((struct { u8 pad[0x400]; s32 v; } *)D_001A4BE0)->v));
            if (left > 0.0f) {
                func_L01_004E1268((((struct { u8 pad[0x498]; f32 v; } *)D_001A4BE0)->v), left, (((struct { u8 pad[0x4E4]; f32 v; } *)D_001A4BE0)->v), -1.0f);
            }
            break;
        }
        {
            u8 c = (((struct { u8 pad[0x46C]; u8 v; } *)D_001A4BE0)->v);
            if (c != 0) {
                (((struct { u8 pad[0x46C]; u8 v; } *)D_001A4BE0)->v) = c + 1;
            } else if (((((struct { u8 pad[0x36E]; s16 v; } *)D_001A4BE0)->v) == 0) && ((((struct { u8 pad[0x46E]; u8 v; } *)D_001A4BE0)->v) != 0)) {
                s32 k;
                (((struct { u8 pad[0x46C]; u8 v; } *)D_001A4BE0)->v) = 1;
                k = (s32)(((struct { u8 pad[0x4A0]; f32 v; } *)D_001A4BE0)->v) + 3;
                if ((((struct { u8 pad[0xC18]; f32 v; } *)D_001A4BE0)->v) < (((struct { u8 pad[0x49C]; f32 v; } *)D_001A4BE0)->v)) {
                    func_L01_0050BB98((((struct { u8 pad[0x43]; u8 v; } *)cur)->v), k, 6.0f);
                }
            }
        }
        if ((((struct { u8 pad[0x46C]; u8 v; } *)D_001A4BE0)->v) != 0) {
            (((struct { u8 pad[0xC00]; f32 v; } *)D_001A4BE0)->v) = 1.0f;
        } else if ((((struct { u8 pad[0x46E]; u8 v; } *)D_001A4BE0)->v) != 0) {
            if ((s32)(((struct { u8 pad[0x41]; u8 v; } *)cur)->v) < (s32)(((struct { u8 pad[0x4A0]; f32 v; } *)D_001A4BE0)->v)) {
                s32 k;
                (((struct { u8 pad[0x47E]; s16 v; } *)D_001A4BE0)->v) = (s32)func_L01_0050C4A0(60.0f, (((struct { u8 pad[0x4F0]; f32 v; } *)D_001A4BE0)->v), -1.0f);
                func_L01_004E1268((((struct { u8 pad[0x49C]; f32 v; } *)D_001A4BE0)->v), (f32)(((struct { u8 pad[0x47E]; s16 v; } *)D_001A4BE0)->v), (((struct { u8 pad[0x4E4]; f32 v; } *)D_001A4BE0)->v), -1.0f);
                k = (s32)(((struct { u8 pad[0x4A0]; f32 v; } *)D_001A4BE0)->v) + 1;
                if ((((struct { u8 pad[0xC00]; f32 v; } *)D_001A4BE0)->v) > 1.8f) {
                    func_L01_0050BB98((((struct { u8 pad[0x43]; u8 v; } *)cur)->v), k, (f32)((((struct { u8 pad[0x47E]; s16 v; } *)D_001A4BE0)->v) + 2));
                }
                if ((((struct { u8 pad[0xC00]; f32 v; } *)D_001A4BE0)->v) < 0.2f) {
                    (((struct { u8 pad[0xC00]; f32 v; } *)D_001A4BE0)->v) = 0.2f;
                }
                if ((((struct { u8 pad[0xC00]; f32 v; } *)D_001A4BE0)->v) > 2.7f) {
                    (((struct { u8 pad[0xC00]; f32 v; } *)D_001A4BE0)->v) = 2.7f;
                }
            }
            if ((s32)(((struct { u8 pad[0xC18]; f32 v; } *)D_001A4BE0)->v) == (s32)(((struct { u8 pad[0x49C]; f32 v; } *)D_001A4BE0)->v)) {
                (((struct { u8 pad[0xC00]; s32 v; } *)D_001A4BE0)->v) = 0;
            }
        }
        if (((((struct { u8 pad[0x46C]; u8 v; } *)D_001A4BE0)->v) != 0) && ((((struct { u8 pad[0x1E0]; s16 v; } *)D_001A4BE0)->v) == 0) && ((((struct { u8 pad[0x147C]; u8 v; } *)D_001A4BE0)->v) == 0) && (func_L01_0045D358(func_0039E928(0x40, 0), 4, 0, 0) != 0) && ((((struct { u8 pad[0x36E]; s16 v; } *)D_001A4BE0)->v) < 4)) {
            func_L01_004EAA78(0, 1.0f);
            func_L23_004DF5A8(0x45, 1);
            break;
        }
        if ((((struct { u8 pad[0x46C]; u8 v; } *)D_001A4BE0)->v) >= 2) {
            (((struct { u8 pad[0x280C]; s32 v; } *)D_001A4BE0)->v) = 0;
            func_L01_004EAA78(0, 1.0f);
            if (((((struct { u8 pad[0x1B0]; f32 v; } *)D_001A4BE0)->v) > D_L23_001DBE0C) && ((((struct { u8 pad[0x2838]; f32 v; } *)D_001A4BE0)->v) > 0.5f) && ((((struct { u8 pad[0x147C]; u8 v; } *)D_001A4BE0)->v) == 0) && ((((struct { u8 pad[0x1E0]; s16 v; } *)D_001A4BE0)->v) == 0) && (func_00389468((((struct { u8 pad[0x1A0]; f32 v; } *)D_001A4BE0)->v), (((struct { u8 pad[0x98]; f32 v; } *)D_001A4BE0)->v)) < 1.5707964f)) {
                func_L23_004DF5A8(0x40, 1);
            } else if ((((struct { u8 pad[0x46C]; u8 v; } *)D_001A4BE0)->v) >= 0xd) {
                func_L23_004DF5A8(0x3F, 1);
            }
        }
        if (((((struct { u8 pad[0x33C]; f32 v; } *)D_001A4BE0)->v) > 2.0f) && ((((struct { u8 pad[0x46E]; u8 v; } *)D_001A4BE0)->v) != 0) && ((((struct { u8 pad[0x1B8]; s32 v; } *)D_001A4BE0)->v) >= 0x29)) {
            func_L23_004DF5A8(0x41, 1);
            break;
        }
        if (((((struct { u8 pad[0x46E]; u8 v; } *)D_001A4BE0)->v) != 0) && ((((struct { u8 pad[0x33C]; f32 v; } *)D_001A4BE0)->v) < 0.2f) && (func_L01_0045D358(0x80, 5, 0, 0) != 0)) {
            func_L23_004DF5A8(0x4D, 1);
            break;
        }
        if ((((struct { u8 pad[0x528]; s32 v; } *)D_001A4BE0)->v) != 0) {
            func_L23_004DF5A8(0x46, 1);
            break;
        }
        if (((((struct { u8 pad[0x25C4]; u32 v; } *)D_001A4BE0)->v) != 0x48) && (func_L01_0045D358(func_0039E928(0x40, 0), 5, 0, 0) != 0) && ((((struct { u8 pad[0x33C]; f32 v; } *)D_001A4BE0)->v) > 0.55f)) {
            func_L23_004DF5A8(0x4B, 1);
        }
        break;
    }
    case 0x4B:
        if (((((struct { u8 pad[0x1B8]; s32 v; } *)D_001A4BE0)->v) >= 0x1f) && !((((struct { u8 pad[0x1A0]; s32 v; } *)D_001D52FC)->v) & func_0039E928(0x40, 0))) {
            func_L23_004DF5A8(0x41, 1);
            break;
        }
        if ((((struct { u8 pad[0x528]; s32 v; } *)D_001A4BE0)->v) != 0) {
            func_L23_004DF5A8(0x46, 1);
            break;
        }
        if (((((struct { u8 pad[0x36E]; s16 v; } *)D_001A4BE0)->v) != 0) && !(((((struct { u8 pad[0x88]; f32 v; } *)D_001A4BE0)->v) - (((struct { u8 pad[0x338]; f32 v; } *)D_001A4BE0)->v)) < 0.0f)) {
            break;
        }
        if ((((struct { u8 pad[0x1B8]; s32 v; } *)D_001A4BE0)->v) < 10) {
            (((struct { u8 pad[0x1EE]; s16 v; } *)D_001A4BE0)->v) = 0xc - (((struct { u8 pad[0x1B8]; u16 v; } *)D_001A4BE0)->v);
        }
        if ((((struct { u8 pad[0x2838]; f32 v; } *)D_001A4BE0)->v) > 0.3f) {
            func_L23_004DF5A8(0x40, 1);
            break;
        }
        if ((((struct { u8 pad[0x36E]; s16 v; } *)D_001A4BE0)->v) == 0) {
            func_L23_004DF5A8(0x3F, 1);
        }
        break;
    case 0x4F:
        if ((((struct { u8 pad[0xC18]; f32 v; } *)D_001A4BE0)->v) > 23.0f) {
            func_L23_004DF5A8(0x3F, 0);
            func_L01_0050BB98(0x21, 7, 5.0f);
        }
        break;
    case 0x41:
        if ((((struct { u8 pad[0x36E]; s16 v; } *)D_001A4BE0)->v) == 0) {
            if ((((struct { u8 pad[0x118]; f32 v; } *)D_001A4BE0)->v) < -0.15f) {
                (((struct { u8 pad[0x118]; f32 v; } *)D_001A4BE0)->v) = -0.15f;
            }
            if ((((struct { u8 pad[0xF8]; f32 v; } *)D_001A4BE0)->v) < -0.15f) {
                (((struct { u8 pad[0xF8]; f32 v; } *)D_001A4BE0)->v) = -0.15f;
            }
            if ((((struct { u8 pad[0x2850]; s32 v; } *)D_001A4BE0)->v) <= 0) {
                func_L23_004DF5A8(0x43, 1);
            } else if ((((struct { u8 pad[0x2838]; f32 v; } *)D_001A4BE0)->v) > 0.5f) {
                if ((((struct { u8 pad[0x1E0]; s16 v; } *)D_001A4BE0)->v) == 0) {
                    func_L23_004DF5A8(0x40, 1);
                } else {
                    func_L23_004DF5A8(0x3F, 1);
                }
            } else {
                func_L23_004DF5A8(0x3F, 1);
            }
        } else if ((((struct { u8 pad[0x2850]; s32 v; } *)D_001A4BE0)->v) > 0) {
            if ((((struct { u8 pad[0x528]; s32 v; } *)D_001A4BE0)->v) != 0) {
                func_L23_004DF5A8(0x46, 1);
                break;
            }
            if ((func_L01_0045D358(func_0039E928(0x40, 0), 5, 0, 0) != 0) && ((((struct { u8 pad[0x33C]; f32 v; } *)D_001A4BE0)->v) > 0.6f)) {
                func_L23_004DF5A8(0x4B, 1);
            }
        }
        break;
    case 0x44:
        if (((((struct { u8 pad[0xF8]; f32 v; } *)D_001A4BE0)->v) < 0.0f) && ((((struct { u8 pad[0x360]; s32 v; } *)D_001A4BE0)->v) != 0)) {
            func_L23_004DF5A8(0x3F, 1);
        }
        break;
    case 0x4E:
        if ((((struct { u8 pad[0x1B8]; s32 v; } *)D_001A4BE0)->v) >= 0x12d) {
            func_L01_004EA040();
        }
        if ((((struct { u8 pad[0x147C]; u8 v; } *)D_001A4BE0)->v) == 0) {
            if ((((struct { u8 pad[0x36E]; s16 v; } *)D_001A4BE0)->v) != 0) {
                func_L23_004DF5A8(0x41, 1);
            } else {
                func_L23_004DF5A8(0x3F, 1);
            }
        }
        break;
    case 0x40:
    {
        f32 speed;
        u8 *o;
        s32 anim;
        if ((((struct { u8 pad[0x147C]; u8 v; } *)D_001A4BE0)->v) != 0) {
            func_L23_004DF5A8(0x4E, 1);
            break;
        }
        if (((((struct { u8 pad[0xC0C]; s32 v; } *)D_001A4BE0)->v) == 0) && ((((struct { u8 pad[0x170]; f32 v; } *)D_001A4BE0)->v) < 0.027500002f) && ((((struct { u8 pad[0x43]; u8 v; } *)(o = (((struct { u8 pad[0x25C0]; u8 * v; } *)D_001A4BE0)->v)))->v) != 0x19)) {
            u8 *info = (((struct { u8 pad[0x24]; u8 * v; } *)o)->v);
            s32 n = (((struct { u8 pad[0x10]; u8 v; } *)((((struct { u8 pad[0xAC]; u8 * v; } *)info)->v)))->v);
            func_L01_0050BB98(0x19, ((((struct { u8 pad[0x41]; u8 v; } *)o)->v) * n / (((struct { u8 pad[0x10]; u8 v; } *)((((struct { u8 pad[0xB0]; u8 * v; } *)info)->v)))->v) + 1) % n, 8.0f);
        } else if (((((struct { u8 pad[0xC0C]; s32 v; } *)D_001A4BE0)->v) == 0) && ((((struct { u8 pad[0x170]; f32 v; } *)D_001A4BE0)->v) > 0.033000004f) && ((((struct { u8 pad[0x43]; u8 v; } *)(o = (((struct { u8 pad[0x25C0]; u8 * v; } *)D_001A4BE0)->v)))->v) != 0x1A)) {
            u8 *info = (((struct { u8 pad[0x24]; u8 * v; } *)o)->v);
            s32 n = (((struct { u8 pad[0x10]; u8 v; } *)((((struct { u8 pad[0xB0]; u8 * v; } *)info)->v)))->v);
            func_L01_0050BB98(0x1A, ((((struct { u8 pad[0x41]; u8 v; } *)o)->v) * n / (((struct { u8 pad[0x10]; u8 v; } *)((((struct { u8 pad[0xAC]; u8 * v; } *)info)->v)))->v) + 7) % n, 8.0f);
        }
        speed = (((struct { u8 pad[0x170]; f32 v; } *)D_001A4BE0)->v);
        if ((((struct { u8 pad[0x3EF]; u8 v; } *)D_001A4BE0)->v) != 0) {
            speed = 0.055000003f;
        }
        anim = (((struct { u8 pad[0x43]; u8 v; } *)((((struct { u8 pad[0x25C0]; u8 * v; } *)D_001A4BE0)->v)))->v);
        if (anim == 0x19) {
            (((struct { u8 pad[0xC00]; f32 v; } *)D_001A4BE0)->v) = speed * 90.0f;
        } else if (anim == 0x1A) {
            (((struct { u8 pad[0xC00]; f32 v; } *)D_001A4BE0)->v) = speed * 20.0f;
        }
        if ((((struct { u8 pad[0xC00]; f32 v; } *)D_001A4BE0)->v) < 0.57f) {
            (((struct { u8 pad[0xC00]; f32 v; } *)D_001A4BE0)->v) = 0.57f;
        }
        if (func_L01_0045D358(func_0039E928(0x40, 0), 8, 0, 0) != 0) {
            func_L23_004DF5A8(0x45, 1);
            break;
        }
        if (func_L01_0045D358(0x80, 9, 0, 0) != 0) {
            func_L23_004DF5A8(0x4D, 1);
            break;
        }
        if (((((struct { u8 pad[0x36E]; s16 v; } *)D_001A4BE0)->v) >= 5) && (((((struct { u8 pad[0x33C]; f32 v; } *)D_001A4BE0)->v) > 0.8f) || ((((struct { u8 pad[0x340]; f32 v; } *)D_001A4BE0)->v) > 0.87266463f))) {
            func_L23_004DF5A8(0x41, 1);
            break;
        }
        if (((((struct { u8 pad[0x36E]; s16 v; } *)D_001A4BE0)->v) == 0) && ((((struct { u8 pad[0x2838]; f32 v; } *)D_001A4BE0)->v) < 0.17f)) {
            func_L23_004DF5A8(0x3F, 1);
        }
        break;
    }
    case 0x42:
        if (((((struct { u8 pad[0x1B8]; s32 v; } *)D_001A4BE0)->v) >= 0x20) && ((((struct { u8 pad[0x36E]; s16 v; } *)D_001A4BE0)->v) != 0) && ((((struct { u8 pad[0x33C]; f32 v; } *)D_001A4BE0)->v) > 1.0f)) {
            func_L23_004DF5A8(0x41, 1);
            break;
        }
        if ((((struct { u8 pad[0x1B8]; s32 v; } *)D_001A4BE0)->v) >= 0x1a) {
            if ((((struct { u8 pad[0x2850]; s32 v; } *)D_001A4BE0)->v) <= 0) {
                func_L23_004DF5A8(0x43, 1);
            } else {
                func_L23_004DF5A8(0x3F, 0);
            }
        }
        break;
    case 0x46:
        if ((((struct { u8 pad[0xC08]; s32 v; } *)D_001A4BE0)->v) & 2) {
            func_L23_004DF5A8(0x47, 1);
        }
        break;
    case 0x47:
        func_L01_004EAA78(0, 1.0f);
        qcopy_4EAE60(v10, D_001A4BE0 + 0x80);
        if (func_L01_004E4550((s8 *)v10, (s8 *)(D_001A4BE0 + 0x90), 0) == 0) {
            func_L23_004DF5A8(0x41, 1);
            (((struct { u8 pad[0x1D0]; s16 v; } *)D_001A4BE0)->v) = 10;
            break;
        }
        if ((((((struct { u8 pad[0x2838]; f32 v; } *)D_001A4BE0)->v) > 0.5f) && (func_L01_0045D358(func_0039E928(0x40, 0), 9, 0, 0) != 0) && (func_00389468((((struct { u8 pad[0x1A0]; f32 v; } *)D_001A4BE0)->v), (((struct { u8 pad[0x98]; f32 v; } *)D_001A4BE0)->v)) > 2.3561945f)) || ((((struct { u8 pad[0x1A0]; s32 v; } *)D_001D52FC)->v) & func_0039E928(8, 0))) {
            func_L23_004DF5A8(0x41, 1);
            (((struct { u8 pad[0x1D0]; s16 v; } *)D_001A4BE0)->v) = 10;
            break;
        }
        if (func_L01_0045D358(func_0039E928(0x40, 0), 9, 0, 0) != 0) {
            func_L23_004DF5A8(0x48, 1);
            break;
        }
        if ((((struct { u8 pad[0x2838]; f32 v; } *)D_001A4BE0)->v) > 0.5f) {
            if (func_00389468((((struct { u8 pad[0x1A0]; f32 v; } *)D_001A4BE0)->v), func_00389380((((struct { u8 pad[0x98]; f32 v; } *)D_001A4BE0)->v), 1.5707964f)) < 0.7853982f) {
                qcopy_4EAE60(v20, D_001A4BE0 + 0x80);
                v20[0] += func_00388960(func_00389380((((struct { u8 pad[0x98]; f32 v; } *)D_001A4BE0)->v), 1.5707964f)) * 0.3f;
                v20[1] += func_00388978(func_00389380((((struct { u8 pad[0x98]; f32 v; } *)D_001A4BE0)->v), 1.5707964f)) * 0.3f;
                if (func_L01_004E4550((s8 *)v20, (s8 *)(D_001A4BE0 + 0x90), 0) != 0) {
                    func_L23_004DF5A8(0x49, 1);
                }
                break;
            }
        }
        if ((((struct { u8 pad[0x2838]; f32 v; } *)D_001A4BE0)->v) > 0.5f) {
            if (func_00389468((((struct { u8 pad[0x1A0]; f32 v; } *)D_001A4BE0)->v), func_00389380((((struct { u8 pad[0x98]; f32 v; } *)D_001A4BE0)->v), -1.5707964f)) < 0.7853982f) {
                qcopy_4EAE60(v20, D_001A4BE0 + 0x80);
                v20[0] += func_00388960(func_00389380((((struct { u8 pad[0x98]; f32 v; } *)D_001A4BE0)->v), -1.5707964f)) * 0.3f;
                v20[1] += func_00388978(func_00389380((((struct { u8 pad[0x98]; f32 v; } *)D_001A4BE0)->v), -1.5707964f)) * 0.3f;
                if (func_L01_004E4550((s8 *)v20, (s8 *)(D_001A4BE0 + 0x90), 0) != 0) {
                    func_L23_004DF5A8(0x4A, 1);
                }
            }
        }
        break;
    case 0x49:
    case 0x4A:
    {
        f32 side;
        qcopy_4EAE60(v10, D_001A4BE0 + 0x80);
        side = 1.5707964f;
        if ((((struct { u8 pad[0x25C4]; u32 v; } *)D_001A4BE0)->v) == 0x4A) {
            side = -1.5707964f;
        }
        v10[0] += func_00388960(func_00389380((((struct { u8 pad[0x98]; f32 v; } *)D_001A4BE0)->v), side)) * 0.3f;
        v10[1] += func_00388978(func_00389380((((struct { u8 pad[0x98]; f32 v; } *)D_001A4BE0)->v), side)) * 0.3f;
        func_L01_004EAA78(0, 1.0f);
        if (((((struct { u8 pad[0x2838]; f32 v; } *)D_001A4BE0)->v) < 0.5f) || (func_00389468((((struct { u8 pad[0x1A0]; f32 v; } *)D_001A4BE0)->v), func_00389380((((struct { u8 pad[0x98]; f32 v; } *)D_001A4BE0)->v), side)) > 0.7853982f) || (func_L01_004E4550((s8 *)v10, (s8 *)(D_001A4BE0 + 0x90), 0) == 0)) {
            if ((((struct { u8 pad[0xC08]; s32 v; } *)D_001A4BE0)->v) & 2) {
                func_L23_004DF5A8(0x47, 1);
                break;
            }
        }
        if (((((struct { u8 pad[0x2838]; f32 v; } *)D_001A4BE0)->v) > 0.5f) && (func_L01_0045D358(func_0039E928(0x40, 0), 9, 0, 0) != 0) && (func_00389468((((struct { u8 pad[0x1A0]; f32 v; } *)D_001A4BE0)->v), (((struct { u8 pad[0x98]; f32 v; } *)D_001A4BE0)->v)) > 2.3561945f)) {
            func_L23_004DF5A8(0x41, 1);
            (((struct { u8 pad[0x1D0]; s16 v; } *)D_001A4BE0)->v) = 0x28;
            break;
        }
        if (func_L01_0045D358(func_0039E928(0x40, 0), 9, 0, 0) != 0) {
            func_L23_004DF5A8(0x48, 1);
        }
        break;
    }
    case 0x5A:
        if ((((struct { u8 pad[0x1E0]; s16 v; } *)D_001A4BE0)->v) != 0) {
            return;
        }
        if ((((struct { u8 pad[0xC08]; s32 v; } *)D_001A4BE0)->v) & 2) {
            if ((((struct { u8 pad[0x43]; u8 v; } *)((((struct { u8 pad[0x25C0]; u8 * v; } *)D_001A4BE0)->v)))->v) != 0) {
                func_L01_0050BB98(0, 0, 12.0f);
            } else if ((((struct { u8 pad[0x1B8]; s32 v; } *)D_001A4BE0)->v) >= 0x33) {
                f32 r = func_0037E250(0.0f, 1.0f);
                if (r < 0.1f) {
                    func_L01_0050BB98(1, 0, 8.0f);
                } else if (r < 0.5f) {
                    func_L01_0050BB98(2, 0, 8.0f);
                }
            }
        }
        if (((((struct { u8 pad[0x1A0]; s32 v; } *)D_001D52FC)->v) & func_L01_0050EE20(func_0039E928(4, 0)))
            && (((((struct { u8 pad[0x25E4]; u8 v; } *)D_001A4BE0)->v) != 0) || (D_001439F4[0] != 2) || ((((struct { u8 pad[0x1228]; s32 v; } *)D_001A4BE0)->v) == 0x6F))
            && (func_L01_003E9428(0) == 0)) {
            func_L23_004DF5A8(1, 1);
            break;
        }
        if (func_L01_0045D358(func_0039E928(0x40, 0), 0xf, 0, 0) != 0) {
            func_L23_004DF5A8(0x5F, 1);
            break;
        }
        if (func_L01_0045D358(0x80, 0xf, 0, 0) != 0) {
            func_L23_004DF5A8(0x61, 1);
            break;
        }
        if ((func_L01_0045D358(0x10, 8, 0, 0) != 0) && ((((struct { u8 pad[0x1A98]; s32 v; } *)D_001A4BE0)->v) == 0) && (func_L23_00309720((((struct { u8 pad[0x25C0]; void * v; } *)D_001A4BE0)->v)) == 0)) {
            func_L23_004DF5A8(0x62, 1);
            break;
        }
        if (((((struct { u8 pad[0x36E]; s16 v; } *)D_001A4BE0)->v) != 0) && ((((struct { u8 pad[0x33C]; f32 v; } *)D_001A4BE0)->v) > 2.0f)) {
            func_L23_004DF5A8(0x5C, 1);
            break;
        }
        func_L01_004EAA78(0, 1.0f);
        if (((((struct { u8 pad[0x2838]; f32 v; } *)D_001A4BE0)->v) > 0.22f) && ((((struct { u8 pad[0x1B0]; f32 v; } *)D_001A4BE0)->v) > 0.0f)) {
            func_L23_004DF5A8(0x5B, 1);
        }
        break;
    case 0x5F:
    {
        s32 lo;
        s32 now;
        if ((((struct { u8 pad[0x46E]; u8 v; } *)D_001A4BE0)->v) != 0) {
            qcopy_4EAE60(v10, D_001A4BE0 + 0x80);
            v10[2] -= D_L23_001DBD0C * 1.5f;
            func_L01_00443648((((struct { u8 pad[0x25C0]; void * v; } *)D_001A4BE0)->v), v10, 0x90000, 0, 1, 0, D_L23_001DBD0C * 3.7f, 100.0f, 1.0f);
            if (((((struct { u8 pad[0x202]; s16 v; } *)D_001A4BE0)->v) != 0) && (func_L01_0045D358(func_0039E928(0x40, 0), 10, 0, 0) != 0)) {
                func_L23_004DF5A8(0x5F, 1);
                break;
            }
        }
        lo = (((struct { u8 pad[0x47C]; s16 v; } *)D_001A4BE0)->v);
        now = (((struct { u8 pad[0x1B8]; s32 v; } *)D_001A4BE0)->v);
        if (!(lo < now)) {
            break;
        }
        if ((now >= lo + 1) && ((((struct { u8 pad[0x180]; f32 v; } *)D_001A4BE0)->v) > 0.050000004f)) {
            func_L01_0050D770((f32 *)(D_001A4BE0 + 0x80), (f32 *)(D_001A4BE0 + 0xF0), &spA4, (((struct { u8 pad[0x4F0]; f32 v; } *)D_001A4BE0)->v));
            func_L01_004E1268((((struct { u8 pad[0x498]; f32 v; } *)D_001A4BE0)->v), (f32)spA4, (((struct { u8 pad[0x4E4]; f32 v; } *)D_001A4BE0)->v), 0.25f);
            break;
        }
        {
            u8 c = (((struct { u8 pad[0x46C]; u8 v; } *)D_001A4BE0)->v);
            if (c != 0) {
                (((struct { u8 pad[0x46C]; u8 v; } *)D_001A4BE0)->v) = c + 1;
            } else if (((((struct { u8 pad[0x36E]; s16 v; } *)D_001A4BE0)->v) == 0) && ((((struct { u8 pad[0x46E]; u8 v; } *)D_001A4BE0)->v) != 0)) {
                s32 k;
                (((struct { u8 pad[0x46C]; u8 v; } *)D_001A4BE0)->v) = 1;
                k = (s32)(((struct { u8 pad[0x4A0]; f32 v; } *)D_001A4BE0)->v) + 3;
                (((struct { u8 pad[0x20]; f32 v; } *)D_L23_001E1AC0)->v) = 0.15f;
                (((struct { u8 pad[0x28]; s32 v; } *)D_L23_001E1AC0)->v) = 0x1e;
                (((struct { u8 pad[0x2C]; s32 v; } *)D_L23_001E1AC0)->v) = 0;
                if ((((struct { u8 pad[0xC18]; f32 v; } *)D_001A4BE0)->v) < (((struct { u8 pad[0x49C]; f32 v; } *)D_001A4BE0)->v)) {
                    func_L01_0050BB98((((struct { u8 pad[0x43]; u8 v; } *)cur)->v), k, 5.0f);
                }
            }
        }
        if ((((struct { u8 pad[0x46C]; u8 v; } *)D_001A4BE0)->v) != 0) {
            (((struct { u8 pad[0xC00]; f32 v; } *)D_001A4BE0)->v) = 1.0f;
        } else if ((((struct { u8 pad[0x46E]; u8 v; } *)D_001A4BE0)->v) != 0) {
            if ((s32)(((struct { u8 pad[0x41]; u8 v; } *)cur)->v) < (s32)(((struct { u8 pad[0x49C]; f32 v; } *)D_001A4BE0)->v)) {
                s32 k;
                (((struct { u8 pad[0x47E]; s16 v; } *)D_001A4BE0)->v) = (s32)func_L01_0050C4A0(90.0f, (((struct { u8 pad[0x4F0]; f32 v; } *)D_001A4BE0)->v), -1.0f);
                func_L01_004E1268((((struct { u8 pad[0x49C]; f32 v; } *)D_001A4BE0)->v), (f32)(((struct { u8 pad[0x47E]; s16 v; } *)D_001A4BE0)->v), (((struct { u8 pad[0x4E4]; f32 v; } *)D_001A4BE0)->v), -1.0f);
                k = (s32)(((struct { u8 pad[0x4A0]; f32 v; } *)D_001A4BE0)->v) + 1;
                if ((((struct { u8 pad[0xC00]; f32 v; } *)D_001A4BE0)->v) > 1.8f) {
                    func_L01_0050BB98((((struct { u8 pad[0x43]; u8 v; } *)cur)->v), k, (f32)((((struct { u8 pad[0x47E]; s16 v; } *)D_001A4BE0)->v) + 2));
                }
                if ((((struct { u8 pad[0xC00]; f32 v; } *)D_001A4BE0)->v) < 0.2f) {
                    (((struct { u8 pad[0xC00]; f32 v; } *)D_001A4BE0)->v) = 0.2f;
                }
                if ((((struct { u8 pad[0xC00]; f32 v; } *)D_001A4BE0)->v) > 2.7f) {
                    (((struct { u8 pad[0xC00]; f32 v; } *)D_001A4BE0)->v) = 2.7f;
                }
            }
            if ((s32)(((struct { u8 pad[0xC18]; f32 v; } *)D_001A4BE0)->v) == (s32)(((struct { u8 pad[0x49C]; f32 v; } *)D_001A4BE0)->v)) {
                (((struct { u8 pad[0xC00]; s32 v; } *)D_001A4BE0)->v) = 0;
            }
        }
        if (((((struct { u8 pad[0x46C]; u8 v; } *)D_001A4BE0)->v) != 0) && ((((struct { u8 pad[0x1E0]; s16 v; } *)D_001A4BE0)->v) == 0) && (func_L01_0045D358(func_0039E928(0x40, 0), 4, 0, 0) != 0) && ((((struct { u8 pad[0x36E]; s16 v; } *)D_001A4BE0)->v) < 0xf)) {
            func_L01_004EAA78(0, 1.0f);
            func_L23_004DF5A8(0x5F, 1);
            break;
        }
        if ((((struct { u8 pad[0x46C]; u8 v; } *)D_001A4BE0)->v) >= 11) {
            (((struct { u8 pad[0x280C]; s32 v; } *)D_001A4BE0)->v) = 0;
            func_L01_004EAA78(0, 1.0f);
            if ((((struct { u8 pad[0xC08]; s32 v; } *)D_001A4BE0)->v) & 2) {
                func_L23_004DF5A8(0x5A, 1);
                break;
            }
            if ((((struct { u8 pad[0x46C]; u8 v; } *)D_001A4BE0)->v) >= 0xf) {
                func_L23_004DF5A8(0x5A, 1);
                break;
            }
            if (((((struct { u8 pad[0x1B0]; f32 v; } *)D_001A4BE0)->v) > D_L23_001DBE0C) && ((((struct { u8 pad[0x2838]; f32 v; } *)D_001A4BE0)->v) > 0.5f) && ((((struct { u8 pad[0x1E0]; s16 v; } *)D_001A4BE0)->v) == 0) && (func_00389468((((struct { u8 pad[0x1A0]; f32 v; } *)D_001A4BE0)->v), (((struct { u8 pad[0x98]; f32 v; } *)D_001A4BE0)->v)) < 1.5707964f)) {
                func_L23_004DF5A8(0x5B, 1);
            }
        }
        break;
    }
    case 0x5C:
        if ((((struct { u8 pad[0x46E]; u8 v; } *)D_001A4BE0)->v) != 0) {
            qcopy_4EAE60(v10, D_001A4BE0 + 0x80);
            v10[2] -= D_L23_001DBD0C;
            func_L01_00443648((((struct { u8 pad[0x25C0]; void * v; } *)D_001A4BE0)->v), v10, 0x30000, 0, 1, 0, D_L23_001DBD0C * 3.5f, 2.0f, 1.0f);
        }
        if (((((struct { u8 pad[0x202]; s16 v; } *)D_001A4BE0)->v) != 0) && (func_L01_0045D358(func_0039E928(0x40, 0), 10, 0, 0) != 0)) {
            func_L23_004DF5A8(0x5F, 1);
            break;
        }
        if ((((struct { u8 pad[0x36E]; s16 v; } *)D_001A4BE0)->v) != 0) {
            break;
        }
        if ((((struct { u8 pad[0x118]; f32 v; } *)D_001A4BE0)->v) < -0.15f) {
            (((struct { u8 pad[0x118]; f32 v; } *)D_001A4BE0)->v) = -0.15f;
        }
        if ((((struct { u8 pad[0xF8]; f32 v; } *)D_001A4BE0)->v) < -0.15f) {
            (((struct { u8 pad[0xF8]; f32 v; } *)D_001A4BE0)->v) = -0.15f;
        }
        (((struct { u8 pad[0x20]; f32 v; } *)D_L23_001E1AC0)->v) = 0.15f;
        (((struct { u8 pad[0x28]; s32 v; } *)D_L23_001E1AC0)->v) = 0x1e;
        (((struct { u8 pad[0x2C]; s32 v; } *)D_L23_001E1AC0)->v) = 0;
        if ((((struct { u8 pad[0x1A84]; s32 v; } *)D_001A4BE0)->v) <= 0) {
            func_L23_004DF5A8(0x63, 1);
            break;
        }
        if ((((struct { u8 pad[0x2838]; f32 v; } *)D_001A4BE0)->v) > 0.5f) {
            if ((((struct { u8 pad[0x1E0]; s16 v; } *)D_001A4BE0)->v) == 0) {
                func_L23_004DF5A8(0x5B, 1);
            } else {
                func_L23_004DF5A8(0x5A, 1);
            }
        } else {
            func_L23_004DF5A8(0x5A, 1);
        }
        break;
    case 0x61:
    {
        f32 top = 15.0f;
        if ((((struct { u8 pad[0x43]; u8 v; } *)((((struct { u8 pad[0x25C0]; u8 * v; } *)D_001A4BE0)->v)))->v) == 0xB) {
            top = 25.5f;
        }
        if (((((struct { u8 pad[0xC0C]; s32 v; } *)D_001A4BE0)->v) == 0) && ((((struct { u8 pad[0xC18]; f32 v; } *)D_001A4BE0)->v) > top) && ((((struct { u8 pad[0x1B8]; s32 v; } *)D_001A4BE0)->v) >= 0x15) && (func_L01_0045D358(0x80, 0x11, 0, 0) != 0)) {
            func_L23_004DF5A8(0x61, 1);
        }
        if ((((((struct { u8 pad[0xC18]; f32 v; } *)D_001A4BE0)->v) > 28.5f) && ((((struct { u8 pad[0xC0C]; s32 v; } *)D_001A4BE0)->v) == 0)) || ((((struct { u8 pad[0xC08]; s32 v; } *)D_001A4BE0)->v) & 2)) {
            func_L23_004DF5A8(0x5A, 0);
            break;
        }
        if (((((struct { u8 pad[0xC18]; f32 v; } *)D_001A4BE0)->v) > 19.0f) && ((((struct { u8 pad[0xC0C]; s32 v; } *)D_001A4BE0)->v) == 0) && ((((struct { u8 pad[0x2838]; f32 v; } *)D_001A4BE0)->v) > 0.75f)) {
            func_L23_004DF5A8(0x5B, 0);
            func_L01_0050BB98(3, 0x12, 11.0f);
        }
        break;
    }
    case 0x62:
        if ((((struct { u8 pad[0xC08]; s32 v; } *)D_001A4BE0)->v) & 2) {
            func_L23_004DF5A8(0x5A, 1);
            break;
        }
        if ((((struct { u8 pad[0xC0C]; s32 v; } *)D_001A4BE0)->v) != 0) {
            break;
        }
        if ((((struct { u8 pad[0xC18]; f32 v; } *)D_001A4BE0)->v) > 32.0f) {
            func_L23_004DF5A8(0x5A, 1);
        }
        break;
    case 0x5B:
        (((struct { u8 pad[0xC00]; f32 v; } *)D_001A4BE0)->v) = (((struct { u8 pad[0x170]; f32 v; } *)D_001A4BE0)->v) * 15.0f * D_L23_001DBD0C;
        if ((((struct { u8 pad[0xC00]; f32 v; } *)D_001A4BE0)->v) < 0.3f) {
            (((struct { u8 pad[0xC00]; f32 v; } *)D_001A4BE0)->v) = 0.3f;
        }
        if (func_L01_0045D358(func_0039E928(0x40, 0), 0xf, 0, 0) != 0) {
            func_L23_004DF5A8(0x5F, 1);
            break;
        }
        if (func_L01_0045D358(0x80, 8, 0, 0) != 0) {
            func_L23_004DF5A8(0x61, 1);
            break;
        }
        if ((func_L01_0045D358(0x10, 8, 0, 0) != 0) && ((((struct { u8 pad[0x1A98]; s32 v; } *)D_001A4BE0)->v) == 0)) {
            func_L23_004DF5A8(0x62, 1);
            break;
        }
        if (((((struct { u8 pad[0x36E]; s16 v; } *)D_001A4BE0)->v) >= 5) && (D_L23_001DBD0C * 1.5f < (((struct { u8 pad[0x33C]; f32 v; } *)D_001A4BE0)->v)) && ((D_L23_001DBD0C * 1.5f < (((struct { u8 pad[0x33C]; f32 v; } *)D_001A4BE0)->v)) || ((((struct { u8 pad[0x340]; f32 v; } *)D_001A4BE0)->v) > 0.87266463f))) {
            func_L23_004DF5A8(0x5C, 1);
            break;
        }
        if (((((struct { u8 pad[0x36E]; s16 v; } *)D_001A4BE0)->v) == 0) && ((((struct { u8 pad[0x2838]; f32 v; } *)D_001A4BE0)->v) < 0.17f) && ((((struct { u8 pad[0x1B8]; s32 v; } *)D_001A4BE0)->v) >= 0x15)) {
            func_L23_004DF5A8(0x5A, 1);
        }
        break;
    case 0x5D:
    case 0x5E:
    {
        s32 t;
        if (((((struct { u8 pad[0x202]; s16 v; } *)D_001A4BE0)->v) != 0) && (func_L01_0045D358(func_0039E928(0x40, 0), 10, 0, 0) != 0)) {
            func_L23_004DF5A8(0x5F, 1);
            break;
        }
        t = (((struct { u8 pad[0x1B8]; s32 v; } *)D_001A4BE0)->v);
        if (t >= 0xb5) {
            func_L23_004DF5A8(0x5A, 1);
            break;
        }
        if (((((struct { u8 pad[0x360]; s32 v; } *)D_001A4BE0)->v) != 0) && (t >= 0x1a)) {
            if ((((struct { u8 pad[0x1A84]; s32 v; } *)D_001A4BE0)->v) <= 0) {
                func_L23_004DF5A8(0x63, 1);
            } else {
                func_L23_004DF5A8(0x5A, 0);
            }
            break;
        }
        if (((((struct { u8 pad[0x1B8]; s32 v; } *)D_001A4BE0)->v) >= 0x1f) || ((((struct { u8 pad[0xC08]; s32 v; } *)D_001A4BE0)->v) & 2)) {
            if ((((struct { u8 pad[0x1A84]; s32 v; } *)D_001A4BE0)->v) <= 0) {
                func_L23_004DF5A8(0x63, 1);
            } else {
                func_L01_0050BB98(0xE, 0, 11.0f);
            }
        }
        break;
    }
    case 0x51:
        if ((((struct { u8 pad[0xC08]; s32 v; } *)D_001A4BE0)->v) & 2) {
            if ((((struct { u8 pad[0x43]; u8 v; } *)((((struct { u8 pad[0x25C0]; u8 * v; } *)D_001A4BE0)->v)))->v) != 1) {
                func_L01_0050BB98(1, 0, 12.0f);
            } else if (func_0037E250(0.0f, 1.0f) < 0.5f) {
                func_L01_0050BB98(2, 0, 8.0f);
            }
        }
        if (((((struct { u8 pad[0x1A0]; s32 v; } *)D_001D52FC)->v) & func_L01_0050EE20(func_0039E928(4, 0)))
            && (((((struct { u8 pad[0x25E4]; u8 v; } *)D_001A4BE0)->v) != 0) || (D_001439F4[0] != 2) || ((((struct { u8 pad[0x1228]; s32 v; } *)D_001A4BE0)->v) == 0x6F))
            && (func_L01_003E9428(0) == 0)) {
            func_L23_004DF5A8(1, 1);
            break;
        }
        if ((((struct { u8 pad[0x36E]; s16 v; } *)D_001A4BE0)->v) != 0) {
            func_L23_004DF5A8(0x53, 1);
            break;
        }
        if ((((struct { u8 pad[0x1E0]; s16 v; } *)D_001A4BE0)->v) != 0) {
            break;
        }
        if (func_L01_0045D358(func_0039E928(0x40, 0), 8, 0, 0) != 0) {
            func_L23_004DF5A8(0x54, 1);
            break;
        }
        if ((((struct { u8 pad[0x1A4]; s32 v; } *)D_001D52FC)->v) & 0x20) {
            func_L23_004DF5A8(0x59, 1);
            break;
        }
        if (func_L01_0045D358(0x80, 7, 0, 0) != 0) {
            if ((((struct { u8 pad[0x288C]; s16 v; } *)D_001A4BE0)->v) == 0) {
                (((struct { u8 pad[0x2888]; s16 v; } *)D_001A4BE0)->v) = 1;
                (((struct { u8 pad[0x288C]; s16 v; } *)D_001A4BE0)->v) = 0x12;
                (((struct { u8 pad[0x288A]; s16 v; } *)D_001A4BE0)->v) = 1;
            }
            func_L01_004E8830(0);
            break;
        }
        func_L01_004EAA78(0, 1.0f);
        if (!((((struct { u8 pad[0x2838]; f32 v; } *)D_001A4BE0)->v) > 0.22f)) {
            break;
        }
        if ((((struct { u8 pad[0x1B0]; f32 v; } *)D_001A4BE0)->v) > 0.0f) {
            func_L23_004DF5A8(0x52, 1);
        }
        break;
    case 0x57:
        if ((((struct { u8 pad[0x1B8]; s32 v; } *)D_001A4BE0)->v) >= 0x12d) {
            func_L01_004EA040();
        }
        if ((((struct { u8 pad[0x147C]; u8 v; } *)D_001A4BE0)->v) == 0) {
            if ((((struct { u8 pad[0x36E]; s16 v; } *)D_001A4BE0)->v) != 0) {
                func_L23_004DF5A8(0x53, 1);
            } else {
                func_L23_004DF5A8(0x51, 1);
            }
        }
        break;
    case 0x59:
        if (((((struct { u8 pad[0x1B8]; s32 v; } *)D_001A4BE0)->v) >= 0x2e) && !((((struct { u8 pad[0x1A0]; s32 v; } *)D_001D52FC)->v) & 0x20)) {
            func_L23_004DF5A8(0x51, 0);
            func_L01_0050BB98(1, 0, 20.0f);
            break;
        }
        if (func_L01_0045D358(func_0039E928(0x40, 0), 8, 0, 0) != 0) {
            func_L23_004DF5A8(0x54, 1);
        }
        break;
    case 0x58:
        (((struct { u8 pad[0x25ED]; u8 v; } *)D_001A4BE0)->v) = 1;
        break;
    case 0x54:
    {
        s16 lo = (((struct { u8 pad[0x47C]; s16 v; } *)D_001A4BE0)->v);
        s32 now = (((struct { u8 pad[0x1B8]; s32 v; } *)D_001A4BE0)->v);
        if (!(lo < now)) {
            break;
        }
        if (now == lo + 1) {
            func_L01_0050D770((f32 *)(D_001A4BE0 + 0x80), (f32 *)(D_001A4BE0 + 0xF0), &spA0, (((struct { u8 pad[0x4F0]; f32 v; } *)D_001A4BE0)->v));
            func_L01_004E1268((((struct { u8 pad[0x498]; f32 v; } *)D_001A4BE0)->v), (f32)spA0, (((struct { u8 pad[0x4E4]; f32 v; } *)D_001A4BE0)->v), 0.25f);
            break;
        }
        if (((((struct { u8 pad[0x46D]; u8 v; } *)D_001A4BE0)->v) != 0) && (now >= (((struct { u8 pad[0x400]; s32 v; } *)D_001A4BE0)->v)) && (now < (((struct { u8 pad[0x404]; s32 v; } *)D_001A4BE0)->v))) {
            f32 left = (f32)((((struct { u8 pad[0x410]; s32 v; } *)D_001A4BE0)->v) - (((struct { u8 pad[0x400]; s32 v; } *)D_001A4BE0)->v));
            if (left > 0.0f) {
                func_L01_004E1268((((struct { u8 pad[0x498]; f32 v; } *)D_001A4BE0)->v), left, (((struct { u8 pad[0x4E4]; f32 v; } *)D_001A4BE0)->v), -1.0f);
            }
            break;
        }
        {
            u8 c = (((struct { u8 pad[0x46C]; u8 v; } *)D_001A4BE0)->v);
            if (c != 0) {
                (((struct { u8 pad[0x46C]; u8 v; } *)D_001A4BE0)->v) = c + 1;
            } else if (((((struct { u8 pad[0x36E]; s16 v; } *)D_001A4BE0)->v) == 0) && ((((struct { u8 pad[0x46E]; u8 v; } *)D_001A4BE0)->v) != 0)) {
                s32 k;
                (((struct { u8 pad[0x46C]; u8 v; } *)D_001A4BE0)->v) = 1;
                k = (s32)(((struct { u8 pad[0x4A0]; f32 v; } *)D_001A4BE0)->v) + 3;
                if ((((struct { u8 pad[0xC18]; f32 v; } *)D_001A4BE0)->v) < (((struct { u8 pad[0x49C]; f32 v; } *)D_001A4BE0)->v)) {
                    func_L01_0050BB98((((struct { u8 pad[0x43]; u8 v; } *)cur)->v), k, 6.0f);
                }
            }
        }
        if ((((struct { u8 pad[0x46C]; u8 v; } *)D_001A4BE0)->v) != 0) {
            (((struct { u8 pad[0xC00]; f32 v; } *)D_001A4BE0)->v) = 1.0f;
        } else if ((((struct { u8 pad[0x46E]; u8 v; } *)D_001A4BE0)->v) != 0) {
            if ((s32)(((struct { u8 pad[0x41]; u8 v; } *)cur)->v) < (s32)(((struct { u8 pad[0x4A0]; f32 v; } *)D_001A4BE0)->v)) {
                s32 k;
                (((struct { u8 pad[0x47E]; s16 v; } *)D_001A4BE0)->v) = (s32)func_L01_0050C4A0(60.0f, (((struct { u8 pad[0x4F0]; f32 v; } *)D_001A4BE0)->v), -1.0f);
                func_L01_004E1268((((struct { u8 pad[0x49C]; f32 v; } *)D_001A4BE0)->v), (f32)(((struct { u8 pad[0x47E]; s16 v; } *)D_001A4BE0)->v), (((struct { u8 pad[0x4E4]; f32 v; } *)D_001A4BE0)->v), -1.0f);
                k = (s32)(((struct { u8 pad[0x4A0]; f32 v; } *)D_001A4BE0)->v) + 1;
                if ((((struct { u8 pad[0xC00]; f32 v; } *)D_001A4BE0)->v) > 1.8f) {
                    func_L01_0050BB98((((struct { u8 pad[0x43]; u8 v; } *)cur)->v), k, (f32)((((struct { u8 pad[0x47E]; s16 v; } *)D_001A4BE0)->v) + 2));
                }
                if ((((struct { u8 pad[0xC00]; f32 v; } *)D_001A4BE0)->v) < 0.2f) {
                    (((struct { u8 pad[0xC00]; f32 v; } *)D_001A4BE0)->v) = 0.2f;
                }
                if ((((struct { u8 pad[0xC00]; f32 v; } *)D_001A4BE0)->v) > 2.7f) {
                    (((struct { u8 pad[0xC00]; f32 v; } *)D_001A4BE0)->v) = 2.7f;
                }
            }
            if ((s32)(((struct { u8 pad[0xC18]; f32 v; } *)D_001A4BE0)->v) == (s32)(((struct { u8 pad[0x49C]; f32 v; } *)D_001A4BE0)->v)) {
                (((struct { u8 pad[0xC00]; s32 v; } *)D_001A4BE0)->v) = 0;
            }
        }
        if (((((struct { u8 pad[0x46C]; u8 v; } *)D_001A4BE0)->v) != 0) && ((((struct { u8 pad[0x1E0]; s16 v; } *)D_001A4BE0)->v) == 0) && ((((struct { u8 pad[0x147C]; u8 v; } *)D_001A4BE0)->v) == 0) && (func_L01_0045D358(func_0039E928(0x40, 0), 4, 0, 0) != 0) && ((((struct { u8 pad[0x36E]; s16 v; } *)D_001A4BE0)->v) < 4)) {
            func_L01_004EAA78(0, 1.0f);
            func_L23_004DF5A8(0x54, 1);
            break;
        }
        if ((((struct { u8 pad[0x46C]; u8 v; } *)D_001A4BE0)->v) >= 2) {
            (((struct { u8 pad[0x280C]; s32 v; } *)D_001A4BE0)->v) = 0;
            func_L01_004EAA78(0, 1.0f);
            if (((((struct { u8 pad[0x1B0]; f32 v; } *)D_001A4BE0)->v) > D_L23_001DBE0C) && ((((struct { u8 pad[0x2838]; f32 v; } *)D_001A4BE0)->v) > 0.5f) && ((((struct { u8 pad[0x147C]; u8 v; } *)D_001A4BE0)->v) == 0) && ((((struct { u8 pad[0x1E0]; s16 v; } *)D_001A4BE0)->v) == 0) && (func_00389468((((struct { u8 pad[0x1A0]; f32 v; } *)D_001A4BE0)->v), (((struct { u8 pad[0x98]; f32 v; } *)D_001A4BE0)->v)) < 1.5707964f)) {
                func_L23_004DF5A8(0x52, 1);
            } else if ((((struct { u8 pad[0x46C]; u8 v; } *)D_001A4BE0)->v) >= 0xd) {
                func_L23_004DF5A8(0x51, 1);
            }
        }
        if (((((struct { u8 pad[0x33C]; f32 v; } *)D_001A4BE0)->v) > 2.0f) && ((((struct { u8 pad[0x46E]; u8 v; } *)D_001A4BE0)->v) != 0) && ((((struct { u8 pad[0x1B8]; s32 v; } *)D_001A4BE0)->v) >= 0x29)) {
            func_L23_004DF5A8(0x53, 1);
        }
        break;
    }
    case 0x53:
        if ((((struct { u8 pad[0x36E]; s16 v; } *)D_001A4BE0)->v) == 0) {
            if ((((struct { u8 pad[0x118]; f32 v; } *)D_001A4BE0)->v) < -0.15f) {
                (((struct { u8 pad[0x118]; f32 v; } *)D_001A4BE0)->v) = -0.15f;
            }
            if ((((struct { u8 pad[0xF8]; f32 v; } *)D_001A4BE0)->v) < -0.15f) {
                (((struct { u8 pad[0xF8]; f32 v; } *)D_001A4BE0)->v) = -0.15f;
            }
            if ((((struct { u8 pad[0x2850]; s32 v; } *)D_001A4BE0)->v) <= 0) {
                func_L23_004DF5A8(0x56, 1);
            } else if (((((struct { u8 pad[0x2838]; f32 v; } *)D_001A4BE0)->v) > 0.5f) && ((((struct { u8 pad[0x1B8]; s32 v; } *)D_001A4BE0)->v) < 0x28) && ((((struct { u8 pad[0x1E0]; s16 v; } *)D_001A4BE0)->v) == 0)) {
                func_L23_004DF5A8(0x52, 1);
            } else {
                func_L23_004DF5A8(0x51, 0);
                func_L01_0050BB98(0x16, 0, -1.0f);
                (((struct { u8 pad[0xC00]; f32 v; } *)D_001A4BE0)->v) = 0.35f;
                (((struct { u8 pad[0x1E0]; s16 v; } *)D_001A4BE0)->v) = 0x14;
            }
        }
        break;
    case 0x52:
        (((struct { u8 pad[0xC00]; f32 v; } *)D_001A4BE0)->v) = (((struct { u8 pad[0x170]; f32 v; } *)D_001A4BE0)->v) * D_L23_001DBD50;
        if ((((struct { u8 pad[0xC00]; f32 v; } *)D_001A4BE0)->v) < 1.0f) {
            (((struct { u8 pad[0xC00]; f32 v; } *)D_001A4BE0)->v) = 1.0f;
        }
        if (((((struct { u8 pad[0x36E]; s16 v; } *)D_001A4BE0)->v) >= 5) && (((((struct { u8 pad[0x33C]; f32 v; } *)D_001A4BE0)->v) > 0.8f) || ((((struct { u8 pad[0x340]; f32 v; } *)D_001A4BE0)->v) > 0.87266463f))) {
            func_L23_004DF5A8(0x53, 1);
            break;
        }
        if ((((struct { u8 pad[0x1E0]; s16 v; } *)D_001A4BE0)->v) != 0) {
            func_L23_004DF5A8(0x51, 1);
        }
        if (func_L01_0045D358(func_0039E928(0x40, 0), 8, 0, 0) != 0) {
            func_L23_004DF5A8(0x54, 1);
            break;
        }
        if (func_L01_0045D358(0x80, 7, 0, 0) != 0) {
            if ((((struct { u8 pad[0x288C]; s16 v; } *)D_001A4BE0)->v) == 0) {
                (((struct { u8 pad[0x2888]; s16 v; } *)D_001A4BE0)->v) = 1;
                (((struct { u8 pad[0x288C]; s16 v; } *)D_001A4BE0)->v) = 0x12;
                (((struct { u8 pad[0x288A]; s16 v; } *)D_001A4BE0)->v) = 1;
            }
            func_L01_004E8830(0);
            break;
        }
        if ((((struct { u8 pad[0x1A4]; s32 v; } *)D_001D52FC)->v) & 0x20) {
            func_L23_004DF5A8(0x59, 1);
            break;
        }
        if (((((struct { u8 pad[0x36E]; s16 v; } *)D_001A4BE0)->v) == 0) && ((((struct { u8 pad[0x2838]; f32 v; } *)D_001A4BE0)->v) < 0.17f)) {
            func_L23_004DF5A8(0x51, 1);
        }
        break;
    case 0x55:
        if (((((struct { u8 pad[0x1B8]; s32 v; } *)D_001A4BE0)->v) >= 0x20) && ((((struct { u8 pad[0x36E]; s16 v; } *)D_001A4BE0)->v) != 0) && ((((struct { u8 pad[0x33C]; f32 v; } *)D_001A4BE0)->v) > 1.0f)) {
            func_L23_004DF5A8(0x53, 1);
            break;
        }
        if ((((struct { u8 pad[0xC08]; s32 v; } *)D_001A4BE0)->v) & 2) {
            func_L23_004DF5A8(0x51, 1);
            break;
        }
        if ((((struct { u8 pad[0x1B8]; s32 v; } *)D_001A4BE0)->v) >= 0x2e) {
            if ((((struct { u8 pad[0x2850]; s32 v; } *)D_001A4BE0)->v) <= 0) {
                func_L23_004DF5A8(0x56, 1);
            } else {
                func_L23_004DF5A8(0x51, 0);
            }
        }
        break;
    case 0x1D:
        if (((((struct { u8 pad[0x25E4]; u8 v; } *)D_001A4BE0)->v) == 0) && (((((struct { u8 pad[0x25EB]; u8 v; } *)D_001A4BE0)->v) == 0) || ((((struct { u8 pad[0x25E5]; u8 v; } *)D_001A4BE0)->v) != 0))) {
            if ((((struct { u8 pad[0x1A0]; s32 v; } *)D_001D52FC)->v) & func_0039E928(8, 0)) {
                func_L01_0050BB98(0xD, 0, 8.0f);
            } else {
                func_L01_0050BB98(func_L23_004BDA28(1), 0, 8.0f);
            }
        }
        if (!((((struct { u8 pad[0x1A0]; s32 v; } *)D_001D52FC)->v) & func_0039E928(4, 0))) {
            if ((((struct { u8 pad[0x25C4]; u32 v; } *)D_001A4BE0)->v) == 0x1D) {
                s32 anim;
                func_L23_004DF5A8(0, 0);
                anim = func_L23_004BDA28(1);
                if ((((struct { u8 pad[0x43]; u8 v; } *)((((struct { u8 pad[0x25C0]; u8 * v; } *)D_001A4BE0)->v)))->v) != anim) {
                    func_L01_0050BB98(anim, 0, 8.0f);
                }
            }
            D_L23_001D60F8_004E6F00 = 0;
        }
        break;
    case 0x22:
        if ((((struct { u8 pad[0xC18]; f32 v; } *)D_001A4BE0)->v) > 19.0f) {
            if (func_L01_0045D358(func_0039E928(0x40, 0), 11, 0, 0) != 0) {
                if ((((struct { u8 pad[0x1A0]; s32 v; } *)D_001D52FC)->v) & func_0039E928(8, 0)) {
                    func_L01_00502ED8();
                    break;
                }
                func_L23_004DF5A8(7, 1);
                break;
            }
        }
        if ((((struct { u8 pad[0xC18]; f32 v; } *)D_001A4BE0)->v) >= 21.0f) {
            func_L23_004DF5A8(0, 0);
        }
        break;
/*NEXT*/
    default:
        break;
    }
end:
    if (state0 != (((struct { u8 pad[0x25CC]; s32 v; } *)D_001A4BE0)->v)) {
        func_L01_004DD850();
    }
    {
        s32 prev = (((struct { u8 pad[0x25D0]; s32 v; } *)D_001A4BE0)->v);
        if (((prev == 0x3C) && ((((struct { u8 pad[0x25C4]; s32 v; } *)D_001A4BE0)->v) != 0x3D)) || ((prev == 0x3D) && ((((struct { u8 pad[0x1A04]; s32 v; } *)D_001A4BE0)->v) != 0))) {
            func_L01_005028C8();
        }
    }
    if (sub0 != (((struct { u8 pad[0x25C8]; s32 v; } *)D_001A4BE0)->v)) {
        (((struct { u8 pad[0x1C0]; s32 v; } *)D_001A4BE0)->v) = 0;
    }
    if (anim0 != (((struct { u8 pad[0x43]; u8 v; } *)cur)->v)) {
        (((struct { u8 pad[0x1C4]; s32 v; } *)D_001A4BE0)->v) = 0;
    }
}
/* localdecomp:end func_L23_004E6F00 */

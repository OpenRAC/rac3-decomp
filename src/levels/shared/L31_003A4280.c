#include "common.h"
#include "vu0.h"

INCLUDE_ASM("asm/levels", func_L31_003A4280);

/* localdecomp:start func_L31_003A4410 */
/* func_L31_003A4410: the vidcomic enemy's state machine (switch on the moby's state byte).
   Needs -mvu0-use-vf0-vf2 (vec_sub_ba/vec_add_ab in state 4) and --as ps2as (inline lui/ori float
   constants; the $gp floats then need their .extern size hints), plus the div.s nop row 2 2 2 0 2 1.
   Log: first draft with locals for &s->v180 / &a0->pos / &s->v160 gave other registers (no $s5);
   writing the expressions in place gave gcse's copies as retail has them. The query struct of
   state 4 is 0x30 bytes (frame 0xC0). Its store order is the scheduler's: equal-priority stores
   come out last-written first, and the load of s->b14 waits for the stores written before it. */
typedef int q_003A4410 __attribute__((mode(TI)));

typedef struct {
    u8 pad0[0x14];
    u8 b14;
    u8 pad15[0x50 - 0x15];
    u8 a50[0xB8 - 0x50];
    f32 fB8;
    u8 padBC[0xD0 - 0xBC];
    u8 aD0[0x138 - 0xD0];
    f32 f138;
    u8 pad13C[0x160 - 0x13C];
    f32 v160[4];
    u8 pad170[0x180 - 0x170];
    f32 v180[4];
    u8 pad190[0x1B0 - 0x190];
    s32 w1B0;
    u8 pad1B4[4];
    s32 w1B8;
    u8 pad1BC[4];
    s32 w1C0;
    u8 a1C4[4];
    s32 w1C8;
    s32 w1CC;
    f32 f1D0;
    s32 w1D4;
} Vars_003A4410;

typedef struct {
    u8 pad0[0x10];
    f32 pos[4];
    u8 state;
    u8 pad21[0x43 - 0x21];
    u8 b43;
    u8 pad44[4];
    f32 f48;
    u8 pad4C[0x60 - 0x4C];
    u8 b60;
    u8 pad61[0x68 - 0x61];
    Vars_003A4410 *vars;
    u8 pad6C[0x98 - 0x6C];
    s32 w98;
    u8 pad9C[0xAA - 0x9C];
    u16 hAA;
    u8 padAC[0xF8 - 0xAC];
    f32 fF8;
} Moby_003A4410;

typedef struct {
    u8 pad0[0x80];
    f32 pos[4];
} Player_003A4410;

typedef struct {
    u8 pad0[0x10];
    void *moby;
    s32 mask;
    u8 b18;
    u8 b19;
    u16 h1A;
    f32 f1C;
    u8 pad20[0x10];
} Query_003A4410;

extern Player_003A4410 D_001A4BE0_003A4410;
extern f32 D_001A4C60[4];

extern f32 D_L31_001DE958;
extern f32 D_L31_001DE95C;
extern f32 D_L31_001DE960;
extern f32 D_L31_001DE964;
extern f32 D_L31_001DE968;
extern f32 D_L31_001DE978;
extern f32 D_L31_001DE97C;
extern f32 D_L31_001DE988;
extern f32 D_L31_001DE99C;
extern f32 D_L31_001DE9B0;
extern s32 D_L31_001DE9B4;
extern f32 D_L31_001DE9BC;
extern f32 D_L31_001DE9C0;
extern f32 D_L31_001DE9C4;
extern f32 D_L31_001DE9C8;
extern f32 D_L31_001DE9CC;
extern s32 D_L31_001DE9D0;
extern f32 D_L31_001DE9D4;
extern f32 D_L31_001DE9D8;
extern f32 D_L31_001DE9E0;
extern f32 D_L31_001DE9E4;
extern f32 D_L31_001DE9E8;
extern f32 D_L31_001DE9EC;
extern f32 D_L31_001DE9F0;
extern f32 D_L31_001DE9F8;
extern f32 D_L31_001DE9FC;
extern f32 D_L31_001DEA04;
extern f32 D_L31_001DEA08;
extern f32 D_L31_001DEA0C;
extern f32 D_L31_001DEA10;
extern f32 D_L31_001DEA14;

__asm__(".extern D_L31_001DE958, 4");
__asm__(".extern D_L31_001DE95C, 4");
__asm__(".extern D_L31_001DE960, 4");
__asm__(".extern D_L31_001DE964, 4");
__asm__(".extern D_L31_001DE968, 4");
__asm__(".extern D_L31_001DE978, 4");
__asm__(".extern D_L31_001DE97C, 4");
__asm__(".extern D_L31_001DE988, 4");
__asm__(".extern D_L31_001DE99C, 4");
__asm__(".extern D_L31_001DE9B0, 4");
__asm__(".extern D_L31_001DE9B4, 4");
__asm__(".extern D_L31_001DE9BC, 4");
__asm__(".extern D_L31_001DE9C0, 4");
__asm__(".extern D_L31_001DE9C4, 4");
__asm__(".extern D_L31_001DE9C8, 4");
__asm__(".extern D_L31_001DE9CC, 4");
__asm__(".extern D_L31_001DE9D0, 4");
__asm__(".extern D_L31_001DE9D4, 4");
__asm__(".extern D_L31_001DE9D8, 4");
__asm__(".extern D_L31_001DE9E0, 4");
__asm__(".extern D_L31_001DE9E4, 4");
__asm__(".extern D_L31_001DE9E8, 4");
__asm__(".extern D_L31_001DE9EC, 4");
__asm__(".extern D_L31_001DE9F0, 4");
__asm__(".extern D_L31_001DE9F8, 4");
__asm__(".extern D_L31_001DE9FC, 4");
__asm__(".extern D_L31_001DEA04, 4");
__asm__(".extern D_L31_001DEA08, 4");
__asm__(".extern D_L31_001DEA0C, 4");
__asm__(".extern D_L31_001DEA10, 4");
__asm__(".extern D_L31_001DEA14, 4");

extern s32 func_L30_0034D8D8(void *, f32);
extern void func_L31_003478E8(void *, void *, void *, f32, f32, f32, f32, f32, f32, f32, s32);
extern u8 *func_L31_003A4280(u8 *, s32);
extern void func_L31_003A5110(u8 *a0);
extern int func_L31_003A5178(void *, f32 *);
extern void func_L31_003A5238(void *);
extern int func_L31_003A53F8(); /* defined below with its own Moby type */
extern void func_L31_003A5488(void *);
extern void func_L31_003A55A0(u8 *a0, s32 a1);
extern void func_L31_003A5818(u8 *a0, f32 a, f32 b, f32 c, f32 d);
extern s32 func_L31_003A5888(u8 *a0, f32 r);
extern void func_L31_003A5948(void *arg0);
extern void func_L31_003A5A88(u8 *a0);
extern f32 func_L31_003A5B00(void *, f32 *);
extern s32 func_L31_003A5B30(void *);
extern s32 func_003D3CB0(void *, void *, s32, void *, void *);
extern f32 func_0038CEA8(void *);
extern f32 func_0038CF00(void *, void *);
extern void func_0038CF68(void *, void *, f32);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern f32 func_0038DB00(f32, f32);
extern f32 func_0038DB48(f32);
extern void func_003C2880(void *);
extern void func_003C2F58(void *, s32, void *);
extern s32 func_00382380(void *, s32, s32);
extern f32 func_003824E0(f32, f32);
extern void func_003C3A10(void *, s32, s32, s32);
extern f32 func_003C4088(f32, f32, f32);
extern void func_L01_00448890(void *, void *, s32, f32, f32, f32, f32);
extern s32 func_L01_0044E1B8(void *, f32);
extern void func_L01_0044E850(void *, void *, s32, f32, f32);
extern s32 func_L01_004561B8(void *);
extern s32 func_L01_00456250(void *);

typedef void (*Fn5818_003A4410)(void *, void *, s32, f32, f32, f32, f32);

void func_L31_003A4410(Moby_003A4410 *a0) {
    Vars_003A4410 *s = a0->vars;

    if (a0->state == 0) {
        func_L31_003A5488(a0);
        if (s->w1C0 != 0) {
            func_L31_003A55A0((u8 *)a0, 13);
        } else {
            func_L31_003A5A88((u8 *)a0);
        }
    }
    func_L31_003A5238(a0);

    switch (a0->state) {
    case 1:
        func_L01_004561B8(a0);
        if (fabs_asm(a0->pos[0] - D_001A4BE0_003A4410.pos[0]) < D_L31_001DE9F8 &&
            fabs_asm(a0->pos[2] - D_001A4BE0_003A4410.pos[2]) < D_L31_001DE9F8 &&
            func_L31_003A5178(a0, D_001A4BE0_003A4410.pos) != 0) {
            func_L31_003A55A0((u8 *)a0, 4);
        }
        func_L31_003478E8(a0, a0->pos, s->v160, D_L31_001DE9BC, D_L31_001DE9B0, 0.0f, 0.0f, 1000.0f, 1.0f, 0.0f, 0);
        if (func_L31_003A5B30(a0) != 0) {
            func_L31_003A55A0((u8 *)a0, 2);
        }
        break;
    case 2:
        if (func_L01_004561B8(a0) != 0) {
            func_L31_003A5948(a0);
        }
        *(q_003A4410 *)s->v180 = *(q_003A4410 *)D_001A4C60;
        if (func_L31_003A5178(a0, s->v180) == 0) {
            func_L31_003A55A0((u8 *)a0, 12);
            break;
        }
        if (func_L31_003A5B30(a0) == 0 && s->w1D4 == 0) {
            func_L31_003A55A0((u8 *)a0, 1);
            break;
        }
        a0->f48 = D_L31_001DE9C0 * func_0038CEA8(s->v160) / D_L31_001DE9EC;
        ((Fn5818_003A4410)func_L31_003A5818)(a0, s->v180, 0, D_L31_001DE9F8, D_L31_001DE9EC, D_L31_001DE9E0, D_L31_001DE9E4);
        func_L31_003478E8(a0, a0->pos, s->v160, D_L31_001DE9BC, D_L31_001DE9B0, D_L31_001DE9EC, D_L31_001DE9EC, 1000.0f, 0.0f, D_L31_001DE9E8, 0);
        if (func_L31_003A53F8(a0) != 0) {
            func_L31_003A55A0((u8 *)a0, 4);
        }
        break;
    case 3:
        func_L01_004561B8(a0);
        func_L31_003478E8(a0, a0->pos, s->v160, D_L31_001DE9BC, D_L31_001DE9B0, 0.0f, 0.0f, 1000.0f, 1.0f, 0.0f, 0);
        if (func_L01_0044E1B8(a0, D_L31_001DE978) != 0) {
            func_L31_003A55A0((u8 *)a0, 4);
        }
        break;
    case 4: {
        f32 a[4] __attribute__((aligned(16)));
        f32 b[4] __attribute__((aligned(16)));
        f32 c[4] __attribute__((aligned(16)));
        Query_003A4410 qr __attribute__((aligned(16)));

        func_L01_004561B8(a0);
        func_L31_003478E8(a0, a0->pos, s->v160, D_L31_001DE9BC, D_L31_001DE9B0, 0.0f, 0.0f, 1000.0f, 1.0f, 0.0f, 0);
        qr.mask = 0x1010001;
        qr.moby = a0;
        qr.f1C = s->b14;
        qr.b18 = 3;
        qr.b19 = 2;
        qr.h1A = a0->hAA;
        qzero(&qr);
        func_003C2F58(a0, 3, a);
        func_003C2F58(a0, 0, b);
        vec_sub_ab(c, b, a);
        func_0038CF68(c, c, D_L31_001DE9FC);
        vec_add_ab(c, c, b);
        func_003D3CB0(b, c, 0x10, a0, &qr);
        if (func_L01_0044E1B8(a0, D_L31_001DE97C) == 0) {
            break;
        }
        if (func_L31_003A53F8(a0) != 0) {
            func_L31_003A55A0((u8 *)a0, 3);
        } else {
            func_L31_003A55A0((u8 *)a0, 11);
        }
        break;
    }
    case 66:
        if (func_L01_004561B8(a0) == 0) {
            break;
        }
        if (func_L30_0034D8D8(a0->pos, 1.0f) != 0) {
            func_L31_003A4280((u8 *)a0, -1);
        }
        func_003C2880(a0);
        return;
    case 5:
        if (func_L01_004561B8(a0) != 0) {
            a0->w98 = 0;
            func_L31_003478E8(a0, a0->pos, s->v160, D_L31_001DE9BC, D_L31_001DE9B0, 0.0f, 0.0f, 1000.0f, 0.0f, D_L31_001DE99C, 0);
        }
        func_L31_003478E8(a0, a0->pos, s->v160, D_L31_001DE9BC, D_L31_001DE9B0, 0.0f, 0.0f, 1000.0f, 0.0f, D_L31_001DE99C, 0);
        if (a0->b60 & 2) {
            func_L31_003A55A0((u8 *)a0, 66);
        }
        break;
    case 6:
        if (func_L01_004561B8(a0) != 0) {
            func_L31_003A5948(a0);
            if (func_0038CF00(a0->pos, s->v180) < D_L31_001DE968) {
                func_L31_003A5110((u8 *)a0);
            }
        }
        if (func_L31_003A5178(a0, s->v180) == 0) {
            func_L31_003A55A0((u8 *)a0, 12);
            break;
        }
        a0->f48 = D_L31_001DE9C0 * func_0038CEA8(s->v160) / D_L31_001DE9EC;
        ((Fn5818_003A4410)func_L31_003A5818)(a0, s->v180, 0, D_L31_001DE9F8, D_L31_001DE9EC, D_L31_001DE9E0, D_L31_001DE9E4);
        func_L31_003478E8(a0, a0->pos, s->v160, D_L31_001DE9BC, D_L31_001DE9B0, D_L31_001DE9EC, D_L31_001DE9EC, 1000.0f, 0.0f, D_L31_001DE9E8, 0);
        if (func_L31_003A53F8(a0) != 0) {
            func_L31_003A55A0((u8 *)a0, 4);
        }
        if (func_L31_003A5178(a0, D_001A4C60) == 0 || func_00382380(D_001A4C60, s->w1B0, 0) == 0) {
            func_L31_003A55A0((u8 *)a0, 8);
        }
        if (func_L31_003A5888((u8 *)a0, D_L31_001DE9F8) != 0) {
            func_L31_003A55A0((u8 *)a0, 5);
        }
        if (func_0038CF00(a0->pos, s->v180) < D_L31_001DE968) {
            func_L31_003A55A0((u8 *)a0, 8);
        }
        break;
    case 7:
        func_L01_004561B8(a0);
        func_L31_003478E8(a0, a0->pos, s->v160, D_L31_001DE9BC, D_L31_001DE9B0, 0.0f, 0.0f, 1000.0f, 1.0f, 0.0f, 0);
        if (a0->b60 & 2) {
            func_L31_003A5A88((u8 *)a0);
        }
        break;
    case 8:
        if (func_L01_004561B8(a0) != 0) {
            func_L31_003A5948(a0);
            if (func_0038CF00(a0->pos, s->v180) < D_L31_001DE968) {
                func_L31_003A5110((u8 *)a0);
            }
            s->w1CC = 0;
        }
        s->w1CC++;
        if (func_L31_003A5178(a0, s->v180) == 0) {
            func_L31_003A55A0((u8 *)a0, 12);
            break;
        }
        a0->f48 = D_L31_001DE9C0 * func_0038CEA8(s->v160) / D_L31_001DE9D8;
        ((Fn5818_003A4410)func_L31_003A5818)(a0, s->v180, 0, D_L31_001DE968, D_L31_001DE9D8, D_L31_001DE9C4, D_L31_001DE9C8);
        func_L31_003478E8(a0, a0->pos, s->v160, D_L31_001DE9BC, D_L31_001DE9B0, D_L31_001DE9D8, D_L31_001DE9D8, 1000.0f, 0.0f, D_L31_001DE9D4, 0);
        if (func_L31_003A53F8(a0) != 0) {
            func_L31_003A55A0((u8 *)a0, 3);
        }
        if (func_L31_003A5178(a0, D_001A4C60) != 0 && func_00382380(D_001A4C60, s->w1B0, 0) != 0) {
            func_L31_003A55A0((u8 *)a0, 6);
        }
        s->f138 = D_L31_001DE9CC * func_0038D0B0((f32)(s->w1CC % D_L31_001DE9D0) * 6.2831855f / (f32)D_L31_001DE9D0);
        if (func_L31_003A5888((u8 *)a0, D_L31_001DE9F8) != 0) {
            func_L31_003A55A0((u8 *)a0, 5);
        }
        if (func_0038CF00(a0->pos, s->v180) < D_L31_001DE968) {
            func_L31_003A55A0((u8 *)a0, 8);
        }
        break;
    case 9:
        func_L01_004561B8(a0);
        if (func_L31_003A53F8(a0) != 0) {
            func_L31_003A55A0((u8 *)a0, 3);
        }
        func_L31_003478E8(a0, a0->pos, s->v160, D_L31_001DE9BC, D_L31_001DE9B0, 0.0f, 0.0f, 1000.0f, 1.0f, 0.0f, 0);
        if (!(a0->b60 & 2)) {
            break;
        }
        if (D_L31_001DE9F0 < func_003824E0(0.0f, 1.0f)) {
            if (a0->b43 == 0) {
                break;
            }
            func_003C3A10(a0, 0, 0, D_L31_001DE9B4);
        } else {
            if (a0->b43 == 1) {
                break;
            }
            func_003C3A10(a0, 1, 0, D_L31_001DE9B4);
        }
        break;
    case 10:
        if (func_L01_004561B8(a0) != 0) {
            func_L31_003478E8(a0, a0->pos, s->v160, D_L31_001DE9BC, D_L31_001DE9B0, 0.0f, 0.0f, 1000.0f, 0.0f, D_L31_001DE988, 0);
        }
        func_L31_003478E8(a0, a0->pos, s->v160, D_L31_001DE9BC, D_L31_001DE9B0, 0.0f, 0.0f, 1000.0f, 0.0f, D_L31_001DE988, 0);
        if (a0->b60 & 2) {
            func_L31_003A5A88((u8 *)a0);
        }
        break;
    case 11:
        func_L01_004561B8(a0);
        func_L31_003478E8(a0, a0->pos, s->v160, D_L31_001DE9BC, D_L31_001DE9B0, 0.0f, 0.0f, 1000.0f, 1.0f, 0.0f, 0);
        if (!(a0->b60 & 2)) {
            break;
        }
        if (s->w1C8 == 1 && func_00382380(D_001A4C60, s->w1B0, 0) == 0) {
            func_L31_003A55A0((u8 *)a0, 7);
            break;
        }
        func_L31_003A5A88((u8 *)a0);
        break;
    case 12: {
        f32 ang;
        f32 spd;
        f32 len;
        f32 c;

        if (func_L01_004561B8(a0) != 0) {
            s->f1D0 = func_L31_003A5B00(a0, s->v180);
            s->v160[0] = 0.0f;
        }
        ang = func_0038DB00(s->f1D0, a0->fF8);
        if (D_L31_001DE960 < fabs_asm(ang)) {
            func_L01_00448890(&a0->fF8, s->a1C4, s->f1D0 == 0.0f ? 1 : -1, s->f1D0, D_L31_001DE958, D_L31_001DE95C, D_L31_001DE964);
            if (ang > 2.0943952f) {
                ang = 2.0943952f;
            } else if (ang < -2.0943952f) {
                ang = -2.0943952f;
            }
            s->fB8 = ang * 0.5f;
            s->f138 = ang * 0.4f;
        } else {
            func_L31_003A5A88((u8 *)a0);
        }
        if (s->w1C8 == 0) {
            spd = D_L31_001DE9EC;
        } else {
            spd = D_L31_001DE9D8;
        }
        len = func_0038CEA8(s->v160) / spd;
        c = func_0038D098(func_0038DB48(ang));
        if (c < 0.0f) {
            c = 0.0f;
        }
        a0->f48 = func_003C4088(len, D_L31_001DEA04, fabs_asm(ang) / 2.0943952f);
        spd = spd * fabs_asm(c);
        ((Fn5818_003A4410)func_L31_003A5818)(a0, s->v180, 0, D_L31_001DE968, D_L31_001DE9D8, D_L31_001DE9C4, D_L31_001DE9C8);
        if (spd < s->v160[0]) {
            s->v160[0] = spd;
        } else if (s->v160[0] < -spd) {
            s->v160[0] = -spd;
        }
        func_L31_003478E8(a0, a0->pos, s->v160, D_L31_001DE9BC, D_L31_001DE9B0, spd, 0.0f, 1000.0f, 1.0f, 0.0f, 0);
        break;
    }
    case 13:
        func_L01_004561B8(a0);
        if (func_L01_00456250(a0) != 0 || func_00382380(D_001A4C60, s->w1B8, 0) != 0) {
            func_L31_003A5A88((u8 *)a0);
        }
        func_L31_003478E8(a0, a0->pos, s->v160, D_L31_001DE9BC, D_L31_001DE9B0, 0.0f, 0.0f, 1000.0f, 1.0f, 0.0f, 0);
        break;
    }
    func_L01_0044E850(a0, s->a50, 1, D_L31_001DEA14, D_L31_001DEA10);
    func_L01_0044E850(a0, s->aD0, 2, D_L31_001DEA0C, D_L31_001DEA08);
}
/* localdecomp:end func_L31_003A4410 */

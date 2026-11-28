/* func_L01_004C0888 (Claude wave 14 r62, 2026-11-28). Replaces the earlier draft of this function (round 21 W5, written from the listing). */
/* PAL near miss (wave 14 r62): func_L01_004C0888, alone in src/levels/shared/L01_004C0888.c. Under the
 * file's line (-O2 -G8 -fopt-stack -mno-check-zero-division) every wording gives 380 differences: GNU as
 * turns li.s 0.62f into one gp-relative lwc1 where retail has Ps2EeAs's lui/ori/mtc1, which shifts every
 * later word by two. With @ps2as on the file's line (the file holds only this function, so the whole file
 * can take the existing line "-O2 -G8 -fopt-stack -mno-check-zero-division @ps2as"; no cut) this C gives
 * 16 differences (the earlier draft: 31, 22 once its vu0.h include and D_L01_002446C0 moved inside the
 * block and the thirteen func_L01_004BF4D0..004BF5F8 callees got their void(void) prototypes; implicit
 * int declarations moved the D_L01_001E0F80 loads from v0 to v1).
 * Changed against the draft: the block is self-contained (vu0.h, D_L01_002446C0, the callee prototypes),
 * the FA0 base is a pointer local f assigned first, and the matrix copy runs p, f[0] = p[1], r = p + 1,
 * f[2] = r[2], q = p - 0x150, f[1] = r[1], fE0 = p[0]: q now gets a0 as in retail.
 * Left (16): in the matrix save/clear block retail allocates r = p + 1 to v1 and the FA0 base to a1, the
 * r[2]/r[1] loads to a2/a3 and p[0] to v1; here the FA0 base is v1 and r a1 (local-alloc order), and the
 * FA0 lui is scheduled first. About 80 statement orders of the block (fRABceg, three zero orders, two
 * float-store orders) gave 16..22.
 */
#include "common.h"

/* localdecomp:start func_L01_004C0888 */
#include "vu0.h"
extern u8 D_L01_002446C0[0x780];
typedef int u128_004C0888 __attribute__((mode(TI)));
extern void func_00392350(s32);
extern void func_00388AF8(s32);
extern void func_003A92F0(s32);
extern s32 func_0012C908(s32);
extern void func_003A91D0(void);
extern void func_003A9150(void);
extern void func_L01_00404F00(s32);
extern void func_003861F0(void);
extern void func_0038CBA0(void *, s32);
extern void func_L01_004BF980(void);
extern void func_003873C0(void);
extern void func_L01_004C6030(s32, s32, s32);
extern void func_00389240(s32);
extern void func_00387F68(void);
extern void func_003C36C0(void);
extern void func_003C3638(void);
extern void func_003C3660(void);
extern void func_003A9440(s32, unsigned long);
extern void func_L01_004CB540(u8);
extern void func_L01_00478AA0(void);
extern void func_003B3158(s32);
extern void func_L01_00478AD8(void);
extern void func_L01_004C3448(void);
extern void func_L01_004BED50(void);
extern void func_L01_004BF948(void);
extern void func_003A9500(s32, s32, s32, s32);
extern void func_L01_00512BE0(s32, u8 *, u8 *, u8 *);
extern void func_003C3780(u8 *, s32);
extern void func_003C3690(void);
extern void func_003C3800(void);
extern void func_L01_004BEA70(void);
extern s32 func_003825F8(s32, s32, s32, s32, s32, s32);
extern unsigned long func_003C6F90(u8 *, u32, u32, u32, u32);
extern void func_00389370(void);
extern void func_L01_004BF518(void);
extern void func_L01_004BF538(void);
extern void func_L01_004BF5A0(void);
extern void func_L01_004BF5B8(void);
extern void func_L01_004BF4D0(void);
extern void func_L01_004BF5B0(void);
extern void func_L01_004BF5F8(void);
extern void func_L01_004BF4F8(void);
extern void func_L01_004BF578(void);
extern void func_L01_004BF558(void);
extern void func_L01_004BF5A8(void);
extern void func_L01_004BF5D8(void);
extern void func_L01_004BF4F0(void);
extern void func_003C31B0(void);
extern u8 D_L01_001E7580[];
extern s32 D_L01_001DF944;
extern s32 D_L01_001DF948;
extern s32 D_L01_001E1070;
extern u8 D_L01_001E29C0[];
extern u8 D_L01_001E2880[];
extern u8 D_L01_001E0FA0[];
extern s32 D_001A1ED4[];
extern s32 D_001D4BC0;
extern s32 D_001D4BC4;
extern f32 D_L01_001DAC50;
__asm__(".extern D_L01_001DAC50, 4");
extern f32 D_L01_001E0FD0;
extern s32 D_L01_001E0F80;

typedef struct {
    u8 p0[8];
    s32 f8;
    s32 fC;
    s32 f10;
    u8 *f14;
    u8 *f18;
    u8 pad1C[4];
    u8 *f20;
    u8 *f24;
    u8 *f28;
    u8 *f2C;
    u8 pad30[4];
    s32 f34;
    u8 pad38[4];
    u8 *f3C;
    u8 pad40[16];
    s32 f50;
    s32 f54;
    s32 f58;
    s32 pad5C;
    s32 f60;
    u8 pad64[36];
    u8 b88;
    u8 pad89[3];
    s32 f8C;
    s32 f90;
    u8 pad94[76];
    u8 fE0[16];
    u8 padF0[0x744 - 0xF0];
    s32 f744;
} M_004C0888;

void func_L01_004C0888(void) {
    s32 tab[4];
    M_004C0888 *s;
    M_004C0888 *t;
    M_004C0888 *u;
    M_004C0888 *w;
    u128_004C0888 *p;
    u8 *q;
    u128_004C0888 *r;
    u8 *g;
    u8 *g2;
    u128_004C0888 *f;
    s32 h;
    s32 i;
    func_00392350(0);
    s = (M_004C0888 *)D_L01_002446C0;
    i = s->f8;
    g = D_L01_001E7580;
    *(f32 *)(g + 0xB0) = 0.62f;
    switch (i) {
    case 0:
        if (s->fC != 0) {
            *(u16 *)(s->f28 + 0x34) |= 1;
        }
        D_L01_001DF944 = 0x100FF;
        if (s->fC != 0) {
            D_L01_001DF944 = 0x7F;
        }
        func_00388AF8(0);
        *(u16 *)(s->f28 + 0x34) &= 0xFFFE;
        if (s->fC == 0) {
            return;
        }
        s->f8 = 1;
        s->fC = 0;
        func_003A92F0(1);
        func_0012C908(0);
        D_L01_001DF948 = D_L01_001DF948 + 1;
        func_003A91D0();
        func_003A9150();
        D_L01_001E1070 = 0x60000;
        func_L01_00404F00(s->f10);
        if (s->f60 != 0) {
            f = (u128_004C0888 *)D_L01_001E0FA0;
            p = (u128_004C0888 *)(D_L01_001E29C0 + 0x10);
            f[0] = p[1];
            r = p + 1;
            f[2] = r[2];
            q = (u8 *)p - 0x150;
            f[1] = r[1];
            *(u128_004C0888 *)(s->fE0) = p[0];
            qzero(&p[1]);
            qzero(&p[2]);
            qzero(&p[3]);
            *(f32 *)(q + 0x160) = 1.0f;
            *(f32 *)(q + 0x174) = 1.0f;
            *(f32 *)(q + 0x188) = 1.0f;
            *(f32 *)(q + 0x18C) = 1.0f;
            func_003861F0();
        }
        s->f20 = s->f14;
        s->f24 = s->f14 + 0x800;
        s->f2C = s->f14 + 0x1000;
        s->f3C = s->f14 + 0x2400;
        func_0038CBA0(s->f3C, 0x400);
        s->f90 = 0;
        s->f8C = 0;
        s->f18 = s->f3C + 0x400;
        func_L01_004BF980();
    case 1:
    u = (M_004C0888 *)D_L01_002446C0;
    g2 = D_L01_001E7580;
    *(f32 *)(g2 + 0x238) = 255.0f;
    *(f32 *)(g2 + 0x23C) = 254.0f;
    func_003873C0();
    func_L01_004C6030(u->f10, D_001A1ED4[0], D_001D4BC4 << 11);
    func_00389240(0);
    func_003861F0();
    func_00387F68();
    if (D_L01_001DAC50 >= 1.0f && u->b88 != 0) {
        func_003C36C0();
        func_003C3638();
        func_003C3660();
    }
    func_003A9440(0x42, 0x8000000044UL);
    t = (M_004C0888 *)D_L01_002446C0;
    if (t->f50 == 0) {
        tab[0] = 0x13; tab[1] = 0x14; tab[2] = 0x15; tab[3] = 0x16;
    } else if (t->f50 == 3 || t->f50 == 5) {
        tab[0] = 0x17; tab[1] = 0x18; tab[2] = 0x19; tab[3] = 0x1A;
    } else if (t->f50 == 2) {
        tab[0] = 0x1B; tab[1] = 0x1C; tab[2] = 0x1D; tab[3] = 0x1E;
    }
    func_L01_004CB540(0);
    func_L01_00478AA0();
    func_003B3158(0);
    func_L01_00478AD8();
    if (D_L01_001DAC50 >= 1.0f) {
        w = (M_004C0888 *)D_L01_002446C0;
        if (w->f50 == 0) {
            func_L01_004BF518();
            func_L01_004C3448();
            if (D_L01_001E0F80 == 0) {
                func_L01_004BED50();
            }
            if (w->f744 != 0) {
                func_L01_004BF948();
            }
            if (w->b88 != 0) {
                func_003A9500(0x9E, 0x168, 0x73, 0xCE);
            }
        } else if (w->f50 == 3) {
            func_L01_004BF538();
            func_L01_004BF5A0();
            func_L01_004BF5B8();
            if (D_L01_001E0F80 == 0) {
                func_L01_004BF4D0();
            }
            if (w->b88 != 0) {
                func_003A9500(0, D_001D4BC0 - 1, 0, D_001D4BC4 - 1);
                func_L01_00512BE0((s32)w->f2C, w->f2C + 0x100, w->f2C + 0x200, w->f2C + 0x300);
                func_003C3780(w->f2C, w->f34);
                func_003C3690();
                func_003C3800();
            }
        } else if (w->f50 == 2) {
            func_L01_004BF5B0();
            func_L01_004BF5F8();
            if (D_L01_001E0F80 == 0) {
                func_L01_004BF4F8();
            }
            func_L01_004BEA70();
            if (w->b88 != 0) {
                func_003A9500(0x38, 0x1C3, (s32)(D_L01_001E0FD0 * 68.0f + 0.5f), (s32)(D_L01_001E0FD0 * 245.0f + 0.5f));
                h = func_003825F8(0xFFFFFF, 0x606060, 0x1E, 1, 0, 0);
                if (w->f54 != -1) {
                    func_003C6F90(w->f2C + (w->f54 << 8), h, 0xE, 0xE, 0);
                }
                if (w->f58 != -1) {
                    func_003C6F90(w->f2C + (w->f58 << 8), h, 0xE, 0xE, 0);
                }
                func_003C3780(w->f2C, w->f34);
                func_003C3690();
                func_003C3800();
                func_003A9500(0, D_001D4BC0 - 1, 0, D_001D4BC4 - 1);
                func_L01_004BF578();
            }
        } else if (w->f50 == 5) {
            func_L01_004BF558();
            func_L01_004BF5A8();
            func_L01_004BF5D8();
            if (D_L01_001E0F80 == 0) {
                func_L01_004BF4F0();
            }
            if (w->b88 != 0) {
                func_003A9500(0, D_001D4BC0 - 1, 0, D_001D4BC4 - 1);
                func_L01_00512BE0((s32)w->f2C, w->f2C + 0x100, w->f2C + 0x200, w->f2C + 0x300);
                func_003C3780(w->f2C, w->f34);
                func_003C3690();
                func_003C3800();
            }
        }
        func_003A9500(0, D_001D4BC0 - 1, 0, D_001D4BC4 - 1);
    }
    func_00389370();
    func_003A92F0(0x10);
    func_003C31B0();
    }
}
/* localdecomp:end func_L01_004C0888 */

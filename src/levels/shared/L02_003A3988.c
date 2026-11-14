#include "common.h"
#include "vu0.h"

typedef int u128_t __attribute__((mode(TI)));
typedef struct { u8 pad0[0x10]; s32 f10; u8 pad14[0x30]; u16 f44; } Own_003A3988;
typedef struct {
    u8 pad0[0x30];
    f32 f30;
    u8 pad34[0x10];
    u8 f44;
    u8 pad45[0x1A];
    u8 f5F;
    u8 pad60[0x100];
    u8 b160[0xC0];
    vu0_v4 v220;
    s32 f230;
    s16 f234;
    u8 pad236[0x9A];
    s32 f2D0;
    u8 pad2D4[2];
    s16 f2D6;
    s32 f2D8;
    s32 f2DC;
    vu0_v4 v2E0;
    vu0_v4 v2F0;
    s32 f300;
    u8 b304[0xC];
    f32 f310;
    s32 f314;
    u8 pad318[8];
    u8 b320[0x10];
} Dat_003A3988;
typedef struct {
    u8 pad0[0x10];
    vu0_v4 pos;
    u8 state;
    u8 pad21[3];
    Own_003A3988 *owner;
    u8 pad28[0xC];
    union { u16 w; u8 b0; } fl;
    u8 pad36[0xC];
    u8 f42;
    u8 f43;
    u8 pad44[4];
    f32 f48;
    u8 pad4C[0x14];
    u8 f60;
    u8 pad61[7];
    Dat_003A3988 *d;
    u8 pad6C[0x29];
    u8 mode;
    u16 f96;
    s32 f98;
    u8 pad9C[0x20];
    u8 fBC;
    u8 padBD[0x37];
    f32 fF4;
    f32 fF8;
} Obj_003A3988;
typedef struct {
    u8 pad0[0xD8];
    f32 fD8;
    u8 padDC[0x284];
    s32 f360;
    u8 pad364[0x225C];
    s32 f25C0;
} Glob_003A3988;

/* localdecomp:start func_L02_003A3988 */
#include "vu0.h"


extern s32 func_L02_003A49F0(void *);
extern void func_L02_003A5010(s32);
extern void func_L02_003A5030(void *);
extern void func_003C2880(void *);
extern void func_L01_004AA7E8(void *, s32);
extern void func_003A52A0(s32, s32, void *);
extern void func_0038CF68(void *, void *, f32);
extern void func_003C4C18(void *, f32);
extern f32 func_003824E0(f32, f32);
extern s32 func_00382498(s32, s32);
extern f32 func_00382538(void);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern s32 func_0038DBD8(f32, s32, s32);
extern void func_L01_004739D8(void *, void *, f32, s32, s32, s16, s32);
extern s32 func_L01_00463378(void *, void *, void *, s32, s32, s32, s32, s32, s32);
extern s32 func_L01_004561E0(void *);
extern s32 func_L01_004561B8(void *);
extern s32 func_0038CB00(void *);
extern void func_L01_004450F0(void *, s32, s32);
extern f32 func_003C4138(f32 *, f32, f32);
extern s32 func_L01_00454370(void *, void *);
extern f32 func_0038DAB8(f32, f32);
extern void func_003C3A10(void *, s32, s32, s32);
extern s32 func_L01_00456500(void *, s32);
extern void func_L01_0045BD78(void *, f32, f32, f32, f32);
extern void func_L01_0045A898(void *, void *, f32);
extern f32 func_0038D160(f32, f32);
extern void func_L01_00448890(void *, void *, f32, f32, f32, f32, s32);
extern f32 func_0038CF38(void *, void *);
extern void func_L01_00459188(void *, s32, void *);
extern void func_L01_00458F78(void *, void *, s32, s32);
extern void func_L01_0045A7A8(void *, void *, f32);
extern void func_L01_0045A748(void *, void *);
extern f32 func_L01_004395E0(void *);
extern void func_L01_0045BD10(void *, f32);
extern void func_L01_004468C8(void *, f32, f32, f32, s32, s32, s32, s32, s32);

__asm__(".extern D_L02_001D6694, 4");
__asm__(".extern D_L02_001DDCF0, 4");
__asm__(".extern D_L02_001DDD00, 4");
__asm__(".extern D_L02_001DDD04, 4");
__asm__(".extern D_L02_001DDD14, 4");
__asm__(".extern D_L02_001DDCF4, 4");
__asm__(".extern D_L02_001DDD10, 4");
__asm__(".extern D_L02_001DDD08, 4");
__asm__(".extern D_L02_001DDD0C, 4");
__asm__(".extern D_L02_001DDCF8, 4");
__asm__(".extern D_L02_001DDCFC, 4");
__asm__(".extern D_L02_001DDCA4, 4");
__asm__(".extern D_L02_001DDCAC, 4");
__asm__(".extern D_L02_001DDCB8, 4");
__asm__(".extern D_L02_001DDCBC, 4");
__asm__(".extern D_L02_001DDCC0, 4");
__asm__(".extern D_L02_001DDCC4, 4");
__asm__(".extern D_L02_001DDCE8, 4");
__asm__(".extern D_L02_001DDCC8, 4");
__asm__(".extern D_L02_001DDCA8, 4");
__asm__(".extern D_L02_001DDCCC, 4");
__asm__(".extern D_L02_001DDCD0, 4");
__asm__(".extern D_L02_001DDCB0, 4");
__asm__(".extern D_L02_001DDCB4, 4");
__asm__(".extern D_L02_001DDCD4, 4");
__asm__(".extern D_L02_001DDCDC, 4");
__asm__(".extern D_L02_001DDCE0, 4");
__asm__(".extern D_L02_001DDCD8, 4");
__asm__(".extern D_L02_001DDCEC, 4");
__asm__(".extern D_L02_001DDCE4, 4");
extern Glob_003A3988 D_001A4BE0;
extern s32 D_L02_001D6694;
extern s32 D_L02_001DDCF0;
extern f32 D_L02_001DDD00;
extern f32 D_L02_001DDD04;
extern f32 D_L02_001DDD14;
extern f32 D_L02_001DDCF4;
extern f32 D_L02_001DDD10;
extern f32 D_L02_001DDD08;
extern f32 D_L02_001DDD0C;
extern s32 D_L02_001DDCF8;
extern s32 D_L02_001DDCFC;
extern s32 D_L02_001DDCA4;
extern f32 D_L02_001DDCAC;
extern f32 D_L02_001DDCB8;
extern f32 D_L02_001DDCBC;
extern f32 D_L02_001DDCC0;
extern f32 D_L02_001DDCC4;
extern s32 D_L02_001DDCE8;
extern f32 D_L02_001DDCC8;
extern s32 D_L02_001DDCA8;
extern f32 D_L02_001DDCCC;
extern f32 D_L02_001DDCD0;
extern f32 D_L02_001DDCB0;
extern f32 D_L02_001DDCB4;
extern s32 D_L02_001DDCD4;
extern s32 D_L02_001DDCDC;
extern s32 D_L02_001DDCE0;
extern s32 D_L02_001DDCD8;
extern s32 D_L02_001DDCEC;
extern s32 D_L02_001DDCE4;

void func_L02_003A3988(Obj_003A3988 *self) {
    Dat_003A3988 *d;
    vu0_v4 axis, a, b, c;
    s32 i, k, j, r, s16v, s17v;
    f32 f20, f21;
    f32 *rot;
    f32 ang;

    d = self->d;
    if (func_L02_003A49F0(self) != 0) {
        func_003C2880(self);
        return;
    }
    if (D_L02_001D6694 == 2) {
        if ((self->fl.b0 ^ 1) & 1) {
            self->f98 = 0;
            self->fl.w = (self->fl.w | 0x41) & 0xEFFF;
            func_L01_004AA7E8(self, 1);
            d->f314 = 1;
        }
        return;
    }
    if (d->f314 != 0) {
        self->fl.w &= 0xFFBE;
        self->fl.w |= self->owner->f44 & 0x1000;
        self->f98 = self->owner->f10;
        d->f314 = 0;
    }
    if (d->f30 <= 0.0f && self->mode != 3) {
        func_L02_003A5010((s32)self);
        func_003A52A0(3, 0, self);
        {
            s32 i, k, j;
            *(u128_t *)&axis = 0;
            axis.z = 1.0f;
            for (i = 0; i < D_L02_001DDCF0; i++) {
                func_0038CF68(&a, &axis, func_003824E0(D_L02_001DDD00, D_L02_001DDD04) * 0.020000001f);
                func_003C4C18(&a, D_L02_001DDD14 * 0.020000001f);
                func_0038CF68(&b, &axis, D_L02_001DDCF4);
                vec_add_ab(&b, &b, &self->pos);
                func_003C4C18(&b, D_L02_001DDD10);
                f20 = func_003824E0(D_L02_001DDD08, D_L02_001DDD0C) * 210000.0f;
                func_L01_004739D8(&b, &a, f20, D_L02_001DDCF8, D_L02_001DDCFC, (func_00382498(120, 240) * 5 + 2) / 6, 0);
            }
            for (k = 0; k < D_L02_001DDCA4; k++) { f32 ang2, hgt, rad;
                a = self->pos;
                func_003C4C18(&a, D_L02_001DDCAC);
                ang2 = func_00382538();
                rad = func_003824E0(D_L02_001DDCB8, D_L02_001DDCBC);
                hgt = func_003824E0(D_L02_001DDCC0, D_L02_001DDCC4);
                rad = rad * 0.020000001f;
                qzero(&b);
                b.x += func_0038D098(ang2) * rad;
                b.y += func_0038D0B0(ang2) * rad;
                b.z += hgt * 0.020000001f;
                c = b;
                c.z -= D_L02_001DDCC8 * 0.00040000002f * (f32)((D_L02_001DDCE8 * 5 + 2) / 6);
                for (j = 0; j < D_L02_001DDCA8; j++) {
                    f32 r1, r2;
                    r1 = func_003824E0(0.5f, 1.5f);
                    b.w = r1 * D_L02_001DDCCC;
                    c.w = r1 * D_L02_001DDCD0;
                    func_003C4C18(&a, D_L02_001DDCB0);
                    func_003C4C18(&c, D_L02_001DDCB4 * 0.020000001f);
                    s16v = func_0038DBD8(func_003824E0(0.0f, 1.0f), D_L02_001DDCD4, D_L02_001DDCDC);
                    s17v = func_0038DBD8(func_003824E0(0.0f, 1.0f), D_L02_001DDCD8, D_L02_001DDCE0);
                    r2 = func_003824E0((f32)D_L02_001DDCEC * 0.5f, (f32)D_L02_001DDCEC * 2.5f);
                    func_L01_00463378(&a, &b, &c, s16v, s17v, (D_L02_001DDCE4 * 5 + 2) / 6,
                                      (D_L02_001DDCE8 * 5 + 2) / 6, (s32)((r2 * 5.0f + 2.0f) / 6.0f), -1);
                }
            }
        }
        func_003C2880(self);
        return;
    }
    switch (self->mode) {
    case 0:
        if (func_L01_004561E0(self) != 0) {
            d->f2D6 = (func_00382498(0, 30) * 5 + 2) / 6;
        }
        if (d->f234 == 1) {
            if (func_0038CB00(&d->f2D6) != 0) {
                func_L01_004450F0(self, 3, 2);
                break;
            }
        }
        if (d->f2D8 != 0) {
            if (func_0038CB00(&d->f2D6) != 0) {
                func_L01_004450F0(self, 2, 1);
                d->f2D8 = 0;
                if (d->f2D0 < 250) {
                    d->f2D0 = (func_00382498(480, 600) * 5 + 2) / 6;
                }
            }
        }
        break;
    case 1:
        if (d->f234 == 1) {
            func_L01_004450F0(self, 3, 2);
            break;
        }
        if (d->f2D0 == 0) {
            func_L01_004450F0(self, 1, 0);
        }
        break;
    case 2:
        if (d->f230 == D_001A4BE0.f25C0) {
            if (D_001A4BE0.f360 != 0) {
                func_003C4138(&self->pos.z, D_001A4BE0.fD8, 0.060000002f);
            }
        } else {
            func_003C4138(&self->pos.z, d->v220.z, 0.020000001f);
        }
        if (d->f234 != 1) {
            if (func_L01_004561E0(self) == 0) {
                func_L01_004450F0(self, 1, 0);
                if (self->f43 != 1) {
                    func_003C3A10(self, 1, 0, 0);
                }
                d->f2D0 = (func_00382498(580, 600) * 5 + 2) / 6;
            }
        }
        break;
    case 3:
        r = func_L01_00454370(self, d->b160);
        if (d->f30 <= 0.0f) {
            self->fF4 = func_0038DAB8(self->fF4, 0.6981317f);
            if (self->fBC == 0) {
                func_003A52A0(3, 0, self);
                self->fBC = 1;
            }
        }
        if (r & 1) {
            func_L02_003A5010((s32)self);
            {
                s32 i, k, j;
                *(u128_t *)&axis = 0;
                axis.z = 1.0f;
                for (i = 0; i < D_L02_001DDCF0; i++) {
                    func_0038CF68(&a, &axis, func_003824E0(D_L02_001DDD00, D_L02_001DDD04) * 0.020000001f);
                    func_003C4C18(&a, D_L02_001DDD14 * 0.020000001f);
                    func_0038CF68(&b, &axis, D_L02_001DDCF4);
                    vec_add_ab(&b, &b, &self->pos);
                    func_003C4C18(&b, D_L02_001DDD10);
                    f20 = func_003824E0(D_L02_001DDD08, D_L02_001DDD0C) * 210000.0f;
                    func_L01_004739D8(&b, &a, f20, D_L02_001DDCF8, D_L02_001DDCFC, (func_00382498(120, 240) * 5 + 2) / 6, 0);
                }
                for (k = 0; k < D_L02_001DDCA4; k++) { f32 ang2, hgt, rad;
                    a = self->pos;
                    func_003C4C18(&a, D_L02_001DDCAC);
                    ang2 = func_00382538();
                    rad = func_003824E0(D_L02_001DDCB8, D_L02_001DDCBC);
                    hgt = func_003824E0(D_L02_001DDCC0, D_L02_001DDCC4);
                    rad = rad * 0.020000001f;
                    qzero(&b);
                    b.x += func_0038D098(ang2) * rad;
                    b.y += func_0038D0B0(ang2) * rad;
                    b.z += hgt * 0.020000001f;
                    c = b;
                    c.z -= D_L02_001DDCC8 * 0.00040000002f * (f32)((D_L02_001DDCE8 * 5 + 2) / 6);
                    for (j = 0; j < D_L02_001DDCA8; j++) {
                        f32 r1, r2;
                        r1 = func_003824E0(0.5f, 1.5f);
                        b.w = r1 * D_L02_001DDCCC;
                        c.w = r1 * D_L02_001DDCD0;
                        func_003C4C18(&a, D_L02_001DDCB0);
                        func_003C4C18(&c, D_L02_001DDCB4 * 0.020000001f);
                        s16v = func_0038DBD8(func_003824E0(0.0f, 1.0f), D_L02_001DDCD4, D_L02_001DDCDC);
                        s17v = func_0038DBD8(func_003824E0(0.0f, 1.0f), D_L02_001DDCD8, D_L02_001DDCE0);
                        r2 = func_003824E0((f32)D_L02_001DDCEC * 0.5f, (f32)D_L02_001DDCEC * 2.5f);
                        func_L01_00463378(&a, &b, &c, s16v, s17v, (D_L02_001DDCE4 * 5 + 2) / 6,
                                          (D_L02_001DDCE8 * 5 + 2) / 6, (s32)((r2 * 5.0f + 2.0f) / 6.0f), -1);
                    }
                }
            }
            func_003C2880(self);
            return;
        } else if (r & 2) {
            if (d->f234 == 1) {
                func_L01_004450F0(self, 3, 2);
            } else {
                func_L01_004450F0(self, 2, 1);
                d->f2D0 = (func_00382498(580, 600) * 5 + 2) / 6;
            }
        }
        break;
    }
    switch (self->state) {
    case 2:
        break;
    case 1:
        if (func_L01_004561B8(self) != 0) {
            f20 = func_00382538();
            f21 = func_003824E0(1.0f, 3.0f);
            qzero(&d->v2F0);
            d->v2F0.x = func_0038D098(f20) * f21;
            d->v2F0.y = func_0038D0B0(f20) * f21;
            vec_add_ab(&d->v2F0, &d->v2F0, &d->v2E0);
            if (d->f300 != -1 && func_L01_00456500(&d->v2F0, d->f300) == 0) {
                d->v2F0 = d->v2E0;
            }
            d->f2DC = func_00382498(300, 530);
            func_L01_0045BD78(self, 0.0064000003f, 0.120000005f, 0.005585054f, 0.34906587f);
        }
        func_L01_0045A898(self, &d->v2F0, self->fF8);
        rot = &self->fF8;
        ang = func_0038D160(d->v2F0.x - self->pos.x, d->v2F0.y - self->pos.y);
        func_L01_00448890(rot, d->b304, ang, 0.005585054f, 0.005585054f, 0.34906587f, 0);
        if (func_0038CF38(&self->pos, &d->v2F0) < 0.75f) {
            f20 = func_00382538();
            f21 = func_003824E0(1.0f, 3.0f);
            qzero(&d->v2F0);
            d->v2F0.x = func_0038D098(f20) * f21;
            d->v2F0.y = func_0038D0B0(f20) * f21;
            vec_add_ab(&d->v2F0, &d->v2F0, &d->v2E0);
            if (d->f300 != -1 && func_L01_00456500(&d->v2F0, d->f300) == 0) {
                d->v2F0 = d->v2E0;
            }
        }
        break;
    case 3:
        if (func_L01_004561B8(self) != 0) {
            func_L01_00459188(self, d->f230, d->b320);
            func_L01_0045BD78(self, 0.0068000006f, 0.14000002f, 0.010053097f, 0.25132743f);
        }
        func_L01_00458F78(self, d->b320, 0, 0);
        func_L01_0045A7A8(self, d->b320, d->f310);
        if (func_0038CF38(&self->pos, &d->v220) < 1.3f) {
            if (self->f43 != 3) {
                func_003C3A10(self, 3, 0, 5);
            }
            func_L01_004450F0(self, 4, -1);
        }
        break;
    case 5:
        if (func_L01_004561B8(self) != 0) {
            vec_sub_ba(&axis, &self->pos, &d->v220);
            func_0038CF68(&axis, &axis, func_003824E0(4.0f, 5.0f));
            vec_add_ab(&d->v2F0, &self->pos, &axis);
        }
        func_L01_0045A748(self, &d->v2F0);
        if (func_0038CF38(&self->pos, &d->v2F0) < 0.5f || self->f96 >= 0x79) {
            func_L01_004450F0(self, 3, -1);
        }
        break;
    case 4:
        func_L01_0045BD78(self, 0.0192f, 0.36f, 0.010053097f, 0.25132743f);
        if (func_0038CF38(&self->pos, &d->v220) > 1.2f && self->f42 == 3 && func_L01_004395E0(self) > 8.0f) {
            self->f48 = 1.0f;
        } else if (self->f42 == 3) {
            func_L01_004395E0(self);
        }
        func_L01_0045BD10(self, func_0038D160(d->v220.x - self->pos.x, d->v220.y - self->pos.y));
        self->f48 = 1.0f;
        if (d->f5F != 0) {
            func_L01_004468C8(self, 0.5f, (f32)d->f44, 1.0f, 0, 0x10001, 0, 1, 0);
        } else {
            func_L01_004468C8(self, 0.5f, (f32)d->f44, 1.0f, 0, 1, 0, 1, 0);
        }
        if (self->f60 & 2) {
            if (self->f43 != 1) {
                func_003C3A10(self, 1, 0, 5);
            }
            func_L01_004450F0(self, 5, -1);
            func_L01_0045BD78(self, 0.0064000003f, 0.120000005f, 0.010053097f, 0.25132743f);
            if (d->f230 != D_001A4BE0.f25C0) {
                func_L01_004450F0(self, 3, -1);
            }
        }
        break;
    }
    func_L02_003A5030(self);
}
/* localdecomp:end func_L02_003A3988 */

INCLUDE_ASM("asm/levels", func_L02_003A49F0);

INCLUDE_ASM("asm/levels", func_L02_003A4CC0);

/* localdecomp:start func_L02_003A5010 */
void func_L01_004443E8(s32, s32, s32);
void func_L02_003A5010(s32 arg0) {
    func_L01_004443E8(arg0, 0, 3);
}
/* localdecomp:end func_L02_003A5010 */

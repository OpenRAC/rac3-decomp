#include "common.h"

/* NTSC-U counterpart of func_L02_003A3988 (src/levels/shared/L02_003A3988.c) */
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

/* localdecomp:start func_L02_003A1BA8 */
#include "vu0.h"


extern s32 func_L02_003A2AD8(void *);
extern void func_L02_003A30F0(s32);
extern void func_L02_003A3110(void *);
extern void func_003BD360(void *);
extern void func_L01_004A6DF8(void *, s32);
extern void func_0039FE80(s32, s32, void *);
extern void func_00388830(void *, void *, f32);
extern void func_003BF6A8(void *, f32);
extern f32 func_0037E250(f32, f32);
extern s32 func_0037E208(s32, s32);
extern f32 func_0037E2A8(void);
extern f32 func_00388960(f32);
extern f32 func_00388978(f32);
extern s32 func_003894A0(f32, s32, s32);
extern void func_L01_00470258(void *, void *, f32, s32, s32, s16, s32);
extern s32 func_L01_0045FEC8(void *, void *, void *, s32, s32, s32, s32, s32, s32);
extern s32 func_L01_00452EF0(void *);
extern s32 func_L01_00452EC8(void *);
extern s32 func_003883C8(void *);
extern void func_L01_00441FB8(void *, s32, s32);
extern f32 func_003BEBF8(f32 *, f32, f32);
extern s32 func_L01_00451078(void *, void *);
extern f32 func_00389380(f32, f32);
extern void func_003BE4F0(void *, s32, s32, s32);
extern s32 func_L01_00453210(void *, s32);
extern void func_L01_00458A70(void *, f32, f32, f32, f32);
extern void func_L01_00457590(void *, void *, f32);
extern f32 func_00388A28(f32, f32);
extern void func_L01_00445758(void *, void *, f32, f32, f32, f32, s32);
extern f32 func_00388800(void *, void *);
extern void func_L01_00455E98(void *, s32, void *);
extern void func_L01_00455C88(void *, void *, s32, s32);
extern void func_L01_004574A0(void *, void *, f32);
extern void func_L01_00457440(void *, void *);
extern f32 func_L01_00436500(void *);
extern void func_L01_00458A08(void *, f32);
extern void func_L01_00443790(void *, f32, f32, f32, s32, s32, s32, s32, s32);

__asm__(".extern D_L02_001D6694_003A1BA8, 4");
__asm__(".extern D_L02_001DDD30, 4");
__asm__(".extern D_L02_001DDD40, 4");
__asm__(".extern D_L02_001DDD44, 4");
__asm__(".extern D_L02_001DDD54, 4");
__asm__(".extern D_L02_001DDD34, 4");
__asm__(".extern D_L02_001DDD50, 4");
__asm__(".extern D_L02_001DDD48, 4");
__asm__(".extern D_L02_001DDD4C, 4");
__asm__(".extern D_L02_001DDD38, 4");
__asm__(".extern D_L02_001DDD3C, 4");
__asm__(".extern D_L02_001DDCE4_003A1BA8, 4");
__asm__(".extern D_L02_001DDCEC_003A1BA8, 4");
__asm__(".extern D_L02_001DDCF8_003A1BA8, 4");
__asm__(".extern D_L02_001DDCFC_003A1BA8, 4");
__asm__(".extern D_L02_001DDD00_003A1BA8, 4");
__asm__(".extern D_L02_001DDD04_003A1BA8, 4");
__asm__(".extern D_L02_001DDD28_003A1BA8, 4");
__asm__(".extern D_L02_001DDD08_003A1BA8, 4");
__asm__(".extern D_L02_001DDCE8_003A1BA8, 4");
__asm__(".extern D_L02_001DDD0C_003A1BA8, 4");
__asm__(".extern D_L02_001DDD10_003A1BA8, 4");
__asm__(".extern D_L02_001DDCF0_003A1BA8, 4");
__asm__(".extern D_L02_001DDCF4_003A1BA8, 4");
__asm__(".extern D_L02_001DDD14_003A1BA8, 4");
__asm__(".extern D_L02_001DDD1C_003A1BA8, 4");
__asm__(".extern D_L02_001DDD20_003A1BA8, 4");
__asm__(".extern D_L02_001DDD18_003A1BA8, 4");
__asm__(".extern D_L02_001DDD2C, 4");
__asm__(".extern D_L02_001DDD24_003A1BA8, 4");
extern Glob_003A3988 D_001A4BE0;
extern s32 D_L02_001D6694_003A1BA8;
extern s32 D_L02_001DDD30;
extern f32 D_L02_001DDD40;
extern f32 D_L02_001DDD44;
extern f32 D_L02_001DDD54;
extern f32 D_L02_001DDD34;
extern f32 D_L02_001DDD50;
extern f32 D_L02_001DDD48;
extern f32 D_L02_001DDD4C;
extern s32 D_L02_001DDD38;
extern s32 D_L02_001DDD3C;
extern s32 D_L02_001DDCE4_003A1BA8;
extern f32 D_L02_001DDCEC_003A1BA8;
extern f32 D_L02_001DDCF8_003A1BA8;
extern f32 D_L02_001DDCFC_003A1BA8;
extern f32 D_L02_001DDD00_003A1BA8;
extern f32 D_L02_001DDD04_003A1BA8;
extern s32 D_L02_001DDD28_003A1BA8;
extern f32 D_L02_001DDD08_003A1BA8;
extern s32 D_L02_001DDCE8_003A1BA8;
extern f32 D_L02_001DDD0C_003A1BA8;
extern f32 D_L02_001DDD10_003A1BA8;
extern f32 D_L02_001DDCF0_003A1BA8;
extern f32 D_L02_001DDCF4_003A1BA8;
extern s32 D_L02_001DDD14_003A1BA8;
extern s32 D_L02_001DDD1C_003A1BA8;
extern s32 D_L02_001DDD20_003A1BA8;
extern s32 D_L02_001DDD18_003A1BA8;
extern s32 D_L02_001DDD2C;
extern s32 D_L02_001DDD24_003A1BA8;

void func_L02_003A1BA8(Obj_003A3988 *self) {
    Dat_003A3988 *d;
    vu0_v4 axis, a, b, c;
    s32 i, k, j, r, s16v, s17v;
    f32 f20, f21;
    f32 *rot;
    f32 ang;

    d = self->d;
    if (func_L02_003A2AD8(self) != 0) {
        func_003BD360(self);
        return;
    }
    if (D_L02_001D6694_003A1BA8 == 2) {
        if ((self->fl.b0 ^ 1) & 1) {
            self->f98 = 0;
            self->fl.w = (self->fl.w | 0x41) & 0xEFFF;
            func_L01_004A6DF8(self, 1);
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
        func_L02_003A30F0((s32)self);
        func_0039FE80(3, 0, self);
        {
            s32 i, k, j;
            *(u128_t *)&axis = 0;
            axis.z = 1.0f;
            for (i = 0; i < D_L02_001DDD30; i++) {
                func_00388830(&a, &axis, func_0037E250(D_L02_001DDD40, D_L02_001DDD44) * 0.01666666753590107f);
                func_003BF6A8(&a, D_L02_001DDD54 * 0.01666666753590107f);
                func_00388830(&b, &axis, D_L02_001DDD34);
                vec_add_ab(&b, &b, &self->pos);
                func_003BF6A8(&b, D_L02_001DDD50);
                f20 = func_0037E250(D_L02_001DDD48, D_L02_001DDD4C) * 210000.0f;
                func_L01_00470258(&b, &a, f20, D_L02_001DDD38, D_L02_001DDD3C, func_0037E208(120, 240), 0);
            }
            for (k = 0; k < D_L02_001DDCE4_003A1BA8; k++) { f32 ang2, hgt, rad;
                a = self->pos;
                func_003BF6A8(&a, D_L02_001DDCEC_003A1BA8);
                ang2 = func_0037E2A8();
                rad = func_0037E250(D_L02_001DDCF8_003A1BA8, D_L02_001DDCFC_003A1BA8);
                hgt = func_0037E250(D_L02_001DDD00_003A1BA8, D_L02_001DDD04_003A1BA8);
                rad = rad * 0.01666666753590107f;
                qzero(&b);
                b.x += func_00388960(ang2) * rad;
                b.y += func_00388978(ang2) * rad;
                b.z += hgt * 0.01666666753590107f;
                c = b;
                c.z -= D_L02_001DDD08_003A1BA8 * 0.00027777778450399637f * (f32)(D_L02_001DDD28_003A1BA8);
                for (j = 0; j < D_L02_001DDCE8_003A1BA8; j++) {
                    f32 r1, r2;
                    r1 = func_0037E250(0.5f, 1.5f);
                    b.w = r1 * D_L02_001DDD0C_003A1BA8;
                    c.w = r1 * D_L02_001DDD10_003A1BA8;
                    func_003BF6A8(&a, D_L02_001DDCF0_003A1BA8);
                    func_003BF6A8(&c, D_L02_001DDCF4_003A1BA8 * 0.01666666753590107f);
                    s16v = func_003894A0(func_0037E250(0.0f, 1.0f), D_L02_001DDD14_003A1BA8, D_L02_001DDD1C_003A1BA8);
                    s17v = func_003894A0(func_0037E250(0.0f, 1.0f), D_L02_001DDD18_003A1BA8, D_L02_001DDD20_003A1BA8);
                    r2 = func_0037E250((f32)D_L02_001DDD2C * 0.5f, (f32)D_L02_001DDD2C * 2.5f);
                    func_L01_0045FEC8(&a, &b, &c, s16v, s17v, D_L02_001DDD24_003A1BA8,
                                      D_L02_001DDD28_003A1BA8, (s32)r2, -1);
                }
            }
        }
        func_003BD360(self);
        return;
    }
    switch (self->mode) {
    case 0:
        if (func_L01_00452EF0(self) != 0) {
            d->f2D6 = func_0037E208(0, 30);
        }
        if (d->f234 == 1) {
            if (func_003883C8(&d->f2D6) != 0) {
                func_L01_00441FB8(self, 3, 2);
                break;
            }
        }
        if (d->f2D8 != 0) {
            if (func_003883C8(&d->f2D6) != 0) {
                func_L01_00441FB8(self, 2, 1);
                d->f2D8 = 0;
                if (d->f2D0 < 300) {
                    d->f2D0 = func_0037E208(480, 600);
                }
            }
        }
        break;
    case 1:
        if (d->f234 == 1) {
            func_L01_00441FB8(self, 3, 2);
            break;
        }
        if (d->f2D0 == 0) {
            func_L01_00441FB8(self, 1, 0);
        }
        break;
    case 2:
        if (d->f230 == D_001A4BE0.f25C0) {
            if (D_001A4BE0.f360 != 0) {
                func_003BEBF8(&self->pos.z, D_001A4BE0.fD8, 0.05000000447034836f);
            }
        } else {
            func_003BEBF8(&self->pos.z, d->v220.z, 0.01666666753590107f);
        }
        if (d->f234 != 1) {
            if (func_L01_00452EF0(self) == 0) {
                func_L01_00441FB8(self, 1, 0);
                if (self->f43 != 1) {
                    func_003BE4F0(self, 1, 0, 0);
                }
                d->f2D0 = func_0037E208(580, 600);
            }
        }
        break;
    case 3:
        r = func_L01_00451078(self, d->b160);
        if (d->f30 <= 0.0f) {
            self->fF4 = func_00389380(self->fF4, 0.6981317f);
            if (self->fBC == 0) {
                func_0039FE80(3, 0, self);
                self->fBC = 1;
            }
        }
        if (r & 1) {
            func_L02_003A30F0((s32)self);
            {
                s32 i, k, j;
                *(u128_t *)&axis = 0;
                axis.z = 1.0f;
                for (i = 0; i < D_L02_001DDD30; i++) {
                    func_00388830(&a, &axis, func_0037E250(D_L02_001DDD40, D_L02_001DDD44) * 0.01666666753590107f);
                    func_003BF6A8(&a, D_L02_001DDD54 * 0.01666666753590107f);
                    func_00388830(&b, &axis, D_L02_001DDD34);
                    vec_add_ab(&b, &b, &self->pos);
                    func_003BF6A8(&b, D_L02_001DDD50);
                    f20 = func_0037E250(D_L02_001DDD48, D_L02_001DDD4C) * 210000.0f;
                    func_L01_00470258(&b, &a, f20, D_L02_001DDD38, D_L02_001DDD3C, func_0037E208(120, 240), 0);
                }
                for (k = 0; k < D_L02_001DDCE4_003A1BA8; k++) { f32 ang2, hgt, rad;
                    a = self->pos;
                    func_003BF6A8(&a, D_L02_001DDCEC_003A1BA8);
                    ang2 = func_0037E2A8();
                    rad = func_0037E250(D_L02_001DDCF8_003A1BA8, D_L02_001DDCFC_003A1BA8);
                    hgt = func_0037E250(D_L02_001DDD00_003A1BA8, D_L02_001DDD04_003A1BA8);
                    rad = rad * 0.01666666753590107f;
                    qzero(&b);
                    b.x += func_00388960(ang2) * rad;
                    b.y += func_00388978(ang2) * rad;
                    b.z += hgt * 0.01666666753590107f;
                    c = b;
                    c.z -= D_L02_001DDD08_003A1BA8 * 0.00027777778450399637f * (f32)(D_L02_001DDD28_003A1BA8);
                    for (j = 0; j < D_L02_001DDCE8_003A1BA8; j++) {
                        f32 r1, r2;
                        r1 = func_0037E250(0.5f, 1.5f);
                        b.w = r1 * D_L02_001DDD0C_003A1BA8;
                        c.w = r1 * D_L02_001DDD10_003A1BA8;
                        func_003BF6A8(&a, D_L02_001DDCF0_003A1BA8);
                        func_003BF6A8(&c, D_L02_001DDCF4_003A1BA8 * 0.01666666753590107f);
                        s16v = func_003894A0(func_0037E250(0.0f, 1.0f), D_L02_001DDD14_003A1BA8, D_L02_001DDD1C_003A1BA8);
                        s17v = func_003894A0(func_0037E250(0.0f, 1.0f), D_L02_001DDD18_003A1BA8, D_L02_001DDD20_003A1BA8);
                        r2 = func_0037E250((f32)D_L02_001DDD2C * 0.5f, (f32)D_L02_001DDD2C * 2.5f);
                        func_L01_0045FEC8(&a, &b, &c, s16v, s17v, D_L02_001DDD24_003A1BA8,
                                          D_L02_001DDD28_003A1BA8, (s32)r2, -1);
                    }
                }
            }
            func_003BD360(self);
            return;
        } else if (r & 2) {
            if (d->f234 == 1) {
                func_L01_00441FB8(self, 3, 2);
            } else {
                func_L01_00441FB8(self, 2, 1);
                d->f2D0 = func_0037E208(580, 600);
            }
        }
        break;
    }
    switch (self->state) {
    case 2:
        break;
    case 1:
        if (func_L01_00452EC8(self) != 0) {
            f20 = func_0037E2A8();
            f21 = func_0037E250(1.0f, 3.0f);
            qzero(&d->v2F0);
            d->v2F0.x = func_00388960(f20) * f21;
            d->v2F0.y = func_00388978(f20) * f21;
            vec_add_ab(&d->v2F0, &d->v2F0, &d->v2E0);
            if (d->f300 != -1 && func_L01_00453210(&d->v2F0, d->f300) == 0) {
                d->v2F0 = d->v2E0;
            }
            d->f2DC = func_0037E208(300, 530);
            func_L01_00458A70(self, 0.004444444552063942f, 0.10000000894069672f, 0.0038785096257925034f, 0.2908882200717926f);
        }
        func_L01_00457590(self, &d->v2F0, self->fF8);
        rot = &self->fF8;
        ang = func_00388A28(d->v2F0.x - self->pos.x, d->v2F0.y - self->pos.y);
        func_L01_00445758(rot, d->b304, ang, 0.0038785096257925034f, 0.0038785096257925034f, 0.2908882200717926f, 0);
        if (func_00388800(&self->pos, &d->v2F0) < 0.75f) {
            f20 = func_0037E2A8();
            f21 = func_0037E250(1.0f, 3.0f);
            qzero(&d->v2F0);
            d->v2F0.x = func_00388960(f20) * f21;
            d->v2F0.y = func_00388978(f20) * f21;
            vec_add_ab(&d->v2F0, &d->v2F0, &d->v2E0);
            if (d->f300 != -1 && func_L01_00453210(&d->v2F0, d->f300) == 0) {
                d->v2F0 = d->v2E0;
            }
        }
        break;
    case 3:
        if (func_L01_00452EC8(self) != 0) {
            func_L01_00455E98(self, d->f230, d->b320);
            func_L01_00458A70(self, 0.0047222222201526165f, 0.11666667461395264f, 0.0069813174195587635f, 0.20943953096866608f);
        }
        func_L01_00455C88(self, d->b320, 0, 0);
        func_L01_004574A0(self, d->b320, d->f310);
        if (func_00388800(&self->pos, &d->v220) < 1.3f) {
            if (self->f43 != 3) {
                func_003BE4F0(self, 3, 0, 6);
            }
            func_L01_00441FB8(self, 4, -1);
        }
        break;
    case 5:
        if (func_L01_00452EC8(self) != 0) {
            vec_sub_ba(&axis, &self->pos, &d->v220);
            func_00388830(&axis, &axis, func_0037E250(4.0f, 5.0f));
            vec_add_ab(&d->v2F0, &self->pos, &axis);
        }
        func_L01_00457440(self, &d->v2F0);
        if (func_00388800(&self->pos, &d->v2F0) < 0.5f || self->f96 >= 0x79) {
            func_L01_00441FB8(self, 3, -1);
        }
        break;
    case 4:
        func_L01_00458A70(self, 0.013333333656191826f, 0.30000001192092896f, 0.0069813174195587635f, 0.20943953096866608f);
        if (func_00388800(&self->pos, &d->v220) > 1.2f && self->f42 == 3 && func_L01_00436500(self) > 8.0f) {
            self->f48 = 1.0f;
        } else if (self->f42 == 3) {
            func_L01_00436500(self);
        }
        func_L01_00458A08(self, func_00388A28(d->v220.x - self->pos.x, d->v220.y - self->pos.y));
        self->f48 = 1.0f;
        if (d->f5F != 0) {
            func_L01_00443790(self, 0.5f, (f32)d->f44, 1.0f, 0, 0x10001, 0, 1, 0);
        } else {
            func_L01_00443790(self, 0.5f, (f32)d->f44, 1.0f, 0, 1, 0, 1, 0);
        }
        if (self->f60 & 2) {
            if (self->f43 != 1) {
                func_003BE4F0(self, 1, 0, 6);
            }
            func_L01_00441FB8(self, 5, -1);
            func_L01_00458A70(self, 0.004444444552063942f, 0.10000000894069672f, 0.0069813174195587635f, 0.20943953096866608f);
            if (d->f230 != D_001A4BE0.f25C0) {
                func_L01_00441FB8(self, 3, -1);
            }
        }
        break;
    }
    func_L02_003A3110(self);
}
/* localdecomp:end func_L02_003A1BA8 */

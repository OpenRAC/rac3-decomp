#include "common.h"

/* NTSC-U counterpart of func_L40_00423310 (src/levels/shared/L40_00422A78.c) */
typedef struct {
    u8 pad00[0x20];
    s32 f20;
    s32 f24;
    u8 pad28[4];
    f32 f2C;
} Obj_00423310;
typedef struct S2_00423310 {
    u8 pad00[0x70];
    s32 f70;
    s32 f74;
    u8 pad78[0xC];
    s32 f84;
} S2_00423310;
typedef struct {
    u8 pad00[0x20];
    u8 f20;
    u8 pad21[0x47];
    S2_00423310 *f68;
    u8 pad6C[0x3C];
    u8 fA8;
} Self_00423310;
extern void func_L01_00441FB8(void *, s32, s32);
extern void func_L40_00423C70(void *, s32, s32);
extern s32 D_001A5F78[];

/* localdecomp:start func_L40_00422A40 */
extern u8 *func_L01_00444358(void *, s32, s32);
extern void func_L01_00441FB8(void *, s32, s32);
extern f32 func_L01_0040C018(void *, void *);
extern s32 func_L40_00421F78_00422A40(void *);
extern void func_L40_00421FA0(void *, void *);
extern s32 func_L40_004224B0(void *, void *);
extern void func_L40_004221D0(s32, s32);
extern void func_L40_00423C70(void *, s32, s32);
extern u8 *func_L39_0061A7C8(s32);
extern s32 func_L39_0055F770(void *);
extern void func_L39_0055F858(void *);
extern s32 D_001A5F78[];
extern s32 *D_L40_002494B0[8] __attribute__((section(".sdata")));

s32 func_L40_00422A40(Self_00423310 *self) {
    S2_00423310 *s2 = self->f68;
    Obj_00423310 *v = (Obj_00423310 *)func_L01_00444358(self, 0x0B030001, 0);
    s32 i;
    s32 ok;
    u8 *y;
    s32 *e;

    if (v != 0) {
        if (v->f24 == 0x2000000) {
            v = 0;
        }
    }
    self->fA8 = 0xFF;
    switch (self->f20) {
    case 1:
        if (v != 0 && 0.0f < v->f2C) {
            if (func_L40_00421F78_00422A40(self) == 0) {
                func_L40_00423C70(self, 0, (s32)v);
                ok = 1;
                func_L01_00441FB8(self, 2, -1);
                y = 0;
                if (v->f20 != 0) {
                    y = func_L39_0061A7C8(v->f20);
                    if (y != 0 && y[0x1A14] == 0) {
                        ok = 0;
                    }
                }
                if (ok != 0) {
                    func_L40_00421FA0(self, y);
                }
            }
        }
        break;
    case 2:
    case 3:
        break;
    case 4:
    case 5:
        for (i = 0; i < 8; i++) {
            e = D_L40_002494B0[i];
            if (e != 0 && func_L01_0040C018((u8 *)e + 0xA0, (u8 *)self + 0x10) < 4.0f && func_L40_004224B0(e, self) != 0) {
                func_L40_004221D0((s32)self, *e);
                break;
            }
        }
        break;
    case 6:
        if (s2->f84 != 0 && s2->f70 > 0) {
            if (s2->f70 < D_001A5F78[0] - s2->f74) {
                if (func_L39_0055F770(self) == 0) {
                    func_L39_0055F858(self);
                }
            }
        }
        break;
    }
    return 0;
}
/* localdecomp:end func_L40_00422A40 */

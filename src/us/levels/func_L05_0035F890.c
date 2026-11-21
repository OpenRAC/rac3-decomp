#include "common.h"

/* NTSC-U counterpart of func_L05_00360AE0 (src/levels/shared/L05_00360A10.c) */
#include "vu0.h"
extern u8 D_001A4C60[];
extern u8 *D_L05_001DFD00;

/* localdecomp:start func_L05_0035F890 */
typedef struct B_360AE0 {
    u8 pad0[0x30];
    vu0_v4 v30;
    u8 pad40[0x2c];
    u32 f6C;
    vu0_v4 v70;
    vu0_v4 v80;
    s32 f90;
    f32 f94;
    f32 f98;
    s16 f9C;
    u8 f9E;
    u8 f9F;
    s8 fA0;
    s8 fA1;
    s8 fA2;
    s8 fA3;
    u8 fA4;
    u8 fA5;
    u8 fA6;
    u8 fA7;
    s32 fA8;
    f32 fAC;
    f32 fB0;
    f32 fB4;
    f32 fB8;
    f32 fBC;
    f32 fC0;
    s32 fC4;
} B_360AE0;

typedef struct O_360AE0 {
    u8 pad0[0x10];
    vu0_v4 v10;
    u8 f20;
    u8 pad21[0x13];
    u16 f34;
    u8 pad36[0xc];
    u8 f42;
    u8 f43;
    u8 pad44[4];
    s32 f48;
    u8 pad4c[0x14];
    u8 f60;
    u8 pad61[7];
    B_360AE0 *p68;
    u8 pad6c[0xc];
    s32 f78;
    u8 pad7c[0x74];
    vu0_v4 vF0;
} O_360AE0;

typedef struct G_360AE0 {
    u8 pad0[0x35C];
    O_360AE0 *f35C;
    s32 f360;
    u8 pad364[10];
    s16 f36E;
} G_360AE0;
extern G_360AE0 D_001A4BE0_360AE0;
__asm__(".extern D_001A4BE0_360AE0, 16");
typedef struct M_360AE0 {
    u8 pad0[0xD0];
    u8 fD0;
    u8 padD1[0xB];
    void *fDC;
    u8 padE0[0x20];
} M_360AE0;
extern u8 D_001A30B0[];
extern u8 D_001A4C60[];
extern u8 *D_L05_001DFD00;
extern u8 *D_L05_001DFD00_0035F890;
__asm__(".extern D_L05_001DFD00_0035F890, 4");

extern void func_L05_003601F8(u8 *);
extern void func_L05_00360338(u8 *);
extern void func_L05_00360478(u8 *);
extern void func_L05_0044D7A0(void *, s32);
extern void func_L05_0044D948(void *, void *, void *, s32, f32);
extern void func_L01_00441FB8(void *, s32, s32);
extern void func_003BE418(void *, s32, s32);
extern void func_003BE4F0(void *, s32, s32, s32);
extern s32 func_L01_00452F60(void *);
extern s32 func_L01_00452EC8(void *);
extern s32 func_0039FE80(s32, s32, void *);
extern void func_0039FB08(s32);
extern f32 func_00388800(void *, void *);
extern f32 func_00388960(f32);
extern f32 func_00388978(f32);
extern s32 func_00388398(void *);
extern s32 func_003894A0(s32, s32, f32);
extern void func_L01_0044B860(void *, void *, void *, f32, f32, f32);
extern void func_L01_0044B920(void *, void *, void *, f32, f32, f32);
extern void func_003BF838(void *, void *, void *, void *);
extern void func_L01_00402498(void *, void *);

void func_L05_0035F890(O_360AE0 *self) {
    B_360AE0 *b = self->p68;
    vu0_v4 old = self->v10;
    vu0_v4 oldrot = self->vF0;
    vu0_v4 d;
    s32 ok;
    s32 near;
    s32 s0;

    if (D_001A4BE0_360AE0.f35C == self && D_001A4BE0_360AE0.f360 >= 2 && D_001A4BE0_360AE0.f36E <= 0) {
        b->fA5 = b->fA5 + 1;
    } else if (D_001A4BE0_360AE0.f35C != self && b->fA5 != 0) {
        b->fA5 = b->fA5 - 1;
    }
    if (b->fA5 >= 11) {
        b->fA5 = 10;
    }
    switch (self->f20) {
    case 0:
        if (b->f90 == -1 && b->fA0 == -1) {
            self->f34 |= 2;
            func_L01_00441FB8(self, 6, -1);
            return;
        }
        b->f98 = 0.0f;
        b->f6C |= 1;
        b->v70 = self->v10;
        b->v80 = self->vF0;
        func_L05_0044D7A0(self, b->f9C);
        b->fA4 = 0;
        if (b->f9E != 0) {
            if (b->f90 != -1) {
                *(vu0_q *)&self->v10 = *(vu0_q *)(D_L05_001DFD00_0035F890 + b->f90 * 128 + 0x30);
                *(vu0_q *)&self->vF0 = *(vu0_q *)(D_L05_001DFD00 + b->f90 * 128 + 0x70);
            }
            if (b->fA2 != -1) {
                func_003BE418(self, b->fA2, 0);
            }
            func_L01_00441FB8(self, 3, -1);
            b->fB0 = 0.0f;
            b->fB4 = 0.0f;
            b->fB8 = 0.0f;
            b->fBC = 0.0f;
        } else {
            if (b->fA0 != -1) {
                func_003BE418(self, b->fA0, 0);
            }
            func_L01_00441FB8(self, 1, -1);
        }
        b->fC0 = self->v10.z;
        break;
    case 1:
        ok = 1;
        if (self->f60 & 2) {
            if (b->fA0 != -1 && self->f43 != b->fA0) {
                func_003BE4F0(self, b->fA0, 0, 5);
            } else {
                self->f48 = 0;
            }
        }
        if (b->fA0 != -1 && self->f42 != b->fA0) {
            ok = 0;
        }
        s0 = func_L05_0035F7C0((u8 *)self) == 0;
        if (ok && b->fA4 == 0 && (func_L01_00452F60(self) != 0 || s0 || b->fA5 >= 10)) {
            b->fA4 = 1;
            if (b->fA1 != -1 && self->f43 != b->fA1) {
                func_003BE4F0(self, b->fA1, 0, 5);
            }
            func_L01_00441FB8(self, 2, -1);
        } else if (func_L01_00452F60(self) == 0 && b->fA5 == 0) {
            b->fA4 = 0;
        }
        func_L05_00360338((u8 *)self);
        break;
    case 2:
        if (func_L01_00452EC8(self) != 0) {
            if (b->fA7 != 0) {
                b->fA8 = func_0039FE80(b->fA6, 4, self);
            } else {
                func_0039FE80(b->fA6, 0, self);
            }
        }
        near = 0;
        if (*(f32 *)(D_L05_001DFD00 + (b->f90 << 7) + 0x38) <= self->v10.z) {
            if (func_00388800(&self->v10, D_001A4C60) < 3.5f) {
                if (*(f32 *)(D_001A4C60 + 8) < self->v10.z) {
                    if (self->v10.z < *(f32 *)(D_001A4C60 + 8) + 3.0f) {
                        near = 1;
                    }
                }
            }
        }
        if (near == 0) {
            b->f98 = b->f98 + 1.0f / (b->f94);
            if (b->f98 > 1.0f) {
                b->f98 = 1.0f;
            }
            func_L05_0044D948(self, &b->v70, &b->v80, b->f90, (1.0f - func_00388960(b->f98 * 3.14159274f)) * 0.5f);
            if (self->f60 & 2) {
                if (b->fA2 != -1 && self->f43 != b->fA2) {
                    func_003BE4F0(self, b->fA2, 0, 5);
                } else {
                    self->f48 = 0;
                }
            }
        }
        b->fC0 = self->v10.z;
        if (b->f98 >= 1.0f) {
            if (b->fA7 != 0) {
                if (b->fA8 != -1) {
                    if (((M_360AE0 *)(D_001A30B0 + (b->fA8 << 7)))->fDC == self && ((M_360AE0 *)(D_001A30B0 + (b->fA8 << 7)))->fD0 != 0) {
                        func_0039FB08(b->fA8);
                    }
                }
                b->fA8 = -1;
            }
            b->f98 = 1.0f;
            if (b->f9F != 0) {
                func_L01_00441FB8(self, 5, -1);
            } else {
                func_L01_00441FB8(self, 3, -1);
            }
        }
        break;
    case 3:
        ok = 1;
        if (self->f60 & 2) {
            if (b->fA2 != -1 && self->f43 != b->fA2) {
                func_003BE4F0(self, b->fA2, 0, 5);
            } else {
                self->f48 = 0;
            }
        }
        if (b->fA2 != -1 && self->f42 != b->fA2) {
            ok = 0;
        }
        s0 = func_L05_0035F7C0((u8 *)self) == 1;
        if (ok && b->fA4 == 0 && (func_L01_00452F60(self) != 0 || s0 || b->fA5 >= 10)) {
            b->fA4 = 1;
            if (b->fA3 != -1 && self->f43 != b->fA3) {
                func_003BE4F0(self, b->fA3, 0, 5);
            }
            func_L01_00441FB8(self, 4, -1);
        } else if (func_L01_00452F60(self) == 0 && b->fA5 == 0) {
            b->fA4 = 0;
        }
        break;
    case 4:
        if (func_L01_00452EC8(self) != 0) {
            if (b->fA7 != 0) {
                b->fA8 = func_0039FE80(b->fA6, 4, self);
            } else {
                func_0039FE80(b->fA6, 0, self);
            }
        }
        near = 0;
        if (b->fC0 >= b->v70.z) {
            if (func_00388800(&self->v10, D_001A4C60) < 3.5f) {
                if (*(f32 *)(D_001A4C60 + 8) < b->fC0) {
                    if (b->fC0 < *(f32 *)(D_001A4C60 + 8) + 3.0f) {
                        near = 1;
                    }
                }
            }
        }
        if (near == 0) {
            b->f98 = b->f98 - 1.0f / (b->f94);
            if (b->f98 < 0.0f) {
                b->f98 = 0.0f;
            }
            func_L05_0044D948(self, &b->v70, &b->v80, b->f90, (1.0f - func_00388960(b->f98 * 3.14159274f)) * 0.5f);
            b->fC0 = self->v10.z;
            if (self->f60 & 2) {
                if (b->fA0 != -1 && self->f43 != b->fA0) {
                    func_003BE4F0(self, b->fA0, 0, 5);
                } else {
                    self->f48 = 0;
                }
            }
        }
        if (b->f98 <= 0.0f) {
            if (b->fA7 != 0) {
                if (b->fA8 != -1) {
                    if (((M_360AE0 *)(D_001A30B0 + (b->fA8 << 7)))->fDC == self && ((M_360AE0 *)(D_001A30B0 + (b->fA8 << 7)))->fD0 != 0) {
                        func_0039FB08(b->fA8);
                    }
                }
                b->fA8 = -1;
            }
            if (b->f9F != 0) {
                func_L01_00441FB8(self, 5, -1);
            } else {
                func_L01_00441FB8(self, 1, -1);
            }
        }
        break;
    case 5:
        self->f34 |= 2;
        break;
    }
    func_L01_0044B860(self, &b->fB0, &b->fB4, 0.1f, 0.05f, b->fC0);
    func_L01_0044B920(self, &b->fB8, &b->fBC, 0.05f, 0.02f, 0.02f);
    if (self->f20 < 5) {
        vec_sub_ba(&d, &self->v10, &old);
        func_003BF838(&b->v30, &d, &oldrot, &self->vF0);
    }
    if (func_00388398(&b->fC4) != 0) {
        b->fC4 = 60;
    }
    self->f78 = func_003894A0(0x80B0B000, 0x80303000, func_00388978((f32)b->fC4 * 6.2831855f / 60.0f) * 0.5f + 0.5f);
    func_L05_003601F8((u8 *)self);
    func_L01_00402498(func_L05_00360478, self);
}
/* localdecomp:end func_L05_0035F890 */

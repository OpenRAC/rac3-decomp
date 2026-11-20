#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L05_00360A10 */
extern f32 func_0038CF00(void *, void *);
extern u8 D_001A4C60[];
extern u8 *D_L05_001DFC80;

s32 func_L05_00360A10(u8 *a0) {
    u8 *v = *(u8 **)(a0 + 0x68);
    s32 r;
    if (*(s32 *)(v + 0x90) != -1) {
        f32 d = func_0038CF00(D_001A4C60, v + 0x70);
        f32 e = func_0038CF00(D_001A4C60, D_L05_001DFC80 + (*(s32 *)(v + 0x90) << 7) + 0x30);
        r = 0;
        if (!(e < d)) {
            r = 1;
        }
        return r;
    }
    if (*(f32 *)(v + 0xAC) == 0.0f) {
        return 2;
    }
    r = 0;
    if (!(fabs_asm(*(f32 *)(D_001A4C60 + 8) - (*(f32 *)(a0 + 0x18) + *(f32 *)(v + 0xAC))) < fabs_asm(*(f32 *)(D_001A4C60 + 8) - *(f32 *)(a0 + 0x18)))) {
        r = 1;
    }
    return r;
}
/* localdecomp:end func_L05_00360A10 */

/* localdecomp:start func_L05_00360AE0 */
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
extern u8 *D_L05_001DFC80;
extern u8 *D_L05_001DFC80_00360AE0;
__asm__(".extern D_L05_001DFC80_00360AE0, 4");

extern void func_L05_00361498(u8 *);
extern void func_L05_003615D8(u8 *);
extern void func_L05_00361718(u8 *);
extern void func_L05_00451150(void *, s32);
extern void func_L05_004512F8(void *, void *, void *, s32, f32);
extern void func_L01_004450F0(void *, s32, s32);
extern void func_003C3938(void *, s32, s32);
extern void func_003C3A10(void *, s32, s32, s32);
extern s32 func_L01_00456250(void *);
extern s32 func_L01_004561B8(void *);
extern s32 func_003A52A0(s32, s32, void *);
extern void func_003A4F28(s32);
extern f32 func_0038CF38(void *, void *);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern s32 func_0038CAD0(void *);
extern s32 func_0038DBD8(s32, s32, f32);
extern void func_L01_0044EAE0(void *, void *, void *, f32, f32, f32);
extern void func_L01_0044EBA0(void *, void *, void *, f32, f32, f32);
extern void func_003C4DA8(void *, void *, void *, void *);
extern void func_L01_00404808(void *, void *);

void func_L05_00360AE0(O_360AE0 *self) {
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
    if (b->fA5 >= 9) {
        b->fA5 = 8;
    }
    switch (self->f20) {
    case 0:
        if (b->f90 == -1 && b->fA0 == -1) {
            self->f34 |= 2;
            func_L01_004450F0(self, 6, -1);
            return;
        }
        b->f98 = 0.0f;
        b->f6C |= 1;
        b->v70 = self->v10;
        b->v80 = self->vF0;
        func_L05_00451150(self, b->f9C);
        b->fA4 = 0;
        if (b->f9E != 0) {
            if (b->f90 != -1) {
                *(vu0_q *)&self->v10 = *(vu0_q *)(D_L05_001DFC80_00360AE0 + b->f90 * 128 + 0x30);
                *(vu0_q *)&self->vF0 = *(vu0_q *)(D_L05_001DFC80 + b->f90 * 128 + 0x70);
            }
            if (b->fA2 != -1) {
                func_003C3938(self, b->fA2, 0);
            }
            func_L01_004450F0(self, 3, -1);
            b->fB0 = 0.0f;
            b->fB4 = 0.0f;
            b->fB8 = 0.0f;
            b->fBC = 0.0f;
        } else {
            if (b->fA0 != -1) {
                func_003C3938(self, b->fA0, 0);
            }
            func_L01_004450F0(self, 1, -1);
        }
        b->fC0 = self->v10.z;
        break;
    case 1:
        ok = 1;
        if (self->f60 & 2) {
            if (b->fA0 != -1 && self->f43 != b->fA0) {
                func_003C3A10(self, b->fA0, 0, 5);
            } else {
                self->f48 = 0;
            }
        }
        if (b->fA0 != -1 && self->f42 != b->fA0) {
            ok = 0;
        }
        s0 = func_L05_00360A10((u8 *)self) == 0;
        if (ok && b->fA4 == 0 && (func_L01_00456250(self) != 0 || s0 || b->fA5 >= 8)) {
            b->fA4 = 1;
            if (b->fA1 != -1 && self->f43 != b->fA1) {
                func_003C3A10(self, b->fA1, 0, 5);
            }
            func_L01_004450F0(self, 2, -1);
        } else if (func_L01_00456250(self) == 0 && b->fA5 == 0) {
            b->fA4 = 0;
        }
        func_L05_003615D8((u8 *)self);
        break;
    case 2:
        if (func_L01_004561B8(self) != 0) {
            if (b->fA7 != 0) {
                b->fA8 = func_003A52A0(b->fA6, 4, self);
            } else {
                func_003A52A0(b->fA6, 0, self);
            }
        }
        near = 0;
        if (*(f32 *)(D_L05_001DFC80 + (b->f90 << 7) + 0x38) <= self->v10.z) {
            if (func_0038CF38(&self->v10, D_001A4C60) < 3.5f) {
                if (*(f32 *)(D_001A4C60 + 8) < self->v10.z) {
                    if (self->v10.z < *(f32 *)(D_001A4C60 + 8) + 3.0f) {
                        near = 1;
                    }
                }
            }
        }
        if (near == 0) {
            b->f98 = b->f98 + 1.0f / ((b->f94 * 5.0f + 2.0f) / 6.0f);
            if (b->f98 > 1.0f) {
                b->f98 = 1.0f;
            }
            func_L05_004512F8(self, &b->v70, &b->v80, b->f90, (1.0f - func_0038D098(b->f98 * 3.14159274f)) * 0.5f);
            if (self->f60 & 2) {
                if (b->fA2 != -1 && self->f43 != b->fA2) {
                    func_003C3A10(self, b->fA2, 0, 5);
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
                        func_003A4F28(b->fA8);
                    }
                }
                b->fA8 = -1;
            }
            b->f98 = 1.0f;
            if (b->f9F != 0) {
                func_L01_004450F0(self, 5, -1);
            } else {
                func_L01_004450F0(self, 3, -1);
            }
        }
        break;
    case 3:
        ok = 1;
        if (self->f60 & 2) {
            if (b->fA2 != -1 && self->f43 != b->fA2) {
                func_003C3A10(self, b->fA2, 0, 5);
            } else {
                self->f48 = 0;
            }
        }
        if (b->fA2 != -1 && self->f42 != b->fA2) {
            ok = 0;
        }
        s0 = func_L05_00360A10((u8 *)self) == 1;
        if (ok && b->fA4 == 0 && (func_L01_00456250(self) != 0 || s0 || b->fA5 >= 8)) {
            b->fA4 = 1;
            if (b->fA3 != -1 && self->f43 != b->fA3) {
                func_003C3A10(self, b->fA3, 0, 5);
            }
            func_L01_004450F0(self, 4, -1);
        } else if (func_L01_00456250(self) == 0 && b->fA5 == 0) {
            b->fA4 = 0;
        }
        break;
    case 4:
        if (func_L01_004561B8(self) != 0) {
            if (b->fA7 != 0) {
                b->fA8 = func_003A52A0(b->fA6, 4, self);
            } else {
                func_003A52A0(b->fA6, 0, self);
            }
        }
        near = 0;
        if (b->fC0 >= b->v70.z) {
            if (func_0038CF38(&self->v10, D_001A4C60) < 3.5f) {
                if (*(f32 *)(D_001A4C60 + 8) < b->fC0) {
                    if (b->fC0 < *(f32 *)(D_001A4C60 + 8) + 3.0f) {
                        near = 1;
                    }
                }
            }
        }
        if (near == 0) {
            b->f98 = b->f98 - 1.0f / ((b->f94 * 5.0f + 2.0f) / 6.0f);
            if (b->f98 < 0.0f) {
                b->f98 = 0.0f;
            }
            func_L05_004512F8(self, &b->v70, &b->v80, b->f90, (1.0f - func_0038D098(b->f98 * 3.14159274f)) * 0.5f);
            b->fC0 = self->v10.z;
            if (self->f60 & 2) {
                if (b->fA0 != -1 && self->f43 != b->fA0) {
                    func_003C3A10(self, b->fA0, 0, 5);
                } else {
                    self->f48 = 0;
                }
            }
        }
        if (b->f98 <= 0.0f) {
            if (b->fA7 != 0) {
                if (b->fA8 != -1) {
                    if (((M_360AE0 *)(D_001A30B0 + (b->fA8 << 7)))->fDC == self && ((M_360AE0 *)(D_001A30B0 + (b->fA8 << 7)))->fD0 != 0) {
                        func_003A4F28(b->fA8);
                    }
                }
                b->fA8 = -1;
            }
            if (b->f9F != 0) {
                func_L01_004450F0(self, 5, -1);
            } else {
                func_L01_004450F0(self, 1, -1);
            }
        }
        break;
    case 5:
        self->f34 |= 2;
        break;
    }
    func_L01_0044EAE0(self, &b->fB0, &b->fB4, 0.1f, 0.05f, b->fC0);
    func_L01_0044EBA0(self, &b->fB8, &b->fBC, 0.05f, 0.02f, 0.02f);
    if (self->f20 < 5) {
        vec_sub_ba(&d, &self->v10, &old);
        func_003C4DA8(&b->v30, &d, &oldrot, &self->vF0);
    }
    if (func_0038CAD0(&b->fC4) != 0) {
        b->fC4 = 50;
    }
    self->f78 = func_0038DBD8(0x80B0B000, 0x80303000, func_0038D0B0((f32)b->fC4 * 6.2831855f / 50.0f) * 0.5f + 0.5f);
    func_L05_00361498((u8 *)self);
    func_L01_00404808(func_L05_00361718, self);
}
/* localdecomp:end func_L05_00360AE0 */

/* localdecomp:start func_L05_00361498 */
extern void func_0038D000(void *, void *, void *);
extern void func_0038CF68(void *, void *, f32);
extern void func_003C4C18(void *, f32);
extern f32 func_003824E0(f32, f32);
extern s32 func_00382468(s32);
extern u8 *func_L05_00468EA8(void *, void *, void *, s32, s32);
extern vu0_v4 D_L05_001E2680;
__asm__(".extern D_L05_001DD8A0, 8");
extern u8 D_L05_001DD8A0[8];
__asm__(".extern D_L05_001DD8E0, 8");
extern u8 D_L05_001DD8E0[8];
__asm__(".extern D_L05_001DD8B8, 4");
extern s32 D_L05_001DD8B8;
__asm__(".extern D_L05_001DD8BC, 4");
extern f32 D_L05_001DD8BC;
__asm__(".extern D_L05_001DD8C0, 4");
extern f32 D_L05_001DD8C0;
__asm__(".extern D_L05_001DD8C4, 4");
extern f32 D_L05_001DD8C4;
__asm__(".extern D_L05_001DD8C8, 4");
extern f32 D_L05_001DD8C8;
__asm__(".extern D_L05_001DD8CC, 4");
extern f32 D_L05_001DD8CC;
__asm__(".extern D_L05_001DD8D0, 4");
extern f32 D_L05_001DD8D0;

void func_L05_00361498(u8 *a0) {
    vu0_v4 r;
    vu0_v4 p;
    vu0_v4 d;
    s32 i;

    *(vu0_q *)&r = 0;
    func_0038D000(&p, D_L05_001DD8E0, a0 + 0xC0);
    vec_add_ba(&p, a0 + 0x10, &p);
    vec_sub_ab(&d, &D_L05_001E2680, &p);
    func_0038CF68(&d, &d, D_L05_001DD8D0);
    vec_add_ab(&p, &p, &d);
    for (i = 0; i < D_L05_001DD8B8; i++) {
        func_003C4C18(&p, D_L05_001DD8BC);
        r.x = func_003824E0(D_L05_001DD8C0, D_L05_001DD8C4) * 0.020000001f;
        r.y = func_003824E0(D_L05_001DD8C0, D_L05_001DD8C4) * 0.020000001f;
        r.z = func_003824E0(D_L05_001DD8C8, D_L05_001DD8CC) * 0.020000001f;
        func_L05_00468EA8(&p, &r, D_L05_001DD8A0, func_00382468(2), func_00382468(3) - 1);
    }
}
/* localdecomp:end func_L05_00361498 */

/* localdecomp:start func_L05_003615D8 */
extern void func_0038D000(void *, void *, void *);
extern void func_0038CF68(void *, void *, f32);
extern void func_003C4C18(void *, f32);
extern f32 func_003824E0(f32, f32);
extern s32 func_00382468(s32);
extern u8 *func_L05_00468EA8(void *, void *, void *, s32, s32);
extern vu0_v4 D_L05_001E2680;
__asm__(".extern D_L05_001DD910, 8");
extern u8 D_L05_001DD910[8];
__asm__(".extern D_L05_001DD950, 8");
extern u8 D_L05_001DD950[8];
__asm__(".extern D_L05_001DD928, 4");
extern s32 D_L05_001DD928;
__asm__(".extern D_L05_001DD92C, 4");
extern f32 D_L05_001DD92C;
__asm__(".extern D_L05_001DD930, 4");
extern f32 D_L05_001DD930;
__asm__(".extern D_L05_001DD934, 4");
extern f32 D_L05_001DD934;
__asm__(".extern D_L05_001DD938, 4");
extern f32 D_L05_001DD938;
__asm__(".extern D_L05_001DD93C, 4");
extern f32 D_L05_001DD93C;
__asm__(".extern D_L05_001DD940, 4");
extern f32 D_L05_001DD940;

void func_L05_003615D8(u8 *a0) {
    vu0_v4 r;
    vu0_v4 p;
    vu0_v4 d;
    s32 i;

    *(vu0_q *)&r = 0;
    func_0038D000(&p, D_L05_001DD950, a0 + 0xC0);
    vec_add_ba(&p, a0 + 0x10, &p);
    vec_sub_ab(&d, &D_L05_001E2680, &p);
    func_0038CF68(&d, &d, D_L05_001DD940);
    vec_add_ab(&p, &p, &d);
    for (i = 0; i < D_L05_001DD928; i++) {
        func_003C4C18(&p, D_L05_001DD92C);
        r.x = func_003824E0(D_L05_001DD930, D_L05_001DD934) * 0.020000001f;
        r.y = func_003824E0(D_L05_001DD930, D_L05_001DD934) * 0.020000001f;
        r.z = func_003824E0(D_L05_001DD938, D_L05_001DD93C) * 0.020000001f;
        func_L05_00468EA8(&p, &r, D_L05_001DD910, func_00382468(2), func_00382468(3) - 1);
    }
}
/* localdecomp:end func_L05_003615D8 */

/* localdecomp:start func_L05_00361718 */
extern void func_0038D000(void *, void *, void *);
extern void func_0038CF68(void *, void *, f32);
extern void func_0038CE20(void *, void *, f32);
extern f32 func_0038CE68(void *, void *);
extern s32 func_0038DBD8(s32, s32, f32);
extern void func_003C5458(void *, s32, f32, f32);
extern vu0_v4 D_L05_001E2680;
extern u8 D_L05_001DD970[8];
__asm__(".extern D_L05_001DD970, 8");
extern f32 D_L05_001DD980;
__asm__(".extern D_L05_001DD980, 4");
extern s32 D_L05_001DD988;
__asm__(".extern D_L05_001DD988, 4");
extern s32 D_L05_001DD984;
__asm__(".extern D_L05_001DD984, 4");
extern f32 D_L05_001DD964;
__asm__(".extern D_L05_001DD964, 4");
extern f32 D_L05_001DD960;
__asm__(".extern D_L05_001DD960, 4");

void func_L05_00361718(u8 *a0) {
    vu0_v4 p;
    vu0_v4 d;
    vu0_v4 n;
    f32 dot;
    func_0038D000(&p, D_L05_001DD970, a0 + 0xC0);
    vec_add_ba(&p, a0 + 0x10, &p);
    vec_sub_ab(&d, &D_L05_001E2680, &p);
    func_0038CF68(&d, &d, 1.0f);
    func_0038CE20(&n, a0 + 0xE0, -1.0f);
    dot = func_0038CE68(&d, &n);
    if (D_L05_001DD980 < dot) {
        dot = dot * dot;
        func_003C5458(&p, func_0038DBD8(D_L05_001DD988, D_L05_001DD984, dot), D_L05_001DD964, D_L05_001DD960);
    }
}
/* localdecomp:end func_L05_00361718 */

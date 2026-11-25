#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L02_00350478 */
typedef int s128_350478 __attribute__((mode(TI)));
typedef struct {
    f32 x, y, z, w;
} __attribute__((aligned(16))) V4_350478;
typedef struct {
    u8 p00[0x10];
    f32 x;
    f32 y;
    u8 p18[8];
    u8 b20;
    u8 p21[3];
    u8 *p24;
    u8 p28[0xC];
    u16 h34;
    u8 p36[0xC];
    u8 b42;
    u8 b43;
    u8 p44[4];
    f32 f48;
    u8 p4C[0x14];
    u8 b60;
    u8 p61[7];
    u8 *p68;
    u8 p6C[0x29];
    u8 b95;
    u8 p96[2];
    s32 w98;
} S_350478;
typedef struct {
    u8 p00[0x30];
    f32 f30;
    u8 p34[0x10];
    u8 b44;
    u8 b45;
    u8 p46[0x11A];
    u8 a160[0xC0];
    f32 f220;
    f32 f224;
    u8 p228[0xC];
    s16 h234;
    u8 p236[0x9A];
    s32 w2D0;
    u8 p2D4[2];
    s16 h2D6;
    s32 w2D8;
    s32 w2DC;
} P_350478;

extern s32 func_L02_00351208(u8 *);
extern void func_003C2880(void *);
extern s32 func_L01_004561E0(void *);
extern s32 func_00382498(s32, s32);
extern s32 func_0038CB00(void *);
extern void func_L01_004450F0(void *, s32, s32);
extern void func_003C3A10(void *, s32, s32, s32);
extern s32 func_00382468(s32);
extern s32 func_L01_00454370(void *, void *);
extern void func_003A52A0(s32, s32, void *);
extern s32 func_L01_0044E1B8(void *, f32);
extern f32 func_003C3D30(void *, s32, void *, f32);
extern void func_L01_003016B0(void *, f32, f32, s32);
extern f32 func_00382538(void);
extern f32 func_003824E0(f32, f32);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern void func_L01_00468A68(void *, void *, s32, s32);
extern void func_L02_003516A8(s32);
extern void func_L01_00315900(void *, s32, s32);
extern f32 func_0038D160(f32, f32);
extern s32 func_L01_0045BD10(void *, f32);
extern f32 func_0038CF38(void *, void *);
extern void func_L01_0045A748(void *, void *);
extern f32 func_L01_004395E0(void *);
extern s32 func_L01_004468C8(u8 *, s32, f32, s32, f32, f32, s32, s32, s32);
extern void func_003C2F58(void *, s32, void *);
extern void func_0038CF68(void *, void *, f32);
extern void func_L02_0039CD18(void *, void *, void *, f32, s32);
extern s32 func_L01_004561B8(void *);
extern void func_L02_003516C8(u8 *);

void func_L02_00350478(S_350478 *self) {
    P_350478 *p = (P_350478 *)self->p68;
    s32 fl;
    s32 i;
    s32 j;
    s32 r;
    s32 r2;
    s32 fl2;
    f32 h;
    f32 rf;
    f32 a1;
    V4_350478 v[3];

    if (func_L02_00351208((u8 *)self)) {
        func_003C2880(self);
        return;
    }
    switch (self->b95) {
    case 0:
        if (func_L01_004561E0(self)) {
            if (p->h2D6 == 0) {
                p->h2D6 = (func_00382498(0, 0x28) * 5 + 2) / 6;
            }
        }
        if (p->h234 == 1) {
            if (func_0038CB00(&p->h2D6)) {
                self->h34 &= 0xFFBE;
                self->h34 |= *(u16 *)(self->p24 + 0x44) & 0x1000;
                self->w98 = *(s32 *)(self->p24 + 0x10);
                func_L01_004450F0(self, 3, 2);
                if (self->b43 != 0xB) {
                    func_003C3A10(self, 0xB, 0, (func_00382498(6, 0xE) * 5 + 2) / 6);
                }
                if (func_00382468(2)) {
                    if (p->w2DC == 0) {
                        if (self->b43 != 0xC) {
                            func_003C3A10(self, 0xC, 0, (func_00382498(6, 0xE) * 5 + 2) / 6);
                        }
                    }
                }
                break;
            }
        }
        if (p->w2D8 != 0) {
            if (func_0038CB00(&p->h2D6)) {
                func_L01_004450F0(self, 2, 1);
                p->w2D8 = 0;
                if (p->w2D0 < 0xFA) {
                    p->w2D0 = (func_00382498(0x1E0, 0x258) * 5 + 2) / 6;
                }
            }
        }
        break;
    case 1:
        if (p->h234 == 1) {
            if (self->b43 != 7) {
                func_003C3A10(self, 7, 0, 0x11);
            }
            func_L01_004450F0(self, 8, 2);
        } else if (p->w2D0 == 0) {
            func_L01_004450F0(self, 1, 0);
        }
        break;
    case 2:
        if (p->h234 != 1) {
            if (self->b20 != 3 && self->b20 != 8 && self->b20 != 9) {
                if (self->b43 != 0xF) {
                    func_003C3A10(self, 0xF, 0, 0x15);
                }
                func_L01_004450F0(self, 2, 1);
                p->w2D0 = (func_00382498(0x244, 0x258) * 5 + 2) / 6;
            }
        }
        break;
    case 3:
        fl = func_L01_00454370(self, p->a160);
        if (func_L01_004561E0(self)) {
            if (self->b43 == 0x10) {
                func_003A52A0(4, 0, self);
            }
        }
        if (self->b42 == 2 || self->b42 == 0x10) {
            if (func_L01_0044E1B8(self, 25.0f)) {
                h = func_003C3D30(&self->x, 0, self, 2.0f) + 0.2f;
                *(s128_350478 *)&v[0] = *(s128_350478 *)&self->x;
                v[0].z = h - 0.2f;
                func_L01_003016B0(v, 9.0f, 1.025f, 3);
                func_L01_003016B0(v, 9.0f, 1.025f, 3);
                for (i = 0x13; i >= 0; i--) {
                    f32 ang = func_00382538();
                    f32 mag = func_003824E0(0.0f, 0.060000002f);
                    v[1].x = func_0038D098(ang) * mag;
                    v[1].y = func_0038D0B0(ang) * mag;
                    v[1].z = func_003824E0(0.060000002f, 0.16000001f);
                    v[2].x = v[0].x + v[1].x * 8.0f;
                    v[2].y = v[0].y + v[1].x * 8.0f;
                    v[2].z = h - func_003824E0(0.0f, 0.2f);
                    r = func_00382468(2);
                    func_L01_00468A68(v, &v[1], r, func_00382498(0x5A, 0x78));
                }
            }
        }
        fl2 = fl & 1;
        if (((u8)fl2 && self->b42 != 0x10) ||
            (self->b42 == 0x10 && func_L01_0044E1B8(self, 38.0f))) {
            func_L02_003516A8((s32)self);
            func_L01_00315900(self, 0, 0);
            return;
        }
        if (fl & 2) {
            if (0.0f < p->f30) {
                if (self->b43 != 4) {
                    func_003C3A10(self, 4, 0, 8);
                }
                if (p->h234 == 1) {
                    func_L01_004450F0(self, 4, 2);
                } else {
                    func_L01_004450F0(self, 2, 1);
                    p->w2D0 = (func_00382498(0x244, 0x258) * 5 + 2) / 6;
                }
            }
        }
        break;
    }
    switch (self->b20) {
    case 1:
        break;
    case 2:
        if (self->b42 == 0xF) {
            if (self->b60 & 2) {
                if (self->b43 != 1) {
                    func_003C3A10(self, 1, 0, 0x15);
                }
            }
        } else if (self->b42 == 1) {
            if (self->b60 & 2) {
                if (self->b43 != 0xF) {
                    func_003C3A10(self, 0xF, 0, 0x15);
                }
            }
        }
        break;
    case 3:
        if (self->b42 == 0xB) {
            if (func_L01_0044E1B8(self, 2.0f)) {
                h = func_003C3D30(&self->x, 0, self, 2.0f) + 0.2f;
                *(s128_350478 *)&v[0] = *(s128_350478 *)&self->x;
                v[0].z = h - 0.2f;
                func_L01_003016B0(v, 9.0f, 1.025f, 3);
                func_L01_003016B0(v, 9.0f, 1.025f, 3);
                for (j = 0x13; j >= 0; j--) {
                    f32 ang = func_00382538();
                    f32 mag = func_003824E0(0.0f, 0.060000002f);
                    v[1].x = func_0038D098(ang) * mag;
                    v[1].y = func_0038D0B0(ang) * mag;
                    v[1].z = func_003824E0(0.060000002f, 0.16000001f);
                    v[2].x = v[0].x + v[1].x * 8.0f;
                    v[2].y = v[0].y + v[1].x * 8.0f;
                    v[2].z = h - func_003824E0(0.0f, 0.2f);
                    r = func_00382468(2);
                    func_L01_00468A68(v, &v[1], r, func_00382498(0x5A, 0x78));
                }
            }
        }
        func_L01_0045BD10(self, func_0038D160(p->f220 - self->x, p->f224 - self->y));
        if (self->b60 & 2) {
            if (func_0038CF38(&self->x, &p->f220) < 9.0f) {
                if (self->b43 != 6) {
                    func_003C3A10(self, 6, 0, 8);
                }
                func_L01_004450F0(self, 6, -1);
            } else {
                if (self->b43 != 7) {
                    func_003C3A10(self, 7, 0, (func_00382498(0xA, 0xF) * 5 + 2) / 6);
                }
                func_L01_004450F0(self, 8, -1);
            }
        }
        break;
    case 4:
        func_L01_0045BD10(self, func_0038D160(p->f220 - self->x, p->f224 - self->y));
        if (func_0038CF38(&self->x, &p->f220) < 9.0f) {
            if (self->b43 != 6) {
                func_003C3A10(self, 6, 0, 8);
            }
            func_L01_004450F0(self, 6, -1);
        } else {
            if (self->b43 != 7) {
                func_003C3A10(self, 7, 0, (func_00382498(8, 0x14) * 5 + 2) / 6);
            }
            func_L01_004450F0(self, 8, -1);
        }
        break;
    case 5:
        func_L01_0045A748(self, &p->f220);
        if (func_0038CF38(&self->x, &p->f220) < 7.0f) {
            if (self->b43 != 6) {
                func_003C3A10(self, 6, 0, 8);
            }
            func_L01_004450F0(self, 6, -1);
        }
        break;
    case 6:
        func_L01_0045BD10(self, func_0038D160(p->f220 - self->x, p->f224 - self->y));
        if (self->b60 & 2) {
            func_L01_004450F0(self, 7, -1);
            if (self->b43 != 9) {
                func_003C3A10(self, 9, 0, 3);
            }
        }
        break;
    case 7:
        if (self->b60 & 2) {
            func_L01_004450F0(self, 0xA, -1);
            if (self->b43 != 0xF) {
                func_003C3A10(self, 0xF, 6, 0x19);
            }
        }
        if (func_L01_004395E0(self) < 3.0f || 18.0f < func_L01_004395E0(self)) {
            func_L01_0045BD10(self, func_0038D160(p->f220 - self->x, p->f224 - self->y));
        }
        if (func_L01_004395E0(self) < 10.0f) {
            func_L01_004468C8((u8 *)self, 1, 1.75f, 0x10008, (f32)p->b45, 2.5f, 0, 1, 0);
            func_L01_004468C8((u8 *)self, 2, 1.5f, 0x10008, (f32)p->b45, 2.5f, 0, 1, 0);
        }
        break;
    case 8:
        func_L01_0045BD10(self, func_0038D160(p->f220 - self->x, p->f224 - self->y));
        if (self->b60 & 2) {
            func_L01_004450F0(self, 9, -1);
            if (self->b43 != 0xA) {
                func_003C3A10(self, 0xA, 0, 8);
            }
        }
        break;
    case 9:
        func_L01_0045BD10(self, func_0038D160(p->f220 - self->x, p->f224 - self->y));
        if (func_L01_0044E1B8(self, 32.0f)) {
            if (self->b42 == 0xA) {
                func_L01_004450F0(self, 0xA, -1);
                if (self->b43 != 0xF) {
                    func_003C3A10(self, 0xF, 4, (func_00382498(0x19, 0x1E) * 5 + 2) / 6);
                }
                if (func_00382468(6) == 0) {
                    if (self->b43 != 0) {
                        func_003C3A10(self, 0, 0xA, 0x19);
                    }
                }
            }
        }
        if (func_L01_0044E1B8(self, 8.0f)) {
            func_003C2F58(self, 0, v);
            vec_sub_ab(&v[1], &p->f220, v);
            func_0038CF68(&v[1], &v[1], 0.6f);
            func_L02_0039CD18(self, &v[1], v, (f32)p->b44, 0);
        }
        break;
    case 10:
        if (func_L01_004561B8(self)) {
            self->f48 = func_003824E0(0.85f, 1.15f);
        }
        func_L01_0045BD10(self, func_0038D160(p->f220 - self->x, p->f224 - self->y));
        if (self->b60 & 2) {
            func_L01_004450F0(self, 4, -1);
            if (self->b43 != 0xD) {
                func_003C3A10(self, 0xD, 0, 0x15);
            }
        }
        break;
    }
    func_L02_003516C8((u8 *)self);
}
/* localdecomp:end func_L02_00350478 */

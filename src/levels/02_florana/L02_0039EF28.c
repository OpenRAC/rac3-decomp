#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L02_0039EF28 */
typedef int u128_t __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_39EF28;
typedef struct {
    s16 f0, f2, f4, f6;
    union {
        unsigned long q8;
        struct { s16 f8; u8 fA, fB; s32 fC; } s;
    } u;
    V4_39EF28 v[4];
} P_39EF28;
typedef struct { u8 pad[0x18]; u8 f18; u8 f19; u16 f1A; u8 pad1C[4]; } S_39EF28;
typedef struct {
    u8 pad0[0x10];
    V4_39EF28 pos;
    u8 state;
    u8 pad21[0x47];
    P_39EF28 *p;
    u8 pad70[0x3E];
    u16 fAA;
    u8 padAC[0xC];
    s32 fB8;
} O_39EF28;
typedef struct { u8 pad[0x35C]; s32 f35C; s32 f360; } G_39EF28;
typedef struct { u8 pad[0xD0]; u8 fD0; u8 padD1[0xB]; void *fDC; u8 padE0[0x20]; } E_39EF28;

extern void func_L02_0039F7D8(void *);
extern void func_L01_004450F0(void *, s32, s32);
extern s32 func_0038CB00(void *);
extern void func_L01_00470150(void *, s32, s32, s32, s32, s32, f32, f32, s32, s32, f32, s32, s32);
extern f32 func_L01_00443A18(f32, f32);
extern f32 func_003824E0(f32, f32);
extern f32 func_0038CF38(void *, void *);
extern s32 func_00382498(s32, s32);
extern s32 func_00382468(s32);
extern u8 *func_L01_0046FB40(void *, void *, s32, s32, s32, s32, s32, f32, f32, s32, f32);
extern void func_L01_00466F50(void *, void *, s32, f32, f32);
extern s32 func_L01_0041A4F0(void);
extern void func_L01_00446748(void *, void *, s32, f32);
extern void func_003D4D00(void *, s32, s32, S_39EF28 *, f32);
extern s32 func_L01_004AA710(void *, s32);
extern s32 func_003A52A0(s32, s32, void *);
extern void func_003A4F28(s32);
extern u8 D_001A30B0[];
extern u8 D_L02_001E1300[];
extern G_39EF28 D_001A4BE0;
extern f32 D_L02_002EF1F0[];
extern u8 *D_L02_0021E134[];
__asm__(".extern D_L02_0021E134, 16");
extern s32 D_001D545C_sda;
__asm__(".extern D_001D545C_sda, 4");

void func_L02_0039EF28(O_39EF28 *self) {
    P_39EF28 *p;
    V4_39EF28 v;
    V4_39EF28 w;
    S_39EF28 s;
    u8 *rr;
    f32 f;
    int i, j;
    s32 far;
    f32 g;
    char buf[0x10];
    func_L02_0039F7D8(self);
    p = self->p;
    if ((p->u.q8 & 0xFF00FFFF) != 0xFFFF) {
        switch (self->state) {
        case 3:
            if ((p->u.q8 & 0xFFFF0000) == 0) {
                func_L01_004450F0(self, 3, -1);
                p->f0 = (p->u.s.f8 * 5 + 2) / 6;
            } else if (func_0038CB00(p) != 0) {
                func_L01_004450F0(self, 4, -1);
                p->f0 = (p->f2 * 5 + 2) / 6;
            } else if (p->f4 != 30 && p->f0 + p->f2 < 33) {
                *(u128_t *)&w = 0;
                w.z = func_003824E0(0.3f, 0.7f) * 0.020000001f;
                v = w;
                f = func_003824E0(0.4f, 0.7f) * 210000.0f;
                j = func_00382468(4);
                rr = func_L01_0046FB40(&p->v[j], &v, (func_00382498(20, 30) * 5 + 2) / 6, 0x10101, 1, 0x30, 0, f, f, 0, -0.0002f);
                if (rr != 0) {
                    rr[2] = D_L02_0021E134[0][0];
                    rr[3] = 0x44;
                }
            }
            break;
        case 4:
            if ((p->u.q8 & 0xFFFF0000) == 0) {
                func_L01_004450F0(self, 3, -1);
                p->f0 = (p->u.s.f8 * 5 + 2) / 6;
            } else if (func_0038CB00(p) != 0) {
                func_L01_004450F0(self, 5, -1);
                p->f0 = (p->f4 * 5 + 2) / 6;
                v = self->pos;
                v.z += 4.5f;
                func_L01_00470150(&v, 0, 0x10204070, -1, 1, (p->f4 * 5 + 2) / 6, 1.47e+06f, 1.0f, 0, -1, 1.0f, 0, 0);
                for (i = 0; i < 4; i++) {
                    func_L01_00470150(&p->v[i], 0, 0x30103060, -1, 1, (p->f4 * 5 + 2) / 6, 3.15e+05f, 1.0f, 0, -1, 1.0f, 0, 0);
                }
            } else if (p->f4 != 30 && p->f0 < 33) {
                *(u128_t *)&w = 0;
                w.z = func_003824E0(0.3f, 0.7f) * 0.020000001f;
                v = w;
                f = func_003824E0(0.4f, 0.7f) * 210000.0f;
                j = func_00382468(4);
                rr = func_L01_0046FB40(&p->v[j], &v, (func_00382498(20, 30) * 5 + 2) / 6, 0x10101, 1, 0x30, 0, f, f, 0, -0.0002f);
                if (rr != 0) {
                    rr[2] = D_L02_0021E134[0][0];
                    rr[3] = 0x44;
                }
            }
            break;
        case 5:
            if ((p->u.q8 & 0xFFFF0000) == 0) {
                func_L01_004450F0(self, 3, -1);
                p->f0 = (p->u.s.f8 * 5 + 2) / 6;
            } else if (func_0038CB00(p) != 0) {
                func_L01_004450F0(self, 6, -1);
                p->f0 = (p->f2 * 5 + 2) / 6;
                if (p->u.s.fC != -1) {
                    u8 *e = (u8 *)D_001A30B0 + (p->u.s.fC << 7);
                    if (*(void **)(e + 0xDC) == self && e[0xD0] != 0) {
                        func_003A4F28(p->u.s.fC);
                    }
                }
                p->u.s.fC = -1;
            } else {
                *(u128_t *)&w = 0;
                w.x = func_L01_00443A18(0.0f, 0.02f);
                w.y = func_L01_00443A18(0.0f, 0.02f);
                w.z = func_003824E0(4.0f, 6.0f) * 0.020000001f;
                v = w;
                far = func_0038CF38(&self->pos, D_L02_001E1300) > 18.0f;
                if (far == 0) {
                    f = func_003824E0(0.4f, 0.8f) * 2.1e+05f;
                    g = f * 0.25f;
                    for (i = 0; i < 4; i++) {
                        func_L01_0046FB40(&p->v[i], &v, (func_00382498(10, 20) * 5 + 2) / 6, 0x7F7F7F, 1, 0x7F, 0, f, g, 0, -0.003f);
                    }
                    if (func_00382468(2) == 0) {
                        func_L01_00466F50(&p->v[func_00382468(4)], &v, 0, -1.0f, 0.0f);
                    }
                } else {
                    f = func_003824E0(0.5f, 0.9f) * 2.1e+05f;
                    g = f * 0.25f;
                    for (j = 0; j < 4; j++) {
                        if (func_00382468(2) == 0) {
                            func_L01_0046FB40(&p->v[j], &v, (func_00382498(10, 20) * 5 + 2) / 6, 0x7F7F7F, 1, 0x7F, 0, f, g, 0, -0.003f);
                        }
                    }
                }
                func_L01_00446748(&s, self, 0x10001, func_L01_0041A4F0() != 0 ? D_L02_002EF1F0[D_001D545C_sda] : 1.0f);
                w = self->pos;
                w.z += 3.0f;
                s.f18 = 0;
                s.f19 = 1;
                s.f1A = self->fAA;
                func_003D4D00(&w, 0, self->fB8, &s, 1.5f);
                if (func_L01_004AA710(self, p->u.s.fC) == 0) {
                    p->u.s.fC = func_003A52A0(0, 4, self);
                }
            }
            break;
        case 6:
            if ((p->u.q8 & 0xFFFF0000) == 0) {
                func_L01_004450F0(self, 3, -1);
                p->f0 = (p->u.s.f8 * 5 + 2) / 6;
            }
            if (func_0038CB00(p) != 0) {
                if (p->u.s.fB != 0) {
                    func_L01_004450F0(self, 2, -1);
                } else if (p->u.s.fA != 0) {
                    func_L01_004450F0(self, 3, -1);
                    p->f0 = (p->f6 * 5 + 2) / 6;
                } else {
                    func_L01_004450F0(self, 1, -1);
                }
            } else if (!(func_0038CF38(&self->pos, D_L02_001E1300) > 18.0f)) {
                *(u128_t *)&w = 0;
                w.z = func_003824E0(0.3f, 0.7f) * 0.020000001f;
                v = w;
                f = func_003824E0(0.4f, 0.7f) * 210000.0f;
                j = func_00382468(4);
                rr = func_L01_0046FB40(&p->v[j], &v, (func_00382498(20, 30) * 5 + 2) / 6, 0x10101, 1, 0x30, 0, f, f, 0, -0.0002f);
                if (rr != 0) {
                    rr[2] = D_L02_0021E134[0][0];
                    rr[3] = 0x44;
                }
            }
            break;
        case 1:
            if (p->u.s.fA != 0) {
                func_L01_004450F0(self, 3, -1);
                p->u.s.fA = 0;
                p->f0 = (p->u.s.f8 * 5 + 2) / 6;
            }
            break;
        case 2:
            if (D_001A4BE0.f35C == (s32)self && D_001A4BE0.f360 >= 2) {
                func_L01_004450F0(self, 3, -1);
                p->f0 = (p->f6 * 5 + 2) / 6;
            }
            break;
        }
    }
}
/* localdecomp:end func_L02_0039EF28 */

/* localdecomp:start func_L02_0039F7D8 */
extern void func_0038D890(void *, void *, void *, f32);

void func_L02_0039F7D8(void *arg) {
    u8 *self = arg;
    u8 *d;
    vu0_v4 axis;
    vu0_v4 *p;
    s32 i;

    if (self[0x20] != 0) return;
    d = *(u8 **)(self + 0x68);
    *(u128_t *)&axis = 0;
    for (i = 0; i < 4; i++) {
        p = (vu0_v4 *)(d + 0x10) + i;
        p->y = 0.0f;
        p->w = 0.0f;
        p->x = 1.0f;
        p->z = 3.0f;
        axis.z = 1.0f;
        func_0038D890(p, p, &axis, *(f32 *)(self + 0xF8) + -0.7853982f + (f32)i * 1.5707964f);
        axis.z = 0.0f;
        if (*(f32 *)(self + 0xF4) != 0.0f) {
            axis.y = 1.0f;
            func_0038D890(p, p, &axis, *(f32 *)(self + 0xF4));
            axis.y = 0.0f;
            p->x += 0.3f;
            p->y += 0.3f;
        }
        vec_add_ab(p, p, self + 0x10);
    }
    self[0x20] = d[0xB] ? 2 : 1;
    self[0x30] = 0xFF;
    *(s16 *)d = (*(s16 *)(d + 8) * 5 + 2) / 6;
}
/* localdecomp:end func_L02_0039F7D8 */

/* localdecomp:start func_L02_0039F980 */
extern u8 D_001A4C60[];
extern u8 D_L02_001DDC70;
extern u8 D_L02_001DDC80;
extern u8 D_L02_001DDC90;
__asm__(".extern D_L02_001DDC70, 4");
__asm__(".extern D_L02_001DDC80, 4");
__asm__(".extern D_L02_001DDC90, 4");
extern void func_003C6680(void *, void *, s32, s32, void *, s32, s32, s32, void *, void *, s32);
extern void func_003C6990(void *, void *, s32);
extern void func_003C4DA8(void *, void *, void *, void *);
extern s32 func_00382380(void *, s32, s32);
extern f32 func_003C4138(f32 *, f32, f32);

void func_L02_0039F980(u8 *self) {
    u8 *d = *(u8 **)(self + 0x68);
    vu0_v4 pos, rot, dp;

    if (d == 0) return;
    pos = *(vu0_v4 *)(self + 0x10);
    rot = *(vu0_v4 *)(self + 0xF0);
    if (self[0x20] == 0) {
        func_003C6680(self, d + 0x70, 0, 0, &D_L02_001DDC70, 0, 0, 0, &D_L02_001DDC90, &D_L02_001DDC80, 0);
    } else if (self[0x20] == 2) {
        func_003C6990(self, d + 0x70, 0);
    }
    vec_sub_ab(&dp, &pos, self + 0x10);
    func_003C4DA8(d + 0x30, &dp, &rot, self + 0xF0);
    if (self[0x20] == 0) {
        if (*(s32 *)(d + 0x130) != 0) {
            *(f32 *)(d + 0x138) = *(f32 *)(self + 0x18);
            self[0x20] = 1;
            *(f32 *)(self + 0x18) = *(f32 *)(self + 0x18) - 7.0f;
        } else {
            self[0x20] = 2;
        }
    }
    if (self[0x20] == 1) {
        if (func_00382380(D_001A4C60, *(s32 *)(d + 0x134), 0) != 0) {
            func_003C4138((f32 *)(self + 0x18), *(f32 *)(d + 0x138), 0.120000005f);
            if (*(f32 *)(self + 0x18) == *(f32 *)(d + 0x138)) self[0x20] = 2;
        }
    }
}
/* localdecomp:end func_L02_0039F980 */

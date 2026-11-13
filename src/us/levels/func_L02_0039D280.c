#include "common.h"

/* NTSC-U counterpart of func_L02_0039EF28 (src/levels/02_florana/L02_0039EF28.c) */
/* localdecomp:start func_L02_0039D280 */
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

extern void func_L02_0039DA50(void *);
extern void func_L01_00441FB8(void *, s32, s32);
extern s32 func_003883C8(void *);
extern void func_L01_0046CA58(void *, s32, s32, s32, s32, s32, f32, f32, s32, s32, f32, s32, s32);
extern f32 func_L01_00440918(f32, f32);
extern f32 func_0037E250(f32, f32);
extern f32 func_00388800(void *, void *);
extern s32 func_0037E208(s32, s32);
extern s32 func_0037E1D8(s32);
extern u8 *func_L01_0046C468(void *, void *, s32, s32, s32, s32, s32, f32, f32, s32, f32);
extern void func_L01_00463938(void *, void *, s32, f32, f32);
extern s32 func_L01_00417EA0(void);
extern void func_L01_00443610(void *, void *, s32, f32);
extern void func_003CF790(void *, s32, s32, S_39EF28 *, f32);
extern s32 func_L01_004A6D20(void *, s32);
extern s32 func_0039FE80(s32, s32, void *);
extern void func_0039FB08(s32);
extern u8 D_001A30B0[];
extern u8 D_L02_001E1380[];
extern G_39EF28 D_001A4BE0;
extern f32 D_L02_002EF270[];
extern u8 *D_L02_0021E1B4[];
__asm__(".extern D_L02_0021E1B4, 16");
extern s32 D_001D545C_sda_0039D280;
__asm__(".extern D_001D545C_sda_0039D280, 4");

void func_L02_0039D280(O_39EF28 *self) {
    P_39EF28 *p;
    V4_39EF28 v;
    V4_39EF28 w;
    S_39EF28 s;
    u8 *rr;
    f32 f;
    int i, j, k;
    s32 far;
    f32 g;
    char buf[0x10];
    func_L02_0039DA50(self);
    p = self->p;
    if ((p->u.q8 & 0xFF00FFFF) != 0xFFFF) {
        switch (self->state) {
        case 3:
            if ((p->u.q8 & 0xFFFF0000) == 0) {
                func_L01_00441FB8(self, 3, -1);
                p->f0 = p->u.s.f8;
            } else if (func_003883C8(p) != 0) {
                func_L01_00441FB8(self, 4, -1);
                p->f0 = p->f2;
            } else if (p->f4 != 30 && p->f0 + p->f2 < 40) {
                *(u128_t *)&w = 0;
                w.z = func_0037E250(0.3f, 0.7f) * 0.016666668f;
                v = w;
                f = func_0037E250(0.4f, 0.7f) * 210000.0f;
                j = func_0037E1D8(4);
                rr = func_L01_0046C468(&p->v[j], &v, func_0037E208(20, 30), 0x10101, 1, 0x30, 0, f, f, 0, -0.0002f);
                if (rr != 0) {
                    rr[2] = D_L02_0021E1B4[0][0];
                    rr[3] = 0x44;
                }
            }
            break;
        case 4:
            if ((p->u.q8 & 0xFFFF0000) == 0) {
                func_L01_00441FB8(self, 3, -1);
                p->f0 = p->u.s.f8;
            } else if (func_003883C8(p) != 0) {
                func_L01_00441FB8(self, 5, -1);
                p->f0 = p->f4;
                v = self->pos;
                v.z += 4.5f;
                func_L01_0046CA58(&v, 0, 0x10204070, -1, 1, p->f4, 1.47e+06f, 1.0f, 0, -1, 1.0f, 0, 0);
                for (k = 0; k < 4; k++) {
                    func_L01_0046CA58(&p->v[k], 0, 0x30103060, -1, 1, p->f4, 3.15e+05f, 1.0f, 0, -1, 1.0f, 0, 0);
                }
            } else if (p->f4 != 30 && p->f0 < 40) {
                *(u128_t *)&w = 0;
                w.z = func_0037E250(0.3f, 0.7f) * 0.016666668f;
                v = w;
                f = func_0037E250(0.4f, 0.7f) * 210000.0f;
                j = func_0037E1D8(4);
                rr = func_L01_0046C468(&p->v[j], &v, func_0037E208(20, 30), 0x10101, 1, 0x30, 0, f, f, 0, -0.0002f);
                if (rr != 0) {
                    rr[2] = D_L02_0021E1B4[0][0];
                    rr[3] = 0x44;
                }
            }
            break;
        case 5:
            if ((p->u.q8 & 0xFFFF0000) == 0) {
                func_L01_00441FB8(self, 3, -1);
                p->f0 = p->u.s.f8;
            } else if (func_003883C8(p) != 0) {
                func_L01_00441FB8(self, 6, -1);
                p->f0 = p->f2;
                if (p->u.s.fC != -1) {
                    u8 *e = (u8 *)D_001A30B0 + (p->u.s.fC << 7);
                    if (*(void **)(e + 0xDC) == self && e[0xD0] != 0) {
                        func_0039FB08(p->u.s.fC);
                    }
                }
                p->u.s.fC = -1;
            } else {
                *(u128_t *)&w = 0;
                w.x = func_L01_00440918(0.0f, 0.02f);
                w.y = func_L01_00440918(0.0f, 0.02f);
                w.z = func_0037E250(4.0f, 6.0f) * 0.016666668f;
                v = w;
                far = func_00388800(&self->pos, D_L02_001E1380) > 18.0f;
                if (far == 0) {
                    f = func_0037E250(0.4f, 0.8f) * 2.1e+05f;
                    g = f * 0.25f;
                    for (i = 0; i < 4; i++) {
                        func_L01_0046C468(&p->v[i], &v, func_0037E208(10, 20), 0x7F7F7F, 1, 0x7F, 0, f, g, 0, -0.003f);
                    }
                    if (func_0037E1D8(2) == 0) {
                        func_L01_00463938(&p->v[func_0037E1D8(4)], &v, 0, -1.0f, 0.0f);
                    }
                } else {
                    f = func_0037E250(0.5f, 0.9f) * 2.1e+05f;
                    g = f * 0.25f;
                    for (j = 0; j < 4; j++) {
                        if (func_0037E1D8(2) == 0) {
                            func_L01_0046C468(&p->v[j], &v, func_0037E208(10, 20), 0x7F7F7F, 1, 0x7F, 0, f, g, 0, -0.003f);
                        }
                    }
                }
                func_L01_00443610(&s, self, 0x10001, func_L01_00417EA0() != 0 ? D_L02_002EF270[D_001D545C_sda_0039D280] : 1.0f);
                w = self->pos;
                w.z += 3.0f;
                s.f18 = 0;
                s.f19 = 1;
                s.f1A = self->fAA;
                func_003CF790(&w, 0, self->fB8, &s, 1.5f);
                if (func_L01_004A6D20(self, p->u.s.fC) == 0) {
                    p->u.s.fC = func_0039FE80(0, 4, self);
                }
            }
            break;
        case 6:
            if ((p->u.q8 & 0xFFFF0000) == 0) {
                func_L01_00441FB8(self, 3, -1);
                p->f0 = p->u.s.f8;
            }
            if (func_003883C8(p) != 0) {
                if (p->u.s.fB != 0) {
                    func_L01_00441FB8(self, 2, -1);
                } else if (p->u.s.fA != 0) {
                    func_L01_00441FB8(self, 3, -1);
                    p->f0 = p->f6;
                } else {
                    func_L01_00441FB8(self, 1, -1);
                }
            } else if (!(func_00388800(&self->pos, D_L02_001E1380) > 18.0f)) {
                *(u128_t *)&w = 0;
                w.z = func_0037E250(0.3f, 0.7f) * 0.016666668f;
                v = w;
                f = func_0037E250(0.4f, 0.7f) * 210000.0f;
                j = func_0037E1D8(4);
                rr = func_L01_0046C468(&p->v[j], &v, func_0037E208(20, 30), 0x10101, 1, 0x30, 0, f, f, 0, -0.0002f);
                if (rr != 0) {
                    rr[2] = D_L02_0021E1B4[0][0];
                    rr[3] = 0x44;
                }
            }
            break;
        case 1:
            if (p->u.s.fA != 0) {
                func_L01_00441FB8(self, 3, -1);
                p->u.s.fA = 0;
                p->f0 = p->u.s.f8;
            }
            break;
        case 2:
            if (D_001A4BE0.f35C == (s32)self && D_001A4BE0.f360 >= 2) {
                func_L01_00441FB8(self, 3, -1);
                p->f0 = p->f6;
            }
            break;
        }
    }
}
/* localdecomp:end func_L02_0039D280 */

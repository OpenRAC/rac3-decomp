#include "common.h"

/* NTSC-U counterpart of func_L20_003E9E38 (src/levels/20_final_boss/L20_003E9AC0.c) */
#include "vu0.h"
#include "vu0.h"
extern u8 D_L20_001E2E00_003E7F28[];
extern f32 func_00388978(f32);
extern f32 func_0037E250(f32, f32);
extern f32 func_00389380(f32, f32);
extern void func_00389158(void *, void *, void *, f32);
extern void func_00388830(void *, void *, f32);

/* localdecomp:start func_L20_003E7F28 */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_003E9E38;

typedef struct {
    f32 f0;                         /* 0x000 */
    f32 f4;                         /* 0x004 */
    u8 pad8[0xC - 0x8];
    f32 fC;                         /* 0x00C */
    u8 pad10[0x14 - 0x10];
    u16 h14;                        /* 0x014 */
    s16 h16;                        /* 0x016 */
    s16 h18;                        /* 0x018 */
    s16 h1A;                        /* 0x01A */
    u16 h1C;                        /* 0x01C */
    u16 h1E;
    s16 timer;                      /* 0x020 */
    s16 h22;                        /* 0x022 */
    u8 pad24[0x2C - 0x24];
    f32 len;                        /* 0x02C */
    u8 pad30[0xC50 - 0x30];
    V4_003E9E38 pts[12];            /* 0xC50 */
    f32 ang[12];                    /* 0xD10 */
} S_003E9E38;

extern f32 func_00389380(f32, f32);
extern f32 func_0037E250(f32, f32);
extern f32 func_00388960(f32);
extern f32 func_00388978(f32);
extern void func_00388830(void *, void *, f32);
extern void func_00388758(void *, void *, void *);
extern void func_00389158(void *, void *, void *, f32);
extern f32 func_0037E2A8(void);
extern s32 func_003883C8(void *);
extern void func_0037E2F0(void *, f32, f32);
extern u8 *func_L01_0046FE70(void *, void *, s32, f32);
extern void func_L01_004026A0(void *, void *);
extern void func_L20_003E6638(u8 *);
extern void func_L20_003E6F58(u8 *m);
extern void func_L20_003E71B0(u8 *);
extern void func_L20_003E7C98(u8 *obj);
extern void func_L20_003E7BB0(u8 *p);
__asm__(".extern D_L20_001E2E00_003E7F28, 16");
extern s32 D_L20_001DF24C;
__asm__(".extern D_L20_001DF24C, 4");

/* d.xyz = qa - *b, with qa already in a VU0 register */
static __inline__ void sub_003E9E38(void *d, vu0_q qa, void *b) {
    vu0_q qb, qr;
    __asm__("lqc2 %0, %1" : "=j"(qb) : "m"(*(vu0_v4 *)b));
    __asm__("vsub.xyz %0, %1, %2" : "=j"(qr) : "j"(qa), "j"(qb));
    __asm__("sqc2 %1, %0" : "=m"(*(vu0_v4 *)d) : "j"(qr));
}

void func_L20_003E7F28(u8 *p) {
    S_003E9E38 *v = *(S_003E9E38 **)(p + 0x68);
    V4_003E9E38 a;
    V4_003E9E38 d;
    s32 i;
    s32 j;
    s32 k;
    u8 *ray;

    v->f0 = func_00389380(v->f0, 0.029088823f);
    v->f4 = func_00389380(v->f4, 0.08726647f);
    switch (p[0x20]) {
    case 0:
        for (i = 0; i < 12; i++) {
            v->ang[i] = func_0037E250(0.014544412f, 0.043633234f);
            v->len = 2.0f;
            a.x = func_00388960(*(f32 *)(p + 0xF8));
            a.y = func_00388978(*(f32 *)(p + 0xF8));
            a.z = 0.0f;
            vec_sub_ab(&d, ((f32 *)&D_L20_001E2E00_003E7F28), p + 0x10);
            func_00388830(&d, &d, 1.0f);
            func_00388758(&v->pts[i], &a, &d);
            func_00388830(&v->pts[i], &v->pts[i], v->len);
            func_00389158(&v->pts[i], &v->pts[i], &d, func_0037E2A8());
        }
        func_L20_003E6638(p);
        v->timer = v->h1C;
        p[0x20] = 2;
        v->fC = 2.5f;
        v->h18 = 1;
        v->h1A = 1;
        break;
    case 2:
        if (func_003883C8(&v->timer) != 0) {
            p[0x20] = 3;
            v->timer = v->h14;
            func_L20_003E6638(p);
        }
        break;
    case 3:
        if (func_003883C8(&v->timer) != 0) {
            if (v->h16 != 0) {
                p[0x20] = 2;
                v->timer = 5;
            } else {
                v->timer = 5;
            }
        } else if (v->h22 == 0) {
            func_L20_003E6638(p);
        }
        break;
    }
    for (j = 0; j < 1; j++) {
        vu0_q qp;

        func_0037E2F0(&a, 0.025f, 0.15f);
        vec_add_ba(&a, &a, p + 0x10);
        __asm__("lqc2 %0, %1" : "=j"(qp) : "m"(*(vu0_v4 *)(p + 0x10)));
        sub_003E9E38(&d, qp, &a);
        func_00388830(&d, &d, 0.012500001f);
        ray = func_L01_0046FE70(&a, &d, 0xF, 3.0f);
        if (ray != 0) {
            *(u32 *)(ray + 4) = 0xFF20FF20;
        }
    }
    for (k = 0; k < 1; k++) {
        vu0_q qp;

        func_0037E2F0(&a, 0.025f, 0.15f);
        vec_add_ba(&a, &a, p + 0x10);
        __asm__("lqc2 %0, %1" : "=j"(qp) : "m"(*(vu0_v4 *)(p + 0x10)));
        sub_003E9E38(&d, qp, &a);
        func_00388830(&d, &d, 0.012500001f);
        ray = func_L01_0046FE70(&a, &d, 0xF, 1.5f);
        if (ray != 0) {
            *(u32 *)(ray + 4) = 0x7FFFFFFF;
        }
    }
    func_L01_004026A0(func_L20_003E7BB0, p);
    func_L01_004026A0(func_L20_003E7C98, p);
    if (v->h22 != 0) {
        func_L20_003E6F58(p);
        if (D_L20_001DF24C < v->h22) {
            func_L01_004026A0(func_L20_003E71B0, p);
        }
    }
}
/* localdecomp:end func_L20_003E7F28 */

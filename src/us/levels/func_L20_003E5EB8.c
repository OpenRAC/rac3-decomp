#include "common.h"

/* NTSC-U counterpart of func_L20_003E7D00 (src/levels/20_final_boss/L20_003E6150.c) */
#include "vu0.h"
extern void func_00388830(void *, void *, f32);
extern void func_00388758(void *, void *, void *);
extern s32 D_L20_001DF1A4_003E5EB8;
#include "vu0.h"
extern u8 D_L20_001E2E00_003E5EB8[];
extern f32 func_00388978(f32);
extern f32 func_0037E250(f32, f32);
extern f32 func_00389380(f32, f32);
extern void func_00389158(void *, void *, void *, f32);
extern void func_00388830(void *, void *, f32);

/* localdecomp:start func_L20_003E5EB8 */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_003E7D00;

typedef struct {
    f32 f0;                     /* 0x000 */
    f32 f4;                     /* 0x004 */
    u8 pad8[0xC - 0x8];
    f32 fC;                     /* 0x00C */
    u8 pad10[0x14 - 0x10];
    s16 h14;                    /* 0x014 */
    s16 h16;                    /* 0x016 */
    s16 h18;                    /* 0x018 */
    s16 h1A;                    /* 0x01A */
    u16 i1C; u16 pad1E;                    /* 0x01C */
    s16 timer;                  /* 0x020 */
    s16 h22;                    /* 0x022 */
    u8 pad24[0x2C - 0x24];
    f32 f2C;                    /* 0x02C */
    u8 pad30[0xC50 - 0x30];
    V4_003E7D00 q[12];          /* 0xC50 */
    f32 r[12];                  /* 0xD10 */
} V_003E7D00;

typedef struct {
    u8 pad0[0x80];
    f32 x;                      /* 0x80 */
    f32 y;                      /* 0x84 */
} G_003E7D00;

extern void func_003BD360(void *);
extern f32 func_00388A28(f32, f32);
extern f32 func_L01_00440918(f32, f32);
extern f32 func_00389380(f32, f32);
extern f32 func_00388960(f32);
extern f32 func_00388978(f32);
extern f32 func_0037E250(f32, f32);
extern void func_00388830(void *, void *, f32);
extern s32 func_L01_004A72A8(s32, s32, void *, s32);
extern u8 *func_L20_003E9448_003E5EB8(void *, void *, f32 *, f32, s32);
extern void func_L20_003E45C8(void *);
extern s32 func_003883C8(void *);
extern void func_00388758(void *, void *, void *);
extern f32 func_0037E2A8(void);
extern void func_00389158(void *, void *, void *, f32);
extern void func_0037E2F0(void *, f32, f32);
extern u8 *func_L01_0046FE70(void *, void *, s32, f32);
extern void func_L01_004026A0(void *, void *);
extern void func_L20_003E4EE8(u8 *m);
extern void func_L20_003E5140(void);
extern void func_L20_003E5B40(u8 *p);
extern void func_L20_003E5C28(u8 *a0);
extern s32 D_L20_001DFD40_003E5EB8;
extern G_003E7D00 D_001A4BE0_003E5EB8;
__asm__(".extern D_L20_001E2E00_003E5EB8, 16");
extern s32 D_L20_001DF1A4_003E5EB8;
__asm__(".extern D_L20_001DF1A4_003E5EB8, 4");

void func_L20_003E5EB8(u8 *p) {
    V_003E7D00 *v = *(V_003E7D00 **)(p + 0x68);
    V4_003E7D00 pos;
    V4_003E7D00 dir;
    V4_003E7D00 a;
    u8 *e;
    s32 i;
    s32 j;
    s32 k;

    *(u16 *)(p + 0x96) += 1;
    if (*(u16 *)(p + 0x96) >= 0x97) {
        func_003BD360(p);
        return;
    }
    if ((D_L20_001DFD40_003E5EB8 & 7) == (((s32)p >> 8) & 7)) {
        pos = *(V4_003E7D00 *)(p + 0x10);
        a.x = func_00388960(func_00389380(func_00388A28(D_001A4BE0_003E5EB8.x - *(f32 *)(p + 0x10),
                                                        D_001A4BE0_003E5EB8.y - *(f32 *)(p + 0x14)),
                                          func_L01_00440918(5.0f, 25.0f) * 0.017453292f));
        a.y = func_00388978(func_00389380(func_00388A28(D_001A4BE0_003E5EB8.x - *(f32 *)(p + 0x10),
                                                        D_001A4BE0_003E5EB8.y - *(f32 *)(p + 0x14)),
                                          func_L01_00440918(5.0f, 25.0f) * 0.017453292f));
        a.z = 0.0f;
        func_00388830(&dir, &a, func_0037E250(10.0f, 15.0f) * 0.0166666675f);
        func_L01_004A72A8(0x14, 0, p, 0x1AFD);
        func_L20_003E9448_003E5EB8(p, &pos, &dir.x, 45.0f, 0);
    }
    v->f0 = func_00389380(v->f0, 0.0290888231f);
    v->f4 = func_00389380(v->f4, 0.0872664675f);
    switch (p[0x20]) {
    case 0:
        for (i = 0; i < 12; i++) {
            v->r[i] = func_0037E250(0.0145444116f, 0.0436332338f);
            v->f2C = 2.0f;
            pos.x = func_00388960(*(f32 *)(p + 0xF8));
            pos.y = func_00388978(*(f32 *)(p + 0xF8));
            pos.z = 0.0f;
            vec_sub_ba(&dir, ((f32 *)&D_L20_001E2E00_003E5EB8), p + 0x10);
            func_00388830(&dir, &dir, 1.0f);
            func_00388758(&v->q[i], &pos, &dir);
            func_00388830(&v->q[i], &v->q[i], v->f2C);
            func_00389158(&v->q[i], &v->q[i], &dir, func_0037E2A8());
        }
        func_L20_003E45C8(p);
        v->timer = v->i1C;
        p[0x20] = 2;
        v->fC = 2.5f;
        v->h18 = 1;
        v->h1A = 1;
        break;
    case 2:
        if (func_003883C8(&v->timer)) {
            p[0x20] = 3;
            v->timer = (u16)v->h14;
            func_L20_003E45C8(p);
        }
        break;
    case 3:
        if (func_003883C8(&v->timer)) {
            if (v->h16 != 0) {
                p[0x20] = 2;
                v->timer = 5;
            } else {
                v->timer = 5;
            }
        } else if (v->h22 == 0) {
            func_L20_003E45C8(p);
        }
        break;
    }
    for (j = 0; j < 1; j++) {
        vu0_q qx, qy, qd;

        func_0037E2F0(&pos, 0.025f, 0.15f);
        __asm__("lqc2 %0, %1" : "=j"(qx) : "m"(*(vu0_v4 *)(p + 0x10)));
        vec_add_ba(&pos, &pos, p + 0x10);
        __asm__("lqc2 %0, %1" : "=j"(qy) : "m"(pos));
        __asm__("vsub.xyz %0, %1, %2" : "=j"(qd) : "j"(qx), "j"(qy));
        __asm__("sqc2 %1, %0" : "=m"(dir) : "j"(qd));
        func_00388830(&dir, &dir, 0.0125000011f);
        e = func_L01_0046FE70(&pos, &dir, 0xF, 3.0f);
        if (e != 0) {
            *(u32 *)(e + 4) = 0xFF2020FF;
        }
    }
    for (k = 0; k < 1; k++) {
        vu0_q qx, qy, qd;

        func_0037E2F0(&pos, 0.025f, 0.15f);
        __asm__("lqc2 %0, %1" : "=j"(qx) : "m"(*(vu0_v4 *)(p + 0x10)));
        vec_add_ba(&pos, &pos, p + 0x10);
        __asm__("lqc2 %0, %1" : "=j"(qy) : "m"(pos));
        __asm__("vsub.xyz %0, %1, %2" : "=j"(qd) : "j"(qx), "j"(qy));
        __asm__("sqc2 %1, %0" : "=m"(dir) : "j"(qd));
        func_00388830(&dir, &dir, 0.0125000011f);
        e = func_L01_0046FE70(&pos, &dir, 0xF, 1.5f);
        if (e != 0) {
            *(u32 *)(e + 4) = 0x7FFFFFFF;
        }
    }
    func_L01_004026A0(func_L20_003E5B40, p);
    func_L01_004026A0(func_L20_003E5C28, p);
    if (v->h22 != 0) {
        func_L20_003E4EE8(p);
        if (D_L20_001DF1A4_003E5EB8 < v->h22) {
            func_L01_004026A0(func_L20_003E5140, p);
        }
    }
}
/* localdecomp:end func_L20_003E5EB8 */

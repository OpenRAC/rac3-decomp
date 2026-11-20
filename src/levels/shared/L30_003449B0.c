#include "common.h"

/* declared by functions of L30_00344610.c, which this file was cut from */
extern s32 D_L30_001DF2C0;
extern s32 func_L01_004561B8(void *);
extern void func_003A52A0(s32, s32, void *);
extern f32 func_L03_0034B148(s32, s32, f32);
extern s32 func_0038CAD0(void *);
extern void func_L01_004450F0(void *, s32, s32);
extern void func_L01_004AA7E8(void *, s32);

/* localdecomp:start func_L30_003449B0 */
#include "vu0.h"

typedef struct {
    f32 x, y, z, w;
} __attribute__((aligned(16))) V4_003449B0;

typedef struct {
    u8 pad0[0x130];
    V4_003449B0 v130;
    V4_003449B0 v140;
    V4_003449B0 v150;
    f32 f160;
    f32 f164;
    u8 pad168[0x170 - 0x168];
    f32 f170;
    u8 pad174[0x178 - 0x174];
    f32 f178;
    s32 f17C;
    s32 f180;
    u8 pad184[0x18C - 0x184];
    s32 f18C;
    s32 f190;
    u8 pad194[0x1A4 - 0x194];
    f32 f1A4;
    f32 f1A8;
} S_003449B0;

extern void func_0038CE20(void *, void *, f32);
extern f32 func_0038CE68(void *, void *);
extern f32 func_0038CEA8(void *);
extern f32 func_0038D0B0(f32);
extern s32 func_L01_003303B8(u8 *, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32,
    s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern void func_L30_00343798(u8 *, f32);
extern s32 func_L05_00328FF8(u8 *);
extern s32 D_L30_001DCEDC; __asm__(".extern D_L30_001DCEDC, 4");
extern f32 D_L30_001DCED8; __asm__(".extern D_L30_001DCED8, 4");

void func_L30_003449B0(u8 *a0) {
    S_003449B0 *s = *(S_003449B0 **)(a0 + 0x68);
    V4_003449B0 d;
    V4_003449B0 r;
    f32 f;
    u8 *p;
    vu0_q qa, qb, qc, qd;

    switch (a0[0x20]) {
    case 6:
        if (func_L01_004561B8(a0)) {
            *(f32 *)(a0 + 0xF4) = 0.0f;
            s->f164 = 0.0f;
            s->f160 = 0.0f;
            if (*(s16 *)(a0 + 0xAA) == 0x19B9) {
                func_003A52A0(2, 0, a0);
            }
            if (*(s16 *)(a0 + 0xAA) == 0x1745) {
                func_003A52A0(5, 0, a0);
            }
        }
        s->f164 += s->f170;
        if (s->f178 < s->f164) {
            s->f164 = s->f178;
        }
        s->f160 += s->f164;
        if (1.0f < s->f160) {
            s->f160 = 1.0f;
        }
        vec_sub_ba(&d, &s->v150, &s->v140);
        func_0038CE20(&d, &d, s->f160);
        __asm__("lqc2 %0, %1" : "=j"(qa) : "m"(s->v140));
        __asm__("lqc2 %0, %1" : "=j"(qb) : "m"(d));
        __asm__("vadd.xyz %0, %1, %2" : "=j"(qa) : "j"(qa), "j"(qb));
        __asm__("sqc2 %1, %0" : "=m"(s->v130) : "j"(qa));
        __asm__("lqc2 %0, %1" : "=j"(qc) : "m"(s->v150));
        __asm__("lqc2 %0, %1" : "=j"(qd) : "m"(s->v130));
        __asm__("vsub.xyz %0, %1, %2" : "=j"(qc) : "j"(qc), "j"(qd));
        __asm__("sqc2 %1, %0" : "=m"(r) : "j"(qc));
        if (func_0038CE68(&d, &r) < 0.0f || func_0038CEA8(&r) < 0.001f) {
            func_L01_004450F0(a0, 7, -1);
        }
        break;
    case 7:
        if (func_L01_004561B8(a0)) {
            if (*(s16 *)(a0 + 0xAA) == 0x1745) {
                func_003A52A0(2, 0, a0);
            }
            if (*(s16 *)(a0 + 0xAA) == 0x19B9) {
                func_003A52A0(3, 0, a0);
            }
            s->f180 = s->f18C;
            func_L01_003303B8(a0 + 0x10, 1, 0x19, 0x14, 0x14, 0x14, 0x2D, 2, 1.0f, 0.0f, 0.0f, 2.0f,
                1, 1, 1, 0, 1, 0, 0x1010000, 0, 0x388EF7, 0x63F7, 0x407FFF, 0x20FF, 0x8FFF, 0x3064FF,
                0x7F60A0FF, 0x280000FF, 0x3064FF, 0);
            *(u16 *)(a0 + 0x34) = (*(u16 *)(a0 + 0x34) | 0x41) & ~0x1000;
            *(s32 *)(a0 + 0x98) = 0;
            func_L01_004AA7E8(a0, 1);
        }
        if (func_0038CAD0(&s->f180)) {
            func_L01_004450F0(a0, 10, -1);
        }
        break;
    case 8:
        if (func_L01_004561B8(a0)) {
            s->f180 = s->f17C;
            if (*(s16 *)(a0 + 0xAA) == 0x1745) {
                func_003A52A0(3, 0, a0);
            }
            if (*(s16 *)(a0 + 0xAA) == 0x19B9) {
                func_003A52A0(1, 0, a0);
            }
        }
        s->f160 = 0.0f;
        func_L30_00343798(a0, s->f160);
        f = (f32)D_L30_001DF2C0 / (f32)D_L30_001DCEDC;
        f -= cvtsw_asm(cvtws_asm(f));
        *(f32 *)(a0 + 0xF4) = D_L30_001DCED8 * func_0038D0B0(f * 6.2831855f);
        if (func_0038CAD0(&s->f180)) {
            func_L01_004450F0(a0, 6, -1);
        }
        break;
    case 9:
        s->f160 = 0.0f;
        func_L30_00343798(a0, s->f160);
        if (func_L05_00328FF8(a0)) {
            func_L01_004450F0(a0, 8, -1);
        }
        break;
    case 10:
        if (func_L01_004561B8(a0)) {
            s->v130 = s->v140;
            s->f180 = s->f190;
            s->f160 = 0.0f;
            if (*(s16 *)(a0 + 0xAA) == 0x1745) {
                func_003A52A0(1, 0, a0);
            }
            *(u16 *)(a0 + 0x34) &= ~0x41;
            p = *(u8 **)(a0 + 0x24);
            *(u16 *)(a0 + 0x34) |= *(u16 *)(p + 0x44) & 0x1000;
            *(s32 *)(a0 + 0x98) = *(s32 *)(p + 0x10);
        }
        if (s->f160 < 0.25f) {
            *(s32 *)(a0 + 0x98) = 0;
        } else {
            *(s32 *)(a0 + 0x98) = *(s32 *)(*(u8 **)(a0 + 0x24) + 0x10);
        }
        s->f1A8 = s->f1A4 = s->f160 = func_L03_0034B148(s->f180, s->f190, 0.0f);
        if (func_0038CAD0(&s->f180)) {
            s->f1A8 = s->f1A4 = 1.0f;
            func_L01_004450F0(a0, 9, -1);
        }
        break;
    }
}
/* localdecomp:end func_L30_003449B0 */

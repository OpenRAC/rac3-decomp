#include "common.h"

/* localdecomp:start func_L39_005DC4C0 */
extern u8 *D_L39_0024BF5C;
extern void func_L01_00451388(u8 *, s32 *, s32 *);

s32 func_L39_005DC4C0(s32 i, s32 *a, s32 *b) {
    s32 r;

    *a = 0;
    r = 0;
    *b = 0;
    if (i >= 0) {
        r = 1;
        func_L01_00451388(D_L39_0024BF5C + (i << 8), a, b);
    }
    return r;
}
/* localdecomp:end func_L39_005DC4C0 */

/* localdecomp:start func_L39_005DC508 */
typedef struct {
    u8 pad60[0x60];
    s32 f60[8];
    u8 pad80[0x28];
    s32 fA8[8];
} S_005DC508_e;

typedef struct {
    u8 pad[0x20C];
    S_005DC508_e *f20C;
} S_005DC508_t;

extern S_005DC508_t D_L39_00352940_005DC508;
extern u8 *D_L39_0024BF5C;
extern u8 *D_L39_0024CE20[] __attribute__((section(".sdata")));
extern f32 func_L01_0040E548(void *, void *);

s32 func_L39_005DC508(void *a0, s32 a1, s32 a2) {
    s32 r;
    s32 i;
    s32 j;

    r = a1 == a2;
    if (r == 0) {
        for (j = 0; j < 8; j++) {
            u8 *p = D_L39_0024CE20[j];
            if (p != 0 && *(s32 *)(p + 0x2548) == a2) {
                if (func_L01_0040E548(p + 0xA0, a0) < 1225.0f) {
                    r = 1;
                    break;
                }
            }
        }
        for (i = 0; i < 8; i++) {
            if (D_L39_00352940_005DC508.f20C->f60[i] >= 0 && D_L39_00352940_005DC508.f20C->fA8[i] == a2) {
                if (func_L01_0040E548(D_L39_0024BF5C + (D_L39_00352940_005DC508.f20C->f60[i] << 8) + 0x10, a0) < 2500.0f) {
                    r = 1;
                    break;
                }
            }
        }
    }
    return r;
}
/* localdecomp:end func_L39_005DC508 */

INCLUDE_ASM("asm/levels", func_L39_005DC648);

/* localdecomp:start func_L39_005DD258 */
typedef struct {
    u8 pad[136];
    s32 f88[2];
} S_005DD258;

extern S_005DD258 *D_L39_00352B4C[];

long func_L39_005DD258(u8 *a0) {
    s32 v = *(s32 *)(a0 + 0x2548);
    S_005DD258 *p = D_L39_00352B4C[0];
    long r;

    if (p->f88[0] == v) {
        r = 0;
    } else if (p->f88[1] == v) {
        r = 1;
    } else if (v) {
        r = 1;
    } else {
        r = 0;
    }
    return r;
}
/* localdecomp:end func_L39_005DD258 */

/* localdecomp:start func_L39_005DD290 */
typedef struct {
    u8 pad40[0x40];
    s32 f40[8];
    s32 f60[8];
    u8 pad80[0x28];
    s32 fA8[8];
} S_005DD290_e;

typedef struct {
    u8 pad[0x20C];
    S_005DD290_e *f20C;
} S_005DD290_t;

typedef struct {
    u8 pad[0xC60];
    s32 fC60;
    s32 fC64;
} S_005DD290_g;

extern S_005DD290_t D_L39_00352940;
extern u8 *D_L39_0024BF5C;
extern long func_L39_005DD258(u8 *);
extern void func_L01_00451388(u8 *, s32 *, s32 *);

void func_L39_005DD290(u8 *a0, s32 *a1, s32 *a2) {
    S_005DD290_g *g = *(S_005DD290_g **)(a0 + 0x2558);
    s32 idx = g->fC64;
    u8 *p;

    if (idx >= 0 && D_L39_00352940.f20C->fA8[idx] == *(s32 *)(a0 + 0x2548)) {
        p = D_L39_0024BF5C + (D_L39_00352940.f20C->f60[idx] << 8);
    } else {
        (*(S_005DD290_g **)(a0 + 0x2558))->fC64 = -1;
        (*(S_005DD290_g **)(a0 + 0x2558))->fC60 = ((s32 (*)(u8 *))func_L39_005DD258)(a0);
        p = D_L39_0024BF5C + (D_L39_00352940.f20C->f40[(*(S_005DD290_g **)(a0 + 0x2558))->fC60] << 8);
    }
    func_L01_00451388(p, a1, a2);
}
/* localdecomp:end func_L39_005DD290 */

/* localdecomp:start func_L39_005DD370 */
__asm__(".extern D_001D81E0_sda, 4");
extern float D_001D81E0_sda;
extern float func_0038DAB8(float, float);

float func_L39_005DD370(void *m) {
    return func_0038DAB8(*(float *)((char *)m + 0xF8), D_001D81E0_sda);
}
/* localdecomp:end func_L39_005DD370 */

/* localdecomp:start func_L39_005DD390 */
extern u8 *D_L39_0024BF5C;
extern float func_L39_005DD370(void *);
float func_L39_005DD390(s32 a0) {
    float r = 0.0f;
    if (a0 >= 0) r = func_L39_005DD370(D_L39_0024BF5C + (a0 << 8));
    return r;
}
/* localdecomp:end func_L39_005DD390 */

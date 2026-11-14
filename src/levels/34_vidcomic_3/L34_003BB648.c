#include "common.h"

/* localdecomp:start func_L34_003BB648 */
typedef struct {
    f32 f0;
    f32 f4;
    s32 f8;
} V_003BB648;

typedef struct {
    u8 pad0[0x2C];
    s32 f2C;
    u8 pad30[0x10];
    f32 f40;
    u8 pad44[4];
    s32 f48;
} C_003BB648;

typedef struct {
    f32 x;
    f32 y;
    f32 z;
    f32 w;
} P_003BB648;

typedef struct {
    u8 pad0[0x80];
    P_003BB648 pos;
    u8 pad90[0x360 - 0x90];
    s32 f360;
} H_003BB648;

extern H_003BB648 D_001A4BE0;
extern s16 D_001A4DC0[];
extern C_003BB648 D_L34_001E2440;
extern s32 func_00382380(void *, s32, s32);
extern s32 func_003A52A0(s32, s32, void *);
extern void func_L01_004450F0(void *, s32, s32);
extern f32 fabsf(f32);

void func_L34_003BB648(u8 *a0) {
    V_003BB648 *v = *(V_003BB648 **)(a0 + 0x68);

    switch (a0[0x20]) {
    case 0:
        if (func_00382380(&D_001A4BE0.pos, v->f8, 0) && D_001A4BE0.f360 != 0
            && fabsf(*(f32 *)(a0 + 0x10) - D_001A4BE0.pos.x) > 2.5f) {
            func_L01_004450F0(a0, 1, -1);
        }
        break;
    case 1:
        D_001A4DC0[0] = 2;
        v->f4 += 0.016f;
        *(f32 *)(a0 + 0x18) -= v->f4;
        if (*(f32 *)(a0 + 0x18) < v->f0) {
            func_003A52A0(0, 0, a0);
            D_L34_001E2440.f40 = 0.07f;
            D_L34_001E2440.f48 = 31;
            D_L34_001E2440.f2C = 0;
            *(f32 *)(a0 + 0x18) = v->f0;
            func_L01_004450F0(a0, 2, -1);
        }
        break;
    case 2:
        break;
    }
}
/* localdecomp:end func_L34_003BB648 */

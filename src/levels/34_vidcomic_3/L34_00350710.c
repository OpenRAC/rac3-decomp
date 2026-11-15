#include "common.h"

/* declared by functions of L34_0034F718.c, which this file was cut from */
extern u8 D_001A4BE0[];

/* localdecomp:start func_L34_00350710 */
extern f32 D_001A4C60[];
__asm__(".extern D_001A4C60, 16");
extern s32 func_L01_0045BD10(u8 *, f32);

s32 func_L34_00350710(u8 *a0) {
    s32 ret;
    if (D_001A4C60[0] < *(f32 *)(a0 + 0x10)) {
        ret = func_L01_0045BD10(a0, 3.1415927f);
    } else {
        ret = func_L01_0045BD10(a0, 0.0f);
    }
    return ret;
}
/* localdecomp:end func_L34_00350710 */

/* localdecomp:start func_L34_00350768 */
#include "vu0.h"
__asm__(".extern D_L34_001DD720, 4");
extern f32 D_L34_001DD720 __attribute__((section(".sdata")));
extern void func_003C2F58(void *, s32, void *);
extern f32 func_0038DBA0(f32, f32);
extern u8 *func_L30_00342D98(void *, void *, void *);
extern f32 func_0038D160(f32, f32);

void func_L34_00350768(u8 *a0) {
    u8 *p = *(u8 **)(a0 + 0x68);
    f32 v[4];
    f32 w[4] __attribute__((aligned(16)));
    u8 *r;

    func_003C2F58(a0, 0, v);
    v[1] = *(f32 *)(a0 + 0x14);
    if (*(s32 *)(p + 0x254) != 0) {
        v[2] += D_L34_001DD720;
    }
    v[1] += 0.4f;
    if (func_0038DBA0(*(f32 *)(a0 + 0xF8), 0.0f) < 1.5707964f) {
        v[1] += 0.3f;
    } else {
        v[1] -= 0.3f;
    }
    qzero(w);
    if (func_0038DBA0(*(f32 *)(a0 + 0xF8), 3.1415927f) < 1.5707964f) {
        w[0] = -1.0f;
    } else {
        w[0] = 1.0f;
    }
    r = func_L30_00342D98(a0, v, w);
    if (r != 0) {
        *(f32 *)(r + 0xF8) = func_0038D160(w[0], w[1]);
    }
}
/* localdecomp:end func_L34_00350768 */

/* localdecomp:start func_L34_003508A8 */
typedef struct {
    f32 f0;
    f32 f4;
    u8 pad8[8];
} E_003508A8;

typedef struct {
    s32 count;
    u8 pad4[0xC];
    E_003508A8 e[1];
} T_003508A8;

typedef struct {
    u8 pad0[0x50];
    f32 f50;
    u8 pad54[0xC];
    f32 f60;
    u8 pad64[0x2C];
    f32 f90;
    f32 f94;
    f32 f98;
    f32 f9C;
    f32 fA0;
    u8 padA4[0x18];
    f32 fBC;
    f32 fC0;
    u8 padC4[0x260 - 0xC4];
    s32 f260;
    u8 pad264[8];
    s32 f26C;
} V_003508A8;


extern T_003508A8 *D_L34_0021D840[];
extern void func_L01_004450F0(u8 *, s32, s32);

void func_L34_003508A8(u8 *a0) {
    V_003508A8 *p = *(V_003508A8 **)(a0 + 0x68);
    u8 *g = D_001A4BE0;
    s32 i;

    p->f90 = 0.5f;
    p->f94 = 0.5f;
    p->f60 = 0.75f;
    p->f50 = 3.0f;
    p->f98 = 0.5f;
    p->f9C = 1.0f;
    p->fA0 = 0.7853982f;
    p->fC0 = 0.34906584f;
    p->fBC = 0.00392f;
    *(u16 *)(a0 + 0x34) |= 0x100;
    *(f32 *)(a0 + 0x14) = *(f32 *)(g + 0x84);
    if (p->f260 != -1) {
        T_003508A8 *t = D_L34_0021D840[p->f260];
        for (i = 0; i < t->count; i++) {
            t->e[i].f4 = *(f32 *)(g + 0x84);
        }
    }
    if (p->f26C != 0) {
        *(u16 *)(a0 + 0x34) |= 0x41;
        *(s32 *)(a0 + 0x98) = 0;
        func_L01_004450F0(a0, 1, -1);
    } else {
        func_L01_004450F0(a0, 2, -1);
    }
}
/* localdecomp:end func_L34_003508A8 */

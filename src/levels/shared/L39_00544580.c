#include "common.h"

/* localdecomp:start func_L39_00544580 */
#include "vu0.h"

typedef struct S_00544580 S_00544580;
struct S_00544580 {
    u8 pad0[0x290];
    f32 f290;
    f32 f294;
    f32 f298;
    u8 pad1[0x384 - 0x29C];
    struct T_00544580 *f384;
};
struct T_00544580 {
    u8 pad0[0x2D8];
    s32 f2D8;
    s32 f2DC;
    u8 pad1[0x300 - 0x2E0];
    u8 f300;
};
typedef struct T_00544580 T_00544580;

typedef struct {
    u8 pad0[0x68];
    S_00544580 *f68;
} A_00544580;

extern s32 func_L39_00543AA8(void *);

s32 func_L39_00544580(A_00544580 *a) {
    S_00544580 *o = a->f68;
    s32 r;

    o->f290 -= o->f290 * 0.060000002f;
    if (fabs_asm(o->f290) < 0.001f) {
        o->f290 = 0;
    }
    o->f294 -= o->f294 * 0.060000002f;
    if (fabs_asm(o->f294) < 0.001f) {
        o->f294 = 0;
    }
    if (o->f384 != 0 && o->f384->f2DC != 0) {
        o->f298 -= o->f298 * 0.060000002f;
        if (fabs_asm(o->f298) < 0.001f) {
            o->f298 = 0;
        }
    } else {
        o->f298 -= 0.00392f;
        if (o->f384 != 0 && o->f384->f2DC == 0 && o->f384->f2D8 == 0) {
            o->f298 -= 0.00392f;
        }
    }
    r = func_L39_00543AA8(a);
    if (r != 0 && o->f298 == 0.0f) {
        o->f384->f300 = 0;
    } else {
        o->f384->f300 = 1;
    }
    return r;
}
/* localdecomp:end func_L39_00544580 */

INCLUDE_ASM("asm/levels", func_L39_005446C0);

INCLUDE_ASM("asm/levels", func_L39_00544DF8);

INCLUDE_ASM("asm/levels", func_L39_00545028);

#include "common.h"

/* localdecomp:start func_L01_003CC9C8 */
typedef int q128_3CC9C8 __attribute__((mode(TI)));

typedef struct {
    u8 pad0[0x10];
    q128_3CC9C8 q10;
    u8 pad20[3];
    u8 b23;
    u8 pad24[0xC];
    u8 b30;
    u8 pad31[3];
    u16 h34;
    u8 pad36[0x62];
    s32 w98;
    u8 pad9C[0x54];
    q128_3CC9C8 qF0;
} S_3CC9C8;
typedef struct {
    q128_3CC9C8 q0;
    q128_3CC9C8 q10;
    s32 w20;
    s32 w24;
    u16 h28;
    u16 h2A;
    u16 h2C;
    u8 b2E;
    u8 b2F;
    u8 b30;
} V_3CC9C8;
typedef struct {
    u8 pad0[0x10];
    q128_3CC9C8 q10;
    u8 pad20[0x10];
    u8 b30;
    u8 b31;
    u16 h32;
    u8 pad34[0x34];
    V_3CC9C8 *w68;
    u8 pad6C[0x4C];
    S_3CC9C8 *wB8;
} O_3CC9C8;

extern O_3CC9C8 *func_003C24B0(s32, s32);
extern void func_003A52A0(s32, s32, void *);
extern void func_003C7C38(void *);

O_3CC9C8 *func_L01_003CC9C8(S_3CC9C8 *a0, q128_3CC9C8 *a1, q128_3CC9C8 *a2, u8 a3, s32 a4, s32 a5, s32 a6, s32 a7, s32 a8, s32 a9) {
    O_3CC9C8 *o;
    V_3CC9C8 *v;
    u16 h;

    o = func_003C24B0(0x1B10, 0x80);
    if (o != 0) {
        if (a3 != 0) {
            func_003A52A0(0, 0, o);
        } else {
            func_003A52A0(1, 0, o);
        }
        a0->w98 = 0;
        a0->h34 = (a0->h34 & 0xEFFF) | 0x42;
        o->b30 = 0xFF;
        o->wB8 = a0;
        o->h32 = 0;
        o->b31 = 0;
        v = o->w68;
        o->q10 = a0->q10;
        v->b2E = a4;
        v->b2F = a5;
        v->h2C = a7;
        v->w20 = a8;
        v->w24 = a9;
        if ((u8)a3 != 0) {
            v->b30 = 1;
        }
        h = a0->h34;
        if (h & 1) {
            a0->b23 = 0;
            a0->h34 = h & 0xFFFE;
            v->h2A = v->h2C;
            a0->q10 = *a1;
            a0->qF0 = *a2;
            v->h28 = 1;
        } else {
            v->h2A = a6;
            v->q0 = *a1;
            v->q10 = *a2;
            v->h28 = 0;
        }
        func_003C7C38(a0);
    } else {
        a0->q10 = *a1;
        a0->qF0 = *a2;
    }
    return o;
}
/* localdecomp:end func_L01_003CC9C8 */

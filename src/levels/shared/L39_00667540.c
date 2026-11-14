#include "common.h"

typedef struct { u8 pad[0x2D8]; s32 x2D8; s32 x2DC; u8 pad2E0[0x2F8 - 0x2E0]; s32 x2F8; } X_006683F8;
typedef struct { u8 pad[0x2528]; X_006683F8 *x2528; u8 pad2[0x254C - 0x252C]; s32 x254C; } P_006683F8;

/* declared by functions of L39_00666F88.c, which this file was cut from */
extern s32 func_L39_0061BF68(void *);
extern void func_L01_003F2278(s32, void *);

/* localdecomp:start func_L39_00667540 */
struct P_00667540;
typedef struct { u8 p0[0xAA]; s16 hAA; u8 pAC[0xC]; s32 wB8; u8 pBC[2]; u8 bBE; } T_00667540;
typedef struct { u8 p0[0x2D0]; T_00667540 *w2D0; u8 p2D4[4]; struct P_00667540 *w2D8; u8 p2DC[0x1C]; s32 w2F8; } X_00667540;
typedef struct { u8 p0[0x34]; s32 (*f34)(struct P_00667540 *, s32, s32, s32, s32); } V_00667540;
typedef struct P_00667540 { u8 p0[0x14]; V_00667540 *vt; u8 p18[0x19F2]; u8 b1A0A; u8 p1A0B[0xB19]; s32 w2524; X_00667540 *w2528; s32 w252C; u8 p2530[4]; void *w2534; u8 p2538[0x10]; s32 w2548; s32 w254C; } P_00667540;
extern s32 func_L39_0061BF68(void *);
extern void func_L01_003F2278(s32, void *);
extern s32 func_L39_00648840(P_00667540 *, s32);
extern void func_L39_00648960(P_00667540 *, s32);

void func_L39_00667540(X_00667540 *x, P_00667540 *p) {
    s32 r = func_L39_0061BF68(p);
    if (r >= 0) func_L01_003F2278(0, p->w2534);
    x->w2D8 = p;
    x->w2F8 &= 0xFFFFFBD1;
    x->w2D0->wB8 = p->w2524;
    p->w254C = 5;
    p->w2528 = x;
    p->w252C = 0;
    p->vt->f34(p, 0x31, 1, 0, 1);
    if (r >= 0 || !(x->w2F8 & 0x4000000)) p->b1A0A = 1;
    if (p->w2548 == 0) {
        x->w2D0->bBE |= 0x10;
        x->w2D0->bBE &= 0xF7;
    } else if (p->w2548 == 1) {
        x->w2D0->bBE |= 8;
        x->w2D0->bBE &= 0xEF;
    }
    if (x->w2D0->hAA == 0x107C) {
        if (func_L39_00648840(p, 0x1A) == 0) func_L39_00648960(p, 0x1A);
    } else if (x->w2D0->hAA == 0x107E) {
        if (func_L39_00648840(p, 0x19) == 0) func_L39_00648960(p, 0x19);
    } else if (x->w2D0->hAA == 0x10C2) {
        if (func_L39_00648840(p, 7) == 0) func_L39_00648960(p, 7);
    }
    if (r < 0) x->w2F8 |= 0x20;
    else x->w2F8 |= 4;
}
/* localdecomp:end func_L39_00667540 */

INCLUDE_ASM("asm/levels", func_L39_00667700);

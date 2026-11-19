#include "common.h"

/* localdecomp:start func_L39_0052D348 */
typedef struct { u8 p0[0x20]; f32 f20; s32 w24; s32 w28; s32 w2C; f32 f30; s32 w34; s32 w38; s32 w3C; f32 f40; s32 w44; s32 w48; u8 p4C[0x460 - 0x4C]; } E_0052D348;
typedef struct { u8 p0[0x1A14]; u8 b1A14; u8 p1A15[0x24C9 - 0x1A15]; u8 b24C9; u8 p24CA[0x2534 - 0x24CA]; s32 w2534; } P_0052D348;
typedef struct { u8 p0[0x2D8]; P_0052D348 *pl0; P_0052D348 *pl1; } R_0052D348;
typedef struct { u8 p0[0x6D0]; R_0052D348 *r; } Q_0052D348;
typedef struct { u8 p0[0x68]; Q_0052D348 *q; } O_0052D348;
extern E_0052D348 D_L39_0024DE80[];
extern void func_L01_003F1F20(s32, s32);

void func_L39_0052D348(O_0052D348 *o) {
    Q_0052D348 *q = o->q;
    P_0052D348 *p = q->r->pl0;
    s32 idx;
    if (p != 0 && p->b1A14 != 0) {
        func_L01_003F1F20(0x12, p->w2534);
        (D_L39_0024DE80 + p->b24C9)->f20 = 0.3f;
        (D_L39_0024DE80 + p->b24C9)->w28 = 20;
        (D_L39_0024DE80 + p->b24C9)->w2C = 0;
        (D_L39_0024DE80 + p->b24C9)->f30 = 0.1f;
        (D_L39_0024DE80 + p->b24C9)->w38 = 20;
        (D_L39_0024DE80 + p->b24C9)->w2C = 0;
        (D_L39_0024DE80 + p->b24C9)->f40 = 0.01f;
        (D_L39_0024DE80 + p->b24C9)->w48 = 20;
        (D_L39_0024DE80 + p->b24C9)->w2C = 0;
    }
    p = q->r->pl1;
    idx = -1;
    if (p != 0 && p->b1A14 != 0) {
        func_L01_003F1F20(0x12, p->w2534);
        idx = p->b24C9;
    }
    if (idx >= 0) {
        (D_L39_0024DE80 + idx)->f20 = 0.3f;
        (D_L39_0024DE80 + idx)->w28 = 20;
        (D_L39_0024DE80 + idx)->w2C = 0;
        (D_L39_0024DE80 + idx)->f30 = 0.1f;
        (D_L39_0024DE80 + idx)->w38 = 20;
        (D_L39_0024DE80 + idx)->w2C = 0;
        (D_L39_0024DE80 + idx)->f40 = 0.01f;
        (D_L39_0024DE80 + idx)->w48 = 20;
        (D_L39_0024DE80 + idx)->w2C = 0;
    }
}
/* localdecomp:end func_L39_0052D348 */

INCLUDE_ASM("asm/levels", func_L39_0052D4E8);

/* localdecomp:start func_L39_0052D9D0 */
#include "vu0.h"

extern s32 D_L39_002412DC;
__asm__(".extern D_L39_002412DC, 16");
extern f32 D_L39_0024AB34;
extern f32 D_L39_0024AB30;
extern f32 D_L39_0024D510[] __attribute__((section(".sdata")));
extern const f32 D_L39_0024AC68[] __attribute__((section(".sdata")));
extern const f32 D_L39_0024AC58[] __attribute__((section(".sdata")));
extern void func_L09_003CA6A8(void *, s32);
extern void func_L09_003CA7E8(void *, s32);
extern void func_003C3FC0(void *, void *);

typedef struct {
    f32 x;
    f32 y;
    f32 z;
    f32 w;
} V_0052D9D0;

void func_L39_0052D9D0(u8 *arg0) {
    u8 *p = *(u8 **)(arg0 + 0x68);
    u8 *q = *(u8 **)(p + 0x6D0);
    u8 *r;
    f32 f;
    s32 i;
    s32 mode;
    s32 *ia;
    f32 *fa;
    V_0052D9D0 v;

    qzero(q + 0x270);
    mode = D_L39_002412DC;
    *(s32 *)(q + 0x310) = 0;
    if (mode == 0x12) {
        f = D_L39_0024AB34;
        *(f32 *)(q + 0x308) = f;
        *(f32 *)(q + 0x30C) = f;
    } else if (mode == 0x14) {
        f = 200.0f;
        *(f32 *)(q + 0x308) = f;
        *(f32 *)(q + 0x30C) = f;
    } else {
        f = D_L39_0024AB30;
        *(f32 *)(q + 0x308) = f;
        *(f32 *)(q + 0x30C) = f;
    }
    r = *(u8 **)(p + 0x720);
    *(f32 *)(p + 0x700) = *(f32 *)(r + 0x80);
    *(s32 *)(p + 0x6F8) = 0;
    qzero(p + 0x620);
    qzero(p + 0x6A0);
    *(s32 *)(p + 0x704) = 0;
    qzero(p + 0x630);
    *(s32 *)(p + 0x708) = 0;
    qzero(p + 0x640);
    *(s16 *)(p + 0x718) = 0;
    qzero(p + 0x650);
    *(s16 *)(p + 0x71A) = 0;
    *(s32 *)(p + 0x6DC) = 0;
    *(s32 *)(p + 0x6D4) = 0;
    *(f32 *)(p + 0x6D8) = *(f32 *)(r + 0x70);
    *(f32 *)(p + 0x724) = -999.0f;
    *(s32 *)(p + 0x72C) = -1;
    *(u8 *)(p + 0x714) = 0;
    *(u8 *)(p + 0x713) = 0;
    *(s32 *)(p + 0x7A4) = 0;
    *(s32 *)(p + 0x7A8) = 0;
    *(s16 *)(p + 0x710) = 0;
    *(s32 *)(p + 0x6F0) = 0;
    *(s32 *)(p + 0x6F4) = 0;
    *(s32 *)(p + 0x74C) = 0;
    *(s32 *)(p + 0x750) = 0;
    *(s32 *)(p + 0x70C) = 0;
    *(s16 *)(p + 0x71C) = 0;
    *(s16 *)(p + 0x71E) = 0;
    *(s32 *)(p + 0x728) = 0;
    *(s32 *)(p + 0x730) = 0;
    *(s32 *)(p + 0x6E8) = 0;
    *(s32 *)(p + 0x6E0) = 0;
    ia = (s32 *)(p + 0x6B0);
    fa = (f32 *)(p + 0x6C0);
    for (i = 0; i < 4; i++) {
        ia[i] = 0;
        fa[i] = -1.0f;
        D_L39_0024D510[i] = D_L39_0024AC68[i] + fabs_asm(D_L39_0024AC58[i]);
    }
    func_L09_003CA6A8(p, 0);
    func_L09_003CA6A8(p, 1);
    func_L09_003CA7E8(p, 2);
    func_L09_003CA7E8(p, 3);
    qzero(&v);
    v.x = *(f32 *)(p + 0x6F0);
    v.y = *(f32 *)(p + 0x74C);
    func_003C3FC0(p + 0x2B0, &v);
    qzero(&v);
    v.x = *(f32 *)(p + 0x6F0);
    v.y = -*(f32 *)(p + 0x74C);
    func_003C3FC0(p + 0x3B0, &v);
}
/* localdecomp:end func_L39_0052D9D0 */

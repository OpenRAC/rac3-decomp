/* functional: high. Plain C for the VU0/asm parts: qzero for the quadword zero stores, fabs as a ternary (retail uses abs.s), same result. Compiles at level 09 (142 diff words: register allocation/scheduling only). Constants/globals from PAL asm: gp-relative D_L09_001DE8B0/8B4 (s1 damage-scale floats) and D_001DA9F8. */
#include "vu0.h"

extern s32 D_001D545C;
extern f32 D_L09_001DE8B0;
extern f32 D_L09_001DE8B4;
extern f32 D_001DA9F8;
extern u8 D_0014275B[];
extern f32 D_L09_002F1F30[];
extern f32 D_L09_001DE9B8[];
extern f32 D_L09_001DE9C8[];
extern f32 D_L09_001E22B8[];
extern s32 func_L01_0041A4F0(void);
extern void func_L09_003CA6A8(void *, s32);
extern void func_L09_003CA7E8(void *, s32);
extern void func_003C3FC0(void *, void *);

void func_L09_003C7B78(u8 *m) {
    u8 *st = *(u8 **)(m + 0x68);
    u8 *g = *(u8 **)(st + 0x6D0);
    u8 *o;
    f32 *p0;
    f32 *p1;
    f32 *p2;
    f32 f;
    f32 k;
    s32 v;
    s32 i;
    f32 tmp[4] __attribute__((aligned(16)));

    qzero(g + 0xC0);
    v = D_001D545C;
    *(s32 *)(g + 0x138) = 0;
    if (v == 0x12) {
        f = D_L09_001DE8B4;
    } else {
        f = 200.0f;
        if (v != 0x14) {
            f = D_L09_001DE8B0;
        }
    }
    *(f32 *)(g + 0x134) = f;
    *(f32 *)(g + 0x130) = f;
    if (func_L01_0041A4F0() != 0) {
        v = D_001D545C;
        k = (v == 7 && D_0014275B[0] != 0) ? D_001DA9F8 : D_L09_002F1F30[v];
        *(f32 *)(g + 0x130) = *(f32 *)(g + 0x130) * k;
        v = D_001D545C;
        k = (v == 7 && D_0014275B[0] != 0) ? D_001DA9F8 : D_L09_002F1F30[v];
        *(f32 *)(g + 0x134) = *(f32 *)(g + 0x134) * k;
    }

    o = *(u8 **)(st + 0x720);
    *(s32 *)(st + 0x6F8) = 0;
    qzero(st + 0x620);
    *(f32 *)(st + 0x700) = *(f32 *)(o + 0x80);
    qzero(st + 0x6A0);
    *(s32 *)(st + 0x704) = 0;
    qzero(st + 0x630);
    *(s32 *)(st + 0x708) = 0;
    qzero(st + 0x640);
    *(s16 *)(st + 0x718) = 0;
    qzero(st + 0x650);
    *(s16 *)(st + 0x71A) = 0;
    *(s32 *)(st + 0x6DC) = 0;
    *(s32 *)(st + 0x6D4) = 0;
    *(u16 *)(st + 0x710) = *(u16 *)(st + 0x710) & 4;
    *(f32 *)(st + 0x6D8) = *(f32 *)(o + 0x70);
    st[0x714] = 0;
    st[0x713] = 0;
    *(s32 *)(st + 0x7A4) = 0;
    *(s32 *)(st + 0x7A8) = 0;
    *(s32 *)(st + 0x6F0) = 0;
    *(s32 *)(st + 0x6F4) = 0;
    *(s32 *)(st + 0x74C) = 0;
    *(s32 *)(st + 0x750) = 0;
    *(s32 *)(st + 0x70C) = 0;
    *(s16 *)(st + 0x71C) = 0;
    *(s16 *)(st + 0x71E) = 0;
    *(f32 *)(st + 0x724) = *(f32 *)(m + 0xF8);
    *(s32 *)(st + 0x728) = 0;
    *(s32 *)(st + 0x730) = 0;
    *(s32 *)(st + 0x72C) = -1;
    *(s32 *)(st + 0x6E8) = 0;
    *(s32 *)(st + 0x6E0) = 0;
    p0 = (f32 *)(st + 0x6B0);
    p1 = (f32 *)(st + 0x6C0);
    for (i = 0; i < 4; i++) {
        *(s32 *)&p0[i] = 0;
        p1[i] = -1.0f;
        p2 = &D_L09_001DE9B8[i];
        D_L09_001E22B8[i] = D_L09_001DE9C8[i] + (*p2 < 0.0f ? -*p2 : *p2);
    }
    func_L09_003CA6A8(st, 0);
    func_L09_003CA6A8(st, 1);
    func_L09_003CA7E8(st, 2);
    func_L09_003CA7E8(st, 3);
    qzero(tmp);
    tmp[0] = *(f32 *)(st + 0x6F0);
    tmp[1] = *(f32 *)(st + 0x74C);
    func_003C3FC0(st + 0x2B0, tmp);
    qzero(tmp);
    tmp[0] = *(f32 *)(st + 0x6F0);
    tmp[1] = -*(f32 *)(st + 0x74C);
    func_003C3FC0(st + 0x3B0, tmp);
}

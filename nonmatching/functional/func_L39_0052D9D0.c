/* functional: high. Reset/initialise the state block of the object's controller (clears fields, sets defaults from two globals and the controller's own fields, builds four per-slot floats and two vectors) */
#include "vu0.h"
extern void func_L09_003CA6A8(void *, s32);
extern void func_L09_003CA7E8(void *, s32);
extern void func_003C3FC0(void *, void *);
extern s32 D_L39_002412DC;
__asm__(".extern D_L39_0024AB34, 4");
__asm__(".extern D_L39_0024AB30, 4");
extern f32 D_L39_0024AB34;
extern f32 D_L39_0024AB30;
extern f32 D_L39_0024D510[];
extern f32 D_L39_0024AC68[];
extern f32 D_L39_0024AC58[];

typedef struct { u8 pad0[0x68]; u8 *x68; } O_0052D9D0;

void func_L39_0052D9D0(O_0052D9D0 *o) {
    u8 *s = o->x68;
    u8 *t = *(u8 **)(s + 0x6D0);
    u8 *u;
    f32 f;
    f32 *pa;
    f32 *pb;
    f32 *pc;
    s32 *pi;
    f32 *pf;
    s32 j;
    vu0_v4 v;

    qzero(t + 0x270);
    *(s32 *)(t + 0x310) = 0;
    if (D_L39_002412DC == 0x12) {
        f = D_L39_0024AB34;
    } else {
        f = 200.0f;
        if (D_L39_002412DC != 0x14) {
            f = D_L39_0024AB30;
        }
    }
    *(f32 *)(t + 0x30C) = f;
    *(f32 *)(t + 0x308) = f;
    u = *(u8 **)(s + 0x720);
    *(s32 *)(s + 0x6F8) = 0;
    qzero(s + 0x620);
    *(f32 *)(s + 0x700) = *(f32 *)(u + 0x80);
    qzero(s + 0x6A0);
    *(s32 *)(s + 0x704) = 0;
    qzero(s + 0x630);
    *(s32 *)(s + 0x708) = 0;
    qzero(s + 0x640);
    *(s16 *)(s + 0x718) = 0;
    qzero(s + 0x650);
    *(s16 *)(s + 0x71A) = 0;
    *(s32 *)(s + 0x6DC) = 0;
    *(s32 *)(s + 0x6D4) = 0;
    *(f32 *)(s + 0x724) = -999.0f;
    *(f32 *)(s + 0x6D8) = *(f32 *)(u + 0x70);
    *(s32 *)(s + 0x72C) = -1;
    s[0x714] = 0;
    s[0x713] = 0;
    *(s32 *)(s + 0x7A4) = 0;
    *(s32 *)(s + 0x7A8) = 0;
    *(s16 *)(s + 0x710) = 0;
    *(s32 *)(s + 0x6F0) = 0;
    *(s32 *)(s + 0x6F4) = 0;
    *(s32 *)(s + 0x74C) = 0;
    *(s32 *)(s + 0x750) = 0;
    *(s32 *)(s + 0x70C) = 0;
    *(s16 *)(s + 0x71C) = 0;
    *(s16 *)(s + 0x71E) = 0;
    *(s32 *)(s + 0x728) = 0;
    *(s32 *)(s + 0x730) = 0;
    *(s32 *)(s + 0x6E8) = 0;
    *(s32 *)(s + 0x6E0) = 0;
    pi = (s32 *)(s + 0x6B0);
    pf = (f32 *)(s + 0x6C0);
    pa = D_L39_0024AC68;
    pb = D_L39_0024AC58;
    pc = D_L39_0024D510;
    for (j = 3; j >= 0; j--) {
        *pi++ = 0;
        *pf++ = -1.0f;
        *pc++ = *pa++ + fabs_asm(*pb++);
    }
    func_L09_003CA6A8(s, 0);
    func_L09_003CA6A8(s, 1);
    func_L09_003CA7E8(s, 2);
    func_L09_003CA7E8(s, 3);
    qzero(&v);
    v.x = *(f32 *)(s + 0x6F0);
    v.y = *(f32 *)(s + 0x74C);
    func_003C3FC0(s + 0x2B0, &v);
    qzero(&v);
    v.x = *(f32 *)(s + 0x6F0);
    v.y = -*(f32 *)(s + 0x74C);
    func_003C3FC0(s + 0x3B0, &v);
}

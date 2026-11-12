#include "common.h"

INCLUDE_ASM("asm/levels", func_L04_00366800);

/* localdecomp:start func_L04_00366AC8 */
typedef struct { float x, y, z, w; } __attribute__((aligned(16))) V4_366AC8;
typedef int u128_t_366AC8 __attribute__((mode(TI)));

typedef struct {
    u8 pad0[0x30];
    f32 f30, f34, f38, f3C, f40;
    u8 pad44[0x18];
    s32 f5C;
    f32 f60, f64;
    s32 f68;
} State_366AC8;

extern u16 *D_L04_0021C9A0[];
extern u8 *D_L04_001DFD9C;
__asm__(".extern D_L04_001DFD9C, 16");
extern u8 *D_L04_001DFE80;
__asm__(".extern D_L04_001DFE80, 16");
extern u8 D_001BBC40[];
extern s32 D_001DFDD8_sda;
__asm__(".extern D_001DFDD8_sda, 4");
extern s32 D_001D545C_sda;
__asm__(".extern D_001D545C_sda, 4");
extern f32 D_001DD7F4_sda;
__asm__(".extern D_001DD7F4_sda, 4");

extern void func_003C2F58(void *, s32, void *);
extern void func_0038D308(void *, void *);
extern void func_L01_004450F0(void *, s32, s32);
extern void func_L01_0044F450(void *, void *);
extern void func_L01_0044ED88(void *, void *, s32, s32, s32, s32, s32, s32);
extern void func_L01_0045BD78(void *, f32, f32, f32, f32);
extern void func_L01_00366E48(void *, void *, void *, void *, s32);
extern void func_003C3A10(void *, s32, s32, s32);

void func_L04_00366AC8(u8 *a0, u8 *a1) {
    u16 *p;
    u8 *e;
    V4_366AC8 t;
    u128_t_366AC8 v;
    u8 *q;
    u8 *pos;
    s32 f;
    f32 turn;
    State_366AC8 *state = (State_366AC8 *)a1;

    a0[0x30] = 0x20;
    *(u16 *)(a0 + 0x32) = 0x20;
    *(V4_366AC8 *)(a1 + 0x2C0) = *(V4_366AC8 *)(a0 + 0x10);
    p = D_L04_0021C9A0[*(s32 *)(a1 + 0x120)];

    for (;;) {
        f = *(s32 *)(a1 + 0x120);
        if ((u8)f == 0xFF) break;
        if (D_001DFDD8_sda < f) break;
        if (p == 0) break;
        if ((s16)p[-1] < 0 && p != D_L04_0021C9A0[f]) break;
        e = D_L04_001DFD9C + ((*p & 0x7FFF) << 8);
        if (e == 0) break;
        *(u16 *)(e + 0x34) |= 0x41;
        if (*(s16 *)(e + 0xAA) == 0x1860) {
            *(u8 **)(a1 + 0x12C) = e;
            *(u8 **)(e + 0xB8) = a0;
            func_003C2F58(a0, 0, &t);
            *(V4_366AC8 *)(e + 0x10) = t;
        } else if (*(s16 *)(e + 0xAA) == 0x11C1) {
            *(u8 **)(e + 0xB8) = a0;
            func_003C2F58(a0, 1, &t);
            *(V4_366AC8 *)(e + 0x10) = t;
        }
        p++;
    }

    pos = a0 + 0xF0;
    func_L01_0044ED88(a0, a1 + 0x180, 4, *(s32 *)(a1 + 0x120), -1, -1, 7, 0);

    state->f34 = 0.1f;
    state->f38 = 0.1f;
    state->f30 = 0.2f;
    state->f3C = 0.1f;
    state->f40 = 0.61086524f;
    state->f60 = 0.08726646f;
    state->f64 = 0.75f;
    state->f68 |= 4;
    state->f5C = 0;
    turn = D_001DD7F4_sda;
    turn *= 0.020000001f;
    *(u16 *)(a0 + 0x34) |= 0x100;
    func_L01_0045BD78(a0, 0.0032000002f, turn, 0.0018849557f, 0.041887905f);
    *(s32 *)(a1 + 0x300) = 0;
    *(V4_366AC8 *)(a1 + 0x2E0) = *(V4_366AC8 *)(a0 + 0x10);
    *(V4_366AC8 *)(a1 + 0x2F0) = *(V4_366AC8 *)(a0 + 0xF0);
    func_L01_00366E48(a0, a1 + 0x134, a1 + 0x138, a1 + 0x140, 0);
    *(s32 *)(a1 + 0x130) = 0x5A;
    if (a0[0xB0] != 0xFF) {
        if ((D_001BBC40[a0[0xB0] + (D_001D545C_sda << 4)] & 0x80) != 0) {
            q = D_L04_001DFE80 + (*(s32 *)(a1 + 0x13C) << 7);
            v = *(u128_t_366AC8 *)(q + 0x30);
            *(u128_t_366AC8 *)(a0 + 0x10) = v;
            *(u128_t_366AC8 *)(a1 + 0x2C0) = v;
            *(V4_366AC8 *)(a0 + 0xF0) = *(V4_366AC8 *)(q + 0x70);
            func_0038D308(a0 + 0xC0, pos);
            func_L01_0044F450(a0, a1 + 0x180);
            *(V4_366AC8 *)(a1 + 0x2E0) = *(V4_366AC8 *)(a0 + 0x10);
            *(V4_366AC8 *)(a1 + 0x2F0) = *(V4_366AC8 *)(a0 + 0xF0);
            *(s32 *)(a1 + 0x300) = 1;
        }
    }
    func_L01_004450F0(a0, 1, -1);
    func_003C3A10(a0, 0, 0, 0);
}
/* localdecomp:end func_L04_00366AC8 */

INCLUDE_ASM("asm/levels", func_L04_00366DC8);

/* localdecomp:start func_L04_00367068 */
extern void func_L04_003672E8(void *);
extern void func_L04_00367150(void *);
extern void func_L01_004450F0(void *, s32, s32);
extern s32 func_L01_00447490(void *, s32, s32);
extern s32 func_0038CAD0(void *);

void func_L04_00367068(u8 *a0) {
    u8 *p = *(u8 **)(a0 + 0x68);

    switch (a0[0x20]) {
    case 0:
        *(s32 *)p = 8;
        func_L01_004450F0(a0, 1, -1);
        break;
    case 1:
        if (func_L01_00447490(a0, -1, 0) != 0) {
            func_L01_004450F0(a0, 2, -1);
        }
        break;
    case 2:
        func_L04_003672E8(a0);
        func_L01_004450F0(a0, 3, -1);
        break;
    case 3:
        if (func_0038CAD0(p) != 0) {
            func_L04_00367150(a0);
        }
        break;
    }
    *(u8 *)(a0 + 0xA8) = 0xFF;
}
/* localdecomp:end func_L04_00367068 */

/* localdecomp:start func_L04_00367150 */
typedef struct { float x, y, z, w; } __attribute__((aligned(16))) V4_367150;
extern void func_0038D000(void *, void *, void *);
extern s32 func_00382498(s32, s32);
extern void func_L02_003E2E38(void *, void *, f32, void *, s32, s32, s32, f32, f32, f32, f32);

void func_L04_00367150(void *a0) {
    u8 *p = (u8 *)a0;
    V4_367150 a;
    V4_367150 b;
    s32 r;
    s32 *q;

    q = *(s32 **)(p + 0x68);
    b = (V4_367150){0.0f, 0.0f, 0.0f, 0.0f};
    a = (V4_367150){0.0f, 0.0f, 5.0f, 0.0f};
    b.x = 0.040000003f;
    b.z = 0.040000003f;
    func_0038D000(&b, &b, p + 0xC0);
    r = func_00382498(3, 6);
    func_L02_003E2E38(p, &a, 0.0f, &b, r, 0, 0, 0.040000003f, 0.5f, 15.0f, 1.0f);
    b.x = -0.040000003f;
    b.z = 0.048000004f;
    func_0038D000(&b, &b, p + 0xC0);
    r = func_00382498(3, 6);
    func_L02_003E2E38(p, &a, 0.0f, &b, r, 1, 0, 0.040000003f, 0.5f, 15.0f, 1.0f);
    r = func_00382498(0x5A, 0xB4);
    *q = (r * 5 + 2) / 6;
}
/* localdecomp:end func_L04_00367150 */

INCLUDE_ASM("asm/levels", func_L04_003672E8);

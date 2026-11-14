#include "common.h"

typedef int u128_t __attribute__((mode(TI)));

/* localdecomp:start func_L24_003B7820 */
extern s32 D_001DD570;
__asm__(".extern D_001DD570, 16");
extern s32 D_001D545C;
__asm__(".extern D_001D545C, 16");
extern void func_L24_003B7A70(u8 *);
extern void func_L24_00355C18(u8 *, s32, s32, void *, s32, f32);
extern s32 func_L01_00447490(void *, s32, s32);
extern void func_L01_004450F0(void *, s32, s32);
extern void func_003C3A10(void *, s32, s32, s32);
extern void func_003C2F58(void *, s32, void *);
extern s32 func_L01_003303B8(u8 *, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32,
    s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern void func_L01_004AA7E8(void *, s32);

void func_L24_003B7820(u8 *a0) {
    u8 *p = *(u8 **)(a0 + 0x68);
    u8 buf[16];

    if (D_001DD570 != 0 && a0[0x20] < 2) return;
    if (D_001D545C != 0x539 && D_001D545C != 0x18) return;
    if (a0[0x20] == 0) func_L24_003B7A70(a0);
    if (a0[0x20] == 1) {
        func_L24_00355C18(a0, 1, 0, p + 0x130, *(s32 *)(p + 0x124), *(f32 *)(p + 0x128));
        if (func_L01_00447490(a0, -1, 0) != 0) {
            func_L01_004450F0(a0, 2, -1);
            if (a0[0x43] != 7) func_003C3A10(a0, 7, 0, 3);
        }
    } else if (a0[0x20] == 2 && (a0[0x60] & 2)) {
        a0[0xA8] = 0xFF;
        func_003C2F58(a0, 0, buf);
        func_L01_003303B8(buf, 0, 0x19, 0x14, 0x14, 0x14, 0x2D, 2, 0.75f, 0.0f, 0.0f, 2.0f,
            0, 1, 0, 0, 1, 0, 0x1010000, 0, 0x388EF7, 0x63F7, 0x407FFF, 0x20FF, 0x8FFF,
            0x3064FF, 0x7F60A0FF, 0x280000FF, 0x3064FF, 0);
        *(u16 *)(a0 + 0x34) = (*(u16 *)(a0 + 0x34) | 0x41) & 0xEFFF;
        *(s32 *)(a0 + 0x98) = 0;
        func_L01_004AA7E8(a0, 1);
        func_L01_004450F0(a0, 3, -1);
        *(u16 *)(a0 + 0x34) |= 2;
    }
    if (D_001D545C == 0x18) *(f32 *)(a0 + 0x18) = 101.86f;
    else *(f32 *)(a0 + 0x18) = 48.84f;
}
/* localdecomp:end func_L24_003B7820 */

/* localdecomp:start func_L24_003B7A70 */
typedef struct { u8 p0[0x10]; s32 w10; u8 p14[0x30]; u16 h44; } T_003B7A70;
typedef struct {
    u8 p0[0x24]; T_003B7A70 *p24; u8 p28[0xC]; u16 h34; u8 p36[0xD];
    u8 b43; u8 p44[0x24]; u8 *p68; u8 p6C[0x2C]; s32 w98;
} M_003B7A70;
typedef struct {
    u8 p0[0x30]; f32 f30; f32 f34; f32 f38; f32 f3C; f32 f40; u8 p44[0x18]; f32 f5C; f32 f60;
    u8 p64[0xC0]; s32 w124; f32 f128;
} P_003B7A70;
extern s32 D_L24_001DD584;
__asm__(".extern D_L24_001DD584, 16");
extern f32 D_L24_001DD580;
__asm__(".extern D_L24_001DD580, 16");
extern f32 D_L24_001DD57C;
__asm__(".extern D_L24_001DD57C, 16");
extern void func_L01_0045BD78(void *, f32, f32, f32, f32);
extern void func_003C3A10(void *, s32, s32, s32);
extern void func_L01_004450F0(void *, s32, s32);

void func_L24_003B7A70(u8 *a0) {
    M_003B7A70 *m = (M_003B7A70 *)a0;
    P_003B7A70 *p;
    m->h34 &= ~0x41;
    m->h34 |= m->p24->h44 & 0x1000;
    m->w98 = m->p24->w10;
    p = (P_003B7A70 *)m->p68;
    p->f34 = 0.1f;
    p->f30 = 0.5f;
    p->f38 = 0.5f;
    p->f3C = 1.0f;
    p->f40 = 0.7853982f;
    p->f60 = 0.34906584f;
    p->f5C = 0.00392f;
    p->w124 = D_L24_001DD584;
    p->f128 = D_L24_001DD580;
    *(u128_t *)((u8 *)p + 0x150) = *(u128_t *)(a0 + 0x10);
    func_L01_0045BD78(m, D_L24_001DD57C, D_L24_001DD57C, 0.50265485f, 0.50265485f);
    if (m->b43 != 0) func_003C3A10(m, 0, 0, 3);
    func_L01_004450F0(m, 1, -1);
}
/* localdecomp:end func_L24_003B7A70 */

/* localdecomp:start func_L24_003B7B88 */
/* log:
 * 1. copy of func_L24_003B7820 (same file) with this one's offsets, state 1, and the 0x300 copy
 */
extern s32 D_001DD570;
__asm__(".extern D_001DD570, 16");
extern s32 D_001D545C;
__asm__(".extern D_001D545C, 16");
struct M_003B7DE8;
extern void func_L24_003B7DE8(struct M_003B7DE8 *);
extern void func_L24_00355C18(u8 *, s32, s32, void *, s32, f32);
extern s32 func_L01_00447490(void *, s32, s32);
extern void func_L01_004450F0(void *, s32, s32);
extern void func_003C3A10(void *, s32, s32, s32);
extern void func_003C2F58(void *, s32, void *);
extern s32 func_L01_003303B8(u8 *, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32,
    s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern void func_L01_004AA7E8(void *, s32);

void func_L24_003B7B88(u8 *a0) {
    u8 *p = *(u8 **)(a0 + 0x68);
    u8 buf[16];

    if (D_001DD570 != 0 && a0[0x20] < 2) return;
    if (D_001D545C != 0x539 && D_001D545C != 0x18) return;
    if (a0[0x20] == 0) func_L24_003B7DE8((struct M_003B7DE8 *)a0);
    if (a0[0x20] == 1) {
        func_L24_00355C18(a0, 2, 0, p + 0x940, *(s32 *)(p + 0x93C), *(f32 *)(p + 0x960));
        if (func_L01_00447490(a0, -1, 0) != 0) {
            func_L01_004450F0(a0, 2, -1);
            if (a0[0x43] != 1) func_003C3A10(a0, 1, 0, 3);
        }
    } else if (a0[0x20] == 2 && (a0[0x60] & 2)) {
        a0[0xA8] = 0xFF;
        func_003C2F58(a0, 1, buf);
        func_L01_003303B8(buf, 0, 0x19, 0x14, 0x14, 0x14, 0x2D, 2, 0.75f, 0.0f, 0.0f, 2.0f,
            0, 1, 0, 0, 1, 0, 0x1010000, 0, 0x388EF7, 0x63F7, 0x407FFF, 0x20FF, 0x8FFF,
            0x3064FF, 0x7F60A0FF, 0x280000FF, 0x3064FF, 0);
        *(u16 *)(a0 + 0x34) = (*(u16 *)(a0 + 0x34) | 0x41) & 0xEFFF;
        *(s32 *)(a0 + 0x98) = 0;
        func_L01_004AA7E8(a0, 1);
        *(u128_t *)(a0 + 0x10) = *(u128_t *)(p + 0x300);
        func_L01_004450F0(a0, 3, -1);
        *(u16 *)(a0 + 0x34) |= 2;
    }
    if (D_001D545C == 0x18) *(f32 *)(a0 + 0x18) = 101.86f;
    else *(f32 *)(a0 + 0x18) = 48.84f;
}
/* localdecomp:end func_L24_003B7B88 */

/* localdecomp:start func_L24_003B7DE8 */
typedef struct P_003B7DE8 {
    u8 pad0[0x70];
    f32 f70, f74, f78, f7C, f80;
    u8 pad84[0x18];
    f32 f9C, fA0;
    u8 padA4[0x898];
    s32 f93C;
    u8 pad940[0x20];
    f32 f960;
} P_003B7DE8;
typedef struct O_003B7DE8 {
    u8 pad0[0x10];
    s32 f10;
    u8 pad14[0x30];
    u16 f44;
} O_003B7DE8;
typedef struct M_003B7DE8 {
    u8 pad0[0x10];
    u128_t f10;
    u8 pad20[4];
    O_003B7DE8 *f24;
    u8 pad28[0xC];
    u16 f34;
    u8 pad36[0xD];
    u8 f43;
    u8 pad44[0x24];
    P_003B7DE8 *f68;
    u8 pad6C[0x2C];
    s32 f98;
} M_003B7DE8;
extern s32 D_001DD584;
__asm__(".extern D_001DD584, 16");
extern f32 D_001DD580;
__asm__(".extern D_001DD580, 16");
extern f32 D_001DD57C;
__asm__(".extern D_001DD57C, 16");
extern void func_L01_0045BD78(void *, f32, f32, f32, f32);

void func_L24_003B7DE8(M_003B7DE8 *a0) {
    O_003B7DE8 *obj;
    P_003B7DE8 *p;

    a0->f34 &= ~0x41;
    obj = a0->f24;
    p = a0->f68;
    a0->f34 |= obj->f44 & 0x1000;
    a0->f98 = obj->f10;
    p->f70 = 0.5f;
    p->f74 = 0.1f;
    p->f78 = 0.5f;
    p->f7C = 1.0f;
    p->f80 = 0.785398185f;
    p->fA0 = 0.34906584f;
    p->f9C = 0.00392f;
    p->f93C = D_001DD584;
    p->f960 = D_001DD580;
    *(u128_t *)((u8 *)p + 0x300) = a0->f10;
    func_L01_0045BD78(a0, D_001DD57C, D_001DD57C, 0.50265485f, 0.50265485f);
    if (a0->f43 != 0) func_003C3A10(a0, 0, 0, 3);
    func_L01_004450F0(a0, 1, -1);
}
/* localdecomp:end func_L24_003B7DE8 */

/* localdecomp:start func_L24_003B7F00 */
/* log:
 * 1. copy of func_L24_003B7B88 (same task) with this one's offsets and callee
 */
extern s32 D_001DD570;
__asm__(".extern D_001DD570, 16");
extern s32 D_001D545C;
__asm__(".extern D_001D545C, 16");
extern void func_L24_003B8160(u8 *);
extern void func_L24_00355C18(u8 *, s32, s32, void *, s32, f32);
extern s32 func_L01_00447490(void *, s32, s32);
extern void func_L01_004450F0(void *, s32, s32);
extern void func_003C3A10(void *, s32, s32, s32);
extern void func_003C2F58(void *, s32, void *);
extern s32 func_L01_003303B8(u8 *, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32,
    s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern void func_L01_004AA7E8(void *, s32);

void func_L24_003B7F00(u8 *a0) {
    u8 *p = *(u8 **)(a0 + 0x68);
    u8 buf[16];

    if (D_001DD570 != 0 && a0[0x20] < 2) return;
    if (D_001D545C != 0x539 && D_001D545C != 0x18) return;
    if (a0[0x20] == 0) func_L24_003B8160(a0);
    if (a0[0x20] == 1) {
        func_L24_00355C18(a0, 2, 0, p + 0x170, *(s32 *)(p + 0x168), *(f32 *)(p + 0x16C));
        if (func_L01_00447490(a0, -1, 0) != 0) {
            func_L01_004450F0(a0, 2, -1);
            if (a0[0x43] != 1) func_003C3A10(a0, 1, 0, 3);
        }
    } else if (a0[0x20] == 2 && (a0[0x60] & 2)) {
        a0[0xA8] = 0xFF;
        func_003C2F58(a0, 2, buf);
        func_L01_003303B8(buf, 0, 0x19, 0x14, 0x14, 0x14, 0x2D, 2, 0.75f, 0.0f, 0.0f, 2.0f,
            0, 1, 0, 0, 1, 0, 0x1010000, 0, 0x388EF7, 0x63F7, 0x407FFF, 0x20FF, 0x8FFF,
            0x3064FF, 0x7F60A0FF, 0x280000FF, 0x3064FF, 0);
        *(u16 *)(a0 + 0x34) = (*(u16 *)(a0 + 0x34) | 0x41) & 0xEFFF;
        *(s32 *)(a0 + 0x98) = 0;
        func_L01_004AA7E8(a0, 1);
        *(u128_t *)(a0 + 0x10) = *(u128_t *)(p + 0x190);
        func_L01_004450F0(a0, 3, -1);
        *(u16 *)(a0 + 0x34) |= 2;
    }
    if (D_001D545C == 0x18) *(f32 *)(a0 + 0x18) = 101.86f;
    else *(f32 *)(a0 + 0x18) = 48.84f;
}
/* localdecomp:end func_L24_003B7F00 */

/* localdecomp:start func_L24_003B8160 */
/* log: v1 from func_L24_003B7A70 (same file), offsets +0x40 */
typedef struct {
    u8 p0[0x70]; f32 f70; f32 f74; f32 f78; f32 f7C; f32 f80; u8 p84[0x18]; f32 f9C; f32 fA0;
    u8 pA4[0xC4]; s32 w168; f32 f16C;
} P_003B8160;

void func_L24_003B8160(u8 *a0) {
    M_003B7A70 *m = (M_003B7A70 *)a0;
    P_003B8160 *p;
    m->h34 &= ~0x41;
    m->h34 |= m->p24->h44 & 0x1000;
    m->w98 = m->p24->w10;
    p = (P_003B8160 *)m->p68;
    p->f74 = 0.1f;
    p->f70 = 0.5f;
    p->f78 = 0.5f;
    p->f7C = 1.0f;
    p->f80 = 0.7853982f;
    p->fA0 = 0.34906584f;
    p->f9C = 0.00392f;
    p->w168 = D_L24_001DD584;
    p->f16C = D_L24_001DD580;
    *(u128_t *)((u8 *)p + 0x190) = *(u128_t *)(a0 + 0x10);
    func_L01_0045BD78(m, D_L24_001DD57C, D_L24_001DD57C, 0.50265485f, 0.50265485f);
    if (m->b43 != 0) func_003C3A10(m, 0, 0, 3);
    func_L01_004450F0(m, 1, -1);
}
/* localdecomp:end func_L24_003B8160 */

INCLUDE_ASM("asm/levels", func_L24_003B8278);

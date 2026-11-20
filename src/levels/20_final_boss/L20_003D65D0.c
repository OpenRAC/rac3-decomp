#include "common.h"

typedef struct {
    u8 pad[0x2850];
    s32 w2850;
} Hero2850;

/* declared by functions of L20_003D61B8.c, which this file was cut from */
extern s32 func_L20_003D65D0(void *);
extern void func_003C3A10(void *, s32, s32, s32);
extern void func_L01_004450F0(void *, s32, s32);
extern s32 D_L20_001D67A8;
extern s32 D_L20_001DEBEC;

/* localdecomp:start func_L20_003D65D0 */
#include "vu0.h"
extern s32 D_L20_001D67A8;
__asm__(".extern D_L20_001D67A8, 16");
extern s32 D_L20_001DEBEC;
typedef int u128_003D65D0 __attribute__((mode(TI)));
struct V_003D65D0;
typedef struct M_003D65D0 {
    u8 pad_0[0x10];
    u128_003D65D0 pos; /* 0x10 */
    u8 pad_20[0x10];
    u8 f30; /* 0x30 */
    u8 pad_31[0x1];
    s16 f32; /* 0x32 */
    u16 flags; /* 0x34 */
    u8 pad_36[0xD];
    u8 f43; /* 0x43 */
    u8 pad_44[0x24];
    struct V_003D65D0 * pvar; /* 0x68 */
    u8 pad_6C[0x2C];
    s32 f98; /* 0x98 */
    u8 pad_9C[0x24];
    u128_003D65D0 m0; /* 0xC0 */
    u128_003D65D0 m1; /* 0xD0 */
    u128_003D65D0 m2; /* 0xE0 */
    u8 pad_F0[0x10];
} M_003D65D0;
typedef struct V_003D65D0 {
    u8 pad_0[0x30];
    f32 f30; /* 0x30 */
    s16 f34; /* 0x34 */
    u8 pad_36[0x3];
    u8 f39; /* 0x39 */
    u8 pad_3A[0x4];
    u8 f3E; /* 0x3E */
    u8 f3F; /* 0x3F */
    f32 f40; /* 0x40 */
    u8 f44; /* 0x44 */
    u8 f45; /* 0x45 */
    u8 f46; /* 0x46 */
    u8 pad_47[0x11];
    u8 f58; /* 0x58 */
    u8 pad_59[0x1];
    u8 f5A; /* 0x5A */
    u8 pad_5B[0x9];
    u8 f64; /* 0x64 */
    u8 pad_65[0xB];
    f32 f70; /* 0x70 */
    f32 f74; /* 0x74 */
    f32 f78; /* 0x78 */
    f32 f7C; /* 0x7C */
    f32 f80; /* 0x80 */
    u8 pad_84[0x18];
    f32 f9C; /* 0x9C */
    f32 fA0; /* 0xA0 */
    u8 pad_A4[0xCC];
    u8 f170; /* 0x170 */
    u8 pad_171[0x1F];
    f32 f190; /* 0x190 */
    f32 f194; /* 0x194 */
    u8 pad_198[0x4];
    f32 f19C; /* 0x19C */
    u8 pad_1A0[0x8];
    u8 f1A8; /* 0x1A8 */
    u8 pad_1A9[0x2E];
    u8 f1D7; /* 0x1D7 */
    u8 f1D8; /* 0x1D8 */
    u8 f1D9; /* 0x1D9 */
    u8 f1DA; /* 0x1DA */
    u8 f1DB; /* 0x1DB */
    u8 pad_1DC[0x3C];
    s32 f218; /* 0x218 */
    u8 pad_21C[0xDC];
    struct M_003D65D0 * f2F8; /* 0x2F8 */
    struct M_003D65D0 * f2FC; /* 0x2FC */
    u8 pad_300[0x2B0];
    u128_003D65D0 f5B0; /* 0x5B0 */
    u8 pad_5C0[0xC];
    s32 f5CC; /* 0x5CC */
    u8 pad_5D0[0x44];
    s32 f614; /* 0x614 */
    struct M_003D65D0 * f618; /* 0x618 */
    u8 pad_61C[0x4];
    s32 f620; /* 0x620 */
    s32 f624; /* 0x624 */
    s32 f628; /* 0x628 */
    u8 pad_62C[0x24];
    s32 f650; /* 0x650 */
    u8 pad_654[0x24];
    s32 f678; /* 0x678 */
    struct M_003D65D0 * f67C; /* 0x67C */
} V_003D65D0;
extern M_003D65D0 *func_003C24B0(s32, s32);
extern void func_L01_00456160(M_003D65D0 *, M_003D65D0 *);
extern void func_L01_004AA7E8(void *, s32);
extern void func_0038CF68(void *, void *, f32);
extern void func_0038CE90(void *, void *, void *);
extern void func_L01_0045BD78(void *, f32, f32, f32, f32);
extern s32 func_L01_0041A4F0(void);
extern void func_L01_004450F0(void *, s32, s32);
extern void func_003C3A10(void *, s32, s32, s32);
extern s32 D_L20_001DEBF0;
extern s32 D_L20_001DEBF4;
extern f32 D_L20_001DEBF8;
extern f32 D_L20_001DEBBC;
extern f32 D_L20_001DEBC0;
extern M_003D65D0 *D_L20_001E029C;
__asm__(".extern D_L20_001DEBEC, 4");
__asm__(".extern D_L20_001DEBF0, 4");
__asm__(".extern D_L20_001DEBF4, 4");
__asm__(".extern D_L20_001DEBF8, 4");
__asm__(".extern D_L20_001DEBBC, 4");
__asm__(".extern D_L20_001DEBC0, 4");
__asm__(".extern D_L20_001E029C, 4");
extern s32 D_L20_001E2640[4] __attribute__((section(".sdata")));
extern u8 D_L20_002A2940[];
extern u128_003D65D0 D_L20_001E2600 __attribute__((section(".sdata")));
extern u128_003D65D0 D_L20_001E2610 __attribute__((section(".sdata")));
extern u128_003D65D0 D_L20_001E2620 __attribute__((section(".sdata")));
extern u128_003D65D0 D_L20_001E2630 __attribute__((section(".sdata")));

s32 func_L20_003D65D0(void *arg) {
    M_003D65D0 *a0 = arg;
    V_003D65D0 *p = a0->pvar;
    s32 i;
    s32 *ip;
    u128_003D65D0 *vb;
    u128_003D65D0 *vc;

    a0->flags |= 0x800;
    p->f5B0 = a0->pos;
    p->f2F8 = func_003C24B0(0x1CB4, 0x80);
    p->f2FC = func_003C24B0(0x1CB4, 0x80);
    func_L01_00456160(p->f2F8, a0);
    func_L01_00456160(p->f2FC, a0);
    a0->f30 = 0xFF;
    a0->f32 = 0xFF;
    D_L20_001DEBEC = 0;
    D_L20_001DEBF0 = 0;
    D_L20_001DEBF4 = 0;
    p->f2F8->flags |= 0x41;
    p->f2F8->flags &= ~0x1000;
    p->f2F8->f98 = 0;
    func_L01_004AA7E8(p->f2F8, 1);
    p->f2FC->flags |= 0x41;
    p->f2FC->flags &= ~0x1000;
    p->f2FC->f98 = 0;
    func_L01_004AA7E8(p->f2FC, 1);
    i = 3;
    ip = &D_L20_001E2640[3];
    for (; i >= 0; i--) {
        *ip-- = 0;
    }
    func_0038CF68(D_L20_002A2940, &a0->m0, D_L20_001DEBF8);
    vb = &a0->m1;
    vc = &a0->m2;
    D_L20_001E2600 = a0->m2;
    func_0038CF68(D_L20_002A2940 + 0x140, vb, D_L20_001DEBF8);
    D_L20_001E2610 = a0->m0;
    func_0038CF68(D_L20_002A2940 + 0x280, vc, D_L20_001DEBF8);
    D_L20_001E2620 = a0->m1;
    vec_add_ab(D_L20_002A2940 + 0x3C0, &a0->m0, &a0->m2);
    func_0038CF68(D_L20_002A2940 + 0x3C0, D_L20_002A2940 + 0x3C0, D_L20_001DEBF8);
    func_0038CE90(&D_L20_001E2630, D_L20_002A2940 + 0x3C0, vb);
    if (p->f614 != -1) {
        p->f618 = &D_L20_001E029C[p->f614];
        p->f618->flags |= 0x41;
    }
    if (p->f678 != -1) {
        p->f67C = &D_L20_001E029C[p->f678];
        p->f67C->flags |= 0x41;
    }
    p->f170 = 0x23;
    p->f1A8 = 3;
    p->f1D7 = 1;
    p->f1DB = 0xFF;
    p->f1D8 = 0;
    p->f1D9 = 0;
    p->f1DA = 0;
    p->f190 = 0.5f;
    p->f194 = 0.5f;
    p->f74 = 0.5f;
    p->f19C = 0.15f;
    p->f218 = 1;
    p->f70 = 0.7f;
    p->f78 = 1.0f;
    p->f7C = 2.0f;
    p->f80 = 1.553343f;
    p->fA0 = 0.34906584f;
    p->f9C = 0.00392f;
    func_L01_0045BD78(a0, D_L20_001DEBC0 * 0.00040000002f, D_L20_001DEBBC * 0.020000001f, 0.010053097f, 0.25132743f);
    p->f58 = 0x14;
    p->f5A = 0xE;
    if (p->f34 == 0) {
        p->f34 = 2000;
        p->f30 = 2000.0f;
    }
    if (p->f44 == 0) {
        p->f44 = 60;
        p->f45 = 60;
        p->f46 = 60;
    }
    if (func_L01_0041A4F0() != 0) {
        p->f34 = 32000;
        p->f30 = 32000.0f;
    }
    if (D_L20_001D67A8 == 5 || D_L20_001D67A8 == 6) {
        p->f34 = p->f34 * 0.9f;
        p->f30 = p->f34;
    } else if (D_L20_001D67A8 == 7) {
        p->f34 = p->f34 * 0.8f;
        p->f30 = p->f34;
    } else if (D_L20_001D67A8 == 8) {
        p->f34 = p->f34 * 0.75f;
        p->f30 = p->f34;
    } else if (D_L20_001D67A8 >= 9) {
        p->f34 = p->f34 * 0.5f;
        p->f30 = p->f34;
    }
    p->f620 = p->f34 * 0.75f;
    p->f40 = 2.0f;
    p->f624 = p->f34 * 0.5f;
    p->f3F = 0;
    p->f628 = p->f34 * 0.25f;
    p->f39 = p->f5CC = 1;
    p->f3E = 3;
    p->f64 = 0;
    p->f650 = p->f34;
    func_L01_004450F0(a0, 2, 0);
    if (a0->f43 != 0) {
        func_003C3A10(a0, 0, 0, 0);
    }
    return 0;
}
/* localdecomp:end func_L20_003D65D0 */

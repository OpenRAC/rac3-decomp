#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L19_003D98E0 */
typedef int u128_t_3D98E0 __attribute__((mode(TI)));
typedef struct P_3D98E0 {
    u8 pad0[0x10];
    f32 f10;
    s16 f14;
} P_3D98E0;
typedef struct S_3D98E0 {
    u8 pad0[0x20];
    u8 f20;
    u8 pad1[0x3];
    u8 *f24;
    u8 pad2[0x4];
    f32 f2C;
    u8 pad3[0x1];
    u8 f31;
    u8 pad4[0x2];
    u16 f34;
    u8 pad5[0xC];
    u8 f42;
    u8 f43;
    u8 pad6[0x1C];
    u8 f60;
    u8 pad7[0x7];
    P_3D98E0 *f68;
    u8 pad8[0x8C];
    f32 fF8;
} S_3D98E0;
extern u8 D_001A4BE0[];
typedef struct { u8 pad[0x24]; s32 i24; u8 pad28[0x6C - 0x28]; s32 i6C; u8 pad70[6]; s16 h76; u8 pad78[0x94 - 0x78]; s32 i94; s16 h98; u8 pad9A[4]; s16 h9E; } G_3D98E0;
extern G_3D98E0 D_001CCFD0;
extern u8 D_00142CC3[];
extern u8 D_00142D63[];
typedef struct T_3D98E0 { s16 f0; s16 f2; s32 f4; } T_3D98E0;
extern T_3D98E0 D_L19_001DF434;
__asm__(".extern D_L19_001DF434, 16");
extern s32 D_L19_001DF05C;

extern void func_003C2880(void *);
extern void func_L01_004450F0(void *, s32, s32);
extern s32 func_L01_00456250(void *);
extern void func_L19_003D9B70(u8 *);
extern s32 func_L01_004561B8(void *);
extern s32 func_003A1798(void);
extern void func_L04_003E3978(void *);
extern void func_L01_0050FB40(s32, s32, f32);
extern void func_003C3A10(void *, s32, s32, s32);
extern void func_L01_00451F60(s32, s32, s32);
extern s32 func_0038CB00(void *);
extern void func_0039EF28(void);
extern void func_L01_00419060(s32);
extern void func_L01_004F50C8(void *, void *, s32, s32);
extern void func_L01_003EB5E0(s32, s32);
extern s32 func_0039EC28(s32, s32);

void func_L19_003D98E0(void *m) {
    S_3D98E0 *s = m;
    P_3D98E0 *p;
    u8 *c;
    u8 *g;

    p = s->f68;
    if (s->f20 == 0) {
        if (D_00142CC3[0] != 0) {
            func_003C2880(s);
            return;
        }
        *(u128_t_3D98E0 *)p = *(u128_t_3D98E0 *)((u8 *)s + 0x10);
        p->f10 = s->fF8;
        s->f31 = 0;
        s->f34 = s->f34 | 1;
        func_L01_004450F0(s, 1, -1);
    }

    switch (s->f20) {
    case 1:
        if (func_L01_00456250(s)) {
            func_L19_003D9B70((u8 *)s);
        }
        break;
    case 2:
        c = (u8 *)&D_001CCFD0;
        if (*(s16 *)(c + 0x76) == 0) {
            if (*(s16 *)(c + 0x9E) == 3 && *(s16 *)(c + 0x98) < 0x1B58) {
                if (func_L01_004561B8(s)) {
                    func_003A1798();
                }
            }
        }
        g = D_001A4BE0;
        *(s16 *)(g + 0x1DC) = 3;
        D_L19_001DF434.f4 = 1;
        func_L04_003E3978(s);
        *(u128_t_3D98E0 *)((u8 *)s + 0x10) = *(u128_t_3D98E0 *)(g + 0x80);
        *(u128_t_3D98E0 *)((u8 *)s + 0xF0) = *(u128_t_3D98E0 *)(g + 0x90);
        if (*(u32 *)(g + 0xC08) & 2) {
            func_L01_0050FB40(0, 0, 25.0f);
        }
        if (s->f42 == 1 && (s->f60 & 2)) {
            if (s->f43 != 0) {
                func_003C3A10(s, 0, 0, 0);
            }
            s->f31 = 0;
            s->f34 = s->f34 | 1;
            func_L01_004450F0(s, 3, -1);
        }
        break;
    case 4:
        if (func_L01_004561B8(s)) {
            func_L01_00451F60(0xAF5, 0x64, 0);
        }
        func_003C2880(s);
        break;
    case 3:
        if (func_0038CB00((u8 *)p + 0x14) != 0) {
            u8 *h;
            D_00142CC3[0] = 1;
            D_00142D63[0] = 1;
            func_0039EF28();
            func_L01_00419060(0x23);
            h = D_001A4BE0;
            *(s32 *)(h + 0x25F8) = 0x23;
            D_L19_001DF05C = 0;
            func_L01_004F50C8(h + 0x80, h + 0x90, 0, 0);
            func_L01_003EB5E0(0, 0);
            func_0039EC28(0, -1);
            func_L01_004450F0(s, 4, -1);
        }
        break;
    }
}
/* localdecomp:end func_L19_003D98E0 */

/* localdecomp:start func_L19_003D9B70 */
typedef int u128_t_3D9B70 __attribute__((mode(TI)));
extern u8 D_001A4BE0[];
extern u8 D_001D5469;
extern s32 D_L19_001DF05C;
extern G_3D98E0 D_001CCFD0;
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern f32 func_0038DAB8(f32, f32);
extern f32 func_0038DB00(f32, f32);
extern void func_0038A238(s32);
extern void func_L01_004ED658(s32);
extern void func_L01_004F50C8(void *, void *, s32, s32);
extern void func_L01_003EB438(s32, void *, void *, s32, s32, s32);
extern void func_L01_003EB350(s32, void *);
extern void func_L01_003EB3C0(s32, void *);
extern void func_003C3A10(void *, s32, s32, s32);
extern void func_L01_0050FB40(s32, s32, f32);
extern void func_003A2B68(s32, s32);
extern void func_L01_004450F0(void *, s32, s32);

void func_L19_003D9B70(u8 *a0) {
    u8 *q = *(u8 **)(a0 + 0x68);
    f32 v[4];
    f32 w[4];
    f32 v2[4];
    f32 w2[4];
    u8 *h;

    a0[0x31] = 1;
    *(u16 *)(a0 + 0x34) &= 0xFFFE;
    *(f32 *)(a0 + 0x2C) = *(f32 *)(*(u8 **)(a0 + 0x24) + 0x24);
    v[0] = func_0038D098(*(f32 *)(q + 0x10)) * 2.5f;
    v[1] = func_0038D0B0(*(f32 *)(q + 0x10)) * 2.5f;
    v[2] = 0.0f;
    vec_add_ab(v, v, q);
    qzero(w);
    w[2] = func_0038DAB8(*(f32 *)(q + 0x10), 3.1415927f);
    func_0038A238(8);
    h = D_001A4BE0;
    if (h[0x25E4] == 3) {
        func_L01_004ED658(0);
    }
    func_L01_004F50C8(v, w, 0x74, 0);
    v2[0] = func_0038D098(*(f32 *)(q + 0x10)) * 1.25f;
    v2[1] = func_0038D0B0(*(f32 *)(q + 0x10)) * 1.25f;
    v2[2] = 0.0f;
    v2[0] = v2[0] + func_0038D098(func_0038DAB8(*(f32 *)(q + 0x10), 1.5707964f)) * 4.0f;
    v2[1] = v2[1] + func_0038D0B0(func_0038DAB8(*(f32 *)(q + 0x10), 1.5707964f)) * 4.0f;
    vec_add_ab(v2, v2, q);
    v2[2] = v2[2] + 1.0f;
    qzero(w2);
    w2[2] = func_0038DB00(*(f32 *)(q + 0x10), 1.5707964f);
    func_L01_003EB438(0, v2, w2, 1, 0, 0);
    func_L01_003EB350(0, v2);
    func_L01_003EB3C0(0, w2);
    *(u128_t_3D9B70 *)(a0 + 0x10) = *(u128_t_3D9B70 *)(h + 0x80);
    *(u128_t_3D9B70 *)(a0 + 0xF0) = *(u128_t_3D9B70 *)(h + 0x90);
    if (a0[0x43] != 1) {
        func_003C3A10(a0, 1, 2, 0);
    }
    func_L01_0050FB40(0x66, 0, 0.0f);
    if (D_001D5469 != 0) {
        *(u16 *)(a0 + 0x34) |= 0x8000;
    }
    h[0x25F0] = 1;
    D_L19_001DF05C = 1;
    *(s16 *)(q + 0x14) = 0x32;
    if (D_001CCFD0.i6C == 0) {
        if (D_001CCFD0.i24 == -1 && D_001CCFD0.i94 == 0) {
            func_003A2B68(0xEB8, 0);
        }
    }
    func_L01_004450F0(a0, 2, -1);
}
/* localdecomp:end func_L19_003D9B70 */

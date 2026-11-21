#include "common.h"

/* NTSC-U counterpart of func_L39_00556638 (src/levels/shared/L39_00554E60.c) */
#include "vu0.h"
extern f32 func_L01_00443D00(void *, void *, f32, s32, void *);
#include "vu0.h"
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_00555548;
struct O_00555548;
typedef struct { u8 pad0[0x7C]; f32 f7C; s32 s80; s32 s84; u8 pad88[8]; s32 s90; u8 pad94[8]; s32 s9C; s32 sA0; f32 fA4; s32 sA8; } A_00555548;
typedef struct { u8 pad0[0x240]; struct O_00555548 *p240; u8 pad244[0x254 - 0x244]; s32 i254; u8 pad258[0x27B - 0x258]; u8 b27B; } S2530_00555548;
typedef struct { u8 pad0[0x1A4]; s32 i1A4; u8 pad1A8[0x1D4 - 0x1A8]; s32 i1D4; } S2534_00555548;
typedef struct {
    u8 pad0[0x20];
    u8 m20[0x80];
    V4_00555548 vA0;
    V4_00555548 vB0;
    u8 padC0[0x60];
    V4_00555548 v120;
    u8 pad130[0x1A0A - 0x130];
    u8 b1A0A;
    u8 pad1A0B[9];
    u8 b1A14;
    u8 pad1A15[0x2458 - 0x1A15];
    s32 i2458;
    u8 pad245C[0x24CC - 0x245C];
    u32 i24CC;
    s32 i24D0;
    u8 pad24D4[0x2530 - 0x24D4];
    S2530_00555548 *p2530;
    S2534_00555548 *p2534;
    u8 pad2538[0x2548 - 0x2538];
    s32 i2548;
    u8 pad254C[0x4D30 - 0x254C];
    V4_00555548 v4D30;
    u8 pad4D40[0x4D68 - 0x4D40];
    f32 f4D68;
} W_00555548;
typedef struct O_00555548 {
    u8 pad0[0x10];
    V4_00555548 pos;
    u8 state;
    u8 pad21[0x10];
    u8 b31;
    u8 pad32[0x43 - 0x32];
    u8 b43;
    u8 pad44[4];
    f32 f48;
    u8 pad4C[0x60 - 0x4C];
    u8 b60;
    u8 pad61[7];
    A_00555548 *a68;
    u8 pad6C[3];
    u8 b6F;
    u8 pad70[0x96 - 0x70];
    u16 h96;
    u8 pad98[0xA8 - 0x98];
    u8 bA8;
    u8 padA9[0xF0 - 0xA9];
    V4_00555548 vF0;
} O_00555548;
extern W_00555548 *D_L39_0024CF20[1];
extern void func_L39_00555C28(void *, s32, s32);
extern s32 func_L39_005B24C8(s32, s32);
extern f32 func_L39_005B2510(f32, f32);
#include "vu0.h"
extern s32 func_L39_005B24C8(s32, s32);

/* localdecomp:start func_L39_00555C28 */
#include "vu0.h"

extern vu0_q D_L39_0025F870;
extern u8 D_L39_004998A0[];
extern f32 D_L39_0024DDC0[];
extern void func_L39_00625F88(void *);
extern s32 func_0037E0B8(u8 *);
extern void func_L39_00635680(void *, void *, void *, s32, s32, s32, s32);
extern void func_L39_00625860(void *, s32);
extern f32 func_L39_005B25C8_00555C28(void);
extern void func_0037E4B8(void *, f32, f32, f32);
extern void func_L39_005C6980(void *, void *, s32, s32, s32, f32);
extern f32 func_00388A28(f32, f32);
extern f32 func_L39_005B2568(f32, f32);
extern f32 func_00389380(f32, f32);
extern f32 func_00388960(f32);
extern f32 func_00388978(f32);
extern void func_L01_00471248(void *, void *, s32);
extern void func_L01_003D46A8(void *, s32, s32, s32, s32, f32, f32);
extern void func_L39_0051AC58(void *, void *, void *);
extern void func_L39_00556268(void *);
extern void func_003BD360(void *);

void func_L39_00555C28(void *arg0, s32 a1, s32 a2) {
    u8 *a0 = arg0;
    vu0_v4 b;
    vu0_v4 a;
    u8 *p;
    s32 i;
    s32 j2;

    p = (u8 *)D_L39_0024CF20[*(s32 *)(*(u8 **)(a0 + 0x68) + 0x9C)];
    if (p != 0) {
        *(s32 *)(p + 0x2458) = 0;
        if (p[0x1A14] != 0) {
            *(vu0_q *)&b = *(vu0_q *)(a0 + 0x10);
            *(vu0_q *)&a = *(vu0_q *)&b;
            a.z += 2.0f;
            b.z -= 0.5f;
            if (func_L01_00443D00(&a, &b, *(f32 *)(p + 0x1F4), 0x80, a0) < 1.0f) {
                *(vu0_q *)(a0 + 0x10) = D_L39_0025F870;
            }
            *(vu0_q *)(p + 0xA0) = *(vu0_q *)(a0 + 0x10);
            *(vu0_q *)(p + 0xB0) = *(vu0_q *)(a0 + 0xF0);
        }
        if (a1 != 0) {
            u8 *q;
            func_L39_00625F88(p);
            q = (u8 *)func_0037E0B8(*(u8 **)(p + 0x2524));
            if (q != 0) {
                q[0xE] = 1;
            }
            if (p[0x1A14] != 0) {
                p[0x1A0A] = 1;
                func_L39_00635680(p, a0 + 0x10, a0 + 0xF0, 0, 1, 1, 0);
            }
        } else {
            s16 flag;
            if (*(u8 **)(p + 0x2530) != 0 && (*(u8 **)(p + 0x2530))[0x27B] != 0) {
                u8 *q;
                long t;
                s32 x;
                flag = 0;
                q = p + 0x19E4;
                t = *q;
                x = 0;
                if (t != 0) {
                    u8 *d;
                    s32 m;
                    s32 k;
                    s32 n = *q;
                    s32 j;
                    m = n + 1;
                    k = ((s32)q - n) & 7;
                    d = (u8 *)&b;
                    for (j = 0; j < 40; j += 5) {
                        *d++ = D_L39_004998A0[m + ((k + j) & 7) * 255];
                    }
                    ((u32 *)&b)[0] ^= (u32)q;
                    ((u32 *)&b)[1] ^= ((u32 *)&b)[0];
                    x = ((u32 *)&b)[1];
                }
                if ((x ^ 0x31) == 0) {
                    flag++;
                }
            } else {
                flag = 0;
            }
            if ((u8)flag) {
                func_L39_00625860(p, 0);
                (*(s32 (**)(void *, s32, s32, s32, s32))(*(u8 **)(p + 0x14) + 0x34))(p, 0x76, 0, 1, 0);
                if (p[0x1A14] == 0) {
                    p[0x1A0A] = 2;
                }
            }
        }
    }

    for (j2 = 0; j2 < 15; j2++) {
        f32 x, y, z;
        x = func_L39_005B2510(0.0f, 0.37f);
        y = func_L39_005B25C8_00555C28();
        z = func_L39_005B25C8_00555C28();
        func_0037E4B8(&a, x, y, z);
        a.z += func_L39_005B2510(0.35f, 0.6f);
        vec_add_ba(&a, &a, a0 + 0x10);
        x = func_L39_005B2510(0.0025000001f, 0.020000001f);
        y = func_L39_005B25C8_00555C28();
        z = func_L39_005B25C8_00555C28();
        func_0037E4B8(&b, x, y, z);
        func_L39_005C6980(&a, &b, 0x4F7F7F7F, 0x202020, func_L39_005B24C8(0x1E, 0x39), 150000.0f);
    }

    for (i = 0; i < 20; i++) {
        f32 r, ang, t, h;
        ang = func_00388A28(D_L39_0024DDC0[0x50] - *(f32 *)(a0 + 0x10), D_L39_0024DDC0[0x51] - *(f32 *)(a0 + 0x14));
        func_L39_005B2568(1.0f, 2.0f);
        b.x = *(f32 *)(a0 + 0x10) + func_L39_005B2568(0.0f, 0.15f);
        b.y = *(f32 *)(a0 + 0x14) + func_L39_005B2568(0.0f, 0.15f);
        b.z = *(f32 *)(a0 + 0x18) + func_L39_005B2568(0.0f, 0.15f);
        r = func_L39_005B2510(3.0f, 7.0f);
        t = func_L39_005B2568(0.0f, 2.6179938f);
        r *= 0.016666668f;
        h = func_00389380(ang, t);
        a.x = func_00388960(h) * r;
        a.y = func_00388978(h) * r;
        a.z = 0.0f;
        a.z = func_L39_005B2510(5.0f, 10.0f) * 0.016666668f;
        func_L01_00471248(&b, &a, 0xAA);
    }

    func_L01_003D46A8(a0, 0x4E, 0x4F, 0xA, 1, 1.5f, 1.2f);

    for (i = 0; i < 10; i++) {
        f32 x, y, z, w, v;
        x = func_L39_005B2510(0.0f, 0.35f);
        y = func_L39_005B25C8_00555C28();
        z = func_L39_005B25C8_00555C28();
        func_0037E4B8(&a, x, y, z);
        a.z += 0.25f;
        vec_add_ba(&a, &a, a0 + 0x10);
        w = func_L39_005B2510(0.050000004f, 0.10000001f);
        v = func_L39_005B25C8_00555C28();
        func_0037E4B8(&b, w, v, 1.2217305f);
        b.z = func_L39_005B2510(3.0f, 5.0f) * 0.016666668f;
        func_L39_0051AC58(a0, &a, &b);
    }

    func_L39_00556268(a0);
    func_003BD360(a0);
}
/* localdecomp:end func_L39_00555C28 */

#include "common.h"

/* NTSC-U counterpart of func_L39_0051DD30 (src/levels/shared/L39_0051CEF8.c) */
#include "vu0.h"
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_0051CEF8;
typedef struct {
    u8 pad0[0x7C];
    f32 f7C;
    s32 f80;
    s32 f84;
    u8 pad88[0x8];
    s32 f90;
    u8 pad94[0x8];
    s32 f9C;
} P_0051CEF8;
typedef struct {
    u8 pad0[0x10];
    V4_0051CEF8 pos;
    u8 b20;
    u8 pad21[0x10];
    u8 b31;
    u8 pad32[0x11];
    u8 b43;
    u8 pad44[0x4];
    f32 f48;
    u8 pad4C[0x14];
    u8 b60;
    u8 pad61[0x7];
    P_0051CEF8 *pv;
    u8 pad6C[0x3];
    u8 b6F;
    u8 pad70[0x38];
    u8 bA8;
    u8 padA9[0x47];
    V4_0051CEF8 vF0;
} M_0051CEF8;
typedef struct {
    u8 pad0[0x240];
    M_0051CEF8 *f240;
    u8 pad244[0x10];
    s32 f254;
    u8 pad258[0x23];
    u8 b27B;
} C_0051CEF8;
typedef struct {
    u8 pad0[0x1A4];
    s32 f1A4;
    u8 pad1A8[0x2C];
    s32 f1D4;
} G_0051CEF8;
typedef struct {
    u8 pad0[0x20];
    u8 v20[0x80];
    V4_0051CEF8 vA0;
    V4_0051CEF8 vB0;
    u8 padC0[0x60];
    V4_0051CEF8 v120;
    u8 pad130[0xE84];
    f32 fFB4;
    u8 padFB8[0xA52];
    u8 b1A0A;
    u8 pad1A0B[0x9];
    u8 b1A14;
    u8 pad1A15[0xA43];
    s32 f2458;
    u8 pad245C[0x70];
    u32 f24CC;
    s32 f24D0;
    u8 pad24D4[0x5C];
    C_0051CEF8 *f2530;
    G_0051CEF8 *f2534;
    u8 pad2538[0x10];
    s32 f2548;
    u8 pad254C[0x27E4];
    V4_0051CEF8 v4D30;
} Pl_0051CEF8;
extern Pl_0051CEF8 *D_L39_0024CF20[8] __attribute__((section(".sdata")));
extern void func_L39_0051D918(void *, s32, s32);
extern s32 func_L39_005B24C8(s32, s32);
extern f32 func_L39_005B2510(f32, f32);
#include "vu0.h"
extern s32 func_L39_005B24C8(s32, s32);

/* localdecomp:start func_L39_0051D918 */
#include "vu0.h"
typedef int Q_0051DD30 __attribute__((mode(TI)));
typedef union { Q_0051DD30 q; struct { f32 x, y, z, w; } f; s32 w[4]; u8 c[16]; } V_0051DD30;

extern Q_0051DD30 D_L39_0025F870;
extern u8 D_L39_004998A0[];
extern s32 D_L39_0024D590_b;
typedef struct { u8 pad0[0x140]; f32 x; f32 y; } T_0051DD30;
extern T_0051DD30 D_L39_0024DDC0;
extern f32 func_L01_00443D00(f32, void *, void *, s32, void *);
extern void func_L39_00625F88(void *);
extern u8 *func_0037E0B8(void *);
extern void func_L39_00635680(void *, void *, void *, s32, s32, s32, s32);
extern void func_L39_00625860(void *, s32);
extern f32 func_L39_005B2510(f32, f32);
extern f32 func_L39_005B25C8_0051D918(void);
extern void func_0037E4B8(void *, f32, f32, f32);
extern s32 func_L39_005B24C8(s32, s32);
extern void func_L39_005C6980(void *, void *, s32, s32, s32, f32);
extern f32 func_00388A28(f32, f32);
extern f32 func_L39_005B2568(f32, f32);
extern f32 func_00389380(f32, f32);
extern f32 func_00388960(f32);
extern f32 func_00388978(f32);
extern u8 *func_L39_005D04C0(void *, void *, s32);
extern void func_L39_0051DE40(void *);
extern void func_003BD360(void *);

/* the 5-step byte decode of an obfuscated u32, as in matched func_L39_00524E00 */
static __inline__ u32 dec5_0051DD30(u8 *p) {
    union { u8 b[8]; u32 w[2]; } buf;
    u32 a;
    u32 b;
    s32 n;
    s32 k;
    s32 m;
    s32 i;
    u8 *d;

    if (*p == 0) {
        return 0;
    }
    n = *p;
    k = ((u32)p - n) & 7;
    m = n + 1;
    d = buf.b;
    for (i = 0; i < 40; i += 5) {
        *d++ = D_L39_004998A0[m + ((k + i) & 7) * 255];
    }
    a = buf.w[0] ^ (u32)p;
    b = buf.w[1] ^ a;
    buf.w[0] = a;
    buf.w[1] = b;
    return b;
}

/* from rac2-decomp's func_003320F0 */
void func_L39_0051D918(void *m0, s32 a1, s32 a2) {
    u8 *m = m0;
    u8 *p;
    u8 *q;
    s32 i;
    s32 j;
    f32 ra, rb, rc, p1, p2;

    p = (u8 *)D_L39_0024CF20[*(s32 *)(*(u8 **)(m + 0x68) + 0x9C)];
    if (p != 0) {
        *(s32 *)(p + 0x2458) = 0;
        if (p[0x1A14]) {
            V_0051DD30 b;
            V_0051DD30 a;
            {
                a.q = *(Q_0051DD30 *)(m + 0x10);
                b.q = a.q;
                a.f.z += 2.0f;
                if (func_L01_00443D00(*(f32 *)(p + 0x1F4), &a, &b, 0, m) < 1.0f) {
                    *(Q_0051DD30 *)(m + 0x10) = D_L39_0025F870;
                }
                *(Q_0051DD30 *)(p + 0xA0) = *(Q_0051DD30 *)(m + 0x10);
                *(Q_0051DD30 *)(p + 0xB0) = *(Q_0051DD30 *)(m + 0xF0);
            }
        }
        if (a1) {
            func_L39_00625F88(p);
            q = func_0037E0B8(*(void **)(p + 0x2524));
            if (q) q[0xE] = 1;
            if (p[0x1A14]) {
                p[0x1A0A] = 1;
                func_L39_00635680(p, m + 0x10, m + 0xF0, 0, 1, 1, 0);
            }
        } else {
            u8 ok;
            u8 *t = *(u8 **)(p + 0x2530);
            if ((ok = t != 0 ? (t[0x27B] != 0 && (dec5_0051DD30(p + 0x19E4) ^ 0x31) == 0) : 0)) {
                *(Q_0051DD30 *)(p + 0xA0) = *(Q_0051DD30 *)(m + 0x10);
                *(Q_0051DD30 *)(p + 0xB0) = *(Q_0051DD30 *)(m + 0xF0);
                func_L39_00625860(p, 0);
                (*(s32 (**)(void *, s32, s32, s32, s32))(*(u8 **)(p + 0x14) + 0x34))(p, 0x76, 0, 1, 0);
                if (p[0x1A14] == 0) p[0x1A0A] = 2;
            }
        }
    }
    {
        V_0051DD30 b;
        V_0051DD30 a;
        {
            for (i = 0; i < 0x21 - D_L39_0024D590_b; i++) {
                ra = func_L39_005B2510(0.0f, 0.37f);
                rb = func_L39_005B25C8_0051D918();
                rc = func_L39_005B25C8_0051D918();
                func_0037E4B8(&a, ra, rb, rc);
                a.f.z += func_L39_005B2510(0.35f, 0.6f);
                vec_add_ba(&a, &a, m + 0x10);
                ra = func_L39_005B2510(0.0016666668f, 0.016666668f);
                rb = func_L39_005B25C8_0051D918();
                rc = func_L39_005B25C8_0051D918();
                func_0037E4B8(&b, ra, rb, rc);
                func_L39_005C6980(&a, &b, 0x4F20507F, 0x102F, func_L39_005B24C8(0x1E, 0x39), 150000.0f);
            }
            for (j = 0; j < 0x32 - D_L39_0024D590_b; j++) {
                p1 = func_00388A28(D_L39_0024DDC0.x - *(f32 *)(m + 0x10), D_L39_0024DDC0.y - *(f32 *)(m + 0x14));
                func_L39_005B2568(1.0f, 2.0f);
                b.f.x = *(f32 *)(m + 0x10) + func_L39_005B2568(0.0f, 0.15f);
                b.f.y = *(f32 *)(m + 0x14) + func_L39_005B2568(0.0f, 0.15f);
                b.f.z = *(f32 *)(m + 0x18) + func_L39_005B2568(0.0f, 0.15f);
                p2 = func_00389380(p1, func_L39_005B2568(0.0f, -1.5707964f));
                a.f.x = func_00388960(p2) * 0.13333334f;
                a.f.y = func_00388978(p2) * 0.13333334f;
                a.f.z = 0.15f;
                func_L39_005D04C0(&b.q, &a.q, 0x12C);
            }
        }
    }
    func_L39_0051DE40(m);
    func_003BD360(m);
}
/* localdecomp:end func_L39_0051D918 */

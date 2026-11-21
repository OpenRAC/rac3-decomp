#include "common.h"

/* NTSC-U counterpart of func_L07_003BBBA8 (src/levels/07_annihilation_nation/L07_003BBBA8.c) */
/* localdecomp:start func_L07_003BA2B8 */
#include "vu0.h"

typedef int u128_t_003BBBA8 __attribute__((mode(TI)));

extern u8 *D_L07_001DF41C_003BA2B8;
__asm__(".extern D_L07_001DF41C_003BA2B8, 16");
extern u8 *D_L07_001ECC80_003BA2B8[];
extern u8 *D_L07_0021D2C0_003BA2B8[];
extern u8 D_L07_001D66B0_003BA2B8[8];

extern void func_L07_003BABC8(void *);
extern void func_L07_003BADB0(void *);
extern s32 func_L07_003BB748(void *);
extern void func_L07_003BB2D8(void *);
extern void func_L07_003BB4C0(void *);
extern void func_L07_003BB540(void *);
extern void func_L07_003BB558(void *);
extern void func_L07_003BB378(void *);
extern void func_L07_003BB200(void *, s32);
extern void func_L07_003BB7E8(void *);
extern void func_L07_003BB320(void *);
extern void func_L07_003BB470(void *);
extern s32 func_L01_00452EC8(void *);
extern s32 func_003883C8(void *);
extern void func_L01_00441FB8(void *, s32, s32);
extern void func_00388830(void *, void *, f32);
extern s32 func_003CF790(void *, s32, f32, void *, void *);
extern f32 func_00388A28(f32, f32);
extern void func_L01_00407180(void *, void *, void *, s32, s32, s32, s32, s32, s32, s32);
extern void func_L03_004460F8(void *, s32, s32, s32);
extern void func_L03_00445EB8(void *, s32);
extern s32 func_L06_00455BC0(void *, void *, u8);
extern s32 func_L01_00458AE0(void *, s32);
extern f32 func_0037E250(f32, f32);
extern s32 func_L01_00457440(void *, void *);
extern f32 func_L01_0040C040(void *, void *);
extern f32 func_00389380(f32, f32);
extern s32 func_L01_003F9498(void *, s32, u8 *, f32);
extern void func_L01_0032FE90_003BA2B8(void *, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern void func_L01_0044ED60(void *, s32, void *, f32, f32, f32, f32, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32);
extern void func_L01_004412D0(void *, s32, s32);
extern s32 func_0039FE80(s32, s32, void *);

void func_L07_003BA2B8(u8 *m) {
    u8 *v;
    vu0_v4 tmp;
    vu0_v4 b;

    if (m[0x20] == 0) {
        func_L07_003BABC8(m);
    }
    func_L07_003BADB0(m);
    v = *(u8 **)(m + 0x68);
    switch (m[0x20]) {
    case 1:
        break;
    case 2:
        if (func_L01_00452EC8(m)) {
            *(s16 *)(v + 0x29E) = *(s16 *)(v + 0x29C);
        }
        if (func_L07_003BB748(m)) {
            if (func_003883C8(v + 0x29E)) {
                func_L01_00441FB8(m, 3, -1);
            }
        }
        break;
    case 3: {
        u8 *e;
        s32 n;
        s32 i;
        s32 ok;
        e = D_L07_001DF41C_003BA2B8 + (*(s32 *)(v + 0x298) << 8);
        func_00388830(&tmp, e + 0xE0, 0.8f);
        vec_add_ab(&tmp, e + 0x10, &tmp);
        n = func_003CF790(&tmp, 1, 0.8f, m, 0);
        ok = 1;
        for (i = 0; i < n; i++) {
            s16 c = *(s16 *)(D_L07_001ECC80_003BA2B8[i] + 0xAA);
            if (c == 0x1A85 || c == 0x19D2 || c == 0x1D88) {
                ok = 0;
                break;
            }
        }
        if (ok) {
            qzero(&b);
            b.z = func_00388A28(*(f32 *)(v + 0x220) - *(f32 *)(m + 0x10), *(f32 *)(v + 0x224) - *(f32 *)(m + 0x14));
            func_L01_00407180(m, &tmp, &b, 0, 2, 3, 0x2D, 0x2D, 0xFF8040, 0x8F1010);
            *(s32 *)(m + 0x98) = *(s32 *)(*(u8 **)(m + 0x24) + 0x10);
            func_L07_003BB2D8(m);
        }
        break;
    }
    case 4:
        func_L07_003BB4C0(m);
        if (func_L07_003BB748(m)) {
            func_L07_003BB378(m);
        }
        break;
    case 5:
        if (func_L01_00452EC8(m)) {
            u8 *q = v + 0x30;
            *(f32 *)(q + 0x20) = *(f32 *)(v + 0x2A0) * 0.00027777778f;
            *(f32 *)(q + 0x24) = *(f32 *)(v + 0x2A0) * 0.00027777778f;
            *(f32 *)(q + 0x28) = *(f32 *)(v + 0x2A0) * 0.016666668f;
            func_L03_004460F8(m, *(s32 *)(v + 0x290), 1, -1);
        }
        func_L07_003BB540(m);
        func_L03_00445EB8(m, *(s32 *)(v + 0x290));
        func_L07_003BB558(m);
        if (func_L07_003BB748(m)) {
            func_L07_003BB378(m);
        }
        break;
    case 6:
        if (func_L01_00452EC8(m)) {
            u8 *q = v + 0x30;
            u8 *t;
            *(f32 *)(q + 0x20) = *(f32 *)(v + 0x2A4) * 0.00027777778f;
            *(f32 *)(q + 0x24) = *(f32 *)(v + 0x2A4) * 0.00027777778f;
            *(f32 *)(q + 0x28) = *(f32 *)(v + 0x2A4) * 0.016666668f;
            t = D_L07_0021D2C0_003BA2B8[*(s32 *)(v + 0x294)];
            *(u8 **)(q + 0xC4) = t;
            *(u128_t_003BBBA8 *)&tmp = *(u128_t_003BBBA8 *)(m + 0x10);
            *(s16 *)(q + 0xC8) = func_L06_00455BC0(&tmp, t, 1);
            *(s16 *)(q + 0xCA) = 0;
        }
        if (func_L07_003BB748(m)) {
            func_L07_003BB378(m);
            break;
        }
        func_L07_003BB540(m);
        {
        s32 r = (u8)func_L01_00458AE0(m, *(s32 *)(v + 0x294));
        func_L07_003BB558(m);
        if (r) {
            func_L07_003BB2D8(m);
        }
        }
        break;
    case 8:
        if (func_L01_00452EC8(m)) {
            *(s16 *)(v + 0x29E) = (func_0037E250(0.0f, 0.5f) + 1.0f) * 120.0f;
        }
        func_L07_003BB4C0(m);
        if (func_L07_003BB748(m)) {
            func_L07_003BB200(m, 8);
        } else if (func_003883C8(v + 0x29E)) {
            func_L07_003BB320(m);
        }
        break;
    case 9:
        if (func_L01_00452EC8(m)) {
            u8 *q = v + 0x30;
            u8 *t;
            *(f32 *)(q + 0x20) = *(f32 *)(v + 0x2A4) * 0.00027777778f;
            *(f32 *)(q + 0x24) = *(f32 *)(v + 0x2A4) * 0.00027777778f;
            *(f32 *)(q + 0x28) = *(f32 *)(v + 0x2A4) * 0.016666668f;
            t = D_L07_0021D2C0_003BA2B8[*(s32 *)(v + 0x294)];
            *(u8 **)(q + 0xC4) = t;
            *(u128_t_003BBBA8 *)&tmp = *(u128_t_003BBBA8 *)(m + 0x10);
            *(s16 *)(q + 0xC8) = func_L06_00455BC0(&tmp, t, 1);
            *(s16 *)(q + 0xCA) = *(u16 *)t - 1;
        }
        if (!func_L07_003BB748(m)) {
            func_L07_003BB200(m, 8);
            break;
        }
        func_L07_003BB540(m);
        {
        s32 r = (u8)func_L01_00458AE0(m, *(s32 *)(v + 0x294));
        func_L07_003BB558(m);
        if (r) {
            func_L07_003BB200(m, 0xA);
        }
        }
        break;
    case 10:
        if (func_L01_00452EC8(m)) {
            u8 *q = v + 0x30;
            *(f32 *)(q + 0x20) = 0.016666668f;
            *(f32 *)(q + 0x28) = 0.5f;
            *(f32 *)(q + 0x24) = 0.016666668f;
        }
        vec_sub_ba(&tmp, m + 0x10, v + 0x220);
        tmp.z = 0.0f;
        func_00388830(&tmp, &tmp, 3.0f);
        vec_add_ba(&tmp, v + 0x220, &tmp);
        func_L07_003BB540(m);
        {
        s32 r = func_L01_00457440(m, &tmp);
        func_L07_003BB558(m);
        if (r & 0x80) {
            func_L07_003BB200(m, 0xB);
        }
        }
        break;
    case 11:
        *(f32 *)(m + 0xF0) *= 0.97f;
        *(f32 *)(m + 0xF4) *= 0.97f;
        if (m[0x60] & 2) {
            func_L07_003BB200(m, 0xC);
        }
        break;
    case 12:
        if (func_L01_00452EC8(m)) {
            *(f32 *)(m + 0x48) = 0.0f;
        }
        *(f32 *)(m + 0x48) += 0.02f;
        *(f32 *)(m + 0xF0) *= 0.97f;
        *(f32 *)(m + 0xF4) *= 0.97f;
        if (*(f32 *)(m + 0x48) >= 1.0f) {
            *(f32 *)(m + 0x48) = 1.0f;
            func_L07_003BB200(m, 0xD);
        }
        break;
    case 13:
        if (func_L01_00452EC8(m)) {
            u8 *q = v + 0x30;
            *(f32 *)(q + 0x20) = 0.0011111111f;
            *(f32 *)(q + 0x28) = 0.050000004f;
            *(f32 *)(q + 0x24) = 0.0011111111f;
        }
        *(f32 *)(m + 0xF0) *= 0.97f;
        *(f32 *)(m + 0xF4) *= 0.97f;
        func_L01_00457440(m, v + 0x220);
        func_L07_003BB7E8(m);
        if (!func_L07_003BB748(m)) {
            func_L07_003BB320(m);
        } else if (func_L01_0040C040(m + 0x10, v + 0x220) > 144.0f) {
            func_L07_003BB200(m, 0xA);
        }
        break;
    case 14: {
        u8 *pos;
        vu0_v4 *p;
        if (func_L01_00452EC8(m)) {
            *(s16 *)(v + 0x29E) = 0x1E;
        }
        pos = m + 0x10;
        *(f32 *)(m + 0xF8) = func_00389380(*(f32 *)(m + 0xF8), 0.41887906f);
        p = &tmp;
        vec_add_ba(m + 0x10, m + 0x10, v + 0xD0);
        *(u128_t_003BBBA8 *)p = *(u128_t_003BBBA8 *)(m + 0x10);
        tmp.z += 0.8f;
        if (func_003883C8(v + 0x29E) || func_L01_003F9498(p, 0, m, 0.9f)) {
            func_L01_0032FE90_003BA2B8(pos, 0, 5, 10, 10, 3, 0x14, 0, 0.3f, 0.0f, v[0x135], 1.0f,
                              0, 0, 0, 0, 0, 0, 0x1010000, 0, 0x388EF7, 0x63F7, 0x407FFF, 0x20FF,
                              0x8FFF, 0x3064FF, 0x7F60A0FF, 0x280000FF, 0x3064FF, 0);
            func_L01_0044ED60(m, 0x1F, D_L07_001D66B0_003BA2B8, 3.0f, 6.0f, 3.0f, 6.0f, 0xFF, 0xB4, 0, 0, 0x23, 0, 3,
                              -1.0f, -1.0f, 1.0f, 1.0f);
            func_L01_004412D0(m, 0, 3);
            func_L07_003BB470(m);
            func_0039FE80(2, 0, m);
        }
        break;
    }
    }
}
/* localdecomp:end func_L07_003BA2B8 */

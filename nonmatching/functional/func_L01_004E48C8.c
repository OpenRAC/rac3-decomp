/* functional: medium. Written from the PAL asm (no draft): call sequence identical to retail (17 calls, same order), constants checked bit for bit; branch structure re-derived by hand. 4-iteration probe loop reads D_L01_001DBFC8/D8 (gp slots) and D_L01_001EAA28 (loop-invariant in retail too). vadd/vsub xyz done in plain C keeping w from the first operand. Not gate-tested. */
#include "vu0.h"
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_4E48C8;
extern s32 D_L01_001D673C;
extern V4_4E48C8 D_L01_001EAA20;
extern f32 D_L01_001EAA28;
extern u128_t D_L01_001E0080;
extern f32 D_L01_001DBFC8[4];
extern f32 D_L01_001DBFD8[4];
void func_L01_004E48C8(void) {
    extern s32 func_003D3CB0(char *, char *, s32, s32, s32);
    extern void func_0038CE20(void *, void *, f32);
    extern f32 func_0038CE68(void *, void *);
    extern void func_0038CF68(void *, void *, f32);
    extern f32 func_0038D098(f32);
    extern f32 func_0038D0B0(f32);
    extern f32 func_0038D160(f32, f32);
    extern f32 func_0038DAB8(f32, f32);
    extern f32 func_0038DB00(f32, f32);
    extern void func_L01_0043BA48(void *, void *);
    u8 *h = (u8 *)&D_001A4BE0;
    u8 *m;
    V4_4E48C8 w, a, b;
    f32 f20, f21, f22, f23, f24, f25, f0, f1, f2, f4, f5, f6, f7;
    s32 i, near;

    if (*(s32 *)(h + 0x25CC) == 0x12 || *(s32 *)(h + 0x25C4) == 0x7F || *(s32 *)(h + 0x25C4) == 0x31) {
        if (*(s32 *)(h + 0x25CC) == 0x12) *(f32 *)(h + 0xE90) = 1.56f;
        m = *(u8 **)(h + 0x25C0);
        *(u16 *)(m + 0x34) &= 0xFBFF;
        return;
    }
    m = *(u8 **)(h + 0x25C0);
    *(u16 *)(m + 0x34) |= 0x400;
    if (D_L01_001D673C != 0 || (*(f32 *)(m + 0xE8) < 0.99f && *(s32 *)(h + 0x25CC) != 0x11)) {
        m = *(u8 **)(h + 0x25C0);
        m[0xBD] = 0xFF;
        func_0038CE20(&w, *(u8 **)(h + 0x25C0), 0.0009765625f);
        func_0038CE20(&a, *(u8 **)(h + 0x25C0) + 0xE0, -16.0f);
        a.x = w.x + a.x;
        a.y = w.y + a.y;
        a.z = w.z + a.z;
        a.w = w.w;
        if (func_003D3CB0((char *)&w, (char *)&a, 0x22, 0, 0)) {
            m = *(u8 **)(h + 0x25C0);
            b.x = D_L01_001EAA20.x - *(f32 *)(m + 0x10);
            b.y = D_L01_001EAA20.y - *(f32 *)(m + 0x14);
            b.z = D_L01_001EAA20.z - *(f32 *)(m + 0x18);
            b.w = D_L01_001EAA20.w;
            f0 = func_0038CE68(&b, m + 0xE0);
            m = *(u8 **)(h + 0x25C0);
            *(f32 *)(m + 0x70) = f0;
            m = *(u8 **)(h + 0x25C0);
            *(f32 *)(m + 0x74) = *(f32 *)(m + 0xC) * 0.000244140625f;
        } else {
            m = *(u8 **)(h + 0x25C0);
            *(s32 *)(m + 0x70) = 0;
            m = *(u8 **)(h + 0x25C0);
            *(s32 *)(m + 0x74) = 0;
        }
        *(f32 *)(h + 0xE90) = 1.56f;
        *(f32 *)(h + 0xE98) = 0.12f;
        *(f32 *)(h + 0xE94) = *(f32 *)(h + 0x88);
        return;
    }
    m = *(u8 **)(h + 0x25C0);
    m[0xBD] = 1;
    f0 = 1.15f;
    if (*(s16 *)(h + 0x36E) != 0 || *(s32 *)(h + 0x25CC) == 4) f0 = 1.56f;
    f0 = func_0038DB00(f0, *(f32 *)(h + 0xE90));
    f1 = 0.052000000f;
    if (f1 < f0) f0 = f1;
    f1 = -0.052000000f;
    if (f0 < f1) f0 = f1;
    *(f32 *)(h + 0xE90) = func_0038DAB8(*(f32 *)(h + 0xE90), f0);
    func_L01_0043BA48(*(u8 **)(h + 0x25C0), &w);
    f25 = func_0038D160(w.x, w.y);
    f21 = func_0038D098(f25);
    f20 = func_0038D0B0(f25);
    f0 = func_0038D098(*(f32 *)(h + 0xE90));
    f20 = f20 * f0;
    f21 = f21 * f0;
    w.y = f20;
    w.x = f21;
    f0 = func_0038D0B0(*(f32 *)(h + 0xE90));
    w.z = -f0;
    f22 = *(f32 *)(h + 0x338);
    D_L01_001E0080 = *(u128_t *)&w;
    if (f22 < 1.0f) {
        f22 = *(f32 *)(h + 0x350);
        if (!(1.0f <= f22)) {
            f22 = *(f32 *)(h + 0x354);
            if (!(1.0f < f22)) {
                m = *(u8 **)(h + 0x25C0);
                *(s32 *)(m + 0x70) = 0;
                m = *(u8 **)(h + 0x25C0);
                *(s32 *)(m + 0x74) = 0;
                *(s32 *)(h + 0xE98) = 0;
                *(f32 *)(h + 0xE94) = *(f32 *)(h + 0x88);
                return;
            }
        }
    }
    f0 = *(f32 *)(h + 0xE90) - 1.56f;
    f0 = fabs_asm(f0);
    near = f0 < 0.1f;
    if (!near) {
        f24 = f22;
        f23 = f22;
        for (i = 0; i < 4; i++) {
            m = *(u8 **)(h + 0x25C0);
            *(u128_t *)&a = *(u128_t *)(h + 0x80);
            f21 = *(f32 *)(m + 0xC) * 0.0009765625f;
            a.z = a.z + f21;
            f20 = func_0038DAB8(f25, D_L01_001DBFD8[i]);
            f0 = func_0038D098(f20);
            f0 = f0 * 0.35f;
            f0 = f0 * f21;
            a.x = a.x + f0;
            f0 = func_0038D0B0(f20);
            f0 = f0 * 0.35f;
            f0 = f0 * f21;
            f1 = a.y + f0;
            f2 = a.z + D_L01_001DBFC8[i] * f21;
            f4 = -w.z;
            a.z = f2;
            f1 = f1;
            a.y = f1;
            func_0038CF68(&b, &w, ((f2 - f22) + 0.4f) / f4);
            b.x = a.x + b.x;
            b.y = a.y + b.y;
            b.z = a.z + b.z;
            b.w = a.w;
            if (func_003D3CB0((char *)&a, (char *)&b, 0x22, 0, 0)) {
                f0 = D_L01_001EAA28;
                if (f24 < f0) f24 = f0;
                if (f0 < f23) f23 = f0;
            }
        }
        f5 = (f24 - f23) * 0.5f + 0.12f;
        f6 = (f23 + f24) * 0.5f;
    } else {
        f0 = *(f32 *)(h + 0x2C8);
        f0 = f0 * f0;
        f2 = 1.0f - f0;
        if (1.0f < f2) f2 = 1.0f;
        if (f2 < 0.0f) f2 = 0.0f;
        f6 = f22;
        f5 = f2 * 0.6f + 0.2f;
    }
    f4 = *(f32 *)(h + 0xE94);
    f7 = f6 - f5;
    f2 = *(f32 *)(h + 0xE98);
    f0 = (f6 - f4) * 0.125f;
    f1 = (f5 - f2) * 0.125f;
    f4 = f4 + f0;
    f0 = f2 + f1;
    *(f32 *)(h + 0xE94) = f4;
    *(f32 *)(h + 0xE98) = f0;
    f2 = f4 - f0;
    if (f7 < f2) f2 = f7;
    f1 = f4 + f0;
    f0 = f6 + f5;
    if (f1 < f0) f1 = f0;
    m = *(u8 **)(h + 0x25C0);
    *(f32 *)(m + 0x70) = (f1 + f2) * 0.5f - *(f32 *)(m + 0x18);
    m = *(u8 **)(h + 0x25C0);
    *(f32 *)(m + 0x74) = (f1 - f2) * 0.5f;
    m = *(u8 **)(h + 0x25C0);
    if (1.0f < *(f32 *)(m + 0x74)) *(f32 *)(m + 0x74) = 1.0f;
}

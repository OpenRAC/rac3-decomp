/* near miss (level 5, Daxx): 63 differences: file already @ps2as; most come from one shift: retail zeroes the 16-byte local with a bare sq zero (not reachable, gcc emits por + sq); also one addu operand order at the reset check and the sq lands in the jal delay slot */
#include "common.h"

/* localdecomp:start func_L05_0035F360 */
typedef struct { u8 pad[0x90]; f32 ang[4]; s32 lo[4]; s32 hi[4]; } Q_0035F360;
extern u8 *D_001DFB9C_sda;
__asm__(".extern D_001DFB9C_sda, 4");
extern s32 func_0038CB00(void *);
extern s32 func_00382498(s32, s32);
extern f32 func_003824E0(f32, f32);
extern f32 func_0038DAB8(f32, f32);
extern s32 func_0013D3E0(void);
extern void func_L01_004450F0(void *, s32, s32);
extern s32 func_L01_00447490(void *, s32, s32);
extern f32 func_L01_004474E8(void *, s32);
extern void func_003C4A40(void *, void *);
extern void func_003C4C18(f32 *, f32);
extern void func_L01_0044BB30(void *, void *, s32, f32, f32);
extern s32 func_003A52A0(s32, s32, void *);
extern void func_L01_00451FE0(void *, s32, void *, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32, f32, f32, f32, f32);
extern void func_003C2880(void *);
extern void func_L01_0044ABD0(void *, void *);

void func_L05_0035F360(u8 *p) {
    u8 *q;
    u8 *e;
    Q_0035F360 *qq;
    s32 k;
    s32 m;
    s32 h;
    s32 flag;
    s32 idx;
    s32 o;
    s32 r;
    f32 f0;
    f32 f21;
    u128_t loc;

    q = *(u8 **)(p + 0x68);
    qq = (Q_0035F360 *)q;
    if (p[0x20] == 0) {
        k = *(s32 *)(q + 0x84);
        if (k != -1) {
            e = D_001DFB9C_sda + (k << 8);
            if (e == 0 || e[0x20] == 0xFE || e[0x20] == 0xFD || *(u16 *)(e + 0x7C) == 0 || *(s16 *)(q + 0x8E) == 0) {
                *(s32 *)(q + 0x84) = -1;
            }
        }
        *(u16 *)(p + 0x7C) = *(u16 *)(p + 0x7C) | 1;
    }

    m = *(s32 *)(q + 0x80);
    if (m == -1 || (e = D_001DFB9C_sda + (m << 8), e[0x20] == 0xFE) || e[0x20] == 0xFD) {
        *(s32 *)(q + 0x80) = -1;
        if (p[0x20] == 0 || func_0038CB00(q + 0x8C) != 0) {
            idx = func_00382498(0, 3);
            o = idx << 2;
            f0 = qq->ang[idx] * 0.017453292f * 0.020000001f;
            *(f32 *)(q + 0x88) = f0;
            if (func_0013D3E0() & 1) {
                *(f32 *)(q + 0x88) = -*(f32 *)(q + 0x88);
            }
            r = func_00382498(qq->lo[idx], qq->hi[idx]);
            *(s16 *)(q + 0x8C) = (r * 5 + 2) / 6;
            func_L01_004450F0(p, 1, -1);
        }
        *(f32 *)(p + 0xF0) = func_0038DAB8(*(f32 *)(p + 0xF0), *(f32 *)(q + 0x88));
    } else {
        *(f32 *)(p + 0xF0) = *(f32 *)(e + 0xF0);
    }

    func_L01_004450F0(p, 1, -1);
    flag = 0;
    h = func_L01_00447490(p, -1, 0);
    f21 = func_L01_004474E8(p, h);
    if (h != 0 && f21 != 0.0f) {
        *(f32 *)(p + 0xF4) = func_003824E0(-0.05235988f, 0.05235988f);
        func_003C4A40(p, q + 0x70);
        f0 = *(f32 *)(q + 0x30) - f21;
        *(f32 *)(q + 0x30) = f0;
        if (f0 <= 0.0f) {
            *(f32 *)(q + 0x30) = 0.0f;
            flag = 1;
        }
    }

    k = *(s32 *)(q + 0x84);
    if (k != -1) {
        e = D_001DFB9C_sda + (k << 8);
        if (e == 0 || e[0x20] == 0xFE || e[0x20] == 0xFD || (*(u16 *)(e + 0x7C) & *(s16 *)(q + 0x8E)) == 0) {
            flag = 1;
            *(s32 *)(q + 0x84) = -1;
        }
    }

    if (flag != 0) {
        loc = 0;
        func_003C4C18((f32 *)&loc, 0.040000003f);
        func_L01_0044BB30(p, p + 0x10, -1, 0.5f, 13.0f);
        func_003A52A0(0, 0, p);
        func_L01_00451FE0(p, 1, &loc, 255, 180, 0, 0, 35, 0, 3, 3.0f, 6.0f, 3.0f, 6.0f, -1.0f, -1.0f, 1.0f, 1.0f);
        func_003C2880(p);
    } else {
        func_L01_0044ABD0(p, q + 0x70);
        p[0xA8] = 0xFF;
    }
}
/* localdecomp:end func_L05_0035F360 */

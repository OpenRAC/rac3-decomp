#include "common.h"

/* NTSC-U counterpart of func_L05_0035F360 (src/levels/05_daxx/L05_0035F360.c) */
#include "vu0.h"

/* localdecomp:start func_L05_0035E150 */
typedef struct { u8 pad[0x90]; f32 ang[4]; s32 lo[4]; s32 hi[4]; } Q_0035F360;
extern u8 *D_001DFC1C_sda;
__asm__(".extern D_001DFC1C_sda, 4");
extern s32 func_003883C8(void *);
extern s32 func_0037E208(s32, s32);
extern f32 func_0037E250(f32, f32);
extern f32 func_00389380(f32, f32);
extern s32 func_0013D3E0(void);
extern void func_L01_00441FB8(void *, s32, s32);
extern s32 func_L01_00444358(void *, s32, s32);
extern f32 func_L01_004443B0(void *, s32);
extern void func_003BF4F8(void *, void *);
extern void func_003BF6A8(f32 *, f32);
extern void func_L01_004488B8(void *, void *, s32, f32, f32);
extern s32 func_0039FE80(s32, s32, void *);
extern void func_L01_0044ED60(void *, s32, void *, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32, f32, f32, f32, f32);
extern void func_003BD360(void *);
extern void func_L01_004479A8(void *, void *);

void func_L05_0035E150(u8 *p) {
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
    f32 loc[4];
    f32 *lp;

    q = *(u8 **)(p + 0x68);
    qq = (Q_0035F360 *)q;
    if (p[0x20] == 0) {
        k = *(s32 *)(q + 0x84);
        if (k != -1) {
            e = D_001DFC1C_sda + (k << 8);
            if (e == 0 || e[0x20] == 0xFE || e[0x20] == 0xFD || *(u16 *)(e + 0x7C) == 0 || *(s16 *)(q + 0x8E) == 0) {
                *(s32 *)(q + 0x84) = -1;
            }
        }
        *(u16 *)(p + 0x7C) = *(u16 *)(p + 0x7C) | 1;
    }

    m = *(s32 *)(q + 0x80);
    if (m == -1 || (e = (u8 *)((m << 8) + (s32)D_001DFC1C_sda), e[0x20] == 0xFE) || e[0x20] == 0xFD) {
        *(s32 *)(q + 0x80) = -1;
        if (p[0x20] == 0 || func_003883C8(q + 0x8C) != 0) {
            idx = func_0037E208(0, 3);
            o = idx << 2;
            f0 = qq->ang[idx] * 0.017453292f * 0.016666668f;
            *(f32 *)(q + 0x88) = f0;
            if (func_0013D3E0() & 1) {
                *(f32 *)(q + 0x88) = -*(f32 *)(q + 0x88);
            }
            r = func_0037E208(qq->lo[idx], qq->hi[idx]);
            *(s16 *)(q + 0x8C) = r;
            func_L01_00441FB8(p, 1, -1);
        }
        *(f32 *)(p + 0xF0) = func_00389380(*(f32 *)(p + 0xF0), *(f32 *)(q + 0x88));
    } else {
        *(f32 *)(p + 0xF0) = *(f32 *)(e + 0xF0);
    }

    func_L01_00441FB8(p, 1, -1);
    flag = 0;
    h = func_L01_00444358(p, -1, 0);
    f21 = func_L01_004443B0(p, h);
    if (h != 0 && f21 != 0.0f) {
        *(f32 *)(p + 0xF4) = func_0037E250(-0.05235988f, 0.05235988f);
        func_003BF4F8(p, q + 0x70);
        f0 = *(f32 *)(q + 0x30) - f21;
        *(f32 *)(q + 0x30) = f0;
        if (f0 <= 0.0f) {
            *(f32 *)(q + 0x30) = 0.0f;
            flag = 1;
        }
    }

    k = *(s32 *)(q + 0x84);
    if (k != -1) {
        e = D_001DFC1C_sda + (k << 8);
        if (e == 0 || e[0x20] == 0xFE || e[0x20] == 0xFD || (*(u16 *)(e + 0x7C) & *(s16 *)(q + 0x8E)) == 0) {
            flag = 1;
            *(s32 *)(q + 0x84) = -1;
        }
    }

    if (flag != 0) {
        lp = loc;
        qzero(lp);
        func_003BF6A8(lp, 0.033333335f);
        func_L01_004488B8(p, p + 0x10, -1, 0.5f, 13.0f);
        func_0039FE80(0, 0, p);
        func_L01_0044ED60(p, 1, lp, 255, 180, 0, 0, 35, 0, 3, 3.0f, 6.0f, 3.0f, 6.0f, -1.0f, -1.0f, 1.0f, 1.0f);
        func_003BD360(p);
    } else {
        func_L01_004479A8(p, q + 0x70);
        p[0xA8] = 0xFF;
    }
}
/* localdecomp:end func_L05_0035E150 */

#include "common.h"

/* NTSC-U counterpart of func_L09_003BBF10 (src/levels/09_tyhrranosis/L09_003B8580.c) */
#include "vu0.h"
#include "vu0.h"
extern u8 *D_L09_001E011C;
extern u8 D_L09_001E2C00[];
extern u16 *D_L09_0021CE20[];
extern s32 func_0037E1D8(s32);
extern s32 func_003883C8(void *);
extern s32 func_0039FE80(s32, s32, void *);
extern void func_L02_0039E538(u8 *a0, s32 a1);
extern s32 func_L09_003BA698(u8 *);
extern u8 *D_L09_001E011C;

/* localdecomp:start func_L09_003BA698 */
extern u8 *D_L09_001E011C;
__asm__(".extern D_L09_001E011C, 16");
extern u8 D_L09_001E2C00[];
__asm__(".extern D_L09_001E2C00, 16");
extern u16 *D_L09_0021CE20[];
extern s32 D_L09_001E0158;
extern s32 func_L09_003BA2E0(u8 *);
extern void func_L01_003E6D50(s32, s32, f32, f32);
extern void func_L01_003E6EC8(s32, f32);
extern void func_L02_003F84F0(s32, s32, f32);
extern s32 func_L01_00444358(void *, s32, s32);
extern s32 func_0037E1D8(s32);
extern s32 func_0039FE80(s32, s32, void *);
extern s32 func_L01_0044FCD0(void *, void *, s32, s32, s32);
extern void func_L09_003BDA78(u8 *);
extern s32 func_003883C8(void *);
extern void func_L02_0039E538(u8 *a0, s32 a1);
extern f32 func_L01_0040C018(void *, void *);
extern void func_L01_00444188(void *);
extern void func_L01_0044B5C8(void *, void *, s32, f32, f32);

s32 func_L09_003BA698(u8 *a0) {
    u8 *p;
    u8 *e;
    u16 *q;
    u8 *t;
    u8 saved;
    if (func_L09_003BA2E0(a0) != 0) {
        return 1;
    }
    p = *(u8 **)(a0 + 0x68);
    e = D_L09_001E011C + (*(s32 *)(p + 0xCD0) << 8);
    {
        u8 *g = D_L09_001E2C00;
        if (*(s32 *)(g + 0x144) != 0) {
            func_L01_003E6D50(0, 0, 7.7f, 0.003f);
            func_L01_003E6EC8(0, 0.0755727515f);
        }
    }
    if ((a0[0x34] ^ 1) & 1) {
        func_L02_003F84F0(9, 0, *(f32 *)(p + 0x30) / (f32)*(s16 *)(p + 0x34));
        if ((a0[0x34] ^ 1) & 1) {
            u8 *m;
            saved = a0[0x94];
            m = (u8 *)func_L01_00444358(a0, -1, 0);
            if (m != 0) {
                f32 v = *(f32 *)(p + 0x30);
                f32 d = v - *(f32 *)(m + 0x2C);
                f32 lim = (f32)*(s16 *)(p + 0x34) * *(f32 *)(p + 0xD4C);
                if (d < lim) {
                    *(f32 *)(m + 0x2C) = v - lim + 1.0f;
                }
                if (func_0037E1D8(5) == 0) {
                    func_0039FE80(7, 0, a0);
                }
            }
            func_L01_0044FCD0(a0, p + 0xD0, 0, 0, 0);
            if ((u8)(a0[0x94] - 0x16) < 2) {
                a0[0x94] = saved;
            }
        }
    }
    if (e != 0) {
        if (p[0xD2C] != 0) {
            func_L09_003BDA78(a0);
        }
        *(long *)(e + 0x38) = *(long *)(a0 + 0x38);
    }
    if (*(f32 *)(p + 0x30) > 0.0f) {
        if (func_003883C8(p + 0xD32) != 0 || *(f32 *)(p + 0x30) / 250.0f < (f32)p[0xD43]) {
            for (q = D_L09_0021CE20[*(s32 *)(p + 0xD28)];
                 (*(s32 *)(p + 0xD28) & 0xFF) != 0xFF && *(s32 *)(p + 0xD28) <= D_L09_001E0158 && q != 0 &&
                 ((s16)q[-1] >= 0 || q == D_L09_0021CE20[*(s32 *)(p + 0xD28)]);
                 q++) {
                t = D_L09_001E011C + ((*q & 0x7FFF) << 8);
                if (t == 0) {
                    break;
                }
                func_L02_0039E538(t, 0);
            }
            *(s16 *)(p + 0xD32) = 7200;
            if (*(f32 *)(p + 0x30) / 250.0f < (f32)p[0xD43]) {
                p[0xD43]--;
            }
        }
    }
    if (a0[0x31] != 0) {
        if (func_L01_0040C018(D_L09_001E2C00, a0 + 0x10) < 4096.0f) {
            func_L01_00444188(a0);
            a0[0x6F] = 0x3C;
        }
    }
    func_L01_0044B5C8(a0, p + 0xB80, 1, 0.03f, 0.3f);
    return 0;
}
/* localdecomp:end func_L09_003BA698 */

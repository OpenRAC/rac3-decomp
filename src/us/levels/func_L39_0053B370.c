#include "common.h"

/* NTSC-U counterpart of func_L39_0053BB08 (src/levels/shared/L39_0053BA68.c): 0.020944 -> 0.0174533; 0.0628319 -> 0.0523599 */
typedef int u128_t __attribute__((mode(TI)));
extern u8 *func_003BCFB0(s32, s32);
extern void func_003C26C8(u8 *);
extern f32 func_L39_005B2510(f32, f32);
extern s32 D_L39_002412AC;

/* localdecomp:start func_L39_0053B370 */
#include "vu0.h"


extern u8 *func_003BCFB0(s32, s32);
extern void func_003C26C8(u8 *);
extern f32 func_L39_005B2510(f32, f32);
extern s32 D_L39_002412AC;
extern s16 D_L39_00294038[][64];
extern u8 *D_L39_0024C05C;
extern s32 D_L39_0024AEC0_0053B370[] __attribute__((section(".sdata")));
extern s32 D_001D5BCC_sda_0053B370;
extern s32 D_L39_0024AEB8_0053B370;
__asm__(".extern D_001D5BCC_sda_0053B370, 4");
__asm__(".extern D_L39_0024AEB8_0053B370, 4");
extern f32 func_L01_0040C018(void *, void *);
extern s32 func_L39_005B2498(s32);

/* from func_L39_00537998 (same spawn sequence) */
u8 *func_L39_0053B370(s32 a0, u8 *a1, u128_t *a2) {
    u8 *p;
    u8 *q;
    u8 *best;
    s32 count;
    s32 n;
    s32 row;
    s32 i;
    u8 *m;
    s32 idx;

    p = func_003BCFB0(0x1099, 0x80);
    if (p != 0) {
        q = *(u8 **)(p + 0x68);
        if (D_001D5BCC_sda_0053B370 == 0x30) {
            D_L39_0024AEB8_0053B370 = 0x20;
        }
        p[0x30] = 0xFF;
        *(s16 *)(p + 0x32) = 0x40;
        *(f32 *)(p + 0x2C) *= 0.5f;
        p[0x31] = 1;
        *(s32 *)(p + 0xB8) = a0;
        p[0x20] = 0;
        *(s16 *)(q + 0x36) = 0;
        qzero(q);
        *(s32 *)(q + 0x74) = 0;
        q[0x51] = 0;
        *(u16 *)(q + 0x7C) = *(u16 *)(a1 + 0x2544);
        *(s32 *)(p + 0x90) = *(s32 *)a1;
        idx = *(s32 *)(a1 + 0x2548);
        *(u16 *)(p + 0x34) |= 0x10;
        *(s32 *)(p + 0x78) = D_L39_0024AEC0_0053B370[idx];
        *(u128_t *)(p + 0x10) = *a2;
        *(f32 *)(q + 0x38) = func_L39_005B2510(0.0174532942f, 0.0523598827f);
        {
            s32 d;
            f32 t = func_L39_005B2510(0.0174532942f, 0.0523598827f);
            f32 z = 0.0f;
            d = D_L39_002412AC;
            *(f32 *)(q + 0x64) = z;
            *(f32 *)(q + 0x3C) = t;
            *(f32 *)(q + 0x60) = z;
            *(f32 *)(q + 0x70) = z;
            *(f32 *)(q + 0x6C) = z;
            *(s32 *)(q + 0x5C) = d;
            *(s32 *)(q + 0x68) = -1;
        }
        *(s32 *)(p + 0x98) = 0;
        if (a1 != 0) {
            if ((*(unsigned long *)(a1 + 0x1A08) & 0xFFFF0000) != 0 || *(s32 *)(a1 + 0x1310) == 2 || *(s16 *)(a1 + 0x2488) != 0) {
                *(u16 *)(p + 0x34) |= 0x41;
            }
        }
        if (a1[0x1A14] != 0) {
            best = 0;
            count = 0;
            n = func_L39_005B2498(10);
            for (row = 0; row < 8; row++) {
                for (i = 1; i <= D_L39_00294038[row][0]; i++) {
                    m = D_L39_0024C05C + D_L39_00294038[row][i] * 256;
                    if (m != 0 && m[0x20] != 0xFE && m[0x20] != 0xFD && m[0xBC] == 0
                        && *(s32 *)(*(u8 **)(m + 0x68) + 0x5C) != -1 && m != p
                        && (*(unsigned long *)(m + 0x20) & 0x16) == 6) {
                        if (func_L01_0040C018(m + 0x10, p + 0x10) < 900.0f) {
                            if (count == n) {
                                best = m;
                            }
                            count++;
                        }
                    }
                }
            }
            if (count > 10 && best != 0) {
                *(s32 *)(*(u8 **)(best + 0x68) + 0x5C) = -2;
                best[0x30] = 0xFF;
            }
        }
        func_003C26C8(p);
    }
    return p;
}
/* localdecomp:end func_L39_0053B370 */

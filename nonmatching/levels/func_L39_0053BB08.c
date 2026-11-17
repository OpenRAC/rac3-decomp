/* NTSC-U draft (Claude wave K): C of func_L39_0053B370, the NTSC-U twin of func_L39_0053BB08, with NTSC-U names and addresses (the two versions' code differs).
 * near miss on NTSC-U, no count recorded (NTSC-U twin "func_L39_0053B370", whose code is not the PAL one).
 * Worker's note: first full draft (was skip: no template): 12 aligned / 18 positional diffs of ~210 words with the entry's own flags (-O2 -G8 -fopt-stack -mno-check-zero-division @ps2as; qzero() from vu0.h is a plain asm, no vu0 flag needed). Decode: actor spawn: o = ...
 */
#include "common.h"
#include "vu0.h"

/* NTSC-U counterpart of func_L39_00537998 (src/levels/shared/L39_00537998.c) */
/* localdecomp:start func_L39_0053B370 */
typedef int u128_t __attribute__((mode(TI)));
extern s32 D_001D5BCC_sda_0053B370;
__asm__(".extern D_001D5BCC_sda_0053B370, 4");
extern s32 D_001DF628_sda_0053B370;
__asm__(".extern D_001DF628_sda_0053B370, 4");
extern s32 D_L39_0024AEC0[];
extern s32 D_L39_002412AC[];
extern u8 *D_L39_0024C05C;
extern u8 D_L39_00294038[];
extern u8 *func_003BCFB0(s32, s32);
extern f32 func_L39_005B2510(f32, f32);
extern s32 func_L39_005B2498(s32);
extern f32 func_L01_0040C018(void *, void *);
extern void func_003C26C8(void *);

u8 *func_L39_0053B370(void *a0, u8 *a1, u8 *a2) {
    u8 *o;
    u8 *st;
    u8 *other;
    u8 *best;
    s16 *row;
    s32 i, j, n, k;
    f32 z;

    o = func_003BCFB0(0x1099, 0x80);
    if (o != 0) {
        st = *(u8 **)(o + 0x68);
        if (D_001D5BCC_sda_0053B370 == 0x30) {
            D_001DF628_sda_0053B370 = 0x20;
        }
        *(f32 *)(o + 0x2C) = *(f32 *)(o + 0x2C) * 0.5f;
        o[0x30] = 0xFF;
        *(s16 *)(o + 0x32) = 0x40;
        o[0x31] = 1;
        *(void **)(o + 0xB8) = a0;
        o[0x20] = 0;
        *(s16 *)(st + 0x36) = 0;
        qzero(st);
        *(s32 *)(st + 0x74) = 0;
        st[0x51] = 0;
        *(u16 *)(st + 0x7C) = *(u16 *)(a1 + 0x2544);
        *(s32 *)(o + 0x90) = *(s32 *)a1;
        *(u16 *)(o + 0x34) |= 0x10;
        *(s32 *)(o + 0x78) = D_L39_0024AEC0[*(s32 *)(a1 + 0x2548)];
        *(u128_t *)(o + 0x10) = *(u128_t *)a2;
        *(f32 *)(st + 0x38) = func_L39_005B2510(0.01745329424738884f, 0.05235988274216652f);
        *(f32 *)(st + 0x3C) = func_L39_005B2510(0.01745329424738884f, 0.05235988274216652f);
        z = 0.0f;
        *(s32 *)(st + 0x68) = -1;
        *(f32 *)(st + 0x6C) = z;
        *(s32 *)(st + 0x5C) = D_L39_002412AC[0];
        *(f32 *)(st + 0x64) = z;
        *(f32 *)(st + 0x60) = z;
        *(f32 *)(st + 0x70) = z;
        *(s32 *)(o + 0x98) = 0;
        if (a1 != 0) {
            if ((*(unsigned long *)(a1 + 0x1A08) & 0xFFFF0000) != 0 || *(s32 *)(a1 + 0x1310) == 2 || *(s16 *)(a1 + 0x2488) != 0) {
                *(u16 *)(o + 0x34) |= 0x41;
            }
        }
        if (a1[0x1A14] != 0) {
            best = 0;
            n = 0;
            k = func_L39_005B2498(10);
            for (i = 0; i < 8; i++) {
                for (j = 1; j <= *(s16 *)(D_L39_00294038 + (i << 7)); j++) {
                    other = D_L39_0024C05C + (*(s16 *)(D_L39_00294038 + (i << 7) + (j << 1)) << 8);
                    if (other == 0) continue;
                    if (other[0x20] == 0xFE) continue;
                    if (other[0x20] == 0xFD) continue;
                    if (other[0xBC] != 0) continue;
                    if (*(s32 *)(*(u8 **)(other + 0x68) + 0x5C) == -1) continue;
                    if (other == o) continue;
                    if ((*(unsigned long *)(other + 0x20) & 0x16) != 6) continue;
                    if (func_L01_0040C018(other + 0x10, o + 0x10) < 900.0f) {
                        if (n == k) best = other;
                        n++;
                    }
                }
            }
            if (n >= 0xB && best != 0) {
                *(s32 *)(*(u8 **)(best + 0x68) + 0x5C) = -2;
                best[0x30] = 0xFF;
            }
        }
        func_003C26C8(o);
    }
    return o;
}
/* localdecomp:end func_L39_0053B370 */

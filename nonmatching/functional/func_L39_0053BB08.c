/* functional: high. Same behaviour as retail; compiler scheduling and register allocation differ. */
#include "vu0.h"

extern s32 D_001D5BCC_sda;
__asm__(".extern D_001D5BCC_sda, 4");
extern s32 D_001DF698_sda;
__asm__(".extern D_001DF698_sda, 4");
extern s32 D_L39_0024ADB0[];
extern u8 *D_L39_0024BF5C;
extern u8 D_L39_00293F38[];
extern f32 func_L01_0040E548(void *, void *);
extern s32 func_L39_005B4398(s32);

u8 *func_L39_0053BB08(void *a0, u8 *a1, u8 *a2) {
    u8 *o;
    u8 *st;
    u8 *other;
    u8 *best;
    s32 i, j, n, k;

    o = func_003C24B0(0x1099, 0x80);
    if (o != 0) {
        st = *(u8 **)(o + 0x68);
        if (D_001D5BCC_sda == 0x30) {
            D_001DF698_sda = 0x20;
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
        *(s32 *)(o + 0x78) = D_L39_0024ADB0[*(s32 *)(a1 + 0x2548)];
        *(u128_t *)(o + 0x10) = *(u128_t *)a2;
        *(f32 *)(st + 0x38) = func_L39_005B4410(0.0209439527f, 0.0628318563f);
        *(f32 *)(st + 0x3C) = func_L39_005B4410(0.0209439527f, 0.0628318563f);
        *(s32 *)(st + 0x68) = -1;
        *(f32 *)(st + 0x6C) = 0.0f;
        *(s32 *)(st + 0x5C) = D_L39_0024112C;
        *(f32 *)(st + 0x64) = 0.0f;
        *(f32 *)(st + 0x60) = 0.0f;
        *(f32 *)(st + 0x70) = 0.0f;
        *(s32 *)(o + 0x98) = 0;
        if (a1 != 0) {
            if ((*(unsigned long *)(a1 + 0x1A08) & 0xFFFF0000) != 0 || *(s32 *)(a1 + 0x1310) == 2 || *(s16 *)(a1 + 0x2488) != 0) {
                *(u16 *)(o + 0x34) |= 0x41;
            }
        }
        if (a1[0x1A14] != 0) {
            best = 0;
            n = 0;
            k = func_L39_005B4398(10);
            for (i = 0; i < 8; i++) {
                for (j = 1; j <= *(s16 *)(D_L39_00293F38 + (i << 7)); j++) {
                    other = D_L39_0024BF5C + (*(s16 *)(D_L39_00293F38 + (i << 7) + (j << 1)) << 8);
                    if (other == 0) continue;
                    if (other[0x20] == 0xFE) continue;
                    if (other[0x20] == 0xFD) continue;
                    if (other[0xBC] != 0) continue;
                    if (*(s32 *)(*(u8 **)(other + 0x68) + 0x5C) == -1) continue;
                    if (other == o) continue;
                    if ((*(unsigned long *)(other + 0x20) & 0x16) != 6) continue;
                    if (func_L01_0040E548(other + 0x10, o + 0x10) < 900.0f) {
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
        func_003C7C38(o);
    }
    return o;
}

/* functional: medium. Ported from the NTSC-U draft and checked against the PAL asm: callee names via map.tsv, PAL data (D_L40_0024112C, ...00249848/4C, ...00248380) and PAL constants (frame gap 0xC9 not 0xF1, final obj[0xBC]=0xC not 0xF). Immediates and call list equal; 235 words differ (float-constant addressing, register allocation). */
#include "vu0.h"

/* localdecomp:start func_L40_00424540 */
typedef int u128_t __attribute__((mode(TI)));

extern s32 func_L39_005F33E0(s32, s32, void *);
extern void func_L39_005F3718(s32, void *);
extern void func_L01_004653B8(void *, s32, s32, f32, f32, f32, f32, f32);
extern void func_L01_00448248(void *, s32, s32);
extern void func_L01_00451FE0(void *, s32, void *, f32, f32, f32, f32, s32, f32, f32, s32, s32, s32, s32, f32, f32, s32, s32);
extern void func_L01_004450F0(void *, s32, s32);
extern s32 D_L40_0024112C;
extern s32 D_L40_00249848;
extern s32 D_L40_0024984C;
extern s32 D_L40_00248380;
extern s32 D_L40_00247710;
__asm__(".extern D_L40_00247710, 4");
extern s32 D_L40_00247714;
__asm__(".extern D_L40_00247714, 4");

void func_L40_00424540(u8 *obj, s32 unused, u8 *src) {
    f32 pos[4] __attribute__((aligned(16)));
    f32 dir[4] __attribute__((aligned(16)));
    f32 zero[4] __attribute__((aligned(16)));
    s32 i;
    s32 n;
    s32 c;
    s32 mask;
    s32 d;
    s32 r;

    if (abs_asm(D_L40_0024112C - D_L40_00249848) >= 2) {
        r = func_L39_005F33E0(0, 0, obj);
        *(u128_t *)dir = 0;
        dir[2] = 0.5f;
        func_L39_005F3718(r, dir);
        D_L40_00249848 = D_L40_0024112C;
    }
    if (abs_asm(D_L40_0024112C - D_L40_0024984C) >= 2) {
        D_L40_0024984C = D_L40_0024112C;
    }
    *(u128_t *)pos = *(u128_t *)(obj + 0x10);
    pos[2] = pos[2] + 0.3f;
    func_L01_004653B8(pos, 1, 0x40808080, 0.3f, 1.01f, 1.075f, 0.05f, 50000.0f);
    for (i = 0; i < 5; i++) {
        func_L01_004653B8(pos, 1, 0x40808080, 0.3f, 1.01f, 1.07f, 0.05f, 50000.0f);
    }
    if (src != 0) {
        *(u128_t *)dir = *(u128_t *)(src + 0x10);
    } else {
        qzero(dir);
        dir[2] = 1.0f;
    }
    d = abs_asm(D_L40_0024112C - D_L40_00247710);
    if (d >= 0xC9) {
        D_L40_00247710 = D_L40_0024112C;
        D_L40_00247714 = 0;
    } else if (D_L40_0024112C != D_L40_00247710) {
        func_L01_00448248(&D_L40_00247714, 0, d >> 2);
        D_L40_00247710 = D_L40_0024112C;
    }
    n = D_L40_00248380;
    if (n >= 0xFB && D_L40_00247714 < 5) {
        c = 4;
    } else if (n >= 0xC9 && D_L40_00247714 < 10) {
        c = 3;
    } else if (n >= 0x97 && D_L40_00247714 < 15) {
        c = 2;
    } else if (n < 0x65) {
        c = 0;
    } else {
        c = D_L40_00247714 < 20;
    }
    if (c != 0) {
        mask = 0;
        D_L40_00247714 = D_L40_00247714 + c;
        switch (*(s16 *)(obj + 0xAA)) {
        case 0x1F5:
        case 0x200:
            mask = (1 << (c - 1)) - 1;
            if (!(mask < 0x10)) {
                mask = 0xF;
            }
            break;
        case 0x1FF:
        case 0x1ABA:
        case 0x1ABB:
        case 0x1ABC:
        case 0x1ABD:
        case 0x1ABE:
        case 0x1ABF:
        case 0x1AC0:
        case 0x1AC1:
        case 0x1AF2:
        case 0x1B09:
        case 0x1B0A:
        case 0x1B0B:
        case 0x1B4B:
            if (c == 2) {
                mask = 5;
            } else if (c < 3) {
                if (c == 1) {
                    mask = 1;
                } else {
                    mask = 0x25;
                }
            } else {
                mask = 0x25;
            }
            break;
        }
        if (mask != 0) {
            *(u128_t *)zero = 0;
            func_L01_00451FE0(obj, mask, zero, 3.0f, 6.0f, 3.0f, 6.0f, 0xFF, -1.0f, -1.0f, 0xB4, 0, 0, 0x23, 1.0f, 1.0f, 0, 3);
        }
    }
    *(u16 *)(obj + 0x34) = *(u16 *)(obj + 0x34) | 1;
    func_L01_004450F0(obj, 3, -1);
    *(s32 *)(obj + 0x98) = 0;
    obj[0xBC] = 0xC;
}
/* localdecomp:end func_L40_00424540 */

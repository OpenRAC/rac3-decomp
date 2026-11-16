/* NTSC-U draft (Claude wave C4): C of func_L40_00423C70, the NTSC-U twin of func_L40_00424540, with NTSC-U names and addresses (the two versions' code differs).
 * near miss: 131 words differ on NTSC-U with "-O2 -G8 -fopt-stack -mno-check-zero-division @ps2as" (the file's line: "-O2 -G8 -fopt-stack -mno-check-zero-division") (NTSC-U twin "func_L40_00423C70", whose code is not the PAL one).
 * Worker's note: first draft, not converged: 247 words against retail's 246; the c ladder (n >= 0xFB && m < 5 ...) is compiled into a2 with delay-slot constants in retail, and the call order of func_L39_005F0CE0 / the zero vector differs; needs an extra @ps2as (lui/ori/mtc1 ...
 */
#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L40_00423C70 */
typedef int u128_t __attribute__((mode(TI)));

extern s32 func_L39_005F0CE0(s32, s32, void *);
extern void func_L39_005F1018(s32, void *);
extern void func_L01_00461E08(void *, s32, s32, f32, f32, f32, f32, f32);
extern void func_L01_00445110(void *, s32, s32);
extern void func_L01_0044ED60(void *, s32, void *, f32, f32, f32, f32, s32, f32, f32, s32, s32, s32, s32, f32, f32, s32, s32);
extern void func_L01_00441FB8(void *, s32, s32);
extern s32 D_L40_002412AC;
extern s32 D_L40_002499C8;
extern s32 D_L40_002499CC;
extern s32 D_L40_00248500;
extern s32 D_001DC000_sda;
__asm__(".extern D_001DC000_sda, 4");
extern s32 D_001DC004_sda;
__asm__(".extern D_001DC004_sda, 4");

void func_L40_00423C70(u8 *obj, s32 unused, u8 *src) {
    f32 pos[4] __attribute__((aligned(16)));
    f32 dir[4] __attribute__((aligned(16)));
    f32 zero[4] __attribute__((aligned(16)));
    s32 i;
    s32 n;
    s32 c;
    s32 mask;
    s32 d;
    s32 r;

    if (abs_asm(D_L40_002412AC - D_L40_002499C8) >= 2) {
        r = func_L39_005F0CE0(0, 0, obj);
        *(u128_t *)dir = 0;
        dir[2] = 0.5f;
        func_L39_005F1018(r, dir);
        D_L40_002499C8 = D_L40_002412AC;
    }
    if (abs_asm(D_L40_002412AC - D_L40_002499CC) >= 2) {
        D_L40_002499CC = D_L40_002412AC;
    }
    *(u128_t *)pos = *(u128_t *)(obj + 0x10);
    pos[2] = pos[2] + 0.3f;
    func_L01_00461E08(pos, 1, 0x40808080, 0.3f, 1.01f, 1.075f, 0.05f, 50000.0f);
    for (i = 0; i < 5; i++) {
        func_L01_00461E08(pos, 1, 0x40808080, 0.3f, 1.01f, 1.07f, 0.05f, 50000.0f);
    }
    if (src != 0) {
        *(u128_t *)dir = *(u128_t *)(src + 0x10);
    } else {
        qzero(dir);
        dir[2] = 1.0f;
    }
    d = abs_asm(D_L40_002412AC - D_001DC000_sda);
    if (d >= 0xF1) {
        D_001DC000_sda = D_L40_002412AC;
        D_001DC004_sda = 0;
    } else if (D_L40_002412AC != D_001DC000_sda) {
        func_L01_00445110(&D_001DC004_sda, 0, d >> 2);
        D_001DC000_sda = D_L40_002412AC;
    }
    n = D_L40_00248500;
    if (n >= 0xFB && D_001DC004_sda < 5) {
        c = 4;
    } else if (n >= 0xC9 && D_001DC004_sda < 10) {
        c = 3;
    } else if (n >= 0x97 && D_001DC004_sda < 15) {
        c = 2;
    } else if (n < 0x65) {
        c = 0;
    } else {
        c = D_001DC004_sda < 20;
    }
    if (c != 0) {
        mask = 0;
        D_001DC004_sda = D_001DC004_sda + c;
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
            func_L01_0044ED60(obj, mask, zero, 3.0f, 6.0f, 3.0f, 6.0f, 0xFF, -1.0f, -1.0f, 0xB4, 0, 0, 0x23, 1.0f, 1.0f, 0, 3);
        }
    }
    *(u16 *)(obj + 0x34) = *(u16 *)(obj + 0x34) | 1;
    func_L01_00441FB8(obj, 3, -1);
    *(s32 *)(obj + 0x98) = 0;
    obj[0xBC] = 0xF;
}
/* localdecomp:end func_L40_00423C70 */

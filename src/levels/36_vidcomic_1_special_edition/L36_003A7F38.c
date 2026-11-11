#include "common.h"

INCLUDE_ASM("asm/levels", func_L36_003A7F38);

/* localdecomp:start func_L36_003A85A8 */
#include "vu0.h"
typedef int u128_t __attribute__((mode(TI)));
extern u8 D_001A4BE0[];
extern u8 *D_L36_001DFC00;
extern void func_0038CF68(void *, void *, f32);
extern void func_L32_00347FE8(u8 *, void *, f32, f32, s32, s32, s32, s32, s32);
extern s32 func_00382380(u8 *, s32, s32);
__asm__(".extern D_L36_001DEA98, 4");
extern f32 D_L36_001DEA98;
void func_L36_003A85A8(u8 *a0) {
    u8 *g = D_001A4BE0;
    u8 *s;
    u8 st;
    vu0_v4 v;
    *(f32 *)(a0 + 0x14) = *(f32 *)(g + 0x84);
    s = *(u8 **)(a0 + 0x68);
    *(f32 *)(a0 + 0xF4) = *(f32 *)(s + 0x70);
    *(f32 *)(a0 + 0xF0) = *(f32 *)(s + 0x74);
    *(u16 *)(a0 + 0x96) += 1;
    st = *(u8 *)(a0 + 0x20);
    if (st != 0x42 && st != 4 && st != 0 && st != 5) {
        vec_sub_ba(&v, g + 0x80, a0 + 0x10);
        func_0038CF68(&v, &v, 1.0f);
        func_L32_00347FE8(a0, &v, (f32)*(u8 *)(s + 0x14), D_L36_001DEA98, 0, 1, 0, 0, 0);
    }
    if (func_00382380(a0 + 0x10, *(s32 *)(s + 0x8C), 0) == 0) {
        *(u128_t *)(a0 + 0x10) = *(u128_t *)(D_L36_001DFC00 + *(s32 *)(s + 0x8C) * 0x80 + 0x30);
    }
}
/* localdecomp:end func_L36_003A85A8 */

/* localdecomp:start func_L36_003A86B8 */
extern s32 D_L36_001DEAD4;
extern s32 func_L01_00456250(u8 *);
extern void func_L01_004450F0(u8 *, s32, s32);
extern void func_L36_003A87C0(u8 *);
extern s32 func_0038CAD0(u8 *);
void func_L36_003A86B8(u8 *a0) {
    u8 *s = *(u8 **)(a0 + 0x68);
    switch (*(u8 *)(a0 + 0x20)) {
    case 0:
        *(s32 *)(s + 0x10) = D_L36_001DEAD4;
        *(s32 *)(s + 0xC) = 0;
        *(u8 *)(a0 + 0x31) = 0;
        *(u16 *)(a0 + 0x34) |= 1;
        func_L01_004450F0(a0, 1, -1);
        break;
    case 1:
        if (func_L01_00456250(a0) != 0) {
            *(s32 *)(a0 + 0x98) = 0;
            func_L01_004450F0(a0, 2, -1);
        }
        func_L36_003A87C0(a0);
        break;
    case 2:
        if (func_L01_00456250(a0) == 0) {
            *(s32 *)(a0 + 0x98) = *(s32 *)(*(u8 **)(a0 + 0x24) + 0x10);
            func_L01_004450F0(a0, 1, -1);
        }
        if (func_0038CAD0(s + 0x10) == 0) {
            func_L36_003A87C0(a0);
        }
        break;
    }
}
/* localdecomp:end func_L36_003A86B8 */

INCLUDE_ASM("asm/levels", func_L36_003A87C0);

INCLUDE_ASM("asm/levels", func_L36_003A8920);

INCLUDE_ASM("asm/levels", func_L36_003A8AB0);

/* localdecomp:start func_L36_003A8CF8 */
/* Ps2EeAs only uses $gp for this if it knows the size before the use. */
__asm__(".extern D_L36_001DEAEC, 4");
extern f32 D_L36_001DEAEC;
extern u8 D_001A4C60[];
extern u8 *func_L01_00447490(u8 *, s32, s32);
extern void func_003C4A40(u8 *, u8 *);
extern void func_L01_004450F0(u8 *, s32, s32);
extern f32 func_0038CF00(u8 *, u8 *);
void func_L36_003A8CF8(u8 *a0) {
    u8 *s = *(u8 **)(a0 + 0x68);
    u8 *r = func_L01_00447490(a0, 0x10000, 0);
    f32 f;
    if (r != 0) {
        *(u8 *)(a0 + 0xA8) = 0xFF;
        f = *(f32 *)(r + 0x2C);
        if (0.0f < f) {
            if (*(u8 *)(a0 + 0x20) != 0x42) {
                if (*(s32 *)(s + 0x50) <= 0) {
                    *(s32 *)(s + 0x50) = 0xC;
                    *(u8 *)(s + 0x47) = 0xFF;
                    *(f32 *)s = *(f32 *)s - f;
                    func_003C4A40(a0, s + 0x40);
                    if (*(f32 *)s <= 0.0f) {
                        func_L01_004450F0(a0, 0x42, -1);
                    }
                }
            }
        }
    }
    if (func_0038CF00(D_001A4C60, a0 + 0x10) < D_L36_001DEAEC) {
        if (*(u8 *)(a0 + 0x20) != 0x42) {
            func_L01_004450F0(a0, 0x42, -1);
        }
    }
}
/* localdecomp:end func_L36_003A8CF8 */

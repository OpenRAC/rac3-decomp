#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L24_003B6050 */
extern s32 D_001D545C;
extern s32 D_L24_001DD570;
__asm__(".extern D_L24_001DD570, 16");
extern s32 func_L24_003B6320(u8 *);
extern void func_003C2880(void *);
extern void func_L24_00355C18(u8 *, s32, s32, void *, s32, f32);
extern s32 func_L01_00447490(void *, s32, s32);
extern void func_L01_004450F0(void *, s32, s32);
extern void func_003C3A10(void *, s32, s32, s32);
extern void func_003C2F58(void *, s32, void *);
extern s32 func_L01_003303B8(u8 *, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32,
    s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern void func_L01_004AA7E8(void *, s32);

void func_L24_003B6050(u8 *a0) {
    u8 *p = *(u8 **)(a0 + 0x68);
    s32 t;
    if (func_L24_003B6320(a0) != 0) {
        func_003C2880(a0);
        return;
    }
    t = D_001D545C;
    if (t != 0x539 && t != 0x18 && t != 3) {
        return;
    }
    if (*(s32 *)(p + 0x938) != 0) {
        return;
    }
    if (D_L24_001DD570 != 0 && a0[0x20] < 2) {
        return;
    }
    if (a0[0x20] == 1) {
        *(u16 *)(*(u8 **)(p + 0x8DC) + 0x34) &= 0xFFBE;
        *(u16 *)(*(u8 **)(p + 0x8DC) + 0x34) |= *(u16 *)(*(u8 **)(*(u8 **)(p + 0x8DC) + 0x24) + 0x44) & 0x1000;
        *(s32 *)(*(u8 **)(p + 0x8DC) + 0x98) = *(s32 *)(*(u8 **)(*(u8 **)(p + 0x8DC) + 0x24) + 0x10);
        *(u16 *)(a0 + 0x34) &= 0xFFBE;
        *(u16 *)(a0 + 0x34) |= *(u16 *)(*(u8 **)(a0 + 0x24) + 0x44) & 0x1000;
        *(s32 *)(a0 + 0x98) = *(s32 *)(*(u8 **)(a0 + 0x24) + 0x10);
        func_L24_00355C18(a0, 1, 0, p + 0x910, *(s32 *)(p + 0x90C), *(f32 *)(p + 0x930));
        if (func_L01_00447490(a0, -1, 0) != 0) {
            func_L01_004450F0(a0, 2, -1);
            if (a0[0x43] != 4) {
                func_003C3A10(a0, 4, 0, 3);
            }
        }
    } else if (a0[0x20] == 2) {
        if (a0[0x60] & 2) {
            u8 v[16] __attribute__((aligned(16)));
            func_003C2F58(a0, 5, v);
            func_L01_003303B8(v, 0, 0x19, 0x14, 0x14, 0x14, 0x2D, 2, 0.75f, 0.0f, 0.0f, 2.0f,
                0, 1, 0, 0, 1, 0, 0x1010000, 0, 0x388EF7, 0x63F7, 0x407FFF, 0x20FF, 0x8FFF,
                0x3064FF, 0x7F60A0FF, 0x280000FF, 0x3064FF, 0);
            a0[0xA8] = 0xFF;
            *(u16 *)(*(u8 **)(p + 0x8DC) + 0x34) |= 0x41;
            *(u16 *)(*(u8 **)(p + 0x8DC) + 0x34) &= 0xEFFF;
            *(s32 *)(*(u8 **)(p + 0x8DC) + 0x98) = 0;
            func_L01_004AA7E8(*(u8 **)(p + 0x8DC), 1);
            *(u16 *)(a0 + 0x34) = (*(u16 *)(a0 + 0x34) | 0x41) & 0xEFFF;
            *(s32 *)(a0 + 0x98) = 0;
            func_L01_004AA7E8(a0, 1);
            *(u16 *)(a0 + 0x34) |= 2;
            func_L01_004450F0(a0, 3, -1);
        }
    }
}
/* localdecomp:end func_L24_003B6050 */

/* localdecomp:start func_L24_003B6320 */
extern s32 D_001D545C;
extern s32 func_L24_003B64C8(void);
extern void func_L01_0044FD88(void *, s32, s32, s32);
extern void func_L01_00404808(void *, void *);
extern void func_L24_003B66C8(void);
extern void func_L24_003B69F8(void *);
extern f32 func_L01_004395E0(void *);
extern void func_003C4138(void *, f32, f32);

s32 func_L24_003B6320(u8 *a0) {
    u8 *p = *(u8 **)(a0 + 0x68);
    f32 f1;
    if (a0[0x20] == 0 && func_L24_003B64C8() != 0) {
        return 1;
    }
    if (*(s32 *)(p + 0x900) < 6) {
        *(s32 *)(p + 0x900) += 1;
    }
    if (*(s32 *)(p + 0x8DC) != 0) {
        func_L01_0044FD88(a0, *(s32 *)(p + 0x8DC), 0, 0);
        func_L01_00404808(func_L24_003B66C8, a0);
        func_L24_003B69F8(a0);
    }
    f1 = func_L01_004395E0(a0);
    if (a0[0x43] == 0 || (a0[0x42] == 3 && f1 > 17.0f)) {
        func_003C4138(p + 0x8E4, 2.0f, 0.12000000476837158f);
        func_003C4138(p + 0x8E8, 2.0f, 0.12000000476837158f);
    } else if (a0[0x42] == 5 && f1 > 16.0f) {
        func_003C4138(p + 0x8E4, 3.5f, 0.12000000476837158f);
        func_003C4138(p + 0x8E8, 1.5f, 0.12000000476837158f);
    }
    if (D_001D545C == 0x18) {
        *(f32 *)(a0 + 0x18) = 101.86f;
    } else {
        *(f32 *)(a0 + 0x18) = 48.84f;
    }
    return 0;
}
/* localdecomp:end func_L24_003B6320 */

INCLUDE_ASM("asm/levels", func_L24_003B64C8);

INCLUDE_ASM("asm/levels", func_L24_003B66C8);

/* localdecomp:start func_L24_003B69F8 */
__asm__(".extern D_L24_001DE804, 4");
extern s32 D_L24_001DE804;
extern void func_003C2F58(void *, s32, void *);
extern void func_003C2EC0(void *, s32, void *);
extern void func_0038CF68(void *, void *, f32);
extern void func_L01_0044C280(void *, void *, void *, s32, f32);
extern void func_003C3FC0(void *, void *);

void func_L24_003B69F8(void *arg0) {
    u8 *a0 = arg0;
    f32 a[4] __attribute__((aligned(16)));
    f32 d[16] __attribute__((aligned(16)));
    f32 e[4] __attribute__((aligned(16)));
    f32 f[4] __attribute__((aligned(16)));
    f32 g[4] __attribute__((aligned(16)));
    f32 h[4] __attribute__((aligned(16)));
    f32 i[4] __attribute__((aligned(16)));
    f32 j[4] __attribute__((aligned(16)));
    u8 *p = *(u8 **)(a0 + 0x68);
    *(s32 *)(p + 0x8F8) = 0;
    func_003C2F58(*(u8 **)(p + 0x8DC), 3, a);
    func_003C2EC0(*(u8 **)(p + 0x8DC), 3, d);
    func_003C2F58(*(u8 **)(p + 0x8DC), 2, e);
    vec_sub_ab(f, e, a);
    func_0038CF68(f, f, *(f32 *)(p + 0x8E4));
    vec_add_ab(a, f, e);
    if (*(f32 *)(p + 0x8F8) == 0.0f) {
        s32 n = D_L24_001DE804;
        *(s32 *)(p + 0x8EC) = (*(s32 *)(p + 0x8EC) + 1) % n;
        if (*(s32 *)(p + 0x8FC) < n) {
            *(s32 *)(p + 0x8FC) = *(s32 *)(p + 0x8FC) + 1;
        }
    }
    g[0] = 0;
    g[1] = 0;
    g[2] = 0;
    g[3] = 0;
    if (*(s32 *)(p + 0x900) >= 2) {
        s32 n = D_L24_001DE804;
        s32 t = n - 1;
        s32 k = (*(s32 *)(p + 0x8EC) + t) % n;
        vec_sub_ab(h, a, a0 + 0x10);
        vec_sub_ba(i, p + 0x2C0 + k * 16, a0 + 0x10);
        func_L01_0044C280(j, i, h, 0, 0.5f);
        func_003C3FC0(p + 0x4C0 + *(s32 *)(p + 0x8EC) * 16, g);
        vec_add_ba(p + 0x2C0 + *(s32 *)(p + 0x8EC) * 16, j, a0 + 0x10);
        *(s32 *)(p + 0x8EC) = (*(s32 *)(p + 0x8EC) + 1) % D_L24_001DE804;
    }
    func_003C3FC0(p + 0x4C0 + *(s32 *)(p + 0x8EC) * 16, g);
    *(vu0_q *)(p + 0x2C0 + *(s32 *)(p + 0x8EC) * 16) = *(vu0_q *)a;
}
/* localdecomp:end func_L24_003B69F8 */

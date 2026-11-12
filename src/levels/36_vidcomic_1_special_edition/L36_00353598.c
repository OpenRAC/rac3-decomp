#include "common.h"
#include "vu0.h"

typedef int u128_t __attribute__((mode(TI)));

INCLUDE_ASM("asm/levels", func_L36_00353598);

/* localdecomp:start func_L36_00353F58 */
__asm__(".extern D_L36_001DD908, 4");
extern f32 D_L36_001DD908;
extern u8 *func_003C24B0(s32, s32);
extern void func_L01_00456160(u8 *, u8 *);
extern void func_0038D308(u8 *, u8 *);
extern void func_003C7DD8(u8 *);
extern void func_003C29B0(u8 *);
extern void func_003C6FE0(u8 *);
extern void func_L01_0043B9E8(u8 *, s32, s32, s32);
extern f32 func_003824E0(f32, f32);
extern void func_0038CE20(u8 *, u8 *, f32);
extern void func_L36_00354B28(u8 *);
extern void func_L36_003540D8(u8 *);
u8 *func_L36_00353F58(u8 *a0, void *a1, s32 a2, f32 a3) {
    u8 *o;
    u8 *p;
    u8 *q;
    u16 h;
    s32 m;
    o = func_003C24B0(*(s16 *)(a0 + 0xAA), 0x80);
    if (o == 0 || a0 == 0) {
        return 0;
    }
    func_L01_00456160(o, a0);
    func_0038D308(o + 0xC0, o + 0xF0);
    *(f32 *)(o + 0x2C) = *(f32 *)(*(u8 **)(o + 0x24) + 0x24) * (*(f32 *)(a0 + 0x2C) / *(f32 *)(*(u8 **)(a0 + 0x24) + 0x24));
    func_003C7DD8(o);
    h = *(u16 *)(o + 0x34);
    m = 1 << a2;
    *(s32 *)(o + 0x98) = 0;
    h |= 0x100;
    m |= 0x8000;
    h &= 0xFFDF;
    *(u8 *)(o + 0x43) = 0;
    *(u8 *)(o + 0x42) = 0;
    *(u16 *)(o + 0x34) = h;
    *(u16 *)(o + 0x7C) = m;
    func_003C29B0(o);
    *(s32 *)(o + 0x48) = 0;
    *(s32 *)(o + 0x44) = 0;
    func_003C6FE0(o);
    *(u128_t *)(o + 0x10) = *(u128_t *)(a0 + 0x10);
    q = *(u8 **)(a0 + 0x68);
    func_L01_0043B9E8(o, *(u8 *)(q + 0x44), *(u8 *)(q + 0x45), *(u8 *)(q + 0x46));
    p = *(u8 **)(o + 0x68);
    *(u128_t *)(p + 0x20) = *(u128_t *)a1;
    func_0038CE20(a1, a1, func_003824E0(1.0f - D_L36_001DD908, D_L36_001DD908 + 1.0f));
    *(u128_t *)(p + 0x30) = *(u128_t *)a1;
    *(s32 *)(p + 0x4C) = a2;
    *(f32 *)(p + 0x58) = a3;
    *(s32 *)(p + 0x40) = 0;
    *(u16 *)(p + 0x44) = 0;
    *(s32 *)(p + 0x54) = 0;
    *(s32 *)(p + 0x5C) = 0;
    func_L36_00354B28(o);
    *(void **)(o + 0x64) = func_L36_003540D8;
    return o;
}
/* localdecomp:end func_L36_00353F58 */

INCLUDE_ASM("asm/levels", func_L36_003540D8);

INCLUDE_ASM("asm/levels", func_L36_00354288);

INCLUDE_ASM("asm/levels", func_L36_00354648);

/* localdecomp:start func_L36_003549F0 */
extern f32 D_L36_001DD87C;
__asm__(".extern D_L36_001DD87C, 4");
extern void func_0038CF68(void *, void *, f32);
extern f32 func_003824E0(f32, f32);
extern u8 *func_L36_00353F58(u8 *, void *, s32, f32);
void func_L36_003549F0(u8 *a0, u8 *a1, u8 *a2) {
    u8 *s;
    u8 **q;
    u8 *o;
    u8 *p;
    vu0_v4 v;
    vu0_v4 buf;
    s32 i;
    s32 j;
    s = *(u8 **)(a0 + 0x68);
    *(s32 *)(s + 0x80) = 0;
    q = (u8 **)(s + 0x8C);
    for (i = 6; i < 12; i++) {
        func_0038CF68(&buf, a1, D_L36_001DD87C * 0.5f);
        j = 1;
        o = func_L36_00353F58(a0, &buf, i, func_003824E0(-0.11309733f, 0.11309733f));
        *(u8 **)((s32)q + (i << 2)) = o;
        p = *(u8 **)(o + 0x68);
        do {
            vec_sub_ab(&v, p, a2);
            func_0038CF68(&v, &v, D_L36_001DD87C * 0.5f);
            vec_add_ab(p + 0x20, p + 0x20, &v);
            j--;
            p += 0x10;
        } while (j >= 0);
    }
}
/* localdecomp:end func_L36_003549F0 */

/* localdecomp:start func_L36_00354B28 */
__asm__(".extern D_L36_001DD840, 8");
extern f32 D_L36_001DD840[2];
extern f32 D_001A4C64[];
extern void func_003C2F58(u8 *, s32, u8 *);
extern void func_003C2880(u8 *);
void func_L36_00354B28(u8 *a0) {
    u8 *s = *(u8 **)(a0 + 0x68);
    f32 d;
    switch (*(u32 *)(s + 0x4C)) {
    case 2:
        func_003C2F58(a0, 0x8, s);
        *(s16 *)(s + 0x46) = 0;
        *(f32 *)(s + 0x48) = 0.85f;
        break;
    case 3:
        func_003C2F58(a0, 0xB, s);
        *(s16 *)(s + 0x46) = 0;
        *(f32 *)(s + 0x48) = 0.85f;
        break;
    case 4:
        func_003C2F58(a0, 0xD, s);
        func_003C2F58(a0, 0xE, s + 0x10);
        *(s16 *)(s + 0x46) = 1;
        *(f32 *)(s + 0x48) = 0.75f;
        break;
    case 5:
        func_003C2F58(a0, 0x10, s);
        func_003C2F58(a0, 0x11, s + 0x10);
        *(s16 *)(s + 0x46) = 1;
        *(f32 *)(s + 0x48) = 0.75f;
        break;
    case 6:
        func_003C2F58(a0, 0x3, s);
        *(s16 *)(s + 0x46) = 0;
        *(f32 *)(s + 0x48) = 0.8f;
        break;
    case 0:
    case 1:
    case 7:
        func_003C2F58(a0, 0x4, s);
        *(s16 *)(s + 0x46) = 0;
        *(f32 *)(s + 0x48) = 0.6f;
        break;
    case 8:
        func_003C2F58(a0, 0x5, s);
        func_003C2F58(a0, 0x6, s + 0x10);
        *(s16 *)(s + 0x46) = 1;
        *(f32 *)(s + 0x48) = 0.65f;
        break;
    case 9:
        func_003C2F58(a0, 0x7, s);
        func_003C2F58(a0, 0x9, s + 0x10);
        *(s16 *)(s + 0x46) = 1;
        *(f32 *)(s + 0x48) = 0.5f;
        break;
    case 10:
        func_003C2F58(a0, 0xA, s);
        func_003C2F58(a0, 0xC, s + 0x10);
        *(s16 *)(s + 0x46) = 1;
        *(f32 *)(s + 0x48) = 0.5f;
        break;
    case 11:
        func_003C2F58(a0, 0xD, s);
        func_003C2F58(a0, 0xF, s + 0x10);
        *(s16 *)(s + 0x46) = 1;
        *(f32 *)(s + 0x48) = 0.5f;
        break;
    case 12:
        func_003C2F58(a0, 0x10, s);
        func_003C2F58(a0, 0x12, s + 0x10);
        *(s16 *)(s + 0x46) = 1;
        *(f32 *)(s + 0x48) = 0.5f;
        break;
    case 13:
        func_003C2880(a0);
        break;
    }
    *(f32 *)(s + 0x50) = D_L36_001DD840[*(s32 *)(s + 0x4C)];
    d = D_001A4C64[0] - *(f32 *)(s + 4);
    *(f32 *)(a0 + 0x14) = *(f32 *)(a0 + 0x14) + d;
    *(f32 *)(s + 4) = *(f32 *)(s + 4) + d;
    *(f32 *)(s + 0x14) = *(f32 *)(s + 0x14) + d;
}
/* localdecomp:end func_L36_00354B28 */

INCLUDE_ASM("asm/levels", func_L36_00354D88);

/* localdecomp:start func_L36_00355210 */
extern u8 D_L36_001D66B0[8];
extern void func_L36_003553B8(u8 *, u8 *, f32, f32);
void func_L36_00355210(u8 *a0) {
    u8 *p = *(u8 **)(a0 + 0x68);
    s32 i;
    s32 *q;
    f32 f = *(f32 *)p;
    *(s32 *)(p + 0x80) = 0x3F;
    func_L36_003553B8(a0, D_L36_001D66B0, f, f);
    for (i = 12, q = (s32 *)(p + 0xBC); i >= 0; i--) {
        *q-- = 0;
    }
    *(s32 *)(p + 0x7C) = 0;
    *(s32 *)(p + 0x70) = 1;
    *(s32 *)(p + 0x74) = 0;
    *(s32 *)(p + 0x78) = 0;
    qzero(p + 0x60);
}
/* localdecomp:end func_L36_00355210 */

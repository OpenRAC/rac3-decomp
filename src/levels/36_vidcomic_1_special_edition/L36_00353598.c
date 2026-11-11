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
u8 *func_L36_00353F58(u8 *a0, u8 *a1, s32 a2, f32 a3) {
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

INCLUDE_ASM("asm/levels", func_L36_003549F0);

INCLUDE_ASM("asm/levels", func_L36_00354B28);

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

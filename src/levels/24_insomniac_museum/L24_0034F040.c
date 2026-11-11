#include "common.h"

INCLUDE_ASM("asm/levels", func_L24_0034F040);

INCLUDE_ASM("asm/levels", func_L24_0034F080);

INCLUDE_ASM("asm/levels", func_L24_0034F1B8);

LINKER_REMNANT("asm/levels", func_L24_0034F4D8);

INCLUDE_ASM("asm/levels", func_L24_0034F4E0);

INCLUDE_ASM("asm/levels", func_L24_0034F5D8);

INCLUDE_ASM("asm/levels", func_L24_0034F828);

INCLUDE_ASM("asm/levels", func_L24_0034FA98);

INCLUDE_ASM("asm/levels", func_L24_0034FBE8);

/* localdecomp:start func_L24_0034FCF8 */
typedef int u128_t __attribute__((mode(TI)));
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern void func_0038CE20(f32 *, void *, f32);
extern void func_L01_00446760(void *, void *, s32, void *, f32);
extern s32 func_003D3CB0(void *, void *, s32, void *, void *);

s32 func_L24_0034FCF8(u8 *obj, void *a1, void *a2, void *a3, s32 b0, s32 b1, s32 n, f32 scale, f32 d) {
    f32 v[4];
    u8 q[0x30];

    if (*(u16 *)(obj + 0x34) & 0x100) {
        *(u128_t *)v = *(u128_t *)(obj + 0xC0);
    } else {
        v[0] = func_0038D098(*(f32 *)(obj + 0xF8));
        v[1] = func_0038D0B0(*(f32 *)(obj + 0xF8));
        v[2] = 0.0f;
    }
    func_0038CE20(v, v, d);
    v[2] = 1.0f;
    v[3] = 5627.925f;
    func_L01_00446760(q, obj, (s32)a3, v, scale);
    q[0x18] = b0;
    q[0x19] = b1;
    *(u16 *)(q + 0x1A) = *(u16 *)(obj + 0xAA);
    return func_003D3CB0(a1, a2, n, obj, q);
}
/* localdecomp:end func_L24_0034FCF8 */

INCLUDE_ASM("asm/levels", func_L24_0034FE28);

INCLUDE_ASM("asm/levels", func_L24_00350190);

INCLUDE_ASM("asm/levels", func_L24_00350288);

INCLUDE_ASM("asm/levels", func_L24_003503F0);

INCLUDE_ASM("asm/levels", func_L24_00350560);

INCLUDE_ASM("asm/levels", func_L24_00350980);

INCLUDE_ASM("asm/levels", func_L24_00350C30);

INCLUDE_ASM("asm/levels", func_L24_00351448);

INCLUDE_ASM("asm/levels", func_L24_003515A8);

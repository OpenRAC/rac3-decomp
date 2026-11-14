#include "common.h"

/* NTSC-U counterpart of func_L30_0034E710 (src/levels/shared/L30_0034E420.c) */
/* localdecomp:start func_L30_0034D828 */
#include "vu0.h"
extern s32 D_L30_001DD5CC_0034D828; __asm__(".extern D_L30_001DD5CC_0034D828, 4");
extern s32 D_L30_001DD570; __asm__(".extern D_L30_001DD570, 4");
extern s32 D_L30_001DD574_0034D828; __asm__(".extern D_L30_001DD574_0034D828, 4");
extern f32 D_L30_001DD58C_0034D828; __asm__(".extern D_L30_001DD58C_0034D828, 4");
extern s32 D_L30_001DD590_0034D828; __asm__(".extern D_L30_001DD590_0034D828, 4");
extern s32 D_L30_001DD5A8; __asm__(".extern D_L30_001DD5A8, 4");
extern s32 D_L30_001DD5AC; __asm__(".extern D_L30_001DD5AC, 4");
extern f32 D_L30_001DD5B4; __asm__(".extern D_L30_001DD5B4, 4");
extern s32 D_L30_001DD5B8; __asm__(".extern D_L30_001DD5B8, 4");
extern f32 D_L30_001DD608_0034D828; __asm__(".extern D_L30_001DD608_0034D828, 4");
extern f32 D_L30_001DD60C_0034D828; __asm__(".extern D_L30_001DD60C_0034D828, 4");
extern f32 D_L30_001DD610; __asm__(".extern D_L30_001DD610, 4");
extern f32 D_L30_001DD614_0034D828; __asm__(".extern D_L30_001DD614_0034D828, 4");
extern f32 D_L30_001DD618_0034D828; __asm__(".extern D_L30_001DD618_0034D828, 4");
extern f32 D_L30_001DD61C_0034D828; __asm__(".extern D_L30_001DD61C_0034D828, 4");
extern f32 D_L30_001DD620; __asm__(".extern D_L30_001DD620, 4");
typedef struct { s16 a, b; f32 c; s32 d, e, f; void *g; } S_0034E710;
extern S_0034E710 D_L30_001E1240_0034D828 __attribute__((section(".sdata")));
extern S_0034E710 D_L30_001E1260_0034D828 __attribute__((section(".sdata")));
extern void func_L30_0034D660(void *, void *);
extern void func_L30_0034D998(void *, void *);
extern void func_L03_0034A658(void *, s32, s32, f32, s32, void *);
extern void func_003BD360(void *);
extern s32 func_L01_00442E08(u8 *, s32);
extern void func_003C2868(void *);
void func_L30_0034D828(u8 *a0) {
    u8 *s = *(u8 **)(a0 + 0x68);
    s32 t;
    f32 x, y, z;
    if (D_L30_001DD5CC_0034D828 == 0) {
        D_L30_001DD5CC_0034D828 = 1;
        func_L03_0034A658(&D_L30_001E1240_0034D828, D_L30_001DD570, D_L30_001DD574_0034D828, D_L30_001DD58C_0034D828, D_L30_001DD590_0034D828, func_L30_0034D660);
        func_L03_0034A658(&D_L30_001E1260_0034D828, D_L30_001DD5A8, D_L30_001DD5AC, D_L30_001DD5B4, D_L30_001DD5B8, func_L30_0034D998);
    }
    qzero(s);
    t = *(s32 *)(s + 0x14);
    if (t < 1 || t > 5 || *(s32 *)(s + 0x18) <= 0) {
        func_003BD360(a0);
        return;
    }
    if (t == 1) {
        func_L01_00442E08(a0, 0x15D5);
        *(f32 *)(a0 + 0x2C) = D_L30_001DD614_0034D828 * *(f32 *)(*(u8 **)(a0 + 0x24) + 0x24);
    } else if (t == 2) {
        func_L01_00442E08(a0, 0x1C7C);
        *(f32 *)(a0 + 0x2C) = D_L30_001DD618_0034D828 * *(f32 *)(*(u8 **)(a0 + 0x24) + 0x24);
    } else if (t == 3) {
        func_L01_00442E08(a0, 0x1C7D);
        *(f32 *)(a0 + 0x2C) = D_L30_001DD61C_0034D828 * *(f32 *)(*(u8 **)(a0 + 0x24) + 0x24);
    } else if (t == 4) {
        func_L01_00442E08(a0, 0x1C7E);
        *(f32 *)(a0 + 0x2C) = D_L30_001DD620 * *(f32 *)(*(u8 **)(a0 + 0x24) + 0x24);
    }
    func_003C2868(a0);
    a0[0x40] = 0;
    a0[0x41] = 0;
    x = D_L30_001DD608_0034D828;
    y = D_L30_001DD60C_0034D828;
    z = D_L30_001DD610;
    *(u16 *)(a0 + 0x34) &= 0xFFFA;
    *(f32 *)(a0 + 0xF0) = x;
    *(f32 *)(a0 + 0xF4) = y;
    *(f32 *)(a0 + 0xF8) = z;
}
/* localdecomp:end func_L30_0034D828 */

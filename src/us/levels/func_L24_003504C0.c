#include "common.h"

/* NTSC-U counterpart of func_L24_00351448 (src/levels/24_insomniac_museum/L24_0034F040.c): 0.0004 -> 0.000277778 */
#include "vu0.h"
#include "vu0.h"
#include "vu0.h"
extern f32 func_00388A28(f32, f32);
#include "vu0.h"
#include "vu0.h"
extern f32 func_00388A28(f32, f32);
#include "vu0.h"
#include "vu0.h"
#include "vu0.h"
extern s32 func_L24_003504C0(void *, void *, void *, f32, f32, f32, s32, s32, f32);
typedef int u128_t __attribute__((mode(TI)));
#include "vu0.h"
#include "vu0.h"
#include "vu0.h"
extern u8 *func_003BCFB0(s32, s32);
extern void func_003C26C8(void *);
extern void func_0039FE80(s32, s32, void *);
#include "vu0.h"
extern f32 func_00388A28(f32, f32);
extern f32 func_003887A0(void *);

/* localdecomp:start func_L24_003504C0 */
extern u8 *func_003BCFB0(s32, s32);
extern void func_003C26C8(void *);
extern f32 func_00388A28(f32, f32);
extern f32 func_003887A0(void *);
extern void func_0039FE80(s32, s32, void *);

s32 func_L24_003504C0(void *a0, void *a1, void *a2, f32 f12, f32 f13, f32 f14, s32 a3, s32 a4, f32 f15) {
    u8 *o = func_003BCFB0(0x15E2, 0x80);
    u8 *s;
    f32 *v = (f32 *)a2;

    if (o != 0) {
        o[0x30] = 0xFF;
        *(s16 *)(o + 0x32) = 0xFF;
        o[0x31] = 1;
        o[0x20] = 0;
        s = *(u8 **)(o + 0x68);
        *(u128_t *)s = *(u128_t *)a2;
        *(u128_t *)(o + 0x10) = *(u128_t *)a0;
        *(f32 *)(o + 0xF8) = func_00388A28(v[0], v[1]);
        *(f32 *)(o + 0xF4) = -func_00388A28(func_003887A0(v), v[2]);
        *(s32 *)(o + 0xF0) = 0;
        *(void **)(s + 0x10) = a1;
        *(f32 *)(s + 0x20) = f13;
        *(s32 *)(s + 0x28) = a3;
        *(s32 *)(s + 0x2C) = a4;
        *(f32 *)(s + 0x24) = f14;
        *(f32 *)(s + 0x18) = f12 * 0.000277777785f;
        *(f32 *)(o + 0x2C) = *(f32 *)(*(u8 **)(o + 0x24) + 0x24) * f15;
        *(f32 *)(s + 0x14) = f15;
        o[0x20] = 0;
        func_0039FE80(0, 0, o);
        func_003C26C8(o);
    }
    return (s32)o;
}
/* localdecomp:end func_L24_003504C0 */

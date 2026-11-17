#include "common.h"

typedef struct {
    void (*f0)(void *);
    void (*f4)(void *);
} S_3AC810;

/* localdecomp:start func_L13_003AF2F8 */
#include "vu0.h"
__asm__(".extern D_L13_001DE7B4, 4");
__asm__(".extern D_L13_001DE7B8, 4");
extern f32 D_L13_001DE7B4;
extern f32 D_L13_001DE7B8;
extern void func_003C2F58(void *, s32, void *);
extern f32 func_0038D160(f32, f32);
extern f32 func_0038DB00(f32, f32);

void func_L13_003AF2F8(u8 *a0) {
    u8 *s = *(u8 **)(a0 + 0x68);
    vu0_v4 loc0;
    vu0_v4 loc1;
    f32 r;
    f32 lim;

    func_003C2F58(a0, 1, &loc0);
    vec_sub_ba(&loc1, s + 0x130, &loc0);
    r = func_0038DB00(func_0038D160(loc1.x, loc1.y), *(f32 *)(a0 + 0xF8));
    if (*(u16 *)(a0 + 0x34) & 0x8000) {
        r = -r;
    }
    lim = D_L13_001DE7B4 * 0.017453292f;
    if (r < lim) {
        *(f32 *)(s + 0x2D8) = lim;
        func_0038DB00(r, lim);
    } else {
        lim = D_L13_001DE7B8 * 0.017453292f;
        if (lim < r) {
            *(f32 *)(s + 0x2D8) = lim;
            func_0038DB00(r, lim);
        } else {
            *(f32 *)(s + 0x2D8) = r;
        }
    }
}
/* localdecomp:end func_L13_003AF2F8 */

INCLUDE_ASM("asm/levels", func_L13_003AF3B8);

INCLUDE_ASM("asm/levels", func_L13_003AF5E8);

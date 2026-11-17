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

/* localdecomp:start func_L13_003AF5E8 */
#include "vu0.h"

__asm__(".extern D_L13_001DE6B8, 4");
__asm__(".extern D_L13_001DE6BC, 4");
extern f32 D_L13_001DE6B8;
extern f32 D_L13_001DE6BC;
extern void func_003C2EC0(void *, s32, void *);
extern void func_0038CF68(void *, void *, f32);
extern void func_L01_00446780(u8 *, u8 *, s32, s32, s32, s32, f32, f32, f32);
extern void func_003C2F58(void *, s32, void *);

void func_L13_003AF5E8(u8 *o) {
    vu0_v4 m[4];
    vu0_v4 v;
    u8 *p = *(u8 **)(o + 0x68);
    s32 f = 1;

    func_003C2EC0(o, 2, m);
    func_0038CF68(&v, m, D_L13_001DE6BC);
    vec_add_ab(&v, &m[3], &v);
    if (p[0x5F] != 0) {
        f = 0x10001;
    }
    func_L01_00446780(o, (u8 *)&v, f, 0, 1, 0, D_L13_001DE6B8, p[0x45], 1.0f);
    func_003C2F58(o, 3, &v);
    func_L01_00446780(o, (u8 *)&v, f, 0, 1, 0, D_L13_001DE6B8, p[0x45], 1.0f);
}
/* localdecomp:end func_L13_003AF5E8 */

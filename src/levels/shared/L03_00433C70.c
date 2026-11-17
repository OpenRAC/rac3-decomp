#include "common.h"

/* localdecomp:start func_L03_00433C70 */
typedef int u128_00433C70 __attribute__((mode(TI)));
typedef struct {
    u8 pad0[0x18];
    u8 b18;
    u8 b19;
    s16 h1A;
    u8 pad1C[0x30 - 0x1C];
} R_00433C70;
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern void func_0038CE20(void *, void *, f32);
extern void func_L01_00446760(void *, void *, s32, void *, f32);
extern s32 func_003D3CB0(void *, void *, s32, void *, void *);

s32 func_L03_00433C70(u8 *m, void *a1, void *a2, s32 a3, f32 x, f32 scale, s32 b0, s32 b1, s32 fl) {
    f32 dir[4];
    R_00433C70 rec;
    if (*(u16 *)(m + 0x34) & 0x100) {
        *(u128_00433C70 *)dir = *(u128_00433C70 *)(m + 0xC0);
    } else {
        dir[0] = func_0038D098(*(f32 *)(m + 0xF8));
        dir[1] = func_0038D0B0(*(f32 *)(m + 0xF8));
        dir[2] = 0.0f;
    }
    func_0038CE20(dir, dir, scale);
    dir[2] = 1.0f;
    dir[3] = 5627.9248f;
    func_L01_00446760(&rec, m, a3, dir, x);
    rec.b18 = b0;
    rec.b19 = b1;
    rec.h1A = *(s16 *)(m + 0xAA);
    return func_003D3CB0(a1, a2, fl | 9, m, &rec);
}
/* localdecomp:end func_L03_00433C70 */

#include "common.h"

/* NTSC-U counterpart of func_L17_003BEC30 (src/levels/17_crash_site/L17_003BE8C8.c): 0.02 -> 0.0166667; 0.0004 -> 0.000277778; 50 -> 60 */
#include "vu0.h"
typedef struct S_003BED98 {
    u8 pad0[0x20];
    u8 f20;
    u8 pad21[0x75];
    u16 f96;
} S_003BED98;

/* localdecomp:start func_L17_003BCEF0 */
extern void func_00388830(void *, void *, f32);
extern void func_003886E8(void *, void *, f32);
extern f32 func_0037E250(f32, f32);
extern void func_L01_0046CF70(void *, void *, s32, f32);

void func_L17_003BCEF0(S_003BED98 *p, s32 n, f32 speed, f32 unused, f32 spread, f32 up, f32 upvar, f32 size) {
    u8 *m = (u8 *)p;
    vu0_v4 w, pos, v;
    s32 i;

    for (i = 0; i < n; i++) {
        pos = *(vu0_v4 *)(m + 0x10);
        v = *(vu0_v4 *)(m + 0xE0);
        func_00388830(&v, &v, *(f32 *)(m + 0x2C) / *(f32 *)(*(u8 **)(m + 0x24) + 0x24) * speed);
        vec_add_ab(&pos, &pos, &v);
        w = *(vu0_v4 *)(m + 0xE0);
        w.x += func_0037E250(-spread, spread);
        w.y += func_0037E250(-spread, spread);
        func_003886E8(&w, &w, (up + func_0037E250(0.0f, upvar)) * 0.0166666675f);
        func_L01_0046CF70(&pos, &w, 0x3C, size * 0.000277777785f);
    }
}
/* localdecomp:end func_L17_003BCEF0 */

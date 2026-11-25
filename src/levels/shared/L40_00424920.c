#include "common.h"

/* localdecomp:start func_L40_00424920 */
#include "vu0.h"
extern s32 func_L40_004224E0(u8 *);
extern s32 func_L40_00422540(u8 *);
extern void func_0038CE20(void *, void *, f32);
extern void func_0038CF68(void *, void *, f32);
extern s32 func_0038DBD8(f32, s32, s32);
extern u8 *func_L39_005CDCF0(void *, s32, u8, s32, s32, s32, s32, u8 *, f32);
typedef struct { s32 a, b; } E_424920;
extern E_424920 D_L40_003A33F0[];
extern s32 D_L40_0024112C;
extern f32 D_L40_00247740;
extern f32 D_L40_00247744;
extern s32 D_L40_00247748;
extern s32 D_L40_0024774C;
__asm__(".extern D_L40_00247740, 4");
__asm__(".extern D_L40_00247744, 4");
__asm__(".extern D_L40_00247748, 4");
__asm__(".extern D_L40_0024774C, 4");

void func_L40_00424920(u8 *a0) {
    u8 *p = *(u8 **)(a0 + 0x68);
    vu0_v4 v;
    vu0_v4 w;
    s32 i;
    s32 x;
    s32 a;
    f32 d;
    E_424920 *tbl;

    if (func_L40_004224E0(a0)) {
        tbl = &D_L40_003A33F0[*(s32 *)(p + 0x7C)];
    } else {
        if (!func_L40_00422540(a0)) {
            return;
        }
        tbl = &D_L40_003A33F0[*(s32 *)(p + 0x80)];
    }
    if (*(void **)(p + 0x78) != 0) {
        func_0038CE20(&v, *(void **)(p + 0x78), 0.0009765625f);
    } else {
        w = *(vu0_v4 *)(a0 + 0xE0);
        func_0038CF68(&w, &w, 0.75f);
        vec_add_ba(&v, a0 + 0x10, &w);
    }
    for (i = 0; i < 4; i++) {
        s32 col;
        x = (D_L40_0024112C + i * 0x14) & 0xFF;
        d = 0.5f - (f32)(0xD4 - (x * 5 + 2) / 6) / 212.0f;
        d = fabs_asm(d);
        col = func_0038DBD8(d, tbl->a, tbl->b);
        a = (u8)D_L40_0024112C;
        if (i & 2) {
            a = a << 1;
        }
        if (i & 1) {
            a = 0xFF - a;
        }
        func_L39_005CDCF0(&v, col, a, D_L40_0024774C, D_L40_00247748, 2, 0, 0,
                          (D_L40_00247740 + (f32)i * D_L40_00247744) * (*(f32 *)(a0 + 0x2C) / *(f32 *)(*(u8 **)(a0 + 0x24) + 0x24)));
    }
}
/* localdecomp:end func_L40_00424920 */

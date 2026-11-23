#include "common.h"

/* NTSC-U counterpart of func_L32_003A3CA8 (src/levels/32_vidcomic_4/L32_003A2508.c) */
#include "vu0.h"
extern f32 func_00388960(f32);
extern f32 func_00388978(f32);
extern u8 *D_L32_0021F918_003A2428[];
extern f32 func_0037E250(f32, f32);
extern s32 func_0037E208(s32, s32);

/* localdecomp:start func_L32_003A2428 */
typedef struct V_003A3CA8 {
    f32 x, y, z, w;
} __attribute__((aligned(16))) V_003A3CA8;

extern f32 D_L32_001DE8D8;
__asm__(".extern D_L32_001DE8D8, 4");
extern f32 D_L32_001DE8DC_003A2428;
__asm__(".extern D_L32_001DE8DC_003A2428, 4");
extern s32 D_L32_001DE8E0_003A2428;
__asm__(".extern D_L32_001DE8E0_003A2428, 4");
extern f32 func_0037E2A8(void);
extern f32 func_00388960(f32);
extern f32 func_00388978(f32);
extern u8 *func_L01_0046DCB8(void *, void *, s32, u32, f32, f32, s32, s32, s32, f32, s32);

void func_L32_003A2428(void *arg0) {
    u8 *o = *(u8 **)((u8 *)arg0 + 0x68);
    s32 i;
    f32 ang;
    f32 r;
    f32 k;
    s32 n;
    u8 *p;
    V_003A3CA8 v;
    V_003A3CA8 w;

    for (i = 0; i < D_L32_001DE8E0_003A2428; i++) {
        ang = func_0037E2A8();
        r = func_0037E250(0.0f, D_L32_001DE8D8);
        qzero(&w);
        k = func_0037E250(D_L32_001DE8DC_003A2428 * 0.5f, D_L32_001DE8DC_003A2428) * 0.016666668f;
        qzero(&v);
        w.z = (D_L32_001DE8D8 - r) * k;
        v.x = r * func_00388960(ang);
        v.y = fabs_asm(r * func_00388978(ang) * 0.6f) - 0.2f;
        vec_add_ab(&v, &v, o + 0x1C0);
        n = func_0037E208(10, 30);
        p = func_L01_0046DCB8(&v, &w, n, 0x804020, 210000.0f, 84000.0f, func_0037E208(-2, -4), 0x7F,
                              0, 0.0f, 0);
        if (p != 0) {
            p[2] = D_L32_0021F918_003A2428[23][0];
        }
    }
}
/* localdecomp:end func_L32_003A2428 */

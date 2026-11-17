#include "common.h"

/* localdecomp:start func_L40_003ED980 */
__asm__(".extern D_L40_00246DA0, 6");
extern u8 D_L40_00246DA0[2][3];
extern void func_L01_0044E820(void *, s32);

void func_L40_003ED980(u8 *a0, s32 idx) {
    u8 *state = *(u8 **)(a0 + 0x68);
    s32 r = 0;
    s32 g = 0;
    s32 b = 0;
    if (idx >= 0) {
        r = D_L40_00246DA0[idx][0];
        g = D_L40_00246DA0[idx][1];
        b = D_L40_00246DA0[idx][2];
    }
    if (*(s16 *)(state + 0x160) == 0) {
        func_L01_0044E820(a0, (b << 16) | ((g << 8) | 0xFF000000) | r);
    }
}
/* localdecomp:end func_L40_003ED980 */

/* localdecomp:start func_L40_003EDA10 */
/* log: first try 28 diff (gp-lit float, lui table); ps2as + .extern hints (8, as L39_00686138 does for sdata tables) + retail's exact 0x3CA3D70B constant -> MATCH with --as ps2as */
typedef int u128_003EDA10 __attribute__((mode(TI)));
typedef struct {
    f32 x, y, z, w;
} __attribute__((aligned(16))) V_003EDA10;

__asm__(".extern D_L40_00246DB8, 4");
__asm__(".extern D_L40_00246DC0, 8");
extern s32 D_L40_00246DB8;
extern V_003EDA10 D_L40_00246DC0[] __attribute__((section(".sdata")));
extern f32 func_L39_005B4410(f32, f32);
extern s32 func_L39_005B4398(s32);
extern void func_003C2F58(void *, s32, void *);
extern void func_L39_005CF720(void *, void *, void *, void *, s32);

void func_L40_003EDA10(u8 *a0) {
    V_003EDA10 buf;
    V_003EDA10 off;
    V_003EDA10 v;

    if (a0[0x31] != 0) {
        *(u128_003EDA10 *)&v = 0;
        v.z = -(func_L39_005B4410(1.0f, 2.0f) * 0.020000001f);
        off = v;
        func_003C2F58(a0, D_L40_00246DB8, &buf);
        func_L39_005CF720(a0, &buf, &off, &D_L40_00246DC0[func_L39_005B4398(3)], 1);
    }
}
/* localdecomp:end func_L40_003EDA10 */

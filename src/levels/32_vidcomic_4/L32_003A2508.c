#include "common.h"
#include "vu0.h"

/* declared by functions of L32_003A0BB8.c, which this file was cut from */
void func_L32_003A2508(void *, s32, f32);

/* localdecomp:start func_L32_003A2508 */
extern void func_0038CF68(void *, void *, f32);

void func_L32_003A2508(void *arg0v, s32 arg1, f32 arg2) {
    u8 *arg0 = arg0v;
    s32 i;
    u8 **p;
    u8 *obj;
    u8 *sub;

    p = (u8 **)(*(u8 **)(arg0 + 0x68) + 0x200);
    i = 5;
    do {
        obj = *p;
        i--;
        if (obj != 0) {
            sub = *(u8 **)(obj + 0x68);
            *(s32 *)(sub + 0x4C) = arg1;
            *(f32 *)(sub + 0x5C) = arg2;
            vec_sub_ab(sub + 0x20, arg0 + 0x10, *p + 0x10);
            func_0038CF68(sub + 0x20, sub + 0x20, 1.0f);
        }
        p++;
    } while (i >= 0);
}
/* localdecomp:end func_L32_003A2508 */

INCLUDE_ASM("asm/levels", func_L32_003A25B0);

INCLUDE_ASM("asm/levels", func_L32_003A2830);

INCLUDE_ASM("asm/levels", func_L32_003A2A38);

/* localdecomp:start func_L32_003A2C30 */
typedef struct V_003A2C30 {
    f32 x, y, z, w;
} __attribute__((aligned(16))) V_003A2C30;

extern f32 D_L32_001DE81C;
__asm__(".extern D_L32_001DE81C, 4");
extern s32 D_L32_001DE820;
__asm__(".extern D_L32_001DE820, 4");
extern s32 D_L32_001DE824;
__asm__(".extern D_L32_001DE824, 4");
extern f32 D_L32_001DE828;
__asm__(".extern D_L32_001DE828, 4");
extern f32 D_L32_001DE82C;
__asm__(".extern D_L32_001DE82C, 4");
extern f32 D_L32_001DE834;
__asm__(".extern D_L32_001DE834, 4");
extern s32 D_L32_001DE838;
__asm__(".extern D_L32_001DE838, 4");
extern f32 D_L32_001DE840;
__asm__(".extern D_L32_001DE840, 4");
extern s32 D_L32_001DE848;
__asm__(".extern D_L32_001DE848, 4");
extern u8 *D_L32_0021F918[];
extern f32 func_003824E0(f32, f32);
extern void func_0038CE20(void *, void *, f32);
extern void func_L01_003D8E60(void *, void *, f32, s32, f32, s32, f32, s32, s32, s32, s32);
extern void func_00382580(void *, f32, f32);
extern s32 func_00382498(s32, s32);
extern u8 *func_L01_00475C60(void *, void *, s32, s32, s32, s32, f32, f32, f32, s32);
extern s32 func_00382468(s32);

void func_L32_003A2C30(void *arg0, void *arg1, s32 count, s32 arg3, f32 scale) {
    V_003A2C30 v;
    u8 *p;
    s32 i;
    s32 n;
    s32 r;
    f32 size;

    func_0038CE20(&v, arg1, func_003824E0(D_L32_001DE81C * 0.5f, D_L32_001DE81C) * 0.020000001f);
    func_L01_003D8E60(arg0, &v, -100000.0f, D_L32_001DE824, scale * D_L32_001DE828, 7,
                      D_L32_001DE840, 5, D_L32_001DE820, arg3, 0);
    for (i = 0; i < count; i++) {
        func_00382580(&v, D_L32_001DE82C * 0.5f * 0.020000001f, D_L32_001DE82C * 0.020000001f);
        n = (D_L32_001DE838 * 5 + 2) / 6;
        r = func_00382498(-2, 2);
        size = D_L32_001DE834 * scale * 210000.0f;
        p = func_L01_00475C60(arg0, &v, n, r, 0x7F407FFF, 0x407FFF, size, size,
                              func_003824E0(D_L32_001DE840 * 0.6f, D_L32_001DE840), 0);
        if (p != 0) {
            p[9] = 0xF2;
            p[3] = func_00382468(D_L32_001DE848) ? 0x44 : 0x48;
            p[2] = D_L32_0021F918[97][3];
        }
    }
}
/* localdecomp:end func_L32_003A2C30 */

INCLUDE_ASM("asm/levels", func_L32_003A2E30);

INCLUDE_ASM("asm/levels", func_L32_003A3038);

INCLUDE_ASM("asm/levels", func_L32_003A3310);

INCLUDE_ASM("asm/levels", func_L32_003A3420);

INCLUDE_ASM("asm/levels", func_L32_003A3888);

INCLUDE_ASM("asm/levels", func_L32_003A3CA8);

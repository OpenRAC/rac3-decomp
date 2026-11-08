#include "common.h"

typedef int u128_t __attribute__((mode(TI)));

INCLUDE_ASM("asm/levels", func_L23_0032B060);

INCLUDE_ASM("asm/levels", func_L23_0032B190);

/* localdecomp:start func_L23_0032B328 */
extern u32 D_L23_001DCB70;
__asm__(".extern D_L23_001DCB70, 4");
extern u32 D_L23_001DCB74;
__asm__(".extern D_L23_001DCB74, 4");
extern u32 D_L23_001DCB78;
__asm__(".extern D_L23_001DCB78, 4");
extern u32 D_L23_001DCB7C;
__asm__(".extern D_L23_001DCB7C, 4");
extern s32 D_L23_001DCB80;
__asm__(".extern D_L23_001DCB80, 4");
extern u32 D_L23_001DCB84;
__asm__(".extern D_L23_001DCB84, 4");
extern s32 D_L23_001DCB88;
__asm__(".extern D_L23_001DCB88, 4");
extern u32 D_L23_001DCB8C;
__asm__(".extern D_L23_001DCB8C, 4");
extern s32 D_L23_001DCB90;
__asm__(".extern D_L23_001DCB90, 4");
extern float D_L23_001DCB94;
__asm__(".extern D_L23_001DCB94, 4");
extern float func_0038CEA8(void *);
extern float func_00382538(void);
extern void func_003D9508(void *, s32, u32, s32, float, float, float);
extern void func_L01_0040A4A0(void *, void *, s32, u32, s32, s32, float, float, float);

void func_L23_0032B328(u8 *obj) {
    float v[4];
    u8 *pl = *(u8 **)(obj + 0x68);
    float f;
    float t;
    float s1;

    *(u128_t *)v = 0;
    v[3] = 1.0f;
    f = *(float *)(pl + 0x14) - 0.1f;
    *(float *)(pl + 0x14) = f;
    if (f <= -8.0f) {
        *(float *)(pl + 0x14) = f + 8.0f;
    }
    t = func_0038CEA8(pl);
    s1 = D_L23_001DCB94 * 0.2f;
    *(float *)(pl + 0x18) = *(float *)(pl + 0x18) + t;
    s1 = s1 * *(float *)(obj + 0x2C);
    func_003D9508(obj + 0x10, 0x31, D_L23_001DCB70, 1, s1, 0.0f, func_00382538());
    func_003D9508(obj + 0x10, 0x31, D_L23_001DCB74, 1, D_L23_001DCB94 * 0.1f * *(float *)(obj + 0x2C), 0.0f, func_00382538());
    func_003D9508(obj + 0x10, 0x2F, D_L23_001DCB78, 1, D_L23_001DCB94 * 0.05f * *(float *)(obj + 0x2C), 0.0f, func_00382538());
    if (*(float *)(pl + 0x18) > 1.0f) {
        func_L01_0040A4A0(obj, v, 1, D_L23_001DCB7C, D_L23_001DCB80, 0x17, D_L23_001DCB94 * 0.02f * *(float *)(obj + 0x2C),
                          D_L23_001DCB94 * 0.4f, *(float *)(pl + 0x14));
        func_L01_0040A4A0(obj, v, 1, D_L23_001DCB84, D_L23_001DCB88, 0x17, D_L23_001DCB94 * 0.07f * *(float *)(obj + 0x2C),
                          D_L23_001DCB94 * 0.4f, *(float *)(pl + 0x14));
        func_L01_0040A4A0(obj, v, 1, D_L23_001DCB8C, D_L23_001DCB90, 0x17, D_L23_001DCB94 * 0.07f * *(float *)(obj + 0x2C),
                          D_L23_001DCB94 * 0.4f, *(float *)(pl + 0x14));
    }
}
/* localdecomp:end func_L23_0032B328 */

INCLUDE_ASM("asm/levels", func_L23_0032B570);

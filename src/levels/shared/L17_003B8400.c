#include "common.h"

INCLUDE_ASM("asm/levels", func_L17_003B8400);

INCLUDE_ASM("asm/levels", func_L17_003B8658);

INCLUDE_ASM("asm/levels", func_L17_003B8748);

/* localdecomp:start func_L17_003B8B18 */
extern f32 D_L17_001DE59C;
__asm__(".extern D_L17_001DE59C, 4");
extern f32 D_L17_001DE5A0;
__asm__(".extern D_L17_001DE5A0, 4");
extern s32 D_L17_001DE58C;
__asm__(".extern D_L17_001DE58C, 4");
extern s32 D_L17_001DE590;
__asm__(".extern D_L17_001DE590, 4");
extern f32 D_L17_001DE5AC;
__asm__(".extern D_L17_001DE5AC, 4");
extern f32 D_L17_001DE5B0;
__asm__(".extern D_L17_001DE5B0, 4");
extern f32 D_L17_001DE5C8;
__asm__(".extern D_L17_001DE5C8, 4");
extern s32 D_L17_001DE5B4;
__asm__(".extern D_L17_001DE5B4, 4");
extern s32 D_L17_001DE5B8;
__asm__(".extern D_L17_001DE5B8, 4");
extern f32 D_L17_001DE5BC;
__asm__(".extern D_L17_001DE5BC, 4");
extern f32 D_L17_001DE5C0;
__asm__(".extern D_L17_001DE5C0, 4");
extern f32 D_L17_001DE5CC;
__asm__(".extern D_L17_001DE5CC, 4");
extern u8 D_L17_002A3270[];
extern void func_L17_003B8BF8(void *, s32, s32, s32, f32, f32, f32);

void func_L17_003B8B18(u8 *a0) {
    u8 *s = *(u8 **)(a0 + 0x68);
    f32 v = D_L17_001DE59C - D_L17_001DE5A0 * 1.2f;
    D_L17_001DE59C = v;
    if (v <= -8.0f) {
        D_L17_001DE59C = v + 8.0f;
    }
    func_L17_003B8BF8(D_L17_002A3270 + *(s32 *)(s + 0x38) * 640, D_L17_001DE58C, D_L17_001DE590,
                      *(s32 *)(s + 0x2C) - 2, D_L17_001DE5AC, D_L17_001DE5B0, D_L17_001DE5C8);
    func_L17_003B8BF8(D_L17_002A3270 + 0x140 + *(s32 *)(s + 0x38) * 640, D_L17_001DE5B4, D_L17_001DE5B8,
                      *(s32 *)(s + 0x2C), D_L17_001DE5BC, D_L17_001DE5C0, D_L17_001DE5CC);
}
/* localdecomp:end func_L17_003B8B18 */

INCLUDE_ASM("asm/levels", func_L17_003B8BF8);

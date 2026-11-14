#include "common.h"

/* NTSC-U counterpart of func_L21_003A43E8 (src/levels/21_obani_draco/L21_003A3BA0.c) */
/* localdecomp:start func_L21_003A2A78 */
extern s32 D_001DE114_sda;
__asm__(".extern D_001DE114_sda, 4");
extern s32 D_L21_001DE940;
extern s32 D_L21_001DE118[2];
__asm__(".extern D_L21_001DE118, 16");
extern s32 D_L21_001E1050[2];
__asm__(".extern D_L21_001E1050, 16");
extern s32 D_L21_001E1060[2];
__asm__(".extern D_L21_001E1060, 16");
extern s32 D_L21_001E1070[2];
__asm__(".extern D_L21_001E1070, 16");
extern s32 func_00388398(void *);
extern s32 func_0037E208(s32, s32);
extern s32 func_0037E1D8(s32);
extern s32 func_003894A0(f32, s32, s32);

void func_L21_003A2A78(u8 *a0, u8 *a1) {
    s32 i;

    if (D_001DE114_sda != D_L21_001DE940) {
        for (i = 0; i < 3; i++) {
            if (func_00388398(&D_L21_001E1050[i]) != 0) {
                D_L21_001E1050[i] = func_0037E208(100, 200);
                D_L21_001E1060[i] = D_L21_001DE118[func_0037E1D8(4)];
            }
            D_L21_001E1070[i] = func_003894A0(0.01700002f, D_L21_001E1070[i], D_L21_001E1060[i]);
        }
        D_001DE114_sda = D_L21_001DE940;
    }
    *(s32 *)(a0 + 0x78) = D_L21_001E1070[*(s32 *)(a1 + 0x50)];
}
/* localdecomp:end func_L21_003A2A78 */

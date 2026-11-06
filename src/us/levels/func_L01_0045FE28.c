#include "common.h"

/* localdecomp:start func_L01_0045FE28 */
extern s32 func_003883C8(u8 *);
extern void func_003C7CE0(u8 *);
extern u8 *D_L01_0022111C[];

void func_L01_0045FE28(u8 *object) {
    s32 alpha = *(s16 *)(object + 0xA) * *(s32 *)(object + 0x20) / 27;
    *(u32 *)(object + 4) = (*(u32 *)(object + 4) & 0xFFFFFFu) | (alpha << 24);
    if (func_003883C8(object + 0xA)) {
        func_003C7CE0(object);
    } else {
        object[2] = D_L01_0022111C[0][(27 - *(s16 *)(object + 0xA)) * 9 / 27];
    }
}
/* localdecomp:end func_L01_0045FE28 */

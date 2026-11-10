#include "common.h"

/* localdecomp:start func_L39_006CC0E8 */
void func_L39_006CC0E8(u8 *a0, s32 a1, s32 a2, s32 a3, s32 a4, u8 a5, u8 a6, u8 a7) {
    *(s32 *)(a0 + 0x2A8) = a1;
    *(s32 *)(a0 + 0x2AC) = a2;
    *(s32 *)(a0 + 0x2B0) = a3;
    *(s32 *)(a0 + 0x2B4) = a4;
    *(u8 *)(a0 + 0x2B8) = a5;
    *(u8 *)(a0 + 0x2B9) = a6;
    *(u8 *)(a0 + 0x2BA) = a7;
}
/* localdecomp:end func_L39_006CC0E8 */

/* localdecomp:start func_L39_006CC108 */
/* from rac2-decomp's func_00343028, renamed, constants adapted */
void func_L39_006CC108(u8 *a0, f32 a1, f32 a2) { *(f32 *)(a0 + 0x2bc) = a1; *(f32 *)(a0 + 0x2c0) = a2; }
/* localdecomp:end func_L39_006CC108 */

LINKER_REMNANT("asm/levels", func_L39_006CC118);

/* localdecomp:start func_L39_006CC120 */
extern s32 D_L39_00249AF8[];
extern void func_L39_006CC188(void *);

void *func_L39_006CC120(void *object) {
    *(s32 **)((u8 *)object + 0x1D0) = D_L39_00249AF8;
    func_L39_006CC188(object);
    return object;
}
/* localdecomp:end func_L39_006CC120 */

/* localdecomp:start func_L39_006CC158 */
extern s32 D_L39_00249AF8[];
extern void func_L01_004D3BD0(void *);

void func_L39_006CC158(void *object, s32 flags) {
    *(u8 **)((u8 *)object + 0x1D0) = D_L39_00249AF8;
    if (flags & 1) {
        func_L01_004D3BD0(object);
    }
}
/* localdecomp:end func_L39_006CC158 */

INCLUDE_ASM("asm/levels", func_L39_006CC188);

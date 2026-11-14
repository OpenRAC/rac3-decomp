#include "common.h"

INCLUDE_ASM("asm/levels", func_L21_00338DF8);

/* localdecomp:start func_L21_00339088 */
extern s16 *D_L21_0021B860[];
extern u8 *D_L21_001DED9C;
__asm__(".extern D_L21_001DED9C, 16");
extern s32 D_L21_001DEDD8;
extern void func_L02_003A02D8(u8 *, s32);

void func_L21_00339088(u8 *self) {
    u8 *s = *(u8 **)(self + 0x68);
    s16 *p = D_L21_0021B860[*(s32 *)(s + 0x3C)];
    u8 *o;
    s32 i;

    while (i = *(s32 *)(s + 0x3C), (u8)i != 0xFF && i <= D_L21_001DEDD8 && p != 0 && (p[-1] >= 0 || p == D_L21_0021B860[i])) {
        o = D_L21_001DED9C + ((*(u16 *)p & 0x7FFF) << 8);
        if (o == 0) {
            break;
        }
        func_L02_003A02D8(o, 0);
        p++;
    }
}
/* localdecomp:end func_L21_00339088 */

/* localdecomp:start func_L21_00339148 */
extern void func_L01_003E8BD0(s32, s32, f32, f32);
extern void func_L01_003E8D48(s32, f32);

void func_L21_00339148(void) {
    func_L01_003E8BD0(0, 0, 7.0f, 0.003f);
    func_L01_003E8D48(0, 0.34906584f);
}
/* localdecomp:end func_L21_00339148 */

INCLUDE_ASM("asm/levels", func_L21_00339190);

/* localdecomp:start func_L21_00339248 */
s32 func_L21_00339248(void *arg0) {
    return (*(u8 *)((u8 *)arg0 + 0x20)) == 6;
}
/* localdecomp:end func_L21_00339248 */

INCLUDE_ASM("asm/levels", func_L21_00339258);

INCLUDE_ASM("asm/levels", func_L21_003392E0);

INCLUDE_ASM("asm/levels", func_L21_003393C0);

#include "common.h"
#include "vu0.h"

typedef int u128_t __attribute__((mode(TI)));

INCLUDE_ASM("asm/levels", func_L09_003B8580);

INCLUDE_ASM("asm/levels", func_L09_003BBB58);

INCLUDE_ASM("asm/levels", func_L09_003BBF10);

/* localdecomp:start func_L09_003BC288 */
extern u8 *D_L09_001E009C;
__asm__(".extern D_L09_001E009C, 16");
extern u8 D_001A4BE0[];
extern unsigned char D_0014271D[];
__asm__(".extern D_0014271D, 16");
extern void func_003C2880(void *);
extern s32 func_L01_003303B8(u8 *, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32,
    s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern void func_0039EF28(void);
extern void func_L01_00419248(s32);
extern void func_L01_00456230(void *, s32);
extern void func_L01_0043B510(s32);
extern void func_L01_004443E8(void *, s32, s32);
extern void func_L01_004450F0(void *, s32, s32);
extern void func_L01_00445188(u8 *, u8);

void func_L09_003BC288(u8 *a0) {
    u8 *p = *(u8 **)(a0 + 0x68);
    u8 *e = D_L09_001E009C + (*(s32 *)(p + 0xCD0) << 8);
    u8 *h;
    if (a0[0x7F] != 0) {
        return;
    }
    h = D_001A4BE0;
    if (*(s32 *)(h + 0x2850) > 0
        && *(s32 *)(h + 0x25C4) != 0x6A && *(s32 *)(h + 0x25C4) != 0x7D) {
        *(s16 *)(h + 0x1DC) = 0x96;
        func_003C2880(e);
        func_L01_003303B8(e + 0x10, 0, 5, 5, 5, 5, 10, 1, 1.3f, 0.0f, 0.0f, 2.0f,
            0, 1, 0, 0, 0, 1, 0x1010000, 0, 0x388EF7, 0x63F7, 0x407FFF, 0x20FF, 0x8FFF,
            0x3064FF, 0x7F60A0FF, 0x280000FF, 0x3064FF, 0);
        D_0014271D[0] = 1;
        func_0039EF28();
        func_L01_00419248(0x67);
        func_L01_00456230(D_L09_001E009C + (*(s32 *)(p + 0xD24) << 8), 1);
        func_L01_0043B510(*(s32 *)(p + 0xD5C));
        func_L01_004443E8(a0, 0, 3);
        func_L01_004450F0(a0, 1, 9);
        func_L01_00445188(a0, 0);
    }
}
/* localdecomp:end func_L09_003BC288 */

INCLUDE_ASM("asm/levels", func_L09_003BC450);

/* localdecomp:start func_L09_003BC790 */
extern void func_L09_003BC450(u8 *, s32, s32, s32, s32);
extern s32 func_00382498(s32, s32);

void func_L09_003BC790(u8 *a0, s32 a1, s32 a2, s32 a3, s32 a4) {
    u8 *p = *(u8 **)(a0 + 0x68);
    func_L09_003BC450(a0, a1, a2, a3, 0);
    *(s16 *)(p + 0xD38) = (f32)func_00382498(5, 10) * 50.0f;
}
/* localdecomp:end func_L09_003BC790 */

INCLUDE_ASM("asm/levels", func_L09_003BC7F0);

INCLUDE_ASM("asm/levels", func_L09_003BCE10);

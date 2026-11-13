#include "common.h"

INCLUDE_ASM("asm/levels", func_L39_005D6508);

/* localdecomp:start func_L39_005D6730 */
extern s32 *D_L39_00241120;
__asm__(".extern D_L39_00241120, 16");
extern s32 func_L39_005D9730(s32);
extern s32 func_003E6FE0(s32);
extern s32 func_L01_0047C4A8(s32);
extern void func_003E82F8(s32);
extern s32 func_003E8440(s32);
extern s32 func_L39_005DED68(s32);
extern s32 func_L01_00479578(s32);
extern s32 func_L01_0047B638(s32);
extern s32 func_L39_005E1ED0(s32);
extern s32 func_L01_0047C368(s32);
extern s32 func_L39_005E0310(s32);
extern void func_L39_005D6468(s32, s32);

void func_L39_005D6730(void) {
    s32 i;
    s32 n;

    n = (*D_L39_00241120 < 2) ? 0 : 4;
    func_003E6FE0(func_L39_005D9730(0));
    func_003E6FE0(func_L01_0047C4A8(0));
    func_003E82F8(n);
    func_003E8440(func_L39_005D9730(0));
    func_003E8440(func_L01_0047C4A8(0));
    func_003E8440(func_L39_005DED68(0));
    for (i = 0; i < *D_L39_00241120; i++) {
        func_003E6FE0(func_L01_00479578(i));
        func_003E6FE0(func_L01_0047B638(i));
        func_003E6FE0(func_L39_005E1ED0(i));
        func_003E6FE0(func_L01_0047C368(i));
        func_003E6FE0(func_L39_005E0310(i));
        func_L39_005D6468(i, 0);
        func_003E82F8(i);
        func_003E8440(func_L01_00479578(i));
        func_003E8440(func_L01_0047B638(i));
        func_003E8440(func_L39_005E1ED0(i));
        func_003E8440(func_L01_0047C368(i));
        func_003E8440(func_L39_005E0310(i));
    }
    func_003E82F8(0);
}
/* localdecomp:end func_L39_005D6730 */

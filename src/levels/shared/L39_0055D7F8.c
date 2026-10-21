#include "common.h"

/* localdecomp:start func_L39_0055D7F8 */
s32 func_L39_0055D7F8(u8 *a) {
    return *(s16 *)(a + 0xAA) == 0x107e;
}
/* localdecomp:end func_L39_0055D7F8 */

/* localdecomp:start func_L39_0055D808 */
s32 func_L39_0055D808(u8 *a0) {
    return *(s16 *)(a0 + 0xAA) == 0xCBE;
}
/* localdecomp:end func_L39_0055D808 */

/* localdecomp:start func_L39_0055D818 */
s32 func_L39_0055D818(u8 *a0) {
    return *(s16 *)(a0 + 0xAA) == 0x1A47;
}
/* localdecomp:end func_L39_0055D818 */

INCLUDE_ASM("asm/levels", func_L39_0055D828);

INCLUDE_ASM("asm/levels", func_L39_0055D948);

INCLUDE_ASM("asm/levels", func_L39_0055DB18);

/* localdecomp:start func_L39_0055DBE8 */
extern s32 func_L39_0066DCC8(s32 a0, s32 a1, s32 a2, s32 a3);
extern void func_L39_00662AA0(s32 a0, void *a1, s32 a2);
void func_L39_0055DBE8(s32 a0, s32 a1) {
    s32 x;
    s32 r = func_L39_0066DCC8(a0, 0, 0, 250);
    x = a1;
    func_L39_00662AA0(r, &x, 4);
}
/* localdecomp:end func_L39_0055DBE8 */

/* localdecomp:start func_L39_0055DC30 */
extern s32 func_L39_0066DCC8(s32 a0, s32 a1, s32 a2, s32 a3);
typedef struct {
    u8 pad0[0x55];
    u8 b55;
} S_55D1B8;

extern S_55D1B8 *func_L39_0066DD30(s32 a0, s32 a1, s32 a2);
extern void func_L39_006626E8(S_55D1B8 *p);

void func_L39_0055DC30(s32 a0) {
    S_55D1B8 *p;
    ((void (*)(s32 a0, s32 a1, s32 a2, s32 a3))func_L39_0066DCC8)(a0, 1, 0, 250);
    p = func_L39_0066DD30(a0, 2, 0);
    if (p != 0 && p->b55 != 0) {
        func_L39_006626E8(p);
    }
}
/* localdecomp:end func_L39_0055DC30 */

/* localdecomp:start func_L39_0055DC90 */
extern S_55D1B8 *func_L39_0066DD30(s32 a0, s32 a1, s32 a2);
s32 func_L39_0055DC90(s32 a0) {
    return ((s32 (*)(s32, s32, s32))func_L39_0066DD30)(a0, 0, 0) != 0;
}
/* localdecomp:end func_L39_0055DC90 */

/* localdecomp:start func_L39_0055DCB8 */
extern S_55D1B8 *func_L39_0066DD30(s32 a0, s32 a1, s32 a2);
s32 func_L39_0055DCB8(s32 a0) {
    return ((s32 (*)(s32, s32, s32))func_L39_0066DD30)(a0, 1, 0) != 0;
}
/* localdecomp:end func_L39_0055DCB8 */

INCLUDE_ASM("asm/levels", func_L39_0055DCE0);

INCLUDE_ASM("asm/levels", func_L39_0055E2E0);

/* localdecomp:start func_L39_0055E770 */
s32 func_L39_0055E770(u8 *p, s32 *a, s32 *b) {
    s32 v = *(s32 *)(p + 104);
    *b = 12;
    *a = v + 512;
    return 0;
}
/* localdecomp:end func_L39_0055E770 */

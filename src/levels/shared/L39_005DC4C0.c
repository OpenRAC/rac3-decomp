#include "common.h"

/* localdecomp:start func_L39_005DC4C0 */
extern u8 *D_L39_0024BF5C;
extern void func_L01_00451388(u8 *, s32 *, s32 *);

s32 func_L39_005DC4C0(s32 i, s32 *a, s32 *b) {
    s32 r;

    *a = 0;
    r = 0;
    *b = 0;
    if (i >= 0) {
        r = 1;
        func_L01_00451388(D_L39_0024BF5C + (i << 8), a, b);
    }
    return r;
}
/* localdecomp:end func_L39_005DC4C0 */

INCLUDE_ASM("asm/levels", func_L39_005DC508);

INCLUDE_ASM("asm/levels", func_L39_005DC648);

INCLUDE_ASM("asm/levels", func_L39_005DD258);

INCLUDE_ASM("asm/levels", func_L39_005DD290);

/* localdecomp:start func_L39_005DD370 */
__asm__(".extern D_001D81E0_sda, 4");
extern float D_001D81E0_sda;
extern float func_0038DAB8(float, float);

float func_L39_005DD370(void *m) {
    return func_0038DAB8(*(float *)((char *)m + 0xF8), D_001D81E0_sda);
}
/* localdecomp:end func_L39_005DD370 */

/* localdecomp:start func_L39_005DD390 */
extern u8 *D_L39_0024BF5C;
extern float func_L39_005DD370(void *);
float func_L39_005DD390(s32 a0) {
    float r = 0.0f;
    if (a0 >= 0) r = func_L39_005DD370(D_L39_0024BF5C + (a0 << 8));
    return r;
}
/* localdecomp:end func_L39_005DD390 */

INCLUDE_ASM("asm/levels", func_L39_005DD3C0);

INCLUDE_ASM("asm/levels", func_L39_005DD810);

/* localdecomp:start func_L39_005DE6B8 */
extern u8 D_L39_002438EC;
extern s32 func_L39_006121B0();
void func_L39_005DE6B8(void) {
    D_L39_002438EC = 0;
    func_L39_006121B0(23);
}
/* localdecomp:end func_L39_005DE6B8 */

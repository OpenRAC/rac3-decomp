#include "common.h"

/* localdecomp:start func_L39_006770F8 */
extern u8 D_L39_00246598[8];
void func_L39_006770F8(s32 i) {
    D_L39_00246598[i] = 1;
}
/* localdecomp:end func_L39_006770F8 */

/* localdecomp:start func_L39_00677110 */
extern u8 D_L39_00246598[8];

u8 func_L39_00677110(s32 a0) {
    return D_L39_00246598[a0];
}
/* localdecomp:end func_L39_00677110 */

/* localdecomp:start func_L39_00677120 */
extern u8 D_L39_00246598[8];

void func_L39_00677120(s32 a0) {
    D_L39_00246598[a0] = 0;
}
/* localdecomp:end func_L39_00677120 */

/* localdecomp:start func_L39_00677130 */
extern s32 D_L39_002465A0[2];
void func_L39_00677130(s32 i) {
    D_L39_002465A0[i] = 0;
}
/* localdecomp:end func_L39_00677130 */

/* localdecomp:start func_L39_00677148 */
extern s32 D_L39_002465A0[2];
void func_L39_00677148(s32 i) {
    if (D_L39_002465A0[i] == 0) {
        D_L39_002465A0[i] = 1;
    }
}
/* localdecomp:end func_L39_00677148 */

/* localdecomp:start func_L39_00677170 */
extern s32 D_L39_002465A0[2];

s32 func_L39_00677170(s32 i) {
    return D_L39_002465A0[i] == 3;
}
/* localdecomp:end func_L39_00677170 */

INCLUDE_ASM("asm/levels", func_L39_00677190);

#include "common.h"

/* localdecomp:start func_L01_0041A910 */
extern s32 func_00381FF0_0041A910(s32);
extern s32 func_00382030_0041A910();
void func_L01_0041A910(void) {
    func_00381FF0_0041A910(func_00382030_0041A910());
}
/* localdecomp:end func_L01_0041A910 */

INCLUDE_ASM("asm/levels", func_L01_0041A938);

/* localdecomp:start func_L01_0041A990 */
extern s16 D_L01_002E5F68[];

void func_L01_0041A990(void) {
    D_L01_002E5F68[0] = 0;
}
/* localdecomp:end func_L01_0041A990 */

INCLUDE_ASM("asm/levels", func_L01_0041A9A0);

INCLUDE_ASM("asm/levels", func_L01_0041AB50);

/* localdecomp:start func_L01_0041B600 */
void func_L01_0041B600(void) {

}
/* localdecomp:end func_L01_0041B600 */

INCLUDE_ASM("asm/levels", func_L01_0041B608);

LINKER_REMNANT("asm/levels", func_L01_0041BD40);

/* localdecomp:start func_L01_0041BD48 */
extern s32 D_001D5598;
extern u16 D_001A8EC8[];

void func_L01_0041BD48(u16 id) {
    s32 i;

    for (i = 0; D_001A8EC8[i] != id && i < D_001D5598; i++) {
    }
    if (i < D_001D5598) {
        for (; i < D_001D5598 - 1; i++) {
            D_001A8EC8[i] = D_001A8EC8[i + 1];
        }
        D_001A8EC8[i] = 0;
        D_001D5598--;
    }
    D_001A8EC8[D_001D5598++] = id;
}
/* localdecomp:end func_L01_0041BD48 */

LINKER_REMNANT("asm/levels", func_L01_0041BE18);

/* localdecomp:start func_L01_0041BE20 */
void func_L01_0041BE20(void) {

}
/* localdecomp:end func_L01_0041BE20 */

INCLUDE_ASM("asm/levels", func_L01_0041BE28);

/* localdecomp:start func_L01_0041BF08 */
extern u8 D_L01_001DFCF2;
extern u8 D_L01_001DFCF3;
extern s16 D_L01_001DFCE0;
extern s16 D_L01_001DFCC8;
extern s32 func_L01_0041A5B0(s32 a0, s32 a1);
void func_L01_0041BF08(void) {
    if (D_L01_001DFCF2 != 0) {
        if (func_L01_0041A5B0((&D_L01_001DFCC8)[D_L01_001DFCF3], (&D_L01_001DFCE0)[D_L01_001DFCF3]) != 0) {
            D_L01_001DFCF2 = D_L01_001DFCF2 - 1;
            D_L01_001DFCF3 = (D_L01_001DFCF3 + 1) % 9;
        }
    }
}
/* localdecomp:end func_L01_0041BF08 */

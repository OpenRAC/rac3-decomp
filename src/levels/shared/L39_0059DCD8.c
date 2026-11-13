#include "common.h"

/* localdecomp:start func_L39_0059DCD8 */
void func_0012BAC8();
void func_0012BB38();

void func_L39_0059DCD8(void) {
    func_0012BB38();
    func_0012BAC8();
}
/* localdecomp:end func_L39_0059DCD8 */

/* localdecomp:start func_L39_0059DD00 */
extern s32 func_00126620(s32 *, s32);
extern s32 func_00126600(s32);
extern s32 func_0012C2C0(s32, s32, s32);
extern void func_L39_0059DCD8(void);

s32 func_L39_0059DD00(s32 a0, s32 a1, s32 a2, s32 a3, s32 a4) {
    s32 dma[4];
    s32 id;
    s32 r;
    r = -1;
    dma[0] = a0;
    dma[1] = a2;
    dma[2] = a1;
    dma[3] = 0;
    id = func_00126620(dma, 1);
    if (id != 0) {
        while (func_00126600(id) >= 0) {
        }
        r = func_0012C2C0(a2, a3, a4);
    }
    func_L39_0059DCD8();
    return r;
}
/* localdecomp:end func_L39_0059DD00 */

INCLUDE_ASM("asm/levels", func_L39_0059DDB0);

/* localdecomp:start func_L39_0059DE98 */
void func_00139250(s32);

void func_L39_0059DE98(void) {
    func_00139250(2);
}
/* localdecomp:end func_L39_0059DE98 */

INCLUDE_ASM("asm/levels", func_L39_0059DEB8);

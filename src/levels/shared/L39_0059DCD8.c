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

/* localdecomp:start func_L39_0059DDB0 */
/* from rac1-decomp's InitMemSlots (initonce.c), the slot table and its sizes adapted */
extern void func_0011D534(void *, s32, s32);
extern s32 D_L39_0025F680[];
extern u8 D_L39_006F277F[];
extern u8 D_01F38000[];
extern u8 D_01FFC000[];
extern s32 D_L39_0024CAD8;
__asm__(".extern D_L39_0024CAD8, 16");

void func_L39_0059DDB0(void) {
    s32 base;
    s32 size;
    s32 a, b, c;
    s32 e, f, g;
    s32 h;

    func_0011D534(D_L39_0025F680, 0, 0xA0);
    D_L39_0025F680[0] = 0;
    base = (s32)D_L39_006F277F & 0xFFFFF000;
    size = D_L39_0024CAD8;
    D_L39_0025F680[3] = base;
    a = base + size;
    D_L39_0025F680[4] = a;
    b = a + size;
    D_L39_0025F680[5] = b;
    c = b + 0x100000;
    D_L39_0025F680[6] = c;
    e = (s32)D_01F38000;
    h = (s32)D_01FFC000;
    D_L39_0025F680[34] = e;
    f = e - 0x40000;
    D_L39_0025F680[33] = f;
    g = f - 0x64000;
    D_L39_0025F680[32] = g;
    D_L39_0025F680[31] = g;
    D_L39_0025F680[26] = c;
    D_L39_0025F680[35] = h;
    D_L39_0025F680[27] = g;
    D_L39_0025F680[36] = 0x7000000;
    D_L39_0025F680[37] = 0x7100000;
    D_L39_0025F680[38] = 0x7180000;
    D_L39_0025F680[1] = 0x100000;
    D_L39_0025F680[2] = base;
    D_L39_0025F680[39] = 0x7200000;
}
/* localdecomp:end func_L39_0059DDB0 */

/* localdecomp:start func_L39_0059DE98 */
void func_00139250(s32);

void func_L39_0059DE98(void) {
    func_00139250(2);
}
/* localdecomp:end func_L39_0059DE98 */

INCLUDE_ASM("asm/levels", func_L39_0059DEB8);

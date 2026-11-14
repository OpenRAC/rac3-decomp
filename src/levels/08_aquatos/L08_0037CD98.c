#include "common.h"

/* localdecomp:start func_L08_0037CD98 */
typedef int Quad_0037CD98 __attribute__((mode(TI)));
typedef struct G_0037CD98 {
    u8 pad00[0x25C0];
    u8 *x25C0;
} G_0037CD98;

extern void func_L01_004450F0(void *, s32, s32);
extern void func_L08_0037CE30(void *);
extern G_0037CD98 D_001A4BE0;

void func_L08_0037CD98(u8 *self) {
    u8 *s = *(u8 **)(self + 0x68);

    switch (self[0x20]) {
    case 0:
        func_L01_004450F0(self, 1, -1);
        self[0x30] = 0xFF;
        *(Quad_0037CD98 *)(self + 0xC0) = *(Quad_0037CD98 *)(D_001A4BE0.x25C0 + 0xC0);
        *(Quad_0037CD98 *)(self + 0xD0) = *(Quad_0037CD98 *)(D_001A4BE0.x25C0 + 0xD0);
        *(Quad_0037CD98 *)(self + 0xE0) = *(Quad_0037CD98 *)(D_001A4BE0.x25C0 + 0xE0);
        break;
    case 1:
        if (*(s32 *)(s + 0x24) != 0) {
            func_L08_0037CE30(self);
        }
        break;
    }
}
/* localdecomp:end func_L08_0037CD98 */

INCLUDE_ASM("asm/levels", func_L08_0037CE30);

INCLUDE_ASM("asm/levels", func_L08_0037CFC0);

INCLUDE_ASM("asm/levels", func_L08_0037D450);

#include "common.h"

typedef struct { u8 pad[0x60]; u8 x60; } V_3D6A28;
typedef struct { u8 pad[0x68]; V_3D6A28 *x68; } M_3D6A28;
typedef struct { u8 pad[0x70]; u8 x70[0x100]; s32 x170; u8 pad174[0x18C - 0x174]; M_3D6A28 *x18C; } B_3D6A28;
typedef struct { u8 pad[0xA8]; u8 xA8; } O_3D6A28;

INCLUDE_ASM("asm/levels", func_L12_003D7BE8);

INCLUDE_ASM("asm/levels", func_L12_003D84A0);

/* localdecomp:start func_L12_003D8808 */
extern void func_L01_0044ABD0(O_3D6A28 *, void *);
extern s32 func_L01_00452FB0(O_3D6A28 *, void *, s32, s32, s32);
extern void func_L12_003D88C8(O_3D6A28 *, B_3D6A28 *);
extern void func_L01_00456BD0(O_3D6A28 *, s32);
s32 func_L12_003D8808(O_3D6A28 *a0, B_3D6A28 *a1) {
    if (a1->x18C != 0 && a1->x18C->x68->x60 != 0) {
        func_L01_0044ABD0(a0, a1->x70);
        a0->xA8 = 255;
    } else {
        s32 r = func_L01_00452FB0(a0, a1->x70, 0, 0, 0);
        if (r != 0) {
            if (r == 4 || r == 5) {
                func_L12_003D88C8(a0, a1);
                return 0;
            }
        }
    }
    if (a1->x170 != 0) {
        func_L01_00456BD0(a0, 1);
    } else {
        func_L01_00456BD0(a0, 3);
    }
    return 1;
}
/* localdecomp:end func_L12_003D8808 */

INCLUDE_ASM("asm/levels", func_L12_003D88C8);

INCLUDE_ASM("asm/levels", func_L12_003D89F8);

INCLUDE_ASM("asm/levels", func_L12_003D8B20);

INCLUDE_ASM("asm/levels", func_L12_003D8C30);

INCLUDE_ASM("asm/levels", func_L12_003D8DB8);

INCLUDE_ASM("asm/levels", func_L12_003D9000);

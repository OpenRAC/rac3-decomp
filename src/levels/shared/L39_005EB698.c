#include "common.h"

INCLUDE_ASM("asm/levels", func_L39_005EB698);

/* localdecomp:start func_L39_005EBAF0 */
extern s32 func_L01_00517688(void);
extern s32 *func_003B9BD0(s32);
extern s32 func_003B9C58(s32 *);
extern void func_L39_005F3548(s32, s32, s32);
/* an alias: func_L39_005EBDA0 below declares func_L39_0061BF38 with its own return type */
extern u8 *func_L39_0061BF38_005EBAF0(s32 i);
typedef struct { u8 pad[0x74]; s32 t[4][4]; } S_005EBAF0_A;
typedef struct { s32 t[4][8]; } S_005EBAF0_B;
extern s32 D_L39_0024C890[] __attribute__((section(".sdata")));
extern S_005EBAF0_A D_001A5810;
extern S_005EBAF0_B D_001A5990;

void func_L39_005EBAF0(s32 buttons) {
    s32 i = 0;
    s32 idx = 0;
    switch (func_L01_00517688()) {
    case 0: i = 0; break;
    case 1: i = 1; break;
    case 2: i = 2; break;
    case 3: i = 3; break;
    default: break;
    }
    idx = func_L01_00517688();
    if (func_003B9C58(func_003B9BD0(i)) == 3) {
        if (buttons & 0x8000) {
            s32 v = D_001A5810.t[D_L39_0024C890[idx]][idx] - 2;
            if (v < 0) v = 0;
            D_001A5810.t[D_L39_0024C890[idx]][idx] = v;
            func_L39_005F3548(3, 0, 0);
        } else if (buttons & 0x2000) {
            s32 v = D_001A5810.t[D_L39_0024C890[idx]][idx] + 2;
            D_001A5810.t[D_L39_0024C890[idx]][idx] = (v > 100) ? 100 : v;
            func_L39_005F3548(3, 0, 0);
        }
        D_001A5990.t[D_L39_0024C890[idx]][*(s32 *)(func_L39_0061BF38_005EBAF0(idx) + 0x2544)] = D_001A5810.t[D_L39_0024C890[idx]][idx];
    }
}
/* localdecomp:end func_L39_005EBAF0 */

INCLUDE_ASM("asm/levels", func_L39_005EBCB8);

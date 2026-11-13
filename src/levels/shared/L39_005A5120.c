#include "common.h"

/* localdecomp:start func_L39_005A5120 */
extern s32 D_001A43F0[];
extern s32 D_001D4CE8_sda;

void func_L39_005A5120(void) {
    D_001A43F0[0] = 0;
    D_001D4CE8_sda = 4;
}
/* localdecomp:end func_L39_005A5120 */

/* localdecomp:start func_L39_005A5138 */
extern s32 D_001A43E8[];
extern s32 D_L39_002403F8;
__asm__(".extern D_L39_002403F8, 16");
extern s32 D_L39_002403FC;
__asm__(".extern D_L39_002403FC, 16");

void func_L39_005A5138(void) {
    s32 f, w, g;
    if (D_001A43E8[0] != 2) {
        D_L39_002403F8 = 4;
    } else if (D_L39_002403FC & 4) {
        D_L39_002403F8 = 0x1E;
    } else if (D_L39_002403FC & 2) {
        D_L39_002403F8 = 0x1D;
    }
    f = D_L39_002403FC;
    if (f & 0x80) {
        w = 0x18;
        g = f ^ 0x80;
    } else if (f & 0x100) {
        w = 0x16;
        g = f ^ 0x100;
    } else {
        return;
    }
    g |= 0x40;
    D_L39_002403F8 = w;
    D_L39_002403FC = g;
}
/* localdecomp:end func_L39_005A5138 */

/* localdecomp:start func_L39_005A51C0 */
typedef struct {
    u8 pad0[0x16C];
    s32 w16C;
    u8 pad170[0x17C - 0x170];
    s32 w17C;
} S_1A43E0_005A51C0;

extern void (*D_001D79A0_sda)(void);
extern S_1A43E0_005A51C0 D_001A43E0;
extern s32 D_L39_002403F8;
__asm__(".extern D_L39_002403F8, 16");

void func_L39_005A51C0(void) {
    if (D_001D79A0_sda != 0) {
        D_001D79A0_sda();
        D_001D79A0_sda = 0;
    }
    if (D_001A43E0.w16C == 0) {
        D_001A43E0.w17C = 1;
    }
    D_L39_002403F8 = 1;
}
/* localdecomp:end func_L39_005A51C0 */

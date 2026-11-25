#include "common.h"

typedef struct { u8 pad[0x10]; f32 x; f32 y; } M_4574A0;
typedef struct {
    u8 pad[0xDC];
    f32 fDC;
    s16 hE0;
    s16 hE2;
    s16 hE4;
} S_4574A0;
typedef struct { u8 pad[16]; u8 sub[248 - 16]; f32 f; } S457;
typedef int u128_t __attribute__((mode(TI)));

/* localdecomp:start func_L01_0045C1D0 */
extern s32 D_L01_001DFB40_0045C1D0;
__asm__(".extern D_L01_001DFB40_0045C1D0, 16");
extern f32 D_L01_001D7DD4_0045C1D0;
extern s32 D_L01_001D7DD8_0045C1D0;
extern s32 D_L01_001D7DDC_0045C1D0;
extern f32 D_L01_001D7DE0_0045C1D0;
void func_L01_0045C1D0(void) {
    if (D_L01_001D7DD8_0045C1D0 != D_L01_001DFB40_0045C1D0) {
        if (D_L01_001D7DDC_0045C1D0 != 0) {
            D_L01_001D7DE0_0045C1D0 = D_L01_001D7DD4_0045C1D0 / D_L01_001D7DDC_0045C1D0;
        } else {
            D_L01_001D7DE0_0045C1D0 = 0;
        }
        D_L01_001D7DDC_0045C1D0 = 0;
        D_L01_001D7DD8_0045C1D0 = D_L01_001DFB40_0045C1D0;
        D_L01_001D7DD4_0045C1D0 = 0;
    }
    *(volatile u32 *)0x10000010 = 0x81;
    *(volatile u32 *)0x10000000 = 0;
}
/* localdecomp:end func_L01_0045C1D0 */

/* localdecomp:start func_L01_0045C240 */
extern s32 D_L01_001D7DDC;
extern f32 D_L01_001D7DD4;
void func_L01_0045C240(void) {
    D_L01_001D7DDC++;
    D_L01_001D7DD4 += (f32)*(volatile u32 *)0x10000000;
}
/* localdecomp:end func_L01_0045C240 */

LINKER_REMNANT("asm/levels", func_L01_0045C298);

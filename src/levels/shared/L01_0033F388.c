#include "common.h"
#include "vu0.h"

typedef struct {
    u8 pad0[0x18];
    f32 f18;
} S_33BDC8;
typedef void (*Fn_33CA98)(u8 *);


/* localdecomp:start func_L01_0033F388 */
typedef struct {
    s32 w0;
    s16 h4;
    s16 h6;
    s16 h8;
    s16 hA;
} R_0033F388;
extern R_0033F388 D_L01_00278DA0[];
extern s32 D_L01_001E18C0[] __attribute__((section(".sdata")));
extern s32 D_L01_001E18C4[] __attribute__((section(".sdata")));
extern s32 D_L01_001E18C8[] __attribute__((section(".sdata")));
extern f32 D_L01_001E18CC[] __attribute__((section(".sdata")));
extern s32 D_L01_001DD050;
extern s32 D_L01_001DD054;
extern f32 D_L01_001DD058;
extern f32 D_L01_001DD094;
extern u16 D_L01_001DD098;
__asm__(".extern D_L01_001DD050, 4");
__asm__(".extern D_L01_001DD054, 4");
__asm__(".extern D_L01_001DD058, 4");
__asm__(".extern D_L01_001DD094, 4");
__asm__(".extern D_L01_001DD098, 2");
extern s32 func_L01_0040DFC0(s32 *);
extern s32 func_L01_0040DFF0(u8 *);

void func_L01_0033F388(void) {
    s32 i;
    s32 n;

    if (D_L01_001DD050 != 0) {
        for (i = 9; i >= 0; i--) {
            D_L01_00278DA0[i].h8 = 0;
        }
        D_L01_001DD050 = 0;
        D_L01_001E18C0[0] = 0;
        n = (s32)(D_L01_001DD058 / (D_L01_001DD094 * 0.020000001f));
        D_L01_001E18C8[0] = n;
        D_L01_001E18CC[0] = 1.0f / (f32)n;
    }
    if (D_L01_001E18C4[0] == 0) {
        if (func_L01_0040DFC0(D_L01_001E18C0) != 0) {
            for (i = 0; i < 10; i++) {
                if (D_L01_00278DA0[i].h8 == 0) {
                    D_L01_001E18C0[0] = (D_L01_001DD054 * 5 + 2) / 6;
                    D_L01_00278DA0[i].h8 = 1;
                    D_L01_00278DA0[i].h4 = D_L01_001E18C8[0];
                    D_L01_00278DA0[i].h6 = D_L01_001DD098;
                    break;
                }
            }
        }
    }
    for (i = 0; i < 10; i++) {
        if (D_L01_00278DA0[i].h8 != 0) {
            if (func_L01_0040DFF0((u8 *)&D_L01_00278DA0[i].h4) != 0) {
                D_L01_00278DA0[i].h8 = 0;
            }
        }
    }
}
/* localdecomp:end func_L01_0033F388 */

INCLUDE_ASM("asm/levels", func_L01_0033F530);

INCLUDE_ASM("asm/levels", func_L01_0033F920);

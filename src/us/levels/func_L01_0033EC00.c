#include "common.h"

/* NTSC-U counterpart of func_L01_0033F388 (src/levels/shared/L01_0033F388.c) */
#include "vu0.h"

/* localdecomp:start func_L01_0033EC00 */
typedef struct {
    s32 w0;
    s16 h4;
    s16 h6;
    s16 h8;
    s16 hA;
} R_0033F388;
extern R_0033F388 D_L01_00278E20_0033EC00[];
extern s32 D_L01_001E1940_0033EC00[] __attribute__((section(".sdata")));
extern s32 D_L01_001E1944[] __attribute__((section(".sdata")));
extern s32 D_L01_001E1948[] __attribute__((section(".sdata")));
extern f32 D_L01_001E194C[] __attribute__((section(".sdata")));
extern s32 D_L01_001DD090_0033EC00;
extern s32 D_L01_001DD094_0033EC00;
extern f32 D_L01_001DD098_0033EC00;
extern f32 D_L01_001DD0D4;
extern u16 D_L01_001DD0D8;
__asm__(".extern D_L01_001DD090_0033EC00, 4");
__asm__(".extern D_L01_001DD094_0033EC00, 4");
__asm__(".extern D_L01_001DD098_0033EC00, 4");
__asm__(".extern D_L01_001DD0D4, 4");
__asm__(".extern D_L01_001DD0D8, 2");
extern s32 func_00388398(s32 *);
extern s32 func_003883C8(u8 *);

void func_L01_0033EC00(void) {
    s32 i;
    s32 n;

    if (D_L01_001DD090_0033EC00 != 0) {
        for (i = 9; i >= 0; i--) {
            D_L01_00278E20_0033EC00[i].h8 = 0;
        }
        D_L01_001DD090_0033EC00 = 0;
        D_L01_001E1940_0033EC00[0] = 0;
        n = (s32)(D_L01_001DD098_0033EC00 / (D_L01_001DD0D4 * 0.016666668f));
        D_L01_001E1948[0] = n;
        D_L01_001E194C[0] = 1.0f / (f32)n;
    }
    if (D_L01_001E1944[0] == 0) {
        if (func_00388398(D_L01_001E1940_0033EC00) != 0) {
            for (i = 0; i < 10; i++) {
                if (D_L01_00278E20_0033EC00[i].h8 == 0) {
                    D_L01_001E1940_0033EC00[0] = D_L01_001DD094_0033EC00;
                    D_L01_00278E20_0033EC00[i].h8 = 1;
                    D_L01_00278E20_0033EC00[i].h4 = D_L01_001E1948[0];
                    D_L01_00278E20_0033EC00[i].h6 = D_L01_001DD0D8;
                    break;
                }
            }
        }
    }
    for (i = 0; i < 10; i++) {
        if (D_L01_00278E20_0033EC00[i].h8 != 0) {
            if (func_003883C8((u8 *)&D_L01_00278E20_0033EC00[i].h4) != 0) {
                D_L01_00278E20_0033EC00[i].h8 = 0;
            }
        }
    }
}
/* localdecomp:end func_L01_0033EC00 */

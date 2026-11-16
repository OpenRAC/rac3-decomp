/* NTSC-U draft (Claude wave K): C of func_L01_0033EC00, the NTSC-U twin of func_L01_0033F388, with NTSC-U names and addresses (the two versions' code differs).
 * near miss: 79 words differ on NTSC-U (the worker's best count) (NTSC-U twin "func_L01_0033EC00", whose code is not the PAL one).
 * Worker's note: 79 diff with a divs row "func_L01_0033EC00 2 2" (91 without): 10-slot effect table D_L01_00278E20 (12-byte records, h4/h6/h8) refilled by a timer: reset block when D_001DD090 (gp) set: clear h8 of 10 records, n = (s32)(D_001DD098 / (D_001DD0D4 * ...
 */
#include "common.h"

/* NTSC-U counterpart of func_L01_0033E0C8 (src/levels/shared/L01_0033E0C8.c) */
/* localdecomp:start func_L01_0033EC00 */
typedef struct { s32 w0; s16 h4; s16 h6; s16 h8; s16 h10; } R_0033EC00;
extern R_0033EC00 D_L01_00278E20[];
extern s32 D_L01_001E1940[];
extern s32 D_L01_001E1944[];
extern s32 D_L01_001E1948[];
extern f32 D_L01_001E194C[];
extern s32 D_001DD090_sda;
extern f32 D_001DD098_sda;
extern s32 D_001DD094_sda;
extern f32 D_001DD0D4_sda;
extern s16 D_001DD0D8_sda;
__asm__(".extern D_001DD090_sda, 4");
__asm__(".extern D_001DD098_sda, 4");
__asm__(".extern D_001DD094_sda, 4");
__asm__(".extern D_001DD0D4_sda, 4");
__asm__(".extern D_001DD0D8_sda, 2");
extern s32 func_00388398(void *);
extern s32 func_003883C8(void *);

void func_L01_0033EC00(void) {
    s32 i;
    s32 n;
    R_0033EC00 *p;

    if (D_001DD090_sda != 0) {
        for (i = 9; i >= 0; i--) {
            D_L01_00278E20[i].h8 = 0;
        }
        D_001DD090_sda = 0;
        D_L01_001E1940[0] = 0;
        n = (s32)(D_001DD098_sda / (D_001DD0D4_sda * 0.016666668f));
        D_L01_001E1948[0] = n;
        D_L01_001E194C[0] = 1.0f / (f32)n;
    }
    if (D_L01_001E1944[0] == 0) {
        if (func_00388398(D_L01_001E1940) != 0) {
            for (p = D_L01_00278E20; p < D_L01_00278E20 + 10; p++) {
                if (p->h8 == 0) {
                    p->h6 = D_001DD0D8_sda;
                    D_L01_001E1940[0] = D_001DD094_sda;
                    p->h8 = 1;
                    p->h4 = *(u16 *)D_L01_001E1948;
                    break;
                }
            }
        }
    }
    for (p = D_L01_00278E20; p < D_L01_00278E20 + 10; p++) {
        if (p->h8 != 0) {
            if (func_003883C8(&p->h4) != 0) {
                p->h8 = 0;
            }
        }
    }
}
/* localdecomp:end func_L01_0033EC00 */

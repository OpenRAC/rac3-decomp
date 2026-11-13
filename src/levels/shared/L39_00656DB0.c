#include "common.h"

/* localdecomp:start func_L39_00656DB0 */
typedef struct {
    u8 p0[0xA0];
    u8 aA0[0x1A14 - 0xA0];
    u8 b1A14;
    u8 p1A15[0x24C9 - 0x1A15];
    u8 b24C9;
    u8 p24CA[0x2548 - 0x24CA];
    s32 w2548;
} O_00656DB0;
typedef struct {
    u8 p0[0x200];
    s32 w200;
    s32 w204;
    s32 w208;
} S_00656DB0;
extern O_00656DB0 *D_L39_0024CE20[2];
__asm__(".extern D_L39_0024CE20, 16");
extern S_00656DB0 D_L39_00352940;
extern f32 func_L01_0040E548(void *, void *);

void func_L39_00656DB0(O_00656DB0 *o) {
    s32 i;
    s32 a = 0;
    s32 flag = 0;
    for (i = 0; i < 8; i++) {
        O_00656DB0 *p = D_L39_0024CE20[i];
        f32 d;
        if (p == 0) {
            continue;
        }
        if (p != o) {
            d = func_L01_0040E548(&o->aA0[0], &p->aA0[0]);
            if (D_L39_0024CE20[i]->w2548 != o->w2548) {
                if (p->b1A14 != 0 && p->b24C9 == 0 && d < 5.0625f) {
                    D_L39_00352940.w204++;
                } else if (o->b1A14 != 0 && o->b24C9 == 0 && d < 2.25f) {
                    D_L39_00352940.w200++;
                    flag = 1;
                }
            } else if (d < 6.25f) {
                a++;
            }
        }
    }
    if (flag != 0 && a > 0) {
        D_L39_00352940.w208++;
    }
}
/* localdecomp:end func_L39_00656DB0 */

INCLUDE_ASM("asm/levels", func_L39_00656F28);

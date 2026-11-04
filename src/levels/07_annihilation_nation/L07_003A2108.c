#include "common.h"

typedef struct R_L07_003A2380 {
    u8 pad0[0x1D0];
    s32 f1D0[8];
    u8 f1F0[8];
    u8 f1F8[8];
    s16 f200[8];
    s16 f210;
    s16 f212;
    s16 f214;
} R_L07_003A2380;
typedef struct Q_L07_003A2380 {
    u8 pad0[0x68];
    R_L07_003A2380 *f68;
} Q_L07_003A2380;

INCLUDE_ASM("asm/levels", func_L07_003A2108);

/* localdecomp:start func_L07_003A2380 */
extern Q_L07_003A2380 *D_L07_001DE330;

s32 func_L07_003A2380(u8 a, s32 b, u8 c, s16 d)
{
    R_L07_003A2380 *r = D_L07_001DE330->f68;

    if (r->f214 < 8) {
        r->f1D0[r->f212] = b;
        r->f1F8[r->f212] = c;
        r->f1F0[r->f212] = a;
        r->f200[r->f212] = d;
        r->f212 = (r->f212 + 1) & 7;
        r->f214++;
        return 1;
    }
    return 0;
}
/* localdecomp:end func_L07_003A2380 */

INCLUDE_ASM("asm/levels", func_L07_003A2408);

INCLUDE_ASM("asm/levels", func_L07_003A2450);

INCLUDE_ASM("asm/levels", func_L07_003A24C8);

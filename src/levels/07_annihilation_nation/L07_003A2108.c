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

/* localdecomp:start func_L07_003A2408 */
s32 func_L07_003A2408(u8 x) {
    if (x < 9) return 0;
    if (x < 17) return 1;
    if (x < 27) return 2;
    if (x < 98) return 3;
    return -1;
}
/* localdecomp:end func_L07_003A2408 */

/* localdecomp:start func_L07_003A2450 */
extern u8 *D_L07_001DE330_003A2450;
extern u8 D_001CCFD0[];
__asm__(".extern D_001CCFD0, 16");

void func_L07_003A2450(void) {
    u8 *m = D_L07_001DE330_003A2450;
    s16 *p = (s16 *)(*(u8 **)(m + 0x68) + 0x20E);
    s32 i;
    u16 *h;

    for (i = 7; i >= 0; i--) {
        *p = 0;
        p--;
    }
    D_L07_001DE330_003A2450[0x20] = 1;
    h = (u16 *)D_001CCFD0;
    if ((u16)(h[0x76 / 2] - 6) >= 2) h[0x76 / 2] = 5;
    if ((u16)(h[0x9E / 2] - 6) >= 2) h[0x9E / 2] = 5;
}
/* localdecomp:end func_L07_003A2450 */

/* localdecomp:start func_L07_003A24C8 */
extern u8 *D_L07_001DE330_003A24C8;
s32 func_L07_003A24C8(void) {
    u8 *m = D_L07_001DE330_003A24C8;
    u8 *p = *(u8 **)(m + 0x68);
    if (m[0x20] == 1 && *(s16 *)(p + 0x214) == 0) {
        return *(u16 *)(m + 0x96);
    }
    return 0;
}
/* localdecomp:end func_L07_003A24C8 */

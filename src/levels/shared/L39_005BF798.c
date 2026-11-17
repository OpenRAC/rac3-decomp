#include "common.h"

/* localdecomp:start func_L39_005BF798 */
extern s32 D_L39_00242910;
__asm__(".extern D_L39_00242910, 16");
extern u8 D_L39_002428F8[] __attribute__((section(".sdata")));
extern s32 D_L39_0024C130[8] __attribute__((section(".sdata")));
__asm__(".extern D_L39_0024C130, 32");
extern s32 D_L39_00241128;
__asm__(".extern D_L39_00241128, 16");
extern s32 D_001D7D10_sda;
extern s32 D_001D7D14_sda;
extern s32 D_001D7D18_sda;
extern s32 D_001D7D1C_sda;

s32 func_L39_005BF798(s32 a, s32 b, s32 c, s32 d, s8 *e) {
    s32 r;
    s32 t;

    if (e != 0) {
        *e = 0;
    }
    r = (D_L39_00242910 == -2) ? 0 : -1;
    if (b == 1 && D_001D7D18_sda >= 8) {
        r = -2;
    }
    t = (a >= 0) ? D_L39_002428F8[a] : 0;
    if (t != 0) {
        r = -3;
    }
    if (r == 0) {
        D_L39_00242910 = a;
        D_001D7D10_sda = c;
        D_001D7D14_sda = d;
        D_001D7D1C_sda = (s32)e;
        if (b == 1) {
            D_L39_0024C130[D_001D7D18_sda++] = D_L39_00241128;
        }
    }
    return r;
}
/* localdecomp:end func_L39_005BF798 */

/* localdecomp:start func_L39_005BF840 */
extern s32 D_L39_00242910;
__asm__(".extern D_L39_00242910, 16");
extern s32 D_L39_0024C130[8] __attribute__((section(".sdata")));
__asm__(".extern D_L39_0024C130, 32");
extern s32 D_001D7D10_sda;
extern s32 D_001D7D14_sda;
extern s32 D_001D7D18_sda;
extern s32 D_001D7D1C_sda;

s32 func_L39_005BF840(s32 a, s32 b) {
    s32 r;

    if (D_L39_00242910 != -2) {
        r = 1;
    } else {
        r = 0;
    }
    if (D_001D7D18_sda == 0) {
        r = 1;
    }
    if (r == 0) {
        D_001D7D10_sda = a;
        D_001D7D14_sda = b;
        D_L39_00242910 = D_L39_0024C130[--D_001D7D18_sda];
        D_001D7D1C_sda = 0;
    }
    return r;
}
/* localdecomp:end func_L39_005BF840 */

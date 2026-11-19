/* PAL near miss (nm/b8-s6): 7 diff words in check.py at level 01. scheduling of the two $gp float loads and the sh 0x7E store in the else branch (retail loads the second float before the first store); level 03+ places not checked. Uses a u8 alias of the entry table (D_L01_001E2A40_003EE7B0) like func_L01_003EC8A0
 */
#include "common.h"
/* localdecomp:start func_L01_003EE7B0 */
__asm__(".extern D_001DF728_sda, 4");
__asm__(".extern D_001DF72C_sda, 4");
extern u8 D_L01_001E2A40_003EE7B0[];
extern s32 D_L01_001D6694;
extern s32 D_L01_001D6690;
extern f32 D_001DF728_sda;
extern f32 D_001DF72C_sda;
void func_L01_003EE7B0(u8 *m) {
    u8 *q;
    u8 *r;
    u8 *e;
    s32 st;
    f32 fa;
    f32 fb;
    q = D_L01_001E2A40_003EE7B0 + *(s32 *)(m + 148) * 1120;
    r = q + 336;
    if (*(s32 *)(r + 252) == *(s16 *)(m + 134) && D_L01_001D6694 == 0 && (D_L01_001D6690 == 0 || D_L01_001D6690 == -2))
        return;
    st = *(s32 *)(r + 252);
    if (st != 4 && st != 81) {
        q[675] = 0;
        fa = D_001DF72C_sda;
        fb = D_001DF728_sda;
        *(s16 *)(m + 126) = 2;
        e = D_L01_001E2A40_003EE7B0 + *(s32 *)(m + 148) * 1120;
        *(f32 *)(e + 712) = fa;
        e = D_L01_001E2A40_003EE7B0 + *(s32 *)(m + 148) * 1120;
        *(f32 *)(e + 696) = fb;
    } else {
        *(s32 *)(q + 1112) = 2;
        *(s16 *)(m + 126) = 4;
    }
}
/* localdecomp:end func_L01_003EE7B0 */

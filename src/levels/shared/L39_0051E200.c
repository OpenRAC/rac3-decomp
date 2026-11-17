#include "common.h"

/* localdecomp:start func_L39_0051E200 */
extern s32 D_L39_0024D48C[];

/* from rac4-decomp's func_004F4E58 */
void func_L39_0051E200(void) {
    s32 i;
    s32 *p;
    i = 0xF;
    p = &D_L39_0024D48C[0];
    do {
        *p = 0;
        i -= 1;
        p -= 1;
    } while (i >= 0);
}
/* localdecomp:end func_L39_0051E200 */

/* localdecomp:start func_L39_0051E230 */
extern s32 D_L39_0024D450[];

s32 func_L39_0051E230(void) {
    s32 i;
    for (i = 0; i < 16; i++) {
        if (D_L39_0024D450[i] == 0) {
            return 0;
        }
    }
    return 1;
}
/* localdecomp:end func_L39_0051E230 */

/* localdecomp:start func_L39_0051E268 */
extern s32 D_L39_0024D490[];
extern s32 D_L39_0024D450[];
extern s32 D_L39_0024D490_b;
void func_L39_0051E268(s32 a0) {
    s32 n = D_L39_0024D490[0];
    s32 i = 0;
    s32 *p = D_L39_0024D450;
    do {
        if (*p == a0) {
            *p = 0;
            n--;
            break;
        }
        i++;
        p++;
    } while (i < 16);
    D_L39_0024D490_b = n;
}
/* localdecomp:end func_L39_0051E268 */

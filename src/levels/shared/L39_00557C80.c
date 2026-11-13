#include "common.h"

/* localdecomp:start func_L39_00557C80 */
extern s32 D_L39_0024D5CC[];

/* from rac4-decomp's func_004F4E58 */
void func_L39_00557C80(void) {
    s32 i;
    s32 *p;
    i = 15;
    p = D_L39_0024D5CC;
    do {
        *p = 0;
        i--;
        p--;
    } while (i >= 0);
}
/* localdecomp:end func_L39_00557C80 */

/* localdecomp:start func_L39_00557CB0 */
extern s32 D_L39_0024D590[];

s32 func_L39_00557CB0(void) {
    s32 i;
    for (i = 0; i < 16; i++) {
        if (D_L39_0024D590[i] == 0) {
            return 0;
        }
    }
    return 1;
}
/* localdecomp:end func_L39_00557CB0 */

/* localdecomp:start func_L39_00557CE8 */
extern int D_L39_0024D590[16];
void func_L39_00557CE8(int arg0) {
    int i;
    for (i = 0; i < 16; i++) {
        if (D_L39_0024D590[i] == arg0) {
            D_L39_0024D590[i] = 0;
            return;
        }
    }
}
/* localdecomp:end func_L39_00557CE8 */

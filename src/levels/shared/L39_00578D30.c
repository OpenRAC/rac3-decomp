#include "common.h"

/* localdecomp:start func_L39_00578D30 */
extern s32 D_L39_0024B840[2];
extern void (*D_L39_002577D0[][16])(s32);

void func_L39_00578D30(s32 a, void (*fn)(s32)) {
    s32 i;
    if (D_L39_0024B840[a] < 16) {
        for (i = 0; i < D_L39_0024B840[a]; i++) {
            if (fn == D_L39_002577D0[a][i]) return;
        }
        {
            s32 n = D_L39_0024B840[a];
            D_L39_0024B840[a] = n + 1;
            D_L39_002577D0[a][n] = fn;
        }
    }
}
/* localdecomp:end func_L39_00578D30 */

/* localdecomp:start func_L39_00578DB8 */
extern s32 D_L39_0024B840[2];
extern void (*D_L39_002577D0[][16])(s32);
/* from rac4-decomp's func_0043A470 */
void func_L39_00578DB8(s32 a) {
    s32 i;
    for (i = 0; i < D_L39_0024B840[a]; i++) D_L39_002577D0[a][i](a);
    D_L39_0024B840[a] = 0;
}
/* localdecomp:end func_L39_00578DB8 */

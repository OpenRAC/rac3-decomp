#include "common.h"

INCLUDE_ASM("asm/levels", func_L39_005DBF90);

INCLUDE_ASM("asm/levels", func_L39_005DC068);

/* localdecomp:start func_L39_005DC140 */
extern u8 D_L39_0024C410[];
extern u8 D_L39_0024C418[];

s32 func_L39_005DC140(s32 a0) {
    s32 r = 0;
    if (D_L39_0024C410[a0] != 0 || D_L39_0024C418[a0] != 0) {
        r = 1;
    }
    return r;
}
/* localdecomp:end func_L39_005DC140 */

INCLUDE_ASM("asm/levels", func_L39_005DC180);

/* localdecomp:start func_L39_005DC248 */
extern u8 D_L39_0024C410[];
void func_L39_005DC248(s32 i, u8 v) {
    D_L39_0024C410[i] = v;
}
/* localdecomp:end func_L39_005DC248 */

/* localdecomp:start func_L39_005DC260 */
extern u8 D_L39_0024C418[];
u8 func_L39_005DC260(s32 i) {
    return D_L39_0024C418[i];
}
/* localdecomp:end func_L39_005DC260 */

/* localdecomp:start func_L39_005DC278 */
extern u8 D_L39_0024C418[];
void func_L39_005DC278(s32 i, u8 v) {
    D_L39_0024C418[i] = v;
}
/* localdecomp:end func_L39_005DC278 */

INCLUDE_ASM("asm/levels", func_L39_005DC290);

INCLUDE_ASM("asm/levels", func_L39_005DC338);

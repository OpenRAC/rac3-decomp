#include "common.h"

/* localdecomp:start func_L39_004F1918 */
s32 func_L39_004F1918(void *arg0) {
    return *(*(s32 **)((u8 *)((*(void **)((u8 *)arg0 + 4))) + 0x10));
}
/* localdecomp:end func_L39_004F1918 */

/* localdecomp:start func_L39_004F1928 */
s32 func_L39_004F1928(void *arg0) {
    return (*(s32 **)((u8 *)((*(void **)((u8 *)arg0 + 4))) + 0x10))[1];
}
/* localdecomp:end func_L39_004F1928 */

/* localdecomp:start func_L39_004F1938 */
extern s32 func_L39_004E0C88(u32);
extern s32 func_L39_004E1160(s32);

s32 func_L39_004F1938(void *arg0) {
    return func_L39_004E1160(func_L39_004E0C88(**(u32 **)((u8 *)arg0 + 8)));
}
/* localdecomp:end func_L39_004F1938 */

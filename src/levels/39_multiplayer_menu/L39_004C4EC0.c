#include "common.h"

/* localdecomp:start func_L39_004C4EC0 */
void func_L39_004C4EC0(void *arg0, s32 arg1) {
    *(s32 *)((u8 *)arg0 + 0xC0) = arg1;
}
/* localdecomp:end func_L39_004C4EC0 */

/* localdecomp:start func_L39_004C4EC8 */
void func_L39_004C4EC8(void *arg0, s32 arg1, s32 arg2) {
    *(s32 *)((u8 *)arg0 + 0xC4) = arg1;
    *(s32 *)((u8 *)arg0 + 0xC8) = arg2;
}
/* localdecomp:end func_L39_004C4EC8 */

LINKER_REMNANT("asm/levels", func_L39_004C4ED8);

/* localdecomp:start func_L39_004C4EE0 */
typedef struct S_004C4EE0 { char pad[0x30]; s32 v; } S_004C4EE0;
s32 func_L39_004C4EE0(S_004C4EE0 *a) { return a->v; }
/* localdecomp:end func_L39_004C4EE0 */

/* localdecomp:start func_L39_004C4EE8 */
s32 func_L39_004C4EE8(void) { return 1; }
/* localdecomp:end func_L39_004C4EE8 */

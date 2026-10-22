#include "common.h"

/* localdecomp:start func_L39_004BB3F0 */
void func_L39_004BB3F0(void *arg0, s32 arg1) {
    *(s32 *)((u8 *)arg0 + 0x14) = (s32) ((*(s32 *)((u8 *)arg0 + 0x14)) | arg1);
}
/* localdecomp:end func_L39_004BB3F0 */

/* localdecomp:start func_L39_004BB400 */
void func_L39_004BB400(void *arg0) {
    *(s32 *)((u8 *)arg0 + 0x14) = (s32) ((*(s32 *)((u8 *)arg0 + 0x14)) | 9);
}
/* localdecomp:end func_L39_004BB400 */

INCLUDE_ASM("asm/levels", func_L39_004BB410);

/* localdecomp:start func_L39_004BB428 */
void func_L39_004BB428(void *arg0) {
    *(s32 *)((u8 *)arg0 + 0x14) = (s32) ((*(s32 *)((u8 *)arg0 + 0x14)) & ~0xF);
}
/* localdecomp:end func_L39_004BB428 */

/* localdecomp:start func_L39_004BB440 */
s32 func_L39_004BB440(void *arg0) {
    return (*(s32 *)((u8 *)arg0 + 0x14)) & 0xF;
}
/* localdecomp:end func_L39_004BB440 */

/* localdecomp:start func_L39_004BB450 */
s32 func_L39_004BB450(void *arg0) {
    return (*(s32 *)((u8 *)arg0 + 0x14)) & 1;
}
/* localdecomp:end func_L39_004BB450 */

/* localdecomp:start func_L39_004BB460 */
s32 func_L39_004BB460(void *arg0) {
    return (*(s32 *)((u8 *)arg0 + 0x14)) & 2;
}
/* localdecomp:end func_L39_004BB460 */

INCLUDE_ASM("asm/levels", func_L39_004BB470);

INCLUDE_ASM("asm/levels", func_L39_004BB490);

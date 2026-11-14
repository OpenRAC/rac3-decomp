#include "common.h"

/* declared by functions of L39_004E5210.c, which this file was cut from */
void func_L39_004EACC8_004EACC8(s32 a0) __asm__("func_L39_004EACC8");
void func_L39_004EACD8_004EACD8(s32 a0) __asm__("func_L39_004EACD8");
void func_L39_004EACE8_004EACE8(s32 a0) __asm__("func_L39_004EACE8");

/* localdecomp:start func_L39_004EC7B8 */
s32 func_L39_004EC7B8(void *arg0) {
    return (*(s32 *)((u8 *)arg0 + 0xC));
}
/* localdecomp:end func_L39_004EC7B8 */

/* localdecomp:start func_L39_004EC7C0 */
s32 func_L39_004EC7C0(void *arg0) {
    return (*(s32 *)((u8 *)arg0 + 0x10));
}
/* localdecomp:end func_L39_004EC7C0 */

/* localdecomp:start func_L39_004EC7C8 */
s32 func_L39_004EC7C8(void *arg0) {
    return (*(s32 *)((u8 *)arg0 + 0xB8));
}
/* localdecomp:end func_L39_004EC7C8 */

LINKER_REMNANT("asm/levels", func_L39_004EC7D0);

/* localdecomp:start func_L39_004EC7D8 */
typedef struct VT_004EC7D8 {
    u8 pad[0x50];
    s32 (*fn)(void *);
} VT_004EC7D8;

s32 func_L39_004EC7D8(void *a0) {
    return (*(VT_004EC7D8 **)((u8 *)a0 + 8))->fn(a0);
}
/* localdecomp:end func_L39_004EC7D8 */

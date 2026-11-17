#include "common.h"

/* localdecomp:start func_L39_00605B20 */
extern s32 func_00194DF8(void);

/* Calls func_00194DF8, then zeroes eight words (offsets 0, 0x30, 0x38, 0x3C, 0x44, 0x50, 0x58,
 * 0x5C) of the given structure. */
void func_L39_00605B20(void *p) {
    func_00194DF8();
    *(s32 *)((u8 *)p + 0x0) = 0;
    *(s32 *)((u8 *)p + 0x30) = 0;
    *(s32 *)((u8 *)p + 0x38) = 0;
    *(s32 *)((u8 *)p + 0x3C) = 0;
    *(s32 *)((u8 *)p + 0x44) = 0;
    *(s32 *)((u8 *)p + 0x50) = 0;
    *(s32 *)((u8 *)p + 0x58) = 0;
    *(s32 *)((u8 *)p + 0x5C) = 0;
}
/* localdecomp:end func_L39_00605B20 */

#include "common.h"

/* NTSC-U version of func_00396390 (frontbin): 130 -> 150 */
/* localdecomp:start func_U_00391B30 */
extern void func_U_0038EFD0(void *);
 
void func_U_00391B30(void *p) {
    *(s32 *)((u8 *)p + 0x7C) = 0x96;
    *(s32 *)((u8 *)p + 0x58) = 0x20;
    *(s32 *)((u8 *)p + 0x5C) = 0x20;
    func_U_0038EFD0(p);
}
/* localdecomp:end func_U_00391B30 */

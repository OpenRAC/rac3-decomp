#include "common.h"

/* localdecomp:start func_L39_006095C8 */
/* Ported from rac4-decomp/src/game/004F0BE8.c. */
void func_L39_006095C8(s32 a) {
    extern void func_12CD60(void);
    extern void func_12CDB0(void);
    func_12CD60();
    *(volatile u32 *)0x1000F590 = *(volatile u32 *)0x1000F520 | 0x10000;
    *(volatile u32 *)0x1000B000 = a;
    *(volatile u32 *)0x1000F590 = *(volatile u32 *)0x1000F520 & ~0x10000;
    func_12CDB0();
}
/* localdecomp:end func_L39_006095C8 */

/* localdecomp:start func_L39_00609638 */
void func_L39_00609638(s32 arg0) {
    extern s32 func_0012CD60(void);
    extern s32 func_0012CDB0(void);
    func_0012CD60();
    *(volatile u32 *)0x1000F590 = *(volatile u32 *)0x1000F520 | 0x10000;
    *(volatile u32 *)0x1000B400 = arg0;
    *(volatile u32 *)0x1000F590 = *(volatile u32 *)0x1000F520 & ~0x10000;
    func_0012CDB0();
}
/* localdecomp:end func_L39_00609638 */

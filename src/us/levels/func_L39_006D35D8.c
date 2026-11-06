#include "common.h"

/* localdecomp:start func_L39_006D35D8 */
extern u16 D_L39_00249E90[];
extern u8 D_00197DA8[];
extern s32 func_0012DCB0(void);
extern long func_00130760(s32, long);
extern s32 func_0017EEA0(void *, void *, s32);
extern void func_001962D8(s32);
extern s32 func_001962E8(void);

s32 func_L39_006D35D8(void *object) {
    u16 buffer[24];
    s32 result = 1;
    s32 value;

    if (*(u8 *)object != 0) {
        buffer[0] = D_L39_00249E90[0];
        *(u8 *)((u8 *)object + 8) = result;
        value = func_0012DCB0();
        *(s32 *)((u8 *)object + 0xC) = (s32)func_00130760(value, 0x24000);
        func_001962D8(func_0017EEA0(buffer, D_00197DA8, 0));
        if (func_001962E8() != 0) {
            result = 0;
        }
    }
    return result;
}
/* localdecomp:end func_L39_006D35D8 */

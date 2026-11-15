#include "common.h"

typedef void (*FnVt_006C7F08)(void *, s32, s32);

/* localdecomp:start func_L39_006C8490 */
extern void func_L39_0068ADC8(void *);
extern void func_L39_0067F168();

void func_L39_006C8490(void *arg0) {
    func_L39_0067F168(arg0);
    func_L39_0068ADC8(arg0);
    *(s32 *)((u8 *)arg0 + 0x380) = -1;
    *(s32 *)((u8 *)arg0 + 0x384) = -1;
    *(s32 *)((u8 *)arg0 + 0x388) = -1;
    *(s32 *)((u8 *)arg0 + 0x38C) = -1;
    *(s32 *)((u8 *)arg0 + 0x398) = -1;
    *(s32 *)((u8 *)arg0 + 0x390) = -1;
    *(s32 *)((u8 *)arg0 + 0x39C) = -1;
    *(s32 *)((u8 *)arg0 + 0x3A0) = -1;
    *(s32 *)((u8 *)arg0 + 0x3A4) = -1;
}
/* localdecomp:end func_L39_006C8490 */

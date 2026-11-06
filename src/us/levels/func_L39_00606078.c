#include "common.h"

/* localdecomp:start func_L39_00606078 */
extern void func_001264E0(s32);
extern s32 func_00126620(s32 *, s32);
extern s32 func_00126600(s32);
extern void func_00194EB8(s32, s32);

void func_L39_00606078(void *object, u8 *buffer, s32 size, s32 offset) {
    s32 descriptor[4];
    s32 job;
    func_001264E0(0);
    descriptor[0] = (s32)buffer;
    descriptor[1] = *(s32 *)((u8 *)object + 0x48);
    descriptor[2] = size;
    descriptor[3] = 0;
    do {
        job = func_00126620(descriptor, 1);
    } while (job == 0);
    while (func_00126600(job) >= 0) {
    }
    func_00194EB8(size, offset);
}
/* localdecomp:end func_L39_00606078 */

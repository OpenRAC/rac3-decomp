#include "common.h"

/* localdecomp:start func_L39_006D06F8 */
extern void func_L39_006CC518(void *);
extern void func_00197008(s32, void *);

void func_L39_006D06F8(s32 *object) {
    u8 buffer[0x100];
    func_L39_006CC518(buffer);
    func_00197008(object[0], buffer);
}
/* localdecomp:end func_L39_006D06F8 */

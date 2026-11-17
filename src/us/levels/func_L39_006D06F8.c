#include "common.h"

/* localdecomp:start func_L39_006D06F8 */
extern void func_L39_006CC518(void *);
extern void func_00197008(s32, void *);

/* Fills a 256-byte buffer with func_L39_006CC518 and passes it with the object's first field to
 * func_00197008. */
void func_L39_006D06F8(s32 *object) {
    u8 buffer[0x100];
    func_L39_006CC518(buffer);
    func_00197008(object[0], buffer);
}
/* localdecomp:end func_L39_006D06F8 */

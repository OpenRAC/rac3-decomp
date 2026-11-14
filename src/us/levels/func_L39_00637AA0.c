#include "common.h"

/* localdecomp:start func_L39_00637AA0 */
extern void func_L39_00637C98(void *, s32, s32, s32, s32);
extern void func_L39_006379A0(void *, s32, s32, s32);

/* Calls func_L39_00637C98 on the object with its byte at +0x37B, 0, 1 and 50, then
 * func_L39_006379A0 with 28, 7, 0. */
void func_L39_00637AA0(u8 *object) {
    func_L39_00637C98(object, object[0x37B], 0, 1, 50);
    func_L39_006379A0(object, 28, 7, 0);
}
/* localdecomp:end func_L39_00637AA0 */

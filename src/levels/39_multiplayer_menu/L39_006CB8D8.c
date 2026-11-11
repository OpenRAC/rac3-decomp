#include "common.h"

/* localdecomp:start func_L39_006CB8D8 */
extern void func_L39_00688460(void *, void *, void *, void *, void *, void *, f32, f32, f32, f32, f32);

void func_L39_006CB8D8(void *object)
{
    u8 buf[16];

    func_L39_00688460(object, buf, buf, buf, buf, buf, 0.6f, 0.5f, 1.0f, 1.0f, 1.5f);
}
/* localdecomp:end func_L39_006CB8D8 */

INCLUDE_ASM("asm/levels", func_L39_006CB930);

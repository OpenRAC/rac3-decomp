#include "common.h"

/* declared by functions of L39_006C99F0.c, which this file was cut from */
s32 func_L39_00688340(s32, s32, s32);
extern s32 *D_L39_0024D760;
extern u8 *D_L39_00247914;

/* localdecomp:start func_L39_006CA268 */
/* pattern from L39_0068DDC8.c: scalar pointer with .extern size hint */
__asm__(".extern D_L39_0024D760, 16");
extern s32 *D_L39_0024D760;
extern void func_L39_006D0078(void *);

s32 func_L39_006CA268(u8 *arg0)
{
    func_L39_006D0078((void *)D_L39_0024D760[0x38 / 4]);
    arg0[0x2A8] = 1;
    return 1;
}
/* localdecomp:end func_L39_006CA268 */

LINKER_REMNANT("asm/levels", func_L39_006CA2A8);

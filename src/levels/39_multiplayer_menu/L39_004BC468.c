#include "common.h"

/* declared by functions of L39_004BB4C0.c, which this file was cut from */
extern s32 (*D_L39_00443494[])(void);
extern s32 func_L39_004BC6C8(s32, s32, s32, s32, s32);

/* localdecomp:start func_L39_004BC468 */
__asm__(".extern D_L39_00443494, 16");
extern s32 (*D_L39_00443494[])(void);
extern s32 func_L39_004BC6C8(s32, s32, s32, s32, s32);

/* from rac4-decomp's func_L00_004F8268 */
s32 func_L39_004BC468(void) {
    if (D_L39_00443494[0] != 0) {
        return D_L39_00443494[0]();
    }
    func_L39_004BC6C8(26, 108, 14, 0, 0);
    return 0;
}
/* localdecomp:end func_L39_004BC468 */

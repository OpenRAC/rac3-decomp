#include "common.h"

/* NTSC-U counterpart of func_L39_006E0D90 (src/levels/39_multiplayer_menu/L39_006E0D90.c) */
/* localdecomp:start func_L39_006DE230 */
__asm__(".extern D_L39_0024A1D0, 16");
extern void *D_L39_0024A1D0;
extern f32 D_001A6BC4[];

f32 func_L39_006DE230(f32 arg0, f32 arg1, f32 arg2) {
    f32 (*temp_v0)(f32) = (f32 (*)(f32))D_L39_0024A1D0;
    f32 temp_f0;

    temp_f0 = temp_v0(arg2);
    return (-temp_f0) * (arg0 - arg1) / D_001A6BC4[0];
}
/* localdecomp:end func_L39_006DE230 */

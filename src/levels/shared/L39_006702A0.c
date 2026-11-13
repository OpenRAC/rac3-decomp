#include "common.h"

/* localdecomp:start func_L39_006702A0 */
typedef struct { u8 pad[0x1A8]; s32 f1A8; } S_006702A0;

extern s32 D_L39_0024BD18;
extern s32 D_L39_0024CFA0;
extern S_006702A0 D_L39_00352940;
extern char D_L39_00352B58[][0x30];
extern s32 func_00120884(char *);
extern void func_0038E7E8(f32, f32, unsigned long, char *, s32, f32, f32, s32, s32, unsigned long, f32, f32);

s32 func_L39_006702A0(void) {
    s32 i;
    if (D_L39_0024BD18 != 0) {
        return 0;
    }
    for (i = 0; i < D_L39_0024CFA0; i++) {
        f32 y = 0x186 - (D_L39_00352940.f1A8 + i) * 15;
        func_0038E7E8(15.0f, y, 0xB080FFFF, D_L39_00352B58[i], func_00120884(D_L39_00352B58[i]), 1.0f, 1.0f, 0, 0, 0x80000000, 0.0f, 0.0f);
    }
    return 0;
}
/* localdecomp:end func_L39_006702A0 */

INCLUDE_ASM("asm/levels", func_L39_006703B0);

INCLUDE_ASM("asm/levels", func_L39_00670438);

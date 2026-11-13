#include "common.h"

/* localdecomp:start func_L39_006B0FA8 */
typedef struct { u8 pad[0x10]; s32 a; s32 b; } S_006B0FA8;
extern s32 D_L39_00241128;
__asm__(".extern D_L39_00241128, 16");
extern s32 D_L39_00242910;
__asm__(".extern D_L39_00242910, 16");
extern s32 D_L39_0024BB44;
__asm__(".extern D_L39_0024BB44, 16");
extern s32 D_001DD730_sda;
extern S_006B0FA8 D_L39_003D2880[];
extern void func_L01_00516470(s32, f32, f32);
extern void func_L39_0068B058(void *);

void func_L39_006B0FA8(void *a0) {
    if (D_L39_00241128 == 12) {
        if (D_L39_00242910 == -2) {
            S_006B0FA8 *p = D_L39_003D2880;
            f32 n = D_001DD730_sda;
            f32 t = (f32)(D_L39_0024BB44 % D_001DD730_sda) / n;
            t = t + t;
            func_L01_00516470(p->a, t + 0.0f, 0.5f);
            func_L01_00516470(p->b, t + -2.0f, 0.5f);
        }
    }
    func_L39_0068B058(a0);
}
/* localdecomp:end func_L39_006B0FA8 */

LINKER_REMNANT("asm/levels", func_L39_006B1078);

INCLUDE_ASM("asm/levels", func_L39_006B1080);

LINKER_REMNANT("asm/levels", func_L39_006B15A0);

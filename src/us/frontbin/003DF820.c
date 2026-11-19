#include "common.h"

/* NTSC-U version of func_003E4D70 (frontbin): 0.13 -> 0.1335 */
#include "common.h"





extern u8 D_U_001D959D;
extern u8 D_U_001D959C;
extern s32 func_U_0038E1E0(void);
extern s32 func_U_003E2B98(s32, s32, s32);
extern s32 func_U_003E1E50(s32, f32, f32);
extern s32 func_U_003E2C88(s32, f32, f32);
/* localdecomp:start func_U_003DF820 */
__asm__(".extern D_U_001D959D, 1");
__asm__(".extern D_U_001D959C, 1");
typedef struct { u8 p0[0x20]; u8 x20; } S_003E4D70;
extern S_003E4D70 D_00142CA0_003E4D70;
void func_U_003DF820(s32 arg0) {
    S_003E4D70 *g = &D_00142CA0_003E4D70;
    s32 a, b;
    D_U_001D959C = (g->x20 != D_U_001D959D);
    if (D_U_001D959C) {
        a = g->x20 ? 0x8E : 0x8C;
        b = g->x20 ? 0x8F : 0x8D;
        D_U_001D959D = g->x20 != 0;
        func_U_003E2B98(0x90002, func_U_0038E1E0(), a);
        func_U_003E2B98(0x90001, func_U_0038E1E0(), b);
        func_U_003E1E50(0x9000C, g->x20 ? 0.4025f : 0.4285f, 0.1315f);
        func_U_003E2C88(0x9000C, 0.6f, 0.6f);
        func_U_003E1E50(0x90007, g->x20 ? 0.4394f : 0.464136f, 0.133499995f);
    }
}
/* localdecomp:end func_U_003DF820 */

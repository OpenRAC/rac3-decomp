#include "common.h"

/* NTSC-U version of func_003E5128 (boot_elf): 0.13 -> 0.1335 */
#include "common.h"





typedef struct { u8 pad[0x20]; u8 x20; } F_3DE8F0;
extern F_3DE8F0 D_142CA0[];
extern s32 func_U_003E7610(s32, f32, f32);
extern s32 func_U_003E8448(s32, f32, f32);
extern u8 D_U_001D959D;
extern u8 D_U_001D959C;
extern s32 func_U_00392D38(void);
extern s32 func_U_003E8358(s32, s32, s32);
extern u8 D_U_001D959D;
extern u8 D_U_001D959C;
extern s32 func_U_00392D38(void);
extern s32 func_U_003E8358(s32, s32, s32);
extern s32 func_U_003E7610(s32, f32, f32);
extern s32 func_U_003E8448(s32, f32, f32);
/* localdecomp:start func_U_003E4FE0 */
__asm__(".extern D_U_001D959D, 1");
__asm__(".extern D_U_001D959C, 1");
void func_U_003E4FE0(s32 arg0) {
    F_3DE8F0 *g = D_142CA0;
    s32 a, b;
    D_U_001D959C = (g->x20 != D_U_001D959D);
    if (D_U_001D959C) {
        a = g->x20 ? 0x8E : 0x8C;
        b = g->x20 ? 0x8F : 0x8D;
        D_U_001D959D = g->x20 != 0;
        func_U_003E8358(0x90002, func_U_00392D38(), a);
        func_U_003E8358(0x90001, func_U_00392D38(), b);
        func_U_003E7610(0x9000C, g->x20 ? 0.4025f : 0.4285f, 0.1315f);
        func_U_003E8448(0x9000C, 0.6f, 0.6f);
        func_U_003E7610(0x90007, g->x20 ? 0.4394f : 0.464136f, 0.133499995f);
    }
}
/* localdecomp:end func_U_003E4FE0 */

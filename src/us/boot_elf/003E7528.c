#include "common.h"

/* NTSC-U counterpart of func_003E7670 (boot_elf). */
extern f32 D_U_001D96D8;
extern f32 D_U_001D96DC;
extern f32 D_U_001D96E0;
extern f32 D_U_001D96E4;
__asm__(".extern D_U_001D96D8, 4");
__asm__(".extern D_U_001D96DC, 4");
__asm__(".extern D_U_001D96E0, 4");
__asm__(".extern D_U_001D96E4, 4");

/* localdecomp:start func_U_003E7528 */
__asm__(".extern D_U_001D96C8, 4");
__asm__(".extern D_U_001D96CC, 4");
__asm__(".extern D_U_001D96D0, 4");
__asm__(".extern D_U_001D96D4, 4");
__asm__(".extern D_U_001D96F0, 4");
__asm__(".extern D_U_001D96F4, 4");
extern f32 D_U_001D96C8;
extern f32 D_U_001D96CC;
extern s32 D_U_001D96D0;
extern s32 D_U_001D96D4;
extern f32 D_U_001D96F0;
extern f32 D_U_001D96F4;
extern void func_U_003E74D8(void);
extern void func_U_00390FA8(f32 *, f32 *, s32);
void func_U_003E7528(s32 mode) {
    f32 v[2];
    D_U_001D96C8 = 1.0f;
    D_U_001D96CC = 1.0f;
    D_U_001D96D0 = 0;
    D_U_001D96D4 = 0;
    D_U_001D96D8 = 512.0f;
    switch (mode) {
    case 0:
        D_U_001D96E0 = 512.0f;
        D_U_001D96DC = 416.0f;
        D_U_001D96E4 = 416.0f;
        break;
    case 1:
        D_U_001D96E0 = 512.0f;
        D_U_001D96DC = 448.0f;
        D_U_001D96E4 = 448.0f;
        break;
    }
    func_U_003E74D8();
    v[1] = v[0] = 0.0f;
    func_U_00390FA8(&v[0], &v[1], 1);
    D_U_001D96F0 = v[0] / D_U_001D96DC;
    D_U_001D96F4 = (v[1] + v[0] * 0.5f) / D_U_001D96DC;
}
/* localdecomp:end func_U_003E7528 */

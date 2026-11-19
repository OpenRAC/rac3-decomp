/* functional: high. Compiles in context and differs from retail in 5 words (v0 vs v1 register for the counter decrement and the byte store); behaviour identical. */
#include "common.h"
extern f32 func_0038D098(f32);
extern s32 func_0038DBD8(s32, s32, f32);
extern void func_L01_00516AA0(s32, s32, s32);
extern void func_L01_005170B8(s32, s32);
extern void func_L01_0047BB98(void);
__asm__(".extern D_L01_001D80C8, 4");
__asm__(".extern D_L01_001D80CC, 1");
__asm__(".extern D_L01_001D80E4, 4");
extern s32 D_L01_001D80C8;
extern u8 D_L01_001D80CC;
extern f32 D_L01_001D80E4;
void func_L01_0047C278(void) {
    s32 count = D_L01_001D80C8;
    if (count != 0) {
        f32 t = D_L01_001D80E4;
        f32 u;
        s32 color;
        if (1.0f < t) {
            u = 2.0f - t;
        } else {
            u = t;
        }
        color = func_0038DBD8(0x8066CCFF, 0x60202080, (1.0f - func_0038D098(u * 3.1415927f)) * 0.5f);
        func_L01_005170B8(0x20003, color);
        D_L01_001D80C8 = D_L01_001D80C8 - 1;
    } else {
        func_L01_00516AA0(0x20000, 1, 0);
        D_L01_001D80CC = 1;
    }
    func_L01_0047BB98();
}

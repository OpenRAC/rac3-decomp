/* functional: high. Draft diff is nop placement after div.s (divs_nops) and scheduling only; args (0,u152,0,u150,color) verified */
#include "common.h"

extern G391938B D_001CFEC0;
extern void func_0038AF30(s32, s32, s32, s32, s32);
extern f32 func_L01_004451A8(f32 f12);
extern void func_L01_00391EC8(void *);
void func_L01_00391F98(u8 *a0) {
    s32 n = *(s32 *)(*(u8 **)(a0 + 0x68) + 4);

    if (n >= 0x58) {
        f32 t = func_L01_004451A8((f32)(n - 0x57) / 12.0f);

        func_0038AF30(0, D_001CFEC0.unk152, 0, D_001CFEC0.unk150, ((s32)(t * 128.0f) << 24) | 0xFFFFFF);
    }
    func_L01_00391EC8(a0);
}

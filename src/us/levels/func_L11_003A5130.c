#include "common.h"

/* NTSC-U counterpart of func_L11_003A6CE0 (src/levels/11_obani_moons/L11_003A6B78.c) */
#include "vu0.h"

/* localdecomp:start func_L11_003A5130 */
__asm__(".extern D_L11_001D66B0_003A5130, 16");
extern u8 D_L11_001D66B0_003A5130;
extern u8 D_001A30B0[];
extern u16 D_001A8C40[];
extern s32 func_L01_004A6D20(void *, s32);
extern s32 func_0039FE80(s32, s32, void *);
extern void func_0037E2F0(void *, f32, f32);
extern u8 *func_L01_00467DA8(void *, s32, f32, f32, s32, s32, s32, void *, f32, s32);
extern s32 func_L01_00452F60(void *);

void func_L11_003A5130(u8 *a0)
{
    s32 *v = *(s32 **)(a0 + 0x68);
    vu0_v4 p;
    s32 idx;
    u8 *e;
    s32 t;

    if (func_L01_004A6D20(a0, v[1]) == 0) {
        idx = v[1];
        if (idx == -1) {
            goto spawn;
        }
        e = D_001A30B0 + (idx << 7);
        if (*(u8 **)(e + 0xDC) != a0 || e[0xD0] == 0) {
spawn:
            v[1] = func_0039FE80(0, 4, a0);
        }
    }
    t = *(u16 *)(a0 + 0x96) + 1;
    *(u16 *)(a0 + 0x96) = t;
    if ((u16)t >= 10) {
        func_0037E2F0(&p, 3.0f, 3.0f);
        vec_add_ba(&p, a0 + 0x10, &p);
        func_L01_00467DA8(&p, 0x28, 6.0f, 0.0f, 0xFFFF0707, 0, 3, &D_L11_001D66B0_003A5130, 0.0f, 0);
        func_L01_00467DA8(&p, 0x28, 3.0f, 0.0f, 0x9F7F7F7F, 0, -3, &D_L11_001D66B0_003A5130, 0.0f, 0);
        *(u16 *)(a0 + 0x96) = 0;
    }
    if (func_L01_00452F60(a0) != 0) {
        D_001A8C40[0] = 0xFFFF;
    }
}
/* localdecomp:end func_L11_003A5130 */

/* NTSC-U draft (2026-11-14, Claude worker): C of func_L39_00675390, the NTSC-U twin of func_L39_00677D78, with NTSC-U names
 * and addresses. Near miss on NTSC-U: 5 words differ with its file's flags.
 */
#include "common.h"

/* localdecomp:start func_L39_00675390 */
extern s32 func_003B8A20(void);
extern s32 func_00388398(void *);
extern void func_003B8B10(f32);

extern s32 D_L39_0024040C[];
typedef struct { s32 state; s32 timer; s32 p8; s32 pC; s32 p10; f32 f; } St_675390;
extern St_675390 D_L39_0024D128;
extern s32 D_L39_00352DF0[];
extern s32 D_L39_0024D12C[];
extern s32 D_001E1898_sda;
__asm__(".extern D_001E1898_sda, 4");

s32 func_L39_00675390(s32 arg0) {
    s32 ret = 0;
    if (func_003B8A20()) {
        D_L39_0024040C[0] = 0;
    }
    switch (D_001E1898_sda) {
    case 0:
        if (func_00388398(D_L39_0024D12C)) {
            D_L39_0024D128.state = 1;
            D_L39_0024D128.timer = 0x5A;
        } else {
            D_L39_0024D128.f = (f32)D_L39_0024D128.timer / 90.0f;
        }
        break;
    case 1:
        if (func_00388398(D_L39_0024D12C)) {
            D_L39_0024D128.state = 2;
            D_L39_0024D128.timer = 0x1E;
        }
        D_L39_0024D128.f = 0.0f;
        break;
    case 2:
        ret = func_00388398(D_L39_0024D12C) ? arg0 : 0;
        D_L39_0024D128.f = 1.0f - (f32)D_L39_00352DF0[0] / 30.0f;
        break;
    }
    func_003B8B10(0.0f);
    return ret;
}
/* localdecomp:end func_L39_00675390 */

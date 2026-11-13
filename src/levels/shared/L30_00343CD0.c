#include "common.h"

/* declared by functions of L30_00343398.c, which this file was cut from */
extern u8 D_001A4C60[];

/* localdecomp:start func_L30_00343CD0 */
typedef struct {
    f32 x, y, z, w;
} __attribute__((aligned(16))) V4_00343CD0;

extern u8 D_001A4C60[];

extern void func_L30_00343660(u8 *);
extern void func_L30_00343AC8(u8 *, V4_00343CD0 *, f32 *, f32 *);
extern void func_003C6990(void *, void *, s32);
extern s32 func_L05_00328FF8(u8 *);

void func_L30_00343CD0(u8 *moby) {
    u8 *vars = *(u8 **)(moby + 0x68);
    V4_00343CD0 pos;
    f32 a;
    f32 b;

    func_L30_00343660(moby);
    func_L30_00343AC8(moby, &pos, &a, &b);
    if (vars[0x1B0] == 0 && moby[0x20] != 8 && moby[0x20] != 10) {
        *(V4_00343CD0 *)(vars + 0x80) = pos;
        func_003C6990(moby, vars + 0x70, 0);
    }
    if (vars[0x1B1] != 0 && *(s32 *)(vars + 0x19C) == 0) {
        if (func_L05_00328FF8(moby) != 0) {
            *(s32 *)(vars + 0x19C) = 1;
        }
    }
    if (vars[0x1B3] == 0 && *(f32 *)(vars + 0x130) + a > *(f32 *)D_001A4C60) {
        *(s32 *)(vars + 0x6C) &= ~1;
    } else if (vars[0x1B4] == 0 && *(f32 *)(vars + 0x130) - a < *(f32 *)D_001A4C60) {
        *(s32 *)(vars + 0x6C) &= ~1;
    } else {
        *(s32 *)(vars + 0x6C) |= 1;
    }
    vars[0x1B8] = func_L05_00328FF8(moby);
}
/* localdecomp:end func_L30_00343CD0 */

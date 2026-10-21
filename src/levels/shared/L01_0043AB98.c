#include "common.h"

/* localdecomp:start func_L01_0043AB98 */
typedef struct {
    f32 v[4];
} __attribute__((aligned(16))) Vec4;

extern s32 D_001A71A0[];
extern f32 D_L01_001E0070[];
extern void func_L01_0043BA48(s32, Vec4 *);
extern f32 func_0038D160(f32, f32);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);

void func_L01_0043AB98(void)
{
    Vec4 dir;
    f32 angle;

    func_L01_0043BA48(D_001A71A0[0], &dir);
    angle = func_0038D160(dir.v[0], dir.v[1]);
    D_L01_001E0070[0] = func_0038D098(angle) * 0.14f;
    D_L01_001E0070[1] = func_0038D0B0(angle) * 0.14f;
    D_L01_001E0070[2] = -0.99f;
}
/* localdecomp:end func_L01_0043AB98 */

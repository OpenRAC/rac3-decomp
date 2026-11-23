/* functional: high. Same result as retail; COP2 vsub via inline asm, scheduling differs. */
#include "common.h"
/* localdecomp:start func_L07_003C9528 */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) Vec_003C9528;
typedef struct { s32 count; u8 pad[12]; Vec_003C9528 points[1]; } Path_003C9528;
typedef struct {
    u8 pad[0xC4];
    Path_003C9528 *path;
    s16 index;
    s16 backwards;
} Control_003C9528;

f32 func_L07_003C9528(u8 *moby) {
    extern f32 func_0038CEA8(Vec_003C9528 *);
    extern f32 func_0038CE68(Vec_003C9528 *, Vec_003C9528 *);
    Control_003C9528 *control = (Control_003C9528 *)(*(u8 **)(moby + 0x68) + 0x150);
    Path_003C9528 *path = control->path;
    s16 first, last;
    Vec_003C9528 direction, offset;
    f32 length, t;
    if (path == 0) return -1.0f;
    if (control->backwards == 0) {
        if (control->index >= path->count - 1) return 1.0f;
        first = control->index;
        last = control->index + 1;
    } else {
        if (control->index <= 0) return 0.0f;
        last = control->index;
        first = control->index - 1;
    }
    __asm__(
        "lqc2 $vf2, %2\n\t"
        "lqc2 $vf1, %1\n\t"
        "vsub.xyz $vf1, $vf1, $vf2\n\t"
        "sqc2 $vf1, %0"
        : "=m"(direction) : "m"(path->points[last]), "m"(path->points[first]) : "vf1", "vf2");
    length = func_0038CEA8(&direction);
    func_0038CF68(&direction, &direction, 1.0f);
    __asm__(
        "lqc2 $vf1, %1\n\t"
        "lqc2 $vf2, %2\n\t"
        "vsub.xyz $vf1, $vf1, $vf2\n\t"
        "sqc2 $vf1, %0"
        : "=m"(offset) : "m"(*(Vec_003C9528 *)(moby + 0x10)), "m"(path->points[first]) : "vf1", "vf2");
    t = func_0038CE68(&direction, &offset) / length;
    if (t > 1.0f) t = 1.0f;
    else if (t < 0.0f) t = 0.0f;
    return ((f32)first + t) / (f32)(path->count - 1);
}
/* localdecomp:end func_L07_003C9528 */

/* PAL near miss (Claude wave S/pal): flags: byte-exact only with "-mvu0-use-vf0-vf2 added to the file line" (its file's line: "-mvu0-use-vf0-vf2 -O2 -G8 -fopt-stack -mno-check-zero-division @ps2as").
 * Worker's note: byte-exact with -mvu0-use-vf0-vf2 only (vec_sub_ba + vec_add_ba from vu0.h, path lerp); L07_003C7468.c line has @ps2as but no vu0 flag. C in near/
 */
#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L07_003C96C0 */
typedef int Quad_003C96C0 __attribute__((mode(TI)));
typedef struct Path_003C96C0 {
    s32 count;
    u8 pad04[0xC];
    Quad_003C96C0 pts[1];
} Path_003C96C0;

extern void func_0038CE20(void *, void *, f32);

void func_L07_003C96C0(Path_003C96C0 *path, Quad_003C96C0 *out, f32 t) {
    vu0_v4 d;
    s32 i = (u8)(s32)t;

    if (i >= path->count - 1) {
        *out = *(Quad_003C96C0 *)((u8 *)path + path->count * 16);
    } else {
        vec_sub_ba(&d, &path->pts[(u8)(i + 1)], &path->pts[i]);
        func_0038CE20(&d, &d, t - (f32)i);
        vec_add_ba(out, &path->pts[i], &d);
    }
}
/* localdecomp:end func_L07_003C96C0 */

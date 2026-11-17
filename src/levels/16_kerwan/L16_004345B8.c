#include "common.h"

/* localdecomp:start func_L16_004345B8 */
#include "vu0.h"
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_004345B8;
extern f32 func_003824E0(f32, f32);
extern void func_0038CF68(V4_004345B8 *out, V4_004345B8 *v, f32 r);
extern void func_003C4C18(f32 *v, f32 r);
extern void *func_L01_003AEA58(void *, void *, void *, s32, f32);
extern void *func_L01_003CD878(void *, void *, void *, s32, s32, f32);
extern s32 func_00382468(s32);
extern s32 func_L01_004AAC98(s32, s32, void *, s32);

void func_L16_004345B8(void *self, V4_004345B8 off, V4_004345B8 a, V4_004345B8 b, s32 kind) {
    V4_004345B8 pos;
    V4_004345B8 r;
    V4_004345B8 dir;
    void *p;

    r.x = func_003824E0(a.x, b.x);
    r.y = func_003824E0(a.y, b.y);
    r.z = func_003824E0(a.z, b.z);
    dir = r;
    func_0038CF68(&dir, &dir, -0.6f);
    func_003C4C18(&dir.x, 0.3f);
    vec_add_ba(&pos, (u8 *)self + 0x10, &r);
    vec_add_ab(&pos, &pos, &off);
    if (kind == 3) {
        p = func_L01_003AEA58(0, &dir, &pos, 0, 0.0f);
    } else {
        p = func_L01_003CD878(0, &pos, &dir, 0, 200, 0.0f);
    }
    if (p != 0 && func_00382468(2) == 0) {
        func_L01_004AAC98(0, 0, p, 0x1F7C);
    }
}
/* localdecomp:end func_L16_004345B8 */

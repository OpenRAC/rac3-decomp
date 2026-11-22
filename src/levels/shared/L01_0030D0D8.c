#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L01_0030D0D8 */
typedef struct {
    f32 v[4];
    s32 w16;
    f32 f20;
    s32 w24;
    s32 w28;
    f32 f32_;
    s32 w36;
    f32 f40;
    f32 f44;
} S_0030CD20;
extern S_0030CD20 *D_L01_001E1720;
__asm__(".extern D_L01_001E1720, 16");
void func_L01_0030D0D8(s32 owner) {
    extern f32 func_003824E0(f32, f32);
    extern s32 func_0038CAD0(void *);
    extern s32 func_00382498(s32, s32);
    extern s32 func_0013D3E0(void);
    extern void func_0038CF68(S_0030CD20 *, S_0030CD20 *, f32);
    S_0030CD20 *p;
    s32 i, timer;
    for (i = 0; i < 64; i++) {
        p = (S_0030CD20 *)(i * 48 + (s32)D_L01_001E1720);
        if (p->w16 != owner) continue;
        p->f32_ -= func_003824E0(0.01f, 0.075f);
        if (p->f32_ <= -8.0f) {
            p->f32_ += 8.0f;
        }
        if (func_0038CAD0(&p->w24)) {
            p->v[0] = func_003824E0(-1.0f, 1.0f);
            p->v[1] = func_003824E0(-1.0f, 1.0f);
            p->v[2] = func_003824E0(-1.0f, 1.0f);
            p->w36 = 0;
            timer = func_00382498(20, 50);
            p->w24 = timer;
            p->w28 = timer;
            p->f40 = (func_0013D3E0() & 1) ? -1.0f : 1.0f;
            p->f44 = 1.0f;
            func_0038CF68(p, p, 1.0f);
            p->f20 = func_003824E0(0.7f, 0.9f);
        }
    }
}
/* localdecomp:end func_L01_0030D0D8 */

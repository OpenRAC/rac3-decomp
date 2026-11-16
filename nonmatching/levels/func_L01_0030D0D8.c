/* PAL near miss (Codex wave 8): near miss: 47 words differ with the file's flags.
 * Worker's note: Best 47 diff: build/codex/w415/func_L01_0030D0D8.04.log; loop counter allocation, float/argument hoisting and branch scheduling; .06/.08/.09 gave identical 50-diff instruction listings, stopped at 9 checks; retained out/func_L01_0030D0D8.near.c
 */
#include "common.h"
/* localdecomp:start func_L01_0030D0D8 */
extern S_0030CD20 *D_L01_001E1720;
__asm__(".extern D_L01_001E1720, 16");
void func_L01_0030D0D8(s32 owner) {
    extern f32 func_003824E0(f32, f32);
    extern s32 func_0038CAD0(void *);
    extern s32 func_00382498(s32, s32);
    extern s32 func_0013D3E0(void);
    extern void func_0038CF68(S_0030CD20 *, S_0030CD20 *, f32);
    S_0030CD20 *p;
    s32 i, timer, next;
    f32 scroll;
    i = 0;
    do {
        next = i + 1;
        p = (S_0030CD20 *)(i * 48 + (s32)D_L01_001E1720);
        if (p->w16 == owner) {
        scroll = func_003824E0(0.01f, 0.075f);
        scroll = p->f32_ - scroll;
        p->f32_ = scroll;
        if (scroll <= -8.0f) {
            f32 eight = 8.0f;
            p->f32_ = scroll + eight;
        }
        if (func_0038CAD0(&p->w24)) {
            f32 one = 1.0f;
            p->v[0] = func_003824E0(-1.0f, one);
            p->v[1] = func_003824E0(-1.0f, one);
            p->v[2] = func_003824E0(-1.0f, one);
            p->w36 = 0;
            timer = func_00382498(20, 50);
            p->w24 = timer;
            p->w28 = timer;
            p->f40 = (func_0013D3E0() & 1) ? -1.0f : 1.0f;
            p->f44 = one;
            func_0038CF68(p, p, one);
            p->f20 = func_003824E0(0.7f, 0.9f);
        }
        }
        i = next;
    } while (i < 64);
}
/* localdecomp:end func_L01_0030D0D8 */

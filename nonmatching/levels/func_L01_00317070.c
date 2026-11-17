/* PAL near miss (Codex wave 6): near miss: 73 words differ with the file's flags.
 * Worker's note: 4 diff: independent VU0 loads/store order at 0xAC/0xC0/0xC8/0xD0; three wordings unchanged; best log build/codex/w328/func_L01_00317070.03.log; tested injected divs row 'func_L01_00317070 2' leaves 4 diff (no MATCH)
 */
#include "common.h"
/* localdecomp:start func_L01_00317070 */
#include "vu0.h"
void func_L01_00317070(void *obj, vu0_v4 *a, vu0_v4 *b, u8 *shape) {
    extern void func_L01_00316DA0(vu0_v4 *, vu0_v4 *, vu0_v4 *, f32);
    extern void func_L01_00316E38(vu0_v4 *, vu0_v4 *, vu0_v4 *, vu0_v4 *, vu0_v4 *, f32);
    extern f32 func_003824E0(f32, f32);
    extern void func_0038CF68(vu0_v4 *, vu0_v4 *, f32);
    extern void func_L01_00317440(void *, s32, vu0_v4 *, s32);
    vu0_v4 points[11];
    vu0_v4 c, d, noise, tmp;
    s32 i;
    f32 t;
    vu0_q av, bv;
    for (i = 0; i < 10; i++) {
        t = (f32)i / 9.0f;
        func_L01_00316DA0(&points[i], a, b, t);
        *(vu0_q *)&c = *(vu0_q *)(shape + 0x50);
        *(vu0_q *)&d = *(vu0_q *)(shape + 0x60);
        __asm__("lqc2 %0, %1" : "=j"(av) : "m"(*a));
        __asm__("lqc2 %0, %1" : "=j"(bv) : "m"(*b));
        __asm__("sqc2 %1, %0" : "=m"(tmp) : "j"(bv));
        __asm__("lqc2 %0, %1" : "=j"(bv) : "m"(c));
        __asm__("vadd.xyz %0, %0, %1" : "+j"(bv) : "j"(av));
        __asm__("sqc2 %1, %0" : "=m"(c) : "j"(bv));
        __asm__("lqc2 %0, %1" : "=j"(av) : "m"(tmp));
        __asm__("lqc2 %0, %1" : "=j"(bv) : "m"(d));
        __asm__("vadd.xyz %0, %0, %1" : "+j"(bv) : "j"(av));
        __asm__("sqc2 %1, %0" : "=m"(d) : "j"(bv));
        func_L01_00316E38(&points[i], a, b, &c, &d, t);
        noise.w = 0.0f;
        noise.x = func_003824E0(-1.0f, 1.0f);
        noise.y = func_003824E0(-1.0f, 1.0f);
        noise.z = func_003824E0(-1.0f, 1.0f);
        func_0038CF68(&noise, &noise, 0.04f);
        vec_add_ab(&points[i], &points[i], &noise);
    }
    func_L01_00317440(obj, 128, points, 11);
}
/* localdecomp:end func_L01_00317070 */

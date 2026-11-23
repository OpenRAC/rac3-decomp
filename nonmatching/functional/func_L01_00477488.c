/* functional: high. Read block by block against the PAL asm; differs only in scheduling around VU0 blocks and constant/argument setup. */
#include "common.h"
#include "vu0.h"
extern int D_L01_0021F6C0[];
s32 func_L01_00477488(s32 index, Vec4 *start, Vec4 *end) {
    extern f32 func_0038CEA8(void *);
    extern void func_0038CF68(void *, void *, f32);
    extern void func_0038D000(void *, void *, void *);
    struct { Vec4 basis[3]; Vec4 prev; Vec4 current; } w;
    s32 i;
    f32 x;
    __asm__("lqc2 $vf1, %1\n\tlqc2 $vf2, %2\n\tvsub.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0" : "=m"(w.basis[0]) : "m"(*end), "m"(*start) : "vf1", "vf2");
    w.basis[0].f[2] = 0;
    func_0038CF68(&w.basis[0], &w.basis[0], 1.0f / func_0038CEA8(&w.basis[0]));
    qzero(&w.basis[1]);
    qzero(&w.basis[2]);
    w.basis[1].f[0] = w.basis[0].f[1];
    w.basis[1].f[1] = -w.basis[0].f[0];
    w.basis[2].f[2] = 1;
    __asm__("lqc2 $vf2, %2\n\tlqc2 $vf1, %1\n\tvsub.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0" : "=m"(w.prev) : "m"(*(Vec4 *)(D_L01_0021F6C0[index] + 16)), "m"(*start) : "vf1", "vf2");
    func_0038D000(&w.prev, &w.prev, w.basis);
    for (i = 1; i < *(s32 *)D_L01_0021F6C0[index]; i++) {
        __asm__("lqc2 $vf2, %2\n\tlqc2 $vf1, %1\n\tvsub.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0" : "=m"(w.current) : "m"(*(Vec4 *)(D_L01_0021F6C0[index] + i * 16 + 16)), "m"(*start) : "vf1", "vf2");
        func_0038D000(&w.current, &w.current, w.basis);
        if (w.prev.f[3] != 0.0f || w.current.f[3] != 0.0f) {
            if (w.current.f[1] * w.prev.f[1] < 0.0f) {
                x = ((w.prev.f[0] - w.current.f[0]) / (w.prev.f[1] - w.current.f[1])) * -w.current.f[1] + w.current.f[0];
                if (x > 0.0f && x < 1.0f) return 1;
            }
        }
        w.prev.q = w.current.q;
    }
    return 0;
}

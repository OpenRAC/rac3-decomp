/* functional: high. Plain-C vector adds instead of vadd.xyz (w kept untouched as retail does); callee prototypes as the neighbours declare them. */
#include "vu0.h"
extern void func_0038CF68(void *, void *, f32);
extern void func_L39_00632298(void *, void *, void *, f32);
extern void func_L39_00632558(void *, void *, void *, f32);

void func_L39_00632A20(u8 *m, f32 *out, f32 *in, f32 f) {
    f32 t0[4] __attribute__((aligned(16)));
    f32 t1[4] __attribute__((aligned(16)));
    switch (m[0x1A06]) {
    case 0:
        out[2] = in[2] - f;
        break;
    case 1:
        func_0038CF68(t0, m + 0x230, -f);
        func_L39_00632298(m, t1, in, 0.0f);
        func_L39_00632558(m, out, out, 0.0f);
        out[0] += t1[0]; out[1] += t1[1]; out[2] += t1[2];
        out[0] += t0[0]; out[1] += t0[1]; out[2] += t0[2];
        break;
    case 2:
        func_0038CF68(t0, m + 0x250, f);
        func_L39_00632298(m, t1, in, 0.0f);
        func_L39_00632558(m, out, out, 0.0f);
        out[0] += t1[0]; out[1] += t1[1]; out[2] += t1[2];
        out[0] += t0[0]; out[1] += t0[1]; out[2] += t0[2];
        break;
    }
}

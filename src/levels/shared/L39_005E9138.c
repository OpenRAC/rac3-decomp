#include "common.h"

/* localdecomp:start func_L39_005E9138 */
extern void func_0011D534(void *, s32, s32);
extern s32 func_L01_00517688(void);
extern s32 *func_003B9BD0(s32);
extern void *func_L39_005E7FF8(void *, s32, s32);
extern s32 func_0038E548(u8 *, s32, f32);
extern f32 D_L39_00245C38;
__asm__(".extern D_L39_00245C38, 16");

typedef struct { f32 a; f32 b; } P_005E9138;

void func_L39_005E9138(s32 n, s32 m, f32 *out, f32 *w, f32 total) {
    P_005E9138 buf[32];
    s32 v = 0;
    s32 i = 0;
    f32 sum, mx, mn, d;
    func_0011D534(buf, 0, 0x100);
    mn = 1000.0f;
    switch (func_L01_00517688()) {
    case 0: v = 0; break;
    case 1: v = 1; break;
    case 2: v = 2; break;
    case 3: v = 3; break;
    }
    for (i = 0; i < m; i++) w[i] = 0;
    for (i = 0; i < n; i++) {
        s32 j;
        sum = mx = d = 0;
        for (j = 0; j < m; j++) {
            d = (f32)func_0038E548(func_L39_005E7FF8(func_003B9BD0(v), j, i), -1, 1.0f) / D_L39_00245C38;
            sum += d;
            if (mx < d) mx = d;
        }
        {
            f32 r = total / sum;
            buf[i].b = r;
            buf[i].a = mx * r;
        }
    }
    for (i = 0; i < n; i++) {
        if (buf[i].b < mn) mn = buf[i].b;
    }
    for (i = 0; i < n; i++) {
        buf[i].a = buf[i].a * (mn / buf[i].b);
        buf[i].b = mn;
    }
    for (i = 0; i < n; i++) {
        s32 j;
        for (j = 0; j < m; j++) {
            d = (f32)func_0038E548(func_L39_005E7FF8(func_003B9BD0(v), j, i), -1, buf[i].b) / D_L39_00245C38;
            if (w[i] < d) w[i] = d;
        }
    }
    sum = 0;
    for (i = 0; i < m; i++) sum += w[i];
    {
        f32 r = total / sum;
        mn = mn * r;
        for (i = 0; i < m; i++) w[i] *= r;
    }
    *out = mn;
}
/* localdecomp:end func_L39_005E9138 */

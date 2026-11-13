#include "common.h"

/* declared by functions of L30_00357570.c, which this file was cut from */
extern s32 D_001D545C;

/* localdecomp:start func_L30_00357C78 */
typedef struct {
    f32 x0;
    f32 x4;
    f32 x8;
} S_00357C78;

extern s32 D_001D545C;
extern u8 D_001D55B0[] __attribute__((section(".sdata")));
extern f32 D_L30_001DDAE8; __asm__(".extern D_L30_001DDAE8, 4");
extern S_00357C78 D_L30_002B1A80[];
extern s32 func_L01_0041A4F0(void);

s32 func_L30_00357C78(s32 a) {
    s32 idx = D_001D545C - 30;
    f32 scale;
    s32 cnt;
    s32 rem;
    s32 total;

    if (func_L01_0041A4F0()) {
        scale = (&D_L30_001DDAE8)[idx];
    } else {
        scale = 1.0f;
    }
    rem = a;
    total = 0;
    cnt = D_001D55B0[idx];
    if (cnt < 100) {
        s32 n = 100 - cnt;
        if (rem < n) {
            n = rem;
        }
        cnt += n;
        rem -= n;
        total = D_L30_002B1A80[idx].x0 * n * scale;
        if (rem <= 0) {
            return total;
        }
    }
    if (cnt < 200) {
        s32 n = 200 - cnt;
        if (rem < n) {
            n = rem;
        }
        rem -= n;
        total += (s32)(D_L30_002B1A80[idx].x4 * n * scale);
        if (rem <= 0) {
            return total;
        }
    }
    return total + (s32)(D_L30_002B1A80[idx].x8 * rem * scale);
}
/* localdecomp:end func_L30_00357C78 */

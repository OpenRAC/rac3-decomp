#include "common.h"

typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_3A7DE8;

/* localdecomp:start func_L30_003A98C8 */
extern s32 D_001A71A0[];
extern f32 D_L30_001E9020[];
extern s32 func_003D3CB0(V_3A7DE8 *, V_3A7DE8 *, s32, s32, s32);
f32 func_L30_003A98C8(V_3A7DE8 *p, f32 h) {
    V_3A7DE8 t;
    f32 z;
    t = *p;
    t.z = t.z - h;
    z = p->z;
    if (func_003D3CB0(p, &t, 0, D_001A71A0[0], 0)) {
        z = D_L30_001E9020[2];
    }
    return z;
}
/* localdecomp:end func_L30_003A98C8 */

/* localdecomp:start func_L30_003A9928 */
#include "vu0.h"
typedef struct {
    u8 pad0[0x12];
    s16 count;
    u8 pad14[0xC];
    s32 *list;
} S_003A9928;
extern u8 *D_L30_001DF3CC;
__asm__(".extern D_L30_001DF800, 4");
extern u8 *D_L30_001DF800;
extern void func_0038D000(void *, void *, void *);
extern f32 func_0038CEA8(void *);

f32 func_L30_003A9928(s32 idx, vu0_v4 *pos) {
    S_003A9928 *s;
    u8 *m;
    vu0_v4 d;
    vu0_v4 l;
    f32 best = 0.0f;
    f32 len;
    f32 v;
    s32 i;

    if (idx != -1) {
        s = (S_003A9928 *)(D_L30_001DF3CC + (idx * 0x30 + 0x20));
        if (s != 0) {
            for (i = 0; i < s->count; i++) {
                if (s->list[i] != -1) {
                    m = D_L30_001DF800 + (s->list[i] << 7);
                    if (m != 0) {
                        vec_sub_ba(&d, pos, m + 0x30);
                        func_0038D000(&l, &d, m + 0x40);
                        if (fabs_asm(l.x) > fabs_asm(l.z)) {
                            len = func_0038CEA8(&l);
                            v = len / sqrt_asm((l.z / l.x) * (l.z / l.x) + 1.0f);
                        } else if (fabs_asm(l.x) < fabs_asm(l.z)) {
                            len = func_0038CEA8(&l);
                            v = len / sqrt_asm((l.x / l.z) * (l.x / l.z) + 1.0f);
                        } else {
                            len = func_0038CEA8(&l);
                            v = len / sqrt_asm(2.0f);
                        }
                        v = 1.0f - v;
                        if (v < best) {
                            v = best;
                        }
                        best = v;
                    }
                }
            }
        }
    }
    return best;
}
/* localdecomp:end func_L30_003A9928 */

/* localdecomp:start func_L30_003A9B00 */
f32 func_L30_003A9B00(f32 a, f32 b, f32 c) {
    return c * -0.5f + c * (1.0f - b) + a;
}
/* localdecomp:end func_L30_003A9B00 */

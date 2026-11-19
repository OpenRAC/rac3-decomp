/* functional: high. Compiles with --no-context (the file has no vu0 flag, so vsub.xyz is written as scalar subtraction with w copied from pos); sqrt.s/abs.s via sqrt_asm/fabs_asm; only scheduling and the sqrt placement differ. */
/* localdecomp:start func_L30_003A9928 */
#include "vu0.h"
__asm__(".extern D_L30_001DF800, 4");
extern u8 *D_L30_001DF800;
extern u8 *D_L30_001DF3CC;
extern f32 func_0038CEA8(void *);
extern void func_0038D000(void *, void *, void *);
f32 func_L30_003A9928(s32 idx, vu0_v4 *pos) {
    vu0_v4 d, t;
    f32 best = 0.0f;
    u8 *e;
    s32 i;
    s32 *ids;

    if (idx == -1) {
        return best;
    }
    e = D_L30_001DF3CC + idx * 0x30 + 0x20;
    if (e == 0) {
        return best;
    }
    for (i = 0; i < *(s16 *)(e + 0x12); i++) {
        s32 id;
        u8 *o;
        ids = *(s32 **)(e + 0x20);
        id = ids[i];
        if (id == -1) {
            continue;
        }
        o = D_L30_001DF800 + id * 0x80;
        if (o == 0) {
            continue;
        }
        d.x = pos->x - *(f32 *)(o + 0x30);
        d.y = pos->y - *(f32 *)(o + 0x34);
        d.z = pos->z - *(f32 *)(o + 0x38);
        d.w = pos->w;
        func_0038D000(&t, &d, o + 0x40);
        {
            f32 len, den, v;
            f32 ax = fabs_asm(t.x);
            f32 az = fabs_asm(t.z);
            if (az < ax) {
                len = func_0038CEA8(&t);
                den = t.z / t.x;
                den = sqrt_asm(den * den + 1.0f);
            } else if (ax < az) {
                len = func_0038CEA8(&t);
                den = t.x / t.z;
                den = sqrt_asm(den * den + 1.0f);
            } else {
                len = func_0038CEA8(&t);
                den = sqrt_asm(2.0f);
            }
            v = 1.0f - len / den;
            if (v < best) {
                v = best;
            }
            best = v;
        }
    }
    return best;
}
/* localdecomp:end func_L30_003A9928 */

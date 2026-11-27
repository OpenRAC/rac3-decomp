#include "common.h"
#include "vu0.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void (*D_001D9A40[2])(s32);
extern void (*D_001D9A40_00382B20[1])(s32);
extern void func_003C48A8();
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
extern void func_003C48A8(f32 *, f32 *);
/* --- end of declarations from other files --- */

/* localdecomp:start func_003C48A8 */
extern f32 func_0038CED8(f32 *);
extern f32 func_0038D160(f32, f32);
extern f32 func_0038CED8(f32 *);
extern f32 func_0038D160(f32, f32);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
void func_003C48A8(f32 *p, f32 *out) {
    f32 c, s, x, y, z, r;
    out[1] = func_0038D160(func_0038CED8(p), -p[2]);
    out[2] = func_0038D160(p[0], p[1]);
    if (__builtin_fabsf(out[2]) > 1e-5f) {
        c = func_0038D098(-out[2]);
        s = func_0038D0B0(-out[2]);
        x = c * p[4] - s * p[5];
        y = s * p[4] + c * p[5];
    } else {
        x = p[4];
        y = p[5];
    }
    if (__builtin_fabsf(out[1]) > 1e-5f) {
        c = func_0038D098(-out[1]);
        s = func_0038D0B0(-out[1]);
        z = -s * x + c * p[6];
        x = c * x + s * p[6];
    } else {
        z = p[6];
    }
    {
        f32 q;
        q = sqrt_asm(x * x + y * y);
        r = func_0038D160(q, z);
    }
    out[0] = r;
    if (y < 0.0f) {
        if (r < 0.0f) out[0] = -3.14159274f - r;
        else out[0] = 3.14159274f - r;
    }
}
/* localdecomp:end func_003C48A8 */

/* localdecomp:start func_003C4A40 */
/* from boot_elf's func_003C4DF8 */
typedef struct State_003C4A40 {
    s16 count, pending;
    u8 r, g, b, pad[5];
    s16 duration, previous;
} State_003C4A40;
extern void func_003C6FB0(s32, s32 *, s32 *, s32 *);
void func_003C4A40(s32 arg, State_003C4A40 *st) {
    s32 r, g, b;
    s32 old = st->count;
    if (old && !st->pending) return;
    st->pending = 0;
    st->count = (st->duration * 5 + 2) / 6;
    if (old) {
        st->count = (s16)((f32)((st->duration * 5 + 2) / 6) * ((f32)old / (f32)((st->previous * 5 + 2) / 6)));
        if (st->count <= 0) st->count = 1;
    } else {
        func_003C6FB0(arg, &r, &g, &b);
        st->r = r;
        st->g = g;
        st->b = b;
    }
}
/* localdecomp:end func_003C4A40 */

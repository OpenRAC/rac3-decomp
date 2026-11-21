#include "common.h"

/* NTSC-U counterpart of func_003C4A40 (src/frontbin/3C2FE0.c): the count is the duration itself, no 5/6 scaling */
/* localdecomp:start func_U_003BF4F8 */
typedef struct State_U_003BF4F8 {
    s16 count, pending;
    u8 r, g, b, pad[5];
    s16 duration, previous;
} State_U_003BF4F8;
extern void func_U_003C1A60(s32, s32 *, s32 *, s32 *);
void func_U_003BF4F8(s32 arg, State_U_003BF4F8 *st) {
    s32 r, g, b;
    s32 old = st->count;
    if (old && !st->pending) return;
    st->pending = 0;
    st->count = st->duration;
    if (old) {
        st->count = (s16)((f32)st->duration * ((f32)old / (f32)st->previous));
        if (st->count <= 0) st->count = 1;
    } else {
        func_U_003C1A60(arg, &r, &g, &b);
        st->r = r;
        st->g = g;
        st->b = b;
    }
}
/* localdecomp:end func_U_003BF4F8 */

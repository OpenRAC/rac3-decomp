/* PAL near miss (Codex wave 10): near miss: 6 words differ with the file's flags.
 * Worker's note: 6/74 word diffs, size delta 0 (w549/func_L01_0036AA60.check01.log). Four diffs +0xCC-0xD8: retail interleaves float constant load before final VU store; legal atomic VU sequence stays contiguous. Two tail diffs +0xE4/+0xE8 swap argument move and store. ...
 */
#include "common.h"
/* localdecomp:start func_L01_0036AA60 */
typedef struct {
    u8 p0[0x10]; s128 pos; u8 state; u8 p21[15];
    u8 opacity; u8 mode; u16 distance; u16 flags; u8 p36[0x32];
    void *data;
} Moby_0036AA60;
typedef struct {
    s128 pos; u8 p10[0x10]; s128 velocity; s32 p30;
    s32 arg; s32 time; f32 step; u8 p40[0x10]; s128 target; f32 value;
} Data_0036AA60;
Moby_0036AA60 *func_L01_0036AA60(s128 *a, s128 *b, s128 *c, s32 arg, f32 value) {
    extern Moby_0036AA60 *func_003C24B0(s32, s32);
    extern void func_0038CF68(void *, void *, f32);
    extern void func_L01_0036B440(void *);
    s128 v;
    s128 *position;
    Moby_0036AA60 *m;
    Data_0036AA60 *d;
    m = func_003C24B0(0x1862, 0x80);
    if (m) {
        d = m->data;
        position = &m->pos;
        m->opacity = 255;
        m->state = 0;
        m->distance = 255;
        m->mode = 1;
        m->flags |= 0x41;
        func_0038CF68(&d->velocity, b, 0.16000001f);
        d->pos = *a;
        m->pos = *c;
        func_0038CF68(&v, &d->velocity, -1.5f);
        __asm__("lqc2 $vf1, %1\n\tlqc2 $vf2, %2\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0"
            : "=m"(d->target) : "m"(*a), "m"(v) : "vf1", "vf2");
        d->value = value;
        d->arg = arg;
        d->step = 0.083333336f;
        d->time = 12;
        func_L01_0036B440(position);
    }
    return m;
}
/* localdecomp:end func_L01_0036AA60 */

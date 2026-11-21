/* functional: high. Plain-C port of the PAL asm; vadd.xyz written per component with w kept from the first operand; byte diffs only (scheduling). */
typedef struct {
    u8 p0[0x10]; s128 pos; u8 state; u8 p21[15];
    u8 opacity; u8 mode; u16 distance; u16 flags; u8 p36[0x32];
    void *data;
} Moby_0036AA60;
typedef struct {
    s128 pos; u8 p10[0x10]; s128 velocity; s32 p30;
    s32 arg; s32 time; f32 step; u8 p40[0x10]; f32 target[4]; f32 value;
} Data_0036AA60;
Moby_0036AA60 *func_L01_0036AA60(s128 *a, s128 *b, s128 *c, s32 arg, f32 value) {
    extern Moby_0036AA60 *func_003C24B0(s32, s32);
    extern void func_0038CF68(void *, void *, f32);
    extern void func_L01_0036B440(void *);
    f32 v[4] __attribute__((aligned(16)));
    f32 *pa = (f32 *)a;
    Moby_0036AA60 *m;
    Data_0036AA60 *d;
    m = func_003C24B0(0x1862, 0x80);
    if (m) {
        d = m->data;
        m->opacity = 255;
        m->state = 0;
        m->distance = 255;
        m->mode = 1;
        m->flags |= 0x41;
        func_0038CF68(&d->velocity, b, 0.16000001f);
        d->pos = *a;
        m->pos = *c;
        func_0038CF68(v, &d->velocity, -1.5f);
        d->target[0] = pa[0] + v[0];
        d->target[1] = pa[1] + v[1];
        d->target[2] = pa[2] + v[2];
        d->target[3] = pa[3];
        d->value = value;
        d->arg = arg;
        d->step = 0.083333336f;
        d->time = 12;
        func_L01_0036B440(&m->pos);
    }
    return m;
}

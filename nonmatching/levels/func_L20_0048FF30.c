/* func_L20_0048FF30: near miss, ps2as (--as ps2as), 24 diff, only s-reg numbering (retail self=s1, ctl=s2; mine self=s2, ctl=s1)
   twin rac2 func_002C6868; VU0 as one volatile block (contiguous in retail)
   Left: change priority so self outranks ctl */
typedef struct {
    int *colors;
    short *sizes;
    short *times;
    short last_index;
    short pad0E;
    short lifetime;
    short pad12;
    f32 scale;
} KF_48FF30;
typedef struct {
    u8 pad[0x10];
    KF_48FF30 *ctl;
    short idx;
    u8 pad2[2];
    u8 step;
} MO_48FF30;
extern void func_0038CE20(void *, void *, f32);
extern int func_L01_0047C4F8(int, int, f32);
extern int func_0038CB00(void *);
extern void func_003CD250(void *);

void func_L20_0048FF30(u8 *self) {
    MO_48FF30 *m = (MO_48FF30 *)(self + 0x20);
    KF_48FF30 *c = m->ctl;
    short elapsed;
    f32 t;
    func_0038CE20(m, m, (c->scale - 1.0f) * 1.2f + 1.0f);
    __asm__ __volatile__(
        "lqc2    $vf1, 0x10(%0)\n"
        "lqc2    $vf2, 0x20(%0)\n"
        "vadd.xyz $vf1, $vf1, $vf2\n"
        "sqc2    $vf1, 0x10(%0)\n"
        : : "r"(self) : "memory");
    self[8] += m->step;
    elapsed = c->lifetime - *(u16 *)(self + 0xA);
    if (c->times[m->idx + 1] < elapsed && m->idx < c->last_index) {
        m->idx++;
    }
    t = (f32)(elapsed - c->times[m->idx]) / (f32)(c->times[m->idx + 1] - c->times[m->idx]);
    *(int *)(self + 4) = func_L01_0047C4F8(c->colors[m->idx], c->colors[m->idx + 1], t);
    *(f32 *)(self + 0xC) = ((f32)c->sizes[m->idx] + t * (f32)(c->sizes[m->idx + 1] - c->sizes[m->idx])) * 1000.0f;
    if (func_0038CB00(self + 0xA)) {
        func_003CD250(self);
    }
}

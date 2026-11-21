/* functional: high. Uses the file's raw VU0 asm helper style. */
/* localdecomp:start func_L01_004736F0 */
static __inline__ void copy_004736F0(Quad_4735F0 *d, Quad_4735F0 *s) {
    __asm__("lqc2 $vf1, %1\n\tsqc2 $vf1, %0" : "=m"(*d) : "m"(*s) : "vf1");
}
static __inline__ void add_004736F0(Quad_4735F0 *d, Quad_4735F0 *a, Quad_4735F0 *b) {
    __asm__("lqc2 $vf2, %2\n\tlqc2 $vf1, %1\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0"
        : "=m"(*d) : "m"(*a), "m"(*b) : "vf1", "vf2");
}
static __inline__ void sub_ab_004736F0(Quad_4735F0 *d, Quad_4735F0 *a, Quad_4735F0 *b) {
    __asm__("lqc2 $vf1, %1\n\tlqc2 $vf2, %2\n\tvsub.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0"
        : "=m"(*d) : "m"(*a), "m"(*b) : "vf1", "vf2");
}
static __inline__ void sub_ba_004736F0(Quad_4735F0 *d, Quad_4735F0 *a, Quad_4735F0 *b) {
    __asm__("lqc2 $vf2, %2\n\tlqc2 $vf1, %1\n\tvsub.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0"
        : "=m"(*d) : "m"(*a), "m"(*b) : "vf1", "vf2");
}
void func_L01_004736F0(Ray_4735F0 *p) {
    extern s32 func_0038CB00(void *);
    extern void func_003CD250(u8 *);
    extern void func_0038CF68(void *, void *, f32);
    extern void func_L01_004CAB30(void *, void *);
    struct { Quad_4735F0 old, delta, saved; } vectors;
    Quad_4735F0 *tail = &p->tail;
    s32 alpha;
    if (func_0038CB00(&p->life)) {
        func_003CD250((u8 *)p);
    } else {
        vectors.old = p->head;
        p->texture = *D_L01_00221254[0];
        copy_004736F0(&vectors.saved, &vectors.old);
        add_004736F0(&p->head, &p->head, tail);
        sub_ab_004736F0(&vectors.delta, &p->head, &vectors.saved);
        func_0038CF68(&vectors.delta, &vectors.delta, ((f32 *)tail)[3] * 1.35f);
        sub_ba_004736F0((Quad_4735F0 *)((u8 *)p+0x20), &p->head, &vectors.delta);
        func_L01_004CAB30(&p->head, &p->head);
        func_L01_004CAB30((u8 *)p+0x20, (u8 *)p+0x20);
        if (p->life < p->spin) {
            alpha = (s32)(((f32)p->life / (f32)p->spin) * 127.0f) << 24;
            p->rgba = alpha | (p->rgba & 0xFFFFFF);
            p->end_rgba = alpha | (p->end_rgba & 0xFFFFFF);
        }
    }
}
/* localdecomp:end func_L01_004736F0 */

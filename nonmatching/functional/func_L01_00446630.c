/* functional: high. Same calls and VU0 vector ops as retail (vsub.xyz/vadd.xyz in one asm block each, with fixed vf1/vf2: the level file's flags have no "j" class, and plain FPU math rounds differently from VU0); out's w lane is p's w, as retail's sqc2 writes it. Clamp scheduling differs. func_0038CE68 is the dot product, func_0038CE20 the scale. */
/* d.xyz = a.xyz - b.xyz, d.w = a.w (lqc2 a, lqc2 b, vsub.xyz, sqc2) */
static void vsub_00446630(void *d, void *a, void *b) {
    __asm__ __volatile__("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)"
                         : : "r"(d), "r"(a), "r"(b) : "memory");
}
/* d.xyz = a.xyz + b.xyz, d.w = a.w */
static void vadd_00446630(void *d, void *a, void *b) {
    __asm__ __volatile__("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)"
                         : : "r"(d), "r"(a), "r"(b) : "memory");
}
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_00446630;
extern void func_0038CE20(void *, void *, f32);
extern f32 func_0038CE68(void *, void *);

f32 func_L01_00446630(f32 *out, f32 *p, f32 *q, f32 *r) {
    V4_00446630 d, rp, qc;
    f32 t;

    /* retail copies q and r to the stack first (lqc2/sqc2), then: d = q - p (w = q.w), rp = r - p (w = p.w) */
    qc = *(V4_00446630 *)q;
    vsub_00446630(&d, &qc, p);
    vsub_00446630(&rp, r, p);
    rp.w = p[3];
    t = func_0038CE68(&d, &rp) / func_0038CE68(&d, &d);
    if (t < 0.0f) {
        t = 0.0f;
    }
    if (1.0f < t) {
        t = 1.0f;
    }
    func_0038CE20(&d, &d, t);
    vadd_00446630(out, p, &d);
    return t;
}

/* functional: high. Same control flow, reads, calls and result as retail; differs only in dead stores to the stack (up vector at +0x20, perpendicular at +0x10) that nothing reads, and in register scheduling. */
/* localdecomp:start func_L39_005BEFB0 */
typedef struct {
    Vec4 a;
    Vec4 b;
    f32 x, y, z, r;
    f32 pad10;
    f32 lo;
    f32 ext;
    f32 pad1C;
} L39Seg;

extern f32 func_0038CEA8(void *);
extern f32 func_0038CF00(void *, void *);
extern void func_0038CF68(void *, void *, f32);
extern void func_0038D000(void *, void *, void *);
extern void func_0038CDF8(void *, void *, void *, f32);
extern f32 func_L01_00446630(void *, void *, void *, void *);
extern s32 D_L39_0024C124;
extern L39Seg D_L39_00294FC0[];

int func_L39_005BEFB0(void *a_, void *b_, Vec4 *out) {
    Vec4 *a = a_, *b = b_;
    Vec4 dir, perp, up, tmp, pa, pb;
    f32 inv, tmax, zlo, zhi, t, cy, py, lo, hi;
    int ok, i;
    L39Seg *w;

    dir.v[0] = b->v[0] - a->v[0];
    dir.v[1] = b->v[1] - a->v[1];
    dir.v[2] = b->v[2] - a->v[2];
    dir.v[3] = b->v[3];
    inv = 1.0f / func_0038CEA8(&dir);
    dir.v[2] = 0.0f;
    func_0038CF68(&dir, &dir, inv);
    perp.v[0] = dir.v[1];
    perp.v[1] = -dir.v[0];
    perp.v[2] = 0.0f;
    up.v[0] = 0.0f;
    up.v[1] = 0.0f;
    up.v[2] = 1.0f;
    up.v[3] = 0.0f;
    if (out != 0) {
        *out = *b;
    }
    tmax = 1.0f;
    ok = 1;
    if (b->v[2] < a->v[2]) {
        zhi = a->v[2];
        zlo = b->v[2];
    } else {
        zhi = b->v[2];
        zlo = a->v[2];
    }
    w = D_L39_00294FC0;
    for (i = 0; i < D_L39_0024C124; i++, w++) {
        func_L01_00446630(&tmp, a, b, &w->x);
        if (w->r < func_0038CF00(&tmp, &w->x)) {
            continue;
        }
        pa.v[0] = w->a.v[0] - a->v[0];
        pa.v[1] = w->a.v[1] - a->v[1];
        pa.v[2] = w->a.v[2] - a->v[2];
        pa.v[3] = w->a.v[3];
        func_0038D000(&pa, &pa, &dir);
        pb.v[0] = w->b.v[0] - a->v[0];
        pb.v[1] = w->b.v[1] - a->v[1];
        pb.v[2] = w->b.v[2] - a->v[2];
        pb.v[3] = w->b.v[3];
        func_0038D000(&pb, &pb, &dir);
        cy = pb.v[1];
        py = pa.v[1];
        if (cy * py < 0.0f) {
            t = (pa.v[0] - pb.v[0]) / (py - cy) * -cy + pb.v[0];
            if (0.0f < t && t < tmax) {
                lo = w->lo;
                hi = lo + w->ext;
                if ((lo < zlo && zhi < hi) || (zlo < lo && lo < zhi) || (zlo < hi && hi < zhi)) {
                    tmax = t;
                    if (out == 0) {
                        return 0;
                    }
                    ok = 0;
                }
            }
        }
    }
    if (out == 0) {
        return 1;
    }
    if (ok == 0) {
        func_0038CDF8(out, a, b, tmax);
        return 0;
    }
    return 1;
}
/* localdecomp:end func_L39_005BEFB0 */

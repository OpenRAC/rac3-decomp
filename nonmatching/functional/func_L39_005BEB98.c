/* functional: high. Same control flow, reads, calls and result as retail; differs only in dead stores to the stack (up vector at +0x20, perpendicular at +0x10) that nothing reads, and in float register scheduling. */
/* localdecomp:start func_L39_005BEB98 */
typedef struct {
    f32 x, y, z, r;
    Vec4 *pts;
    s32 n;
    s32 pad18[2];
} L39Wall;

extern f32 func_0038CEA8(void *);
extern f32 func_0038CF00(void *, void *);
extern void func_0038CF68(void *, void *, f32);
extern void func_0038D000(void *, void *, void *);
extern void func_0038CDF8(void *, void *, void *, f32);
extern f32 func_L01_00446630(void *, void *, void *, void *);
extern s32 D_L39_0024C120;
extern L39Wall D_L39_002947C0[];
extern f32 D_001D7CC4_sda;

int func_L39_005BEB98(void *a_, void *b_, Vec4 *out) {
    Vec4 *a = a_, *b = b_;
    Vec4 dir, perp, up, tmp, prev, cur;
    f32 inv, tol, tmax, zlo, zhi, t;
    int ok, i, j;
    L39Wall *w;

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
    tol = D_001D7CC4_sda * inv;
    if (out != 0) {
        *out = *b;
    }
    ok = 1;
    tmax = 1.0f;
    if (b->v[2] < a->v[2]) {
        zhi = a->v[2];
        zlo = b->v[2];
    } else {
        zhi = b->v[2];
        zlo = a->v[2];
    }
    w = D_L39_002947C0;
    for (i = 0; i < D_L39_0024C120; i++, w++) {
        func_L01_00446630(&tmp, a, b, w);
        if (w->r < func_0038CF00(&tmp, w)) {
            continue;
        }
        prev.v[0] = w->pts[0].v[0] - a->v[0];
        prev.v[1] = w->pts[0].v[1] - a->v[1];
        prev.v[2] = w->pts[0].v[2] - a->v[2];
        prev.v[3] = w->pts[0].v[3];
        func_0038D000(&prev, &prev, &dir);
        for (j = 1; j < w->n; j++) {
            int near0;
            f32 py, cy, zl, zh, zlw;
            cur.v[0] = w->pts[j].v[0] - a->v[0];
            cur.v[1] = w->pts[j].v[1] - a->v[1];
            cur.v[2] = w->pts[j].v[2] - a->v[2];
            func_0038D000(&cur, &cur, &dir);
            cy = cur.v[1];
            py = prev.v[1];
            near0 = 0;
            if (cy < 0.0f ? -cy < tol : cy < tol) {
                near0 = 1;
            } else if ((py < 0.0f ? -py : py) < tol) {
                near0 = 1;
            }
            if (cy * py <= 0.0f || near0) {
                int hit = 0;
                t = prev.v[0] - cur.v[0];
                t = t / (py - cy);
                t = t * -cy + cur.v[0];
                if ((t < 0.0f ? -t : t) < tol) {
                    hit = 1;
                }
                if (tmax == 1.0f && 0.0f < t && t < tol + 1.0f) {
                    hit = 1;
                }
                if ((0.0f < t && t <= tmax) || hit) {
                    f32 pz = w->pts[j].v[2];
                    zl = w->pts[j - 1].v[2] - w->pts[j - 1].v[3];
                    zh = zl + w->pts[j - 1].v[3];
                    if (pz < zl) {
                        zl = pz;
                    }
                    zlw = pz + w->pts[j].v[3];
                    if (zh < zlw) {
                        zh = zlw;
                    }
                    zl -= 0.5f;
                    if ((zl < zlo && zhi < zh) || (zlo < zl && zl < zhi) || (zlo < zh && zh < zhi)) {
                        tmax = t;
                        if (out == 0) {
                            return 0;
                        }
                        ok = 0;
                    }
                }
            }
            prev = cur;
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
/* localdecomp:end func_L39_005BEB98 */

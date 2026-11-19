/* functional: high. Segment vs vertical-cylinder (xy circle) intersection helper: returns the number of entry/exit points (0..2) with their parameters; VU0 vadd/vsub.xyz written as plain float math (w only differs on scratch vectors); radius arrives in f12. Callee names are catalogue names; func_0038D0C8 (acos) and func_0038D098 (sin) identified from other callers. Compiles at level_05 (249 diff, bytes only). */
typedef struct { f32 x, y, z, w; } V4_43F7E0;
extern f32 func_L01_004464C8(V4_43F7E0 *, V4_43F7E0 *, V4_43F7E0 *, V4_43F7E0 *);
extern f32 func_0038CF38(V4_43F7E0 *, V4_43F7E0 *);
extern void func_0038CF68(void *, void *, f32);
extern void func_0038CE20(void *, void *, f32);
extern f32 func_0038D0C8(f32);
extern f32 func_0038D098(f32);

s32 func_L05_0043F7E0(V4_43F7E0 *out0, V4_43F7E0 *out1, f32 *t0, f32 *t1, V4_43F7E0 *a, V4_43F7E0 *b, V4_43F7E0 *n, f32 radius) {
    V4_43F7E0 nrm, diff, dir, p;
    f32 f20, f21, f22, f23, f12, a2, a3;
    s32 count = 0;

    nrm = *n;
    f20 = func_L01_004464C8(&p, a, b, &nrm);
    f21 = func_0038CF38(&p, &nrm);
    if (radius < f21) {
        *out0 = p;
        *t0 = f20;
        *out1 = p;
        *t1 = f20;
        return 0;
    }
    diff.w = b->w;
    diff.x = b->x - a->x; diff.y = b->y - a->y; diff.z = b->z - a->z;
    dir = diff;
    dir.z = 0.0f;
    func_0038CF68(&dir, &dir, 1.0f);
    f22 = a->x * dir.x + a->y * dir.y;
    f23 = (b->x * dir.x + b->y * dir.y) - f22;
    if (f20 < 0.0001f || 0.99926f < f20) {
        func_0038CE20(&p, &diff, f20);
        p.x += a->x; p.y += a->y; p.z += a->z;
        f21 = func_0038CF38(&p, &nrm);
    }
    a2 = f21 / radius;
    f21 = p.x * dir.x + p.y * dir.y;
    f20 = func_0038D098(func_0038D0C8(a2)) * radius;
    f12 = (f21 - f20) - f22;
    *t0 = f12;
    if (f12 < 0.0f) {
        *out0 = *a;
    } else {
        if (f23 < f12) return 0;
        func_0038CE20(out0, &dir, f12);
        count = 1;
        out0->x += a->x; out0->y += a->y; out0->z += a->z;
    }
    f12 = (f21 + f20) - f22;
    *t0 = *t0 / f23;
    out0->z = a->z + diff.z * *t0;
    *t1 = f12;
    if (f23 < f12) {
        *out1 = *b;
    } else {
        if (f12 < 0.0f) return 0;
        func_0038CE20(out1, &dir, f12);
        count++;
        out1->x += a->x; out1->y += a->y; out1->z += a->z;
    }
    *t1 = *t1 / f23;
    out1->z = a->z + diff.z * *t1;
    return count;
}

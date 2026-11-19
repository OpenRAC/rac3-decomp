/* functional: high. Same math in a loop over x/y/z (retail unrolls it); same op order per component. Uses the file's Vec4_40CA60 prototype. */
void func_L01_0040D220(Vec4_40CA60 *out, Vec4_40CA60 *p0, Vec4_40CA60 *p1, Vec4_40CA60 *p2, Vec4_40CA60 *p3, f32 t) {
    f32 t2, t3, d, e;
    s32 i;
    if (t == 0.0f) {
        *out = *p0;
        return;
    }
    if (t == 1.0f) {
        *out = *p1;
        return;
    }
    t2 = t * t;
    t3 = t2 * t;
    for (i = 0; i < 3; i++) {
        d = (p3->f[i] - p1->f[i]) - (p2->f[i] - p0->f[i]);
        e = (p2->f[i] - p0->f[i]) - d;
        out->f[i] = ((d * t3 + e * t2) + (p1->f[i] - p2->f[i]) * t) + p0->f[i];
    }
    out->f[3] = 0.0f;
}

/* functional: high. Near exact: instruction stream matches retail except 2 nops before div.s (needs a config/levels/divs_nops.txt line 'func_L01_0040BE10 2') and the file lacking -mvu0-use-vf0-vf2 for vec helpers; checked with that flag added. */
extern void func_0038CE20(f32 *, f32 *, f32);
void func_L01_0040BE10(f32 *a, f32 *v) {
    f32 t;
    s32 i;
    f32 r;
    if (v[0] > 0.0f && v[1] > 0.0f && v[2] > 0.0f) {
        return;
    }
    t = 1.0f;
    for (i = 0; i < 3; i++) {
        if (v[i] <= 0.0f) {
            r = 1.0f - v[i] / (v[i] - a[i]);
            if (r < t) {
                t = r;
            }
        }
    }
    v[0] = v[0] - a[0];
    v[1] = v[1] - a[1];
    v[2] = v[2] - a[2];
    v[3] = a[3];
    func_0038CE20(v, v, t - 0.01f);
    v[0] = v[0] + a[0];
    v[1] = v[1] + a[1];
    v[2] = v[2] + a[2];
}

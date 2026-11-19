/* functional: high. Near miss (30 diffs): retail keeps the second (s32)t conversion in the FPU (cvt.w.s, cvt.s.w) and the index in a GPR; behaviour identical. Signature (s32 path, f32 t, f32 d, f32) as the file declares it; path points at a node count word. */
extern f32 D_L16_00278200[];

/* walks forward along a closed path: t = segment index + fraction, d = distance to cover */
f32 func_L16_00345DE8(s32 path, f32 t, f32 d, f32 unused) {
    s32 n;

    if (0.0f < d) {
        n = *(s32 *)path;
        do {
            s32 i = (s32)t;
            f32 rem = 1.0f - (t - (f32)(s32)t);
            f32 seg = D_L16_00278200[i];
            s32 next = (i + 1) % n;
            f32 step = d / seg;

            if (rem < step) {
                d = d - rem * seg;
                t = (f32)next;
            } else {
                t = t + step;
                d = 0.0f;
            }
        } while (0.0f < d);
    }
    return t;
}

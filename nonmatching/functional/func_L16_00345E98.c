/* functional: high. Near miss (45 diffs, FPU/GPR placement of the int<->float conversions only). Same file prototype (s32 path, f32, f32, f32); path points at the node count word. */
extern f32 D_L16_00278200[];

/* walks backward along a closed path */
f32 func_L16_00345E98(s32 path, f32 position, f32 distance, f32 unused) {
    f32 fraction = position - (f32)(s32)position;
    s32 index = (s32)position;

    while (distance > 0.0f) {
        f32 length = D_L16_00278200[index];
        f32 step = distance / length;

        if (fraction < step) {
            distance -= fraction * length;
            index--;
            if (index < 0) {
                index = *(s32 *)path - 1;
            }
            fraction = 1.0f;
            position = (f32)index;
        } else {
            position = (f32)index + (fraction - step);
            distance = 0.0f;
        }
    }
    return position;
}

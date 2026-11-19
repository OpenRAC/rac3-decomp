/* functional: high. Compiles at level_01 (62 diff, same structure; constants verified bit-exact). */
extern f32 D_L01_001DC0E8;
extern s32 func_00381FF0(s32);
extern s32 func_0038E548(s32, s32, f32);
extern f32 func_003C4088(f32, f32, f32);

void func_L01_0049A748(s32 id, f32 *scale, f32 *size) {
    f32 ratio;
    f32 s = 1.2f;
    f32 v;
    s32 w;

    w = func_0038E548(func_00381FF0(id), -1, 1.2f);
    ratio = (f32)w / D_L01_001DC0E8;
    if (0.49f < ratio) {
        s = 0.58800006f / ratio;
        ratio = 0.49f;
    }
    v = func_003C4088(6.0f, 11.0f, (ratio - 0.0f) / 0.49f);
    *size = v;
    if (v > 11.0f) {
        *size = 11.0f;
    } else if (v < 6.0f) {
        *size = 6.0f;
    }
    *scale = s;
}

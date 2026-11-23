/* functional: medium. Real entry is at +0x58; callers may reference that address. */
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern f32 func_0038DB48(f32);

/* The catalogue entry starts 0x58 bytes early (trailing delay slots of the previous
   functions); the real function starts at +0x58 with the float to int conversion. */
f32 func_L24_00359248(f32 time, f32 period, s32 reverse, s32 mode, u32 curve) {
    f32 t;
    f32 e;
    f32 r;

    t = (f32)((s32)time % (s32)period) / period;
    if (reverse == 1) {
        t = 1.0f - t;
    }
    switch (curve) {
    case 0:
        e = t;
        break;
    case 1:
        e = 0.5f - func_0038D098(t * 3.1415927f) * 0.5f;
        break;
    case 2:
        if (t < 0.5f) {
            e = (t + t) * t;
        } else {
            e = (t + t) * (2.0f - t) - 1.0f;
        }
        break;
    case 3:
        if (t < 0.5f) {
            e = func_0038D0B0(t * 3.1415927f) * 0.5f;
        } else {
            e = 1.0f - func_0038D0B0((1.0f - t) * 3.1415927f) * 0.5f;
        }
        break;
    case 4:
        if (t < 0.5f) {
            e = (t + t) * (1.0f - t);
        } else {
            e = (t + t) * (t - 1.0f) + 1.0f;
        }
        break;
    case 5:
        e = (func_0038D098(t * 6.2831855f) + 1.0f) * 0.5f;
        break;
    }
    switch (mode) {
    case 0:
        r = e;
        break;
    case 1:
        r = func_0038DB48(e * 6.2831855f);
        break;
    case 2:
        r = func_0038DB48(e * 1.5707964f);
        break;
    case 3:
        r = (e + e) - 1.0f;
        break;
    }
    return r;
}

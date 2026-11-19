/* functional: high. Near-exact: the arithmetic op order matches retail instruction for instruction in the segment branch; only the negative-t branch constant materialisation (f2/f6 zero) and block layout differ. */
f32 func_L05_0032A238(u8 *obj, u8 *pts, s32 *idx, f32 t, f32 step) {
    f32 rem = 1.0f;
    do {
        if (t < 0.0f) {
            f32 d;
            f32 nt;
            *idx = -1;
            d = step / *(f32 *)(obj + 0x18C) * rem;
            nt = t + d;
            if (nt >= 0.0f) {
                f32 over = 0.0f - t;
                *idx = 0;
                t = 0.0f;
                rem = rem - over / d * rem;
            } else {
                t = nt;
                rem = 0.0f;
            }
        } else {
            s32 i = (s32)t;
            f32 d;
            f32 after;
            *idx = i;
            d = step / *(f32 *)(pts + i * 16 + 0x1C) * rem;
            after = (t + d) - (f32)i;
            if (after >= 1.0f && i < *(s32 *)pts - 1) {
                f32 k = (d - (after - 1.0f)) / d;
                t = t + d * k;
                rem = rem - k * rem;
                *idx = (s32)t;
            } else {
                t = t + d;
                rem = 0.0f;
            }
        }
    } while (rem > 0.0f);
    return t;
}

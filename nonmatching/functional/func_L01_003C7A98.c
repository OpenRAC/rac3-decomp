/* functional: high. 70 instructions differ (scheduling only); same arithmetic, reads and writes. */
f32 func_L01_003C7A98(u8 *s, u8 *t, s32 *out, f32 pos, f32 dist) {
    f32 rem = 1.0f;
    do {
        f32 step;
        if (pos < 0.0f) {
            f32 np;
            *out = -1;
            step = dist / *(f32 *)(s + 0x14C) * rem;
            np = pos + step;
            if (np >= 0.0f) {
                *out = 0;
                rem -= (0.0f - pos) / step * rem;
                pos = 0.0f;
            } else {
                pos = np;
                rem = 0.0f;
            }
        } else {
            s32 i = (s32)pos;
            f32 frac;
            *out = i;
            step = dist / *(f32 *)(t + i * 16 + 0x1C) * rem;
            frac = (pos + step) - (f32)i;
            if (frac >= 1.0f && i < *(s32 *)t - 1) {
                f32 portion = (step - (frac - 1.0f)) / step;
                pos += step * portion;
                rem -= portion * rem;
                *out = (s32)pos;
            } else {
                pos += step;
                rem = 0.0f;
            }
        }
    } while (rem > 0.0f);
    return pos;
}

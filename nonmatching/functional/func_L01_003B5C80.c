/* functional: medium. Same reads, writes and returned float on every path; a1 is unused in retail; division by zero left as retail (no guard in this function; PS2 divide semantics apply on target). */
f32 func_L01_003B5C80(u8 *m, s32 a1, s32 flag, f32 *o1, f32 *o2) {
    u8 *s = *(u8 **)(m + 104);
    f32 ratio;
    f32 f38;
    f32 num;
    f32 den;

    if (*(s32 *)(s + 60) != 0) {
        if (o1 != 0) {
            *o2 = (f32)*(s32 *)(s + 60);
            if (*(s32 *)(s + 196) < *(s32 *)(s + 60)) {
                *o1 = (f32)*(s32 *)(s + 196);
            } else {
                *o1 = (f32)*(s32 *)(s + 60);
            }
        }
        ratio = (f32)*(s32 *)(s + 196) / (f32)*(s32 *)(s + 60);
        if (1.0f < ratio) {
            ratio = 1.0f;
        }
        return ratio;
    }
    if (*(s32 *)(s + 188) < 0) {
        if (*(s32 *)(s + 136) == 0) {
            if (flag == 0) {
                return -1.0f;
            }
            goto use_c0;
        }
        if (*(s32 *)(s + 140) < *(s32 *)(s + 136)) {
            if (o1 != 0) {
                *o1 = (f32)*(s32 *)(s + 140);
                *o2 = (f32)*(s32 *)(s + 136);
            }
            return (f32)*(s32 *)(s + 140) / (f32)*(s32 *)(s + 136);
        }
        if (o1 != 0) {
            *o1 = (f32)*(s32 *)(s + 196);
            *o2 = (f32)*(s32 *)(s + 192);
        }
        f38 = *(f32 *)(s + 56);
        num = (f32)*(s32 *)(s + 196);
        den = (f32)*(s32 *)(s + 192);
        ratio = num / den;
        goto scale;
    }
    if (flag != 0) {
use_c0:
        if (o1 != 0) {
            *o1 = (f32)*(s32 *)(s + 196);
            *o2 = (f32)*(s32 *)(s + 192);
        }
        num = (f32)*(s32 *)(s + 196);
        den = (f32)*(s32 *)(s + 192);
    } else {
        if (o1 != 0) {
            *o1 = (f32)*(s32 *)(s + 196);
            *o2 = (f32)*(s32 *)(s + 188);
        }
        num = (f32)*(s32 *)(s + 196);
        den = (f32)*(s32 *)(s + 188);
    }
    ratio = num / den;
    f38 = *(f32 *)(s + 56);
scale:
    if (0.0f < f38) {
        if (o1 != 0) {
            *o1 = *o1 * f38;
            *o2 = *o2 * f38;
            if (*o2 < *o1) {
                *o1 = *o2;
            }
        }
        return ratio / f38;
    }
    return ratio;
}

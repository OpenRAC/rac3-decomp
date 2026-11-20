/* functional: high. PAL near-miss draft; full check.py diff read: identical except the four float literals (0.5675, 0.005, 0.85, 0.03 come from the .lit4 pool, not lui/ori) and the 8 extra words that shift three branch targets. No return value (retail leaves $v0 as is and the caller ignores it): void, as the fuzz gate found. */
extern void func_003AB810(void *, f32);
void func_003ACD00(void *arg0) {
    O_A73A0 *o = arg0;
    s32 cnt = o->f198;
    s32 v = o->p8[3];
    u8 *p;
    u8 *q;
    s32 hi;
    s32 m;
    if (cnt > 0) {
        v = v + 9;
        v = (v >= 0x81) ? 0x80 : v;
        o->f198 = cnt - 1;
    } else {
        v = v - 9;
        v = (v <= -1) ? 0 : v;
    }
    if (v == 0) {
        *o->p4 = 0;
    } else {
        f32 k14 = 14.0f;
        f32 k23 = 23.5f;
        f32 g = 0.0f;
        f32 zero;
        hi = v << 24;
        p = (u8 *)o + 0x10;
        q = (u8 *)o + 0x4C;
        { s32 *r = (s32 *)o->p8; *r = (*r & 0xFFFFFF) | hi; }
        { s32 *r = o->pC; *r = (*r & 0xFFFFFF) | hi; }
        { s32 *r = (s32 *)func_003AB270(p); *r = (*r & 0xFFFFFF) | hi; }
        { s32 *r = (s32 *)func_003AB270(q); *r = (*r & 0xFFFFFF) | hi; }
        m = o->f1A4;
        switch (m) {
        case 0: {
            s32 x;
            f32 f;
            zero = g;
            x = (o->f1B4 >> 1) + 8;
            o->f19C = 8;
            o->f1A0 = 6;
            o->f18C = ((o->f190 * 0x10) >> 1) + 6;
            o->f188 = x;
            { f32 k; f32 t = ((f32)x - 40.0f) / 202.0f; k = 0.5675f; k *= t; func_003AB810(q, k + 0.005f); }
            f = D_001D8434_003ACD00;
            if (zero < f) {
                func_003AB810(q, f);
            }
            g = ((f32)o->f18C - k14) / 152.0f;
            func_003AB810(p, g * 0.85f + 0.03f);
            f = D_001D8438_003ACD00;
            if (zero <= f) {
                func_003AB810(p, f);
            }
            o->f1B0 = g * 306.0f + k23;
            break;
        }
        case 1: {
            s32 x;
            f32 f;
            zero = g;
            x = (o->f1B4 >> 1) + 8;
            o->f19C = 8;
            o->f1A0 = 6;
            o->f18C = ((o->f190 * 0x10) >> 1) + 6;
            o->f188 = x;
            { f32 k; f32 t = ((f32)x - 40.0f) / 202.0f; k = 0.5675f; k *= t; func_003AB810(q, k + 0.005f); }
            f = D_001D8434_003ACD00;
            if (zero < f) {
                func_003AB810(q, f);
            }
            g = ((f32)o->f18C - k14) / 152.0f;
            func_003AB810(p, g * 0.85f + 0.03f);
            f = D_001D8438_003ACD00;
            if (zero <= f) {
                func_003AB810(p, f);
            }
            o->f1B0 = g * 306.0f + k23;
            break;
        }
        case 2:
            break;
        }
    }
}

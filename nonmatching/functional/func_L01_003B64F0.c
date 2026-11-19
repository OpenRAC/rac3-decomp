/* functional: medium. Branches follow the asm; not byte-matched. Radius-collision test (func_L01_003FB640) uses the vector copy plus radius on z; 16-byte lq/sq copy written as four float copies. */
extern s16 *D_L01_0021DE20[];
extern s32 func_00382468(s32);
extern s32 func_L01_003FB640(f32 *, s32, u8 *, f32);

u8 *func_L01_003B64F0(u8 *s, s32 *out, f32 t, f32 radius) {
    f32 buf[4] __attribute__((aligned(16)));
    f32 frac;
    s32 idx, i, n, k, rem, cnt;
    u8 *p;
    s32 a = *(s32 *)(s + 0x60);
    s32 b = *(s32 *)(s + 0x64);

    if (a == 0) {
        frac = 0.0f;
    } else if (b == 0) {
        frac = 1.0f;
    } else {
        frac = (f32)a / (f32)(a + b);
    }

    if ((frac == 0.0f && 0.0f < t) || frac <= t) {
        if (out) {
            *out = -1;
        }
        if (*(s32 *)(s + 0x5C)) {
            idx = func_00382468(*(s32 *)(s + 0xB4));
        } else {
            idx = *(s32 *)(s + 0x60) % *(s32 *)(s + 0xB4);
        }
        cnt = *(s32 *)(s + 0xB4);
        for (i = 0; i < cnt; i = i + 1, cnt = *(s32 *)(s + 0xB4)) {
            if (idx == *(s32 *)(s + 0xB0)) {
                p = D_L01_001E001C + (*(s32 *)(s + 8) << 8);
            } else {
                s16 *tbl = D_L01_0021DE20[*(s32 *)(s + 4)];
                p = D_L01_001E001C + ((tbl[idx] & 0x7FFF) << 8);
            }
            buf[0] = *(f32 *)(p + 0x10);
            buf[1] = *(f32 *)(p + 0x14);
            buf[2] = *(f32 *)(p + 0x18);
            buf[3] = *(f32 *)(p + 0x1C);
            buf[2] = buf[2] + radius;
            if (radius == 0.0f || func_L01_003FB640(buf, 1, 0, radius) == 0) {
                *(s32 *)(s + 0x60) = *(s32 *)(s + 0x60) + 1;
                return p;
            }
            idx = (idx + 1) % *(s32 *)(s + 0xB4);
        }
        return 0;
    }

    if (out) {
        *out = 0;
    }
    if (*(s32 *)(s + 0x5C)) {
        idx = func_00382468(*(s32 *)(s + 0xB8));
    } else {
        idx = *(s32 *)(s + 0x64) % *(s32 *)(s + 0xB8);
    }
    cnt = *(s32 *)(s + 0xB4);
    for (i = 0; i < cnt; i = i + 1, cnt = *(s32 *)(s + 0xB4)) {
        n = *(s32 *)(s + 0xC8);
        rem = idx;
        for (k = 0; k < n; k++) {
            s32 w = *(s32 *)(s + 0x100 + k * 4);
            if (rem < w) {
                s16 *tbl = D_L01_0021DE20[*(s32 *)(s + 0xD0 + k * 4)];
                p = D_L01_001E001C + ((tbl[rem] & 0x7FFF) << 8);
                goto have;
            }
            rem -= w;
        }
        p = D_L01_001E001C + (*(s32 *)(s + 0xE0 + rem * 4) << 8);
        k = n;
        if (out) {
            *out = rem;
            goto have2;
        }
        goto have2;
have:
        if (out) {
            *out = k;
        }
have2:
        if (func_L01_003FB640((f32 *)(p + 0x10), 1, 0, radius) == 0) {
            *(s32 *)(s + 0x64) = *(s32 *)(s + 0x64) + 1;
            return p;
        }
        idx = (idx + 1) % *(s32 *)(s + 0xB8);
    }
    return 0;
}

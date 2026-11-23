/* functional: medium-high. RC2 block encrypt (16 mixing rounds, mash after rounds 5 and 11); retail is fully unrolled; loop form verified by encrypt/decrypt round trip against the matching decrypt on 1000 random keys natively. */
typedef struct { u16 data[64]; } RC2_KEY_004E6030;

void func_L39_004E6030(u64 *d, RC2_KEY_004E6030 *key) {
    u16 x0, x1, x2, x3;
    u16 *p0 = key->data;
    s32 i;
    s32 r;

    x0 = (u16)d[0];
    x1 = (u16)(d[0] >> 16);
    x2 = (u16)d[1];
    x3 = (u16)(d[1] >> 16);

    for (r = 0; r < 16; r++) {
        x0 = x0 + *p0++ + (x3 & x2) + (~x3 & x1);
        x0 = (u16)((x0 << 1) | (x0 >> 15));
        x1 = x1 + *p0++ + (x0 & x3) + (~x0 & x2);
        x1 = (u16)((x1 << 2) | (x1 >> 14));
        x2 = x2 + *p0++ + (x1 & x0) + (~x1 & x3);
        x2 = (u16)((x2 << 3) | (x2 >> 13));
        x3 = x3 + *p0++ + (x2 & x1) + (~x2 & x0);
        x3 = (u16)((x3 << 5) | (x3 >> 11));
        if (r == 4 || r == 10) {
            x0 += key->data[x3 & 0x3F];
            x1 += key->data[x0 & 0x3F];
            x2 += key->data[x1 & 0x3F];
            x3 += key->data[x2 & 0x3F];
        }
    }

    d[0] = (u64)x0 | ((u64)x1 << 16);
    d[1] = (u64)x2 | ((u64)x3 << 16);
}

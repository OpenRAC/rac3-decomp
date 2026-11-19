/* functional: high. Same algorithm (DES key schedule) block for block: word loads, 5 bit-permutation steps, 16 rounds over the same tables; retail stores the first word of each pair unrotated and the second rotated left 4, as written here. Not byte-checked (file is @ee296, compiler does not run on the Mac); compiles with SN gcc. DNAS crypto library, the port may replace it. */
extern const s8 D_L39_0046E998[16];
extern const u32 D_L39_0046E198[8][64];

/* DES key schedule (the libdes set_key shape): key is already two words, schedule gets 16 pairs */
void func_L39_004F6420(u32 *k, u32 *key) {
    u32 c, d, t, s;
    s32 i;

    c = key[0];
    d = key[1];

    t = ((d >> 4) ^ c) & 0x0f0f0f0f; c ^= t; d ^= (t << 4);
    t = ((c << 18) ^ c) & 0xcccc0000; c = c ^ t ^ (t >> 18);
    t = ((d << 18) ^ d) & 0xcccc0000; d = d ^ t ^ (t >> 18);
    t = ((d >> 1) ^ c) & 0x55555555; c ^= t; d ^= (t << 1);
    t = ((c >> 8) ^ d) & 0x00ff00ff; d ^= t; c ^= (t << 8);
    t = ((d >> 1) ^ c) & 0x55555555; c ^= t; d ^= (t << 1);
    d = ((d & 0x000000ff) << 16) | (d & 0x0000ff00) |
        ((d & 0x00ff0000) >> 16) | ((c & 0xf0000000) >> 4);
    c &= 0x0fffffff;

    for (i = 0; i < 16; i++) {
        if (D_L39_0046E998[i]) {
            c = (c >> 2) | (c << 26);
            d = (d >> 2) | (d << 26);
        } else {
            c = (c >> 1) | (c << 27);
            d = (d >> 1) | (d << 27);
        }
        c &= 0x0fffffff;
        d &= 0x0fffffff;
        s = D_L39_0046E198[0][c & 0x3f] |
            D_L39_0046E198[1][((c >> 6) & 0x03) | ((c >> 7) & 0x3c)] |
            D_L39_0046E198[2][((c >> 13) & 0x0f) | ((c >> 14) & 0x30)] |
            D_L39_0046E198[3][((c >> 20) & 0x01) | ((c >> 21) & 0x06) | ((c >> 22) & 0x38)];
        t = D_L39_0046E198[4][d & 0x3f] |
            D_L39_0046E198[5][((d >> 7) & 0x03) | ((d >> 8) & 0x3c)] |
            D_L39_0046E198[6][(d >> 15) & 0x3f] |
            D_L39_0046E198[7][((d >> 21) & 0x0f) | ((d >> 22) & 0x30)];

        *k++ = (t << 16) | (s & 0x0000ffff);
        s = (s >> 16) | (t & 0xffff0000);
        *k++ = (s << 4) | (s >> 28);
    }
}

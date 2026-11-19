/* functional: high. Not byte-matched (retail reads D_001D545C gp-relative, C uses lui form). Logic traced branch by branch. */
extern u8 D_001BBC40[];
extern s32 D_001D545C[];
extern s32 func_L01_00326DD0(s32, s32);

s32 func_L01_003B7AA8(u8 *a0, u8 *s) {
    s32 a = *(s32 *)(s + 0x110);
    s32 b;
    s32 n, d, k, r, m, c, rem;

    if (a != -1) {
        if ((D_001BBC40[(a + (D_001D545C[0] << 4))] & 0x80) == 0) {
            return 0;
        }
    }
    b = *(s32 *)(s + 0x114);
    if (b != -1) {
        if ((D_001BBC40[(b + (D_001D545C[0] << 4))] & 0x80) != 0) {
            return 0;
        }
    }
    n = *(s32 *)(s + 0x18);
    if (n <= 0) {
        return 0;
    }
    if (*(s32 *)(s + 0x30) == 0) {
        return 0;
    }
    if (*(s32 *)(s + 0x88) != 0 && !(*(s32 *)(s + 0x8C) < *(s32 *)(s + 0x88))) {
        return 0;
    }
    d = *(s32 *)(s + 0xC0) - *(s32 *)(s + 0xC4);
    if (!(d < n)) {
        return 0;
    }
    k = n - d;
    if (k < *(s32 *)(s + 0x1C)) {
        return 0;
    }
    r = func_L01_00326DD0(*(s32 *)s, k);
    if (r < k) {
        k = r;
    }
    if (k == 0) {
        return 0;
    }
    m = *(s32 *)(s + 0x1C);
    c = *(s32 *)(s + 0x30);
    if (m < k) {
        k = m;
    }
    if (c <= 0) {
        return k;
    }
    rem = *(s32 *)(s + 0xBC) - *(s32 *)(s + 0xC0);
    if (rem <= 0) {
        return 0;
    }
    if (rem < k) {
        k = rem;
    }
    if (k < m) {
        return 0;
    }
    return k;
}

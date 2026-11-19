/* functional: high. Near miss (10 diff words: divisor register choice and store order only); all offsets and the /3 /4 /5 split checked against retail. */
extern u8 *func_003C24B0(s32, s32);
extern s32 D_00142668[];
u8 *func_L01_00301798(u8 *src, s32 a1, s32 a2, s32 a3, s32 a4) {
    u8 *m;
    u8 *pv;
    s32 v;
    if ((s8)src[32] < 0)
        return 0;
    m = func_003C24B0(806, 192);
    if (m != 0) {
        pv = *(u8 **)(m + 104);
        m[48] = 64;
        m[32] = 0;
        *(u8 **)(m + 184) = src;
        pv[87] = a1;
        *(s32 *)(pv + 128) = a2;
        *(s32 *)(pv + 132) = a3;
        *(s32 *)(pv + 136) = a4;
        if (a2 == 0 && a3 == 0 && a4 == 0) {
            v = D_00142668[0];
            v = D_00142668[0];
            *(s32 *)(pv + 140) = 0;
            *(s32 *)(pv + 132) = v / 4;
            *(s32 *)(pv + 128) = v / 3;
            *(s32 *)(pv + 136) = v / 5;

        } else {
            *(s32 *)(pv + 140) = 1;
        }
        *(u16 *)(m + 52) |= 65;
        *(s32 *)(m + 152) = 0;
        *(u128_t *)(m + 16) = *(u128_t *)(src + 16);
    }
    return m;
}

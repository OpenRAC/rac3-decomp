/* functional: high. Same reads, writes and call order; only register allocation and scheduling differ. */
extern s32 D_L01_001DE630;
extern s32 D_L01_001DE634;
extern s32 func_L01_003B5B40(u8 *);
extern s32 func_L01_003B5B68(u8 *);

s32 func_L01_003B3470(u8 *m, s32 flag) {
    u8 *cur;
    u8 *st;

    if (D_L01_001DE630 == 0) {
        return 0;
    }
    st = *(u8 **)(D_L01_001DE630 + 104);
    if (m[33] != *(s32 *)(st + 12)) {
        cur = (u8 *)D_L01_001DE634;
        while (1) {
            if (cur == 0) {
                return 0;
            }
            st = *(u8 **)(cur + 104);
            if (cur == m) {
                break;
            }
            cur = *(u8 **)(st + 88);
        }
    }
    if (flag == 0) {
        return func_L01_003B5B40(m) != 0;
    }
    return func_L01_003B5B68(m) != 0;
}

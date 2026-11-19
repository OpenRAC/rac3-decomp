/* functional: high. Same reads, writes, calls and order; only register allocation differs. */
extern s32 D_L01_001DE630;
extern s32 D_L01_001DE638;
extern s32 D_L01_001DE63C;
extern s32 D_L01_001DE640;
extern s32 D_L01_001DE644;
extern s32 D_L01_001DE648;
extern s32 D_L01_001DFB40[];
extern s32 func_L01_003B42E8(s32, s32, s32, s32);

s32 func_L01_003B4718(void) {
    u8 *s;
    s32 now;
    s32 dt;

    if (D_L01_001DE630 == 0) {
        if (D_L01_001DE648 != 0) {
            if (D_L01_001DE648 + 1 < D_L01_001DFB40[0]) {
                D_L01_001DE638 = 0;
                D_L01_001DE63C = 0;
                D_L01_001DE640 = 0;
                D_L01_001DE644 = 0;
                D_L01_001DE648 = 0;
            } else {
                func_L01_003B42E8(D_L01_001DE638, D_L01_001DE63C, D_L01_001DE640, D_L01_001DE644);
            }
        }
        return 1;
    }
    s = *(u8 **)(D_L01_001DE630 + 104);
    now = D_L01_001DFB40[0];
    dt = now - *(s32 *)(s + 4);
    if (*(s32 *)(s + 16) != 0 && dt < 250) {
        func_L01_003B42E8(*(s32 *)(s + 16), 0, 0, 0);
        return 1;
    }
    if (*(s32 *)(s + 20) != 0) {
        if (*(s32 *)(s + 24) < dt) {
            if ((dt - *(s32 *)(s + 24)) % *(s32 *)(s + 28) < 250) {
                func_L01_003B42E8(*(s32 *)(s + 20), 0, 0, 0);
                return 1;
            }
        }
    }
    if (D_L01_001DE648 != 0) {
        if (D_L01_001DE648 + 1 < now) {
            D_L01_001DE638 = 0;
            D_L01_001DE63C = 0;
            D_L01_001DE640 = 0;
            D_L01_001DE644 = 0;
            D_L01_001DE648 = 0;
        } else {
            func_L01_003B42E8(D_L01_001DE638, D_L01_001DE63C, D_L01_001DE640, D_L01_001DE644);
        }
    }
    return 1;
}

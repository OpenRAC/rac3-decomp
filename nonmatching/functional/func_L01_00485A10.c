/* functional: high. Returns a0 / 2 plus (a0 odd ? a2 : a1), with signed halving as retail, no side effects. */
s32 func_L01_00485A10(s32 a0, s32 a1, s32 a2) {
    s32 q = a0 / 2;
    s32 r = a0 - q * 2;
    s32 t = q;
    if (r != 0) {
        a1 = a2;
    }
    return a1 + t;
}

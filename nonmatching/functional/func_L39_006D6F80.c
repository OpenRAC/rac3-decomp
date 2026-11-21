/* functional: high. Layout-size helper: 4-align(arg0+0x28), add func_L39_006E16A0(p, arg1, 0x64, 4), 4-align, plus arg1*4, minus arg0. Retail passes the caller's a1 as arg1 (existing callers' 1-arg prototype is wrong; give it 2 args). */
s32 func_L39_006E16A0(s32, s32, s32, s32);

s32 func_L39_006D6F80(s32 arg0, s32 arg1) {
    u32 p;
    u32 r;

    p = arg0 + 0x28;
    r = p % 4;
    if (r != 0) {
        p += 4 - r;
    }
    p += func_L39_006E16A0(p, arg1, 0x64, 4);
    r = p % 4;
    if (r != 0) {
        p += 4 - r;
    }
    return p + arg1 * 4 - arg0;
}

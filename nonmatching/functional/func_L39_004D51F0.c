/* functional: high. Only s0/s1 register naming differs from retail (loop counter vs object pointer swapped); behaviour identical. */
extern s32 func_00129C38(s32, s32, s32);
extern s32 func_00127108(s32);

s32 func_L39_004D51F0(s32 *obj, s32 a1, s32 a2) {
    s32 i;
    s32 ret;

    i = 0;
    for (;;) {
        i++;
        if (i > 1000) {
            ret = -1;
            break;
        }
        if (func_00129C38((s32)obj, a1, a2) >= 0 && obj[0x24 / 4] != 0) {
            ret = 0;
            break;
        }
        if (func_00127108(10000) < 0) {
            ret = -1;
            break;
        }
    }
    return ret;
}

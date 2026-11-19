/* functional: high. Near-miss draft; 104->2, 102/103/105->1, else 0, as retail; only the zero/one return scheduling differs. */
/* localdecomp:start func_L01_00511A98 */
extern int D_001A71A4[];
s32 func_L01_00511A98(void)
{
    s32 state = D_001A71A4[0];
    if (state == 104) goto two;
    if (state < 105) {
        if (state < 102) goto zero;
        return 1;
    } else {
        if (state != 105) goto zero;
        return 1;
    }
two:
    return 2;
zero:
    return 0;
}
/* localdecomp:end func_L01_00511A98 */

/* func_L39_0050C5A8: 8 diff, schedule only (retail moves a0->s0 and addiu s1 before the arg setup; ours sets t2/a3 first). Call has 7 args (a4..a6 in t0..t2). 5 forms, all modes tried. */
extern int func_L39_00508128(void *, void *, int, int, int, int, int);

int func_L39_0050C5A8(char *obj, int a, int b, int c) {
    char *s = obj + 0x10;
    int r = func_L39_00508128(obj, s, 1, a, *(int *)(obj + 0x2C), b, c);
    if (r == 0) *(char **)(obj + 8) = s;
    return r;
}

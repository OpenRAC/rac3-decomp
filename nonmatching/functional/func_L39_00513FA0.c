/* functional: high. 112 diffs (loop block layout; retail enters the three-step rotation mid-loop); same behaviour. */
typedef struct BN_00513FA0 {
    s32 cap;
    s32 n;
    long *d;
} BN_00513FA0;

s32 func_L39_00513FA0(void *arg0, void *arg1, void *arg2) {
    BN_00513FA0 *a = arg0;
    BN_00513FA0 *b = arg1;
    BN_00513FA0 *out = arg2;
    BN_00513FA0 t;
    BN_00513FA0 u;
    s32 err;
    s32 mode;

    func_L39_005128E8((s32 *)&t);
    func_L39_005128E8((s32 *)&u);
    do {
        if (func_L39_00510F60(a, b) >= 0) {
            if ((err = func_L39_00510EF0(a, &t)) != 0) break;
            if ((err = func_L39_00510EF0(b, out)) != 0) break;
        } else {
            if ((err = func_L39_00510EF0(b, &t)) != 0) break;
            if ((err = func_L39_00510EF0(a, out)) != 0) break;
        }
        mode = 3;
        while (out->d[out->n - 1] != 0) {
            err = func_L39_00513808(&t, out, &u);
            mode = 0;
            if (err != 0) break;
            if (u.d[u.n - 1] == 0) break;
            err = func_L39_00513808(out, &u, &t);
            mode = 2;
            if (err != 0) break;
            if (t.d[t.n - 1] == 0) break;
            err = func_L39_00513808(&u, &t, out);
            mode = 1;
            if (err != 0) break;
        }
        if (err != 0) break;
        if (mode == 2) {
            err = func_L39_00510EF0(&u, out);
        } else if (mode == 1) {
            err = func_L39_00510EF0(&t, out);
        } else if (mode == 3) {
            if (t.d[t.n - 1] == 0) {
                err = 0x10A;
            } else {
                err = func_L39_00510EF0(&t, out);
            }
        }
    } while (0);
    func_L39_005128F8(&t);
    func_L39_005128F8(&u);
    return err;
}

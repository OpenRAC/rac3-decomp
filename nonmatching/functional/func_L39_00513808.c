/* functional: high. EXACT match (checker MATCH at level 39); ported from the sibling func_L39_00513470 (division with quotient) by dropping the quotient work. */
typedef struct BN_00513808 {
    s32 cap;
    s32 n;
    long *d;
} BN_00513808;

s32 func_L39_00513808(void *arg0, void *arg1, void *arg2) {
    BN_00513808 *a = arg0;
    BN_00513808 *b = arg1;
    BN_00513808 *r = arg2;
    BN_00513808 t;
    BN_00513808 u;
    s32 shift;
    s32 err;
    s32 na;
    s32 nb;
    s32 i;

    func_L39_005128E8((s32 *)&t);
    func_L39_005128E8((s32 *)&u);
    do {
        if (func_L39_00510F60(a, b) < 0) {
            err = func_L39_00510EF0(a, r);
            break;
        }
        if ((err = func_L39_005151E8(b, &shift)) != 0) break;
        err = 0x107;
        if (shift == 0x40) break;
        if (shift > 0) {
            if ((err = func_L39_00514EB8(shift, b)) != 0) break;
            if ((err = func_L39_00514EB8(shift, a)) != 0) break;
        }
        na = a->n;
        nb = b->n;
        if ((err = func_L39_00510EF0(a, r)) != 0) break;
        if (nb < na) {
            if ((err = func_L39_00515030(na - nb, r)) != 0) break;
        } else {
            if ((err = func_L39_00514AA0(b, r)) != 0) break;
        }
        if ((err = func_L39_00512A40(na, &u)) != 0) break;
        if ((err = func_L39_00512A40(2, &t)) != 0) break;
        for (i = na - nb - 1; i >= 0; i--) {
            if (func_L39_00510F60(r, b) >= 0) {
                if ((err = func_L39_00514AA0(b, r)) != 0) break;
            }
            if ((err = func_L39_00513AD8(a->d[i], r)) != 0) break;
            if (nb < r->n) {
                if ((err = func_L39_00513B90(r, b, &t, &u)) != 0) break;
                while (func_L39_00510F60(&u, r) > 0) {
                    if ((err = func_L39_00514AA0(b, &u)) != 0) break;
                }
                if (err != 0) break;
                if ((err = func_L39_00514AA0(&u, r)) != 0) break;
            }
        }
        if (err != 0) break;
        if (shift > 0) {
            func_L39_00515088(shift, r);
            func_L39_00515088(shift, a);
            func_L39_00515088(shift, b);
        }
        if (func_L39_00510F60(r, b) < 0) break;
        err = func_L39_00514AA0(b, r);
    } while (0);
    func_L39_005128F8(&t);
    func_L39_005128F8(&u);
    return err;
}

/* functional: high. 42 diffs, mostly one register swap (loop index vs borrow); same behaviour. */
typedef struct Big_00511268 {
    s32 cap;
    s32 count;
    unsigned long *words;
} Big_00511268;

extern s32 func_L39_00512A40(s32, Big_00511268 *);
extern s32 func_L39_00515180(s32, Big_00511268 *);
extern void func_L39_004F7510(void *, void *, u32);

s32 func_L39_00511268(Big_00511268 *a, Big_00511268 *b, Big_00511268 *r) {
    s32 m = b->count;
    s32 n = a->count;
    unsigned long *bw = b->words;
    unsigned long *aw = a->words;
    unsigned long *rw;
    s32 i;
    s32 borrow;
    s32 ret;

    if (n < m) {
        return 0x109;
    }
    if (r->cap < n) {
        ret = func_L39_00512A40(n + 1, r);
        if (ret != 0) {
            return ret;
        }
    }
    rw = r->words;
    {
    unsigned long d = aw[0] - bw[0];
    rw[0] = d;
    borrow = aw[0] < d;
    }
    for (i = 1; i < m; i++) {
        unsigned long d = aw[i] - bw[i];
        rw[i] = d;
        if (!borrow) {
            borrow = aw[i] < d;
        } else {
            unsigned long d1 = d - 1;
            rw[i] = d1;
            borrow = !(d1 < aw[i]);
        }
    }
    if (i == n) {
        if (borrow) {
            return 0x109;
        }
        return func_L39_00515180(n - 1, r);
    }
    if (!borrow) {
        func_L39_004F7510(&rw[i], &aw[i], (n - i) << 3);
        r->count = n;
        return 0;
    }
    while (i < n) {
        unsigned long d = aw[i] - borrow;
        rw[i] = d;
        borrow = aw[i] < d;
        i++;
    }
    if (borrow) {
        return 0x109;
    }
    while (n > 1 && r->words[n - 1] == 0) {
        n--;
    }
    r->count = n;
    return 0;
}

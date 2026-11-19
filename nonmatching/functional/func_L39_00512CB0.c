/* functional: high. 74 diffs, layout only (the retail hoists n*2 into a branch delay slot); same behaviour. */
typedef struct Big_00512CB0 {
    s32 cap;
    s32 count;
    unsigned long *words;
} Big_00512CB0;

extern s32 func_L39_00512A40(s32, Big_00512CB0 *);
extern s32 func_L39_00510EF0(Big_00512CB0 *, Big_00512CB0 *);
extern s32 func_L39_00514CF8(s32, Big_00512CB0 *);
extern void func_L39_005128F8(Big_00512CB0 *);

s32 func_L39_00512CB0(Big_00512CB0 *a, Big_00512CB0 *b, Big_00512CB0 *out) {
    Big_00512CB0 tmp;
    s32 n = b->count;
    s32 i;
    s32 ret;

    if (n < a->count) {
        return 0x108;
    }
    if (n == a->count) {
        i = n - 1;
        if (i < 0) {
            return 0x108;
        }
        while (b->words[i] == a->words[i]) {
            i--;
            if (i < 0) {
                return 0x108;
            }
        }
        if (b->words[i] < a->words[i]) {
            return 0x108;
        }
    }
    func_L39_005128E8((s32 *)&tmp);
    ret = func_L39_00512A40(n * 2 + 1, &tmp);
    if (ret == 0) {
        ret = func_L39_00510EF0(a, &tmp);
        if (ret == 0) {
            ret = func_L39_00514CF8(n, &tmp);
            if (ret == 0) {
                ret = func_L39_00513808(&tmp, b, out);
            }
        }
    }
    func_L39_005128F8(&tmp);
    return ret;
}

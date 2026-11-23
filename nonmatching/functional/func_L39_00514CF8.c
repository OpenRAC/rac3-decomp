/* functional: high. 102 diffs, register allocation and block order; same behaviour: shift x left by 'shift' 64-bit words, growing via a temp copy when capacity is short. */
typedef struct Big_00514CF8 {
    s32 cap;
    s32 count;
    unsigned long *words;
} Big_00514CF8;

extern s32 func_L39_00512A40(s32, Big_00514CF8 *);
extern void func_L39_005128F8(Big_00514CF8 *);
extern void func_L39_004F7538(void *, void *, u32);

s32 func_L39_00514CF8(s32 shift, Big_00514CF8 *x) {
    Big_00514CF8 tmp;
    s32 ret;
    s32 cnt;
    s32 newcnt;
    s32 bytes;

    if (shift <= 0) {
        return 0;
    }
    cnt = x->count;
    newcnt = cnt + shift;
    if (x->cap < newcnt) {
        bytes = shift << 3;
        func_L39_005128E8((s32 *)&tmp);
        ret = func_L39_00510EF0(x, &tmp);
        if (ret == 0) {
            ret = func_L39_00512A40(newcnt + 1, x);
            if (ret == 0) {
                func_L39_004F74E8(x->words, 0, bytes);
                func_L39_004F7510((u8 *)x->words + bytes, tmp.words, cnt << 3);
                if (x->words[newcnt - 1] != 0 || newcnt < 2) {
                    x->count = newcnt;
                } else {
                    do {
                        newcnt--;
                    } while (newcnt >= 2 && x->words[newcnt - 1] == 0);
                    x->count = newcnt;
                }
            }
        }
        func_L39_005128F8(&tmp);
        return ret;
    }
    bytes = shift << 3;
    func_L39_004F7538((u8 *)x->words + bytes, x->words, cnt << 3);
    func_L39_004F74E8(x->words, 0, bytes);
    while (newcnt > 1 && x->words[newcnt - 1] == 0) {
        newcnt--;
    }
    x->count = newcnt;
    return 0;
}

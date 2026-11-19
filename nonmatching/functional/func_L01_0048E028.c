/* functional: high. Same clamp (max then min with count-1) and store order as retail. */
extern f32 D_L01_001D8CCC;
extern f32 D_L01_001D8CA0;
extern s32 D_L01_001D8C7C;
extern s32 D_L01_001D8C78;
extern s32 D_L01_001E0958;

void func_L01_0048E028(void) {
    f32 off = D_L01_001D8CCC;
    f32 thr = D_L01_001D8CA0;
    s32 s = D_L01_001E0958;
    s32 cur;
    s32 lo;
    s32 hi;

    if (!(thr < off)) {
        thr = -thr;
        if (!(off < thr)) {
            return;
        }
    }
    if (s == 1 || s == 3) {
        cur = D_L01_001D8C7C + 1;
        D_L01_001D8C7C = cur;
    } else {
        cur = D_L01_001D8C7C - 1;
        D_L01_001D8C7C = cur;
    }
    lo = 0;
    if (-1 < cur) {
        lo = cur;
    }
    hi = D_L01_001D8C78;
    D_L01_001E0958 = 0;
    D_L01_001D8CCC = 0.0f;
    cur = hi - 1;
    if (lo < hi) {
        cur = lo;
    }
    D_L01_001D8C7C = cur;
}

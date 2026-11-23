/* functional: high. Near miss (7 diff at level 01 with -mvu0-use-vf0-vf2 and @ps2as, which the file would need; only the branch delay slot choice differs). Needs #include "vu0.h" for vec_add_ab. */
extern void func_0038CE50(void *, void *, f32);
extern void func_0038D000(void *, void *, void *);
extern void func_0038D080(void *, unsigned long);
extern void func_0038CE20(void *, void *, f32);

s32 func_L01_00439A98(u8 *obj, u8 *m, u8 *out, s32 index) {
    u8 *p = *(u8 **)(obj + 0x24);
    s32 cnt = *(s16 *)(p + 0x2E);
    u8 *tab;
    u8 *rec;
    s32 e;
    s32 n;
    s32 i;
    f32 k;
    if (cnt == 0) {
        return 0;
    }
    tab = p + (cnt << 4);
    index += (s32)tab;
    e = ((u8 *)index)[1];
    if (e == 0xFF) {
        return 0;
    }
    k = 0.0009765625f;
    rec = tab + (e << 4);
    func_0038CE50(m, rec, *(f32 *)(obj + 0x2C) * k);
    rec += 0x10;
    func_0038D000(m, m, obj + 0xC0);
    vec_add_ab(m, m, obj + 0x10);
    n = *(s16 *)(rec + 6);
    if (out != 0 && n > 0) {
        m = out;
        for (i = n; i != 0;) {
            i--;
            func_0038D080(m, *(unsigned long *)rec);
            rec += 8;
            func_0038CE20(m, m, *(f32 *)(obj + 0x2C) * k);
            *(f32 *)(m + 0xC) = 1.0f;
            m += 0x10;
        }
    }
    return n;
}

/* Near miss, ported from rac2-decomp's func_0029F840 (cross-game near pair). NEAR: VU0: retail uses COP2 (4 words lqc2/vmul-style .word 0x4bc20868 etc.) plus lq vs ld; plain C cannot produce */
extern void func_0038CE50(void *, void *, float);
extern void func_0038D000(void *, void *, void *);
extern void func_00282CC0(void *, void *, void *);
extern void func_0038D080(void *, unsigned long long);
extern void func_0038CE20(void *, void *, float);

int func_L01_00439A98(char *obj, char *m, char *out, int index) {
    char *p = *(char **)(obj + 0x24);
    int cnt = *(short *)(p + 0x2E);
    int tab;
    char *rec;
    int n;
    int i;
    int e;
    char *dst;
    float k;
    float s;
    if (cnt == 0) {
        goto fail;
    }
    tab = (int)p + cnt * 16;
    index += tab;
    e = ((unsigned char *)index)[1];
    p = m;
    if (e == 0xFF) {
        do {
fail:
            return 0;
        } while (0);
    }
    do {
        s = *(float *)(obj + 0x2C);
    } while (0);
    k = 0.0009765625f;
    do {
        e *= 16;
    } while (0);
    rec = (char *)tab + e;
    func_0038CE50(p, rec, s * k);
    rec += 0x10;
    func_0038D000(m, m, obj + 0xC0);
    func_00282CC0(m, m, obj + 0x10);
    do {
        n = *(short *)(rec + 6);
    } while (0);
    if (out != 0 && n > 0) {
        dst = out;
        for (i = n; i != 0;) {
            i--;
            func_0038D080(dst, *(unsigned long long *)rec);
            rec += 8;
            func_0038CE20(dst, dst, *(float *)(obj + 0x2C) * k);
            *(float *)(dst + 0xC) = 1.0f;
            dst += 0x10;
        }
    }
    return n;
}
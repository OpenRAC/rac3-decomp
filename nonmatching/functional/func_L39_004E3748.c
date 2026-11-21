/* functional: high. check shows 3 register-name diffs only (second byte-length temp in a0 vs v1); same calls, branches and results. Uses N_004E3B68-style struct locals (self-contained here). */
typedef struct N_004E3748 {
    s32 f[8];
} N_004E3748;

typedef struct V_004E3748 {
    s32 (*f0)(s32, u8 *, s32, s32, s32, s32);
} V_004E3748;

typedef struct K_004E3748 {
    s32 f0;
    s32 f4[17];
    s32 f48;
    s32 _p4C[3];
    V_004E3748 *f58;
} K_004E3748;

typedef struct S_004E3748 {
    s32 _p0[2];
    K_004E3748 *f8;
} S_004E3748;

extern void func_L39_004FC370(N_004E3748 *);
extern void func_L39_004FC228(N_004E3748 *);
extern s32 func_L39_004FC158(s32 *);
extern void func_L39_004FC780(u8 *, s32, N_004E3748 *);
extern s32 func_L39_004E38F0(N_004E3748 *, N_004E3748 *, K_004E3748 *);
extern s32 func_L39_004FC8C0(N_004E3748 *, u8 *);

s32 func_L39_004E3748(void *ctx, s32 mode, u8 *to, u32 *outlen, u32 tlen, s32 a5, s32 a6, s32 a7) {
    N_004E3748 a;
    N_004E3748 b;
    K_004E3748 *key;
    s32 len;
    s32 n;
    s32 i;
    s32 ret;
    s32 m;

    ret = 1;
    if (mode != 1 && mode != 10) {
        return 2;
    }
    func_L39_004FC370(&a);
    func_L39_004FC370(&b);
    key = ((S_004E3748 *)ctx)->f8;
    len = (func_L39_004FC158(key->f4) + 7) / 8;
    if (tlen < len) {
        ret = 1;
        goto done;
    }
    if (key->f58->f0(key->f48, to, len, a5, a6, a7) != 0) {
        goto done;
    }
    func_L39_004FC780(to, len, &a);
    if (func_L39_004E38F0(&b, &a, key) != 0) {
        goto done;
    }
    m = (func_L39_004FC158(b.f) + 7) / 8;
    if (len < m) {
        goto done;
    }
    n = func_L39_004FC8C0(&b, to + (len - m));
    for (i = 0; i < len - n; i++) {
        to[i] = 0;
    }
    *outlen = len;
    ret = 0;
done:
    func_L39_004FC228(&b);
    func_L39_004FC228(&a);
    return ret;
}

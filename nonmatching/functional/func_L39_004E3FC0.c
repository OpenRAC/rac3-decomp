/* functional: high. Retail keeps ret and a7 in stack slots (0x44/0x40) so bytes differ; same calls, order, error exits. Needs file context types N_004E3B68 and B_004E3CB8 (declared earlier in L39_004E3B68.c). */
typedef struct V_004E3FC0 {
    s32 _p0;
    s32 (*f4)(u8 *, u32 *, u8 *, s32, s32, s32);
} V_004E3FC0;

typedef struct K_004E3FC0 {
    s32 f0;
    s32 f4[17];
    s32 f48;
    s32 f4C;
    s32 _p50;
    s32 f54;
    V_004E3FC0 *f58;
} K_004E3FC0;

typedef struct S_004E3FC0 {
    s32 _p0[2];
    K_004E3FC0 *f8;
} S_004E3FC0;


s32 func_L39_004E3FC0(void *ctx, s32 mode, u8 *to, u32 *outlen, s32 tlen, void *from, s32 flen, s32 a7) {
    N_004E3B68 a;
    N_004E3B68 b;
    K_004E3FC0 *key;
    B_004E3CB8 *blind;
    s32 len;
    s32 n;
    s32 ret;

    ret = 1;
    blind = 0;
    if (mode != 4 && mode != 9) {
        return 2;
    }
    func_L39_004FC370(&a);
    func_L39_004FC370(&b);
    key = ((S_004E3FC0 *)ctx)->f8;
    len = (func_L39_004FC158(key->f4) + 7) / 8;
    if ((u32)tlen < (u32)len || (u32)len < (u32)flen) {
        ret = 1;
        goto done;
    }
    blind = func_L39_004FC3C8();
    if (blind == 0) {
        goto done;
    }
    blind->f10C = key->f4C;
    if (((void *(*)(void *, u32, N_004E3B68 *))func_L39_004FC780)(from, flen, &a) == 0) {
        goto done;
    }
    ret = func_L39_004FCE30(key->f54, &b, &a, 0, 0, blind);
    if (ret != 0) {
        goto done;
    }
    n = func_L39_004FC8C0(&b, (s32)to);
    if (len < n) {
        goto done;
    }
    ret = key->f58->f4(to, outlen, to, n, len, a7);
done:
    if (blind != 0) {
        func_L39_004FC448(blind);
    }
    func_L39_004FC228(&b);
    func_L39_004FC228(&a);
    return ret;
}

/* functional: medium. Written from the PAL asm only (no draft): control flow, offsets, constants, call order and delay-slot stores traced by hand. Unsure: func_L04_004FE9E0, func_L01_004F0AB0 and func_L01_004F02D8 are called with no visible argument setup (declared void(void); if they read a0 from the caller, the gate must show it). Compiles, 382 diffs vs bytes. */
typedef int Q_4FFC48 __attribute__((mode(TI)));
typedef union {
    u8 b[0x3000];
    s16 h[0x1800];
    s32 i[0xC00];
    f32 f[0xC00];
    Q_4FFC48 q[0x300];
} H_4FFC48;
extern u8 D_001A4BE0[];
extern u8 D_001A4C60[];
extern void func_L01_00511B50(s32, void *, void *);
extern f32 func_L01_00511408(void *);
extern f32 func_L01_005114B0(void *);
extern void func_L01_00511588(void *, void *, f32);
extern void func_L01_00511508(void *, void *, f32);
extern void func_L01_00511320(void *, void *);
extern f32 func_0038CEA8(void *);
extern f32 func_0038CE68(void *, void *);
extern void func_0038CF68(void *, void *, f32);
extern void func_0038CE20(void *, void *, f32);
extern void func_L01_004F0AB0(void);
extern void func_L04_004FE9E0(void);
extern void func_L01_004F02D8(void);
extern f32 func_L01_004F05F0(void *);

void func_L04_004FFC48(void) {
    H_4FFC48 *h = (H_4FFC48 *)D_001A4BE0;
    f32 *P = (f32 *)D_001A4C60;
    f32 prev[4] __attribute__((aligned(16)));
    f32 snap[4] __attribute__((aligned(16)));
    f32 tmp[4] __attribute__((aligned(16)));
    f32 tmp2[4] __attribute__((aligned(16)));
    f32 z, lim, len, d, w;
    s32 st;

    *(Q_4FFC48 *)prev = *(Q_4FFC48 *)P;
    func_L01_00511B50(h->i[0x538 / 4], D_001A4C60 + 0x80, D_001A4C60 + 0x10);
    st = h->i[0x25C4 / 4];
    if (st == 0x14 || st == 0x5F || st == 0x5C || st == 0xA2 || st == 0x86) {
        if (h->h[0x1F0 / 2] == 0) {
            lim = h->f[0x284 / 4] - 0.0199999996f;
            if (lim < func_L01_00511408(&h->b[0xF0]))
                func_L01_00511588(&h->b[0xF0], &h->b[0xF0], lim);
        }
        z = func_L01_005114B0(&h->b[0xF0]);
        if (z < 0.0f) {
            lim = -h->f[0x24C / 4];
            if (z < lim) {
                w = lim - 0.100000001f;
                if (z < w) z = w;
                if (0.0f < z) z = 0.0f;
                func_L01_00511508(&h->b[0xF0], &h->b[0xF0], z);
            }
        }
        if (h->i[0x25C4 / 4] == 0x14) {
            len = func_0038CEA8(&h->b[0xF0]);
            lim = h->f[0x284 / 4] - 0.0199999996f;
            if (lim < len)
                func_0038CE20(&h->b[0xF0], &h->b[0xF0], lim / len);
        }
    } else if (h->i[0x25CC / 4] != 0xD && h->i[0x25CC / 4] != 0xE && st != 0x44 && h->h[0x1F0 / 2] == 0) {
        len = func_0038CEA8(&h->b[0xF0]);
        lim = h->f[0x284 / 4] - 0.0199999996f;
        if (lim < len)
            func_0038CF68(&h->b[0xF0], &h->b[0xF0], lim);
    }
    /* P.xyz += velocity, then P.xyz += the h+0x9E0 offset (cleared afterwards) */
    P[0] += h->f[0xF0 / 4];
    P[1] += h->f[0xF4 / 4];
    P[2] += h->f[0xF8 / 4];
    P[0] += h->f[0x9E0 / 4];
    P[1] += h->f[0x9E4 / 4];
    P[2] += h->f[0x9E8 / 4];
    ((long *)&h->b[0x9E0])[0] = 0;
    ((long *)&h->b[0x9E0])[1] = 0;
    h->b[0x2A7] = 0;
    h->i[0x28C / 4] = 0;
    if (func_0038CEA8(&h->b[0x100]) <= 0.0000999999975f) {
        func_L01_004F0AB0();
        func_L04_004FE9E0();
        *(Q_4FFC48 *)&h->f[0x110 / 4] = *(Q_4FFC48 *)P;
        h->f[0x110 / 4] = P[0] - prev[0];
        h->f[0x114 / 4] = P[1] - prev[1];
        h->f[0x118 / 4] = P[2] - prev[2];
        func_L01_004F02D8();
    } else {
        func_L04_004FE9E0();
    }
    /* h+0x120: movement of this step; h+0x130/0x140: its component along the velocity / the rest */
    *(Q_4FFC48 *)&h->f[0x120 / 4] = *(Q_4FFC48 *)P;
    h->f[0x120 / 4] = P[0] - prev[0];
    h->f[0x124 / 4] = P[1] - prev[1];
    h->f[0x128 / 4] = P[2] - prev[2];
    h->q[0x130 / 16] = h->q[0x120 / 16];
    h->q[0x140 / 16] = h->q[0x120 / 16];
    func_0038CF68(&h->b[0x120], &h->b[0x120], 1.0f);
    d = func_0038CE68(&h->b[0x120], &h->b[0xF0]);
    if (d < 0.0f) d = 0.0f;
    func_0038CF68(&h->b[0x120], &h->b[0xF0], d);
    *(Q_4FFC48 *)tmp = h->q[0xF0 / 16];
    func_L01_00511320(tmp, tmp);
    func_L01_00511320(&h->b[0x140], &h->b[0x140]);
    func_0038CF68(&h->b[0x140], &h->b[0x140], 1.0f);
    d = func_0038CE68(&h->b[0x140], tmp);
    if (d < 0.0f) d = 0.0f;
    func_0038CF68(&h->b[0x140], tmp, d);
    *(Q_4FFC48 *)tmp2 = h->q[0xF0 / 16];
    func_L01_00511588(tmp2, tmp2, 0.0f);
    func_L01_00511588(&h->b[0x130], &h->b[0x130], 0.0f);
    func_0038CF68(&h->b[0x130], &h->b[0x130], 1.0f);
    d = func_0038CE68(&h->b[0x130], tmp2);
    if (d < 0.0f) d = 0.0f;
    func_0038CF68(&h->b[0x130], tmp2, d);
    h->f[0x170 / 4] = func_0038CEA8(&h->b[0x120]);
    h->f[0x174 / 4] = func_L01_00511408(&h->b[0x120]);
    *(Q_4FFC48 *)snap = h->q[0x120 / 16];
    h->f[0x178 / 4] = func_L01_004F05F0(snap);
    h->f[0x180 / 4] = func_L01_005114B0(&h->b[0x120]);
    if (h->f[0x178 / 4] < 0.0f) h->f[0x178 / 4] = 0.0f;
    *(Q_4FFC48 *)snap = *(Q_4FFC48 *)P;
    if (0.0000999999975f < func_0038CEA8(&h->b[0x100])) {
        P[0] += h->f[0x100 / 4];
        P[1] += h->f[0x104 / 4];
        P[2] += h->f[0x108 / 4];
        w = h->f[0x10C / 4];
        ((long *)&h->b[0x100])[0] = 0;
        ((long *)&h->b[0x100])[1] = 0;
        h->f[0x10C / 4] = w;
        func_L01_004F0AB0();
        func_L04_004FE9E0();
        *(Q_4FFC48 *)&h->f[0x110 / 4] = *(Q_4FFC48 *)P;
        h->f[0x110 / 4] = P[0] - prev[0];
        h->f[0x114 / 4] = P[1] - prev[1];
        h->f[0x118 / 4] = P[2] - prev[2];
        func_L01_004F02D8();
    }
    *(Q_4FFC48 *)&h->f[0x150 / 4] = *(Q_4FFC48 *)P;
    h->f[0x150 / 4] = P[0] - snap[0];
    h->f[0x154 / 4] = P[1] - snap[1];
    h->f[0x158 / 4] = P[2] - snap[2];
    w = h->f[0x10C / 4];
    h->f[0x184 / 4] = func_0038CEA8(&h->b[0x150]);
    h->f[0x15C / 4] = w;
    h->f[0x10C / 4] = 0.0f;
    *(Q_4FFC48 *)&h->f[0x110 / 4] = *(Q_4FFC48 *)P;
    h->f[0x110 / 4] = P[0] - prev[0];
    h->f[0x114 / 4] = P[1] - prev[1];
    h->f[0x118 / 4] = P[2] - prev[2];
    h->f[0x17C / 4] = 0.0f;
    if (0.00400000019f < h->f[0x174 / 4]) {
        d = h->f[0x118 / 4] / h->f[0x174 / 4];
        h->f[0x17C / 4] = d;
        if (0.5f < d) h->f[0x17C / 4] = 0.5f;
        else if (d < -0.5f) h->f[0x17C / 4] = -0.5f;
    }
    if (1.04000008f < h->f[0x170 / 4]) {
        func_0038CE20(&h->b[0x110], &h->b[0x110], 1.04000008f / h->f[0x170 / 4]);
        h->f[0x170 / 4] = 1.04000008f;
    }
}

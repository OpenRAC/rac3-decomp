/* functional: high. Rewritten from the PAL asm using the NTSC-U twin draft only as a map: every state threshold, frame count (0x2E, 0x22, 0xC, 8, 7, 10), float constant (read as hex from the asm; PAL values differ from NTSC) and call argument checked; VU0 xyz adds are plain C (w untouched, z of the first two kept as retail). 593 diffs vs bytes: not close, scheduling/regalloc. */
typedef int Q_500CF8 __attribute__((mode(TI)));
typedef union {
    u8 b[0x3000];
    s16 h[0x1800];
    s32 i[0xC00];
    f32 f[0xC00];
    Q_500CF8 q[0x300];
} H_500CF8;
extern u8 D_001A4BE0[];
extern s32 D_001D673C[];
extern u8 D_L04_001E2840[];
extern f32 D_001DBC98[];
extern void func_L01_004EE850(s32, f32);
extern void func_L04_00500298(f32);
extern void func_L01_004F0558(f32, f32);
extern void func_003C4138(void *, f32, f32);
extern void func_L01_004EF128(f32, f32);
extern void func_L01_00511588(void *, void *, f32);
extern void func_L01_00511178(void *, void *, f32);
extern void func_L01_004EEDD0(s32, f32, f32, f32);
extern f32 func_0038CE68(void *, void *);
extern void func_0038D000(void *, void *, void *);
extern void func_0038CFB8(void *, void *, f32);
extern s32 func_003D3CB0(void *, void *, s32, void *, s32);
extern s32 func_L01_004606E8(s32, s32, s32, s32);
extern void func_L01_004EE388(void *);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern f32 func_0038DBA0(f32, f32);
extern void func_L01_00511508(void *, void *, f32);
extern void func_0038CF68(void *, void *, f32);
extern f32 func_L01_00448728(void *, void *, s32, f32, f32, f32, f32);
extern f32 func_0038DB00(f32, f32);
extern void func_L01_004E5290(f32, f32, f32);
extern f32 func_L01_00511408(void *);

void func_L04_00500CF8(void) {
    H_500CF8 *h = (H_500CF8 *)D_001A4BE0;
    f32 v[4] __attribute__((aligned(16)));
    f32 a[4] __attribute__((aligned(16)));
    f32 b[4] __attribute__((aligned(16)));
    f32 c[4] __attribute__((aligned(16)));
    f32 d[4] __attribute__((aligned(16)));
    f32 mag, tmp, turn, old;
    Q_500CF8 save;
    s32 blocked = 0;
    s32 st = h->i[0x25C4 / 4];

    if (st == 0xA2) {
        func_L01_004EE850(0, 0.194000006f);
        h->f[0x1A0 / 4] = h->f[0x98 / 4];
        func_L04_00500298(0.0280000009f);
        h->f[0x1B4 / 4] = h->f[0x174 / 4];
        return;
    }
    if (st == 0xA) {
        func_L01_004F0558(0.699999988f, 0.0f);
        h->q[0x160 / 16] = h->q[0x9E0 / 16];
        h->f[0x1B4 / 4] = h->f[0x174 / 4];
        return;
    }
    if (st == 0x10) {
        if (h->i[0x1B8 / 4] >= 0x2E)
            func_003C4138(&h->b[0x4F0], 0.0100000007f, 0.00280000013f);
        h->f[0x1B0 / 4] = h->i[0x1B8 / 4] < 0x2E ? h->f[0x424 / 4] : 0.0700000077f;
        func_L01_004EF128(0.0175999999f, 0.0180000011f);
        func_L01_00511588(&h->b[0xF0], &h->b[0xF0], 0.0f);
        func_L01_00511178(&h->b[0xF0], &h->b[0xF0], h->f[0x1B4 / 4]);
        return;
    }
    if (st == 0x1B) {
        if (h->i[0x1B8 / 4] >= 0x22) {
            func_L01_004EEDD0(0, 0.0576000027f, 0.288000017f, 0.300196648f);
            func_L04_00500298(0.00800000038f);
        }
        if (h->f[0xC18 / 4] >= 13.0f && h->f[0xC18 / 4] <= 30.0f) {
            if (h->f[0xC18 / 4] > 27.0f)
                func_003C4138(&h->b[0x48C], 0.0f, 0.00320000015f);
            else
                func_003C4138(&h->b[0x48C], 0.0400000028f, 0.00320000015f);
        }
        goto rotate;
    }
    if (st == 0x48) {
        if (h->f[0xC18 / 4] >= 5.0f && h->f[0xC18 / 4] <= 18.0f) {
            if (h->f[0xC18 / 4] > 15.0f)
                func_003C4138(&h->b[0x48C], 0.0f, 0.00320000015f);
            else
                func_003C4138(&h->b[0x48C], 0.0250000022f, 0.00320000015f);
        }
    rotate:
        v[1] = 0.0f;
        v[0] = h->f[0x48C / 4];
        v[2] = func_0038CE68(&h->b[0xF0], &h->b[0x20]);
        func_0038D000(&h->b[0xF0], v, h);
        return;
    }
    if (st == 0xB) {
        if (h->h[0x1434 / 2] || (h->i[0x16B0 / 4] == 1 && func_L01_004606E8(40, 2, 0, 0))) {
            func_L01_004EE388(h);
        } else {
            h->q[0x190 / 16] = h->q[0x450 / 16];
            h->f[0x1A0 / 4] = h->f[0x494 / 4];
            func_L01_004EEDD0(0, 0.0576000027f, 0.288000017f, 0.139626354f);
        }
        h->f[0x1B4 / 4] = h->i[0x4A4 / 4] == 3 ? 0.0f : h->f[0x4A8 / 4];
        if (!D_001D673C[0] && h->f[0x33C / 4] < 3.0f && h->i[0x1B8 / 4] >= 12) {
            func_0038CFB8(v, &h->b[0x110], 0.569999993f);
            v[0] += h->f[0x80 / 4];
            v[1] += h->f[0x84 / 4];
            v[2] = h->f[0x308 / 4];
            *(Q_500CF8 *)b = *(Q_500CF8 *)v;
            *(Q_500CF8 *)a = *(Q_500CF8 *)v;
            b[2] -= 3.0f;
            a[2] += 2.0f;
            if (!func_003D3CB0(a, b, 2, 0, 0)) {
                func_0038CFB8(v, &h->b[0x110], 5.5f);
                v[0] += h->f[0x80 / 4];
                v[1] += h->f[0x84 / 4];
                v[2] = h->f[0x308 / 4];
                *(Q_500CF8 *)d = *(Q_500CF8 *)v;
                *(Q_500CF8 *)c = *(Q_500CF8 *)v;
                d[2] -= 3.0f;
                c[2] += 2.0f;
                if (!func_003D3CB0(c, d, 2, 0, 0)) {
                    h->i[0x4AC / 4] = 0;
                    blocked = 1;
                }
            }
        }
        if (h->b[0x4FD]) {
            if (!blocked) {
                mag = h->f[0x2838 / 4] * 0.110000007f;
                if (mag < 0.0400000028f) mag = 0.0400000028f;
                func_003C4138(&h->b[0x4AC], mag, 0.0188000016f);
                h->f[0x1B4 / 4] = h->f[0x174 / 4];
            }
        } else if (h->b[0x46E] && h->h[0x47E / 2] < 10) {
            func_003C4138(&h->b[0x4AC], 0.0f, 0.00320000015f);
        } else if (!blocked) {
            func_003C4138(&h->b[0x4AC], 0.0839999989f, 0.00320000015f);
        }
        if (!h->b[0x25F4]) {
            h->f[0xF0 / 4] = func_0038D098(h->f[0x490 / 4]) * h->f[0x4AC / 4];
            h->f[0xF4 / 4] = func_0038D0B0(h->f[0x490 / 4]) * h->f[0x4AC / 4];
        } else {
            func_L01_00511588(v, &h->b[0x440], h->f[0x4AC / 4]);
            func_L01_00511508(v, v, 0.0f);
            func_L01_00511588(&h->b[0xF0], &h->b[0xF0], 0.0f);
            h->f[0xF0 / 4] += v[0];
            h->f[0xF4 / 4] += v[1];
            h->f[0xF8 / 4] += v[2];
        }
        if (!h->b[0x25F4] && !h->b[0x4FD]) {
            mag = h->f[0x4A8 / 4] * func_0038D0B0(func_0038DBA0(h->f[0x494 / 4], h->f[0x490 / 4]));
            h->f[0xF0 / 4] += func_0038D098(h->f[0x494 / 4]) * mag;
            h->f[0xF4 / 4] += func_0038D0B0(h->f[0x494 / 4]) * mag;
        }
        func_L01_004F0558(0.699999988f, 0.0f);
        h->q[0x160 / 16] = h->q[0x9E0 / 16];
        return;
    }
    if (st == 0x11) {
        h->f[0x1A0 / 4] = h->f[0x4CC / 4];
        h->q[0x190 / 16] = h->q[0x4C0 / 16];
        if (h->i[0x1B8 / 4] >= 8)
            func_L01_004EEDD0(-1, 0.0604800023f, 0.288000017f, 0.237364784f);
        if (h->i[0x1B8 / 4] >= 7) {
            if (!h->h[0x368 / 2]) {
                h->f[0xF0 / 4] = func_0038D098(h->f[0x1A0 / 4]) * 0.0980000123f;
                h->f[0xF4 / 4] = func_0038D0B0(h->f[0x1A0 / 4]) * 0.0980000123f;
            } else {
                func_L01_00511588(&h->b[0xF0], &h->b[0xF0], 0.0f);
                func_0038CF68(v, &h->b[0x190], 0.0980000123f);
                h->f[0xF0 / 4] += v[0];
                h->f[0xF4 / 4] += v[1];
                h->f[0xF8 / 4] += v[2];
            }
        }
        h->f[0x1B4 / 4] = h->f[0x174 / 4];
        return;
    }
    if (st == 0x86 && !D_001D673C[0]) {
        func_L01_004EEDD0(0, 0.0576000027f, 0.288000017f, h->f[0x464 / 4]);
        h->i[0x1B4 / 4] = 0;
        return;
    }
    if (st == 0x2C) {
        tmp = h->f[0x98 / 4];
        h->f[0x1A8 / 4] = func_L01_00448728(&tmp, &h->b[0x1A4], 0, h->f[0x1A0 / 4], 0.0259199999f, 0.288000017f, 0.146607667f);
        func_L01_004E5290(0.0f, 0.0f, func_0038DB00(tmp, h->f[0x98 / 4]));
    } else {
        save = h->q[0x190 / 16];
        old = h->f[0x1A0 / 4];
        if (h->h[0x1434 / 2] || (h->i[0x16B0 / 4] == 1 && func_L01_004606E8(40, 2, 0, 0))) {
            h->q[0x190 / 16] = *(Q_500CF8 *)(D_L04_001E2840 + 0x380);
            h->f[0x1A0 / 4] = *(f32 *)(D_L04_001E2840 + 0x18);
        }
        func_L01_004EEDD0(0, 0.0576000027f, 0.288000017f, h->f[0x464 / 4]);
        if (h->h[0x1434 / 2] || (h->i[0x16B0 / 4] == 1 && func_L01_004606E8(40, 2, 0, 0))) {
            h->f[0x1A0 / 4] = old;
            h->q[0x190 / 16] = save;
            h->f[0x1438 / 4] = old;
            h->q[0x1420 / 16] = save;
        }
    }
    func_L01_004F0558(0.699999988f, 0.0f);
    h->q[0x160 / 16] = h->q[0x9E0 / 16];
    turn = 0.00800000038f;
    if (h->f[0x1B0 / 4] < D_001DBC98[0] * 0.0200000014f * 0.200000003f) {
        if (h->i[0x25CC / 4] == 2) {
            mag = h->f[0xA04 / 4];
            tmp = func_L01_00511408(&h->b[0xF0]);
            func_003C4138(&tmp, 0.0f, mag);
            func_L01_00511588(&h->b[0xF0], &h->b[0xF0], tmp);
            return;
        }
        if (h->h[0x36A / 2]) turn = 0.00439999998f;
        else if (h->h[0x4F4 / 2]) turn = 0.000800000038f;
        else turn = 0.00320000015f;
    }
    func_L04_00500298(turn);
}

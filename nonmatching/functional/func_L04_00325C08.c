/* functional: medium. Rewritten from the asm, no draft. Effect-burst spawner called by func_L04_00325460 (a1, the basis, is unused here; a2 is an offset added to the spawn vector, f12 an extra scale). All loop bodies follow the asm call by call, with the PAL scalings: counts through (n*5+2)/6, the floats D_L04_001DC7A8/7AC through K=210000.0f. VU0 vadd.xyz is scalar (w kept), the quad copy/zero are 128-bit. Callee prototypes follow the neighbours' matched calls (ints a0..t3 then stack; floats f12..). Unsure: the exact meaning of func_L01_00443A18 vs func_003824E0 (two random-range helpers, both (lo, hi)); the particle byte fields p[2], p[9] (palette/flag bytes, copied as retail does). Not byte-matched. */
__asm__(".extern D_L04_001DC7B0, 4");
__asm__(".extern D_L04_001DC7A8, 4");
__asm__(".extern D_L04_001DC7AC, 4");
typedef int u128_00325C08 __attribute__((mode(TI)));
extern s32 D_L04_001DC7B0;
extern f32 D_L04_001DC7A8;
extern f32 D_L04_001DC7AC;
extern s32 D_001D52F0[];
extern u8 D_L04_001E2840[];
extern u8 D_001D66B0[];
extern u8 *D_L04_0021FD88[];
extern u8 *D_L04_0021FC18[];
extern u8 *func_L01_0046FB40(void *, void *, s32, s32, s32, s32, s32, s32, f32, f32, f32);
extern u8 *func_L01_004713C8(void *, void *, s32, s32, s32, s32, s32, s32, f32, f32, f32);
extern u8 *func_L01_00470668(void *, void *, s32, f32);
extern void func_L01_002F9578(void *, void *, void *, s32, s32, s32, s32, s32, f32);
extern void func_L01_0044AF78(void *, void *, void *, s32, s32, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32, f32, f32, f32);
extern u8 *func_L01_004669B0(void *, f32, f32, f32, f32, s32, void *, u32, s32);
extern f32 func_0038D160(f32, f32);
extern f32 func_L01_00443A18(f32, f32);
extern f32 func_003824E0(f32, f32);
extern s32 func_00382498(s32, s32);
extern f32 func_0038DAB8(f32, f32);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern void func_0038CE20(void *, void *, f32);
extern void func_003C4840(void *, void *, f32);
extern void func_0038D850(void *, void *, void *);
extern void func_00382760(void *, f32, f32, f32);
void func_L04_00325C08(u8 *m, void *basis, f32 *off, f32 extra) {
    u8 *vars = *(u8 **)(m + 0x68);
    f32 pos[4] __attribute__((aligned(16)));
    f32 v[4] __attribute__((aligned(16)));
    f32 w[4] __attribute__((aligned(16)));
    f32 K = 210000.0f;
    f32 fa, fb, scale;
    f32 ang, spd, up, r;
    s32 i, n, rs, sgn;
    u8 *p;
    u8 *pl;

    scale = *(f32 *)(vars + 0x14);
    fa = D_L04_001DC7A8 * scale * K;
    fb = D_L04_001DC7AC * scale * K;
    p = func_L01_0046FB40(m + 0x10, off, (D_L04_001DC7B0 * 5 + 2) / 6, 0x388EF7, 0, 100, 0, 0, fa, fb, 0.0f);
    if (p) {
        p[2] = *D_L04_0021FD88[0];
        p[9] = 0xF0;
    }
    p = func_L01_0046FB40(m + 0x10, off, (D_L04_001DC7B0 * 5 + 2) / 6, 0x63F7, 0, 100, 0, 0, fa, fb, 0.0f);
    if (p) {
        p[2] = *D_L04_0021FD88[0];
        p[9] = 0xF0;
    }
    for (i = 1; i >= 0; i--) {
        p = func_L01_0046FB40(m + 0x10, off, (D_L04_001DC7B0 * 5 + 2) / 6, 0x388EF7, 0, 0x7F, 0, 0, fa, fb, 0.0f);
        if (p) {
            p[2] = D_L04_0021FC18[0x170 / 4][5];
            p[9] = 0xF0;
        }
    }
    for (i = 1; i >= 0; i--) {
        p = func_L01_0046FB40(m + 0x10, off, (D_L04_001DC7B0 * 5 + 2) / 6, 0x388EF7, 0, 0x7F, 0, 0, fa, fb, 0.0f);
        if (p) {
            p[2] = D_L04_0021FC18[0x170 / 4][6];
            p[9] = 0xF0;
        }
    }

    /* burst type 1 (count at +0x20): two particles per round */
    for (i = 0; i < *(s32 *)(vars + 0x20); i++) {
        pl = D_L04_001E2840 + D_001D52F0[0] * 0x460;
        ang = func_0038D160(*(f32 *)(pl + 0) - *(f32 *)(m + 0x10), *(f32 *)(pl + 4) - *(f32 *)(m + 0x14));
        rs = (s32)func_L01_00443A18(2.0f, 5.0f);
        n = func_00382498(30, 50);
        pos[0] = *(f32 *)(m + 0x10) + func_L01_00443A18(0.0f, 0.1f) * *(f32 *)(vars + 0x14);
        pos[1] = *(f32 *)(m + 0x14) + func_L01_00443A18(0.0f, 0.1f) * *(f32 *)(vars + 0x14);
        pos[2] = *(f32 *)(m + 0x18) + func_L01_00443A18(0.0f, 0.1f) * *(f32 *)(vars + 0x14);
        up = func_003824E0(0.6f, 1.0f) * *(f32 *)(vars + 0x14);
        spd = func_003824E0(9.0f, 12.0f) * *(f32 *)(vars + 0x14);
        ang = func_0038DAB8(ang, func_L01_00443A18(0.0f, 1.3962634f));
        spd = spd * 0.020000001f;
        v[0] = func_0038D098(ang) * spd;
        v[1] = func_0038D0B0(ang) * spd;
        v[2] = 0.0f;
        spd = func_003824E0(0.0f, 12.0f) * *(f32 *)(vars + 0x14);
        v[2] = spd * 0.020000001f;
        v[0] += off[0];
        v[1] += off[1];
        v[2] += off[2];
        p = func_L01_004713C8(pos, v, (n * 5 + 2) / 6, 0x407FFF, rs, 0x7F, 0x7F, 1, up * K, *(f32 *)(vars + 0x14) * 0.01f * K, 0.00584f);
        if (p) {
            p[9] = 0xF4;
        }
        p = func_L01_004713C8(pos, v, (n * 5 + 2) / 6, 0x20FF, -(rs * 2), 0x30, 0x30, 0, up * 6.0f * K, *(f32 *)(vars + 0x14) * 0.02f * K, 0.00584f);
        if (p) {
            p[2] = *D_L04_0021FC18[0xD4 / 4];
            p[9] = 0xF4;
        }
    }

    /* burst type 2 (count at +0x24) */
    for (i = 0; i < *(s32 *)(vars + 0x24); i++) {
        pl = D_L04_001E2840 + D_001D52F0[0] * 0x460;
        ang = func_0038D160(*(f32 *)(pl + 0) - *(f32 *)(m + 0x10), *(f32 *)(pl + 4) - *(f32 *)(m + 0x14));
        rs = (s32)func_L01_00443A18(2.0f, 5.0f);
        n = func_00382498(30, 50);
        pos[0] = *(f32 *)(m + 0x10) + func_L01_00443A18(0.0f, 0.1f) * *(f32 *)(vars + 0x14);
        pos[1] = *(f32 *)(m + 0x14) + func_L01_00443A18(0.0f, 0.1f) * *(f32 *)(vars + 0x14);
        pos[2] = *(f32 *)(m + 0x18) + func_L01_00443A18(0.0f, 0.1f) * *(f32 *)(vars + 0x14);
        up = func_003824E0(0.75f, 1.5f) * *(f32 *)(vars + 0x14);
        spd = func_003824E0(9.0f, 12.0f) * *(f32 *)(vars + 0x14);
        ang = func_0038DAB8(ang, func_L01_00443A18(0.0f, 1.3962634f));
        spd = spd * 0.020000001f;
        v[0] = func_0038D098(ang) * spd;
        v[1] = func_0038D0B0(ang) * spd;
        v[2] = 0.0f;
        spd = func_003824E0(0.0f, 12.0f) * *(f32 *)(vars + 0x14);
        v[2] = spd * 0.020000001f;
        v[0] += off[0];
        v[1] += off[1];
        v[2] += off[2];
        p = func_L01_004713C8(pos, v, (n * 5 + 2) / 6, 0x8FFF, rs, 0x7F, 0x7F, 5, up * K, *(f32 *)(vars + 0x14) * 0.01f * K, 0.00584f);
        if (p) {
            p[9] = 0xF4;
        }
    }

    /* burst type 3 (count at +0x28) */
    for (i = 0; i < *(s32 *)(vars + 0x28); i++) {
        pl = D_L04_001E2840 + D_001D52F0[0] * 0x460;
        ang = func_0038D160(*(f32 *)(pl + 0) - *(f32 *)(m + 0x10), *(f32 *)(pl + 4) - *(f32 *)(m + 0x14));
        rs = (s32)func_L01_00443A18(2.0f, 5.0f);
        n = func_00382498(30, 50);
        pos[0] = *(f32 *)(m + 0x10) + func_L01_00443A18(0.0f, 0.1f) * *(f32 *)(vars + 0x14);
        pos[1] = *(f32 *)(m + 0x14) + func_L01_00443A18(0.0f, 0.1f) * *(f32 *)(vars + 0x14);
        pos[2] = *(f32 *)(m + 0x18) + func_L01_00443A18(0.0f, 0.1f) * *(f32 *)(vars + 0x14);
        up = func_003824E0(0.6f, 1.0f) * *(f32 *)(vars + 0x14);
        spd = func_003824E0(9.0f, 12.0f) * *(f32 *)(vars + 0x14);
        ang = func_0038DAB8(ang, func_L01_00443A18(0.0f, 1.3962634f));
        spd = spd * 0.020000001f;
        v[0] = func_0038D098(ang) * spd;
        v[1] = func_0038D0B0(ang) * spd;
        v[2] = 0.0f;
        spd = func_003824E0(0.0f, 12.0f) * *(f32 *)(vars + 0x14);
        v[2] = spd * 0.020000001f;
        v[0] += off[0];
        v[1] += off[1];
        v[2] += off[2];
        p = func_L01_004713C8(pos, v, (n * 5 + 2) / 6, 0x3064FF, rs, 0x7F, 0x7F, 3, up * K, *(f32 *)(vars + 0x14) * 2100.0f, 0.00584f);
        if (p) {
            p[9] = 0xF4;
        }
    }

    /* burst type 4 (count at +0x30): sparks along the basis vectors at m+0xC0 / m+0xD0 */
    for (i = 0; i < *(s32 *)(vars + 0x30); i++) {
        r = func_003824E0(15.0f, 20.0f) * *(f32 *)(vars + 0x14);
        func_0038CE20(pos, m + 0xC0, r * 0.020000001f);
        spd = func_L01_00443A18(0.2617994f, 1.3962634f);
        up = func_L01_00443A18(0.2617994f, 1.3962634f);
        func_003C4840(w, m + 0xD0, spd);
        func_0038D850(v, pos, w);
        func_003C4840(w, m + 0xC0, up);
        func_0038D850(v, v, w);
        v[0] += off[0];
        v[1] += off[1];
        v[2] += off[2];
        n = func_00382498(20, 35);
        p = func_L01_00470668(m + 0x10, v, (n * 5 + 2) / 6, 0.00584f);
        if (p) {
            p[9] = 0xF4;
        }
    }

    if (*(s32 *)(vars + 0x34) != 0) {
        *(u128_00325C08 *)v = 0;
        v[2] = *(f32 *)(vars + 0x14) * 8.0f * 0.020000001f;
        *(u128_00325C08 *)pos = *(u128_00325C08 *)v;
        pos[0] += off[0];
        pos[1] += off[1];
        pos[2] += off[2];
        func_L01_002F9578(m, m + 0x10, pos, 0xD, 0xFF, 0, 0, 0x28, *(f32 *)(vars + 0x14) * 3.5f);
    }

    func_L01_0044AF78(m, D_001D66B0, m + 0x10, 0, 0, 0, -1, 0, 0, -1, 0, 0x1010001, 0.0f, 0.0f, 0.0f, 0.0f, 9.0f, 0.0f, extra * *(f32 *)(vars + 0x14));

    sgn = 1;
    pl = D_L04_001E2840 + D_001D52F0[0] * 0x460;
    ang = func_0038D160(*(f32 *)(pl + 0) - *(f32 *)(m + 0x10), *(f32 *)(pl + 4) - *(f32 *)(m + 0x14));
    for (i = 0; i < *(s32 *)(vars + 0x2C); i++) {
        sgn = -sgn;
        pos[0] = *(f32 *)(m + 0x10) + func_L01_00443A18(0.0f, 1.0f) * *(f32 *)(vars + 0x14);
        pos[1] = *(f32 *)(m + 0x14) + func_L01_00443A18(0.0f, 1.0f) * *(f32 *)(vars + 0x14);
        pos[2] = *(f32 *)(m + 0x18) + func_L01_00443A18(0.0f, 1.0f) * *(f32 *)(vars + 0x14);
        spd = func_003824E0(0.020000001f, 0.040000003f) * *(f32 *)(vars + 0x14);
        up = func_L01_00443A18(0.0f, 1.3962634f);
        r = func_L01_00443A18(0.0f, 1.5707964f);
        func_00382760(v, spd, func_0038DAB8(ang, r), up);
        v[0] += off[0];
        v[1] += off[1];
        v[2] += off[2];
        p = func_L01_004669B0(pos, 0.0f, 1.0f, 1.01f, *(f32 *)(vars + 0x14) * 1.5f * K, sgn, v, 0x7F60A0FF, 0);
        if (p) {
            n = func_00382498(40, 70);
            p[9] = 0xF4;
            *(s16 *)(p + 0xA) = (n * 5 + 2) / 6;
            *(s32 *)(p + 0x20 + 4) = 3;
            n = func_00382498(1, 10);
            *(u8 *)(p + 0x20 + 0xA) = 0x40;
            *(f32 *)(p + 0x20 + 0x1C) = (f32)((n * 5 + 2) / 6);
            *(u8 *)(p + 0x20 + 0xB) = *(u8 *)(p + 0xA);
        }
    }
}

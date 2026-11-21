/* functional: high. Particle burst spawner (sparks via func_L01_003298C8, then extra trail particles via func_L01_004637C8); structure from the NTSC-U draft re-checked against PAL asm: PAL uses 100..125 frame lifetime range, 0.02 speed scale, gp globals gp+0x256C..0x25C0 (named by address, unnamed in the catalogue); compiles at level_05 (419 diff, scheduling only). */
typedef struct { f32 x, y, z, w; } V4_3CB090;
extern f32 func_003824E0(f32, f32);
extern f32 func_00382538(void);
extern s32 func_00382468(s32);
extern s32 func_00382498(s32, s32);
extern void func_00382760(V4_3CB090 *, f32, f32, f32);
extern void func_0038CF68(void *, void *, f32);
extern void *func_L01_003298C8(void *, void *, s32, s32, s32, s32, void *, s32, s32, s32, f32, f32);
extern void func_L01_004637C8(void *, void *, s32, s32, s32, s32, s32, s32);
extern f32 D_001DF6D0_sda;
extern s32 D_001DEE1C_sda;
extern f32 D_001DEE20_sda, D_001DEE24_sda, D_001DEE28_sda;
extern s32 D_001DEE2C_sda, D_001DEE30_sda, D_001DEE34_sda, D_001DEE38_sda;
extern s32 D_001DEE3C_sda, D_001DEE40_sda, D_001DEE44_sda, D_001DEE48_sda;
extern s32 D_001DEE4C_sda, D_001DEE50_sda, D_001DEE54_sda, D_001DEE5C_sda, D_001DEE60_sda;
extern f32 D_001DEE58_sda, D_001DEE64_sda, D_001DEE68_sda, D_001DEE6C_sda, D_001DEE70_sda;

static s32 pack_3CB090(f32 a, f32 r, f32 g, f32 b, f32 s) {
    return ((s32)(a * s) << 24) | ((s32)(r * s) << 16) | ((s32)(g * s) << 8) | (s32)(b * s);
}

void func_L05_003CB090(u8 *self) {
    u8 *st;
    s32 n, i, s0, s2, s4, idx;
    f32 f20, f21, spd, mid;
    f32 al;
    V4_3CB090 a;
    u32 b[4];
    u8 *tab;
    u8 *o;

    st = *(u8 **)(self + 0x68);
    n = D_001DEE1C_sda;
    if (0.7f < D_001DF6D0_sda && D_001DF6D0_sda < 0.85f) {
        n = n - 1;
    } else if (0.85f < D_001DF6D0_sda) {
        n = n - 2;
    }
    for (; n > 0; n--) {
        f21 = func_003824E0(0.43633232f, 0.78539819f);
        s4 = 0;
        f20 = func_00382538();
        spd = func_003824E0(10.0f, 20.0f) * 0.02f;
        func_00382760(&a, spd * D_001DEE20_sda, f20, f21);
        al = (f32)D_001DEE38_sda;
        b[0] = pack_3CB090(al, (f32)D_001DEE34_sda, (f32)D_001DEE30_sda, (f32)D_001DEE2C_sda, 1.0f);
        b[1] = pack_3CB090(al, (f32)D_001DEE34_sda, (f32)D_001DEE30_sda, (f32)D_001DEE2C_sda, 0.75f);
        b[2] = pack_3CB090(al, (f32)D_001DEE34_sda, (f32)D_001DEE30_sda, (f32)D_001DEE2C_sda, 0.5f);
        b[3] = pack_3CB090(al, (f32)D_001DEE34_sda, (f32)D_001DEE30_sda, (f32)D_001DEE2C_sda, 0.25f);
        if (*(u8 **)(st + 0x3C) != 0) {
            idx = func_00382468(*(s32 *)(st + 0x38)) * 4;
            tab = *(u8 **)(st + 0x3C) + idx;
            b[0] = pack_3CB090(al, (f32)tab[2], (f32)tab[1], (f32)tab[0], 1.0f);
            s4 = (tab[3] << 24) | (tab[2] << 16) | (tab[1] << 8) | tab[0];
            b[1] = pack_3CB090(al, (f32)tab[2], (f32)tab[1], (f32)tab[0], 0.75f);
            b[2] = pack_3CB090(al, (f32)tab[2], (f32)tab[1], (f32)tab[0], 0.5f);
            b[3] = pack_3CB090(al, (f32)tab[2], (f32)tab[1], (f32)tab[0], 0.25f);
        }
        s2 = 0;
        s0 = 0;
        f20 = func_003824E0(D_001DEE24_sda, D_001DEE28_sda);
        mid = D_001DEE24_sda + (D_001DEE28_sda - D_001DEE24_sda) * 0.5f;
        if (mid < f20 || func_00382468(3) == 0) {
            s2 = 1;
            if (func_00382468(3) != 0) {
                if (D_001DF6D0_sda < 0.8f) {
                    s0 = 2;
                }
            }
        }
        o = (u8 *)func_L01_003298C8(st + 0x10, &a, func_00382498(100, 125), s0, s2, s4, b, 0, 0x32, 0x78, 1.0f, 14.6f);
        if (o != 0) {
            *(f32 *)(o + 0x2C) = *(f32 *)(*(u8 **)(o + 0x24) + 0x24) * f20;
        }
    }
    for (i = 0; i < D_001DEE5C_sda; ) {
        i = i + 1;
        b[0] = 0; b[1] = 0; b[2] = 0; b[3] = 0;
        ((f32 *)b)[0] = func_003824E0(D_001DEE64_sda, D_001DEE68_sda);
        ((f32 *)b)[1] = func_003824E0(D_001DEE64_sda, D_001DEE68_sda);
        ((f32 *)b)[2] = func_003824E0(D_001DEE6C_sda, D_001DEE70_sda);
        a = *(V4_3CB090 *)b;
        func_0038CF68(&a, &a, D_001DEE58_sda * 0.02f);
        func_L01_004637C8(st + 0x10, &a,
            (D_001DEE48_sda << 24) | (D_001DEE44_sda << 16) | (D_001DEE40_sda << 8) | D_001DEE3C_sda,
            (D_001DEE44_sda << 16) | (D_001DEE40_sda << 8) | D_001DEE3C_sda,
            D_001DEE4C_sda, D_001DEE50_sda, D_001DEE54_sda, D_001DEE60_sda);
    }
}

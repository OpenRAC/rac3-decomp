/* functional: medium. Not byte-matched. Uses two static helpers (v4_003B8E60, cp4_003B8E60) for the 128-bit lq/sq vector stores; w components are written explicitly (0 or 1 per retail swc1/sq pattern). The shuffle loop and per-type tables follow retail; float literals are the exact f32 values from the asm. */
extern s16 *D_L01_0021DE20[];
extern u8 *D_L01_0021F6C0[];
extern int D_L01_001E001C;
extern u8 D_001D5476;
extern s32 D_001D545C;
extern s32 D_L01_001DE780;
extern s32 D_L01_001DE784;
extern f32 D_L01_001DE788;
extern f32 D_L01_001DE78C;
extern f32 D_L01_001DE7F0[];
extern f32 D_L01_001DE820[];
extern f32 D_L01_001DE840[];
extern f32 D_L01_001DE860[];
extern f32 D_L01_001DE8A0[];
extern f32 D_L01_001DE8C0[];
extern f32 func_0038CF00(void *, void *);
extern s32 func_00382468(s32);
extern s32 func_00382498(s32, s32);
extern f32 func_003824E0(f32, f32);
extern f32 func_00382538(void);
extern f32 func_L01_00443A18(f32, f32);
extern s32 func_L01_00445F40(void *, s32);
extern void func_003C3A10(void *, s32, s32, s32);
extern void func_003C7C38(void *);
extern void func_0038CE20(void *, void *, f32);

static void v4_003B8E60(f32 *v, f32 x, f32 y, f32 z, f32 w) {
    v[0] = x;
    v[1] = y;
    v[2] = z;
    v[3] = w;
}

static void cp4_003B8E60(f32 *d, f32 *s) {
    d[0] = s[0];
    d[1] = s[1];
    d[2] = s[2];
    d[3] = s[3];
}

void func_L01_003B8E60(void *m_, s32 idx) {
    u8 *m = (u8 *)m_;
    s16 *list, *cur, *fp;
    u8 *vars, *path, *mob, *v2;
    f32 d, d2, f20, f24, f29, f30, f31, sc, r;
    f32 A[4] __attribute__((aligned(16)));
    f32 B[4] __attribute__((aligned(16)));
    f32 C[4] __attribute__((aligned(16)));
    f32 D[4] __attribute__((aligned(16)));
    f32 T[12] __attribute__((aligned(16)));
    s32 i, j, n, k, g, type;
    s16 tmp;

    list = D_L01_0021DE20[idx];
    if (list == 0) {
        return;
    }
    vars = *(u8 **)(m + 0x68);
    m[0x30] = 0xFF;
    path = D_L01_0021F6C0[*(s32 *)vars];
    d = func_0038CF00(path + 0x10, path + 0x20);
    f31 = (f32)*(s32 *)path;
    f20 = 1.0f / d;
    d2 = func_0038CF00(path + 0x10, path + *(s32 *)path * 16);
    *(s16 *)(vars + 0x80) = d2 < 5.0f ? 1 : 0;
    *(u8 **)(vars + 0x70) = path;
    *(f32 *)(vars + 0x14) = *(f32 *)(vars + 8) * 0.020000001f * f20;

    list = D_L01_0021DE20[idx];
    n = 1;
    i = 0;
    if ((list[0] & 0x8000) == 0) {
        cur = list;
        do {
            if (i > 0) {
                j = func_00382468(i);
                tmp = list[j];
                list[j] = *(u16 *)cur;
                *cur = tmp;
            }
            cur++;
            i++;
            n++;
        } while ((*cur & 0x8000) == 0);
    }
    f30 = (f32)n;
    f24 = ((f32)*(s32 *)path * 0.4f) / f30;
    f29 = (*(f32 *)(vars + 0x14) * 0.25f) / f24;
    fp = D_L01_0021DE20[idx];
    k = n - 1;
    for (;;) {
        mob = (u8 *)D_L01_001E001C + ((*(u16 *)fp & 0x7FFF) << 8);
        v2 = *(u8 **)(mob + 0x68);
        if (mob != m) {
            *(u16 *)(mob + 0x34) = *(u16 *)(mob + 0x34) | 2;
        }
        if (*(s16 *)(mob + 0xAA) != 0x1D3E && D_001D5476 != 0) {
            func_L01_00445F40(mob, 0x1D3E);
            *(f32 *)(mob + 0x2C) = *(f32 *)(*(u8 **)(mob + 0x24) + 0x24) * 1.5f;
            func_003C3A10(mob, 5, 0, 0);
            func_003C7C38(mob);
        }
        r = (f32)k / f30;
        k--;
        cur = fp + 1;
        *(f32 *)(v2 + 0x8C) = f24;
        *(f32 *)(v2 + 0x10) = r * f31;
        *(f32 *)(v2 + 0x94) = f29 * func_003824E0(0.75f, 1.25f);
        *(f32 *)(v2 + 0x90) = func_00382538();
        {
            f32 *z = (f32 *)(v2 + 0x20);
            z[0] = 0.0f;
            z[1] = 0.0f;
            z[2] = 0.0f;
            z[3] = 0.0f;
        }
        *(s16 *)(v2 + 0x82) = 1;
        *(f32 *)(v2 + 0x28) = *(f32 *)(v2 + 4) * func_L01_00443A18(0.5f, 1.0f);
        g = func_00382498(D_L01_001DE780, D_L01_001DE784);
        *(s16 *)(v2 + 0x86) = (g * 5 + 2) / 6;
        *(f32 *)(v2 + 0x78) = func_00382538();
        *(f32 *)(v2 + 0x7C) = func_L01_00443A18(D_L01_001DE788, D_L01_001DE78C) * 0.017453292f * 0.020000001f;
        *(s32 *)(v2 + 0x18) = -1;
        *(f32 *)(v2 + 0x88) = *(f32 *)(mob + 0x2C) / *(f32 *)(*(u8 **)(mob + 0x24) + 0x24);
        *(s32 *)(v2 + 0x1C) = 0;
        *(s32 *)(v2 + 0x98) = 0;
        sc = *(f32 *)(v2 + 0x88);
        type = *(s16 *)(mob + 0xAA);

        if (type == 0x9B0) {
            v4_003B8E60(A, -2.1f, 0.75f, 0.86f, 0.0f);
            v4_003B8E60(B, -2.1f, -0.75f, 0.86f, 0.0f);
            v4_003B8E60(C, -3.0f, 0.0f, -0.67f, 0.0f);
            func_0038CE20(A, A, sc);
            cp4_003B8E60((f32 *)(v2 + 0x30), A);
            func_0038CE20(B, B, sc);
            cp4_003B8E60((f32 *)(v2 + 0x40), B);
            func_0038CE20(C, C, sc);
            cp4_003B8E60((f32 *)(v2 + 0x50), C);
            for (i = 0; i < 3; i++) {
                cp4_003B8E60(T + i * 4, D_L01_001DE7F0 + i * 4);
                func_0038CE20(v2 + 0xB0 + i * 16, T + i * 4, sc);
            }
        }
        if (type == 0x1C87) {
            v4_003B8E60(A, -3.7f, -1.7f, 4.0f, 0.0f);
            v4_003B8E60(B, -3.7f, 1.7f, 4.0f, 0.0f);
            func_0038CE20(A, A, sc);
            cp4_003B8E60((f32 *)(v2 + 0x30), A);
            func_0038CE20(B, B, sc);
            cp4_003B8E60((f32 *)(v2 + 0x40), B);
            for (i = 0; i < 2; i++) {
                cp4_003B8E60(T + i * 4, D_L01_001DE820 + i * 4);
                func_0038CE20(v2 + 0xB0 + i * 16, T + i * 4, sc);
            }
        }
        if (type == 0x1A78) {
            v4_003B8E60(A, -3.75f, 2.6f, 2.0f, 1.0f);
            v4_003B8E60(B, -3.75f, -2.6f, 2.0f, 1.0f);
            func_0038CE20(A, A, sc);
            cp4_003B8E60((f32 *)(v2 + 0x30), A);
            func_0038CE20(B, B, sc);
            cp4_003B8E60((f32 *)(v2 + 0x40), B);
            for (i = 0; i < 2; i++) {
                cp4_003B8E60(T + i * 4, D_L01_001DE840 + i * 4);
                func_0038CE20(v2 + 0xB0 + i * 16, T + i * 4, sc);
            }
        }
        if (type == 0x1C46) {
            v4_003B8E60(A, -1.6f, 0.0f, -0.15f, 1.0f);
            func_0038CE20(A, A, sc);
            cp4_003B8E60((f32 *)(v2 + 0x30), A);
            v4_003B8E60(B, -1.6f, 0.0f, -0.15f, 1.0f);
            func_0038CE20(v2 + 0xB0, B, sc);
        }
        if (type == 0xB13) {
            v4_003B8E60(A, -3.678f, 0.808f, 0.1f, 1.0f);
            v4_003B8E60(B, -3.678f, -0.808f, 0.1f, 1.0f);
            func_0038CE20(A, A, sc);
            cp4_003B8E60((f32 *)(v2 + 0x30), A);
            func_0038CE20(B, B, sc);
            cp4_003B8E60((f32 *)(v2 + 0x40), B);
        }
        if (type == 0x1D94) {
            v4_003B8E60(A, -5.0f, 5.5f, 4.5f, 1.0f);
            v4_003B8E60(B, -5.0f, -5.5f, 4.5f, 1.0f);
            v4_003B8E60(C, -5.0f, 5.5f, 2.0f, 1.0f);
            v4_003B8E60(D, -5.0f, -5.5f, 2.0f, 1.0f);
            func_0038CE20(A, A, sc);
            cp4_003B8E60((f32 *)(v2 + 0x30), A);
            func_0038CE20(B, B, sc);
            cp4_003B8E60((f32 *)(v2 + 0x40), B);
            func_0038CE20(C, C, sc);
            cp4_003B8E60((f32 *)(v2 + 0x50), C);
            func_0038CE20(D, D, sc);
            cp4_003B8E60((f32 *)(v2 + 0x60), D);
            for (i = 0; i < 4; i++) {
                cp4_003B8E60(T + i * 4 - 0, D_L01_001DE860 + i * 4);
                func_0038CE20(v2 + 0xB0 + i * 16, T + i * 4, sc);
            }
        }
        if (type == 0x127D) {
            v4_003B8E60(A, -0.165f, 0.7f, -0.161f, 1.0f);
            v4_003B8E60(B, -0.165f, -0.7f, -0.161f, 1.0f);
            func_0038CE20(A, A, sc);
            cp4_003B8E60((f32 *)(v2 + 0x30), A);
            func_0038CE20(B, B, sc);
            cp4_003B8E60((f32 *)(v2 + 0x40), B);
            for (i = 0; i < 2; i++) {
                cp4_003B8E60(T + i * 4, (f32 *)(v2 + 0x30 + i * 16));
                func_0038CE20(v2 + 0xB0 + i * 16, T + i * 4, sc);
            }
        }
        if (type == 0x1C4D) {
            v4_003B8E60(A, -1.9f, 0.84f, -0.2f, 1.0f);
            v4_003B8E60(B, -1.9f, -0.84f, -0.2f, 1.0f);
            func_0038CE20(A, A, sc);
            cp4_003B8E60((f32 *)(v2 + 0x30), A);
            func_0038CE20(B, B, sc);
            cp4_003B8E60((f32 *)(v2 + 0x40), B);
            for (i = 0; i < 2; i++) {
                cp4_003B8E60(T + i * 4, D_L01_001DE8A0 + i * 4);
                func_0038CE20(v2 + 0xB0 + i * 16, T + i * 4, sc);
            }
        }
        if (type == 0x1290) {
            v4_003B8E60(A, -0.823f, 0.698f, -0.219f, 1.0f);
            v4_003B8E60(B, -0.823f, -0.698f, -0.219f, 1.0f);
            v4_003B8E60(C, -1.376f, 0.0f, 0.208f, 1.0f);
            func_0038CE20(A, A, sc);
            cp4_003B8E60((f32 *)(v2 + 0x30), A);
            func_0038CE20(B, B, sc);
            cp4_003B8E60((f32 *)(v2 + 0x40), B);
            func_0038CE20(C, C, sc);
            cp4_003B8E60((f32 *)(v2 + 0x50), C);
            for (i = 0; i < 3; i++) {
                cp4_003B8E60(T + i * 4, (f32 *)(v2 + 0x30 + i * 16));
                func_0038CE20(v2 + 0xB0 + i * 16, T + i * 4, sc);
            }
        }
        if (type == 0x1340) {
            v4_003B8E60(A, -0.215f, 2.132f, -0.319f, 1.0f);
            v4_003B8E60(B, -0.215f, -2.132f, -0.319f, 1.0f);
            func_0038CE20(A, A, sc);
            cp4_003B8E60((f32 *)(v2 + 0x30), A);
            func_0038CE20(B, B, sc);
            cp4_003B8E60((f32 *)(v2 + 0x40), B);
            for (i = 0; i < 2; i++) {
                cp4_003B8E60(T + i * 4, D_L01_001DE8C0 + i * 4);
                func_0038CE20(v2 + 0xB0 + i * 16, T + i * 4, sc);
            }
        }
        mob[0x20] = 1;
        g = D_001D545C;
        if (g != 0x10 && g != 1 && g != 5 && g != 0xE) {
            *(s16 *)(mob + 0x32) = 0xBE;
        }
        if (*fp < 0) {
            break;
        }
        fp = cur;
    }
}

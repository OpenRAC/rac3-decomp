/* functional: medium. Effects draw routine of the Thran object (tail of the unit after func_L19_003ABAE8): up to four parts. (1) if pv+0x274, three flame sprites at attach points 3..5. (2) a glow strength f23 from pv+0x27C (clamped 0..1); when >0 a sprite at attach point 0 and a ribbon of 16 quad segments (table at gp+0x1CB8) plus 8 wobbling quads (D_L19_002BDC30), textures 0x16. (3) for attach points 1 and 2 four fading quads (texture 8) around it and a sprite, then two spark particles via func_L01_00463378 with random velocity. func_003C2EC0 fills a 4x4 attach-point matrix (rows 0xA0..0xDF on the stack; translation is row 3); retail adds to the translation row of the stack matrix, modelled with one f32 array. VU0 vector adds are plain adds on x,y,z. Dead packet set-up before the part-1 sprites dropped (the sprites do not read it). Float constants decoded from retail hex. */
typedef struct {
    f32 v[4][4];
    s32 col[4];
    f32 uv[4][2];
    long zero, tex, prim, mode;
} Pkt_003ABBD8;
extern s32 D_L19_001DF240;
extern f32 D_L19_002BDC30[][4];
extern f32 D_L19_001DE568[];
__asm__(".extern D_L19_001DE568, 4");
extern long func_00389598(s32);
extern void func_003C2F58(void *, s32, void *);
extern void func_003C2EC0(void *, s32, void *);
extern void func_003D9508(void *, s32, s32, s32, f32, f32, f32);
extern void func_0038CE20(void *, void *, f32);
extern s32 func_0038DBD8(s32, s32, f32);
extern f32 func_0038DB48(f32);
extern f32 func_0038D0B0(f32);
extern f32 func_0038D098(f32);
extern f32 func_003824E0(f32, f32);
extern f32 func_003C3D30(void *, s32, s32, f32);
extern void func_003D2DA0(void *, void *, s32);
extern void func_L01_00463378(void *, void *, void *, s32, s32, s32, s32, s32, s32);

void func_L19_003ABBD8(void *arg0) {
    u8 *obj = (u8 *)arg0;
    u8 *pv = *(u8 **)(obj + 0x68);
    f32 S[20];              /* the matrix rows at sp+0xA0..0xDF and the vector at 0xE0 */
    f32 *A0 = &S[0];
    f32 *B0 = &S[4];
    f32 *D0 = &S[12];
    f32 *E0 = &S[16];
    Pkt_003ABBD8 PA, PB;
    f32 P0F0[4], P100[4], P110[4];
    f32 alpha, f22, f23, f20, f21, f1, f3, x, y, z, ff, h, fsin, fcos;
    s32 i, j, k, m, q, t, g, col, idx1, idx2, o, rr;
    long tex;

    if (*(s32 *)(pv + 0x274) != 0) {
        tex = func_00389598(0x16);
        for (k = 3; k < 6; k++) {
            func_003C2F58(obj, k, A0);
            t = 20 - D_L19_001DF240 % 40;
            if (t <= 0) {
                t = -t;
            }
            func_003D9508(A0, 6, 0x40000080, 1, (f32)t * 0.02f + 0.1f, 0.08f, 0.0f);
        }
    }
    f23 = 1.0f;
    if (obj[0x95] != 2) {
        f23 = 1.0f - (f32)*(s32 *)(pv + 0x27C) / 50.333332f;
    }
    if (1.0f < f23) {
        f23 = 1.0f;
    } else if (f23 < 0.0f) {
        f23 = 0.0f;
    }
    f22 = 0.0f;
    if (0.0f < f23) {
        func_003C2EC0(obj, 0, B0);
        func_0038CE20(A0, B0, 0.7f);
        E0[0] = E0[0] + A0[0];
        E0[1] = E0[1] + A0[1];
        E0[2] = E0[2] + A0[2];
        col = func_0038DBD8(0x7F7F7F, 0x7F7F7F7F, f23);
        func_003D9508(E0, 0xB, col, 1, 0.5f, f22, f22);
    }
    if (0.0f < f23) {
        func_003C2EC0(obj, 0, A0);
        func_0038CE20(E0, A0, 0.43f);
        D0[0] = D0[0] + E0[0];
        D0[1] = D0[1] + E0[1];
        D0[2] = D0[2] + E0[2];
        tex = func_00389598(0x16);
        PB.prim = 0xFF9000000260L;
        PB.tex = tex;
        PB.zero = 4;
        PB.mode = 0x8000000048L;
        PB.v[0][0] = 0.0f;
        PB.v[0][1] = 0.0f;
        PB.v[0][2] = -0.25f;
        PB.v[0][3] = 1.0f;
        PB.v[1][0] = 0.0f;
        PB.v[1][3] = 1.0f;
        PB.v[2][0] = *(f32 *)(pv + 0x258) - 1.30395f;
        PB.v[2][1] = 0.0f;
        PB.v[2][2] = -(*(f32 *)(pv + 0x25C) * 0.5f);
        PB.v[2][3] = 1.0f;
        PB.v[3][3] = 1.0f;
        PB.uv[0][0] = 0.0f;
        PB.uv[0][1] = 0.0f;
        PB.uv[1][0] = 0.0f;
        PB.uv[1][1] = 1.0f;
        PB.uv[2][0] = 1.0f;
        PB.uv[2][1] = 0.0f;
        PB.uv[3][0] = 1.0f;
        PB.uv[3][1] = 1.0f;
        col = func_0038DBD8(0x508080, 0x30508080, f23);
        PB.col[0] = col;
        PB.col[1] = col;
        PB.col[2] = 0x508080;
        PB.col[3] = 0x508080;
        for (m = 0; m < 16; m++) {
            idx1 = (m * 3) % 16;
            idx2 = (m + 12) % 16;
            f1 = *(f32 *)(pv + 0x25C) * 0.5f;
            x = (D_L19_001DE568[idx1] * 0.05f + 1.1f);
            f1 = f1 * x;
            f3 = (*(f32 *)(pv + 0x258) - 1.30395f) * x;
            PB.v[1][1] = D_L19_001DE568[idx2] * 0.25f;
            PB.v[1][2] = D_L19_001DE568[m] * 0.25f;
            PB.v[3][0] = f3;
            PB.v[3][1] = D_L19_001DE568[idx2] * f1;
            PB.v[3][2] = D_L19_001DE568[m] * f1;
            func_003D2DA0(&PB, A0, 0);
            PB.v[0][0] = PB.v[1][0];
            PB.v[0][1] = PB.v[1][1];
            PB.v[0][2] = PB.v[1][2];
            PB.v[0][3] = PB.v[1][3];
            PB.v[2][0] = PB.v[3][0];
            PB.v[2][1] = PB.v[3][1];
            PB.v[2][2] = PB.v[3][2];
            PB.v[2][3] = PB.v[3][3];
        }
        j = 0;
        for (i = 0; i < 8; i++) {
            f32 *T = D_L19_002BDC30[i];
            x = func_0038DB48((f32)i * 0.89759785f);
            t = j % 5 + 2;
            j += 17;
            y = func_0038DB48(x + (f32)t * 0.17453292f);
            f21 = (f32)(i * 2);
            f20 = f21 + x;
            f21 = f21 + y;
            rr = (D_L19_001DF240 >> 1) % 60;
            z = func_0038DB48(f20 + (f32)rr * 6.0f * 0.017453292f);
            f23 = func_0038D0B0(z) * 0.25f + 1.0f;
            rr = (D_L19_001DF240 >> 1) % 60;
            z = func_0038DB48(f21 + (f32)rr * 6.0f * 0.017453292f);
            f22 = func_0038D0B0(z) * 0.25f + 1.0f;
            fcos = func_0038D098(func_0038DB48(f20));
            fsin = func_0038D0B0(func_0038DB48(f21));
            f1 = *(f32 *)(pv + 0x25C) * 0.5f * (fcos * 0.2f + 0.7f);
            f3 = (*(f32 *)(pv + 0x258) - 1.30395f) * (fsin * 0.2f + 0.7f);
            PB.v[0][1] = T[0] * 0.25f;
            PB.v[0][2] = T[1] * 0.25f;
            PB.v[3][0] = f3 * f22;
            PB.v[3][2] = T[3] * f1 * f22;
            PB.v[3][1] = T[2] * f1 * f22;
            PB.v[2][1] = T[0] * f1 * f23;
            PB.v[2][2] = T[1] * f1 * f23;
            PB.v[2][0] = f3 * f23;
            PB.v[1][1] = T[2] * 0.25f;
            PB.v[1][2] = T[3] * 0.25f;
            func_003D2DA0(&PB, A0, 0);
        }
    }
    tex = func_00389598(8);
    PA.prim = 0xFF9000000260L;
    PA.tex = tex;
    PA.zero = 4;
    PA.mode = 0x8000000048L;
    PA.uv[0][0] = 0.0f;
    PA.uv[0][1] = 0.0f;
    PA.uv[1][0] = 0.0f;
    PA.uv[1][1] = 1.0f;
    PA.uv[2][0] = 1.0f;
    PA.uv[2][1] = 0.0f;
    PA.uv[3][0] = 1.0f;
    PA.uv[3][1] = 1.0f;
    for (o = 1; o < 3; o++) {
        func_003C2EC0(obj, o, A0);
        for (q = 0; q < 4; q++) {
            ff = (f32)((D_L19_001DF240 + ((q * 25) >> 2)) % 25) / 25.0f;
            E0[0] = 0.0f;
            E0[1] = 0.0f;
            E0[3] = 1.0f;
            E0[2] = -ff + 0.4f;
            col = ((s32)((1.0f - ff) * 128.0f) << 24) | 0x804000;
            h = 0.5f - ff * 0.3f;
            for (k = 0; k < 4; k++) {
                PA.v[k][0] = E0[0];
                PA.v[k][1] = E0[1];
                PA.v[k][2] = E0[2];
                PA.v[k][3] = E0[3];
            }
            PA.v[0][0] = PA.v[0][0] - h;
            PA.v[1][1] = PA.v[1][1] - h;
            PA.v[2][1] = PA.v[2][1] + h;
            PA.v[3][0] = PA.v[3][0] + h;
            PA.col[0] = col;
            PA.col[1] = col;
            PA.col[2] = col;
            PA.col[3] = col;
            func_003D2DA0(&PA, A0, 0);
        }
        t = 10 - D_L19_001DF240 % 20;
        if (t <= 0) {
            t = -t;
        }
        E0[0] = D0[0];
        E0[1] = D0[1];
        E0[2] = D0[2];
        E0[3] = D0[3];
        func_003D9508(E0, 6, 0x40804000, 1, (f32)t * 0.01f + 0.05f, 0.08f, 0.0f);
        E0[0] = D0[0];
        E0[1] = D0[1];
        E0[2] = D0[2];
        E0[3] = D0[3];
        E0[2] = func_003C3D30(E0, 0, 0, 0.5f);
        for (k = 1; k >= 0; k--) {
            f21 = func_003824E0(-3.1415927f, 3.1415927f);
            P0F0[0] = 0.0f;
            P0F0[1] = 0.0f;
            P0F0[2] = 0.0f;
            P0F0[3] = 0.0f;
            x = func_003824E0(0.05f, 0.1f);
            P0F0[0] = x * func_0038D098(f21);
            y = func_003824E0(0.05f, 0.1f);
            P0F0[1] = y * func_0038D0B0(f21);
            z = func_003824E0(0.005f, 0.015f);
            P100[0] = 0.0f;
            P100[1] = 0.0f;
            P100[2] = 0.0f;
            P100[3] = 0.0f;
            P0F0[2] = z;
            P0F0[3] = 0.2f;
            P100[1] = P0F0[1] * 0.5f;
            P100[0] = P0F0[0] * 0.5f;
            P100[2] = 0.01f;
            P100[3] = 0.25f;
            P110[0] = E0[0] + P0F0[0];
            P110[1] = E0[1] + P0F0[1];
            P110[2] = E0[2] + P0F0[2];
            P110[3] = E0[3];
            P110[0] = P110[0] + func_0038D098(f21) * 0.5f;
            P110[1] = P110[1] + func_0038D0B0(f21) * 0.5f;
            func_L01_00463378(P110, P0F0, P100, 0x30808080, 0x20808080, 4, 8, 8, -1);
        }
    }
}

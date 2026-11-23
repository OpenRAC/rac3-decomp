/* functional: medium. functional: medium. Behaviour reconstructed from the asm including all table strides; byte layout differs only in scheduling/addressing */
extern void func_003A9440(s32, unsigned long);
extern void func_0038C750(void);
extern f32 func_0038CF00(void *, void *);
extern void func_003D3A24(s32, void *, void *, void *, s32);
extern long func_00389598(s32);
extern void func_0038CE20(void *, void *, f32);
extern u8 D_L01_001E29C0[];
extern u32 D_L01_001DBCA0[];
extern f32 D_L01_001E22A0[];
extern f32 D_L01_001E22A4[];
extern f32 D_L01_001E22A8[];
extern s32 D_L01_001E22D0[];
extern f32 D_L01_001E22E0[];
extern f32 D_L01_001E22E4[];
extern f32 D_L01_001DF214[];
extern f32 D_L01_001DF234[];
extern f32 D_L01_002BB550[];
extern s32 D_001DF250_sda;
extern s32 D_001DF254_sda;
extern f32 D_001DF20C_sda;
extern f32 D_001DF1FC_sda;
extern f32 D_001DF200_sda;
extern f32 D_001DF210_sda[8];
extern f32 D_001DF230_sda[8];
__asm__(".extern D_001DF250_sda, 4");
__asm__(".extern D_001DF254_sda, 4");
__asm__(".extern D_001DF20C_sda, 4");
__asm__(".extern D_001DF1FC_sda, 4");
__asm__(".extern D_001DF200_sda, 4");
__asm__(".extern D_001DF210_sda, 4");
__asm__(".extern D_001DF230_sda, 4");

void func_L01_003CE8A8(u8 *self) {
    f32 v[4];
    f32 t[4];
    u8 *vars;
    s32 a;
    s32 b;
    s32 i;
    s32 j;
    s32 q;
    f32 dist, scale, f20, f21, s;
    f32 *tbl;

    vars = *(u8 **)(self + 0x68);
    a = D_001DF250_sda;
    b = D_001DF254_sda;
    *(s32 *)(vars + 0x28) = a;
    *(s32 *)(vars + 0x2C) = b;
    if ((u32)(a & 0xFF000000) > 0x80000000u || (u32)(b & 0xFF000000) > 0x80000000u) {
        D_L01_001DBCA0[0] |= 1;
    }
    s = *(f32 *)(vars + 0x10) + D_001DF20C_sda;
    *(f32 *)(vars + 0x10) = s - (f32)(s32)s;
    func_003A9440(8, 0);
    func_003A9440(0x14, 0xFF9000000260ul);
    func_003A9440(0x47, 0x513F1);
    func_0038C750();
    dist = func_0038CF00(self + 0x10, D_L01_001E29C0);
    if (dist < D_001DF1FC_sda) {
        scale = D_001DF200_sda + (dist / D_001DF1FC_sda) * (1.0f - D_001DF200_sda);
    } else {
        scale = 1.0f;
    }
    f20 = *(f32 *)(vars + 0x24) * scale;
    f21 = f20 * *(f32 *)(vars + 0x20);
    for (i = 0; i < 4; i++) {
        func_0038CE20(v, self + 0xC0, D_001DF210_sda[2 * i] * f21);
        func_0038CE20(t, self + 0xD0, D_L01_001DF214[2 * i] * f20);
        v[0] = t[0] + v[0]; v[1] = t[1] + v[1]; v[2] = t[2] + v[2];
        D_L01_001E22E0[2 * i] = D_001DF230_sda[2 * i];
        v[0] = v[0] + *(f32 *)(self + 0x10);
        v[1] = v[1] + *(f32 *)(self + 0x14);
        v[2] = v[2] + *(f32 *)(self + 0x18);
        D_L01_001E22E4[2 * i] = D_L01_001DF234[2 * i];
        D_L01_001E22A0[3 * i] = v[0];
        D_L01_001E22A4[3 * i] = v[1];
        D_L01_001E22A8[3 * i] = v[2];
        D_L01_001E22D0[i] = -1;
    }
    func_003A9440(6, func_00389598(0x3A));
    func_003A9440(0x42, 0x800000006Aul);
    func_003D3A24(4, D_L01_001E22A0, D_L01_001E22D0, D_L01_001E22E0, 1);
    for (i = 0; i < 4; i++) {
        D_L01_001E22D0[i] = *(s32 *)(vars + 0x28);
        D_L01_001E22E4[2 * i] += *(f32 *)(vars + 0x10);
    }
    func_003A9440(0x42, 0x8000000058ul);
    func_003D3A24(4, D_L01_001E22A0, D_L01_001E22D0, D_L01_001E22E0, 1);
    for (j = 0; j < 5; j++) {
        tbl = D_L01_002BB550 + j * 12;
        for (i = 0; i < 4; i++) {
            func_0038CE20(v, self + 0xC0, tbl[3 * i + 0] * f21);
            func_0038CE20(t, self + 0xD0, tbl[3 * i + 1] * f20);
            v[0] = t[0] + v[0]; v[1] = t[1] + v[1]; v[2] = t[2] + v[2];
            func_0038CE20(t, self + 0xE0, tbl[3 * i + 2] * f20);
            v[0] = t[0] + v[0]; v[1] = t[1] + v[1]; v[2] = t[2] + v[2];
            D_L01_001E22E0[2 * i] = D_001DF230_sda[2 * i];
            v[0] = v[0] + *(f32 *)(self + 0x10);
            v[1] = v[1] + *(f32 *)(self + 0x14);
            v[2] = v[2] + *(f32 *)(self + 0x18);
            D_L01_001E22E4[2 * i] = D_L01_001DF234[2 * i];
            D_L01_001E22A0[3 * i] = v[0];
            D_L01_001E22A4[3 * i] = v[1];
            D_L01_001E22A8[3 * i] = v[2];
            D_L01_001E22D0[i] = -1;
        }
        func_003A9440(0x42, 0x800000006Aul);
        func_003D3A24(4, D_L01_001E22A0, D_L01_001E22D0, D_L01_001E22E0, 1);
        for (i = 0; i < 4; i++) {
            D_L01_001E22D0[i] = *(s32 *)(vars + 0x2C);
            D_L01_001E22E4[2 * i] += *(f32 *)(vars + 0x10);
        }
        func_003A9440(0x42, 0x8000000058ul);
        func_003D3A24(4, D_L01_001E22A0, D_L01_001E22D0, D_L01_001E22E0, 1);
    }
    func_003A9440(0x47, 0x5360B);
}

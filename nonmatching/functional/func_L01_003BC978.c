/* functional: medium. Not byte-matched; the check could not run: src declares func_L01_003BC978(void) but retail reads a0 (the moby), so the prototype in L01_003BC530.c (extern at the top, callback passed to func_L01_00404A10) must become (u8 *) to compile in place. Compiled OK under a renamed symbol. COP2 vadd/vsub.xyz written as plain float xyz math (w from first operand). Matrix b50 is three rows written by func_0038D328. */
extern u8 D_001A4C60[];
extern u8 D_L01_001E29C0[];
extern u8 D_L01_001E29E0[];
extern u8 D_L01_001DE990[];
extern f32 D_L01_001DE9A0;
extern f32 D_L01_001DE9A4;
extern f32 D_L01_001DE9A8;
extern f32 D_L01_001DE9CC;
extern f32 D_L01_001DE9D0;
extern f32 D_L01_001DE980;
extern f32 D_L01_001DE984;
extern s32 D_L01_001DE9D4;
extern u8 D_L01_001DE9E0[];
extern f32 D_L01_001E2178[];
extern f32 D_L01_002A2D70[];
extern u8 D_L01_002BB0F0[];
extern u8 D_L01_002BB170[];
extern u8 D_L01_002BB260[];
extern void func_0038D000(void *, void *, void *);
extern void func_0038CF68(void *, void *, f32);
extern void func_0038CE20(void *, void *, f32);
extern f32 func_0038D160(f32, f32);
extern f32 func_0038DBA0(f32, f32);
extern void func_0038D308(void *, void *);
extern void func_0038D328(void *, void *);
extern void func_0038D028(void *, void *, void *);
extern void func_003A9440(s32, unsigned long);
extern long func_00389598(s32);
extern void func_0038C750(void);
extern void func_003D3A24(s32, void *, void *, void *, s32);

void func_L01_003BC978(u8 *m) {
    f32 b0[4] __attribute__((aligned(16)));
    f32 b10[4] __attribute__((aligned(16)));
    f32 b20[4] __attribute__((aligned(16)));
    f32 b30[4] __attribute__((aligned(16)));
    f32 b40[4] __attribute__((aligned(16)));
    f32 b50[12] __attribute__((aligned(16)));
    f32 b80[4] __attribute__((aligned(16)));
    u8 *vars = *(u8 **)(m + 0x68);
    f32 *P = (f32 *)D_L01_001E29C0;
    f32 *V = (f32 *)vars;
    f32 f20, f0, f1, ang;
    s32 i, n1, n2;
    u8 *src1, *src2, *aux1, *aux2;
    f32 *dst;

    func_0038D000(b20, D_L01_001DE990, D_L01_001E29E0);
    func_0038CF68(b0, b20, D_L01_001DE9A0);
    b0[0] = b0[0] + P[0];
    b0[1] = b0[1] + P[1];
    b0[2] = b0[2] + P[2];
    b20[0] = V[0] - P[0];
    b20[1] = V[1] - P[1];
    b20[2] = V[2] - P[2];
    b20[3] = V[3];
    func_0038CF68(b10, b20, D_L01_001DE9A0);
    b10[0] = b10[0] + P[0];
    b10[1] = b10[1] + P[1];
    b10[2] = b10[2] + P[2];
    b20[0] = b10[0] - b0[0];
    b20[1] = b10[1] - b0[1];
    b20[2] = b10[2] - b0[2];
    b20[3] = b10[3];
    func_0038CE20(b30, b20, *(f32 *)(vars + 0x18));
    b30[0] = b30[0] + b0[0];
    b30[1] = b30[1] + b0[1];
    b30[2] = b30[2] + b0[2];
    b20[0] = b30[0] - P[0];
    b20[1] = b30[1] - P[1];
    b20[2] = b30[2] - P[2];
    b20[3] = b30[3];
    func_0038CF68(b30, b20, D_L01_001DE9A0);
    b30[0] = b30[0] + P[0];
    b30[1] = b30[1] + P[1];
    b30[2] = b30[2] + P[2];

    f1 = *(f32 *)(vars + 0x10);
    f20 = f1 * D_L01_001DE9A8;
    f1 = f1 * D_L01_001DE9A4;
    f20 = (f20 - f1) * *(f32 *)(vars + 0x18) + f1;
    *(f32 *)(m + 0x2C) = *(f32 *)(*(u8 **)(m + 0x24) + 0x24) * f20;

    {
        f32 *Q = (f32 *)D_001A4C60;
        b20[0] = V[0] - Q[0];
        b20[1] = V[1] - Q[1];
        b20[2] = V[2] - Q[2];
        b20[3] = V[3];
    }
    ang = func_0038D160(b20[0], b20[1]);
    *(f32 *)(m + 0xF8) = ang;
    f0 = (func_0038DBA0(ang, P[6]) - 1.5707964f) * 0.6366198f * D_L01_001DE9CC;
    *(f32 *)(m + 0xF4) = (D_L01_001DE9D0 - f0) * *(f32 *)(vars + 0x18) + f0;
    func_0038D308(m + 0xC0, m + 0xF0);
    func_0038CE20(b20, m + 0xC0, ((*(f32 *)(vars + 0x18) * 0.5f) + 0.5f) * f20 * D_L01_001DE980);
    b30[0] = b30[0] - b20[0];
    b30[1] = b30[1] - b20[1];
    b30[2] = b30[2] - b20[2];
    func_0038D328(b50, m + 0xF0);
    func_0038CE20(b50, b50, D_L01_001DE980 * f20);
    func_0038CE20(b50 + 4, b50 + 4, D_L01_001DE984 * f20);
    func_0038CE20(b50 + 8, b50 + 8, D_L01_001DE984 * f20);
    b80[0] = b30[0];
    b80[1] = b30[1];
    b80[2] = b30[2];
    b80[3] = 1.0f;
    func_003A9440(8, 0);
    func_003A9440(0x14, 0xFF9000000260UL);
    func_003A9440(0x47, 0x5360B);
    func_003A9440(6, func_00389598(D_L01_001DE9D4));
    func_003A9440(0x42, (0x8000UL << 24) | 0x44);
    func_0038C750();
    for (i = 15; i >= 0; i--) {
        D_L01_001E2178[i] = 9.274833f;
    }

    if (func_0038DBA0(*(f32 *)(m + 0xF8), P[6]) < 1.5707964f) {
        aux1 = D_L01_001DE9E0;
        src1 = D_L01_002BB0F0;
        n1 = 8;
        src2 = D_L01_002BB170;
        n2 = 0xF;
        aux2 = D_L01_002BB260;
    } else {
        aux2 = D_L01_001DE9E0;
        src1 = D_L01_002BB170;
        n1 = 0xF;
        n2 = 8;
        aux1 = D_L01_002BB260;
        src2 = D_L01_002BB0F0;
    }
    if (n1 != 0) {
        dst = D_L01_002A2D70;
        for (i = 0; i < n1; i++) {
            func_0038D028(b40, src1 + i * 16, b50);
            dst[0] = b40[0];
            dst[1] = b40[1];
            dst[2] = b40[2];
            dst += 3;
        }
    }
    func_003D3A24(n1, D_L01_002A2D70, D_L01_001E2178, aux1, 1);
    dst = D_L01_002A2D70;
    if (n2 != 0) {
        for (i = 0; i < n2; i++) {
            func_0038D028(b40, src2 + i * 16, b50);
            dst[0] = b40[0];
            dst[1] = b40[1];
            dst[2] = b40[2];
            dst += 3;
        }
    }
    func_003D3A24(n2, D_L01_002A2D70, D_L01_001E2178, aux2, 1);
}

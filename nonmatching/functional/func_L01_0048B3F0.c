/* functional: high. functional: switch targets decoded from the retail jump table */
typedef struct {
    s32 w0;
    u8 pad4[0xAC];
} E_lv100_B0b;
extern E_lv100_B0b D_L01_00233DD8_0048B3F0[];
extern char D_L01_00233E2D_0048B3F0[];
extern s32 D_L01_001D8A2C;
extern s32 D_L01_001D8A34;
extern char *D_L01_001E08B0;
extern char D_L01_001D8BB0[];
extern s32 func_L01_004527A0(s32);
extern s32 func_L01_004527F0(s32);
extern int func_0011B2E8(char *, char *, ...);
extern void func_L01_00516FD8(s32, char *);

void func_L01_0048B3F0(void) {
    s32 a;
    s32 b;
    s32 w;

    w = D_L01_00233DD8_0048B3F0[D_L01_001D8A2C].w0;
    a = func_L01_004527A0(w);
    b = func_L01_004527F0(D_L01_00233DD8_0048B3F0[D_L01_001D8A2C].w0);
    switch (D_L01_00233DD8_0048B3F0[D_L01_001D8A2C].w0) {
    case 3:
        a += func_L01_004527A0(6);
        b += func_L01_004527F0(6);
        break;
    case 8:
        a += func_L01_004527A0(0x1B);
        b += func_L01_004527F0(0x1B);
        a += func_L01_004527A0(0x1C);
        b += func_L01_004527F0(0x1C);
        break;
    case 9:
        a += func_L01_004527A0(0x1D);
        b += func_L01_004527F0(0x1D);
        break;
    case 13:
        a += func_L01_004527A0(0x17);
        b += func_L01_004527F0(0x17);
        break;
    case 16:
        a += func_L01_004527A0(0x1A);
        b += func_L01_004527F0(0x1A);
        break;
    case 20:
        a += func_L01_004527A0(0x16);
        b += func_L01_004527F0(0x16);
        break;
    }
    func_0011B2E8(D_L01_001E08B0, D_L01_001D8BB0, a, b);
    func_L01_00516FD8(0x13000A, D_L01_001E08B0);
    func_L01_00516FD8(0x130005, D_L01_00233E2D_0048B3F0 + D_L01_001D8A34 * 0xB0);
}

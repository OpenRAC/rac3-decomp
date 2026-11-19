/* functional: high. functional: only register allocation differs */
typedef struct {
    u8 pad0[4];
    s32 x4;
    u8 pad8[0x36];
    s16 x3E;
    u8 pad40[0xF0 - 0x40];
} E_lv100_487670;
extern u8 D_00142CA0[];
extern u8 D_001425C0[];
extern E_lv100_487670 D_L01_002C5600_00487670[];
extern s32 D_L01_001D86E8;
extern s32 D_L01_001D86EC;
extern s32 D_L01_001D8718[2];
extern s32 D_L01_001D8770;
extern char D_L01_002EA828[];
extern char D_L01_002EA8A8[];
extern char D_L01_001D8778[];
extern char D_L01_001D8780[];
extern char D_L01_001D8788[];
extern s32 func_L01_00487508(s32, s32);
extern s32 func_L01_00487528(s32, s32);
extern s32 func_L01_00517190(s32, s32);
extern s32 func_L01_00516D60(s32, s32);
extern void func_L01_00517D18(s32);
extern s32 func_00381FF0(s32);
extern int func_0011B2E8(char *, char *, ...);

void func_L01_00487670(void) {
    s32 r;

    r = func_L01_00487508(D_L01_001D86E8, D_L01_001D86EC);
    if (D_00142CA0[r] != 0) {
        func_0011B2E8(D_L01_002EA828, D_L01_001D8778, func_00381FF0(D_L01_002C5600_00487670[D_001425C0[r]].x4));
        func_0011B2E8(D_L01_002EA8A8, D_L01_001D8778, func_00381FF0(D_L01_002C5600_00487670[D_001425C0[r]].x3E));
        func_L01_00517190(0xF000B, D_L01_001D8718[func_L01_00487528(D_L01_001D86E8, D_L01_001D86EC)] + 1);
        func_L01_00517190(0xF000D, D_L01_001D8718[func_L01_00487528(D_L01_001D86E8, D_L01_001D86EC)] + 1);
        func_L01_00516D60(0xF000B, 1);
        func_L01_00516D60(0xF000D, 1);
    } else {
        func_0011B2E8(D_L01_002EA828, D_L01_001D8780);
        func_0011B2E8(D_L01_002EA8A8, D_L01_001D8788);
        func_L01_00517190(0xF000B, 3);
        func_L01_00517190(0xF000D, 3);
    }
    if (D_L01_001D8770 != r) {
        D_L01_001D8770 = r;
        func_L01_00517D18(0xF0008);
    }
    D_L01_001D8770 = r;
}

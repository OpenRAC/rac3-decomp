/* functional: high. functional: layout only */
typedef struct {
    s32 w0;
    char name[0xAC];
} E_lv100_B0c;
typedef struct {
    s32 y;
    s32 x;
} P_lv100_9DC0;
extern E_lv100_B0c D_L01_00233DD8_0048B080[];
extern P_lv100_9DC0 D_L01_002E9DC0_0048B080[];
extern s32 D_L01_001D8A3C;
extern s32 D_L01_001E08B0;
extern s32 D_L01_001E08B4;
extern s32 D_L01_001E08B8[];
extern s32 func_0011A264(void *, s32, s32);
extern s32 func_003BB118(s32);
extern s32 func_00381FF0(s32);
extern int func_0011B2E8(char *, char *, ...);
extern void func_L01_0048AFB8(s32);

void func_L01_0048B080(void) {
    char buf[0x20];
    s32 p;
    s32 i;
    s32 w;
    s32 s;
    s32 k;

    func_0011A264(buf, 0, 0x20);
    p = func_003BB118(0);
    D_L01_001E08B0 = p;
    p += 0x10;
    for (k = 0; k < 6; k++) {
        D_L01_001E08B8[k] = p;
        p += 0x20;
    }
    D_L01_001E08B4 = p;
    for (i = 0; i < D_L01_001D8A3C; i++) {
        w = D_L01_00233DD8_0048B080[i].w0;
        if (w == 1 || w == 2 || w == 4 || w == 8 || w == 0x1B || w == 0x1C || w == 9 || w == 0x1D || w == 5 || w == 0xD || w == 0x17 || w == 0xA || w == 0x12 || w == 0xE) {
            if (w > 0) {
                s = D_L01_002E9DC0_0048B080[w % 0x3C].x;
            } else {
                s = D_L01_002E9DC0_0048B080[1].x;
            }
        } else {
            if (w > 0) {
                s = D_L01_002E9DC0_0048B080[w % 0x3C].y;
            } else {
                s = D_L01_002E9DC0_0048B080[1].y;
            }
        }
        if (s != 0) {
            buf[0] = '%';
            buf[1] = 's';
            buf[2] = 0;
            func_0011B2E8(D_L01_00233DD8_0048B080[i].name, buf, func_00381FF0(s));
        } else {
            buf[0] = ' ';
            buf[1] = 0;
            func_0011B2E8(D_L01_00233DD8_0048B080[i].name, buf);
        }
        func_L01_0048AFB8(i);
    }
}

/* functional: high. Not byte-exact (register/scheduling only); semantics read against PAL asm: all gp slots and constants taken from the PAL disassembly (not the NTSC draft). */
typedef struct { s32 w0; s16 h4; s16 h6; s16 h8; s16 h10; } R_0033F388;
extern R_0033F388 D_L01_00278DA0[];
extern s32 D_L01_001E18C0[];
extern s32 D_L01_001E18C4[];
extern s32 D_L01_001E18C8[];
extern f32 D_L01_001E18CC[];
extern s32 D_001DD050_sda;
extern s32 D_001DD054_sda;
extern f32 D_001DD058_sda;
extern f32 D_001DD094_sda;
extern u16 D_001DD098_sda;
__asm__(".extern D_001DD050_sda, 4");
__asm__(".extern D_001DD054_sda, 4");
__asm__(".extern D_001DD058_sda, 4");
__asm__(".extern D_001DD094_sda, 4");
__asm__(".extern D_001DD098_sda, 2");
extern s32 func_0038CAD0(void *);
extern s32 func_0038CB00(void *);

void func_L01_0033F388(void) {
    s32 i;
    s32 n;
    R_0033F388 *p;

    if (D_001DD050_sda != 0) {
        for (i = 9; i >= 0; i--) {
            D_L01_00278DA0[i].h8 = 0;
        }
        D_001DD050_sda = 0;
        D_L01_001E18C0[0] = 0;
        n = (s32)(D_001DD058_sda / (D_001DD094_sda * 0.02f));
        D_L01_001E18C8[0] = n;
        D_L01_001E18CC[0] = 1.0f / (f32)n;
    }
    if (D_L01_001E18C4[0] == 0) {
        if (func_0038CAD0(D_L01_001E18C0) != 0) {
            for (p = D_L01_00278DA0; p < D_L01_00278DA0 + 10; p++) {
                if (p->h8 == 0) {
                    p->h6 = D_001DD098_sda;
                    D_L01_001E18C0[0] = (D_001DD054_sda * 5 + 2) / 6;
                    p->h8 = 1;
                    p->h4 = *(u16 *)D_L01_001E18C8;
                    break;
                }
            }
        }
    }
    for (p = D_L01_00278DA0; p < D_L01_00278DA0 + 10; p++) {
        if (p->h8 != 0) {
            if (func_0038CB00(&p->h4) != 0) {
                p->h8 = 0;
            }
        }
    }
}

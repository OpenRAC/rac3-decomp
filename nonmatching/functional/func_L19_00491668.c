/* functional: high. EXACT at level_19 (check.py MATCH): rename-port of the matched PAL func_L09_004B6B18 (table D_L19_002EED48, callee func_L01_0041A4F0). */
typedef struct S_4961F0 {
    int a0;
    int a4;
    int a8;
    unsigned c;
    int kind;
    unsigned char flag;
} S_4961F0;
extern S_4961F0 D_L19_002EED48[];
__asm__(".extern D_L19_002EED48, 16");
extern unsigned D_142BA0[];
__asm__(".extern D_142BA0, 16");
extern unsigned char D_00142693[];
__asm__(".extern D_00142693, 16");
int func_L01_0041A4F0(void);

void func_L19_00491668(void) {
    int i;
    int j;
    int n;
    i = 0;
    while (D_L19_002EED48[i].a0) {
        switch (D_L19_002EED48[i].kind) {
        case 0:
            D_L19_002EED48[i].flag = (D_142BA0[D_L19_002EED48[i].c >> 2] & (1 << (D_L19_002EED48[i].c & 0x1F))) || func_L01_0041A4F0();
            n = i + 1;
            break;
        case 1:
            D_L19_002EED48[i].flag = 0;
            n = i + 1;
            for (j = 0; ((unsigned *)D_L19_002EED48[i].c)[j]; j++) {
                D_L19_002EED48[i].flag = D_L19_002EED48[i].flag ||
                    (D_142BA0[((unsigned *)D_L19_002EED48[i].c)[j] >> 2] & (1 << (((unsigned *)D_L19_002EED48[i].c)[j] & 0x1F))) ||
                    func_L01_0041A4F0();
            }
            i = n;
            continue;
        case 2:
            D_L19_002EED48[i].flag = (D_142BA0[D_L19_002EED48[i].c >> 2] & (1 << (D_L19_002EED48[i].c & 0x1F))) || func_L01_0041A4F0();
            n = i + 1;
            break;
        case 3:
        case 4:
        default:
            D_L19_002EED48[i].flag = D_00142693[0] || func_L01_0041A4F0();
            n = i + 1;
            break;
        }
        i = n;
    }
}

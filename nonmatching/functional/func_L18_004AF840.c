/* functional: high. Same behaviour as retail; bytes differ slightly (register allocation of the loop index) which does not matter. Walks a table of 0x18-byte entries until a zero first word; per entry sets flag (+0x14) from a bit in a bit array (D_00142BA0) or a null-terminated list of bit indices, OR the result of func_L01_0041A4F0 (kinds 3,4 and others test byte D_00142693 instead). */
typedef struct S_4AF840 {
    int a0;
    int a4;
    int a8;
    unsigned c;
    int kind;
    unsigned char flag;
} S_4AF840;
extern S_4AF840 D_L18_002ECBA8[];
__asm__(".extern D_L18_002ECBA8, 16");
extern unsigned D_00142BA0[];
__asm__(".extern D_00142BA0, 16");
extern unsigned char D_00142693[];
__asm__(".extern D_00142693, 16");
int func_L01_0041A4F0(void);

void func_L18_004AF840(void) {
    int i;
    int j;
    i = 0;
    while (D_L18_002ECBA8[i].a0) {
        switch (D_L18_002ECBA8[i].kind) {
        case 0:
            D_L18_002ECBA8[i].flag = (D_00142BA0[D_L18_002ECBA8[i].c >> 2] & (1 << (D_L18_002ECBA8[i].c & 0x1F))) || func_L01_0041A4F0();
            i++;
            break;
        case 1:
            D_L18_002ECBA8[i].flag = 0;
            for (j = 0; ((unsigned *)D_L18_002ECBA8[i].c)[j]; j++) {
                D_L18_002ECBA8[i].flag = D_L18_002ECBA8[i].flag ||
                    (D_00142BA0[((unsigned *)D_L18_002ECBA8[i].c)[j] >> 2] & (1 << (((unsigned *)D_L18_002ECBA8[i].c)[j] & 0x1F))) || func_L01_0041A4F0();
            }
            i++;
            break;
        case 2:
            D_L18_002ECBA8[i].flag = (D_00142BA0[D_L18_002ECBA8[i].c >> 2] & (1 << (D_L18_002ECBA8[i].c & 0x1F))) || func_L01_0041A4F0();
            i++;
            break;
        case 3:
        case 4:
        default:
            D_L18_002ECBA8[i].flag = D_00142693[0] || func_L01_0041A4F0();
            i++;
            break;
        }
    }
}

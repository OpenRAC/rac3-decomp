/* Ported from rac2-decomp's func_002B6788 (a twin of this function's code), names renamed from retail's
   relocations; 2 instruction(s) still differ under this file's flags. */
extern char D_001FE020[];
extern int D_001F0A00[];
extern void func_L01_0045E690(int, long);
extern void func_00193888(void *, int, void (*)(int, long), unsigned long);

void func_L39_005C1310(void) {
    char *b = D_001FE020;
    int *d = D_001F0A00;
    *(unsigned int *)(b + 0x90) = 0xFFFFFFFFu;
    func_00193888((void *)(d[0x14AC] + d[0x14A7]), 0, func_L01_0045E690,
                  (unsigned long)(unsigned int)(b + 0x90));
}
/* Ported from rac4-decomp's func_L00_00708228 (a twin of this function's code), names renamed from retail's
   relocations; 1 instruction(s) still differ under this file's flags. */
extern int func_00126150(void);
extern int func_001260F0(int arg0, int arg1);
extern void func_001915F0(void);
extern int D_001E1A60;

void func_L39_0067EC00(void) {
    D_001E1A60 = func_001260F0(func_00126150(), 0x3C);
    func_001915F0();
}
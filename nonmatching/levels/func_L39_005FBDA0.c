/* Ported from rac4-decomp's func_004E5550 (a twin of this function's code), names renamed from retail's
   relocations; 6 instruction(s) still differ under this file's flags. */
void func_L39_0059A578(s32, s32, s32);
extern s32 D_001A455C[];
extern s16 D_001FC368[];
extern s32 D_001D4D58;

void func_L39_005FBDA0(void) {
    D_001FC368[0] = (D_001A455C[0] = 1);
    D_001D4D58 = 1;
    func_L39_0059A578(1, 1, -1);
}
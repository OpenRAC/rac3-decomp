/* Ported from rac2-decomp's func_L00_00403CB8 (a twin of this function's code), names renamed from retail's
   relocations; 3 instruction(s) still differ under this file's flags. */

extern int func_L39_00557CB0(void);
extern int func_L39_005B4398(int n);
extern void func_L39_00557890(int *v);
extern void func_L39_00557CE8(int *v);

void func_L39_00557D20(int *arg)
{
    if (func_L39_00557CB0() == 0) {
        int i;
        for (i = 0; i < 16; i++) {
            if (D_L39_0024D590[i] == 0) {
                D_L39_0024D590[i] = arg;
                return;
            }
        }
    } else {
        int **slot = &D_L39_0024D590[func_L39_005B4398(16)];
        func_L39_00557890(*slot);
        func_L39_00557CE8(*slot);
        *slot = arg;
    }
}
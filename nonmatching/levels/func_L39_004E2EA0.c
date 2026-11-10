/* Ported from rac4-decomp's func_L00_0051EC00 (a twin of this function's code), names renamed from retail's
   relocations; 1 instruction(s) still differ under this file's flags. */
typedef struct {
    void *f0;
    void *f4;
    void *f8;
    int (*fC)(void *, int, int, int, int, int, int, int);
} Type1;
typedef struct {
    Type1 *f0;
} Type2;

int func_L39_004E2EA0(Type2 *arg0, int arg1, int arg2, int arg3, int arg4, int arg5, int arg6) {
    return arg0->f0->fC(arg0, 3, arg1, arg2, arg3, arg4, arg5, arg6);
}

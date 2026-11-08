/* func_L02_00431568: near miss 10 diff (w2 p2w2); 260 bytes, 15 levels. rac2 twin func_L02_00331440 + 4th float arg f15 saved/restored at +0x24.
   Only remaining difference: FPR allocation swap f22/f23 (retail: f15 copy in f22, old20 in f23; ours reversed).
   Tried decl order, compare form, early save: no change. */
extern int func_L01_0045A898(void *a0, void *a1, float f12);
extern void *func_L01_0045B958(char *a0);

int func_L02_00431568(void *a0, void *a1, int a2, float f12, float f13, float f14, float f15) {
    char *rec;
    int old38;
    float old28;
    float old20;
    float old24;
    int ret;
    rec = (char *)func_L01_0045B958((char *)a0);
    if (rec == 0)
        return 8;
    old38 = *(int *)(rec + 0x38);
    old28 = *(float *)(rec + 0x28);
    *(int *)(rec + 0x38) = a2;
    if (0.0f < f13)
        *(float *)(rec + 0x28) = f13;
    old20 = *(float *)(rec + 0x20);
    if (0.0f < f14)
        *(float *)(rec + 0x20) = f14;
    old24 = *(float *)(rec + 0x24);
    if (0.0f < f15)
        *(float *)(rec + 0x24) = f15;
    ret = func_L01_0045A898(a0, a1, f12);
    *(float *)(rec + 0x24) = old24;
    *(int *)(rec + 0x38) = old38;
    *(float *)(rec + 0x28) = old28;
    *(float *)(rec + 0x20) = old20;
    return ret;
}

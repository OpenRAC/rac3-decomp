/* func_L07_0035CA80: NEAR 3 diff (w5 p2w1). rac2 twin func_L00_00403C30 is a different loop (16 entries); this is find a0 in int[8] and clear.
   Diff: retail does move a1,0 first then lui/addiu on v1; ours uses v0 for lui. Variant e2 below.
*/
extern int D_L07_001E0F90[8];
void func_L07_0035CA80(int a0)
{
    int i = 0;
    int *p = &D_L07_001E0F90[0];
    while (i < 8) {
        if (*p == a0) {
            *p = 0;
            return;
        }
        i++;
        p++;
    }
}

/* func_L39_005C2960: NEAR 2 diff (w5 p2w1). Only the constant-1 register differs (retail v1, ours v0) in if(s->f4){func_00194AF8(); s->f6=1;}.
   Twin func_002B7AD0 (rac2 core). D_00225660 is the real name.
*/
struct S { short pad; short pad2; short f4; char f6; int pad3[4]; };
extern struct S D_00225660;
void func_00194AF8();
void func_L39_005C2960(void)
{
    struct S *s = &D_00225660;
    if (s->f4 != 0) {
        func_00194AF8();
        s->f6 = 1;
    }
}

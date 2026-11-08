/* func_L07_003318D8: near miss, 2 diff (Sonnet w1, p2)
   rac2 func_L04_00415EA8
   Left: lui goes to $v0 then addiu $v1; retail lui $v1 directly
*/
extern int D_L07_001DF600[];
void func_L07_003318D8(int a0)
{
    char *s = *(char **)((char *)a0 + 0x68);
    int i;
    int *p = D_L07_001DF600;
    for (i = 1; i >= 0; i--) {
        if (*p != 0) {
            *p = 0;
        }
        p++;
    }
    s[0xA9] = 0;
}

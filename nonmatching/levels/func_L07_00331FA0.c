/* func_L07_00331FA0: near miss, 5 diff (Sonnet w1, p2)
   rac2 func_00351EE8
   Left: lw 0x18(s0) must be scheduled before the lui/lw of the table pointer
*/
typedef struct { unsigned char pad[0x20]; unsigned char f; unsigned char pad2[0xDF]; } S_ent;
extern int func_L07_00331FF0(char *);
extern S_ent *D_L07_001DF41C[];
int func_L07_00331FA0(char *a0)
{
    char *s = *(char **)(a0 + 0x68);
    if (func_L07_00331FF0(a0) != 0) {
        return 1;
    }
    return D_L07_001DF41C[0][*(int *)(s + 0x18)].f != 1;
}

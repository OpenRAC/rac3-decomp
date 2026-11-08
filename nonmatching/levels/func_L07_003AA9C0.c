/* func_L07_003AA9C0: near miss 5 diff (Sonnet w3, p2w1)
   file: src/levels/07_annihilation_nation/L07_003A9DB0.c, 72 bytes
   mask -0x11 hoisted into a1 above sd s0 in retail; mine a0 after
*/
extern void func_L07_00334740(void);
extern void func_L07_003AAA50(void *, int);

void func_L07_003AA9C0(char *a)
{
    int *p = *(int **)(a + 0x68);
    int v = p[0x188 / 4];
    p[0x53C / 4] = 0;
    p[0x188 / 4] = v & ~0x10;
    func_L07_00334740();
    func_L07_003AAA50(a, 1);
}

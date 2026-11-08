/* func_L39_00510298: near miss 2 diff (Sonnet w3, p2w1)
   file: src/levels/39_multiplayer_menu/L39_0050F5B8.c, 76 bytes
   only prologue order differs: retail move s0,a0 before sd s1; tried param types, callee returns, negation
*/
extern void func_L39_004F74E8(void *, int, int);
extern int func_L39_00515BD8(void *);

void func_L39_00510298(char *a, int b)
{
    func_L39_004F74E8(a + 4, 0, 0x18);
    if (func_L39_00515BD8(a) == 0)
        *(int *)(a + 0x1C) = b;
}

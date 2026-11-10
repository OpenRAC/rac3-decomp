/* func_L20_0053FFD8: near miss, 1 diff (Sonnet w1, p2)
   rac2 func_L02_003D69F0 (not really)
   Left: only diff is the trailing delay-slot addiu sp that retail keeps in the LINKER_REMNANT at 00540000; body matches
*/
extern int func_003EDBA8(int, int);
int func_L20_0053FFD8(int a0, int a1)
{
    return a1 == 2 ? 1 : func_003EDBA8(a0, a1);
}

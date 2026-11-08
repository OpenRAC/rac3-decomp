/* func_L39_00608FE0: near miss, 4 diff (Sonnet w1, p2)
   rac2 func_003501E0
   Left: needs --as ps2as; scheduler puts ld $ra before the two lui $at stores, retail interleaves
*/
__asm__(".extern D_001D5C90_sda, 4");
extern int func_00139E08(int);
extern int D_001D5C90_sda;
extern int D_L39_0024CC2C;
extern int D_L39_0024CC28;

void func_L39_00608FE0(int value)
{
    while (func_00139E08(0) == value && D_001D5C90_sda == 0) {}
    D_L39_0024CC2C = 0;
    D_L39_0024CC28 = 1;
}

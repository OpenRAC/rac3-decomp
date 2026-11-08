/* func_L20_003EE6B8: near miss 5 diff (Sonnet w3, p2w1)
   file: src/levels/20_final_boss/L20_003EE688.c, 48 bytes
   flag test D_00142C58&0x2000000; retail schedules lw after addiu sp, mask in a1
*/
__asm__(".extern D_00142C58, 16");
extern int D_00142C58;
extern void func_003C2880(int);

void func_L20_003EE6B8(int arg)
{
    if (D_00142C58 & 0x2000000)
        func_003C2880(arg);
}

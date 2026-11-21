/* functional: high. Same instructions as retail; only the $at vs scratch register choice for the two D_L39 stores differs (retail assembler macro form). */
__asm__(".extern D_001D5C90_sda, 4");
extern int func_00139E08(int);
extern int D_001D5C90_sda;
extern int D_L39_0024CC2C __attribute__((section(".data")));
extern int D_L39_0024CC28 __attribute__((section(".data")));

void func_L39_00608FE0(int value)
{
    while (func_00139E08(0) == value && D_001D5C90_sda == 0) {}
    D_L39_0024CC2C = 0;
    D_L39_0024CC28 = 1;
}

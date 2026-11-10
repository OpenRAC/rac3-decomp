/* func_L39_005A5F48: NEAR 5 (p2w1 w7). 28 bytes, 15 levels, file src/levels/shared/L39_005A5F48.c; twin func_002D7B00.
   Names: D_002403FC/D_001A4528 unsized int[] (lui form), D_001D4CEC_sda (gp). Diff is only scheduling/regs:
   retail lui v0;lw v0;lui v1;sw 0;ori;sw -- ours hoists the 2nd lui (a0) before the lw and lw into v1. */
extern int D_002403FC[];
extern int D_001A4528[];
extern int D_001D4CEC_sda;

void func_L39_005A5F48(void)
{
    int v = D_002403FC[0];
    D_001A4528[0] = 0;
    D_001D4CEC_sda = v | 0x800;
}

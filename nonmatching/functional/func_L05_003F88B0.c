/* functional: high. Hand-written asm; `add` (trapping) written as plain int add; overflow cannot occur on these values. Struct at D_L05_001EA6C0: +0x18 pointer, +0x1C int. */
extern int D_L05_001EA6C0[];

int func_L05_003F88B0(void)
{
    int *p = (int *)D_L05_001EA6C0[6];
    int n = D_L05_001EA6C0[7];

    if (p != 0 && n < 0) {
        return (unsigned int)(-(p[0x98 / 4] + n)) >> 5;
    }
    return -1;
}

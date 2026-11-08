/* func_L39_005F3668: NEAR 1 at levels 40-53 (matches at 39 and NTSC-U): false fold, gp base differs
   (L39 gp slot 0x3BAC = D_001E045C_sda; levels 40-53 use 0xAC($gp)). file src/levels/shared/L39_005F2FF8.c.
   Callee decl in file context is (void*,s32,void*,s32,s32): a4 cast to void*. */
extern int D_L39_0024BB68;
__asm__(".extern D_L39_0024BB68, 16");
extern int D_L39_00242918;
__asm__(".extern D_L39_00242918, 16");
extern u8 *D_001E045C_sda;
extern u8 D_001FE020[];

int func_L39_005F3668(int a0, int a1, int a2, int a3, int a4, int a5)
{
    int index;
    int r;
    u8 *p;
    if (a0 == 0xFFFFFFFF)
        return -1;
    index = a0 * 4 + a1 * 2 + a2 + D_L39_00242918;
    if (index >= D_L39_0024BB68)
        return -1;
    r = func_L39_005F3138(D_001E045C_sda + index * 32, a3, (void *)a4, 0, a5);
    if (r >= 0) {
        p = D_001FE020 + r * 128;
        *(int *)(p + 0xDC) = a4;
        *(short *)(p + 0xCA) = index;
    }
    return r;
}

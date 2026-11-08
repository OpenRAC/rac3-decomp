/* Near miss, ported from rac2-decomp's func_002A0300 (cross-game near pair). NEAR: GP-SLOT: level 39 matches (D_001E0848_sda, .extern hint on D_L39_0024BF58, unsigned long arg) but levels 40-53 use gp slot 0x498 vs 0x3f98: 1 diff each */
__asm__(".extern D_L39_0024BF58, 16");
extern void func_003A9440(unsigned int, unsigned long);
extern int func_001264E0(int);
extern void func_003C3690(void);
extern void func_003C3660(void);
extern int func_L39_005B25C8(void *, void *, int, int);
extern char *D_L39_0024BF58;
extern int D_001E0848_sda __attribute__((section(".sdata")));

void func_L39_005ABFE8(void *object, int mode)
{
    func_003A9440(0x47, 0x5360B);
    func_001264E0(0);
    func_003C3690();
    D_001E0848_sda = func_L39_005B25C8(object, D_L39_0024BF58, mode, 0);
    func_003C3660();
    D_L39_0024BF58 -= 0x10;
}

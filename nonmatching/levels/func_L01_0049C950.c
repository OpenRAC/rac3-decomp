/* func_L01_0049C950: NEAR 3 diff (w5 p2w1). Only the global-load scheduling differs (retail loads D_001D52FC before 'move a0,v0'). */
extern int *D_001D52FC[];
extern int *func_003B9BD0(int);
extern void func_003BA4F8(void *, int);
extern void func_L01_0049D200(void);
extern void func_L01_0049D190(int);
void func_L01_0049C950(int a0)
{
    int *p = func_003B9BD0(0);
    func_003BA4F8(p, D_001D52FC[0][0x1C4/4]);
    func_L01_0049D200();
    func_L01_0049D190(a0);
}

/* Near miss, ported from rac2-decomp's func_00278EB0 (cross-game near pair). NEAR: gp/lui fixed with .extern hints (5 globals), z is D_L39_0024CAD8 (non-gp), D_L39_001E13C8 sdata, f26=0 store dropped (retail has none); remaining: scheduler loads D_L39_0024CAD8 after x/y (retail right after counter) -> register assignment a3/t0/t1 vs v1; 6 variants no change */
__asm__(".extern D_L39_0024B9C8, 16");
__asm__(".extern D_L39_0024CAD8, 16");
__asm__(".extern D_L39_00242920, 16");
__asm__(".extern D_L39_0024B9D0, 16");
__asm__(".extern D_002402F4, 16");
extern void func_003A92F0(unsigned long);
extern int func_00139E08(int);
extern void func_003A9108(void);
extern void func_L39_005F3948(void);
extern int D_L39_0025F680[8];
typedef struct { int x, y, z, pad0C, f10, f14, f18; char pad1C[0x26 - 0x1C]; short f26; } S_584568_Cam;
extern S_584568_Cam D_L39_0025C600;
extern int D_L39_0024B9C8;
extern int D_L39_0024CAD8;
extern int D_L39_001E13C8 __attribute__((section(".sdata")));
extern int D_L39_00242920;
extern float D_L39_0024B9D0;
extern int D_002402F4;

void func_L39_00584568(void)
{
    S_584568_Cam *state;
    int x, y, z;
    func_003A92F0(1UL);
    func_00139E08(0);
    D_L39_0024B9C8++;
    z = D_L39_0024CAD8;
    x = D_L39_0025F680[3];
    y = D_L39_0025F680[4];
    state = &D_L39_0025C600;
    state->f14 = z - 0x60000;
    D_L39_001E13C8 = 0x60000;
    state->x = x + 0x60000;
    state->y = y + 0x60000;
    state->z = state->x + 0xD0800;
    D_L39_00242920 = 0x2000;
    func_003A9108();
    func_L39_005F3948();
    state->f18 = D_002402F4;
    D_L39_0024B9D0 = 1.0f;
}

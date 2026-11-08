/* Near miss, ported from rac2-decomp's func_002E11C0 (cross-game near pair). NEAR: GP-SLOT: matches level_39 exactly (D_001E13C0_sda store, .extern 16 hints, front-end callee names); levels 40-53 differ by 1 instr only: store disp 0x1020($gp) vs L39 0x4b10 */
__asm__(".extern D_L39_0024CAD0, 16");
__asm__(".extern D_L39_0024C910, 16");
__asm__(".extern D_002402F4, 16");
__asm__(".extern D_002402F0, 16");
extern char *D_L39_0024CAD0;
extern char *D_001E13C0_sda;
extern char *D_L39_0024C910;
extern int D_002402F0;
extern int D_002402F4;
extern char D_L39_002B85A0[];
extern void func_001264E0(int);
extern void func_003DEF90(void);
extern void func_0038CD80(void *first, int second, int third);
extern void func_003DED18(void);

void func_L39_005EDE28(void)
{
    char *pointer = D_L39_0024CAD0;
    int other = D_002402F4;
    D_L39_0024C910 = pointer;
    pointer += 0x10;
    D_002402F0 = other;
    D_001E13C0_sda = pointer;
    func_001264E0(0);
    func_003DEF90();
    func_0038CD80(D_L39_002B85A0, 0x3200, 0x40);
    func_003DED18();
}

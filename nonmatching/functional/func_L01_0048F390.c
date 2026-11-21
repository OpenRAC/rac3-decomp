/* functional: high. */
extern u8 *D_001D52FC;
extern s16 D_001CCFD4[];
extern void func_L01_0047EC88(void);
extern void func_L01_0048F4E0(void);
extern s32 func_L01_0047EBE0(void);
extern s32 func_L01_0048EE70(void);
extern void func_L01_00517748(s32);
extern void func_L01_00516090(s32);

void func_L01_0048F390(s32 a0) {
    func_L01_0047EC88();
    func_L01_0048F4E0();
    if ((*(s32 *)(D_001D52FC + 0x1C4) & 0xD10) != 0 && D_001CCFD4[0] == 0) {
        func_L01_00517748(func_L01_0047EBE0());
        func_L01_00516090(a0);
    } else if (*(s32 *)(D_001D52FC + 0x1C4) & 0x80) {
        func_L01_00517748(func_L01_0048EE70());
        func_L01_00516090(a0);
    }
}

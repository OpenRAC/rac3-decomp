/* func_L14_00362C28: near miss, 17 diff: needs @ps2as on L14_003622D0.c (the 64-bit constants as ori/dsll/ori); D_L14_001E1220_b is a second name for the same address (resolve_symbols row needed) so the address is rebuilt for the second call; left: the order of the argument moves before the calls (retail a2,a3,a0,a1 in the first call, a0..a3 in the second; ours a3,a2,...) and the 1200/1220 lui order
   Level 14 (Koros) only; flags of its file in config/levels/text_parts.txt. */
extern u8 D_L14_00286520[];
extern int D_L14_001E1220[];
extern int D_L14_001E1220_b[];
extern void func_003A9440(s32, unsigned long);
extern int D_L14_001E1200[];
extern void func_003D3A24(s32, void *, void *, void *, s32);
extern void func_L14_00362B68(f32, s32, s32, s32, s32);
void func_L14_00362C28(s32 a0, s32 a1, s32 a2, s32 a3, s32 a4, s32 a5, f32 t) {
    func_003A9440(0x42, 0x800000006AUL);
    func_L14_00362B68(t, a0, a1, a2, a4);
    func_003D3A24(4, D_L14_00286520, D_L14_001E1200, D_L14_001E1220, 1);
    func_003A9440(0x42, 0x8000000058UL);
    func_L14_00362B68(t, a0, a1, a3, a5);
    func_003D3A24(4, D_L14_00286520, D_L14_001E1200, D_L14_001E1220_b, 1);
}

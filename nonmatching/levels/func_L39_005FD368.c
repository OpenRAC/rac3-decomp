/* Near miss, ported from rac4-decomp's func_004E7CB0 (cross-game near pair). NEAR: level_39 place is an exact MATCH; the other 14 places differ by 2 (jal target 0x45d5d0 vs 0x590360, and $gp slot 0x1020 vs 0x4b10): per-level callee and sda slot, GP-SLOT-like; needs level aliases for callee and slot */
__asm__(".extern D_L39_0024CAD0, 16");
extern u32 *D_L39_0024CAD0;
extern u32 *D_001E13C0_sda;
extern u8 D_001A40D0[];
extern u8 D_002411B0[];
extern void func_00590360(u32 *, u8 *, s32);

void func_L39_005FD368(void) {
    D_L39_0024CAD0[0] = 0x30000009;
    D_L39_0024CAD0[1] = (u32)D_001A40D0;
    D_L39_0024CAD0[2] = 0;
    D_L39_0024CAD0[3] = 0x50000009;
    D_L39_0024CAD0 += 4;
    D_L39_0024CAD0[0] = 0x10000003;
    D_L39_0024CAD0[1] = 0;
    D_L39_0024CAD0[2] = 0;
    D_L39_0024CAD0[3] = 0x50000003;
    D_001E13C0_sda = D_L39_0024CAD0 + 4;
    func_00590360(D_001E13C0_sda, D_002411B0, 0x30);
    D_L39_0024CAD0 += 12;
}

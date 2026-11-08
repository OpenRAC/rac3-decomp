/* Near miss, ported from rac2-decomp's func_0028FC48 (cross-game near pair). FLAGS: Only 64-bit constant synthesis (ori/dsll32 form) needs the assembler @ps2as; file src/levels/shared/L01_00421730.c lacks it in config/levels/text_parts.txt (sibling L01_004208C8.c has it). Alias D_L01_001E1068 (+ .extern 16 hint) for lui accesses, D_L01_001E1068_sda for the final $gp store, D_001D4B */
extern long *D_L01_001E1068;
__asm__(".extern D_L01_001E1068, 16");
extern long *D_L01_001E1068_sda;
extern s32 D_001D4BD0;
extern s32 D_001D4BD4;
__asm__(".extern D_001D4BD0, 16");
__asm__(".extern D_001D4BD4, 16");

void func_L01_00421738(s32 a0, s32 a1, s32 a2, s32 a3, long p4, s32 p5) {
    long *q;
    *(s32 *)((u8 *)D_L01_001E1068 + 0) = 0x10000003;
    *(s32 *)((u8 *)D_L01_001E1068 + 4) = 0;
    *(s32 *)((u8 *)D_L01_001E1068 + 8) = 0;
    *(s32 *)((u8 *)D_L01_001E1068 + 12) = 0x50000003;
    q = D_L01_001E1068;
    D_L01_001E1068 = q + 2;
    q[2] = 0x4400000000008001L;
    q[3] = 0x4410;
    q[4] = 70;
    q[5] = p4;
    if (p5 != 0) {
        q[6] = (a0 + D_001D4BD0 - 8) | ((long)(a1 + D_001D4BD4 - 8) << 16) | 0xFFFFF000000000L;
        q[7] = (a2 + D_001D4BD0 - 8) | ((long)(a3 + D_001D4BD4 - 8) << 16) | 0xFFFFF000000000L;
    } else {
        q[6] = ((a0 << 4) + D_001D4BD0 - 16) | ((long)((a1 << 4) + D_001D4BD4 - 16) << 16) | 0xFFFFF000000000L;
        q[7] = ((a2 << 4) + D_001D4BD0 - 16) | ((long)((a3 << 4) + D_001D4BD4 - 16) << 16) | 0xFFFFF000000000L;
    }
    D_L01_001E1068_sda = D_L01_001E1068 + 6;
}

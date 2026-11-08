/* Near miss, ported from rac2-decomp's func_L08_00300100 (cross-game near pair). FLAGS: needs @ps2as (inline lui/ori/mtc1 float const); file L24_00402798.c has default as (10 diff); must be split into its own file with @ps2as like config/* /text_parts.txt entries. C: D_L24_001E6DF0[0] = 0.62f; func_003873C0(); */
extern f32 D_L24_001E6DF0[];
extern void func_003873C0();

void func_L24_00402808(void) {
    D_L24_001E6DF0[0] = 0.62f;
    func_003873C0();
}

/* Near miss, ported from rac4-decomp's func_00472690 (cross-game near pair). FLAGS: matches only with check.py --as ps2as (inline lui/ori/mtc1 pi constant); default assembler pools the constant via $gp; file flags have no @ps2as */
extern s32 func_0019D510(void);

f32 func_L39_005B44C8(void) {
    return (f32)(func_0019D510() - 0x4000) * 3.1415927f * (1.0f / 16384.0f);
}

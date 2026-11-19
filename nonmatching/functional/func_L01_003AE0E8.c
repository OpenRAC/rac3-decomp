/* functional: high. from the repo's PAL near-miss draft (0 diff at level 01 only with divs_nops row 'func_L01_003AE0E8 2'; plain check shows only div-nop/epilogue diff); all gp slots and 0x1960 verified vs PAL asm; false fold: level 03 reads other gp slots */
extern s32 func_0038CAD0(void *);
extern void func_L01_004AAC98(s32, s32, u8 *, s32);
extern s32 func_0038DBD8(f32, s32, s32);
__asm__(".extern D_001DE4A0_sda, 4");
__asm__(".extern D_001DE4B0_sda, 4");
__asm__(".extern D_001DE4B4_sda, 4");
extern s32 D_001DE4A0_sda;
extern s32 D_001DE4B0_sda;
extern s32 D_001DE4B4_sda;
void func_L01_003AE0E8(u8 *m) {
    u8 *pv;
    pv = *(u8 **)(m + 104);
    if (func_0038CAD0(pv + 16)) {
        *(s32 *)(pv + 16) = (D_001DE4A0_sda * 5 + 2) / 6;
        func_L01_004AAC98(0, 0, m, 6496);
    }
    *(s32 *)(m + 120) = func_0038DBD8((f32)*(s32 *)(pv + 16) / (f32)((D_001DE4A0_sda * 5 + 2) / 6), D_001DE4B0_sda, D_001DE4B4_sda);
}

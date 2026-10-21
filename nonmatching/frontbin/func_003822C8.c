/* Draft of func_003822C8 from the C of boot_elf's copy, func_003826A8 (config/frontend_pairs.tsv),
   with front-end names mapped to frontbin's. With 381140.c's flags tools/check.py reports 1 diff. */

typedef struct { u8 p0[0x64C]; s32 f64C; s32 f650; s32 f654; } S_160C40_3826C8;
extern S_160C40_3826C8 D_160C40_003826A8;
extern u8 D_2D2100[];
extern s32 D_1A1F0C[];
extern s32 func_003A26F0(s32, s32, s32);
extern void func_003824D0_003826A8(void *, unsigned long *, s32, s32);
void func_003822C8(void) {
    unsigned long out[4];
    S_160C40_3826C8 *g = &D_160C40_003826A8;
    func_003A26F0((s32)D_2D2100, g->f650 + g->f64C, g->f654);
    func_003824D0_003826A8(D_2D2100, out, D_1A1F0C[0], 0x3FFC00);
    *(unsigned long *)0x1D4D38 = out[0];
}

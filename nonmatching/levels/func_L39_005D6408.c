/* Near miss, ported from rac4-decomp's func_L00_0061DAA8 (cross-game near pair). NEAR: size hint on D_L39_002429AE gives retail lui/lbu; remaining: retail does the final store via lui $at/sw absolute while ours uses $gp for D_002413A8 (same symbol read via $gp); 3 tries incl. hint 4 */
__asm__(".extern D_002413A8, 4");
__asm__(".extern D_L39_002429AE, 16");
extern u8 D_L39_002429AE;
extern s32 D_002413A8;
extern s32 D_001A5810[];

void func_L39_005D6408(void) {
    if (D_L39_002429AE == 0) {
        s32 v = D_002413A8;
        D_002413A8 = v + 1;
        if ((v + 1) % 50 == 0 && D_001A5810[0] != 0) {
            D_002413A8 = v + 11;
        }
    }
}

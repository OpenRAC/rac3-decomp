/* Near miss, ported from rac4-decomp's func_0011A1C8 (cross-game near pair). NEAR: call then return 0 is right in shape; retail has move v0,zero before ld ra, SN puts it after; 7 wordings same bytes */
__asm__(".extern D_L39_00464674, 16");
extern s32 func_00126280(s32);
extern s32 D_L39_00464674[];

s32 func_L39_004D5928(void) {
    func_00126280(D_L39_00464674[0]);
    return 0;
}

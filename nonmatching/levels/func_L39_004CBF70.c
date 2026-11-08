/* Near miss, ported from rac4-decomp's func_L00_00507D70 (cross-game near pair). NEAR: SQ_RA: only frame (0x10 vs 0x20, ra at 0x10 restored before s0) differs; body identical */
extern s32 func_L39_004C4F30(s32);
extern s32 func_L39_004E0ED0(s32 *);

s32 func_L39_004CBF70(s32 *arg0) {
    if (arg0 != 0) {
        if ((*arg0 != 0x74) || (func_L39_004C4F30(2) != 0)) {
            return func_L39_004E0ED0(arg0);
        }
        return 0;
    }
    return 0;
}

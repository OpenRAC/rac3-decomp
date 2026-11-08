/* Near miss, ported from rac4-decomp's func_L00_00507DC8 (cross-game near pair). NEAR: SQ_RA: early-return form (==0 return 0) fixes branch layout; only frame 0x30 / ra@0x20 / save slots differ */
s32 func_L39_004C4F30(s32);
s32 func_L39_004E0F28(s32, s32);

s32 func_L39_004CBFC8(s32 arg0, s32 arg1) {
    if (func_L39_004C4F30(2) == 0) {
        return 0;
    }
    return func_L39_004E0F28(arg0, arg1);
}

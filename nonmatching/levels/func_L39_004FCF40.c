/* Near miss, ported from rac4-decomp's func_L00_005381D8 (cross-game near pair). NEAR: SQ_RA frame only (size 0x58, field 0x50, callees func_L00_004BEED8/func_L39_004FCF88 fixed) */
void *func_L00_004BEED8(s32);
s32 func_L39_004FCF88(void *);

void *func_L39_004FCF40(void) {
    void *temp_v0;
    void *var_v0;
    temp_v0 = func_L00_004BEED8(0x58);
    var_v0 = 0;
    if (temp_v0 != 0) {
        func_L39_004FCF88(temp_v0);
        (*(s32 *)((u8 *)(temp_v0) + 0x50)) = 1;
        var_v0 = temp_v0;
    }
    return var_v0;
}

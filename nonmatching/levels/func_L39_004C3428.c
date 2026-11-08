/* Near miss, ported from rac4-decomp's func_L00_004FF228 (cross-game near pair). NEAR: SQ_RA frame/save order only; body reordered (success path first) matches */
s32 func_0011D534();
s32 func_L00_004BC6C8(s32, s32, s32, s32, s32);
void *func_L00_004BEED8(s32);

void *func_L39_004C3428(void) {
    void *temp_v0;
    temp_v0 = func_L00_004BEED8(0x70);
    if (temp_v0 != 0) {
        func_0011D534(temp_v0, 0, 0x70);
        (*(void **)((u8 *)(temp_v0) + 4)) = (void *) ((u8 *)temp_v0 + 0x40);
        (*(s32 *)((u8 *)(temp_v0) + 0x6C)) = 1;
        return temp_v0;
    }
    func_L00_004BC6C8(0x14, 0xA3, 0x21, 0, 0);
    return 0;
}

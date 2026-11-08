/* Near miss, ported from rac4-decomp's func_L00_00519658 (cross-game near pair). NEAR: SQ_RA frame/save order only; fn-ptr-first if reordered; callees func_L39_004DBA08 and func_L00_004BC6C8 (jal masked, unverified by name) */
s32 func_L00_004BC6C8(s32, s32, s32, s32, s32);
void *func_L39_004DBA08();

s32 func_L39_004DD858(s32 arg0) {
    s32 (*fn)(s32) = *(s32 (**)(s32))((u8 *)func_L39_004DBA08() + 0x28);
    if (fn != 0) {
        return fn(arg0);
    }
    func_L00_004BC6C8(0xA, 0x6B, 0xE, 0, 0);
    return -1;
}

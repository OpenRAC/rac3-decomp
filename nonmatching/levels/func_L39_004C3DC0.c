/* Near miss, ported from rac4-decomp's func_L00_004FFBC0 (cross-game near pair). NEAR: SQ_RA frame/save order only (u64 flag read as long OK); callee func_L39_004C4EE0 by address */
s32 func_L39_004C4EE0();

s32 func_L39_004C3DC0(void *arg0) {
    if (arg0 != 0) {
        if (!(func_L39_004C4EE0() & 0x3000) || ((*(long *)((u8 *)(arg0) + 0x100)) & 0x40000)) {
            return (*(s32 (**)(void *))((u8 *)((*(void **)((u8 *)(arg0) + 8))) + 0x24))(arg0);
        }
        return 1;
    }
    return 1;
}

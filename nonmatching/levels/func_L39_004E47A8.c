/* Near miss, ported from rac4-decomp's func_L00_005205A8 (cross-game near pair). NEAR: SQ_RA: 16-byte save slots (frame 0x20, ra at 0x10); also retail branch layout bnez/b with move v0,zero after; shape alloc+memset(0x18)+[0x14]=1 right */
extern void *func_L39_004BEED8(s32);
extern void func_0011D534(void *, s32, s32);

void *func_L39_004E47A8(void) {
    void *obj = func_L39_004BEED8(0x18);
    if (obj == 0) {
        return 0;
    }
    func_0011D534(obj, 0, 0x18);
    *(s32 *)((u8 *)obj + 0x14) = 1;
    return obj;
}

/* Near miss, ported from rac4-decomp's func_L00_005381D8 (cross-game near pair). NEAR: SQ_RA: retail 0x20 frame with ra at 0x10, C gives 0x10 frame (plus v0/v1 order) */
extern void *func_L39_004BEED8(s32);
extern void func_L39_004FC410(void *);

void *func_L39_004FC3C8(void) {
    void *obj = func_L39_004BEED8(0x110);
    if (obj != 0) {
        func_L39_004FC410(obj);
        *(s32 *)((u8 *)obj + 0x108) = 1;
    }
    return obj;
}

/* Near miss, ported from rac4-decomp's func_L00_00540338 (cross-game near pair). NEAR: body matches retail (calls func_0011D534(p,0,0x60), if(p!=0) first); only the frame differs: retail 0x20 with 16-byte save slots (ra 0x10) vs our 0x10 frame */
extern void *func_0011D534(void *, s32, s32);
extern s32 func_L39_004BC6C8(s32, s32, s32, s32, s32);
extern void *func_L39_004BEED8(s32);

void *func_L39_00504528(void) {
    void *p = func_L39_004BEED8(0x60);
    if (p != 0) {
        func_0011D534(p, 0, 0x60);
        return p;
    }
    func_L39_004BC6C8(6, 0x72, 0x21, 0, 0);
    return 0;
}

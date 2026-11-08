/* Near miss, ported from rac4-decomp's func_L00_005205A8 (cross-game near pair). NEAR: SQ_RA: retail 0x20 frame with ra at 0x10 restored before s0 (and b-to-end shape); C gives 0x10 frame */
typedef struct {
    s32 pad[5];
    s32 f14;
} S_505780;

extern void *func_L39_004BEED8(s32);
extern void func_0011D534(void *, s32, s32);

S_505780 *func_L39_00505780(void) {
    S_505780 *p = func_L39_004BEED8(0x18);
    if (p == 0) {
        return 0;
    }
    func_0011D534(p, 0, 0x18);
    p->f14 = 1;
    return p;
}

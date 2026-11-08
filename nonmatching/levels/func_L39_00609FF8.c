/* Near miss, ported from rac4-decomp's func_004F1618 (cross-game near pair). NEAR: HW-ADDR: retail writes DMA regs 0x1000B420/B410/B430 via lui/ori constants; honest extern symbols go via $gp, only forbidden hardcoded (volatile) addresses can produce it; not attempted further */
extern void func_L39_00609638(s32);
extern void func_00126270(s32);
extern u32 D_1000B420;
extern u32 D_1000B410;
extern u32 D_1000B430;

s32 func_L39_00609FF8(u8 *p) {
    func_L39_00609638(5);
    D_1000B420 = 0;
    D_1000B410 = 0;
    D_1000B430 = 0;
    func_00126270(*(s32 *)(p + 0x40));
    return 1;
}

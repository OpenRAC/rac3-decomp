/* func_L01_004D2498: partial (w5 p2w1). MATCH at 34 PAL levels (01..38) + NTSC-U, but levels 39-53 use 0x45e0 not 0x4610: needs a split by place.
   Round 12: measured again at levels 01 and 39: MATCH at 01, 1 diff at 39 (0x4610 against 0x45e0), see func_L01_004D2470. */
extern void func_003AD278(char *);
void func_L01_004D2498(char *a0, int a1)
{
    func_003AD278(a0 + (a1 * 0x230 + 0x4610));
}

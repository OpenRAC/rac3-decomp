/* Near miss, ported from rac4-decomp's func_004F0BE8 (cross-game near pair). NEAR: needs hardware register addresses (0x1000F590/F520/B000) and volatile; forbidden constructs; not attempted */
extern void func_0012CD60(void);
extern void func_0012CDB0(void);

void func_L39_006095C8(s32 a) {
    func_0012CD60();
    *(u32 *)0x1000F590 = *(u32 *)0x1000F520 | 0x10000;
    *(u32 *)0x1000B000 = a;
    *(u32 *)0x1000F590 = *(u32 *)0x1000F520 & ~0x10000;
    func_0012CDB0();
}
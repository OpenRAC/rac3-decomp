/* Near miss, ported from rac2-decomp's func_L03_0038AA20 (cross-game near pair). FLAGS: donor C unchanged; retail builds f32 constants inline (lui/ori/mtc1) which needs the @ps2as marker on src/levels/shared/L19_003357A0.c in config/levels/text_parts.txt (currently no marker); file holds INCLUDE_ASM stubs perhaps so needs its own single-function range */
extern void func_L19_00335898(s8 *, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32, f32);
extern s8 D_L19_00276F40[];

void func_L19_003357A0(s8 *arg0) {
    s8 *s0;
    s32 i;
    s32 b1;
    s32 b2;
    i = 0;
    b1 = (s32)D_L19_00276F40;
    s0 = *(s8 **)(arg0 + 0x68);
    b2 = b1 + 0x400;
    do {
        func_L19_00335898(arg0, ((*(s32 *)(s0 + 0xDC) + i) << 8) + b1, *(s32 *)(s0 + 0x38), *(s32 *)(s0 + 0x40), *(s32 *)(s0 + 0x60), *(s32 *)(s0 + 0x44), *(s32 *)(s0 + 0x64), *(f32 *)(s0 + 0x50), *(f32 *)(s0 + 0x70), *(f32 *)(s0 + 0x54), *(f32 *)(s0 + 0x74), 0.89999997615814208984375f);
        func_L19_00335898(arg0, ((*(s32 *)(s0 + 0xDC) + i) << 8) + b2, *(s32 *)(s0 + 0x38), *(s32 *)(s0 + 0x48), *(s32 *)(s0 + 0x68), *(s32 *)(s0 + 0x4C), *(s32 *)(s0 + 0x6C), *(f32 *)(s0 + 0x58), *(f32 *)(s0 + 0x78), *(f32 *)(s0 + 0x5C), *(f32 *)(s0 + 0x7C), 0.100000001490116119384765625f);
        i += 1;
    } while (i < 4);
}
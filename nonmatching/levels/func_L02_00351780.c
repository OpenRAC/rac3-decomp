/* func_L02_00351780: near miss (Sonnet w4 p2w2), false fold */
/* 184 bytes, 6 places; MATCH at levels 02,05,11 and NTSC-U; levels 08,20,28 differ in 1 insn: sw to 0x198($v1) instead of 0x2d8 */
/* src/levels/shared/L02_00351780.c; written from asm, rac2 twin was wrong shape */
extern u16 *D_L02_0021B460[];
extern u8 *D_L02_001DE99C;
__asm__(".extern D_L02_001DE99C, 16");
extern s32 D_L02_001DE9D8;

void func_L02_00351780(u8 *object) {
    u16 *p;
    u8 *entity;
    if (object[0x21] == 0xFF)
        return;
    p = D_L02_0021B460[object[0x21]];
    while (object[0x21] != 0xFF && object[0x21] <= D_L02_001DE9D8 && p != 0 &&
           ((s16)p[-1] >= 0 || p == D_L02_0021B460[object[0x21]])) {
        entity = D_L02_001DE99C + ((*p & 0x7FFF) << 8);
        if (entity == 0)
            break;
        if (*(s16 *)(entity + 0xAA) == *(s16 *)(object + 0xAA))
            *(s32 *)(*(u8 **)(entity + 0x68) + 0x2D8) = 1;
        p++;
    }
}

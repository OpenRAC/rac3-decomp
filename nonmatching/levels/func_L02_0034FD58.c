/* func_L02_0034FD58: near miss (w3 p2w2): MATCH at 6 levels (incl. 02 and NTSC-U); false fold: levels 04,08,17,22,28 store at +0x2F8 instead of +0x2D8.
   Twin func_L19_0041C328. Could be delivered as split_places variant. */
extern u16 *D_L02_0021B460[];
extern u8 *D_L02_001DE99C;
__asm__(".extern D_L02_001DE99C, 16");
extern s32 D_L02_001DE9D8;

void func_L02_0034FD58(u8 *object) {
    u16 *p;
    u8 *entity;
    if (object[0x21] == 0xFF) {
        return;
    }
    p = D_L02_0021B460[object[0x21]];
    while (object[0x21] != 0xFF && object[0x21] <= D_L02_001DE9D8 && p != 0 &&
           ((s16)p[-1] >= 0 || p == D_L02_0021B460[object[0x21]])) {
        entity = D_L02_001DE99C + ((*p & 0x7FFF) << 8);
        if (entity == 0) {
            break;
        }
        if (*(s16 *)(entity + 0xAA) == *(s16 *)(object + 0xAA)) {
            *(s32 *)(*(u8 **)(entity + 0x68) + 0x2D8) = 1;
        }
        p++;
    }
}

/* functional: high. 5 words differ from retail (register allocation only). */
extern u8 D_001426E0[];
extern s32 D_001D545C;
extern u8 *D_L01_001E001C;
__asm__(".extern D_L01_001E001C, 16");
s32 func_L01_00326898(s32 arg, u8 *save) {
    extern s32 func_L01_003294A0(s32 a, List_003290D8 *l, s32 key);
    extern void func_L01_00456230(void *, s32);
    extern void func_L01_004450F0(void *, s32, s32);
    s32 packed = (D_001426E0[0xE5] << 8) + D_001426E0[0xE6];
    s32 key;
    s32 area;
    s32 index;
    s32 next;
    u8 *moby;
    u8 *vars;
    D_001426E0[0xE5] = 0;
    D_001426E0[0xE6] = 0;
    key = packed & 0x7FF;
    area = (packed >> 11) & 31;
    if (*(s32 *)(save + 0x40) != 0) return 0;
    if (area != D_001D545C) return 0;
    if (!func_L01_003294A0(arg, (List_003290D8 *)save, key)) return 0;
    index = *(s32 *)(*(u8 **)(*(u8 **)(save + 8) + 0x68) + 0x18);
    if (index == -1) return 0;
    moby = D_L01_001E001C + (index << 8);
    while (moby != 0) {
        if (*(s16 *)(moby + 0xAA) == 0x19E4) break;
        vars = *(u8 **)(moby + 0x68);
        next = *(s32 *)vars;
        if (next == -1) break;
        moby = D_L01_001E001C + (next << 8);
    }
    if (moby != 0 && *(s16 *)(moby + 0xAA) == 0x19E4) {
        s32 result_index;
        vars = *(u8 **)(moby + 0x68);
        result_index = *(s32 *)(vars + 0x18);
        if (result_index != -1) {
            u8 *result = D_L01_001E001C + (result_index << 8);
            result[0x30] = 255;
            *(u16 *)(result + 0x34) &= 0xFFFD;
            func_L01_00456230(result, 1);
            func_L01_004450F0((void *)arg, 11, -1);
            return 1;
        }
    }
    return 0;
}

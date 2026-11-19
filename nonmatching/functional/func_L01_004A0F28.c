/* functional: high. 68 diff at default flags (register allocation, load ordering); identical behaviour. The two paths store before the sound call as in retail. */
extern u8 D_00143950[];
extern s32 D_00143AD0[];
extern s32 D_L01_001E0CD0[];
extern s32 func_003B9C58(void *);
extern s32 *func_003B9BD0(s32);
extern void func_003A5348(s32, s32, s32);
void func_L01_004A0F28(s32 flags) {
    s32 *p;
    s32 v;
    if (func_003B9C58(func_003B9BD0(0)) != 3) {
        return;
    }
    if (flags & 0x8000) {
        p = (s32 *)(D_00143950 + 0x74 + D_L01_001E0CD0[0] * 16);
        v = *p - 2;
        if (v < 0) {
            v = 0;
        }
        *p = v;
        func_003A5348(3, 0, 0);
    } else if (flags & 0x2000) {
        p = (s32 *)(D_00143950 + 0x74 + D_L01_001E0CD0[0] * 16);
        v = *p + 2;
        if (v >= 0x65) {
            v = 0x64;
        }
        *p = v;
        func_003A5348(3, 0, 0);
    }
    D_00143AD0[D_L01_001E0CD0[0] * 8] = *(s32 *)(D_00143950 + 0x74 + D_L01_001E0CD0[0] * 16);
}

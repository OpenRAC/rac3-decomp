/* functional: high. 16 instructions differ from retail (register allocation and scheduling only); same reads, writes and calls. */
extern f32 D_L01_001DEC80_003C76A0;
__asm__(".extern D_L01_001DEC80_003C76A0, 4");
extern void func_L01_003C6EF0(void *, void *);
extern s32 func_L01_003C6860(void *);
extern void func_L01_003C7810(void *, void *, s32, s32, s32);
extern void func_L01_004450F0(void *, s32, s32);
extern void func_L01_003C54E8(void *, void *);
extern void func_L01_003C57B0(void *, void *, s32);
extern void func_L01_003C6E78(void *, void *);
extern void func_L01_003C5290(void *, void *);

void func_L01_003C76A0(void *obj, u8 *s, s32 enabled) {
    s32 *arr = (s32 *)(s + 0x720);
    func_L01_003C6EF0(obj, s);
    if (enabled && arr[*(s32 *)(s + 0x6BC)] != -1 && !func_L01_003C6860(obj)) {
        s32 i = *(s32 *)(s + 0x6BC);
        func_L01_003C7810(obj, s, arr[i], *(s32 *)(s + i * 4 + 0x6D0), 1);
        *(f32 *)(s + 0xC8) = D_L01_001DEC80_003C76A0 * 0.0200000014f;
        if (*(s32 *)(s + *(s32 *)(s + 0x6BC) * 4 + 0x710) != -1) {
            func_L01_004450F0(obj, 1, -1);
        } else {
            func_L01_004450F0(obj, 2, -1);
        }
        func_L01_003C54E8(obj, s);
    } else {
        *(s32 *)(s + 0xC8) = 0;
        func_L01_003C57B0(obj, s, *(s32 *)(s + *(s32 *)(s + 0x6BC) * 4 + 0x6D0));
        if (*(s32 *)(s + *(s32 *)(s + 0x6BC) * 4 + 0x6F0)) {
            func_L01_004450F0(obj, 5, -1);
        } else {
            func_L01_004450F0(obj, 4, -1);
        }
        func_L01_003C6E78(obj, s);
        func_L01_003C5290(obj, s);
    }
}

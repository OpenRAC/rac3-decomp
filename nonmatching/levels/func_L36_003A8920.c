/* func_L36_003A8920: near miss, level 36 (Vidcomic 1 Special Edition). about 90 differences (word shifts from one cause): the logic and call structure are right (switch with bodies in retail's order 0, 0x42, 1); retail keeps the constant 1 (case 1 compare and the D_L36_001DEADC store) in $a0 loaded before the lbu, ours puts it in $a1 and loads it later; local copy of the state byte and per-case loads of the object pointer tried */
__asm__(".extern D_L36_001DEADC, 4");
__asm__(".extern D_L36_001DEAE0, 4");
__asm__(".extern D_L36_001DEAE4, 4");
__asm__(".extern D_L36_001DEAE8, 4");
__asm__(".extern D_L36_001DEAD8, 4");
extern s32 D_L36_001DEADC;
extern f32 D_L36_001DEAE0;
extern f32 D_L36_001DEAE4;
extern s32 D_L36_001DEAE8;
extern f32 D_L36_001DEAD8;
extern u8 D_L36_001E1FB0[];
extern f32 D_L36_001E1FB4[];
extern void func_L03_0034B218(u8 *, s32, s32, s32, f32, void *);
extern void func_L36_003A8AB0(u8 *);
extern void func_L01_004450F0(u8 *, s32, s32);
extern s32 func_L01_004561B8(u8 *);
extern void func_003A52A0(s32, s32, u8 *);
extern s32 func_0038CAD0(u8 *);
extern f32 func_003C4088(f32, f32, f32);
extern void func_L30_0034C8A8(u8 *, u8 *);
extern void func_L01_0044E820(u8 *, s32);
extern f32 func_0038DAB8(f32, f32);
void func_L36_003A8920(u8 *a0) {
    u8 *s = *(u8 **)(a0 + 0x68);
    switch (*(u8 *)(a0 + 0x20)) {
    case 0:
        *(s32 *)(s + 0x50) = 0;
        if (D_L36_001DEADC == 0) {
            D_L36_001DEADC = 1;
            func_L03_0034B218(D_L36_001E1FB0, 0x11, 8, D_L36_001DEAE8, D_L36_001DEAE0, (void *)func_L36_003A8AB0);
        }
        func_L01_004450F0(a0, 1, -1);
        break;
    case 0x42:
        if (func_L01_004561B8(a0) != 0) {
            func_003A52A0(1, 0, a0);
            *(s32 *)(s + 0x54) = 0x43;
        }
        if (func_0038CAD0(s + 0x54) == 0) {
            if (*(s32 *)(s + 0x54) == 0x32) {
                func_003A52A0(0, 0, a0);
            }
            *(u8 *)(a0 + 0x23) = (s32)((f32)*(s32 *)(s + 0x54) * 128.0f / 80.0f);
            D_L36_001E1FB4[0] = func_003C4088(D_L36_001DEAE4, D_L36_001DEAE0, (f32)*(s32 *)(s + 0x54) / 80.0f);
            func_L30_0034C8A8(D_L36_001E1FB0, a0);
        }
        break;
    case 1:
        if (*(s32 *)(s + 0x58) != 0) {
            func_L01_0044E820(a0, 0x80000080);
        }
        *(f32 *)(a0 + 0xF8) = func_0038DAB8(*(f32 *)(a0 + 0xF8), D_L36_001DEAD8);
        break;
    }
    func_L36_003A8CF8(a0);
}

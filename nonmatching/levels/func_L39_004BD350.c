// near miss: logic complete (lookup via func_L39_004BD428, then BD4E0/BDC08, then func_001264E0(0), (2)); 53 diff: retail saves s regs in 8-byte slots (frame 0x30, addiu addresses, p hoisted before branch, !flag path falls through) but the file's @ee29 flags give 16-byte slots (frame 0x50, ori addresses)
extern void func_L39_004BD428(u32, s32 *, s32 *, s32 *);
extern void func_L39_004BD4E0(s32, s32, s32, s32, s32, s32);
extern void func_L39_004BDC08(s32, s32, s32, s32, s32, s32);
extern void func_001264E0(s32);

void func_L39_004BD350(s32 a, s32 b, s32 c, u32 flags) {
    s32 l[3];
    s32 d = b ^ c;
    s32 *p;

    if (flags & 1) {
        p = (s32 *)(a - d - 0x14);
        *p = 0;
        func_L39_004BD428(flags >> 1, &l[0], &l[1], &l[2]);
        func_L39_004BD4E0(a - d, a, (a - d) - l[0], c, l[1], l[2]);
    } else {
        p = (s32 *)(a - 0x14);
        *p = (s32)p;
        func_L39_004BD428(flags >> 1, &l[0], &l[1], &l[2]);
        func_L39_004BDC08(a, a + d, a - l[0], c, l[1], l[2]);
    }
    func_001264E0(0);
    func_001264E0(2);
}

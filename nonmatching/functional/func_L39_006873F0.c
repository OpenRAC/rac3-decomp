/* functional: high. If the object has a child at +0xA8, calls func_L39_006A5F28 on it, stores a byte at child+0x2B0, notifies the object (event 0x11) and returns 1; else returns 0. */
extern void func_L39_006A5F28(void *);
extern void func_L39_00687268(void *, s32);

s32 func_L39_006873F0(u8 *self, s32 a1, s32 a2, u8 val) {
    u8 *child = *(u8 **)(self + 0xA8);
    if (child == 0) {
        return 0;
    }
    func_L39_006A5F28(child);
    child[0x2B0] = val;
    func_L39_00687268(self, 0x11);
    return 1;
}

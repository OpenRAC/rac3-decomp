/* functional: high. If the object has a child at +0xB0, runs its setup calls with a2/a5/a6, stores min(a4-1,199) at child+0x394, notifies the object (event 0x13) and returns a2; else returns 0. */
extern void func_L39_006AB6D0(void *);
extern void func_L39_006AB700(void *, s32);
extern void func_L39_006AB778(void *, s32);
extern void func_L39_006AB6F8(void *, s32);
extern void func_L39_00687268(void *, s32);

s32 func_L39_00687450(u8 *self, s32 a1, s32 a2, s32 a3, s32 a4, s32 a5, s32 a6) {
    u8 *child = *(u8 **)(self + 0xB0);
    s32 t;
    if (child == 0) {
        return 0;
    }
    func_L39_006AB6D0(child);
    func_L39_006AB700(child, a2);
    func_L39_006AB778(child, a5);
    t = a4 - 1;
    *(s32 *)(child + 0x394) = t < 200 ? t : 199;
    func_L39_006AB6F8(child, a6);
    func_L39_00687268(self, 0x13);
    return a2;
}

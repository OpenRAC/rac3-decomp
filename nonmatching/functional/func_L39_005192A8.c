/* functional: high. Stores a value in the object, mirrors it into a global slot when a flag is set, refreshes via func_L39_005190C8, returns 0 if the value is 0 else -1. */
extern s32 D_L39_0046F558;
extern s32 *func_0011A6E0(void);
extern void func_L39_005190C8(void);

s32 func_L39_005192A8(u8 *self, s32 val) {
    *(s32 *)(self + 0xC) = val;
    if (D_L39_0046F558 != 0) {
        *func_0011A6E0() = val;
    }
    func_L39_005190C8();
    return val != 0 ? -1 : 0;
}

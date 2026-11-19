/* functional: high. Only register choice for the entry differs from retail; third argument is passed straight through to the callee. */
extern void func_003EDAD0(void *p, s32 mask, s32 set);

s32 func_L01_00514DD0(u8 **o, u32 i, s32 set) {
    void *p;
    if (i < 0x23) {
        o = (u8 **)*o;
        i <<= 2;
        p = *(void **)(i + (u32)o + 0x50);
        if (p != 0) {
            func_003EDAD0(p, 1, set);
            return 1;
        }
    }
    return 0;
}

/* functional: medium. 92 instructions differ (scheduling); same stores and calls; arguments 9 and 10 come from the stack. */
typedef int u128 __attribute__((mode(TI)));
extern u8 *func_003C24B0(s32, s32);
extern void func_003A52A0(s32, s32, void *);
extern void func_003C7C38(void *);

u8 *func_L01_003CC9C8(u8 *obj, u8 *pos, u8 *dir, u8 flag, u8 b2e, u8 b2f, u16 h2a, u16 h2c, s32 w20, s32 w24) {
    u8 *n = func_003C24B0(0x1B10, 0x80);
    u8 *st;
    if (n == 0) {
        *(u128 *)(obj + 0x10) = *(u128 *)pos;
        *(u128 *)(obj + 0xF0) = *(u128 *)dir;
        return n;
    }
    func_003A52A0(flag ? 0 : 1, 0, n);
    *(s32 *)(obj + 0x98) = 0;
    *(u16 *)(obj + 0x34) = (*(u16 *)(obj + 0x34) & 0xEFFF) | 0x42;
    n[0x30] = 0xFF;
    *(u8 **)(n + 0xB8) = obj;
    *(u16 *)(n + 0x32) = 0;
    n[0x31] = 0;
    st = *(u8 **)(n + 0x68);
    *(u128 *)(n + 0x10) = *(u128 *)(obj + 0x10);
    st[0x2E] = b2e;
    st[0x2F] = b2f;
    *(u16 *)(st + 0x2C) = h2c;
    *(s32 *)(st + 0x20) = w20;
    *(s32 *)(st + 0x24) = w24;
    if (flag) st[0x30] = 1;
    if (*(u16 *)(obj + 0x34) & 1) {
        obj[0x23] = 0;
        *(u16 *)(obj + 0x34) &= 0xFFFE;
        *(u16 *)(st + 0x2A) = *(u16 *)(st + 0x2C);
        *(u128 *)(obj + 0x10) = *(u128 *)pos;
        *(u128 *)(obj + 0xF0) = *(u128 *)dir;
        *(u16 *)(st + 0x28) = 1;
    } else {
        *(u16 *)(st + 0x2A) = h2a;
        *(u128 *)st = *(u128 *)pos;
        *(u16 *)(st + 0x28) = 0;
        *(u128 *)(st + 0x10) = *(u128 *)dir;
    }
    func_003C7C38(obj);
    return n;
}

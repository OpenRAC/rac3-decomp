/* func_L14_00361F40: near miss, 10 diff: only register naming; the lw of the object pointer should be $v1 and the +0x20 pointer $a0 (ours the reverse); about 9 wordings tried (declaration order, struct types, one pointer)
   Level 14 (Koros) only; flags of its file in config/levels/text_parts.txt. */
extern void func_L14_00361E90(void *, s32, void *);
typedef int u128_t __attribute__((mode(TI)));
void func_L14_00361F40(void *a0, s32 a1) {
    u128_t buf;
    u8 *s;
    u8 *p;
    f32 w;
    func_L14_00361E90(a0, a1, &buf);
    s = *(u8 **)(a1 + 0x2C);
    p = s + 0x20;
    w = *(f32 *)(p + 0x1C);
    *(u128_t *)(s + 0x30) = buf;
    *(f32 *)(p + 0x1C) = w;
    s = *(u8 **)(a1 + 0x30);
    p = s + 0x20;
    w = *(f32 *)(p + 0x1C);
    *(u128_t *)(s + 0x30) = buf;
    *(f32 *)(p + 0x1C) = w;
}

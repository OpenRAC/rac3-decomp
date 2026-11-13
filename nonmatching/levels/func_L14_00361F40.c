/* func_L14_00361F40: near miss, 8 diff: only register naming; retail keeps the object pointer in $v1 and the +0x20 pointer in $a0, this C the reverse (with the vector stored through s, 10 diff); callee and own prototypes are the ones the file already declares (the earlier draft did not compile in its file); about 15 wordings tried (pointer/struct types, a set_xyz inline, store base, declaration order)
   Level 14 (Koros) only; flags of its file in config/levels/text_parts.txt. */
extern void func_L14_00361E90(u8 *, u8 *, f32 *);
typedef int u128_t __attribute__((mode(TI)));
void func_L14_00361F40(void *a0, s32 a1) {
    u128_t buf;
    u8 *s;
    u8 *p;
    f32 w;
    func_L14_00361E90(a0, (u8 *)a1, (f32 *)&buf);
    s = *(u8 **)(a1 + 0x2C);
    p = s + 0x20;
    w = *(f32 *)(p + 0x1C);
    *(u128_t *)(p + 0x10) = buf;
    *(f32 *)(p + 0x1C) = w;
    s = *(u8 **)(a1 + 0x30);
    p = s + 0x20;
    w = *(f32 *)(p + 0x1C);
    *(u128_t *)(p + 0x10) = buf;
    *(f32 *)(p + 0x1C) = w;
}

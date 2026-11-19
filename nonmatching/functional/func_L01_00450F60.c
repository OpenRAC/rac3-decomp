/* functional: high. Same calls and order as retail; sqrt via sqrt_asm as the original; a2 (nonzero: a matrix pointer) is passed through to func_0038D000 as retail leaves it in $a2. Only register allocation differs. */
extern s32 D_L01_001D673C;
extern void func_003C5180(void *);
extern void func_0038CF68(void *, void *, f32);
extern f32 func_0038CE68(void *, void *);
extern f32 func_0038D160(f32, f32);

f32 func_L01_00450F60(u8 *self, void *a1, void *a2) {
    f32 buf[8];
    f32 x, y, one;

    if (D_L01_001D673C == 0) {
        y = func_0038CED8(a1);
        x = ((f32 *)a1)[2];
    } else if (a2 != 0) {
        func_0038D000(buf, a1, a2);
        y = func_0038CED8(buf);
        x = buf[2];
    } else {
        one = 1.0f;
        ((void (*)(void *, void *, s32))func_003C5180)(self + 0x10, buf + 4, 1);
        func_0038CF68(buf, a1, one);
        x = func_0038CE68(buf, buf + 4);
        one = one - x;
        y = sqrt_asm(one);
    }
    return func_0038D160(x, y);
}

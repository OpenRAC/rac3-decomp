/* func_L39_00632328: near miss (p2w3 w2), 3 diff rows at level 39, no @ps2as
   retail: lbu mode; bltz mode skip; slti mode,3 (unfolded signed range test on an unsigned byte)
   mine with char/s8 mode: lb + andi/sltiu fold; u8: 20 diff (sltiu fold, branch layout) */
extern void func_0038D028(Vec4 *, Vec4 *, u8 *);
void func_L39_00632328(u8 *a, u8 *dst, u8 *src, f32 s) {
    char m = a[0x1A06];
    if (m == 0) {
        *(u128_t *)dst = *(u128_t *)src;
        *(f32 *)(dst + 8) *= s;
    } else if (m >= 0 && m < 3) {
        func_0038D028((Vec4 *)dst, (Vec4 *)src, a + 0x60);
        *(f32 *)(dst + 8) *= s;
        func_0038D028((Vec4 *)dst, (Vec4 *)dst, a + 0x20);
    }
}

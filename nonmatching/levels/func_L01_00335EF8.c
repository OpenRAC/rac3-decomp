/* Near miss for func_L01_00335EF8 (no readable name yet), file
   src/levels/shared/L01_003326A8.c: tools/check.py nonmatching/levels/func_L01_00335EF8.c
   func_L01_00335EF8. One instruction short (5 words differ): retail computes the
   comparison into $v0 (sltiu $v0, $v0, 1) and copies it to $a2 before the return
   (move $a2, $v0; jr; move $v0, $a2); here the sltiu writes $a2 directly. Tried with the
   same bytes: r as s32, u8, s16 and long, `!x`, `x ? 0 : 1`, `x < 1`, `(u32)x < 1`, an
   inline helper, the vars pointer in a local and a struct, a temporary for the compare. */
s32 func_L01_00335EF8(u8 *moby)
{
    s32 r = 0;

    if (*(s32 *)(*(u8 **)(moby + 0x68) + 0x70) != -1) {
        r = moby[0x95] == 0;
    }
    return r;
}

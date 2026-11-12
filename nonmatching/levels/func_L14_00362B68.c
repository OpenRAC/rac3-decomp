/* func_L14_00362B68: near miss, 14 diff: needs @ps2as on L14_003622D0.c (inline 1.0f) and the divs_nops row "func_L14_00362B68 2"; left: loop registers/order, retail keeps the counter in $v0, the D_001E1220 pointer in $v1 and the D_001E1224 pointer in $a0 (address of 1224 computed first), ours counter $a0, 1224 pointer $v0; index, pointer, do-while and struct wordings tried
   Level 14 (Koros) only; flags of its file in config/levels/text_parts.txt. */
__asm__(".extern D_L14_001DD988, 4");
extern f32 D_L14_001DD988;
extern f32 D_L14_001E1220[];
extern f32 D_L14_001E1224[];
void func_L14_00362B68(f32 t, s32 a0, s32 a1, f32 *p, f32 *q) {
    f32 base;
    s32 i;
    f32 *o1;
    f32 *o2;
    base = *p + t * (1.0f / D_L14_001DD988);
    i = 3;
    o1 = D_L14_001E1220;
    o2 = D_L14_001E1224;
    do {
        *o1 = base + (*p - base) * q[0];
        *o2 = q[1];
        o1 += 2;
        o2 += 2;
        q += 2;
    } while (--i >= 0);
    *p = base - (f32)(s32)base;
}

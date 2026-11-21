/* functional: high. EXACT at default flags; byte-identical to retail. */
extern void func_0038D000(void *, void *, void *);
extern s32 func_L01_003FB640(void *, s32, u8 *, f32);
extern u8 D_L01_001EAA00[];

s32 func_L01_0045DF48(u8 *a, u8 *o) {
    f32 v0[4];
    f32 v1[4];
    f32 v2[4];
    u8 *d;

    *(vu0_q *)v2 = 0;
    v2[2] = *(f32 *)(o + 4) + *(f32 *)o;
    *(vu0_q *)v1 = *(vu0_q *)v2;
    func_0038D000(v1, v1, a + 0xC0);
    vec_add_ba(v0, a + 0x10, v1);
    if (func_L01_003FB640(v0, *(s32 *)(o + 0x38) & 2, a, *(f32 *)o) != 0) {
        d = D_L01_001EAA00;
        *(s32 *)(o + 0x84) = *(s32 *)(d + 0x18);
        *(vu0_q *)(o + 0x60) = *(vu0_q *)(d + 0x20);
        *(vu0_q *)v0 = *(vu0_q *)(d + 0x30);
        vec_sub_ab(a + 0x10, v0, v1);
        return 1;
    }
    return 0;
}

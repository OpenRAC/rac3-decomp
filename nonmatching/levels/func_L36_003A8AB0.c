/* func_L36_003A8AB0: near miss, level 36 (Vidcomic 1 Special Edition). about 94 differences (file builds with -mvu0-use-vf0-vf2 @ps2as): the logic is complete, but retail's prologue loads a1[0] and a1[1] before testing, hoists s = o->0x68 into the beqz delay slot and keeps o/s/a0/a1 in $s0/$s1/$s2/$s3 (ours rotates them); two restructurings of the early exits tried (worse) */
extern f32 func_003824E0(f32, f32);
extern f32 func_0038DB48(f32);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern s32 func_00382498(s32, s32);
extern f32 func_003C4088(f32, f32, f32);
void func_L36_003A8AB0(u8 *a0, u8 *a1) {
    u8 *o;
    u8 *s;
    f32 ang;
    f32 rad;
    vu0_v4 v;
    s32 r1;
    s32 r2;
    s32 r3;
    if (a1 == 0) {
        return;
    }
    o = *(u8 **)a1;
    if (o == 0 || *(s32 *)(a1 + 4) == 0) {
        return;
    }
    s = *(u8 **)(o + 0x68);
    if (*(u16 *)(a1 + 0xA) & 1) {
        ang = func_0038DB48(func_003824E0(0.0f, 6.2831855f));
        rad = func_003824E0(0.0f, 1.5f);
        *(u128_t *)(a0 + 0x10) = *(u128_t *)(o + 0x10);
        *(f32 *)(a0 + 0x18) = *(f32 *)(a0 + 0x18) + 2.0f;
        v.x = func_0038D098(ang) * rad;
        v.y = 0.0f;
        v.z = func_0038D0B0(ang) * rad;
        vec_add_ab(a0 + 0x10, a0 + 0x10, &v);
    }
    *(f32 *)(a0 + 0x18) = *(f32 *)(a0 + 0x18) + 0.015f;
    if (*(u16 *)(a1 + 0xA) & 1) {
        if (*(s32 *)(s + 0x58) != 0) {
            r1 = func_00382498(0, 0x40);
            r2 = func_00382498(0, 0x40);
            r3 = func_00382498(0x40, 0x80);
        } else {
            r1 = func_00382498(0, 0x40);
            r2 = func_00382498(0x60, 0x80);
            r3 = func_00382498(0, 0x40);
        }
        *(s32 *)(a0 + 4) = ((s32)((f32)*(s16 *)(a0 + 0xA) * 128.0f / (f32)*(s16 *)(a1 + 8)) << 24) | (r1 << 16) | (r2 << 8) | r3;
    }
    *(u8 *)(a0 + 8) = (s32)(f32)*(u8 *)(a1 + 0xE);
    *(f32 *)(a0 + 0xC) = func_003C4088(315000.0f, 42000.0f, (f32)*(s16 *)(a0 + 0xA) / (f32)*(s16 *)(a1 + 8));
}

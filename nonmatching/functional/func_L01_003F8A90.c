/* functional: high. Plain C for retail's vadd/vsub.xyz: the xyz sums are the same, and each w lane is the one retail's destination register held (L0.w after the first add; D.w, through the vsub's vf1, in the final store to self+0x10). The earlier vec_add_ba draft let gcc give the last vadd L2's register as destination, so self+0x10's w became the old w instead of D.w. The temporaries retail spills below its frame (sp+0x10..0x3F) are dead. */
extern vu0_v4 D_L01_001EAA30;
extern s32 func_L01_003FB640(void *, s32, s32, f32);

s32 func_L01_003F8A90(u8 *self) {
    vu0_v4 L0;
    vu0_v4 *pos = (vu0_v4 *)(self + 0x10);
    u8 *m = *(u8 **)(self + 0x68);
    f32 x, y, z, w;

    func_0038D000(&L0, m + 0x20, self + 0xC0);
    /* vadd.xyz vf1(L0), vf1, vf2(pos): w stays L0.w */
    L0.x = L0.x + pos->x;
    L0.y = L0.y + pos->y;
    L0.z = L0.z + pos->z;
    if (func_L01_003FB640(&L0, 2, *(s32 *)(m + 0x54), *(f32 *)(m + 0x2C)) == 0) {
        return 0;
    }
    /* vsub.xyz vf1(D), vf1, vf2(L0): t = D - L0, w = D.w;
       vadd.xyz vf1(t), vf2(pos), vf1: pos = pos + t, w = t.w = D.w */
    x = D_L01_001EAA30.x - L0.x;
    y = D_L01_001EAA30.y - L0.y;
    z = D_L01_001EAA30.z - L0.z;
    w = D_L01_001EAA30.w;
    pos->x = pos->x + x;
    pos->y = pos->y + y;
    pos->z = pos->z + z;
    pos->w = w;
    return 1;
}

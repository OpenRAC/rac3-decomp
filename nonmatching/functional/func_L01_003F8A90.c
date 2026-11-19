/* functional: high. 19 instruction positions differ at L01 (scheduling of two argument loads and the order of the lqc2/bbit hazard fillers; the last vadd picks different vf registers); same calls, vector ops and return values. Needs vu0.h (already in this file's prelude). */
extern vu0_v4 D_L01_001EAA30;
extern s32 func_L01_003FB640(void *, s32, s32, f32);

s32 func_L01_003F8A90(u8 *self) {
    vu0_v4 L[4];
    u8 *m = *(u8 **)(self + 0x68);

    func_0038D000(&L[0], m + 0x20, self + 0xC0);
    vec_add_ab(&L[0], &L[0], self + 0x10);
    if (func_L01_003FB640(&L[0], 2, *(s32 *)(m + 0x54), *(f32 *)(m + 0x2C)) == 0) {
        return 0;
    }
    vec_copy(&L[3], &L[0]);
    vec_copy(&L[2], self + 0x10);
    vec_sub_ab(&L[1], &D_L01_001EAA30, &L[3]);
    vec_add_ba(self + 0x10, &L[2], &L[1]);
    return 1;
}

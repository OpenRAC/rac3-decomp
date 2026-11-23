/* functional: medium. Rewritten from PAL asm (the NTSC draft has other callees); unknown first callee at 0x477888 kept by that name with the retail argument list. */
extern void func_L01_00477888(s32, f32 *, f32 *, void *, f32, f32, vu0_q);
extern s32 func_003D4D00(void *, s32, void *, s32, f32);
extern void func_L01_00447718(void *, void *, void *, s32, s32, s32, s32, s32, f32, f32, f32, s32);
extern u8 D_L01_001EEA80[];
void func_L01_0046B898(u8 *p) {
    f32 loc30, loc34;
    vu0_q tmp;
    f32 h;
    s32 hit;
    *(f32 *)(p + 0x24) += *(f32 *)(p + 0x28);
    func_L01_00477888(*(s32 *)(p + 0x20), &loc30, &loc34, p + 0x10, *(f32 *)(p + 0x24), *(f32 *)(p + 0x2C), *(vu0_q *)(p + 0x10));
    if (func_0038CB00((s16 *)(p + 0xA))) {
        func_003CD250((Obj *)p);
        return;
    }
    h = (f32)*(s16 *)(p + 0xA);
    if (h < 6.25f) {
        *(s32 *)(p + 4) = func_L01_00448CC0(0.7f, 0.7f, 0.7f, h * 0.08f / 6.25f);
    }
    hit = func_003D4D00(p + 0x10, 0x10, *(void **)(p + 0x34), 0, 0.15f);
    tmp = *(vu0_q *)(p + 0x10);
    func_L01_00447718(*(void **)(p + 0x34), &tmp, D_L01_001EEA80, hit, 0, 0x01010001, 2, 1, 2.0f, 1.0f, 1.0f, -1);
}

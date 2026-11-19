/* functional: medium. Hit pointer passed to func_003D5630 explicitly (retail leaves it in a0; other callers declare it void). Not byte exact. Includes retail's quirk: after the 'too far above ground' reject path it still copies D_001EAA40 into b+0x50. */
extern s32 func_003D3CB0(void *, void *, s32, void *, s32);
extern s32 func_003D5630(void *);
extern u8 *func_L01_00448FF0(u8 *);
extern void func_0038CF68(void *, void *, f32);
extern u8 D_L01_001EAA00[];
void func_L01_0045B6C8(u8 *self, u8 *b, f32 x) {
    f32 p0[4] __attribute__((aligned(16)));
    f32 p1[4] __attribute__((aligned(16)));
    f32 *sp = (f32 *)(self + 16);
    u8 *p;
    s32 k;
    s32 c;
    p0[0] = sp[0];
    p0[1] = sp[1];
    p0[2] = sp[2];
    p0[3] = sp[3];
    p1[0] = p0[0];
    p1[1] = p0[1];
    p1[2] = p0[2];
    p1[3] = p0[3];
    p0[2] = p0[2] + (*(f32 *)(b + 8) + 0.1f);
    if (x == 0.0f) {
        p1[2] = p1[2] - (*(f32 *)(b + 12) + 0.1f);
    } else {
        p1[2] = p1[2] - x;
    }
    if (func_003D3CB0(p0, p1, 2, self, 0) == 0) {
        *(s32 *)(b + 144) = 0;
        *(s32 *)(b + 216) = -1;
        ((s32 *)(b + 80))[0] = 0;
        ((s32 *)(b + 80))[1] = 0;
        ((s32 *)(b + 80))[2] = 0;
        ((s32 *)(b + 80))[3] = 0;
        *(s32 *)(b + 136) = 0;
        *(s32 *)(b + 140) = 0;
        return;
    }
    *(f32 *)(b + 144) = *(f32 *)(D_L01_001EAA00 + 40);
    *(s32 *)(b + 136) = *(s32 *)(D_L01_001EAA00 + 24);
    *(s32 *)(b + 140) = *(s32 *)(D_L01_001EAA00 + 28);
    k = func_003D5630(D_L01_001EAA00);
    *(s32 *)(b + 216) = k;
    if (k != -1) {
        p = func_L01_00448FF0(self);
        if (p != 0 && *(u8 *)(p + 73) != 0 && *(u16 *)(p + 74) != 0 &&
            ((*(u16 *)(p + 74) >> *(s32 *)(b + 216)) & 1)) {
            if (*(f32 *)(self + 24) - *(f32 *)(b + 144) > 0.3f) {
                *(s32 *)(b + 216) = -1;
                *(s32 *)(b + 144) = 0;
                *(s32 *)(b + 136) = 0;
                *(s32 *)(b + 140) = 0;
            }
        } else {
            c = *(s32 *)(b + 216);
            if (c == 0 || c == 3) {
                if (func_003D3CB0(p0, p1, 34, self, 0) != 0) {
                    *(f32 *)(b + 144) = *(f32 *)(D_L01_001EAA00 + 40);
                    *(s32 *)(b + 136) = *(s32 *)(D_L01_001EAA00 + 24);
                    *(s32 *)(b + 140) = *(s32 *)(D_L01_001EAA00 + 28);
                    *(s32 *)(b + 216) = func_003D5630(D_L01_001EAA00);
                } else {
                    *(s32 *)(b + 144) = 0;
                    *(s32 *)(b + 216) = -1;
                    ((s32 *)(b + 80))[0] = 0;
                    ((s32 *)(b + 80))[1] = 0;
                    ((s32 *)(b + 80))[2] = 0;
                    ((s32 *)(b + 80))[3] = 0;
                    *(s32 *)(b + 136) = 0;
                    *(s32 *)(b + 140) = 0;
                }
            }
        }
    }
    func_0038CF68(b + 80, D_L01_001EAA00 + 64, 1.0f);
}

/* functional: high. VU0 vadd/vsub.xyz as scalar math; a3 declared void* (caller passes stack matrix). Not byte exact. Callers' extern in 0045CF00 snippet matches (u8*,u8*,void*,void*). */
extern s32 func_L01_0045CCD8(u8 *, u8 *);
extern s32 func_0038CAD0(void *);
extern void func_L01_00451048(void *, void *, void *, void *);
extern void func_L01_00450E48(u8 *, f32 *, f32, f32, f32);
extern f32 D_L01_001E0240[];
void func_L01_0045C7A8(u8 *self, u8 *s, void *unused, void *a3) {
    f32 old[4] __attribute__((aligned(16)));
    f32 *pos = (f32 *)(self + 16);
    f32 *mv = (f32 *)(s + 160);
    f32 d, len;
    s32 i;
    s32 acc = 0;
    pos[0] = pos[0] + mv[0];
    pos[1] = pos[1] + mv[1];
    pos[2] = pos[2] + mv[2];
    old[0] = pos[0];
    old[1] = pos[1];
    old[2] = pos[2];
    old[3] = pos[3];
    *(s32 *)(s + 132) = 0;
    ((s32 *)(s + 96))[0] = 0;
    ((s32 *)(s + 96))[1] = 0;
    ((s32 *)(s + 96))[2] = 0;
    ((s32 *)(s + 96))[3] = 0;
    for (i = 0; i < 8; i++) {
        s32 r = func_L01_0045CCD8(self, s);
        acc |= r;
        if (r == 0) {
            break;
        }
    }
    if (acc == 0) {
        func_0038CAD0(s + 128);
    } else {
        mv[0] = pos[0] - D_L01_001E0240[0];
        mv[1] = pos[1] - D_L01_001E0240[1];
        mv[2] = pos[2] - D_L01_001E0240[2];
        mv[3] = pos[3];
        d = func_L01_004510F8(self, mv, (s32)a3);
        if (*(f32 *)(s + 176) < d) {
            func_L01_00451048(self, mv, mv, a3);
        } else {
            *(f32 *)(s + 176) = d;
        }
        len = func_L01_00451580(pos);
        if (len <= *(f32 *)(s + 144)) {
            func_L01_00450E48(self, pos, 0.0f, 0.0f, *(f32 *)(s + 144) - len);
            func_L01_004510A8(self, mv, mv, 0.0f, (s32)a3);
        }
        if (*(f32 *)(s + 176) < *(f32 *)(s + 40) * 0.5f) {
            *(s32 *)(s + 128) = *(s32 *)(s + 128) + 1;
        } else {
            func_0038CAD0(s + 128);
        }
    }
    mv = (f32 *)(s + 112);
    mv[0] = pos[0] - old[0];
    mv[1] = pos[1] - old[1];
    mv[2] = pos[2] - old[2];
    mv[3] = pos[3];
}

/* functional: high. Same calls, args and data as retail; scheduling differences only. Floats are level 01 sda slots (D_L01_..._sda) so other levels move them. */
extern void func_L01_003E8F90(s32, s32);
extern void func_L01_003E8BD0(s32, s32, f32, f32);
extern void func_L01_003E8C28(s32, f32, f32);
extern void func_L01_003E8C70(s32, s32, f32, f32);
extern void func_L01_003E8E70(s32);
extern void func_L01_003E9250(s32, void *, f32, f32);
extern f32 func_0038DAB8(f32, f32);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern f32 D_L01_001DF270_sda;
extern f32 D_L01_001DF274_sda;
extern f32 D_L01_001DF278_sda;
extern f32 D_L01_001DF27C_sda;
extern f32 D_L01_001DF280_sda;
extern f32 D_L01_001DF284_sda;
__asm__(".extern D_L01_001DF270_sda, 4");
__asm__(".extern D_L01_001DF274_sda, 4");
__asm__(".extern D_L01_001DF278_sda, 4");
__asm__(".extern D_L01_001DF27C_sda, 4");
__asm__(".extern D_L01_001DF280_sda, 4");
__asm__(".extern D_L01_001DF284_sda, 4");

void func_L01_003D0BD0(u8 *self, u8 *obj) {
    f32 vec[3];
    f32 ang;
    f32 f13;
    u8 st;

    func_L01_003D22A8((s32)self);
    if (func_L01_00513EF0() != 0) {
        return;
    }
    if (*(s16 *)(D_L01_001E2A90[0] + 134) != 0) {
        return;
    }
    if (obj[0xB1] == 0) {
        func_L01_003D0B70((s32)self, obj);
    }
    func_L01_003E8F90(0, -1);
    func_L01_003E8BD0(0, 0, D_L01_001DF270_sda, 0.003f);
    func_L01_003E8C28(0, D_L01_001DF274_sda, 0.003f);
    func_L01_003E8C70(0, 0, D_L01_001DF278_sda, 0.005f);
    func_L01_003E8E70(0);
    st = self[0x20];
    if (st == 3) {
        f13 = D_L01_001DF27C_sda;
    } else if ((u8)(st - 6) < 3) {
        func_L01_003E8BD0(0, 0, D_L01_001DF280_sda, 0.003f);
        f13 = D_L01_001DF284_sda;
    } else {
        func_L01_003E9250(0, self + 0xC0, 0.15707964f, 0.0f);
        return;
    }
    ang = func_0038DAB8(*(f32 *)(self + 0xF8), f13);
    vec[0] = func_0038D098(ang);
    vec[1] = func_0038D0B0(ang);
    vec[2] = 0.0f;
    func_L01_003E9250(0, vec, 0.2617994f, vec[2]);
}

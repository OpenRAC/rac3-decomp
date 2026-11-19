/* functional: high. Same as retail except the two nops retail puts before div.s (add 'func_L01_003F8208 2' to config/levels/divs_nops.txt); the remaining 55 differing positions are that two-word shift. Constants are retail's exact floats (0.0400000028f, 0.00280000013f). */
typedef struct { vu0_v4 a; vu0_v4 b; vu0_v4 c; vu0_v4 d; f32 e; } L_3F8208;
extern u8 D_L01_001EAA40[];
extern void func_L01_003F8550(u8 *);
extern s32 func_L01_003F8A90(u8 *);
extern void func_0038CF68(void *, void *, f32);
extern void func_0038CE90(void *, void *, void *);
extern void func_L01_003F8E78(u8 *, void *, void *);
extern void func_003C5180(void *, void *, s32);
extern f32 func_0038CE68(void *, void *);
extern f32 func_0038CEA8(void *);
extern void func_003C4138(f32 *, f32, f32);
extern void func_003C4CE8(void *, void *, f32);
extern void func_0038D6C8(void *, void *, void *, f32);
extern s32 func_003A52A0(s32 a, s32 b, u8 *c);
extern s32 func_003A5348(s32, s32, u8 *);
extern void func_L01_004AAFD0(s32, void *);
extern void func_L01_0040E790(void *, void *, void *);

s32 func_L01_003F8208(u8 *self) {
    L_3F8208 L;
    u8 *m = *(u8 **)(self + 0x68);
    u8 *dir;
    u8 *pos;
    f32 f20;
    f32 f21;
    f32 f22;
    s32 h;

    func_L01_003F8550(self);
    if (func_L01_003F8A90(self) == 0) {
        return 0;
    }
    dir = D_L01_001EAA40;
    pos = m + 0x10;
    func_0038CF68(dir, dir, 1.0f);
    func_0038CE90(&L.a, dir, m);
    func_L01_003F8E78(self, pos, &L.a);
    func_003C5180(self + 0x10, &L.b, 1);
    if (func_0038CE68(&L.b, dir) > 0.7f) {
        f21 = func_0038CE68(m, dir);
        f22 = 0.0400000028f;
        f20 = f21 * 0.5f;
        if (fabs_asm(f20) < f22) {
            f20 = 0.0f;
        }
        func_0038CF68(&L.c, dir, f21 + f20);
        vec_sub_ab(m, m, &L.c);
        if (f20 == 0.0f) {
            L.e = func_0038CEA8(m);
            func_003C4138(&L.e, f22, 0.00280000013f);
            func_0038CF68(m, m, L.e);
            func_0038CE90(&L.d, m, dir);
            func_003C4CE8(&L.d, &L.d, func_0038CEA8(&L.d) * -0.5f / *(f32 *)(m + 0x2C));
            func_0038D6C8(pos, pos, &L.d, 0.1f);
        }
        if (fabs_asm(f21) >= f22) {
            if (m[0x5E] != 0xFF) {
                h = func_003A52A0(m[0x5E], 0, self);
            } else {
                h = func_003A5348(8, 0, self);
            }
            if (h != -1) {
                func_L01_004AAFD0(h, m + 0x20);
            }
        }
    } else {
        func_L01_0040E790(m, m, dir);
    }
    return 0;
}

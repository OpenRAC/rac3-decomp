/* functional: high. Byte-identical at L04 (checked). func_0038DB00 is called in retail with only its first argument; f13 still holds 1.5707964 from the preceding angle call (func_0038DAB8/D0B0 never touch f13), so C passes 1.5707964f explicitly. D_001D5469 and D_L04_001DF75C declared as scalars (not arrays) to get the lui/sw  form. */
/* localdecomp:start func_L04_003F5B78 */
typedef int s128_003F5B78 __attribute__((mode(TI)));
extern u8 D_001A4BE0[];
extern u8 D_001CCFD0[];
extern u8 D_001D5469;
extern s32 D_L04_001DF75C;
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern f32 func_0038DAB8(f32, f32);
extern f32 func_0038DB00(f32, f32);
extern void func_0038A238(s32);
extern s32 func_L01_004ED658(s32);
extern void func_L01_004F50C8(void *, void *, s32, s32);
extern void func_L01_003EB438(s32, void *, void *, s32, s32, s32);
extern void func_L01_003EB350(s32, void *);
extern void func_L01_003EB3C0(s32, void *);
extern void func_003C3A10(void *, s32, s32, s32);
extern void func_L01_0050FB40(s32, s32, f32);
extern void func_003A2B68(s32, s32);
extern void func_L01_004450F0(void *, s32, s32);

void func_L04_003F5B78(u8 *self) {
    vu0_v4 a;
    vu0_v4 r;
    vu0_v4 b;
    vu0_v4 r2;
    u8 *m;
    u8 *g;
    u8 *d;
    *(f32 *)(self + 0x2C) = *(f32 *)(*(u8 **)(self + 0x24) + 0x24);
    m = *(u8 **)(self + 0x68);
    a.x = func_0038D098(*(f32 *)(m + 0x10)) * 2.5f;
    a.y = func_0038D0B0(*(f32 *)(m + 0x10)) * 2.5f;
    a.z = 0.0f;
    vec_add_ab(&a, &a, m);
    qzero(&r);
    r.z = func_0038DAB8(*(f32 *)(m + 0x10), 3.1415927f);
    func_0038A238(8);
    g = D_001A4BE0;
    if (g[0x25E4] == 3) {
        func_L01_004ED658(0);
    }
    func_L01_004F50C8(&a, &r, 0x74, 0);
    b.x = func_0038D098(*(f32 *)(m + 0x10)) * 1.25f;
    b.y = func_0038D0B0(*(f32 *)(m + 0x10)) * 1.25f;
    b.z = 0.0f;
    b.x += func_0038D098(func_0038DAB8(*(f32 *)(m + 0x10), 1.5707964f)) * 4.0f;
    b.y += func_0038D0B0(func_0038DAB8(*(f32 *)(m + 0x10), 1.5707964f)) * 4.0f;
    vec_add_ab(&b, &b, m);
    qzero(&r2);
    b.z += 1.0f;
    r2.z = func_0038DB00(*(f32 *)(m + 0x10), 1.5707964f);
    func_L01_003EB438(0, &b, &r2, 1, 0, 0);
    func_L01_003EB350(0, &b);
    func_L01_003EB3C0(0, &r2);
    *(s128_003F5B78 *)(self + 0x10) = *(s128_003F5B78 *)(g + 0x80);
    *(s128_003F5B78 *)(self + 0xF0) = *(s128_003F5B78 *)(g + 0x90);
    if (self[0x43] != 1) {
        func_003C3A10(self, 1, 0, 0);
    }
    func_L01_0050FB40(0x66, 0, 0.0f);
    if (D_001D5469 != 0) {
        *(u16 *)(self + 0x34) |= 0x8000;
    }
    g[0x25F0] = 1;
    D_L04_001DF75C = 1;
    *(s16 *)(m + 0x1C) = 0x32;
    d = D_001CCFD0;
    if (*(s32 *)(d + 0x6C) == 0 && *(s32 *)(d + 0x24) == -1 && *(s32 *)(d + 0x94) == 0) {
        func_003A2B68(0xEB8, 0);
    }
    func_L01_004450F0(self, 3, -1);
}
/* localdecomp:end func_L04_003F5B78 */

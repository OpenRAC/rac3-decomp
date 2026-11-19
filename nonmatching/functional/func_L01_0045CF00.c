/* functional: high. Same frame-stamp pattern as func_L01_0045A898. Retail's func_L01_0045C1D0 call takes no args. Stack temps: m (0x40 matrix at sp+0, also passed as t2/a3), t3/t4 at sp+0x80/0x90. Not byte exact. */
extern void func_003C5180(void *, void *, s32);
extern u8 *func_L01_0045B958(u8 *);
extern void func_L01_0045C1D0(void);
extern void func_0038D5B0(void *, void *);
extern void func_L01_004515D8(void *, void *, void *);
extern void func_0038D000(void *, void *, void *);
extern void func_L01_0045B908(u8 *, u8 *);
extern void func_L01_0045B8D8(u8 *, u8 *);
extern void func_L01_0045C510(u8 *, u8 *, void *, s32, void *, void *, void *);
extern void func_L01_0045C7A8(u8 *, u8 *, void *, void *);
extern s32 D_L01_001DFB40;
s32 func_L01_0045CF00(u8 *self, u8 *b, u8 *c) {
    f32 m[16] __attribute__((aligned(16)));
    f32 t0[4] __attribute__((aligned(16)));
    f32 t1[4] __attribute__((aligned(16)));
    f32 t2[4] __attribute__((aligned(16)));
    f32 t3[4] __attribute__((aligned(16)));
    f32 t4[4] __attribute__((aligned(16)));
    u8 *s = func_L01_0045B958(self);
    s32 old;
    if (s == 0) {
        return 8;
    }
    if (D_L01_001DFB40 == *(s32 *)(s + 188)) {
        return *(s32 *)(s + 148);
    }
    func_L01_0045C1D0();
    func_0038D5B0(m, self + 192);
    func_003C5180(self + 16, t0, 0);
    func_L01_004515D8(self + 192, t0, t1);
    func_0038D000(s + 160, s + 160, t1);
    old = *(s32 *)(s + 148);
    *(s32 *)(s + 148) = 0;
    *(s32 *)(s + 152) = old;
    func_L01_0045B908(self, s);
    func_L01_0045B8D8(self, s);
    if (D_L01_001DFB40 - *(s32 *)(s + 188) >= 2 || *(s32 *)(s + 188) == 0) {
        func_L01_0045CDA0(self, s);
        *(s32 *)(s + 156) &= ~2;
        *(u8 *)(s + 234) = 255;
        *(s32 *)(s + 128) = 0;
        ((s32 *)(s + 160))[0] = 0;
        ((s32 *)(s + 160))[1] = 0;
        ((s32 *)(s + 160))[2] = 0;
        ((s32 *)(s + 160))[3] = 0;
        *(s32 *)(s + 180) = 0;
    }
    *(s32 *)(s + 188) = D_L01_001DFB40;
    func_L01_0045C510(self, s, b, (s32)c, t3, t4, m);
    func_L01_0045C7A8(self, s, t4, m);
    func_L01_0045C950(self, s, b, (s32)m);
    return *(s32 *)(s + 148);
}

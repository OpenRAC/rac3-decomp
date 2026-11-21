/* functional: medium. Written from PAL asm; compiles at level 02 (358 diff, frame 0x10 larger, regalloc only). Unsure: exact types of func_L01_00446780 args (a0 passthrough = self passed explicitly), RNG call order kept sequential as retail (hoisted into locals). Needs vu0.h/vec_add_ba from the file prelude. */
extern void func_L01_004450F0(void *, s32, s32);
extern void func_L01_00446760(void *, void *, s32, void *, f32);
extern void func_L01_00446780(void *, void *, s32, f32, f32, f32, s32, s32, s32);
extern void func_L01_004CB320(void);
extern void func_L01_004CB358(void);
extern s32 func_003D3CB0(void *, void *, s32, void *, void *);
extern void func_003D4D00(void *, f32, s32, void *, void *);
extern void func_0038CE20(void *, void *, f32);
extern void func_003C2880(void *);
extern void func_003C4C18(void *, f32);
extern f32 func_003824E0(f32, f32);
extern f32 func_00382538(void);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern s32 func_0038DBD8(s32, s32, f32);
extern u8 *func_L01_0046A610(void *, void *, s32, s32, s32, s32, f32, f32, f32, f32, f32);
extern void func_L01_00463378(void *, void *, void *, s32, s32, s32, s32, s32, s32);
extern u8 D_001D66B0;
extern u8 *D_L02_0021E27C[];
extern u8 *D_L02_001E8058 __attribute__((section(".data")));

void func_L02_0039C730(u8 *self) {
    u8 *st = *(u8 **)(self + 0x68);
    s32 hit;
    s32 i, j;
    u8 *g;
    u8 *r;
    vu0_v4 v10, v20, v30, v50;
    u8 v60[0x30] __attribute__((aligned(16)));
    u8 vA0[0x30] __attribute__((aligned(16)));
    f32 a, b, c, d;
    s32 m1, m2, m3;

    *(s32 *)(st + 0x24) += 1;
    if (*(s32 *)(st + 0x24) > 0xF0) {
        func_L01_00446780(self, self + 0x10, 0x10001, 0.6f, *(f32 *)(st + 0x14), 0.0f, 0, 1, 0);
        func_L01_004450F0(self, 1, -1);
    }
    if (self[0x20] == 0) {
        s32 n;
        n = (s32)func_00382538();
        r = func_L01_0046A610(self + 0x10, &D_001D66B0, 5, 0x4F, 0xFF90, n, 472500.0f, -1000.0f, 0.95f, 0.0f, 0.0f);
        if (r != 0) r[2] = *D_L02_0021E27C[0];
        n = (s32)func_00382538();
        r = func_L01_0046A610(self + 0x10, &D_001D66B0, 5, 0x4F, 0x10A182, n, 168000.0f, -1000.0f, 0.95f, 0.0f, 0.0f);
        if (r != 0) r[2] = *D_L02_0021E27C[0];
        vec_add_ba(&v10, self + 0x10, st);
        func_L01_00446760(vA0, self, 1, st, *(f32 *)(st + 0x14));
        *(u16 *)(vA0 + 0x1A) = *(u16 *)(self + 0xAA);
        func_L01_004CB320();
        hit = func_003D3CB0(self + 0x10, &v10, 0, self, vA0);
        if (hit != 0) {
            g = D_L02_001E8058;
            if (g != 0 && *(s16 *)(g + 0xAA) == 0x186D && g[0x20] != 2 && g[0x20] != 5) {
                g[0x20] = 4;
            }
        }
        func_L01_004CB358();
        if (hit != 0) {
            g = D_L02_001E8058;
            if (g == 0 || g != *(u8 **)(st + 0x10)) {
                v50 = *(vu0_v4 *)st;
                func_0038CE20(&v50, &v50, g == 0 ? 3.0f : 1.5f);
                v50.z = 1.0f;
                v50.w = 5627.9248f;
                func_L01_00446760(v60, self, 0x10001, &v50, *(f32 *)(st + 0x14));
                v60[0x19] = 1;
                *(u16 *)(v60 + 0x1A) = *(u16 *)(self + 0xAA);
                v60[0x18] = 0;
                func_003D4D00(self + 0x10, 0.6f, 0, *(u8 **)(st + 0x10), v60);
                func_L01_004450F0(self, 1, -1);
                return;
            }
        }
        *(vu0_v4 *)(self + 0x10) = v10;
        func_0038CE20(&v50, st, -0.5f);
    } else if (self[0x20] == 1) {
        for (i = 0; i < 45; i++) {
            v10 = *(vu0_v4 *)(self + 0x10);
            func_003C4C18(&v10, 0.25f);
            v10.z += 0.25f;
            a = func_00382538();
            b = func_003824E0(1.0f, 8.0f) * 0.02f;
            c = func_003824E0(2.0f, 6.0f);
            d = func_003824E0(0.0f, 0.0f) * 0.02f;
            func_0038CE20(&v20, st, d);
            v20.x += func_0038D098(a) * b;
            v20.y += func_0038D0B0(a) * b;
            v20.z += c * 0.02f;
            v30 = v20;
            v30.z -= 0.2f;
            for (j = 14; j >= 0; j--) {
                f32 s = func_003824E0(0.5f, 1.5f);
                v30.w = s * 0.065f;
                v20.w = s * 0.125f;
                func_003C4C18(&v10, 0.125f);
                func_003C4C18(&v30, 0.01f);
                m1 = func_0038DBD8(0x8000EEEE, 0x8000FF90, func_003824E0(0.0f, 1.0f));
                m2 = func_0038DBD8(0xFFEE, 0xFFEE, func_003824E0(0.0f, 1.0f));
                m3 = (s32)((func_003824E0(5.0f, 25.0f) * 5.0f + 2.0f) / 6.0f);
                func_L01_00463378(&v10, &v20, &v30, m1, m2, 8, 0x19, m3, -1);
            }
        }
        func_003C2880(self);
    }
}

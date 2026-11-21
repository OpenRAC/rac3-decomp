/* functional: high. Read against PAL asm block by block; vector add/sub kept as plain xyz maths with w taken as vadd.xyz/vsub.xyz would; call to func_L01_00332160 passes 5 floats (f12-f16) per retail; byte-level scheduling differs. */
typedef struct { f32 v[4][4]; s32 col[4]; f32 uv[4][2]; long f70, f78, f80, f88; } S_331DD0;
extern s16 D_001CFEC0[];
extern s32 D_001D52F0;
__asm__(".extern D_001D52F0, 16");
extern u8 D_L01_001E2A40[];
extern void func_003A9440(s32, s32);
extern void func_0038AF30(s32, s32, s32, s32, s32);
extern void func_L01_00332160(void *, s32, s32, f32, f32, f32, f32, f32);
extern void func_003C5180(void *, void *, s32);
extern void func_003D93B0(void *, s32, s32, s32);
extern void func_0038CF68(void *, void *, f32);
extern void func_0038CE90(void *, void *, void *);
extern void func_003D2DA0(void *, void *, s32);

void func_L01_00331DD0(u8 *obj) {
    u8 *st = *(u8 **)(obj + 0x68);
    s16 *h = (s16 *)st;
    f32 *fp = (f32 *)st;
    s32 d;
    S_331DD0 Q __attribute__((aligned(16)));
    f32 vA0[4] __attribute__((aligned(16)));
    f32 vB0[4] __attribute__((aligned(16)));
    f32 vC0[4] __attribute__((aligned(16)));
    f32 vD0[4] __attribute__((aligned(16)));
    f32 vE0[4] __attribute__((aligned(16)));
    f32 vF0[4] __attribute__((aligned(16)));
    f32 m90[4] __attribute__((aligned(16)));
    f32 *E;
    f32 *p;
    f32 a;
    s32 col;
    int i;

    if (h[0x1A / 2] != 0 && h[0x12 / 2] - h[0x10 / 2] < 2) {
        if (h[0x14 / 2] != 0) {
            func_003A9440(0x42, 0x48);
            func_0038AF30(0, D_001CFEC0[0xA9], 0, D_001CFEC0[0xA8], 0x80808080);
        }
    }
    if (h[0x18 / 2] != 0) {
        d = h[0x12 / 2] - h[0x10 / 2];
        if (d < 10) {
            a = (f32)d / 10.0f;
            func_L01_00332160(obj + 0x10, 0x3B, 0, fp[0] + (fp[1] - fp[0]) * a, 0.5f, 0.0f, 0.0f, 0.0f);
        } else if ((u16)(h[0x10 / 2] - 0x2E) < 4) {
            a = (f32)(h[0x10 / 2] - 0x2D) / 10.0f;
            func_L01_00332160(obj + 0x10, 0x3B, 0, fp[0] + (fp[1] - fp[0]) * a, 0.5f, 0.0f, 0.0f, 0.0f);
        }
    }
    if (h[0x1E / 2] != 0 && h[0x14 / 2] != 0) {
        p = (f32 *)(obj + 0x10);
        func_003C5180(obj + 0x10, m90, 1);
        a = (f32)h[0x14 / 2] * fp[2];
        func_003D93B0(&Q, 0xB, 4, 0x80);
        col = ((s32)(a * 255.0f) << 24) | 0xFFFFFF;
        E = (f32 *)(D_L01_001E2A40 + D_001D52F0 * 0x460);
        Q.col[0] = col;
        Q.col[1] = col;
        Q.col[2] = col;
        Q.col[3] = col;
        Q.uv[0][0] = 0.0f; Q.uv[0][1] = 0.0f;
        Q.uv[1][0] = 0.0f; Q.uv[1][1] = 1.0f;
        Q.uv[2][0] = 1.0f; Q.uv[2][1] = 0.0f;
        Q.uv[3][0] = 1.0f; Q.uv[3][1] = 1.0f;
        vA0[0] = p[0] - E[0];
        vA0[1] = p[1] - E[1];
        vA0[2] = p[2] - E[2];
        vA0[3] = p[3];
        func_0038CF68(vB0, vA0, 0.1f);
        E = (f32 *)(D_L01_001E2A40 + D_001D52F0 * 0x460);
        vC0[0] = E[0] + vB0[0];
        vC0[1] = E[1] + vB0[1];
        vC0[2] = E[2] + vB0[2];
        vC0[3] = E[3];
        func_0038CE90(vD0, vA0, m90);
        func_0038CF68(vD0, vD0, 0.075f);
        func_0038CE90(vE0, vD0, vA0);
        func_0038CF68(vE0, vE0, 0.075f);
        vF0[0] = vC0[0] + vE0[0];
        vF0[1] = vC0[1] + vE0[1];
        vF0[2] = vC0[2] + vE0[2];
        vF0[3] = vC0[3];
        Q.v[0][0] = vF0[0] + vD0[0];
        Q.v[0][1] = vF0[1] + vD0[1];
        Q.v[0][2] = vF0[2] + vD0[2];
        Q.v[0][3] = vF0[3];
        Q.v[1][0] = vF0[0] - vD0[0];
        Q.v[1][1] = vF0[1] - vD0[1];
        Q.v[1][2] = vF0[2] - vD0[2];
        Q.v[1][3] = vF0[3];
        vF0[0] = vC0[0] - vE0[0];
        vF0[1] = vC0[1] - vE0[1];
        vF0[2] = vC0[2] - vE0[2];
        Q.v[2][0] = vF0[0] + vD0[0];
        Q.v[2][1] = vF0[1] + vD0[1];
        Q.v[2][2] = vF0[2] + vD0[2];
        Q.v[2][3] = vF0[3];
        Q.v[3][0] = vF0[0] - vD0[0];
        Q.v[3][1] = vF0[1] - vD0[1];
        Q.v[3][2] = vF0[2] - vD0[2];
        Q.v[3][3] = vF0[3];
        func_003D2DA0(&Q, 0, 0);
    }
}

/* functional: medium. Written from the PAL assembly (no earlier draft; signature from the callers in the same file). Draws a textured two-layer beam through n points (lightning/laser strip: quad 1 plus a wider, UV-scrolling quad 2 per segment using game quad helper func_003D2DA0); when a segment hits something (func_003D3CB0) and f2 is 0 it spawns spark particles, applies weapon damage (weapon level >= 4) and stops. All 59 retail jal targets and $gp loads match; frame size and scalar-vs-VU0 vector ops differ. The dead lerp at i==n-2 and the doubled texture lookups are kept as in retail. */
typedef int T128_003225F8 __attribute__((mode(TI)));
typedef struct {
    f32 v[4][4];
    u32 col[4];
    f32 uv[4][2];
    unsigned long zero, texture, clamp, prim;
} Quad_003225F8;
typedef struct {
    f32 fwd[4];
    f32 up[4];
    f32 side[4];
    f32 org[4];
} Basis_003225F8;
extern s32 D_L01_001DC950, D_L01_001DC954;
extern f32 D_L01_001DC95C;
extern u8 D_001A4BE0[];
extern u8 D_001425C0[];
extern u8 D_L01_001EAA20[];
extern u8 *D_L01_0022121C[];
extern f32 D_L01_001E29C0[];
__asm__(".extern D_L01_001DC950, 4");
__asm__(".extern D_L01_001DC954, 4");
__asm__(".extern D_L01_001DC95C, 4");
static __inline__ void sub3_003225F8(f32 *d, f32 *a, f32 *b) {
    d[0] = a[0] - b[0];
    d[1] = a[1] - b[1];
    d[2] = a[2] - b[2];
    d[3] = a[3];
}
static __inline__ void basis_003225F8(Basis_003225F8 *m, f32 *from, f32 *to) {
    extern void func_0038CF68(f32 *, s32, f32);
    extern void func_0038CE90(float *, float *, float *);
    sub3_003225F8(m->fwd, to, from);
    func_0038CF68(m->fwd, (s32)m->fwd, 1.0f);
    sub3_003225F8(m->up, D_L01_001E29C0, from);
    func_0038CE90(m->side, m->up, m->fwd);
    func_0038CF68(m->side, (s32)m->side, 1.0f);
    func_0038CE90(m->up, m->fwd, m->side);
}
void func_L01_003225F8(void *pts, s32 n, s32 half, u32 c0, f32 width, f32 scale, u32 c1, s32 z, void *owner, s32 f1, s32 f2) {
    extern unsigned long func_00389598(s32);
    extern void func_L01_00322570(u8 *);
    extern void func_0038CE20(void *, void *, f32);
    extern void func_0038D028(void *, void *, void *);
    extern void func_0038CDF8(void *, void *, void *, f32);
    extern s32 func_003D3CB0(void *, void *, s32, u8 *, s32);
    extern void func_003D9508(void *, s32, u32, s32, f32, f32, f32);
    extern void func_003D2DA0(void *, s32, s32);
    extern f32 func_003824E0(f32, f32);
    extern f32 func_00382538(void);
    extern f32 func_0038D160(f32, f32);
    extern f32 func_0038DAB8(f32, f32);
    extern void func_00382760(f32 *, f32, f32, f32);
    extern f32 func_L01_00443A18(f32, f32);
    extern u8 *func_L01_004669B0(f32, f32, f32, f32, u8 *, s32, f32 *, u32, s32);
    extern u8 *func_L01_0046A610(f32 *, u8 *, s32, s32, s32, s32, f32, f32, f32, f32, f32);
    extern s32 func_L01_00446780(u8 *, f32 *, s32, s32, s32, s32, f32, f32, f32);
    Basis_003225F8 m;
    Quad_003225F8 q1, q2;
    f32 w1[4], w2[4];                   /* corner offsets in the segment basis */
    f32 toCam[4], vel[4], at[4], mid[4];
    f32 (*p)[4] = (f32 (*)[4])pts;
    s32 i, k, life;
    f32 u0, u1, ang, size, elev, head, spd, dmg;
    u8 *weapon;
    u8 *pr;
    q1.col[0] = q1.col[1] = q1.col[2] = q1.col[3] = c0;
    q1.texture = func_00389598(D_L01_001DC950);
    q1.zero = 0;
    q1.clamp = 0xFF9000000260;
    q1.prim = ((unsigned long)half << 32) | 0x68;
    func_L01_00322570((u8 *)&q1);
    q1.uv[0][0] = 0; q1.uv[0][1] = 0;
    q1.uv[1][0] = 0; q1.uv[1][1] = 1.0f;
    q1.uv[2][0] = 1.0f; q1.uv[2][1] = 0;
    q1.uv[3][0] = 1.0f; q1.uv[3][1] = 1.0f;
    q2.col[0] = q2.col[1] = q2.col[2] = q2.col[3] = c1;
    q2.texture = func_00389598(D_L01_001DC950);
    q2.zero = 0;
    q2.clamp = 0xFF9000000260;
    q2.prim = ((unsigned long)(half / 3) << 32) | 0x68;
    func_L01_00322570((u8 *)&q2);
    q2.uv[0][0] = 0; q2.uv[0][1] = 0;
    q2.uv[1][0] = 0; q2.uv[1][1] = 1.0f;
    q2.uv[2][0] = 0.33f; q2.uv[2][1] = 0;
    q2.uv[3][0] = 0.33f; q2.uv[3][1] = 1.0f;
    w1[0] = 0; w1[1] = 0; w1[2] = width; w1[3] = 1.0f;
    w2[0] = 0; w2[1] = 0; w2[2] = width * scale; w2[3] = 1.0f;
    basis_003225F8(&m, p[0], p[1]);
    *(T128_003225F8 *)m.org = *(T128_003225F8 *)p[0];
    *(T128_003225F8 *)q1.v[0] = *(T128_003225F8 *)w1;
    func_0038CE20(q1.v[1], q1.v[0], -1.0f);
    func_0038D028(q1.v[0], q1.v[0], &m);
    func_0038D028(q1.v[1], q1.v[1], &m);
    *(T128_003225F8 *)q2.v[0] = *(T128_003225F8 *)w2;
    func_0038CE20(q2.v[1], q2.v[0], -1.0f);
    func_0038D028(q2.v[0], q2.v[0], &m);
    func_0038D028(q2.v[1], q2.v[1], &m);
    for (i = 1; i < n; i++) {
        w1[2] *= D_L01_001DC95C;
        *(T128_003225F8 *)q1.v[2] = *(T128_003225F8 *)w1;
        func_0038CE20(q1.v[3], q1.v[2], -1.0f);
        w2[2] *= D_L01_001DC95C;
        *(T128_003225F8 *)q2.v[2] = *(T128_003225F8 *)w2;
        func_0038CE20(q2.v[3], q2.v[2], -1.0f);
        basis_003225F8(&m, p[i], p[i + 1]);
        m.org[0] = p[i][0]; m.org[1] = p[i][1]; m.org[2] = p[i][2]; m.org[3] = p[i][3];
        func_0038D028(q1.v[2], q1.v[2], &m);
        func_0038D028(q1.v[3], q1.v[3], &m);
        func_0038D028(q2.v[2], q2.v[2], &m);
        func_0038D028(q2.v[3], q2.v[3], &m);
        if (i == n - 2) func_0038CDF8(mid, q1.v[2], q1.v[3], 0.5f);
        if (f2 == 0 && func_003D3CB0(p[i - 1], p[i], 2, *(u8 **)(D_001A4BE0 + 0x25C0), 0)) {
            u32 ca, cb, cc;
            weapon = (u8 *)D_L01_002C5600 + D_001425C0[0x47] * 0xF0;
            if (f1 != 0) {
                if (weapon[1] < 4) {
                    ca = 0x3FFF1010; cb = 0x5F505050; cc = 0x20FF1010;
                } else {
                    ca = 0x3F202020; cb = 0x5F50507F; cc = 0x20404040;
                }
                func_003D9508(D_L01_001EAA20, 0x39, ca, 1, func_003824E0(0.125f, 0.25f) * 1.5f, 0.2f, func_00382538());
                func_003D9508(D_L01_001EAA20, 0x39, cb, 1, func_003824E0(0.0625f, 0.125f) * 1.5f, 0.2f, func_00382538());
                func_003D9508(D_L01_001EAA20, 0x0B, cc, 1, func_003824E0(0.15f, 0.35f) * 1.5f, 0.2f, 0.0f);
                weapon = (u8 *)D_L01_002C5600 + D_001425C0[0x47] * 0xF0;
                if (weapon[1] >= 4)
                    func_L01_00446780((u8 *)owner, (f32 *)D_L01_001EAA20, 0x08000000, 0, 1, 0, 1.0f, *(f32 *)(weapon + 0x6C), 0.0f);
                return;
            }
            if (weapon[1] >= 4)
                func_L01_00446780((u8 *)owner, p[i - 1], 0x410000, 0, 1, 0, 2.0f, *(f32 *)(weapon + 0x6C), 0.0f);
            sub3_003225F8(toCam, D_L01_001E29C0, p[i]);
            ang = func_0038D160(toCam[0], toCam[1]);
            func_0038CE20(vel, D_001A4BE0 + 0x2E0, -(func_003824E0(0.2f, 3.0f) * 0.020000001f));
            life = (s32)func_L01_00443A18(1.0f, 2.0f);
            size = func_003824E0(0.3f, 0.75f) * 210000.0f;
            at[0] = p[i - 1][0] + func_L01_00443A18(0.0f, 0.2f);
            at[1] = p[i - 1][1] + func_L01_00443A18(0.0f, 0.2f);
            at[2] = p[i - 1][2] + func_L01_00443A18(0.0f, 0.2f);
            pr = func_L01_004669B0(0.0f, 1.0f, 1.01f, size, (u8 *)at, life, vel, 0x7F202020, 0);
            if (pr) {
                *(s16 *)(pr + 0xA) = 75;
                pr[3] = 0x44;
                pr[9] = 0x44;
                *(s32 *)(pr + 0x24) = 3;
                *(f32 *)(pr + 0x3C) = 4.0f;
                pr[0x2A] = 0x30;
                pr[0x2B] = pr[0xA];
            }
            spd = func_003824E0(1.0f, 2.0f);
            elev = func_003824E0(0.0f, 1.3962634f);
            head = func_0038DAB8(ang, func_L01_00443A18(0.0f, 1.3962634f));
            func_00382760(vel, spd * 0.020000001f, head, elev);
            at[0] = p[i - 1][0] + func_L01_00443A18(0.0f, 0.1f);
            at[1] = p[i - 1][1] + func_L01_00443A18(0.0f, 0.1f);
            at[2] = p[i - 1][2] + func_L01_00443A18(0.0f, 0.1f);
            pr = func_L01_0046A610(at, (u8 *)vel, 0x19, 0x7F, 0x7F804020, life,
                                   func_003824E0(0.25f, 0.7f) * 210000.0f, 500.0f, 1.0f, 0.0f, 0.0f);
            if (pr) pr[2] = D_L01_0022121C[0][6];
            return;
        }
        func_00389598(D_L01_001DC954);
        q1.texture = func_00389598(0x2B);
        q1.prim = ((unsigned long)half << 32) | 0x68;
        func_003D2DA0(&q1, 0, 0);
        func_003D2DA0(&q2, 0, 0);
        u0 = (f32)i * 0.33f;
        u1 = u0 + 0.33f;
        if (u0 >= 1.0f) {
            u1 -= 1.0f;
            u0 -= 1.0f;
        }
        for (k = 0; k < 4; k++) {
            q1.v[0][k] = q1.v[2][k];
            q1.v[1][k] = q1.v[3][k];
            q2.v[0][k] = q2.v[2][k];
            q2.v[1][k] = q2.v[3][k];
        }
        q2.uv[0][0] = u0;
        q2.uv[1][0] = u0;
        q2.uv[2][0] = u1;
        q2.uv[3][0] = u1;
    }
}

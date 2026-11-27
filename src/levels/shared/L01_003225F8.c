#include "common.h"
#include "vu0.h"
/* localdecomp:start func_L01_003225F8 */
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
typedef struct {
    u8 pad0[0x2E0];
    f32 vel[4];
    u8 pad2F0[0x25C0 - 0x2F0];
    u8 *x25C0;
} Hero_003225F8;
typedef struct {
    u8 pad0;
    u8 level;
    u8 pad2[0x6C - 2];
    f32 damage;
    u8 pad70[0xF0 - 0x70];
} Weapon_003225F8;
extern Hero_003225F8 D_001A4BE0;
extern Weapon_003225F8 D_L01_002C5600[];
extern vu0_v4 D_L01_001E29C0;
extern s32 D_L01_001DC950, D_L01_001DC954;
extern f32 D_L01_001DC95C;
extern u8 D_001425C0[];
extern u8 D_L01_001EAA20[];
extern u8 *D_L01_0022121C[];
__asm__(".extern D_L01_001DC950, 4");
__asm__(".extern D_L01_001DC954, 4");
__asm__(".extern D_L01_001DC95C, 4");
static __inline__ void basis_003225F8(Basis_003225F8 *m, f32 *from, f32 *to) {
    extern void func_0038CF68(f32 *, f32 *, f32);
    extern void func_0038CE90(float *, float *, float *);
    f32 one = 1.0f;
    vec_sub_ab(m->fwd, to, from);
    func_0038CF68(m->fwd, m->fwd, one);
    vec_sub_ab(m->up, &D_L01_001E29C0, from);
    func_0038CE90(m->side, m->up, m->fwd);
    func_0038CF68(m->side, m->side, one);
    func_0038CE90(m->up, m->fwd, m->side);
}
void func_L01_003225F8(void *pts, s32 n, s32 half, u32 c0, f32 width, f32 scale, u32 c1, s32 z, void *owner, s32 f1, s32 f2) {
    extern void func_0038CF68(f32 *, f32 *, f32);
    extern void func_0038CE90(float *, float *, float *);
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
    extern u8 *func_L01_004669B0(void *, f32, f32, f32, f32, s32, void *, u32, s32);
    extern u8 *func_L01_0046A610(f32 *, f32 *, s32, s32, s32, s32, f32, f32, f32, f32, f32);
    extern s32 func_L01_00446780(void *, f32 *, s32, s32, s32, s32, f32, f32, f32);
    f32 (*p)[4] = (f32 (*)[4])pts;
    Basis_003225F8 m;
    Quad_003225F8 q1, q2;
    f32 w1[4] __attribute__((aligned(16)));
    f32 w2[4] __attribute__((aligned(16)));
    f32 tmp[4] __attribute__((aligned(16)));
    f32 vel[4] __attribute__((aligned(16)));
    f32 at[4] __attribute__((aligned(16)));
    s32 i, life;
    f32 u0, u1, ang, size, elev, spd, head;
    u8 *weapon;
    u8 *pr;
    u8 *pr2;
    u8 *s;
    s32 flags = 0x44;
    f32 spread;
    q1.texture = func_00389598(D_L01_001DC950);
    q1.zero = 0;
    q1.clamp = 0xFF9000000260;
    q1.col[0] = q1.col[1] = q1.col[2] = q1.col[3] = c0;
    q1.prim = ((unsigned long)half << 32) | 0x68;
    func_L01_00322570((u8 *)&q1);
    q1.uv[0][0] = 0; q1.uv[0][1] = 0;
    q1.uv[1][0] = 0; q1.uv[1][1] = 1.0f;
    q1.uv[2][0] = 1.0f; q1.uv[2][1] = 0;
    q1.uv[3][0] = 1.0f; q1.uv[3][1] = 1.0f;
    q2.texture = func_00389598(D_L01_001DC950);
    q2.zero = 0;
    q2.clamp = 0xFF9000000260;
    q2.col[0] = q2.col[1] = q2.col[2] = q2.col[3] = c1;
    q2.prim = ((unsigned long)(half / 3) << 32) | 0x68;
    func_L01_00322570((u8 *)&q2);
    q2.uv[0][0] = 0; q2.uv[0][1] = 0;
    q2.uv[1][0] = 0; q2.uv[1][1] = 1.0f;
    q2.uv[2][0] = 0.33f; q2.uv[2][1] = 0;
    q2.uv[3][0] = 0.33f; q2.uv[3][1] = 1.0f;
    *(T128_003225F8 *)w1 = 0;
    *(T128_003225F8 *)w2 = 0;
    w1[3] = 1.0f; w2[3] = 1.0f; w1[2] = width; w2[2] = width * scale;
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
        *(T128_003225F8 *)m.org = *(T128_003225F8 *)p[i];
        func_0038D028(q1.v[2], q1.v[2], &m);
        func_0038D028(q1.v[3], q1.v[3], &m);
        func_0038D028(q2.v[2], q2.v[2], &m);
        func_0038D028(q2.v[3], q2.v[3], &m);
        if (i == n - 2) func_0038CDF8(tmp, q1.v[2], q1.v[3], 0.5f);
        if (i > 0 && f2 == 0 && func_003D3CB0(p[i - 1], p[i], 2, D_001A4BE0.x25C0, 0)) {
            u32 ca, cb, cc;
            if (f1 != 0) {
                ca = 0x3FFF1010; cb = 0x5F505050; cc = 0x20FF1010;
                if (D_L01_002C5600[D_001425C0[0x47]].level >= 4) {
                    ca = 0x3F202020; cb = 0x5F50507F; cc = 0x20404040;
                }
                func_003D9508(D_L01_001EAA20, 0x39, ca, 1, func_003824E0(0.125f, 0.25f) * 1.5f, 0.2f, func_00382538());
                func_003D9508(D_L01_001EAA20, 0x39, cb, 1, func_003824E0(0.0625f, 0.125f) * 1.5f, 0.2f, func_00382538());
                func_003D9508(D_L01_001EAA20, 0x0B, cc, 1, func_003824E0(0.15f, 0.35f) * 1.5f, 0.2f, 0.0f);
                weapon = (u8 *)&D_L01_002C5600[D_001425C0[0x47]];
                if (weapon[1] >= 4)
                    func_L01_00446780(owner, (f32 *)D_L01_001EAA20, 0x08000000, 0, 1, 0, 1.0f, *(f32 *)(weapon + 0x6C), 0.0f);
                return;
            }
            weapon = (u8 *)(D_L01_002C5600 + D_001425C0[0x47]);
            if (weapon[1] >= 4)
                func_L01_00446780(owner, p[i - 1], 0x410000, 0, 1, 0, 2.0f, *(f32 *)(weapon + 0x6C), 0.0f);
            vec_sub_ba(tmp, &D_L01_001E29C0, p[i]);
            ang = func_0038D160(tmp[0], tmp[1]);
            spd = func_003824E0(0.2f, 3.0f);
            func_0038CE20(vel, D_001A4BE0.vel, -(spd * 0.020000001f));
            life = func_L01_00443A18(1.0f, 2.0f);
            size = func_003824E0(0.3f, 0.75f) * 210000.0f;
            at[0] = p[i - 1][0] + func_L01_00443A18(0.0f, 0.2f);
            at[1] = p[i - 1][1] + func_L01_00443A18(0.0f, 0.2f);
            at[2] = p[i - 1][2] + func_L01_00443A18(0.0f, 0.2f);
            pr = func_L01_004669B0(at, 0.0f, 1.0f, 1.01f, size, life, vel, 0x7F202020, 0);
            if (pr) {
                *(s16 *)(pr + 0xA) = 75;
                s = pr + 0x20;
                pr[3] = flags;
                pr[9] = flags;
                *(f32 *)(s + 0x1C) = 4.0f;
                *(s32 *)(s + 4) = 3;
                s[0xA] = 0x30;
                s[0xB] = pr[0xA];
            }
            spread = 0.1f;
            spd = func_003824E0(1.0f, 2.0f);
            elev = func_003824E0(0.0f, 1.3962634f);
            head = func_L01_00443A18(0.0f, 1.3962634f);
            head = func_0038DAB8(ang, head);
            func_00382760(vel, spd * 0.020000001f, head, elev);
            at[0] = p[i - 1][0] + func_L01_00443A18(0.0f, spread);
            at[1] = p[i - 1][1] + func_L01_00443A18(0.0f, spread);
            at[2] = p[i - 1][2] + func_L01_00443A18(0.0f, spread);
            pr2 = func_L01_0046A610(at, vel, 0x19, 0x7F, 0x7F804020, life,
                                   func_003824E0(0.25f, 0.7f) * 210000.0f, 500.0f, 1.0f, 0.0f, 0.0f);
            if (pr2) pr2[2] = D_L01_0022121C[0][6];
            return;
        }
        q1.texture = func_00389598(D_L01_001DC954);
        q1.prim = 0x68;
        q1.prim |= (unsigned long)half << 32;
        q1.texture = func_00389598(0x2B);
        func_003D2DA0(&q1, 0, 0);
        func_003D2DA0(&q2, 0, 0);
        u0 = (f32)i * 0.33f;
        u1 = u0 + 0.33f;
        if (u0 >= 1.0f) {
            u0 -= 1.0f;
            u1 -= 1.0f;
        }
        q2.uv[0][0] = u0;
        q2.uv[1][0] = u0;
        q2.uv[2][0] = u1;
        q2.uv[3][0] = u1;
        *(T128_003225F8 *)q1.v[0] = *(T128_003225F8 *)q1.v[2];
        *(T128_003225F8 *)q1.v[1] = *(T128_003225F8 *)q1.v[3];
        *(T128_003225F8 *)q2.v[0] = *(T128_003225F8 *)q2.v[2];
        *(T128_003225F8 *)q2.v[1] = *(T128_003225F8 *)q2.v[3];
    }
}
/* localdecomp:end func_L01_003225F8 */

#include "common.h"

typedef struct { u8 pad[80]; s32 idx; } Sub_00322E00;
typedef struct { u8 pad[104]; Sub_00322E00 *sub; } Moby_00322E00;

/* localdecomp:start func_L01_00322F80 */
__asm__(".extern D_L01_001DC93C, 4");
extern s32 D_L01_001DC93C;
extern u8 D_L01_001D66B0[8];
extern f32 func_003824E0(f32, f32);
extern s32 func_L01_00424CB0(void *pos, f32 radius, f32 x, f32 r, f32 g, f32 b);
extern void func_L01_00323120(f32 *muzzle, u8 *zero, f32 charge);
extern void func_L01_00323080(f32 *muzzle);

/* hydra_charge_glow: the Spitting Hydra's muzzle look each frame at charge c: a light of
   radius 4c (made once; its slot is kept in D_L01_001DC93C, -1 for none), the glows sized
   by c, and from c 0.45 the glare. */
void func_L01_00322F80(u8 *gun, f32 *muzzle, f32 charge)
{
    u8 *vars = *(u8 **)(gun + 0x68);

    if (D_L01_001DC93C == -1) {
        /* blue-white: r 0.1-0.35, g 0.35, b 0.75-1 */
        D_L01_001DC93C = func_L01_00424CB0(vars + 0x10, charge * 4.0f, 0.0f,
                                           func_003824E0(0.1f, 0.35f), 0.35f,
                                           func_003824E0(0.75f, 1.0f));
    }
    /* D_L01_001D66B0, a zero vector, goes unused */
    func_L01_00323120(muzzle, D_L01_001D66B0, charge);
    if (0.45f <= charge) {
        func_L01_00323080(muzzle);
    }
}
/* localdecomp:end func_L01_00322F80 */

/* localdecomp:start func_L01_00323080 */
#include "vu0.h"
extern void func_00382580(void *, f32, f32);
extern void func_0038CF68(f32 *, s32, f32);
extern void func_L01_004735F0(void *, void *, s32, f32);

void func_L01_00323080(f32 *a0) {
    vu0_q v;
    vu0_q w;
    func_00382580(&v, 0.025f, 0.15f);
    vec_add_ba(&v, &v, a0);
    vec_sub_ab(&w, a0, &v);
    ((void (*)(void *, void *, f32))func_0038CF68)(&w, &w, 0.015000001f);
    func_L01_004735F0(&v, &w, 0xC, 1.0f);
}
/* localdecomp:end func_L01_00323080 */

LINKER_REMNANT("asm/levels", func_L01_00323118);

/* localdecomp:start func_L01_00323120 */
extern u8 D_L01_001D66B0[8];
extern u8 *D_L01_00221208[];
extern s32 func_00382468(s32);
extern f32 func_L01_00443A18(f32, f32);
extern u8 *func_L01_0046A610(f32 *pos, u8 *velocity, s32 life, s32 alpha, s32 rgb, s32 spin,
                             f32 size, f32 growth, f32 f14, f32 f15, f32 f16);

/* hydra_muzzle_glows: the Spitting Hydra's muzzle glows sized by its charge, each frame with
   even odds: a 0x2C of 6 x the charge in (0x20, 0x40, 0x90) at alpha 6 with particle type
   0x5C's texture 1, and one of 2.4 x the charge in (0x20, 0x40, 0x80) at 0x7F with its
   texture 0, jittered +-0.04, half added and half blended. */
void func_L01_00323120(f32 *muzzle, u8 *zero, f32 charge)
{
    f32 size = charge * 210000.0f;
    f32 at[4];
    u8 *glow;

    /* spun +-1, growing 500 (/ 210000) a frame */
    if (func_00382468(2) != 0) {
        glow = func_L01_0046A610(muzzle, D_L01_001D66B0, 12, 6, 0x904020,
                                 (s32)func_L01_00443A18(1.0f, -1.0f), size * 6.0f, 500.0f,
                                 1.0f, 0.0f, 2.0f);
        if (glow != 0) {
            glow[2] = D_L01_00221208[0][1];
        }
    }
    /* the second jittered up to 0.04 either way */
    at[0] = muzzle[0] + func_L01_00443A18(0.0f, 0.04f);
    at[1] = muzzle[1] + func_L01_00443A18(0.0f, 0.04f);
    at[2] = muzzle[2] + func_L01_00443A18(0.0f, 0.04f);
    if (func_00382468(2) != 0) {
        glow = func_L01_0046A610(at, D_L01_001D66B0, 12, 0x7F, 0x804020,
                                 (s32)func_L01_00443A18(1.0f, -1.0f), size * 2.4f, 500.0f,
                                 1.0f, 0.0f, 2.0f);
        if (glow != 0) {
            glow[3] = func_00382468(2) != 0 ? 0x48 : 0x44;
            glow[2] = D_L01_00221208[0][0];
        }
    }
}
/* localdecomp:end func_L01_00323120 */

/* localdecomp:start func_L01_00323300 */
extern u8 D_001A30B0[];
extern void func_003A4F28(s32);
void func_L01_00323300(Moby_00322E00 *m) {
    Sub_00322E00 *s = m->sub;
    s32 i = s->idx;
    if (i != -1) {
        u8 *e = D_001A30B0 + i * 128;
        if (*(Moby_00322E00 **)(e + 220) == m && e[208] != 0) func_003A4F28(i);
    }
    s->idx = -1;
}
/* localdecomp:end func_L01_00323300 */

/* localdecomp:start func_L01_00323368 */
#include "vu0.h"
typedef struct {
 u8 pad0[0xBD8]; u8 *lockTarget;
 u8 padBDC[0x1210-0xBDC]; s32 fireButton;
 u8 pad1214[0x1220-0x1214]; s32 handTicks;
 u8 pad1224[0x1430-0x1224]; u8 *target;
 u8 pad1434[0x16B0-0x1434]; s32 f16B0;
 u8 pad16B4[0x16D4-0x16B4]; s32 f16D4; s32 f16D8;
 u8 pad16DC[0x25C0-0x16DC]; u8 *moby; s32 state;
 u8 pad25C8[0x25E9-0x25C8]; u8 firing;
 u8 pad25EA[3]; u8 noFiring;
 u8 pad25EE[0x28BC-0x25EE]; s32 aimingWait;
} Game_0031CCE8;
extern Game_0031CCE8 D_001A4BE0;
extern vu0_v4 D_L01_001E29C0;
extern u8 *D_001D52FC;
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_00323368;
extern s32 D_L01_001D6694;
extern s32 D_L01_001E1830;
extern s32 D_L01_001E1834;
extern s32 D_L01_001E1850;
extern s32 D_L01_001DCA00;
__asm__(".extern D_L01_001DCA00, 4");
extern f32 D_L01_001DC9A0;
extern f32 D_L01_001DC9B0;
__asm__(".extern D_L01_001DC9A0, 4");
__asm__(".extern D_L01_001DC9B0, 4");
extern V_00323368 D_L01_001E29E0;
extern u8 D_L01_002AE990[];
/* hydra_gun_update: aim the Spitting Hydra at the locked target each frame and fire on the button. */
void func_L01_00323368(u8 *m) {
    extern void func_L01_00323F38();
    extern u8 *func_L01_004572B0(u8 *, s32, s32 *);
    extern u8 *func_L01_00457410(u8 *);
    extern void func_L01_00444F38(u8 *, s32, s32, s32, s32);
    extern void func_L01_0040E050(void *);
    extern u8 *func_L01_00450BB0(void *, void *, f32, f32, f32, f32, f32, s32);
    extern void func_L01_004CB128(void *, u8 *, s32);
    extern f32 func_0038CF00(void *, void *);
    extern f32 func_0038DAB8(f32, f32);
    extern s32 func_L01_004CB1F0(f32, f32);
    extern s32 func_L01_005118D0(s32, s32);
    extern void func_L01_004EA7D8(s32, u8 *);
    extern void func_003C3A10(u8 *, s32, s32, s32);
    extern s32 func_L01_003F2058(void *, s32);
    extern f32 func_003824E0(f32, f32);
    extern s32 func_003A52A0(s32, s32, u8 *);
    extern u8 *func_L01_00457480(s32, s32);
    extern void func_L01_005003D0(s32, s32);
    extern void func_L01_00385228(void *, u8 *, u8 *);
    extern void func_L01_00404A10(void *, u8 *);
    extern void func_L01_00323A18(u8 *);
    extern void func_L01_004EAA80(void);
    extern s32 func_L01_005119E0(s32);
    extern void func_L01_003F2278(s32, s32);
    extern s32 func_L01_003F1FC0(s32, s32);
    extern void func_L01_003F6F20(s32, u8 *, u32, void *, s32, s32, s32, f32, f32, f32, f32, f32, f32, f32);
    V_00323368 sp0, sp10, sp20;
    u8 *vars = *(u8 **)(m + 0x68);
    u8 *obj;
    u8 *P;
    u8 *hero;
    s32 idx;
    s32 found, i;
    f32 f20;
    if (m[0x20] == 0) {
        m[0x30] = 0xFF;
        D_L01_001E1834 = 0;
        *(s16 *)(vars + 0x58) = -1;
        m[0x20] = 1;
        idx = (s32)func_L01_004572B0(m, 0, &found);
        *(s16 *)(vars + 0x5A) = idx;
        if (found == 0) {
            u8 *p = func_L01_00457480(*(s16 *)(m + 0xAA), (s16)idx);
            s32 v = (s32)func_L01_00457410(p + 0x40);
            for (i = 0; i < 16; i++) {
                *(s32 *)(p + i * 4) = v;
                v += 0x280;
            }
        }
    }
    if (D_001A4BE0.state == 1) func_L01_005003D0(0x1D, 1);
    if (m[0x42] == m[0x43]) {
        if (m[0x60] & 2) func_L01_00444F38(m, 1, 0, 2, 0);
    }
    func_L01_0040E050(vars + 0x50);
    func_0038D000(&sp0, &D_L01_001DC9A0, m + 0xC0);
    vec_add_ab(&sp0, &sp0, (V_00323368 *)(m + 0x10));
    *(V_00323368 *)(vars + 0x10) = sp0;
    func_0038D000(&sp10, &D_L01_001DC9B0, m + 0xC0);
    vec_add_ab(&sp10, &sp10, (V_00323368 *)(m + 0x10));
    *(V_00323368 *)(vars + 0x20) = sp10;
    func_0038CF68(vars + 0x40, m + 0xD0, -20.0f);
    func_0038CF68(vars + 0x30, D_001A4BE0.moby + 0xC0, 1.0f);
    obj = func_L01_00450BB0(vars + 0x10, vars + 0x30, 0.052359879f, 0.052359879f, 35.0f, 0.7853982f, 0.610865235f, 0);
    if (obj) {
        func_L01_004CB128(&sp20, obj, 0);
        vec_sub_ba((V_00323368 *)(vars + 0x30), &sp20, (V_00323368 *)(vars + 0x10));
        func_0038CF68(vars + 0x30, vars + 0x30, 20.0f);
        vec_add_ab((V_00323368 *)vars, (V_00323368 *)(vars + 0x30), &sp0);
        if (D_001A4BE0.state != 0x1D && D_001A4BE0.f16B0 == 0) {
            f20 = func_0038CF00(&D_L01_001E29C0, &sp20) / 150.0f;
            *(f32 *)(vars + 0x5C) = func_0038DAB8(*(f32 *)(vars + 0x5C), 0.0349065848f);
            f20 = f20 * 0.65f;
            func_L01_003F6F20(0, m, 0xFF0FFF0F, &sp20, 0x26, -1, 4,
                              fabs_asm(0.9f - f20), -*(f32 *)(vars + 0x5C), 90.0f, 0.5f, 0.5f, 40.0f, 40.0f);
            D_001A4BE0.lockTarget = obj;
        }
    }
    if (D_001A4BE0.state == 0x1D || D_001A4BE0.f16B0 != 0) {
        func_0038CF68(vars + 0x30, &D_L01_001E29E0, 20.0f);
        vec_add_ba((V_00323368 *)vars, (V_00323368 *)(vars + 0x30), &sp0);
        func_L01_003F6F20(0, m, func_L01_004CB1F0(0.99f, 150.0f), 0, 0x56, -1, 4,
                          0.75f, 0.0f, 90.0f, 0.5f, 0.5f, 40.0f, 40.0f);
        D_001A4BE0.lockTarget = obj;
    } else {
        if (!obj) {
            func_0038CF68(vars + 0x30, D_001A4BE0.moby + 0xC0, 20.0f);
            vec_add_ab((V_00323368 *)vars, (V_00323368 *)(vars + 0x30), &sp0);
        }
        D_001A4BE0.f16D4 = 0;
        D_001A4BE0.f16D8 = 0;
    }
    if ((D_001A4BE0.noFiring == 0 && D_L01_001D6694 == 0 && D_001A4BE0.handTicks >= 0x13 && m[0x42] < 2
         && (*(s32 *)((u8 *)D_001D52FC + 0x1A0) & D_001A4BE0.fireButton))
        || ((*(s32 *)((u8 *)D_001D52FC + 0x1A0) & 8) && D_001A4BE0.state == 0x1D)) {
        /* one shot more and the 17-frame hold; the do-while block keeps retail's order (it forms
           &D_L01_001E1830 only after both stores) */
        do {
            D_L01_001E1834 = D_L01_001E1834 + 1;
            *(s32 *)(vars + 0x54) = 0x11;
        } while (0);
        if (func_0038CAD0((s32)&D_L01_001E1830)) {
            if (func_L01_005118D0(-1, 1)) {
                f20 = 3.0f;
                func_L01_004EA7D8(-1, (u8 *)D_001D52FC);
                *(f32 *)(m + 0x48) = f20;
                if (m[0x43] != 2) func_003C3A10(m, 2, 0, 0);
                *(f32 *)(m + 0x48) = f20;
                D_L01_001E1850 = 1;
                *(s16 *)(vars + 0x58) = (s16)func_L01_003F2058(D_L01_002AE990, 0);
                func_0038CF68(&sp20, vars + 0x30, func_003824E0(60.0f, 80.0f) * 0.020000001f);
                func_003A52A0(3, 0, m);
                if (D_L01_001DCA00) {
                    func_L01_00385228(vars + 0x20, m, obj);
                    D_L01_001DCA00 = 0;
                } else {
                    func_L01_00385228(vars + 0x10, m, obj);
                    D_L01_001DCA00 = 1;
                }
                D_L01_001E1830 = 8;
                func_L01_00404A10(func_L01_00323F38, m);
                func_L01_00323A18(m);
            } else {
                if ((*(s32 *)((u8 *)D_001D52FC + 0x1A4) & D_001A4BE0.fireButton) || D_L01_001E1850 == 1) {
                    func_003A52A0(4, 0, m);
                    D_L01_001E1850 = 0;
                }
            }
        }
    } else {
        s32 t;
        func_L01_004EAA80();
        t = *(s32 *)(vars + 0x54);
        D_L01_001E1830 = 0;
        if (t <= 0) D_L01_001E1834 = 0;
    }
    if ((*(s32 *)((u8 *)D_001D52FC + 0x1A0) & D_001A4BE0.fireButton) == 0 || func_L01_005119E0(-1) == 0
        || D_001A4BE0.firing == 0) {
        if (*(s16 *)(vars + 0x58) < 0) return;
        func_L01_003F2278(*(s16 *)(vars + 0x58), 0);
        *(s16 *)(vars + 0x58) = -1;
    }
    {
        s32 h = *(s16 *)(vars + 0x58);
        if (h > 0) {
            if (func_L01_003F1FC0(h - 1, 0) == 0) *(s16 *)(vars + 0x58) = -1;
        }
    }
}
/* localdecomp:end func_L01_00323368 */

/* localdecomp:start func_L01_00323A18 */
#include "vu0.h"
typedef int Q_00323A18 __attribute__((mode(TI)));
typedef union { Q_00323A18 q; f32 f[4]; } V_00323A18;
typedef struct { u8 pad[0xD4]; u8 *texture; } Textures_00323A18;
extern Textures_00323A18 D_L01_00221098[];
extern s32 D_L01_001DCA00_00323A18;
__asm__(".extern D_L01_001DCA00_00323A18, 4");
extern s32 D_L01_001DC9E0;
__asm__(".extern D_L01_001DC9E0, 4");
extern u8 D_L01_001D66B0[8];
void func_L01_00323A18(u8 *obj) {
    extern void func_0038CE20(void *, void *, f32);
    extern f32 func_L01_00443A18(f32, f32);
    extern s32 func_00382468(s32);
    extern u8 *func_L01_0046FB40(void *, u8 *, s32, u32, s32, s32, s32, f32, f32, f32, s32);
    V_00323A18 pos, delta, step, jitter;
    u8 *vars = *(u8 **)(obj + 0x68);
    f32 size, spread;
    s32 i, spin;
    u8 *p;
    if (D_L01_001DCA00_00323A18) pos.q = *(Q_00323A18 *)(vars + 0x10);
    else pos.q = *(Q_00323A18 *)(vars + 0x20);
    func_0038CE20(&delta, obj + 0xD0, -0.1f);
    vec_add_ba(&pos, &pos, &delta);
    func_0038CE20(&step, obj + 0xE0, 0.15f);
    vec_add_ab(&pos, &pos, &step);
    func_0038CE20(&step, obj + 0xE0, -0.033333335f);
    if (D_L01_001DC9E0) { size = 0.2f; spread = 0.15f; }
    else { size = 0.175f; spread = 0.1f; }
    for (i = 0; i < 9; i++) {
        jitter.f[0] = pos.f[0] + func_L01_00443A18(0.0f, spread);
        jitter.f[1] = pos.f[1] + func_L01_00443A18(0.0f, spread);
        jitter.f[2] = pos.f[2] + func_L01_00443A18(0.0f, spread);
        spin = func_00382468(255);
        func_L01_0046FB40(&jitter, D_L01_001D66B0, 3, 0x808080, spin, 127, 127,
                          size * 210000.0f, size * 210000.0f, 0.0f, 1);
        p = func_L01_0046FB40(&pos, D_L01_001D66B0, 3, 0x203080, spin, 16, 16,
                             262500.0f, 262500.0f, 0.0f, 1);
        if (p) p[2] = *D_L01_00221098[0].texture;
        vec_add_ab(&pos, &pos, &step);
    }
}
/* localdecomp:end func_L01_00323A18 */

/* localdecomp:start func_L01_00323C68 */
#include "vu0.h"
typedef union { vu0_q q; f32 f[4]; } V_00323C68;
typedef struct {
    V_00323C68 vertices[4];
    u32 color[4];
    s32 x50, x54, x58;
    f32 x5C, x60;
    s32 x64;
    f32 x68, x6C;
    u8 tail[0x20];
} Render_00323C68;
extern s32 D_L01_001DC9E0_00323C68;
__asm__(".extern D_L01_001DC9E0_00323C68, 4");
extern s32 D_L01_001DCA00_00323C68;
__asm__(".extern D_L01_001DCA00_00323C68, 4");
extern vu0_v4 D_L01_001E29C0;
void func_L01_00323C68(u8 *object) {
    extern f32 func_003824E0_00323C68(f32, f32);
    extern void func_0038CF68(f32 *, s32, f32);
    extern void func_0038CE90_00323C68(f32 *, f32 *, f32 *);
    extern void func_0038D000_00323C68(f32 *, f32 *, f32 *);
    extern void func_003D93B0(void *, s32, s32, s32);
    extern void func_003D2DA0(void *, f32 *, s32);
    V_00323C68 basis[4];
    Render_00323C68 render;
    V_00323C68 offset;
    u8 *state = *(u8 **)(object + 0x68);
    f32 a, b;
    s32 i;
    if (D_L01_001DC9E0_00323C68) {
        a = func_003824E0_00323C68(0.75f, 0.95f);
        b = func_003824E0_00323C68(2.0f, 2.5f);
    } else {
        a = func_003824E0_00323C68(0.275f, 0.475f);
        b = func_003824E0_00323C68(1.0f, 1.3f);
    }
    func_0038CF68(basis[0].f, (s32)(state + 0x40), -1.0f);
    vec_sub_ba(&basis[1], &D_L01_001E29C0, object + 0x10);
    func_0038CE90_00323C68(basis[2].f, basis[1].f, basis[0].f);
    func_0038CF68(basis[2].f, (s32)&basis[2], a);
    func_0038CF68(basis[0].f, (s32)&basis[0], b);
    basis[0].f[3] = 0.0f;
    basis[1].f[3] = 0.0f;
    basis[2].f[3] = 0.0f;
    if (D_L01_001DC9E0_00323C68) func_003D93B0(&render, 63, 1, 128);
    else func_003D93B0(&render, 62, 1, 128);
    render.x50 = 0;
    render.x5C = 1.0f;
    render.x60 = 1.0f;
    render.x68 = 1.0f;
    render.x6C = 1.0f;
    render.x54 = 0;
    render.x58 = 0;
    render.x64 = 0;
    for (i = 0; i < 4; i++) {
        qzero(&render.vertices[i]);
        render.vertices[i].f[0] = i < 2 ? 0.0f : 1.0f;
        render.vertices[i].f[1] = 0.0f;
        render.vertices[i].f[2] = (i & 1) ? 1.0f : -1.0f;
        render.vertices[i].f[3] = 1.0f;
        render.color[i] = 0x7FFFFFFF;
    }
    {
        f32 y = -1.0f;
        if (D_L01_001DC9E0_00323C68) y = -2.0f;
        offset.q = 0;
        offset.f[1] = y;
    }
    func_0038D000_00323C68(basis[3].f, offset.f, (f32 *)(object + 0xC0));
    if (D_L01_001DCA00_00323C68) vec_add_ba(&basis[3], &basis[3], state + 0x10);
    else vec_add_ba(&basis[3], &basis[3], state + 0x20);
    basis[3].f[3] = 1.0f;
    func_003D2DA0(&render, basis[0].f, 0);
    func_003D2DA0(&render, basis[0].f, 0);
    func_003D2DA0(&render, basis[0].f, 0);
    func_003D2DA0(&render, basis[0].f, 0);
    func_003D2DA0(&render, basis[0].f, 0);
    func_003D2DA0(&render, basis[0].f, 0);
}
/* localdecomp:end func_L01_00323C68 */

/* localdecomp:start func_L01_00323F38 */
extern s32 D_L01_001DCA00;
__asm__(".extern D_L01_001DCA00, 4");
void func_L01_00323F38(u8 *o) {
    extern s32 func_0038CAD0(s32);
    extern void func_L01_00323C68(u8 *);
    extern f32 func_00382538(void);
    extern f32 func_003824E0(f32,f32);
    extern void func_003D9508(u8 *,s32,u32,s32,f32,f32,f32);
    u8 *s=*(u8 **)(o+0x68);
    u8 *p;
    if (func_0038CAD0((s32)(s+0x54))) return;
    func_L01_00323C68(o);
    if (D_L01_001DCA00) {
        p=s+0x10;
        func_003D9508(p,49,0x3F204090,1,0.75f,0.0f,func_00382538());
        func_003D9508(p,49,0x3F204090,1,0.75f,0.0f,func_00382538());
        func_003D9508(p,11,0x3F204090,1,0.75f,0.08f,0.0f);
        func_003D9508(p,65,0x3F909090,1,0.94f,0.0f,func_003824E0(30.0f,60.0f)*0.017453292f);
    } else {
        p=s+0x20;
        func_003D9508(p,49,0x3F204090,1,0.75f,0.0f,func_00382538());
        func_003D9508(p,49,0x3F204090,1,0.75f,0.0f,func_00382538());
        func_003D9508(p,11,0x3F204090,1,0.75f,0.08f,0.0f);
        func_003D9508(p,65,0x3F909090,1,0.94f,0.0f,func_003824E0(30.0f,60.0f)*0.017453292f);
    }
}
/* localdecomp:end func_L01_00323F38 */

LINKER_REMNANT("asm/levels", func_L01_00324160);

/* localdecomp:start func_L01_00324180 */
extern u8 D_L01_002AF298[];

u8 *func_L01_00324180(s32 a0, s32 a1, s32 *a2) {
    if (a1 == 0) {
        *a2 = 0x6C;
        return D_L01_002AF298;
    }
    return 0;
}
/* localdecomp:end func_L01_00324180 */

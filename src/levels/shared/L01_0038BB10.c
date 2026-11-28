#include "common.h"
#include "vu0.h"

typedef int s128 __attribute__((mode(TI)));
typedef struct {
    f32 x;
    f32 y;
    f32 z;
    f32 w;
} __attribute__((aligned(16))) S_38C110v;
typedef int u128_t __attribute__((mode(TI)));
typedef struct {
    u128_t q[5];
} S_2BEE10;

/* localdecomp:start func_L01_0038BB10 */
#include "vu0.h"
#include "structs/hero.h"
typedef union { f32 f[4]; vu0_q q; } V_VH;
typedef struct {
    f32 x, y, z, w;
    u8 p10[0x10];
    f32 f20;
    s32 f24;
    s32 f28;
    s32 f2C;
    u8 p30[0x10];
    f32 f40;
    s32 f44;
    s32 f48;
} __attribute__((aligned(16))) S_2A40_38BB10;
typedef struct { u8 pad[0x140]; f32 x, y; } S_2880_38BB10;
typedef struct { u8 pad[0x5C]; u8 *f5C; u8 pad2[0x184 - 0x60]; s32 f184; } S_1098_38BB10;
typedef struct { u8 pad[0x6C]; f32 f6C; u8 pad2[0xF0 - 0x70]; } __attribute__((aligned(16))) S_5600_38BB10;
typedef struct { u8 pad[0x77]; u8 f77; } S_25C0_38BB10;
typedef struct { u8 pad[0x30]; u8 *f30; u8 pad2[0x60 - 0x34]; } S_0820_38BB10;
typedef struct {
    V_VH v;
    u8 p10[8];
    u8 b18;
    u8 b19;
    u16 h1A;
    u8 p1C[4];
    s32 i20;
    u8 p24[0xC];
} S_Hit_38BB10;
extern struct Hero D_001A4BE0_0038BB10;
extern S_25C0_38BB10 D_001425C0;
extern S_2A40_38BB10 D_L01_001E2A40_0038BB10;
extern S_2880_38BB10 D_L01_001E2880;
extern u8 *D_L01_001EEA80[];
extern S_1098_38BB10 D_L01_00221098;
extern u8 D_L01_002B3D60[];
extern S_5600_38BB10 D_L01_002C5600[];
extern S_0820_38BB10 D_L01_00290820[];
extern u8 D_L01_001D66B0[] __attribute__((section(".sdata")));
extern s32 D_L01_001E1F1C;
extern f32 D_L01_001DDF30, D_L01_001DDF34, D_L01_001DDF38, D_L01_001DDF44, D_L01_001DDF48;
extern s32 D_L01_001DDF4C;
__asm__(".extern D_L01_001DDF30, 4");
__asm__(".extern D_L01_001DDF34, 4");
__asm__(".extern D_L01_001DDF38, 4");
__asm__(".extern D_L01_001DDF44, 4");
__asm__(".extern D_L01_001DDF48, 4");
__asm__(".extern D_L01_001DDF4C, 4");
extern s32 func_L01_004CB2D8(u8 *);
extern void func_L01_004CAB30(void *, void *);
extern s32 func_0038CAD0(s32 *);
extern void func_L01_00404A10(void (*)(u8 *), u8 *);
extern void func_L01_00404808(void (*)(u8 *), u8 *);
extern void func_L01_00404AD8(void (*)(u8 *), u8 *);
extern void func_L01_0038CC38();
extern void func_L01_0038D5C0(u8 *);
extern void func_L01_0038DF00(u8 *);
extern void func_L01_0038D138();
extern void func_L01_0038D108();
extern void func_L01_0038CDC8();
extern f32 func_0038D160(f32, f32);
extern f32 func_L01_00443A18(f32, f32);
extern f32 func_0038DAB8(f32, f32);
extern f32 func_0038D098_0038BB10(f32);
extern f32 func_0038D0B0(f32);
extern f32 func_003824E0(f32, f32);
extern s32 func_00382498(s32, s32);
extern s32 func_00382468(s32);
extern void func_L01_00474680(void *, void *, s32, u32, u32, s32, s32, f32, f32, f32, f32);
extern u8 *func_L01_0046B458(void *, s32, f32, f32, u32, s32, s32, void *, f32, s32);
extern void func_L01_00470C78(void *, s32, f32, f32, u32, s32, s32, void *, s32, s32, s32, s32);
extern void func_L01_0038E968(u8 *);
extern f32 func_0038CEA8(void *);
extern s32 func_L01_003F2058(void *, s32);
extern void func_00382760_0038BB10(void *, f32, f32, f32);
extern void func_L01_003298C8(void *, void *, s32, s32, s32, u32, s32, s32, s32, s32, f32, f32);
extern u8 *func_L01_004713C8(void *, void *, s32, u32, s32, s32, s32, f32, f32, f32, s32);
extern s32 func_003D4D00(void *, s32, u8 *, s32, f32);
extern f32 func_0038CF00(void *, void *);
extern s32 func_00382348(u8 *);
extern void func_0038CF68(void *, void *, f32);
extern void func_L01_0035E638(u8 *, void *, void *, s32, f32);
extern f32 func_00382538(void);
extern s32 func_0038DC20(void *, f32);
extern void func_L01_00446760(void *, u8 *, u32, void *, f32);
extern void func_L01_00446978(u8 *, void *);
extern void func_L01_0031B090(u8 *, s32, s32);
extern void func_003C2880(u8 *);
typedef struct {
    u8 pad[0x10];
    V_VH v;
    u8 pad2[0x4];
    s32 timer;
    f32 scale;
    s32 damage_timer;
    s32 alpha;
    u8 gap[4];
    s32 effect;
    s32 intro_timer;
} Effect_38BB10;
extern void func_L01_004C7D98(void *, void *);

void func_L01_0038BB10(u8 *self) {
    V_VH a, b, c;
    S_Hit_38BB10 hit;
    Effect_38BB10 *inner = *(Effect_38BB10 **)(self + 0x68);
    u8 *pos;

    if (func_L01_004CB2D8(self)) func_L01_004CAB30(self + 0x10, self + 0x10);
    if (func_0038CAD0(&inner->intro_timer) == 0) {
        if (inner->intro_timer >= 0xD) {
            D_L01_001DDF44 += 0.8f;
            D_L01_001DDF48 += 0.4f;
        } else {
            D_L01_001DDF44 -= 0.5f;
            D_L01_001DDF48 -= 0.3f;
        }
        func_L01_00404A10(func_L01_0038CC38, self);
    }
    if (self[0x20] == 0) {
        s32 i, j, k, m, n, t, budget;
        f32 heading;
        func_0038CAD0(&inner->timer);
        inner->scale -= 0.1f;
        if (inner->timer >= 0x4C) {
            func_L01_00404808(func_L01_0038D5C0, self);
            return;
        }
        func_L01_00404808(func_L01_0038DF00, self);
        heading = func_0038D160(D_L01_001E2A40_0038BB10.x - *(f32 *)(self + 0x10),
                                D_L01_001E2A40_0038BB10.y - *(f32 *)(self + 0x14));
        pos = self + 0x10;
        for (i = 0; i < 50; i++) {
            f32 r1, sz;
            s32 k;
            r1 = func_0038DAB8(heading, func_L01_00443A18(0.0f, 2.268928f));
            a.f[0] = func_0038D098_0038BB10(r1) * (func_003824E0(18.0f, 27.0f) * 0.020000001f);
            a.f[1] = func_0038D0B0(r1) * (func_003824E0(18.0f, 27.0f) * 0.020000001f);
            a.f[2] = 0.0f;
            a.f[2] = func_003824E0(0.0f, 14.0f) * 0.020000001f;
            sz = func_003824E0(0.8f, 1.2f);
            k = func_00382498(25, 35);
            func_L01_00474680(pos, &a, 0x19, 0x3F8080FF, 0x8080FF, (k * 5 + 2) / 6, 0,
                              0.04f, sz, 2.7f, 2.5f);
        }
        func_L01_0046B458(pos, 0x1C, 21.0f, 0.1f, 0xBF204080, 2, 1, D_L01_001D66B0, 0.0f, 1);
        func_L01_0046B458(pos, 0x1C, 15.0f, 0.1f, 0xBF2040A0, 2, -1, D_L01_001D66B0, 0.0f, 1);
        func_L01_0046B458(pos, 0x1C, 10.5f, 0.1f, 0xC0FFFFFF, 2, 1, D_L01_001D66B0, 0.0f, 1);
        func_L01_0046B458(pos, 0x1C, 7.5f, 0.1f, 0xB0FFFFFF, 2, -1, D_L01_001D66B0, 0.0f, 1);
        func_L01_00470C78(pos, 0x21, 3.6f, 2.8f, 0x46787878, 2, 2, D_L01_001D66B0, 0, 2, 6, 1);
        func_L01_00470C78(pos, 0x21, 6.8f, 2.8f, 0x46787878, 2, -1, D_L01_001D66B0, 1, 2, 6, 1);
        func_L01_00470C78(pos, 0x21, 8.0f, 6.0f, 0x2D787878, 2, 1, D_L01_001D66B0, 1, 2, 6, 1);
        func_L01_0038E968(self);
        vec_sub_ab(&a, &D_L01_001E2A40_0038BB10, self + 0x10);
        {
            s32 d = (s32)(30.0f - func_0038CEA8(&a));
            D_L01_001DDF4C = d;
            if (d >= 0x1F) D_L01_001DDF4C = 0x1E;
            else if (d < 0xF) D_L01_001DDF4C = 0xF;
        }
        inner->effect = func_L01_003F2058(D_L01_002B3D60, 0);
        D_L01_001E2A40_0038BB10.f20 = 0.4f;
        D_L01_001E2A40_0038BB10.f40 = 0.15f;
        D_L01_001E2A40_0038BB10.f28 = 0x15;
        D_L01_001E2A40_0038BB10.f48 = 0x15;
        D_L01_001E2A40_0038BB10.f2C = 0;
        for (j = 0; j < 5; j++) {
            f32 r1, r2;
            s32 k;
            r2 = func_003824E0(0.08726646f, 0.5235988f);
            r1 = func_0038DAB8(heading, func_L01_00443A18(0.0f, 1.3962634f));
            func_00382760_0038BB10(&b, func_003824E0(8.0f, 15.0f) * 0.020000001f, r1, r2);
            k = func_00382498(0x53, 0x6C);
            func_L01_003298C8(pos, &b, k, 3, 1, 0x80204080, 0, 1, 0x32, 0x78, 3.0f, 14.6f);
        }
        for (m = 0; m < 5; m++) {
            s32 ri = (s32)func_L01_00443A18(2.0f, 6.0f);
            f32 sz, sp, ang;
            s32 k;
            u8 *p;
            b.f[0] = *(f32 *)(self + 0x10) + func_003824E0(-0.2f, 0.2f);
            b.f[1] = *(f32 *)(self + 0x14) + func_003824E0(-0.2f, 0.2f);
            b.f[2] = *(f32 *)(self + 0x18) + func_003824E0(-0.2f, 0.2f);
            sz = func_003824E0(0.15f, 0.2f);
            sp = func_003824E0(7.0f, 10.0f);
            ang = func_0038DAB8(heading, func_L01_00443A18(0.0f, 1.3962634f));
            c.f[0] = func_0038D098_0038BB10(ang) * (sp * 0.020000001f);
            c.f[1] = func_0038D0B0(ang) * (sp * 0.020000001f);
            c.f[2] = 0.0f;
            c.f[2] = func_003824E0(0.0f, 12.0f) * 0.020000001f;
            k = (func_00382498(0x5A, 0x96) * 5 + 2) / 6;
            sz *= 210000.0f;
            p = func_L01_004713C8(&b, &c, k, 0x273538, ri, 0x7F, 0x7F, sz, sz, 0.00584f, 1);
            if (p != 0) {
                k = func_00382468(3);
                p[2] = *(u8 *)(k + D_L01_00221098.f184 + 0xA);
                p[3] = 0x44;
            }
        }
        n = func_003D4D00(pos, 0, self, 0, 13.0f);
        budget = 10;
        if (n > 10) n = 10;
        if (n > 0) {
            u8 **list = D_L01_001EEA80;
            s32 cnt = n;
            for (; cnt != 0; cnt--, list++) {
                if (func_00382348(*list) == 0 && (*(u16 *)(*list + 0x34) & 0x4000) == 0) continue;
                if (*list == (u8 *)D_001A4BE0_0038BB10.hero_moby) continue;
                if (!(8.0f < func_0038CF00(pos, *list + 0x10))) continue;
                vec_sub_ab(&b, *list + 0x10, self + 0x10);
                func_0038CF68(&b, &b, func_003824E0(20.0f, 30.0f) * 0.020000001f);
                func_L01_0035E638(self, pos, &b, 0x10000, 10.0f);
                budget--;
            }
        }
        k = budget + 5;
        for (t = 0; t < k; t++) {
            f32 r2, ang;
            r2 = func_003824E0(-0.34906584f, 0.2617994f);
            ang = func_00382538();
            func_00382760_0038BB10(&b, func_003824E0(20.0f, 30.0f) * 0.020000001f, ang, r2);
            func_L01_0035E638(self, pos, &b, 0x10000, 10.0f);
        }
        self[0x20] = 1;
        return;
    }
    if (self[0x20] == 1) {
        s32 i;
        f32 heading;
        func_0038CAD0(&inner->timer);
        if (inner->timer >= 0x49) {
            pos = self + 0x10;
            func_L01_00404808(func_L01_0038D138, self);
            for (i = 0; i < 100; i++) {
                f32 ang;
                s32 k;
                u8 *p;
                heading = func_0038D160(D_001A4BE0_0038BB10.pos.x - D_L01_001E2880.x,
                                        D_001A4BE0_0038BB10.pos.y - D_L01_001E2880.y);
                func_L01_00443A18(1.0f, 2.0f);
                func_L01_004C7D98(pos, &b);
                func_0038CF68(&b, &b, 0.3f);
                vec_add_ab(&a, &inner->v, &b);
                ang = func_0038DAB8(heading, func_L01_00443A18(0.0f, -6.2831855f));
                c.f[0] = func_0038D098_0038BB10(ang) * 0.3f;
                c.f[1] = func_0038D0B0(ang) * 0.3f;
                c.f[2] = 0.0f;
                k = (func_00382498(0x14, 0x28) * 5 + 2) / 6;
                p = func_L01_004713C8(&a, &c, k, 0x4080FF, func_00382498(-2, -4), 0x70, 0,
                                      168000.0f, 252000.02f, 0.0f, 0);
                if (p != 0) p[2] = *D_L01_00221098.f5C;
            }
        } else {
            self[0x20] = 2;
        }
        return;
    }
    if (self[0x20] == 2) {
        s32 n;
        inner->scale += 0.5f;
        D_L01_001DDF34 += 0.5f;
        D_L01_001DDF38 += 0.7f;
        if (1.6f < inner->scale) inner->scale = 1.6f;
        if (func_0038CAD0(&inner->damage_timer) == 0) {
            a.q = ((V_VH *)(self + 0x10))->q;
            a.f[3] = 2.0f;
            if (func_0038DC20(&a, 100.0f) != -1) {
                if (func_0038CAD0(&D_L01_001E1F1C) == 0) func_L01_00404AD8(func_L01_0038CDC8, self);
                D_L01_001DDF30 += 0.8f;
                inner->alpha -= 4;
                if (inner->alpha < 0) inner->alpha = 0;
                func_L01_00404808(func_L01_0038D108, self);
                func_L01_00404808(func_L01_0038DF00, self);
            }
            n = func_003D4D00(self + 0x10, 0, self, 0,
                              (1.0f - (f32)inner->damage_timer / 25.0f) * 8.0f + 3.0f);
            if (n > 0) {
                u8 **list = D_L01_001EEA80;
                s32 cnt = n;
                for (; cnt != 0; cnt--, list++) {
                    s32 idx;
                    if (func_00382348(*list) == 0 && (*(u16 *)(*list + 0x34) & 0x4000) == 0) continue;
                    if (*list == (u8 *)D_001A4BE0_0038BB10.hero_moby && *(s16 *)(*list + 0xAA) != 0x1068) continue;
                    if (*(s16 *)(*list + 0xAA) == 0xA5A) continue;
                    vec_sub_ba(&b, *list + 0x10, self + 0x10);
                    func_0038CF68(&b, &b, 1.5f);
                    func_0038CF68(&hit, &hit, 2.0f);
                    idx = D_001425C0.f77;
                    func_L01_00446760(&hit, self, 0x1030000, &b, D_L01_002C5600[idx].f6C);
                    hit.v.q = b.q;
                    hit.b19 = 3;
                    hit.b18 = 5;
                    hit.i20 = 1;
                    hit.v.f[3] = 5627.9248f;
                    hit.h1A = *(u16 *)(*list + 0xAA);
                    func_L01_00446978(*list, &hit);
                    func_L01_0031B090(*list, 0x77, *(s32 *)(self + 0xB8));
                }
            }
        } else {
            self[0x20] = 3;
        }
        return;
    }
    if (self[0x20] == 3) {
        s32 i;
        for (i = 0; i < 0x1E; i++) {
            S_0820_38BB10 *e = &D_L01_00290820[i];
            if (e->f30 == self) e->f30 = 0;
        }
        func_003C2880(self);
    }
}
/* localdecomp:end func_L01_0038BB10 */

/* localdecomp:start func_L01_0038C9A0 */
void func_L01_0038C9A0(u8 *a) {
    a[32] = 3;
}
/* localdecomp:end func_L01_0038C9A0 */

/* localdecomp:start func_L01_0038C9B0 */
typedef int s128_9B0 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_38C9B0;
typedef struct { f32 x, y, z; } V3_38C9B0;
typedef struct { f32 u, v; } Uv_38C9B0;
extern V3_38C9B0 D_L01_00291360[];
extern s32 D_L01_00291558[];
extern Uv_38C9B0 D_L01_00291600[];
/* the file's earlier blocks declare it with a 32-bit value; these calls pass the full 64-bit GS register */
extern void func_003A9440(s32, unsigned long);
extern unsigned long func_00389598(s32 a);
extern void func_0038C750(void);
extern f32 func_0038DB48(f32 a);
extern void func_0038D098(f32 a);
extern void func_00382760(V4_38C9B0 *v, f32 a, f32 b, f32 c);
extern void func_0038D028(void *a, void *b, void *c);
extern void func_003D3A24(s32 n, void *a, void *b, void *c, s32 d);

/* eruptor_band: a band of the unit ball, 21 pairs of points, u along it */
void func_L01_0038C9B0(s128_9B0 *matrix, f32 span, f32 from_lat, f32 to_lat, s32 texture, f32 unused_f, s32 colour, s32 added) {
    V4_38C9B0 v;
    V4_38C9B0 w;
    f32 step, lon, u, rad, twenty;
    s32 i, k;

    func_003A9440(8, 0);
    func_003A9440(0x14, 0xFF9000000260UL);
    func_003A9440(0x47, 0x513F1);
    func_003A9440(6, func_00389598(texture));
    if (added != 0) {
        func_003A9440(0x42, 0x8000000048UL);
    } else {
        func_003A9440(0x42, 0x8000000041UL);
    }
    rad = 0.0174532924f;
    func_0038C750();
    twenty = 20.0f;
    step = span * rad / twenty;
    for (i = 0; i < 42; i += 2) {
        k = i / 2;
        lon = func_0038DB48((f32)k * step);
        func_0038D098(lon);
        u = (f32)k / twenty;
        D_L01_00291558[i] = colour;
        D_L01_00291558[i + 1] = colour;
        D_L01_00291600[i].u = u;
        D_L01_00291600[i].v = 0.0f;
        D_L01_00291600[i + 1].u = u;
        D_L01_00291600[i + 1].v = 1.0f;
        func_00382760(&v, 1.0f, lon, from_lat * rad);
        v.w = 1.0f;
        func_0038D028(&w, &v, matrix);
        D_L01_00291360[i].x = w.x;
        D_L01_00291360[i].y = w.y;
        D_L01_00291360[i].z = w.z;
        func_00382760(&v, 1.0f, lon, to_lat * rad);
        v.w = 1.0f;
        func_0038D028(&w, &v, matrix);
        D_L01_00291360[i + 1].x = w.x;
        D_L01_00291360[i + 1].y = w.y;
        D_L01_00291360[i + 1].z = w.z;
    }
    func_003D3A24(0x2A, D_L01_00291360, D_L01_00291558, D_L01_00291600, 1);
}
/* localdecomp:end func_L01_0038C9B0 */

/* localdecomp:start func_L01_0038CC38 */
typedef struct {
    S_38C110v velocity;
    u8 pad10[0x2C];
    s32 alpha;
} Vars_0038CC38;
typedef struct {
    u8 pad0[0x10];
    S_38C110v position;
    u8 state;
    u8 pad21[0x47];
    Vars_0038CC38 *vars;
    u8 pad6C[0x3E];
    s16 class_id;
} Moby_0038CC38;
extern f32 D_L01_001DDF48, D_L01_001DDF44, D_L01_001DDF40;
extern s32 D_L01_001DDF3C;
__asm__(".extern D_L01_001DDF48, 4");
__asm__(".extern D_L01_001DDF44, 4");
__asm__(".extern D_L01_001DDF40, 4");
__asm__(".extern D_L01_001DDF3C, 4");
extern f32 D_L01_001E1F18;
void func_L01_0038CC38(Moby_0038CC38 *moby) {
    extern f32 func_0038CED8(S_38C110v *);
    extern f32 func_0038D160(f32,f32);
    extern void func_0038D328(s128 *,S_38C110v *);
    extern void func_0038CE20(s128 *,s128 *,f32);
    extern void func_003D9740(s128 *,s32,u32,s32,s32,f32);
    s128 matrix[4];
    S_38C110v pos,vel,rot,offset;
    Vars_0038CC38 *vars;
    long state;
    if (moby != 0 && (state=moby->state) != 0xFE && state != 0xFD && moby->class_id == 0x1888) {
    pos=moby->position;
    vars=moby->vars;
    vel=vars->velocity;
    rot.x=0.0f;
    rot.y=-func_0038D160(func_0038CED8(&vel),vel.z) + -1.5707963705062866f;
    rot.z=func_0038D160(vel.x,vel.y);
    rot.w=1.0f;
    func_0038D328(matrix,&rot);
    offset=vars->velocity;
    func_0038CE20((s128 *)&offset,(s128 *)&offset,5.0f);
    vec_add_ab(&pos,&pos,&offset);
    *(S_38C110v *)&matrix[3]=pos;
    func_0038CE20(&matrix[0],&matrix[0],D_L01_001DDF48);
    func_0038CE20(&matrix[1],&matrix[1],D_L01_001DDF44);
    func_0038CE20(&matrix[2],&matrix[2],D_L01_001DDF40);
    D_L01_001E1F18 += 0.2f;
    if (D_L01_001E1F18 >= 7.0f) D_L01_001E1F18 -= 7.0f;
    func_003D9740(matrix,D_L01_001DDF3C,(vars->alpha * 3 << 24) | 0x008080FF,4,1,D_L01_001E1F18);
    }
}
/* localdecomp:end func_L01_0038CC38 */

/* localdecomp:start func_L01_0038CDC8 */
typedef struct {
    u8 pad_0[0x10];
    u8 position[0x10];
} Moby_38CDC8;

/* The warp's timer, set at the spawn from the last burst's 30 less its distance from the camera,
   kept within 15 to 30 (0x1E1F9C on NTSC-U) */
extern s32 D_L01_001E1F1C;
extern void func_L01_0038CE18(void *position, s32 texture, s32 alpha, f32 a, f32 b, f32 c, f32 d);

/* eruptor_warp: the screen warp while its timer runs, as the Shock Cannon's: texture 66 at
   5 x the timer; the four floats (1, 0, 0, 0.9) aren't read */
void func_L01_0038CDC8(Moby_38CDC8 *blast) {
    func_L01_0038CE18(blast->position, 0x42, D_L01_001E1F1C * 5, 1.0f, 0.0f, 0.0f, 0.9f);
}
/* localdecomp:end func_L01_0038CDC8 */

/* localdecomp:start func_L01_0038CE18 */
extern s32 D_001D5520;
extern s16 D_001CFEC0[];
extern s32 D_L01_001DDF50;
__asm__(".extern D_L01_001DDF50, 4");
extern s32 D_L01_001DDF54;
__asm__(".extern D_L01_001DDF54, 4");
extern s32 D_L01_001DDF58;
__asm__(".extern D_L01_001DDF58, 4");
extern s32 D_L01_001DDF5C;
__asm__(".extern D_L01_001DDF5C, 4");
extern s32 D_L01_001DDF60;
__asm__(".extern D_L01_001DDF60, 4");
extern s32 D_L01_001DDF64;
__asm__(".extern D_L01_001DDF64, 4");
extern s32 D_L01_001DDF68;
__asm__(".extern D_L01_001DDF68, 4");
extern s32 D_L01_001DDF6C;
__asm__(".extern D_L01_001DDF6C, 4");
extern s32 D_L01_001DDF70;
__asm__(".extern D_L01_001DDF70, 4");
extern s32 D_L01_001DDF74;
__asm__(".extern D_L01_001DDF74, 4");
extern s32 D_L01_001DDF78;
__asm__(".extern D_L01_001DDF78, 4");
extern s32 D_L01_001DDF7C;
__asm__(".extern D_L01_001DDF7C, 4");
extern s32 D_L01_001DDF80;
__asm__(".extern D_L01_001DDF80, 4");
extern s32 D_L01_001DDF84;
__asm__(".extern D_L01_001DDF84, 4");
extern s32 D_L01_001DDF88;
__asm__(".extern D_L01_001DDF88, 4");
extern void func_L01_004C5E28(void);
/* the file's earlier blocks declare it with a 32-bit value; these calls pass the full 64-bit GS register */
extern void func_003A9440(s32, unsigned long);
extern unsigned long func_00389598(s32 a);
extern void func_0038B4D0(s32 a, s32 b, s32 c, s32 d, s32 e, s32 f, s32 g, s32 h, long i, long j);

/* eruptor_warp_draw: the screen warp, texture 66 into the frame's alpha in four mirrored quarters, then the frame's copy mixed in */
void func_L01_0038CE18(void *position, s32 texture, s32 alpha, f32 a, f32 b, f32 c, f32 d) {
    long tex, col;

    func_L01_004C5E28();
    if (D_001D5520 != 0) {
        D_L01_001DDF88 = -1;
        D_L01_001DDF80 = 0xEC;
        D_L01_001DDF84 = 0xF0;
    }
    ((void (*)(s32, long))func_003A9440)(0x47, 0x513F1);
    ((void (*)(s32, long))func_003A9440)(0x42, ((long)D_L01_001DDF58 | ((long)D_L01_001DDF5C << 2) | ((long)D_L01_001DDF60 << 4) | ((long)D_L01_001DDF64 << 6)) | (0x8000L << 24));
    tex = func_00389598(D_L01_001DDF50);
    col = (s32)((alpha << 24) | 0x7F7F7F);
    func_0038B4D0(0, 0, (s32)((f32)D_001CFEC0[0xA8] * 0.5f), (s32)((f32)D_001CFEC0[0xA9] * 0.5f), 0, 0, 0xFF, 0xFF, col, tex);
    func_0038B4D0(D_001CFEC0[0xA8], 0, -(s32)((f32)D_001CFEC0[0xA8] * 0.5f), (s32)((f32)D_001CFEC0[0xA9] * 0.5f), 0, 0, 0xFF, 0xFF, col, tex);
    func_0038B4D0(0, D_001CFEC0[0xA9], (s32)((f32)D_001CFEC0[0xA8] * 0.5f), -(s32)((f32)D_001CFEC0[0xA9] * 0.5f), 0, 0, 0xFF, 0xFF, col, tex);
    func_0038B4D0(D_001CFEC0[0xA8], D_001CFEC0[0xA9], -(s32)((f32)D_001CFEC0[0xA8] * 0.5f), -(s32)((f32)D_001CFEC0[0xA9] * 0.5f), 0, 0, 0xFF, 0xFF, col, tex);
    ((void (*)(s32, long))func_003A9440)(0x42, ((long)D_L01_001DDF58 | ((long)D_L01_001DDF5C << 2) | ((long)D_L01_001DDF60 << 4) | ((long)D_L01_001DDF64 << 6)) | (0x8000L << 24));
    ((void (*)(s32, long))func_003A9440)(0x42, ((long)D_L01_001DDF68 | ((long)D_L01_001DDF6C << 2) | ((long)D_L01_001DDF70 << 4) | ((long)D_L01_001DDF74 << 6)) | (0x8000L << 24));
    func_0038B4D0(0, 0, D_001CFEC0[0xA8], D_001CFEC0[0xA9], D_L01_001DDF78, D_L01_001DDF7C, D_L01_001DDF80, D_L01_001DDF84, D_L01_001DDF54, func_00389598(D_L01_001DDF88));
}
/* localdecomp:end func_L01_0038CE18 */

/* localdecomp:start func_L01_0038D108 */
extern void func_L01_0038E720_0038D108(void *);
extern void func_L01_0038D108(void *);

extern void func_L01_0038E4D0_0038D108();
void func_L01_0038D108(void *p) {
    func_L01_0038E4D0_0038D108(p);
    func_L01_0038E720_0038D108(p);
}
/* localdecomp:end func_L01_0038D108 */

/* localdecomp:start func_L01_0038D138 */
extern void func_003A9440(s32, unsigned long);
extern void func_0038AF30(s32, s32, s32, s32, unsigned long);
extern s16 D_001CFEC0[];

void func_L01_0038D138(void) {
    func_003A9440(66, 72);
    func_0038AF30(0, D_001CFEC0[0xA9], 0, D_001CFEC0[0xA8], (s32)0x80808080);
}
/* localdecomp:end func_L01_0038D138 */

/* localdecomp:start func_L01_0038D180 */
#include "vu0.h"
typedef struct {
    vu0_v4 v[4]; u32 color[4]; f32 uv[4][2];
    u8 pad70[0x18]; unsigned long tag;
} Draw_0038D180;
typedef struct {
    Draw_0038D180 draw;
    vu0_v4 basis[3]; vu0_v4 pos; vu0_v4 delta; vu0_v4 matrix[3];
} Work_0038D180;
typedef int u128_0038D180 __attribute__((mode(TI)));
extern vu0_v4 D_L01_001E2A40;
extern vu0_v4 D_001A4EC0;
extern vu0_v4 D_L01_001D7C50[];
extern void func_003D93B0(void *, s32, s32, s32);
extern void func_0038CF68_0038D180(void *, void *, f32);
extern void func_0038CE90(void *, void *, void *);
extern void func_0038D308(void *, void *);
extern void func_0038D5F0(void *, void *, void *);
extern void func_0038CE20_0038D180(void *, void *, f32);
extern void func_0038D028(void *, void *, void *);
extern void func_003A9440(s32, unsigned long);
extern void func_003D2DA0(void *, s32, s32);
extern void func_00389478(void *, f32 *, f32 *);

void func_L01_0038D180(void *position, s32 texture, f32 size, f32 offset, f32 angle, f32 stretch) {
    Work_0038D180 w;
    s32 i;
    func_003D93B0(&w.draw, texture, 1, 0x80);
    w.draw.tag = 0x800000004A;
    w.draw.color[3] = 0x80808080;
    w.draw.color[2] = 0x80808080;
    w.draw.color[1] = 0x80808080;
    w.draw.color[0] = 0x80808080;
    *(u128_0038D180 *)&w.pos = *(u128_0038D180 *)position;
    w.draw.uv[0][0] = 0; w.draw.uv[0][1] = 0;
    w.draw.uv[1][0] = 0; w.draw.uv[1][1] = 1;
    w.draw.uv[2][0] = 1; w.draw.uv[2][1] = 0;
    w.draw.uv[3][0] = 1; w.draw.uv[3][1] = 1;
    vec_sub_ab(&w.basis[0], &D_L01_001E2A40, &w.pos);
    func_0038CF68_0038D180(&w.basis[0], &w.basis[0], 1.0f);
    func_0038CE90(&w.basis[1], &w.basis[0], &D_001A4EC0);
    func_0038CF68_0038D180(&w.basis[1], &w.basis[1], 1.0f);
    func_0038CE90(&w.basis[2], &w.basis[1], &w.basis[0]);
    if (angle != 0.0f) {
        *(u128_0038D180 *)&w.delta = 0;
        w.delta.x = angle;
        func_0038D308(w.matrix, &w.delta);
        func_0038D5F0(w.basis, w.basis, w.matrix);
    }
    func_0038CE20_0038D180(&w.delta, w.basis, offset);
    vec_add_ab(&w.pos, &w.pos, &w.delta);
    for (i = 0; i < 4; i++) {
        func_0038CE20_0038D180(&w.draw.v[i], &D_L01_001D7C50[i], size);
        func_0038D028(&w.draw.v[i], &w.draw.v[i], w.basis);
    }
    func_003A9440(0x47, 0x31001);
    func_003D2DA0(&w.draw, 0, 0);
    {
        s32 k;
        s32 j;
        *(u128_0038D180 *)&w.matrix[0] = *(u128_0038D180 *)&w.draw.v[0];
        for (k = 1; k < 4; k++) vec_add_ba(&w.matrix[0], &w.matrix[0], &w.draw.v[k]);
        func_0038CE20_0038D180(&w.matrix[0], &w.matrix[0], 0.25f);
        for (j = 0; j < 4; j++) {
            vec_sub_ab(&w.matrix[1], &w.draw.v[j], &w.matrix[0]);
            func_0038CE20_0038D180(&w.matrix[1], &w.matrix[1], stretch);
            vec_add_ab(&w.matrix[1], &w.matrix[0], &w.matrix[1]);
            func_00389478(&w.matrix[1], &w.draw.uv[j][0], &w.draw.uv[j][1]);
        }
    }
    func_003D93B0(&w.draw, -1, 1, 0x80);
    w.draw.tag = 0x2000000054;
    func_003A9440(0x47, 0x53001);
    func_003D2DA0(&w.draw, 0, 0);
    func_003A9440(0x47, 0x5360B);
}
/* localdecomp:end func_L01_0038D180 */

/* localdecomp:start func_L01_0038D498 */


extern void func_0038D328(s128 *, S_38C110v *);
extern void func_0038D640(s128 *, void *, s128 *);
extern void func_0038CE20(s128 *, s128 *, f32);
extern void func_L01_0038C9B0(s128 *, f32, f32, f32, s32, f32, s32, s32);

void func_L01_0038D498(S_38C110v *a0, void *a1, f32 f12, f32 f13, f32 f14, f32 f15, s32 a2, s32 a3, f32 f16, f32 f17) {
    S_38C110v v;
    s128 m1[4];
    s128 m2[4];

    v.x = 0.0f;
    v.y = 0.0f;
    v.z = f12;
    v.w = 1.0f;
    func_0038D328(m1, &v);
    func_0038D640(m2, a1, m1);
    func_0038CE20(&m2[0], &m2[0], f13);
    func_0038CE20(&m2[1], &m2[1], f13);
    func_0038CE20(&m2[2], &m2[2], f13);
    *(S_38C110v *)&m2[3] = *a0;
    func_L01_0038C9B0(m2, f17, f14, f15, a2, f16, a3, 1);
}
/* localdecomp:end func_L01_0038D498 */

/* localdecomp:start func_L01_0038D5C0 */
#include "vu0.h"
extern u8 *D_001A71A0[];
extern f32 D_L01_001E1F18;
extern f32 D_L01_001E1F24_0038D5C0;
__asm__(".extern D_L01_001E1F24_0038D5C0, 4");
extern f32 D_L01_001E1F34_0038D5C0;
__asm__(".extern D_L01_001E1F34_0038D5C0, 4");
extern f32 D_L01_001E1F40;
__asm__(".extern D_L01_001E1F40, 4");
extern f32 D_L01_001E1F44;
__asm__(".extern D_L01_001E1F44, 4");
extern f32 D_L01_001E1F48;
__asm__(".extern D_L01_001E1F48, 4");
extern f32 D_L01_001E1F20;
extern f32 D_L01_001DDF38;
__asm__(".extern D_L01_001DDF38, 4");
extern f32 D_L01_001DDF94;
__asm__(".extern D_L01_001DDF94, 4");
extern f32 D_L01_001DDF98;
__asm__(".extern D_L01_001DDF98, 4");
extern f32 D_L01_001DDF9C;
__asm__(".extern D_L01_001DDF9C, 4");
extern f32 D_L01_001DDFA0;
__asm__(".extern D_L01_001DDFA0, 4");
extern f32 D_L01_001DDFA4;
__asm__(".extern D_L01_001DDFA4, 4");
extern f32 D_L01_001DDFA8;
__asm__(".extern D_L01_001DDFA8, 4");
extern f32 D_L01_001E1F28;
__asm__(".extern D_L01_001E1F28, 4");
extern f32 D_L01_001E1F2C;
__asm__(".extern D_L01_001E1F2C, 4");
extern f32 D_L01_001E1F30;
__asm__(".extern D_L01_001E1F30, 4");
extern s32 D_L01_001DDF90;
__asm__(".extern D_L01_001DDF90, 4");
extern f32 D_L01_001E1F38;
extern f32 D_L01_001E1F3C;
extern f32 D_L01_001E1F4C;
extern s32 D_L01_001DDF8C;
__asm__(".extern D_L01_001DDF8C, 4");
typedef struct { u8 pad[40]; f32 size; s32 id; } State_38D5C0;
void func_L01_0038D5C0(u8 *object) {
    extern f32 func_003824E0(f32, f32);
    extern f32 func_0038DAB8(f32, f32);
    extern void func_003D9508(void *, s32, u32, s32, f32, f32, f32);
    extern f32 func_0038CED8(void *);
    extern f32 func_0038D160(f32, f32);
    extern void func_0038D328(s128 *, S_38C110v *);
    extern void func_L01_0040AAC8(void *, s32, s32, s32, f32, f32, f32, f32, f32, f32, s32);
    extern void func_L01_0038D180(void *, s32, f32, f32, f32, f32);
    extern void func_L01_0038D498(S_38C110v *, void *, f32, f32, f32, f32, s32, s32, f32, f32);
    s128 matrix[4];
    S_38C110v rotation;
    S_38C110v difference;
    State_38D5C0 *state = *(State_38D5C0 **)(object + 0x68);
    S_38C110v *position = (S_38C110v *)(object + 0x10);
    s32 color, color2;
    D_L01_001DDF94 = func_0038DAB8(D_L01_001DDF94, func_003824E0(-1.0f, -2.0f) * 0.01745329238474369f);
    D_L01_001DDFA0 = func_0038DAB8(D_L01_001DDFA0, func_003824E0(-2.0f, -4.0f) * 0.01745329238474369f);
    D_L01_001DDF98 = func_0038DAB8(D_L01_001DDF98, func_003824E0(-1.0f, -3.0f) * 0.01745329238474369f);
    D_L01_001DDFA4 = func_0038DAB8(D_L01_001DDFA4, func_003824E0(-3.0f, -5.0f) * 0.01745329238474369f);
    D_L01_001DDF9C = func_0038DAB8(D_L01_001DDF9C, func_003824E0(-1.0f, -3.0f) * 0.01745329238474369f);
    D_L01_001DDFA8 = func_0038DAB8(D_L01_001DDFA8, func_003824E0(-1.0f, -4.0f) * 0.01745329238474369f);
    func_003D9508(position, 0x49, 0x7F400505, 0, state->size * 1.2f, 0.01f, D_L01_001DDFA4);
    func_003D9508(position, 0x49, 0x7F200505, 0, state->size * 1.1f, 0.01f, -D_L01_001DDFA8);
    func_003D9508(position, 0x49, 0x7F400505, 0, state->size * 0.9f, 0.01f, D_L01_001DDFA0);
    func_003D9508(position, 0x49, 0x7F200505, 0, state->size, 0.01f, -D_L01_001DDFA0);
    func_003D9508(position, 0x4A, 0x7F400505, 0, state->size * 1.2f, 0.01f, -D_L01_001DDFA4);
    func_003D9508(position, 0x4A, 0x7F200505, 0, state->size * 1.1f, 0.01f, D_L01_001DDFA8);
    func_003D9508(position, 0x4A, 0x7F400505, 0, state->size * 0.9f, 0.01f, -D_L01_001DDFA0);
    func_003D9508(position, 0x4A, 0x7F200505, 0, state->size, 0.01f, D_L01_001DDFA0);
    func_L01_0040AAC8(position, 0x47, 0x48, 0x353200FF, state->size * 1.4f, 1.0f, 1.0f, D_L01_001DDF94, -D_L01_001DDFA0, 0.0f, 1);
    func_L01_0040AAC8(position, 0x47, 0x48, 0x35204080, state->size * 1.4f, 1.0f, 1.0f, -D_L01_001DDF98, D_L01_001DDFA4, 0.05f, 1);
    func_L01_0040AAC8(position, 0x47, 0x48, 0x3520207F, state->size * 1.4f, 1.0f, 1.0f, D_L01_001DDF9C, -D_L01_001DDFA8, 0.1f, 1);
    func_L01_0038D180(position, 0x36, state->size * 2.1f, 0.0f, D_L01_001DDFA4, 0.8f);
    func_L01_0038D180(position, 0x36, state->size * 2.1f, 0.0f, -D_L01_001DDFA4, 0.8f);
    vec_sub_ab(&difference, object + 0x10, D_001A71A0[0] + 0x10);
    rotation.x = 0.0f;
    rotation.y = func_0038D160(func_0038CED8(&difference), difference.z) + -0.3490658402442932f;
    rotation.z = func_0038D160(difference.x, difference.y);
    rotation.w = 1.0f;
    func_0038D328(matrix, &rotation);
    color = ((state->id * 6) << 24) | 0x204080;
    D_L01_001E1F20 = func_0038DAB8(D_L01_001E1F20, 0.296705961227417f);
    func_L01_0038D498(position, matrix, D_L01_001E1F20, state->size * 1.5f, 25.0f, 35.0f, D_L01_001DDF8C, color, D_L01_001E1F18, 180.0f);
    D_L01_001E1F24_0038D5C0 = func_0038DAB8(D_L01_001E1F24_0038D5C0, 0.3839724361896515f);
    func_L01_0038D498(position, matrix, D_L01_001E1F24_0038D5C0, state->size * 1.7f, 10.0f, 20.0f, D_L01_001DDF8C, color, D_L01_001E1F18, 180.0f);
    D_L01_001E1F28 = func_0038DAB8(D_L01_001E1F28, 0.4712388813495636f);
    func_L01_0038D498(position, matrix, D_L01_001E1F28, state->size + state->size, -2.0f, 7.0f, D_L01_001DDF8C, color, D_L01_001E1F18, 180.0f);
    D_L01_001E1F2C = func_0038DAB8(D_L01_001E1F2C, 0.5061454772949219f);
    func_L01_0038D498(position, matrix, D_L01_001E1F2C, state->size * 1.8f, -5.0f, -10.0f, D_L01_001DDF8C, color, D_L01_001E1F18, 180.0f);
    D_L01_001E1F30 = func_0038DAB8(D_L01_001E1F30, 0.45378559827804565f);
    func_L01_0038D498(position, matrix, D_L01_001E1F30, state->size * 1.7f, -12.0f, -18.0f, D_L01_001DDF8C, color, D_L01_001E1F18, 180.0f);
    D_L01_001E1F34_0038D5C0 = func_0038DAB8(D_L01_001E1F34_0038D5C0, 0.3839724361896515f);
    func_L01_0038D498(position, matrix, D_L01_001E1F34_0038D5C0, state->size * 1.5f, 5.0f, 15.0f, D_L01_001DDF8C, color, D_L01_001E1F18, 180.0f);
    color2 = ((state->id * 7) << 24) | 0x108080;
    D_L01_001E1F38 = func_0038DAB8(D_L01_001E1F38, 0.12217304855585098f);
    func_L01_0038D498(position, matrix, D_L01_001E1F38, state->size * 1.5f, 25.0f, 35.0f, D_L01_001DDF90, color2, D_L01_001E1F18, 90.0f);
    D_L01_001E1F3C = func_0038DAB8(D_L01_001E1F3C, 0.20943951606750488f);
    func_L01_0038D498(position, matrix, D_L01_001E1F3C, state->size * 1.7f, 10.0f, 20.0f, D_L01_001DDF90, color2, D_L01_001E1F18, 90.0f);
    D_L01_001E1F40 = func_0038DAB8(D_L01_001E1F40, 0.296705961227417f);
    func_L01_0038D498(position, matrix, D_L01_001E1F40, state->size + state->size, -2.0f, 7.0f, D_L01_001DDF90, color2, D_L01_001E1F18, 90.0f);
    D_L01_001E1F44 = func_0038DAB8(D_L01_001E1F44, 0.33161255717277527f);
    func_L01_0038D498(position, matrix, D_L01_001E1F44, state->size * 1.8f, -5.0f, -10.0f, D_L01_001DDF90, color2, D_L01_001E1F18, 90.0f);
    D_L01_001E1F48 = func_0038DAB8(D_L01_001E1F48, 0.27925267815589905f);
    func_L01_0038D498(position, matrix, D_L01_001E1F48, state->size * 1.7f, -12.0f, -18.0f, D_L01_001DDF90, color2, D_L01_001E1F18, 90.0f);
    D_L01_001E1F4C = func_0038DAB8(D_L01_001E1F4C, 0.20943951606750488f);
    func_L01_0038D498(position, matrix, D_L01_001E1F4C, state->size * 1.5f, 5.0f, 15.0f, D_L01_001DDF90, color2, D_L01_001E1F18, 90.0f);
}
/* localdecomp:end func_L01_0038D5C0 */

/* localdecomp:start func_L01_0038DF00 */
extern u8 *D_001A71A0[];
extern f32 D_L01_001E1F18;
extern f32 D_L01_001E1F20;
extern f32 D_L01_001E1F24;
extern f32 D_L01_001E1F34;
extern f32 D_L01_001DDF38;
__asm__(".extern D_L01_001DDF38, 4");
extern f32 D_L01_001DDF94;
__asm__(".extern D_L01_001DDF94, 4");
extern f32 D_L01_001DDF98;
__asm__(".extern D_L01_001DDF98, 4");
extern f32 D_L01_001DDF9C;
__asm__(".extern D_L01_001DDF9C, 4");
extern f32 D_L01_001DDFA0;
__asm__(".extern D_L01_001DDFA0, 4");
extern f32 D_L01_001DDFA4;
__asm__(".extern D_L01_001DDFA4, 4");
extern f32 D_L01_001DDFA8;
__asm__(".extern D_L01_001DDFA8, 4");
extern f32 D_L01_001E1F28;
__asm__(".extern D_L01_001E1F28, 4");
extern f32 D_L01_001E1F2C;
__asm__(".extern D_L01_001E1F2C, 4");
extern f32 D_L01_001E1F30;
__asm__(".extern D_L01_001E1F30, 4");
extern s32 D_L01_001DDF8C;
__asm__(".extern D_L01_001DDF8C, 4");
typedef struct { u8 pad[40]; f32 size; s32 id; } State_38DF00;
void func_L01_0038DF00(u8 *object) {
    extern f32 func_003824E0(f32, f32);
    extern f32 func_0038DAB8(f32, f32);
    extern void func_003D9508(void *, s32, u32, s32, f32, f32, f32);
    extern f32 func_0038CED8(void *);
    extern f32 func_0038D160(f32, f32);
    extern void func_0038D328(s128 *, S_38C110v *);
    extern void func_L01_0038D498_0038DF00(S_38C110v *, void *, f32, f32, f32, f32, s32, s32, f32, f32);
    s128 matrix[4];
    S_38C110v rotation;
    S_38C110v difference;
    State_38DF00 *state = *(State_38DF00 **)(object + 0x68);
    S_38C110v *position = (S_38C110v *)(object + 0x10);
    s32 color;
    D_L01_001DDF94 = func_0038DAB8(D_L01_001DDF94, func_003824E0(-1.0f, -2.0f) * 0.01745329238474369f);
    D_L01_001DDFA0 = func_0038DAB8(D_L01_001DDFA0, func_003824E0(-2.0f, -4.0f) * 0.01745329238474369f);
    D_L01_001DDF98 = func_0038DAB8(D_L01_001DDF98, func_003824E0(-1.0f, -3.0f) * 0.01745329238474369f);
    D_L01_001DDFA4 = func_0038DAB8(D_L01_001DDFA4, func_003824E0(-3.0f, -5.0f) * 0.01745329238474369f);
    D_L01_001DDF9C = func_0038DAB8(D_L01_001DDF9C, func_003824E0(-1.0f, -3.0f) * 0.01745329238474369f);
    D_L01_001DDFA8 = func_0038DAB8(D_L01_001DDFA8, func_003824E0(-1.0f, -4.0f) * 0.01745329238474369f);
    func_003D9508(position, 76, (state->id << 26) | 0x200505, 0, D_L01_001DDF38 * 1.2f, 0.01f, D_L01_001DDFA4);
    func_003D9508(position, 76, (state->id << 26) | 0xFF0032, 0, state->size * 0.5f, 0.01f, -D_L01_001DDFA0);
    func_003D9508(position, 76, (state->id << 26) | 0x300505, 0, state->size * 0.2f, 0.01f, D_L01_001DDFA0);
    func_003D9508(position, 75, 0x2F204080, 0, state->size * 0.6f, 0.01f, D_L01_001DDFA4);
    func_003D9508(position, 57, ((state->id * 7) << 24) | 0x2040FF, 1, state->size * 3.0f, 0.01f, D_L01_001DDF94);
    func_003D9508(position, 57, ((state->id * 7) << 24) | 0x2040FF, 1, state->size * 3.0f, 0.01f, D_L01_001DDF98);
    vec_sub_ab(&difference, position, D_001A71A0[0] + 0x10);
    rotation.x = 0.0f;
    rotation.y = func_0038D160(func_0038CED8(&difference), difference.z) + -0.3490658402442932f;
    rotation.z = func_0038D160(difference.x, difference.y);
    rotation.w = 1.0f;
    func_0038D328(matrix, &rotation);
    color = ((state->id * 6) << 24) | 0x204080;
    D_L01_001E1F20 = func_0038DAB8(D_L01_001E1F20, 0.296705961227417f);
    func_L01_0038D498_0038DF00(position, matrix, D_L01_001E1F20, (D_L01_001DDF38 * 1.5f) * 0.4f, 25.0f, 35.0f, D_L01_001DDF8C, color, D_L01_001E1F18, 180.0f);
    D_L01_001E1F24 = func_0038DAB8(D_L01_001E1F24, 0.3839724361896515f);
    func_L01_0038D498_0038DF00(position, matrix, D_L01_001E1F24, (D_L01_001DDF38 * 1.7f) * 0.4f, 10.0f, 20.0f, D_L01_001DDF8C, color, D_L01_001E1F18, 180.0f);
    D_L01_001E1F28 = func_0038DAB8(D_L01_001E1F28, 0.4712388813495636f);
    func_L01_0038D498_0038DF00(position, matrix, D_L01_001E1F28, (D_L01_001DDF38 + D_L01_001DDF38) * 0.4f, -2.0f, 7.0f, D_L01_001DDF8C, color, D_L01_001E1F18, 180.0f);
    D_L01_001E1F2C = func_0038DAB8(D_L01_001E1F2C, 0.5061454772949219f);
    func_L01_0038D498_0038DF00(position, matrix, D_L01_001E1F2C, (D_L01_001DDF38 * 1.8f) * 0.4f, -5.0f, -10.0f, D_L01_001DDF8C, color, D_L01_001E1F18, 180.0f);
    D_L01_001E1F30 = func_0038DAB8(D_L01_001E1F30, 0.45378559827804565f);
    func_L01_0038D498_0038DF00(position, matrix, D_L01_001E1F30, (D_L01_001DDF38 * 1.7f) * 0.4f, -12.0f, -18.0f, D_L01_001DDF8C, color, D_L01_001E1F18, 180.0f);
    D_L01_001E1F34 = func_0038DAB8(D_L01_001E1F34, 0.3839724361896515f);
    func_L01_0038D498_0038DF00(position, matrix, D_L01_001E1F34, (D_L01_001DDF38 * 1.5f) * 0.4f, 5.0f, 15.0f, D_L01_001DDF8C, color, D_L01_001E1F18, 180.0f);
}
/* localdecomp:end func_L01_0038DF00 */

LINKER_REMNANT("asm/levels", func_L01_0038E4C8);

/* localdecomp:start func_L01_0038E4D0 */
typedef struct {
    s128 vertices[4];
    s32 colors[4];
    f32 uv[4][2];
    unsigned long zero, texture, alpha, test;
} Packet_0038E4D0;
extern s32 D_L01_001DDFC0, D_L01_001DDFB0, D_L01_001DDFAC;
extern s32 D_L01_001DDFB4, D_L01_001DDFB8, D_L01_001DDFBC, D_L01_001DDFC4;
extern f32 D_L01_001DDF30;
__asm__(".extern D_L01_001DDFC0, 4");
__asm__(".extern D_L01_001DDFB0, 4");
__asm__(".extern D_L01_001DDFAC, 4");
__asm__(".extern D_L01_001DDFB4, 4");
__asm__(".extern D_L01_001DDFB8, 4");
__asm__(".extern D_L01_001DDFBC, 4");
__asm__(".extern D_L01_001DDFC4, 4");
__asm__(".extern D_L01_001DDF30, 4");
extern s16 D_L01_002B42E0[][8];
extern s128 D_L01_002B3DE0[];
extern f32 D_L01_002B46E0[][2];
extern f32 D_L01_002B46E4[][2];
typedef struct { u8 pad[0x25C0]; u8 *camera; } Scene_0038E4D0;
extern Scene_0038E4D0 D_001A4BE0;
__asm__(".extern D_001A4BE0, 16");
static __inline__ s128 *camera_0038E4D0(Scene_0038E4D0 *base) {
    return (s128 *)(base->camera + 0xC0);
}
void func_L01_0038E4D0(u8 *moby) {
    extern unsigned long func_00389598(s32);
    extern void func_003C5180(void *, void *, s32);
    extern void func_0038CE20(s128 *, s128 *, f32);
    extern void func_0038D000(s128 *, s128 *, s128 *);
    extern void func_003D2DA0(void *, s32, s32);
    Packet_0038E4D0 packet;
    s128 matrix[3];
    s128 offset;
    f32 *u, *v;
    u8 *p = *(u8 **)(moby + 0x68);
    s32 i, j, uv;
    packet.texture = func_00389598(D_L01_001DDFC0);
    packet.test = (unsigned long)D_L01_001DDFAC |
        ((unsigned long)D_L01_001DDFB0 << 2) |
        ((unsigned long)D_L01_001DDFB4 << 4) |
        ((unsigned long)D_L01_001DDFB8 << 6) |
        ((unsigned long)D_L01_001DDFBC << 32);
    packet.alpha = 0xFF9000000260UL;
    qzero(&matrix[0]);
    qzero(&matrix[1]);
    qzero(&matrix[2]);
    packet.zero = 0;
    ((f32 *)&matrix[0])[0] = *(f32 *)(p + 0x34) * 2.0f;
    ((f32 *)&matrix[1])[1] = *(f32 *)(p + 0x34) * 2.0f;
    ((f32 *)&matrix[2])[2] = *(f32 *)(p + 0x34) * 0.25f;
    packet.colors[3] = D_L01_001DDFC4 + (*(s32 *)(p + 0x30) << 24);
    packet.colors[2] = packet.colors[3];
    packet.colors[1] = packet.colors[3];
    packet.colors[0] = packet.colors[3];
    func_003C5180(p + 0x10, &offset, 1);
    func_0038CE20(&offset, &offset, 0.25f);
    u = &packet.uv[0][0];
    v = &packet.uv[0][1];
    for (i = 0; i < 64; i++) {
        f32 *vp = v, *up = u;
        s16 *entry = D_L01_002B42E0[i];
        s128 *vertex = packet.vertices;
        j = 3;
        do {
            uv = entry[1];
            func_0038CE20(vertex, &D_L01_002B3DE0[entry[0]], D_L01_001DDF30);
            j--;
            entry += 2;
            *up = D_L01_002B46E0[uv][0];
            *vp = D_L01_002B46E4[uv][0];
            up += 2;
            func_0038D000(vertex, vertex, matrix);
            vp += 2;
            func_0038D000(vertex, vertex, camera_0038E4D0(&D_001A4BE0));
            vec_add_ab(vertex, vertex, p + 0x10);
            vec_add_ab(vertex, vertex, &offset);
            vertex++;
        } while (j >= 0);
        func_003D2DA0(&packet, 0, 0);
    }
}
/* localdecomp:end func_L01_0038E4D0 */

/* localdecomp:start func_L01_0038E720 */
typedef struct {
    s128 vertices[4];
    s32 colors[4];
    f32 uv[4][2];
    unsigned long zero, texture, alpha, test;
} Packet_0038E720;
extern s32 D_L01_001DDFC0, D_L01_001DDFB0, D_L01_001DDFAC;
extern s32 D_L01_001DDFB4, D_L01_001DDFB8, D_L01_001DDFBC, D_L01_001DDFC4;
extern f32 D_L01_001DDF30;
__asm__(".extern D_L01_001DDFC0, 4");
__asm__(".extern D_L01_001DDFB0, 4");
__asm__(".extern D_L01_001DDFAC, 4");
__asm__(".extern D_L01_001DDFB4, 4");
__asm__(".extern D_L01_001DDFB8, 4");
__asm__(".extern D_L01_001DDFBC, 4");
__asm__(".extern D_L01_001DDFC4, 4");
__asm__(".extern D_L01_001DDF30, 4");
extern s16 D_L01_002B42E0[][8];
extern s128 D_L01_002B3DE0[];
extern f32 D_L01_002B46E0[][2];
extern f32 D_L01_002B46E4[][2];
typedef struct { u8 pad[0x25C0]; u8 *camera; } Scene_0038E720;
extern Scene_0038E720 D_001A4BE0_0038E720;
__asm__(".extern D_001A4BE0_0038E720, 16");
static __inline__ s128 *camera_0038E720(Scene_0038E720 *base) {
    return (s128 *)(base->camera + 0xC0);
}
void func_L01_0038E720(u8 *moby) {
    extern unsigned long func_00389598(s32);
    extern void func_003C5180(void *, void *, s32);
    extern void func_0038CE20(s128 *, s128 *, f32);
    extern void func_0038D000(s128 *, s128 *, s128 *);
    extern void func_003D2DA0(void *, s32, s32);
    Packet_0038E720 packet;
    s128 matrix[3];
    s128 offset;
    f32 *u, *v;
    u8 *p = *(u8 **)(moby + 0x68);
    s32 i, j, uv;
    packet.texture = func_00389598(D_L01_001DDFC0);
    packet.test = (unsigned long)D_L01_001DDFAC |
        ((unsigned long)D_L01_001DDFB0 << 2) |
        ((unsigned long)D_L01_001DDFB4 << 4) |
        ((unsigned long)D_L01_001DDFB8 << 6) |
        ((unsigned long)D_L01_001DDFBC << 32);
    packet.alpha = 0xFF9000000260UL;
    qzero(&matrix[0]);
    qzero(&matrix[1]);
    qzero(&matrix[2]);
    packet.zero = 0;
    ((f32 *)&matrix[0])[0] = *(f32 *)(p + 0x34);
    ((f32 *)&matrix[1])[1] = *(f32 *)(p + 0x34);
    ((f32 *)&matrix[2])[2] = *(f32 *)(p + 0x34) * 0.125f;
    packet.colors[3] = D_L01_001DDFC4 + (*(s32 *)(p + 0x30) << 24);
    packet.colors[2] = packet.colors[3];
    packet.colors[1] = packet.colors[3];
    packet.colors[0] = packet.colors[3];
    func_003C5180(p + 0x10, &offset, 1);
    func_0038CE20(&offset, &offset, 0.25f);
    u = &packet.uv[0][0];
    v = &packet.uv[0][1];
    for (i = 0; i < 64; i++) {
        f32 *vp = v, *up = u;
        s16 *entry = D_L01_002B42E0[i];
        s128 *vertex = packet.vertices;
        j = 3;
        do {
            uv = entry[1];
            func_0038CE20(vertex, &D_L01_002B3DE0[entry[0]], D_L01_001DDF30);
            j--;
            entry += 2;
            *up = D_L01_002B46E0[uv][0];
            *vp = D_L01_002B46E4[uv][0];
            up += 2;
            func_0038D000(vertex, vertex, matrix);
            vp += 2;
            func_0038D000(vertex, vertex, camera_0038E720(&D_001A4BE0_0038E720));
            vec_add_ab(vertex, vertex, p + 0x10);
            vec_add_ab(vertex, vertex, &offset);
            vertex++;
        } while (j >= 0);
        func_003D2DA0(&packet, 0, 0);
    }
}
/* localdecomp:end func_L01_0038E720 */

/* localdecomp:start func_L01_0038E968 */

extern S_2BEE10 D_L01_002BEDD0;
extern void func_L01_003006C0(S_2BEE10 *, u8 *, s32, s32);

void func_L01_0038E968(u8 *a0) {
    S_2BEE10 m = D_L01_002BEDD0;

    func_L01_003006C0(&m, a0 + 16, 0, 0);
}
/* localdecomp:end func_L01_0038E968 */

/* localdecomp:start func_L01_0038E9C8 */
#include "vu0.h"
extern s32 D_L01_0029EE50[];
extern u8 D_L01_0038EB80[];
void func_L01_0038E9C8(u8 *obj) {
    extern void func_L01_0038F3F8(u8 *);
    extern s32 func_0038CAD0(s32 *);
    extern f32 func_003824E0(f32, f32);
    extern u8 *func_L01_004660F8(void *, void *);
    extern void func_0038CF68(void *, void *, f32);
    extern void func_L01_00404A10_0038E9C8(void *, void *);
    vu0_v4 v;
    u8 *p;
    u8 *vars = *(u8 **)(obj + 0x68);
    s32 i;
    if (!obj[0x20]) {
        func_L01_0038F3F8(obj);
        obj[0x20] = 1;
        D_L01_0029EE50[0] = 4;
        *(f32 *)(vars + 4) = 0.5f;
    }
    if (!func_0038CAD0(D_L01_0029EE50) && !*(s32 *)(vars + 8)) {
        u8 *pos = obj + 0x10;
        for (i = 9; i >= 0; i--) {
            v.x = func_003824E0(-0.3f, 0.3f) * *(f32 *)(vars + 4);
            v.y = func_003824E0(-0.3f, 0.3f) * *(f32 *)(vars + 4);
            v.z = func_003824E0(-0.3f, 0.3f) * *(f32 *)(vars + 4);
            v.w = 0.0f;
            p = func_L01_004660F8(pos, &v);
            if (p) {
                u8 *q = p + 0x30;
                func_0038CF68(&v, &v, 1.0f);
                __asm__("lqc2 $vf1, %1\n\tlqc2 $vf2, %2\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0"
                    : "=m"(*(vu0_v4 *)(p + 0x10))
                    : "m"(*(vu0_v4 *)(obj + 0x10)), "m"(v) : "vf1", "vf2");
                *(vu0_q *)(p + 0x20) = *(vu0_q *)(obj + 0x10);
                *(f32 *)(q + 0xC) = 1.0f;
                *(f32 *)(p + 0x1C) = 0.05f;
                *(f32 *)(p + 0x2C) = 0.25f;
            }
        }
    }
    func_L01_00404A10_0038E9C8(D_L01_0038EB80, obj);
}
/* localdecomp:end func_L01_0038E9C8 */

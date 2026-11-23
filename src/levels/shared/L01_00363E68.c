#include "common.h"

INCLUDE_ASM("asm/levels", func_L01_00363E68);

INCLUDE_ASM("asm/levels", func_L01_00364180);

INCLUDE_ASM("asm/levels", func_L01_003649E8);

INCLUDE_ASM("asm/levels", func_L01_00364C20);

/* localdecomp:start func_L01_00365E28 */
typedef int s128_365E28 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_365E28;
typedef struct { f32 x, y, z; } V3_365E28;
typedef struct { f32 u, v; } Uv_365E28;
extern V3_365E28 D_L01_0028F1B0[];
extern s32 D_L01_0028F3A8[];
extern Uv_365E28 D_L01_0028F450[];
extern s32 func_003A9440(s32 a, unsigned long b);
extern s32 func_00389598(s32 a);
extern void func_0038C750(void);
extern f32 func_0038DB48(f32 a);
extern f32 func_0038D098(f32 a);
extern void func_00382760(V4_365E28 *v, f32 a, f32 b, f32 c);
extern void func_0038D028(void *a, void *b, void *c);
extern void func_003D3A24(s32 n, void *a, void *b, void *c, s32 d);

/* suck_arc_strip_draw: one Suck Cannon vortex arc: a strip of 21 pairs of points on a ball, drawn
   in an effect texture; the pair's two points sit at the two latitudes */
void func_L01_00365E28(s128_365E28 *matrix, f32 span, f32 from_lat, f32 to_lat, s32 texture, f32 unused_f, s32 colour, s32 added) {
    V4_365E28 v;
    V4_365E28 w;
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
        D_L01_0028F3A8[i] = colour;
        D_L01_0028F3A8[i + 1] = colour;
        D_L01_0028F450[i].u = u;
        D_L01_0028F450[i].v = 0.0f;
        D_L01_0028F450[i + 1].u = u;
        D_L01_0028F450[i + 1].v = 1.0f;
        func_00382760(&v, 1.0f, lon, from_lat * rad);
        v.w = 1.0f;
        func_0038D028(&w, &v, matrix);
        D_L01_0028F1B0[i].x = w.x;
        D_L01_0028F1B0[i].y = w.y;
        D_L01_0028F1B0[i].z = w.z;
        func_00382760(&v, 1.0f, lon, to_lat * rad);
        v.w = 1.0f;
        func_0038D028(&w, &v, matrix);
        D_L01_0028F1B0[i + 1].x = w.x;
        D_L01_0028F1B0[i + 1].y = w.y;
        D_L01_0028F1B0[i + 1].z = w.z;
    }
    func_003D3A24(0x2A, D_L01_0028F1B0, D_L01_0028F3A8, D_L01_0028F450, 1);
}
/* localdecomp:end func_L01_00365E28 */

/* localdecomp:start func_L01_003660B0 */
typedef int s128 __attribute__((mode(TI)));

typedef struct {
    f32 x;
    f32 y;
    f32 z;
    f32 w;
} __attribute__((aligned(16))) S_38C110v;

extern void func_0038D328(s128 *, S_38C110v *);
extern void func_0038D640(s128 *, void *, s128 *);
extern void func_0038CE20(s128 *, s128 *, f32);
extern void func_L01_00365E28(s128 *, f32, f32, f32, s32, f32, s32, s32);

void func_L01_003660B0(S_38C110v *a0, void *a1, s32 a2, s32 a3, f32 f12, f32 f13, f32 f14, f32 f15, f32 f16, f32 f17) {
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
    func_L01_00365E28(m2, f17, f14, f15, a2, f16, a3, 1);
}
/* localdecomp:end func_L01_003660B0 */

/* localdecomp:start func_L01_003661D8 */
extern s16 D_L01_001E1B10;
extern void func_L01_00364180();
extern void func_L01_00404808(void *, void *);
void func_L01_003661D8(void *a0) {
    s32 i;
    if (D_L01_001E1B10 > 0) {
        for (i = 0; i < 10; i++) {
            if ((&D_L01_001E1B10)[i] > 64) {
                (&D_L01_001E1B10)[i] = 64;
            }
            (&D_L01_001E1B10)[i] -= 8;
        }
        func_L01_00404808(func_L01_00364180, a0);
    }
}
/* localdecomp:end func_L01_003661D8 */

INCLUDE_ASM("asm/levels", func_L01_00366240);

LINKER_REMNANT("asm/levels", func_L01_003663F0);

INCLUDE_ASM("asm/levels", func_L01_00366400);

/* localdecomp:start func_L01_00366BE0 */
#include "vu0.h"
extern vu0_v4 D_L01_001E1C40_00366BE0[1] __attribute__((section(".sdata")));
extern vu0_v4 D_L01_001E1C50_00366BE0[1] __attribute__((section(".sdata")));
typedef struct { u8 pad0[0x80]; vu0_v4 v80; u8 pad1[0x25C0 - 0x90]; u8 *object; } State_00366BE0;
extern State_00366BE0 D_001A4BE0_00366BE0;
void func_L01_00366BE0(u8 *object) {
    extern void func_0038D308(void *, void *);
    extern void func_003C2EC0(void *, s32, void *);
    extern f32 func_0038CF00(void *, void *);
    vu0_v4 matrix[4];
    vu0_q a, b, c;
    func_0038D308(object + 0xC0, object + 0xF0);
    func_003C2EC0(object, 0, matrix);
    D_L01_001E1C40_00366BE0[0] = matrix[3];
    __asm__("lqc2 %0, %1" : "=j"(a) : "m"(matrix[1]));
    __asm__("vsub.xyz %0, vf0, %1" : "=j"(b) : "j"(a));
    __asm__("sqc2 %1, %0" : "=m"(D_L01_001E1C50_00366BE0[0]) : "j"(b));
    if (func_0038CF00(D_L01_001E1C40_00366BE0, &D_001A4BE0_00366BE0.v80) > 5.0f) {
        func_0038CE20((s128 *)D_L01_001E1C40_00366BE0, (s128 *)(D_001A4BE0_00366BE0.object + 0xE0), 1.5f);
        vec_add_ab(D_L01_001E1C40_00366BE0, D_L01_001E1C40_00366BE0, &D_001A4BE0_00366BE0.v80);
        D_L01_001E1C50_00366BE0[0] = *(vu0_v4 *)(D_001A4BE0_00366BE0.object + 0xC0);
    }
}
/* localdecomp:end func_L01_00366BE0 */

/* localdecomp:start func_L01_00366CD0 */
extern s128 D_001A4C60;
extern f32 D_L01_001E1C64;
extern s128 D_L01_001E1C30_00366CD0 __attribute__((section(".sdata")));
extern s128 D_L01_001E1C40 __attribute__((section(".sdata")));
extern s128 D_L01_001E1C50 __attribute__((section(".sdata")));
void func_L01_00366CD0(void) {
    extern void func_L01_004C7D98(s128 *, s128 *);
    extern void func_0038CDF8(s128 *, s128 *, s128 *, f32);
    s128 a, b;
    func_L01_004C7D98(&D_001A4C60, &a);
    func_0038CE20(&D_L01_001E1C30_00366CD0, &a, 0.5f);
    vec_add_ab(&D_L01_001E1C30_00366CD0, &D_L01_001E1C30_00366CD0, &D_001A4C60);
    if (D_L01_001E1C64 > 0.0f) {
        func_0038CDF8(&D_L01_001E1C30_00366CD0, &D_L01_001E1C30_00366CD0, &D_L01_001E1C40, D_L01_001E1C64 * 0.4f + 0.4f);
        func_0038CE20(&b, &D_L01_001E1C50, D_L01_001E1C64 * -0.55f);
        vec_add_ab(&D_L01_001E1C30_00366CD0, &b, &D_L01_001E1C30_00366CD0);
    } else {
        func_0038CDF8(&D_L01_001E1C30_00366CD0, &D_L01_001E1C30_00366CD0, &D_L01_001E1C40, 0.4f);
    }
}
/* localdecomp:end func_L01_00366CD0 */

/* localdecomp:start func_L01_00366DE0 */
extern s32 D_001A71A4[];
extern s32 D_L01_001E1C60;
extern f32 D_L01_001E1C64;

void func_L01_00366DE0(void) {
    s32 temp_v0;
    s32 temp_v0_2;

    if (D_001A71A4[0] == 1) {
        temp_v0 = D_L01_001E1C60 + 1;
        D_L01_001E1C60 = temp_v0;
        if (temp_v0 >= 0x22) {
            D_L01_001E1C60 = 0x21;
        }
    } else {
        temp_v0_2 = D_L01_001E1C60 - 1;
        D_L01_001E1C60 = temp_v0_2;
        if (temp_v0_2 < 0) {
            D_L01_001E1C60 = 0;
        }
    }
    D_L01_001E1C64 = (f32) D_L01_001E1C60 / 33.0f;
}
/* localdecomp:end func_L01_00366DE0 */

/* localdecomp:start func_L01_00366E48 */
extern void func_0038CB78(void *, s32, s32);
extern void func_L01_0043A430(s32, s32, void *);
void func_L01_00366E48(s32 a, s32 *b, s32 *c, void *buf, s32 e) {
    *b = 0;
    *c = 0;
    func_0038CB78(buf, 0, 64);
    func_L01_0043A430(a, e, buf);
}
/* localdecomp:end func_L01_00366E48 */

/* localdecomp:start func_L01_00366EA8 */
void func_L01_00366EA8(f32 *a, f32 *b, f32 *c, s32 index, s32 active) {
    extern f32 func_0038DAB8(f32, f32);
    extern f32 func_0038D0B0(f32);
    extern f32 func_0038D098(f32);
    if (active) {
        *a += 0.05400000512599945f;
        if (*a > 1.0f) *a = 1.0f;
    } else {
        if (*a < 0.1f) {
            *a += 0.012f;
            if (*a > 0.1f) *a = 0.1f;
        } else {
            *a -= 0.007200000341981649f;
            if (*a < 0.1f) *a = 0.1f;
        }
    }
    *b = func_0038DAB8(*b, *a * 0.37699115f);
    c[index + 4] = func_0038D0B0(*b * 0.5f);
    c[7] = func_0038D098(*b * 0.5f);
}
/* localdecomp:end func_L01_00366EA8 */

/* localdecomp:start func_L01_00366FC8 */
typedef struct {
    u8 pad[0x1200];
    u8 *p1200;
    u8 pad2[0x24];
    s32 mode1228;
} State_00366240;

extern State_00366240 D_001A4BE0;

s32 func_L01_00366FC8(void) {
    State_00366240 *s = &D_001A4BE0;
    if (s->mode1228 != 18 || s->p1200 == 0 || s->p1200[32] == 1 || s->p1200[32] == 5) {
        return 0;
    }
    return 1;
}
/* localdecomp:end func_L01_00366FC8 */

/* localdecomp:start func_L01_00367018 */
extern s128 D_L01_001E1C30[1] __attribute__((section(".sdata")));
extern f32 D_L01_001E1C28;
s32 func_L01_00367018(s128 *out, f32 *value) {
    extern s32 func_L01_00366FC8(void);
    if (!func_L01_00366FC8()) return 0;
    *out = D_L01_001E1C30[0];
    *value = D_L01_001E1C28;
    return 1;
}
/* localdecomp:end func_L01_00367018 */

LINKER_REMNANT("asm/levels", func_L01_00367078);

INCLUDE_ASM("asm/levels", func_L01_00367080);

INCLUDE_ASM("asm/levels", func_L01_00367260);

/* localdecomp:start func_L01_00367430 */
extern s32 D_L01_001E1C24;
extern s32 D_L01_001E1CD4;
extern s32 D_L01_001DFB40;
extern f32 D_L01_001E1C20;
extern s32 D_L01_001E1CD0;
extern s32 D_001D545C;
extern f32 D_L01_002B3870[];
void func_L01_00367430(s32 a, f32 amount) {
    if (amount <= 0.0f && a != D_L01_001E1C24) return;
    if (amount < D_L01_001E1C20 && D_L01_001E1CD4 == D_L01_001DFB40) return;
    D_L01_001E1C24 = a;
    D_L01_001E1CD0 = 8;
    D_L01_001E1CD4 = D_L01_001DFB40;
    D_L01_001E1C20 = amount;
    if (amount > 2.0f) {
        if (D_001D545C == 16) D_L01_002B3870[5] = 0.08f;
        else D_L01_002B3870[5] = (amount - 2.0f) * 0.05f + 0.08f;
        if (D_L01_002B3870[5] > 1.0f) D_L01_002B3870[5] = 1.0f;
        D_L01_002B3870[6] = 0.08f / D_L01_002B3870[5];
        D_L01_002B3870[7] = 0.55f;
    } else {
        D_L01_002B3870[5] = 0.08f;
        D_L01_002B3870[7] = 0.0f;
    }
}
/* localdecomp:end func_L01_00367430 */

LINKER_REMNANT("asm/levels", func_L01_00367580);

/* localdecomp:start func_L01_00367590 */
#include "vu0.h"

extern s32 D_001D545C;
extern s32 D_L01_001E1CE0;
extern s32 D_L01_001E1CF0;
extern f32 func_0038CF00(void *, void *);
extern void func_0038CF68(void *, void *, f32);

void func_L01_00367590(void) {
    f32 lim = 40.0f;
    f32 v[4];

    if (D_001D545C == 11) {
        lim = 80.0f;
    }
    if (lim <= func_0038CF00(&D_L01_001E1CE0, &D_L01_001E1CF0)) {
        vec_sub_ab(v, &D_L01_001E1CF0, &D_L01_001E1CE0);
        func_0038CF68(v, v, D_001D545C == 11 ? 80.0f : 40.0f);
        vec_add_ab(&D_L01_001E1CF0, &D_L01_001E1CE0, v);
    }
}
/* localdecomp:end func_L01_00367590 */

/* localdecomp:start func_L01_00367658 */
extern f32 D_L01_001E1C70;

s32 func_L01_00367658(void) {
    s32 var_v0;

    var_v0 = 0;
    if (!(D_L01_001E1C70 < 1.0f)) {
        var_v0 = 1;
    }
    return var_v0;
}
/* localdecomp:end func_L01_00367658 */

/* localdecomp:start func_L01_00367688 */
#include "vu0.h"
typedef struct { u8 p0[0x10]; s32 x10; } Obj24_00367688;
typedef struct { u8 p0[0x24]; Obj24_00367688 *p24; u8 p28[0x70]; s32 x98; } Hero_00367688;
typedef struct { u8 pad[0x25C0]; Hero_00367688 *hero; } State_00367688;
extern State_00367688 D_001A4BE0_00367688;
extern s32 D_001D545C;
extern vu0_q D_L01_001EAA20_00367688;
extern void func_0038CE20(s128 *, s128 *, f32);
extern void func_L01_0040BE10_00367688(void *, void *);
extern void func_003C7C38(void *);
extern void func_L01_003F3740_00367688(s32);
extern void func_L01_003F3768_00367688(s32);
extern s32 func_003D3CB0(void *, void *, s32, void *, s32);

void func_L01_00367688(vu0_q *from, vu0_q *dir, vu0_q *out) {
    vu0_q pos;
    f32 distance = 40.0f;
    if (D_001D545C == 11) distance = 80.0f;
    func_0038CE20((s128 *)&pos, (s128 *)dir, distance);
    vec_add_ab(&pos, &pos, from);
    func_L01_0040BE10_00367688(from, &pos);
    D_001A4BE0_00367688.hero->x98 = 0;
    func_003C7C38(D_001A4BE0_00367688.hero);
    func_L01_003F3740_00367688(0);
    if (func_003D3CB0(from, &pos, 0, 0, 0)) *out = D_L01_001EAA20_00367688;
    else *out = pos;
    D_001A4BE0_00367688.hero->x98 = D_001A4BE0_00367688.hero->p24->x10;
    func_003C7C38(D_001A4BE0_00367688.hero);
    func_L01_003F3768_00367688(0);
}
/* localdecomp:end func_L01_00367688 */

/* localdecomp:start func_L01_00367780 */
extern f32 D_L01_002B3870_00367780[];
extern s32 D_L01_001E1CD0_00367780;
extern s32 D_L01_001E1C24_00367780;
extern f32 D_L01_001E1C20_00367780;
extern s32 D_L01_001DFB40_00367780;
#include "vu0.h"
typedef struct Moby_367780_00367780 {
    u8 pad0[0x24];
    struct { u8 pad[0x46]; u8 x46; } *p24;
    u8 pad28[0x34 - 0x28];
    u16 flags34;
    u8 pad36[0x68 - 0x36];
    s32 *p68;
    u8 pad6C[0xAA - 0x6C];
    s16 oclass;
    u8 padAC[0xB8 - 0xAC];
    struct Moby_367780_00367780 *pB8;
    u8 padBC[0x100 - 0xBC];
} Moby_367780_00367780;
typedef struct {
    u8 pad[0x25C0];
    struct Obj_367780_00367780 *p25C0;
    s32 x25C4;
} State_367780_00367780;
typedef struct Obj_367780_00367780 {
    u8 pad0[0x24];
    struct { u8 pad[0x10]; s32 x10; } *p24;
    u8 pad28[0x98 - 0x28];
    s32 x98;
} Obj_367780_00367780;
typedef struct {
    void (*f0)(void *, void *);
    void (*f4)(void *, void *, s32);
} Cls1860_367780_00367780;
typedef struct {
    Moby_367780_00367780 *(*f0)(void *, void *);
    s32 (*f4)(void *, void *, void *);
} Cls_367780_00367780;
typedef struct {
    u8 pad0[0x18];
    Moby_367780_00367780 *m18;
    u8 pad1C[4];
    vu0_v4 v20;
} Target_367780_00367780;
typedef struct {
    u8 pad0[0x18];
    Moby_367780_00367780 *m18;
    s16 x1C;
} Link_367780_00367780;
typedef struct {
    s128 v;
    u8 pad10[8];
    u8 x18;
    s16 x1A;
    u8 pad1C[0x14];
} Hit_367780_00367780;
extern Moby_367780_00367780 *D_L01_001E1CC4_00367780;
extern vu0_v4 D_L01_001E1C40_00367780[1] __attribute__((section(".sdata")));
typedef struct {
    vu0_v4 pos;
    vu0_v4 v;
    s32 state;
    s32 timer;
} Cam_367780_00367780;
extern Cam_367780_00367780 D_L01_001E1CE0_00367780 __attribute__((section(".sdata")));
extern vu0_v4 D_L01_001E1C50_00367780[1] __attribute__((section(".sdata")));
extern u8 D_L01_001E29C0_00367780[];
extern Target_367780_00367780 D_L01_001EAA00_00367780;
extern Moby_367780_00367780 *D_L01_001E001C_00367780;
extern Moby_367780_00367780 *D_L01_001E1CC8_00367780;
extern s32 D_L01_001E1CCC_00367780;
extern u8 D_0014275B[];
extern f32 D_L01_002F1510_00367780[];
extern f32 D_L01_001DAA30_00367780;
extern Cls1860_367780_00367780 *func_L01_0043B568_00367780(s32, s32, s32);
extern Cls_367780_00367780 *func_L01_0043B548_00367780(s32, s32);
extern void func_L01_00367688_00367780(void *, void *, void *);
extern void func_0038CF68(void *, void *, f32);
extern void func_L01_0040BE10_00367780(void *, void *);
extern void func_003C7C38(void *);
extern void func_L01_003F3740_00367780(s32);
extern void func_L01_003F3768_00367780(s32);
extern void func_L01_00367590_00367780(void);
extern s32 func_003D3CB0(void *, void *, s32, void *, s32);
extern s32 func_L01_0041A4F0_00367780(void);
extern void func_0038CE90(void *, void *, void *);
extern f32 func_L01_00443A18_00367780(f32, f32);
extern void func_L01_00446760_00367780(void *, void *, s32, void *, f32);
extern s32 func_003D4D00(void *, s32, f32, s32, void *);
extern s32 func_003C4B50(void *);
extern Link_367780_00367780 *func_00382348(void *);
extern s32 func_L01_004AAC98_00367780(s32, s32, void *, s32);
extern s32 func_0038CAD0(void *);

void func_L01_00367780(Moby_367780_00367780 *a0) {
    Moby_367780_00367780 *m;
    Moby_367780_00367780 *hit;
    Cls_367780_00367780 *c;
    Cls1860_367780_00367780 *c2;
    vu0_v4 tmp;
    s32 i;

    if (D_L01_001E1CC4_00367780 != 0) {
        func_L01_0043B568_00367780(0x1860, 0, 8)->f4(D_L01_001E1CC4_00367780, a0, 0);
        D_L01_001E1CC4_00367780 = 0;
    }
    if (D_L01_001E1C20_00367780 > 0.0f && func_L01_00367658_00367780()) {
        D_L01_001E1CE0_00367780.pos = D_L01_001E1C40_00367780[0];
        if (((State_367780_00367780 *)&D_001A4BE0)->x25C4 == 1) {
            func_L01_00367688_00367780(D_L01_001E29C0_00367780, D_L01_001E29C0_00367780 + 0x20, &D_L01_001E1CE0_00367780.v);
            vec_sub_ba(&tmp, &D_L01_001E1CE0_00367780.v, &D_L01_001E1CE0_00367780.pos);
            func_0038CF68(&tmp, &tmp, 1.0f);
            vec_add_ab(&D_L01_001E1CE0_00367780.v, &D_L01_001E1CE0_00367780.v, &tmp);
        } else {
            func_0038CF68(&D_L01_001E1CE0_00367780.v, D_L01_001E1C50_00367780, D_001D545C == 11 ? 80.0f : 40.0f);
            vec_add_ab(&D_L01_001E1CE0_00367780.v, &D_L01_001E1CE0_00367780.v, &D_L01_001E1CE0_00367780.pos);
        }
        func_L01_0040BE10_00367780(&D_L01_001E1CE0_00367780.pos, &D_L01_001E1CE0_00367780.v);
        ((State_367780_00367780 *)&D_001A4BE0)->p25C0->x98 = 0;
        func_003C7C38(((State_367780_00367780 *)&D_001A4BE0)->p25C0);
        func_L01_003F3740_00367780(0);
        func_L01_00367590_00367780();
        if (func_003D3CB0(&D_L01_001E1CE0_00367780.pos, &D_L01_001E1CE0_00367780.v, 0, ((State_367780_00367780 *)&D_001A4BE0)->p25C0, 0)) {
            vu0_v4 *tv = &D_L01_001EAA00_00367780.v20;
            D_L01_001E1CE0_00367780.v = *tv;
            if (D_L01_001EAA00_00367780.m18 != 0) {
                if (D_L01_001EAA00_00367780.m18->oclass == 0x1751) {
                    Moby_367780_00367780 *o = (Moby_367780_00367780 *)D_L01_001EAA00_00367780.m18->p68[0x12C / 4];
                    if (o != 0) D_L01_001EAA00_00367780.m18 = o;
                }
                if (D_L01_001EAA00_00367780.m18->oclass == 0x1BA8) {
                    i = D_L01_001EAA00_00367780.m18->p68[0];
                    if (i != -1) D_L01_001EAA00_00367780.m18 = &D_L01_001E001C_00367780[i];
                }
                if (D_L01_001EAA00_00367780.m18->oclass == 0x1860 && D_L01_001E1C24_00367780 != 0
                    && ((Moby_367780_00367780 *)D_L01_001E1C24_00367780)->oclass == 0x11C1) {
                    c = func_L01_0043B548_00367780(0x11C1, 8);
                    hit = c->f0((void *)D_L01_001E1C24_00367780, D_L01_001EAA00_00367780.m18);
                    if (hit != 0) {
                        c2 = (Cls1860_367780_00367780 *)func_L01_0043B548_00367780(0x1860, 8);
                        c2->f0(hit, &tmp);
                        if (c->f4(&D_L01_001E1CE0_00367780.pos, &tmp, &tmp)) {
                            D_L01_001E1CE0_00367780.v = tmp;
                            c2->f0(hit, &D_L01_001E1CE0_00367780.v);
                            D_L01_001E1CC4_00367780 = hit;
                            if (hit->pB8 != 0 && hit->pB8->oclass == 0x1751) {
                                func_L01_0043B568_00367780(0x1860, 0, 8)->f4(hit, a0, 1);
                            }
                        }
                    }
                } else {
                    vu0_v4 v10;
                    vu0_v4 v20;
                    Hit_367780_00367780 h;
                    Link_367780_00367780 *p;
                    f32 k;
                    s32 ok;

                    m = D_L01_001EAA00_00367780.m18;
                    if (m->oclass != 0x185F && m->oclass != 0x1B92 && (m->flags34 & 0x4000)) {
                        func_0038CE20((s128 *)&v20, (s128 *)D_L01_001E1C50_00367780, D_L01_002B3870_00367780[5] * 0.5f);
                        vec_add_ab(&v20, &v20, &D_L01_001E1CE0_00367780.v);
                        if (func_L01_0041A4F0_00367780()) {
                            if (D_001D545C != 7 || D_0014275B[0] == 0) {
                                k = D_L01_001E1C20_00367780 * D_L01_002F1510_00367780[D_001D545C];
                            } else {
                                k = D_L01_001E1C20_00367780 * D_L01_001DAA30_00367780;
                            }
                        } else {
                            k = D_L01_001E1C20_00367780;
                        }
                        ok = 1;
                        qzero(&tmp);
                        tmp.z = 1.0f;
                        func_0038CE90(&v10, D_L01_001E1C50_00367780, &tmp);
                        func_0038CE20((s128 *)&v10, (s128 *)&v10, func_L01_00443A18_00367780(0.15f, 0.3f));
                        func_L01_00446760_00367780(&h, a0, 0x210000, &v10, k);
                        h.x18 = 9;
                        h.x1A = a0->oclass;
                        func_003D4D00(&v20, 0, D_L01_002B3870_00367780[5] * 1.2f, 0, &h);
                        if (func_L01_0043B548_00367780(0x11C1, 8) == 0) {
                            ok = 0;
                        } else if (func_003C4B50(m) || (m->p24 != 0 && m->p24->x46 == 0x16)
                                   || (p = func_00382348(m)) == 0) {
                            if (m == D_L01_001E1CC8_00367780 && D_L01_001DFB40_00367780 - D_L01_001E1CCC_00367780 <= 0x31) ok = 0;
                        } else if (p->m18 == a0 && p->x1C <= 0x30) {
                            ok = 0;
                        }
                        if (ok) {
                            D_L01_001E1CC8_00367780 = m;
                            D_L01_001E1CCC_00367780 = D_L01_001DFB40_00367780;
                            func_L01_004AAC98_00367780(2, 0, a0, 0x1937);
                        }
                    }
                }
            }
        }
        ((State_367780_00367780 *)&D_001A4BE0)->p25C0->x98 = ((State_367780_00367780 *)&D_001A4BE0)->p25C0->p24->x10;
        func_003C7C38(((State_367780_00367780 *)&D_001A4BE0)->p25C0);
        func_L01_003F3768_00367780(0);
        if (D_L01_001E1CE0_00367780.state != 1) {
            if (D_L01_001E1CE0_00367780.state == 2) D_L01_001E1CE0_00367780.timer = 0;
            else D_L01_001E1CE0_00367780.timer = D_L01_001DFB40_00367780;
            D_L01_001E1CE0_00367780.state = 1;
        }
    } else if (D_L01_001E1CE0_00367780.state != 0) {
        D_L01_001E1CE0_00367780.pos = D_L01_001E1C40_00367780[0];
        func_0038CF68(&D_L01_001E1CE0_00367780.v, D_L01_001E1C50_00367780, D_001D545C == 11 ? 80.0f : 40.0f);
        vec_add_ab(&D_L01_001E1CE0_00367780.v, &D_L01_001E1CE0_00367780.v, &D_L01_001E1CE0_00367780.pos);
        func_L01_0040BE10_00367780(&D_L01_001E1CE0_00367780.pos, &D_L01_001E1CE0_00367780.v);
        func_L01_00367590_00367780();
        if (func_003D3CB0(&D_L01_001E1CE0_00367780.pos, &D_L01_001E1CE0_00367780.v, 0, ((State_367780_00367780 *)&D_001A4BE0)->p25C0, 0)) {
            vu0_v4 *tv = &D_L01_001EAA00_00367780.v20;
            D_L01_001E1CE0_00367780.v = *tv;
        }
        if (D_L01_001E1CE0_00367780.state == 1) {
            D_L01_001E1CE0_00367780.state = 2;
            D_L01_001E1CE0_00367780.timer = D_L01_001DFB40_00367780;
        }
    }
    if (func_0038CAD0(&D_L01_001E1CD0_00367780)) D_L01_001E1C20_00367780 = 0.0f;
    D_L01_001E1C24_00367780 = 0;
}
/* localdecomp:end func_L01_00367780 */

INCLUDE_ASM("asm/levels", func_L01_00367EE0);

INCLUDE_ASM("asm/levels", func_L01_00368478);

INCLUDE_ASM("asm/levels", func_L01_003687C8);

INCLUDE_ASM("asm/levels", func_L01_00368B30);

LINKER_REMNANT("asm/levels", func_L01_003691D0);

/* localdecomp:start func_L01_003691D8 */
typedef struct { u8 pad0[0x24]; f32 scale; } Class_003691D8;
typedef struct {
 u8 pad0[0x10]; s128 pos; u8 state; u8 pad21[3]; Class_003691D8 *cls;
 u8 pad28[4]; f32 scale; u8 pad30[4]; u16 flags;
 u8 pad36[0x62]; s32 data; u8 pad9C[0x24]; s128 rot[3]; f32 angles[4];
} Moby_003691D8;
extern s128 D_L01_001E2A40[];
void func_L01_003691D8(Moby_003691D8 *m) {
 extern void func_L01_003693F8(void *);
 extern s32 func_0038DC20(void *,f32);
 extern f32 func_0038DAB8(f32,f32);
 extern void func_0038D308(void *,void *);
 extern void func_L01_00404A10_003691D8(void *,void *);
 extern f32 func_L01_0040E548(void *,void *);
 extern void func_L01_004AA7E8(void *,s32);
 extern void func_L01_003303B8(void *,s32,s32,s32,s32,s32,s32,s32,f32,f32,f32,f32,s32,s32,s32,s32,s32,s32,s32,s32,s32,s32,s32,s32,s32,s32,s32,s32,s32,s32);
 S_38C110v v;
 if(m->flags & 0x80) return;
 switch(m->state) {
 case 3: break;
 case 1:
  *(s128 *)&v=m->pos;
  v.w=m->scale/m->cls->scale/1.5f*1.4f;
  if(func_0038DC20(&v,40.0f)==-1) return;
  m->angles[2]=func_0038DAB8(m->angles[2],0.03141593f);
  func_0038D308(m->rot,m->angles);
  func_L01_00404A10_003691D8(func_L01_003693F8,m);
  break;
 case 2:
  if(func_L01_0040E548(D_L01_001E2A40,&m->pos)<1600.0f) {
   func_L01_003303B8(&m->pos,0,25,20,20,20,0,0,0.2f,0.0f,0.0f,2.0f,
    1,1,1,0,0,1,0,0,0xF78E38,0xF76300,0xFF7F40,0xFF2000,0xFF8F00,0xFF6430,0x7FFFA060,0x28FF0000,0xFF6430,0);
  }
  m->data=0;
  m->state=3;
  m->flags=(m->flags|0x41)&0xEFFF;
  func_L01_004AA7E8(m,1);
  break;
 }
}
/* localdecomp:end func_L01_003691D8 */

LINKER_REMNANT("asm/levels", func_L01_003693E8);

INCLUDE_ASM("asm/levels", func_L01_003693F8);

INCLUDE_ASM("asm/levels", func_L01_00369700);

/* localdecomp:start func_L01_00369C48 */
#include "vu0.h"
typedef int Q_00369C48 __attribute__((mode(TI)));
void func_L01_00369C48(vu0_v4 *pos) {
    extern f32 func_00382538(void);
    extern f32 func_003824E0(f32, f32);
    extern f32 func_0038D098(f32);
    extern f32 func_0038D0B0(f32);
    extern s32 func_00382498(s32, s32);
    extern u8 *func_L01_0046B288(void *, s32, s32, f32, f32, s32);
    vu0_v4 v;
    s32 i;
    f32 angle, radius, a, b;
    s32 n;
    u8 *p;
    for (i=0; i>=0; i--) {
        angle=func_00382538();
        radius=func_003824E0(0.0f,0.6f);
        a=func_003824E0(0.0f,1.2f);
        b=func_003824E0(1.0f,4.0f);
        n=func_00382498(70,130);
        v.x=func_0038D098(angle)*radius;
        v.y=func_0038D0B0(angle)*radius;
        v.z=0.0f;
        {
            Q_00369C48 qa, qb, qr;
            __asm__("lqc2 %0, %1" : "=j"(qa) : "m"(*pos));
            __asm__("lqc2 %0, %1" : "=j"(qb) : "m"(v));
            __asm__("vadd.xyz %0, %1, %2" : "=j"(qr) : "j"(qb), "j"(qa));
            __asm__("sqc2 %1, %0" : "=m"(v) : "j"(qr));
        }
        p=func_L01_0046B288(&v,0x5005B182,0x5B182,a,b,n);
        if(p) p[3]=68;
    }
}
/* localdecomp:end func_L01_00369C48 */

/* localdecomp:start func_L01_00369D80 */
typedef struct {
    u8 pad[0x1C];
    s32 f1C;
} S_00369D80_1C;

typedef struct {
    u8 pad[0x68];
    S_00369D80_1C *f68;
    u8 pad2[0x4C];
    s32 fB8;
} S_00369D80;

extern s32 func_00382498(s32, s32);
extern void *func_L01_003E0058(void *, void *, s32);

void func_L01_00369D80(S_00369D80 *a0, void *a1, void *a2) {
    S_00369D80_1C *p;
    void *r;
    s32 x;

    p = a0->f68;
    x = func_00382498(15, 45);
    p->f1C = (x * 5 + 2) / 6;
    func_0038CE20(a2, a2, 0.2f);
    r = func_L01_003E0058(a1, a2, 0);
    if (r != 0) {
        ((S_00369D80 *)r)->fB8 = a0->fB8;
    }
}
/* localdecomp:end func_L01_00369D80 */

INCLUDE_ASM("asm/levels", func_L01_00369E28);

/* localdecomp:start func_L01_0036AA60 */
#include "vu0.h"
typedef struct {
    u8 p0[0x10]; s128 pos; u8 state; u8 p21[15];
    u8 opacity; u8 mode; u16 distance; u16 flags; u8 p36[0x32];
    void *data;
} Moby_0036AA60;
typedef struct {
    s128 pos; u8 p10[0x10]; s128 velocity; s32 p30;
    s32 arg; s32 time; f32 step; u8 p40[0x10]; s128 target; f32 value;
} Data_0036AA60;
Moby_0036AA60 *func_L01_0036AA60(s128 *a, s128 *b, s128 *c, s32 arg, f32 value) {
    extern Moby_0036AA60 *func_003C24B0(s32, s32);
    extern void func_0038CF68(void *, void *, f32);
    extern void func_L01_0036B440(void *);
    s128 v;
    s128 *position;
    Moby_0036AA60 *m;
    Data_0036AA60 *d;
    m = func_003C24B0(0x1862, 0x80);
    if (m) {
        d = m->data;
        position = &m->pos;
        m->opacity = 255;
        m->state = 0;
        m->distance = 255;
        m->mode = 1;
        m->flags |= 0x41;
        func_0038CF68(&d->velocity, b, 0.16000001f);
        d->pos = *a;
        m->pos = *c;
        func_0038CF68(&v, &d->velocity, -1.5f);
        vec_add_ab(&d->target, a, &v);
        d->value = value;
        d->arg = arg;
        d->step = 0.083333336f;
        d->time = 12;
        func_L01_0036B440(position);
    }
    return m;
}

/* localdecomp:end func_L01_0036AA60 */

INCLUDE_ASM("asm/levels", func_L01_0036AB88);

INCLUDE_ASM("asm/levels", func_L01_0036B078);

INCLUDE_ASM("asm/levels", func_L01_0036B440);

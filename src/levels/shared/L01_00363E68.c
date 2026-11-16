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
extern void func_0038D098(f32 a);
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

INCLUDE_ASM("asm/levels", func_L01_00366BE0);

INCLUDE_ASM("asm/levels", func_L01_00366CD0);

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

INCLUDE_ASM("asm/levels", func_L01_00366EA8);

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

INCLUDE_ASM("asm/levels", func_L01_00367018);

LINKER_REMNANT("asm/levels", func_L01_00367078);

INCLUDE_ASM("asm/levels", func_L01_00367080);

INCLUDE_ASM("asm/levels", func_L01_00367260);

INCLUDE_ASM("asm/levels", func_L01_00367430);

LINKER_REMNANT("asm/levels", func_L01_00367580);

INCLUDE_ASM("asm/levels", func_L01_00367590);

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

INCLUDE_ASM("asm/levels", func_L01_00367688);

INCLUDE_ASM("asm/levels", func_L01_00367780);

INCLUDE_ASM("asm/levels", func_L01_00367EE0);

INCLUDE_ASM("asm/levels", func_L01_00368478);

INCLUDE_ASM("asm/levels", func_L01_003687C8);

INCLUDE_ASM("asm/levels", func_L01_00368B30);

LINKER_REMNANT("asm/levels", func_L01_003691D0);

INCLUDE_ASM("asm/levels", func_L01_003691D8);

LINKER_REMNANT("asm/levels", func_L01_003693E8);

INCLUDE_ASM("asm/levels", func_L01_003693F8);

INCLUDE_ASM("asm/levels", func_L01_00369700);

INCLUDE_ASM("asm/levels", func_L01_00369C48);

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

INCLUDE_ASM("asm/levels", func_L01_0036AA60);

INCLUDE_ASM("asm/levels", func_L01_0036AB88);

INCLUDE_ASM("asm/levels", func_L01_0036B078);

INCLUDE_ASM("asm/levels", func_L01_0036B440);

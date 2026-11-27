#include "common.h"

/* localdecomp:start func_L01_00363E68 */
#include "vu0.h"
typedef struct {
    vu0_v4 v[4]; u32 color[4]; f32 uv[4][2];
    u8 pad70[0x18]; unsigned long tag;
} Draw_00363E68;
typedef struct {
    Draw_00363E68 draw;
    vu0_v4 basis[3]; vu0_v4 pos; vu0_v4 delta; vu0_v4 matrix[3];
} Work_00363E68;
typedef int u128_00363E68 __attribute__((mode(TI)));
extern u128_00363E68 D_L01_001E2A40_00363E68[];
extern vu0_v4 D_001A4EC0;
extern vu0_v4 D_L01_001D7C50[];
extern void func_003D93B0(void *, s32, s32, s32);
extern void func_0038CF68_00376178(void *, void *, f32);
extern void func_0038CE90(void *, void *, void *);
extern void func_0038D308(void *, void *);
extern void func_0038D5F0(void *, void *, void *);
extern void func_0038CE20_00363E68(u128_00363E68 *, u128_00363E68 *, f32);
extern void func_0038D028(void *, void *, void *);
extern s32 func_003A9440(s32, unsigned long);
extern void func_003D2DA0(void *, s32, s32);
extern void func_00389478(void *, f32 *, f32 *);

void func_L01_00363E68(void *position, s32 texture, f32 size, f32 offset, f32 angle, f32 stretch) {
    Work_00363E68 w;
    s32 i;
    func_003D93B0(&w.draw, texture, 1, 0x80);
    w.draw.tag = 0x800000004A;
    w.draw.color[3] = 0x80808080;
    w.draw.color[2] = 0x80808080;
    w.draw.color[1] = 0x80808080;
    w.draw.color[0] = 0x80808080;
    *(u128_00363E68 *)&w.pos = *(u128_00363E68 *)position;
    w.draw.uv[0][0] = 0; w.draw.uv[0][1] = 0;
    w.draw.uv[1][0] = 0; w.draw.uv[1][1] = 1;
    w.draw.uv[2][0] = 1; w.draw.uv[2][1] = 0;
    w.draw.uv[3][0] = 1; w.draw.uv[3][1] = 1;
    vec_sub_ab(&w.basis[0], D_L01_001E2A40_00363E68, &w.pos);
    func_0038CF68_00376178(&w.basis[0], &w.basis[0], 1.0f);
    func_0038CE90(&w.basis[1], &w.basis[0], &D_001A4EC0);
    func_0038CF68_00376178(&w.basis[1], &w.basis[1], 1.0f);
    func_0038CE90(&w.basis[2], &w.basis[1], &w.basis[0]);
    if (angle != 0.0f) {
        *(u128_00363E68 *)&w.delta = 0;
        w.delta.x = angle;
        func_0038D308(w.matrix, &w.delta);
        func_0038D5F0(w.basis, w.basis, w.matrix);
    }
    func_0038CE20_00363E68((u128_00363E68 *)&w.delta, (u128_00363E68 *)w.basis, offset);
    vec_add_ab(&w.pos, &w.pos, &w.delta);
    for (i = 0; i < 4; i++) {
        func_0038CE20_00363E68((u128_00363E68 *)&w.draw.v[i], (u128_00363E68 *)&D_L01_001D7C50[i], size);
        func_0038D028(&w.draw.v[i], &w.draw.v[i], w.basis);
    }
    func_003A9440(0x47, 0x31001);
    func_003D2DA0(&w.draw, 0, 0);
    {
        s32 k;
        s32 j;
        *(u128_00363E68 *)&w.matrix[0] = *(u128_00363E68 *)&w.draw.v[0];
        for (k = 1; k < 4; k++) vec_add_ba(&w.matrix[0], &w.matrix[0], &w.draw.v[k]);
        func_0038CE20_00363E68((u128_00363E68 *)&w.matrix[0], (u128_00363E68 *)&w.matrix[0], 0.25f);
        for (j = 0; j < 4; j++) {
            vec_sub_ab(&w.matrix[1], &w.draw.v[j], &w.matrix[0]);
            func_0038CE20_00363E68((u128_00363E68 *)&w.matrix[1], (u128_00363E68 *)&w.matrix[1], stretch);
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
/* localdecomp:end func_L01_00363E68 */

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
/* GetEffectTex returns the whole 64-bit TEX0, but this caller was compiled against a 32-bit
   declaration: a long one moves the register allocation of the two table addresses below. The
   value still reaches func_003A9440 whole in $v0; a native build must keep all 64 bits itself. */
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

/* localdecomp:start func_L01_00366240 */
#include "vu0.h"
typedef struct {
    s16 idx;
    s16 pad2;
    f32 len;
    u8 pad8[4];
    s32 flag;
    u8 pad10[12];
    u8 *obj;
} Rope_00366240;
extern f32 D_L01_001DD784;
extern s32 D_L01_001DD778;
extern s32 D_L01_001DD7DC;
extern s32 D_L01_001DD774;
extern Rope_00366240 D_L01_0028CAA0[];
extern vu0_v4 D_L01_0028E390[];
__asm__(".extern D_L01_001DD784, 4");
__asm__(".extern D_L01_001DD778, 4");
__asm__(".extern D_L01_001DD774, 4");
__asm__(".extern D_L01_001DD7DC, 4");
void func_L01_00366240(void *arg) {
    extern f32 func_0038CEA8(void *);
    extern void func_0038CF68_00366240(void *, void *, f32);
    extern void func_0038CE20(s128 *, s128 *, f32);
    extern void func_L01_003661D8(void *);
    vu0_v4 a, b, c;
    s32 i;
    u8 *obj;
    f32 length;
    D_L01_001DD784 *= 0.5f;
    D_L01_001DD7DC = 0;
    D_L01_001DD774 = 1;
    D_L01_001DD778 = 1;
    for (i = 0; i < 200; i++) {
        obj = D_L01_0028CAA0[i].obj;
        if (obj != 0) {
            D_L01_0028CAA0[i].obj = 0;
            vec_sub_ba(&a, &D_L01_0028E390[D_L01_0028CAA0[i].idx], &D_L01_0028E390[D_L01_0028CAA0[i].idx + 1]);
            length = func_0038CEA8(&a);
            func_0038CE20((s128 *)&a, (s128 *)&a, D_L01_0028CAA0[i].len / length);
            vec_add_ba(&b, &D_L01_0028E390[D_L01_0028CAA0[i].idx + 1], &a);
            vec_sub_ba(&c, obj + 0x10, &b);
            func_0038CF68_00366240(&c, &c, 0.03f);
            func_0038CE20((s128 *)&a, (s128 *)&a, 0.1f / length);
            vec_add_ab(obj + 0x30, &c, &a);
            if (D_L01_0028CAA0[i].flag != 0) *(s16 *)(obj + 0xA) = 10;
            else *(s16 *)(obj + 0xA) = 70;
            D_L01_0028CAA0[i].flag = 0;
        }
    }
    func_L01_003661D8(arg);
}
/* localdecomp:end func_L01_00366240 */

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

/* localdecomp:start func_L01_00367080 */
#include "vu0.h"
static __inline__ void sub_00367080(s128 *d, s128 *a, s128 *b) {
    vec_sub_ba(d, a, b);
}
static __inline__ void add_00367080(s128 *d, s128 *a, s128 *b) {
    vec_add_ab(d, a, b);
}
s32 func_L01_00367080(s128 *a0, s128 *a1, s128 *out0, s128 *out1) {
    extern s32 func_L01_00367018(s128 *, f32 *);
    extern void func_L01_00446630(s128 *, s128 *, s128 *, s128 *);
    extern f32 func_L01_0040E548_00367080(s128 *, s128 *);
    extern f32 func_0038D0C8(f32);
    extern f32 func_0038D098(f32);
    extern void func_0038CF68_00367080(s128 *, s128 *, f32);
    extern f32 func_0038CE68(s128 *, s128 *);
    struct { s128 plane, direction, center; f32 radius; } local;
    f32 distance, half, lo, hi, middle;
    s32 flags;
    if (!func_L01_00367018(&local.plane, &local.radius)) return 0;
    local.radius += -0.07f;
    func_L01_00446630(&local.center, a0, a1, &local.plane);
    distance = func_L01_0040E548_00367080(&local.center, &local.plane);
    if (distance > local.radius) return 0;
    half = func_0038D098(func_0038D0C8(distance / local.radius)) * local.radius;
    flags = 0;
    sub_00367080(&local.direction, a1, a0);
    func_0038CF68_00367080(&local.direction, &local.direction, 1.0f);
    lo = func_0038CE68(&local.direction, a0);
    hi = func_0038CE68(&local.direction, a1);
    middle = func_0038CE68(&local.direction, &local.center);
    if (lo < middle - half) {
        func_0038CE20(out0, &local.direction, -half);
        flags = 1;
        add_00367080(out0, out0, &local.center);
    }
    if (middle + half < hi) {
        func_0038CE20(out1, &local.direction, half);
        add_00367080(out1, out1, &local.center);
        if ((flags ^ 1) & 1) *out0 = *out1;
        flags |= 2;
    }
    return flags;
}
/* localdecomp:end func_L01_00367080 */

/* localdecomp:start func_L01_00367260 */
#include "vu0.h"
extern s32 D_L01_001E1B60[] __attribute__((section(".sdata")));
extern s32 D_L01_001E1B70[] __attribute__((section(".sdata")));
extern s32 D_L01_001E1B80[] __attribute__((section(".sdata")));
extern vu0_v4 D_L01_001E1B90[] __attribute__((section(".sdata")));
extern vu0_v4 D_L01_001E1BD0[] __attribute__((section(".sdata")));
extern s32 D_L01_001E1C10[] __attribute__((section(".sdata")));
void func_L01_00367260(s32 object, s32 key, s32 enabled, vu0_v4 *start, vu0_v4 *end, s32 kind) {
    extern void func_0038CF68_00367260(void *, void *, f32);
    s32 i;
    if (enabled == 0) {
        for (i = 0; i < 4; i++) {
            if (object == D_L01_001E1B60[i]) D_L01_001E1B80[i] = 0;
        }
        return;
    }
    for (i = 0; i < 4; i++) {
        if (object == D_L01_001E1B60[i] && key == D_L01_001E1B70[i]) {
            D_L01_001E1B60[i] = object;
            D_L01_001E1B70[i] = key;
            D_L01_001E1B80[i] = enabled;
            D_L01_001E1C10[i] = kind;
            D_L01_001E1B90[i] = *end;
            vec_sub_ab(&D_L01_001E1BD0[i], end, start);
            func_0038CF68_00367260(&D_L01_001E1BD0[i], &D_L01_001E1BD0[i], 1.0f);
            return;
        }
    }
    for (i = 0; i < 4; i++) {
        if (D_L01_001E1B80[i] == 0) {
            D_L01_001E1B60[i] = object;
            D_L01_001E1B70[i] = key;
            D_L01_001E1B80[i] = enabled;
            D_L01_001E1C10[i] = kind;
            D_L01_001E1B90[i] = *end;
            vec_sub_ab(&D_L01_001E1BD0[i], end, start);
            func_0038CF68_00367260(&D_L01_001E1BD0[i], &D_L01_001E1BD0[i], 1.0f);
            return;
        }
    }
}
/* localdecomp:end func_L01_00367260 */

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

/* localdecomp:start func_L01_00367EE0 */
extern s32 D_L01_001E1D00;
extern f32 D_L01_001E1C64;
extern f32 D_L01_001E1C70;
extern f32 D_L01_001E1C68;
extern f32 D_L01_001E1C20;
void func_L01_00367EE0(void *m) {
 extern void func_L01_0043A800(void *,s32,S_38C110v *);
 extern void func_0038CE20(s128 *,s128 *,f32);
 extern f32 func_003824E0(f32,f32);
 extern s32 func_0038DBD8(s32,s32,f32);
 extern void func_L01_00470150(void *,void *,u32,s32,s32,f32,f32,s32,s32,s32,f32,s32,s32);
 S_38C110v point;
 S_38C110v ground;
 s32 color;
 s32 mode;
 func_L01_0043A800(m,0,&point);
 point.y-=0.2f;
 mode=D_L01_001E1D00;
 if(mode==1) {
  f32 amount=D_L01_001E1C70;
  if(D_L01_001E1C64>0.0f) {
   func_0038CE20((s128 *)&ground,&D_L01_001E1C50,0.75f);
   __asm__("lqc2 $vf1,%1\n\tlqc2 $vf2,%2\n\tvadd.xyz $vf1,$vf1,$vf2\n\tsqc2 $vf1,%0" : "=m"(*(S_38C110v *)&ground) : "m"(*(S_38C110v *)&ground),"i"(&D_L01_001E1C40) : "vf1","vf2","memory");
   amount=D_L01_001E1C70;
  }
  if(amount<1.0f) {
   s32 mask=0xFFFFFF;
   color=((s32)(amount*64.0f)<<24)+0xFF2020;
   if(D_L01_001E1C64<1.0f)
    func_L01_00470150(&point,m,color,-1,1,func_003824E0(1.0f,1.0375f)*0.5625f*210000.0f,0.5f,2,5,-1,1.0f,mode,0);
   if(D_L01_001E1C64>0.0f) {
    color=(color & mask)+((s32)((f32)(s32)((u32)color>>24)*D_L01_001E1C64)<<24);
    func_L01_00470150(&ground,0,color,-1,1,func_003824E0(1.0f,1.0375f)*1.125f*210000.0f,0.0f,2,0,-1,1.0f,mode,0);
   }
  } else {
   if(D_L01_001E1C64<1.0f)
    func_L01_00470150(&point,m,0x60FF2020,-1,1,func_003824E0(1.0f,1.0375f)*0.5625f*210000.0f,0.5f,2,5,-1,1.0f,mode,0);
   if(D_L01_001E1C64>0.0f) {
    color=((s32)(D_L01_001E1C64*96.0f)<<24)+0xFF2020;
    func_L01_00470150(&ground,0,color,-1,1,func_003824E0(1.0f,1.0375f)*1.125f*210000.0f,0.0f,2,0,-1,1.0f,mode,0);
   }
   if(D_L01_001E1C64<1.0f)
    func_L01_00470150(&point,m,0x50FF4050,-1,0,func_003824E0(1.0f,1.0375f)*0.5625f*210000.0f,0.5f,2,5,-1,1.0f,0,0);
   if(D_L01_001E1C64>0.0f) {
    color=((s32)(D_L01_001E1C64*80.0f)<<24)+0xFF4050;
    func_L01_00470150(&ground,0,color,-1,0,func_003824E0(1.0f,1.0375f)*1.8f*210000.0f,0.0f,2,0,-1,1.0f,mode,0);
   }
  }
 }
 if(D_L01_001E1C68>1.0f) {
  color=0x28FF2020;
  if(D_L01_001E1C20>0.0f) color=0x38D020FF;
  if(D_L01_001E1C68<14.0f) color=func_0038DBD8(color&-16777216,color,D_L01_001E1C68/14.0f);
  point.y-=0.3f;
  func_L01_00470150(&point,m,color,-1,1,(func_003824E0(1.0f,1.0375f)+D_L01_001E1C64*0.25f)*0.61875f*210000.0f,0.0f,2,0,-1,1.0f,1,0);
 }
}
/* localdecomp:end func_L01_00367EE0 */

/* localdecomp:start func_L01_00368478 */
#include "vu0.h"
extern s32 D_L01_001DFB40;
extern f32 D_L01_001E1C28;
void func_L01_00368478(u8 *data) {
    extern f32 func_L01_0040F518(f32,f32);
    extern f32 func_0038D0B0(f32);
    extern s32 func_0038DBD8(s32,s32,f32);
    extern f32 func_0038CED8(void *);
    extern f32 func_0038D160(f32,f32);
    extern f32 func_0038DB48(f32);
    extern void func_003D9740(void *,s32,f32,s32,s32,s32);
    S_38C110v angles, delta;
    s128 out[4], basis[4], spin[4];
    s32 color;
    f32 progress, phase;
    color=func_0038DBD8(*(s32 *)(data+8),*(s32 *)(data+12),
          (func_0038D0B0(func_L01_0040F518((f32)D_L01_001DFB40,112.83333587646484f)/112.83333587646484f*6.2831855f)+1.0f)*0.5f);
    progress=func_L01_0040F518((f32)D_L01_001DFB40,(*(f32 *)(data+4)*60.0f*5.0f+2.0f)/6.0f)/
             ((*(f32 *)(data+4)*60.0f*5.0f+2.0f)/6.0f);
    phase=func_L01_0040F518((f32)D_L01_001DFB40,(*(f32 *)(data+4)*60.0f*10.0f*5.0f+2.0f)/6.0f)/
          ((*(f32 *)(data+4)*60.0f*10.0f*5.0f+2.0f)/6.0f)*6.2831855f;
    vec_sub_ba(&delta, (S_38C110v *)(data+0x30), (S_38C110v *)(data+0x20));
    angles.x=0.0f;
    angles.y=-func_0038D160(func_0038CED8(&delta),delta.z)+1.5707964f;
    angles.z=func_0038D160(delta.x,delta.y);
    angles.w=1.0f;
    func_0038D328(basis,&angles);
    qzero(&angles);
    angles.z=func_0038DB48(phase);
    func_0038D328(spin,&angles);
    func_0038D640(out,basis,spin);
    out[3]=*(s128 *)(data+0x20);
    func_0038CE20(&out[0],&out[0],D_L01_001E1C28);
    func_0038CE20(&out[1],&out[1],D_L01_001E1C28);
    func_0038CE20(&out[2],&out[2],D_L01_001E1C28);
    func_003D9740(out,*(s32 *)data,progress,color,*(s32 *)(data+0x10),1);
    progress+=0.5f;
    angles.z=func_0038DB48(-phase);
    func_0038D328(spin,&angles);
    func_0038D640(out,basis,spin);
    out[3]=*(s128 *)(data+0x20);
    func_0038CE20(&out[0],&out[0],D_L01_001E1C28);
    func_0038CE20(&out[1],&out[1],D_L01_001E1C28);
    func_0038CE20(&out[2],&out[2],D_L01_001E1C28);
    func_003D9740(out,*(s32 *)data,progress,color,*(s32 *)(data+0x10),1);
}
/* localdecomp:end func_L01_00368478 */

/* localdecomp:start func_L01_003687C8 */
#include "vu0.h"
typedef struct {
    s32 mode;
    f32 width;
    u32 color0, color1;
    s32 count;
    u8 pad[12];
    vu0_v4 origin, target;
} Params_003687C8;
extern s32 D_L01_001E1B80_003687C8[] __attribute__((section(".sdata")));
extern s32 D_L01_001E1C10_003687C8[] __attribute__((section(".sdata")));
extern vu0_v4 D_L01_001E1B90_003687C8[] __attribute__((section(".sdata")));
extern vu0_v4 D_L01_001E1BD0_003687C8[] __attribute__((section(".sdata")));
extern f32 D_L01_001E1C28_003687C8;
extern f32 D_L01_001E1C64;
__asm__(".extern D_L01_001E1C28_003687C8, 4");
void func_L01_003687C8(s32 unused, vu0_v4 *origin) {
    extern s32 func_0038DBD8(s32, s32, f32);
    extern void func_L01_00368478_003687C8(Params_003687C8 *);
    extern void func_0038CE20(s128 *, s128 *, f32);
    extern void func_L01_00446630_003687C8(vu0_v4 *, vu0_v4 *, vu0_v4 *, vu0_v4 *);
    vu0_v4 a, b, c;
    Params_003687C8 p;
    s32 i;
    s32 *flags = D_L01_001E1B80_003687C8;
    s32 *colors = D_L01_001E1C10_003687C8;
    p.origin = *origin;
    for (i = 0; i < 4; i++) {
        if (flags[i] == 0) continue;
        switch (flags[i]) {
        case 1: case 2: case 3:
            p.mode = 23;
            p.width = 0.25f;
            if (colors[i] != -1) {
                p.color0 = colors[i];
                p.color1 = func_0038DBD8(colors[i] & 0xFFFFFF, 0, 0.25f) + (colors[i] & 0xFF000000);
            } else {
                p.color0 = 0x306020FF;
                p.color1 = 0x304820E0;
            }
            if (D_L01_001E1C64 > 0.0f) {
                p.color0 -= (s32)(D_L01_001E1C64 * 16.0f) << 24;
                p.color1 = (p.color1 & 0xFFFFFF) + (p.color0 & 0xFF000000);
            }
            p.count = 6;
            break;
        case 4: case 5: case 6:
            p.mode = 47;
            p.width = 0.3f;
            if (colors[i] != -1) {
                p.color0 = colors[i];
                p.color1 = func_0038DBD8(colors[i] & 0xFFFFFF, 0, 0.25f) + (colors[i] & 0xFF000000);
            } else {
                p.color0 = 0x68F02060;
                p.color1 = 0x68802040;
            }
            if (D_L01_001E1C64 > 0.0f) {
                p.color0 -= (s32)(D_L01_001E1C64 * 32.0f) << 24;
                p.color1 = (p.color1 & 0xFFFFFF) + (p.color0 & 0xFF000000);
            }
            p.count = 4;
            break;
        }
        p.target = D_L01_001E1B90_003687C8[i];
        if (flags[i] != 3 && flags[i] != 6) {
            func_L01_00368478_003687C8(&p);
        }
        switch (flags[i]) {
        case 2: case 3:
            p.count -= 3;
            break;
        case 5: case 6:
            p.count -= 1;
            break;
        default:
            continue;
        }
        if (flags[i] != 3 && flags[i] != 6) {
            vu0_v4 *pos = &D_L01_001E1B90_003687C8[i];
            func_0038CE20((s128 *)&a, (s128 *)&D_L01_001E1BD0_003687C8[i], D_L01_001E1C28_003687C8);
            vec_add_ba(&a, &a, pos);
            func_L01_00446630_003687C8(&b, pos, &a, origin);
            vec_sub_ab(&c, &b, pos);
            vec_add_ab(&p.target, &b, &c);
        }
        p.color0 += 0x20000000;
        p.width = -p.width;
        p.color1 += 0x20000000;
        func_L01_00368478_003687C8(&p);
    }
}
/* localdecomp:end func_L01_003687C8 */

/* localdecomp:start func_L01_00368B30 */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_368B30;
typedef struct {
    V4_368B30 pos[4];
    u32 rgba[4];
    f32 uv[4][2];
    unsigned long count;
    unsigned long tex;
    unsigned long tex0;
    unsigned long alpha;
} Quad_368B30;
typedef struct { u8 pad0[0x150]; s16 x150; s16 x152; } S_001CFEC0_368B30;
extern s128 D_001A4C60;
extern S_001CFEC0_368B30 D_001CFEC0;
extern s32 D_L01_001DFB40;
extern f32 D_L01_001E1C28_00368B30;
extern V4_368B30 D_L01_001E1C40_00368B30 __attribute__((section(".sdata")));
extern V4_368B30 D_L01_001E1C50_00368B30 __attribute__((section(".sdata")));
extern f32 D_L01_001E1C64;
extern f32 D_L01_001E1C68;
extern s32 D_L01_001E1CC0;
extern s32 D_L01_001E1CE0;
extern s32 D_L01_001E1CF0;
extern s32 D_L01_001E1D00;
extern f32 D_L01_002B3870[];
extern V4_368B30 D_L01_001E2A40_00368B30;

void func_L01_00368B30(u8 *obj) {
    extern void func_L01_004C7D98(void *, void *);
    extern f32 func_L01_0040F518(f32, f32);
    extern f32 func_0038D0B0(f32);
    extern s32 func_0038DBD8(s32, s32, f32);
    extern void func_0038CE90(void *, void *, void *);
    extern void func_0038CF68(void *, void *, f32);
    extern void func_0038CE20(s128 *, s128 *, f32);
    extern void func_003D9740(void *, s32, f32, s32, s32, s32);
    extern void func_L01_0040B858(void *, void *);
    extern void func_003A9440_00368B30(s32, unsigned long);
    extern f32 func_00382538(void);
    extern void func_003D9508(void *, s32, u32, s32, f32, f32, f32);
    extern void func_0038AF30(s32, s32, s32, s32, long);
    extern void func_003C5180(void *, void *, s32);
    extern void func_003D93B0(void *, s32, s32, s32);
    extern void func_003D2DA0(void *, s32, s32);
    V4_368B30 p0;
    V4_368B30 pts[4];
    V4_368B30 b;
    V4_368B30 a;
    Quad_368B30 q;
    V4_368B30 d;
    V4_368B30 e;
    V4_368B30 f;
    V4_368B30 g;
    V4_368B30 h;
    V4_368B30 k;
    f32 pulse;
    f32 phase;
    f32 t;
    s32 color;
    s32 n;
    s32 c0;
    s32 c1;

    func_L01_004C7D98(&D_001A4C60, &p0);
    n = D_L01_001E1C68;
    pulse = func_L01_0040F518((f32)D_L01_001DFB40, 150.33333f) / 150.33333f;
    pulse = (func_0038D0B0(pulse * 6.2831855f) + 1.0f) * 0.5f;
    color = func_0038DBD8(0x38B43264, 0x38801028, pulse);
    phase = func_L01_0040F518((f32)D_L01_001DFB40, 19.083334f) / 19.083334f;
    if (D_L01_001E1C64 > 0.0f) {
        color -= (s32)(D_L01_001E1C64 * 24.0f) << 24;
    }
    pts[2] = D_L01_001E1C50_00368B30;
    func_0038CE90(&pts[1], &p0, &D_L01_001E1C50_00368B30);
    func_0038CF68(&pts[1], &pts[1], 1.0f);
    func_0038CE90(&pts[0], &D_L01_001E1C50_00368B30, &pts[1]);
    pts[3] = *(V4_368B30 *)D_L01_001E1C30;
    func_0038CE20(&pts[0], &pts[0], D_L01_001E1C28_00368B30);
    func_0038CE20(&pts[1], &pts[1], D_L01_001E1C28_00368B30);
    func_0038CE20(&pts[2], &pts[2], D_L01_001E1C28_00368B30);
    func_003D9740(&pts[0], 0x30, phase, color, n, 1);
    if (obj[0x20] != 4) {
        c0 = 0xB43264;
        c1 = 0x801028;
        if (D_L01_001E1C64 > 0.0f) {
            color = (0x7F - (s32)(D_L01_001E1C64 * 32.0f)) << 24;
            c0 = color + c0;
            c1 = color + c1;
        } else {
            c0 = 0x7FB43264;
            c1 = 0x7F801028;
        }
        color = func_0038DBD8(c0, c1, pulse);
        phase = func_L01_0040F518((f32)D_L01_001DFB40, 14.333333f) / 14.333333f;
        vec_neg(&pts[2], &pts[2]);
        vec_neg(&pts[1], &pts[1]);
        func_0038CE20(&pts[3], &D_L01_001E1C50_00368B30, 0.7f);
        vec_add_ab(&pts[3], &pts[3], &D_L01_001E1C40_00368B30);
        func_0038CF68(&pts[0], &pts[0], 0.5f);
        func_0038CF68(&pts[1], &pts[1], 0.5f);
        func_0038CF68(&pts[2], &pts[2], 0.5f);
        func_003D9740(&pts[0], 0x30, phase, color, 4, 1);
    }
    func_L01_0040B858(&D_L01_001E1CE0, D_L01_002B3870);
    if (D_L01_001E1D00 == 1) {
        func_003A9440_00368B30(0x47, 0x53001);
        func_003D9508(&D_L01_001E1CF0, 0x39, 0xFFFF2040, 1, 2.0f * D_L01_002B3870[5], D_L01_002B3870[5], func_00382538());
        func_003D9508(&D_L01_001E1CF0, 0x39, 0x4FFF2040, 1, D_L01_002B3870[5] * 2.5f, D_L01_002B3870[5], func_00382538());
        func_003D9508(&D_L01_001E1CF0, 0x31, 0x60FF4060, 1, D_L01_002B3870[5] * 3.0f, D_L01_002B3870[5], func_00382538());
    }
    func_L01_003687C8((s32)obj, (vu0_v4 *)D_L01_001E1C30);
    if (D_L01_001E1CC0 != 0) {
        if (D_L01_001E1CC0 >= 0x1D) {
            func_003A9440_00368B30(0x42, 0x48);
            func_0038AF30(0, D_001CFEC0.x152, 0, D_001CFEC0.x150, (s32)0x80808080);
        }
        func_0038CE20(&a, &D_L01_001E1C50_00368B30, 0.75f);
        vec_add_ab(&a, &a, &D_L01_001E1C40_00368B30);
        func_003C5180(&a, &b, 1);
        t = (f32)D_L01_001E1CC0 / 30.0f;
        func_003D93B0(&q, 0xB, 4, 0x80);
        q.uv[0][0] = 0.0f;
        q.uv[0][1] = 0.0f;
        q.uv[1][0] = 0.0f;
        q.uv[1][1] = 1.0f;
        q.uv[2][0] = 1.0f;
        q.uv[2][1] = 0.0f;
        q.uv[3][0] = 1.0f;
        q.uv[3][1] = 1.0f;
        q.rgba[0] = q.rgba[1] = q.rgba[2] = q.rgba[3] = ((s32)(t * 255.0f) << 24) | 0xFFFFFF;
        vec_sub_ba(&d, &a, &D_L01_001E2A40_00368B30);
        func_0038CF68(&e, &d, 0.1f);
        vec_add_ba(&f, &D_L01_001E2A40_00368B30, &e);
        func_0038CE90(&g, &d, &b);
        func_0038CF68(&g, &g, 0.08f);
        func_0038CE90(&h, &g, &d);
        func_0038CF68(&h, &h, 0.08f);
        vec_add_ba(&k, &f, &h);
        vec_add_ab(&q.pos[0], &k, &g);
        vec_sub_ab(&q.pos[1], &k, &g);
        vec_sub_ab(&k, &f, &h);
        vec_add_ba(&q.pos[2], &k, &g);
        vec_sub_ab(&q.pos[3], &k, &g);
        func_003D2DA0(&q, 0, 0);
    }
}
/* localdecomp:end func_L01_00368B30 */

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
 extern void func_L01_003693F8_003691D8(void *);
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
  func_L01_00404A10_003691D8(func_L01_003693F8_003691D8,m);
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

/* localdecomp:start func_L01_003693F8 */
#include "vu0.h"
void func_L01_003693F8(Moby_003691D8 *m) {
    extern f32 func_L01_0040E548(void *, void *);
    extern s32 func_0038DBD8(s32, s32, f32);
    extern f32 func_00382538(void);
    extern f32 func_003824E0(f32, f32);
    extern s32 func_00382498(s32, s32);
    extern void func_003D9508(void *, s32, u32, s32, f32, f32, f32);
    extern f32 func_L01_00443A18(f32, f32);
    extern void func_00382580(void *, f32, f32);
    extern void func_0038CF68(void *, void *, f32);
    extern void func_L01_004713C8(void *, void *, s32, u32, s32, s32, s32, s32, f32, f32, f32);
    vu0_v4 point;
    vu0_v4 velocity;
    s128 *position;
    f32 distance, fade, scale, size;
    s32 count, life;
    u32 color;
    distance = func_L01_0040E548(D_L01_001E2A40, &m->pos);
    if (distance > 1600.0f) return;
    if (distance > 1024.0f) { distance = sqrt_asm(distance) - 32.0f; fade = distance * 0.125f; }
    else fade = 0.0f;
    func_003A9440(0x47, 0x53001);
    scale = m->scale / m->cls->scale / 1.5f * 1.4f;
    color = func_0038DBD8(0x7FFF2020, 0x7F000000, fade);
    size = scale * 1.25f;
    position = &m->pos;
    func_003D9508(position, 0x39, color, 1, size, 0.05f, func_00382538());
    color = func_0038DBD8(0x4FFF2020, 0x7F000000, fade);
    func_003D9508(position, 0x39, color, 1, size, 0.05f, func_00382538());
    color = func_0038DBD8(0x7F503040, 0x7F000000, fade);
    func_003D9508(position, 0x31, color, 1, size, 0.05f, func_00382538());
    count = func_L01_00443A18(2.0f, 5.0f);
    func_00382580(&point, scale * 0.8f, scale);
    vec_add_ab(&point, &point, &m->pos);
    vec_sub_ab(&velocity, &m->pos, &point);
    func_0038CF68(&velocity, &velocity, 0.0150000006f);
    color = func_0038DBD8(0x00FF2020, 0xFF000000, fade);
    life = (func_00382498(55, 70) * 5 + 2) / 6;
    func_L01_004713C8(&point, &velocity, life, color, count, 0, 95, 6,
        func_003824E0(0.025f, 0.04f) * 210000.0f, 25200.0f, 0.0f);
}
/* localdecomp:end func_L01_003693F8 */

/* localdecomp:start func_L01_00369700 */
#include "vu0.h"
typedef struct { u8 pad0; u8 kind; u8 pad2[0xEE]; } Row_00369700;
typedef struct { u8 pad0[0x1A4]; u8 *table; } Table_00369700;
extern s32 D_L01_001E1D10;
extern u16 D_001A8BB0[];
extern u8 D_001425C0[];
extern Row_00369700 D_L01_002C5600[];
__asm__(".extern D_L01_001DD7F0, 4");
extern s128 D_L01_001DD7F0[] __attribute__((section(".sdata")));

extern s32 D_L01_001D6694;
extern u8 *D_001D52FC;
extern s128 D_L01_001E29E0[];
extern Table_00369700 D_L01_00221098;
extern u8 D_L01_001D66B0[] __attribute__((section(".sdata")));
typedef struct {
    u8 p0[0x80];
    s128 x80;
    u8 p90[0x1210 - 0x90];
    s32 x1210;
    u8 p1214[0x1220 - 0x1214];
    s32 x1220;
    u8 p1224[0x16B0 - 0x1224];
    s32 x16B0;
    u8 p16B4[0x25C0 - 0x16B4];
    u8 *x25C0;
    s32 x25C4;
    u8 p25C8[0x25ED - 0x25C8];
    u8 x25ED;
    u8 p25EE[0x2874 - 0x25EE];
    s16 x2874;
} H_00369700;
#define H369700 (*(H_00369700 *)&D_001A4BE0)
/* The speed is the y component of the offset vector D_L01_001DD7F0. */
void func_L01_00369700(u8 *moby) {
    extern s32 func_L01_004CB2D8(u8 *);
    extern void func_L01_0041A5B0(s32, s32);
    extern void func_L01_005003D0(s32, s32);
    extern void func_0038D000(void *, void *, void *);
    extern s32 func_0038CAD0(void *);
    extern void func_L01_00444F38(u8 *, s32, s32, s32, s32);
    extern s32 func_L01_005118D0(s32, s32);
    extern s32 func_003A52A0(s32, s32, u8 *);
    extern void func_L01_004EA7D8(s32);
    extern void func_003C3A10(u8 *, s32, s32, s32);
    extern void func_L01_00369D80_00369700(void *, void *, void *) __asm__("func_L01_00369D80");
    extern void func_L01_00369E28(u8 *, void *, void *);
    extern void func_L01_004EAA80(void);
    extern s32 func_L01_005119E0(s32);
    extern s32 func_00382498(s32, s32);
    extern u8 *func_L01_004713C8(void *, void *, s32, s32, s32, s32, s32, s32, f32, f32, f32);
    extern void func_L01_004C7D98(void *, void *);
    extern f32 func_003824E0(f32, f32);
    extern void func_0038CF68(void *, void *, f32);
    extern s32 func_0013D3E0(void);
    extern void func_L01_00466F50(void *, void *, s32, f32, f32);
    Row_00369700 *row;
    s128 pos;
    s128 direction;
    u8 *vars = *(u8 **)(moby + 0x68);
    func_L01_004CB2D8(moby);
    if (moby[0x20] == 0) {
        *(s32 *)vars = 0;
        moby[0x20] = 1;
        *(s32 *)(vars + 12) = 0;
        D_L01_001E1D10 = 1;
        *(s32 *)(vars + 24) = 25;
    }
    if (D_001A8BB0[0] == 0 && (&D_L01_002C5600[D_001425C0[0x37]])->kind == 0) func_L01_0041A5B0(0x1517, 0x122);
    if (H369700.x25C4 == 1) func_L01_005003D0(29, 1);
    func_0038D000(&pos, D_L01_001DD7F0, moby + 0xC0);
    vec_add_ab(&pos, &pos, moby + 0x10);
    row = &D_L01_002C5600[D_001425C0[0x37]];
    if (row->kind >= 3) *(s16 *)(moby + 0x7C) = 7;
    if ((&D_L01_002C5600[D_001425C0[0x37]])->kind == 2) *(s16 *)(moby + 0x7C) = 3;
    else if ((&D_L01_002C5600[D_001425C0[0x37]])->kind == 1) *(s16 *)(moby + 0x7C) = 1;
    if ((&D_L01_002C5600[D_001425C0[0x37]])->kind != 0) ((f32 *)D_L01_001DD7F0)[1] = -0.8199999928474426f;
    else ((f32 *)D_L01_001DD7F0)[1] = -0.75f;
    func_0038CAD0(vars);
    if (moby[0x42] == moby[0x43] && (moby[0x60] & 2)) func_L01_00444F38(moby, 1, 0, 2, 0);
    if (D_L01_001D6694 == 0 && H369700.x25ED == 0 &&
        ((*(s32 *)(D_001D52FC + 0x1A4) & H369700.x1210) ||
         ((*(s32 *)(D_001D52FC + 0x1A0) & 8) && H369700.x25C4 == 29)) &&
        H369700.x1220 >= 19) {
        if (*(s32 *)vars == 0) {
            if (func_L01_005118D0(-1, 1)) {
                func_003A52A0(0, 0, moby);
                D_L01_001E1D10 = 1;
                func_L01_004EA7D8(-1);
                func_003C3A10(moby, 2, 0, 0);
                *(s32 *)vars = 37;
                if (H369700.x2874) func_0038CE20(&direction, (s128 *)(moby + 0xD0), -1.0f);
                else if (H369700.x25C4 == 29 || H369700.x16B0 != 0) direction = D_L01_001E29E0[0];
                else direction = *(s128 *)(H369700.x25C0 + 0xC0);
                func_L01_00369D80_00369700(moby, &pos, &direction);
                func_L01_00369E28(moby, &pos, &direction);
            } else {
                if ((*(s32 *)(D_001D52FC + 0x1A4) & H369700.x1210) || D_L01_001E1D10 == 1) {
                    func_003A52A0(2, 0, moby);
                    D_L01_001E1D10 = 0;
                }
                func_L01_004EAA80();
            }
        }
    } else func_L01_004EAA80();
    if (H369700.x25ED == 0 && H369700.x1220 >= 19 && func_L01_005119E0(-1)) {
        s32 i;
        for (i = 0; i < 1; i++) {
            s32 life = (func_00382498(10, 20) * 5 + 2) / 6;
            u8 *particle = func_L01_004713C8(&pos, D_L01_001D66B0, life, 0x5A182, func_00382498(1, 4), 0x30, 0, 0, 63000.00390625f, 31500.001953125f, 0.000800000037997961f);
            if (particle) particle[2] = *D_L01_00221098.table;
        }
        func_L01_004C7D98(&H369700.x80, &direction);
        func_0038CF68(&direction, &direction, func_003824E0(0.004999999888241291f, 0.014999999664723873f));
        ((f32 *)&pos)[0] += func_003824E0(-0.07500000298023224f, 0.07500000298023224f);
        ((f32 *)&pos)[1] += func_003824E0(-0.07500000298023224f, 0.07500000298023224f);
        ((f32 *)&pos)[2] += func_003824E0(-0.07500000298023224f, 0.07500000298023224f);
        if (func_0013D3E0() % 12 == 0) func_L01_00466F50(&pos, &direction, 0x4005A182, -1.0f, 0.0f);
    }
}
/* localdecomp:end func_L01_00369700 */

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

/* localdecomp:start func_L01_0036B078 */
#include "vu0.h"
typedef struct { float x,y,z,w; } __attribute__((aligned(16))) V_0036B078;
typedef struct { V_0036B078 pos[4]; u32 color[4]; float uv[8]; u8 tail[0x20]; } R_0036B078;
extern s32 D_L01_001DD800, D_L01_001DD804;
__asm__(".extern D_L01_001DD804, 4");
extern V_0036B078 D_L01_001E29C0;
void func_L01_0036B078(u8 *m) {
    extern void func_003D93B0(void *, s32, s32, s32);
    extern void func_0038CE90(void *, void *, void *);
    extern void func_0038CF68_0036B078(void *, void *, float);
    extern void func_003D2DA0(void *, s32, s32);
    R_0036B078 r;
    V_0036B078 diff, delta, end, side, tmp;
    u8 *p = *(u8 **)(m+0x68);
    float alpha;
    s32 i;
    if (!m || m[0x20] == 0xFE || m[0x20] == 0xFD || !p) return;
    alpha = (float)*(s32 *)(p+0x38) * *(float *)(p+0x3C);
    func_003D93B0(&r,D_L01_001DD800,0,128);
    r.color[0] = r.color[1] = ((s32)(alpha*64.0f)<<24)|0x4080FF;
    r.color[2] = r.color[3] = ((s32)(alpha*64.0f)<<24)|0x909090;
    r.uv[0]=0; r.uv[1]=0; r.uv[2]=0; r.uv[3]=1;
    r.uv[4]=1; r.uv[5]=0; r.uv[6]=1; r.uv[7]=1;
    for (i=0;i<4;i++) {
        r.uv[i*2] += *(float *)(p+0x30);
        if (r.uv[i*2]>=7.0f) r.uv[i*2]-=7.0f;
    }
    *(float *)(p+0x30)+=0.1f;
    if (*(float *)(p+0x30)>=4.0f) *(float *)(p+0x30)-=4.0f;
    vec_sub_ab(&diff, (V_0036B078 *)(m+0x10), &D_L01_001E29C0);
    vec_sub_ba(&delta, (V_0036B078 *)(p+0x50), (V_0036B078 *)(m+0x10));
    func_0038CE20((s128 *)&delta,(s128 *)&delta,0.5f);
    vec_add_ba(&end, (V_0036B078 *)(m+0x10), &delta);
    func_0038CE90(&side,&diff,&delta);
    func_0038CF68_0036B078(&side,&side,1.4f);
    vec_add_ba(&(r.pos[0]), (V_0036B078 *)(m+0x10), &side);
    vec_sub_ab(&(r.pos[1]), (V_0036B078 *)(m+0x10), &side);
    func_0038CF68_0036B078(&side,&side,0.6f);
    vec_add_ba(&(r.pos[2]), &end, &side);
    vec_sub_ab(&(r.pos[3]), &end, &side);
    func_003D2DA0(&r,0,0);
    r.color[0]=r.color[2]; r.color[1]=r.color[3];
    r.color[2]=r.color[3]=0x804020;
    r.pos[0]=r.pos[2]; r.pos[1]=r.pos[3];
    vec_add_ba(&(r.pos[2]), &(r.pos[2]), &delta);
    vec_add_ab(&(r.pos[3]), &(r.pos[3]), &delta);
    func_003D2DA0(&r,0,0);
    func_003D93B0(&r,D_L01_001DD804,1,128);
    r.uv[0]=0; r.uv[1]=0; r.uv[2]=0; r.uv[3]=1;
    r.uv[4]=1; r.uv[5]=0;
    r.color[0]=r.color[1]=((s32)(alpha*64.0f)<<24)|0x40FF;
    r.uv[6]=1; r.uv[7]=1;
    r.color[2]=r.color[3]=0x40FF;
    func_0038CF68_0036B078(&side,&side,0.6f);
    vec_add_ba(&(r.pos[0]), (V_0036B078 *)(m+0x10), &side);
    __asm__("lqc2 $vf1,%1\n\tsqc2 $vf1,%0" : "=m"(tmp) : "m"(*(V_0036B078 *)(m+0x10)) : "vf1");
    vec_sub_ab(&(r.pos[1]), (V_0036B078 *)(m+0x10), &side);
    __asm__("lqc2 $vf2, %1\n\tlqc2 $vf1, %2\n\tvadd.xyz $vf1, $vf2, $vf1\n\tsqc2 $vf1, %0" : "=m"(end) : "m"(tmp), "m"(delta) : "vf1", "vf2");
    vec_add_ba(&end, &end, &delta);
    vec_add_ab(&(r.pos[2]), &end, &side);
    vec_sub_ab(&(r.pos[3]), &end, &side);
    func_003D2DA0(&r,0,0);
}
/* localdecomp:end func_L01_0036B078 */

/* localdecomp:start func_L01_0036B440 */
#include "vu0.h"
extern f32 func_0038D160(f32, f32);
extern f32 func_003824E0(f32, f32);
extern f32 func_L01_00443A18(f32, f32);
extern f32 func_0038DAB8(f32, f32);
extern void func_L01_0046A610(void *, void *, s32, s32, s32, s32, f32, f32, f32, f32, f32);

void func_L01_0036B440(V4_365E28 *origin) {
    V4_365E28 delta, velocity, position;
    f32 angle, speed, tilt, yaw;
    f32 life;
    s32 type, i;

    vec_sub_ab(&delta, &D_L01_001E29C0, origin);
    angle = func_0038D160(delta.x, delta.y);
    for (i = 14; i >= 0; i--) {
        speed = func_003824E0(0.5f, 1.0f);
        type = func_L01_00443A18(1.0f, 2.0f);
        func_003824E0(0.05f, 0.2f);
        life = 210000.0f;
        tilt = func_003824E0(0.0f, 1.3962634f);
        yaw = func_0038DAB8(angle, func_L01_00443A18(0.0f, 1.3962634f));
        func_00382760(&velocity, speed * 0.020000001415610313f, yaw, tilt);
        position.x = origin->x + func_L01_00443A18(0.0f, 0.1f);
        position.y = origin->y + func_L01_00443A18(0.0f, 0.1f);
        position.z = origin->z + func_L01_00443A18(0.0f, 0.1f);
        func_L01_0046A610(&position, &velocity, 25, 127, 0x7F7F7F, type,
            func_003824E0(0.05f, 0.2f) * life, 500.0f, 1.0f, 0.0f, 2.0f);
    }
}
/* localdecomp:end func_L01_0036B440 */

#include "common.h"

/* NTSC-U counterpart of func_00388638 (src/boot_elf/text/388638.c): the 30..120 frame delay is used as is, not scaled by 5/6 for 50 Hz */
/* localdecomp:start func_U_00388610 */
typedef int Q_00388610 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_00388610;
typedef struct { V_00388610 pos[4]; s32 rgba[4]; f32 uv[4][2]; long a, tex, c, d; } P_00388610;
typedef struct { u8 p0[0x24]; f32 f24, f28; u8 p2C[8]; f32 f34, f38; s32 f3C; } O_00388610;
__asm__(".extern D_U_001D59B0, 4");
__asm__(".extern D_U_001D59B4, 4");
__asm__(".extern D_U_001D59B8, 4");
__asm__(".extern D_U_001D59BC, 4");
__asm__(".extern D_U_001D5948, 4");
__asm__(".extern D_U_001D5958, 4");
extern f32 D_U_001D59B0, D_U_001D59B4, D_U_001D59BC;
extern s32 D_U_001D59B8;
extern f32 D_U_001D5948;
extern f32 D_U_001D594C;
extern f32 D_U_001D5950;
extern f32 D_U_001D5954;
extern f32 D_U_001D5958;
extern f32 D_U_001D595C;
extern f32 D_U_001D5960;
extern f32 D_U_001D5964;
extern V_00388610 D_U_00222500;
extern s32 func_U_0038CDF8(void *);
extern void func_U_003C4318(V_00388610 *, V_00388610, V_00388610, f32);
extern void func_U_0038D1B8(V_00388610 *, V_00388610, V_00388610);
extern f32 func_U_0038D190(void *, void *);
extern void func_U_0038D290(s32 a, s32 b, f32 x);
extern f32 func_U_003C4308(f32, f32, f32);
extern void func_U_003D2FF0();
extern s32 func_U_00382898(s32, s32);
static __inline__ void vaddA_00388610(V_00388610 *d, V_00388610 *a, V_00388610 *b) {
    Q_00388610 x, y;
    __asm__("lqc2 %0, %1" : "=j"(x) : "m"(*a));
    __asm__("lqc2 %0, %1" : "=j"(y) : "m"(*b));
    __asm__("vadd.xyz %0, %0, %1" : "+j"(x) : "j"(y));
    __asm__("sqc2 %1, %0" : "=m"(*d) : "j"(x));
}
void func_U_00388610(O_00388610 *o, V_00388610 *v, long tex) {
    P_00388610 s;
    V_00388610 a, b;
    Q_00388610 x0, x1, x2, x3, y0, y2;
    f32 sc, dot;
    if (func_U_0038CDF8(&o->f3C) == 0) return;
    s.c = 0xFF9000000260UL;
    s.tex = tex;
    s.a = 5;
    s.d = 0x8000000044UL;
    s.rgba[0] = s.rgba[1] = s.rgba[2] = s.rgba[3] = D_U_001D59B8;
    a = v[0];
    b = v[1];
    func_U_003C4318(&s.pos[0], a, b, o->f38 - D_U_001D59B0);
    a = v[0];
    b = v[1];
    func_U_003C4318(&s.pos[1], a, b, o->f38 + D_U_001D59B0);
    a = v[2];
    b = v[3];
    func_U_003C4318(&s.pos[2], a, b, o->f38 - D_U_001D59B0);
    a = v[2];
    b = v[3];
    func_U_003C4318(&s.pos[3], a, b, o->f38 + D_U_001D59B0);
    {
    V_00388610 n;
    V_00388610 d;
    __asm__("lqc2 %0, %1" : "=j"(x0) : "m"(v[1]));
    __asm__("lqc2 %0, %1" : "=j"(x1) : "m"(v[0]));
    __asm__("lqc2 %0, %1" : "=j"(x2) : "m"(v[2]));
    __asm__("vsub.xyz %0, %1, %2" : "=j"(y0) : "j"(x0), "j"(x1));
    __asm__("lqc2 %0, %1" : "=j"(x3) : "m"(v[0]));
    __asm__("vsub.xyz %0, %1, %2" : "=j"(y2) : "j"(x2), "j"(x3));
    __asm__("sqc2 %1, %0" : "=m"(a) : "j"(y0));
    __asm__("sqc2 %1, %0" : "=m"(b) : "j"(y2));
    func_U_0038D1B8(&n, a, b);
    __asm__("lqc2 %0, %1" : "=j"(x0) : "m"(v[0]));
    __asm__("lqc2 %0, %1" : "=j"(x1) : "m"(D_U_00222500));
    __asm__("vsub.xyz %0, %1, %2" : "=j"(x1) : "j"(x1), "j"(x0));
    __asm__("sqc2 %1, %0" : "=m"(d) : "j"(x1));
    dot = func_U_0038D190(&n, &d);
    sc = D_U_001D59BC;
    if (!(0.0f < dot)) sc = -sc;
    func_U_0038D290((s32)&n, (s32)&n, sc);
    vaddA_00388610(&s.pos[0], &s.pos[0], &n);
    vaddA_00388610(&s.pos[1], &s.pos[1], &n);
    vaddA_00388610(&s.pos[2], &s.pos[2], &n);
    vaddA_00388610(&s.pos[3], &s.pos[3], &n);
    }
    s.uv[0][0] = o->f24 * D_U_001D5948 + 0.5f + D_U_001D59B4;
    s.uv[1][0] = o->f24 * D_U_001D594C + 0.5f + D_U_001D59B4;
    s.uv[2][0] = o->f24 * D_U_001D5950 + 0.5f - D_U_001D59B4;
    s.uv[3][0] = o->f24 * D_U_001D5954 + 0.5f - D_U_001D59B4;
    s.uv[0][1] = o->f28 * func_U_003C4308(D_U_001D5958, D_U_001D595C, o->f38 - D_U_001D59B0) + 0.5f;
    s.uv[1][1] = o->f28 * func_U_003C4308(D_U_001D595C, D_U_001D5958, o->f38 - D_U_001D59B0) + 0.5f;
    s.uv[2][1] = o->f28 * func_U_003C4308(D_U_001D5960, D_U_001D5964, o->f38 - D_U_001D59B0) + 0.5f;
    s.uv[3][1] = o->f28 * func_U_003C4308(D_U_001D5964, D_U_001D5960, o->f38 - D_U_001D59B0) + 0.5f;
    func_U_003D2FF0(&s, 0, 0);
    o->f38 += o->f34;
    if (0.0f < o->f34) {
        if (1.0f - D_U_001D59B0 <= o->f38) {
            o->f38 -= 1.0f;
            o->f3C = func_U_00382898(0x1E, 0x78);
        }
        if (o->f38 < D_U_001D59B0) o->f38 = D_U_001D59B0;
    } else {
        if (o->f38 <= D_U_001D59B0) {
            o->f38 += 1.0f;
            o->f3C = func_U_00382898(0x1E, 0x78);
        }
        if (1.0f - D_U_001D59B0 <= o->f38) o->f38 = 1.0f - D_U_001D59B0;
    }
}
/* localdecomp:end func_U_00388610 */

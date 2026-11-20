#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
/* --- end of declarations from other files --- */

/* declarations of 388618.c's earlier functions */
extern void (*D_001D9A40[2])(s32);
extern f32 func_0038D248(void *, void *);
extern void func_0038D348(s32 a, s32 b, f32 x);
extern s32 func_0038CEB0(void *);

/* localdecomp:start func_00388638 */
/* from the NTSC decomp's func_00388610 (US boot_elf); PAL's tail differs */
typedef int Q_00388638 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_00388638;
typedef struct { V_00388638 pos[4]; s32 rgba[4]; f32 uv[4][2]; long a, tex, c, d; } P_00388638;
typedef struct { u8 p0[0x24]; f32 f24, f28; u8 p2C[8]; f32 f34, f38; s32 f3C; } O_00388638;
__asm__(".extern D_001D59B0_00388638, 4");
__asm__(".extern D_001D59B4_00388638, 4");
__asm__(".extern D_001D59B8_00388638, 4");
__asm__(".extern D_001D59BC_00388638, 4");
__asm__(".extern D_001D5948_00388638, 4");
__asm__(".extern D_001D5958_00388638, 4");
extern f32 D_001D59B0_00388638, D_001D59B4_00388638, D_001D59BC_00388638;
extern s32 D_001D59B8_00388638;
extern f32 D_001D5948_00388638;
extern f32 D_001D594C_00388638;
extern f32 D_001D5950_00388638;
extern f32 D_001D5954_00388638;
extern f32 D_001D5958_00388638;
extern f32 D_001D595C_00388638;
extern f32 D_001D5960_00388638;
extern f32 D_001D5964_00388638;
extern V_00388638 D_00222480_00388638;
extern s32 func_0038CEB0(void *);
extern void func_003C4450_00388638(V_00388638 *, V_00388638, V_00388638, f32);
extern void func_0038D270_00388638(V_00388638 *, V_00388638, V_00388638);
extern f32 func_0038D248(void *, void *);
extern void func_0038D348(s32 a, s32 b, f32 x);
extern f32 func_003C4440(f32, f32, f32);
extern void func_003D3158();
extern s32 func_00382878(s32, s32);
static __inline__ void vaddA_00388638(V_00388638 *d, V_00388638 *a, V_00388638 *b) {
    Q_00388638 x, y;
    __asm__("lqc2 %0, %1" : "=j"(x) : "m"(*a));
    __asm__("lqc2 %0, %1" : "=j"(y) : "m"(*b));
    __asm__("vadd.xyz %0, %0, %1" : "+j"(x) : "j"(y));
    __asm__("sqc2 %1, %0" : "=m"(*d) : "j"(x));
}
void func_00388638(O_00388638 *o, V_00388638 *v, long tex) {
    P_00388638 s;
    V_00388638 a, b;
    Q_00388638 x0, x1, x2, x3, y0, y2;
    f32 sc, dot;
    if (func_0038CEB0(&o->f3C) == 0) return;
    s.c = 0xFF9000000260UL;
    s.tex = tex;
    s.a = 5;
    s.d = 0x8000000044UL;
    s.rgba[0] = s.rgba[1] = s.rgba[2] = s.rgba[3] = D_001D59B8_00388638;
    a = v[0];
    b = v[1];
    func_003C4450_00388638(&s.pos[0], a, b, o->f38 - D_001D59B0_00388638);
    a = v[0];
    b = v[1];
    func_003C4450_00388638(&s.pos[1], a, b, o->f38 + D_001D59B0_00388638);
    a = v[2];
    b = v[3];
    func_003C4450_00388638(&s.pos[2], a, b, o->f38 - D_001D59B0_00388638);
    a = v[2];
    b = v[3];
    func_003C4450_00388638(&s.pos[3], a, b, o->f38 + D_001D59B0_00388638);
    {
    V_00388638 n;
    V_00388638 d;
    __asm__("lqc2 %0, %1" : "=j"(x0) : "m"(v[1]));
    __asm__("lqc2 %0, %1" : "=j"(x1) : "m"(v[0]));
    __asm__("lqc2 %0, %1" : "=j"(x2) : "m"(v[2]));
    __asm__("vsub.xyz %0, %1, %2" : "=j"(y0) : "j"(x0), "j"(x1));
    __asm__("lqc2 %0, %1" : "=j"(x3) : "m"(v[0]));
    __asm__("vsub.xyz %0, %1, %2" : "=j"(y2) : "j"(x2), "j"(x3));
    __asm__("sqc2 %1, %0" : "=m"(a) : "j"(y0));
    __asm__("sqc2 %1, %0" : "=m"(b) : "j"(y2));
    func_0038D270_00388638(&n, a, b);
    __asm__("lqc2 %0, %1" : "=j"(x0) : "m"(v[0]));
    __asm__("lqc2 %0, %1" : "=j"(x1) : "m"(D_00222480_00388638));
    __asm__("vsub.xyz %0, %1, %2" : "=j"(x1) : "j"(x1), "j"(x0));
    __asm__("sqc2 %1, %0" : "=m"(d) : "j"(x1));
    dot = func_0038D248(&n, &d);
    sc = D_001D59BC_00388638;
    if (!(0.0f < dot)) sc = -sc;
    func_0038D348((s32)&n, (s32)&n, sc);
    vaddA_00388638(&s.pos[0], &s.pos[0], &n);
    vaddA_00388638(&s.pos[1], &s.pos[1], &n);
    vaddA_00388638(&s.pos[2], &s.pos[2], &n);
    vaddA_00388638(&s.pos[3], &s.pos[3], &n);
    }
    s.uv[0][0] = o->f24 * D_001D5948_00388638 + 0.5f + D_001D59B4_00388638;
    s.uv[1][0] = o->f24 * D_001D594C_00388638 + 0.5f + D_001D59B4_00388638;
    s.uv[2][0] = o->f24 * D_001D5950_00388638 + 0.5f - D_001D59B4_00388638;
    s.uv[3][0] = o->f24 * D_001D5954_00388638 + 0.5f - D_001D59B4_00388638;
    s.uv[0][1] = o->f28 * func_003C4440(D_001D5958_00388638, D_001D595C_00388638, o->f38 - D_001D59B0_00388638) + 0.5f;
    s.uv[1][1] = o->f28 * func_003C4440(D_001D595C_00388638, D_001D5958_00388638, o->f38 - D_001D59B0_00388638) + 0.5f;
    s.uv[2][1] = o->f28 * func_003C4440(D_001D5960_00388638, D_001D5964_00388638, o->f38 - D_001D59B0_00388638) + 0.5f;
    s.uv[3][1] = o->f28 * func_003C4440(D_001D5964_00388638, D_001D5960_00388638, o->f38 - D_001D59B0_00388638) + 0.5f;
    func_003D3158(&s, 0, 0);
    o->f38 += o->f34;
    if (0.0f < o->f34) {
        if (1.0f - D_001D59B0_00388638 <= o->f38) {
            o->f38 -= 1.0f;
            o->f3C = (func_00382878(0x1E, 0x78) * 5 + 2) / 6;
        }
        if (o->f38 < D_001D59B0_00388638) o->f38 = D_001D59B0_00388638;
    } else {
        if (o->f38 <= D_001D59B0_00388638) {
            o->f38 += 1.0f;
            o->f3C = (func_00382878(0x1E, 0x78) * 5 + 2) / 6;
        }
        if (1.0f - D_001D59B0_00388638 <= o->f38) o->f38 = 1.0f - D_001D59B0_00388638;
    }
}
/* localdecomp:end func_00388638 */

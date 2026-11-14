#include "common.h"

/* NTSC-U counterpart of func_L39_006302E0 (src/levels/shared/L39_0062D7C8.c): 0.0504 -> 0.035; 0.432 -> 0.3; 8 -> 10; 0.00144 -> 0.001 */
typedef int u128_t __attribute__((mode(TI)));
typedef union {
    u128_t q;
    f32 f[4];
} Vec4;
extern void func_L39_0062DA98(u8 *s);

/* localdecomp:start func_L39_0062DA98 */
typedef struct {
    u8 pad0[0x20];
    f32 m20[16];
    f32 m60[16];
    Vec4 vA0;
    u8 padB0[0x230 - 0xB0];
    Vec4 v230;
    u8 pad240[0x10];
    Vec4 v250;
    u8 pad260[0x2AC - 0x260];
    f32 f2AC;
    u8 pad2B0[0x2DE - 0x2B0];
    s16 h2DE;
    u8 pad2E0[0x33E - 0x2E0];
    s16 h33E;
    u8 pad340[0x1290 - 0x340];
    f32 m1290[16];
    u8 pad12D0[0x1310 - 0x12D0];
    s32 s1310;
    u8 pad1314[0x1A06 - 0x1314];
    u8 mode;
} S_006302E0;

extern void func_003888F0(Vec4 *, Vec4 *, u8 *);
extern void func_003886E8(void *, void *, f32);
extern void func_003888C8(f32 *, f32 *, u8 *);
extern void func_L39_00631168(void *, Vec4 *, f32 *, s32, f32, f32, f32);

void func_L39_0062DA98(u8 *s) {
    S_006302E0 *p = (S_006302E0 *)s;
    f32 m[16];
    Vec4 pos;
    Vec4 fwd;
    Vec4 off;
    Vec4 tmp;
    f32 a;
    f32 b;

    pos.q = 0;
    pos.f[2] = 1.0f;
    fwd.q = 0;
    fwd.f[2] = 0.8f;
    off.q = 0;
    off.f[2] = 0.8f;
    func_003888F0(&fwd, &fwd, (u8 *)p->m20);
    a = 0.0350000001f;
    pos.q = p->v230.q;
    b = 0.300000012f;
    if (p->mode == 2) {
        func_003886E8(&pos, &p->v250, -1.0f);
    }
    if (p->mode == 1 && (p->h2DE < 10 || p->f2AC < 1.0f)) {
        pos.q = p->v230.q;
    }
    if (p->h2DE != 0 && p->h33E != 0) {
        b = 0.00100000005f;
        a = b;
    }
    if (p->s1310 != 0) {
        func_003888C8(p->m1290, p->m1290, (u8 *)p->m60);
    }
    func_L39_00631168(p, &pos, m, 0, a, b, 0.0f);
    if (p->s1310 != 0) {
        func_003888C8(p->m1290, p->m1290, (u8 *)m);
    }
    if (p->mode == 1 && p->h2DE != 0) {
        func_003888F0(&off, &off, (u8 *)m);
        __asm__ __volatile__(
            "lqc2 $vf1, %2\n"
            "lqc2 $vf2, %0\n"
            "vsub.xyz $vf2, $vf2, $vf1\n"
            "lqc2 $vf1, %3\n"
            "sqc2 $vf1, %1\n"
            "sqc2 $vf2, %0\n"
            "lqc2 $vf1, %0\n"
            "lqc2 $vf2, %1\n"
            "vadd.xyz $vf1, $vf1, $vf2\n"
            "sqc2 $vf1, %0\n"
            : "+m"(p->vA0), "=m"(tmp) : "m"(off), "m"(fwd) : "memory");
    }
}
/* localdecomp:end func_L39_0062DA98 */

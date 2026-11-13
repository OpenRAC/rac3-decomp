#include "common.h"

typedef int u128_t __attribute__((mode(TI)));
typedef union {
    u128_t q;
    f32 f[4];
} Vec4;
typedef struct { u8 pad[288]; u8 sub[4020 - 288]; f32 f; } S630;

typedef struct { u8 pad0[0xFB0]; f32 f0FB0; u8 pad1[0x2468 - 0xFB4]; f32 f2468; } S_00633160;

typedef struct {
    u8 pad0[0x474];
    s32 mode;
    s32 kind;
    u8 pad1[0x142F - 0x47C];
    u8 alternate;
    u8 pad2[0x1A07 - 0x1430];
    u8 special;
    u8 pad3[0x2468 - 0x1A08];
    f32 speed;
} View_00633428;

INCLUDE_ASM("asm/levels", func_L39_00632888);

/* localdecomp:start func_L39_00632988 */
#include "vu0.h"

extern void func_0038D328(Vec4 *, Vec4 *);
extern void func_0038D028(Vec4 *out, void *a, void *b);

typedef struct {
    u8 pad0[0x1A06];
    u8 mode;
    u8 pad1[0x2524 - 0x1A07];
    u8 *ctx;
} S_00632988;

void func_L39_00632988(S_00632988 *s, Vec4 *out, Vec4 *in, f32 z) {
    s32 m = s->mode;

    if (m == 0) {
        out->q = in->q;
        out->f[2] += z;
        return;
    }
    if (m < 0) {
        return;
    }
    if (m < 3) {
        Vec4 mat[4];
        Vec4 t;
        qzero(&t);
        t.f[2] = z;
        func_0038D328(mat, (Vec4 *)(s->ctx + 240));
        func_0038D028(&t, &t, mat);
        __asm__ __volatile__(
            "lqc2 $vf1, 0(%1)\n"
            "lqc2 $vf2, %2\n"
            "vadd.xyz $vf1, $vf1, $vf2\n"
            "sqc2 $vf1, 0(%0)\n"
            : : "r"(out), "r"(in), "m"(t) : "memory");
    }
}
/* localdecomp:end func_L39_00632988 */

INCLUDE_ASM("asm/levels", func_L39_00632A20);

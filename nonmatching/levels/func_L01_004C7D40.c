/* PAL near miss (haiku-w1): 6 words differ with the file's flags (-O2 -G8 -fopt-stack -mno-check-zero-division @ps2as); the j-form needs -mvu0-use-vf0-vf2, which the file line lacks; the one-block volatile VU0 form keeps the sqc2 and the epilogue ld $ra/$s0 out of their retail order (sd $ra, move $a1 order in the prologue). */
#include "common.h"
#include "vu0.h"

typedef struct {
    f32 x, y, z, w;
} __attribute__((aligned(16))) Vec4_004C4AD8;

extern void func_L01_004C7D98(void *, void *);
extern void func_0038CE20(Vec4_004C4AD8 *, Vec4_004C4AD8 *, f32);

void func_L01_004C7D40(void *obj, f32 *pos, f32 s) {
    Vec4_004C4AD8 v;

    func_L01_004C7D98(obj, &v);
    func_0038CE20(&v, &v, s);
    __asm__ __volatile__(
        "lqc2 $vf1, 0(%0)\n"
        "lqc2 $vf2, 0(%1)\n"
        "vsub.xyz $vf1, $vf1, $vf2\n"
        "sqc2 $vf1, 0(%0)\n"
        : : "r"(pos), "r"(&v) : "memory", "vf1", "vf2");
}

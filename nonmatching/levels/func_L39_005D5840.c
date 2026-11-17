/* NTSC-U draft (2026-11-14, Codex worker): C of func_L39_005D32D0, the NTSC-U twin of func_L39_005D5840, with NTSC-U names
 * and addresses. Byte-exact on NTSC-U with "-O2 -G8 -fopt-stack -mno-check-zero-division" when tried; not with src/levels/shared/L39_005D5840.c's current line.
 * Worker's note: 67 diff; best log func_L39_005D32D0.1.log; allowed flags emit lit4 loads for 0x3991A2B4 versus retail inline lui/ori/mtc1; VU0 scheduling also differs
 */
#include "common.h"
/* localdecomp:start func_L39_005D32D0 */
typedef struct { char pad[8]; float z, scale, grow; u8 step, pad15; short gravity; int a, b; } P87;
typedef struct { int a, color; u8 alpha, pad9; short life; float size; float pos[4]; P87 p; } E87;
extern int func_003883C8(short *);
extern void func_003C7CE0(void *);
extern int func_003894A0(int, int, float);
extern void func_L39_005FD3A8(void *, void *);
extern int D_L39_00242B3C[];
extern void func_L39_005FC9F8(int, void *, void *);
extern void func_00388830(void *, void *, float);
void func_L39_005D32D0(E87 *e) {
    float v[4] __attribute__((aligned(16)));
    P87 *p;
    float *pos;
    if (func_003883C8(&e->life)) { func_003C7CE0(e); return; }
    p = &e->p;
    pos = e->pos;
    e->color = func_003894A0(p->b, p->a, e->life * p->scale);
    __asm__("lqc2 $vf1, %1\n\tlqc2 $vf2, %2\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0" : "=m"(*(int (*)[4])pos) : "m"(*(int (*)[4])pos), "m"(*(int (*)[4])p) : "vf1", "vf2");
    func_L39_005FD3A8(pos, pos);
    if (!D_L39_00242B3C[0]) p->z -= p->gravity * 0.0078125f * 0.00027777778450399637f;
    else {
        func_L39_005FC9F8(0, pos, v);
        func_00388830(v, v, -(p->gravity * 0.0078125f * 0.00027777778450399637f));
        __asm__("lqc2 $vf1, %1\n\tlqc2 $vf2, %2\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0" : "=m"(*(int (*)[4])pos) : "m"(*(int (*)[4])pos), "m"(*(int (*)[4])v) : "vf1", "vf2");
    }
    e->alpha += p->step;
    e->size += p->grow;
}
/* localdecomp:end func_L39_005D32D0 */

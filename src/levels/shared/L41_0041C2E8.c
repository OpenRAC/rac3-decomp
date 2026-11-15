#include "common.h"

/* types of func_L41_0041C328, from upstream's L41_0041B308.c */
typedef struct { s32 f0; f32 f4; s32 f8; s32 fC; } V_0041C328;
typedef struct { u8 p0[0x68]; V_0041C328 *vars; u8 p6C[0x100 - 0x6C]; } M_0041C328;

/* declared by functions of L41_0041B308.c, which this file was cut from */
extern void func_L41_0041C170(void *, s32);

/* localdecomp:start func_L41_0041C2E8 */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_0041C2E8;
extern s32 func_L39_005BE900(void *, s32, f32);

s32 func_L41_0041C2E8(V4_0041C2E8 *p) {
    V4_0041C2E8 v = *p;
    s32 r;

    v.w = 1.0f;
    r = ((s32 (*)(void *, s32))func_L39_005BE900)(&v, 0);
    return ~r >> 31 != 0;
}
/* localdecomp:end func_L41_0041C2E8 */

/* localdecomp:start func_L41_0041C328 */
extern M_0041C328 *D_L41_0024865C;
extern void func_L41_0041C170(void *, s32);
void func_L41_0041C328(M_0041C328 *m, s32 a1) {
    V_0041C328 *v = m->vars;
    M_0041C328 *a;
    M_0041C328 *b;
    M_0041C328 *r;

    a = v->f8 >= 0 ? &D_L41_0024865C[v->f8] : 0;
    b = v->fC >= 0 ? &D_L41_0024865C[v->fC] : 0;
    r = 0;
    if (a == 0 || b == 0) {
        if (a != 0) {
            r = a;
        } else if (b != 0) {
            r = b;
        }
    } else {
        V_0041C328 *av = a->vars;
        V_0041C328 *bv = b->vars;
        if (av->f4 > 0.0f && bv->f4 > 0.0f) {
            r = av->f4 < bv->f4 ? a : b;
        } else if (av->f4 > 0.0f) {
            r = a;
        } else if (bv->f4 > 0.0f) {
            r = b;
        }
    }
    if (r != 0) {
        V_0041C328 *rv = r->vars;
        func_L41_0041C170(r, a1);
        rv->f4 = 0;
    }
}
/* localdecomp:end func_L41_0041C328 */

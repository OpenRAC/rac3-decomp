#include "common.h"

/* localdecomp:start func_L16_003E93F8 */
typedef struct {
    f32 x, y, z, w;
} __attribute__((aligned(16))) V_003E93F8;

typedef struct {
    V_003E93F8 v[4];
    f32 f40[4];
    f32 t[4];
    f32 f60;
    f32 f64;
    u8 p68[6];
    u8 b6E;
    u8 p6F;
    V_003E93F8 v70;
    V_003E93F8 v80;
} S_003E93F8;

extern void func_L16_003E8D20(V_003E93F8 *, V_003E93F8 *, f32, f32);
extern f32 func_0038CF38(void *, void *);
extern f32 func_003824E0(f32, f32);
extern void func_L16_003E92B8(void *, u8 *, f32 *);
__asm__(".extern D_L16_001DF63C, 4");
extern f32 D_L16_001DF63C;
__asm__(".extern D_L16_001DF640, 4");
extern f32 D_L16_001DF640;

void func_L16_003E93F8(u8 *a0) {
    S_003E93F8 *m = *(S_003E93F8 **)(a0 + 0x68);
    s32 i;

    for (i = 0; i < 4; i++) {
        if (i < (s32)(m->b6E * 0.5f)) {
            func_L16_003E91B0(a0, (u8 *)&m->v[i], &m->t[i]);
        } else {
            if (D_L16_001DF63C + D_L16_001DF640 < m->v[i].w) {
                f32 d;
                func_L16_003E8D20(&m->v[i], &m->v70, 0.25f, 0.75f);
                d = func_0038CF38(&m->v[i], &m->v80);
                if (m->f60 * 0.4f < d) {
                    func_L16_003E8D20(&m->v[i], &m->v80, 1.0f, 3.0f);
                }
                m->v70 = m->v[i];
                m->v[i].w = D_L16_001DF63C + func_003824E0(0.0f, 0.3f);
                m->t[i] = m->f64 * func_003824E0(0.75f, 0.95f);
            }
            func_L16_003E92B8(a0, (u8 *)&m->v[i], &m->t[i]);
        }
    }
}
/* localdecomp:end func_L16_003E93F8 */

/* localdecomp:start func_L16_003E95A8 */
extern void func_L01_004048D0(void *, u8 *);
extern f32 func_0038CF38(void *, void *);
extern void func_L01_004450F0(s32, s32, s32);
extern void func_003C2880(void *);
extern void func_L16_003E93F8();
extern u8 D_1A4C60[];

void func_L16_003E95A8(u8 *o) {
    s32 k = o[0x20];
    f32 d;

    switch (k) {
    case 0:
        func_L01_004450F0((s32)o, 1, -1);
        break;
    case 1:
        func_L01_004048D0(func_L16_003E93F8, o);
        d = func_0038CF38(D_1A4C60, o + 0x10);
        if (40.0f < d) {
            func_L01_004450F0((s32)o, 2, -1);
        }
        break;
    case 2:
        func_003C2880(o);
        break;
    }
}
/* localdecomp:end func_L16_003E95A8 */

INCLUDE_ASM("asm/levels", func_L16_003E9660);

INCLUDE_ASM("asm/levels", func_L16_003E9ED8);

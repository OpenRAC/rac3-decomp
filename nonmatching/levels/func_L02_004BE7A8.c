/* Level 02 (Florana), PAL. 22 diff with check.py --target level_02. 22 differences, all the prologue/epilogue: retail saves callee-saved registers with 16-byte `sq` slots in a 0xD0 frame, this compiler gives 8-byte `sd` slots in a 0x80 frame (the `sq_ra` class). Body and register allocation match; `pv = &v` kept through every use is what gives retail's `move $s2,$sp`. Levels have no `sq_ra_funcs` table, so it cannot be reached with the file's flags. Needs `@ps2as`. */
#include "common.h"

typedef struct V4_4BE7A8 { f32 x, y, z, w; } __attribute__((aligned(16))) V4_4BE7A8;
typedef struct Q_4BE7A8 { f32 x, y, z, w; } Q_4BE7A8;
typedef struct L_4BE7A8 { s32 n; s32 p4, p8, pc; Q_4BE7A8 q[1]; } L_4BE7A8;
typedef struct E_4BE7A8 { s32 f0, f4, f8; f32 fC; L_4BE7A8 *f10; s32 f14; s32 f18, f1C; } E_4BE7A8;
typedef struct P_4BE7A8 { u8 pad[0x25E4]; u8 mode; } P_4BE7A8;

extern E_4BE7A8 *D_L02_001DE610;
__asm__(".extern D_L02_001DE610, 16");
extern s32 D_L02_001DE614;
__asm__(".extern D_L02_001DE614, 16");
extern E_4BE7A8 *D_001DE610_sda;
__asm__(".extern D_001DE610_sda, 4");
extern s32 D_001DE614_sda;
__asm__(".extern D_001DE614_sda, 4");
extern P_4BE7A8 D_1A4BE0;
extern f32 func_0038CF00(void *, void *);
extern f32 func_0038CF38(void *, void *);
extern s32 func_L01_00476B98(s32, void *, void *, s32 *, f32 *, s32, f32, f32, f32);

s32 func_L02_004BE7A8(V4_4BE7A8 *a0, s32 *a1, V4_4BE7A8 *a2, s32 *a3, f32 *a4, s32 *a5, s32 a6, s32 a7)
{
    V4_4BE7A8 v = *a0;
    V4_4BE7A8 *pv = &v;
    s32 x;
    f32 y;
    s32 i;
    for (i = 0; i < D_L02_001DE614; i++) {
        L_4BE7A8 *l;
        if (a6 == 0 || D_L02_001DE610[i].f10 != (L_4BE7A8 *)a6) {
            if (D_1A4BE0.mode == 5 && (l = D_L02_001DE610[i].f10) != 0) {
                if (__builtin_fabsf(l->q[0].x - l->q[l->n - 1].x) < 0.1f) continue;
            }
            if (a7 == 0 || D_L02_001DE610[i].f10 == (L_4BE7A8 *)a7) {
                if (D_L02_001DE610[i].f10->n != 0) {
                    f32 r = func_0038CF00(&D_L02_001DE610[i], pv);
                    if (!(D_L02_001DE610[i].fC < r)) {
                        if (func_L01_00476B98((s32)D_L02_001DE610[i].f10, pv, a2, &x, &y, D_L02_001DE610[i].f14, 12.0f, 10.0f, 0.0f)) {
                            if (func_0038CF38(pv, a2) < 1.7f) {
                                if (__builtin_fabsf(pv->z - a2->z) < 1.5f) {
                                    *a1 = (s32)D_001DE610_sda[i].f10;
                                    *a3 = x;
                                    *a4 = y;
                                    *a5 = D_L02_001DE610[i].f14;
                                    return 1;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return 0;
}

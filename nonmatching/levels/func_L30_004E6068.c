/* PAL near miss (Sonnet worker b10-u1): 12 diff with the file's flags (-O2 -G8 -fopt-stack @ps2as, no extra options), levels 30-36.
 * Only register names differ: retail keeps the path's count and its (n - 1) * 16 offset and the last-point address all in $v0 and the
 * hero pointer in $v1; this C puts the count in $v1, the address in $v0 and the hero pointer in $a0.
 * The prelude below is the file's own declaration of D_001A4BE0 plus vu0.h (fabs_asm).
 */
#include "common.h"
#include "vu0.h"

typedef struct {
    u8 pad0[0x25C0];
    u8 *p25C0;
    s32 w25C4;
} S_004E6988;
extern S_004E6988 D_001A4BE0;

/* localdecomp:start func_L30_004E6068 */
typedef struct {
    u8 pad0[0x80];
    f32 f80;
    u8 pad84[4];
    f32 f88;
    u8 pad8C[0x1E0 - 0x8C];
    s16 h1E0;
    u8 pad1E2[0x25C4 - 0x1E2];
    s32 w25C4;
    u8 pad25C8[0x2840 - 0x25C8];
    f32 f2840;
} S_004E6068;
typedef struct {
    f32 x;
    f32 y;
    f32 z;
    f32 w;
} Pt_004E6068;
typedef struct {
    s32 n;
    u8 pad4[0xC];
    Pt_004E6068 pts[1];
} Path_004E6068;
typedef struct {
    u8 pad0[0x10];
    Path_004E6068 *path;
    u8 pad14[0xC];
} Ent_004E6068;
extern s32 D_L30_001DF414;
extern Ent_004E6068 *D_L30_001DF410;
extern f32 func_0038DBA0(f32, f32);

Path_004E6068 *func_L30_004E6068(void) {
    s32 i;
    Path_004E6068 *p;

    if (((S_004E6068 *)&D_001A4BE0)->h1E0 != 0) return 0;
    if ((u32)(((S_004E6068 *)&D_001A4BE0)->w25C4 - 0x9A) >= 2 && ((S_004E6068 *)&D_001A4BE0)->w25C4 != 0xA2 && ((S_004E6068 *)&D_001A4BE0)->w25C4 != 0x9C) return 0;
    for (i = 0; i < D_L30_001DF414; i++) {
        p = D_L30_001DF410[i].path;
        if (p->n == 0) continue;
        if (1.0f < fabs_asm(p->pts[0].x - p->pts[p->n - 1].x)) continue;
        if (!(fabs_asm(p->pts[0].x - ((S_004E6068 *)&D_001A4BE0)->f80) < 0.8f)) continue;
        if (!(((S_004E6068 *)&D_001A4BE0)->f88 < p->pts[p->n - 1].z - 0.5f)) continue;
        if (!(p->pts[0].z - 0.5f < ((S_004E6068 *)&D_001A4BE0)->f88)) continue;
        if (func_0038DBA0(((S_004E6068 *)&D_001A4BE0)->f2840, 1.5707964f) < 0.5235988f) return p;
    }
    return 0;
}
/* localdecomp:end func_L30_004E6068 */

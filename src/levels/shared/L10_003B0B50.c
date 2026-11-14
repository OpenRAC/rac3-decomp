#include "common.h"

typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_003B10C8;
typedef struct { u8 pad0[0x12]; s16 count; u8 pad14[0xC]; s32 *ids; u8 pad24[0xC]; } Path_003B10C8;
typedef struct { s32 count; u8 pad4[0x1C]; Path_003B10C8 paths[1]; } Paths_003B10C8;
typedef struct { u8 pad0[0x30]; V4_003B10C8 pos; u8 pad40[0x40]; } Node_003B10C8;

INCLUDE_ASM("asm/levels", func_L10_003B0B50);

INCLUDE_ASM("asm/levels", func_L10_003B0F78);

/* localdecomp:start func_L10_003B10C8 */
#include "vu0.h"

extern Paths_003B10C8 *D_L10_001DEF4C;
__asm__(".extern D_L10_001DEF4C, 16");
extern Node_003B10C8 *D_L10_001DF380;
__asm__(".extern D_L10_001DF380, 16");
extern f32 func_L01_0040E570(void *, void *);
extern void func_0038CE20(void *, void *, f32);
extern s32 func_003D3CB0(void *, void *, s32, void *, void *);
extern int func_00382380(void *, int, int);

s32 func_L10_003B10C8(u8 *m, s32 idx, f32 *out, void *a3, void *a4, s32 flag)
{
    V4_003B10C8 *home = a3;
    s32 *cur = a4;
    Path_003B10C8 *path;
    V4_003B10C8 pos;
    V4_003B10C8 tgt;
    V4_003B10C8 dir;
    f32 d;
    f32 nd;
    f32 lim;
    s32 best;
    s32 i;
    s32 id;
    Node_003B10C8 *e;

    if (idx >= 0 && idx < D_L10_001DEF4C->count) {
    path = &D_L10_001DEF4C->paths[idx];
    pos = *(V4_003B10C8 *)(m + 0x10);
    tgt = *(V4_003B10C8 *)out;
    pos.z += 1.0f;
    tgt.z += 1.0f;
    d = func_L01_0040E570(&pos, &tgt);
    vec_sub_ab(&dir, &tgt, &pos);
    func_0038CE20(&dir, &dir, sqrt_asm(d));
    if (flag == 0 && func_003D3CB0(&pos, &tgt, 0, m, 0) == 0) {
        *cur = -1;
        *home = *(V4_003B10C8 *)out;
        return 1;
    }
    lim = d * 4.0f;
    best = -1;
    for (i = 0; i < path->count; i++) {
        id = path->ids[i];
        e = &D_L10_001DF380[id];
        if (id == *cur)
            continue;
        if (func_00382380(&pos, id, 0) != 0) {
            *cur = path->ids[i];
            continue;
        }
        nd = func_L01_0040E570(&tgt, &e->pos);
        if (lim < nd)
            continue;
        if (func_003D3CB0(&pos, &e->pos, 0, m, 0) != 0)
            continue;
        lim = nd;
        best = i;
    }
    if (best < 0) {
        if (func_L01_0040E570(m + 0x10, home) > 0.040000003f)
            *(V4_003B10C8 *)out = *home;
        else
            return 0;
    } else {
        *(V4_003B10C8 *)out = D_L10_001DF380[path->ids[best]].pos;
    }
    }
    return 1;
}
/* localdecomp:end func_L10_003B10C8 */

LINKER_REMNANT("asm/levels", func_L10_003B1350);

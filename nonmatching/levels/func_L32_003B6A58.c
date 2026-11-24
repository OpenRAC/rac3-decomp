/* Unlinked regional matching draft. PAL: 25 to 24 words; the typed slot table corrects a reload's operand order, but allocation still differs. */
#include "common.h"

/* localdecomp:start func_L32_003B6A58 */
extern s32 D_L32_001DF9C0;
extern s32 D_L32_001DEE70;
extern s32 D_L32_001DEE70_sdata[] __attribute__((section(".sdata")));
typedef int u128_003B6A58 __attribute__((mode(TI)));
typedef struct Q_003B6A58 {
    u8 pad00[0x80];
    u8 f80[0x210 - 0x80];
} Q_003B6A58;
typedef struct R_003B6A58 {
    u8 pad00[0x68];
    Q_003B6A58 *f68;
    u8 pad6C[0x100 - 0x6C];
} R_003B6A58;
extern R_003B6A58 *D_L32_001DFE1C[] __attribute__((section(".sdata")));

typedef struct {
    u8 pad00[0x68];
    f32 *geometry;
} Spawned_003B6A58;
typedef struct {
    u8 pad00[0x130];
    f32 anchorX;
    u8 pad134[0x1C];
    struct SpawnTable_003B6A58 { Spawned_003B6A58 *items[48]; } slots;
    u8 pad210[0x14];
    f32 band0, band1, maxX;
    s32 tile;
    u8 pad234[4];
    f32 minX;
    u8 pad23C[0x14];
    f32 anchorZ;
} SpawnerState_003B6A58;
typedef struct {
    u8 pad00[0x10];
    f32 x, y, z;
    u8 pad1C[0x4C];
    SpawnerState_003B6A58 *state;
} Spawner_003B6A58;
void func_L32_003B6A58(Spawner_003B6A58 *obj)
{
    extern void func_003C2F58(void *, s32, void *);
    extern s32 func_00382498(s32, s32);
    extern Spawned_003B6A58 *func_L32_0039FE78(u128_003B6A58 *, s32, s32, f32 *, f32 *);
    SpawnerState_003B6A58 *st;
    struct SpawnTable_003B6A58 *tbl;
    Spawned_003B6A58 **q, **slot;
    s32 i, flag, found, n, j, lo, hi, off, size;
    u128_003B6A58 vec;
    f32 y;
    f32 *p;

    flag = 0;
    st = obj->state;
    tbl = &st->slots;
    q = tbl->items;
    i = 0x2F;
loop1:
    if (*q != 0) {
        if (!(((u8 *)*q)[0x20] < 0xFD)) {
            *q = 0;
        }
    }
    i--;
    q++;
    if (i >= 0) goto loop1;
    y = obj->x;
    if (!(st->maxX < y)) {
        if (st->band1 < y) {
            flag = (D_L32_001DF9C0 % D_L32_001DEE70_sdata[2]) == 0;
        } else if (st->band0 < y) {
            flag = (D_L32_001DF9C0 % D_L32_001DEE70_sdata[1]) == 0;
        } else if (st->minX < y) {
            flag = (D_L32_001DF9C0 % D_L32_001DEE70) == 0;
        }
    }
    if (flag) {
        found = 0;
        i = 0;
        size = 0x210;
        for (; i < 0x30 && !found; i++) {
            slot = &tbl->items[i];
            if (*slot == 0) {
                found = 1;
                func_003C2F58(obj, 1, &vec);
                if (obj->x > st->band1) {
                    hi = 3;
                    lo = 2;
                } else {
                    hi = 1;
                    lo = 0;
                }
                n = func_00382498(lo, hi);
                off = n * size + 0x80;
                *slot = func_L32_0039FE78(&vec, (s32)D_L32_001DFE1C[0][st->tile].f68 + off, 1, 0, 0);
                if (tbl->items[i] != 0) {
                    p = tbl->items[i]->geometry + 64;
                    for (j = 0x1F; j >= 0; j--, p++) {
                        p[-0x20] += obj->x - st->anchorX;
                        p[0] += obj->z - st->anchorZ;
                    }
                }
            }
        }
    }
}
/* localdecomp:end func_L32_003B6A58 */

#include "common.h"

typedef struct Node_003C5DC0 {
    u8 pad00[0x20];
    s32 f20;
    u8 pad24[0x14];
    u8 f38;
    u8 f39;
    s16 f3A;
    s32 f3C;
    u8 pad40[4];
    u8 f44;
    u8 pad45[7];
    s32 f4C;
} Node_003C5DC0;
typedef struct Elem_003C5DC0 {
    u8 pad00[0x1C];
    Node_003C5DC0 *f1C;
} Elem_003C5DC0;
typedef struct Cnt_003C5DC0 {
    s32 n;
    u8 pad04[0x18];
} Cnt_003C5DC0;
typedef struct Ent_003C5DC0 {
    f32 v;
    s32 pad04[3];
} Ent_003C5DC0;

/* localdecomp:start func_L02_003C5DC0 */
extern Elem_003C5DC0 *D_L02_001DE184;
extern Cnt_003C5DC0 *D_L02_0021C700[];

void func_L02_003C5DC0(s32 idx)
{
    Elem_003C5DC0 *el;
    Node_003C5DC0 *nd;
    Cnt_003C5DC0 *cnt;
    Ent_003C5DC0 *e;
    s32 j;
    s32 k;
    s32 off;

    off = idx << 5;
    nd = ((Elem_003C5DC0 *)(off + (s32)D_L02_001DE184))->f1C;
    k = nd->f3A;
    nd->f44 = 0;
    nd->f38 = 0;
    nd->f39 = 0;
    if (k != 0) {
        nd->f3C = 0;
    }
    if (nd->f20 >= 0) {
        cnt = D_L02_0021C700[nd->f20];
        j = 0;
        if (cnt->n > 0) {
            e = (Ent_003C5DC0 *)((u8 *)cnt + 0x1C);
            do {
                e->v = -1.0f;
                j++;
                e++;
            } while (j < cnt->n);
        }
    }
    if (nd->f4C != -1) {
        func_L02_003C5DC0(nd->f4C);
    }
}
/* localdecomp:end func_L02_003C5DC0 */

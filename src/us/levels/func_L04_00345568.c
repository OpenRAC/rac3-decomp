#include "common.h"

typedef struct Table_003460F8 {
    s32 entries[64];
    s32 count;
} Table_003460F8;
typedef struct Obj_003460F8 {
    u8 pad0[0x20];
    u8 state;
    u8 pad21[0xF];
    u8 flag;
    u8 pad31[0x37];
    Table_003460F8 *table;
} Obj_003460F8;

/* localdecomp:start func_L04_00345568 */
extern u8 D_001A4BE0[];
extern u8 D_001A4C60[];
extern s32 func_0037E0F0(void *, s32, s32);
extern void func_00385B60(s32);
extern void func_L01_004EA040(void);
extern void func_L04_00508950(s32, s32);

/* Moby update: state 0 just initializes; state 1 checks each entry of its table with
 * point_in_cuboid and, when hit, either kills the hero via func_L01_004EA040 or triggers
 * func_L04_00508950, depending on the table's count and hero state. */
void func_L04_00345568(Obj_003460F8 *a0)
{
    Table_003460F8 *t = a0->table;
    s32 *e;
    u8 *q;
    u8 *m;
    s32 i;
    s32 j;
    s32 v;

    switch (a0->state) {
    case 0:
        a0->state = 1;
        a0->flag = 0xFF;
        break;
    case 1:
        q = D_001A4BE0;
        e = t->entries + 32;
        for (i = 0; i < 32; i++) {
            v = t->entries[i];
            if (v < 0)
                continue;
            if (func_0037E0F0(D_001A4C60, v, 0) == 0)
                continue;
            if (t->count != 0) {
                *(f32 *)(q + 0x284C) = 0.25f;
                continue;
            }
            m = D_001A4C60 - 0x80;
            if (m[0x25E4] != 0) {
                func_00385B60(10);
                func_L01_004EA040();
            } else if (*(s32 *)(m + 0x25C4) != 0x79) {
                func_L04_00508950(0x79, 1);
            }
        }
        for (j = 0; j < 32; j++) {
            v = e[j];
            if (v < 0)
                continue;
            if (func_0037E0F0(D_001A4C60, v, 0) == 0)
                continue;
            func_00385B60(10);
            func_L01_004EA040();
        }
        break;
    }
}
/* localdecomp:end func_L04_00345568 */

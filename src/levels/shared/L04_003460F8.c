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

/* localdecomp:start func_L04_003460F8 */
extern u8 D_001A4BE0[];
extern u8 D_001A4C60[];
extern s32 func_00382380(void *, s32, s32);
extern void func_0038A238(s32);
extern void func_L01_004EDE10(void);
extern void func_L04_0050CB28(s32, s32);

void func_L04_003460F8(Obj_003460F8 *a0)
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
            if (func_00382380(D_001A4C60, v, 0) == 0)
                continue;
            if (t->count != 0) {
                *(f32 *)(q + 0x284C) = 0.25f;
                continue;
            }
            m = D_001A4C60 - 0x80;
            if (m[0x25E4] != 0) {
                func_0038A238(8);
                func_L01_004EDE10();
            } else if (*(s32 *)(m + 0x25C4) != 0x79) {
                func_L04_0050CB28(0x79, 1);
            }
        }
        for (j = 0; j < 32; j++) {
            v = e[j];
            if (v < 0)
                continue;
            if (func_00382380(D_001A4C60, v, 0) == 0)
                continue;
            func_0038A238(8);
            func_L01_004EDE10();
        }
        break;
    }
}
/* localdecomp:end func_L04_003460F8 */

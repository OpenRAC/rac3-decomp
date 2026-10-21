#include "common.h"

INCLUDE_ASM("asm/levels", func_L01_004A9E58);

/* localdecomp:start func_L01_004AA710 */
extern u8 D_001A30B0[];

int func_L01_004AA710(int a0, int a1)
{
    if (a1 >= 0) {
        u8 *p = D_001A30B0 + a1 * 128;
        if (*(int *)(p + 220) == a0) {
            u8 b = p[208];
            if ((u32)(b - 1) < 2 || b == 7) {
                return 1;
            }
        }
    }
    return 0;
}
/* localdecomp:end func_L01_004AA710 */

/* localdecomp:start func_L01_004AA760 */
typedef struct {
    u8 pad0[10];
    s16 f10;
    u8 pad12[16];
    s32 f28;
    u8 pad32[96];
} Ent_004A6D70;

extern Ent_004A6D70 D_001A3170[];
extern void func_003A4F28(s32);

void func_L01_004AA760(s32 arg0, s32 arg1)
{
    Ent_004A6D70 *p;
    s32 i;

    p = D_001A3170;
    for (i = 0; i < 52; i++, p++) {
        if ((arg1 == 0 || arg1 == p->f28) && arg0 == p->f10) {
            func_003A4F28(i);
        }
    }
}
/* localdecomp:end func_L01_004AA760 */

/* localdecomp:start func_L01_004AA7E8 */
extern Ent_004A6D70 D_001A3170[];
typedef struct {
    u8 pad0[28];
    u8 *owner;
    u8 pad20[56];
    s32 flags;
    u8 pad5C[36];
} Entry_004A6DF8;

extern void func_003A4F28(s32);

void func_L01_004AA7E8(u8 *obj, s32 check)
{
    s32 i;
    Entry_004A6DF8 *e;

    if (obj == 0) {
        return;
    }
    e = ((Entry_004A6DF8 *)&D_001A3170);
    for (i = 0; i < 52; i++, e++) {
        if (obj == e->owner) {
            if (check == 0 || (e->flags & 4)) {
                func_003A4F28(i);
            }
        }
    }
    obj[109] = 255;
}
/* localdecomp:end func_L01_004AA7E8 */

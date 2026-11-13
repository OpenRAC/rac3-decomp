#include "common.h"

/* localdecomp:start func_L39_006CB348 */
typedef struct S_006CB348G { u8 pad[0x54]; void *f54; } S_006CB348G;
__asm__(".extern D_L39_0024D760, 16");
extern S_006CB348G *D_L39_0024D760;
extern u8 D_L39_00249A18[];
extern u8 D_L39_00249A20[];
extern s32 func_L39_006DD860(void *, s32);
extern s32 func_00120B70(void *, void *, s32);

typedef struct S_006CB348E { s32 f0; s32 count; s32 *list; } S_006CB348E;
typedef struct S_006CB348D { u8 pad[0x60]; void **vt; } S_006CB348D;
typedef struct S_006CB348L { u8 pad[0x2F89]; u8 f2F89; u8 pad2[6]; s32 f2F90; s32 f2F94; s32 pad3; S_006CB348E ents[1]; } S_006CB348L;
typedef struct S_006CB348O { u8 pad[0x114]; S_006CB348D *dev; u8 pad2[0x2A8 - 0x118]; u8 f2A8; u8 pad3[3]; s32 f2AC; s32 f2B0; } S_006CB348O;

void func_L39_006CB348(S_006CB348O *object)
{
    S_006CB348L *level;
    S_006CB348E *entry;
    struct { void *a; void *b; } pairs[0x40];
    s32 i;
    s32 count;
    u8 *tag;
    u8 flag;
    s32 max = 0x3F;

    level = (S_006CB348L *)D_L39_0024D760->f54;
    entry = 0;
    if (level->f2F94 >= 0) {
        entry = &level->ents[level->f2F94];
    }
    if (object->f2A8 != 0 && level->f2F89 == 0) {
        func_L39_006DD860(level, 1);
        object->f2A8 = 0;
    }
    flag = level->f2F89;
    if (flag == 0 && entry != 0) {
        if (object->f2AC != level->f2F90) {
            object->f2AC = level->f2F90;
            tag = D_L39_00249A18;
            object->f2B0 = entry->count > max ? 0x40 : entry->count;
            count = 0;
            for (i = 0; i < object->f2B0; i++) {
                u8 *cur = (u8 *)entry->list[i] + 0x20;
                if (func_00120B70(cur, D_L39_00249A20, 5) == 0) {
                    pairs[count].a = cur;
                    pairs[count].b = tag;
                    count++;
                }
            }
            object->f2B0 = count;
            ((void (*)(void *, s32, void *))object->dev->vt[0x6C / 4])(object->dev, count * 2, pairs);
            ((void (*)(void *, s32, void *))object->dev->vt[0x20 / 4])(object->dev, 2, 0);
        }
    }
}
/* localdecomp:end func_L39_006CB348 */

LINKER_REMNANT("asm/levels", func_L39_006CB4C8);

INCLUDE_ASM("asm/levels", func_L39_006CB4D8);

/* localdecomp:start func_L39_006CB8B0 */
extern u8 D_L39_0047EFC0[];
extern void func_L39_00688400(u8 *, s32);

/* from rac4-decomp's func_004EE7B0, renamed, constants adapted */
void func_L39_006CB8B0(void *object, s32 flags)
{
    *(void **)((u8 *)object + 96) = D_L39_0047EFC0;
    func_L39_00688400(object, flags);
}
/* localdecomp:end func_L39_006CB8B0 */

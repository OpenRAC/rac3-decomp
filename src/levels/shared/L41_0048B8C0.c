#include "common.h"

typedef struct {
    u8 pad0[0x10];
    f32 x, y, z;
    u8 pad1c[0x34 - 0x1C];
    u16 flags;
} Obj_0048B8C0;
typedef struct {
    u8 pad0[0x30];
    f32 x, y, z;
    u8 pad3c[4];
} Ent_0048B8C0;
typedef struct {
    u8 pad0[0x10];
    u16 w;
    u8 pad12[0x0E];
} Slot_0048B8C0;

/* localdecomp:start func_L41_0048B8C0 */
extern s32 func_L03_0043C438(void *);
extern void func_L39_005F62A0(s32, s32);
__asm__(".extern D_L41_002490FC, 16");
extern Ent_0048B8C0 *D_L41_002490FC;
__asm__(".extern D_L41_002490F4, 16");
extern Slot_0048B8C0 *D_L41_002490F4;
extern Slot_0048B8C0 *D_L41_00249148[];
__asm__(".extern D_L41_00241120, 16");
extern s32 *D_L41_00241120;

void func_L41_0048B8C0(Obj_0048B8C0 *o)
{
    s32 idx;
    s32 i;
    Ent_0048B8C0 *e;
    s32 *cnt;

    idx = func_L03_0043C438(o);
    if (idx == -1) {
        return;
    }
    o->flags |= 0x41;
    e = &D_L41_002490FC[idx];
    e->x = o->x;
    e->y = o->y;
    e->z = o->z;
    D_L41_002490F4[idx].w = 0x7F80;
    cnt = D_L41_00241120;
    if (*cnt >= 2) {
        for (i = 1; i < *cnt; i++) {
            D_L41_00249148[i][idx].w = 0x7F80;
        }
    }
    func_L39_005F62A0(idx, 1);
}
/* localdecomp:end func_L41_0048B8C0 */

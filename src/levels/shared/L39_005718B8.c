#include "common.h"

typedef struct {
    u8 pad0[0x460];
} Ent_005718B8;
typedef struct {
    u8 pad0[0x30];
    u8 pos[0x50];
} Pt_005718B8;
typedef struct {
    s32 x0;
    s32 x4;
    s32 x8;
    s32 xC;
    s32 x10;
    u8 pad14[0x26 - 0x14];
    s16 x26;
    u8 pad28[0x34 - 0x28];
    s32 x34;
    u8 pad38[0x4A - 0x38];
    s16 x4A;
} Info_005718B8;
typedef struct {
    u8 pad0[0x1C];
    Info_005718B8 *info;
} Row_005718B8;

/* localdecomp:start func_L39_005718B8 */
extern Ent_005718B8 D_L39_0024DE80[];
extern Row_005718B8 *D_L39_0024B850;
extern Pt_005718B8 *D_L39_0024C000;
extern f32 func_0038CF38(void *, void *);
extern s32 func_00382380(void *, s32, s32);
extern s32 func_L01_0044BFC8(void *, s32);
extern s32 func_L01_0044C078(void *, s32);

s32 func_L39_005718B8(u8 *a)
{
    Info_005718B8 *p = D_L39_0024B850[*(s16 *)(a + 0x84)].info;
    u8 *ent = (u8 *)((s32)D_L39_0024DE80 + *(s32 *)(a + 0x94) * 0x460);
    u8 *owner = *(u8 **)(ent + 0x50);
    u8 *sub = *(u8 **)(owner + 0x70);
    u8 *move = sub + 0x180;
    u8 *rot = sub + 0x1E0;
    u8 *st = ent + 0x150;
    s32 mode;

    if (*(s16 *)(owner + 0x86) != 0) return 0;
    if (p->x4A != 0) return 0;
    if (p->x34 != 0) {
        if (__builtin_fabsf(*(f32 *)(move + 0x34)) > 0.01f) return 0;
        if (__builtin_fabsf(*(f32 *)(rot + 8)) > 0.01f) return 0;
    }
    mode = *(s32 *)(st + 0x100);
    if ((u32)(mode - 0x64) >= 2 && *(f32 *)(st + 0x110) > 0.020000001f) return 0;
    if (p->xC >= 0) {
        if (*(s32 *)(st + 0x100) == 0x64 && func_0038CF38(st + 0x40, &D_L39_0024C000[p->xC].pos) < 3.0f) return 1;
        if (func_00382380(st + 0x40, p->xC, 0)) return 1;
    }
    if (p->x10 >= 0) {
        if (*(s32 *)(st + 0x100) == 0x64 && func_0038CF38(st + 0x40, &D_L39_0024C000[p->x10].pos) < 3.0f) return 1;
        if (func_L01_0044BFC8(st + 0x40, p->x10)) return 1;
    }
    if (p->x8 >= 0) {
        if (*(s32 *)(st + 0x100) == 0x64 && func_0038CF38(st + 0x40, &D_L39_0024C000[p->x8].pos) < 3.0f) return 1;
        if (func_L01_0044C078(st + 0x40, p->x8)) return 1;
    }
    p->x26 = 1;
    return 0;
}
/* localdecomp:end func_L39_005718B8 */

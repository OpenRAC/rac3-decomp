#include "common.h"

/* NTSC-U counterpart of func_L39_006B8AC8 (src/levels/39_multiplayer_menu/L39_006B8458.c) */
extern void func_L39_006B6010(void *, s32);

/* localdecomp:start func_L39_006B6010 */
typedef struct S_006B8AC8 {
    /* 0x000 */ s32 f0;
    /* 0x004 */ u8 pad4[0x19];
    /* 0x01D */ u8 f1D[0x20];
    /* 0x03D */ u8 f3D[0x10];
    /* 0x04D */ u8 f4D;
    /* 0x04E */ u8 f4E;
    /* 0x04F */ u8 f4F;
    /* 0x050 */ u8 f50;
    /* 0x051 */ u8 pad51[0x11F];
    /* 0x170 */ u8 f170;
    /* 0x171 */ u8 pad171;
    /* 0x172 */ s16 f172;
    /* 0x174 */ u8 pad174[0x7C];
} S_006B8AC8;

extern u8 D_L39_0037C948[];
extern s32 D_001DDA04_sda;
extern s32 D_001DDA0C_sda;
extern u8 *func_001206F4(u8 *, u8 *);

void func_L39_006B6010(void *p, s32 save) {
    S_006B8AC8 *e;
    void *o;
    s32 r;

    if (save == 0) {
        e = &((S_006B8AC8 *)D_L39_0037C948)[D_001DDA04_sda];
        o = *(void **)((u8 *)p + 0x110);
        ((void (*)(void *, u8 *))*(void **)(*(u8 **)((u8 *)o + 0x60) + 0xB8))(o, e->f1D);
        o = *(void **)((u8 *)p + 0x11C);
        ((void (*)(void *, u8 *))*(void **)(*(u8 **)((u8 *)o + 0x60) + 0xB8))(o, e->f3D);
        o = *(void **)((u8 *)p + 0x118);
        ((void (*)(void *, s32))*(void **)(*(u8 **)((u8 *)o + 0x60) + 0x60))(o, e->f50 & 1);
        o = *(void **)((u8 *)p + 0x120);
        ((void (*)(void *, s32))*(void **)(*(u8 **)((u8 *)o + 0x60) + 0x88))(o, e->f4D);
        o = *(void **)((u8 *)p + 0x124);
        ((void (*)(void *, s32))*(void **)(*(u8 **)((u8 *)o + 0x60) + 0x60))(o, e->f4F == 0);
        o = *(void **)((u8 *)p + 0x128);
        ((void (*)(void *, s32))*(void **)(*(u8 **)((u8 *)o + 0x60) + 0x88))(o, e->f0);
        o = *(void **)((u8 *)p + 0x134);
        ((void (*)(void *, s32))*(void **)(*(u8 **)((u8 *)o + 0x60) + 0xA8))(o, e->f172);
        D_001DDA0C_sda = e->f170;
    } else {
        o = *(void **)((u8 *)p + 0x110);
        func_001206F4(((S_006B8AC8 *)D_L39_0037C948)[D_001DDA04_sda].f1D, ((u8 *(*)(void *))*(void **)(*(u8 **)((u8 *)o + 0x60) + 0xC4))(o));
        o = *(void **)((u8 *)p + 0x11C);
        func_001206F4(((S_006B8AC8 *)D_L39_0037C948)[D_001DDA04_sda].f3D, ((u8 *(*)(void *))*(void **)(*(u8 **)((u8 *)o + 0x60) + 0xC4))(o));
        o = *(void **)((u8 *)p + 0x118);
        if (((s32 (*)(void *))*(void **)(*(u8 **)((u8 *)o + 0x60) + 0x64))(o)) {
            ((S_006B8AC8 *)D_L39_0037C948)[D_001DDA04_sda].f50 |= 1;
        } else {
            ((S_006B8AC8 *)D_L39_0037C948)[D_001DDA04_sda].f50 &= ~1;
        }
        o = *(void **)((u8 *)p + 0x120);
        ((S_006B8AC8 *)D_L39_0037C948)[D_001DDA04_sda].f4D = ((s32 (*)(void *))*(void **)(*(u8 **)((u8 *)o + 0x60) + 0x8C))(o);
        o = *(void **)((u8 *)p + 0x124);
        ((S_006B8AC8 *)D_L39_0037C948)[D_001DDA04_sda].f4F = ((s32 (*)(void *))*(void **)(*(u8 **)((u8 *)o + 0x60) + 0x64))(o) ^ 1;
        o = *(void **)((u8 *)p + 0x128);
        r = ((s32 (*)(void *))*(void **)(*(u8 **)((u8 *)o + 0x60) + 0x8C))(o);
        ((S_006B8AC8 *)D_L39_0037C948)[D_001DDA04_sda].f0 = r;
        ((S_006B8AC8 *)D_L39_0037C948)[D_001DDA04_sda].f170 = D_001DDA0C_sda;
        o = *(void **)((u8 *)p + 0x134);
        ((S_006B8AC8 *)D_L39_0037C948)[D_001DDA04_sda].f172 = ((s32 (*)(void *))*(void **)(*(u8 **)((u8 *)o + 0x60) + 0xAC))(o);
    }
}
/* localdecomp:end func_L39_006B6010 */

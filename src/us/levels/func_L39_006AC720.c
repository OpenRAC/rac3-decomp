#include "common.h"

/* NTSC-U counterpart of func_L39_006AF070 (src/levels/39_multiplayer_menu/L39_006AF070.c) */
/* localdecomp:start func_L39_006AC720 */
extern u8 D_001A5E50[];
extern s32 *D_L39_002412A0;
__asm__(".extern D_L39_002412A0, 16");
extern s32 D_L39_00240640_006AC720;
__asm__(".extern D_L39_00240640_006AC720, 16");
typedef struct S_006AF070 {
    u8 pad0[0xF0];
    s16 fF0;
    u8 pad1[0x174 - 0xF2];
    s32 f174;
    s32 f178;
    s16 f17C;
} S_006AF070;
extern S_006AF070 *D_L39_002417C0;
__asm__(".extern D_L39_002417C0, 16");
typedef struct Vt_006AF070 {
    u8 pad0[0xF0];
    void (*fF0)(void *);
} Vt_006AF070;
typedef struct Obj_006AF070 {
    u8 pad0[0x60];
    Vt_006AF070 *f60;
} Obj_006AF070;
extern s32 func_L39_006C9748(s32, s32);
extern void func_L39_006C97B8(s32, void *, s32);
extern void func_00199B60(void);
extern void func_L39_00686EC8(void);
extern void func_L39_005992A8(s32, s32);
extern int func_0019D650(void);

void func_L39_006AC720(Obj_006AF070 *self)
{
    u8 *g = D_001A5E50;
    s32 r;
    s32 v;

    r = func_L39_006C9748(3, *(s32 *)(g + 0x5F4));
    if (r < 8) {
        func_L39_006C97B8(3, g + 0x5F4, r + 8);
    }
    D_L39_002417C0->fF0 = 7;
    D_L39_002417C0->f174 = *(s32 *)(g + 0x128) + 600;
    func_00199B60();
    self->f60->fF0(self);
    func_L39_00686EC8();
    *(s32 *)(g + 0x130) = *D_L39_002412A0;
    D_L39_002417C0->f178 = *D_L39_002412A0;
    v = D_L39_002417C0->f17C;
    if (*D_L39_002412A0 >= 2 && v <= 45) {
        v += 10;
    }
    func_L39_005992A8(v, 0);
    D_L39_00240640_006AC720 = func_0019D650();
}
/* localdecomp:end func_L39_006AC720 */

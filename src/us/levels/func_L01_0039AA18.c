#include "common.h"
#include "vu0.h"

/* NTSC-U counterpart of func_L01_0039BEF8 (src/levels/shared/L01_00396B78.c): release 20 (PAL 17), data at NTSC-U addresses */
/* localdecomp:start func_L01_0039AA18 */
typedef int Q_0039AA18 __attribute__((mode(TI)));
typedef struct { Q_0039AA18 axis[2]; u8 pad[0x78]; s32 release; u8 *owner; s32 age, life, done, unused; } Effect_0039AA18;
extern s32 D_L01_001DE130;
__asm__(".extern D_L01_001DE130, 4");
extern u8 D_L01_002A1EF0[];
extern f32 func_0037E250(f32, f32);
extern f32 func_L01_00440918(f32, f32);
void func_L01_0039AA18(u8 *owner, Q_0039AA18 *end, s32 life) {
    s32 i;
    u8 *p;
    for (i = 0; i < D_L01_001DE130; ++i) {
        p = D_L01_002A1EF0 + i * 0xB0;
        if (*(u8 **)(p + 0x9C) == 0) {
            *(u8 **)(p + 0x9C) = owner;
            *(Q_0039AA18 *)(p + 0x20) = *(Q_0039AA18 *)(owner + 0x10);
            *(Q_0039AA18 *)(p + 0x40) = *end;
            *(f32 *)(p + 0x20) += func_0037E250(-0.1f, 0.1f);
            *(f32 *)(p + 0x24) += func_0037E250(-0.1f, 0.1f);
            *(f32 *)(p + 0x28) += func_0037E250(-0.1f, 0.1f);
            *(f32 *)(p + 0x50) = func_0037E250(-3.1415927f, 3.1415927f);
            *(f32 *)(p + 0x54) = func_0037E250(-3.1415927f, 3.1415927f);
            *(f32 *)(p + 0x58) = func_0037E250(-3.1415927f, 3.1415927f);
            *(f32 *)(p + 0x74) = func_0037E250(-3.1415927f, 3.1415927f);
            *(f32 *)(p + 0x78) = func_0037E250(-3.1415927f, 3.1415927f);
            *(f32 *)(p + 0x7C) = func_0037E250(-3.1415927f, 3.1415927f);
            *(f32 *)(p + 0x5C) = func_L01_00440918(0.001f, 0.005f);
            *(f32 *)(p + 0x60) = func_L01_00440918(0.001f, 0.005f);
            *(f32 *)(p + 0x64) = func_L01_00440918(0.001f, 0.005f);
            *(f32 *)(p + 0x80) = func_L01_00440918(0.001f, 0.005f);
            *(f32 *)(p + 0x84) = func_L01_00440918(0.001f, 0.005f);
            *(f32 *)(p + 0x88) = func_L01_00440918(0.001f, 0.005f);
            *(f32 *)(p + 0x68) = func_0037E250(3.25f, 4.75f);
            *(f32 *)(p + 0x6C) = func_0037E250(3.25f, 4.75f);
            *(f32 *)(p + 0x70) = func_0037E250(3.25f, 4.75f);
            *(f32 *)(p + 0x8C) = func_0037E250(3.25f, 4.75f);
            *(f32 *)(p + 0x90) = func_0037E250(3.25f, 4.75f);
            *(f32 *)(p + 0x94) = func_0037E250(3.25f, 4.75f);
            { Effect_0039AA18 *e = (Effect_0039AA18 *)p;
            e->done = 0;
            qzero(p);
            e->age = life;
            qzero(p + 0x10);
            e->life = life;
            e->release = 20; }
            break;
        }
    }
}
/* localdecomp:end func_L01_0039AA18 */

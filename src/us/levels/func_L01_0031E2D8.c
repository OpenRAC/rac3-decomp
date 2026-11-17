#include "common.h"

/* NTSC-U counterpart of func_L01_0031E788 (src/levels/shared/L01_0031C1D0.c) */
extern s32 func_0037E208(s32, s32);
extern f32 func_0037E250(f32, f32);
extern float func_0037E2A8(void);
extern float func_0037E250(float, float);
extern u8 *func_L01_0031E2D8(u8 *, float *, s32, s32, s32);

/* localdecomp:start func_L01_0031E2D8 */
typedef int s128_0031E788 __attribute__((mode(TI)));
typedef struct {
    f32 velocity[4];
    f32 spin[4];      /* 0x10 */
    s16 life;         /* 0x20: frames */
    s16 arm;          /* 0x22: frames until armed */
    s32 heavy;        /* 0x24 */
    s32 x28;
    s32 annihilator;  /* 0x2C: one of the Annihilator's mines */
} Bomblet_0031E788;

__asm__(".extern D_L01_001DC8E4, 4");
__asm__(".extern D_L01_001DC8E8, 4");
__asm__(".extern D_L01_001DC8F4, 4");
__asm__(".extern D_L01_001DC8F8, 4");
__asm__(".extern D_L01_001DC904, 4");
extern s32 D_L01_001DC8E4;
extern s32 D_L01_001DC8E8;
extern f32 D_L01_001DC8F4;
extern f32 D_L01_001DC8F8;
extern u16 D_L01_001DC904;
extern u8 *func_003BCFB0(s32, s32);
extern s32 func_0037E208(s32, s32);
extern f32 func_0037E2A8(void);
extern void func_00388BD0(u8 *matrix, u8 *rotation);
extern f32 func_0037E250(f32, f32);
extern void func_003BF2F8(f32 *out, u8 *axis, f32 angle);
extern s32 func_L01_004C4A18(u8 *moby, s32 a1, f32 x, f32 y, f32 z);
extern void func_L01_00442E08(u8 *moby, s32 class_id);
extern void func_003C26C8(u8 *moby);

/* bouncer_bomblet_spawn: (position, velocity, index, heavy, annihilator): one of the
   Bouncer's bomblets (class 0xECE), or of the Annihilator's V2-V4 mines (model class 0x1897
   at 0.275 of its scale, 0.55 heavy): a life of 240-360 frames and armed after 70 plus its
   index (NTSC-U keeps the 60 Hz values as they are), at a random roll, spinning 3-6 degrees
   a frame. */
u8 *func_L01_0031E2D8(u8 *pos, f32 *velocity, s32 index, s32 heavy, s32 annihilator)
{
    u8 *bomblet = func_003BCFB0(0xECE, 0x80);
    Bomblet_0031E788 *vars;
    f32 spin;

    if (bomblet != 0) {
        s32 opaque = 0xFF;

        bomblet[0x20] = 0;
        *(u16 *)(bomblet + 0x32) = opaque;
        bomblet[0x30] = opaque;
        vars = *(Bomblet_0031E788 **)(bomblet + 0x68);
        *(s128_0031E788 *)(bomblet + 0x10) = *(s128_0031E788 *)pos;
        *(s128_0031E788 *)vars->velocity = *(s128_0031E788 *)velocity;
        vars->life = func_0037E208(D_L01_001DC8E4, D_L01_001DC8E8);
        *(u16 *)(bomblet + 0x34) |= 0x100; /* its matrix (+0xC0) drawn as set */
        *(f32 *)(bomblet + 0xF0) = func_0037E2A8();
        *(f32 *)(bomblet + 0xF4) = func_0037E2A8();
        *(f32 *)(bomblet + 0xF8) = func_0037E2A8();
        vars->annihilator = annihilator;
        func_00388BD0(bomblet + 0xC0, bomblet + 0xF0);
        spin = func_0037E250(0.052359883f, 0.104719765f);
        func_003BF2F8(vars->spin, bomblet + 0xD0, spin);
        vars->heavy = heavy;
        vars->arm = index + D_L01_001DC904;
        /* the moby's scale (+0x2C): x 1.5 heavy, else x 0.75 */
        if (heavy != 0) {
            *(f32 *)(bomblet + 0x2C) = *(f32 *)(bomblet + 0x2C) * D_L01_001DC8F8;
        } else {
            *(f32 *)(bomblet + 0x2C) = *(f32 *)(bomblet + 0x2C) * D_L01_001DC8F4;
        }
        vars->x28 = func_L01_004C4A18(bomblet, 0, 1.0f, 1.0f, 1.0f);
        if (annihilator != 0) {
            /* the mine's model, scaled from its class's scale (class + 0x24) */
            func_L01_00442E08(bomblet, 0x1897);
            if (heavy != 0) {
                *(f32 *)(bomblet + 0x2C) = *(f32 *)(*(u8 **)(bomblet + 0x24) + 0x24) * 0.55f;
            } else {
                *(f32 *)(bomblet + 0x2C) = *(f32 *)(*(u8 **)(bomblet + 0x24) + 0x24) * 0.275f;
            }
        }
        func_003C26C8(bomblet);
    }
    return bomblet;
}
/* localdecomp:end func_L01_0031E2D8 */

#include "common.h"

/* NTSC-U counterpart of func_L01_002F9738 (src/levels/shared/L01_002F7800.c): 0.0628319 -> 0.0523599 */
/* localdecomp:start func_L01_002F9760 */
typedef struct {
    u8 pad_0[0x14];
    s32 life;    /* 0x14: ticks it lives */
    f32 scale;   /* 0x18: its full scale */
    s16 timer;   /* 0x1C: ticks left */
    s16 opacity; /* 0x1E: its opacity while it holds */
} DomeVars_2F9738;

typedef struct {
    u8 pad_0[0x23];
    u8 opacity;  /* 0x23 */
    u8 pad_24[0x2C - 0x24];
    f32 scale;   /* 0x2C */
    u8 pad_30[0x68 - 0x30];
    DomeVars_2F9738 *vars; /* 0x68 */
    u8 pad_6C[0xF0 - 0x6C];
    f32 rotation[3]; /* 0xF0: angles x, y, z */
} DomeMoby_2F9738;

extern f32 func_0038DAB8_002F9760(f32, f32);
extern s32 func_0038CB00_002F9760(void *p);
extern void func_003C2880_002F9760(void *);

/* explosion_dome_update: the explosions' dome (class 0x70) grows to its scale over its life,
 * turns on all three axes and fades over the last half of its life. */
void func_L01_002F9760(DomeMoby_2F9738 *moby)
{
    DomeVars_2F9738 *vars = moby->vars;
    f32 turn = 0.0523598827f; /* 2 pi / 100 rad (3.6 degrees) a frame: NTSC-U turns 3 degrees at 60 Hz */
    s32 half;

    moby->scale = (f32)(vars->life - vars->timer) * vars->scale / (f32)vars->life;
    moby->rotation[0] = func_0038DAB8_002F9760(moby->rotation[0], turn);
    moby->rotation[1] = func_0038DAB8_002F9760(moby->rotation[1], turn);
    moby->rotation[2] = func_0038DAB8_002F9760(moby->rotation[2], turn);
    if (func_0038CB00_002F9760(&vars->timer)) {
        func_003C2880_002F9760(moby);
        return;
    }
    half = vars->life / 2;
    if (vars->timer < half) {
        moby->opacity = vars->timer * vars->opacity / half;
    }
}
/* localdecomp:end func_L01_002F9760 */

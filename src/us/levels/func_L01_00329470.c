#include "common.h"

/* NTSC-U counterpart of func_L01_003298C8 (src/levels/shared/L01_003298C8.c): 0.125664 -> 0.10472; 0.251327 -> 0.20944 */
extern void func_003C26C8(u8 *a0);

/* localdecomp:start func_L01_00329470 */
typedef int Q_003298C8 __attribute__((mode(TI)));
typedef struct {
    Q_003298C8 origin;
    f32 f10;
    f32 f14;
    s16 h18;
    s16 h1A;
    s16 h1C;
    s16 h1E;
    u32 colours[4];
    s32 kind;
    s32 w34;
    s32 w38;
    s16 h3C;
    s16 h3E;
} Vars_003298C8;
typedef struct {
    u8 p0[0x10];
    Q_003298C8 pos;
    u8 p20[3];
    u8 b23;
    u8 p24[8];
    f32 scale;
    u8 b30;
    u8 b31;
    s16 h32;
    u8 p34[0x34];
    Vars_003298C8 *vars;
    u8 p6C[0xC];
    s32 w78;
} Moby_003298C8;
extern Moby_003298C8 *func_003BCFB0(s32, s32);
extern void func_00388550(void *, void *, s32);
extern void func_L01_00438908(void *, s32, s32, s32);
extern f32 func_0037E250(f32, f32);
extern s32 func_0037E1D8(s32);
u8 *func_L01_00329470(Q_003298C8 *pos, Q_003298C8 *origin, s32 life, s32 kind, s32 a4, s32 a5, void *colours, s32 a7, s16 a8, s16 a9, f32 scale, f32 opacity) {
    Moby_003298C8 *moby = func_003BCFB0(0x1A50, 0x80);
    Vars_003298C8 *vars;
    s32 size;
    if (moby) {
        vars = moby->vars;
        moby->b30 = 0xFF;
        moby->h32 = 0xFF;
        moby->b31 = 1;
        moby->b23 = 0x80;
        vars->w34 = a4;
        vars->w38 = a7;
        moby->scale *= scale;
        vars->h3C = a8;
        vars->h3E = a9;
        if (colours) func_00388550(vars->colours, colours, 0x10);
        else {
            vars->colours[0] = 0x2FFFFFFF;
            vars->colours[1] = 0x2F808080;
            vars->colours[2] = 0x2FC0C0C0;
            vars->colours[3] = 0x2F404040;
        }
        func_L01_00438908(moby, 0x7F, 0x7F, 0x7F);
        moby->pos = *pos;
        vars->origin = *origin;
        vars->f10 = func_0037E250(0.104719765f, 0.209439531f);
        vars->f14 = func_0037E250(0.104719765f, 0.209439531f);
        vars->h18 = life;
        vars->h1A = life;
        vars->kind = kind;
        if (kind == 3) vars->kind = func_0037E1D8(3);
        size = moby->scale * 128.0f;
        vars->h1E = opacity * 128.0f;
        vars->h1C = size;
        moby->w78 = a5;
        func_003C26C8((u8 *)moby);
    }
    return (u8 *)moby;
}
/* localdecomp:end func_L01_00329470 */

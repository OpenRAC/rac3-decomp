#include "common.h"

/* NTSC-U counterpart of func_L01_00348258 (src/levels/shared/L01_00340670.c) */
/* localdecomp:start func_L01_003478E8 */
typedef int s128_00348258 __attribute__((mode(TI)));
typedef struct {
    u8 pad0[0x10];
    f32 pos[4];
    f32 angle;  /* 0x20 */
    f32 width;  /* 0x24 */
    f32 spin;   /* 0x28 */
    f32 drift;  /* 0x2C */
} TrailPoint_00348258;
typedef struct {
    u8 pad0[0x18];
    s16 trail;  /* 0x18: its slot in the trail list */
    s16 id;     /* 0x1A */
    u8 pad1C[4];
    s16 points; /* 0x20: points laid so far */
} FluxVars_00348258;

__asm__(".extern D_L01_001DD354, 4");
__asm__(".extern D_L01_001DD358, 4");
__asm__(".extern D_L01_001DD35C, 4");
__asm__(".extern D_L01_001DD360, 4");
__asm__(".extern D_L01_001DD364, 4");
__asm__(".extern D_L01_001DD368, 4");
extern f32 D_L01_001DD354;
extern f32 D_L01_001DD358;
extern f32 D_L01_001DD35C;
extern f32 D_L01_001DD360;
extern f32 D_L01_001DD364;
extern f32 D_L01_001DD368;
extern char *func_L01_00454190(s32, s32);
extern f32 func_L01_00447C00(f32);
extern f32 func_0037E250(f32, f32);
extern f32 func_L01_00440918(f32, f32);
extern void func_L01_00347A08(TrailPoint_00348258 *points, s32 count);

/* flux_shot_trail: a per-step call of the Flux Rifle shot that lays its trail: the next
   point of its list at pos, its angle from n x 40 degrees (D_L01_001DD35C), a spin of 1 to
   1 degree (D_L01_001DD354, D_L01_001DD358), width 0.3 (D_L01_001DD360) and a drift of
   0.01-0.5 either way (D_L01_001DD364, D_L01_001DD368) x 1/60. */
void func_L01_003478E8(u8 *shot, s128_00348258 *pos)
{
    FluxVars_00348258 *vars = *(FluxVars_00348258 **)(shot + 0x68);
    u32 lists;
    TrailPoint_00348258 **list;
    s32 n;

    lists = (u32)func_L01_00454190(0xC04, vars->id);
    n = vars->points;
    /* the shot's own list among them */
    list = (TrailPoint_00348258 **)(vars->trail * 4 + lists);
    *(s128_00348258 *)(*list)[n].pos = *pos;
    (*list)[n].angle = func_L01_00447C00(n * (D_L01_001DD35C * 0.017453292f));
    (*list)[n].spin = func_0037E250(D_L01_001DD354, D_L01_001DD358) * 0.017453292f;
    (*list)[n].width = D_L01_001DD360;
    (*list)[n].drift = func_L01_00440918(D_L01_001DD364, D_L01_001DD368) * 0.016666668f;
    func_L01_00347A08(*list, n);
    vars->points++;
}
/* localdecomp:end func_L01_003478E8 */

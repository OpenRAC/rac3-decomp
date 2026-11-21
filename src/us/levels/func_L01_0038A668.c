#include "common.h"

/* NTSC-U counterpart of func_L01_0038B9A8 (src/levels/shared/L01_0038B9A8.c) */
/* localdecomp:start func_L01_0038A668 */
#include "structs/moby.h"
typedef int u128_38B9A8 __attribute__((mode(TI)));
extern float D_L01_001DDF70_0038A668 __attribute__((section(".sdata")));
extern float D_L01_001DDF84_0038A668 __attribute__((section(".sdata")));
extern float D_L01_001DDF88_0038A668 __attribute__((section(".sdata")));
extern s32 D_L01_001DDF74_0038A668 __attribute__((section(".sdata")));
extern s32 D_L01_001DDF78_0038A668 __attribute__((section(".sdata")));
extern s32 D_L01_001DDF8C __attribute__((section(".sdata")));
extern s32 D_L01_001E1F9C;
extern float D_L01_001E1FA0;
extern float D_L01_001E1FA4;
extern float D_L01_001E1FA8;
extern float D_L01_001E1FAC;
extern float D_L01_001E1FB0_0038A668;
extern float D_L01_001E1FB4;
extern float D_L01_001E1FB8;
extern float D_L01_001E1FBC;
extern float D_L01_001E1FC0;
extern float D_L01_001E1FC4;
extern float D_L01_001E1FC8_0038A668;
extern float D_L01_001E1FCC;
__asm__(".extern D_L01_001DDF70_0038A668, 4");
__asm__(".extern D_L01_001DDF74_0038A668, 4");
__asm__(".extern D_L01_001DDF78_0038A668, 4");
__asm__(".extern D_L01_001DDF84_0038A668, 4");
__asm__(".extern D_L01_001DDF88_0038A668, 4");
__asm__(".extern D_L01_001DDF8C, 4");
/* eruptor_blast_spawn: spawns the Eruptor's blast (class 0x1888) at a position, with the ground
   point and the charge's pvars (open-rac-engine symbols.toml; its timer counts from 105). */
struct Moby *func_L01_0038A668(u128_38B9A8 *position, u128_38B9A8 *ground, u128_38B9A8 *charge_vars) {
    extern struct Moby *func_003BCFB0(s32, s32);
    extern float func_0037E2A8(void);
    struct Moby *blast = func_003BCFB0(0x1888, 0x80);
    if (blast) {
        /* The pvars are written through byte offsets: a struct's fields (MEM_IN_STRUCT_P to cc1)
           don't conflict with the scalar globals, so cc1 moves those stores past them and the order
           is lost. The Nitro blast's at func_L01_0035F340 are the same fields 0x10 lower. */
        u8 *vars = blast->pvar;
        *(u128_38B9A8 *)&blast->position = *position;
        ((u8 *)blast)[0x30] = 255;
        blast->draw_dist = 255;
        blast->state = 0;
        *(s32 *)(vars + 0x24) = 105;        /* the Nitro blast's 83 */
        *(f32 *)(vars + 0x28) = 2.0f;        /* its push 1.5 */
        *(s32 *)(vars + 0x2C) = 30;
        *(s32 *)(vars + 0x20) = 0;
        D_L01_001DDF74_0038A668 = 0;
        D_L01_001DDF78_0038A668 = 0;
        *(s32 *)(vars + 0x30) = 0x50;
        *(f32 *)(vars + 0x34) = 1.0f;
        D_L01_001DDF70_0038A668 = 1.0f;
        *(u128_38B9A8 *)(vars + 0x10) = *ground;
        *(s32 *)(vars + 0x3C) = 20;
        D_L01_001DDF84_0038A668 = 1.0f;
        D_L01_001DDF88_0038A668 = 1.0f;
        *(u128_38B9A8 *)vars = *charge_vars;
        D_L01_001E1F9C = D_L01_001DDF8C;
        *(s32 *)(vars + 0x38) = -1;
        D_L01_001E1FA0 = func_0037E2A8();
        D_L01_001E1FA4 = func_0037E2A8();
        D_L01_001E1FA8 = func_0037E2A8();
        D_L01_001E1FAC = func_0037E2A8();
        D_L01_001E1FB0_0038A668 = func_0037E2A8();
        D_L01_001E1FB4 = func_0037E2A8();
        D_L01_001E1FB8 = func_0037E2A8();
        D_L01_001E1FBC = func_0037E2A8();
        D_L01_001E1FC0 = func_0037E2A8();
        D_L01_001E1FC4 = func_0037E2A8();
        D_L01_001E1FC8_0038A668 = func_0037E2A8();
        D_L01_001E1FCC = func_0037E2A8();
    }
    return blast;
}
/* localdecomp:end func_L01_0038A668 */

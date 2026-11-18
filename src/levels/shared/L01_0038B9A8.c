#include "common.h"

/* localdecomp:start func_L01_0038B9A8 */
#include "structs/moby.h"
typedef int u128_38B9A8 __attribute__((mode(TI)));
extern float D_L01_001DDF30 __attribute__((section(".sdata")));
extern float D_L01_001DDF44 __attribute__((section(".sdata")));
extern float D_L01_001DDF48 __attribute__((section(".sdata")));
extern s32 D_L01_001DDF34 __attribute__((section(".sdata")));
extern s32 D_L01_001DDF38 __attribute__((section(".sdata")));
extern s32 D_L01_001DDF4C __attribute__((section(".sdata")));
extern s32 D_L01_001E1F1C;
extern float D_L01_001E1F20;
extern float D_L01_001E1F24;
extern float D_L01_001E1F28;
extern float D_L01_001E1F2C;
extern float D_L01_001E1F30;
extern float D_L01_001E1F34;
extern float D_L01_001E1F38;
extern float D_L01_001E1F3C;
extern float D_L01_001E1F40;
extern float D_L01_001E1F44;
extern float D_L01_001E1F48;
extern float D_L01_001E1F4C;
__asm__(".extern D_L01_001DDF30, 4");
__asm__(".extern D_L01_001DDF34, 4");
__asm__(".extern D_L01_001DDF38, 4");
__asm__(".extern D_L01_001DDF44, 4");
__asm__(".extern D_L01_001DDF48, 4");
__asm__(".extern D_L01_001DDF4C, 4");
/* eruptor_blast_spawn: spawns the Eruptor's blast (class 0x1888) at a position, with the ground
   point and the charge's pvars (open-rac-engine symbols.toml; its timer counts from 105). */
struct Moby *func_L01_0038B9A8(u128_38B9A8 *position, u128_38B9A8 *ground, u128_38B9A8 *charge_vars) {
    extern struct Moby *func_003C24B0(s32, s32);
    extern float func_00382538(void);
    struct Moby *blast = func_003C24B0(0x1888, 0x80);
    if (blast) {
        /* The pvars are written through byte offsets: a struct's fields (MEM_IN_STRUCT_P to cc1)
           don't conflict with the scalar globals, so cc1 moves those stores past them and the order
           is lost. The Nitro blast's at func_L01_0035F340 are the same fields 0x10 lower. */
        u8 *vars = blast->pvar;
        *(u128_38B9A8 *)&blast->position = *position;
        ((u8 *)blast)[0x30] = 255;
        blast->draw_dist = 255;
        blast->state = 0;
        *(s32 *)(vars + 0x24) = 0x57;        /* the Nitro blast's 83 */
        *(f32 *)(vars + 0x28) = 2.0f;        /* its push 1.5 */
        *(s32 *)(vars + 0x2C) = 0x19;
        *(s32 *)(vars + 0x20) = 0;
        D_L01_001DDF34 = 0;
        D_L01_001DDF38 = 0;
        *(s32 *)(vars + 0x30) = 0x50;
        *(f32 *)(vars + 0x34) = 1.0f;
        D_L01_001DDF30 = 1.0f;
        *(u128_38B9A8 *)(vars + 0x10) = *ground;
        *(s32 *)(vars + 0x3C) = 0x11;
        D_L01_001DDF44 = 1.0f;
        D_L01_001DDF48 = 1.0f;
        *(u128_38B9A8 *)vars = *charge_vars;
        D_L01_001E1F1C = (D_L01_001DDF4C * 5 + 2) / 6;
        *(s32 *)(vars + 0x38) = -1;
        D_L01_001E1F20 = func_00382538();
        D_L01_001E1F24 = func_00382538();
        D_L01_001E1F28 = func_00382538();
        D_L01_001E1F2C = func_00382538();
        D_L01_001E1F30 = func_00382538();
        D_L01_001E1F34 = func_00382538();
        D_L01_001E1F38 = func_00382538();
        D_L01_001E1F3C = func_00382538();
        D_L01_001E1F40 = func_00382538();
        D_L01_001E1F44 = func_00382538();
        D_L01_001E1F48 = func_00382538();
        D_L01_001E1F4C = func_00382538();
    }
    return blast;
}
/* localdecomp:end func_L01_0038B9A8 */

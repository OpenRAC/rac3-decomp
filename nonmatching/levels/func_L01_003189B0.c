/* PAL near miss (haiku-w2): 32 words differ with the file's flags; no divs_nops row for func_L01_003189B0 (retail has 2 nops before its div.s; config/levels/divs_nops.txt needs "func_L01_003189B0 2"). Remaining: the while-loop entry test and prologue scheduling, plus the nop padding. */
#include "common.h"
/* localdecomp:start func_L01_003189B0 */
#include "vu0.h"
typedef struct {
    f32 pos[4];
    f32 phase, rate;
    s32 timer, active;
    u8 pad[16];
} Effect_003189B0;
extern E_L01_00272540_00318408 D_L01_00272540[] __attribute__((section(".sdata")));
extern G_00318408 D_001A4BE0;
void func_L01_003189B0(u8 *obj) {
    extern void func_L01_004C7D98(s32, f32 *);
    extern void func_0038D890(f32 *, f32 *, f32 *, f32);
    extern void func_L01_00318AF8(s32, f32 *, s32);
    extern f32 func_0038DAB8(f32, f32);
    extern void func_0038CF68(f32 *, f32 *, f32);
    extern s32 func_0038CAD0(void *);
    f32 delta[4] __attribute__((aligned(16)));
    f32 out[4] __attribute__((aligned(16)));
    u8 *base = (u8 *)D_L01_00272540;
    s32 *timer = (s32 *)(base + 0x18);
    u8 *cursor = base;
    u8 *limit = base + 0x240;
    while (cursor < limit) {
        Effect_003189B0 *p = (Effect_003189B0 *)cursor;
        if (p->active == (s32)obj) {
            f32 alpha;
            func_L01_004C7D98(D_001A4BE0.x25C0 + 0x10, delta);
            alpha = (f32)p->timer / 37.0f;
            func_0038D890(out, p->pos, delta, p->phase);
            func_L01_00318AF8((s32)obj, out, (s32)(alpha * 128.0f));
            p->phase = func_0038DAB8(p->phase, p->rate);
            func_0038CF68(delta, delta, 0.04f);
            vec_add_ab(p->pos, p->pos, delta);
            if (func_0038CAD0(timer)) p->active = 0;
        }
        cursor += 0x30; timer += 12;
    }
}
/* localdecomp:end func_L01_003189B0 */

/* functional: high. 76 words differ vs retail: prologue/scheduling only; reviewed block by block, same calls, args, offsets. */
/* PAL near miss (Codex wave 8): near miss: 75 words differ with the file's flags.
 * Worker's note: 75 raw positional diff: fourth-best.log with divs 2 injected; prologue base copy/loop branch and scalar scheduling; three wordings unchanged; contract compiles fourth-contract.log; no all-place claim
 */
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
void func_L01_003189B0(s32 kind) {
    extern void func_L01_004C7D98(s32, f32 *);
    extern void func_0038D890(f32 *, f32 *, f32 *, f32);
    extern void func_L01_00318AF8(s32, f32 *, s32);
    extern f32 func_0038DAB8(f32, f32);
    extern void func_0038CF68(f32 *, f32 *, f32);
    extern s32 func_0038CAD0(void *);
    f32 delta[4] __attribute__((aligned(16)));
    f32 out[4] __attribute__((aligned(16)));
    u8 *cursor = (u8 *)D_L01_00272540;
    u8 *limit = cursor + 0x240;
    s32 *timer = (s32 *)(cursor + 0x18);
    do {
        Effect_003189B0 *p = (Effect_003189B0 *)cursor;
        if (p->active == kind) {
            f32 alpha;
            func_L01_004C7D98(D_001A4BE0.x25C0 + 0x10, delta);
            alpha = (f32)p->timer / 37.0f;
            func_0038D890(out, p->pos, delta, p->phase);
            func_L01_00318AF8(kind, out, (s32)(alpha * 128.0f));
            p->phase = func_0038DAB8(p->phase, p->rate);
            func_0038CF68(delta, delta, 0.04f);
            vec_add_ab(p->pos, p->pos, delta);
            if (func_0038CAD0(timer)) p->active = 0;
        }
        cursor += 0x30; timer += 12;
    } while ((s32)cursor < (s32)limit);
}
/* localdecomp:end func_L01_003189B0 */

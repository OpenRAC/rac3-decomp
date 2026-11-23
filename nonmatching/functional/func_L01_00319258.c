/* functional: high. 112 words differ (loop base/constant register allocation); every store offset, random-call order, constant range and field verified vs retail. */
/* PAL near miss (Codex wave 10): near miss: 112 words differ with the file's flags.
 * Worker's note: 112 differing words / 138 retail words; check03.log: loop base addiu stays inside loop, owner relocation and final float constant registers differ; three address forms unchanged; real complete PAL draft retained
 */
#include "common.h"
/* localdecomp:start func_L01_00319258 */
#include "vu0.h"
typedef struct {
    u128_t first, second, origin, current, end;
    f32 phase[3], rate[3], scale[3];
    f32 phase2[3], rate2[3], scale2[3];
    s32 delay;
    void *owner;
    s32 timer, duration, finished, pad;
} Arc_00319258;
extern u8 D_L01_00273B80[0x420];
extern u8 D_001A4CC0[];
void func_L01_00319258(void *owner, u128_t *end, s32 duration) {
    extern f32 func_003824E0(f32, f32);
    extern f32 func_L01_00443A18(f32, f32);
    s32 i;
    Arc_00319258 *p;
    for (i = 0; i < 6; i++) {
        p = (Arc_00319258 *)(i * 0xB0 + (u32)D_L01_00273B80);
        if (p->owner == 0) {
            p->owner = owner;
            p->origin = *(u128_t *)D_001A4CC0;
            p->end = *end;
            p->phase[0] = func_003824E0(-3.1415927410125732f, 3.1415927410125732f);
            p->phase[1] = func_003824E0(-3.1415927410125732f, 3.1415927410125732f);
            p->phase[2] = func_003824E0(-3.1415927410125732f, 3.1415927410125732f);
            p->phase2[0] = func_003824E0(-3.1415927410125732f, 3.1415927410125732f);
            p->phase2[1] = func_003824E0(-3.1415927410125732f, 3.1415927410125732f);
            p->phase2[2] = func_003824E0(-3.1415927410125732f, 3.1415927410125732f);
            p->rate[0] = func_L01_00443A18(0.0010000000474974513f, 0.004999999888241291f);
            p->rate[1] = func_L01_00443A18(0.0010000000474974513f, 0.004999999888241291f);
            p->rate[2] = func_L01_00443A18(0.0010000000474974513f, 0.004999999888241291f);
            p->rate2[0] = func_L01_00443A18(0.0010000000474974513f, 0.004999999888241291f);
            p->rate2[1] = func_L01_00443A18(0.0010000000474974513f, 0.004999999888241291f);
            p->rate2[2] = func_L01_00443A18(0.0010000000474974513f, 0.004999999888241291f);
            p->scale[0] = func_003824E0(3.25f, 4.75f);
            p->scale[1] = func_003824E0(3.25f, 4.75f);
            p->scale[2] = func_003824E0(3.25f, 4.75f);
            p->scale2[0] = func_003824E0(3.25f, 4.75f);
            p->scale2[1] = func_003824E0(3.25f, 4.75f);
            p->scale2[2] = func_003824E0(3.25f, 4.75f);
            qzero(&p->first);
            qzero(&p->second);
            p->delay = 17;
            p->timer = duration;
            p->duration = duration;
            p->finished = 0;
            break;
        }
    }
}
/* localdecomp:end func_L01_00319258 */

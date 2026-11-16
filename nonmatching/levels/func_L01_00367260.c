/* PAL near miss (Codex wave 8): near miss: 100 words differ with the file's flags.
 * Worker's note: 101 word diffs: w387/func_L01_00367260.best.log; whole VU block retained, tail sharing/registers differ; shared vu0 j helper fails under fixed flags (try4); three later wordings identical; try4.o is stale and not proof; type contract compiles: ...
 */
#include "common.h"
/* localdecomp:start func_L01_00367260 */
#include "vu0.h"
extern s32 D_L01_001E1B60[] __attribute__((section(".sdata")));
extern s32 D_L01_001E1B70[] __attribute__((section(".sdata")));
extern s32 D_L01_001E1B80[] __attribute__((section(".sdata")));
extern s128 D_L01_001E1B90[] __attribute__((section(".sdata")));
extern s128 D_L01_001E1BD0[] __attribute__((section(".sdata")));
extern s32 D_L01_001E1C10[] __attribute__((section(".sdata")));
void func_L01_00367260(s32 object, s32 key, s32 enabled, s128 *start, s128 *end, s32 kind) {
    extern void func_0038CF68(void *, void *, f32);
    s32 i;
    s32 *objects;
    s32 *keys;
    s32 *active;
    s128 *delta;
    if (enabled == 0) {
        objects = D_L01_001E1B60;
        active = D_L01_001E1B80;
        for (i = 3; i >= 0; i--) {
            if (object == *objects) *active = 0;
            active++; objects++;
        }
        return;
    }
    objects = D_L01_001E1B60;
    keys = D_L01_001E1B70;
    for (i = 0; i < 4; i++) {
        if (object == *objects && key == *keys) {
            *objects = object;
            *keys = key;
            D_L01_001E1B80[i] = enabled;
            D_L01_001E1C10[i] = kind;
            D_L01_001E1B90[i] = *end;
            delta = &D_L01_001E1BD0[i];
            __asm__("lqc2 $vf1, %1\n\tlqc2 $vf2, %2\n\tvsub.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0" : "=m"(*delta) : "m"(*end), "m"(*start) : "vf1", "vf2");
            func_0038CF68(delta, delta, 1.0f);
            return;
        }
        keys++; objects++;
    }
    active = D_L01_001E1B80;
    for (i = 0; i < 4; i++) {
        if (*active == 0) {
            D_L01_001E1B60[i] = object;
            D_L01_001E1B70[i] = key;
            D_L01_001E1B80[i] = enabled;
            D_L01_001E1C10[i] = kind;
            D_L01_001E1B90[i] = *end;
            delta = &D_L01_001E1BD0[i];
            __asm__("lqc2 $vf1, %1\n\tlqc2 $vf2, %2\n\tvsub.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0" : "=m"(*delta) : "m"(*end), "m"(*start) : "vf1", "vf2");
            func_0038CF68(delta, delta, 1.0f);
            return;
        }
        active++;
    }
}
/* localdecomp:end func_L01_00367260 */

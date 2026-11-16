/* PAL near miss (Codex wave 6): near miss: 53 words differ with the file's flags.
 * Worker's note: 32 diff with --divs 2,0,0: build/codex/w261/func_L07_003CD7E0.wrapper5.log; fixed file flags forbid j VU operands; single-sequence VU blocks differ in scheduling of float compare and final VU load/store. Declaration contract compiles: ...
 */
#include "common.h"
/* localdecomp:start func_L07_003CD7E0 */
typedef struct { f32 x,y,z,w; } __attribute__((aligned(16))) V_003CD7E0;
typedef int Q_003CD7E0 __attribute__((mode(TI)));
void func_L07_003CD7E0(void *obj, int state, int index, int count, float time, float rate, float height, float start, float end, float peak) {
    extern void func_0038CF68(void *, void *, float);
    extern float func_003C3D30(void *, int, int, float);
    extern float func_003C3BE8(float, float, float);
    extern void func_L01_0045AA30(void *, void *);
    V_003CD7E0 pos, step, delta;
    float blend;
    if (*(u8 *)((u8 *)obj + 0x42) == state && start <= time && time < end) {
        *(Q_003CD7E0 *)&pos = *(Q_003CD7E0 *)((u8 *)obj + 0x10);
        func_0038CF68(&step, (u8 *)obj + 0xC0 + index * 16, (count * rate) / (end - start));
        __asm__("lqc2 $vf1, %1\n\tlqc2 $vf2, %2\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0" : "=m"(pos) : "m"(pos), "m"(step) : "vf1", "vf2");
        if (time < 16.0f) blend = (time - start) / (peak - start);
        else blend = 1.0f - (time - peak) / (end - peak);
        { float z = func_003C3D30(&pos, 0, 0, 0.5f);
        pos.z = func_003C3BE8(z, z + height, blend); }
        __asm__("lqc2 $vf2, %2\n\tlqc2 $vf1, %1\n\tvsub.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0" : "=m"(delta) : "m"(pos), "m"(*(V_003CD7E0 *)((u8 *)obj + 0x10)) : "vf1", "vf2");
        func_L01_0045AA30(obj, &delta);
    }
}
/* localdecomp:end func_L07_003CD7E0 */

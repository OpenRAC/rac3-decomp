/* PAL near miss (haiku-w3): 23 words differ with the file's flags: obj and state swap saved registers ($s0/$s1), and the lq/sq copy of pos and the lui $t0 order around the VU0 sqc2 differ. */
#include "common.h"
/* localdecomp:start func_L01_003E3F08 */
typedef int Q_003E3F08 __attribute__((mode(TI)));
typedef struct { u8 pad[0x28]; f32 phase; } State_003E3F08;
typedef struct { u8 pad[0x10]; Q_003E3F08 pos; u8 pad20[0x48]; State_003E3F08 *state; } Obj_003E3F08;
void func_L01_003E3F08(u8 *obj) {
    extern void func_L01_004C7D98(void *, void *);
    extern void func_0038CE20(void *, void *, f32);
    extern void func_L01_0040A8C0(void *, void *, s32, s32, u32, u32, u32, u32, f32, f32, f32);
    Q_003E3F08 end, start;
    State_003E3F08 *state = *(State_003E3F08 **)(obj + 0x68);
    if (state) {
        f32 phase = state->phase - 0.021f;
        state->phase = phase;
        if (phase <= -8.0f) state->phase = phase + 8.0f;
        func_L01_004C7D98((obj + 0x10), &end);
        func_0038CE20(&end, &end, 1.9f);
        __asm__ __volatile__("lqc2 $vf1, 0(%0)\n\tlqc2 $vf2, 16(%1)" : : "r"(&end), "r"(obj) : "memory", "vf1", "vf2");
        start = *(Q_003E3F08 *)(obj + 0x10);
        __asm__("vadd.xyz $vf2, $vf2, $vf1" : : : "vf2");
        __asm__("sqc2 $vf2, 0(%1)" : "=m"(end) : "r"(&end) : "vf2");
        func_L01_0040A8C0(&start, &end, 26, 1, 0x53FF7F40, 0x53FF7F40, 0x00FF7F40, 0x00FF7F40, 0.55f, 1.0f, state->phase);
    }
}
/* localdecomp:end func_L01_003E3F08 */

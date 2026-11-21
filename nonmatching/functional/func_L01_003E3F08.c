/* functional: high. PAL near miss 25 diff (VU0 scheduling); verified vs asm: constants, args, vadd.xyz keeps start w */
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
        __asm__("lqc2 vf1, %1\n\tlqc2 vf2, %2\n\tvadd.xyz vf2, vf2, vf1\n\tsqc2 vf2, %0" : "=m"(end) : "m"(end), "m"(*(Q_003E3F08 *)(obj + 0x10)) : "vf1", "vf2");
        start = *(Q_003E3F08 *)(obj + 0x10);
        func_L01_0040A8C0(&start, &end, 26, 1, 0x53FF7F40, 0x53FF7F40, 0x00FF7F40, 0x00FF7F40, 0.55f, 1.0f, state->phase);
    }
}
/* localdecomp:end func_L01_003E3F08 */

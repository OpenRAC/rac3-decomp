/* functional: high. Near-miss draft (155 words differ: VU0 sequence scheduling and constant allocation only). Re-read against PAL asm: both loops (20 and 10 iterations), rand argument pairs (0..pi, 0..0.1), the func_00382760 yaw/pitch order, constants 0.2/0.05/20000, final state==40 test all match. Needs Vec_337F38 from file context. */
/* localdecomp:start func_L01_00338230 */
typedef struct { u8 pad[0x20]; Vec_337F38 pos; } State_00338230;
extern State_00338230 D_L01_001EAA00;
extern Vec_337F38 D_L01_001E29C0;
void func_L01_00338230(u8 *m)
{
    extern f32 func_0038CED8(void *);
    extern f32 func_0038D160(f32, f32);
    extern f32 func_L01_00443A18(f32, f32);
    extern f32 func_0038DAB8(f32, f32);
    extern void func_00382760(Vec_337F38 *, f32, f32, f32);
    extern f32 func_003824E0(f32, f32);
    extern s32 func_00382498(s32, s32);
    extern void func_0038CE20(void *, void *, f32);
    extern void func_L01_004660F8(void *, void *);
    extern void func_L01_00466588(void *, void *, u32, u32, s32, s32, f32);
    extern void func_L01_00337F38(f32 *, s32);
    Vec_337F38 velocity;
    Vec_337F38 at;
    f32 angle, pitch, yaw, unused;
    s32 i;
    f32 jitter = 0.1f;
    f32 spread = 3.1415927f;
    State_00338230 *state = &D_L01_001EAA00;
    __asm__("lqc2 $vf1, %1\n\tlqc2 $vf2, %2\n\tvsub.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0"
        : "=m"(velocity) : "m"(D_L01_001E29C0), "m"(state->pos) : "vf1", "vf2");
    angle = -func_0038D160(func_0038CED8(&velocity), velocity.z);
    unused = func_0038D160(velocity.x, velocity.y);
    for (i=19; i>=0; i--) {
        pitch = func_0038DAB8(func_L01_00443A18(0.0f, spread), angle);
        yaw = func_0038DAB8(func_L01_00443A18(0.0f, spread), angle);
        func_00382760(&velocity, 0.2f, yaw, pitch);
        func_0038CE20(&at, &velocity, func_003824E0(1.0f, 3.0f));
        __asm__("lqc2 $vf2, %0\n\tlqc2 $vf1, %1\n\tvadd.xyz $vf2, $vf2, $vf1\n\tsqc2 $vf2, %0"
            : "+m"(at) : "m"(state->pos) : "vf1", "vf2");
        func_L01_004660F8(&at, &velocity);
    }
    for (i=9; i>=0; i--) {
        at.x = state->pos.x + func_L01_00443A18(0.0f, jitter);
        at.y = state->pos.y + func_L01_00443A18(0.0f, jitter);
        at.z = state->pos.z + func_L01_00443A18(0.0f, jitter);
        pitch = func_0038DAB8(func_L01_00443A18(0.0f, spread), angle);
        yaw = func_0038DAB8(func_L01_00443A18(0.0f, spread), angle);
        func_00382760(&velocity, 0.05f, yaw, pitch);
        func_L01_00466588(&at, &velocity, 0x4F007FFF, 0x1FFFFFFF, func_00382498(8,17), 1, 20000.0f);
    }
    if (*(s16 *)(*(u8 **)(m+0x68)+0x78)==40) func_L01_00337F38((f32 *)&D_L01_001EAA00.pos,10);
}
/* localdecomp:end func_L01_00338230 */

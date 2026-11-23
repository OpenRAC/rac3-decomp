/* functional: high. 5-word near miss, instruction order only; all fields, constants and calls verified. */
/* localdecomp:start func_L01_00349998 */
typedef struct { f32 v[4]; } __attribute__((aligned(16))) Vector_00349998;
extern u8 D_L01_001E2A40[];
typedef struct { f32 random[6]; f32 height; s16 a1C, a1E; f32 a20, a24; s16 a28, a2A; f32 a2C, a30; s16 a34, a36; f32 a38, a3C; s32 a40; f32 a44; u8 pad48[8]; s32 owner; } State_00349998;
u8 *func_L01_00349998(s32 unused, s128 *position, s128 *direction, s32 owner, f32 height) {
    extern u8 *func_003C24B0(s32, s32);
    extern void func_003C5180(void *, f32 *, s32);
    extern void func_0038CE90(void *, void *, void *);
    extern void func_0038CF68(void *, void *, f32);
    extern void func_0038CE20(f32 *, f32 *, f32);
    extern f32 func_00382538(void);
    extern s32 func_003D3CB0(void *, void *, s32, s32, s32);
    extern s32 func_L01_00459590(void *, s32, f32);
    extern void func_L01_0034A3C8(u8 *, f32 *, s32);
    Vector_00349998 matrix;
    Vector_00349998 offset;
    Vector_00349998 test;
    u8 *m = func_003C24B0(0xD4E, 0x80);
    State_00349998 *v;
    if (m != 0) {
        f32 zero = 0.0f;
        m[0x30] = 255;
        *(s16 *)(m + 0x32) = 255;
        m[0x20] = 0;
        v = *(State_00349998 **)(m + 0x68);
        *(s128 *)(m + 0x10) = *position;
        *(f32 *)(m + 0x1C) = 1.0f;
        func_003C5180(m + 0x10, matrix.v, 1);
        *(s128 *)(m + 0xC0) = *direction;
        func_0038CE90(m + 0xD0, m + 0xC0, &matrix);
        func_0038CF68(m + 0xD0, m + 0xD0, 1.0f);
        func_0038CE90(m + 0xE0, m + 0xD0, m + 0xC0);
        *(f32 *)(m + 0xEC) = zero;
        *(f32 *)(m + 0xDC) = zero;
        *(f32 *)(m + 0xCC) = zero;
        v->owner = owner;
        func_0038CE20(offset.v, (f32 *)(m + 0xC0), 0.5f);
        __asm__("lqc2 $vf1, %1\n\t"
                "lqc2 $vf2, %2\n\t"
                "vadd.xyz $vf1, $vf1, $vf2\n\t"
                "sqc2 $vf1, %0"
                : "=m"(*(Vector_00349998 *)(m + 0x10))
                : "m"(*(Vector_00349998 *)(m + 0x10)), "m"(offset)
                : "vf1", "vf2");
        if (height != zero && *(f32 *)(m + 0x18) - height >= 6.0f) height = zero;
        v->height = height;
        v->random[0] = func_00382538();
        v->random[1] = func_00382538();
        v->random[2] = func_00382538();
        v->random[3] = func_00382538();
        v->random[4] = func_00382538();
        v->random[5] = func_00382538();
        v->a1C = 17;
        v->a1E = 50;
        v->a20 = 0.05882352963089943f;
        v->a24 = 0.019999999552965164f;
        v->a28 = 15;
        v->a2C = 0.06666667014360428f;
        v->a2A = 33;
        v->a30 = 0.03030303120613098f;
        if (func_003D3CB0(m + 0x10, D_L01_001E2A40, 18, 0, 0)) {
            v->a36 = 0;
        } else {
            v->a36 = 13;
            v->a38 = 0.07692307978868484f;
            *(s128 *)&test = *(s128 *)(m + 0x10);
            test.v[3] = 1.0f;
            if (func_L01_00459590(&test, 0, 128.0f) == 1) {
                f32 fade_step = 0.3333333432674408f;
                s32 fade_time = 3;
                f32 step = 0.0833333358168602f;
                s32 duration = 13;
                v->a40 = duration;
                v->a3C = fade_step;
                v->a34 = fade_time;
                v->a44 = step;
            } else {
                v->a34 = 0;
                v->a40 = 0;
            }
        }
        func_L01_0034A3C8(m, matrix.v, owner);
    }
    return m;
}
/* localdecomp:end func_L01_00349998 */

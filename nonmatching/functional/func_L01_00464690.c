/* functional: high. 4 diff at default flags (register moves of the byte args only); callee func_0038CF68 called as (size, dst, src) to match the file context */
/* localdecomp:start func_L01_00464690 */
typedef struct { vu0_v4 velocity; s32 color, value; u8 b0,b1,b2,life; f32 fade; } Vars_00464690;
extern f32 D_L01_001DFB4C;
extern f32 D_L01_001DFB50;
extern u8 *D_L01_002210C4[];
u8 *func_L01_00464690(vu0_q *pos, void *velocity, s32 color, s32 value, s32 life, s32 b0, s32 b2, u8 b1, f32 fade, f32 size) {
    extern s32 func_00382468(s32);
    extern u8 *func_L01_004618E0(s32);
    extern u8 func_0013D3E0(void);
    extern f32 func_003824E0(f32, f32);
    extern void func_0038CF68(f32, void *, void *);
    u8 *p; Vars_00464690 *vars;
    vu0_v4 delta, random;
    if (life == 0) return 0;
    if ((D_L01_001DFB4C > 0.85f || D_L01_001DFB50 > 0.85f) && func_00382468(3) == 0) return 0;
    if ((D_L01_001DFB4C > 0.9f || D_L01_001DFB50 > 0.9f) && func_00382468(2) == 0) return 0;
    if ((D_L01_001DFB4C > 1.0f || D_L01_001DFB50 > 1.0f) && func_00382468(1) == 0) return 0;
    p = func_L01_004618E0(11);
    if (p != 0) {
        *(vu0_q *)(p + 0x10) = *pos;
        *(s32 *)(p + 4) = color;
        p[9] = 0xA4;
        p[3] = func_00382468(100) < 20 ? 0x44 : 0x48;
        p[1] = 0;
        *(s32 *)(p + 0xC) = 0;
        p[8] = func_0013D3E0();
        p[2] = *D_L01_002210C4[0];
        vars = (Vars_00464690 *)(p + 0x20);
        *(vu0_q *)&random = 0;
        random.x = func_003824E0(-1.0f, 1.0f);
        random.y = func_003824E0(-1.0f, 1.0f);
        random.z = func_003824E0(-1.0f, 1.0f);
        delta = random;
        func_0038CF68(size, &delta, &delta);
        vec_add_ab(&vars->velocity, velocity, &delta);
        vars->velocity.w = size * 0.75f;
        *(s16 *)(p + 0xA) = life;
        vars->life = life;
        vars->b0 = b0;
        vars->fade = fade;
        vars->color = color;
        vars->value = value;
        vars->b2 = b2;
        vars->b1 = b1;
    }
    return p;
}
/* localdecomp:end func_L01_00464690 */

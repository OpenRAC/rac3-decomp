/* functional: high. Codex near-miss draft; matches the .s in every constant (0.4f, 31500.002f, -1). */
/* localdecomp:start func_L01_00473860 */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) Vector_00473860;
typedef struct {
    f32 vx, vy, vz, gravity, growth;
    u8 alpha, spin;
} Motion_00473860;
typedef struct {
    u8 pad[4];
    s32 color;
    u8 spin, flags;
    s16 life;
    f32 size;
    Vector_00473860 position;
    Motion_00473860 motion;
} Particle_00473860;
void func_L01_00473860(u8 *raw) {
    extern s32 func_0038CB00(void *);
    extern void func_003CD250(u8 *);
    extern s32 func_00382468(s32);
    extern void func_L01_0046A938(void *, f32, f32, s32, s32);
    extern void func_L01_004CAB30(void *, void *);
    Particle_00473860 *p = (Particle_00473860 *)raw;
    Motion_00473860 *m;
    Vector_00473860 v;
    if (func_0038CB00(&p->life)) {
        func_003CD250(raw);
        if (func_00382468(10) == 1) {
            func_L01_0046A938(&p->position, 0.4f, 31500.001953125f, 0, -1);
        }
    } else {
        m = &p->motion;
        p->color = (p->color & 0xFFFFFF) | (((p->color >> 24) + m->alpha) << 24);
        v.x = m->vx;
        v.y = m->vy;
        v.z = m->vz;
        v.w = 0.0f;
        __asm__(
            "lqc2 $vf2,%1
"
            "lqc2 $vf1,%2
"
            "vadd.xyz $vf2,$vf2,$vf1
"
            "sqc2 $vf2,%0"
            : "=m"(p->position)
            : "m"(p->position), "m"(v)
            : "vf1", "vf2");
        func_L01_004CAB30(&p->position, &p->position);
        m->vz -= m->gravity;
        if (p->position.w != 0.0f) {
            if (p->position.w == 2.0f) {
                func_L01_004CAB30(&p->position, &p->position);
            }
            p->position.w = 2.0f;
        }
        p->spin += m->spin;
        p->size += m->growth;
    }
}
/* localdecomp:end func_L01_00473860 */

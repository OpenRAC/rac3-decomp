/* functional: medium. Near-miss draft (compiles under file flags); 159 diff words; 0x7FFFFFFF constant present; description inferred from draft and callee inventory, not every branch re-read */
/* localdecomp:start func_L01_0034DBE8 */
typedef struct {
    s128 position[4];
    s32 c0, c1, c2, c3;
    f32 uv[8];
    unsigned long flags, texture, primitive, alpha;
} Beam_0034DBE8;
typedef union { s128 q; f32 f[4]; } V_0034DBE8;
typedef struct { s32 value; } State_0034DBE8;
extern State_0034DBE8 D_001A5E08;
extern s128 D_L01_001E29C0;
void func_L01_0034DBE8(s32 unused, s32 alpha, s128 *points, s32 count) {
    extern unsigned long func_00389598(s32);
    extern void func_L01_0034DBA8(s128 *, s32);
    extern void func_L01_0034D840(u8 *p);
    extern void func_0038CF68(void *, void *, f32);
    extern void func_0038CE90(void *, void *, void *);
    extern void func_0038CE20(f32 *, f32 *, f32);
    extern void func_0038D028(void *, void *, void *);
    extern void func_003D2DA0(void *, s32, s32);
    struct {
        Beam_0034DBE8 core, glow;
        s128 basis[4];
        V_0034DBE8 thin, thick;
    } v;
    s32 color = 0x80FF0000;
    s32 i = 1;
    f32 u, next;
    if (D_001A5E08.value == 47) color = 0x800000FF;
    v.core.texture = func_00389598(43);
    v.core.alpha = ((unsigned long)alpha << 32) | 104;
    v.core.c0 = 0x7FFFFFFF;
    v.core.primitive = 0xFF9000000260UL;
    v.core.c1 = 0x7FFFFFFF;
    v.core.flags = 0;
    v.glow.texture = func_00389598(43);
    v.glow.primitive = 0xFF9000000260UL;
    v.glow.alpha = ((unsigned long)(alpha / 3) << 32) | 104;
    v.core.c1 = color;
    v.glow.c0 = color;
    v.glow.flags = 0;
    v.thin.q = 0;
    v.thick.q = 0;
    v.thin.f[2] = 0.05f; v.thin.f[3] = 1.0f;
    v.thick.f[2] = 0.2f; v.thick.f[3] = 1.0f;
    func_L01_0034DBA8(points, count);
    func_L01_0034D840((u8 *)&v.core);
    func_L01_0034D840((u8 *)&v.glow);
    __asm__("lqc2 $vf1, %1\n\tlqc2 $vf2, %2\n\tvsub.xyz $vf2, $vf2, $vf1\n\tsqc2 $vf2, %0"
       : "=m"(v.basis[0]) : "m"(points[0]), "m"(points[1]) : "vf1", "vf2");
    v.core.uv[0]=0;v.core.uv[1]=0;v.core.uv[2]=0;v.core.uv[3]=1;
    v.core.uv[4]=1;v.core.uv[5]=0;v.core.uv[6]=1;v.core.uv[7]=1;
    v.glow.uv[0]=0;v.glow.uv[1]=0;v.glow.uv[2]=0;v.glow.uv[3]=1;
    v.glow.uv[4]=0.33f;v.glow.uv[5]=0;v.glow.uv[6]=0.33f;v.glow.uv[7]=1;
    func_0038CF68(&v.basis[0], &v.basis[0], 1.0f);
    __asm__("lqc2 $vf2, %2\n\tlqc2 $vf1, %1\n\tvsub.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0"
       : "=m"(v.basis[1]) : "m"(D_L01_001E29C0), "m"(points[0]) : "vf1", "vf2");
    func_0038CE90(&v.basis[2], &v.basis[1], &v.basis[0]);
    func_0038CF68(&v.basis[2], &v.basis[2], 1.0f);
    func_0038CE90(&v.basis[1], &v.basis[0], &v.basis[2]);
    v.basis[3] = points[0];
    v.core.position[0] = v.thin.q;
    func_0038CE20((f32 *)&v.core.position[1], (f32 *)&v.core.position[0], -1.0f);
    func_0038D028(&v.core.position[0], &v.core.position[0], v.basis);
    func_0038D028(&v.core.position[1], &v.core.position[1], v.basis);
    v.glow.position[0] = v.thick.q;
    func_0038CE20((f32 *)&v.glow.position[1], (f32 *)&v.glow.position[0], -1.0f);
    func_0038D028(&v.glow.position[0], &v.glow.position[0], v.basis);
    func_0038D028(&v.glow.position[1], &v.glow.position[1], v.basis);
    for (; i < count-1; i++) {
        v.core.position[2] = v.thin.q;
        func_0038CE20((f32 *)&v.core.position[3], (f32 *)&v.core.position[2], -1.0f);
        v.glow.position[2] = v.thick.q;
        func_0038CE20((f32 *)&v.glow.position[3], (f32 *)&v.glow.position[2], -1.0f);
        __asm__("lqc2 $vf1, %1\n\tlqc2 $vf2, %2\n\tvsub.xyz $vf2, $vf2, $vf1\n\tsqc2 $vf2, %0"
           : "=m"(v.basis[0]) : "m"(points[i]), "m"(points[i+1]) : "vf1", "vf2");
        func_0038CF68(&v.basis[0], &v.basis[0], 1.0f);
        __asm__("lqc2 $vf1, %2\n\tlqc2 $vf2, %1\n\tvsub.xyz $vf2, $vf2, $vf1\n\tsqc2 $vf2, %0"
           : "=m"(v.basis[1]) : "m"(D_L01_001E29C0), "m"(points[i]) : "vf1", "vf2");
        func_0038CE90(&v.basis[2], &v.basis[1], &v.basis[0]);
        func_0038CF68(&v.basis[2], &v.basis[2], 1.0f);
        func_0038CE90(&v.basis[1], &v.basis[0], &v.basis[2]);
        v.basis[3] = points[i];
        func_0038D028(&v.core.position[2], &v.core.position[2], v.basis);
        func_0038D028(&v.core.position[3], &v.core.position[3], v.basis);
        func_0038D028(&v.glow.position[2], &v.glow.position[2], v.basis);
        func_0038D028(&v.glow.position[3], &v.glow.position[3], v.basis);
        v.core.c3 = 0x7F7F7F7F;
        v.core.c2 = 0x7F7F7F7F;
        v.glow.c3 = color;
        v.glow.c2 = color;
        func_003D2DA0(&v.core,0,0);
        func_003D2DA0(&v.glow,0,0);
        u = i * 0.33f;
        next = u + 0.33f;
        if (u >= 1.0f) { u -= 1.0f; next -= 1.0f; }
        v.glow.uv[2] = u;
        v.glow.uv[6] = next;
        v.core.position[0] = v.core.position[2];
        v.core.position[1] = v.core.position[3];
        v.glow.position[0] = v.glow.position[2];
        v.glow.position[1] = v.glow.position[3];
        v.glow.uv[0] = u;
        v.glow.uv[4] = next;
    }
}
/* localdecomp:end func_L01_0034DBE8 */

/* functional: high. vadd.xyz written as float adds plus the w lane retail's sqc2 stores (vars w); qzero as a plain 128-bit zero store. */
typedef struct { u8 pad[0x1C]; s32 count; u8 pad20[8]; f32 z; } Collision_0035E010;
extern Collision_0035E010 D_L01_001EAA00;

void func_L01_0035E010(u8 *pod)
{
    extern void func_L01_004C8688(s32, void *, s32);
    extern void func_L01_004C7D40(void *, void *, f32);
    extern s32 func_L01_003FB640(void *, s32, void *, f32);
    extern u32 func_003D5630(void);
    extern u8 *func_L01_003016B0(void *, s32, f32, f32);
    extern f32 func_00382538(void);
    extern f32 func_003824E0(f32, f32);
    extern f32 func_0038D098(f32);
    extern f32 func_0038D0B0(f32);
    extern s32 func_00382498(s32, s32);
    extern s32 func_00382468(s32);
    extern void func_L01_00468A68(void *, void *, s32, s32);
    extern void func_L01_004450F0(u8 *, s32, s32);
    extern s32 func_003D3CB0(void *, void *, s32, void *, s32);
    extern s32 func_0038CAD0(void *);
    extern f32 func_0038CEA8(void *);
    S_38C110v old, pos, velocity;
    S_38C110v *velocity_ptr;
    PodVars_0035DEC8 *vars;
    u8 *particle;
    u32 material;
    s32 i, life, kind;
    f32 angle, speed;
    old = *(S_38C110v *)(pod + 0x10);
    vars = *(PodVars_0035DEC8 **)(pod + 0x68);
    func_L01_004C8688(vars->shadow, vars, 0);
    func_L01_004C7D40(pod + 0x10, vars, 0.0044f);
    {
        f32 *vf = (f32 *)vars;
        f32 *pp = (f32 *)(pod + 0x10);
        pp[0] = vf[0] + pp[0]; pp[1] = vf[1] + pp[1]; pp[2] = vf[2] + pp[2];
        pp[3] = vf[3]; /* vadd.xyz keeps the vars quad's w */
    }
    if (func_L01_003FB640(pod + 0x10, 16, pod, 0.1f)) {
        material = func_003D5630();
        if (material < 2 || material == 11) {
            *(s128 *)vars = 0;
            vars->landed = 1;
            *(f32 *)((u8 *)vars + 8) = -0.030000001192092896f;
            pos.x = *(f32 *)(pod + 0x10);
            pos.y = *(f32 *)(pod + 0x14);
            pos.z = D_L01_001EAA00.z;
            particle = func_L01_003016B0(&pos, 3, 2.0f, 1.025f);
            if (particle) particle[0x23] = 0x70;
            velocity_ptr = &velocity;
            for (i = 15; i >= 0; i--) {
                angle = func_00382538();
                speed = func_003824E0(0.0f, 0.06000000238418579f);
                velocity.x = func_0038D098(angle) * speed;
                velocity.y = func_0038D0B0(angle) * speed;
                velocity.z = func_003824E0(0.06000000238418579f, 0.1300000101327896f);
                life = func_00382498(90, 120);
                kind = func_00382468(2);
                func_L01_00468A68(&pos, velocity_ptr, kind, life);
            }
            func_L01_004450F0(pod, 1, -1);
        } else if (*(s32 *)((u8 *)&D_L01_001EAA00 + 0x1C) > 0) {
            func_L01_004450F0(pod, 2, -1);
        }
    } else if (func_003D3CB0(&old, pod + 0x10, 16, pod, 0)) {
        if (func_003D5630() == 0 && *(f32 *)((u8 *)vars + 8) < 0.0f) {
            *(s128 *)vars = 0;
            vars->landed = 1;
            *(f32 *)((u8 *)vars + 8) = -0.030000001192092896f;
            pos.x = *(f32 *)(pod + 0x10);
            pos.y = *(f32 *)(pod + 0x14);
            pos.z = D_L01_001EAA00.z;
            particle = func_L01_003016B0(&pos, 3, 2.0f, 1.025f);
            if (particle) particle[0x23] = 0x70;
            velocity_ptr = &velocity;
            for (i = 15; i >= 0; i--) {
                angle = func_00382538();
                speed = func_003824E0(0.0f, 0.06000000238418579f);
                velocity.x = func_0038D098(angle) * speed;
                velocity.y = func_0038D0B0(angle) * speed;
                velocity.z = func_003824E0(0.06000000238418579f, 0.1300000101327896f);
                life = func_00382498(90, 120);
                kind = func_00382468(2);
                func_L01_00468A68(&pos, velocity_ptr, kind, life);
            }
            func_L01_004450F0(pod, 1, -1);
        }
        if (D_L01_001EAA00.count > 0) func_L01_004450F0(pod, 2, -1);
    }
    if (func_0038CAD0(&vars->countdown) || func_0038CEA8(vars) < 0.010000000707805157f) {
        func_L01_004450F0(pod, 2, -1);
    }
}

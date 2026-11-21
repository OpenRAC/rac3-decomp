/* functional: high. EXACT at levels 01, 05 and 20 (the file context compiles it; func_0038CF68 is declared with void* here while the file declares it later with S_0030CD20 pointers, so that typedef must be hoisted or the later prototype reconciled). */
extern s32 D_L01_001D673C;
extern u8 *D_L01_001EAA18[];
typedef struct { vu0_v4 other, position, normal; } C_00309D28;
extern C_00309D28 D_L01_001EAA20[1];
typedef struct { f32 r, g, b; s32 flags; vu0_v4 position; } L_00309D28;
extern L_00309D28 D_L01_001F1B40[];
u8 *func_L01_00309D28(u8 *ball) {
    extern f32 func_0038DB00(f32, f32);
    extern void func_L01_004C8688(s32, void *, s32);
    extern s32 func_L01_004CB2D8(void);
    extern void func_L01_004CAC40(void *, void *);
    extern void func_L01_0044C280(void *, void *, void *, s32, f32);
    extern s32 func_L01_003FB640(void *, s32, void *, f32);
    extern void func_0038CF68(void *, void *, f32);
    extern void func_L01_0040E790(void *, void *, void *);
    extern f32 func_0038CE68(void *, void *);
    extern void func_L01_0030BF20(void *, void *, s32, u32);
    extern void func_003A52A0(s32, s32, void *);
    extern void func_L01_0030B400(u8 *, s32);
    vu0_v4 old, normal, component, tangent;
    StormVars_00309B80 *v = *(StormVars_00309B80 **)(ball + 0x68);
    u8 *hit = 0, *target;
    L_00309D28 *light;
    f32 jitter;
    *(f32 *)(ball + 0xF0) = func_0038DAB8(*(f32 *)(ball + 0xF0), 0.06283185631036758f);
    *(f32 *)(ball + 0xF4) = func_0038DB00(*(f32 *)(ball + 0xF4), 0.015707964077591896f);
    *(s32 *)(ball + 0xFC) = 0;
    func_0038D308(ball + 0xC0, ball + 0xF0);
    *(vu0_q *)&old = *(vu0_q *)(ball + 0x10);
    func_L01_004C8688(v->x50, v, 0);
    vec_add_ab(ball + 0x10, v, ball + 0x10);
    if (func_L01_004CB2D8()) func_L01_004CAB30(ball + 0x10, ball + 0x10);
    func_L01_004CAC40(v, v);
    if (D_L01_001D673C == 0 && func_0038CEA8(v) != 0.0f && func_0038CEA8(&v->start_velocity) != 0.0f) {
        func_L01_0044C280(v, v, &v->start_velocity, 0, 0.075f);
    }
    if (func_L01_003FB640(ball + 0x10, 0, ball, v->x4C)) {
        target = D_L01_001EAA18[0];
        if (target != 0 && target != D_001A71A0[0] && *(s16 *)(target + 0xAA) != 0x5CA) {
            hit = 0;
            if (*(u16 *)(target + 0x34) & 0x1000) hit = target;
        }
        *(vu0_q *)(ball + 0x10) = *(vu0_q *)&D_L01_001EAA20[0].position;
        func_0038CE20((f32 *)&normal, (f32 *)&D_L01_001EAA20[0].normal, 0.0009765625f);
        func_0038CF68(&normal, &normal, 1.0f);
        func_L01_0040E790(v, v, &normal);
        { f32 dot = func_0038CE68(v, &normal);
          func_0038CE20((f32 *)&component, (f32 *)&normal, dot); }
        vec_sub_ba(&tangent, v, &component);
        func_0038CE20((f32 *)v, (f32 *)&component, 0.85f);
        vec_add_ab(v, &tangent, v);
        func_0038CE20((f32 *)&v->start_velocity, (f32 *)&v->start_velocity, 0.95f);
        func_L01_0030BF20(&D_L01_001EAA20[0].other, &normal, 6, 0x72FF);
        func_L01_0030BF20(&D_L01_001EAA20[0].other, &normal, 6, 0xFF0000);
        func_003A52A0(1, 0, ball);
    }
    if (v->light != -1) {
        light = D_L01_001F1B40 + v->light;
        *(vu0_q *)&light->position = *(vu0_q *)(ball + 0x10);
        light->position.w = 4.0f;
        light->r = 0.25f;
        light->g = 0.14f;
        light->b = 1.0f;
        light->flags = 0;
        jitter = func_003824E0(-0.1f, 0.1f);
        light->r += jitter;
        light->g += jitter;
        light->b += jitter;
    }
    if (*(f32 *)(ball + 0x10) < 2.0f || *(f32 *)(ball + 0x10) > 1021.0f ||
        *(f32 *)(ball + 0x14) < 2.0f || *(f32 *)(ball + 0x14) > 1021.0f ||
        *(f32 *)(ball + 0x18) < 2.0f || *(f32 *)(ball + 0x18) > 1021.0f) {
        ball[0x20] = 3;
        *(vu0_q *)(ball + 0x10) = *(vu0_q *)&old;
    }
    if (v->x58 < 8) func_L01_0030B400(ball, (func_00382498(8, 20) * 5 + 2) / 6);
    return hit;
}

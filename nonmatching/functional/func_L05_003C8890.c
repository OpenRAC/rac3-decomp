/* functional: high. Ported from the NTSC-U draft with PAL constants (life 250, call ids 12/17) and PAL callees; compiles at level_05, not byte-exact (register allocation/spill order). */
typedef struct { vu0_v4 direction, velocity; s32 life, a24, a28; f32 amount; s32 owner, other; } S_L05_3C8890;
typedef struct { u8 pad0[0x10]; vu0_v4 position; u8 state; u8 pad21[0xb]; f32 scale; u8 alpha, b31; s16 render; u16 flags; u8 pad36[0x32]; S_L05_3C8890 *vars; u8 pad6c[0x54]; vu0_v4 right, up, forward; } O_L05_3C8890;
extern void func_003C5180(void *, void *, s32);
extern O_L05_3C8890 *func_003C24B0(s32, s32);
extern void func_L01_00443B88(void *, f32, f32);
extern f32 func_003824E0(f32, f32);
extern f32 func_0038D0B0(f32);
extern f32 func_0038D098(f32);
extern void func_0038CF68(void *, void *, f32);
extern void func_0038CE90(void *, void *, void *);
extern void func_L01_0046B458(void *, s32, f32, f32, s32, s32, s32, void *, f32, s32);
extern void func_L01_00470C78(void *, s32, f32, f32, s32, s32, s32, void *, s32, s32, s16, s32);
extern s32 D_001DECB0_sda[2];
extern f32 D_001DECD0_sda[2];
extern f32 D_001DECF0_sda[2];
extern s32 D_001DED10_sda[2];
extern vu0_v4 D_L05_001D66B0;
O_L05_3C8890 *func_L05_003C8890(s32 arg0, s32 arg1, vu0_v4 *position, vu0_v4 *direction, f32 amount) {
    vu0_v4 normal, temp;
    O_L05_3C8890 *obj;
    S_L05_3C8890 *s;
    f32 angle;
    s32 i, j;
    func_003C5180(position, &normal, 1);
    obj = func_003C24B0(0x1C33, 0x80);
    if (obj) {
        s = obj->vars;
        obj->flags |= 0x100;
        s->life = 250;
        obj->scale = 0.003f;
        obj->alpha = 255;
        obj->render = 255;
        obj->state = 0;
        *(vu0_q *)&obj->position = *(vu0_q *)position;
        *(vu0_q *)&s->direction = *(vu0_q *)direction;
        s->other = arg1;
        func_L01_00443B88(&s->velocity, 0.2f, 1.0f);
        angle = func_003824E0(-1000.0f, 1000.0f) * 0.0174532924f * 0.0166666675f;
        func_0038CF68(&s->velocity, &s->velocity, func_0038D0B0(angle));
        s->velocity.w = func_0038D098(angle);
        s->amount = amount;
        s->a28 = 0;
        s->a24 = 0;
        func_0038CF68(&temp, direction, 1.0f);
        *(vu0_q *)&obj->right = *(vu0_q *)&temp;
        func_0038CE90(&obj->up, &obj->right, &normal);
        func_0038CF68(&obj->up, &obj->up, 1.0f);
        func_0038CE90(&obj->forward, &obj->up, &obj->right);
        obj->right.w = obj->up.w = obj->forward.w = 0.0f;
        s->owner = arg0;
        for (i = 3; i >= 0; i--) {
            func_L01_0046B458(position, 12, D_001DECD0_sda[i], D_001DECF0_sda[i], D_001DECB0_sda[i], 2, 1, &D_L05_001D66B0, 0.0f, 1);
        }
        for (j = 4; j < 7; j++) {
            func_L01_00470C78(position, 17, D_001DECD0_sda[j], D_001DECF0_sda[j], D_001DECB0_sda[j], 2, 2, &D_L05_001D66B0, 0, D_001DED10_sda[j - 4], 6, 1);
        }
    }
    return obj;
}

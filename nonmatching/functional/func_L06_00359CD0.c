/* functional: high. Ported from the matched level-20 copy func_L20_003EBA98 (same routine) and re-verified against L06 asm: constants (60.0 timer, 0.8 scale, 0.5/0.9/0.7 thresholds, colours, angles) taken from L06 immediates. 250 instrs differ (scheduling). Only state-3 blend and the 0.7 fall-through into 4/5 as retail. */
extern void func_L06_00359B60(u8 *, u8 *, f32, f32);
extern void func_0038D2A0(void *);
extern long func_00389598(s32);
extern void func_003D2DA0(void *, void *, s32);
extern f32 D_L06_001DD3E0[];
extern f32 D_L06_001DD3E4[];

/* Quad buffer: 0x40 bytes of positions (4 x vec4), 4 colours at 0x40, 4 uv pairs at 0x50, 4 GS regs at 0x70. */
typedef struct {
    u8 vertices[0x50];
    f32 uv[4][2];
    unsigned long regs[4];
} Q_00359CD0;

void func_L06_00359CD0(u8 *a0) {
    Q_00359CD0 q;
    u8 ctx[0x40];
    u8 *v;
    f32 t;
    f32 blend;
    f32 fade;
    s32 i;

    if (a0[0x20] < 3) {
        return;
    }
    v = *(u8 **)(a0 + 0x68);
    if (a0[0x20] == 3) {
        t = 1.0f - (f32) * (s32 *)v / 60.0f;
    } else {
        t = 1.0f;
    }
    func_0038D2A0(ctx);
    q.regs[1] = func_00389598(0x27);
    q.regs[2] = 0xFF9000000260UL;
    q.regs[3] = 0x8000000048UL;
    q.regs[0] = 0;
    for (i = 0; i < 4; i++) {
        q.uv[i][0] = D_L06_001DD3E0[i * 2];
        q.uv[i][1] = D_L06_001DD3E4[i * 2];
    }
    switch (a0[0x20]) {
    case 3:
        if (0.0f <= t && t < 0.5f) {
            blend = (t - 0.0f) * 2.0f;
            func_L06_00359C38((u8 *)&q, 0x20C03030, 0x80C03030, blend);
            fade = 1.0f - blend;
            func_L06_00359B60(v, (u8 *)&q, 0.8f + fade * 0.8f * 0.5f, *(f32 *)(a0 + 0xF0) + fade * 0.7853982f);
            func_003D2DA0(&q, ctx, 0);
            func_L06_00359B60(v, (u8 *)&q, 0.8f - fade * 0.8f * 0.5f, *(f32 *)(a0 + 0xF0) + fade * -0.7853982f);
            func_003D2DA0(&q, ctx, 0);
        }
        if (0.5f <= t && t < 0.9f) {
            blend = (t - 0.5f) / 0.39999998f;
            func_L06_00359C38((u8 *)&q, 0x6000F0F0, 0xF0F0, blend);
            func_L06_00359B60(v, (u8 *)&q, 0.8f + blend * 0.8f * 0.05f, *(f32 *)(a0 + 0xF0));
            func_003D2DA0(&q, ctx, 0);
        }
        if (0.5f <= t && t < 1.0f) {
            blend = (t - 0.5f) * 2.0f;
            func_L06_00359C38((u8 *)&q, 0x80800080, 0x04F00060, blend);
            func_L06_00359B60(v, (u8 *)&q, 0.8f + blend * 0.8f * 0.25f, *(f32 *)(a0 + 0xF0) + blend * 0.2617994f);
            func_003D2DA0(&q, ctx, 0);
            func_L06_00359B60(v, (u8 *)&q, 0.8f - blend * 0.8f * 0.25f, *(f32 *)(a0 + 0xF0) + blend * -0.2617994f);
            func_003D2DA0(&q, ctx, 0);
        }
        if (0.5f <= t && t < 0.7f) {
            func_L06_00359C38((u8 *)&q, 0x102040D0, 0x802050F0, (t - 0.5f) / 0.19999999f);
            func_L06_00359B60(v, (u8 *)&q, 0.8f, *(f32 *)(a0 + 0xF0));
            func_003D2DA0(&q, ctx, 0);
        }
        if (t < 0.7f) {
            break;
        }
    case 4:
    case 5:
        func_L06_00359CA8((s32)&q, 0x802050F0);
        func_L06_00359B60(v, (u8 *)&q, 0.8f, *(f32 *)(a0 + 0xF0));
        func_003D2DA0(&q, ctx, 0);
        break;
    }
}

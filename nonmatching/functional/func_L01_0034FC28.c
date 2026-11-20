/* functional: medium. The file context declares this void(void) but retail reads the moby from a0 (the callback arg of func_L01_00404808): m is read from a0 via a register variable at entry; when applied, change the context declaration to (u8 *m) and use a plain parameter. Written from asm; compiles (236 diff words, stack layout). Retail reads the moby from a0 (lw 0x68(a0)) but the file context declares void(void): declaration must become (u8 *m) when applied. */
extern u8 *D_L01_001E2EC0[];
extern s32 D_L01_001E2EC4[];
extern f32 D_L01_001E2EC8[];
extern s32 D_001D4BC8, D_001D4BCC, D_001D4BD0, D_001D4BD4;
extern f32 func_0038CF00(void *, void *);
extern void func_003860A8(f32 *, void *);
extern unsigned long func_00389598(s32);
extern void func_0038B4D0(s32 a, s32 b, s32 c, s32 d, s32 e, s32 f, s32 g, s32 h, long i, long j);
extern u8 D_L01_001E29C0[];
void func_L01_0034FC28(void) {
    register u8 *m __asm__("$4");
    u8 *vars = *(u8 **)(m + 0x68);
    s16 *idx = (s16 *)((u8 *)D_L01_001E2EC0 + 0x30);
    s16 *sz = (s16 *)((u8 *)D_L01_001E2EC0 + 0x10);
    s32 *col = (s32 *)((u8 *)D_L01_001E2EC0 + 0x50);
    f32 *scl = (f32 *)((u8 *)D_L01_001E2EC0 + 0x90);
    f32 *wid = (f32 *)((u8 *)D_L01_001E2EC0 + 0xD0);
    f32 zero = 0.0f;
    f32 near, W, H, pos[4], d[2], off[2], p2[2];
    f32 a, b;
    s32 i;

    if (D_L01_001E2EC4[0] != 1) {
        D_L01_001E2EC4[0] = 0;
        return;
    }
    if (D_L01_001E2EC0[0][0x20] & 0x80) {
        D_L01_001E2EC4[0] = 0;
        return;
    }
    if (D_L01_001E2EC8[0] <= zero) return;
    near = func_0038CF00(D_L01_001E29C0, vars);
    W = (f32)D_001D4BC8;
    H = (f32)D_001D4BCC;
    func_003860A8(pos, vars);
    pos[0] = (pos[0] - (f32)D_001D4BD0) * 0.0625f;
    pos[1] = (pos[1] - (f32)D_001D4BD4) * 0.0625f;
    off[0] = W - pos[0];
    off[1] = H - pos[1];
    for (i = 0; i < 14; i++) {
        f32 s = scl[i];
        f32 fade, fx, fy, k, alpha;
        s32 half, packed;
        long color, tex;
        tex = func_00389598(D_L01_001E1A0C + idx[i]);
        d[0] = off[0] * s;
        d[1] = off[1] * s;
        p2[0] = W + d[0];
        p2[1] = H + d[1];
        fade = near - 5.0f;
        if (1.0f < fade) fade = 1.0f;
        else if (fade < zero) fade = zero;
        fx = (off[0] < 0 ? -off[0] : off[0]) / W * -5.0f + 5.5f;
        if (1.0f < fx) fx = 1.0f;
        else if (fx < zero) fx = zero;
        fy = (off[1] < 0 ? -off[1] : off[1]) / H * -5.0f + 5.5f;
        if (1.0f < fy) fy = 1.0f;
        else if (fy < zero) fy = zero;
        k = fx * fy * D_L01_001E2EC8[0];
        half = (s32)(64.0f * wid[i]);
        alpha = fade * k * (f32)sz[i];
        color = (s32)alpha;
        color = (color << 24) | (col[i] & 0xFFFFFF);
        func_003A9440(0x42, (0x8000L << 24) | 0x48);
        func_0038B4D0((s32)(p2[0] - (f32)(half >> 1)), (s32)(p2[1] - (f32)(half >> 1)), half, half, 0, 0, 0x40, 0x40, color, tex);
    }
    D_L01_001E2EC8[0] = 0;
}

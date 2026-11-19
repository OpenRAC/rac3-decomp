/* functional: high. functional: high. All branches, ring indexing and call args follow the asm; only scheduling differs */
extern void func_003C3FC0(void *, void *);
extern void func_L01_0044C280(void *, void *, void *, s32, f32);
extern u8 D_001A4C60[];
extern s32 D_001DF260_sda;
__asm__(".extern D_001DF260_sda, 4");

void func_L01_003CF918(u8 *self) {
    f32 P[4];
    f32 mat[16];
    f32 Q[4];
    f32 t60[4];
    f32 z[4];
    f32 v80[4];
    f32 v90[4];
    f32 vA0[4];
    u8 *vars;
    f32 *g;
    f32 *s;
    s32 N;
    s32 idx;

    vars = *(u8 **)(self + 0x68);
    *(s32 *)(vars + 0x618) = 0;
    func_003C2F58(self, 3, P);
    func_003C2EC0(self, 3, mat);
    func_003C2F58(self, 2, Q);
    t60[0] = Q[0] - P[0]; t60[1] = Q[1] - P[1]; t60[2] = Q[2] - P[2]; t60[3] = Q[3];
    func_0038CF68(t60, t60, *(f32 *)(vars + 0x604));
    P[0] = t60[0] + Q[0]; P[1] = t60[1] + Q[1]; P[2] = t60[2] + Q[2]; P[3] = t60[3];
    if (*(f32 *)(vars + 0x618) == 0.0f) {
        N = D_001DF260_sda;
        *(s32 *)(vars + 0x60C) = (*(s32 *)(vars + 0x60C) + 1) % N;
        if (*(s32 *)(vars + 0x61C) < N) {
            *(s32 *)(vars + 0x61C) = *(s32 *)(vars + 0x61C) + 1;
        }
    }
    z[0] = 0.0f; z[1] = 0.0f; z[2] = 0.0f; z[3] = 0.0f;
    if (*(s32 *)(vars + 0x620) >= 2) {
        N = D_001DF260_sda;
        g = (f32 *)D_001A4C60;
        idx = *(s32 *)(vars + 0x60C);
        v80[0] = P[0] - g[0]; v80[1] = P[1] - g[1]; v80[2] = P[2] - g[2]; v80[3] = P[3];
        s = (f32 *)(vars + (((idx + (N - 1)) % N) << 4));
        v90[0] = s[0] - g[0]; v90[1] = s[1] - g[1]; v90[2] = s[2] - g[2]; v90[3] = s[3];
        func_L01_0044C280(vA0, v90, v80, 0, 0.5f);
        func_003C3FC0(vars + 0x200 + (*(s32 *)(vars + 0x60C) << 4), z);
        s = (f32 *)(vars + (*(s32 *)(vars + 0x60C) << 4));
        s[0] = vA0[0] + g[0]; s[1] = vA0[1] + g[1]; s[2] = vA0[2] + g[2]; s[3] = vA0[3];
        *(s32 *)(vars + 0x60C) = (*(s32 *)(vars + 0x60C) + 1) % D_001DF260_sda;
    }
    func_003C3FC0(vars + 0x200 + (*(s32 *)(vars + 0x60C) << 4), z);
    s = (f32 *)(vars + (*(s32 *)(vars + 0x60C) << 4));
    s[0] = P[0]; s[1] = P[1]; s[2] = P[2]; s[3] = P[3];
}

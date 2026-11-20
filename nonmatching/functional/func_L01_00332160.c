/* functional: high. Read against PAL asm block by block incl. both uv-projection loops and the two draws; signature (pos,id,flag,5 floats) from callers/asm (f15 unused); byte scheduling differs. */
typedef struct { f32 v[4][4]; s32 col[4]; f32 uv[4][2]; long f70, f78, f80, f88; } S_332160;
extern s32 D_001D52F0;
__asm__(".extern D_001D52F0, 16");
extern u8 D_L01_001E2A40[];
extern f32 D_L01_001D7C50[];
extern void func_003D93B0(void *, s32, s32, s32);
extern void func_0038CF68(void *, void *, f32);
extern void func_0038CE90(void *, void *, void *);
extern void func_0038CE20(void *, void *, f32);
extern void func_0038D308(void *, void *);
extern void func_0038D5F0(void *, void *, void *);
extern void func_0038D028(void *, void *, void *);
extern void func_003A9440(s32, s32);
extern void func_003D2DA0(void *, void *, s32);
extern void func_00389478(void *, f32 *, f32 *);
extern s32 func_00382468(s32);
extern f32 func_003824E0(f32, f32);

void func_L01_00332160(void *pos, s32 id, s32 flag, f32 f12, f32 f13, f32 f14, f32 f15, f32 f16) {
    S_332160 Q __attribute__((aligned(16)));
    f32 M[16] __attribute__((aligned(16)));
    f32 vD0[4] __attribute__((aligned(16)));
    f32 rot[12] __attribute__((aligned(16)));
    f32 vF0[4] __attribute__((aligned(16)));
    f32 ang[4] __attribute__((aligned(16)));
    f32 *E;
    f32 *p = (f32 *)pos;
    f32 *tbl;
    s32 col = 0x80808080;
    f32 j, c;
    int i, k;

    func_003D93B0(&Q, id, 1, 0x80);
    E = (f32 *)(D_L01_001E2A40 + D_001D52F0 * 0x460);
    Q.f88 = 0x800000004AL;
    M[12] = p[0]; M[13] = p[1]; M[14] = p[2]; M[15] = p[3];
    Q.col[0] = col; Q.col[1] = col; Q.col[2] = col; Q.col[3] = col;
    Q.uv[0][0] = 0.0f; Q.uv[0][1] = 0.0f;
    Q.uv[1][0] = 0.0f; Q.uv[1][1] = 1.0f;
    Q.uv[2][0] = 1.0f; Q.uv[2][1] = 0.0f;
    Q.uv[3][0] = 1.0f; Q.uv[3][1] = 1.0f;
    M[0] = E[0] - M[12];
    M[1] = E[1] - M[13];
    M[2] = E[2] - M[14];
    M[3] = E[3];
    func_0038CF68(&M[0], &M[0], 1.0f);
    E = (f32 *)(D_L01_001E2A40 + D_001D52F0 * 0x460);
    func_0038CE90(&M[4], &M[0], E + 0x1D0 / 4);
    func_0038CF68(&M[4], &M[4], 1.0f);
    func_0038CE90(&M[8], &M[4], &M[0]);
    if (f14 != 0.0f) {
        ang[0] = 0.0f; ang[1] = 0.0f; ang[2] = 0.0f; ang[3] = 0.0f;
        ang[0] = f14;
        func_0038D308(rot, ang);
        func_0038D5F0(&M[0], &M[0], rot);
    }
    func_0038CE20(vD0, &M[0], f13);
    M[12] = M[12] + vD0[0];
    M[13] = M[13] + vD0[1];
    M[14] = M[14] + vD0[2];
    tbl = D_L01_001D7C50;
    for (i = 0; i < 4; i++) {
        func_0038CE20(Q.v[i], tbl + i * 4, f12);
        func_0038D028(Q.v[i], Q.v[i], &M[0]);
    }
    func_003A9440(0x47, 0x31001);
    func_003D2DA0(&Q, 0, 0);

    if (flag != 0) {
        f32 sum[4] __attribute__((aligned(16)));
        sum[0] = Q.v[0][0]; sum[1] = Q.v[0][1]; sum[2] = Q.v[0][2]; sum[3] = Q.v[0][3];
        for (i = 1; i < 4; i++) {
            sum[0] = sum[0] + Q.v[i][0];
            sum[1] = sum[1] + Q.v[i][1];
            sum[2] = sum[2] + Q.v[i][2];
        }
        func_0038CE20(sum, sum, 0.25f);
        for (k = 0; k < 4; k++) {
            vF0[0] = Q.v[k][0] - sum[0];
            vF0[1] = Q.v[k][1] - sum[1];
            vF0[2] = Q.v[k][2] - sum[2];
            vF0[3] = Q.v[k][3];
            func_0038CE20(vF0, vF0, 0.8f);
            vF0[0] = sum[0] + vF0[0];
            vF0[1] = sum[1] + vF0[1];
            vF0[2] = sum[2] + vF0[2];
            vF0[3] = sum[3];
            func_00389478(vF0, &Q.uv[k][0], &Q.uv[k][1]);
            if (0.0f < f16) {
                if (func_00382468(1) == 0) {
                    Q.uv[k][0] = Q.uv[k][0] + func_003824E0(-f16, f16);
                    Q.uv[k][1] = Q.uv[k][1] + func_003824E0(-f16, f16);
                }
            }
            if (1.0f < Q.uv[k][0]) {
                Q.uv[k][0] = 1.0f;
            } else if (Q.uv[k][0] < 0.0f) {
                Q.uv[k][0] = 0.0f;
            }
            if (1.0f < Q.uv[k][1]) {
                Q.uv[k][1] = 1.0f;
            } else if (Q.uv[k][1] < 0.0f) {
                Q.uv[k][1] = 0.0f;
            }
        }
    } else {
        for (k = 0; k < 4; k++) {
            func_00389478(Q.v[k], &Q.uv[k][0], &Q.uv[k][1]);
            if (func_00382468(1) == 0) {
                Q.uv[k][0] = Q.uv[k][0] + func_003824E0(-f16, f16);
                Q.uv[k][1] = Q.uv[k][1] + func_003824E0(-f16, f16);
            }
            if (1.0f < Q.uv[k][0]) {
                Q.uv[k][0] = 1.0f;
            } else if (Q.uv[k][0] < 0.0f) {
                Q.uv[k][0] = 0.0f;
            }
            if (1.0f < Q.uv[k][1]) {
                Q.uv[k][1] = 1.0f;
            } else if (Q.uv[k][1] < 0.0f) {
                Q.uv[k][1] = 0.0f;
            }
        }
    }
    func_003D93B0(&Q, -1, 1, 0x80);
    Q.f88 = 0x8000000054L;
    func_003A9440(0x47, 0x53001);
    func_003D2DA0(&Q, 0, 0);
    func_003A9440(0x47, 0x5360B);
}

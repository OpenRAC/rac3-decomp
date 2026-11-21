/* functional: high. Decoded block by block against the PAL asm (calls, stores, uv flip branch, matrix rows); retail's stack layout/scheduling differs, behaviour same. Parameter is void* to match the file's earlier declaration. */
typedef struct { f32 v[4][4]; s32 col[4]; f32 uv[4][2]; long f70, f78, f80, f88; } S_32FF68;
extern s32 D_001DFB40;
extern u8 D_L01_001E29C0[];
extern void func_003C2F58(void *, s32, void *);
extern f32 func_003824E0(f32, f32);
extern void func_0038CF68(void *, void *, f32);
extern void func_0038D000(void *, void *, void *);
extern void func_0038D028(void *, void *, void *);
extern void func_L01_0032FC70(void *, void *);
extern long func_00389598(s32);
extern void func_L01_0032FBE0(void *);
extern s32 func_0013D3E0(void);
extern void func_0038CE20(void *, void *, f32);
extern void func_0038CE90(void *, void *, void *);
extern void func_003D2DA0(void *, void *, s32);

void func_L01_0032FF68(void *obj) {
    u8 *moby = obj;
    S_32FF68 A __attribute__((aligned(16)));
    S_32FF68 B __attribute__((aligned(16)));
    f32 M[16] __attribute__((aligned(16)));
    f32 p180[4] __attribute__((aligned(16)));
    f32 p160[4] __attribute__((aligned(16)));
    f32 p170[4] __attribute__((aligned(16)));
    f32 q190[4] __attribute__((aligned(16)));
    f32 q1A0[4] __attribute__((aligned(16)));
    f32 r;
    u8 *st = *(u8 **)(moby + 0x68);
    s32 c1 = 0x103080;
    long l1, l2;
    int i;

    if (D_001DFB40 & 1) {
        func_003C2F58(moby, 1, p180);
    } else {
        func_003C2F58(moby, 2, p180);
    }
    for (i = 0; i < 4; i++) {
        p160[i] = p180[i];
    }
    func_0038CF68(p170, st + 0x30, func_003824E0(2.0f, 4.0f));
    func_0038D000(p170, p170, moby + 0xC0);
    p170[0] = p170[0] + p180[0];
    p170[1] = p170[1] + p180[1];
    p170[2] = p170[2] + p180[2];
    func_L01_0032FC70(moby, p160);

    l1 = func_00389598(0x17);
    A.f78 = l1;
    A.f80 = 0xFF9000000260L;
    A.col[0] = 0x7F103080;
    A.col[1] = 0x7F103080;
    A.f70 = 0;
    A.f88 = 0x8000000048L;
    A.col[3] = c1;
    A.col[2] = c1;
    l2 = func_00389598(0x17);
    q190[0] = 0.0f; q190[1] = 0.0f; q190[2] = 0.0f; q190[3] = 0.0f;
    q1A0[0] = 0.0f; q1A0[1] = 0.0f; q1A0[2] = 0.0f; q1A0[3] = 0.0f;
    B.f78 = l2;
    B.f80 = 0xFF9000000260L;
    B.f88 = 0x8000000048L;
    B.col[2] = c1;
    B.col[0] = 0x3F103080;
    B.f70 = 0;
    B.col[3] = c1;
    B.col[1] = 0x3F103080;
    q190[3] = 1.0f;
    q1A0[3] = 1.0f;
    r = func_003824E0(0.1f, 0.3f);
    q190[2] = r;
    q1A0[2] = r + r;
    func_L01_0032FBE0(&A);
    func_L01_0032FBE0(&B);
    if ((func_0013D3E0() & 1) == 0) {
        A.uv[0][0] = 0.0f; A.uv[0][1] = 0.0f;
        A.uv[1][0] = 0.0f; A.uv[1][1] = 1.0f;
        A.uv[2][0] = 1.0f; A.uv[2][1] = 0.0f;
        A.uv[3][0] = 1.0f; A.uv[3][1] = 1.0f;
        B.uv[0][0] = 0.0f; B.uv[0][1] = 0.0f;
        B.uv[1][0] = 0.0f; B.uv[1][1] = 1.0f;
        B.uv[2][0] = 1.0f; B.uv[2][1] = 0.0f;
        B.uv[3][0] = 1.0f; B.uv[3][1] = 1.0f;
    } else {
        A.uv[0][0] = 0.0f; A.uv[0][1] = 1.0f;
        A.uv[1][0] = 0.0f; A.uv[1][1] = 0.0f;
        A.uv[2][0] = 1.0f; A.uv[2][1] = 1.0f;
        A.uv[3][0] = 1.0f; A.uv[3][1] = 0.0f;
        B.uv[0][0] = 0.0f; B.uv[0][1] = 1.0f;
        B.uv[1][0] = 0.0f; B.uv[1][1] = 0.0f;
        B.uv[2][0] = 1.0f; B.uv[2][1] = 1.0f;
        B.uv[3][0] = 1.0f; B.uv[3][1] = 0.0f;
    }

    /* M rows 0,1,2 = camera-facing basis from the spark position towards the player; row 3 = position */
    M[0] = p170[0] - p160[0];
    M[1] = p170[1] - p160[1];
    M[2] = p170[2] - p160[2];
    M[3] = p170[3];
    func_0038CF68(&M[0], &M[0], 1.0f);
    M[4] = ((f32 *)D_L01_001E29C0)[0] - p160[0];
    M[5] = ((f32 *)D_L01_001E29C0)[1] - p160[1];
    M[6] = ((f32 *)D_L01_001E29C0)[2] - p160[2];
    M[7] = ((f32 *)D_L01_001E29C0)[3];
    func_0038CE90(&M[8], &M[4], &M[0]);
    func_0038CF68(&M[8], &M[8], 1.0f);
    func_0038CE90(&M[4], &M[0], &M[8]);
    for (i = 0; i < 4; i++) {
        M[12 + i] = p160[i];
        A.v[0][i] = q190[i];
        B.v[0][i] = q1A0[i];
    }
    func_0038CE20(A.v[1], A.v[0], -1.0f);
    func_0038CE20(B.v[1], B.v[0], -1.0f);
    func_0038D028(A.v[0], A.v[0], M);
    func_0038D028(A.v[1], A.v[1], M);
    func_0038D028(B.v[0], B.v[0], M);
    func_0038D028(B.v[1], B.v[1], M);
    q190[2] = q190[2] * 0.15f;
    q1A0[2] = q190[2] + q190[2];
    for (i = 0; i < 4; i++) {
        M[12 + i] = p170[i];
        A.v[2][i] = q190[i];
        B.v[2][i] = q1A0[i];
    }
    func_0038CE20(A.v[3], A.v[2], -1.0f);
    func_0038CE20(B.v[3], B.v[2], -1.0f);
    func_0038D028(A.v[2], A.v[2], M);
    func_0038D028(A.v[3], A.v[3], M);
    func_0038D028(B.v[2], B.v[2], M);
    func_0038D028(B.v[3], B.v[3], M);
    func_003D2DA0(&A, 0, 0);
    func_003D2DA0(&B, 0, 0);
}

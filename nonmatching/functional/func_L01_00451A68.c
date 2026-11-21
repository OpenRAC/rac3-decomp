/* functional: medium. Draws count camera-facing quads (billboards); locals laid out as retail (quad packet at sp+0, basis matrix at sp+0xA0). Memory/calls identical in order; bytes differ (155 diff) from scheduling. D_L01_001D7C50 is the gp-relative corner table (gp-0x4C60). */
extern f32 D_L01_001E29C0[];
extern f32 D_L01_001D7C50[];
extern long func_00389598(s32);
extern void func_0038CF68(void *, void *, f32);
extern void func_0038CE90(void *, void *, void *);
extern void func_0038CE20(f32, void *, void *);
extern void func_0038D028(void *, void *, void *);
extern void func_003D2DA0(void *, s32, s32);

typedef struct {
    f32 corner[4][4];
    s32 col[4];
    f32 uv[8];
    long gs70;
    long gs78;
    long gs80;
    long gs88;
    f32 up[4];
    f32 mat[4][4];
    f32 off[4];
} __attribute__((aligned(16))) BillboardQuad;

void func_L01_00451A68(s32 count, f32 *pts, s32 *colors, f32 scale_a, f32 scale_b) {
    BillboardQuad q;
    s32 i, j;
    s32 cur;
    f32 *p;
    f32 *corner_src;

    q.up[0] = 0.0f;
    q.up[1] = 0.0f;
    q.up[2] = 1.0f;
    q.up[3] = 1.0f;
    q.gs78 = func_00389598(11);
    cur = colors[0];
    q.gs88 = 0x8000000048L;
    q.gs80 = 0xFF9000000260L;
    q.gs70 = 5;
    q.uv[0] = 0.0f;
    q.uv[1] = 0.0f;
    q.uv[2] = 0.0f;
    q.uv[3] = 1.0f;
    q.uv[4] = 1.0f;
    q.uv[5] = 0.0f;
    q.uv[6] = 1.0f;
    q.uv[7] = 1.0f;
    q.col[3] = cur;
    q.col[2] = cur;
    q.col[1] = cur;
    q.col[0] = cur;

    for (i = 0; i < count; i++) {
        p = pts + i * 4;
        q.mat[0][0] = D_L01_001E29C0[0] - p[0];
        q.mat[0][1] = D_L01_001E29C0[1] - p[1];
        q.mat[0][2] = D_L01_001E29C0[2] - p[2];
        q.mat[0][3] = D_L01_001E29C0[3];
        func_0038CF68(q.mat[0], q.mat[0], 1.0f);
        func_0038CE90(q.mat[1], q.mat[0], q.up);
        func_0038CF68(q.mat[1], q.mat[1], 1.0f);
        func_0038CE90(q.mat[2], q.mat[1], q.mat[0]);
        func_0038CE20(scale_b, q.off, q.mat[0]);
        q.mat[3][0] = p[0] + q.off[0];
        q.mat[3][1] = p[1] + q.off[1];
        q.mat[3][2] = p[2] + q.off[2];
        q.mat[3][3] = p[3];
        if (colors[i] != cur) {
            cur = colors[i];
            q.col[3] = cur;
            q.col[2] = cur;
            q.col[1] = cur;
            q.col[0] = cur;
        }
        corner_src = D_L01_001D7C50;
        for (j = 0; j < 4; j++) {
            func_0038CE20(scale_a, q.corner[j], corner_src);
            corner_src += 4;
            func_0038D028(q.corner[j], q.corner[j], q.mat[0]);
        }
        func_003D2DA0(&q, 0, 0);
    }
}

/* functional: high. Plain C (this file has no VU0 flag); retail vsub.xyz keeps w of v1, so out1->w = v1[3] in the degenerate case. 176 diff words: lqc2/sq vs scalar code and scheduling. */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_006202E0;
extern f32 D_L39_0024118C;
extern void func_0038CE20(void *, void *, f32);
extern f32 func_L01_0040E548(void *, void *);
void func_L39_006202E0(V4_006202E0 *out1, V4_006202E0 *out2, f32 *p0, f32 *v0, f32 *v1, s32 *t0, s32 *t1, s32 *t2) {
    f32 b = (f32)(*t2 - *t1) / (D_L39_0024118C * 1000.0f);
    f32 a = (f32)(*t1 - *t0) / (D_L39_0024118C * 1000.0f);
    f32 T, c3, c4, c5, c6, c8, c10;
    if (b == 0.0f || func_L01_0040E548(v0, v1) < 0.02f) {
        out1->x = out1->y = out1->z = out1->w = 0.0f;
        out2->x = out2->y = out2->z = out2->w = 0.0f;
        return;
    }
    if (a == 0.0f || func_L01_0040E548(p0, v0) < 0.02f) {
        out1->x = v1[0] - v0[0];
        out1->y = v1[1] - v0[1];
        out1->z = v1[2] - v0[2];
        out1->w = v1[3];
        func_0038CE20(out1, out1, 1.0f / b);
        out2->x = out2->y = out2->z = out2->w = 0.0f;
        return;
    }
    T = a + b;
    c3 = b / (a * T);
    c4 = 1.0f / a - 1.0f / b;
    c5 = a / (T * b);
    c6 = 2.0f / (a * T);
    c10 = 2.0f / (a * b);
    c8 = 2.0f / (T * b);
    out1->x = c3 * -p0[0] + c4 * v0[0] + c5 * v1[0];
    out1->y = c3 * -p0[1] + c4 * v0[1] + c5 * v1[1];
    out1->z = c3 * -p0[2] + c4 * v0[2] + c5 * v1[2];
    out2->x = c6 * p0[0] - c10 * v0[0] + c8 * v1[0];
    out2->y = c6 * p0[1] - c10 * v0[1] + c8 * v1[1];
    out2->z = c6 * p0[2] - c10 * v0[2] + c8 * v1[2];
}

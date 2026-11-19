/* Near miss (6 differing words of 96; open-rac-engine: agent_comet_glow_draw). Scheduling only, after the
 * texture lookup: retail has `sll alpha,24` before the `or` that makes the prim word, and both dir loads
 * (the atan2 arguments) before the 0xFF9000000260 constant; this C has the `or` first and the constant
 * between the loads. In sched2 the shift and the `or` are ready in the same cycle with equal priority and
 * the `or` wins on its dependents (6 against 4), so retail's order needs the `or` ready a cycle later.
 * Tried: nine orders of the col/prim/colour/reg80/f70 statements, col as two statements, the colours as a
 * chain or copied from each other (same bytes). The snippet declares func_L01_00397060: check.py's
 * context has no prototype for the file's earlier definitions (a K&R call would promote scale to double). */
typedef struct { f32 x, y, z; } V3_00397278;
typedef struct {
    f32 verts[4][4];
    u32 color[4];
    f32 uv[8];
    unsigned long f70;
    unsigned long tex;
    unsigned long reg80;
    unsigned long prim;
} Quad_00397278;
extern void func_L01_00397060(f32 *m, f32 s);
extern unsigned long func_00389598(int tex);
extern f32 func_0038D160(f32 a, f32 b);
extern f32 func_0038CED8(f32 *v);
extern void func_0038D328(f32 *mat, f32 *rot);
extern void func_0038CF68(f32 *dst, f32 *src, f32 s);
extern void func_003D2DA0(Quad_00397278 *quad, f32 *mat, int a);
/* agent_comet_glow_draw: one added quad of the comet's glow, facing along dir */
void func_L01_00397278(V3_00397278 *origin, u32 color, u32 alpha, int tex, unsigned long flags, f32 *dir, f32 scale, f32 roll)
{
    Quad_00397278 quad;
    f32 mat[16];
    f32 rot[4];
    V3_00397278 off;
    f32 pad_off;
    u32 col;

    func_L01_00396FD8((u8 *)&quad);
    quad.tex = func_00389598(tex);
    col = color + (alpha << 24);
    quad.prim = (flags << 2) | 0x8000000040;
    quad.color[3] = col;
    quad.color[2] = col;
    quad.color[1] = col;
    quad.color[0] = col;
    quad.reg80 = 0xFF9000000260;
    quad.f70 = 0;
    rot[3] = 0.0f;
    rot[2] = func_0038D160(dir[0], dir[1]);
    rot[1] = -func_0038D160(func_0038CED8(dir), dir[2]);
    rot[0] = roll;
    func_0038D328(mat, rot);
    func_0038CF68((f32 *)&off, dir, 0.025f);
    mat[12] = origin->x + off.x;
    mat[15] = 1.0f;
    mat[13] = origin->y + off.y;
    mat[14] = origin->z + off.z;
    func_L01_00397060((f32 *)&quad, scale);
    func_003D2DA0(&quad, mat, 0);
}

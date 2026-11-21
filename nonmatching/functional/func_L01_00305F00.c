/* functional: medium. Written from the disassembly with plain C for the vector math; the three quad packets are one local struct each, so the stack layout differs from retail, which does not matter. */
typedef struct {
    vu0_v4 m[4];
    s32 c[4];
    f32 uv[8];
    long x70, x78, x80, x88;
} Ribbon_00305F00;

typedef struct {
    vu0_v4 origin;
    u8 pad10[0x44 - 0x10];
    s32 count;
    s32 head;
    u8 pad4C[0x58 - 0x4C];
    f32 u;
    f32 v;
} Trail_00305F00;

extern u8 D_1425C0[];
extern u8 D_L01_002C5600[];
extern vu0_v4 D_L01_001E29C0;
extern vu0_v4 *D_001DC5C4_sda;
__asm__(".extern D_001DC5C4_sda, 4");
extern void func_0038CE90(void *, void *, void *);
extern void func_0038D028(void *, void *, void *);

/* trail_draw: draws a camera-facing ribbon of three layered quads along the ring buffer of
   the last positions in the object's trail (obj->0x68), tapering 6% a segment. mat is the
   segment's basis (direction, up, side, position): func_0038D028 transforms a vector by it. */
void func_L01_00305F00(u8 *obj, f32 scale)
{
    Trail_00305F00 *t = *(Trail_00305F00 **)(obj + 0x68);
    Ribbon_00305F00 s0, s1, s2;
    vu0_v4 v1F0, v200, cur, other;
    vu0_v4 mat[4];
    vu0_v4 *g;
    f32 w;
    f32 h;
    s32 idx;
    s32 prev;
    s32 i;
    s32 near;
    u32 c;

    if (t->count == 0) {
        return;
    }
    near = (D_L01_002C5600 + D_1425C0[0x11] * 0xF0)[1] < 4;
    s0.x78 = func_00389598(near ? 10 : 0x45);
    s0.c[0] = s0.c[1] = s0.c[2] = s0.c[3] = 0x609F9F9F;
    s0.x80 = 0xFF9000000260L;
    s0.x88 = 0x4000000064L;
    s0.x70 = 0;
    s1.x78 = func_00389598(0xE);
    s1.c[0] = s1.c[1] = s1.c[2] = s1.c[3] = 0x507F7F7F;
    s1.x80 = 0xFF9000000260L;
    s1.x88 = 0x4000000068L;
    s1.x70 = 0;
    s2.x78 = func_00389598(0x2B);
    s2.x70 = 0;
    s2.x80 = 0xFF9000000260L;
    s2.x88 = 0x5000000068L;
    c = near ? 0x55103080 : 0x55803010;
    s2.c[0] = s2.c[1] = s2.c[2] = s2.c[3] = c;
    w = scale * 0.5f;
    v1F0.x = 0.0f;
    v1F0.y = 0.0f;
    v1F0.w = 1.0f;
    h = func_003824E0(w, scale);
    v1F0.z = h;
    v200.x = 0.0f;
    v200.y = 0.0f;
    v200.w = 1.0f;
    v200.z = h * (near ? 6.0f : 3.0f);
    func_L01_00305C50((S_35A8A0 *)&s0);
    s0.uv[0] = t->u + 0.0f;
    s0.uv[1] = t->v + 0.0f;
    s0.uv[2] = t->u + 0.0f;
    s0.uv[3] = t->v + 1.0f;
    s0.uv[4] = t->u + 1.0f;
    s0.uv[5] = t->v + 0.0f;
    s0.uv[6] = t->u + 1.0f;
    s0.uv[7] = t->v + 1.0f;
    s1.uv[0] = t->u + 0.0f;
    s1.uv[1] = 0.0f;
    s1.uv[2] = t->u + 0.0f;
    s1.uv[3] = 1.0f;
    s1.uv[4] = t->u + 1.0f;
    s1.uv[5] = 0.0f;
    s1.uv[6] = t->u + 1.0f;
    s1.uv[7] = 1.0f;
    s2.uv[0] = t->u + 0.0f;
    s2.uv[1] = 0.0f;
    s2.uv[2] = t->u + 0.0f;
    s2.uv[3] = 1.0f;
    s2.uv[4] = t->u + 1.0f;
    s2.uv[5] = 0.0f;
    s2.uv[6] = t->u + 1.0f;
    s2.uv[7] = 1.0f;
    g = D_001DC5C4_sda;
    idx = t->head;
    cur = t->origin;
    other = g[idx * 4];
    vec_sub_ba(&mat[0], &other, &cur);
    func_0038CF68(&mat[0], &mat[0], 1.0f);
    vec_sub_ba(&mat[1], &D_L01_001E29C0, &cur);
    func_0038CE90(&mat[2], &mat[1], &mat[0]);
    func_0038CF68(&mat[2], &mat[2], 1.0f);
    func_0038CE90(&mat[1], &mat[0], &mat[2]);
    mat[3] = cur;
    s0.m[0] = v1F0;
    func_0038CE20((f32 *)&s0.m[1], (f32 *)&s0.m[0], -1.0f);
    func_0038D028(&s0.m[0], &s0.m[0], mat);
    func_0038D028(&s0.m[1], &s0.m[1], mat);
    s2.m[0] = v200;
    s1.m[0] = s0.m[0];
    s1.m[1] = s0.m[1];
    func_0038CE20((f32 *)&s2.m[1], (f32 *)&s2.m[0], -1.0f);
    func_0038D028(&s2.m[0], &s2.m[0], mat);
    func_0038D028(&s2.m[1], &s2.m[1], mat);
    for (i = 1; i < t->count; i++) {
        s0.m[2] = v1F0;
        scale *= 0.94f;
        func_0038CE20((f32 *)&s0.m[3], (f32 *)&s0.m[2], -1.0f);
        w *= 0.94f;
        s2.m[2] = v200;
        func_0038CE20((f32 *)&s2.m[3], (f32 *)&s2.m[2], -1.0f);
        g = D_001DC5C4_sda;
        cur = g[idx * 4];
        prev = idx - 1;
        idx = prev > -1 ? prev : 34;
        other = g[idx * 4];
        vec_sub_ba(&mat[0], &other, &cur);
        func_0038CF68(&mat[0], &mat[0], 1.0f);
        vec_sub_ba(&mat[1], &D_L01_001E29C0, &cur);
        func_0038CE90(&mat[2], &mat[1], &mat[0]);
        func_0038CF68(&mat[2], &mat[2], 1.0f);
        func_0038CE90(&mat[1], &mat[0], &mat[2]);
        mat[3] = cur;
        func_0038D028(&s0.m[2], &s0.m[2], mat);
        func_0038D028(&s0.m[3], &s0.m[3], mat);
        func_0038D028(&s2.m[2], &s2.m[2], mat);
        func_0038D028(&s2.m[3], &s2.m[3], mat);
        s1.m[2] = s0.m[2];
        s1.m[3] = s0.m[3];
        func_003D2DA0((S_35A8A0 *)&s0, 0, 0);
        func_003D2DA0((S_35A8A0 *)&s1, 0, 0);
        func_003D2DA0((S_35A8A0 *)&s2, 0, 0);
        s0.m[1] = s0.m[3];
        s1.m[0] = s1.m[2];
        s1.m[1] = s1.m[3];
        s2.m[0] = s2.m[2];
        s0.m[0] = s0.m[2];
        s2.m[1] = s2.m[3];
        s0.c[0] = s0.c[1] = s0.c[2];
        s1.c[0] = s1.c[1] = s1.c[2];
        s2.c[0] = s2.c[1] = s2.c[2];
        h = func_003824E0(w, scale);
        v1F0.z = h;
        v200.z = h * ((D_L01_002C5600 + D_1425C0[0x11] * 0xF0)[1] < 4 ? 6.0f : 3.0f);
    }
    func_0038D028(&s0.m[2], &s0.m[2], mat);
    func_0038D028(&s0.m[3], &s0.m[3], mat);
}

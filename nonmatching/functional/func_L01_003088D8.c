/* functional: high. Draft verified against PAL assembly line by line; changed so the four vectors (direction, side, normal, position) are one contiguous basis[4], because func_0038D028 reads the whole 4x4 (the draft passed one vector). 153 words differ in codegen only. S_0030CD20 here is defined again by the snippet: the file defines it later, so one of the two must go. */
typedef struct {
    f32 v[4][4];
    u8 pad40[0x10];
    f32 w[4][2];
    unsigned long d70;
    u8 pad78[8];
    unsigned long d80;
} Obj317488;
typedef struct {
    f32 v[4];
    s32 w16;
    f32 f20;
    s32 w24;
    s32 w28;
    f32 f32_;
    s32 w36;
    f32 f40;
    f32 f44;
} S_0030CD20;
extern void func_0038CF68(S_0030CD20 *, S_0030CD20 *, f32);
typedef struct {
    vu0_v4 v[4];
    s32 color[4];
    vu0_v4 uv[2];
    unsigned long d70, d78, d80, d88;
} Packet_003088D8;
extern vu0_v4 D_L01_001E29C0[];
void func_L01_003088D8(s32 unused, s32 resource, vu0_v4 *points, s32 count)
{
    extern void func_L01_00308808(vu0_v4 *, s32);
    extern void func_L01_00308D50(Obj317488 *);
    extern void func_0038CE90(void *, void *, void *);
    extern void func_0038D028(void *, void *, void *);
    Packet_003088D8 a, b;
    vu0_v4 basis[4];
    vu0_v4 offset, offset2;
    s32 i;
    f32 t, t2;
    a.d78 = func_00389598(43);
    a.d80 = 0xFF9000000260UL;
    a.d88 = ((unsigned long)resource << 32) | 0x68;
    a.color[0] = a.color[1] = 0x7F7F7F7F;
    a.d70 = 0;
    b.d78 = func_00389598(14);
    b.d80 = 0xFF9000000260UL;
    b.d88 = ((unsigned long)(resource / 3) << 32) | 0x68;
    *(vu0_q *)&offset = 0;
    *(vu0_q *)&offset2 = 0;
    offset.z = 0.0125f; offset2.z = 0.053125f;
    offset.w = offset2.w = 1.0f;
    a.color[1] = b.color[0] = 0x7FFF0000;
    b.d70 = 0;
    func_L01_00308808(points, count);
    func_L01_00308D50((Obj317488 *)&a);
    func_L01_00308D50((Obj317488 *)&b);
    vec_sub_ba(&basis[0], &points[1], &points[0]);
    a.uv[0].x = 0; a.uv[0].y = 0; a.uv[0].z = 0; a.uv[0].w = 1;
    a.uv[1].x = 1; a.uv[1].y = 0; a.uv[1].z = 1; a.uv[1].w = 1;
    b.uv[0].x = 0; b.uv[0].y = 0; b.uv[0].z = 0; b.uv[0].w = 1;
    b.uv[1].x = 0.33f; b.uv[1].y = 0; b.uv[1].z = 0.33f; b.uv[1].w = 1;
    func_0038CF68((S_0030CD20 *)&basis[0], (S_0030CD20 *)&basis[0], 1.0f);
    vec_sub_ab(&basis[1], D_L01_001E29C0, &points[0]);
    func_0038CE90(&basis[2], &basis[1], &basis[0]);
    func_0038CF68((S_0030CD20 *)&basis[2], (S_0030CD20 *)&basis[2], 1.0f);
    func_0038CE90(&basis[1], &basis[0], &basis[2]);
    basis[3] = points[0];
    a.v[0] = offset;
    func_0038CE20((f32 *)&a.v[1], (f32 *)&a.v[0], -1.0f);
    func_0038D028(&a.v[0], &a.v[0], &basis[0]);
    func_0038D028(&a.v[1], &a.v[1], &basis[0]);
    b.v[0] = offset2;
    func_0038CE20((f32 *)&b.v[1], (f32 *)&b.v[0], -1.0f);
    func_0038D028(&b.v[0], &b.v[0], &basis[0]);
    func_0038D028(&b.v[1], &b.v[1], &basis[0]);
    for (i=1; i<count-1; i++) {
        a.v[2] = offset;
        func_0038CE20((f32 *)&a.v[3], (f32 *)&a.v[2], -1.0f);
        b.v[2] = offset2;
        func_0038CE20((f32 *)&b.v[3], (f32 *)&b.v[2], -1.0f);
        vec_sub_ba(&basis[0], &points[i+1], &points[i]);
        func_0038CF68((S_0030CD20 *)&basis[0], (S_0030CD20 *)&basis[0], 1.0f);
        vec_sub_ba(&basis[1], D_L01_001E29C0, &points[i]);
        func_0038CE90(&basis[2], &basis[1], &basis[0]);
        func_0038CF68((S_0030CD20 *)&basis[2], (S_0030CD20 *)&basis[2], 1.0f);
        func_0038CE90(&basis[1], &basis[0], &basis[2]);
        basis[3] = points[i];
        func_0038D028(&a.v[2], &a.v[2], &basis[0]);
        func_0038D028(&a.v[3], &a.v[3], &basis[0]);
        func_0038D028(&b.v[2], &b.v[2], &basis[0]);
        func_0038D028(&b.v[3], &b.v[3], &basis[0]);
        a.color[3] = a.color[2] = 0x7F7F7F7F;
        { s32 color = 0x7FFF0000; b.color[3] = b.color[2] = color; }
        func_003D2DA0((S_35A8A0 *)&a, 0, 0);
        func_003D2DA0((S_35A8A0 *)&b, 0, 0);
        t = (f32)i * 0.33f;
        t2 = t + 0.33f;
        if (t >= 1.0f) { t -= 1.0f; t2 -= 1.0f; }
        a.v[0] = a.v[2]; a.v[1] = a.v[3];
        b.v[0] = b.v[2]; b.v[1] = b.v[3];
        b.uv[0].z = t; b.uv[1].z = t2;
        b.uv[0].x = t; b.uv[1].x = t2;
    }
}

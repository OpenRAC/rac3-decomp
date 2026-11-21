/* functional: medium. No draft; written from asm. Packet layout and constants as in the sibling func_00388638 (c=0xFF9000000260, d=0x8000000048, a=5, tex=func_00389598(0xB), 4 identical colours, UVs (0,0)(0,1)(1,0)(1,1)). Local 4x4 matrix: row0 = normalised (D_00222400 - pos), row1 = normalise(cross(row0, (0,0,1,1))), row2 = cross(row1,row0), row3 = pos + row0*s2 (xyz); each of the 4 corners = func_0038D028(corner, D_001D9180[i]*s1, matrix) (D_001D9180 = gp-0x3730, gp=0x1DC8B0). Prototypes of func_0038CF68 (normalise to length), func_0038CE90 (cross), func_0038CE20 (scale), func_0038D028 (transform by matrix) are inferred from register use, hence medium. 148 words differ (frame size and schedule). */
typedef struct { f32 pos[4][4]; s32 rgba[4]; f32 uv[4][2]; long a, tex, c, d; } P_003C5458;
extern f32 D_00222400[4];
extern f32 D_001D9180[16];
extern long func_00389598(s32);
extern void func_0038CF68(f32 *, f32 *, f32);
extern void func_0038CE90(f32 *, f32 *, f32 *);
extern void func_0038CE20(f32 *, f32 *, f32);
extern void func_0038D028(f32 *, f32 *, f32 *);
extern void func_003D2DA0(void *, s32, s32);
/* a: world position (xyzw); color: rgba word; s1: corner scale; s2: offset toward the camera */
void func_003C5458(f32 *a, s32 color, f32 s1, f32 s2) {
    P_003C5458 pk;
    f32 up[4];
    f32 m[4][4];   /* rows: direction to camera, right, up, position */
    f32 t[4];
    s32 i;
    up[0] = 0.0f;
    up[1] = 0.0f;
    up[2] = 1.0f;
    up[3] = 1.0f;
    pk.tex = func_00389598(0xB);
    pk.c = 0xFF9000000260L;
    pk.d = 0x8000000048L;
    pk.a = 5;
    pk.uv[0][0] = 0.0f; pk.uv[0][1] = 0.0f;
    pk.uv[1][0] = 0.0f; pk.uv[1][1] = 1.0f;
    pk.uv[2][0] = 1.0f; pk.uv[2][1] = 0.0f;
    pk.uv[3][0] = 1.0f; pk.uv[3][1] = 1.0f;
    for (i = 0; i < 4; i++) m[3][i] = a[i];
    m[0][0] = D_00222400[0] - m[3][0];
    m[0][1] = D_00222400[1] - m[3][1];
    m[0][2] = D_00222400[2] - m[3][2];
    m[0][3] = D_00222400[3];
    func_0038CF68(m[0], m[0], 1.0f);
    func_0038CE90(m[1], m[0], up);
    func_0038CF68(m[1], m[1], 1.0f);
    func_0038CE90(m[2], m[1], m[0]);
    func_0038CE20(t, m[0], s2);
    m[3][0] += t[0];
    m[3][1] += t[1];
    m[3][2] += t[2];
    pk.rgba[0] = color;
    pk.rgba[3] = color;
    pk.rgba[2] = color;
    pk.rgba[1] = color;
    for (i = 0; i < 4; i++) {
        func_0038CE20(pk.pos[i], &D_001D9180[i * 4], s1);
        func_0038D028(pk.pos[i], pk.pos[i], m[0]);
    }
    func_003D2DA0(&pk, 0, 0);
}

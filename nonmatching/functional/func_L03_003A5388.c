/* functional: high. Draws 6 quads (table D_L03_002BA370 entries 0-5) through func_003D2DA0 with a shared descriptor and matrix; 128-bit copies as vu0_v4 assigns; not byte-exact. */
typedef struct {
    vu0_v4 q[4];
    u32 col[4];
    f32 p[8];
    u64 w70;
    u64 w78;
    u64 w80;
    u64 w88;
} Quad_003A5388;
extern long func_00389598(s32);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern void func_003D2DA0(void *, void *, s32);

void func_L03_003A5388(void *arg0) {
    s32 *v = *(s32 **)((u8 *)arg0 + 0x68);
    u8 *rec;
    vu0_v4 m[4];
    Quad_003A5388 s;
    f32 h;
    f32 a;
    f32 b;
    f32 c;
    f32 d;
    u32 col;
    s32 i;

    rec = D_L03_001DFA80 + v[0] * 0x80;
    func_0038D570(m, rec);
    *(vu0_q *)&m[3] = *(vu0_q *)(rec + 0x30);
    m[3].w = 1.0f;
    h = ((f32 *)v)[1];
    col = ((s32)(h * 20.0f) << 24) | (((u8 *)v)[0x1E] << 16) | (((u8 *)v)[0x1D] << 8) | ((u8 *)v)[0x1C];
    h = h * h * 0.2f;
    c = func_0038D098(((f32 *)v)[4]) * 0.08f;
    d = func_0038D0B0(((f32 *)v)[4]) * 0.08f;
    s.w78 = func_00389598(30);
    s.w80 = 0xFF9000000260ULL;
    s.w70 = 4;
    s.w88 = 0x8000000048ULL;
    a = h + 0.5f;
    b = 0.5f - h;
    s.col[0] = col;
    s.col[3] = col;
    s.col[2] = col;
    s.col[1] = col;
    s.p[0] = b + c;
    s.p[1] = a + d;
    s.p[2] = a - d;
    s.p[3] = a + c;
    s.p[4] = b - c;
    s.p[5] = b - d;
    s.p[6] = a + d;
    s.p[7] = b - c;
    for (i = 0; i < 6; i++) {
        s.q[0] = D_L03_002BA370[i][0];
        s.q[1] = D_L03_002BA370[i][1];
        s.q[2] = D_L03_002BA370[i][2];
        s.q[3] = D_L03_002BA370[i][3];
        func_003D2DA0(&s, m, 0);
    }
}

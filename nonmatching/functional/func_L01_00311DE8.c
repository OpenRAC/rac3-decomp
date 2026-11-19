/* functional: high. Same table reads, matrix transforms, adds and draw calls in the same order as retail; vadd.xyz is plain C and the matrix rows share memory with the 'out' vector as in retail (m[3]). */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_311DE8;
typedef struct {
    V_311DE8 v[4];
    s32 col[4];
    f32 w[4][2];
    long d70;
    long d78;
    long d80;
    long d88;
} __attribute__((aligned(16))) P_311DE8;
typedef struct {
    u8 pad0[0x10];
    f32 f10;
    u8 pad14[0x24 - 0x14];
    s32 w24;
} Vars_311DE8;
typedef struct {
    s16 a, b;
} Idx_311DE8;
extern s32 D_L01_001DC6AC;
extern s32 D_L01_001DC6B0;
extern s32 D_L01_001DC6B4;
extern s32 D_L01_001DC6B8;
extern s32 D_L01_001DC6BC;
extern s32 D_L01_001DC6C0;
extern s32 D_L01_001DC6C4;
extern f32 D_L01_001DC6C8;
extern Idx_311DE8 D_L01_002A83F0[][4];
extern V_311DE8 D_L01_002A7EF0[];
extern f32 D_L01_002A87F0[][2];
extern long func_00389598(s32);
extern void func_003C5180(void *, void *, s32);
extern void func_0038CE20(f32 *, f32 *, f32);
extern void func_0038D000(void *, void *, void *);
extern void func_0038CF68(float *off, char *src, float scale);
extern void func_003D2DA0(char *pkt, float *matrix, int mode);

void func_L01_00311DE8(S_311A18 *o) {
    u8 *obj = (u8 *)o;
    P_311DE8 p;
    V_311DE8 m[4];
    Vars_311DE8 *vars;
    s32 j, k;
    Idx_311DE8 *e;
    V_311DE8 *objpos;
    f32 s;

    vars = *(Vars_311DE8 **)(obj + 0x68);
    objpos = (V_311DE8 *)(obj + 0x10);
    p.d78 = func_00389598(D_L01_001DC6C0);
    p.d88 = (long)D_L01_001DC6AC | ((long)D_L01_001DC6B0 << 2) | ((long)D_L01_001DC6B4 << 4) |
            ((long)D_L01_001DC6B8 << 6) | ((long)D_L01_001DC6BC << 32);
    *(long *)&m[0] = 0; *((long *)&m[0] + 1) = 0;
    p.d80 = 0xFF9000000260L;
    *(long *)&m[1] = 0; *((long *)&m[1] + 1) = 0;
    *(long *)&m[2] = 0; *((long *)&m[2] + 1) = 0;
    p.d70 = 0;
    m[0].x = vars->f10 * 2.0f;
    m[1].y = vars->f10 * 2.0f;
    m[2].z = vars->f10 * 0.25f;
    p.col[0] = D_L01_001DC6C4 + (vars->w24 << 24);
    p.col[3] = p.col[0];
    p.col[2] = p.col[0];
    p.col[1] = p.col[0];
    func_003C5180(objpos, &m[3], 1);
    for (j = 0; j < 0x40; j++) {
        e = D_L01_002A83F0[j];
        for (k = 0; k < 4; k++) {
            func_0038CE20((f32 *)&p.v[k], (f32 *)&D_L01_002A7EF0[e[k].a], D_L01_001DC6C8);
            p.w[k][0] = D_L01_002A87F0[e[k].b][0];
            p.w[k][1] = D_L01_002A87F0[e[k].b][1];
            func_0038D000(&p.v[k], &p.v[k], m);
            func_0038D000(&p.v[k], &p.v[k], obj + 0xC0);
            p.v[k].x = p.v[k].x + objpos->x;
            p.v[k].y = p.v[k].y + objpos->y;
            p.v[k].z = p.v[k].z + objpos->z;
            func_0038CF68((f32 *)&m[3], (char *)&m[3], 0.5f);
            p.v[k].x = p.v[k].x + m[3].x;
            p.v[k].y = p.v[k].y + m[3].y;
            p.v[k].z = p.v[k].z + m[3].z;
        }
        func_003D2DA0((char *)&p, 0, 0);
    }
}

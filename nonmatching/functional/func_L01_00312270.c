/* functional: medium. Same table reads, transforms, accumulations and back-face test as retail, same order; vadd/vsub.xyz are plain C. Retail's matrix row 3 (sp+0xC0) is stack garbage on the first of the 215 quads before it is computed; here it starts as zero. */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_312270;
typedef struct {
    V_312270 v[4];
    s32 col[4];
    f32 w[4][2];
    long d70;
    long d78;
    long d80;
    long d88;
} __attribute__((aligned(16))) P_312270;
typedef struct {
    s16 a, b;
} Idx_312270;
typedef struct {
    u8 pad0[0x10];
    f32 f10;
    u8 pad14[0x1C - 0x14];
    s32 w1C;
} Vars_312270;
extern s32 D_L01_001DC6CC;
extern s32 D_L01_001DC6D0;
extern s32 D_L01_001DC6D4;
extern s32 D_L01_001DC6D8;
extern s32 D_L01_001DC6DC;
extern s32 D_L01_001DC6E0;
extern s32 D_L01_001DC6E4;
extern f32 D_L01_001DC6E8;
extern f32 D_L01_001DC6A0;
extern f32 D_L01_001DC6A4;
extern Idx_312270 D_L01_002A9780[][4];
extern V_312270 D_L01_002A8AA0[];
extern f32 D_L01_002AA500[][2];
extern V_312270 D_L01_001E2A40;
extern long func_00389598(s32);
extern void func_0038CE20(f32 *, f32 *, f32);
extern void func_0038D000(void *, void *, void *);
extern f32 func_0038D098(f32);
extern void func_0038CF68(float *off, char *src, float scale);
extern void func_0038CE90(void *, void *, void *);
extern f32 func_0038CE68(void *, void *);
extern void func_003D2DA0(char *pkt, float *matrix, int mode);

void func_L01_00312270(S_311A18 *o) {
    u8 *obj = (u8 *)o;
    P_312270 p;
    V_312270 m[4];
    V_312270 acc, e0, e1;
    Vars_312270 *vars;
    s32 j, k;
    Idx_312270 *e;
    V_312270 *objpos;
    s32 color;

    vars = *(Vars_312270 **)(obj + 0x68);
    objpos = (V_312270 *)(obj + 0x10);
    p.d78 = func_00389598(D_L01_001DC6E0);
    p.d88 = (long)D_L01_001DC6CC | ((long)D_L01_001DC6D0 << 2) | ((long)D_L01_001DC6D4 << 4) |
            ((long)D_L01_001DC6D8 << 6) | ((long)D_L01_001DC6DC << 32);
    p.d80 = 0xFF9000000260L;
    p.d70 = 0;
    *(long *)&m[0] = 0; *((long *)&m[0] + 1) = 0;
    *(long *)&m[1] = 0; *((long *)&m[1] + 1) = 0;
    *(long *)&m[2] = 0; *((long *)&m[2] + 1) = 0;
    *(long *)&m[3] = 0; *((long *)&m[3] + 1) = 0;
    m[0].x = 1.0f;
    m[1].y = 1.0f;
    m[2].z = vars->f10 * 0.8650000095367432f;
    color = D_L01_001DC6E4 + (vars->w1C << 24);
    p.col[0] = color;
    p.col[3] = color;
    p.col[2] = color;
    p.col[1] = color;
    for (j = 0; j < 0xD7; j++) {
        e = D_L01_002A9780[j];
        for (k = 0; k < 4; k++) {
            func_0038CE20((f32 *)&p.v[k], (f32 *)&D_L01_002A8AA0[e[k].a], D_L01_001DC6E8);
            p.w[k][0] = D_L01_002AA500[e[k].b][0] + D_L01_001DC6A0;
            p.w[k][1] = D_L01_002AA500[e[k].b][1] + D_L01_001DC6A4;
            if (D_L01_002A8AA0[e[k].a].z == -0.0010519999777898192f) {
                p.col[k] = D_L01_001DC6E4;
            } else {
                p.col[k] = D_L01_001DC6E4 | (vars->w1C << 24);
            }
        }
        func_0038D000(&p.v[0], &p.v[0], m);
        func_0038D000(&p.v[1], &p.v[1], m);
        func_0038D000(&p.v[2], &p.v[2], m);
        func_0038D000(&p.v[3], &p.v[3], m);
        *(long *)&acc = 0; *((long *)&acc + 1) = 0;
        for (k = 0; k < 4; k++) {
            p.w[k][0] = p.w[k][0] - p.v[k].z * 0.125f;
            p.v[k].x = p.v[k].x * (func_0038D098(p.v[k].z) + 2.0f);
            p.v[k].y = p.v[k].y * (func_0038D098(p.v[k].z) + 2.0f);
            func_0038D000(&p.v[k], &p.v[k], obj + 0xC0);
            p.v[k].x = p.v[k].x + objpos->x;
            p.v[k].y = p.v[k].y + objpos->y;
            p.v[k].z = p.v[k].z + objpos->z;
            acc.x = acc.x + p.v[k].x;
            acc.y = acc.y + p.v[k].y;
            acc.z = acc.z + p.v[k].z;
        }
        func_0038CE20((f32 *)&acc, (f32 *)&acc, 0.25f);
        m[3].x = acc.x - D_L01_001E2A40.x;
        m[3].y = acc.y - D_L01_001E2A40.y;
        m[3].z = acc.z - D_L01_001E2A40.z;
        m[3].w = acc.w;
        func_0038CF68((f32 *)&m[3], (char *)&m[3], 1.0f);
        e0.x = p.v[2].x - p.v[0].x;
        e0.y = p.v[2].y - p.v[0].y;
        e0.z = p.v[2].z - p.v[0].z;
        e0.w = p.v[2].w;
        e1.x = p.v[2].x - p.v[1].x;
        e1.y = p.v[2].y - p.v[1].y;
        e1.z = p.v[2].z - p.v[1].z;
        e1.w = p.v[2].w;
        func_0038CE90(&acc, &e0, &e1);
        func_0038CF68((f32 *)&acc, (char *)&acc, 1.0f);
        if (0.0f < func_0038CE68(&m[3], &acc)) {
            func_003D2DA0((char *)&p, 0, 0);
        }
    }
}

/* functional: medium. Same table reads, transforms, accumulations, back-face test and particle-slot logic as retail, same order; vector add/sub are plain C. Matrix row 3 is stack garbage in retail until first computed (here zero); slot owner offset 0x7C. */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_3126C8;
typedef struct {
    V_3126C8 v[4];
    s32 col[4];
    f32 w[4][2];
    long d70;
    long d78;
    long d80;
    long d88;
} __attribute__((aligned(16))) P_3126C8;
typedef struct {
    s16 a, b;
} Idx_3126C8;
typedef struct {
    u8 pad0[0x10];
    f32 f10;
    u8 pad14[0x1C - 0x14];
    s32 w1C;
} Vars_3126C8;
typedef struct {
    u8 pad0[0x7C];
    void *owner;
} Slot_3126C8;
extern s32 D_L01_001DC6EC;
extern s32 D_L01_001DC6F0;
extern s32 D_L01_001DC6F4;
extern s32 D_L01_001DC6F8;
extern s32 D_L01_001DC6FC;
extern s32 D_L01_001DC700;
extern s32 D_L01_001DC704;
extern f32 D_L01_001DC708;
extern f32 D_L01_001DC6A4;
extern Idx_3126C8 D_L01_002AB460[][4];
extern V_3126C8 D_L01_002AAC00[];
extern f32 D_L01_002ABD60[][2];
extern V_3126C8 D_L01_001E2A40;
extern s32 D_L01_001E1730[];
extern Slot_3126C8 **D_L01_001E1738;
extern long func_00389598(s32);
extern void func_0038CE20(f32 *, f32 *, f32);
extern void func_0038D000(void *, void *, void *);
extern f32 func_0038CED8(void *);
extern f32 func_L01_004451A8(f32);
extern void func_0038CF68(float *off, char *src, float scale);
extern void func_0038CE90(void *, void *, void *);
extern f32 func_0038CE68(void *, void *);
extern void *func_L01_00312DD8(void *, s32, void *, f32);
extern void func_003D2DA0(char *pkt, float *matrix, int mode);

void func_L01_003126C8(S_311A18 *o) {
    u8 *obj = (u8 *)o;
    P_3126C8 p;
    V_3126C8 m[4];
    V_3126C8 acc, center, e0, e1;
    Vars_3126C8 *vars;
    s32 j, k;
    Idx_3126C8 *e;
    V_3126C8 *objpos;
    s32 color;
    f32 x;
    Slot_3126C8 *slot;

    vars = *(Vars_3126C8 **)(obj + 0x68);
    objpos = (V_3126C8 *)(obj + 0x10);
    p.d78 = func_00389598(D_L01_001DC700);
    p.d88 = (long)D_L01_001DC6EC | ((long)D_L01_001DC6F0 << 2) | ((long)D_L01_001DC6F4 << 4) |
            ((long)D_L01_001DC6F8 << 6) | ((long)D_L01_001DC6FC << 32);
    p.d80 = 0xFF9000000260L;
    p.d70 = 0;
    *(long *)&m[0] = 0; *((long *)&m[0] + 1) = 0;
    *(long *)&m[1] = 0; *((long *)&m[1] + 1) = 0;
    *(long *)&m[2] = 0; *((long *)&m[2] + 1) = 0;
    *(long *)&m[3] = 0; *((long *)&m[3] + 1) = 0;
    m[0].x = vars->f10 * 0.0625f + 1.0f;
    m[2].z = 1.0f;
    m[1].y = vars->f10 * 0.0625f + 1.0f;
    color = D_L01_001DC704 + (vars->w1C << 24);
    p.col[0] = color;
    p.col[3] = color;
    p.col[2] = color;
    p.col[1] = color;
    for (j = 0; j < 0x8F; j++) {
        e = D_L01_002AB460[j];
        for (k = 0; k < 4; k++) {
            func_0038CE20((f32 *)&p.v[k], (f32 *)&D_L01_002AAC00[e[k].a], D_L01_001DC708);
            p.w[k][1] = D_L01_002ABD60[e[k].b][1] - D_L01_001DC6A4;
            p.w[k][0] = D_L01_002ABD60[e[k].b][0];
        }
        *(long *)&acc = 0; *((long *)&acc + 1) = 0;
        for (k = 0; k < 4; k++) {
            func_0038D000(&p.v[k], &p.v[k], m);
            x = 1.5f - func_0038CED8(&p.v[k]) / 1.5f;
            if (0.0f < x) {
                x = x;
            } else {
                x = 0.0f;
            }
            x = func_L01_004451A8(x / 1.5f) * 1.5f;
            p.v[k].z = p.v[k].z + x * vars->f10 * 0.008249999955296516f;
            p.v[k].z = p.v[k].z + vars->f10 * 0.15000000596046448f;
            func_0038D000(&p.v[k], &p.v[k], obj + 0xC0);
            p.v[k].x = p.v[k].x + objpos->x;
            p.v[k].y = p.v[k].y + objpos->y;
            p.v[k].z = p.v[k].z + objpos->z;
            acc.x = acc.x + p.v[k].x;
            acc.y = acc.y + p.v[k].y;
            acc.z = acc.z + p.v[k].z;
        }
        func_0038CE20((f32 *)&acc, (f32 *)&acc, 0.25f);
        center = acc;
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
            slot = D_L01_001E1738[j];
            if (slot == 0 || slot->owner == 0) {
                if (obj[0x20] == 6) {
                    if (slot != 0) {
                        D_L01_001E1738[j] = 0;
                    }
                } else {
                    D_L01_001E1738[j] = func_L01_00312DD8((void *)D_L01_001E1730[0], 1, &center, 0.0f);
                }
            }
            slot = D_L01_001E1738[j];
            if (slot != 0) {
                *(V_3126C8 *)slot = center;
            }
            func_003D2DA0((char *)&p, 0, 0);
        }
    }
}

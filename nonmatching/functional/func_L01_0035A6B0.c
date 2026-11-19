/* functional: medium. same calls/order/args and gp side effects; frame layout and registers differ; vector helpers written in C (file lacks vu0.h/-mvu0 flag) */
typedef struct {
    f32 m[4][4];
    s32 c[4];
    f32 x50, x54, x58;
    f32 x5C, x60;
    f32 x64;
    f32 x68, x6C;
} Quad_35A6B0;

static void vsub_xyz(f32 *d, f32 *a, f32 *b) {
    f32 x = a[0] - b[0], y = a[1] - b[1], z = a[2] - b[2], w = a[3];
    d[0] = x; d[1] = y; d[2] = z; d[3] = w;
}
static void vadd_xyz(f32 *d, f32 *a, f32 *b) {
    f32 x = a[0] + b[0], y = a[1] + b[1], z = a[2] + b[2], w = a[3];
    d[0] = x; d[1] = y; d[2] = z; d[3] = w;
}
extern u8 D_001A4BE0[];
extern u8 D_001425C0[];
extern u8 D_L01_002C5600[];
extern u8 D_L01_001E29C0[];
extern s32 D_001DD698_sda;
extern s32 D_001DD69C_sda;
extern f32 D_001DD6A0_sda;
extern f32 D_001DD6A4_sda;
extern s32 D_001DD6A8_sda;
extern void func_003D93B0(void *, s32, s32, s32);
extern void func_0038CF68(void *, void *, f32);
extern void func_0038CE90(void *, void *, void *);
extern void func_003D2DA0(void *, void *, s32);

void func_L01_0035A6B0(u8 *a0, u8 *p0, u8 *p1) {
    f32 v[0x40] __attribute__((aligned(16)));
    f32 *P0 = &v[0], *P1 = &v[4];
    f32 *d = &v[0x34], *e = &v[0x2C], *e2 = &v[0x30];
    Quad_35A6B0 q;
    u8 *obj = *(u8 **)(a0 + 0x68);
    s32 kind, fp, i;
    f32 w;
    s32 state;
    kind = (D_L01_002C5600 + D_001425C0[0x7F] * 0xF0)[1];
    *(u128_t *)P0 = *(u128_t *)p0;
    *(u128_t *)P1 = *(u128_t *)p1;
    state = *(s32 *)(D_001A4BE0 + 0x25C4);
    if ((u32)(state - 19) < 2) {
        w = (kind < 4) ? 0.12f : 0.09f;
    } else {
        w = (kind < 4) ? 0.12f : 0.06f;
    }
    D_001DD6A4_sda = w;
    D_001DD6A0_sda = w;
    if (kind < 2) {
        D_001DD698_sda = 0x5F204080;
        D_001DD69C_sda = 0x5F202080;
    } else if ((u32)(kind - 2) < 2) {
        D_001DD69C_sda = 0x5F804020;
        D_001DD698_sda = 0x5F804020;
    } else if (!(kind < 4)) {
        D_001DD69C_sda = 0x7F000000;
        D_001DD698_sda = 0x7F000000;
    }
    fp = kind < 4;

    func_003D93B0(&q, D_001DD6A8_sda, fp, 0x80);
    q.c[0] = D_001DD698_sda; q.c[1] = D_001DD698_sda; q.c[2] = D_001DD698_sda; q.c[3] = D_001DD698_sda;
    q.x50 = 0.0f; q.x54 = 0.0f; q.x58 = 0.0f;
    q.x5C = 1.0f; q.x60 = 1.0f; q.x64 = 0.0f; q.x68 = 1.0f; q.x6C = 1.0f;
    for (i = 0; i < 4; i++) {
        f32 *u = (f32 *)((u8 *)&q.x50 + i * 8);
        f32 t = *u - *(f32 *)(obj + 0x10);
        *u = t;
        if (t <= 7.0f) *u = t + 7.0f;
    }
    vsub_xyz(d, P0, P1);
    func_0038CF68(d, d, 1.0f);
    vsub_xyz(e, P0, (f32 *)D_L01_001E29C0);
    vsub_xyz(e2, P1, (f32 *)D_L01_001E29C0);
    func_0038CE90(e, e, d);
    func_0038CF68(e, e, D_001DD6A0_sda);
    func_0038CE90(e2, e2, d);
    func_0038CF68(e2, e2, D_001DD6A4_sda);
    vsub_xyz(q.m[0], P0, e);
    vadd_xyz(q.m[1], P0, e);
    vsub_xyz(q.m[2], P1, e2);
    vadd_xyz(q.m[3], P1, e2);
    func_003D2DA0(&q, 0, 0);

    func_003D93B0(&q, 0xE, fp, 0x80);
    q.c[0] = D_001DD69C_sda; q.c[1] = D_001DD69C_sda; q.c[2] = D_001DD69C_sda; q.c[3] = D_001DD69C_sda;
    q.x50 = 0.0f; q.x54 = 0.0f; q.x58 = 0.0f;
    q.x5C = 1.0f; q.x60 = 1.0f; q.x64 = 0.0f; q.x68 = 1.0f; q.x6C = 1.0f;
    for (i = 0; i < 4; i++) {
        f32 *u = (f32 *)((u8 *)&q.x50 + i * 8);
        f32 t = *u - *(f32 *)(obj + 0x10);
        *u = t;
        if (t <= 7.0f) *u = t + 7.0f;
    }
    vsub_xyz(d, P0, P1);
    func_0038CF68(d, d, 1.0f);
    vsub_xyz(e, P0, (f32 *)D_L01_001E29C0);
    vsub_xyz(e2, P1, (f32 *)D_L01_001E29C0);
    func_0038CE90(e, e, d);
    func_0038CF68(e, e, D_001DD6A0_sda * 0.5f);
    func_0038CE90(e2, e2, d);
    func_0038CF68(e2, e2, D_001DD6A4_sda * 0.5f);
    vsub_xyz(q.m[0], P0, e);
    vadd_xyz(q.m[1], P0, e);
    vsub_xyz(q.m[2], P1, e2);
    vadd_xyz(q.m[3], P1, e2);
    func_003D2DA0(&q, 0, 0);
}

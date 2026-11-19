/* functional: high. Retail does the xyz adds/subs with VU0 vadd/vsub (here plain float xyz ops, w kept); the $gp-relative colour and blend globals are named by address (D_L07_001DE668..88). Compiles at level 07 (371 diff words from scheduling). Triangle-strip quads submitted in the same order and with the same stale vertex slots as retail. */
typedef struct {
    vu0_v4 v[4];
    s32 c[4];
    f32 uv[8];
} S_003CB1F8;

extern s32 D_001D52F0;
extern u8 D_L07_001E1EC0[];
extern s32 D_L07_001DE668;
extern s32 D_L07_001DE66C;
extern s32 D_L07_001DE670;
extern s32 D_L07_001DE674;
extern f32 D_L07_001DE678;
extern s32 D_L07_001DE67C;
extern s32 D_L07_001DE680;
extern s32 D_L07_001DE684;
extern s32 D_L07_001DE688;

extern void func_0038CF68(void *, void *, f32);
extern void func_0038CE20(void *, void *, f32);
extern void func_0038CE90(void *, void *, void *);
extern void func_003D93B0(void *, s32, s32, s32);
extern void func_003D2DA0(void *, s32, s32);

static __inline__ void add3_003CB1F8(vu0_v4 *d, vu0_v4 *a, vu0_v4 *b) {
    vu0_v4 r = *a;
    r.x = a->x + b->x;
    r.y = a->y + b->y;
    r.z = a->z + b->z;
    *d = r;
}

static __inline__ void sub3_003CB1F8(vu0_v4 *d, vu0_v4 *a, vu0_v4 *b) {
    vu0_v4 r = *a;
    r.x = a->x - b->x;
    r.y = a->y - b->y;
    r.z = a->z - b->z;
    *d = r;
}

void func_L07_003CB1F8(u8 *a0) {
    S_003CB1F8 s;
    vu0_v4 v90, vA0, vB0, vC0, vD0, vE0, vF0, v100, v110, v120, v130, v140, v150, v160, v170, v180;
    u8 *st;
    f32 frac;
    f32 f;
    s32 i;
    s32 col, colA, colB;

    if (a0 == 0) {
        return;
    }
    st = *(u8 **)(a0 + 0x68);
    if (a0[0x20] == 0xFE) {
        return;
    }
    if (a0[0x20] == 0xFD) {
        return;
    }
    if (st == 0) {
        return;
    }

    v90 = *(vu0_v4 *)(a0 + 0x10);
    if (*(s32 *)(st + 0x30) != 0) {
        vA0 = *(vu0_v4 *)(st + 0x10);
        sub3_003CB1F8(&vB0, &vA0, &v90);
    } else {
        func_0038CF68(&vB0, st, *(f32 *)(st + 0x20));
        add3_003CB1F8(&vA0, &v90, &vB0);
    }

    frac = (f32)*(s32 *)(st + 0x24) * *(f32 *)(st + 0x28);
    func_003D93B0(&s, 0x17, 0, 0x80);
    colA = ((s32)(frac * 64.0f) << 24) | 0x108080;
    colB = ((s32)(frac * 64.0f) << 24) | 0x101080;
    s.uv[0] = 0.0f;
    s.uv[1] = 0.0f;
    s.uv[2] = 0.0f;
    s.uv[3] = 1.0f;
    s.uv[4] = 1.0f;
    s.uv[5] = 0.0f;
    s.uv[6] = 1.0f;
    s.uv[7] = 1.0f;
    s.c[0] = colA;
    s.c[1] = colA;
    s.c[2] = colB;
    s.c[3] = colB;
    for (i = 0; i < 4; i++) {
        f = s.uv[i * 2] - *(f32 *)(st + 0x2C);
        s.uv[i * 2] = f;
        if (f <= 7.0f) {
            s.uv[i * 2] = f + 7.0f;
        }
    }
    f = *(f32 *)(st + 0x2C) + 0.1f;
    *(f32 *)(st + 0x2C) = f;
    if (4.0f <= f) {
        *(f32 *)(st + 0x2C) = f - 4.0f;
    }

    sub3_003CB1F8(&v140, (vu0_v4 *)(a0 + 0x10), (vu0_v4 *)(D_L07_001E1EC0 + D_001D52F0 * 0x460));
    func_0038CE90(&v150, &v140, &vB0);
    func_0038CF68(&v150, &v150, 0.1f);
    func_0038CE20(&v160, &vB0, D_L07_001DE678);
    func_0038CE20(&v170, &vB0, 1.0f - D_L07_001DE678);
    func_0038CE20(&v180, &vB0, 0.5f);
    add3_003CB1F8(&v160, &v160, &v90);
    add3_003CB1F8(&v170, &v170, &v90);
    add3_003CB1F8(&v180, &v180, &v90);
    add3_003CB1F8(&vC0, &v90, &v150);
    sub3_003CB1F8(&vD0, &v90, &v150);
    add3_003CB1F8(&vE0, &v160, &v150);
    sub3_003CB1F8(&vF0, &v160, &v150);
    add3_003CB1F8(&v100, &v150, &v170);
    sub3_003CB1F8(&v110, &v170, &v150);
    add3_003CB1F8(&v120, &vA0, &v150);
    sub3_003CB1F8(&v130, &vA0, &v150);

    s.v[0] = vC0;
    s.v[1] = vD0;
    s.v[2] = vE0;
    s.v[3] = vF0;
    colB = (D_L07_001DE670 << 16) | (D_L07_001DE66C << 8) | D_L07_001DE668;
    colA = (D_L07_001DE674 << 24) | colB;
    s.c[0] = colB;
    s.c[1] = colB;
    s.c[2] = colA;
    s.c[3] = colA;
    func_003D2DA0(&s, 0, 0);
    s.v[0] = v100;
    s.v[1] = v110;
    s.c[0] = colA;
    s.c[1] = colA;
    func_003D2DA0(&s, 0, 0);
    s.v[2] = v120;
    s.v[3] = v130;
    s.c[2] = colB;
    s.c[3] = colB;
    func_003D2DA0(&s, 0, 0);

    func_003D93B0(&s, 0xE, 1, 0x80);
    func_0038CF68(&v150, &v150, 0.6f);
    s.uv[0] = 0.0f;
    s.uv[1] = 0.0f;
    s.uv[2] = 0.0f;
    s.uv[3] = 1.0f;
    s.uv[4] = 1.0f;
    s.uv[5] = 0.0f;
    s.uv[6] = 1.0f;
    s.uv[7] = 1.0f;
    col = ((s32)(frac * 64.0f) << 24) | 0x40FF;
    s.c[0] = col;
    s.c[1] = col;
    s.c[2] = col;
    s.c[3] = col;
    add3_003CB1F8(&vC0, &v90, &v150);
    sub3_003CB1F8(&vD0, &v90, &v150);
    add3_003CB1F8(&vE0, &v180, &v150);
    sub3_003CB1F8(&vF0, &v180, &v150);
    add3_003CB1F8(&v100, &vA0, &v150);
    sub3_003CB1F8(&v110, &vA0, &v150);
    colB = (D_L07_001DE684 << 16) | (D_L07_001DE680 << 8) | D_L07_001DE67C;
    colA = (D_L07_001DE688 << 24) | colB;
    s.v[0] = vC0;
    s.v[1] = vD0;
    s.v[2] = vE0;
    s.v[3] = vF0;
    s.c[0] = colB;
    s.c[1] = colB;
    s.c[2] = colA;
    s.c[3] = colA;
    func_003D2DA0(&s, 0, 0);
    s.v[0] = v100;
    s.v[1] = v110;
    func_003D2DA0(&s, 0, 0);
}

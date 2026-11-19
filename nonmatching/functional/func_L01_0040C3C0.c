/* functional: high. Instruction stream follows retail (88 differing words, all stack-slot offsets/regalloc: frame 0x1B0 vs 0x1A0). Pointer-walking loop kept as retail. File flags already include -mvu0-use-vf0-vf2. */
typedef struct {
    vu0_v4 r[4];
} Mat_0040C3C0;
extern f32 D_L01_001E93D0[];
extern f32 D_L01_001EA240[];
extern s32 D_L01_001E9A00[];
extern s32 D_L01_001E9C10[];
extern f32 D_L01_001E9E20[];
extern u8 D_L01_001E93DC[];
extern u8 D_L01_001E9A04[];
extern u8 D_L01_001E9E28[];
extern u8 D_L01_001E9C14[];
extern u8 D_L01_001EA248[];
extern f32 D_L01_002C5200[];
extern f32 D_L01_002C5308[];
extern void func_0038D308(void *, void *);
extern void func_0038D5F0(void *, void *, void *);
extern void func_00389478(void *, f32 *, f32 *);
extern void func_0038CC88(void *, void *, s32);
extern void func_0038D028(void *, void *, void *);
extern f32 func_003C4088(f32, f32, f32);
extern void func_0038C750(void);
extern long func_00389598(s32);
extern void func_003A9440(s32, unsigned long);
extern void func_003D3A24(s32, void *, void *, void *, s32);
void func_L01_0040C3C0(Mat_0040C3C0 *mat, s32 n, s32 id0, s32 id1, s32 col, s32 tex0, s32 tex1, f32 smooth, f32 rot) {
    Mat_0040C3C0 m;
    vu0_v4 ang;
    Mat_0040C3C0 rm;
    Mat_0040C3C0 prod;
    f32 dir[2];
    f32 mid[4];
    vu0_v4 local;
    vu0_v4 world;
    vu0_v4 endp;
    s32 step, j, n2;
    f32 *tabA, *tabB;
    f32 *p93;
    s32 *p9C;
    s32 *p9A;
    f32 *pA2;
    f32 *p9E;
    m = *mat;
    if (n & 1) {
        n &= ~1;
    }
    if (n > 0x40) {
        n = 0x40;
    }
    step = 0x40 / n;
    if ((0x40 % step) != 0) {
        n -= 0x40 % step;
        step = 0x40 / n;
    }
    if (n < 4) {
        return;
    }
    qzero(&ang);
    ang.x = rot;
    func_0038D308(&rm, &ang);
    n2 = n * 2;
    func_0038D5F0(&prod, &m, &rm);
    prod.r[3] = m.r[3];
    vec_add_ab(&endp, &prod.r[3], &prod.r[0]);
    func_00389478(&endp, &dir[0], &dir[1]);
    local.w = 1.0f;
    local.x = 0.0f;
    p93 = D_L01_001E93D0;
    p9C = D_L01_001E9C10;
    p9A = D_L01_001E9A00;
    pA2 = D_L01_001EA240;
    p9E = D_L01_001E9E20;
    tabA = D_L01_002C5200;
    tabB = D_L01_002C5308;
    for (j = 0; j <= n; j++) {
        func_0038CC88(p93, &endp, 12);
        local.y = *tabB;
        local.z = *tabA;
        func_0038D028(&world, &local, &prod);
        func_0038CC88(p93 + 3, &world, 12);
        p9C[0] = id1;
        p9C[1] = id0;
        func_00389478(&world, pA2 + 2, pA2 + 3);
        if (j == 0) {
            pA2[0] = dir[0];
            pA2[1] = dir[1];
        } else {
            mid[0] = (pA2[-2] + pA2[2]) * 0.5f;
            mid[1] = (pA2[-1] + pA2[3]) * 0.5f;
            pA2[0] = func_003C4088(dir[0], mid[0], smooth);
            pA2[1] = func_003C4088(dir[1], mid[1], smooth);
        }
        p9A[0] = col;
        p9A[1] = col;
        p9E[1] = 1.0f;
        p9E[2] = (f32)(j & 1);
        p9E[0] = 0.5f;
        p9E[3] = 0.0f;
        p93 += 6;
        p9C += 2;
        p9A += 2;
        pA2 += 4;
        p9E += 4;
        tabA += step;
        tabB += step;
    }
    func_0038C750();
    func_003A9440(0x47, 0x513F1UL);
    func_003A9440(6, func_00389598(tex0));
    func_003A9440(8, 4);
    func_003A9440(0x42, 0x800000004AUL);
    func_003D3A24(n2 + 1, D_L01_001E93DC, D_L01_001E9A04, D_L01_001E9E28, 1);
    func_003A9440(6, func_00389598(tex1));
    func_003A9440(8, 5);
    func_003A9440(0x42, 0x8000000054UL);
    func_003D3A24(n2 + 1, D_L01_001E93DC, D_L01_001E9C14, D_L01_001EA248, 1);
    func_003A9440(0x47, 0x5360BUL);
}

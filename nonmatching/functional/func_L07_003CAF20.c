/* functional: high. Retail also copies the old position to a dead stack slot (never read) and does the xyz adds with VU0 vadd; here plain float adds, w kept as retail's vadd.xyz keeps it. Compiles at level 07; 176 words differ (stack size, scheduling). Callee names are the level-07 catalogue names; D_ names checked against the %hi/%lo operands. */
static void add3_003CAF20(void *d, void *a, void *b) {
    f32 *pd = (f32 *)d, *pa = (f32 *)a, *pb = (f32 *)b;
    pd[0] = pa[0] + pb[0];
    pd[1] = pa[1] + pb[1];
    pd[2] = pa[2] + pb[2];
}

typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_003CAF20;
extern V4_003CAF20 D_L07_001E8C20;
extern u8 *D_L07_001E8C18;
extern u8 D_L01_001D66B0[];
extern s32 func_L01_004561B8(void *);
extern s32 func_0038CAD0(void *);
extern void func_003C2880(void *);
extern f32 func_0038CEA8(void *);
extern void func_0038CF68(void *, void *, f32);
extern f32 func_0038CF00(void *, void *);
extern void func_L01_00446760(void *, void *, s32, void *, f32);
extern void func_L01_004CB320(void);
extern void func_L01_004CB358(void);
extern s32 func_003D3CB0(void *, void *, s32, void *, void *);
extern void func_L05_003CAE70(void *);
extern void func_L07_003CC1C0(void *);
extern void func_L01_00404A10(void *, void *);
extern void func_L07_003CB1F8(void *);

void func_L07_003CAF20(u8 *a0) {
    u8 *st = *(u8 **)(a0 + 0x68);
    V4_003CAF20 v10;
    u8 v20[0x30] __attribute__((aligned(16)));
    f32 d;
    s32 hit;
    s32 n;
    u8 *g;

    if (a0[0x20] == 0) {
        if (func_L01_004561B8(a0) == 0) {
            add3_003CAF20(a0 + 0x10, a0 + 0x10, st);
        }
        if (func_0038CAD0(st + 0x24)) {
            func_003C2880(a0);
            return;
        }
        if (*(s32 *)(st + 0x30) == 0) {
            if (*(f32 *)(st + 0x20) < func_0038CEA8(st)) {
                add3_003CAF20(&v10, a0 + 0x10, st);
            } else {
                func_0038CF68(&v10, st, *(f32 *)(st + 0x20));
                add3_003CAF20(&v10, &v10, a0 + 0x10);
            }
            func_L01_00446760(v20, a0, 0x10001, D_L01_001D66B0, *(f32 *)(st + 0x34));
            *(s32 *)(v20 + 0x28) = *(s32 *)(st + 0x44);
            func_L01_004CB320();
            hit = func_003D3CB0(a0 + 0x10, &v10, 0x10, *(void **)(a0 + 0xB8), v20);
            if (hit != 0) {
                g = D_L07_001E8C18;
                if (g != 0 && *(s16 *)(g + 0xAA) == 0x186D && g[0x20] != 2 && g[0x20] != 5) {
                    g[0x20] = 4;
                }
            }
            func_L01_004CB358();
            if (hit != 0) {
                *(s32 *)(st + 0x30) = 1;
                *(V4_003CAF20 *)(st + 0x10) = D_L07_001E8C20;
                d = func_0038CF00(a0 + 0x10, st + 0x10);
                d = d / func_0038CEA8(st);
                n = (s32)d;
                n = (n * 5 + 2) / 6;
                *(s32 *)(st + 0x24) = n;
                *(f32 *)(st + 0x28) = 1.0f / (f32)n;
                if (D_L07_001E8C18 == 0) {
                    func_L07_003CC1C0(a0);
                } else {
                    func_L05_003CAE70(st + 0x10);
                }
            }
        }
        func_L01_00404A10(func_L07_003CB1F8, a0);
    }
    if (*(f32 *)(a0 + 0x10) < 2.0f || *(f32 *)(a0 + 0x10) > 1021.0f ||
        *(f32 *)(a0 + 0x14) < 2.0f || *(f32 *)(a0 + 0x14) > 1021.0f ||
        *(f32 *)(a0 + 0x18) < 2.0f || *(f32 *)(a0 + 0x18) > 1021.0f) {
        func_003C2880(a0);
    }
}

/* functional: high. Written from the PAL asm: 4 textured quads from a corner table (D_001DCF38 index table at $gp+0x688) rotated by a matrix built from D_L01_001E2880+0x158 and drawn through func_003D2DA0, then a second growing/fading quad pair driven by the scroll float at $gp+0x6CC. Stack packet layout (pos@0, colour@0x40, uv@0x50, w70..w88@0x70) matches what the callee reads; local temporaries differ in layout from retail but are not shared. 494 words differ (regalloc/scheduling). */
/* localdecomp:start func_L01_003365C0 */
typedef struct {
    f32 x, y, z, w;
} __attribute__((aligned(16))) V4_003365C0;
typedef struct {
    V4_003365C0 pos[4];
    u32 color[4];
    f32 uv[8];
    unsigned long w70, w78, w80, w88;
} __attribute__((aligned(16))) Pkt_003365C0;
extern u8 D_L01_001E2880[];
extern V4_003365C0 D_L01_002AF4C0[];
extern f32 D_L01_002AF550[];
extern f32 D_L01_002AF554[];
extern u32 D_L01_002AF598[];
extern s32 D_L01_001DCF38[16] __attribute__((section(".sdata")));
extern f32 D_L01_001DCF78 __attribute__((section(".sdata")));
extern f32 D_L01_001DCF7C __attribute__((section(".sdata")));
void func_L01_003365C0(u8 *m)
{
    extern void func_0038D308(void *, void *);
    extern void func_0038D000(void *, void *, void *);
    extern void func_0038CE20(void *, void *, f32);
    extern unsigned long func_00389598(s32);
    extern void func_003D2DA0(void *, void *, s32);
    Pkt_003365C0 pkt;
    V4_003365C0 up, c[4], mat[3], sq[4];
    u8 *p = *(u8 **)(m + 0x68);
    f32 one = 1.0f;
    f32 sc, a, z1, z2, t;
    s32 i, j, quad, alpha;
    u32 color;
    s32 *tbl;
    up.x = 0.0f;
    up.y = 0.0f;
    up.z = *(f32 *)(D_L01_001E2880 + 0x158);
    func_0038D308(mat, &up);
    D_L01_001DCF78 += 0.01f;
    if (one < D_L01_001DCF78) D_L01_001DCF78 -= one;
    pkt.w70 = 0;
    pkt.w80 = 1;
    pkt.w88 = 0x4000000044UL;
    pkt.w78 = func_00389598(0x18);
    for (i = 0; i < 4; i++) {
        tbl = &D_L01_001DCF38[i * 4];
        for (j = 0; j < 4; j++) {
            func_0038D000(&c[j], &D_L01_002AF4C0[tbl[j]], mat);
        }
        for (j = 0; j < 4; j++) {
            func_0038CE20(&c[j], &c[j], 0.5f);
        }
        sc = *(f32 *)(p + 0x90);
        for (j = 0; j < 4; j++) {
            pkt.pos[j].x = *(f32 *)(m + 0x10) + c[j].x * sc;
            pkt.pos[j].y = *(f32 *)(m + 0x14) + c[j].y * sc;
            pkt.pos[j].z = ((*(f32 *)(m + 0x18) + c[j].z) - one) + 1.45f;
        }
        for (j = 0; j < 4; j++) {
            quad = tbl[j];
            pkt.color[j] = D_L01_002AF598[*(s32 *)(p + 0x94) == 2 ? quad + 9 : quad];
            pkt.uv[j * 2] = D_L01_002AF550[quad * 2];
            pkt.uv[j * 2 + 1] = D_L01_002AF554[quad * 2] + D_L01_001DCF78;
        }
        func_003D2DA0(&pkt, 0, 1);
    }
    pkt.w78 = func_00389598(0x1B);
    D_L01_001DCF7C += 0.01f;
    if (one < D_L01_001DCF7C) D_L01_001DCF7C = 0.0f;
    t = D_L01_001DCF7C;
    a = (t * 1.2f) * *(f32 *)(p + 0x90);
    z1 = t * 1.4f + 1.1f;
    z2 = z1 - 0.2f;
    sq[0].x = -a; sq[0].y = -a; sq[0].z = z1; sq[0].w = 0.0f;
    sq[1].x = a;  sq[1].y = -a; sq[1].z = z2; sq[1].w = 0.0f;
    sq[2].x = -a; sq[2].y = a;  sq[2].z = z1; sq[2].w = 0.0f;
    sq[3].x = a;  sq[3].y = a;  sq[3].z = z2; sq[3].w = 0.0f;
    up.x = 0.0f;
    up.y = 0.0f;
    up.z = *(f32 *)(D_L01_001E2880 + 0x158);
    func_0038D308(mat, &up);
    for (j = 0; j < 4; j++) {
        func_0038D000(&c[j], &sq[j], mat);
    }
    for (j = 0; j < 4; j++) {
        func_0038CE20(&c[j], &c[j], 0.5f);
    }
    alpha = (s32)((one - t) * 128.0f);
    color = ((u32)alpha << 24) | 0x808080;
    for (j = 0; j < 4; j++) {
        pkt.pos[j].x = *(f32 *)(m + 0x10) + c[j].x;
        pkt.pos[j].y = *(f32 *)(m + 0x14) + c[j].y;
        pkt.pos[j].z = ((*(f32 *)(m + 0x18) + c[j].z) - one) + 1.45f;
        pkt.color[j] = color;
    }
    pkt.uv[0] = 0.0f; pkt.uv[1] = 0.0f;
    pkt.uv[2] = one;  pkt.uv[3] = 0.0f;
    pkt.uv[4] = 0.0f; pkt.uv[5] = one;
    pkt.uv[6] = one;  pkt.uv[7] = one;
    func_003D2DA0(&pkt, 0, 1);
}
/* localdecomp:end func_L01_003365C0 */

/* functional: medium. Draws the multiplayer-menu player blip's effect (spinning 8-segment ring while ex+8 counts, then a two-segment sweep driven by ex+0xA, then a cone while ex+0x40 counts) as draw records through func_003D93B0 / func_003D2DA0, advances the sweep angles at ex+0x28/0x2C, and flashes the screen for the local player. Draw-record colours are alpha<<24 | rgb. The w lane of vadd/vsub.xyz results keeps the first operand's w, as retail. */
typedef int u128_t __attribute__((mode(TI)));
extern u8 D_00228580[];
extern s32 D_L39_00241118;
__asm__(".extern D_L39_0024AFB4, 4");
extern f32 D_L39_0024AFB4;
__asm__(".extern D_L39_0024AFB8, 4");
extern f32 D_L39_0024AFB8;
__asm__(".extern D_L39_0024AFBC, 4");
extern f32 D_L39_0024AFBC;
__asm__(".extern D_L39_0024AFC0, 4");
extern f32 D_L39_0024AFC0;
__asm__(".extern D_L39_0024AFC4, 4");
extern f32 D_L39_0024AFC4;
__asm__(".extern D_L39_0024AFC8, 4");
extern f32 D_L39_0024AFC8;
__asm__(".extern D_L39_0024AFCC, 4");
extern f32 D_L39_0024AFCC;
__asm__(".extern D_L39_0024AFD0, 4");
extern f32 D_L39_0024AFD0;
__asm__(".extern D_L39_0024AFD8, 4");
extern f32 D_L39_0024AFD8;

extern void func_L39_005BC330(void *, void *, s32);
extern void func_0038CF68(void *, void *, f32);
extern void func_0038CE20(void *, void *, f32);
extern void func_0038CE90(void *, void *, void *);
extern void func_003D93B0(void *, s32, s32, s32);
extern void func_003D2DA0(void *, s32, s32);
extern void func_003C4840(void *, void *, f32);
extern void func_0038D850(void *, void *, void *);
extern f32 func_0038DAB8(f32, f32);
extern void func_003A9440(s32, s32);
extern void func_0038AF30(s32, s32, s32, s32, s32);

/* d.xyz = a.xyz + b.xyz, d.w = a.w (vadd.xyz into a's register) */
static __inline__ void vadd_00548648(f32 *d, f32 *a, f32 *b) {
    f32 w = a[3];
    d[0] = a[0] + b[0];
    d[1] = a[1] + b[1];
    d[2] = a[2] + b[2];
    d[3] = w;
}

static __inline__ void vsub_00548648(f32 *d, f32 *a, f32 *b) {
    f32 w = a[3];
    d[0] = a[0] - b[0];
    d[1] = a[1] - b[1];
    d[2] = a[2] - b[2];
    d[3] = w;
}

/* The four corner points of a strip around centre c, half-extents u (along) and v (across). */
static __inline__ void strip_00548648(f32 *rec, f32 *c, f32 *u, f32 *v) {
    f32 t[4] __attribute__((aligned(16)));

    vadd_00548648(t, c, u);
    vadd_00548648(rec + 0, t, v);
    vsub_00548648(rec + 4, t, v);
    vsub_00548648(t, c, u);
    vadd_00548648(rec + 8, t, v);
    vsub_00548648(rec + 12, t, v);
}

void func_L39_00548648(u8 *a) {
    u8 *ex;
    u8 *g;
    f32 rec[28] __attribute__((aligned(16)));
    f32 v90[4] __attribute__((aligned(16)));
    f32 vA0[4] __attribute__((aligned(16)));
    f32 vB0[4] __attribute__((aligned(16)));
    f32 vC0[4] __attribute__((aligned(16)));
    f32 vD0[4] __attribute__((aligned(16)));
    f32 vE0[4] __attribute__((aligned(16)));
    f32 vF0[4] __attribute__((aligned(16)));
    f32 v100[4] __attribute__((aligned(16)));
    f32 v110[4] __attribute__((aligned(16)));
    f32 v120[4] __attribute__((aligned(16)));
    f32 v130[4] __attribute__((aligned(16)));
    f32 v150[4] __attribute__((aligned(16)));
    s32 i;
    s32 h;
    u32 col;
    f32 f20;
    f32 f22;

    if (a == 0) {
        return;
    }
    if (a[0x20] == 0xFE) {
        return;
    }
    if (a[0x20] == 0xFD) {
        return;
    }
    ex = *(u8 **)(a + 0x68);
    if (ex == 0) {
        return;
    }
    g = *(u8 **)(ex + 0x50);
    if (g == 0) {
        return;
    }
    *(u128_t *)v90 = *(u128_t *)(ex + 0x10);
    func_L39_005BC330(v90, vA0, 1);
    vsub_00548648(vB0, (f32 *)(g + 0x23A0), v90);
    func_0038CF68(vB0, vB0, 1.0f);

    h = *(s16 *)(ex + 8);
    if (h != 0) {
        f20 = (f32)h * *(f32 *)(ex + 0x20);
        func_003D93B0(rec, 0xB, 1, 0x80);
        f20 = f20 * 255.0f;
        col = ((s32)f20 << 24) | 0x2040FF;
        *(f32 *)&rec[22] = 0.5f;
        *(f32 *)&rec[27] = 1.0f;
        *(f32 *)&rec[20] = 0.5f;
        *(s32 *)&rec[21] = 0;
        *(f32 *)&rec[23] = 1.0f;
        *(f32 *)&rec[24] = 1.0f;
        *(s32 *)&rec[25] = 0;
        *(u32 *)&rec[16] = col;
        *(u32 *)&rec[19] = col;
        *(u32 *)&rec[18] = col;
        *(u32 *)&rec[17] = col;
        *(f32 *)&rec[26] = 1.0f;
        func_0038CE20(vC0, vA0, D_L39_0024AFB4);
        vadd_00548648(vD0, v90, vC0);
        func_003C4840(vE0, vB0, *(f32 *)(ex + 0xC));
        func_0038D850(vC0, vC0, vE0);
        for (i = 0; i < 8; i++) {
            func_0038CE90(vF0, vB0, vC0);
            func_0038CF68(vF0, vF0, D_L39_0024AFB8);
            vadd_00548648(&rec[0], v90, vF0);
            vsub_00548648(&rec[4], v90, vF0);
            func_0038CE20(vF0, vF0, D_L39_0024AFBC / D_L39_0024AFB8);
            vadd_00548648(v100, v90, vC0);
            vadd_00548648(&rec[8], v100, vF0);
            vsub_00548648(&rec[12], v100, vF0);
            func_003D2DA0(rec, 0, 0);
            if (i < 7) {
                func_003C4840(vE0, vB0, 0.785398185f);
                func_0038D850(vC0, vC0, vE0);
            }
        }
    }

    f20 = 0.0174532924f;
    f22 = (f32)*(s16 *)(ex + 0xA) * *(f32 *)(ex + 0x24);
    *(f32 *)(ex + 0x28) = func_0038DAB8(*(f32 *)(ex + 0x28), D_L39_0024AFC8 * f20);
    *(f32 *)(ex + 0x2C) = func_0038DAB8(*(f32 *)(ex + 0x2C), D_L39_0024AFCC * f20);
    func_003D93B0(rec, 0x38, 1, 0x80);
    col = ((s32)(f22 * 20.0f) << 24) | 0x8080FF;
    *(s32 *)&rec[20] = 0;
    *(s32 *)&rec[21] = 0;
    *(s32 *)&rec[22] = 0;
    *(f32 *)&rec[23] = 1.0f;
    *(f32 *)&rec[24] = 1.0f;
    *(s32 *)&rec[25] = 0;
    *(u32 *)&rec[16] = col;
    *(u32 *)&rec[19] = col;
    *(u32 *)&rec[18] = col;
    *(u32 *)&rec[17] = col;
    *(f32 *)&rec[26] = 1.0f;
    *(f32 *)&rec[27] = 1.0f;
    func_0038CE20(vC0, ex + 0x30, f22 * -16.0f + 16.0f);
    vadd_00548648(vD0, v90, vC0);
    vsub_00548648(vE0, (f32 *)(g + 0x23A0), vD0);
    func_0038CF68(vE0, vE0, 1.0f);
    func_003C4840(vF0, vE0, *(f32 *)(ex + 0x28));
    func_0038CE90(v100, vE0, vA0);
    func_0038CE90(v110, v100, vE0);
    func_0038D850(v120, v110, vF0);
    f20 = D_L39_0024AFC4 + (D_L39_0024AFC0 - D_L39_0024AFC4) * f22;
    func_0038CF68(v120, v120, f20);
    func_0038CE90(v130, vE0, v120);
    func_0038CF68(v130, v130, f20);
    strip_00548648(&rec[0], vD0, v120, v130);
    func_003D2DA0(rec, 0, 0);

    func_003C4840(vF0, vE0, *(f32 *)(ex + 0x2C));
    func_0038D850(v120, v110, vF0);
    func_0038CE20(v120, v120, f20);
    func_0038CE90(v130, vE0, v120);
    func_0038CF68(v130, v130, f20);
    strip_00548648(&rec[0], vD0, v120, v130);
    func_003D2DA0(rec, 0, 0);

    if (*(s32 *)(ex + 0x40) == 0) {
        return;
    }
    f22 = (f32)*(s32 *)(ex + 0x40) * *(f32 *)(ex + 0x44);
    func_003D93B0(rec, 0xB, 4, 0x80);
    col = ((s32)(f22 * 255.0f) << 24) | 0x808080;
    *(u32 *)&rec[16] = col;
    *(u32 *)&rec[19] = col;
    *(u32 *)&rec[18] = col;
    *(u32 *)&rec[17] = col;
    func_0038CE20(v150, vB0, -0.100000001f);
    vadd_00548648(vD0, (f32 *)(g + 0x23A0), v150);
    func_0038CE90(v130, vB0, vA0);
    func_0038CF68(v130, v130, D_L39_0024AFD0);
    func_0038CE90(v120, v130, vB0);
    func_0038CF68(v120, v120, D_L39_0024AFD0);
    strip_00548648(&rec[0], vD0, v120, v130);
    func_003D2DA0(rec, 0, 0);
    col = ((s32)(D_L39_0024AFD8 * f22) << 24) | 0x808080;
    *(u32 *)&rec[16] = col;
    *(u32 *)&rec[19] = col;
    *(u32 *)&rec[18] = col;
    *(u32 *)&rec[17] = col;
    if (g[0x1A14] != 0) {
        if (g[0x24C9] == D_L39_00241118) {
            func_003A9440(0x42, 0x48);
            func_0038AF30(0, *(s16 *)(D_00228580 + 0x152), 0, *(s16 *)(D_00228580 + 0x150), (s32)*(u32 *)&rec[16]);
        }
    }
}

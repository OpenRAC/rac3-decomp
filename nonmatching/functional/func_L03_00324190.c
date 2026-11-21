/* functional: high. Written from the PAL assembly (no draft). Draws a 32-segment translucent ring around the object: for each segment it builds four GS-style vertices (cos/sin of the angle times the radius at +0x34, z = D_001DCAB0 -/+ a fade-in offset) and sends them with func_003D2DA0 together with a packed ALPHA/colour state block. The state block layout (sp+0x70..0x90) is kept as the same four 64-bit words and the same ALPHA packing. */
/* localdecomp:start func_L03_00324190 */
extern u8 D_001A71C5;
extern s32 D_001DCA78;
extern s32 D_001DCA7C;
extern s32 D_001DCA80;
extern s32 D_001DCA84;
extern s32 D_001DCA88;
extern s32 D_001DCA8C;
extern f32 D_001DCA90[];
extern f32 D_001DCAB0;
extern void func_0038D570(void *, void *);
extern long func_00389598(s32);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern void func_003D2DA0(void *, void *, s32);
typedef struct {
    f32 vtx[16];   /* 0x00: four vertices */
    s32 col[4];    /* 0x40: colour words */
    f32 uv[8];     /* 0x50: four (s, t) pairs */
    long state[4]; /* 0x70: [1] func_00389598 result, [2] constant, [3] packed ALPHA */
    u8 mtx[0x30];  /* 0x90: object matrix from func_0038D570 */
    long pos[2];   /* 0xC0: copy of the object quad at +0x10 (read by the drawer next to the matrix) */
} Ring_00324190;
void func_L03_00324190(u8 *o) {
    u8 *st = *(u8 **)(o + 0x68);
    Ring_00324190 g;
    f32 f21, t, r;
    s32 i, j, k;
    func_0038D570(g.mtx, o + 0xC0);
    g.pos[0] = *(long *)(o + 0x10);
    g.pos[1] = *(long *)(o + 0x18);
    g.state[0] = 0;
    g.state[1] = func_00389598(D_001DCA88);
    g.state[2] = ((long)0xFF90 << 32) | 0x260;
    g.state[3] = (long)D_001DCA78 | ((long)D_001DCA7C << 2) | ((long)D_001DCA80 << 4) | ((long)D_001DCA84 << 6) | ((long)0x8000 << 24);
    for (k = 0; k < 4; k++) {
        g.col[k] = D_001DCA8C;
        g.uv[k * 2] = D_001DCA90[k * 2];
        g.uv[k * 2 + 1] = D_001DCA90[k * 2 + 1];
    }
    f21 = 0.1f;
    t = *(f32 *)(st + 0x34);
    if (t < 1.15f) {
        r = (1.15f - t) + (1.15f - t);
        if (1.0f < r) r = 1.0f;
        else if (r < 0.0f) r = 0.0f;
        f21 = r + 0.1f;
        D_001A71C5 = (t < 0.65f) ? 1 : 0;
    }
    for (i = 0; i < 32; i++) {
        for (j = 0; j < 4; j++) {
            f32 ang = (f32)(i + ((j + ((u32)j >> 31)) >> 1)) * 6.283920764923096f * 0.03125f - 3.1415901184082031f;
            g.vtx[j * 4 + 0] = func_0038D098(ang) * *(f32 *)(st + 0x34);
            g.vtx[j * 4 + 1] = func_0038D0B0(ang) * *(f32 *)(st + 0x34);
            g.vtx[j * 4 + 2] = ((j & 1) ? D_001DCAB0 + f21 : D_001DCAB0 - f21) + 0.0f;
            g.vtx[j * 4 + 3] = 1.0f;
        }
        func_003D2DA0(&g, g.mtx, 0);
    }
}
/* localdecomp:end func_L03_00324190 */

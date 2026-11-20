/* functional: medium. Draw callback of the Thran pickup (registered by func_L19_003553A0): scrolls two global phases, then draws 4 textured quads (a rotated cube shell, texture 0x18) around the object from a vertex/uv/colour table, scaled by the fade-out strength pv+0x24, and one fading glow quad (texture 0x1B) built from 4 tilted corner vectors. Rotations use func_0038D308/D000 matrix helpers; texture/packet submit as in the other drawers (func_00389598, func_003D2DA0). Retail has per-vertex index tables in sdata (D_001DD6C8, colours D_001DD708) read through gp; sized as unsized arrays here. Float constants decoded from retail hex. */
typedef struct {
    f32 v[4][4];
    s32 col[4];
    f32 uv[4][2];
    long w70, tex, prim, mode;
} Pkt_003557B0;
extern f32 D_L19_001E2098;
extern f32 D_L19_002B57E0[][2];
extern f32 D_L19_002B5750[][4];
extern s32 D_L19_001DD6C8[];
__asm__(".extern D_L19_001DD6C8, 4");
__asm__(".extern D_L19_001DD708, 4");
__asm__(".extern D_L19_001DD72C, 4");
__asm__(".extern D_L19_001DD730, 4");
__asm__(".extern D_L19_001DD734, 4");
__asm__(".extern D_L19_001DD738, 4");
extern s32 D_L19_001DD708[];
extern f32 D_L19_001DD72C, D_L19_001DD730, D_L19_001DD734, D_L19_001DD738;
extern void func_0038D308(void *, void *);
extern void func_0038D000(void *, void *, void *);
extern void func_0038CE20(void *, void *, f32);
extern long func_00389598(s32);
extern void func_003D2DA0(void *, s32, s32);

void func_L19_003557B0(void *arg0) {
    u8 *obj = (u8 *)arg0;
    u8 *pv = *(u8 **)(obj + 0x68);
    f32 mtx[12];
    f32 V[4];
    f32 out[4][4];
    f32 R[4][4];
    Pkt_003557B0 pk;
    f32 g1, g2, g4, amp, ox, oy, oz;
    s32 i, k, a, cw;

    V[0] = 0.0f;
    V[1] = 0.0f;
    V[2] = D_L19_001E2098;
    func_0038D308(mtx, V);
    D_L19_001DD734 = D_L19_001DD734 + 0.01f;
    if (1.0f < D_L19_001DD734) {
        D_L19_001DD734 = D_L19_001DD734 - 1.0f;
    }
    D_L19_001DD738 = D_L19_001DD738 + 0.02f;
    if (1.0f < D_L19_001DD738) {
        D_L19_001DD738 = 0.0f;
    }
    pk.mode = 0x4000000044L;
    pk.prim = 1;
    pk.w70 = 0;
    pk.tex = func_00389598(0x18);
    for (i = 0; i < 4; i++) {
        s32 *idx = &D_L19_001DD6C8[i * 4];
        for (k = 0; k < 4; k++) {
            func_0038D000(out[k], D_L19_002B5750[idx[k]], mtx);
        }
        for (k = 0; k < 4; k++) {
            func_0038CE20(out[k], out[k], D_L19_001DD72C);
        }
        amp = *(f32 *)(pv + 0x24);
        ox = *(f32 *)(obj + 0x10);
        oy = *(f32 *)(obj + 0x14);
        oz = *(f32 *)(obj + 0x18);
        g4 = D_L19_001DD730;
        g1 = D_L19_001DD734;
        for (k = 0; k < 4; k++) {
            pk.v[k][0] = ox + out[k][0] * amp;
            pk.v[k][1] = oy + out[k][1] * amp;
            pk.v[k][2] = oz + out[k][2] - 1.0f + g4;
            pk.col[k] = D_L19_001DD708[idx[k]];
            pk.uv[k][0] = D_L19_002B57E0[idx[k]][0];
            pk.uv[k][1] = D_L19_002B57E0[idx[k]][1] + g1;
        }
        func_003D2DA0(&pk, 0, 1);
    }
    pk.tex = func_00389598(0x1B);
    g2 = D_L19_001DD738;
    R[0][0] = -g2 * 1.2f * *(f32 *)(pv + 0x24);
    R[0][1] = -g2 * 1.2f * *(f32 *)(pv + 0x24);
    R[0][2] = g2 * 1.4f + 1.1f;
    R[0][3] = 0.0f;
    R[1][0] = g2 * 1.2f * *(f32 *)(pv + 0x24);
    R[1][1] = -g2 * 1.2f * *(f32 *)(pv + 0x24);
    R[1][2] = g2 * 1.4f + 1.1f - 0.2f;
    R[1][3] = 0.0f;
    R[2][0] = -g2 * 1.2f * *(f32 *)(pv + 0x24);
    R[2][1] = g2 * 1.2f * *(f32 *)(pv + 0x24);
    R[2][2] = g2 * 1.4f + 1.1f;
    R[2][3] = 0.0f;
    R[3][0] = g2 * 1.2f * *(f32 *)(pv + 0x24);
    R[3][1] = g2 * 1.2f * *(f32 *)(pv + 0x24);
    R[3][2] = g2 * 1.4f + 1.1f - 0.2f;
    R[3][3] = 0.0f;
    for (k = 0; k < 4; k++) {
        func_0038D000(out[k], R[k], mtx);
    }
    for (k = 0; k < 4; k++) {
        func_0038CE20(out[k], out[k], D_L19_001DD72C);
    }
    a = (s32)((1.0f - D_L19_001DD738 * D_L19_001DD738) * 255.0f);
    cw = (a << 24) | 0x204080;
    ox = *(f32 *)(obj + 0x10);
    oy = *(f32 *)(obj + 0x14);
    oz = *(f32 *)(obj + 0x18);
    g4 = D_L19_001DD730;
    for (k = 0; k < 4; k++) {
        pk.v[k][0] = ox + out[k][0];
        pk.v[k][1] = oy + out[k][1];
        pk.v[k][2] = oz + out[k][2] - 1.0f + g4;
        pk.col[k] = cw;
    }
    pk.uv[0][0] = 0.0f;
    pk.uv[0][1] = 0.0f;
    pk.uv[1][0] = 1.0f;
    pk.uv[1][1] = 0.0f;
    pk.uv[2][0] = 0.0f;
    pk.uv[2][1] = 1.0f;
    pk.uv[3][0] = 1.0f;
    pk.uv[3][1] = 1.0f;
    func_003D2DA0(&pk, 0, 1);
}

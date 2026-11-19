/* functional: high. Swept probe for the menu player blip: normalises p1-p0 to length 1.5 into out (w = 5627.92), runs the collision sweep func_003D3CB0 between p0 and p1, and on a hit scales a push strength by distance class (ranges from func_L39_00546F30) before calling func_L01_00446978; returns the hit object or 0. vsub.xyz lanes keep p1's w, as retail. */
extern u8 *D_L39_0024CE20[8] __attribute__((section(".sdata")));
extern u8 D_L39_0049C890[];
extern s32 D_L39_0025F740[];
extern f32 D_L39_0025F760[4];

extern void func_0038CF68(void *, void *, f32);
extern void func_L39_005FFDF8(s32);
extern void func_L39_005FFE78(void);
extern s32 func_003D3CB0(void *, void *, s32, void *, s32);
extern void func_L39_0054D5F8(void *, void *, void *, s32, void *, void *);
extern s32 func_L39_00648AE0(void *, s32);
extern f32 func_0038CF00(void *, void *);
extern void func_L39_00546F30(s32, f32 *, f32 *);
extern void func_L01_00446978(void *, void *);

u8 *func_L39_00547E10(u8 *a, f32 *p0, f32 *p1, f32 *out, f32 fa) {
    u8 *g = *(u8 **)(*(u8 **)(a + 0x68) + 0x50);
    f32 v[4] __attribute__((aligned(16)));
    f32 r[2];
    u8 *cfg;
    u8 *ent;
    s32 hit;
    s32 id;
    f32 f20, f21, f22, f23, f12, s;

    if (g == 0) {
        return 0;
    }
    f20 = fa;
    out[0] = p1[0] - p0[0];
    out[1] = p1[1] - p0[1];
    out[2] = p1[2] - p0[2];
    out[3] = p1[3];
    func_0038CF68(out, out, 1.5f);
    out[3] = 5627.9248f;
    ent = D_L39_0024CE20[*(s32 *)(g + 0x2544)];
    id = -1;
    if (ent != 0) {
        id = *(s32 *)(ent + 0x2548);
    }
    func_L39_005FFDF8(id);
    hit = func_003D3CB0(p0, p1, 0x10, *(void **)(g + 0x2524), 0);
    func_L39_005FFE78();
    if (hit == 0) {
        v[0] = p1[0] - p0[0];
        v[1] = p1[1] - p0[1];
        v[2] = p1[2] - p0[2];
        v[3] = p1[3];
        func_L39_0054D5F8(p0, v, p1, 0, a, g);
        return 0;
    }
    v[0] = p1[0] - p0[0];
    v[1] = p1[1] - p0[1];
    v[2] = p1[2] - p0[2];
    v[3] = p1[3];
    func_0038CF68(v, v, 1.0f);
    v[0] = D_L39_0025F760[0] - p0[0];
    v[1] = D_L39_0025F760[1] - p0[1];
    v[2] = D_L39_0025F760[2] - p0[2];
    v[3] = D_L39_0025F760[3];
    func_L39_0054D5F8(p0, v, D_L39_0025F760, 1, a, g);
    if (D_L39_0025F740[6] != 0 && *(s32 *)(D_L39_0025F740[6] + 0x98) != 0) {
        if (func_L39_00648AE0(g, 2) != 0) {
            cfg = D_L39_0049C890 + ((s8)D_L39_0049C890[0x121] << 7);
        } else {
            cfg = D_L39_0049C890 + 0x100;
        }
        f21 = *(f32 *)(cfg + 0x30);
        f22 = func_0038CF00(D_L39_0025F760, p0);
        f12 = f20 - 0.0872664601f;
        if (f12 < 0.0f) {
            f12 = 0.0f;
        }
        f20 = 1.0f - (f12 / 0.239982769f) * 0.5f;
        func_L39_00546F30(D_L39_0025F740[6], &r[0], &r[1]);
        f23 = 33.0f;
        if (r[1] < 10.0f) {
            f23 = 11.5f;
        }
        if (f22 < r[0]) {
            s = (f21 + f21) * f20;
        } else if (f22 < r[1]) {
            s = f21 * f20;
        } else if (f22 < f23) {
            s = f21 * 0.600000024f;
        } else {
            s = f21 * 0.300000012f;
        }
        out[7] = s;
        func_L01_00446978((void *)D_L39_0025F740[6], out);
    }
    return (u8 *)D_L39_0025F740[6];
}

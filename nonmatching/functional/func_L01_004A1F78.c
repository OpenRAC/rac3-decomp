/* functional: high. 157 diff at default flags (hoisting/scheduling and the short-loop nops of the raw .word in retail); behaviour identical. Struct passed to func_003B9C68 is the same 0x54-byte layout as in func_L01_0049FDF0. */
typedef struct {
    s32 f0;
    s32 f4;
    s32 f8;
    s32 fC;
    s32 f10;
    s32 f14;
    f32 f18;
    f32 f1C;
    f32 f20;
    f32 a24[4];
    f32 a34[4];
    f32 a44[4];
} S_L01_004A1F78;
extern char D_L01_001D96B8[];
extern s32 func_L01_0047DAE0(void);
extern s32 func_003BB118(s32);
extern s32 *func_003B9BD0(s32);
extern s32 func_003B9C68();
extern void func_003BABB0(void *, f32, f32, f32, f32, f32, s32);
extern void func_003BABD0(void *, f32, f32, f32, f32);
extern void func_003BA4E0(void *, s32, f32, f32, f32);
extern void func_L01_00498948(void *, s32, s32);
extern s32 func_003B9E30(void *, s32, s32);
extern s32 func_00381FF0(s32);
extern void func_11B2E8();
void func_L01_004A1F78(void) {
    S_L01_004A1F78 s;
    s32 n = 0;
    s32 i;
    if (D_L01_002ED850[0].x0 > 0) {
        E_49E5B8 *p = D_L01_002ED850;
        do {
            p++;
            n++;
        } while (p->x0 > 0);
    }
    s.f0 = func_L01_0047DAE0();
    s.f4 = func_003BB118(0);
    s.f8 = 0x14;
    s.fC = n;
    s.f10 = (n < 6) ? n : 5;
    s.f14 = 1;
    s.f18 = 1.0f;
    s.f1C = 0.722954988f;
    s.f20 = 0.0953399986f;
    s.a24[0] = 0.5f;
    s.a24[1] = 1.0f;
    s.a24[2] = 1.0f;
    s.a24[3] = 1.0f;
    s.a34[0] = 0.79520601f;
    s.a34[1] = 0.0f;
    s.a34[2] = 0.0f;
    s.a34[3] = 0.0f;
    s.a44[0] = 0.0f;
    s.a44[1] = 0.0f;
    s.a44[2] = 0.0f;
    s.a44[3] = 0.0f;
    func_003B9C68(func_003B9BD0(0), &s);
    func_003BABB0(func_003B9BD0(0), 0.5f, 0.816536009f, 0.0450000018f, 0.0425000004f, 0.349999994f, 0);
    func_003BABD0(func_003B9BD0(0), 0.500369012f, 0.764262974f, 0.816536009f, 0.165585995f);
    func_003BA4E0(func_003B9BD0(0), 1, 0.0476699993f, 0.00665999996f, 0.0299999993f);
    for (i = 0; i < n; i++) {
        E_49E5B8 *e = &D_L01_002ED850[i];
        if (e->x14) {
            func_L01_00498948(func_003B9BD0(0), i, 0);
            func_11B2E8(func_003B9E30(func_003B9BD0(0), 0, i), D_L01_001D96B8, func_00381FF0(e->x0));
        } else {
            func_L01_00498948(func_003B9BD0(0), i, 1);
            func_11B2E8(func_003B9E30(func_003B9BD0(0), 0, i), D_L01_001D96B8, func_00381FF0(0x1C8));
        }
    }
}

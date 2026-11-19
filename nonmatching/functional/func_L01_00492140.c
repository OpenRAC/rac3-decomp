/* functional: high. Same scan, descriptor fill and UI calls as retail; byte diff from register allocation and float literal handling. Needs func_0011B2E8 declared varargs in the file context (called with 3 args). */
typedef struct {
    s32 w0;
    u8 b4;
    u8 pad5[11];
} E_00492140;
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
    f32 f24;
    f32 f28;
    f32 f2C;
    f32 f30;
    f32 f34;
    s32 f38;
    s32 f3C;
    s32 f40;
    s32 f44;
    s32 f48;
    s32 f4C;
    s32 f50;
} D_00492140;
extern E_00492140 D_L01_002EB2E8[];
extern s32 D_001D545C[] __attribute__((section(".sdata")));
extern s32 D_L01_001D8E08 __attribute__((section(".sdata")));
extern s32 D_L01_001D8E0C __attribute__((section(".sdata")));
extern s32 D_L01_001D8E10 __attribute__((section(".sdata")));
extern s32 D_L01_001D8E14 __attribute__((section(".sdata")));
extern f32 D_L01_001D8E3C __attribute__((section(".sdata")));
extern f32 D_L01_001D8E40 __attribute__((section(".sdata")));
extern char D_L01_001D8E48[];
extern s32 func_L01_0047DAE0(void);
extern s32 func_003BB118(s32);
extern s32 func_003B9BD0(s32);
extern s32 func_003B9C68(s32, void *);
extern void func_003BABB0(s32, s32, f32, f32, f32, f32, f32);
extern void func_003BABD0(s32, f32, f32, f32, f32);
extern void func_003BA4E0(s32, s32, f32, f32, f32);
extern char *func_003B9E30(s32, s32, s32);
extern char *func_00381FF0(s32);
extern void func_0011B2E8(char *, char *, ...);
extern void func_L01_00498948(s32, s32, s32);

void func_L01_00492140(void) {
    D_00492140 d;
    E_00492140 *e;
    s32 i, k, n;
    s32 sA, sB, sC, sD;
    char *r, *s;

    D_L01_001D8E0C = -1;
    D_L01_001D8E10 = -1;
    D_L01_001D8E14 = -1;
    D_L01_001D8E08 = -1;
    n = 0;
    if (D_L01_002EB2E8[0].w0 > 0) {
        sA = -1; sB = -1; sC = -1; sD = -1;
        e = D_L01_002EB2E8;
        i = 0;
        do {
            if (e->w0 == 0x18D) sB = i;
            else if (e->w0 < 0x18E) {
                if (e->w0 == 0x148) sD = i;
            } else if (e->w0 == 0x18E) sC = i;
            else if (e->w0 == 0x507) sA = i;
            e++;
            i++;
        } while (e->w0 > 0);
        n = i;
        D_L01_001D8E0C = sD;
        D_L01_001D8E08 = sC;
        D_L01_001D8E14 = sB;
        D_L01_001D8E10 = sA;
    }
    if (D_001D545C[0] != 0x18) D_L01_002EB2E8[0].b4 = 1;
    else D_L01_002EB2E8[0].b4 = 0;
    d.f0 = func_L01_0047DAE0();
    d.f4 = func_003BB118(0);
    d.f10 = n < 7 ? n : 6;
    d.f8 = 0x14;
    d.f14 = 1;
    d.f1C = D_L01_001D8E3C;
    d.f20 = D_L01_001D8E40;
    d.f24 = 0.5f;
    d.f30 = 1.0f;
    d.f34 = 0.795206f;
    d.fC = n;
    d.f18 = 1.0f;
    d.f28 = 1.0f;
    d.f2C = 1.0f;
    d.f38 = 0;
    d.f3C = 0;
    d.f40 = 0;
    d.f44 = 0;
    d.f48 = 0;
    d.f4C = 0;
    d.f50 = 0;
    func_003B9C68(func_003B9BD0(0), &d);
    func_003BABB0(func_003B9BD0(0), 0, 0.500369f, 0.816536f, 0.045f, 0.0425f, 0.35f);
    func_003BABD0(func_003B9BD0(0), 0.500369f, 0.698703f, 0.816536f, 0.314706f);
    func_003BA4E0(func_003B9BD0(0), 1, 0.033f, 0.00666f, 0.03f);
    for (k = 0; k < n; k++) {
        r = func_003B9E30(func_003B9BD0(0), 0, k);
        s = func_00381FF0(D_L01_002EB2E8[k].w0);
        func_0011B2E8(r, D_L01_001D8E48, s);
        func_L01_00498948(func_003B9BD0(0), k, D_L01_002EB2E8[k].b4 == 0);
    }
}

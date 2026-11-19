/* functional: high. Same scan/descriptor/UI calls as retail; byte diff only from register allocation and float literals. Needs func_0011B2E8 declared varargs in the file context. */
typedef struct {
    s32 w0;
    u8 b4;
    u8 pad5[11];
} E_004931E0;
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
} D_004931E0;
extern E_004931E0 D_L01_002EB498[];
extern s32 D_001D545C[] __attribute__((section(".sdata")));
extern u8 D_001D557D;
extern u8 D_001D558C;
extern u8 D_001A4BE0[];
extern f32 D_L01_001D8E80 __attribute__((section(".sdata")));
extern f32 D_L01_001D8E84 __attribute__((section(".sdata")));
extern char D_L01_001D8E88[];
extern s32 func_L01_0047DAE0(void);
extern s32 func_003BB118(s32);
extern s32 func_003B9BD0(s32);
extern s32 func_003B9C68(s32, void *);
extern void func_L01_00499760(s32, s32, f32, f32, f32, f32, f32, f32);
extern void func_003BABD0(s32, f32, f32, f32, f32);
extern void func_003BA4E0(s32, s32, f32, f32, f32);
extern char *func_003B9E30(s32, s32, s32);
extern char *func_00381FF0(s32);
extern void func_0011B2E8(char *, char *, ...);
extern void func_L01_00498948(s32, s32, s32);
extern s32 func_L01_0041A4F0(void);

void func_L01_004931E0(void) {
    D_004931E0 d;
    E_004931E0 *e;
    s32 i, n;
    char *r, *s;

    n = 0;
    if (D_L01_002EB498[0].w0 > 0) {
        e = D_L01_002EB498;
        do {
            e++;
            n++;
        } while (e->w0 > 0);
    }
    d.f0 = func_L01_0047DAE0();
    d.f4 = func_003BB118(0);
    d.f10 = 4;
    d.f8 = 0x14;
    d.f14 = 1;
    d.f1C = D_L01_001D8E80;
    d.f20 = D_L01_001D8E84;
    d.f24 = 0.5f;
    d.f30 = 1.0f;
    d.f34 = 0.795206f;
    d.fC = 4;
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
    func_L01_00499760(func_003B9BD0(0), 0, 0.500369f, 0.816536f, 0.065f, 0.00825f, 0.0425f, 0.35f);
    func_003BABD0(func_003B9BD0(0), 0.500369f, 0.698703f, 0.816536f, 0.304706f);
    func_003BA4E0(func_003B9BD0(0), 1, 0.033f, 0.00666f, 0.03f);
    e = D_L01_002EB498;
    for (i = 0; i < n; i++, e++) {
        if (e->w0 == 0x526 && func_L01_0041A4F0() == 0) {
            r = func_003B9E30(func_003B9BD0(0), 0, i);
            s = func_00381FF0(0x16F);
            func_0011B2E8(r, D_L01_001D8E88, s);
            func_L01_00498948(func_003B9BD0(0), i, 1);
        } else {
            e->b4 = 1;
            r = func_003B9E30(func_003B9BD0(0), 0, i);
            s = func_00381FF0(e->w0);
            func_0011B2E8(r, D_L01_001D8E88, s);
            if (e->w0 == 0x526) {
                if ((D_001D545C[0] == 0x17 && D_001D557D == 0) || (D_001D545C[0] == 0x1B && D_001D558C == 0)) {
                    e->b4 = 0;
                    func_L01_00498948(func_003B9BD0(0), i, 1);
                }
            }
        }
        if (e->w0 == 0x139E) {
            if (D_001A4BE0[0x25E4] != 0) {
                e->b4 = 0;
                func_L01_00498948(func_003B9BD0(0), i, 1);
            }
        }
    }
}

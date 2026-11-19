/* functional: high. Same calls, order and conditions as retail (label id selection by the signed w%0x3C table lookup, 30-row loop, shared tail with func_L01_00490050); byte diff from register allocation. Needs func_0011B2E8 varargs in the file context. D_L01_002E9DC8/DCC are D_L01_002E9DC0[1].w0/.w4. */
typedef struct {
    s32 w0;
    s32 w4;
    s32 w8;
    s32 wC;
    s32 w10;
} E_00493BC8;
typedef struct {
    s32 w0;
    s32 w4;
} P_00493BC8;
extern E_00493BC8 D_L01_002EB638[];
extern P_00493BC8 D_L01_002E9DC0[];
extern u8 *D_001D52FC __attribute__((section(".sdata")));
extern u8 D_L01_001D672C;
extern char D_L01_001E0AC0[];
extern char D_L01_001D8F00[];
extern s32 func_003B9BD0(s32);
extern void func_003BA4F8(s32, s32);
extern s32 func_003B9C58(s32);
extern char *func_003B9E30(s32, s32, s32);
extern char *func_00381FF0(s32);
extern s32 func_L01_00492870(void);
extern void func_L01_00517748(s32);
extern void func_L01_00516090(s32);
extern void func_003A5348(s32, s32, s32);
extern s32 func_L01_00494088(void);
extern void func_0011B2E8(char *, char *, ...);
extern void func_L01_00516D60(s32, s32);
extern void func_L01_00516FD8(s32, char *);
extern s32 func_L01_00494070(s32);
extern void func_L01_00517190(s32, s32);
extern void func_L01_00498948(s32, s32, s32);
extern s32 func_L01_0047DAB0(void);
extern void func_L01_0047DAC8(void);
extern s32 func_L01_0047EBE0(void);

void func_L01_00493BC8(s32 a0) {
    s32 sel, w, v, i;
    char *s;
    s32 t;
    E_00493BC8 *e;

    func_003BA4F8(func_003B9BD0(0), *(s32 *)(D_001D52FC + 0x1C4));
    if (*(s32 *)(D_001D52FC + 0x1C4) & 0x10) {
        func_L01_00517748(func_L01_00492870());
        func_L01_00516090(a0);
        func_003A5348(4, 0, 0);
    }
    s = func_00381FF0(0x253);
    t = func_L01_00494088();
    func_0011B2E8(D_L01_001E0AC0, s, t, 0x1E);
    sel = func_003B9C58(func_003B9BD0(0));
    w = D_L01_002EB638[sel].w0;
    if (w < 0x1E) {
        if (w == 1 || w == 2 || w == 4 || w == 8 || w == 0x1B || w == 0x1C || w == 9 || w == 0x1D ||
            w == 5 || w == 0xD || w == 0x17 || w == 0xA || w == 0x12 || w == 0xE) {
            if (w > 0) v = D_L01_002E9DC0[w % 0x3C].w4;
            else v = D_L01_002E9DC0[1].w4;
        } else {
            if (w > 0) v = D_L01_002E9DC0[w % 0x3C].w0;
            else v = D_L01_002E9DC0[1].w0;
        }
    } else {
        if (w > 0) v = D_L01_002E9DC0[w % 0x3C].w4;
        else v = D_L01_002E9DC0[1].w4;
    }
    func_L01_00516D60(0x530005, 0);
    if (v >= 0) {
        func_L01_00516D60(0x530005, 1);
        func_L01_00516FD8(0x530005, func_00381FF0(v));
    }
    e = &D_L01_002EB638[sel];
    if (func_L01_00494070(e->wC) != 0) {
        func_L01_00516FD8(0x530007, func_00381FF0(e->w8));
        func_L01_00517190(0x530003, e->w10);
    } else {
        func_L01_00516FD8(0x530007, func_00381FF0(0x16CE));
        func_L01_00517190(0x530003, 0x1F);
    }
    for (i = 0; i < 0x1E; i++) {
        char *r = func_003B9E30(func_003B9BD0(0), 0, i);
        s = func_00381FF0(D_L01_002EB638[i].w4);
        func_0011B2E8(r, D_L01_001D8F00, s);
        if (func_L01_00494070(D_L01_002EB638[i].wC) != 0) func_L01_00498948(func_003B9BD0(0), i, 0);
        else func_L01_00498948(func_003B9BD0(0), i, 1);
    }
    if (func_L01_0047DAB0() != 0) {
        func_L01_0047DAC8();
        func_L01_00516090(a0);
        if (D_L01_001D672C == 0) func_L01_00517748(func_L01_0047EBE0());
    }
}

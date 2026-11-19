/* functional: high. Multiplayer-menu HUD widget update: three modes on the mode word at the settings object +0x180 (1 / 0 / other) set widget positions, scales, visibility and texts (0x30010-0x30017), mode 0 also scales two gauge widgets by value/max ratios and marks flash timers (0x3C), mode 2 formats a per-player score string; then formats a clock text mm:ss from the elapsed-time counter and shows the timer widget 0x30016. Written from the PAL asm at L40 (4B3670) with the NTSC twin draft as a structural guide; every constant, callee and offset re-checked against PAL; the L39 naming copy is a 4-byte stub so the check ran at level 40; compiles, register allocation differs. */
typedef struct G_005E0FC8 {
    int w0;
    int w4;
    unsigned char pad8[0x20C - 0x8];
    unsigned char *p20C;
    int *p210;
} G_005E0FC8;

extern unsigned char *D_L40_00241640[];
extern int *D_L40_00241120[];
extern G_005E0FC8 D_L40_00357260;
extern int D_001A5DF8[];
extern int D_L40_00248A90[];
extern int D_L40_00248A94[];
extern int D_L40_00248AA0[];
extern int D_L40_00248AA8[];
extern unsigned char D_L40_00248AB0[];
extern unsigned char D_L40_00248AB8[];
extern unsigned char D_L40_00248AC0[];
extern unsigned char D_L40_00243978[];
extern unsigned char D_L40_00243980[];
extern unsigned char D_L40_00243990[];
extern unsigned char D_L40_002439A0[];
extern unsigned char D_L40_002439A8[];
extern unsigned char D_L40_002BA330[];

extern void func_L01_00517190(int, int);
extern void func_L01_00516470(int, float, float);
extern void func_L01_00517538(int, float, float);
extern void func_L01_00516AA0(int, int, int);
extern void func_L01_005170B8(int, int);
extern void func_L01_00516FD8(int, void *);
extern int func_L01_00517688(void);
extern void func_00120048(void *, void *, ...);
extern void func_L39_005E0F00(int, int);

void func_L39_005E0FC8(void) {
    unsigned char *g;
    unsigned char *buf;
    int mode;
    int i;
    int t;
    int mn;
    int sc;
    float f21;
    float f22;

    mode = *(int *)(D_L40_00241640[0] + 0x180);
    if (mode == 1) {
        func_L01_00517190(0x3000F, 0xED5B);
        func_L01_00516470(0x30012, 0.83f, 0.08f);
        func_L01_00516470(0x30013, 0.74f, 0.08f);
        func_L01_00516470(0x30014, 0.825f, 0.062f);
        func_L01_00516470(0x30015, 0.74f, 0.062f);
        func_L01_00517538(0x30012, 0.073f, 0.055f);
        func_L01_00517538(0x30013, 0.073f, 0.055f);
        func_L01_00517538(0x30014, 0.7f, 0.75f);
        func_L01_00517538(0x30015, 0.7f, 0.75f);
        func_L01_00516AA0(0x3000C, 1, 1);
        func_L01_00516AA0(0x30011, 1, 0);
        func_L01_00516AA0(0x30010, 1, 0);
        func_L01_00516AA0(0x30012, 1, 1);
        func_L01_00516AA0(0x30013, 1, 1);
        func_L01_00516AA0(0x30014, 1, 1);
        func_L01_00516AA0(0x30015, 1, 1);
        func_L01_00516AA0(0x30017, 1, 0);
        func_00120048(D_L40_00248AB0, D_L40_00243978, *(int *)(*(unsigned char **)&D_L40_00357260.p210 + 0xC));
        func_00120048(D_L40_00248AB8, D_L40_00243978, *(int *)(*(unsigned char **)&D_L40_00357260.p210 + 8));
    } else if (mode == 0) {
        func_L01_00517190(0x3000F, 0xED33);
        if (*(float *)(D_L40_00357260.p20C + 0x148) != *(float *)(D_L40_00357260.p20C + 0x128)) {
            D_L40_00248A90[0] = 0x3C;
        }
        if (*(float *)(D_L40_00357260.p20C + 0x14C) != *(float *)(D_L40_00357260.p20C + 0x12C)) {
            D_L40_00248A94[0] = 0x3C;
        }
        func_L39_005E0F00(0, 0x60FF0000);
        func_L39_005E0F00(1, 0x600000FF);
        f21 = *(float *)(D_L40_00357260.p20C + 0x14C) / *(float *)(D_L40_00357260.p20C + 0x10C);
        f22 = *(float *)(D_L40_00357260.p20C + 0x148) / *(float *)(D_L40_00357260.p20C + 0x108);
        func_L01_00517538(0x30011, f21 * 0.18f, 0.02f);
        func_L01_00517538(0x30010, f22 * 0.18f, 0.02f);
        func_L01_005170B8(0x30010, D_L40_00248AA0[0]);
        func_L01_005170B8(0x30011, D_L40_00248AA8[0]);
        func_L01_00516AA0(0x3000C, 1, 1);
        func_L01_00516AA0(0x30011, 1, 1);
        func_L01_00516AA0(0x30010, 1, 1);
        func_L01_00516AA0(0x30012, 1, 0);
        func_L01_00516AA0(0x30013, 1, 0);
        func_L01_00516AA0(0x30014, 1, 0);
        func_L01_00516AA0(0x30015, 1, 0);
        func_L01_00516AA0(0x30017, 1, 0);
    } else {
        func_L01_00517190(0x3000F, 0xED3B);
        func_L01_00516AA0(0x3000C, 1, 1);
        func_L01_00516AA0(0x30011, 1, 0);
        func_L01_00516AA0(0x30010, 1, 0);
        func_L01_00516AA0(0x30012, 1, 0);
        func_L01_00516AA0(0x30013, 1, 0);
        func_L01_00516AA0(0x30014, 1, 0);
        func_L01_00516AA0(0x30015, 1, 0);
        func_L01_00516AA0(0x30017, 1, 1);
        i = func_L01_00517688();
        g = (unsigned char *)&D_L40_00357260;
        buf = D_L40_002BA330 + i * 16;
        func_00120048(buf, D_L40_00243980, *(short *)(g + i * 4 + 0x18) - *(short *)(g + i * 2 + 0x198), *(signed char *)(D_L40_00241640[0] + 0x197));
        func_L01_00516470(0x30017, 0.78f, 0.06f);
        func_L01_00517538(0x30017, 0.6f, 0.7f);
        func_L01_00516FD8(0x30017, buf);
    }
    if (*D_L40_00241120[0] < 3) {
        func_L01_00516AA0(0x3000C, 1, 0);
    }
    t = D_L40_00357260.w0 - (D_001A5DF8[0] - D_L40_00357260.w4);
    if (t < 0) {
        t = 0;
    }
    mn = t / 60000;
    sc = t % 60000 / 1000;
    func_00120048(D_L40_00248AC0, D_L40_00243990, mn < 10 ? D_L40_002439A0 : D_L40_002439A8, mn, sc < 10 ? D_L40_002439A0 : D_L40_002439A8, sc);
    func_L01_00516FD8(0x30016, D_L40_00248AC0);
    func_L01_00516470(0x30016, 0.77f, 0.12f);
    func_L01_00517538(0x30016, 0.55f, 0.7f);
    if (*D_L40_00241120[0] >= 3) {
        if (D_L40_00357260.w0 != -1) {
            func_L01_00516AA0(0x30016, 1, 1);
        } else {
            func_L01_00516AA0(0x30016, 1, 0);
        }
    } else {
        func_L01_00516AA0(0x30016, 1, 0);
        func_L01_00516AA0(0x30017, 1, 0);
    }
}

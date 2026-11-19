/* functional: high. PAL-constant state machine (12 and 0x4B frames, 12.0f fade) verified against PAL asm incl. delay slots: state 0 waits for the timer then sets it to 12; state 1 runs the fade-in (func_003BE3C0(w40/12)), then to 0x4B; state 2 waits (calls func_003BBD20 if func_003BE2D0()), advances to state 3 only if `a` is nonzero; state 3 fades out and returns 1 when the timer fires; any other state returns 0. */
typedef struct { u8 pad0[0x40]; s32 w40; s32 w44; } G_003C0E88;
extern G_003C0E88 D_2D1FC0;
extern s32 func_0038CEB0();
extern s32 func_003BE2D0();
extern void func_003BBD20();
extern void func_003BE3C0(f32);
s32 func_003C0E88(s32 a) {
    G_003C0E88 *g = &D_2D1FC0;
    s32 r = 0;
    switch (g->w44) {
    case 0:
        if (func_0038CEB0(&g->w40) == 1) {
            g->w40 = 0xC;
            g->w44 = g->w44 + 1;
        }
        break;
    case 1:
        if (func_0038CEB0(&g->w40) == 1) {
            g->w40 = 0x4B;
            g->w44 = g->w44 + 1;
        }
        func_003BE3C0((f32)g->w40 / 12.0f);
        break;
    case 2:
        if (func_003BE2D0()) {
            func_003BBD20();
        }
        if (func_0038CEB0(&g->w40) == 1 && a != 0) {
            g->w40 = 0xC;
            g->w44 = g->w44 + 1;
        }
        break;
    case 3:
        if (func_0038CEB0(&g->w40) == 1) {
            r = 1;
        }
        func_003BE3C0(1.0f - (f32)g->w40 / 12.0f);
        break;
    }
    return r;
}

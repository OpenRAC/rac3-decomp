/* functional: high. Fade/transition state machine on D_002D2060 (state f48, counter f4C via func_0038CEB0, fade value f30 = counter/50 style): two variants chosen by f40 (6 states with sound cues func_003BBC00 and a skip-on-button check, or 3 states); returns 1 on the frame the final fade-out ends. In the f40==0 path also eases f50 toward D_001D9044 via func_0038DE98 (returns f32 in retail; the file's context declares it void: fix that declaration at gating). The % D_001D9094 is retail's `div`+`mfhi` (no trap on zero on the EE: the gate/port must not SIGFPE on zero). Verified block by block against PAL asm. */
typedef struct {
    u8 p0[0x30];
    f32 f30;
    s32 f34;
    u8 p38[8];
    s32 f40;
    u8 p44[4];
    s32 f48;
    s32 f4C;
    f32 f50;
    u8 p54[0xC];
    u8 b60;
} S_BC0F0;
extern S_BC0F0 D_002D2060[];
extern s32 D_001D9094;
extern f32 D_001D9044;
extern u8 *D_001D52FC;
s32 func_003C1AE0(void) {
    extern void func_003BBC00(s32);
    extern s32 func_0038CEB0();
    extern s32 func_003BE2D0();
    extern void func_003BBD20();
    extern s32 func_003BE6B8(void);
    extern void func_003BBCA8(s32,f32);
    extern f32 func_0038DE98(f32,f32);
    S_BC0F0 *g=D_002D2060;
    s32 done=0;
    if (g->b60==0) { func_003BBC00(2); g->b60=1; }
    if (g->f40) {
        switch(g->f48) {
        case 0:
            g->f30=1.0f-(f32)g->f4C/50.0f;
            if(func_0038CEB0(&g->f4C)) { g->f4C=75;g->f48=1; }
            break;
        case 1:
            if(func_0038CEB0(&g->f4C)) { g->f48=2; g->f4C=g->f34*3; }
            break;
        case 2:
            g->f30=1.0f;
            if((g->f34*3-g->f4C)%D_001D9094==0)func_003BBC00(0);
            if(func_0038CEB0(&g->f4C)) { g->f4C=75;g->f48=3;func_003BBC00(1); }
            break;
        case 3:
            g->f30=1.0f;
            if(func_0038CEB0(&g->f4C)) { g->f48=4;g->f4C=100; }
            if(*(u32 *)(D_001D52FC+0x1C4)&0x40)g->f4C=0;
            break;
        case 4:
            if(func_003BE2D0())func_003BBD20();
            if(func_003BE6B8()) {
                if(func_0038CEB0(&g->f4C)) {g->f48=5;g->f4C=50;}
            }
            break;
        case 5:
            done=(func_0038CEB0(&g->f4C)==1);
            g->f30=(f32)g->f4C/50.0f;
            func_003BBCA8(2,g->f30);
            break;
        }
    } else {
        switch(g->f48) {
        case 0:
            g->f30=1.0f-(f32)g->f4C/50.0f;
            if(func_0038CEB0(&g->f4C)) {g->f48=1;g->f4C=100;}
            break;
        case 1:
            g->f30=1.0f;
            if(func_003BE6B8()) {
                if(func_0038CEB0(&g->f4C)) {g->f4C=50;g->f48=2;}
            }
            break;
        case 2:
            done=(func_0038CEB0(&g->f4C)==1);
            g->f30=(f32)g->f4C/50.0f;
            break;
        }
        g->f50=func_0038DE98(g->f50,D_001D9044);
    }
    return done;
}

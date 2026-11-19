/* functional: high. US draft verified line by line against PAL asm (gp offsets resolve to D_1D5ED8/D_1D5EDC, constants 10.0 and 48.0, call args); only codegen differs. */
extern u8 D_001D5EDC;
extern s32 D_001D5ED8;
extern void func_0038B200();
void func_00397FC0(void) {
    s32 v;
    f32 t;
    if (D_001D5EDC) {
        D_001D5EDC = 0;
        D_001D5ED8 = D_001D5ED8 + 1;
        if (D_001D5ED8 > 10) D_001D5ED8 = 10;
    } else {
        D_001D5ED8 = D_001D5ED8 - 1;
        if (D_001D5ED8 < 0) D_001D5ED8 = 0;
    }
    t = (f32)D_001D5ED8;
    t = t / 10.0f;
    t = t * 48.0f;
    v = (s32)t;
    if (v) func_0038B200(0, 0, 0, v);
}

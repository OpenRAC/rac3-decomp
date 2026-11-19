/* functional: high. Float steps 0.00480769249 and 0.0192307699 taken from the asm bit patterns. */
extern f32 D_L01_001D8CCC;
extern s32 D_L01_001E0958[];

void func_L01_0048DF60(void) {
    s32 s = D_L01_001E0958[0];
    f32 step = 0.00480769249f;
    f32 d;

    if (s == 2) {
        d = 1.0f * step;
    } else if (s < 3) {
        if (s == 1) {
            d = -1.0f * step;
        } else {
            d = 0.0f * step;
        }
    } else if (s == 3) {
        step = 0.0192307699f;
        d = -1.0f * step;
    } else if (s == 4) {
        step = 0.0192307699f;
        d = 1.0f * step;
    } else {
        d = 0.0f * step;
    }
    D_L01_001D8CCC = D_L01_001D8CCC + d;
}

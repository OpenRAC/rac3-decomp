/* functional: high. From the PAL near-miss draft, re-read vs PAL asm: both arms' wave shapes, constants (0.009000001, 1.5, -7/7, -2/+2) verified. Signature void* to match the file's earlier declaration. 36 diff = register naming only. */
extern f32 func_003C3BE8(f32, f32, f32);
extern void func_L07_003B3DB0(void *, s32, f32);

void func_L07_003B3C78(void *self) {
    u8 *arg0 = self;
    u8 *p = *(u8 **)(arg0 + 0x68);
    f32 v, r;
    s32 i;

    *(f32 *)(p + 0x658) += 0.009000001f;
    if (*(f32 *)(p + 0x658) > 1.5f) {
        *(f32 *)(p + 0x658) -= 1.5f;
    }

    for (i = 0; i < 2; i++) {
        if (i == 0) {
            f32 a = *(f32 *)(p + 0x658);
            v = a;
            if (a < 1.0f) {
            } else {
                v = (1.5f - a) * 2.0f;
            }
        } else {
            f32 a = *(f32 *)(p + 0x658);
            if (a < 0.5f) {
                v = a * 2.0f;
            } else {
                v = 1.5f - a;
            }
        }
        r = func_003C3BE8(-7.0f, 7.0f, v);
        func_L07_003B3DB0(arg0, i, r + (i == 0 ? -2.0f : 2.0f));
    }
}

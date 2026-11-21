/* functional: high. The vmr32 of vf0 yields (0,0,1,0), written as four float stores; same stores and call as retail. */
extern s32 D_L01_001D673C;

void func_L01_004512B0(void *a0, f32 *out) {
    if (D_L01_001D673C == 0) {
        out[0] = 0.0f;
        out[1] = 0.0f;
        out[2] = 1.0f;
        out[3] = 0.0f;
    } else {
        ((void (*)(void *, void *, s32))func_003C5180)(a0, out, 1);
    }
}

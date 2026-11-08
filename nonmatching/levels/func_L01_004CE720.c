/* func_L01_004CE720: MATCHES at 35 of 45 PAL places + US (home L01). Levels 40-45,50-53 (multiplayer) differ by one offset: 0x45e4 instead of 0x4614.
   Lead: decide whether those places are separate functions in the build. */
int func_L01_004CE720(char *base, int idx) {
    float *p = *(float **)(base + idx * 0x230 + 0x4614);
    return *p > 0.0f;
}

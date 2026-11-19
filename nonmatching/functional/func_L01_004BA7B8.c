/* functional: high. Sets the D_L01_001D6720 float to 1.2 and, while the fade global D_L01_001DF950 is below 1.0, calls func_0038A238(5). */
extern f32 D_L01_001DF950[];
extern f32 D_L01_001D6720;
extern void func_0038A238(s32);

void func_L01_004BA7B8(void) {
    D_L01_001D6720 = 1.2f;
    if (D_L01_001DF950[0] < 1.0f) {
        func_0038A238(5);
    }
}

/* functional: high. Same float operations in the same order as retail. */
extern f32 D_L01_001D8CA4;
extern f32 D_L01_001D8C98;
extern f32 D_L01_001D8CCC;
extern f32 D_L01_001D8CA0;
extern f32 D_L01_001D8CA8;
extern f32 D_L01_001D8CE0;
extern f32 D_L01_001D8C9C;
extern s32 D_L01_001E0958[];
extern void func_L01_00516470(s32, f32, f32);

void func_L01_0048DE98(void) {
    f32 y = (D_L01_001D8CA4 + D_L01_001D8C98) + D_L01_001D8CCC;
    s32 i;

    if (D_L01_001E0958[0] == 1 || D_L01_001E0958[0] == 3) {
        y = y - D_L01_001D8CA0;
    }
    for (i = 0; i < 4; i++) {
        func_L01_00516470(i + 0x160011, D_L01_001D8CA8, y);
        func_L01_00516470(i + 0x160016, D_L01_001D8CA8, y + D_L01_001D8CE0);
        y = y + D_L01_001D8C9C;
        y = y + D_L01_001D8C98;
    }
}

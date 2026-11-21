/* high: Body exact; the catalogue boundary starts 4 bytes early on a 0xCDCDCDCD fill word, so the real function is at +4.. Returns the global float scale D_001D5308 times the argument (a PAL/NTSC frame-time scale) */
extern f32 D_001D5308;
f32 func_L01_0040DEF4(f32 x) {
    return D_001D5308 * x;
}

/* functional: high. Retail uses adda.s/madd.s to form n*scale+0.5 (0.25+0.25 in ACC); C uses mul+add, same value. */
extern f32 D_001D5308;
s32 func_L01_0040DF08(s32 n) {
    return (s32)((f32)n * D_001D5308 + 0.5f);
}

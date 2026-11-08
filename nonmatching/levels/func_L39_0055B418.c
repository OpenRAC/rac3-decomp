/* func_L39_0055B418: exact except the 2 nops retail pads before div.s (divs_nops table has no level support: config/levels has no divs_nops.txt)
   Size 188, 15 places (shared/L39_0055B418.c), flags file line has -mno-split-addresses; checked with --as ps2as (14 diff = the 2 nops + shift)
   Draft is the full body; if levels get a divs_nops mechanism it should match as is. */
extern f32 func_0038D160(f32, f32);
extern f32 func_0038DBA0(f32, f32);
extern f32 func_0038CEA8(void *);
extern void func_0038CF68(void *, void *, f32);
void func_L39_0055B418(u8 *a0, f32 *a1) {
    f32 t = func_0038DBA0(*(f32 *)(a0 + 0xB8), func_0038D160(a1[0], a1[1]));
    if (1.8325957f < t) {
        t = 1.8325957f;
    }
    func_0038CF68(a1, a1, func_0038CEA8(a1) * ((1.8325957f - t) / 1.8325957f * 0.3f + 0.7f));
}

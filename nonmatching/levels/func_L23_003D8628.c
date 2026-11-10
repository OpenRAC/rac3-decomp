/* func_L23_003D8628: near miss (p2 w2): code matches except retail has 2 nops before div.s (div.s nop padding; level divs_nops table, as for frontbin).
   Needs --as ps2as (inline 1.0f). Lead: add "func_L23_003D8628 2" to the level divs_nops table if levels support it. */
typedef struct { char pad[0x128]; float f128; float f12C; int i130; char pad2[0x460 - 0x134]; } S23;
extern S23 D_L23_001E1A40[];
void func_L23_003D8628(int a0, int a1, float f) {
    S23 *s = &D_L23_001E1A40[a0];
    if (s->f12C == 0.0f) {
        s->i130 = a1;
        s->f12C = 1.0f;
        s->f128 = 1.0f / f;
    }
}

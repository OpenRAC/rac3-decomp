/* Resolved on 2026-11-15: current C is integrated in src/levels/07_annihilation_nation/L07_003AF398.c and the full PAL level build prints MATCH. This saved draft is retained as historical evidence; its obsolete void callee declaration caused the two-word residual. */
/* Level 7 near miss: 2 differences of 60 words with the owning file's @ps2as
   flags. Only the timer literal differs: retail `addiu $v1,$0,0x3E8` / `sh
   $v1,0x32A($s0)`, this C `$v0`. About 16 formulations (literal, s16/s32/u16
   locals, casts, typed struct, do/while wrapper, declaration order) kept the
   same bytes. Not linked; the owning file's flags are unchanged. No VU0. */
extern u8 *D_L07_001DF41C_003B6CD8;
extern s32 func_L01_00456250(void *);
extern void func_L07_003A2380(s32, void *, s32, s32);

s32 func_L07_003B6CD8(u8 *arg0, u8 arg1) {
    u8 *s = *(u8 **)(arg0 + 0x68);
    u8 *p;
    f32 d;

    if (s[0x321] != 0) {
        return 0;
    }
    if (s[0x320] >= 4) {
        return 1;
    }
    if (func_L01_00456250(arg0) != 0) {
        if (*(s16 *)(s + 0x32A) == 0) {
            p = D_L07_001DF41C_003B6CD8 + (*(s32 *)(s + 0x300) << 8);
            if (p[0xBC] == 0) {
                p[0xBC] = 1;
            }
            func_L07_003A2380(0xC, p, 0, 0x64);
            *(s16 *)(s + 0x32A) = 0x3E8;
        }
        return 1;
    }
    if (arg1 != 0) {
        return 0;
    }
    d = *(f32 *)(s + 0x310) - *(f32 *)(s + 0x30);
    if ((f32)*(s16 *)(s + 0x34) * 0.1f < d) {
        return 1;
    }
    return 0;
}

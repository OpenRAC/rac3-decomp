/* Near miss of func_003B26B0 with its file's own flags: tools/check.py reports 3 diff
   (the version it replaces: 17).
   What differs: Everything except the load of D_001DA0B4 now matches (51 of 54 words; the diff
   went from 16 to 3). Retail reaches that global with the destination-reused pair `lui $a0,
   %hi(D_001DA0B4)` + `lw $a0, %lo(D_001DA0B4)($a0)` (the @ps2as assembler macro of a small
   scalar load, per docs/wiki/Matching-Patterns.md), while with this file's flags (S mode,
   default ee-as) gcc can only emit its split form `lui $v1, %hi(D_001DA0B4)` + `lw $a0,
   %lo(D_001DA0B4)($v1)` (high half in $v1) for an unsized-array access; the tied form needs
   the load's destination to stay a pseudo so the address base coalesces with...
*/

/* US draft of func_003B26B0 (rac3-uya-decomp func_003AD108, commit 13cf5c5), names moved to PAL addresses
   where known. Not carried: flags: the US matched it with `@ps2as` (a single-function override). */


/* localdecomp:start func_003B26B0 */
typedef struct { char c[4]; } S4_3AD108;
typedef struct { u8 p0[0x48]; u8 p48[0x60]; s32 fA8; } S_3AD108;
extern S4_3AD108 D_001D8830[];
extern u8 *D_001DA0B4[];
extern void func_003B25A0();
extern s32 func_003B2AC8();
extern void func_003B25C0();
extern void func_003B2050();
s32 func_003B26B0(S_3AD108 *a) {
    S4_3AD108 buf;
    s32 r0;
    s32 r1;
    s32 r2;
    s32 r3;
    s32 v;
    buf = D_001D8830[0];
    func_003B25A0(a, &r0, &r1, &r2, &r3);
    if (r1 + r3 < 4) return 0;
    v = func_003B2AC8((r0 & 0xFFFFFFF) | 0x20000000, r1, (r2 & 0xFFFFFFF) | 0x20000000, r3, &buf, 4, 0, 0);
    func_003B25C0(D_001DA0B4[0], v);
    func_003B2050((u8 *)a + 0x48);
    if (a->fA8 == 0) {
        a->fA8 = 2;
    }
    return 1;
}
/* localdecomp:end func_003B26B0 */

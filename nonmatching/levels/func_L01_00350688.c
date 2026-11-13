/* func_L01_00350688: MATCH with -mno-split-addresses (check.py --mode N) under the file's @ps2as;
   3 diff in L01_003500B8.c's split mode. In N mode gcc writes each unknown-size float store as one
   `s.s` macro of two words, so reorg leaves the jr delay slot empty and Ps2EeAs expands the macros
   with lui $at, as retail. In split mode the stores are either split into lui $vN (arrays) or, as
   small scalars, one word each, and the last one goes into the delay slot (made $gp by Ps2EeAs).
   The store order 1A10, 1A1C, 1A18, 1A14 comes from the source order 1C, 18, 14, 10.
   Needs a file cut: every C block of L01_003500B8.c before func_L01_00352950 (003500C0, 00350658,
   003506B8, 003506E0) also matches in N mode; func_L01_00352950 does not (88 diff). */
__asm__(".extern D_L01_001DD49C, 4");
extern void *D_L01_001DD49C;
extern f32 D_L01_001E1A10[];
extern f32 D_L01_001E1A14[];
extern f32 D_L01_001E1A18[];
extern f32 D_L01_001E1A1C[];

void func_L01_00350688(void) {
    f32 z = 0.0f;
    D_L01_001DD49C = 0;
    D_L01_001E1A1C[0] = z;
    D_L01_001E1A18[0] = z;
    D_L01_001E1A14[0] = z;
    D_L01_001E1A10[0] = z;
}

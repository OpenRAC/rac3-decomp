/* Near miss of func_003BB1F0 with its file's own flags: tools/check.py reports 68 diff
   (the US draft it started from: 100).
   What differs: addressing fixed (retail reaches D_001D5BDC / D_001DA1B0 absolutely, not
   through $gp: with the file's -G8 the compiler only keeps a global out of .sdata when its
   size is unknown, so the candidate uses unknown-size aliases D_001D5BDC_003BB1F0[] /
   D_001DA1B0_003BB1F0b[]; the source file's own scalar/sized declarations of those two symbols
   are forced into the check context and cannot be redeclared). Remaining: instruction
   scheduling / register allocation only. (1) prologue: ours computes %hi(D_001D5BDC) then
   %hi(D_00280FC0) and loads the flag into $a1, retail does %hi(D_00280FC0) then...
*/

/* PAL candidate for func_003BB1F0 (US draft of rac3-uya-decomp func_003B5D10, commit 13cf5c5,
   names moved to PAL addresses where known).
   PAL differs from the US draft in the addressing of the globals: the retail build reaches
   D_001D5BDC and D_001DA1B0 absolutely (lui/%hi + %lo), not through $gp: with the file's -G8
   the compiler only keeps a global out of .sdata when its size is unknown, so both are used
   through aliases of unknown size here (the source file's own declarations of these two
   symbols are scalar/sized, so they cannot be redeclared in the candidate). */

/* localdecomp:start func_003BB1F0 */
typedef struct { u32 a; u32 b; } E_3B5D10;
extern u8 D_001D5BDC_003BB1F0[];
extern E_3B5D10 D_001DA1B0_003BB1F0b[];
extern u8 D_00280FC0[];
void func_003BB1F0(s32 arg) {
    s32 A, B, C, D, i, e;
    u32 p = (u32)D_00280FC0;
    u32 q = 0;
    if (D_001D5BDC_003BB1F0[0] != 0) {
        A = 0; B = 0; C = 1; D = 0;
    } else if (arg == 0) {
        A = 1; B = 1; C = 0; D = 0;
    } else {
        A = 3; B = 1; C = 2; D = 1;
    }
    i = 0;
    e = A;
    for (; i < e; i++) {
        D_001DA1B0_003BB1F0b[i].a = p;
        D_001DA1B0_003BB1F0b[i].b = 0;
        p += 0x12C00;
    }
    e += B;
    for (; i < e; i++) {
        D_001DA1B0_003BB1F0b[i].a = q;
        D_001DA1B0_003BB1F0b[i].b = 0;
        q += 0x12C00;
    }
    e += C;
    for (; i < e; i++) {
        D_001DA1B0_003BB1F0b[i].a = p;
        D_001DA1B0_003BB1F0b[i].b = 1;
        p += 0x4F000;
    }
    e += D;
    for (; i < e; i++) {
        D_001DA1B0_003BB1F0b[i].a = q;
        D_001DA1B0_003BB1F0b[i].b = 1;
        q += 0x4F000;
    }
    for (; i < 7; i++) {
        D_001DA1B0_003BB1F0b[i].b = 0;
        D_001DA1B0_003BB1F0b[i].a = 0;
    }
}
/* localdecomp:end func_003BB1F0 */

/* Near miss of func_00399D68 with its file's own flags: tools/check.py reports 3 diff
   (the version it replaces: 57).
   What differs: 65 of 68 words match. The only difference is the schedule of one instruction
   in the `a == 0` branch: retail puts the D_002DB190 base's low half (`addiu $v1, $v1,
   -0x4e70`) after the byte load (`lui $a0, 0x1e; lbu $a0, -0x5b7c($a0)`), while this C puts it
   before them; the registers ($v0 word load, $v1 base, $a0 byte), the branch targets, the
   frame and the whole second branch match. The `$gp`/`lui` mix was solved with plain
   declarations plus `.extern` size hints (the assembler expands the `$gp` access of a symbol
   it is told is not small), the delay-slot store keeping `$gp` via a second name...
*/

/* PAL candidate for func_00399D68.
   Retail reaches D_001DA480 and D_001DA484 through lui/lw, except for the store of
   D_001DA484 that sits in a branch delay slot, which stays a $gp access. With the
   default assembler that mixed form comes from the counters being small-data scalars
   (gcc emits the $gp access) that the assembler is told are not small, so it expands
   the $gp access into lui + load; the store uses a second name for the same address
   whose size the assembler does not know, so that access stays $gp. `.extern` only
   declares a size, it creates no storage. */


/* localdecomp:start func_00399D68 */
typedef struct { u8 p[0x2D]; u8 b2D; } S_4F78;
extern u8 D_002DB190[];
extern s16 D_002DAFB0[];
extern s32 D_002DA740[];
extern s32 D_002DDC30[];
extern s32 D_001DA480;
extern s32 D_001DA484;
extern s32 D_001DA484_00399D68;
__asm__(".extern D_001DA480, 16");
__asm__(".extern D_001DA484, 16");
extern void func_00399A48(s32, s32, void *, s32);
extern void func_003CCF60();
void func_00399D68(S_4F78 *a, s32 b, void *c, s32 d) {
    if (a == 0) {
        u8 t;
        func_003CCF60(d, 1);
        t = (u8)D_001DA484;
        D_001DA484_00399D68 = D_001DA484 + 1;
        D_002DB190[d] = t;
    } else {
        D_002DAFB0[D_001DA480] = d;
        D_002DB190[d] = D_001DA480;
        D_002DA740[D_001DA480] = (s32)a;
        D_002DDC30[D_001DA480] = a->b2D << 10;
        if (a->b2D == 0xFF) D_002DDC30[D_001DA480] = 0x100000;
        func_00399A48((s32)a, b, c, d);
        func_003CCF60(d, 0);
        D_001DA480 = D_001DA480 + 1;
    }
}
/* localdecomp:end func_00399D68 */

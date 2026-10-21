/* Near miss of func_003BC858 with its file's own flags: tools/check.py reports 87 diff
   (the version it replaces: 91).
   What differs: C now matches PAL's `D_001D99A4 = 25` (0x19, not 0x1e) and the lui/lw-vs-$gp
   global accesses (D_001D4BC4, D_001D9BC8 unsized/aliased; D_001D99A4 read via $gp in the
   delay slots, written lui/sw), 86 diffs left, all in bytes retail got from Ps2EeAs's
   expansion of gcc's pseudo-instructions: `dli $5,0x8000000044` (retail ori $a1,$0,0x8000 /
   dsll $a1,$a1,0x18 / ori $a1,$a1,0x44 vs ee-as addiu $a1,$0,0x80 / dsll32 / ori), `li.s
   $f1,-6.2831855f` (retail lui $at,0xc0c9 / ori $at,$at,0xfdb / mtc1 $at,$f1 vs ee-as `lwc1
   $f1,-0x4000($gp)` out of the .lit4 pool, 1 word instead of 3, which shifts every...
*/

/* Candidate for func_003BC858 (PAL frontbin), compiled with the file's own flags
   (-mvu0-use-vf0-vf2 -O2 -G8 -fopt-stack -mno-check-zero-division).

   The US draft (rac3-uya-decomp func_003B7378) was matched with @ps2as.
   What was changed here and why:

   - D_001D99A4 is 25 (0x19) in PAL, not 30 (0x1e).  This is a real PAL
     difference and is fixed.

   - D_001D4BC4 and D_001D9BC8 are read with lui/lw in retail, not through
     $gp, so they are declared unsized (an unsized array is never small data,
     so gcc splits the address itself).  The file's own declarations are
     sized, so per-function aliases are used (the checker resolves
     D_<addr>_<suffix> to the same address).

   - D_001D99A4 is read through $gp in retail (both reads sit in branch delay
     slots) but written with lui/sw, so the reads use the file's sized
     declaration and the write an unsized alias.

   What still cannot be produced with the file's assembler (bin/ee-as.exe):
   gcc emits the pseudo-instructions `dli' (64-bit constants), `li.s' (float
   constants), `move' (64-bit register moves) and `lw/sw $reg, symbol'
   (global references); retail's bytes are Ps2EeAs's expansion of exactly
   those, while ee-as.exe expands them differently:

     dli $5,0x8000000044  Ps2EeAs: ori $5,$0,0x8000 / dsll $5,$5,24 / ori $5,$5,0x44
                          ee-as:   addiu $5,$0,0x80 / dsll32 $5,$5,0 / ori $5,$5,0x44
     li.s $f1,-6.2831855f Ps2EeAs: lui $at,0xc0c9 / ori $at,$at,0xfdb / mtc1 $at,$f1
                          ee-as:   lwc1 $f1,-0x4000($gp)   (literal pool)
     move $6,$2           Ps2EeAs: daddu $6,$2,$0
                          ee-as:   or $6,$2,$0
     lw $5,symbol         Ps2EeAs: lui $5,%hi(sym) / lw $5,%lo(sym)($5)
                          ee-as:   gcc splits the address itself and picks its own
                                   registers, so lui and lw get different ones.

   No plain C can change how those pseudo-instructions are expanded, so the
   remaining bytes are not reachable with this file's flags. */

/* localdecomp:start func_003BC858 */
typedef struct { u8 p0[0x15C]; s32 f15C; s32 f160; s32 f164; } S_142430_3B7378;
extern S_142430_3B7378 D_142430_003BC858;
extern s32 D_001D99A4_003BC858[];
extern s32 D_001D4BC4_003BC858[];
extern s32 D_001D4BC4_b[];
extern s32 D_001D9BC8_003BC858[];
extern f32 D_001D8CF0;
extern void func_00389240(s32);
extern void func_003A9440(s32, unsigned long);
extern long func_00389598(s32);
extern void func_0038B4D0(s32, s32, s32, s32, s32, s32, s32, s32, long, long);
extern void func_00397638(f32, f32, f32, f32, f32, s32, s32, long);
extern void func_00389370(void);
extern void func_0038AE20(s32, s32, s32, s32);
void func_003BC858(void) {
    f32 c, b, a;
    if ((u32)(D_142430_003BC858.f15C - 15) < 2 || D_142430_003BC858.f164 == 15 || D_001D99A4 != 0) {
        c = 272.0f;
        func_00389240(1);
        func_003A9440(0x42, 0x8000000044UL);
        func_003A9440(0x47, (unsigned long)0x3004B);
        func_0038B4D0(0x2C, D_001D4BC4_003BC858[0] - 0x60, 0x40, 0x40, 0, 0, 0x40, 0x40, 0x80808080UL, func_00389598(3));
        b = (f32)((D_001D4BC4_b[0] - 0x40) << 4);
        a = (f32)(D_001D9BC8_003BC858[0] % 55) * -6.2831855f / 55.0f;
        func_00397638(1216.0f, b, c, c, a, 0x40, 0x40, func_00389598(4));
        func_00389370();
        if ((u32)(D_142430_003BC858.f15C - 15) < 2 || D_142430_003BC858.f164 == 15) D_001D99A4_003BC858[0] = 25;
        else D_001D99A4_003BC858[0] = D_001D99A4 - 1;
    }
    func_003A9440(0x42, 0x8000000044UL);
    func_0038AE20(0, 0, 0, (s32)(D_001D8CF0 * 128.0f));
}
/* localdecomp:end func_003BC858 */

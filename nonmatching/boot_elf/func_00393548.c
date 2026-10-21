/* Near miss of func_00393548 with its file's own flags: tools/check.py reports 5 diff
   (the version it replaces: 73).
   What differs: 5 instructions still differ, all register-allocation: (1) the first `n * 4`
   (the scale of `p0->c[n]`) is allocated to $a0 and scheduled one slot later (`sd $s1, 8($sp)`
   then `sll $a0, $s0, 2`) where retail has `sll $v1, $s0, 2` before `sd $s1, 8($sp)`, which
   also makes the add `addu $v0, $v0, $a0` instead of `addu $v0, $v0, $v1`; (2) the D_1A1F08
   load folds its high half into the destination register (`lui $s4, 0x1a; lw $s4,
   0x1f08($s4)`) where retail has `lui $v0, 0x1a; lw $s4, 0x1f08($v0)`. Everything else matches
   byte for byte, including both D_1D9EA0 loads, both D_1D9EAC loads per...
*/

/* PAL candidate for func_00393548 (boot_elf), compiled with the file's own flags
   (-mvu0-use-vf0-vf2 -O2 -G8 -fopt-stack -mno-check-zero-division -mno-split-addresses).

   Retail reaches D_1D9EA0, D_1D9EAC and D_1A1F08 through lui/lw, not through $gp,
   so the globals are declared here without a size (an unsized array): a sized
   declaration would let gcc put them in small data and address them through $gp.
   The declarations in the source file are kept as they are and are not used. */

typedef struct { u8 p0[0x14]; s32 a[8]; s32 b[16]; s32 c[1]; } S_38E930;
typedef struct { u32 w0; u16 h4; u8 b6; u8 b7; } E_38E930;
extern S_38E930 *D_001D9EA0_00393548_a[];
extern S_38E930 *D_001D9EA0_00393548_b[];
extern E_38E930 *D_001D9EAC_00393548_a[];
extern s32 D_001A1F08_00393548_a[];
extern u32 D_001D5D50;
extern void func_003933B0_00393548();
extern void func_00397D60(s32, s32, s32, s32, s32, s32);
void func_00393548(s32 n, s32 a1, s32 a2) {
    S_38E930 *p0 = D_001D9EA0_00393548_a[0];
    s32 i, j, end, pos, n4;
    S_38E930 *p;
    if (p0->c[n] == 0) {
        func_003933B0_00393548(0);
    } else {
        pos = 0;
    }
    pos = D_001A1F08_00393548_a[0];
    p = D_001D9EA0_00393548_b[0];
    n4 = n * 4;
    j = (n != 0) ? p->b[n - 1] : 0;
    do {
    end = *(s32 *)((u8 *)p + n4 + 0x34);
    for (i = j; i < end; i++) {
        s32 s = pos >> 8;
        u32 b6 = D_001D9EAC_00393548_a[0][i].b6;
        u32 b7 = D_001D9EAC_00393548_a[0][i].b7;
        s32 sz = 1 << (b6 + b7);
        func_00397D60(D_001D9EAC_00393548_a[0][i].w0, s, 0x1B, b6, b7, a2);
        D_001D9EAC_00393548_a[0][i].h4 = s;
        pos += sz << 2;
        D_001D5D50 = pos;
    }
    } while (0);
}

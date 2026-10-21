/* Near miss of func_003B0BB8 with its file's own flags: tools/check.py reports 71 diff
   (the US draft it started from: 77).
   What differs: 64-bit constant materialisation (ours `lui hi16; dsll32 0; ori lo16` vs retail
   `ori $rd,$zero,0x8000; dsll/dsll32 N; ori lo` - same values, retail's shape is the `li.d`
   expansion of SN Ps2EeAs, ours is the default ee-as one); register allocation shifted one
   slot (retail keeps `p` in $t4, ours in $t3; retail mask 0x0FFFFFFF in $t1 and
   0x1000000000000002 in $a2, ours swapped); `D_001A1ED4` address in $t1 (ours reuses $v0);
   tail block: base in $v0 and `addu $a2,$a2,$v0` (index first) vs our $at + `addu
   $v0,$at,$v0`, and the first `lw *q` into $v0 vs $a0.
*/

/* US draft of func_003B0BB8 (rac3-uya-decomp func_003AB610, commit 13cf5c5), names moved to PAL addresses
   where known. Not carried: flags: the US matched it with `@ps2as` and without `-mno-split-addresses` (a single-function override). */


/* localdecomp:start func_003B0BB8 */
extern s32 D_001A1ED4[];
extern s32 D_001DA0C0[];
extern void func_003A1028_003B0BB8(s32, s32);
void func_003B0BB8(unsigned long *p, s32 a1, s32 a2, s32 a3, s32 a4) {
    s32 i, j;
    s32 h = a3 >> 4;
    s32 w = a4 >> 4;
    p[0] = 0x10000003;
    p[1] = 0;
    p[2] = 0x1000000000000002UL;
    p[3] = 0xE;
    p[4] = (((long)D_001A1ED4[0] >> 8) << 32) | 0x8000000000000L;
    p[6] = 0x1000000010UL;
    p[5] = 0x50;
    p[7] = 0x52;
    p += 8;
    for (j = 0; j < h; j++) {
        for (i = 0; i < w; i++) {
            p[0] = 0x10000004;
            p[1] = 0;
            p[2] = 0x1000000000000002UL;
            p[3] = 0xE;
            p[4] = ((unsigned long)(j << 4) << 32) | ((unsigned long)(i << 4) << 48);
            p[5] = 0x51;
            p[6] = 0;
            p[7] = 0x53;
            p[8] = 0x800000000000040UL;
            p[9] = 0;
            ((u32 *)p)[20] = 0x30000040;
            ((u32 *)p)[21] = a1 & 0xFFFFFFF;
            p[11] = 0;
            a1 += 0x400;
            p += 12;
        }
    }
    {
    s32 *q = (s32 *)((a2 << 2) + (s32)D_001DA0C0);
    ((u32 *)p)[0] = 0x20000000;
    ((u32 *)p)[1] = *q;
    ((u32 *)p)[2] = 0;
    ((u32 *)p)[3] = 0;
    func_003A1028_003B0BB8((*q & 0xFFFFFFF) | 0x20000000, 1);
    }
}
/* localdecomp:end func_003B0BB8 */

/* Near miss of func_003E7268 with its file's own flags: tools/check.py reports 9 diff
   (the US draft it started from: 13).
   What differs: the C is byte-exact except for retail's div.s padding: 2 nops in front of each
   div.s (4 nops total) that neither ee-gcc 2.95.3 nor Ps2EeAs emits; this repo restores that
   padding from config/frontbin/divs_nops.txt, whose entry for this function is still filed
   under the NTSC name `func_003E1D18 2 2` - adding the line `func_003E7268 2 2`
   (tools/gen_divs_nops.py adds it) makes the function match byte for byte.
*/

/* localdecomp:start func_003E7268 */
extern f32 D_001D9698;
extern f32 D_001D969C;
extern f32 D_001D96A0;
extern f32 D_001D96A4;
extern f32 D_001D96A8;
extern f32 D_001D96AC;

/* Ps2EeAs only uses $gp for these if it knows they are small before the use,
   so the size hints have to precede the function (docs/wiki/Matching-Patterns.md).
   Retail reaches all six globals through $gp. */
__asm__(".extern D_001D9698, 4");
__asm__(".extern D_001D969C, 4");
__asm__(".extern D_001D96A0, 4");
__asm__(".extern D_001D96A4, 4");
__asm__(".extern D_001D96A8, 4");
__asm__(".extern D_001D96AC, 4");

void func_003E7268(void) {
    D_001D96A8 = D_001D9698 / D_001D96A0;
    D_001D96AC = D_001D969C / D_001D96A4;
}
/* localdecomp:end func_003E7268 */

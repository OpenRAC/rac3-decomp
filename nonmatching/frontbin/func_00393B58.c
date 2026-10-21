/* Near miss of func_00393B58 with its file's own flags: tools/check.py reports 19 diff
   (the version it replaces: 34).
*/

/* func_00393B58 (PAL retail) — matched with the file's own flags
   (-mvu0-use-vf0-vf2 -O2 -G8 -fopt-stack -mno-check-zero-division -mno-split-addresses).

   Retail reaches D_001D9EE8, D_001D9EF0, D_1D4C60 and D_1D4C80 through
   lui/%lo, so the compiler must not put them in small data: an unsized array
   is never small data, a sized one always is.  The source file declares them
   sized (its own declaration cannot be changed from here), so this block uses
   per-function aliases of the same addresses, declared as unsized arrays.

   D_001D5D40 and D_001D5CAC are reached through $gp in retail, so they keep
   their size and get the .extern size hints the assembler needs. */

/* localdecomp:start func_00393B58 */
typedef struct { u8 pad[0x38]; u16 h38; u8 pad2[0xF0 - 0x3A]; } S_38F310;
typedef struct { s32 w0; u8 pad[0x14]; s32 w18; } D_393B58;
__asm__(".extern D_001D5D40, 4");
__asm__(".extern D_001D5CAC, 4");
extern s32 D_001D9EE8_00393B58_lui[];
extern s32 *D_001D9EF0_00393B58_lui[];
extern s32 D_1D4C60_00393B58[];
extern s32 D_1D4C80_00393B58[];
extern s32 D_001D5D40;
extern s32 D_001D5CAC;
extern u8 D_001425C0[];
extern S_38F310 D_001DAA40_00393B58[];
extern D_393B58 D_00331990[];
void func_00393B58(s32 a) {
    s32 *p;
    s32 i;
    s32 v;
    s32 k;
    S_38F310 *t;
    D_001D9EE8_00393B58_lui[0] = 8;
    D_001D9EF0_00393B58_lui[0] = &D_001D5D40;
    p = a ? D_1D4C80_00393B58 : D_1D4C60_00393B58;
    D_001D5CAC = 0;
    for (i = 0; i < 8; i++) {
        k = D_001425C0[p[i]];
        v = D_001DAA40_00393B58[k].h38;
        D_00331990[i].w0 = v;
        D_00331990[i].w18 = p[i];
    }
}
/* localdecomp:end func_00393B58 */

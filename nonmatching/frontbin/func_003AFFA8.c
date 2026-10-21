/* Near miss of func_003AFFA8 with its file's own flags: tools/check.py reports 2 diff
   (the version it replaces: 37).
*/

/* PAL candidate for func_003AFFA8 (frontbin).
 *
 * Retail reaches 0x001DA09C and the pointer stored at 0x001DA0B4 through
 *   lui  $v, %hi(sym)
 *   lw   $v, %lo(sym)($v)
 * while every other global in this function goes through $gp.  An unsized
 * array declaration is never small data, so it always gets the lui/lo form
 * (docs/wiki/Matching-Patterns.md, "Globals: gp vs lui"); the sized
 * D_001DA0B4 stays for the $gp access that sits in the delay slot of the
 * func_003B25E8 call.  The aliases are spelled with this function's address,
 * the convention the wiki records for per-function aliases.
 */

typedef struct { u8 pad[0xB0]; s32 wB0; } S_AAA00;
extern void *D_001DA09C_003AFFA8[];
extern S_AAA00 *D_001DA0B4_003AFFA8[];
extern void *D_001DA09C;
extern void *D_001DA088;
extern void *D_001DA0C8;
extern S_AAA00 *D_001DA0B4;
extern void *D_001DA0B8_003AFFA8;
extern void *D_001DA0B0;
extern u8 D_0013D208[];
extern s32 func_003B1320();
extern s32 func_003B2C50();
extern void func_11EC70(void *);
extern void func_11EC30(void *);
extern void func_11EB50(s32, s32);
extern void func_12D4D8(u8 *);
extern s32 func_003B25E8();
extern s32 func_003B0108();
extern s32 func_003B1418();
void func_003AFFA8(void) {
    ((void (*)(void *))func_003B1320)(D_001DA09C_003AFFA8[0]);
    ((void (*)(void *))func_003B2C50)(D_001DA088);
    func_11EC70(D_001DA0C8);
    func_11EC30(D_001DA0C8);
    ((s32 (*)(s32))func_11F940)(2);  /* s32 return matters: keeps $v0 live */
    func_11EB50(2, D_001DA0B4_003AFFA8[0]->wB0);
    func_12D4D8((u8 *)0x0013D208);
    ((void (*)(void *))func_003B25E8)(D_001DA0B4);
    ((void (*)(void *))func_003B0108)(D_001DA0B8_003AFFA8);
    ((void (*)(void *))func_003B1418)(D_001DA0B0);
    *(u32 *)0x1000E000 &= ~2;
}

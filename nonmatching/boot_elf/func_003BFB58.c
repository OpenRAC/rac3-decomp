/* Near miss of func_003BFB58 with its file's own flags: tools/check.py reports 6 diff
   (the version it replaces: 37).
*/

/* Candidate for func_003BFB58 (PAL boot_elf).
   Retail reaches D_001DA340, D_001DA338, D_001DA33C and the two bytes at
   D_001DA344 through lui/lo, not through $gp (docs/wiki/Matching-Patterns.md,
   "Globals: gp vs lui"), so these stores must not be small data. */

/* localdecomp:start func_003BFB58 */
extern f32 D_001DA340_003BFB58[];
extern s32 D_001D8E30;
extern u8 D_001D8E34[];
extern void *D_002FCDA4[];
extern void func_003BBDC0(s32, s32);
extern void func_003BC7C0();
extern s32 func_003BE0F0(void);
extern void func_003BE1D8(s32);
extern void func_003BE6C0(void *);
extern void func_003BFC18();
extern void func_003C0010();
__asm__(".extern D_001D8E30, 4");
s32 func_003BFB58(void) {
    D_001DA340_003BFB58[0] = 1.0f;
    *(s32 *)0x001DA338 = 0;
    *(u8 *)0x001DA33C = 0;
    *(u8 *)0x001DA344 = 0;
    *(u8 *)0x001DA345 = 0;
    func_003BBDC0(0, 0);
    func_003BC7C0(4, &D_001D8E30);
    func_003BE068(3, (s32 *)D_001D8E34, D_001D8E30);
    func_003BE1D8(func_003BE0F0());
    func_003BE6C0(func_003BFC18);
    func_003BFC78();
    D_002FCDA4[0] = func_003C0010;
    return 1;
}
/* localdecomp:end func_003BFB58 */

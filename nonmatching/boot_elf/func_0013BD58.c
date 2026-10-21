/* Near miss of func_0013BD58 with its file's own flags: tools/check.py reports 44 diff
   (the US draft it started from: 62).
   What differs: 44 diffs remain. Retail reaches D_1D4A00/D_1D4A04/D_1D4A40/D_1D49C0 through
   `lui`/`%lo` (2 words) but reaches D_001D4DE8/D_001D4E18/D_001D4DA8/D_1D4A00(scalar
   reads)/D_1D4A40(store) through `$gp`; the US matched with `@ps2as`, where Ps2EeAs expands
   the one-word `addiu $rt, D($gp)` small-data address macro into `lui`+`addiu`, so retail's
   addresses are really gcc's cheap 1-word `$gp` form expanded by the assembler. With the
   default assembler (bin/ee-as) a sized scalar is always 1 word `$gp`-relative (gcc emits
   GPREL16 directly), so a 2-word address needs a non-small-data symbol; with unsized...
*/

/* US draft of func_0013BD58 (rac3-uya-decomp func_0013BD58, commit 13cf5c5), names moved to PAL addresses
   where known. Not carried: flags: the US matched it with `@ps2as` (a single-function override). */


/* localdecomp:start func_0013BD58 */
__asm__(".extern D_001D4DE8, 4");
__asm__(".extern D_001D4E18, 4");
__asm__(".extern D_001D4DA8, 4");
extern s32 D_001D4DA8;
extern s32 D_001D4DE8;
extern s32 D_001D4E18;
extern s32 D_1D4A00;
extern s32 D_1D4A40;
extern char D_001D5050[];
extern char D_001D5080[];
extern char D_001D4E98[];
extern void func_0011AF48();
extern void func_0011F698(void *, void *);
extern s32 func_00122A10();
extern s32 func_00122810();
extern s32 func_0013B620(void);
extern void func_0011F0A0(s32);
s32 func_0013BD58(s32 a) {
    D_001D4DA8 = 0;
    if (D_001D4DE8 != 0) {
        if (D_001D4E18 == 0) func_0011AF48(D_001D5050);
        return 0;
    }
    *(u32 *)0x001D4A00 = 0xFFFFFFFF;
    func_0011F698((void *)0x001D4A00, (void *)0x001D4A04);
    D_1D4A40 = a;
    while (func_00122A10((void *)0x001D49C0) != 0) {
        if (D_001D4E18 == 0) func_0011AF48(D_001D4E98);
        func_0013B620();
        func_0011F0A0(0);
    }
    if (func_00122810((void *)0x001D49C0, 0x59, 1, (void *)0x001D4A40, 4, (void *)0x001D4A00, 4, 0, 0) < 0) {
        if (D_001D4E18 == 0) func_0011AF48(D_001D5080);
        D_001D4DA8 = 0x106;
        return 0;
    }
    if ((u32)D_1D4A00 == 0xFFFFFFFF) {
        do {
            func_0011F0A0(0);
        } while (*(volatile u32 *)0x001D4A00 == 0xFFFFFFFF);
    }
    return D_1D4A00;
}
/* localdecomp:end func_0013BD58 */

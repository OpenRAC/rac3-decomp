/* US draft of func_003C2948 (rac3-uya-decomp func_003BD428, commit 13cf5c5), names moved to PAL addresses
   where known. Not carried: flags: the US matched it with `@ps2as` (a single-function override). */


/* localdecomp:start func_003C2948 */
extern int D_001DA4CC;
extern int D_001DA4BC;
extern int D_001DA4C8;
extern int D_001DA4C0;
extern int D_001DA4C4;
__asm__(".extern D_001DA4C4, 4");
extern void func_0038CB78(void *, int, int);

unsigned int func_003C2948(int count, int base) {
    int size;
    register int start __asm__("$3") = base;
    register int end __asm__("$2");
    size = count * 4;
    end = start + size;

    D_001DA4CC = end;
    D_001DA4BC = start;
    D_001DA4C8 = start;
    D_001DA4C0 = 0;
    D_001DA4C4 = 0;
    func_0038CB78((void *)start, 0, size);
    return (D_001DA4CC + 0x3F) & 0xFFFFFFC0;
}
/* localdecomp:end func_003C2948 */

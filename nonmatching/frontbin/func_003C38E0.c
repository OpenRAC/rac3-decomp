/* US draft of func_003C38E0 (rac3-uya-decomp func_003BE3C0, commit 13cf5c5), names moved to PAL addresses
   where known. Not carried: flags: the US matched it with `@ps2as` (a single-function override). */


/* localdecomp:start func_003C38E0 */
extern int D_001DA49C;
extern int D_001DA4A4;
int func_003C38E0(void) {
    unsigned char *current = (unsigned char *)(*(volatile int *)&D_001DA49C);
    unsigned char *end = (unsigned char *)(*(volatile int *)&D_001DA4A4);
    int result = (int)end;

    if (current != end) {
        do {
            result = *(int *)(current + 0x24);
            current += 0x100;
        } while (current != end);
    }
    return result;
}
/* localdecomp:end func_003C38E0 */

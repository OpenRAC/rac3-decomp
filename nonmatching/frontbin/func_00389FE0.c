/* US draft of func_00389FE0 (rac3-uya-decomp func_00385908, commit 13cf5c5), names moved to PAL addresses
   where known. Not carried: flags: the US matched it with `@ps2as` (a single-function override). */


/* localdecomp:start func_00389FE0 */
extern int D_001D9C38_00389FE0;
extern void (*D_001D9C18[])(int);
extern int D_001D9C28[];

void func_00389FE0(void) {
    int index;
    register void (**callbacks)(int) __asm__("$17");
    register int *arguments __asm__("$18");

    index = 0;
    if (D_001D9C38_00389FE0 > 0) {
        arguments = D_001D9C28;
        __asm__ volatile("" : "+r"(arguments));
        callbacks = D_001D9C18;
        do {
            index++;
            (*callbacks)(*arguments);
            callbacks++;
            arguments++;
        } while (index < D_001D9C38_00389FE0);
    }
}
/* localdecomp:end func_00389FE0 */

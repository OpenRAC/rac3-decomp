/* US draft of func_003B6CC8 (rac3-uya-decomp func_003B6BF0, commit 13cf5c5), names moved to PAL addresses
   where known. Not carried: flags: the US matched it with `@ps2as` (a single-function override). */


/* localdecomp:start func_003B6CC8 */
extern unsigned char D_001D5BDC;
extern int D_001D8AB4;
extern int D_001D8A40_g;
__asm__(".extern D_001D8AB4, 4");
__asm__(".extern D_001D8A40_g, 4");
extern void func_0039C1A0(int, int, int);
extern void func_003B6A58(void);
extern void func_003B6AA8(void);
extern void func_003B6B60(void);

void func_003B6CC8(void) {
    register int flag __asm__("$2");
    flag = D_001D5BDC;
    if (flag != 0) {
        func_0039C1A0((int)func_003B6A58, D_001D8AB4, (int)func_003B6AA8);
    } else {
        func_0039C1A0((int)func_003B6A58, D_001D8AB4, (int)func_003B6B60);
    }
    D_001D8A40_g = 1;
}
/* localdecomp:end func_003B6CC8 */

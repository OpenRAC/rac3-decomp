/* Near miss of func_003BB968 with its file's own flags: tools/check.py reports 30 diff
   (the version it replaces: 31).
*/

/* func_003BB968: PAL retail bytes, compiled with the file's own flags
   (-mvu0-use-vf0-vf2 -O2 -G8 -fopt-stack -mno-check-zero-division, split addresses).

   The US draft used D_001DA1F4[i - 1]; with split addresses that makes gcc
   split the symbol address (lui $tmp, %hi; addiu $ptr, $tmp, %lo).  Retail
   materialises the address in one register (lui $s1, %hi; addiu $s1, $s1, %lo),
   so the base is taken from a pointer variable instead, and the element is
   walked with p++ rather than an index.  The short do-while loop's padding nops
   are the assembler's (tools/asm_filter.py), not inline asm, so they are left
   to the toolchain. */

extern void func_0013CA20(void);
extern void func_0013BF00(s32);
extern void func_0013CA28(void);
extern s32 func_0013B620(void);
extern void func_0013BED0(void);
extern u32 D_001D8CE0;
extern s32 D_001DA1F4[];
extern s32 D_001D4B4C[];

void func_003BB968(void) {
    s32 r;
    s32 *p;
    u32 i;

    func_0013CA20();
    p = D_001DA1F4;
    for (i = 1; i < D_001D8CE0; i++) {
        func_0013BF00(*p);
        p++;
    }
    func_0013CA28();
    do {
        r = func_0013B620();
    } while (r);
    func_0013BED0();
    D_001D4B4C[0] = 0;
}

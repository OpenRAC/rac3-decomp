/* Near miss of func_003B6910 with its file's own flags: tools/check.py reports 16 diff
   (the version it replaces: 23).
   What differs: Retail reads the flag byte as `lui $v0,0x1d` + `lbu $v0,0x5bdc($v0)` (one
   register, absolute, not $gp small data). With the file's flags (-mvu0-use-vf0-vf2 -O2 -G8
   -fopt-stack -mno-check-zero-division) a declared global is $gp-relative (small data) -> `lbu
   $v0,-0x6cd4($gp)`; an unsized-array alias gives the split form `lui $v0,0x1d` + `lbu
   $v1,0x5bdc($v0)` (4 diffs: the %hi is hoisted above the prologue and the load lands in $v1
   instead of $v0). A byte at a constant address (`*(unsigned char *)0x001D5BDC`) gives the
   exact retail register form `lui $v0,0x1d` + `lbu $v0,0x5bdc($v0)`, but...
*/

/* PAL candidate for func_003B6910 (frontbin, src/frontbin/3B6548.c).

   Retail reads the flag byte with lui/lbu, so it must not be small data
   ($gp-relative).  A byte at a constant address keeps that form.  */

extern int D_001D8AB4;
extern int D_001D8A40_g;
extern void func_0039BDC0(int, int, int);
extern void func_003B66A0(void);
extern void func_003B66F0(void);
extern void func_003B67A8(void);

void func_003B6910(void) {
    unsigned char flag = *(unsigned char *)0x001D5BDC;
    if (flag != 0) {
        func_0039BDC0((int)func_003B66A0, D_001D8AB4, (int)func_003B66F0);
    } else {
        func_0039BDC0((int)func_003B66A0, D_001D8AB4, (int)func_003B67A8);
    }
    D_001D8A40_g = 1;
}

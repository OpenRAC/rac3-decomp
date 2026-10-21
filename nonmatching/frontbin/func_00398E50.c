/* Near miss of func_00398E50 with its file's own flags: tools/check.py reports 151 diff
   (the version it replaces: 163).
   What differs: Loop still reversed: the loop pass rewrites the count-up loop into a count-
   down one (`addiu $a1,$zero,4` / `addiu $a1,$a1,-1` / `bgez`) where retail keeps `addiu
   $a2,$a2,1` / `slti $v1,$a2,5` / `bnez $v1`; that extra counter also shifts the register
   allocation (frame 0x48 with s0-s6+ra instead of 0x40 with s0-s5+ra, lui/lo high halves in
   $s5/$a0/$v1 instead of retail's $at). Everything else now matches: the globals D_001D4B50,
   D_001D9EA0, D_001D9EA4, D_001D9EA8, D_001D9EAC and D_001D9EB0 reach retail through lui/lo,
   so they are declared as unsized arrays (`D_..._00398E50_u`, an unsized...
*/

/* PAL candidate for func_00398E50 (frontbin, src/frontbin/397D48.c).

   Two things differ from the US draft:

   - Retail reaches D_001D4B50, D_001D9EA0, D_001D9EA4, D_001D9EA8, D_001D9EAC
     and D_001D9EB0 through lui/lo, never through $gp, so they are declared as
     unsized arrays (an unsized array is never small data).  The names carry the
     function address, as the file's other per-function aliases do.
   - The loop is written as a do/while, which keeps the shape retail has (the
     counter is incremented in the body and tested at the bottom).  The loop
     pass still reverses the counter into a count-down loop; see RESULTS.md.  */

typedef struct { s32 off; s32 size; } E_94060;
typedef struct { u8 p0[0x18]; s32 f18; s32 f1C; E_94060 e[5]; } B_94060;

extern B_94060 *D_001D4B50_00398E50_u[];
extern int D_001D9EA0_00398E50_u[];
extern s32 D_001D9EA4_00398E50_u[];
extern s32 D_001D9EA8_00398E50_u[];
extern s32 D_001D9EAC_00398E50_u[];
extern s32 D_001D9EB0_00398E50_u[];

/* localdecomp:start func_00398E50 */
void func_00398E50(void) {
    B_94060 *b;
    s32 *h;
    s32 *q;
    s32 i;
    s32 r, x, t;
    b = D_001D4B50_00398E50_u[0];
    i = 0;
    do {
        D_001D9EC8[i] = (b->e[i].size + 0x3F) & 0xFFFFFFC0;
        i++;
    } while (i < 5);
    r = (b->f1C + 0x3F) & 0xFFFFFFC0;
    q = (s32 *)D_00227580;
    h = (s32 *)func_003932C0(r, 0, D_001D5F50, 0x39E);
    func_0038CD28(h, (void *)(b->f18 + (s32)b), r);
    x = q[4] + 0x30000;
    D_001D9EA0_00398E50_u[0] = (int)h;
    D_001D9EA4_00398E50_u[0] = (s32)h + h[1];
    D_001D9EA8_00398E50_u[0] = (s32)h + h[2];
    D_001D9EB0_00398E50_u[0] = (s32)h + h[3];
    D_001D9EAC_00398E50_u[0] = (s32)h + h[4];
    if (h[0x15]) {
        u32 s = (u32)((b->e[0].size + 0x3F) & 0xFFFFFFC0) >> 4;
        func_003990F0(0, x);
        *(s32 *)(D_001D9EA0_00398E50_u[0] + 0x94) = func_003A8678((void *)(b->e[0].off + (s32)b), s, s, D_001D5F60);
        func_00393168(0, x, 1);
    }
    if (*(s32 *)(D_001D9EA0_00398E50_u[0] + 0x58)) {
        t = func_003932C0(*(s32 *)(D_001D9EA0_00398E50_u[0] + 0x58), 0, D_001D5F50, 0x3CE);
        func_003990F0(1, t);
        func_11F0A0(0);
        func_00392FD0(1, t);
    }
    if (*(s32 *)(D_001D9EA0_00398E50_u[0] + 0x5C)) {
        s32 s = ((b->e[2].size + 0x3F) & 0xFFFFFFC0);
        s = (u32)s >> 4;
        *(s32 *)(D_001D9EA0_00398E50_u[0] + 0x9C) = func_003A8678((void *)(b->e[2].off + (s32)b), s, s, D_001D5F70);
    }
    if (*(s32 *)(D_001D9EA0_00398E50_u[0] + 0x60)) {
        s32 s = ((b->e[3].size + 0x3F) & 0xFFFFFFC0);
        s = (u32)s >> 4;
        *(s32 *)(D_001D9EA0_00398E50_u[0] + 0xA0) = func_003A8678((void *)(b->e[3].off + (s32)b), s, s, D_001D5F80);
    }
    if (*(s32 *)(D_001D9EA0_00398E50_u[0] + 0x64)) {
        s32 s = ((b->e[4].size + 0x3F) & 0xFFFFFFC0);
        s = (u32)s >> 4;
        *(s32 *)(D_001D9EA0_00398E50_u[0] + 0xA4) = func_003A8678((void *)(b->e[4].off + (s32)b), s, s, D_001D5F90);
    }
    func_00393138();
}
/* localdecomp:end func_00398E50 */

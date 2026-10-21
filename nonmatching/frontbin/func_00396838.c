/* Near miss of func_00396838 with its file's own flags: tools/check.py reports 6 diff
   (the version it replaces: 73).
   What differs: 6 of 75 words differ, all in one place: the loop table base address is built
   as `lui $s0,0x33 / addiu $s0,$s0,0x1ae0` (one register) instead of retail's `lui $v1,0x33 /
   addiu $s0,$v1,0x1ae0` (high half in a scratch register), and because of that the scheduled
   `ori $v0,$v0,0xfff0` (constant 0xFFFFF0) and `addiu $s1,$zero,0xc` (loop counter) land in a
   different order; everything else matches byte for byte (globals at PAL 0x001D9xxx reached
   through lui need unsized-array declarations, one alias per use, and the two same-address
   globals D_001D9DF8/D_001D9DFC need both a lui alias and the...
*/

/* US draft of func_00396838 (rac3-uya-decomp func_00391FD8, commit 13cf5c5), names moved to PAL addresses
   where known. Not carried: flags: the US matched it with `@ps2as` and without `-mno-split-addresses` (a single-function override). */


/* localdecomp:start func_00396838 */
typedef struct { u8 p0[0x18]; void (*f18)(void *); u8 p1c[0x74]; } S_391FD8;
extern S_391FD8 D_00331AE0_00396838[];
/* Retail reaches these through lui (they are not small data), so they are
   unsized arrays.  Every use gets its own name: the compiler then builds the
   address separately for each of them, like retail does. */
extern s32 D_001D9EC0_1[];
extern s32 D_001D9EC0_2[];
extern s32 D_001D9BDC_1[];
extern s32 D_001D9E94_1[];
extern s32 D_001D9DF8_1[];
extern s32 D_001D9DF8_2[];
extern s32 D_001D9DF8_3[];
extern s32 D_001D9DF8_4[];
extern s32 D_001D9DFC_1[];
extern s32 D_001D9DFC_2[];
extern s32 D_001D9E00_1[];
/* small data, reached through $gp */
extern s32 D_001D9DF8;
extern s32 D_001D9DFC;
extern s32 D_001D5B94;
void func_00396838(void) {
    S_391FD8 *p;
    s32 i;
    s32 z;
    if (*D_001D9EC0_1 || *D_001D9BDC_1) {
        *D_001D9EC0_2 = 0;
        return;
    }
    *D_001D9E94_1 = 0xFFFFF0;
    p = D_00331AE0_00396838;
    for (i = 12; i >= 0; i--) {
        if (p->f18) p->f18(p);
        p++;
    }
    if (*D_001D9DF8_1 || *D_001D9DFC_1) {
        if (D_001D5B94 == 0) {
            z = D_001D9DFC;
            if (*D_001D9DF8_1) {
                D_001D9DFC = z + 0x12;
                if (z + 0x12 > 0x80) D_001D9DFC = 0x80;
            } else {
                D_001D9DFC = z - 0x12;
                if (z - 0x12 < 0) *D_001D9DFC_2 = 0;
            }
            if (*D_001D9DF8_2) *D_001D9DF8_3 = *D_001D9DF8_2 - 1;
            if (*D_001D9DF8_4 == 1000) D_001D9DF8 = 0;
            return;
        }
    }
    *D_001D9E00_1 = 100;
}
/* localdecomp:end func_00396838 */

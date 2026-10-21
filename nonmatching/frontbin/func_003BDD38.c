/* US draft of func_003BDD38 (rac3-uya-decomp func_003B8840, commit 13cf5c5), names moved to PAL addresses
   where known. Not carried: flags: the US matched it with `@ps2as` (a single-function override). */


/* localdecomp:start func_003BDD38 */
__asm__(".extern D_001D8CF8, 4");
__asm__(".extern D_001D8CFC, 4");
typedef struct { u8 pad[0x64]; s32 f64; } S_16C580_3B8840;
extern S_16C580_3B8840 D_16C580_003BDD38;
extern u8 D_001DA290_003BDD38[1];
extern s32 D_001DA268_003BDD38[2];
extern s32 func_00382468(s32);
extern void func_003BDD08(void);
s32 func_003BDD38(void) {
    s32 i;
    s32 r;
    s32 cur;
    u8 *used;
    used = D_001DA290_003BDD38;
    for (i = 0; i < D_001D8CF8; i++) {
        if (i != D_001D8CFC && *(u8 *)(i + (s32)used) == 0) break;
    }
    if (i == D_001D8CF8) func_003BDD08();
    cur = D_16C580_003BDD38.f64;
    do {
        r = func_00382468(D_001D8CF8);
    } while (r == cur || *(u8 *)(r + (s32)used) != 0);
    do {
        *(u8 *)(r + (s32)used) = 1;
        return D_001DA268_003BDD38[r];
    } while (0);
}
/* localdecomp:end func_003BDD38 */

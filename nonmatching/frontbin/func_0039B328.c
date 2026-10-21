/* US draft of func_0039B328 (rac3-uya-decomp func_00396538, commit 13cf5c5), names moved to PAL addresses
   where known. Not carried: flags: the US matched it with `@ps2as` (a single-function override). */


/* localdecomp:start func_0039B328 */
typedef struct { u32 b0:11; u32 f11:1; u32 rest:20; } S_396538;
extern s32 D_00142430_0039B328[];
extern s32 D_001D4CE8_0039B328;
extern union { s32 i; S_396538 b; } D_001D4CEC_0039B328;
void func_0039B328(void) {
    s32 *p = D_00142430_0039B328;
    if (p[0x15C/4] == 2 && p[0x164/4] < 0) {
        p[0x164/4] = 7;
        p[4] = 0;
p[0x168/4] = 0;
        D_001D4CE8_0039B328 = 0xD;
        D_001D4CEC_0039B328.b.f11 = 0;
    }
}
/* localdecomp:end func_0039B328 */

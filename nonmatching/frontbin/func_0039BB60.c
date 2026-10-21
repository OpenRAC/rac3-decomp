/* US draft of func_0039BB60 (rac3-uya-decomp func_00396D70, commit 13cf5c5), names moved to PAL addresses
   where known. Not carried: flags: the US matched it with `@ps2as` (a single-function override). */


/* localdecomp:start func_0039BB60 */
typedef struct { u32 b0:5; u32 f5:1; u32 b6:7; u32 f13:1; u32 rest:18; } S_396D70;
extern s32 D_00142438[];
extern s32 D_001D4CE8_0039BB60;
extern union { s32 i; S_396D70 b; } D_001D4CEC_0039BB60;
void func_0039BB60(void) {
    if (D_00142438[0] != 2) { D_001D4CE8_0039BB60 = 4; return; }
    if (D_001D4CEC_0039BB60.i & 0x2020) {
        D_001D4CE8_0039BB60 = 7;
        D_001D4CEC_0039BB60.b.f5 = 0;
        D_001D4CEC_0039BB60.b.f13 = 0;
    }
}
/* localdecomp:end func_0039BB60 */

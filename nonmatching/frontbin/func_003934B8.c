/* Near miss of func_003934B8 with its file's own flags: tools/check.py reports 3 diff
   (the version it replaces: 8).
   What differs: 3 words differ, all in the materialization of &D_00331AE0: gcc under this
   file's `-mno-split-addresses` emits `lui $v1,0x33; addiu $v1,$v1,0x1ae0` (hi and lo in one
   register), retail has the split form `lui $v0,0x33; ... addiu $v1,$v0,0x1ae0` (hi in $v0,
   address in $v1, scheduled around the `sd $ra`); everything else (peel, IV step 0x90, member
   offset 0x64, the 7-argument call, the returns) is byte-identical.
*/

/* US draft of func_003934B8 (rac3-uya-decomp func_0038EC80, commit 13cf5c5), names moved to PAL addresses
   where known. Not carried: flags: the US matched it with without `-mno-split-addresses` (a single-function override). */


/* localdecomp:start func_003934B8 */
typedef struct { s32 pad0; s32 f4; s32 pad8[7]; s32 f24; s32 pad28[15]; s32 id; s32 f68; s32 pad6C[9]; } S_38ED78;
extern S_38ED78 D_00331AE0[];
extern void func_00393348();
s32 func_003934B8(s32 id) {
    s32 i;
    S_38ED78 *b = D_00331AE0;
    for (i = 0; i < 13; i++) {
        if (b[i].id == id) break;
    }
    if (i < 13) {
        func_00393348(i, 0xFFFF, 0, 0, 0, 0, 0);
        return 1;
    }
    return 0;
}
/* localdecomp:end func_003934B8 */

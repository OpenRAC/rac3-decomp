/* Near miss of func_003F08E0 with its file's own flags: tools/check.py reports 5 diff
   (the version it replaces: 38).
   What differs: Only the materialization of &D_001DA938 differs: retail `lui $v1,
   %hi(D_001DA938)` (high half in a scratch, computed at the top) + `addiu $a0, $v1,
   %lo(D_001DA938)` (low half added into $a0) — the split-address form; ours `lui $a0,
   %hi(D_001DA938)` + `addiu $a0, $a0, %lo(D_001DA938)` — the whole address in one register,
   which is what `-mno-split-addresses` (this file's flag) makes gcc emit; every other
   instruction now matches.
*/

/* US draft of func_003F08E0 (rac3-uya-decomp func_003EB358, commit 13cf5c5), names moved to PAL addresses
   where known. Not carried: flags: the US matched it with `@ps2as` and without `-mno-split-addresses` (a single-function override). */


/* localdecomp:start func_003F08E0 */
s32 *func_003E6C08(s32 *);                  /* extern */
void **func_003E6CC0(s32 *, s32);           /* extern */
void func_003F2380_003F08E0(void *);
extern u8 D_001D9670_003F08E0;
extern u8 D_001D97C8;
extern char D_001D9670[];
/* Retail reaches D_001D97C8 through lui/addiu, so it must not be small data:
   an unsized array is never small data (docs/wiki/Matching-Patterns.md). */
extern u8 D_001D97C8_003F08E0[];
typedef struct { u8 pad0[0x4]; s32 f4; } S_001DA9B8_003EB358;
extern S_001DA9B8_003EB358 D_001DA938[];

void func_003F08E0(void *arg0, s32 arg1) {
    s32 *var_v0;
    void **temp_v0;

    (*(s32 **)((u8 *)(arg0) + 8)) = (s32 *)&D_001D97C8_003F08E0;
    if (D_001DA938->f4 != 0) {
        var_v0 = (s32 *)D_001DA938;
    } else {
        var_v0 = func_003E6C08((s32 *)D_001DA938);
    }
    temp_v0 = func_003E6CC0(var_v0, 1);
    if (temp_v0 != 0) {
        (*(s32 (**)(void **, s32))((u8 *)(*temp_v0) + 0xC))(temp_v0, (*(s32 *)((u8 *)(arg0) + 0x2C)));
        (*(s32 *)((u8 *)(arg0) + 0x2C)) = 0;
    }
    (*(s32 **)((u8 *)(arg0) + 8)) = (s32 *)D_001D9670;
    if (arg1 & 1) {
        func_003F2380_003F08E0(arg0);
    }
}
/* localdecomp:end func_003F08E0 */

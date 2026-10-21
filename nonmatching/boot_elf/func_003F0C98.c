/* Near miss of func_003F0C98 with its file's own flags: tools/check.py reports 5 diff
   (the version it replaces: 38).
   What differs: D_001D97C8 and D_001D9670 now match (unsized-array declarations give retail's
   lui/addiu instead of $gp). Remaining: D_001DA938 - retail forms its address as `lui $v1,
   0x1e` + `addiu $a0, $v1, -0x56c8` (high half in a scratch register), the file's no-split
   mode emits `lui $a0, 0x1e` + `addiu $a0, $a0, -0x56c8` (same register).
*/

/* Candidate for func_003F0C98 (PAL retail bytes, file flags:
   -mvu0-use-vf0-vf2 -O2 -G8 -fopt-stack -mno-check-zero-division -mno-split-addresses)

   Notes:
   - Retail reaches D_001D97C8 and D_001D9670 with lui/addiu (not through $gp),
     so both are declared unsized (an unsized array is never small data).
   - Retail reaches D_001DA938 with the high half in a scratch register and the
     low half added to $a0, which is how the compiler forms a literal address
     in no-split mode.
*/

/* localdecomp:start func_003F0C98 */
s32 *func_003E6FC0(s32 *);                  /* extern */
void **func_003E7078(s32 *, s32);           /* extern */
void func_003F2738_003F0C98(void *);
extern u8 D_001D9670_003F0C98;
extern char D_001D9670[];
extern u8 D_001D97C8;
extern u8 D_001D97C8_003F0C98[];
extern s32 D_001D9790[];
typedef struct { u8 pad0[0x4]; s32 f4; } S_001DA9B8_003EB358;
extern S_001DA9B8_003EB358 D_001DA938[];

void func_003F0C98(void *arg0, s32 arg1) {
    s32 *var_v0;
    void **temp_v0;
    S_001DA9B8_003EB358 *tbl;

    (*(s32 **)((u8 *)(arg0) + 8)) = (s32 *)D_001D97C8_003F0C98;
    tbl = (S_001DA9B8_003EB358 *)((u8 *)D_001D9790 + 0x11A8);
    if (tbl->f4 != 0) {
        var_v0 = (s32 *)tbl;
    } else {
        var_v0 = func_003E6FC0((s32 *)tbl);
    }
    temp_v0 = func_003E7078(var_v0, 1);
    if (temp_v0 != 0) {
        (*(s32 (**)(void **, s32))((u8 *)(*temp_v0) + 0xC))(temp_v0, (*(s32 *)((u8 *)(arg0) + 0x2C)));
        (*(s32 *)((u8 *)(arg0) + 0x2C)) = 0;
    }
    (*(s32 **)((u8 *)(arg0) + 8)) = (s32 *)D_001D9670;
    if (arg1 & 1) {
        func_003F2738_003F0C98(arg0);
    }
}
/* localdecomp:end func_003F0C98 */

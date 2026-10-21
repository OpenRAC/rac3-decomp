/* Near miss of func_003B2A68 with its file's own flags: tools/check.py reports 3 diff
   (the version it replaces: 17).
*/

/* US draft of func_003B2A68 (rac3-uya-decomp func_003B28C8, commit 13cf5c5), names moved to PAL addresses
   where known. Not carried: flags: the US matched it with `@ps2as` (a single-function override). */


/* localdecomp:start func_003B2A68 */
typedef struct { char c[4]; } S4_3AD108;
typedef struct { u8 p0[0x48]; u8 p48[0x60]; s32 fA8; } S_3AD108;
extern S4_3AD108 D_001D8830[];
extern u8 *D_001DA0B4[];
extern void func_003B2958();
extern s32 func_003B2E80();
extern void func_003B2978(u8 *, s32);
extern void func_003B2408();
s32 func_003B2A68(S_3AD108 *a) {
    S4_3AD108 buf;
    s32 r0;
    s32 r1;
    s32 r2;
    s32 r3;
    s32 v;
    u8 *p;
    buf = D_001D8830[0];
    func_003B2958(a, &r0, &r1, &r2, &r3);
    if (r1 + r3 < 4) return 0;
    v = func_003B2E80((r0 & 0xFFFFFFF) | 0x20000000, r1, (r2 & 0xFFFFFFF) | 0x20000000, r3, &buf, 4, 0, 0);
    p = D_001DA0B4[0];
    func_003B2978(p, v);
    func_003B2408((u8 *)a + 0x48);
    if (a->fA8 == 0) {
        a->fA8 = 2;
    }
    return 1;
}
/* localdecomp:end func_003B2A68 */

/* US draft of func_003AF498 (rac3-uya-decomp func_003A9EF0, commit 13cf5c5), names moved to PAL addresses
   where known. Not carried: flags: the US matched it with `@ps2as` and without `-mno-split-addresses` (a single-function override). */


/* localdecomp:start func_003AF498 */
typedef s32 (*FN_A9EF0)();
typedef struct { FN_A9EF0 a; s32 b; } E_A9EF0;
typedef struct { u8 pad[0x24DD0]; void (*cb24DD0)(); u8 padA[0x14]; FN_A9EF0 cb24DE8; u8 padB[4]; E_A9EF0 e1[4]; E_A9EF0 e2[3]; } P_A9EF0;
extern P_A9EF0 *D_001D5C78_003AF498;
extern s32 D_001D9EC0;
extern s32 D_001D5B94;
extern s32 func_003E13F0();
extern void func_003AF3A8();
void func_003AF498(void) {
    s32 r, i, t;
    E_A9EF0 *e;
    if (D_001D9EC0 == 0) {
        if (D_001D5C78_003AF498 != 0) {
            if (D_001D5C78_003AF498->cb24DE8 != 0) {
                if (D_001D5C78_003AF498->cb24DE8() != 0) return;
            }
            r = 0;
            for (i = 0; i < 4; i++) {
                if (D_001D5C78_003AF498->e1[i].a != 0) {
                    E_A9EF0 *e2 = (E_A9EF0 *)(i * 8 + (s32)D_001D5C78_003AF498 + 0x24DF0);
                    r |= e2->a();
                }
            }
            if (r != 0) return;
            for (i = 0; i < 3; i++) {
                if (D_001D5C78_003AF498->e2[i].a != 0) {
                    E_A9EF0 *e3 = (E_A9EF0 *)(i * 8 + (s32)D_001D5C78_003AF498 + 0x24E10);
                    r |= e3->a();
                }
            }
            if (r != 0) return;
        }
        t = D_001D5B94;
        if (t != 0 && t != 5 && t == 4) {
            if (func_003E13F0() != 7) return;
        }
        if (D_001D5C78_003AF498 != 0) {
            D_001D5C78_003AF498->cb24DD0();
            func_003AF3A8();
        }
    }
}
/* localdecomp:end func_003AF498 */

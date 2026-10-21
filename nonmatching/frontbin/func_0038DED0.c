/* US draft of func_0038DED0 (rac3-uya-decomp func_003896E8, commit 13cf5c5), names moved to PAL addresses
   where known. Not carried: flags: the US matched it with `@ps2as` and without `-mno-split-addresses` (a single-function override). */

/* localdecomp:start func_0038DED0 */
__asm__(".extern D_001D5B34, 4");
__asm__(".extern D_001D5B38, 4");
__asm__(".extern D_001D5B3C, 4");
__asm__(".extern D_001D5B30, 4");
__asm__(".extern D_001D55E8, 4");
typedef struct { s16 x; s16 y; } P_3896E8;
typedef struct {
    u8 n0; u8 n1; u8 p2[0x2E];
    u8 k30[0x10];
    u8 k40[0x10];
    P_3896E8 pt[0x10];
    s32 o90[0x10];
    s32 oD0[0x10];
} T_3896E8;
extern T_3896E8 *D_001D55D0_0038DED0[2];
extern s32 D_001D9BC8_0038DED0;
extern s32 D_001D5B34;
extern u8 *D_001D5B38;
extern u8 *D_001D5B3C;
extern s32 D_001D5B30;
extern s32 D_001D55E8;
extern s32 D_0031CFD0_0038DED0[][16];
extern s32 D_0031CF50_0038DED0[][16];
extern s32 func_00389C48(s32 a, s32 b);
extern s32 func_00389B10(s32, s32, s32, s32);
void func_0038DED0(void) {
    s32 i, j;
    s32 o = D_001D5B34;
    s32 v = D_001D9BC8_0038DED0;
    if (o == v && D_001D5B38 && D_001D5B3C && D_001D5B30 == 0) return;
    D_001D5B34 = v;
    D_001D5B30 = 0;
    for (i = 0; i < 2; i++) {
        for (j = 0; j < D_001D55D0_0038DED0[i]->n0; j++) {
            D_0031CFD0_0038DED0[i][j] = func_00389C48((s32)D_001D55D0_0038DED0[i] + D_001D55D0_0038DED0[i]->o90[j],
                (D_001D55D0_0038DED0[i]->k30[j] == 0x14) ? 0x14 : 0x13);
        }
        for (j = 0; j < D_001D55D0_0038DED0[i]->n1; j++) {
            D_0031CF50_0038DED0[i][j] = func_00389B10((s32)D_001D55D0_0038DED0[i] + D_001D55D0_0038DED0[i]->oD0[j],
                D_001D55D0_0038DED0[i]->pt[j].x, D_001D55D0_0038DED0[i]->pt[j].y,
                (D_001D55D0_0038DED0[i]->k40[j] == 0x14) ? 0x14 : 0x13);
        }
    }
    func_0038E150(D_001D55E8);
}
/* localdecomp:end func_0038DED0 */

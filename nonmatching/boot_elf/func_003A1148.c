/* US draft of func_003A1148 (rac3-uya-decomp func_003A1008, commit 13cf5c5), names moved to PAL addresses
   where known. Not carried: flags: the US matched it with `@ps2as` (a single-function override). */


/* localdecomp:start func_003A1148 */
extern s32 D_001D5B94_003A1148;
extern s32 D_001D5B90_003A1148;
extern s32 D_001D5B8C;
extern s32 D_001D6D98;
extern s32 D_001D6D9C_003A1148;
extern s32 D_001D6DA0_003A1148;
extern u8 *D_001D6DA8_003A1148;
extern f32 D_002259B0[];
extern void func_003A8E10(void);
extern void func_00382BF0(s32, s32, s32, f32, f32, f32, f32);
extern void func_003877A0();
extern void func_003A8C70();
extern void func_003B35D0();
void func_003A1148(void) {
    s32 a = D_001D5B94_003A1148;
    s32 t;
    u8 *v;
    s32 s;
    D_001D5B8C = a;
    if (D_001D5B90_003A1148 == -2) return;
    t = D_001D6D98;
    if (t > 0) {
        D_001D6D98 = t - 1;
        return;
    }
    switch (a) {
    case 1:
        func_003A8E10();
        D_002259B0[0] = 0.62f;
        func_00382BF0(0, 0, 3, 1.1100293f, 0.005f, 0.2f, 0.0f);
        func_003877A0();
        break;
    case 0:
    case 2:
    case 4:
    case 18:
        break;
    }
    switch (D_001D5B90_003A1148) {
    case 1:
        func_003A8C70(D_001D6DA0_003A1148);
        v = D_001D6DA8_003A1148;
        break;
    case 18:
        func_003B35D0(D_001D6D9C_003A1148);
    case 0:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
    case 10:
    case 11:
    case 12:
    case 13:
    case 14:
    case 15:
    case 16:
    case 17:
    default:
        v = D_001D6DA8_003A1148;
        break;
    }
    if (v) *v = 1;
    s = D_001D5B90_003A1148;
    D_001D5B90_003A1148 = -2;
    D_001D5B94_003A1148 = s;
    D_001D6DA8_003A1148 = 0;
}
/* localdecomp:end func_003A1148 */

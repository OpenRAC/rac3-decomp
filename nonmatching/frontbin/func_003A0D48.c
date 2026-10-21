/* US draft of func_003A0D48 (rac3-uya-decomp func_0039BD48, commit 13cf5c5), names moved to PAL addresses
   where known. Not carried: flags: the US matched it with `@ps2as` (a single-function override). */


/* localdecomp:start func_003A0D48 */
extern s32 D_001D5B94_003A0D48;
extern s32 D_001D5B90_003A0D48;
extern s32 D_001D5B8C;
extern s32 D_001D6D98;
extern s32 D_001D6D9C_003A0D48;
extern s32 D_001D6DA0_003A0D48;
extern u8 *D_001D6DA8_003A0D48;
extern f32 D_002259B0[];
extern void func_003A8A58(void);
extern void func_00382810(s32, s32, s32, f32, f32, f32, f32);
extern void func_003873C0();
extern void func_003A88B8();
extern void func_003B3218();
void func_003A0D48(void) {
    s32 a = D_001D5B94_003A0D48;
    s32 t;
    u8 *v;
    s32 s;
    D_001D5B8C = a;
    if (D_001D5B90_003A0D48 == -2) return;
    t = D_001D6D98;
    if (t > 0) {
        D_001D6D98 = t - 1;
        return;
    }
    switch (a) {
    case 1:
        func_003A8A58();
        D_002259B0[0] = 0.62f;
        func_00382810(0, 0, 3, 1.1100293f, 0.005f, 0.2f, 0.0f);
        func_003873C0();
        break;
    case 0:
    case 2:
    case 4:
    case 18:
        break;
    }
    switch (D_001D5B90_003A0D48) {
    case 1:
        func_003A88B8(D_001D6DA0_003A0D48);
        v = D_001D6DA8_003A0D48;
        break;
    case 18:
        func_003B3218(D_001D6D9C_003A0D48);
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
        v = D_001D6DA8_003A0D48;
        break;
    }
    if (v) *v = 1;
    s = D_001D5B90_003A0D48;
    D_001D5B90_003A0D48 = -2;
    D_001D5B94_003A0D48 = s;
    D_001D6DA8_003A0D48 = 0;
}
/* localdecomp:end func_003A0D48 */

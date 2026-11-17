/* PAL near miss (b9-t2): about 6 words differ in kind, the rest is the shift they cause: retail recomputes the address of D_L13_001E1B20 (lui/addiu into $s0) after the call where we keep it in a register from the top (move $s0,$a1), and its last loop is a branchy if/else for the f13 argument (bne; mtc1 zero; b; nop; lwc1) where we get a bnel; the search loop and the $gp load in the delay slot match */
#include "common.h"
#include "vu0.h"
/* localdecomp:start func_L13_003C54F8 */
__asm__(".extern D_L13_001DEB58, 4");
extern f32 D_L13_001DEB58;
extern f32 D_L13_001E1B20[];
extern s32 D_L13_001E1B18;
extern f32 func_003824E0(f32, f32);
extern f32 func_003C4088(f32, f32, f32);
extern void func_0038CC88(void *, void *, s32);
extern u8 D_001426E0[];
extern u8 D_001D54C0[];

void func_L13_003C54F8(u8 *self) {
    f32 buf[5];
    u8 *o;
    u8 *p;
    f32 sum;
    f32 t;
    f32 *s;
    s32 i;

    o = *(u8 **)(self + 0x68);
    func_0038CC88(buf, D_L13_001E1B20, 0x14);
    if (*(s32 *)(o + 0x254) != 0) {
        buf[4] = 0.0f;
    }
    p = D_001426E0;
    if (p[0x81] < 0x7D) {
        p[0x81]++;
    }
    if (p[0x81] < 0x4B) {
        buf[2] = 0.0f;
    } else if (D_L13_001E1B18 == 0 && D_001D54C0[0] == 0) {
        buf[2] = 100.0f;
    }
    sum = 0.0f;
    for (i = 0; i < 5; i++) {
        sum += buf[i];
    }
    t = func_003824E0(0.0f, sum) - buf[0];
    i = 0;
    if (!(t < 0.0f)) {
        do {
            i++;
            if (i >= 4) {
                break;
            }
            t -= buf[i];
        } while (!(t < 0.0f));
    }
    *(s32 *)(o + 0x240) = i;
    if (i == 2) {
        D_L13_001E1B18 = 1;
    }
    s = &D_L13_001DEB58;
    for (i = 0; i < 5; i++) {
        if (i == *(s32 *)(o + 0x240)) {
            t = 0.0f;
        } else {
            t = s[i];
        }
        D_L13_001E1B20[i] = func_003C4088(D_L13_001E1B20[i], t, 0.5f);
    }
}
/* localdecomp:end func_L13_003C54F8 */

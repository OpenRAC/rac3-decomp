#include "common.h"

typedef struct {
    u8 pad0[4848];
    u8 *p4848;
    u8 *p4852;
    u8 pad1[4884 - 4856];
    s32 mode;
    u8 pad2[9676 - 4888];
    s32 action;
    s32 state;
} S_0050F4C0;

extern s32 func_L01_0050B678(s32, s32 *, s32 *);
extern void fe_func_003C3A10(void *, s32, s32, s32);
typedef struct {
    s16 h;
    u8 b;
    u8 pad;
} E_0050B448;
extern s32 func_L01_004E5470(s32);
/* localdecomp:start func_L01_0050B518 */
extern S_0050F4C0 D_1A4BE0;
extern s32 func_L01_0050B678(s32, s32 *, s32 *);
extern s32 func_L01_0050B448(s32, s32 *);
extern s32 func_L01_004E5470(s32);
extern void func_003BE4F0(void *, s32, s32, s32);

/* hero_back_follow_anim: keeps the hero's two back-carried mobys playing the right animation:
 * blends both to the one picked by hero_back_pick, or to animation 1 with a speed that depends on
 * the hero state, only when the mode is 2. */
void func_L01_0050B518(s32 a0, s32 a1, f32 f12)
{
    u8 *p1;
    u8 *p2;
    s32 out0;
    s32 out1;
    s32 flag;
    s32 s0;
    f32 f20 = f12;

    if (D_1A4BE0.mode != 2)
        return;
    p1 = D_1A4BE0.p4848;
    p2 = D_1A4BE0.p4852;
    if (p1 == 0)
        return;
    if (p2 == 0)
        return;

    if (func_L01_0050B678(a0, &out0, &out1) != 0 && a0 != 0) {
        if (p1[0x43] != out0) {
            s0 = (s32)f20;
            func_003BE4F0(p1, out0, a1, s0);
            func_003BE4F0(p2, out1, a1, s0);
        }
        return;
    }

    flag = 1;
    if (D_1A4BE0.action == 0) {
        if (func_L01_0050B448(p1[0x43], &a0) != 0 && a0 == 0)
            flag = 0;
    }
    if (flag == 0)
        return;

    s0 = 7;
    if (D_1A4BE0.state == 8) {
        if (func_L01_004E5470(3) == 2)
            s0 = 0x13;
    }
    if (p1[0x43] != 1)
        func_003BE4F0(p1, 1, 0, s0);
    if (p2[0x43] != 1)
        func_003BE4F0(p2, 1, 0, s0);
}
/* localdecomp:end func_L01_0050B518 */

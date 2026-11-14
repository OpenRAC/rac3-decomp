#include "common.h"

/* localdecomp:start func_L09_003175C8 */
extern void func_L01_004E6D10_003175C8(s32);
extern s32 func_003B5060(s32);
extern s32 func_003E5090(s32);
extern s32 func_00392A18(void);
extern s32 func_L01_00517448(s32, s32, s32);
extern s32 func_L01_00516470(s32, f32, f32);
extern s32 func_L01_005170B8(s32, s32);
extern s32 func_L01_00517538(s32, f32, f32);
extern s32 func_003E8630(s32, s32);
extern s32 func_003E8348(s32, s32);

void func_L09_003175C8(void)
{
    f32 x = 0.865f;
    f32 y = 0.84f;
    f32 s;

    func_L01_004E6D10_003175C8(1);
    func_003B5060(0x30000);
    s = 1.75f;
    func_003E5090(0x30001);
    func_003E5090(0x30002);
    func_003E5090(0x30003);
    func_L01_00517448(0x30001, func_00392A18(), 0x2F);
    func_L01_00517448(0x30002, func_00392A18(), 0x30);
    func_L01_00517448(0x30003, func_00392A18(), 0x31);
    func_L01_00516470(0x30001, x, y);
    func_L01_00516470(0x30002, x, y);
    func_L01_00516470(0x30003, x, y);
    func_L01_005170B8(0x30001, 0x332299DE);
    func_L01_005170B8(0x30002, 0x331465B7);
    func_L01_005170B8(0x30003, 0x331465B7);
    func_L01_00517538(0x30001, s, s);
    func_L01_00517538(0x30002, s, s);
    func_L01_00517538(0x30003, s, s);
    func_003E8630(0x30000, 0x30002);
    func_003E8630(0x30000, 0x30001);
    func_003E8630(0x30000, 0x30003);
    func_003E8348(0x15, 0x30000);
    func_L01_004E6D10_003175C8(0);
}
/* localdecomp:end func_L09_003175C8 */

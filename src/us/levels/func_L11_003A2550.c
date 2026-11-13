#include "common.h"

/* NTSC-U counterpart of func_L11_003A40B8 (src/levels/11_obani_moons/L11_003A2CD0.c): 0.167552 -> 0.139626; 0.904 -> 0.92 */
/* localdecomp:start func_L11_003A2550 */
extern s32 func_L01_0044EAB8(void *, s32, s32, f32);
extern s32 func_0038DBD8(s32, s32, f32);
extern void func_003C2F58(void *, s32, void *);
extern void func_003D9508(void *, int, int, int, float, float, float);

void func_L11_003A2550(u8 *a0)
{
    u8 *v = *(u8 **)(a0 + 0x68);
    u8 buf[0x10];
    u8 st;

    if (a0[0x95] == 0) {
        *(s32 *)(v + 0x324) = func_L01_0044EAB8(v + 0x328, 0x40108010, 0x40042004, 0.139626354f);
    } else if (a0[0x95] == 2) {
        st = a0[0x20];
        if (st == 6 || st == 8 || st == 7) {
            *(s32 *)(v + 0x324) = func_L01_0044EAB8(v + 0x328, 0x40101080, 0x40040420, 0.139626354f);
        } else {
            *(s32 *)(v + 0x324) = func_L01_0044EAB8(v + 0x328, 0x40108080, 0x40084040, 0.139626354f);
        }
    } else {
        *(s32 *)(v + 0x324) = func_L01_0044EAB8(v + 0x328, 0x40108080, 0x40084040, 0.139626354f);
    }
    *(s32 *)(a0 + 0x78) = func_0038DBD8(*(s32 *)(v + 0x324), *(s32 *)(a0 + 0x78), 0.920000017f);
    func_003C2F58(a0, 0, buf);
    func_003D9508(buf, 0xB, *(s32 *)(a0 + 0x78), 1, 0.25f, 0.08f, 0.0f);
}
/* localdecomp:end func_L11_003A2550 */

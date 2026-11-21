#include "common.h"

/* NTSC-U counterpart of func_L05_003C24F0 (src/levels/shared/L05_003C24F0.c): 0.167552 -> 0.139626; 0.904 -> 0.92 */
#include "vu0.h"

/* localdecomp:start func_L05_003C0480 */
extern s32 func_L01_0044EAB8(void *, s32, s32, f32);
extern s32 func_003894A0(s32, s32, f32);
extern void func_003BDA38(void *, s32, void *);
extern void func_003D3FA0(void *, int, int, int, float, float, float);

void func_L05_003C0480(u8 *a0)
{
    u8 *v = *(u8 **)(a0 + 0x68);
    u8 buf[0x10];
    u8 st;

    if (a0[0x95] == 0) {
        *(s32 *)(v + 0x328) = func_L01_0044EAB8(v + 0x32C, 0x40108010, 0x40042004, 0.139626354f);
    } else if (a0[0x95] == 2) {
        st = a0[0x20];
        if (st == 7 || st == 9 || st == 8) {
            *(s32 *)(v + 0x328) = func_L01_0044EAB8(v + 0x32C, 0x40101080, 0x40040420, 0.139626354f);
        } else {
            *(s32 *)(v + 0x328) = func_L01_0044EAB8(v + 0x32C, 0x40108080, 0x40084040, 0.139626354f);
        }
    } else {
        *(s32 *)(v + 0x328) = func_L01_0044EAB8(v + 0x32C, 0x40108080, 0x40084040, 0.139626354f);
    }
    *(s32 *)(a0 + 0x78) = func_003894A0(*(s32 *)(v + 0x328), *(s32 *)(a0 + 0x78), 0.920000017f);
    func_003BDA38(a0, 0, buf);
    func_003D3FA0(buf, 0xB, *(s32 *)(a0 + 0x78), 1, 0.25f, 0.08f, 0.0f);
}
/* localdecomp:end func_L05_003C0480 */

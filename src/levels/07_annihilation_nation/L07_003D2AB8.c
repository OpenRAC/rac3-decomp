#include "common.h"

INCLUDE_ASM("asm/levels", func_L07_003D2AB8);

/* localdecomp:start func_L07_003D2B30 */
void func_L07_003D2BE0(void *arg0);
extern void func_L01_00451DB8(void *, void *, s32, s32, f32);

void func_L07_003D2B30(u8 *arg0) {
    u8 *p = *(u8 **)(arg0 + 0x68);

    if (*(u8 *)(arg0 + 0x20) == 0) {
        func_L07_003D2BE0(arg0);
    }
    func_L01_00451DB8(arg0, p + 8, 0x7FC81414, 0x7FC81460, 0.0942477882f);
}
/* localdecomp:end func_L07_003D2B30 */

/* localdecomp:start func_L07_003D2B98 */
void func_L07_003D2B98(u8 *arg0, s32 i) {
    if ((*(u8 **)(arg0 + 0x68))[i] != 0) {
        u8 *q = *(u8 **)(arg0 + 0x24);
        *(u16 *)(arg0 + 0x34) &= 0xFFBC;
        *(u16 *)(arg0 + 0x34) |= *(u16 *)(q + 0x44) & 0x1000;
        *(s32 *)(arg0 + 0x98) = *(s32 *)(q + 0x10);
    }
}
/* localdecomp:end func_L07_003D2B98 */

/* localdecomp:start func_L07_003D2BE0 */
void func_L01_004AA7E8(s32, s32);
void func_L01_004450F0(void *, s32, s32);

void func_L07_003D2BE0(void *arg0) {
    *(s32 *)((u8 *)arg0 + 0x98) = 0;
    *(u16 *)((u8 *)arg0 + 0x34) = (u16) (((*(u16 *)((u8 *)arg0 + 0x34)) | 0x43) & 0xEFFF);
    func_L01_004AA7E8((s32) arg0, 1);
    func_L01_004450F0(arg0, 1, -1);
}
/* localdecomp:end func_L07_003D2BE0 */

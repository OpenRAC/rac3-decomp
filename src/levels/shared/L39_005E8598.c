#include "common.h"

/* localdecomp:start func_L39_005E8598 */
extern void func_L01_0047E7C8_005E8598(void *);
extern void func_003BA608(void *);
extern void func_003BA6D0(void *);
extern void func_003BA790(void *);
extern void func_003BACD8(void *);
extern void func_003BA430(void *);
extern void func_L39_005E74C8(void);
extern void func_L39_005E89A0(void *, s32);
extern s32 func_L01_00516470(s32, f32, f32);
extern s32 func_L01_00517538(s32, f32, f32);
extern s32 func_L01_00516D60(s32, s32);

void func_L39_005E8598(u8 *self, s32 a1) {
    func_L01_0047E7C8_005E8598(self);
    func_003BA608(self);
    func_003BA6D0(self);
    func_003BA790(self);
    func_003BACD8(self);
    func_003BA430(self);
    func_L39_005E74C8();
    if (*(s32 *)(self + 0x1C) == 0) {
        func_L39_005E89A0(self, a1);
    }
    func_L01_00516470(0x4F00A8, *(f32 *)(self + 0x7C), *(f32 *)(self + 0x80));
    func_L01_00517538(0x4F00A8, *(f32 *)(self + 0x84), *(f32 *)(self + 0x88));
    func_L01_00516470(0x4F00B3, *(f32 *)(self + 0x7C), *(f32 *)(self + 0x80));
    func_L01_00517538(0x4F00B3, *(f32 *)(self + 0x84), *(f32 *)(self + 0x88));
    func_L01_00516D60(0x4F00B3, *(u8 *)(self + 0xA9));
    func_L01_00517538(0x4F00AF, *(f32 *)(self + 0x60), *(f32 *)(self + 0x64));
}
/* localdecomp:end func_L39_005E8598 */

/* functional: high. Same stores, call and tail (identical to func_L01_003C6EF0's clearing) as retail; 15 words differ in instruction scheduling only. a0/a1 passed to func_L01_003C7000 explicitly. Constants from $gp offsets 0x236C/0x238C verified. */
#include "common.h"
/* localdecomp:start func_L01_003C6F68 */
extern f32 D_L01_001DEC1C;
extern f32 D_L01_001DEC3C;
__asm__(".extern D_L01_001DEC1C, 4");
__asm__(".extern D_L01_001DEC3C, 4");
extern u8 D_001A30B0[];
extern s32 func_L01_003C7000(u8 *, u8 *);
extern void func_003A4F28(s32 a0);
void func_L01_003C6F68(u8 *m, u8 *s) {
    f32 f = D_L01_001DEC1C * 0.017453292f;
    s32 idx;
    u8 *e;
    *(s32 *)(s + 0xB0) = 2;
    *(f32 *)(s + 0x6A8) = D_L01_001DEC3C;
    *(f32 *)(s + 0x694) = f;
    *(f32 *)(s + 0x674) = f;
    func_L01_003C7000(m, s);
    idx = *(s32 *)(s + 0xA0);
    if (idx != -1) {
        e = D_001A30B0 + idx * 128;
        if (*(s32 *)(e + 0xDC) == *(s32 *)(s + 0x4C) && e[0xD0] != 0) {
            func_003A4F28(idx);
        }
    }
    *(s32 *)(s + 0xA0) = -1;
}
/* localdecomp:end func_L01_003C6F68 */

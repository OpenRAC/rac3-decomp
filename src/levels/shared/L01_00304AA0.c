#include "common.h"

/* localdecomp:start func_L01_00304AA0 */
typedef struct {
    u8 b0;
    u8 b1;
    u8 pad2[0xEE];
} Row_00304AA0;
extern u8 *D_L01_001DC5C4;
__asm__(".extern D_L01_001DC5C4, 4");
extern u8 D_001425D1[];
extern Row_00304AA0 D_L01_002C5600[];
extern s32 func_0013D3E0(void);
extern void func_L01_00305880(void *, void *);
extern s32 func_00382498(s32, s32);
extern f32 func_003824E0(f32, f32);
extern void func_L01_004739D8(void *, void *, s32, f32, s32, s16, s32);
extern void func_L01_00466F50(void *, void *, s32, f32, f32);
void func_L01_00304AA0(u8 *self) {
    u8 *s = *(u8 **)(self + 0x68);
    s32 idx;
    idx = *(s32 *)(s + 0x48) - (*(s32 *)(s + 0x44) - 2);
    if (idx <= -1) {
        idx = idx + 0x23;
    }
    if (func_0013D3E0() % 7 == 0) {
        func_L01_00305880(self, D_L01_001DC5C4 + (idx << 6));
    }
    if (func_0013D3E0() % 0x16 == 0) {
        if ((&D_L01_002C5600[D_001425D1[0]])->b1 >= 4) {
            if ((func_0013D3E0() & 1) != 0) {
                func_L01_004739D8(D_L01_001DC5C4 + (idx << 6), D_L01_001DC5C4 + (idx << 6) + 0x10, (func_00382498(0x40, 0x64) << 16) | 0x64004040, func_003824E0(0.1f, 0.2f) * 210000.0f, 0xFF0A0A, (func_00382498(0x14, 0x50) * 5 + 2) / 6, 0);
            }
        } else {
            func_L01_00466F50(D_L01_001DC5C4 + (idx << 6), D_L01_001DC5C4 + (idx << 6) + 0x10, 0, -1.0f, 0.0f);
        }
    }
}
/* localdecomp:end func_L01_00304AA0 */

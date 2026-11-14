#include "common.h"

/* NTSC-U counterpart of func_L03_00396E00 (src/levels/03_starship_phoenix/L03_003967C8.c) */
/* localdecomp:start func_L03_00395788 */
typedef int s128 __attribute__((mode(TI)));

extern u8 D_001426E8[];
extern u8 *D_L03_001DFA1C;
extern u8 *D_L03_0021D940[];
__asm__(".extern D_L03_001DFA1C, 16");

extern void func_003BD360(void *);
extern f32 func_003BE7F0(void *, s32, s32, f32);
extern void func_L03_00395AC0(void *, s32, s32, s32);
extern void func_L01_00441FB8(void *, s32, s32);

void func_L03_00395788(u8 *self) {
    u8 *s = *(u8 **)(self + 0x68);
    u8 *e;
    s32 id;

    if (D_001426E8[0] == 0) {
        if (s[0x17C] == 1) {
            func_003BD360(self);
            func_003BD360(D_L03_001DFA1C + (*(s32 *)(s + 0x140) << 8));
            return;
        }
    } else {
        if (s[0x17C] == 2) {
            func_003BD360(self);
            func_003BD360(D_L03_001DFA1C + (*(s32 *)(s + 0x140) << 8));
            return;
        }
    }
    id = *(s32 *)(s + 0x14C);
    if (id != -1) {
        e = D_L03_0021D940[id];
        if (*(s32 *)e >= 2) {
            *(s32 *)(s + 0x170) = 0;
            *(s16 *)(s + 0x15E) = 1;
            *(s16 *)(s + 0x15C) = 1;
            *(s128 *)(self + 0x10) = *(s128 *)(e + 0x10);
            *(f32 *)(self + 0x18) = func_003BE7F0(self + 0x10, 0, 0, 0.5f);
            *(s128 *)(s + 0x120) = *(s128 *)(e + 0x10 + (*(s16 *)(s + 0x15C) << 4));
            *(f32 *)(s + 0x30) = 0.6f;
            *(f32 *)(s + 0x38) = 1.0f;
            *(f32 *)(s + 0x34) = 0.4f;
            *(f32 *)(s + 0x3C) = 1.0f;
            *(f32 *)(s + 0x50) = 0.0034906587f;
            *(f32 *)(s + 0x40) = 1.4835298f;
            *(f32 *)(s + 0x60) = 0.34906584f;
            *(f32 *)(s + 0x5C) = 0.0027222224f;
            *(f32 *)(s + 0x64) = 0.01f;
            *(f32 *)(s + 0x58) = 0.041666668f;
            *(f32 *)(s + 0x4C) = 0.20943953f;
            *(f32 *)(s + 0x54) = 0.0034906587f;
            func_L03_00395AC0(self, 2, 0, 0);
            func_L01_00441FB8(self, 2, -1);
        } else {
            func_L01_00441FB8(self, 1, -1);
        }
    } else {
        func_L01_00441FB8(self, 1, -1);
    }
}
/* localdecomp:end func_L03_00395788 */

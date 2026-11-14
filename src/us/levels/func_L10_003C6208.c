#include "common.h"

/* NTSC-U counterpart of func_L10_003C8698 (src/levels/10_zeldrin_starport/L10_003C7C28.c) */
#include "vu0.h"

/* localdecomp:start func_L10_003C6208 */
typedef struct { u8 pad[0x30]; s32 f30; s32 f34; } S_3C8698;
extern s32 D_L10_001D6694_003C6208;
extern S_3C8698 D_L10_001E5F80;
extern f32 func_00389380(f32, f32);

void func_L10_003C6208(u8 *m) {
    s32 v = D_L10_001D6694_003C6208;
    u8 *p;

    if (v == 2) {
        if (D_L10_001E5F80.f30 == v && (u32)(D_L10_001E5F80.f34 - 0x14B) < 0x1E) {
            *(f32 *)(m + 0xF8) = func_00389380(*(f32 *)(m + 0xF8), 0.104719765f);
        }
    } else {
        p = *(u8 **)(m + 0x24);
        *(u16 *)(m + 0x34) &= 0xFFBE;
        *(u16 *)(m + 0x34) |= *(u16 *)(p + 0x44) & 0x1000;
        *(s32 *)(m + 0x98) = *(s32 *)(p + 0x10);
    }
}
/* localdecomp:end func_L10_003C6208 */

#include "common.h"

/* localdecomp:start func_L39_00574948 */
typedef int u128_00574948 __attribute__((mode(TI)));

typedef struct Sub_00574948 {
    s32 w0;
    s32 w4;
} Sub_00574948;

typedef struct Slot_00574948 {
    u8 pad0[0xD0];
    u8 bD0;
    u8 padD1[0x2F];
    void *p100;
} Slot_00574948;

extern u8 D_L39_0024DE00[];
extern s32 D_L39_0024E2D0[];
extern u8 D_001FE100[];
extern u8 D_001FE020[];
extern s32 func_L39_005F35D8(s32, s32, void *, s32);
extern void func_L39_005F3088(s32);

void func_L39_00574948(u8 *self) {
    Sub_00574948 *sub = *(Sub_00574948 **)(self + 8);
    Slot_00574948 *slot;
    s32 busy;

    if (sub->w4 != -1) {
        *(u128_00574948 *)(D_001FE100 + (sub->w4 << 7)) = *(u128_00574948 *)D_L39_0024DE00;
    }
    slot = (Slot_00574948 *)(D_001FE020 + (sub->w4 << 7));
    busy = 0;
    if (slot->p100 == self) {
        busy = slot->bD0 != 0;
    }
    if (D_L39_0024E2D0[0] != 0) {
        if (busy == 0) {
            sub->w4 = func_L39_005F35D8(sub->w0, 0x15, self, 0x400);
        }
    } else if (busy != 0) {
        func_L39_005F3088(sub->w4);
        sub->w4 = -1;
    }
}
/* localdecomp:end func_L39_00574948 */

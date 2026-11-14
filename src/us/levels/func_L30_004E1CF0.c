#include "common.h"

/* NTSC-U counterpart of func_L30_004E5BF0 (src/levels/shared/L30_004E5370.c) */
typedef struct {
    u8 pad0[0x25C0];
    u8 *p25C0;
    s32 w25C4;
} S_004E6988;
extern S_004E6988 D_001A4BE0;
#include "vu0.h"
extern u8 *D_001D52FC;
#include "vu0.h"
extern u8 *D_001D52FC;
extern u8 *D_001D52FC;

/* localdecomp:start func_L30_004E1CF0 */
typedef struct Hero_4E5BF0 {
    u8 pad0[0x208];
    s16 h208;
    u8 pad20A[0x1B08 - 0x20A];
    s32 w1B08;
} Hero_4E5BF0;
typedef struct Slot_4E5BF0 {
    u8 pad0[0x58];
    f32 rate;
    u8 pad5C[4];
    s32 busy;
    u8 pad64[0xC];
} Slot_4E5BF0;
extern u8 *D_001D52FC;
extern Slot_4E5BF0 D_L30_002F2BB0[];
__asm__(".extern D_L30_002F2BB0, 16");
extern f32 func_0037E250(f32, f32);

s32 func_L30_004E1CF0(s32 *out) {
    s32 idx[20];
    Slot_4E5BF0 *s;
    s32 count = 0;
    s32 i;
    f32 total;
    f32 r;
    Hero_4E5BF0 *h = (Hero_4E5BF0 *)&D_001A4BE0;

    if (h->h208 != 0) {
        return 0;
    }
    if ((*(s32 *)(D_001D52FC + 0x1A0) & 0x20) && h->w1B08 != 0) {
        return 0;
    }
    for (i = 0; i < 4; i++) {
        s = &D_L30_002F2BB0[i];
        if (s->busy == 0 && s->rate != 0.0f) {
            idx[count++] = i;
        }
    }
    if (count == 0) {
        return 0;
    }
    total = 0.0f;
    for (i = 0; i < count; i++) {
        Slot_4E5BF0 *q = &D_L30_002F2BB0[idx[i]];
        total += 1.0f / (f32)(s32)(q->rate * 60.0f);
    }
    r = func_0037E250(0.0f, 1.0f);
    if (r < total) {
        for (i = 0; i < count; i++) {
            *out = idx[i];
            s = &D_L30_002F2BB0[idx[i]];
            total -= 1.0f / (f32)(s32)(s->rate * 60.0f);
            if (total < r) {
                break;
            }
        }
        return 1;
    }
    return 0;
}
/* localdecomp:end func_L30_004E1CF0 */

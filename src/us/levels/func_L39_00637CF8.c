#include "common.h"

/* NTSC-U counterpart of func_L39_0063A540 (src/levels/shared/L39_0063A030.c): timer thresholds 12 -> 15 and 18 -> 22 */
/* localdecomp:start func_L39_00637CF8 */
typedef union Buf_00637CF8 {
    u8 b[8];
    u32 w[2];
} Buf_00637CF8;

extern u8 D_L39_004998A0[];
extern s32 func_L39_00630400(void *, f32);
extern void func_L39_00637C98(u8 *p, s32 a, s32 b, s32 en, s32 t);

/* reads an obfuscated 32-bit state stored as an index byte at q */
static __inline__ s32 get_state_00637CF8(u8 *q) {
    Buf_00637CF8 buf;
    u8 *b;
    s32 m;
    s32 k;
    s32 n;
    s32 i;
    long t;

    t = *q;
    if (t == 0) {
        return 0;
    }
    n = *q;
    m = n + 1;
    k = ((s32)q - n) & 7;
    b = buf.b;
    for (i = 0; i < 40; i += 5) {
        *b++ = D_L39_004998A0[m + ((k + i) & 7) * 255];
    }
    buf.w[0] ^= (u32)q;
    buf.w[1] ^= buf.w[0];
    return buf.w[1];
}

void func_L39_00637CF8(u8 *o) {
    s32 id;

    if ((get_state_00637CF8(o + 0x19E6) ^ 1) != 0) {
        return;
    }
    if ((get_state_00637CF8(o + 0x19E4) ^ 2) == 0 && *(s32 *)(o + 0x2F0) < 15) {
        return;
    }
    id = o[0x37B];
    if ((get_state_00637CF8(o + 0x19E4) ^ 2) == 0 && *(s32 *)(o + 0x2F0) == 22) {
        func_L39_00637C98(o, id, 0, 1, 30);
    }
    switch (*(u8 *)(*(u8 **)(o + 0x2524) + 0x43)) {
    case 3:
        if (*(s32 *)(o + 0x61C) != 0) {
            return;
        }
        if (func_L39_00630400(o, 49.5f)) {
            func_L39_00637C98(o, id, 0, 1, 30);
        }
        if (func_L39_00630400(o, 17.0f)) {
            func_L39_00637C98(o, id, 1, 1, 30);
        }
        break;
    case 4:
        if (*(s32 *)(o + 0x61C) != 0) {
            return;
        }
        if (func_L39_00630400(o, 12.5f)) {
            func_L39_00637C98(o, id, 0, 1, 30);
        }
        if (func_L39_00630400(o, 1.0f)) {
            func_L39_00637C98(o, id, 1, 1, 30);
        }
        break;
    case 20:
        if (*(s32 *)(o + 0x61C) != 0) {
            return;
        }
        if (func_L39_00630400(o, 8.0f)) {
            func_L39_00637C98(o, id, 0, 1, 30);
        }
        if (func_L39_00630400(o, 21.0f)) {
            func_L39_00637C98(o, id, 1, 1, 30);
        }
        break;
    }
}
/* localdecomp:end func_L39_00637CF8 */

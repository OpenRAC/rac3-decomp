#include "common.h"

/* NTSC-U counterpart of func_L39_00639D90 (src/levels/shared/L39_00639350.c): data addresses only */
/* localdecomp:start func_L39_00637548 */
typedef union Buf_00637548 {
    u8 b[8];
    u32 w[2];
} Buf_00637548;

extern u8 D_L39_004998A0[];
typedef struct G_00637548 {
    u8 pad0[0xA4];
    u8 bA4[4];
} G_00637548;
extern G_00637548 D_001A5990;
extern s32 D_L39_002412A8;
__asm__(".extern D_L39_002412A8, 16");

/* reads an obfuscated 32-bit state stored as an index byte at q */
static __inline__ s32 get_state_00637548(u8 *q) {
    Buf_00637548 buf;
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

s32 func_L39_00637548(void *obj) {
    u8 *o = (u8 *)obj;
    u8 *e;

    if (D_001A5990.bA4[*(s32 *)(o + 0x2544)] == 0) {
        return 0;
    }
    if (*(s32 *)(o + 0x35C) != 0) {
        return 0;
    }
    if (D_L39_002412A8 == 2 || D_L39_002412A8 == 6) {
        return 0;
    }
    if (o[0x1A14] != 0) {
        e = *(u8 **)(*(u8 **)(o + 0x2530) + 0x50);
        if (e != 0 && *(s16 *)(e + 0x86) == 5) {
            return 0;
        }
    }
    if ((get_state_00637548(o + 0x19E4) ^ 0x71) == 0) {
        return 0;
    }
    if ((get_state_00637548(o + 0x19E4) ^ 0x31) == 0) {
        return 0;
    }
    if ((get_state_00637548(o + 0x19E4) ^ 0x1C) == 0) {
        return 0;
    }
    if ((get_state_00637548(o + 0x19E4) ^ 0x8E) != 0) {
        return D_001A5990.bA4[*(s32 *)(o + 0x2544)];
    } else {
        return 0;
    }
}
/* localdecomp:end func_L39_00637548 */

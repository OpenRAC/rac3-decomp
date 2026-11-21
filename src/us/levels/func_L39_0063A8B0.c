#include "common.h"

/* NTSC-U counterpart of func_L39_0063D0F8 (src/levels/shared/L39_0063BDE0.c): 17 -> 20 */
extern s32 func_003883C8(s16 *timer);
extern u8 D_L39_004998A0[];
#include "vu0.h"
extern u8 D_L39_004998A0[];
extern s32 func_003883C8(s16 *timer);
extern u8 D_L39_004998A0[];

/* localdecomp:start func_L39_0063A8B0 */
typedef union Buf_0063D0F8 {
    u8 b[8];
    u32 w[2];
} Buf_0063D0F8;

typedef struct E_0063D0F8 {
    s32 w0;
    u8 pad4[0x18];
} E_0063D0F8;

extern u8 D_L39_004998A0[];
extern E_0063D0F8 D_L39_00484160[];
extern s32 func_003883C8(s16 *timer);
extern s32 func_L39_005C0F88(void *);
extern s32 func_L39_005C1030(void *);
void func_L39_00674710(u8);

/* reads an obfuscated 32-bit state stored as an index byte at q */
static __inline__ s32 get_state_0063D0F8(u8 *q) {
    Buf_0063D0F8 buf;
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

void func_L39_0063A8B0(u8 *o) {
    func_003883C8((s16 *)(o + 0x24A6));
    func_003883C8((s16 *)(o + 0x24A8));
    if ((get_state_0063D0F8(o + 0x19E4) ^ 0x37) == 0) {
        return;
    }
    if (*(s32 *)(o + 0x251C) != 0 || o[0x1A0C] != 0 || D_L39_00484160[*(s32 *)(o + 0x2544)].w0 != 0) {
        return;
    }
    if (func_L39_005C0F88(*(void **)(o + 0x2534)) & 0x10) {
        *(s16 *)(o + 0x24A6) = 0x14;
    }
    if (*(s16 *)(o + 0x24A6) != 0) {
        if (func_L39_005C1030(*(void **)(o + 0x2534)) & 0x10) {
            o[0x24AA] = 1;
            func_L39_00674710(o[0x24C9]);
            if (*(s16 *)(o + 0x24A8) == 0) {
                *(s16 *)(o + 0x24A8) = 0x14;
            }
        }
    }
}
/* localdecomp:end func_L39_0063A8B0 */

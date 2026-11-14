#include "common.h"

/* NTSC-U counterpart of func_L39_0063EE68 (src/levels/shared/L39_0063EE68.c) */
extern u8 D_L39_004998A0[];
typedef struct { u8 pad[0xA4]; u8 bA4[1]; } G_0063C608;
extern G_0063C608 D_001A5990;

/* localdecomp:start func_L39_0063C608 */
typedef union Buf_0063EE68 {
    u8 b[8];
    u32 w[2];
} Buf_0063EE68;

extern void func_L39_0063D538(void *);
extern void func_L39_00641720(void *, void *);
extern void func_L39_00641328(void *);
extern void func_L39_006702E0(void *);
extern void func_L39_00641170(void *);

#define DECRYPT(OFF)                                                         \
    {                                                                        \
        u8 *q = s + (OFF);                                                   \
        if (*q == 0) {                                                       \
            dec = 0;                                                         \
        } else {                                                             \
            u32 a;                                                           \
            u32 b;                                                           \
            s32 n;                                                           \
            s32 k;                                                           \
            s32 m;                                                           \
            s32 i;                                                           \
            u8 *d;                                                           \
            n = *q;                                                          \
            k = ((u32)q - n) & 7;                                            \
            m = n + 1;                                                       \
            d = buf.b;                                                       \
            for (i = 0; i < 40; i += 5) {                                    \
                *d++ = D_L39_004998A0[m + ((k + i) & 7) * 255];              \
            }                                                                \
            a = buf.w[0] ^ (u32)q;                                           \
            b = buf.w[1] ^ a;                                                \
            buf.w[0] = a;                                                    \
            buf.w[1] = b;                                                    \
            dec = b;                                                         \
        }                                                                    \
    }

void func_L39_0063C608(u8 *s) {
    Buf_0063EE68 buf;
    u32 dec;
    s32 eq;

    DECRYPT(0x19E4)
    eq = dec == 0x31;
    if (eq) {
        s[0x1A10] = 1;
    } else {
        DECRYPT(0x19E4)
        eq = dec == 0x8F;
        if (eq) {
            s[0x1A10] = 1;
        } else {
            DECRYPT(0x19E6)
            eq = dec == 3;
            if (eq) {
                s[0x1A10] = 1;
            } else {
                s[0x1A10] = 0;
            }
        }
    }
    func_L39_0063D538(s);
    if (*(s32 *)(s + 0x478) != 0xA) {
        if (D_001A5990.bA4[*(s32 *)(s + 0x2544)] != 0) {
            *(s32 *)(s + 0x460) |= 8;
        } else if (*(s32 *)(s + 0x460) & 8) {
            *(s32 *)(s + 0x460) &= ~8;
        }
    }
    func_L39_00641720(s, *(void **)(s + 0x2524));
    if ((*(u8 **)(s + 0x2524))[0x31] != 0) {
        func_L39_00641328(s);
    }
    func_L39_006702E0(s + 0x1A40);
    func_L39_00641170(s);
}
/* localdecomp:end func_L39_0063C608 */

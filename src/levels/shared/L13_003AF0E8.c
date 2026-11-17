#include "common.h"

typedef struct {
    void (*f0)(void *);
    void (*f4)(void *);
} S_3AC810;

/* localdecomp:start func_L13_003AF0E8 */
extern u8 *D_L13_001DF1CC;
extern u8 *D_L13_001DF680;
extern f32 func_L01_0040E548(void *, void *);
extern f32 func_L01_0040E570(u8 *, u8 *);

u8 *func_L13_003AF0E8(u8 *o, s32 idx, u8 flag) {
    u8 *p = *(u8 **)(o + 0x68);
    u8 *e = D_L13_001DF1CC + (idx * 0x30 + 0x20);
    s32 n = *(s16 *)(e + 0x12);
    f32 bestv = -100000000.0f;
    u8 *best = 0;
    s32 i;

    for (i = 0; i < n; i++) {
        u8 *m = D_L13_001DF680 + ((*(s32 **)(e + 0x20))[i] << 7);
        f32 a, b, d;

        if (m == *(u8 **)(p + 0x3B8) && n >= 2) {
            continue;
        }
        if (flag) {
            a = func_L01_0040E548(m + 0x30, p + 0x130);
            b = func_L01_0040E548(m + 0x30, o + 0x10);
        } else {
            a = func_L01_0040E570(m + 0x30, p + 0x130);
            b = func_L01_0040E570(m + 0x30, o + 0x10);
        }
        d = a - b * 0.5f;
        if (bestv < d) {
            best = m;
            bestv = d;
        }
    }
    return best;
}
/* localdecomp:end func_L13_003AF0E8 */

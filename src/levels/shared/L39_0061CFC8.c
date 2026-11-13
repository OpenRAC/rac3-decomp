#include "common.h"

/* localdecomp:start func_L39_0061CFC8 */
extern u8 D_L39_004997E0[];
typedef struct { u8 pad[0x128]; s32 f128; } G_0061CFC8;
extern G_0061CFC8 D_001A5CD0[];
extern void func_L39_00637EC8(void *, void *, void *, s32, s32, s32, s32);
extern void func_L39_0061ECE0(s32, void *, s32);

void func_L39_0061CFC8(u8 *self, void *a1, void *a2, s32 a3, s32 a4) {
    u32 buf[2];
    u8 *p;
    u8 *b;
    u8 *q;
    s32 x;
    s32 i;
    p = self + 0x19E4;
    if (*p == 0) {
        x = 0;
    } else {
        s32 n = *p;
        s32 m = n + 1;
        s32 k = ((s32)p - n) & 7;
        b = (u8 *)buf;
        for (i = 0; i < 40; i += 5) {
            *b++ = D_L39_004997E0[m + ((k + i) & 7) * 255];
        }
        buf[0] ^= (u32)p;
        buf[1] ^= buf[0];
        x = buf[1];
    }
    q = self + 0xA0;
    func_L39_00637EC8(self, a1, a2, x, a4, a3, 0);
    func_L39_0061ECE0(*(s32 *)(self + 0x2558) + 0x10, q, D_001A5CD0->f128);
}
/* localdecomp:end func_L39_0061CFC8 */

#include "common.h"

/* localdecomp:start func_L39_005D73C8 */
typedef union {
    u8 b[8];
    u32 w[2];
    f32 f[2];
} Buf_005D73C8;

typedef struct S_005D73C8 {
    u8 pad0[0x2476];
    u8 b2476;
    u8 pad2477[0x2528 - 0x2477];
    u8 *p2528;
    u8 pad252C[0x2554 - 0x252C];
    u8 b2554;
} S_005D73C8;

__asm__(".extern D_L39_002435E8, 8");
__asm__(".extern D_L39_00243600, 8");
extern s32 D_L39_002435E8[2];
extern S_005D73C8 *D_L39_00243600[2];
extern s32 *D_L39_00241120;
extern u8 D_L39_004997E0[];
extern s32 func_L01_00517688(void);
extern void func_L01_00516AA0(s32, s32, s32);
extern void func_L01_00517538(s32, f32, f32);
extern void func_L39_005D6AE0(void);

static inline f32 DecF_005D73C8(u8 *q) {
    Buf_005D73C8 buf;
    u32 a;
    s32 n;
    s32 k;
    s32 m;
    s32 i;
    u8 *d;

    if (*q == 0) {
        return 0.0f;
    }
    n = *q;
    k = ((u32)q - n) & 7;
    m = n + 1;
    d = buf.b;
    for (i = 0; i < 40; i += 5) {
        *d++ = D_L39_004997E0[m + ((k + i) & 7) * 255];
    }
    a = buf.w[0] ^ (u32)q;
    buf.w[0] = a;
    buf.w[1] ^= a;
    return buf.f[1];
}

void func_L39_005D73C8(void) {
    s32 idx;
    f32 ratio;

    idx = func_L01_00517688();
    if (D_L39_002435E8[idx] != 0) {
        D_L39_002435E8[idx]--;
        if (D_L39_00243600[idx]->p2528 != 0) {
            u8 *p = D_L39_00243600[idx]->p2528;
            ratio = *(f32 *)(p + 0x308) / *(f32 *)(p + 0x30C);
            func_L01_00516AA0(0x90003, 1, 0);
            func_L01_00516AA0(0x90004, 1, 0);
            func_L01_00516AA0(0x90005, 1, 0);
        } else {
            f32 a = DecF_005D73C8(&D_L39_00243600[idx]->b2476) * 100.0f;
            f32 b = DecF_005D73C8(&D_L39_00243600[idx]->b2554);
            ratio = a / b / 100.0f;
            func_L01_00516AA0(0x90003, 1, 1);
            func_L01_00516AA0(0x90004, 1, 1);
            func_L01_00516AA0(0x90005, 1, 1);
            func_L39_005D6AE0();
        }
        if (*D_L39_00241120 == 2) {
            func_L01_00517538(0x90006, ratio * 0.28f, 0.07f);
        } else {
            func_L01_00517538(0x90006, ratio * 0.28f, 0.048f);
        }
    } else {
        func_L01_00516AA0(0x90000, 1, 0);
    }
}
/* localdecomp:end func_L39_005D73C8 */

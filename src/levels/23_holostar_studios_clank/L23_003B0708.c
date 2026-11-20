#include "common.h"
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4;

__asm__(".extern D_L23_001DE274, 4");
extern s32 D_L23_001DE274;
typedef struct {
    V4 v[4];
    s32 c40;
    s32 c44;
    s32 c48;
    s32 c4C;
    s32 x50;
    s32 x54;
    s32 x58;
    f32 x5C;
    f32 x60;
    s32 x64;
    f32 x68;
    f32 x6C;
    long x70;
    long x78;
    long x80;
    long x88;
} S_3B0708;

extern long func_00389598(s32);
extern void func_003D2DA0(void *, void *, s32);

/* localdecomp:start func_L23_003B0708 */
void func_L23_003B0708(void *a0, void *a1, s32 count, s32 idx, s32 a4, s32 color, s32 alpha1, s32 alpha2, s32 a8) {
    S_3B0708 s;
    s32 i;
    s32 last;
    s32 x;
    s32 y;
    s32 m = 0xFFFFFF;

    last = count - 1;
    i = 1;
    s.x78 = func_00389598(a8);
    s.x50 = 0;
    s.x54 = 0;
    s.x58 = 0;
    s.x5C = 1.0f;
    s.x60 = 1.0f;
    s.x64 = 0;
    s.x68 = 1.0f;
    s.x80 = 0xFF9000000260L;
    s.x70 = 4;
    s.x88 = 0x8000000048L;
    s.x6C = 1.0f;
    color &= m;
    x = color | (alpha2 << 24);
    y = color | (alpha1 << 24);
    s.c48 = x;
    s.c4C = y;
    s.v[2] = ((V4 *)a1)[idx];
    s.v[3] = ((V4 *)a0)[idx];
    if (i <= last) {
        idx--;
        do {
            if (idx < 0) {
                idx = D_L23_001DE274 - 1;
            }
            y = alpha1 * (last - i) / last;
            x = alpha2 * (last - i) / last;
            if (i & 1) {
                s.c40 = color | (x << 24);
                s.c44 = color | (y << 24);
                s.v[0] = ((V4 *)a1)[idx];
                s.v[1] = ((V4 *)a0)[idx];
            } else {
                s.c48 = color | (x << 24);
                s.c4C = color | (y << 24);
                s.v[2] = ((V4 *)a1)[idx];
                s.v[3] = ((V4 *)a0)[idx];
            }
            func_003D2DA0(&s, 0, 1);
            idx--;
            i++;
        } while (i <= last);
    }
}
/* localdecomp:end func_L23_003B0708 */

#include "common.h"

/* localdecomp:start func_L39_006E0298 */
#include "vu0.h"
typedef struct {
    f32 f0[8];
    f32 f20;
    f32 f24;
    f32 f28;
    f32 f2C;
    f32 f30;
    f32 f34;
    char pad38[0x6C];
} S_006E0298_ent;

typedef struct {
    char pad0[0x120];
    s32 sel[34];
    s32 cur;
    char pad1AC[0x19C];
    S_006E0298_ent ent[2];
} S_006E0298_cam;

typedef struct {
    char pad0[0xC];
    s32 fC;
    char pad10[0x78];
    f32 f88[4];
    f32 f98[4];
} S_006E0298_in;

typedef struct {
    char pad0[0x88];
    f32 f88[3];
    f32 f94[3];
    f32 fA0[3];
    f32 fAC[3];
    f32 fB8[3];
    f32 fC4[3];
    char padD0[0xC];
    f32 fDC;
    char padE0[4];
    f32 fE4;
    f32 fE8;
} S_006E0298_cfg;

extern S_006E0298_cam D_001FD7E8_006E0298;
extern S_006E0298_in D_001A5CD0_006E0298;
extern S_006E0298_cfg D_001A6950_006E0298;
__asm__(".extern D_L39_0024A0D4, 16");
extern f32 (*D_L39_0024A0D4)(f32, f32, f32, f32, f32);

void func_L39_006E0298(f32 *outX, f32 *outY, s32 arg2, s32 arg3, s32 slot, s32 ent, s32 pad)
{
    s32 sel;
    s32 other;
    f32 x, y, a, b, w, ret, t, hi, lo, v, g, f, sum, dif;

    sel = D_001FD7E8_006E0298.sel[slot];
    other = sel == 0;
    x = D_001A5CD0_006E0298.f88[pad];
    y = D_001A5CD0_006E0298.f98[pad];
    a = D_001FD7E8_006E0298.ent[other].f24;
    b = D_001FD7E8_006E0298.ent[other].f28;
    *outX = x;
    *outY = y;
    w = 0.0f;
    if (D_001FD7E8_006E0298.cur == D_001FD7E8_006E0298.sel[slot]) {
        w = 1.0f;
    } else if (D_001FD7E8_006E0298.cur == -1) {
        w = 0.5f;
    }
    if (b < D_001FD7E8_006E0298.ent[other].f20) {
        b = D_001FD7E8_006E0298.ent[other].f20;
    }
    if (D_001A6950_006E0298.fDC < b) {
        b = D_001A6950_006E0298.fDC;
    }
    if (b < D_001A6950_006E0298.fE4) {
        b = D_001A6950_006E0298.fE4;
    }
    ret = D_L39_0024A0D4(x, a, y, b, w);

    t = ret * D_001A6950_006E0298.f88[pad];
    if (0.0f < t) {
        t = t * D_001A6950_006E0298.fB8[pad];
    } else {
        t = t * D_001A6950_006E0298.fC4[pad];
    }
    *outX = *outX + t;

    g = fabs_asm(ret) * D_001A6950_006E0298.f94[pad];
    hi = D_001FD7E8_006E0298.ent[sel].f30;
    lo = D_001FD7E8_006E0298.ent[sel].f34;
    v = D_001FD7E8_006E0298.ent[sel].f0[ent];
    dif = hi - lo;
    sum = hi + lo;
    f = 0.5f;
    if (D_001A5CD0_006E0298.fC < 2) {
        if (v < sum) {
            f = 0.0f;
        } else if (sum <= v && v <= dif) {
            if (0.0f < dif - sum) {
                f = (v - sum) / (dif - sum);
            }
        } else {
            f = 1.0f;
        }
    }
    f = f - 0.5f;
    t = g * f;
    if (0.0f < t) {
        t = t * D_001A6950_006E0298.fA0[pad];
    } else {
        t = t * D_001A6950_006E0298.fAC[pad];
    }
    *outX = *outX + t;

    if (D_001A6950_006E0298.fE4 < y) {
        *outY = y - D_001A6950_006E0298.fE8;
    }
    if (*outY > D_001A6950_006E0298.fDC) {
        *outY = D_001A6950_006E0298.fDC;
    }
    if (*outY < D_001A6950_006E0298.fE4) {
        *outY = D_001A6950_006E0298.fE4;
    }
}
/* localdecomp:end func_L39_006E0298 */

/* localdecomp:start func_L39_006E05C0 */
typedef struct {
    s32 ids[8];
    f32 a[8];
    f32 b[8];
    char pad60[0x8C - 0x60];
    s32 count;
    char pad90[0xA4 - 0x90];
} S_006E05C0_Ent;
typedef struct {
    s32 sel[0x1C8 / 4];
    S_006E05C0_Ent ent[8];
} S_006E05C0;
extern S_006E05C0 D_001FD908;
extern f32 D_001A6950[];

f32 func_L39_006E05C0(s32 arg0) {
    s32 skip = D_001FD908.sel[arg0];
    f32 num = 0.0f;
    f32 den = num;
    s32 i;

    for (i = 0; i < 8; i++) {
        s32 j;
        if (skip != i) {
            for (j = 0; j < *(&D_001FD908.ent[i].count); j++) {
                f32 w = D_001A6950[0xDC / 4] - (D_001FD908.ent + i)->b[j] + D_001A6950[0xE4 / 4];
                num += D_001FD908.ent[i].a[j] * w;
                den += w;
            }
        }
    }
    return num / den;
}
/* localdecomp:end func_L39_006E05C0 */

/* localdecomp:start func_L39_006E0688 */
f32 func_L39_006E0688(s32 arg0) {
    s32 skip = D_001FD908.sel[arg0];
    f32 sum = 0.0f;
    s32 total = 0;
    s32 i;
    s32 j;
    S_006E05C0_Ent *rows = D_001FD908.ent;
    for (i = 0; i < 8; i++) {
        if (skip != i) {
            for (j = 0; j < D_001FD908.ent[i].count; j++) {
                total++;
                sum += rows[i].b[j];
            }
        }
    }
    return sum / total;
}
/* localdecomp:end func_L39_006E0688 */

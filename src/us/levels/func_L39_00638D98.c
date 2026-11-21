#include "common.h"

/* NTSC-U counterpart of func_L39_0063B5E0 (src/levels/shared/L39_0063AC60.c): timer 360 frames instead of 300 */
/* localdecomp:start func_L39_00638D98 */
typedef union Buf_00638D98 {
    u8 b[8];
    u32 w[2];
    u16 h[4];
    f32 f[2];
} Buf_00638D98;

extern u8 D_L39_004998A0[];
extern u8 D_L39_004998A1[];
extern u32 D_L39_0024BAC8;

static __inline__ void Prep_00638D98(u8 *q) {
    s32 t;
    if (*q == 0) {
        *q = ++D_L39_004998A0[0];
    } else {
        t = *q;
        *q = D_L39_004998A1[0];
        D_L39_004998A1[0] = t;
    }
}

static __inline__ f32 DecF_00638D98(u8 *q) {
    Buf_00638D98 buf;
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
        *d++ = D_L39_004998A0[m + ((k + i) & 7) * 255];
    }
    a = buf.w[0] ^ (u32)q;
    buf.w[0] = a;
    buf.w[1] ^= a;
    return buf.f[1];
}

static __inline__ void SetF_00638D98(u8 *q, f32 v) {
    u8 *hk = q;
    Buf_00638D98 buf;
    u32 key;
    s32 k;
    s32 m;
    s32 i;
    u8 *d;

    Prep_00638D98(q);
    key = ((u32 *)D_L39_004998A0)[((u32)hk * D_L39_0024BAC8) % 510];
    k = ((u32)q - *q) & 7;
    buf.w[0] = (u32)q ^ key;
    buf.f[1] = v;
    buf.w[1] ^= key;
    m = *q + 1;
    d = buf.b;
    for (i = 0; i < 40; i += 5) {
        D_L39_004998A0[m + ((k + i) & 7) * 255] = *d++;
    }
}

static __inline__ s32 LtF_00638D98(u8 *q, f32 v) {
    return DecF_00638D98(q) < v;
}

typedef struct Cam_00638D98 {
    u8 pad0[0x44];
    f32 f44;
} Cam_00638D98;

typedef struct Lnk_00638D98 {
    u8 pad0[4];
    Cam_00638D98 *p4;
} Lnk_00638D98;

void func_L39_00638D98(u8 *g, s32 dmg) {
    if (g[0x1A14] != 0 && dmg != 0) {
        u8 *q = g + 0x2476;
        f32 f = dmg;
        *(s32 *)(g + 0x24D4) = dmg;
        SetF_00638D98(q, DecF_00638D98(q) - f);
        if ((u8)LtF_00638D98(g + 0x2476, 0.0f)) {
            SetF_00638D98(g + 0x2476, 0.0f);
        }
        *(s32 *)(g + 0x2514) = 360;
        if (*(Lnk_00638D98 **)(g + 0x2558) != 0 && (*(Lnk_00638D98 **)(g + 0x2558))->p4 != 0) {
            (*(Lnk_00638D98 **)(g + 0x2558))->p4->f44 = DecF_00638D98(g + 0x2476);
        }
    }
}
/* localdecomp:end func_L39_00638D98 */

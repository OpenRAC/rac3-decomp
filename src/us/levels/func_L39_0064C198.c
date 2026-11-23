#include "common.h"

/* NTSC-U counterpart of func_L39_0064EA40 (src/levels/shared/L39_0064EA40.c) */
/* localdecomp:start func_L39_0064C198 */
#include "vu0.h"
typedef int u128_t __attribute__((mode(TI)));

typedef union Buf_0064EA40 {
    u8 b[8];
    u32 w[2];
    u16 h[4];
    f32 f[2];
} Buf_0064EA40;

typedef struct Pkt_0064EA40 {
    u8 b0;
    u8 b1;
    u8 b2;
    u8 b3;
    f32 f4;
    f32 f8;
    f32 fC;
    f32 f10;
    f32 f14;
    f32 f18;
    u8 pad1C[0x14];
} Pkt_0064EA40;

typedef struct Net_0064EA40 {
    u8 pad0[4];
    s32 w4;
    u8 pad8[0x170 - 8];
    s32 w170;
    u8 pad174[0x7D4 - 0x174];
    u8 b7D4;
} Net_0064EA40;

typedef struct VT_0064EA40 {
    u8 pad0[0x34];
    s32 (*f34)(void *, s32, s32, s32, s32);
} VT_0064EA40;

extern u8 D_L39_004998A0[];
extern u8 D_L39_004998A1[];
extern u8 D_L39_00480820[];
extern u8 D_L39_00480821[];
extern u32 D_L39_0024BAC8;
typedef struct Glob_0064EA40 {
    u8 pad0[0xA4];
    u8 bA4[4];
} Glob_0064EA40;
extern Glob_0064EA40 D_001A5990;
extern Net_0064EA40 D_001A5E50;

extern s32 func_L39_00634AC8(void);
extern void func_L39_006335A0(u8 *);
extern void func_L01_0044B4B8(void *);
extern void func_L01_003F0020(s32);
extern void func_L39_0062A388(u8 *, u32, u32);
extern void func_L39_0061FAE8(void *);
extern s32 func_L39_005B24C8(s32, s32);
extern void func_L39_0061F590(void *);
extern s32 func_L39_0061FC10(void *, s32);
extern void func_L39_00628CD0(void *, s32, s32, s32, f32);
extern void func_L39_00644920(void *, s32);
extern void func_L39_00644150(void *);
extern s32 func_L39_00639598(void *, void *);
extern void func_003BE4F0(void *, s32, s32, s32);
extern void func_L39_00637AE8(void *);
extern void func_L39_006378A8(void *);
extern void func_0014AD08(s32, s32, s32, s32, s32, void *);
extern u32 D_L39_00246198[2];
extern f32 func_L39_0062FD90(void *, void *);
extern f32 func_003887A0(void *);
extern f32 func_00389468(f32, f32);
extern void func_L39_00630530(void *, s32, f32);
extern s32 func_L39_006365A8(void *);
extern s32 func_L39_0063A8A8(void *, s32);
extern void func_003BF640(void *, f32);
extern s32 func_L39_006377E8(void *, s32, s32);
extern void func_L39_00628F00(void *, s32, s32);
extern void func_L39_006544D8(void *);
extern f32 func_00388A28(f32, f32);
extern f32 func_003887C8(void *, void *);
extern f32 func_L39_005B2568(f32, f32);
extern s32 func_L01_003EFFE0(s32, s32);
extern void func_L01_0044B090(s32, void *);
extern void func_L01_0044B0B8(void *, s32, s32, f32);
extern void func_L39_00637C98(void *, s32, s32, s32, s32);
extern void func_L39_00645780(void *, s32, s32, s32);
extern f32 func_L39_0062F240(void *, s32);
extern s32 func_L39_00627608(void *);
extern s32 func_L01_0045D358(s32, s32, void *, s32);
extern s32 func_L39_0061EB48(void *);
extern u8 D_L39_002461A0[];
__asm__(".extern D_001D72B0_sda_0064C198, 4");
extern s32 D_001D72B0_sda_0064C198;
extern s32 D_001D4C78_sda_0064C198 __attribute__((section(".sdata")));
extern s32 D_001D5BCC_sda_0064C198 __attribute__((section(".sdata")));
extern s32 D_001D4E98_sda_0064C198 __attribute__((section(".sdata")));
typedef struct Stat_0064EA40 {
    u16 h0;
    u32 w4;
    u32 w8;
} Stat_0064EA40;
extern Stat_0064EA40 D_L39_00200420[];
typedef struct Tune_0064EA40 {
    s32 w0;
    s32 w4;
    s32 w8;
    u8 padC[0x2C - 0xC];
} Tune_0064EA40;
extern Tune_0064EA40 D_L39_0047A968[];
extern void func_L39_0062D4A8(void *, f32, f32, f32);
extern void func_L39_00638D98(void *, s32);
extern f32 func_00389380(f32, f32);
extern void func_003886E8(void *, void *, f32);
extern void func_L39_00635F88(void *, f32);
extern u8 *func_L01_00444358(s32, s32, s32);
extern f32 func_003BE7F0(void *, s32, s32, f32);
extern f32 D_L39_0047A7D8[][25];
extern f32 func_L39_00631430(void *, void *, s32);
typedef struct VT30_0064EA40 {
    u8 pad0[0x30];
    void (*f30)(void *);
} VT30_0064EA40;

static __inline__ u32 Dec_0064EA40(u8 *q) {
    Buf_0064EA40 buf;
    u32 a;
    u32 b;
    s32 n;
    s32 k;
    s32 m;
    s32 i;
    u8 *d;

    if (*q == 0) {
        return 0;
    }
    n = *q;
    k = ((u32)q - n) & 7;
    m = n + 1;
    d = buf.b;
    for (i = 0; i < 40; i += 5) {
        *d++ = D_L39_004998A0[m + ((k + i) & 7) * 255];
    }
    a = buf.w[0] ^ (u32)q;
    b = buf.w[1] ^ a;
    buf.w[0] = a;
    buf.w[1] = b;
    return b;
}

static __inline__ s32 DecEq_0064EA40(u8 *q, s32 v) {
    return Dec_0064EA40(q) == v;
}

static __inline__ s32 DecLt_0064EA40(u8 *q, s32 v) {
    return (s32)Dec_0064EA40(q) < v;
}

static __inline__ void Prep_0064EA40(u8 *q) {
    s32 t;
    if (*q == 0) {
        *q = ++D_L39_004998A0[0];
    } else {
        t = *q;
        *q = D_L39_004998A1[0];
        D_L39_004998A1[0] = t;
    }
}

static __inline__ void Set_0064EA40(u8 *q, u32 v) {
    u8 *hk = q;
    Buf_0064EA40 buf;
    u32 key;
    s32 k;
    s32 m;
    s32 i;
    u8 *d;

    Prep_0064EA40(q);
    key = ((u32 *)D_L39_004998A0)[((u32)hk * D_L39_0024BAC8) % 510];
    k = ((u32)q - *q) & 7;
    buf.w[0] = (u32)q ^ key;
    buf.w[1] = v ^ key;
    m = *q + 1;
    d = buf.b;
    for (i = 0; i < 40; i += 5) {
        D_L39_004998A0[m + ((k + i) & 7) * 255] = *d++;
    }
}

static __inline__ void SetNK_0064EA40(u8 *q, u32 v) {
    Buf_0064EA40 buf;
    u32 key;
    s32 k;
    s32 m;
    s32 i;
    u8 *d;

    Prep_0064EA40(q);
    key = ((u32 *)D_L39_004998A0)[((u32)q * D_L39_0024BAC8) % 510];
    k = ((u32)q - *q) & 7;
    buf.w[0] = (u32)q ^ key;
    buf.w[1] = v ^ key;
    m = *q + 1;
    d = buf.b;
    for (i = 0; i < 40; i += 5) {
        D_L39_004998A0[m + ((k + i) & 7) * 255] = *d++;
    }
}

/* zero store: no separate key copy (retail) */
static __inline__ void ClrSet_0064EA40(u8 *q) {
    Buf_0064EA40 buf;
    u32 key;
    s32 k;
    s32 m;
    s32 i;
    u8 *d;

    Prep_0064EA40(q);
    key = ((u32 *)D_L39_004998A0)[((u32)q * D_L39_0024BAC8) % 510];
    k = ((u32)q - *q) & 7;
    buf.w[0] = (u32)q ^ key;
    buf.w[1] = key;
    m = *q + 1;
    d = buf.b;
    for (i = 0; i < 40; i += 5) {
        D_L39_004998A0[m + ((k + i) & 7) * 255] = *d++;
    }
}

/* byte value, step 3 over the 255-stride table */
static __inline__ void SetB_0064EA40(u8 *q, u8 v) {
    u8 *hk = q;
    Buf_0064EA40 buf;
    u32 key;
    s32 k;
    s32 m;
    s32 i;
    u8 *d;

    Prep_0064EA40(q);
    buf.b[4] = v;
    key = ((u32 *)D_L39_004998A0)[((u32)hk * D_L39_0024BAC8) % 510];
    k = ((u32)q - *q) & 7;
    buf.w[1] = ((buf.w[1] & 0xFFFF) | (buf.w[1] << 16)) ^ key;
    buf.w[0] = (u32)q ^ key;
    m = *q + 1;
    d = buf.b;
    for (i = 0; i < 24; i += 3) {
        D_L39_004998A0[m + ((k + i) & 7) * 255] = *d++;
    }
}

/* 16-bit value, step 3 over the 255-stride table */
static __inline__ void Set16_0064EA40(u8 *q, s16 v) {
    u8 *hk = q;
    Buf_0064EA40 buf;
    u32 key;
    s32 k;
    s32 m;
    s32 i;
    u8 *d;

    Prep_0064EA40(q);
    key = ((u32 *)D_L39_004998A0)[((u32)hk * D_L39_0024BAC8) % 510];
    k = ((u32)q - *q) & 7;
    buf.h[2] = v;
    buf.w[0] = (u32)q ^ key;
    buf.w[1] = ((buf.w[1] & 0xFFFF) | (buf.w[1] << 16)) ^ key;
    m = *q + 1;
    d = buf.b;
    for (i = 0; i < 24; i += 3) {
        D_L39_004998A0[m + ((k + i) & 7) * 255] = *d++;
    }
}

static __inline__ s32 Dec3_0064EA40(u8 *q) {
    Buf_0064EA40 buf;
    u32 a;
    u32 b;
    s32 n;
    s32 k;
    s32 m;
    s32 i;
    u8 *d;

    if (*q == 0) {
        return 0;
    }
    n = *q;
    k = ((u32)q - n) & 7;
    m = n + 1;
    d = buf.b;
    for (i = 0; i < 24; i += 3) {
        *d++ = D_L39_00480820[((k + i) & 7) * 193 + m];
    }
    a = buf.w[0] ^ (u32)q;
    b = buf.w[1] ^ a;
    buf.w[0] = a;
    buf.w[1] = (b >> 16) / (((b ^ (b >> 16)) << 16) + 1);
    return buf.w[1];
}

static __inline__ void Prep3_0064EA40(u8 *q) {
    s32 t;
    if (*q == 0) {
        *q = ++D_L39_00480820[0];
    } else {
        t = *q;
        *q = D_L39_00480821[0];
        D_L39_00480821[0] = t;
    }
}

static __inline__ void Set3_0064EA40(u8 *q, u32 v) {
    u8 *hk = q;
    Buf_0064EA40 buf;
    u32 key;
    s32 k;
    s32 m;
    s32 i;
    u8 *d;

    Prep3_0064EA40(q);
    key = ((u32 *)D_L39_00480820)[((u32)hk * D_L39_0024BAC8) % 386];
    k = ((u32)q - *q) & 7;
    buf.w[1] = ((v & 0xFFFF) | (v << 16)) ^ key;
    buf.w[0] = (u32)q ^ key;
    m = *q + 1;
    d = buf.b;
    for (i = 0; i < 24; i += 3) {
        D_L39_00480820[((k + i) & 7) * 193 + m] = *d++;
    }
}

/* zero store: no separate key copy (retail) */
static __inline__ void ClrSet3_0064EA40(u8 *q) {
    Buf_0064EA40 buf;
    u32 key;
    s32 k;
    s32 m;
    s32 i;
    u8 *d;

    Prep3_0064EA40(q);
    key = ((u32 *)D_L39_00480820)[((u32)q * D_L39_0024BAC8) % 386];
    k = ((u32)q - *q) & 7;
    buf.w[1] = key;
    buf.w[0] = (u32)q ^ key;
    m = *q + 1;
    d = buf.b;
    for (i = 0; i < 24; i += 3) {
        D_L39_00480820[((k + i) & 7) * 193 + m] = *d++;
    }
}

static __inline__ s32 Busy_0064EA40(u8 *g) {
    return DecEq_0064EA40(g + 0x19E4, 1) || DecEq_0064EA40(g + 0x19E4, 0x1D) ||
           g[0x24FE] != 0 || g[0x2500] != 0;
}

static __inline__ s16 Dec16_0064EA40(u8 *q) {
    Buf_0064EA40 buf;
    u32 a;
    u32 b;
    s32 n;
    s32 k;
    s32 m;
    s32 i;
    u8 *d;

    if (*q == 0) {
        return 0;
    }
    n = *q;
    k = ((u32)q - n) & 7;
    m = n + 1;
    d = buf.b;
    for (i = 0; i < 24; i += 3) {
        *d++ = D_L39_004998A0[m + ((k + i) & 7) * 255];
    }
    a = buf.w[0] ^ (u32)q;
    b = buf.w[1] ^ a;
    buf.w[0] = a;
    buf.w[1] = (b >> 16) / (((b ^ (b >> 16)) << 16) + 1);
    return buf.h[2];
}

static __inline__ f32 DecF_0064EA40(u8 *q) {
    Buf_0064EA40 buf;
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

static __inline__ void SetState_0064EA40(u8 *g, s32 st) {
    (*(VT_0064EA40 **)(g + 0x14))->f34(g, st, 1, 0, 1);
}

static __inline__ void Copy3_0064EA40(f32 *d, f32 *a) {
    d[0] = a[0];
    d[1] = a[1];
    d[2] = a[2];
}

static __inline__ void Send_0064EA40(u8 *g, s32 c) {
    Pkt_0064EA40 pk;

    pk.b0 = g[0x2544];
    pk.b1 = c;
    pk.b2 = g[0x44ED];
    pk.b3 = g[0x44EE];
    Copy3_0064EA40(&pk.f4, (f32 *)(g + 0xA0));
    Copy3_0064EA40(&pk.f10, (f32 *)(g + 0xB0));
    if (D_001A5E50.w170 == 0) {
        func_0014AD08(D_001A5E50.b7D4 | 0x80, D_001A5E50.w4, -1, D_001D4E98_sda_0064C198, 0x1C, &pk);
    }
}

/* the packet of Send for the current command, decoded inside */
static __inline__ void SendCur_0064EA40(u8 *g) {
    Pkt_0064EA40 pk;

    pk.b0 = g[0x2544];
    pk.b1 = Dec_0064EA40(g + 0x19E4);
    pk.b2 = g[0x44ED];
    pk.b3 = g[0x44EE];
    Copy3_0064EA40(&pk.f4, (f32 *)(g + 0xA0));
    Copy3_0064EA40(&pk.f10, (f32 *)(g + 0xB0));
    if (D_001A5E50.w170 == 0) {
        func_0014AD08(D_001A5E50.b7D4 | 0x80, D_001A5E50.w4, -1, D_001D4E98_sda_0064C198, 0x1C, &pk);
    }
}

s32 func_L39_0064C198(u8 *g, u32 cmd, s32 a2, s32 a3, s32 a4) {
    s32 obj;
    s32 old;
    s32 f4C;
    s32 f50;

    if (a3 == 0 && func_L39_00634AC8() == 0) {
        return 0;
    }
    obj = *(s32 *)(g + 0x2524);
    func_L39_006335A0(g);
    SetNK_0064EA40(g + 0x19E4, cmd);
    old = Dec_0064EA40(g + 0x19E5);
    ClrSet_0064EA40(g + 0x19E5);
    f4C = g[0x1A0E];
    f50 = g[0x1A13];
    if (g[0x1A0A] == 1) {
        g[0x1A0A] = 0;
    }
    g[0x1A0C] = 0;
    g[0x24FE] = 0;
    g[0x24FF] = 0;
    g[0x2500] = 0;
    *(s32 *)(*(u8 **)(g + 0x2524) + 0x9C) = 0;
    SetB_0064EA40(g + 0x1A18, 0);
    g[0x1A0E] = 0;
    g[0x1A0B] = 0;
    if (*(s32 *)(g + 0x2D0) != 0) {
        g[0x1A13] = 0;
    }
    func_L01_0044B4B8(g + 0x1630);
    if (DecEq_0064EA40(g + 0x19E4, 0x66)) {
        *(s32 *)(g + 0x13D4) = 0;
    }
    if ((u8)Busy_0064EA40(g) == 0) {
        g[0x24FD] = 0;
    }
    if (*(s16 *)(g + 0x32E) == 0) {
        func_L01_003F0020(*(s32 *)(g + 0x2534));
    }
    func_L39_0062A388(g, Dec_0064EA40(g + 0x19E7), Dec_0064EA40(g + 0x19E4));

    switch (cmd) {
    case 0x0:
        ClrSet_0064EA40(g + 0x19E6);
        *(s32 *)(g + 0x2450) = 0;
        if (*(s32 *)(g + 0x478) == 2) {
            func_L39_0061FAE8(g);
        }
        *(s32 *)(g + 0x10A0) = func_L39_005B24C8(0x32, 0x64);
        func_L39_0061F590(g);
        *(u128_t *)(g + 0x190) = *(u128_t *)(g + 0x150);
        if (g[0x378] != 0 && *(s16 *)(g + 0x2DC) == 0) {
            SetState_0064EA40(g, 0x78);
            return 0;
        }
        if (a2 != 0) {
            func_L39_00628CD0(g, func_L39_0061FC10(g, 0), 0, 0, -1.0f);
        }
        break;
    case 0x66:
        ClrSet_0064EA40(g + 0x19E6);
        *(s32 *)(g + 0x2450) = 0;
        qzero(g + 0x190);
        if (a2 != 0) {
            func_L39_00628CD0(g, func_L39_0061FC10(g, 0), 0, 0, -1.0f);
        }
        break;
    case 0x39:
        Set_0064EA40(g + 0x19E6, 0x14);
        *(u128_t *)(g + 0x190) = *(u128_t *)(g + 0x150);
        *(s32 *)(g + 0x2450) = 0;
        if (a2 != 0) {
            func_L39_00628CD0(g, 0x34, 0, 0x18, 12.0f);
            func_L39_00637AE8(g);
        }
        break;
    case 0x90:
        Set_0064EA40(g + 0x19E6, 0x14);
        *(s32 *)(g + 0x2450) = 0;
        if (D_001A5990.bA4[*(s32 *)(g + 0x2544)] == 2) {
            func_L39_00644920(g, 1);
        }
        if (*(f32 *)(g + 0xA0) < 2.0f || 1021.0f < *(f32 *)(g + 0xA0) ||
            *(f32 *)(g + 0xA4) < 2.0f || 1021.0f < *(f32 *)(g + 0xA4) ||
            *(f32 *)(g + 0xA8) < 2.0f || 1021.0f < *(f32 *)(g + 0xA8)) {
            if (*(f32 *)(g + 0xA0) < 2.0f) {
                *(f32 *)(g + 0xA0) = 2.0f;
            }
            if (1021.0f < *(f32 *)(g + 0xA0)) {
                *(f32 *)(g + 0xA0) = 1021.0f;
            }
            if (*(f32 *)(g + 0xA4) < 2.0f) {
                *(f32 *)(g + 0xA4) = 2.0f;
            }
            if (1021.0f < *(f32 *)(g + 0xA4)) {
                *(f32 *)(g + 0xA4) = 1021.0f;
            }
            if (*(f32 *)(g + 0xA8) < 2.0f) {
                *(f32 *)(g + 0xA8) = 2.0f;
            }
            if (1021.0f < *(f32 *)(g + 0xA8)) {
                *(f32 *)(g + 0xA8) = 1021.0f;
            }
        }
        break;
    case 0x1:
        ClrSet_0064EA40(g + 0x19E6);
        *(s32 *)(g + 0x2450) = 4;
        if (DecEq_0064EA40(g + 0x19E8, 0xC)) {
            g[0x24FD] = 1;
        }
        func_L39_00644150(g);
        if (g[0x1A05] == 0) {
            s32 st = func_L39_0061FC10(g, 1);
            if (*(u8 *)(*(u8 **)(g + 0x2524) + 0x43) != st && a2 != 0) {
                func_L39_00628CD0(g, st, 0, 0, 18.0f);
            }
        }
        break;
    case 0x2:
    case 0x72:
        Set_0064EA40(g + 0x19E6, 1);
        *(s32 *)(g + 0x2450) = 0;
        if (!DecEq_0064EA40(g + 0x19E8, 4) && !DecEq_0064EA40(g + 0x19EB, 4)) {
            *(f32 *)(g + 0xFB4) = func_L39_0062FD90(g, g + 0x150);
        }
        *(u128_t *)(g + 0x1410) = *(u128_t *)(g + 0x20);
        *(f32 *)(g + 0x1428) = *(f32 *)(g + 0xB8);
        *(s32 *)(g + 0x1430) = 0;
        if (0.116666675f < *(f32 *)(g + 0xFB4)) {
            *(f32 *)(g + 0xFB4) = 0.116666675f;
        }
        g[0x142F] = 0;
        func_L39_00630530(g, 0, 1.0f);
        if (func_00389468(*(f32 *)(g + 0xB8), *(f32 *)(g + 0xFD0)) > 1.5707964f) {
            if (DecEq_0064EA40(g + 0x19E8, 4) || DecEq_0064EA40(g + 0x19E7, 3) ||
                DecEq_0064EA40(g + 0x19EA, 3)) {
                *(s32 *)(g + 0xFB4) = 0;
            }
        }
        if (g[0x378] != 0 && (*(s16 *)(g + 0x2DC) == 0 || *(f32 *)(g + 0x2AC) < 0.3f)) {
            SetState_0064EA40(g, 0x78);
            return 0;
        }
        ClrSet_0064EA40(g + 0x19E5);
        g[0x142C] = 0;
        g[0x142E] = 0;
        if (a2 != 0) {
            s32 n;
            s32 t;
            n = 8;
            t = DecF_0064EA40(g + 0x2476) == 1.0f;
            if (t) {
                n = 0xC;
            }
            if (DecEq_0064EA40(g + 0x19EA, 0x22) || DecEq_0064EA40(g + 0x19E7, 0x22)) {
                n = 0xF;
            }
            if (DecEq_0064EA40(g + 0x19EA, 0x85) || DecEq_0064EA40(g + 0x19E7, 0x85)) {
                n = 0xF;
            }
            if (DecEq_0064EA40(g + 0x19E7, 0x13)) {
                n = 0xD;
            }
            if (DecEq_0064EA40(g + 0x19EA, 6) || DecEq_0064EA40(g + 0x19EA, 0x2C)) {
                n = 0x12;
            }
            if (DecEq_0064EA40(g + 0x19EB, 4) && g[0x14AC] >= 6) {
                n = 0xD;
            }
            func_L39_00628CD0(g, Dec_0064EA40(g + 0x19E5) + 3, D_L39_00246198[Dec_0064EA40(g + 0x19E5)], 0, n);
        }
        break;
    case 0x7D:
        {
        s32 n7D;
        Set_0064EA40(g + 0x19E6, 0x1C);
        n7D = -2;
        *(u128_t *)(g + 0x120) = *(u128_t *)(g + 0x140);
        *(s32 *)(g + 0x2450) = 0;
        if (*(s32 *)(g + 0x4C8) != 0xF) {
            Set3_0064EA40(g + 0x1A26, *(s32 *)(g + 0x4C8));
            { s32 st = 0xF; Set3_0064EA40(g + 0x1A1A, st); }
        }
        if (a2 != 0) {
            func_L39_00628CD0(g, 0x3A, 0, 0, n7D);
        }
        }
        break;
    case 0x64:
        Set_0064EA40(g + 0x19E6, 1);
        *(s32 *)(g + 0x2450) = 0;
        *(f32 *)(g + 0xFB4) = func_003887A0(g + 0x150);
        g[0x1A0C] = 1;
        func_L39_0061FAE8(g);
        if (a2 != 0) {
            func_L39_00628CD0(g, Dec_0064EA40(g + 0x19E5) + 3, D_L39_00246198[Dec_0064EA40(g + 0x19E5)], 0, 8.0f);
        }
        break;
    case 0x3:
        Set_0064EA40(g + 0x19E6, 1);
        *(u128_t *)(g + 0x190) = *(u128_t *)(g + 0x150);
        *(s32 *)(g + 0x2450) = 0;
        if (g[0x378] != 0 && *(s16 *)(g + 0x2DC) == 0) {
            SetState_0064EA40(g, 0x78);
            return 0;
        }
        if (func_L39_006365A8(g) != 0) {
            return 0;
        }
        if (a2 != 0) {
            f32 f;
            s32 n;
            f = *(f32 *)(g + 0x628);
            n = 6;
            if (func_L39_0063A8A8(g, *(u8 *)(obj + 0x42)) == 4 && 3.0f < f && f < 16.0f) {
                n = 5;
            }
            func_L39_00628CD0(g, n, 4, 0, 9.0f);
        }
        break;
    case 0x65:
        Set_0064EA40(g + 0x19E6, 1);
        *(s32 *)(g + 0x2450) = 0;
        *(f32 *)(g + 0xFB4) = func_L39_0062FD90(g, g + 0x150);
        *(u128_t *)(g + 0x190) = *(u128_t *)(g + 0x150);
        if (a2 != 0) {
            f32 f;
            s32 n;
            f = *(f32 *)(g + 0x628);
            n = 6;
            if (func_L39_0063A8A8(g, *(u8 *)(obj + 0x42)) == 4 && 3.0f < f && f < 16.0f) {
                n = 5;
            }
            func_L39_00628CD0(g, n, 4, 0, 9.0f);
        }
        break;
    case 0x4:
        Set_0064EA40(g + 0x19E6, 0xC);
        *(s32 *)(g + 0x2450) = 0;
        *(f32 *)(g + 0xFB4) = func_003887A0(g + 0x150);
        if (0.116666675f < *(f32 *)(g + 0xFB4)) {
            *(f32 *)(g + 0xFB4) = 0.116666675f;
        }
        if (g[0x378] != 0 && *(s16 *)(g + 0x2DC) == 0) {
            SetState_0064EA40(g, 0x78);
            return 0;
        }
        *(u128_t *)(g + 0x190) = *(u128_t *)(g + 0x150);
        func_003BF640(g + 0x190, 0.116666675f);
        if (0.058333337f < *(f32 *)(g + 0x1A8)) {
            func_L39_006377E8(g, 9, 0);
        }
        if (a2 != 0) {
            if (*(u8 *)(*(u8 **)(g + 0x2524) + 0x42) == func_L39_0061FC10(g, 0)) {
                func_L39_00628CD0(g, 0xD, 2, 0, 9.0f);
            } else {
                func_L39_00628CD0(g, 0xD, 2, 0, 14.0f);
            }
            func_L39_00628F00(g, 3, 0x12);
        }
        func_L39_006544D8(g);
        break;
    case 0x2B:
        Set_0064EA40(g + 0x19E6, 0xE);
        {
            u8 *o = *(u8 **)(g + 0x15E0);
            qzero(g + 0xC0);
            *(s32 *)(g + 0x2450) = 7;
            *(u8 **)(g + 0x15E4) = o;
            *(s16 *)(g + 0x15EC) = 0;
            *(s32 *)(g + 0x15F8) = 0;
            *(s16 *)(g + 0x160C) = 0;
            *(s16 *)(g + 0x160E) = 1;
            g[0x1A0C] = 1;
            *(f32 *)(g + 0x1614) = 0.025f;
            *(f32 *)(g + 0x1618) = 0.33f;
            *(f32 *)(g + 0x161C) = 0.18333334f;
            *(s16 *)(g + 0x332) = 0x28;
            *(s32 *)(g + 0x1604) = 0;
            *(s32 *)(g + 0x1608) = 0;
            if (o != 0) {
                u8 *p = *(u8 **)(o + 0x68);
                *(f32 *)(g + 0x15F0) = *(f32 *)(p + 0x4);
                if (*(f32 *)(p + 0x10) == *(f32 *)(g + 0x15F8)) {
                    *(f32 *)(p + 0x14) = *(f32 *)(p + 0xC);
                } else {
                    *(f32 *)(p + 0x14) = *(f32 *)(p + 0x10);
                }
                if (*(f32 *)(p + 0x24) != 0.0f) {
                    *(f32 *)(g + 0x1614) = *(f32 *)(p + 0x24);
                }
                if (*(f32 *)(p + 0x28) != 0.0f) {
                    *(f32 *)(g + 0x1618) = *(f32 *)(p + 0x28);
                }
                if (*(f32 *)(p + 0x2C) != 0.0f) {
                    *(f32 *)(g + 0x161C) = *(f32 *)(p + 0x2C);
                }
                *(f32 *)(g + 0x15FC) = func_00388A28(*(f32 *)(*(u8 **)(g + 0x15E4) + 0x10) - *(f32 *)(g + 0xA0),
                                                     *(f32 *)(*(u8 **)(g + 0x15E4) + 0x14) - *(f32 *)(g + 0xA4));
                *(f32 *)(g + 0x15F4) = func_003887C8(g + 0xA0, *(u8 **)(g + 0x15E4) + 0x10);
            }
        }
        *(f32 *)(g + 0x1600) = 0.0075000003f;
        if (DecEq_0064EA40(g + 0x19E8, 4)) {
            *(f32 *)(g + 0x1600) = *(f32 *)(g + 0x1530);
        } else if (DecEq_0064EA40(g + 0x19E8, 2)) {
            *(f32 *)(g + 0x1600) = *(f32 *)(g + 0x15C0);
        }
        if (a2 != 0) {
            func_L39_00628CD0(g, 0x2C, 0, 0, 11.0f);
            *(f32 *)(g + 0x610) = 0.7f;
        }
        break;
    case 0x2C:
        Set_0064EA40(g + 0x19E6, 2);
        *(s32 *)(g + 0x2450) = 7;
        qzero(g + 0xC0);
        *(u128_t *)(g + 0x120) = *(u128_t *)(g + 0x150);
        if (a2 != 0) {
            func_L39_00628CD0(g, 0xB, 0, 0, 15.0f);
        }
        break;
    case 0x17:
        Set_0064EA40(g + 0x19E6, 3);
        *(s32 *)(g + 0x2450) = 0xD;
        *(f32 *)(g + 0x156C) = 0.0061111115f;
        *(f32 *)(g + 0x1570) = *(f32 *)(g + 0xA8);
        if (DecEq_0064EA40(g + 0x19E8, 4)) {
            *(f32 *)(g + 0x156C) = *(f32 *)(g + 0x1530);
            *(f32 *)(g + 0x1570) = *(f32 *)(g + 0x14A0);
        }
        g[0x1A0B] = 1;
        g[0x1A0C] = 1;
        if (*(s32 *)(g + 0x478) == 2) {
            func_L39_0061FAE8(g);
        }
        if (a2 != 0) {
            if (0.058333337f < *(f32 *)(g + 0x1A4)) {
                func_L39_00628CD0(g, 0x20, 0, 0, 9.0f);
            } else {
                func_L39_00628CD0(g, 0x20, 1, 0, 11.0f);
            }
        }
        if (g[0x1A14] != 0) {
            Send_0064EA40(g, 0x17);
        }
        break;
    case 0x18:
        Set_0064EA40(g + 0x19E6, 3);
        *(s32 *)(g + 0x2450) = 0xD;
        g[0x1A0B] = 1;
        g[0x1A0C] = 1;
        if (a2 != 0) {
            func_L39_00628CD0(g, 0x21, 0, 0, 6.0f);
        }
        break;
    case 0x19:
        Set_0064EA40(g + 0x19E6, 3);
        *(s32 *)(g + 0x2450) = 0xD;
        g[0x1A0B] = 1;
        g[0x1A0C] = 1;
        if (a2 != 0) {
            func_L39_00628CD0(g, 0x23, 0, 0, 6.0f);
        }
        break;
    case 0x1A:
        Set_0064EA40(g + 0x19E6, 3);
        *(s32 *)(g + 0x2450) = 0xD;
        g[0x1A0B] = 1;
        g[0x1A0C] = 1;
        if (a2 != 0) {
            func_L39_00628CD0(g, 0x24, 0, 0, 6.0f);
        }
        break;
    case 0x78:
        Set_0064EA40(g + 0x19E6, 2);
        *(s32 *)(g + 0x2450) = 0;
        *(u128_t *)(g + 0x120) = *(u128_t *)(g + 0x150);
        if (a2 != 0) {
            func_L39_00628CD0(g, 0xB, 0, 0, 12.0f);
        }
        break;
    case 0x6:
    case 0x76:
        Set_0064EA40(g + 0x19E6, 2);
        *(s32 *)(g + 0x2450) = 0;
        if (DecEq_0064EA40(g + 0x19E4, 0x76)) {
            Set_0064EA40(g + 0x19E6, 0x14);
        }
        *(f32 *)(g + 0x15C0) = 0.0061111115f;
        *(f32 *)(g + 0x15C4) = 0.0019444445f;
        ClrSet_0064EA40(g + 0x19E5);
        if (DecEq_0064EA40(g + 0x19E4, 0x76)) {
            if (a4 != 0) {
                *(s16 *)(g + 0x2490) = func_L39_006377E8(g, 0xE, 0x20);
                *(f32 *)(g + 0x15D0) = func_L39_005B2568(0.052359883f, 0.072722055f);
                *(f32 *)(g + 0x15D4) = func_L39_005B2568(0.052359883f, 0.072722055f);
            } else {
                Set_0064EA40(g + 0x19E5, 8);
                *(s32 *)(g + 0x15C0) = 0;
                *(f32 *)(g + 0x15C4) = 0.0019444445f;
                *(s32 *)(g + 0x15D0) = 0;
                *(s32 *)(g + 0x15D4) = 0;
            }
        }
        *(u128_t *)(g + 0x120) = *(u128_t *)(g + 0x150);
        if (a2 != 0) {
            if (1.75f < *(f32 *)(g + 0x2AC)) {
                func_L39_00628CD0(g, 0xB, 0, 0, 12.0f);
                Set_0064EA40(g + 0x19E5, 1);
            } else {
                func_L39_00628CD0(g, 0xA, 0, 0, 10.0f);
            }
        }
        break;
    case 0x7:
    case 0x9:
    case 0xA:
    case 0xB:
    case 0xC:
    case 0xD:
    case 0xE:
    case 0xF:
    case 0x10:
    case 0x11:
    case 0x12:
    case 0x1B:
    case 0x28:
    case 0x29:
    case 0x38:
    case 0x68:
    case 0x70:
    case 0x83:
        if (!DecEq_0064EA40(g + 0x19E4, 0x83) && *(s32 *)(g + 0x2CC) != 0 && *(s32 *)(g + 0x2D0) != 0 &&
            *(s16 *)(*(u8 **)(g + 0x2CC) + 0xAA) == 0x10C4) {
            SetState_0064EA40(g, 0x83);
            return 0;
        }
        if (!DecEq_0064EA40(g + 0x19E4, 0x70) && *(s16 *)(g + 0x2D8) == 1 && cmd != 0xE && cmd != 0x38 &&
            D_001D72B0_sda_0064C198 == 0) {
            SetState_0064EA40(g, 0x70);
            return 0;
        }
        if (Dec16_0064EA40(g + 0x318) != 0) {
            { u8 *q = g + 0x19E4; Set_0064EA40(q, Dec_0064EA40(g + 0x19E7)); }
            Set_0064EA40(g + 0x19E5, old);
            *(s32 *)(g + 0x2F0) = Dec_0064EA40(g + 0x19E9);
            return 0;
        }
        Set_0064EA40(g + 0x19E6, 4);
        if (cmd == 0x28 || cmd == 0x29) {
            *(s32 *)(g + 0x2450) = 3;
        } else {
            *(s32 *)(g + 0x2450) = 0x50;
        }
        if (DecEq_0064EA40(g + 0x19E4, 7) || DecEq_0064EA40(g + 0x19E4, 0xF) || DecEq_0064EA40(g + 0x19E4, 0xD) ||
            (DecEq_0064EA40(g + 0x19E4, 0xB) && !DecEq_0064EA40(g + 0x19E8, 4))) {
            s32 n;
            n = g[0x37B];
            func_L39_00637C98(g, n, 0, 0, 0x1E);
            func_L39_00637C98(g, n, 1, 0, 0x1E);
        }
        *(u128_t *)(g + 0x120) = *(u128_t *)(g + 0x150);
        if (*(s32 *)(g + 0x2C8) != 0 && *(f32 *)(g + 0xA8) < *(f32 *)(g + 0x2C0) + 0.5f) {
            func_L39_00645780(g, 3, 0x10, 0);
        }
        *(f32 *)(g + 0x14A0) = *(f32 *)(g + 0xA8);
        *(f32 *)(g + 0x1530) = 0.00825f;
        *(s32 *)(g + 0x1458) = -1;
        *(f32 *)(g + 0x1510) = 0.0055555557f;
        *(f32 *)(g + 0x1514) = 0.0030555557f;
        *(f32 *)(g + 0x1520) = 2.5f;
        *(s16 *)(g + 0x1538) = g[0x372];
        *(s16 *)(g + 0x152A) = 0x50;
        *(s16 *)(g + 0x153A) = 0x46;
        *(f32 *)(g + 0x1524) = 0.5f;
        *(f32 *)(g + 0x14B4) = 0.12083334f;
        *(f32 *)(g + 0x14A4) = 0.25016388f;
        *(f32 *)(g + 0x14B0) = 0.8333334f;
        g[0x14AE] = 0;
        g[0x14AC] = 0;
        *(s32 *)(g + 0x14C0) = 0;
        *(s32 *)(g + 0x14C4) = 0;
        g[0x14AD] = 0;
        *(s16 *)(g + 0x1534) = 0;
        g[0x153C] = 0;
        g[0x153E] = 0;
        g[0x153F] = 0;
        *(s16 *)(g + 0x1536) = 0;
        *(s32 *)(g + 0x1468) = 0;
        g[0x14AF] = 0;
        *(s16 *)(g + 0x2492) = 0;
        if (DecEq_0064EA40(g + 0x19E4, 7)) {
            *(f32 *)(g + 0x14C8) = 0.6f;
            *(f32 *)(g + 0x14D8) = 18.0f;
            *(f32 *)(g + 0x14DC) = 30.0f;
            *(f32 *)(g + 0x14E0) = 12.0f;
            *(f32 *)(g + 0x151C) = 2.7f;
            *(f32 *)(g + 0x14B8) = 1.42f;
            *(s16 *)(g + 0x14BC) = 1;
            g[0x153C] = 1;
            g[0x153E] = 1;
            *(f32 *)(g + 0x1518) = 1.42f;
            *(s16 *)(g + 0x1528) = 0x11;
            g[0x153F] = 1;
            *(f32 *)(g + 0x1468) = *(f32 *)(g + 0x1530) * 1.17f;
        } else if (DecEq_0064EA40(g + 0x19E4, 0x83)) {
            *(s16 *)(g + 0x14BC) = 1;
            *(f32 *)(g + 0x14C8) = 0.6f;
            *(f32 *)(g + 0x14D8) = 18.0f;
            *(f32 *)(g + 0x14DC) = 30.0f;
            *(f32 *)(g + 0x14E0) = 12.0f;
            *(f32 *)(g + 0x151C) = *(f32 *)(g + 0x2498) + 0.5f;
            *(f32 *)(g + 0x1518) = *(f32 *)(g + 0x14B8) = *(f32 *)(g + 0x2498);
            *(s16 *)(g + 0x1528) = 0x11;
            *(s16 *)(g + 0x152A) = 0x190;
            *(f32 *)(g + 0x1520) = 300.0f;
            *(f32 *)(g + 0x1530) = *(f32 *)(g + 0x249C) * 0.00027777778f;
            *(s16 *)(g + 0x153A) = *(s16 *)(g + 0x1536) = 0x4B0;
            *(f32 *)(g + 0x14B4) = 0.116666675f;
            if (g[0x1A14] == 0 || *(s32 *)(g + 0x1310) != 2) {
                func_L01_0044B090(*(s32 *)(g + 0x2524), g + 0x1630);
                func_L01_0044B0B8(g + 0x1630, 0x46, 2, 0.0f);
                func_L01_0044B0B8(g + 0x1630, 0x23, 4, 0.0f);
                func_L01_0044B0B8(g + 0x1630, 0x11, 6, 0.0f);
            }
        } else if (DecEq_0064EA40(g + 0x19E4, 9)) {
            *(f32 *)(g + 0x14C8) = 0.6f;
            *(f32 *)(g + 0x14D8) = 18.0f;
            *(f32 *)(g + 0x14DC) = 29.0f;
            *(f32 *)(g + 0x14E0) = 10.0f;
            *(f32 *)(g + 0x151C) = 2.7f;
            *(f32 *)(g + 0x1518) = *(f32 *)(g + 0x14B8) = 1.42f;
            *(s16 *)(g + 0x1528) = 0x11;
            *(f32 *)(g + 0x14B4) = 0.12083334f;
            *(s16 *)(g + 0x14BC) = 1;
            g[0x153C] = 1;
            g[0x153E] = 1;
            g[0x153F] = 1;
        } else if (DecEq_0064EA40(g + 0x19E4, 0x70)) {
            *(f32 *)(g + 0x14C8) = 0.6f;
            *(f32 *)(g + 0x14D8) = 18.0f;
            *(f32 *)(g + 0x14DC) = 30.0f;
            *(f32 *)(g + 0x14E0) = 12.0f;
            *(f32 *)(g + 0x151C) = 2.75f;
            *(f32 *)(g + 0x1518) = *(f32 *)(g + 0x14B8) = 2.7f;
            *(s16 *)(g + 0x1528) = *(s16 *)(g + 0x14BC) = 5;
            g[0x14AF] = g[0x153C] = 1;
            *(f32 *)(g + 0x14B4) = *(f32 *)(g + 0x14B4) * 1.17f;
            g[0x153E] = 0;
            g[0x153F] = 0;
        } else if (DecEq_0064EA40(g + 0x19E4, 0xA)) {
            *(s16 *)(g + 0x14BC) = 5;
            *(f32 *)(g + 0x14C8) = 0.6f;
            *(f32 *)(g + 0x14D8) = 18.0f;
            *(f32 *)(g + 0x14DC) = 29.0f;
            *(f32 *)(g + 0x14E0) = 10.0f;
            *(f32 *)(g + 0x151C) = 1.95f;
            *(f32 *)(g + 0x1518) = *(f32 *)(g + 0x14B8) = 1.9f;
            *(s16 *)(g + 0x1528) = 0xE;
            *(f32 *)(g + 0x1530) = 0.0030555557f;
            g[0x153E] = 1;
            *(s16 *)(g + 0x152A) = 0x78;
            *(s16 *)(g + 0x153A) = 0x5A;
            *(s16 *)(g + 0x1536) = 0x46;
        } else if (DecEq_0064EA40(g + 0x19E4, 0x10)) {
            *(s16 *)(g + 0x14BC) = 5;
            *(f32 *)(g + 0x14C8) = 0.8f;
            *(f32 *)(g + 0x14D8) = 18.0f;
            *(f32 *)(g + 0x14DC) = 30.0f;
            *(f32 *)(g + 0x14E0) = 11.0f;
            *(f32 *)(g + 0x151C) = 1.55f;
            *(f32 *)(g + 0x1518) = *(f32 *)(g + 0x14B8) = 1.5f;
            *(s16 *)(g + 0x1528) = 1;
            func_L01_003EFFE0(0x14, *(s32 *)(g + 0x2534));
            *(f32 *)(g + 0x1518) = *(f32 *)(g + 0x14B8) = 0.4f;
            *(f32 *)(g + 0x151C) = 0.9f;
            if ((g[0x1A14] == 0 || *(s32 *)(g + 0x1310) != 2) && *(f32 *)(g + 0x1B4) < 0.33333334f) {
                func_L01_0044B090(*(s32 *)(g + 0x2524), g + 0x1630);
                func_L01_0044B0B8(g + 0x1630, 0x28, 2, 0.0f);
                func_L01_0044B0B8(g + 0x1630, 0x14, 4, 0.0f);
                func_L01_0044B0B8(g + 0x1630, 0xA, 6, 0.0f);
            }
            g[0x153E] = 1;
            *(f32 *)(g + 0x1464) = 0.19166668f;
            if (1.4f < *(f32 *)(g + 0x2AC)) {
                *(f32 *)(g + 0x1464) = 0.095f;
            }
            *(f32 *)(g + 0x1530) = 0.002361111f;
            *(f32 *)(g + 0x1510) = 0.012222223f;
            *(f32 *)(g + 0x1514) = 0.013888889f;
        } else if (DecEq_0064EA40(g + 0x19E4, 0x1B)) {
            *(s16 *)(g + 0x14BC) = 0xA;
            *(f32 *)(g + 0x14C8) = 0.85f;
            *(f32 *)(g + 0x14D8) = 20.0f;
            *(f32 *)(g + 0x14DC) = 29.0f;
            *(f32 *)(g + 0x14E0) = 10.0f;
            *(f32 *)(g + 0x151C) = 2.05f;
            *(f32 *)(g + 0x1518) = *(f32 *)(g + 0x14B8) = 2.0f;
            *(f32 *)(g + 0x1524) = 1.0f;
            *(f32 *)(g + 0x1530) = 0.0069444445f;
            *(s16 *)(g + 0x1528) = 1;
            *(s32 *)(g + 0x14CC) = 0;
            g[0x14AF] = 1;
            g[0x1A0B] = 1;
            g[0x1A0C] = 1;
            g[0x153E] = 1;
        } else if (DecEq_0064EA40(g + 0x19E4, 0x11)) {
            *(s16 *)(g + 0x14BC) = 9;
            *(f32 *)(g + 0x14C8) = 0.6f;
            *(f32 *)(g + 0x14D8) = 12.0f;
            *(f32 *)(g + 0x14DC) = 20.0f;
            *(f32 *)(g + 0x14E0) = 10.0f;
            *(s16 *)(g + 0x1528) = 0xC;
            if (g[0x2494] != 0) {
                *(f32 *)(g + 0x14A8) = 0.08166667f;
                *(f32 *)(g + 0x151C) = 3.35f;
                *(f32 *)(g + 0x1518) = 3.3f;
            } else {
                *(f32 *)(g + 0x14A8) = 0.028333336f;
                *(f32 *)(g + 0x151C) = 1.85f;
                *(f32 *)(g + 0x1518) = 1.8f;
            }
            *(f32 *)(g + 0x14B8) = *(f32 *)(g + 0x1518);
            g[0x14AF] = 1;
            func_L01_003EFFE0(0x1B, *(s32 *)(g + 0x2534));
            *(s16 *)(g + 0x153A) = 0x50;
            *(f32 *)(g + 0x1530) = 0.008055556f;
            *(u128_t *)(g + 0x1500) = *(u128_t *)(g + 0x14F0);
            *(s16 *)(g + 0x2492) = 1;
            g[0x1A0E] = 1;
            g[0x153C] = 1;
        } else if (DecEq_0064EA40(g + 0x19E4, 0xD)) {
            *(s16 *)(g + 0x14BC) = 9;
            *(f32 *)(g + 0x14C8) = 0.6f;
            *(f32 *)(g + 0x14D8) = 26.0f;
            *(f32 *)(g + 0x14DC) = 38.0f;
            *(f32 *)(g + 0x14E0) = 18.0f;
            *(f32 *)(g + 0x151C) = 4.07f;
            *(s16 *)(g + 0x1528) = 0xE;
            *(f32 *)(g + 0x1518) = *(f32 *)(g + 0x14B8) = 4.0f;
            func_L01_003EFFE0(0x14, *(s32 *)(g + 0x2534));
            *(f32 *)(g + 0x1520) = 4.5f;
            *(s16 *)(g + 0x152A) = 0x78;
            *(f32 *)(g + 0x14B4) = 0.031666666f;
            *(s16 *)(g + 0x1536) = 0x25;
            if ((g[0x1A14] == 0 || *(s32 *)(g + 0x1310) != 2) && *(f32 *)(g + 0x1B4) < 0.33333334f) {
                func_L01_0044B090(*(s32 *)(g + 0x2524), g + 0x1630);
                func_L01_0044B0B8(g + 0x1630, 0x28, 3, 0.0f);
                func_L01_0044B0B8(g + 0x1630, 0x14, 5, 0.0f);
            }
            g[0x153E] = 1;
        } else if (DecEq_0064EA40(g + 0x19E4, 0xE)) {
            f32 f;
            f = 0.7f;
            if (*(f32 *)(g + 0x2AC) < 2.0f) {
                f = (2.5f - *(f32 *)(g + 0x2AC)) * 0.5f + f;
            }
            *(s16 *)(g + 0x14BC) = -1;
            *(f32 *)(g + 0x14C8) = 0.6f;
            *(f32 *)(g + 0x14D8) = 32.0f;
            *(f32 *)(g + 0x14DC) = 43.0f;
            *(f32 *)(g + 0x14E0) = 19.0f;
            *(f32 *)(g + 0x151C) = f + 0.05f;
            *(f32 *)(g + 0x1518) = *(f32 *)(g + 0x14B8) = f;
            *(s16 *)(g + 0x1528) = 0xE;
            *(f32 *)(g + 0x1524) = 1.0f;
            *(f32 *)(g + 0x14B4) = 0.07916667f;
            *(s16 *)(g + 0x1536) = 0x1E;
        } else if (DecEq_0064EA40(g + 0x19E4, 0xB)) {
            *(f32 *)(g + 0x14C8) = 0.6f;
            *(f32 *)(g + 0x14D8) = 18.0f;
            *(f32 *)(g + 0x14DC) = 31.0f;
            *(f32 *)(g + 0x151C) = 3.25f;
            *(f32 *)(g + 0x1518) = *(f32 *)(g + 0x14B8) = 3.2f;
            *(f32 *)(g + 0x14E0) = 24.0f;
            *(s16 *)(g + 0x14BC) = 1;
            *(s16 *)(g + 0x1528) = 0xE;
            *(f32 *)(g + 0x1520) = 4.5f;
            *(s16 *)(g + 0x153A) = 0x32;
            *(f32 *)(g + 0x1524) = 1.0f;
            g[0x14AF] = 1;
            *(f32 *)(g + 0x14D4) = func_L39_0062F240(g, 10);
            *(u128_t *)(g + 0x1490) = *(u128_t *)(g + 0x20);
            *(s32 *)(g + 0x14E4) = func_L39_00627608(g);
            *(f32 *)(g + 0x14D0) = *(f32 *)(g + 0xFD0);
            *(u128_t *)(g + 0x1480) = *(u128_t *)(g + 0xFC0);
            if (0.025000002f < *(f32 *)(g + 0x1A4)) {
                *(f32 *)(g + 0x14E8) = *(f32 *)(g + 0x1A4);
            } else {
                *(s32 *)(g + 0x14E8) = 0;
            }
            g[0x153C] = 1;
            *(s32 *)(g + 0x14EC) = 0;
            if ((*(s16 *)(g + 0x3E4) == 0 &&
                 (*(s32 *)(g + 0x1310) != 1 || func_L01_0045D358(0x28, 2, 0, *(s32 *)(g + 0x2534)) == 0 ||
                  func_L39_0061EB48(g) == 10)) ||
                DecEq_0064EA40(g + 0x19E4, 0x10)) {
                g[0x153D] = 0;
            } else if (0.3f < *(f32 *)(g + 0x2468)) {
                func_L39_00630530(g, 0, *(f32 *)(g + 0xFB0));
                *(f32 *)(g + 0x14D0) = *(f32 *)(g + 0xFD0);
                *(u128_t *)(g + 0x1480) = *(u128_t *)(g + 0x3D0);
                *(f32 *)(g + 0x14EC) = 0.083333336f;
                g[0x153D] = 1;
            } else {
                g[0x153D] = 0;
            }
            g[0x153E] = 1;
        }
        if (*(f32 *)(g + 0x1520) == 0.0f) {
            *(f32 *)(g + 0x1520) = *(f32 *)(g + 0x14B8) * 1.5f;
        }
        if (a2 == 0) {
            break;
        }
        if (DecEq_0064EA40(g + 0x19E4, 7)) {
            func_L39_00628CD0(g, 7, 1, 0, -4.0f);
        } else if (DecEq_0064EA40(g + 0x19E4, 0x70)) {
            func_L39_00628CD0(g, 7, 0, 0, 5.0f);
        } else if (DecEq_0064EA40(g + 0x19E4, 0x83)) {
            func_L39_00628CD0(g, 7, 0, 0, 5.0f);
        } else if (DecEq_0064EA40(g + 0x19E4, 9)) {
            s32 n;
            s32 t;
            n = 8;
            t = *(f32 *)(g + 0x628);
            if (func_L39_0063A8A8(g, *(u8 *)(obj + 0x42)) == 4) {
                n = D_L39_002461A0[t];
            }
            func_L39_00628CD0(g, n, 0, 0, 5.0f);
        } else if (DecEq_0064EA40(g + 0x19E4, 0xA)) {
            func_L39_00628CD0(g, 0x12, 0, 0, 5.0f);
        } else if (DecEq_0064EA40(g + 0x19E4, 0x10)) {
            if (DecEq_0064EA40(g + 0x19E8, 4) || (DecEq_0064EA40(g + 0x19E7, 4) && *(s32 *)(g + 0x2F0) < 7)) {
                func_L39_00628CD0(g, 0x25, 0, 0, 8.0f);
                *(u16 *)(g + 0x14BC) += 3;
            } else {
                func_L39_00628CD0(g, 0x25, 0, 0, 5.0f);
            }
        } else if (DecEq_0064EA40(g + 0x19E4, 0x1B)) {
            func_L39_00628CD0(g, 0x22, 0, 0, 4.0f);
        } else if (DecEq_0064EA40(g + 0x19E4, 0xD)) {
            func_L39_00628CD0(g, 0x11, 0, 0, 5.0f);
        } else if (DecEq_0064EA40(g + 0x19E4, 0xE)) {
            func_L39_00628CD0(g, 0x16, 3, 0, 7.0f);
            *(f32 *)(g + 0x610) = 0.8f;
        } else if (DecEq_0064EA40(g + 0x19E4, 0xF)) {
            func_L39_00628CD0(g, 0x15, 0, 0, 5.0f);
        } else if (DecEq_0064EA40(g + 0x19E4, 0xB)) {
            s32 n;
            n = *(s32 *)(g + 0x14E4) + 0x1C;
            if (DecEq_0064EA40(g + 0x19E8, 4)) {
                func_L39_00628CD0(g, n, 1, 0, 4.0f);
                *(s16 *)(g + 0x14BC) = 1;
            } else {
                func_L39_00628CD0(g, n, 0, 0, 5.0f);
            }
        }
        break;
    case 0x13:
    case 0x14:
    case 0x15:
    case 0x1F:
    case 0x22:
    case 0x85:
        Set_0064EA40(g + 0x19E6, 6);
        if (cmd != 0x85) {
            *(s32 *)(g + 0x2450) = 0;
        }
        *(f32 *)(g + 0x1074) = 1.0f;
        *(s32 *)(g + 0x1068) = 0;
        *(s32 *)(g + 0x1064) = 0;
        *(s16 *)(g + 0x107E) = 0;
        switch ((s32)Dec_0064EA40(g + 0x19E4)) {
        case 0x14:
            if (D_L39_00200420[0].h0 < 0xFFFF) {
                D_L39_00200420[0].h0++;
            }
            {
                s32 lim = D_001D4C78_sda_0064C198;
                if (D_L39_00200420[0].w4 < (u32)lim) {
                    D_L39_00200420[0].w4 = lim;
                }
            }
            D_L39_00200420[0].w8 = D_L39_00200420[0].w8 | (1 << D_001D5BCC_sda_0064C198) | 0x80000000;
            *(s32 *)(g + 0x2450) = 0x50;
            ClrSet3_0064EA40(g + 0x1A25);
            *(s16 *)(g + 0x107C) = 4;
            func_L39_0062D4A8(g, 8.0f, 1.0471976f, -1.0f);
            *(s32 *)(g + 0x1080) = 0;
            if (a2 != 0) {
                void *o;
                s32 n;
                n = 0xB;
                if (DecEq_0064EA40(g + 0x19E7, 0xB) && DecLt_0064EA40(g + 0x19E9, 0x2A)) {
                    n = 0x11;
                }
                func_L39_00628CD0(g, 0x27, 4, 0, n);
                o = 0;
                if (*(s32 *)(g + 0x474) == 2) {
                    o = *(void **)(g + 0x450);
                }
                if (func_L39_00639598(g, o)) {
                    func_003BE4F0(o, 0xA, 4, n + 2);
                }
            }
            break;
        case 0x15:
            if (D_L39_00200420[1].h0 < 0xFFFF) {
                D_L39_00200420[1].h0++;
            }
            {
                s32 lim = D_001D4C78_sda_0064C198;
                if (D_L39_00200420[1].w4 < (u32)lim) {
                    D_L39_00200420[1].w4 = lim;
                }
            }
            D_L39_00200420[1].w8 = D_L39_00200420[1].w8 | (1 << D_001D5BCC_sda_0064C198) | 0x80000000;
            ClrSet3_0064EA40(g + 0x1A25);
            *(s16 *)(g + 0x107C) = 3;
            func_L39_0062D4A8(g, 14.0f, 0.5235988f, -1.0f);
            *(s32 *)(g + 0x108C) = *(s32 *)(g + 0x108C) == 0;
            if ((*(s16 *)(g + 0x3E4) != 0 ||
                 (*(s32 *)(g + 0x1310) == 1 && func_L01_0045D358(0x28, 2, 0, *(s32 *)(g + 0x2534)) != 0 &&
                  func_L39_0061EB48(g) != 10)) &&
                !DecEq_0064EA40(g + 0x19E4, 0x10)) {
                *(s32 *)(g + 0x1068) = 1;
                *(f32 *)(g + 0x106C) = *(f32 *)(g + 0xB8);
            }
            if (a2 != 0) {
                s32 n;
                n = 5;
                if (*(u8 *)(*(u8 **)(g + 0x2524) + 0x43) == 0x1A) {
                    n = 3;
                }
                if (DecEq_0064EA40(g + 0x19E7, 1) && g[0x24FE] == 0) {
                    n = 0x11;
                }
                func_L39_00628CD0(g, 0x1A, 0, 0, n);
                func_L39_00628F00(g, 6, 0x15);
            }
            break;
        case 0x13: {
            Tune_0064EA40 *e;
            s32 k;
            s32 m;
            s32 c;
            void *o;

            ClrSet3_0064EA40(g + 0x1A25);
            e = &D_L39_0047A968[*(s16 *)(g + 0x107C)];
            k = 0;
            if ((DecEq_0064EA40(g + 0x19E7, 0x13) && *(f32 *)(g + 0x628) < (f32)e->w8) ||
                (DecEq_0064EA40(g + 0x19EA, 0x13) && *(s32 *)(g + 0x2F0) + (s32)Dec_0064EA40(g + 0x19E9) < 0x1B)) {
                k = (e->w4 + 1) % 3;
            }
            *(s16 *)(g + 0x107C) = k;
            func_L39_0062D4A8(g, 5.0f, 0.7853982f, 0.7853982f);
            if (a2 != 0) {
                m = 0;
                if (k == 0) {
                    c = 5;
                } else if (k == 1) {
                    m = 2;
                    c = 7;
                } else {
                    m = 4;
                    c = 7;
                }
                if (*(s32 *)(g + 0x1068) != 0 && k < 2) {
                    f32 f;
                    if (g[0x1A06] != 0) {
                        f = func_L39_00631430(g, g + 0x1040, 0);
                    } else {
                        f = func_00389468(*(f32 *)(g + 0x106C), *(f32 *)(g + 0xB8));
                    }
                    c += (s32)(f * 1.5f);
                }
                m = m / 2;
                func_L39_00628CD0(g, k + 0x17, m, 0, c);
                o = 0;
                if (*(s32 *)(g + 0x474) == 2) {
                    o = *(void **)(g + 0x450);
                }
                if (func_L39_00639598(g, o)) {
                    func_003BE4F0(o, k + 3, m, c);
                }
            }
            break;
        }
        case 0x22:
            (*(VT30_0064EA40 **)(g + 0x14))->f30(g);
            if (a2 != 0) {
                func_L39_00628CD0(g, 0x28, 7, 0, 9.0f);
                g[0x1A07] = 1;
                *(s32 *)(g + 0x2448) = 0x28;
                *(s32 *)(g + 0x244C) = func_L39_0061EB48(g);
                *(s32 *)(g + 0x754) = 1;
                g[0x1A05] = 0;
            }
            break;
        }
        break;
    case 0x6F: {
        s32 k;
        s32 b;
        void *o;

        Set_0064EA40(g + 0x19E6, 6);
        *(s16 *)(g + 0x107E) = 0;
        if (DecEq_0064EA40(g + 0x19E7, 0x6F)) {
            *(s16 *)(g + 0x107C) = D_L39_0047A968[*(s16 *)(g + 0x107C)].w4 == 0 ? 6 : 5;
        } else {
            *(s16 *)(g + 0x107C) = 5;
        }
        k = D_L39_0047A968[*(s16 *)(g + 0x107C)].w4;
        if (a2 != 0) {
            b = k == 0;
            func_L39_00628CD0(g, k + 0x17, b, 0, 5.0f);
            o = 0;
            if (*(s32 *)(g + 0x474) == 2) {
                o = *(void **)(g + 0x450);
            }
            if (func_L39_00639598(g, o)) {
                func_003BE4F0(o, k + 0xC, b, 5);
            }
        }
        break;
    }
    case 0x7E:
        Set_0064EA40(g + 0x19E6, 0x14);
        *(s32 *)(g + 0x2450) = 0;
        func_L39_00638D98(g, 0xF);
        *(f32 *)(g + 0x13E4) = *(f32 *)(g + 0x148) * 0.2f;
        *(f32 *)(g + 0x13EC) = *(f32 *)(g + 0x2C0) - 0.37f;
        if (*(f32 *)(g + 0x13E4) < -0.116666675f) {
            *(f32 *)(g + 0x13E4) = -0.116666675f;
        }
        g[0x1A0E] = 1;
        *(s32 *)(g + 0x13F0) = 0;
        *(f32 *)(g + 0x13E0) = *(f32 *)(g + 0xA8) - *(f32 *)(g + 0x13EC);
        if (a2 != 0) {
            func_L39_00628CD0(g, 0x37, 0, 0, 11.0f);
        }
        break;
    case 0x7A:
        Set_0064EA40(g + 0x19E6, 0x19);
        *(s32 *)(g + 0x2450) = 0;
        Set16_0064EA40(g + 0x313, 0x2710);
        if (a4 != 0) {
            func_L39_006377E8(g, 7, 0);
        }
        if (a2 != 0) {
            func_L39_00628CD0(g, 0x36, 0, 0, 8.0f);
        }
        break;
    case 0x79:
        Set_0064EA40(g + 0x19E6, 0xA);
        *(s32 *)(g + 0x2450) = 0;
        *(f32 *)(g + 0x1070) = func_00389380(*(f32 *)(g + 0xB8), 3.1415927f);
        func_003886E8(g + 0x1050, g + 0x20, -1.0f);
        func_L01_003EFFE0(0x1B, *(s32 *)(g + 0x2534));
        *(f32 *)(g + 0xFB4) = 0.15f;
        if (a2 != 0) {
            func_L39_00628CD0(g, 0x26, 5, 8, 8.0f);
            func_L39_00637AE8(g);
        }
        break;
    case 0x16: {
        s32 prev = *(s32 *)(g + 0x2450);
        u8 *p;

        Set_0064EA40(g + 0x19E6, 7);
        *(s32 *)(g + 0x2450) = 0;
        func_L39_00635F88(g, 0.5f);
        func_L01_003EFFE0(0x12, *(s32 *)(g + 0x2534));
        if (DecEq_0064EA40(g + 0x19E7, 0x1D) || DecEq_0064EA40(g + 0x19E7, 1) || *(s32 *)(g + 0x1310) == 2) {
            if (*(s16 *)(g + 0x342) == 0) {
                *(s16 *)(g + 0x342) = 0x12;
            }
            if (DecEq_0064EA40(g + 0x19E7, 0x1D) || DecEq_0064EA40(g + 0x19E7, 1)) {
                *(s32 *)(g + 0x2450) = prev;
                g[0x2500] = 1;
            }
        }
        *(u128_t *)(g + 0x120) = *(u128_t *)(g + 0x150);
        func_003BF640(g + 0x120, 0.116666675f);
        p = func_L01_00444358(*(s32 *)(g + 0x2524), 1, 0);
        if (p != 0) {
            func_L39_00638D98(g, *(f32 *)(p + 0x2C));
        } else {
            func_L39_00638D98(g, 1);
        }
        Set16_0064EA40(g + 0x311, 0x2F);
        if (a2 != 0) {
            func_L39_00628CD0(g, 0x10, 3, 0x18, -3.0f);
            func_L39_00637AE8(g);
            *(f32 *)(*(u8 **)(g + 0x2524) + 0x44) = D_L39_0047A7D8[*(s32 *)(g + 0x620)][(*(s32 *)(g + 0x624))++];
        }
        break;
    }
    case 0x8E:
        *(f32 *)(g + 0xA8) = func_003BE7F0(g + 0xA0, 0, 0, 0.5f) + 0.005f;
        Set_0064EA40(g + 0x19E6, 0x14);
        *(s32 *)(g + 0x2450) = 0;
        func_L39_00635F88(g, 0.5f);
        Set16_0064EA40(g + 0x313, 0x2710);
        g[0x1A0C] = 1;
        func_L01_003EFFE0(0x12, *(s32 *)(g + 0x2534));
        func_L39_00638D98(g, 0xF);
        Set16_0064EA40(g + 0x311, 0x2F);
        if (a2 != 0) {
            func_L39_00628CD0(g, 0x40, 1, 0, -3.0f);
            *(f32 *)(*(u8 **)(g + 0x2524) + 0x44) = D_L39_0047A7D8[*(s32 *)(g + 0x620)][(*(s32 *)(g + 0x624))++];
        }
        break;
    case 0x1C:
        Set_0064EA40(g + 0x19E6, 9);
        *(s32 *)(g + 0x2450) = 0;
        g[0x1A0C] = 1;
        func_L39_00628CD0(g, func_L39_0061FC10(g, 0), 0, 0, 10.0f);
        break;
    case 0x1D:
        ClrSet_0064EA40(g + 0x19E6);
        *(s32 *)(g + 0x2450) = 0x51;
        if (DecEq_0064EA40(g + 0x19E8, 0xC)) {
            g[0x24FD] = 1;
        }
        if (g[0x24FD] == 0 &&
            func_L39_0063A8A8(g, *(u8 *)(*(u8 **)(g + 0x2524) + 0x42)) != func_L39_0061FC10(g, 0)) {
            func_L39_00628CD0(g, func_L39_0061FC10(g, 0), 0, 0, 5.0f);
        }
        break;
    case 0x1E:
        Set_0064EA40(g + 0x19E6, 9);
        *(s32 *)(g + 0x2450) = 0;
        func_L39_00628CD0(g, func_L39_0061FC10(g, 0), 0, 0, 10.0f);
        break;
    case 0x71:
        Set_0064EA40(g + 0x19E6, 9);
        *(s32 *)(g + 0x2450) = 0;
        g[0x1A0C] = 1;
        func_L39_0061FAE8(g);
        if (a2 != 0) {
            func_L39_00628CD0(g, func_L39_0061FC10(g, 0), 0, 0, 10.0f);
        }
        break;
    case 0x26:
        Set_0064EA40(g + 0x19E6, 8);
        *(s32 *)(g + 0x2450) = 0;
        func_L39_00628CD0(g, func_L39_0061FC10(g, 0), 0, 0, 10.0f);
        break;
    case 0x31:
        Set_0064EA40(g + 0x19E6, 9);
        g[0x1A0E] = 1;
        SetB_0064EA40(g + 0x1A18, 1);
        g[0x216] = 0;
        *(s32 *)(g + 0x1FC) = 0;
        g[0x1A0C] = 1;
        func_L01_0044B4B8(g + 0x1780);
        if (a2 != 0) {
            func_L39_00628CD0(g, func_L39_0061FC10(g, 0), 0, 0, -1.0f);
        }
        break;
    case 0x8F:
        Set_0064EA40(g + 0x19E6, 9);
        g[0x1A0E] = 1;
        SetB_0064EA40(g + 0x1A18, 1);
        g[0x1A0C] = 1;
        func_L01_0044B4B8(g + 0x1780);
        if (a2 != 0) {
            func_L39_00628CD0(g, 0x43, 0, 0, 11.0f);
        }
        break;
    case 0x37:
        Set_0064EA40(g + 0x19E6, 9);
        g[0x1A0E] = 1;
        g[0x1A0C] = 1;
        func_L39_00628CD0(g, 0x33, 2, 0, 8.0f);
        {
            void *o = *(void **)(g + 0x450);

            if (func_L39_00639598(g, o)) {
                func_003BE4F0(o, 0xB, 2, 0xD);
            }
        }
        break;
    case 0x62:
    case 0x63:
        Set_0064EA40(g + 0x19E6, 0x18);
        g[0x1A0C] = 1;
        func_L01_0044B4B8(g + 0x1780);
        func_L39_0061FAE8(g);
        if (a2 != 0) {
            func_L39_00628CD0(g, func_L39_0061FC10(g, 0), 0, 0, -1.0f);
        }
        break;
    default:
        break;
    }

    if (D_001A5990.bA4[*(s32 *)(g + 0x2544)] == 2) {
        if (DecEq_0064EA40(g + 0x19E6, 0x14)) {
            if (*(s32 *)(g + 0x1310) == 2) {
                if (1.5f < *(f32 *)(g + 0x12C4)) {
                    *(f32 *)(g + 0x12C4) = 1.5f;
                }
                func_L39_00644920(g, 1);
            }
        } else if (*(s32 *)(g + 0x1310) != 2) {
            func_L39_00644920(g, 2);
        }
    }
    if (f4C != 0 && g[0x1A0E] == 0) {
        { s32 st = 1; Set3_0064EA40(g + 0x1A2B, st); }
    }
    if (f50 != 0 && g[0x1A13] == 0) {
        { s32 st = 1; Set3_0064EA40(g + 0x1A2B, st); }
    }
    if (*(s32 *)(g + 0x251C) != 0) {
        ClrSet3_0064EA40(g + 0x1A2B);
    }
    if (*(s16 *)(g + 0x2D8) == 0 && *(s32 *)(g + 0x4C8) == 0xE && Dec3_0064EA40(g + 0x1A26) != 0) {
        { s32 st = 1; Set3_0064EA40(g + 0x1A2C, st); }
    }
    if (DecEq_0064EA40(g + 0x19E6, 0x14) || DecEq_0064EA40(g + 0x19E4, 0x7A)) {
        g[0x1A13] = 0;
        if (g[0x1A14] != 0 && !DecEq_0064EA40(g + 0x19E4, 0x90)) {
            SendCur_0064EA40(g);
        }
        do {
            func_L39_0061FAE8(g);
            g[0x1A0C] = 1;
        } while (0);
    }
    if (*(f32 *)(g + 0x23A8) > *(f32 *)(g + 0x2C0) || Dec_0064EA40(g + 0x19E6) == 0) {
        *(s32 *)(*(u8 **)(g + 0x2530) + 0x450) = 0;
    }
    if (!DecEq_0064EA40(g + 0x19E6, Dec_0064EA40(g + 0x19E8))) {
        func_L39_006378A8(g);
    }
    *(s32 *)(g + 0x2F0) = 0;
    *(s32 *)(g + 0x2F8) = 0;
    if (!DecEq_0064EA40(g + 0x19E6, Dec_0064EA40(g + 0x19E8))) {
        *(s32 *)(g + 0x2F4) = 0;
    }
    *(s32 *)(g + 0x2FC) = 0;
    return 1;
}
/* localdecomp:end func_L39_0064C198 */

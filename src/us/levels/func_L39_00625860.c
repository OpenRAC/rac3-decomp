#include "common.h"

/* NTSC-U counterpart of func_L39_00628038 (src/levels/shared/L39_00622990.c) */
/* localdecomp:start func_L39_00625860 */
typedef union Buf_00625860 {
    u8 b[8];
    u16 h[4];
    u32 w[2];
} Buf_00625860;

typedef struct Msg_00625860 {
    s8 b0;
    u8 b1;
    u8 b2;
    u8 b3;
    u8 b4;
    u8 pad5[3];
    s32 w8;
} Msg_00625860;

typedef union Pkt_00625860 {
    Msg_00625860 m;
    Buf_00625860 u;
} Pkt_00625860;

typedef struct VT_00625860 {
    u8 pad0[0x1C];
    s32 (*f1C)(void *, s32);
    u8 pad20[0x14];
    s32 (*f34)(void *, s32, s32, s32, s32);
} VT_00625860;

typedef struct Obj_00625860 {
    u8 pad0[3];
    u8 b3;
    u8 pad4[0x10];
    VT_00625860 *vt;
    u8 pad18[4];
    void *w1C;
    u8 pad20[0x2524];
    u8 b2544;
} Obj_00625860;

typedef struct Net_00625860 {
    u8 pad0[4];
    s32 w4;
    u8 pad8[0x168];
    s32 w170;
    u8 pad174[0x660];
    u8 b7D4;
} Net_00625860;

extern u8 D_L39_004998A0[];
extern u8 D_L39_004998A1[];
extern u32 D_L39_0024BAC8;
extern s32 D_L39_00240738;
extern Net_00625860 D_001A5E50;
extern Obj_00625860 *func_L39_0061AA60(s32);
extern s32 func_L39_0066CC08(s32);
extern s32 func_L39_005B2498(s32);
extern s32 func_L39_0053D098(void *);
extern void func_L39_0066E190(void *);
extern void func_0014AD08(s32, s32, s32, s32, s32, void *);

void func_L39_00625860(u8 *g, s32 a1) {
    Pkt_00625860 pk;
    Buf_00625860 buf2;
    Obj_00625860 *o;
    s32 is14;
    s32 h;

    if (((({
        u8 *q = g + 0x19E4;
        u32 a;
        u32 r;
        if (*q == 0) {
            r = 0;
        } else {
            s32 n = *q;
            s32 k = ((u32)q - n) & 7;
            s32 m = n + 1;
            s32 i;
            u8 *d = pk.u.b;
            for (i = 0; i < 40; i += 5) {
                *d++ = D_L39_004998A0[m + ((k + i) & 7) * 255];
            }
            a = pk.u.w[0] ^ (u32)q;
            pk.u.w[0] = a;
            pk.u.w[1] ^= a;
            r = pk.u.w[1];
        }
        r;
    })) ^ 0x90) == 0) {
        return;
    }
    if (a1 != 0) {
        g[0x2501] = 1;
    } else {
        g[0x2501] = 0;
    }
    is14 = (((({
        u8 *q = g + 0x19E8;
        u32 a;
        u32 r;
        if (*q == 0) {
            r = 0;
        } else {
            s32 n = *q;
            s32 k = ((u32)q - n) & 7;
            s32 m = n + 1;
            s32 i;
            u8 *d = pk.u.b;
            for (i = 0; i < 40; i += 5) {
                *d++ = D_L39_004998A0[m + ((k + i) & 7) * 255];
            }
            a = pk.u.w[0] ^ (u32)q;
            pk.u.w[0] = a;
            pk.u.w[1] ^= a;
            r = pk.u.w[1];
        }
        r;
    })) ^ 0x14) == 0);
    if (g[0x1A14] != 0 && !is14) {
        o = func_L39_0061AA60(*(s32 *)(g + 0x24CC));
        if (o == 0) {
            pk.m.b0 = -1;
        } else if ((o->b3 & 0xF) == 0 && o->vt->f1C(o, *(s32 *)(g + 0x2548)) == 0) {
            pk.m.b0 = o->b2544;
        } else if (o != 0 && (o->b3 & 0xF) == 2 && o->w1C != 0) {
            pk.m.b0 = func_L39_0066CC08(*(s16 *)((u8 *)o->w1C + 0xAA));
        } else {
            pk.m.b0 = -1;
        }
        pk.m.b2 = *(u8 *)(g + 0x2544);
        pk.m.b1 = (({
        u8 *q = g + 0x19E4;
        u32 a;
        u32 r;
        if (*q == 0) {
            r = 0;
        } else {
            s32 n = *q;
            s32 k = ((u32)q - n) & 7;
            s32 m = n + 1;
            s32 i;
            u8 *d = buf2.b;
            for (i = 0; i < 40; i += 5) {
                *d++ = D_L39_004998A0[m + ((k + i) & 7) * 255];
            }
            a = buf2.w[0] ^ (u32)q;
            buf2.w[0] = a;
            buf2.w[1] ^= a;
            r = buf2.w[1];
        }
        r;
    }));
        pk.m.b3 = g[0x24D0];
        pk.m.w8 = *(s32 *)(g + 0x24CC);
        pk.m.b4 = func_L39_005B2498(0x10);
        if (D_001A5E50.w170 == 0) {
            func_0014AD08(D_001A5E50.b7D4 | 0x40, D_001A5E50.w4, -1, D_L39_00240738, 0xC, &pk);
        }
        func_L39_0066E190(&pk);
    }
    h = (s16)func_L39_0053D098(g);
    {
        u8 *q = g + 0x31C;
        u8 *hk = q;
        u32 key;
        s32 k;
        s32 m;
        s32 i;
        u8 *d;

        if (*q == 0) {
            *q = ++D_L39_004998A0[0];
        } else {
            s32 t = *q;
            *q = D_L39_004998A1[0];
            D_L39_004998A1[0] = t;
        }
        key = ((u32 *)D_L39_004998A0)[((u32)hk * D_L39_0024BAC8) % 510];
        k = ((u32)q - *q) & 7;
        pk.u.h[2] = h;
        pk.u.w[0] = (u32)q ^ key;
        pk.u.w[1] = ((pk.u.w[1] & 0xFFFF) | (pk.u.w[1] << 16)) ^ key;
        m = *q + 1;
        d = pk.u.b;
        for (i = 0; i < 24; i += 3) {
            D_L39_004998A0[m + ((k + i) & 7) * 255] = *d++;
        }
    }
    *(s32 *)(g + 0x610) = 0;
    g[0x1A13] = 0;
    (*(VT_00625860 **)(g + 0x14))->f34(g, 0x90, 0, 1, 1);
}
/* localdecomp:end func_L39_00625860 */

#include "common.h"

/* NTSC-U counterpart of func_L40_004301D8 (src/levels/shared/L40_00430068.c): the frame counter is D_001A5F78 on NTSC-U */
/* localdecomp:start func_L40_0042F750 */
typedef struct {
    f32 x, y, z, w;
} __attribute__((aligned(16))) V_0042F750;

typedef struct {
    u8 pad0[0x48];
    u8 a48[8];
    u8 a50[0x1C0];
    s32 *p210;
} S_0042F750;

extern u8 *D_L40_002494B0[8] __attribute__((section(".sdata")));
extern S_0042F750 D_L40_003573E0;
extern s32 D_001A5F78[];
extern s32 *D_L40_002412A0;
extern void func_L39_00660240(u8 *, void *, s32);
extern void func_L01_00441FB8(void *, s32, s32);
extern void func_L39_0063A9F8(void *, s32);
extern void func_00388BD0(void *, void *);
extern f32 func_00388770(void *);
extern s32 func_L39_005F0D88(s32, s32, void *, s32);
extern void func_L01_0044ECE0(s32, s32, s32);

static __inline__ void read_0042F750(u8 *pkt, void *dst, s32 n)
{
    func_L39_00660240(pkt, dst, n);
}

void func_L40_0042F750(u8 *o, u8 *pkt)
{
    u8 *v = *(u8 **)(o + 0x68);
    struct {
        u8 a;
        u8 b;
    } ab;
    V_0042F750 tmp;
    V_0042F750 tmp2;
    s32 id;
    s32 msg = -1;
    s32 snd = -1;
    u8 *h;
    s32 i;

    switch (*(u32 *)pkt & 0xF) {
    case 0:
        read_0042F750(pkt, &id, 4);
        func_L01_00441FB8(o, 2, -1);
        *(s32 *)(v + 0x10) = id;
        {
            u8 *e = D_L40_002494B0[id];

            if (e != 0) {
                e[0x1A0E] = 1;
                *(u8 **)(e + 0x251C) = o;
            }
        }
        msg = 0x1411;
        if (*(s16 *)(v + 0x14) == 0) {
            msg = 0x1412;
        }
        snd = 0;
        break;
    case 1:
        read_0042F750(pkt, &ab.a, 1);
        read_0042F750(pkt, &ab.b, 1);
        *(V_0042F750 *)(o + 0x10) = *(V_0042F750 *)(v + 0x0);
        *(V_0042F750 *)(o + 0xF0) = *(V_0042F750 *)(v + 0x20);
        if (*(s32 *)(v + 0x10) >= 0) {
            u8 *e = D_L40_002494B0[*(s32 *)(v + 0x10)];

            if (e != 0) {
                func_L39_0063A9F8(e, 1);
            }
        }
        *(s32 *)(v + 0x10) = -1;
        if (ab.a != 0) {
            snd = 3;
            if (ab.b != 0xFF) {
                S_0042F750 *d = &D_L40_003573E0;
                u8 *q = d->a48;
                u8 *p = &q[ab.b];
                if (*p < 0xFE) {
                    (*p)++;
                }
            }
            if (*(s16 *)(v + 0x14) == 0) {
                msg = 0x13D5;
                D_L40_003573E0.p210[3]++;
            } else {
                msg = 0x13D6;
                D_L40_003573E0.p210[2]++;
            }
        } else {
            if (ab.b != 0xFF) {
                S_0042F750 *d = &D_L40_003573E0;
                u8 *q = d->a50;
                u8 *p = &q[ab.b];
                snd = 2;
                if (*p < 0xFE) {
                    (*p)++;
                }
            }
            msg = 0x1416;
            if (*(s16 *)(v + 0x14) == 0) {
                msg = 0x1415;
            }
        }
        tmp = *(V_0042F750 *)(v + 0x20);
        tmp.y += -1.5707964f;
        func_00388BD0(o + 0xC0, &tmp);
        *(s32 *)(v + 0x1C) = D_001A5F78[0];
        func_L01_00441FB8(o, 1, -1);
        break;
    case 2: {
        s32 snap = 1;

        read_0042F750(pkt, &tmp, 0x10);
        snd = 1;
        func_L01_00441FB8(o, 1, -1);
        *(V_0042F750 *)(o + 0x10) = tmp;
        if (*(s32 *)(v + 0x10) >= 0 && (h = D_L40_002494B0[*(s32 *)(v + 0x10)]) != 0) {
            func_L39_0063A9F8(h, 1);
            if (func_00388770(*(u8 **)(h + 0x2524) + 0xC0) > 0.99f && func_00388770(*(u8 **)(h + 0x2524) + 0xD0) > 0.99f) {
                snap = 0;
                *(V_0042F750 *)(o + 0xC0) = *(V_0042F750 *)(*(u8 **)(h + 0x2524) + 0xE0);
                *(V_0042F750 *)(o + 0xD0) = *(V_0042F750 *)(*(u8 **)(h + 0x2524) + 0xD0);
                *(V_0042F750 *)(o + 0xE0) = *(V_0042F750 *)(*(u8 **)(h + 0x2524) + 0xC0);
            }
        }
        msg = 0x1413;
        if (*(s16 *)(v + 0x14) == 0) {
            msg = 0x1414;
        }
        if (snap) {
            tmp2 = *(V_0042F750 *)(v + 0x20);
            tmp2.y += -1.5707964f;
            func_00388BD0(o + 0xC0, &tmp2);
        }
        *(s32 *)(v + 0x1C) = D_001A5F78[0];
        *(s32 *)(v + 0x10) = -1;
        break;
    }
    }
    if (snd >= 0) {
        func_L39_005F0D88(snd, 0x110, o, 0x1C2F);
    }
    if (msg >= 0) {
        for (i = 0; i < *D_L40_002412A0; i++) {
            func_L01_0044ECE0(msg, -1, i);
        }
    }
}
/* localdecomp:end func_L40_0042F750 */

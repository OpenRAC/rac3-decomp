#include "common.h"

/* localdecomp:start func_L40_00430068 */
extern s32 func_L39_0066DD30(s32, s32, s32);
s32 func_L40_00430068(s32 a0) {
    return func_L39_0066DD30(a0, 0, 0) != 0;
}
/* localdecomp:end func_L40_00430068 */

/* localdecomp:start func_L40_00430090 */
extern s32 func_L39_0066DCC8(s32 a0, s32 a1, s32 a2, s32 a3);
extern void func_L39_00662AA0(s32 a0, void *a1, s32 a2);
void func_L40_00430090(s32 a0, s32 a1) {
    s32 x;
    s32 r = func_L39_0066DCC8(a0, 0, 0, 250);
    x = a1;
    func_L39_00662AA0(r, &x, 4);
}
/* localdecomp:end func_L40_00430090 */

/* localdecomp:start func_L40_004300D8 */
extern s32 func_L39_0066DD30(s32, s32, s32);
s32 func_L40_004300D8(s32 a0) {
    return func_L39_0066DD30(a0, 1, 0) != 0;
}
/* localdecomp:end func_L40_004300D8 */

/* localdecomp:start func_L40_00430100 */
extern void func_L39_00662AA0(s32 a0, void *a1, s32 a2);
extern s32 func_L39_0066DCC8(s32, s32, s32, s32);
void func_L40_00430100(s32 a0, s32 a1, u8 a2) {
    u8 buf[4];
    s32 h = func_L39_0066DCC8(a0, 1, 0, 0);
    buf[0] = a1;
    ((void (*)(s32, u8 *, s32))func_L39_00662AA0)(h, buf, 1);
    buf[0] = a2;
    ((void (*)(s32, u8 *, s32))func_L39_00662AA0)(h, buf, 1);
}
/* localdecomp:end func_L40_00430100 */

/* localdecomp:start func_L40_00430170 */
extern s32 func_L39_0066DD30(s32, s32, s32);
s32 func_L40_00430170(s32 a0) {
    return func_L39_0066DD30(a0, 2, 0) != 0;
}
/* localdecomp:end func_L40_00430170 */

/* localdecomp:start func_L40_00430198 */
extern void func_L39_00662AA0(s32 a0, void *a1, s32 a2);
extern s32 func_L39_0066DCC8(s32, s32, s32, s32);

void func_L40_00430198(u8 *a0) {
    ((void (*)(void *, u8 *, s32))func_L39_00662AA0)(((void * (*)(u8 *, s32, s32, s32))func_L39_0066DCC8)(a0, 2, 0, 250), a0 + 16, 16);
}
/* localdecomp:end func_L40_00430198 */

/* localdecomp:start func_L40_004301D8 */
typedef struct {
    f32 x, y, z, w;
} __attribute__((aligned(16))) V_004301D8;

typedef struct {
    u8 pad0[0x48];
    u8 a48[8];
    u8 a50[0x1C0];
    s32 *p210;
} S_004301D8;

extern u8 *D_L40_00249330[8] __attribute__((section(".sdata")));
extern S_004301D8 D_L40_00357260;
extern s32 D_001A5DF8[];
extern s32 *D_00241120;
extern void func_L39_00662B18(u8 *, void *, s32);
extern void func_L01_004450F0(void *, s32, s32);
extern void func_L39_0063D240(void *, s32);
extern void func_0038D308(void *, void *);
extern f32 func_0038CEA8(void *);
extern s32 func_L39_005F3488(s32, s32, void *, s32);
extern void func_L01_00451F60(s32, s32, s32);

static __inline__ void read_004301D8(u8 *pkt, void *dst, s32 n)
{
    func_L39_00662B18(pkt, dst, n);
}

void func_L40_004301D8(u8 *o, u8 *pkt)
{
    u8 *v = *(u8 **)(o + 0x68);
    struct {
        u8 a;
        u8 b;
    } ab;
    V_004301D8 tmp;
    V_004301D8 tmp2;
    s32 id;
    s32 msg = -1;
    s32 snd = -1;
    u8 *h;
    s32 i;

    switch (*(u32 *)pkt & 0xF) {
    case 0:
        read_004301D8(pkt, &id, 4);
        func_L01_004450F0(o, 2, -1);
        *(s32 *)(v + 0x10) = id;
        {
            u8 *e = D_L40_00249330[id];

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
        read_004301D8(pkt, &ab.a, 1);
        read_004301D8(pkt, &ab.b, 1);
        *(V_004301D8 *)(o + 0x10) = *(V_004301D8 *)(v + 0x0);
        *(V_004301D8 *)(o + 0xF0) = *(V_004301D8 *)(v + 0x20);
        if (*(s32 *)(v + 0x10) >= 0) {
            u8 *e = D_L40_00249330[*(s32 *)(v + 0x10)];

            if (e != 0) {
                func_L39_0063D240(e, 1);
            }
        }
        *(s32 *)(v + 0x10) = -1;
        if (ab.a != 0) {
            snd = 3;
            if (ab.b != 0xFF) {
                S_004301D8 *d = &D_L40_00357260;
                u8 *q = d->a48;
                u8 *p = &q[ab.b];
                if (*p < 0xFE) {
                    (*p)++;
                }
            }
            if (*(s16 *)(v + 0x14) == 0) {
                msg = 0x13D5;
                D_L40_00357260.p210[3]++;
            } else {
                msg = 0x13D6;
                D_L40_00357260.p210[2]++;
            }
        } else {
            if (ab.b != 0xFF) {
                S_004301D8 *d = &D_L40_00357260;
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
        tmp = *(V_004301D8 *)(v + 0x20);
        tmp.y += -1.5707964f;
        func_0038D308(o + 0xC0, &tmp);
        *(s32 *)(v + 0x1C) = D_001A5DF8[0];
        func_L01_004450F0(o, 1, -1);
        break;
    case 2: {
        s32 snap = 1;

        read_004301D8(pkt, &tmp, 0x10);
        snd = 1;
        func_L01_004450F0(o, 1, -1);
        *(V_004301D8 *)(o + 0x10) = tmp;
        if (*(s32 *)(v + 0x10) >= 0 && (h = D_L40_00249330[*(s32 *)(v + 0x10)]) != 0) {
            func_L39_0063D240(h, 1);
            if (func_0038CEA8(*(u8 **)(h + 0x2524) + 0xC0) > 0.99f && func_0038CEA8(*(u8 **)(h + 0x2524) + 0xD0) > 0.99f) {
                snap = 0;
                *(V_004301D8 *)(o + 0xC0) = *(V_004301D8 *)(*(u8 **)(h + 0x2524) + 0xE0);
                *(V_004301D8 *)(o + 0xD0) = *(V_004301D8 *)(*(u8 **)(h + 0x2524) + 0xD0);
                *(V_004301D8 *)(o + 0xE0) = *(V_004301D8 *)(*(u8 **)(h + 0x2524) + 0xC0);
            }
        }
        msg = 0x1413;
        if (*(s16 *)(v + 0x14) == 0) {
            msg = 0x1414;
        }
        if (snap) {
            tmp2 = *(V_004301D8 *)(v + 0x20);
            tmp2.y += -1.5707964f;
            func_0038D308(o + 0xC0, &tmp2);
        }
        *(s32 *)(v + 0x1C) = D_001A5DF8[0];
        *(s32 *)(v + 0x10) = -1;
        break;
    }
    }
    if (snd >= 0) {
        func_L39_005F3488(snd, 0x110, o, 0x1C2F);
    }
    if (msg >= 0) {
        for (i = 0; i < *D_00241120; i++) {
            func_L01_00451F60(msg, -1, i);
        }
    }
}
/* localdecomp:end func_L40_004301D8 */

/* localdecomp:start func_L40_004305B0 */
f32 func_L01_0040E548(void *, void *);

s32 func_L40_004305B0(void *arg0) {
    s32 var_s0;
    void *temp_a1;

    temp_a1 = *(void **)((u8 *)arg0 + 0x68);
    var_s0 = 0;
    if (((*(s32 *)((u8 *)temp_a1 + 0x10)) == -1) && (func_L01_0040E548(arg0 + 0x10, temp_a1) < 4.0f)) {
        var_s0 = 1;
    }
    return var_s0;
}
/* localdecomp:end func_L40_004305B0 */

/* localdecomp:start func_L40_00430608 */
extern f32 func_L01_0040E548(void *, void *);
extern s32 func_L40_00430068(s32 a0);
extern void func_L40_00430090(s32 a0, s32 a1);
extern s32 func_L40_004300D8(s32 a0);
extern void func_L40_00430100(s32 a0, s32 a1, u8 a2);
extern s32 func_L40_004305B0(void *arg0);
extern u8 D_L40_003BFE20[];
extern u8 *D_L40_00249330[8] __attribute__((section(".sdata")));
extern s32 D_001A5DF8[];
extern f32 D_L40_002479D0;

static __inline__ s32 decode_00430608(u8 *key)
{
    union {
        u8 bytes[8];
        u32 words[2];
    } value;
    u8 *out;
    s32 step;
    s32 index;
    s32 base;

    if (*key == 0) {
        return 0;
    }
    out = value.bytes;
    step = 0;
    index = *key + 1;
    base = ((s32)key - *key) & 7;
    do {
        *out++ = D_L40_003BFE20[index + ((base + step) & 7) * 255];
        step += 5;
    } while (step < 40);
    value.words[0] ^= (u32)key;
    value.words[1] ^= value.words[0];
    return value.words[1];
}

static __inline__ s32 ignored_00430608(u8 *o, u32 st)
{
    u8 r;

    if (*(u8 **)(o + 0x2530) != 0) {
        r = 0;
        if ((*(u8 **)(o + 0x2530))[0x27B] != 0 && (decode_00430608(o + 0x19E4) ^ st) == 0) {
            r |= 1;
        }
    } else {
        r = 0;
    }
    return r;
}

s32 func_L40_00430608(u8 *o, s32 mode)
{
    u8 *p = *(u8 **)(o + 0x68);
    u8 *hero;
    u8 *rider;
    s32 x;
    s32 ok;
    u8 ignore;
    f32 range;

    if (mode == 0) {
        if (o[0x20] != 1) {
            return 0;
        }
        if (!func_L40_004300D8((s32)o) && !func_L40_00430068((s32)o) && D_001A5DF8[0] > *(s32 *)(p + 0x1C) + 1500) {
            ok = 1;
            if (*(s32 *)(p + 0x1C) + 40000 < D_001A5DF8[0] && !func_L40_004305B0(o)) {
                func_L40_00430100((s32)o, 0, 255);
                ok = 0;
            }
            if (ok) {
                for (x = 0; x < 8; x++) {
                    hero = D_L40_00249330[x];
                    if (!hero) {
                        continue;
                    }
                    if ((decode_00430608(hero + 0x19E6) ^ 20) == 0) {
                        continue;
                    }
                    if (*(s32 *)(hero + 0x350) < 0x97) {
                        continue;
                    }
                    if (*(s32 *)(hero + 0x2528)) {
                        continue;
                    }
                    ignore = ignored_00430608(hero, 0x31);
                    if (ignore) {
                        continue;
                    }
                    rider = *(u8 **)(hero + 0x2CC);
                    if (rider && *(s16 *)(rider + 0xAA) == 0x10C3) {
                        continue;
                    }
                    range = D_L40_002479D0;
                    range *= range;
                    if (func_L01_0040E548(o + 0x10, hero + 0xA0) < range) {
                        if (*(s32 *)(hero + 0x2548) != *(s16 *)(p + 0x14)) {
                            func_L40_00430090((s32)o, x);
                            return 0;
                        }
                        if (0.1f < func_L01_0040E548(p, o + 0x10)) {
                            func_L40_00430100((s32)o, 0, hero[0x2544]);
                            return 0;
                        }
                    }
                }
            }
        }
    }
    return 0;
}
/* localdecomp:end func_L40_00430608 */

/* US draft of func_003A2DC8 (rac3-uya-decomp func_0039DB38, commit 13cf5c5), names moved to PAL addresses
   where known. Not carried: differs: did not build, or built to other bytes, in PAL. */

/* localdecomp:start func_003A2DC8 */
typedef struct {
    u8 pad0[0x100];
    f32 cur[16];
    f32 prev[16];
    u8 pad180[0xE];
    s16 head;
    s32 cnt;
    u8 pad194[0xC];
    s32 x1A0;
    s32 x1A4;
    s32 x1A8;
    s32 x1AC;
    s32 x1B0;
    s32 x1B4;
    s32 x1B8;
    s32 x1BC;
    s32 x1C0;
    s32 x1C4;
    s32 x1C8;
    s32 x1CC;
    s32 x1D0;
    s32 x1D4;
    s32 x1D8;
    u8 pad1DC[4];
    s32 hist[30];
    f32 ang[30];
    f32 mag[30];
    s32 x348;
    s32 idx;
    s32 count;
    s32 btn[7];
    s32 btn2[7];
    f32 an[7][16];
    u8 pad54C;
    u8 x54D;
    u8 x54E;
    u8 x54F;
    u8 pad550[0x18];
    s32 delay;
} Pad_39DB38;

extern s32 D_001D5B94;
extern u8 D_001D5477[];
extern f32 func_0038CED8(f32 *);
extern f32 func_0038D160(f32, f32);
extern f32 func_0038DBA0(f32, f32);

#define SWAP_LR(x) \
    if ((x) & 0x8000) { (x) = ((x) & ~0x8000) | 0x2000; } \
    else if ((x) & 0x2000) { (x) = ((x) & ~0x2000) | 0x8000; }

void func_003A2DC8(Pad_39DB38 *o, u8 *raw, s32 len) {
    f32 v2[2];
    s32 i, n, j, v, b;
    f32 m, a;
    u8 c, r;
    s32 q;
    s32 b2;

    o->btn[o->idx] = ((raw[2] << 8) | raw[3]) ^ 0xFFFF;
    o->btn2[o->idx] = o->btn[o->idx];
    for (i = 0; i < 16; i++) {
        o->an[o->idx][i] = 0.0f;
    }
    if (len >= 8) {
        for (i = 0; i < 4; i++) {
            v = raw[i + 4] - 0x7F;
            if (v < 0) {
                v = -v;
            }
            if (v >= 0x30) {
                o->an[o->idx][i] = (f32)(v - 0x30) / 76.0f;
                if (o->an[o->idx][i] > 1.0f) {
                    o->an[o->idx][i] = 1.0f;
                }
                if (raw[i + 4] < 0x7F) {
                    o->an[o->idx][i] = -o->an[o->idx][i];
                }
            }
        }
    }
    if (len >= 0x14) {
        for (i = 4; i < 16; i++) {
            o->an[o->idx][i] = raw[i + 4] * 0.003921569f;
        }
    }
    if (*(u8 *)0x1D5477) {
        o->an[o->idx][2] = -o->an[o->idx][2];
        o->an[o->idx][0] = -o->an[o->idx][0];
        if (o->btn[o->idx] & 0x8000) {
            o->btn[o->idx] &= ~0x8000;
            o->btn[o->idx] |= 0x2000;
        } else if (o->btn[o->idx] & 0x2000) {
            o->btn[o->idx] &= ~0x2000;
            o->btn[o->idx] |= 0x8000;
        }
        o->btn2[o->idx] = o->btn[o->idx];
    }
    if (D_001D5B94 == 7) {
        if (o->an[o->idx][2] < 0.0f) {
            o->btn[o->idx] |= 0x8000;
        }
        if (o->an[o->idx][2] > 0.0f) {
            o->btn[o->idx] |= 0x2000;
        }
        if (o->an[o->idx][3] < 0.0f) {
            o->btn[o->idx] |= 0x1000;
        }
        if (o->an[o->idx][3] > 0.0f) {
            o->btn[o->idx] |= 0x4000;
        }
    }
    if (o->count >= o->delay) {
        j = (o->idx - o->delay + 7) % 7;
        o->x1A0 = o->btn[j];
        o->x1B0 = o->btn2[j];
        for (i = 0; i < 16; i++) {
            o->cur[i] = o->an[(o->idx - o->delay + 7) % 7][i];
        }
    } else {
        o->x1A0 = o->x1AC;
        o->x1B0 = o->x1BC;
    }
    o->idx = (o->idx + 1) % 7;
    if (++o->count > o->delay) {
        o->count = o->delay;
    }
    for (i = 0; i < 16; i++) {
        o->prev[i] = o->cur[i];
    }
    if (o->cur[2] != 0.0f || o->cur[3] != 0.0f) {
        o->x1D8 = 1;
    } else {
        o->x1D8 = 0;
    }
    if (o->cur[2] < 0.0f) {
        o->x1A0 |= 0x8000;
    }
    if (o->cur[2] > 0.0f) {
        o->x1A0 |= 0x2000;
    }
    if (o->cur[3] < 0.0f) {
        o->x1A0 |= 0x1000;
    }
    if (o->cur[3] > 0.0f) {
        o->x1A0 |= 0x4000;
    }
    b = o->x1A0;
    o->x1A4 = ~o->x1AC & b;
    o->x1D4 = (b & 0xF000) == 0;
    o->x1D0 = b == 0;
    o->x1A8 = ~b & o->x1AC;
    o->x1B4 = ~o->x1AC & o->x1B0;
    o->x1B8 = ~b & o->x1BC;
    o->x1C4 = ~o->x1AC & b;
    o->x1C8 = ~b & o->x1AC;
    o->x1C0 = b;
    o->x348 = b;
    if (*(u8 *)0x1D5477) {
        o->prev[2] = -o->prev[2];
        o->prev[0] = -o->prev[0];
        SWAP_LR(o->x1C0);
        SWAP_LR(o->x1C4);
        SWAP_LR(o->x1C8);
    }
    if (o->x1CC == 1) {
        o->x1A0 &= ~0x5030;
        o->x1A4 &= ~0x5030;
        o->x1A8 &= ~0x5030;
        o->cur[0] = 0.0f;
        o->cur[1] = 0.0f;
        o->x1CC = 0;
    }
    if (o->x1CC == 2) {
        o->x1A0 &= 0x900;
        o->x1A4 &= 0x900;
        o->x1A8 &= 0x900;
        o->x1B0 &= 0x900;
        o->x1D4 = 1;
        o->cur[2] = 0.0f;
        o->cur[3] = 0.0f;
        o->x1CC = 0;
    }
    v2[0] = o->cur[2];
    v2[1] = o->cur[3];
    m = func_0038CED8(v2);
    a = func_0038D160(v2[0], v2[1]);
    o->mag[o->head] = m;
    o->ang[o->head] = a;
    if (m > 0.9f) {
        for (q = 1; q < 4; q++) {
            j = (o->head - q + 30) % 30;
            if (o->mag[j] > 0.9f) {
                break;
            }
            if (o->mag[j] < 0.25f) {
                o->x1A4 |= 0x10000;
                break;
            }
        }
        if (!(o->x1A4 & 0x10000)) {
            for (n = 1; n < 5; n++) {
                if (func_0038DBA0(o->ang[(o->head - n + 30) % 30], a) > 0.959931076f) {
                    o->x1A4 |= 0x10000;
                    break;
                }
            }
        }
    }
    if (D_001D5B94 != -1) {
        o->hist[o->head] = o->x1A4;
        o->head = (o->head + 1) % 30;
        if (++o->cnt > 30) {
            o->cnt = 30;
        }
    }
    r = o->x54E;
    if (r) {
        b2 = o->x1A0;
        if (b2 != 0 && b2 == o->x1AC) {
            c = --o->x54F;
            if (c == 0 || c == 0xFF) {
                o->x54F = r;
                o->x1A4 = b2;
            }
        } else {
            o->x54F = o->x54D;
        }
    }
}
/* localdecomp:end func_003A2DC8 */

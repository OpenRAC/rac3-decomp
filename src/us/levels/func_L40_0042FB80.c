#include "common.h"

/* NTSC-U counterpart of func_L40_00430608 (src/levels/shared/L40_00430068.c): the hero +0x350 threshold is 0xB5 instead of 0x97, frame counter D_001A5F78 */
/* localdecomp:start func_L40_0042FB80 */
extern f32 func_L01_0040C018(void *, void *);
extern s32 func_L40_0042F5E0(s32 a0);
extern void func_L40_0042F608(s32 a0, s32 a1);
extern s32 func_L40_0042F650(s32 a0);
extern void func_L40_0042F678(s32 a0, s32 a1, u8 a2);
extern s32 func_L40_0042FB28(void *arg0);
extern u8 D_L40_003BFF60[];
extern u8 *D_L40_002494B0[8] __attribute__((section(".sdata")));
extern s32 D_001A5F78[];
extern f32 D_L40_00247B50;

static __inline__ s32 decode_0042FB80(u8 *key)
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
        *out++ = D_L40_003BFF60[index + ((base + step) & 7) * 255];
        step += 5;
    } while (step < 40);
    value.words[0] ^= (u32)key;
    value.words[1] ^= value.words[0];
    return value.words[1];
}

static __inline__ s32 ignored_0042FB80(u8 *o, u32 st)
{
    u8 r;

    if (*(u8 **)(o + 0x2530) != 0) {
        r = 0;
        if ((*(u8 **)(o + 0x2530))[0x27B] != 0 && (decode_0042FB80(o + 0x19E4) ^ st) == 0) {
            r |= 1;
        }
    } else {
        r = 0;
    }
    return r;
}

s32 func_L40_0042FB80(u8 *o, s32 mode)
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
        if (!func_L40_0042F650((s32)o) && !func_L40_0042F5E0((s32)o) && D_001A5F78[0] > *(s32 *)(p + 0x1C) + 1500) {
            ok = 1;
            if (*(s32 *)(p + 0x1C) + 40000 < D_001A5F78[0] && !func_L40_0042FB28(o)) {
                func_L40_0042F678((s32)o, 0, 255);
                ok = 0;
            }
            if (ok) {
                for (x = 0; x < 8; x++) {
                    hero = D_L40_002494B0[x];
                    if (!hero) {
                        continue;
                    }
                    if ((decode_0042FB80(hero + 0x19E6) ^ 20) == 0) {
                        continue;
                    }
                    if (*(s32 *)(hero + 0x350) < 0xB5) {
                        continue;
                    }
                    if (*(s32 *)(hero + 0x2528)) {
                        continue;
                    }
                    ignore = ignored_0042FB80(hero, 0x31);
                    if (ignore) {
                        continue;
                    }
                    rider = *(u8 **)(hero + 0x2CC);
                    if (rider && *(s16 *)(rider + 0xAA) == 0x10C3) {
                        continue;
                    }
                    range = D_L40_00247B50;
                    range *= range;
                    if (func_L01_0040C018(o + 0x10, hero + 0xA0) < range) {
                        if (*(s32 *)(hero + 0x2548) != *(s16 *)(p + 0x14)) {
                            func_L40_0042F608((s32)o, x);
                            return 0;
                        }
                        if (0.1f < func_L01_0040C018(p, o + 0x10)) {
                            func_L40_0042F678((s32)o, 0, hero[0x2544]);
                            return 0;
                        }
                    }
                }
            }
        }
    }
    return 0;
}
/* localdecomp:end func_L40_0042FB80 */

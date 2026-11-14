/* NTSC-U draft (2026-11-14, Codex worker): C of func_L39_0061F020, the NTSC-U twin of func_L39_006217C0, with NTSC-U names
 * and addresses. Byte-exact on NTSC-U with "-O2 -G8 -fopt-stack -mno-check-zero-division" (src/levels/shared/L39_00621600.c's line: "-O2 -G8 -fopt-stack -mno-check-zero-division").
 */
#include "common.h"

/* localdecomp:start func_L39_0061F020 */
typedef union { u8 b[8]; u32 w[2]; } Buf_61F020;
extern u8 D_L39_004998A0[];
extern void func_L39_0062F1D8(void *, s32, f32 *);
extern f32 func_00389380(f32, f32);
extern s32 func_L39_00632610(void *, s32, f32, f32);
extern void *D_L39_0025F858[];
extern s32 func_L39_005B6970(void *);
extern u8 D_L39_0025F860[];
extern f32 func_003887C8(void *, void *);
extern s32 func_L39_0061EB48(void *);
static __inline__ u8 dec3_61F020(u8 *q, Buf_61F020 *buf) {
    u8 r;
    if (*q == 0) r = 0;
    else {
        u32 a, b, hi;
        s32 n = *q;
        s32 k = ((u32)q - n) & 7;
        s32 m = n + 1;
        s32 i;
        u8 *d = buf->b;
        for (i = 0; i < 24; i += 3) *d++ = D_L39_004998A0[m + ((k + i) & 7) * 255];
        a = buf->w[0] ^ (u32)q;
        b = buf->w[1] ^ a;
        buf->w[0] = a;
        hi = b >> 16;
        buf->w[1] = hi / (((b ^ hi) << 16) + 1);
        r = buf->b[4];
    }
    return r;
}
static __inline__ u32 dec5_61F020(u8 *q, Buf_61F020 *buf) {
    u32 r;
    if (*q == 0) r = 0;
    else {
        u32 a;
        s32 n = *q;
        s32 k = ((u32)q - n) & 7;
        s32 m = n + 1;
        s32 i;
        u8 *d = buf->b;
        for (i = 0; i < 40; i += 5) *d++ = D_L39_004998A0[m + ((k + i) & 7) * 255];
        a = buf->w[0] ^ (u32)q;
        buf->w[0] = a;
        buf->w[1] ^= a;
        r = buf->w[1];
    }
    return r;
}
void func_L39_0061F020(u8 *s) {
    Buf_61F020 buf;
    f32 tmp;
    f32 f;
    f32 a,b;
    s32 state;
    s32 idx;
    f32 roll;
    s[0x1A08] = 0;
    if (dec3_61F020(s + 0x1A17, &buf) == 0 || *(s16 *)(s + 0x348) != 0 || s[0x1A0B] != 0) return;
    f = 0.0f;
    tmp = 0.0f;
    func_L39_0062F1D8(s, (*(u8 **)(s + 0x2524))[0x43], &tmp);
    if (tmp != 0.0f) return;
    b = s[0x1A08] ? 1.6f : 1.3f;
    a = s[0x1A07] ? 0.7f : 0.57f;
    if (*(s32 *)(s + 0x1310) == 2) {
        f = func_00389380(*(f32 *)(s + 0x1200), 0.1745329201221466f);
        if (0.3490658402442932f < f) f = 0.3490658402442932f;
        if (f < -1.3962633609771729f) f = -1.3962633609771729f;
        if (s[0x1A05]) f = func_00389380(f, -0.15707963705062866f);
    } else {
        if (func_L39_00632610(s, 0, a, b)) {
            if (!(s[0x1A07] && D_L39_0025F858[0] && func_L39_005B6970(D_L39_0025F858[0]))) {
                f32 d = func_003887C8(s + 0xA0, D_L39_0025F860) - *(f32 *)(s + 0x1F4);
                f = ((1.3f - d) / 1.3f) * 1.25f * -1.2217304706573486f;
                if (-0.5235987901687622f < f) f = -0.5235987901687622f;
                if (f < -1.2217304706573486f) f = -1.2217304706573486f;
            }
            s[0x1A08] = 1;
        }
        if (*(s32 *)(s + 0x1310) == 1) {
            if (!s[0x1A08] || *(f32 *)(s + 0x1200) < f) {
                f = *(f32 *)(s + 0x1200);
                if (0.3490658402442932f < f) f = 0.3490658402442932f;
                else if (f < -1.3962633609771729f) f = -1.3962633609771729f;
                s[0x1A08] = 0;
                state = func_L39_0061EB48(s);
                if (s[0x1A05]) f = func_00389380(f, -0.11344639956951141f);
                else if (dec5_61F020(s + 0x19E6, &buf) == 0 && ((u32)(state - 3) < 2 || state == 19 || state == 18)) f = func_00389380(f, 0.1483529806137085f);
            }
        }
    }
    if (f == 0.0f) return;
    roll = 0.0f;
    idx = -1;
    if (*(s32 *)(s + 0x474) == 2) idx = *(s32 *)(s + 0x478);
    if (idx == 4) {
        roll = f * -0.009973309934139252f;
        if (0.6981316804885864f < roll) roll = 0.6981316804885864f;
    }
    if (*(s32 *)(s + 0x1310) == 2) {
        *(f32 *)(s + 0xE34) = 0.3f;
        *(f32 *)(s + 0xE38) = 0.9f;
    } else {
        *(f32 *)(s + 0xE34) = 0.05f;
        *(f32 *)(s + 0xE38) = 0.3f;
    }
    *(f32 *)(s + 0xDF4) = f;
    *(f32 *)(s + 0xDF0) = roll;
    if ((dec3_61F020(s + 0x1A17, &buf) ^ 2) == 0) {
        *(f32 *)(s + 0xD84) = *(f32 *)(s + 0xE34);
        *(f32 *)(s + 0xD40) = *(f32 *)(s + 0xDF0);
        *(f32 *)(s + 0xD88) = *(f32 *)(s + 0xE38);
        *(f32 *)(s + 0xD44) = *(f32 *)(s + 0xDF4);
    }
}
/* localdecomp:end func_L39_0061F020 */

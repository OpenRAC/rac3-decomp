#include "common.h"

/* NTSC-U counterpart of func_L39_006314E0 (src/levels/shared/L39_006314E0.c): 0.002 -> 0.00166667 */
typedef int u128_t __attribute__((mode(TI)));
typedef union {
    u128_t q;
    f32 f[4];
} Vec4;
typedef struct {
    u8 pad[32];
    u8 m20[64];
    u8 m60[6662 - 96];
    u8 mode;
} S_62FD10;
extern u8 D_L39_004998A0[];
extern void func_003886E8(void *, void *, f32);

/* localdecomp:start func_L39_0062EC98 */
#include "vu0.h"
/* log:
 * v1: first reading, separate Vec4s and decode buffer: 242 diff (frame 0xA0, 1.4f misread).
 * v2: decode buffer is the union that also holds the first vector (sp+0, as in func_L39_0062FE58),
 *     file's decode idiom, func_00590508 with a plain 1.4f: 8 diff, then vec_add_ab for d+c: 6 diff
 *     (a2 = 1 scheduled before the $f12/$f13 moves at both func_L39_0062F938 calls).
 *     Tried: a zero variable, (f32 *)&buf, int 0 args, named prototype, 0.3f*len, VM permuter
 *     (240 s, nothing). sched2 dump: a2's insn wins the LUID tie, so in retail it was emitted
 *     after the float moves.
 * v3: func_L39_0062F938 called with the flag as its LAST parameter (EABI gives it $a2 either
 *     way, but it is then loaded after the floats): MATCH with --flags=-mvu0-use-vf0-vf2.
 */
typedef struct {
    u8 pad0[0x18];
    s32 w18;
    s32 w1C;
    u8 pad20[0x20];
    Vec4 v40;
} S_006314E0;

typedef union Buf_006314E0 {
    u8 b[8];
    u32 w[2];
    u128_t q;
    f32 f[4];
} Buf_006314E0;

extern u8 D_L39_004998A0[];
extern S_006314E0 D_L39_0025F840;
extern f32 func_L39_0062FD90(u8 *, f32 *);
extern void func_L39_0062F938(u8 *, f32 *, s32, f32, f32, f32);
extern void func_L39_0062FD10(S_62FD10 *, Vec4 *, Vec4 *, f32);
extern f32 func_L39_0062F8B8(u8 *, Vec4 *);
extern f32 func_003887A0(Vec4 *);
extern void func_00388830(void *, void *, f32);
extern void func_003886E8(void *, void *, f32);
extern f32 func_00388730(void *, void *);
extern s32 func_003CE740(void *, void *, s32, void *, s32);
extern s32 func_003D00C0(void);

void func_L39_0062EC98(u8 *s, s32 a1) {
    Buf_006314E0 buf;
    f32 sc;
    f32 len;

    if (func_L39_0062FD90(s, (f32 *)(s + 0x120)) < 0.00166666682f) {
        return;
    }
    len = 0.37f;
    sc = 0.5f;
    {
        u32 dec;
        s32 eq;

    {
        u8 *q = s + 0x19E6;
        if (*q == 0) {
            dec = 0;
        } else {
            u32 x;
            u32 y;
            s32 n;
            s32 k;
            s32 m;
            s32 i;
            u8 *p;

            n = *q;
            k = ((u32)q - n) & 7;
            m = n + 1;
            p = buf.b;
            for (i = 0; i < 40; i += 5) {
                *p++ = D_L39_004998A0[m + ((k + i) & 7) * 255];
            }
            x = buf.w[0] ^ (u32)q;
            y = buf.w[1] ^ x;
            buf.w[0] = x;
            buf.w[1] = y;
            dec = y;
        }
    }
        eq = dec == 0x11;
        if (!eq) {
    {
        u8 *q = s + 0x19E6;
        if (*q == 0) {
            dec = 0;
        } else {
            u32 x;
            u32 y;
            s32 n;
            s32 k;
            s32 m;
            s32 i;
            u8 *p;

            n = *q;
            k = ((u32)q - n) & 7;
            m = n + 1;
            p = buf.b;
            for (i = 0; i < 40; i += 5) {
                *p++ = D_L39_004998A0[m + ((k + i) & 7) * 255];
            }
            x = buf.w[0] ^ (u32)q;
            y = buf.w[1] ^ x;
            buf.w[0] = x;
            buf.w[1] = y;
            dec = y;
        }
    }
            eq = dec == 0x12;
        }
        if (eq) {
            len = 0.0f;
            sc = 0.7f;
        }
    }
    {
        Vec4 b;
        Vec4 c;
        Vec4 d;
        f32 hit;
        s32 r;

        ((void (*)(u8 *, f32 *, f32, f32, f32, s32))func_L39_0062F938)(s, buf.f, 0.0f, 0.0f, len, 1);
        ((void (*)(u8 *, f32 *, f32, f32, f32, s32))func_L39_0062F938)(s, c.f, 0.0f, 0.0f, len * 0.3f, 1);
        if (a1 != 0 || func_003887A0((Vec4 *)(s + 0x120)) < 0.01f) {
            func_00388830(&b, s + 0x20, sc);
            func_00388830(&d, s + 0x20, sc * 1.4f);
        } else {
            func_L39_0062FD10((S_62FD10 *)s, &b, (Vec4 *)(s + 0x120), 0.0f);
            func_00388830(&b, &b, sc);
            func_003886E8(&d, &b, 1.4f);
        }
        vec_add_ba(&b, &b, &buf);
        vec_add_ab(&d, &d, &c);
        r = -1;
        if (func_003CE740(&c, &d, 2, *(void **)(s + 0x2524), 0) != 0 && D_L39_0025F840.w1C > 0) {
            r = func_003D00C0();
        }
        hit = 0.0f;
        if (func_003CE740(&buf, &b, 2, *(void **)(s + 0x2524), 0) != 0 && D_L39_0025F840.w1C > 0) {
            hit = func_L39_0062F8B8(s, &D_L39_0025F840.v40);
        }
        if (hit >= 0.87266463f || r == 8 || r == 12) {
            f32 dot;
            *(s32 *)(s + 0x200) = D_L39_0025F840.w18;
            func_L39_0062FD10((S_62FD10 *)s, &D_L39_0025F840.v40, &D_L39_0025F840.v40, 0.0f);
            func_00388830(&D_L39_0025F840.v40, &D_L39_0025F840.v40, 1.0f);
            dot = func_00388730(&D_L39_0025F840.v40, s + 0x120);
            if (dot < 0.0f) {
                func_003886E8(&D_L39_0025F840.v40, &D_L39_0025F840.v40, -dot);
                vec_add_ba(s + 0x120, s + 0x120, &D_L39_0025F840.v40);
            }
        }
    }
}
/* localdecomp:end func_L39_0062EC98 */

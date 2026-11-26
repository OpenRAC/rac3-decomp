#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void (*D_001D9A40[2])(s32);
extern void (*D_001D9A40_00382B20[1])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
extern s32 *D_001D55C4[];
/* --- end of declarations from other files --- */

/* localdecomp:start func_0038E3C0 */
extern u8 D_001D5B42;
void func_0038E3C0(s32 a) { D_001D5B42 = a; }
/* localdecomp:end func_0038E3C0 */

typedef struct { u32 w0; u32 w4; } E_389B98;
/* localdecomp:start func_0038E3C8 */
s32 func_0038E3C8(u8 *str, s32 len, f32 scale) {
    s32 i = 0;
    s32 ok = 1;
    f32 max = 0.0f;
    s32 idx = 0;
    for (; ok && i != len; i++) {
        if (str[i] == 0) {
            ok = 0;
        } else {
            f32 w, h, v;
            i += func_0038E0A8(str, i, &idx);
            w = (f32)((((E_389B98 *)D_001D55C4[0])[idx].w4 >> 17) & 0x3F) * scale;
            h = (f32)((((E_389B98 *)D_001D55C4[0])[idx].w4 >> 9) & 0xFF) * scale;
            v = w + h * 0.25f;
            if (max < v) max = v;
        }
    }
    return (s32)max;
}
/* localdecomp:end func_0038E3C8 */

/* Candidate for func_0038E548 (frontbin, PAL).
   Base: the US draft (rac3-uya-decomp func_00389D18).
   PAL differences so far:
     - the kernel table base is read through D_001D55C4[1] (the same word as
       D_001D55C8, but an array element, so the compiler addresses it with
       lui/lw like retail instead of a $gp-relative load),
     - the inner "k" search loop is restructured. */

/* localdecomp:start func_0038E548 */
typedef struct { u32 w0; u32 w4; } E_389D18;
typedef struct { s16 ch; s8 adj; u8 end; } K_389D18;
s32 func_0038E548(u8 *str, s32 len, f32 scale) {
    s32 idx[2];
    f32 q = scale * 0.25f;
    s32 i;
    s32 ok;
    f32 kern;
    f32 x;
    f32 first;
    idx[0] = 0;
    idx[1] = 0;
    func_0038E0A8(str, 0, &idx[0]);
    kern = 0.0f;
    first = (f32)(-(s32)(((E_389D18 *)D_001D55C4[0])[idx[0]].w0 >> 25)) * q;
    x = 0.0f;
    ok = 1;
    i = 0;
    for (; ok && i != len; i++) {
        if (str[i] == 0) {
            ok = 0;
        } else {
            E_389D18 *e;
            f32 w, b, c, adv;
            i += func_0038E0A8(str, i, &idx[0]);
            e = &((E_389D18 *)D_001D55C4[0])[idx[0]];
            w = (f32)((e->w4 >> 23) & 0x3F) * scale;
            b = (f32)(s32)(((e->w0 >> 25) + 2) & 0xFC) * q;
            c = (f32)(((e->w4 >> 29) + 2) & 0xFC);
            x += w - b;
            adv = (kern + c) * q;
            if (i != len - 1) {
                s32 nx;
                func_0038E0A8(str, i + 1, &idx[1]);
                nx = idx[1];
                if (nx >= 0x10) {
                    f32 t;
                    if (e->w0 & 0xFFF0) {
                        K_389D18 *k = (K_389D18 *)((u8 *)D_001D55C4[1] + ((e->w0 >> 2) & 0x3FFC));
                        s32 r;
                        t = x + adv;
                        if (k != 0) {
                            s32 j;
                            for (j = 0; k[j].end == 0; j++) {
                                if (k[j].ch == nx) { r = k[j].adj; goto done; }
                            }
                        }
                        r = 0;
                    done:
                        kern = (f32)r;
                        kern = kern * q;
                    } else {
                        t = x + adv;
                        kern = 0.0f;
                    }
                    x = t;
                }
            }
        }
    }
    return (s32)(x - first);
}
/* localdecomp:end func_0038E548 */

INCLUDE_ASM("asm/nonmatchings/text", func_0038E7E8);
INCLUDE_RODATA("asm/nonmatchings/text/rodata", jtbl_0031C040);

INCLUDE_ASM("asm/nonmatchings/text", func_0038F078);
INCLUDE_RODATA("asm/nonmatchings/text/rodata", jtbl_0031C070);

/* localdecomp:start func_0038F9E0 */
void func_0038F9E0(s16 *p, s32 a, s32 b, s32 c, s32 d, s32 e, s32 f, s32 g, s32 h) {
    p[0] = a;
    p[1] = b;
    p[2] = c;
    p[3] = d;
    p[4] = e;
    p[5] = f;
    p[8] = g;
    p[9] = h;
    p[6] = 0;
    p[7] = 0;
    p[10] = 0;
    p[11] = 0;
}
/* localdecomp:end func_0038F9E0 */

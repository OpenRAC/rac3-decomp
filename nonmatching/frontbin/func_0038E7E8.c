/* PAL near miss (wave 13, r23), first draft of a fresh entry: 450 words differ in its file's context with
 * the file's flags (no div.s, no sqrt.s, no rows needed). The count is positional and this draft is two
 * words short, so most of it is shifted words; the real difference is about twenty instructions.
 * What it has: the 12-argument prototype (color/extra as 64-bit `unsigned long`, the f12-f15 floats, then
 * fa/fb on the stack), the align switch with `case 0:` and the two-call cases ordered as retail,
 * the packet word read through D_001DA050_0038E7E8 (`.extern ..., 16`, absolute lui/lw and the $at store)
 * and written back through the gp symbol D_001DA050, the glyph record and kern table forms of the matched
 * siblings func_0038E3C8/func_0038E548 (D_001D55C4[1] as the kern base, the `goto done` kern search that
 * gives retail's beql loop), the colour clamp, the page/texture reload through func_00389D00, and the
 * two draw calls (func_0038BA30 with the shadow, func_0038B670 without) with their count updates.
 * Left:
 *  - the align switch: retail loads the jump table with lui/addiu into its own register (split by the
 *    scheduler with the sll between), then addu and lw 0; with this file's -mno-split-addresses the
 *    compiler folds the table address into the load (lui/addu/lw %lo), one word short;
 *  - D_001D5B48[str[i] - 8]: retail forms &D_001D5B48 with addiu $gp and adds (c - 8) << 2; here the -8
 *    folds into the address (lui 0x1d + lw 0x5b28), one word short. Both look like split-addresses
 *    forms; a u32 index, a pointer local and *(D + k) did not change it;
 *  - the space glyph: retail re-reads ((E *)D_001D55C4[0])[0x20].w4 at 0x104 off the base each time and
 *    clears kern after the add; writing it that way matches those words but measures 471 (shift);
 *  - register choices: the colour byte `a` is in v1 in retail (bnel, with lui a0 for 0xC0C0C0), a0 here;
 *    the packet's 0x50000000 constant is a2 in retail, v1 here; an extra nop at the loop entry; the
 *    mtc1 $zero / spill order at the start.
 */
#include "common.h"

/* localdecomp:start func_0038E7E8 */
typedef struct { u32 w0; u32 w4; } E_0038E7E8;
typedef struct { s16 ch; s8 adj; u8 end; } K_0038E7E8;
typedef struct { u8 p0[0x10]; u8 pg[0x18][2]; u8 fmt[0x10]; struct { s16 w, h; } sz[16]; } T_0038E7E8;
typedef unsigned int U128_0038E7E8 __attribute__((mode(TI)));
extern s32 *D_001D55C4[];
extern T_0038E7E8 *D_001D55C0[];
extern u8 D_001D5B40;
extern u8 D_001D5B41;
extern u8 D_001D5B42;
extern s32 D_001D5B48[2];
extern s32 *D_001D5B38;
extern s32 *D_001D5B3C;
extern u8 *D_001DA050;
extern u8 *D_001DA050_0038E7E8;
__asm__(".extern D_001DA050_0038E7E8, 16");
extern U128_0038E7E8 D_001D77D0;

void func_0038E7E8(f32 x, f32 y, f32 sx, f32 sy, unsigned long color, u8 *str, s32 len, s32 align, s32 shadow,
                   unsigned long extra, f32 fa, f32 fb) {
    extern void func_0038DED0();
    extern s32 func_0038E548(u8 *, s32, f32);
    extern s32 func_0038E3C8(u8 *, s32, f32);
    extern s32 func_0038E0A8(u8 *, s32, s32 *);
    extern unsigned long func_00389D00(s32, s32, s32, s32, s32);
    extern s32 func_0038B670(s32, s32, s32, s32, long, long, s32, f32, f32, f32, f32);
    extern s32 func_0038BA30(s32, s32, s32, s32, long, long, long, s32, f32, f32, f32, f32, f32, f32);
    s32 idx;
    s32 idx2;
    s32 i;
    s32 ok;
    s32 first;
    s32 page;
    s32 count;
    s32 snap;
    s32 cur;
    s32 w;
    s32 h;
    unsigned long tex;
    f32 q;
    f32 qy;
    f32 kern;
    f32 step;
    u8 *pkt;
    E_0038E7E8 *e;

    q = sx * 0.25f;
    qy = sy * 0.25f;
    cur = color;
    snap = 0;
    ok = 1;
    first = 1;
    page = -1;
    tex = 0;
    kern = 0.0f;
    if (sx == 1.0f && sy == 1.0f && D_001D5B40) {
        snap = 1;
    }
    func_0038DED0();
    func_003A9440(0x47, 0x33001);
    if (D_001D5B41 == 0) {
        D_001D5B48[0] = color;
    }
    switch (align) {
    case 0:
        break;
    case 1:
        x -= (f32)(func_0038E548(str, len, sx) >> 1);
        break;
    case 2:
        x -= (f32)func_0038E548(str, len, sx);
        break;
    case 3:
        y -= (f32)(func_0038E3C8(str, len, sy) >> 1);
        break;
    case 4:
        w = func_0038E548(str, len, sx);
        h = func_0038E3C8(str, len, sy);
        x -= (f32)(w >> 1);
        y -= (f32)(h >> 1);
        break;
    case 5:
        w = func_0038E548(str, len, sx);
        h = func_0038E3C8(str, len, sy);
        x -= (f32)w;
        y -= (f32)(h >> 1);
        break;
    case 6:
        y -= (f32)func_0038E3C8(str, len, sy);
        break;
    case 7:
        w = func_0038E548(str, len, sx);
        h = func_0038E3C8(str, len, sy);
        y -= (f32)h;
        x -= (f32)(w >> 1);
        break;
    case 8:
        w = func_0038E548(str, len, sx);
        h = func_0038E3C8(str, len, sy);
        x -= (f32)w;
        y -= (f32)h;
        break;
    }
    pkt = D_001DA050_0038E7E8;
    count = 0;
    D_001DA050 = pkt + 0x20;
    for (i = 0; ok && i != len; i++) {
        if (str[i] == 0) {
            ok = 0;
        } else if (str[i] >= 8 && str[i] < 16) {
            if (D_001D5B42) {
                cur = (color & 0xFF000000) | (D_001D5B48[str[i] - 8] & 0xFFFFFF);
            }
        } else if (str[i] == 0x20) {
            E_0038E7E8 *spc = &((E_0038E7E8 *)D_001D55C4[0])[0x20];
            kern = 0.0f;
            x += (f32)(((spc->w4 >> 29) + 2) & 0xFC) * q + (f32)((spc->w4 >> 23) & 0x3F) * sx;
        } else {
            f32 b;
            f32 fw;
            f32 fh;
            f32 yo;
            s32 t;
            s32 r;
            i += func_0038E0A8(str, i, &idx);
            e = &((E_0038E7E8 *)D_001D55C4[0])[idx];
            if (e->w4 & 0x1F800000) {
                if (idx < 0x20) {
                    s32 a = (u32)cur >> 24;
                    if (a >= 0x41) {
                        color = 0x80C0C0C0;
                    } else if (a > 0x20) {
                        color = (((a - 0x20) * 3 + 0x20) << 24) | 0xC0C0C0;
                    } else {
                        color = (cur & 0xFF000000) | 0xC0C0C0;
                    }
                } else {
                    color = cur;
                }
                if (((u16)e->w0 & 0xF) != page) {
                    T_0038E7E8 *tb;
                    s32 b0;
                    s32 b1;
                    page = (u16)e->w0 & 0xF;
                    tb = D_001D55C0[0];
                    b0 = tb->pg[page][0];
                    b1 = tb->pg[page][1];
                    tex = func_00389D00(D_001D5B38[b0], D_001D5B3C[b1], tb->sz[b0].w, tb->sz[b0].h,
                                        tb->fmt[b0] == 0x14 ? 0x14 : 0x13);
                }
                fw = (f32)((e->w4 >> 23) & 0x3F) * sx;
                fh = (f32)((e->w4 >> 17) & 0x3F) * sy;
                b = (f32)(s32)(((e->w0 >> 25) + 2) & 0xFC) * q;
                step = (kern + (f32)(((e->w4 >> 29) + 2) & 0xFC)) * q + (f32)((e->w4 >> 23) & 0x3F) * sx;
                t = (e->w4 >> 9) & 0xFF;
                if (t < 0x80) {
                    yo = (f32)t * qy;
                } else {
                    yo = ((f32)t - 256.0f) * qy;
                }
                if (first == 0) {
                    x -= b;
                } else {
                    first = 0;
                }
                if (idx >= 0x21 && shadow) {
                    r = func_0038BA30((e->w0 >> 16) & 0x1FF, e->w4 & 0x1FF, (e->w4 >> 23) & 0x3F, (e->w4 >> 17) & 0x3F,
                                      color, extra, tex, snap, x + kern, y + yo,
                                      fw, fh, fa, fb);
                    if (r) {
                        count += 2;
                    }
                } else {
                    r = func_0038B670((e->w0 >> 16) & 0x1FF, e->w4 & 0x1FF, (e->w4 >> 23) & 0x3F, (e->w4 >> 17) & 0x3F,
                                      color, tex, snap, x + kern, y + yo,
                                      fw, fh);
                    if (r) {
                        count += 1;
                    }
                }
                x += step;
                kern = 0.0f;
                if ((e->w0 & 0xFFF0) && i != len) {
                    func_0038E0A8(str, i + 1, &idx2);
                    if (idx2 != 0) {
                        K_0038E7E8 *k = (K_0038E7E8 *)((u8 *)D_001D55C4[1] + ((e->w0 >> 2) & 0x3FFC));
                        if (k != 0) {
                            s32 j;
                            for (j = 0; k[j].end == 0; j++) {
                                if (k[j].ch == idx2) { r = k[j].adj; goto done; }
                            }
                        }
                        r = 0;
                    done:
                        kern = (f32)r;
                        kern = kern * q;
                    }
                }
            }
        }
    }
    if (count != 0) {
        u32 n = count * 6 + 1;
        ((u32 *)pkt)[1] = 0;
        ((u32 *)pkt)[2] = 0;
        ((u32 *)pkt)[0] = n | 0x10000000;
        ((u32 *)pkt)[3] = n | 0x50000000;
        *(U128_0038E7E8 *)(pkt + 0x10) = D_001D77D0;
        ((u32 *)pkt)[4] = count | 0x8000;
        func_003A9440(8, 5);
    } else {
        D_001DA050_0038E7E8 -= 0x20;
    }
}
/* localdecomp:end func_0038E7E8 */

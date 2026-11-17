#include "common.h"

typedef struct {
    u8 p0[4];
    s32 n[16];
    s32 b[16];
    s32 a[16];
    u8 p1[0x188 - 0xC4];
} Rec188;

INCLUDE_ASM("asm/levels", func_L22_003B7380);

/* localdecomp:start func_L22_003B7A70 */
extern void func_0038E150(s32);
extern s32 func_0038E548(u8 *, s32, f32);
extern u8 D_L22_002A21B0[];
extern s32 D_L22_001DE518;
__asm__(".extern D_L22_001DE518, 4");

void func_L22_003B7A70(s32 arg) {
    u8 *p;
    u8 *start;
    s32 width;
    u8 *out;
    u8 *end;

    func_0038E150(1);
    p = (u8 *)arg;
    start = p;
    width = 0;
    out = D_L22_002A21B0;
    end = out + 0xFF;
    for (; *p != 0 && out != end; out++) {
        *out = *p;
        if (*out & 0x80) {
            if (out <= end) {
                out[1] = p[1];
            }
        }
        if (*out & 0x80) {
            if (out < end) {
                out[2] = 0;
            }
        } else {
            if (out <= end) {
                out[1] = 0;
            }
        }
        if (func_0038E548(out, (*out & 0x80) ? 2 : 1, 1.0f) <= 20) {
            width += func_0038E548(out, (*out & 0x80) ? 2 : 1, 1.0f);
        } else {
            width += 20;
        }
        if (D_L22_001DE518 < width) {
            if (*p != ' ') {
                if (p == start) {
                    *out = 0;
                    return;
                }
                do {
                    p--;
                    out--;
                } while (*p != ' ' && p != start);
            }
            if (p == start) {
                break;
            }
            width = 0;
            *out = 1;
        }
        if (*out & 0x80) {
            out++;
            p++;
        }
        p++;
    }
    *out = 0;
}
/* localdecomp:end func_L22_003B7A70 */

/* localdecomp:start func_L22_003B7C20 */
extern s32 func_L01_00516AA0(s32, s32, s32);
extern s32 func_0038DBD8_003B7C20(s32, s32, f32);
extern f32 func_0038D0B0(f32);
extern s32 func_L01_00517190(s32, s32);
extern s32 func_L01_005170B8(s32, s32);
extern s32 func_L01_005168F0(s32, f32);
extern s32 func_L01_00516470(s32, f32, f32);
extern s32 func_L01_005169C8(s32, f32);
extern s32 D_L22_001DF8C0;
__asm__(".extern D_L22_001DF8C0, 16");
extern s32 D_L22_001DE490;
__asm__(".extern D_L22_001DE490, 4");
extern f32 D_L22_001DE494;
__asm__(".extern D_L22_001DE494, 4");
extern f32 D_L22_001DE498;
__asm__(".extern D_L22_001DE498, 4");
extern f32 D_L22_001DE49C;
__asm__(".extern D_L22_001DE49C, 4");
extern f32 D_L22_001DE4A8;
__asm__(".extern D_L22_001DE4A8, 4");
extern f32 D_L22_001DE4AC;
__asm__(".extern D_L22_001DE4AC, 4");
extern f32 D_L22_001DE4B0;
__asm__(".extern D_L22_001DE4B0, 4");
extern f32 D_L22_001DE4B4;
__asm__(".extern D_L22_001DE4B4, 4");
extern f32 D_L22_001DE4F8;
__asm__(".extern D_L22_001DE4F8, 4");
extern s32 D_L22_001DE51C;
__asm__(".extern D_L22_001DE51C, 4");
extern s32 D_L22_001DE520;
__asm__(".extern D_L22_001DE520, 4");
extern s32 D_L22_001DE524;
__asm__(".extern D_L22_001DE524, 4");

/* lowers *scale to the fraction (a - b) / w where that is smaller */
static __inline__ void fade_003B7C20(f32 *scale, f32 a, f32 b, f32 w) {
    f32 t = (a - b) / w;
    if (!(*scale < t)) {
        *scale = t;
    }
}

void func_L22_003B7C20(s32 id, s32 kind, s32 pulse, f32 x0, f32 x1, f32 y) {
    f32 scale;
    f32 pulse_t;
    f32 rot;
    f32 mid;
    f32 len;
    s32 sprite;
    s32 color;
    s32 visible;
    s32 c1;
    s32 c2;

    scale = 1.0f;
    if (x0 < D_L22_001DE498 + D_L22_001DE494) {
        fade_003B7C20(&scale, x1, D_L22_001DE498, D_L22_001DE494);
        if (x0 < D_L22_001DE498) {
            x0 = D_L22_001DE498;
        }
    } else if (D_L22_001DE49C - D_L22_001DE494 < x1) {
        fade_003B7C20(&scale, D_L22_001DE49C, x0, D_L22_001DE494);
        if (D_L22_001DE49C < x1) {
            x1 = D_L22_001DE49C;
        }
    }

    sprite = 0;
    visible = 1;
    rot = 0.0f;
    color = 0;
    switch (kind) {
    case -1:
    case 0:
        visible = 0;
        break;
    case 1:
        color = 0x80808080;
        sprite = 0xED29;
        break;
    case 2:
        color = 0x80808080;
        sprite = 0xED27;
        break;
    case 3:
        color = 0x80808080;
        sprite = 0xED2A;
        break;
    case 4:
        color = 0x80808080;
        sprite = 0xED28;
        break;
    case 5:
        sprite = 0xED2B;
        color = D_L22_001DE490;
        break;
    case 6:
        sprite = 0xED2B;
        rot = -1.5707964f;
        color = D_L22_001DE490;
        break;
    case 7:
        sprite = 0xED2B;
        rot = 3.1415927f;
        color = D_L22_001DE490;
        break;
    case 8:
        color = D_L22_001DE490;
        sprite = 0xED2B;
        rot = 1.5707964f;
        break;
    }

    if (scale <= 0.0f || !visible) {
        func_L01_00516AA0(id, 1, 0);
        func_L01_00516AA0(id + 0x11, 1, 0);
        func_L01_00516AA0(id + 0x22, 1, 0);
        func_L01_00516AA0(id + 0x33, 1, 0);
        return;
    }

    func_L01_00516AA0(id, 1, 1);
    func_L01_00516AA0(id + 0x11, 1, 1);
    func_L01_00516AA0(id + 0x22, 1, 1);
    func_L01_00516AA0(id + 0x33, 1, 1);
    c1 = 0x332299DE;
    c2 = func_0038DBD8_003B7C20(0x8066CCFF, 0x332299DE, 0.5f);
    if (pulse) {
        pulse_t = (func_0038D0B0((f32)(D_L22_001DF8C0 % 60) / 60.0f * 6.2831855f - 3.1415927f) * 0.5f + 0.5f) * 0.75f;
        c1 = func_0038DBD8_003B7C20(0x332299DE, 0x80000080, pulse_t);
        c2 = func_0038DBD8_003B7C20(c2, 0x80000080, pulse_t * 0.75f);
    }
    func_L01_00517190(id, sprite);
    func_L01_00517190(id + D_L22_001DE51C, sprite);
    func_L01_005170B8(id, func_0038DBD8_003B7C20(color & 0xFFFFFF, color, scale));
    func_L01_005170B8(id + D_L22_001DE51C, func_0038DBD8_003B7C20(0, 0, scale));
    func_L01_005170B8(id + D_L22_001DE520, func_0038DBD8_003B7C20(c1 & 0xFFFFFF, c1, scale));
    func_L01_005170B8(id + D_L22_001DE524, func_0038DBD8_003B7C20(c2 & 0xFFFFFF, c2, scale));
    func_L01_005168F0(id, rot);
    func_L01_005168F0(id + D_L22_001DE51C, rot);
    if (0.5f < x0) {
        mid = x0;
    } else if (0.5f < x1) {
        mid = 0.5f;
    } else {
        mid = x1;
    }
    len = x1 - x0;
    func_L01_00516470(id, mid + D_L22_001DE4A8, y + D_L22_001DE4AC);
    func_L01_00516470(id + D_L22_001DE51C, mid + D_L22_001DE4B0, y + D_L22_001DE4B4);
    func_L01_00516470(id + D_L22_001DE520, x0, y);
    func_L01_00516470(id + D_L22_001DE524, x0, y);
    func_L01_005169C8(id + D_L22_001DE520, len * D_L22_001DE4F8);
    func_L01_005169C8(id + D_L22_001DE524, len * D_L22_001DE4F8);
}
/* localdecomp:end func_L22_003B7C20 */

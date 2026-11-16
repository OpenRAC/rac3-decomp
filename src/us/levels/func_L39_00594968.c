#include "common.h"

/* NTSC-U counterpart of func_L39_00595C18 (src/levels/shared/L39_00595C18.c) */
/* localdecomp:start func_L39_00594968 */
#include "vu0.h"

typedef struct {
    f32 x, y, z, w;
} __attribute__((aligned(16))) V4_00595C18;

typedef struct {
    s8 pad0[0x424];
    f32 f424;
    s8 pad428[0x460 - 0x428];
} S_00595C18;

__asm__(".extern D_001D7168_sda_00594968, 4");
__asm__(".extern D_001D7160_sda_00594968, 4");
__asm__(".extern D_001D7164_sda_00594968, 4");
extern f32 D_001D7168_sda_00594968;
extern f32 D_001D7160_sda_00594968;
extern f32 D_001D7164_sda_00594968;
extern S_00595C18 D_L39_0024DF80[];
extern s32 D_001A5B10[][8];
extern s32 D_001A5A50[][8];
extern s32 D_001A5AB0[][8];

extern f32 func_003BEBF8(f32 *, f32, f32);
extern f32 func_00388770(void *);
extern f32 func_003BEB48(f32, f32, f32);
extern void func_L39_00595758(void *);
extern s32 func_003883C8(void *);
extern void func_003888C8(void *, void *, void *);
extern f32 func_00388A28(f32, f32);
extern f32 func_003887A0(void *);
extern s32 func_L01_004114B0(u8 *, f32);
extern f32 func_003893C8(f32, f32);
extern void func_00388830(void *, void *, f32);
extern f32 func_003887C8(void *, void *);
extern f32 func_00388730(void *, void *);
extern f32 func_00389380(f32, f32);
extern void func_0037E4B8(void *, f32, f32, f32);
extern void func_00388758(void *, void *, void *);
extern void func_00388BD0(void *, void *);
extern void func_L39_00595380(void *, void *, void *);

void func_L39_00594968(u8 *o, u8 *pad, V4_00595C18 *pos, V4_00595C18 *tgt, V4_00595C18 *up, s32 idx, f32 dt) {
    f32 scale;
    f32 sx, sy;
    f32 yawIn;
    f32 yaw, pitch;
    f32 yawRate, pitchRate;
    s32 i;
    s32 mode;
    u8 *targ;
    f32 tmp;
    V4_00595C18 a;
    V4_00595C18 b;

    func_003BEBF8((f32 *)(o + 0x134), dt * D_001D7168_sda_00594968, 0.03333333507180214f);
    if (idx == -1) {
        i = (func_00388770(o + 0xC0) != 0.0f) ? 1 : 2;
    } else {
        i = idx;
    }
    scale = (&D_L39_0024DF80[*(s32 *)(o + 0x12C)])->f424 / 1.11002934f;
    scale *= func_003BEB48(0.25f, 1.25f, (f32)D_001A5B10[i][*(s32 *)(o + 0x138)] * 0.015625f);
    func_L39_00595758(o);
    func_003883C8(o + 0x86);
    if (*(void **)(o + 0xE8) != 0 && !(*(u16 *)(o + 0xE0) & 2)) {
        func_003888C8(o + 0xF0, o + 0xF0, *(void **)(o + 0xEC));
        *(f32 *)(o + 0x40) = func_00388A28(*(f32 *)(o + 0xF0), *(f32 *)(o + 0xF4));
        *(f32 *)(o + 0x60) = -func_00388A28(func_003887A0(o + 0xF0), *(f32 *)(o + 0xF8));
    }
    sx = -*(f32 *)(pad + 0x100);
    sy = *(f32 *)(pad + 0x104);
    if (*(u16 *)(o + 0xE0) & 1) {
        if (fabs_asm(sy) < fabs_asm(*(f32 *)(pad + 0x10C))) {
            sy = *(f32 *)(pad + 0x10C);
        }
        if (fabs_asm(sx) < fabs_asm(*(f32 *)(pad + 0x108))) {
            sx = -*(f32 *)(pad + 0x108);
        }
        if (sy * sy + sx * sx < 0.25f) {
            s32 buttons = *(s32 *)(pad + 0x1B0);
            s32 down = (buttons >> 14) & 1;
            s32 up = (buttons >> 12) & 1;
            s32 left = (buttons >> 15) & 1;
            s32 right = (buttons >> 13) & 1;
            up = down - up;
            right = left - right;
            sy = up;
            sx = right;
        }
    }
    if (D_001A5A50[i][*(s32 *)(o + 0x138)] != 0) {
        sy = -sy;
    }
    if (!(*(u16 *)(o + 0xE0) & 8) && D_001A5AB0[i][*(s32 *)(o + 0x138)] != 0) {
        sx = -sx;
    }
    sx = sx * fabs_asm(sx);
    sy = sy * fabs_asm(sy);
    yawIn = sx;
    if (*(s16 *)(o + 0x86) != 0 && fabs_asm(sx) < fabs_asm(*(f32 *)(o + 0x88))) {
        if (func_L01_004114B0(o, *(f32 *)(o + 0x44)) != 0) {
            sx = *(f32 *)(o + 0x88);
        } else {
            *(s16 *)(o + 0x86) = 0;
        }
    }
    switch (*(s32 *)(o + 0x80)) {
    case 1:
        if (fabs_asm(sx) <= 0.99000001f) {
            *(s32 *)(o + 0x80) = 0;
        }
        break;
    case 0:
        if (0.99000001f < fabs_asm(sx)) {
            if (*(void **)(o + 0x8C) == 0 || *(s16 *)(o + 0x84) >= 9) {
                *(s32 *)(o + 0x80) = 1;
            } else {
                *(s16 *)(o + 0x84) += 1;
            }
        } else {
            *(s16 *)(o + 0x84) = 0;
        }
        break;
    }
    if (0.850000024f <= fabs_asm(yawIn)) {
        if (func_L01_004114B0(o, sx)) {
            *(f32 *)(o + 0x88) = sx;
            *(s16 *)(o + 0x86) = 7;
        }
    } else if (*(s16 *)(o + 0x86) != 0) {
        if (func_L01_004114B0(o, *(f32 *)(o + 0x44)) == 0) {
            *(s16 *)(o + 0x86) = 0;
        }
    }
    mode = *(s32 *)(o + 0x80);
    switch (mode) {
    case 1: {
        f32 sign = -1.0f;
        if (0.0f < sx) {
            sign = 1.0f;
        }
        yaw = *(f32 *)(o + 0x48) * sign;
        targ = *(u8 **)(o + 0x8C);
        yawRate = *(f32 *)(o + 0x50);
        if (targ != 0) {
            yawRate *= 0.333000004f;
        }
        break;
    }
    case 0:
    default: {
        f32 absX = fabs_asm(sx);
        yaw = *(f32 *)(o + 0x4C) * sx;
        targ = *(u8 **)(o + 0x8C);
        yawRate = *(f32 *)(o + 0x54) * absX;
        if (fabs_asm(yawIn) < absX) {
            yawRate += yawRate;
        }
        break;
    }
    }
    yawRate *= scale;
    pitch = *(f32 *)(o + 0x68) * sy;
    pitchRate = *(f32 *)(o + 0x6C) * fabs_asm(sy);
    pitch *= scale;
    yaw *= scale;
    pitchRate *= scale;
    if (*(f32 *)(o + 0xB0) != 0.0f) {
        f32 lim;
        f32 damp = mode == 0 ? *(f32 *)(o + 0x5C) : *(f32 *)(o + 0x58);
        lim = yaw * (1.0f - damp * *(f32 *)(o + 0xB0));
        lim = fabs_asm(lim);
        if (lim < yaw) {
            yaw = lim;
        } else {
            lim = -lim;
            if (yaw < lim) {
                yaw = lim;
            }
        }
        lim = pitch * (1.0f - *(f32 *)(o + 0x70) * *(f32 *)(o + 0xB0));
        lim = fabs_asm(lim);
        if (lim < pitch) {
            pitch = lim;
        } else {
            lim = -lim;
            if (pitch < lim) {
                pitch = lim;
            }
        }
    }
    if (fabs_asm(yawIn) < 0.850000024f && *(s16 *)(o + 0x86) != 0) {
        f32 ang;
        if (targ == 0) {
            goto apply;
        }
        ang = func_003893C8(func_00388A28(*(f32 *)(targ + 0x10) - pos->x, *(f32 *)(targ + 0x14) - pos->y), *(f32 *)(o + 0x40));
        tmp = *(f32 *)(o + 0x44);
        func_003BEBF8(&tmp, yaw, yawRate);
        if (yaw < tmp) {
            tmp = yaw;
        } else if (tmp < -yaw) {
            tmp = -yaw;
        }
        if (fabs_asm(ang) < fabs_asm(tmp)) {
            *(s16 *)(o + 0x86) = 0;
            yaw = ang;
        }
    }
    if (*(void **)(o + 0x8C) != 0 && *(s32 *)(o + 0x80) != 1 && !(*(u16 *)(o + 0xE0) & 0x20)
        && !(*(f32 *)(pad + 0x100) == 0.0f && *(f32 *)(pad + 0x104) == 0.0f && *(f32 *)(pad + 0x108) == 0.0f && *(f32 *)(pad + 0x10C) == 0.0f)) {
        f32 half = 0.5f;
        f32 dist;
        f32 d;
        f32 k;
        vec_sub_ab(&a, tgt, o + 0xA0);
        if (0.06666667014360428f < func_00388770(&a)) {
            func_00388830(&a, &a, 0.06666667014360428f);
        }
        dist = func_003887C8(pos, *(u8 **)(o + 0x8C) + 0x10);
        d = -(func_00388730(&a, o + 0x10) / dist) * *(f32 *)(o + 0x74) * *(f32 *)(o + 0xB0) * half;
        if (0.01308997068554163f < d) {
            d = 0.01308997068554163f;
        } else if (d < -0.01308997068554163f) {
            d = -0.01308997068554163f;
        }
        yawRate += fabs_asm(d);
        k = *(f32 *)(o + 0x78);
        yaw += d;
        if (dist < D_001D7160_sda_00594968) {
            f32 t = (dist - D_001D7164_sda_00594968) / (D_001D7160_sda_00594968 - D_001D7164_sda_00594968);
            if (t < 0.0f) {
                t = 0.0f;
            }
            k *= t;
        }
        {
            f32 e = func_00388730(&a, o + 0x20) / dist * k * *(f32 *)(o + 0xB0) * half;
            pitchRate += fabs_asm(e);
            pitch += e;
        }
    }
apply:
    if (fabs_asm(pitch) < fabs_asm(*(f32 *)(o + 0x64))) {
        *(f32 *)(o + 0x64) = pitch;
    } else {
        func_003BEBF8((f32 *)(o + 0x64), pitch, pitchRate);
    }
    if (fabs_asm(yaw) < fabs_asm(*(f32 *)(o + 0x44))) {
        *(f32 *)(o + 0x44) = yaw;
    } else {
        func_003BEBF8((f32 *)(o + 0x44), yaw, yawRate);
    }
    *(f32 *)(o + 0x60) = func_00389380(*(f32 *)(o + 0x60), *(f32 *)(o + 0x64));
    *(f32 *)(o + 0x40) = func_00389380(*(f32 *)(o + 0x40), *(f32 *)(o + 0x44));
    if (*(f32 *)(o + 0x60) > *(f32 *)(o + 0xB4)) {
        *(f32 *)(o + 0x60) = *(f32 *)(o + 0xB4);
    } else if (*(f32 *)(o + 0x60) < *(f32 *)(o + 0xB8)) {
        *(f32 *)(o + 0x60) = *(f32 *)(o + 0xB8);
    }
    func_0037E4B8(o + 0xF0, 1.0f, *(f32 *)(o + 0x40), -*(f32 *)(o + 0x60));
    if (*(void **)(o + 0xE8) != 0 && !(*(u16 *)(o + 0xE0) & 2)) {
        func_003888C8(o + 0xF0, o + 0xF0, *(void **)(o + 0xE8));
        *(V4_00595C18 *)o = *(V4_00595C18 *)(o + 0xF0);
        func_00388758(o + 0x10, o, *(u8 **)(o + 0xE8) + 0x20);
        func_00388830(o + 0x10, o + 0x10, 1.0f);
        func_00388758(o + 0x20, o + 0x10, o);
        func_00388830(o + 0x20, o + 0x20, 1.0f);
    } else {
        *(vu0_q *)&b = 0;
        b.y = *(f32 *)(o + 0x60);
        b.z = *(f32 *)(o + 0x40);
        a = b;
        func_00388BD0(o, &a);
    }
    a = *pos;
    b = *up;
    func_L39_00595380(o, &a, &b);
}
/* localdecomp:end func_L39_00594968 */

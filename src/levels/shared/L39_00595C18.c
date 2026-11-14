#include "common.h"

/* localdecomp:start func_L39_00595C18 */
#include "vu0.h"

typedef struct {
    f32 x, y, z, w;
} __attribute__((aligned(16))) V4_00595C18;

typedef struct {
    s8 pad0[0x424];
    f32 f424;
    s8 pad428[0x460 - 0x428];
} S_00595C18;

__asm__(".extern D_001D7168_sda, 4");
__asm__(".extern D_001D7160_sda, 4");
__asm__(".extern D_001D7164_sda, 4");
extern f32 D_001D7168_sda;
extern f32 D_001D7160_sda;
extern f32 D_001D7164_sda;
extern S_00595C18 D_L39_0024DE80[];
extern s32 D_001A5990[][8];
extern s32 D_001A58D0[][8];
extern s32 D_001A5930[][8];

extern f32 func_003C4138(f32 *, f32, f32);
extern f32 func_0038CEA8(void *);
extern f32 func_003C4088(f32, f32, f32);
extern void func_L39_00596A08(void *);
extern s32 func_0038CB00(void *);
extern void func_0038D000(void *, void *, void *);
extern f32 func_0038D160(f32, f32);
extern f32 func_0038CED8(void *);
extern s32 func_L01_00413AE0(u8 *, f32);
extern f32 func_0038DB00(f32, f32);
extern void func_0038CF68(void *, void *, f32);
extern f32 func_0038CF00(void *, void *);
extern f32 func_0038CE68(void *, void *);
extern f32 func_0038DAB8(f32, f32);
extern void func_00382760(void *, f32, f32, f32);
extern void func_0038CE90(void *, void *, void *);
extern void func_0038D308(void *, void *);
extern void func_L39_00596630(void *, void *, void *);

void func_L39_00595C18(u8 *o, u8 *pad, V4_00595C18 *pos, V4_00595C18 *tgt, V4_00595C18 *up, s32 idx, f32 dt) {
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

    func_003C4138((f32 *)(o + 0x134), dt * D_001D7168_sda, 0.0400000028f);
    if (idx == -1) {
        i = (func_0038CEA8(o + 0xC0) != 0.0f) ? 1 : 2;
    } else {
        i = idx;
    }
    scale = (&D_L39_0024DE80[*(s32 *)(o + 0x12C)])->f424 / 1.11002934f;
    scale *= func_003C4088(0.25f, 1.25f, (f32)D_001A5990[i][*(s32 *)(o + 0x138)] * 0.015625f);
    func_L39_00596A08(o);
    func_0038CB00(o + 0x86);
    if (*(void **)(o + 0xE8) != 0 && !(*(u16 *)(o + 0xE0) & 2)) {
        func_0038D000(o + 0xF0, o + 0xF0, *(void **)(o + 0xEC));
        *(f32 *)(o + 0x40) = func_0038D160(*(f32 *)(o + 0xF0), *(f32 *)(o + 0xF4));
        *(f32 *)(o + 0x60) = -func_0038D160(func_0038CED8(o + 0xF0), *(f32 *)(o + 0xF8));
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
    if (D_001A58D0[i][*(s32 *)(o + 0x138)] != 0) {
        sy = -sy;
    }
    if (!(*(u16 *)(o + 0xE0) & 8) && D_001A5930[i][*(s32 *)(o + 0x138)] != 0) {
        sx = -sx;
    }
    sx = sx * fabs_asm(sx);
    sy = sy * fabs_asm(sy);
    yawIn = sx;
    if (*(s16 *)(o + 0x86) != 0 && fabs_asm(sx) < fabs_asm(*(f32 *)(o + 0x88))) {
        if (func_L01_00413AE0(o, *(f32 *)(o + 0x44)) != 0) {
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
            if (*(void **)(o + 0x8C) == 0 || *(s16 *)(o + 0x84) >= 8) {
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
        if (func_L01_00413AE0(o, sx)) {
            *(f32 *)(o + 0x88) = sx;
            *(s16 *)(o + 0x86) = 6;
        }
    } else if (*(s16 *)(o + 0x86) != 0) {
        if (func_L01_00413AE0(o, *(f32 *)(o + 0x44)) == 0) {
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
        ang = func_0038DB00(func_0038D160(*(f32 *)(targ + 0x10) - pos->x, *(f32 *)(targ + 0x14) - pos->y), *(f32 *)(o + 0x40));
        tmp = *(f32 *)(o + 0x44);
        func_003C4138(&tmp, yaw, yawRate);
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
        if (0.0800000057f < func_0038CEA8(&a)) {
            func_0038CF68(&a, &a, 0.0800000057f);
        }
        dist = func_0038CF00(pos, *(u8 **)(o + 0x8C) + 0x10);
        d = -(func_0038CE68(&a, o + 0x10) / dist) * *(f32 *)(o + 0x74) * *(f32 *)(o + 0xB0) * half;
        if (0.0157079641f < d) {
            d = 0.0157079641f;
        } else if (d < -0.0157079641f) {
            d = -0.0157079641f;
        }
        yawRate += fabs_asm(d);
        k = *(f32 *)(o + 0x78);
        yaw += d;
        if (dist < D_001D7160_sda) {
            f32 t = (dist - D_001D7164_sda) / (D_001D7160_sda - D_001D7164_sda);
            if (t < 0.0f) {
                t = 0.0f;
            }
            k *= t;
        }
        {
            f32 e = func_0038CE68(&a, o + 0x20) / dist * k * *(f32 *)(o + 0xB0) * half;
            pitchRate += fabs_asm(e);
            pitch += e;
        }
    }
apply:
    if (fabs_asm(pitch) < fabs_asm(*(f32 *)(o + 0x64))) {
        *(f32 *)(o + 0x64) = pitch;
    } else {
        func_003C4138((f32 *)(o + 0x64), pitch, pitchRate);
    }
    if (fabs_asm(yaw) < fabs_asm(*(f32 *)(o + 0x44))) {
        *(f32 *)(o + 0x44) = yaw;
    } else {
        func_003C4138((f32 *)(o + 0x44), yaw, yawRate);
    }
    *(f32 *)(o + 0x60) = func_0038DAB8(*(f32 *)(o + 0x60), *(f32 *)(o + 0x64));
    *(f32 *)(o + 0x40) = func_0038DAB8(*(f32 *)(o + 0x40), *(f32 *)(o + 0x44));
    if (*(f32 *)(o + 0x60) > *(f32 *)(o + 0xB4)) {
        *(f32 *)(o + 0x60) = *(f32 *)(o + 0xB4);
    } else if (*(f32 *)(o + 0x60) < *(f32 *)(o + 0xB8)) {
        *(f32 *)(o + 0x60) = *(f32 *)(o + 0xB8);
    }
    func_00382760(o + 0xF0, 1.0f, *(f32 *)(o + 0x40), -*(f32 *)(o + 0x60));
    if (*(void **)(o + 0xE8) != 0 && !(*(u16 *)(o + 0xE0) & 2)) {
        func_0038D000(o + 0xF0, o + 0xF0, *(void **)(o + 0xE8));
        *(V4_00595C18 *)o = *(V4_00595C18 *)(o + 0xF0);
        func_0038CE90(o + 0x10, o, *(u8 **)(o + 0xE8) + 0x20);
        func_0038CF68(o + 0x10, o + 0x10, 1.0f);
        func_0038CE90(o + 0x20, o + 0x10, o);
        func_0038CF68(o + 0x20, o + 0x20, 1.0f);
    } else {
        *(vu0_q *)&b = 0;
        b.y = *(f32 *)(o + 0x60);
        b.z = *(f32 *)(o + 0x40);
        a = b;
        func_0038D308(o, &a);
    }
    a = *pos;
    b = *up;
    func_L39_00596630(o, &a, &b);
}
/* localdecomp:end func_L39_00595C18 */

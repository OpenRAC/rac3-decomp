#include "common.h"

/* localdecomp:start func_L01_00412FE0 */
#include "vu0.h"

extern void func_0038D308(void *, void *);
extern void func_L01_00413B68(void *, void *, void *);
extern void func_00382760(void *, f32, f32, f32);

void func_L01_00412FE0(void *o, void *pos, f32 a, f32 b) {
    u8 *a0 = o;
    vu0_v4 v;
    vu0_v4 p1;
    vu0_v4 p2;
    f32 f;

    *(vu0_q *)&v = 0;
    *(s32 *)(a0 + 0x44) = 0;
    qzero(a0 + 0xA0);
    *(s32 *)(a0 + 0x64) = 0;
    *(s32 *)(a0 + 0x80) = 0;
    *(s32 *)(a0 + 0x8C) = 0;
    *(s32 *)(a0 + 0xB0) = 0;
    *(f32 *)(a0 + 0x40) = a;
    *(f32 *)(a0 + 0x60) = b;
    v.y = b;
    v.z = a;
    func_0038D308(a0, &v);
    *(vu0_v4 *)(a0 + 0x30) = *(vu0_v4 *)pos;
    *(vu0_v4 *)(a0 + 0x140) = *(vu0_v4 *)pos;
    p1 = *(vu0_v4 *)pos;
    p2 = p1;
    func_L01_00413B68(a0, &p1, &p2);
    f = *(f32 *)(a0 + 0x60);
    if (*(f32 *)(a0 + 0xB4) < f) {
        *(f32 *)(a0 + 0x60) = *(f32 *)(a0 + 0xB4);
    } else if (f < *(f32 *)(a0 + 0xB8)) {
        *(f32 *)(a0 + 0x60) = *(f32 *)(a0 + 0xB8);
    }
    func_00382760(a0 + 0xF0, 1.0f, *(f32 *)(a0 + 0x40), -*(f32 *)(a0 + 0x60));
}
/* localdecomp:end func_L01_00412FE0 */

/* localdecomp:start func_L01_004130C0 */
void func_L01_004130C0(u8 *a) {
    *(u16 *)(a + 0xE0) &= ~2;
}
/* localdecomp:end func_L01_004130C0 */

/* localdecomp:start func_L01_004130D0 */
extern f32 func_0038CED8(void *v);
extern f32 func_0038D160(f32 a, f32 b);

void func_L01_004130D0(u8 *a0)
{
    if (!(*(u16 *)(a0 + 224) & 2)) {
        *(u16 *)(a0 + 224) |= 2;
        *(f32 *)(a0 + 96) = -func_0038D160(func_0038CED8(a0 + 240), *(f32 *)(a0 + 248));
        *(f32 *)(a0 + 64) = func_0038D160(*(f32 *)(a0 + 240), *(f32 *)(a0 + 244));
    }
}
/* localdecomp:end func_L01_004130D0 */

/* localdecomp:start func_L01_00413138 */
typedef struct {
    f32 x, y, z, w;
} __attribute__((aligned(16))) V4_00413138;

typedef struct {
    s8 pad0[0x424];
    f32 f424;
    s8 pad428[0x460 - 0x428];
} S_00413138;

__asm__(".extern D_L01_001D6530, 4");
__asm__(".extern D_L01_001D6528, 4");
__asm__(".extern D_L01_001D652C, 4");
extern f32 D_L01_001D6530;
extern f32 D_L01_001D6528;
extern f32 D_L01_001D652C;
extern S_00413138 D_L01_001E2A40[];
extern s32 D_L01_00143AD0[][8];
extern s32 D_L01_00143A10[][8];
extern s32 D_L01_00143A70[][8];

extern f32 func_003C4138(f32 *, f32, f32);
extern f32 func_0038CEA8(void *);
extern f32 func_003C4088(f32, f32, f32);
extern void func_L01_00413F48(u8 *);
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
extern void func_L01_00413B68(void *, void *, void *);

void func_L01_00413138(u8 *o, u8 *pad, V4_00413138 *pos, V4_00413138 *tgt, V4_00413138 *up, s32 idx, f32 dt) {
    f32 scale;
    f32 sx, sy;
    f32 yawIn;
    f32 yaw, pitch;
    f32 yawRate, pitchRate;
    s32 i;
    s32 mode;
    u8 *targ;
    f32 tmp;
    V4_00413138 a;
    V4_00413138 b;

    func_003C4138((f32 *)(o + 0x134), dt * D_L01_001D6530, 0.0400000028f);
    if (idx == -1) {
        i = (func_0038CEA8(o + 0xC0) != 0.0f) ? 1 : 2;
    } else {
        i = idx;
    }
    scale = (&D_L01_001E2A40[*(s32 *)(o + 0x12C)])->f424 / 1.11002934f;
    scale *= func_003C4088(0.25f, 1.25f, (f32)D_L01_00143AD0[i][*(s32 *)(o + 0x138)] * 0.015625f);
    func_L01_00413F48(o);
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
    if (D_L01_00143A10[i][*(s32 *)(o + 0x138)] != 0) {
        sy = -sy;
    }
    if (!(*(u16 *)(o + 0xE0) & 8) && D_L01_00143A70[i][*(s32 *)(o + 0x138)] != 0) {
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
        f32 half = 1.0f;
        f32 dist;
        f32 d;
        f32 k;
        vec_sub_ab(&a, tgt, o + 0xA0);
        if (*(u16 *)(o + 0xE0) & 0x20) {
            half = 0.5f;
        }
        if (0.160000011f < func_0038CEA8(&a)) {
            func_0038CF68(&a, &a, 0.160000011f);
        }
        dist = func_0038CF00(pos, *(u8 **)(o + 0x8C) + 0x10);
        d = -(func_0038CE68(&a, o + 0x10) / dist) * *(f32 *)(o + 0x74) * *(f32 *)(o + 0xB0) * half;
        if (0.0314159282f < d) {
            d = 0.0314159282f;
        } else if (d < -0.0314159282f) {
            d = -0.0314159282f;
        }
        yawRate += fabs_asm(d);
        k = *(f32 *)(o + 0x78);
        yaw += d;
        if (dist < D_L01_001D6528) {
            f32 t = (dist - D_L01_001D652C) / (D_L01_001D6528 - D_L01_001D652C);
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
        *(V4_00413138 *)o = *(V4_00413138 *)(o + 0xF0);
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
    func_L01_00413B68(o, &a, &b);
}
/* localdecomp:end func_L01_00413138 */

/* localdecomp:start func_L01_00413AE0 */
extern f32 func_0038D160(f32 a, f32 b);
extern f32 func_0038DB00(f32 a, f32 b);
s32 func_L01_00413AE0(u8 *a0, f32 s) {
    u8 *p;
    p = *(u8 **)(a0 + 140);
    if (p != 0) {
        return s * func_0038DB00(func_0038D160(*(f32 *)(p + 16) - *(f32 *)(a0 + 48), *(f32 *)(p + 20) - *(f32 *)(a0 + 52)), *(f32 *)(a0 + 64)) > 0.0f;
    }
    return 0;
}
/* localdecomp:end func_L01_00413AE0 */

/* localdecomp:start func_L01_00413B68 */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_00413B68;
typedef struct { u8 pad0[0x18]; u8 *f18; u8 pad1C[4]; V_00413B68 v20; V_00413B68 v30; } S_00413B68;
extern f32 func_0038CE68(void *, void *);
extern f32 func_0038CEA8(void *);
extern f32 func_L01_00446E38(void *, void *, s32, f32, void *);
extern void func_003C41A0(f32 *, void *, f32, f32, f32, f32);
extern void func_0038D000(void *, void *, void *);
extern void func_0038CF68(void *, void *, f32);
extern s32 func_003D3CB0(void *, void *, s32, void *, s32);
extern s32 func_003D4D00(void *, s32, f32, void *, void *);
extern f32 func_0038CF00(void *, void *);
extern void func_0038D308(void *, void *);
extern void func_0038D5F0(void *, void *, void *);
extern f32 D_L01_001D6530;
extern f32 D_L01_001D6534;
__asm__(".extern D_L01_001D6530, 4");
__asm__(".extern D_L01_001D6534, 4");
extern S_00413B68 D_L01_001EAA00;

void func_L01_00413B68(void *o_, void *a, void *b) {
    u8 *o = o_;
    V_00413B68 v0;
    V_00413B68 v10;
    V_00413B68 v20;
    V_00413B68 v30;
    V_00413B68 v40;
    V_00413B68 v50;
    V_00413B68 v60;
    V_00413B68 m70[3];
    f32 d;
    f32 len;
    f32 t;
    V_00413B68 *pv0 = &v0;
    V_00413B68 *pv10 = &v10;

    v0 = *(V_00413B68 *)a;
    v10 = *(V_00413B68 *)b;
    v30 = v0;
    vec_sub_ab(&v20, &v0, &v10);
    d = func_0038CE68(&v20, &v20);
    len = func_0038CEA8(o + 0xC0);
    if (fabs_asm(d) > 0.01f) {
        t = func_L01_00446E38(pv10, &v0, 0x84, D_L01_001D6530, *(void **)(o + 0xBC));
        if (t < 1.0f) {
            if (D_L01_001EAA00.f18 == 0 || t > 0.0f) {
                v0 = D_L01_001EAA00.v30;
            }
        }
    }
    if (len == 0.0f) {
        *(V_00413B68 *)(o + 0x30) = *pv0;
        return;
    }
    if (*(u16 *)(o + 0xE0) & 4) {
        *(u16 *)(o + 0xE0) &= ~4;
        func_003C41A0((f32 *)(o + 0x124), o + 0x128, 0.0f, 0.032f, 0.064f, 1.6000001f);
    } else {
        func_0038D000(&v50, o + 0xC0, o);
        func_0038CF68(&v50, &v50, len + 0.5f);
        vec_add_ab(&v50, &v50, &v30);
        if (func_003D3CB0(pv0, &v50, 4, *(void **)(o + 0xBC), 0) != 0) {
            *(vu0_q *)&v60 = *(vu0_q *)&D_L01_001EAA00.v20;
            if (D_L01_001EAA00.f18 != 0 && *(s16 *)(D_L01_001EAA00.f18 + 0xAA) != 0xD54 && func_003D4D00(o + 0x30, 0, 0.51f, *(void **)(o + 0xBC), 0) != 0) {
                len = func_0038CF00(&v30, &v60) - 0.5f;
            } else if (func_003D3CB0(pv0, &v50, 2, *(void **)(o + 0xBC), 0) != 0) {
                len = func_0038CF00(&v30, &D_L01_001EAA00.v20) - 0.5f;
            }
            if (len < 0.0f) {
                *(V_00413B68 *)(o + 0x30) = *pv0;
                return;
            }
        }
        if (len < *(f32 *)(o + 0x124)) {
            *(f32 *)(o + 0x124) = len;
            *(f32 *)(o + 0x128) = 0.0f;
        } else if (len > *(f32 *)(o + 0x124)) {
            if (*(f32 *)(o + 0x128) < 0.0f) {
                *(f32 *)(o + 0x128) = 0.0f;
            }
            func_003C41A0((f32 *)(o + 0x124), o + 0x128, len, 0.008f, 0.008f, 0.40000004f);
        }
    }
    func_0038D000(o + 0x30, o + 0xC0, o);
    func_0038CF68(&v40, o + 0x30, *(f32 *)(o + 0x124) - 1.0f);
    func_0038CF68(o + 0x30, o + 0x30, *(f32 *)(o + 0x124));
    vec_add_ba(o + 0x30, o + 0x30, &v30);
    vec_add_ba(&v40, &v40, pv0);
    if (func_L01_00446E38(&v40, o + 0x30, 0x104, D_L01_001D6534, *(void **)(o + 0xBC)) < 1.0f) {
        *(vu0_q *)(o + 0x30) = *(vu0_q *)&D_L01_001EAA00.v30;
    }
    func_0038D308(m70, o + 0xD0);
    func_0038D5F0(o, o, m70);
}
/* localdecomp:end func_L01_00413B68 */

/* localdecomp:start func_L01_00413F48 */
#include "vu0.h"
typedef struct { u8 p0[0x18]; u8 *p18; } T_13F48;
typedef struct { u8 p0[0x424]; f32 f424; u8 p428[0x38]; } E_13F48;
extern T_13F48 D_L01_001EAA00_00413F48;
extern vu0_q D_L01_001EAA20_00413F48;
extern u8 *D_L01_0021E860_00413F48[];
extern E_13F48 D_L01_001E2A40_00413F48[];
extern void func_0038CF68(void *, void *, f32);
extern s32 func_003D3CB0(void *, void *, s32, void *, s32);
extern f32 func_0038D098(f32);
extern f32 *func_00382348(u8 *);
extern void func_0038D000(void *, void *, void *);
extern f32 func_0038CEA8(void *);
extern void func_0038CE20(void *, void *, f32);
extern f32 func_0038CE68(void *, void *);
extern s32 func_003C4B50(void *);

void func_L01_00413F48(u8 *a0) {
    vu0_v4 *vp;
    vu0_v4 sp0;
    u8 *cand[16];
    vu0_v4 vecs[16];
    f32 dist[16];
    vu0_v4 t190;
    vu0_v4 t1A0;
    u8 *fp;
    s32 k;
    vu0_v4 *pt;
    E_13F48 *tab;
    u8 *m;
    s32 n;
    s32 i;
    f32 best;
    f32 lim;
    f32 d;
    f32 cost;
    f32 t;
    f32 dot;
    void (*fn)(u8 *) = *(void (**)(u8 *))(a0 + 0xE4);

    if (fn != 0) {
        fn(a0);
        return;
    }
    fp = *(u8 **)(a0 + 0x8C);
    *(s32 *)(a0 + 0x8C) = 0;
    *(f32 *)(a0 + 0xB0) = 0;
    func_0038CF68(&sp0, a0, *(f32 *)(a0 + 0x120));
    vec_add_ab(&sp0, &sp0, a0 + 0x30);
    if (func_003D3CB0(a0 + 0x30, &sp0, 0, *(u8 **)(a0 + 0xBC), 0) != 0) {
        u8 *p = D_L01_001EAA00_00413F48.p18;
        if (p != 0 && *(u8 **)(p + 0x24) != 0 && (*(u8 **)(p + 0x24))[0x46] == 5) {
            s32 h = *(s16 *)(p + 0xAA);
            if (h != 0x19C0 && h != 0x1AE6) {
                *(u8 **)(a0 + 0x8C) = p;
                *(f32 *)(a0 + 0xB0) = 1.0f;
            }
        }
        *(vu0_q *)(a0 + 0x110) = D_L01_001EAA20_00413F48;
    } else {
        *(vu0_q *)(a0 + 0x110) = *(vu0_q *)&sp0;
    }
    if (*(u8 **)(a0 + 0x8C) == 0) {
        n = 0;
        lim = 37000000.0f;
        tab = &D_L01_001E2A40_00413F48[*(s32 *)(a0 + 0x12C)];
        best = func_0038D098(*(f32 *)(a0 + 0x7C) * (tab->f424 / 1.1100293f));
        m = D_L01_0021E860_00413F48[0];
        if (m != 0) {
            k = 0;
            pt = &t190;
            vp = vecs;
            do {
                if (m[0x31] != 0 && *(u8 **)(m + 0x24) != 0 && (*(u8 **)(m + 0x24))[0x46] == 5 &&
                    *(s32 *)(m + 0x98) != 0 && m != *(u8 **)(a0 + 0xBC) && *(s16 *)(m + 0xAA) != 0x19C0 &&
                    *(s16 *)(m + 0xAA) != 0x1AE6) {
                    f32 *r = func_00382348(m);
                    if (r != 0) {
                        *(vu0_q *)&t1A0 = 0;
                        t1A0.z = r[4];
                        t190 = t1A0;
                        func_0038D000(pt, pt, m + 0xC0);
                        vec_add_ab(&t190, &t190, m + 0x10);
                        vec_sub_ab(&t1A0, &t190, a0 + 0x30);
                        d = func_0038CEA8(&t1A0);
                        if (!(*(f32 *)(a0 + 0x120) < d)) {
                            func_0038CE20(&t1A0, &t1A0, 1.0f / d);
                            dot = func_0038CE68(&t1A0, a0);
                            if (!(dot < best)) {
                                t = (dot - best) / (1.0f - best);
                                cost = d + d * t;
                                if (func_003C4B50(m) != 0) {
                                    cost += 10.0f;
                                }
                                if (cost < lim) {
                                    lim = cost;
                                    cand[n] = m;
                                    *vp = t190;
                                    dist[n] = t;
                                    n++;
                                    vp++;
                                    if (n >= 16) break;
                                }
                            }
                        }
                    }
                }
                k++;
                m = D_L01_0021E860_00413F48[k];
            } while (m != 0);
        }
        for (i = n - 1; i >= 0; i--) {
            if (func_003D3CB0(a0 + 0x30, &vecs[i], 0, *(u8 **)(a0 + 0xBC), 0) == 0 ||
                D_L01_001EAA00_00413F48.p18 == cand[i]) {
                *(u8 **)(a0 + 0x8C) = cand[i];
                *(f32 *)(a0 + 0xB0) = dist[i];
                break;
            }
        }
    }
    if (*(u8 **)(a0 + 0x8C) != 0) {
        if (*(u8 **)(a0 + 0x8C) == fp) {
            vec_sub_ab(a0 + 0xA0, *(u8 **)(a0 + 0x8C) + 0x10, a0 + 0x90);
        }
        *(vu0_q *)(a0 + 0x90) = *(vu0_q *)(*(u8 **)(a0 + 0x8C) + 0x10);
    } else {
        qzero(a0 + 0xA0);
    }
}
/* localdecomp:end func_L01_00413F48 */

LINKER_REMNANT("asm/levels", func_L01_00414360);

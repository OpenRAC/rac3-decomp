#include "vu0.h"

extern u8 D_001A4BE0[];
typedef struct Moby {
    u8 pad0[0x24];
    u8 *f24;
    u8 pad28[0x54 - 0x28];
    struct Moby *f54;
    u8 pad58[0x68 - 0x58];
    u8 *f68;
    u8 pad6C[0x98 - 0x6C];
    s32 f98;
    s32 f9C;
    u8 padA0[0x100 - 0xA0];
} Moby;

extern Moby *D_L09_001E009C;
extern u8 *D_001D52FC;
extern s32 D_001D545C;
extern u8 *D_L09_001ED940[];
extern vu0_v4 D_L09_001D9B60;
__asm__(".extern D_L09_001DE8D0, 8");
__asm__(".extern D_L09_001DE950, 8");
extern f32 D_L09_001DE8D0[] __attribute__((section(".sdata")));
extern f32 D_L09_001DE950[] __attribute__((section(".sdata")));

extern void func_003C7C38();
extern void func_0038D5B0(u8 *, u8 *);
extern float func_0038DB00(float, float);
extern float func_0038DAB8(float, float);
extern float func_0038DBA0(float, float);
extern float func_0038D160(float, float);
extern s32 func_0038CB00(u8 *);
extern void func_L01_004482A0(u8 *, u8 *, float, float, float, float);
extern float func_L01_004451A8(float);
extern float func_003C4088(float, float, float);
extern void func_003C4138(float *, float, float);
extern void func_L01_00448728(u8 *, float *, s32, float, float, float, float);
extern void func_00382760(void *, float, float, float);
extern void func_0038CE20(vu0_v4 *, vu0_v4 *, float);
extern void func_L01_0040E6B8(u8 *, u8 *, float);
extern void func_L01_0040E728(u8 *, u8 *, float);
extern s32 func_003D4D00(u8 *, s32, u8 *, s32, float);
extern s32 func_003C4B50(u8 *);
extern float func_L01_0040E548(u8 *, u8 *);
extern float func_0038D098(float);
extern float func_0038D0B0(float);
extern void func_L01_00446A70(u8 *, u8 *, s32, u8 *, float *, float);
extern s32 func_L09_003C8740(u8 *, u8 *, u8 *, vu0_v4 *, s32 *, s32, vu0_v4 *, float, float, float);
extern void func_L09_003C8158(u8 *);
extern void func_0038CE90(vu0_v4 *, vu0_v4 *, vu0_v4 *);

void func_L09_003C92E0(u8 *moby) {
    vu0_v4 tmp;
    vu0_v4 hit[2];
    vu0_v4 delta;
    vu0_v4 saved;
    vu0_v4 spare[3];
    float push[4];
    vu0_v4 probe[4];
    float t;
    s32 contact;
    s32 reverse;
    float *speed;
    float *turn;
    s32 *list;
    u8 *p;
    u8 *body;
    u8 *prm;
    u8 *hero;
    u8 *pos;
    u8 *vel;
    float *yaw;
    float heading;
    float accel;
    float grip;
    float slide;
    float ratio;
    float drift;
    float top;
    float steer;
    float k;
    float lim;
    float g;
    float dir;
    s32 i;
    s32 n;
    u8 **lp;
    Moby *m;
    Moby *mp;
    Moby *q;
    u8 *cam;
    u8 *gs;
    vu0_v4 *cv;
    u16 fl;

    reverse = 0;
    p = *(u8 **)(moby + 0x68);
    heading = *(float *)(moby + 0xF8);
    body = *(u8 **)(p + 0x6D0);
    prm = *(u8 **)(p + 0x720);
    contact = 0;
    if (prm == 0) {
        return;
    }
    if (moby[0xBC] == 11 && (*(u16 *)(p + 0x710) & 8)) {
        return;
    }
    list = (s32 *)(p + 0x7B4);
    vel = body + 0xC0;
    speed = (float *)(p + 0x6D8);
    pos = moby + 0x10;
    turn = (float *)(p + 0x6F8);
    for (i = 0; i < 7; i++) {
        if (list[i] != -1) {
            m = &D_L09_001E009C[list[i]];
            m->f98 = *(s32 *)(m->f24 + 0x10);
        }
    }
    if (*(s32 *)(p + 0x7B0) != -1) {
        mp = (Moby *)D_L09_001E009C[*(s32 *)(p + 0x7B0)].f68;
        q = mp->f54;
        if (q != 0) {
            q->f98 = *(s32 *)(q->f24 + 0x10);
            func_003C7C38(mp->f54);
        }
    }
    if (moby[0x20] == 3) {
        gs = D_001A4BE0;
        *(s32 *)(*(u8 **)(gs + 0x25C0) + 0x9C) = -1;
        func_003C7C38(*(u8 **)(gs + 0x25C0));
    }
    cam = D_001A4BE0 + 0x2260;
    saved = *(vu0_v4 *)cam;
    yaw = (float *)(cam - 0x20C0);
    accel = *(float *)(cam + 0x5D8);
    hero = D_001D52FC;
    func_0038D5B0(body, moby + 0xC0);
    if (*(float *)(body + 0x138) < 0.0f) {
        reverse = 1;
    }
    hit[1] = *(vu0_v4 *)(moby + 0x10);
    for (i = 0; i < 4; i++) {
        qzero(&((vu0_v4 *)(p + 0x660))[i]);
    }
    grip = *(float *)(prm + 0xC);
    if (moby[0x20] == 2) {
        heading = *yaw;
        t = saved.x * accel * *(float *)(prm + 0x18);
        if (*(s16 *)(body + 0x128) != 0) {
            t = t * 0.15f;
        }
        if (reverse) {
            *yaw = func_0038DB00(*(float *)(moby + 0xF8), t * 0.017453292f * 0.020000001f);
        } else {
            *yaw = func_0038DAB8(*(float *)(moby + 0xF8), t * 0.017453292f * 0.020000001f);
        }
        if ((*(s32 *)(hero + 0x1A0) & 0x40) && !(*(u16 *)(p + 0x710) & 8)) {
            *(u16 *)(p + 0x78C) += 1;
            slide = *(float *)(prm + 0x30);
            drift = *(float *)(prm + 0x34);
            if ((D_001D545C == 0x15CC || D_001D545C == 0xBC2 || D_001D545C == 0x18) &&
                ((*(s32 *)(hero + 0x1A0) & 4) || (*(u16 *)(p + 0x710) & 2))) {
                if (func_0038CB00(p + 0x71E) != 0) {
                    *(u16 *)(p + 0x710) &= ~2;
                }
                grip = *(float *)(prm + 0x10);
                slide *= 2.0f;
            }
            if (*(s32 *)(hero + 0x1A0) & 4) {
                grip *= 0.8f;
            }
            if (p[0x713] != 0) {
                slide = 0.12f;
                drift = 0.1f;
                grip = 23.5f;
            }
            func_L01_004482A0(body + 0x138, p + 0x6D4, grip * 0.020000001f, slide * 1.44f, drift * 1.44f,
                              *(float *)(prm + 0x2C) * 0.00040000002f);
        } else {
            *(u16 *)(p + 0x78C) -= 2;
        }
        fl = *(u16 *)(p + 0x710);
        if (!(fl & 1) && (*(s32 *)(hero + 0x1A0) & 4) && fabs_asm(saved.x) > 0.05f) {
            *(u16 *)(p + 0x710) = fl | 1;
            *(u16 *)(p + 0x71C) = 0;
            *(float *)(p + 0x70C) = *(float *)(moby + 0xF8);
        }
        fl = *(u16 *)(p + 0x710);
        if ((((*(s32 *)(hero + 0x1A0) & 0x80) && !(fl & 8)) || ((fl & 8) && *(float *)(body + 0x138) > 0.0f)) &&
            *(s16 *)(body + 0x128) == 0) {
            if (*(float *)(body + 0x138) <= 0.0f) {
                func_L01_004482A0(body + 0x138, p + 0x6D4, *(float *)(prm + 0x14) * 0.020000001f,
                                  *(float *)(prm + 0x3C) * 1.44f, *(float *)(prm + 0x40) * 1.44f,
                                  *(float *)(prm + 0x38) * 0.00040000002f);
            } else if ((*(s32 *)(hero + 0x1A0) & 0x40) && !(*(u16 *)(p + 0x710) & 8)) {
                func_L01_004482A0(body + 0x138, p + 0x6D4, *(float *)(prm + 0xC) * 0.6f * 0.020000001f,
                                  *(float *)(prm + 0x30) * 1.44f, *(float *)(prm + 0x34) * 1.44f,
                                  *(float *)(prm + 0x2C) * 0.00040000002f);
            } else {
                func_L01_004482A0(body + 0x138, p + 0x6D4, 0.0f, *(float *)(prm + 0x54) * 1.44f,
                                  *(float *)(prm + 0x58) * 1.44f, *(float *)(prm + 0x50) * 0.00040000002f);
            }
        }
        if (!(*(s32 *)(hero + 0x1A0) & 0xC0)) {
            func_L01_004482A0(body + 0x138, p + 0x6D4, 0.0f, *(float *)(prm + 0x48) * 1.44f,
                              *(float *)(prm + 0x4C) * 1.44f, *(float *)(prm + 0x44) * 0.00040000002f);
        }
    } else if (*(s16 *)(body + 0x128) == 0) {
        func_L01_004482A0(body + 0x138, p + 0x6D4, 0.0f, *(float *)(prm + 0x54) * 1.44f,
                          *(float *)(prm + 0x58) * 1.44f, *(float *)(prm + 0x50) * 0.00040000002f);
    }
    k = *(float *)(body + 0x138);
    if (k < 0.0f) {
        reverse = 1;
        ratio = -k;
    } else {
        ratio = k;
    }
    if ((!reverse && k < 0.0015f) || (moby[0x20] != 2 && fabs_asm(k) < 0.0025f)) {
        ratio = 0.0f;
        *(float *)(body + 0x138) = ratio;
    }
    top = ratio / (grip * 0.020000001f);
    if (top > 1.0f) {
        top = 1.0f;
    }
    if (moby[0x20] != 2) {
        lim = *(float *)(prm + 0x70);
    } else if (*(s16 *)(body + 0x128) != 0) {
        lim = *(float *)(prm + 0x74);
    } else {
        t = func_L01_004451A8(fabs_asm(saved.x));
        if (*(u16 *)(p + 0x710) & 1) {
            *(u16 *)(p + 0x71C) += 1;
            lim = func_003C4088(*(float *)(prm + 0x70), *(float *)(prm + 0x74), t);
        } else if (*(s16 *)(p + 0x71A) < 17 && *(float *)(p + 0x700) < *(float *)(prm + 0x80)) {
            lim = *(float *)(prm + 0x7C);
        } else if (top > 0.5f) {
            lim = func_003C4088(*(float *)(prm + 0x70), *(float *)(prm + 0x78), t);
        } else {
            lim = *(float *)(prm + 0x70);
        }
    }
    t = func_0038DBA0(*(float *)(moby + 0xF8), func_0038D160(*(float *)(body + 0xC0), *(float *)(body + 0xC4)));
    if (lim < *(float *)(p + 0x6D8)) {
        func_003C4138(speed, lim, *(float *)(p + 0x700) * 5.0f * 1.44f);
    } else {
        func_003C4138(speed, lim, *(float *)(p + 0x700) * 1.44f);
    }
    steer = *(float *)(prm + 0x1C) * 1.44f;
    g = *(float *)(prm + 0x20) * 1.44f;
    if ((*(u16 *)(p + 0x710) & 1) && (float)*(s16 *)(p + 0x71C) > 17.0f &&
        (*(s16 *)(body + 0x12A) >= 22 || top < 0.5f || *(float *)(prm + 0x70) * 0.15f <= *(float *)(p + 0x6D8))) {
        t = func_0038DBA0(*(float *)(moby + 0xF8), *(float *)(p + 0x70C));
        fl = *(u16 *)(p + 0x710) & ~1;
        *(u16 *)(p + 0x710) = fl;
        if (*(s16 *)(p + 0x71C) >= 9 && t > 0.43633232f) {
            *(u16 *)(p + 0x710) = fl | 2;
            *(s16 *)(p + 0x71E) = 25;
        }
    }
    dir = func_003C4088(*(float *)(prm + 4) * 0.017453292f * 0.020000001f,
                        *(float *)(prm + 0) * 0.017453292f * 0.020000001f, top);
    k = (1.0f - top) + 1.0f;
    if (k > 1.9f) {
        k = 1.9f;
    }
    steer *= k;
    if (reverse) {
        dir *= 0.5f;
        steer *= 0.5f;
    }
    k = *(float *)(prm + 8) * 0.020000001f;
    if (ratio < k) {
        t = ratio / k;
        k = 0.25f;
        if (p[0x714] != 0) {
            k = 0.7f;
        }
        if (t < k) {
            t = k;
        }
        t = t * t;
        dir *= t;
    }
    if (*(u16 *)(p + 0x710) & 1) {
        dir *= 1.15f;
        steer *= 1.15f;
    }
    if (dir < 0.00034906587f) {
        dir = 0.00034906587f;
    }
    func_003C4138(turn, dir, 0.0069813174f);
    if (moby[0x20] == 2) {
        if (*(s16 *)(body + 0x128) != 0) {
            if (heading == *yaw) {
                *(float *)(body + 0xD8) -= *(float *)(body + 0xD8) * 0.020000001f;
                if (fabs_asm(*(float *)(body + 0xD8)) < 0.001f) {
                    *(float *)(body + 0xD8) = 0.0f;
                }
                *(float *)(moby + 0xF8) = func_0038DAB8(*(float *)(moby + 0xF8), *(float *)(body + 0xD8));
            } else {
                t = *(float *)(body + 0xD8);
                func_L01_00448728(moby + 0xF8, &t, 0, *yaw, steer, g, *(float *)(p + 0x6F8));
                if (t != 0.0f) {
                    *(float *)(body + 0xD8) = t;
                }
            }
        } else {
            func_L01_00448728(moby + 0xF8, (float *)(body + 0xD8), 0, *yaw, steer, g, *(float *)(p + 0x6F8));
        }
    } else {
        *(float *)(body + 0xD8) -= *(float *)(body + 0xD8) * 0.020000001f;
        if (fabs_asm(*(float *)(body + 0xD8)) < 0.005f) {
            *(float *)(body + 0xD8) = 0.0f;
        }
        *(float *)(moby + 0xF8) = func_0038DAB8(*(float *)(moby + 0xF8), *(float *)(body + 0xD8));
    }
    vec_sub_ab(body + 0xC0, body + 0xC0, p + 0x6A0);
    t = 0.0f;
    if (*(s16 *)(body + 0x128) != 0) {
        k = func_0038D160(*(float *)(body + 0xC0), *(float *)(body + 0xC4));
    } else {
        t = -*(float *)(moby + 0xF4);
        if (reverse) {
            k = func_0038DAB8(*(float *)(moby + 0xF8), 3.1415927f);
        } else {
            k = *(float *)(moby + 0xF8);
        }
    }
    func_00382760(&tmp, ratio, k, t);
    func_0038CE20(&tmp, &tmp, *(float *)(p + 0x6D8));
    vec_add_ab(body + 0xC0, body + 0xC0, &tmp);
    if (*(s16 *)(body + 0x128) != 0) {
        k = 9.0f;
        if (p[0x713] == 0) {
            k = *(float *)(prm + 0x24);
        }
        *(float *)(body + 0xC8) -= k * 0.00040000002f;
        func_L01_0040E728(vel, vel, ratio);
    } else {
        *(float *)(body + 0xC8) -= *(float *)(prm + 0x28) * 0.00040000002f;
        if (*(float *)(body + 0xC8) < *(float *)(prm + 0x28) * -3.0f * 0.020000001f) {
            *(float *)(body + 0xC8) = *(float *)(prm + 0x28) * -3.0f * 0.020000001f;
        }
        func_L01_0040E6B8(vel, vel, ratio);
    }
    *(vu0_v4 *)(p + 0x620) = *(vu0_v4 *)(body + 0xC0);
    *(float *)(p + 0x6A0) -= *(float *)(p + 0x6A0) * 0.07000001f;
    if (fabs_asm(*(float *)(p + 0x6A0)) < 0.001f) {
        *(float *)(p + 0x6A0) = 0.0f;
    }
    *(float *)(p + 0x6A4) -= *(float *)(p + 0x6A4) * 0.07000001f;
    if (fabs_asm(*(float *)(p + 0x6A4)) < 0.001f) {
        *(float *)(p + 0x6A4) = 0.0f;
    }
    *(float *)(p + 0x6A8) -= *(float *)(p + 0x6A8) * 0.07000001f;
    if (fabs_asm(*(float *)(p + 0x6A8)) < 0.001f) {
        *(float *)(p + 0x6A8) = 0.0f;
    }
    vec_add_ab(body + 0xC0, body + 0xC0, p + 0x6A0);
    n = func_003D4D00(pos, 0, moby, 0, 4.0f);
    lp = D_L09_001ED940;
    for (i = 0; i < n; i++) {
        if (func_003C4B50(lp[i]) != 0 && func_L01_0040E548(lp[i] + 0x10, pos) < 4.0f) {
            push[0] = func_0038D098(*(float *)(moby + 0xF8)) * 0.2f;
            push[1] = func_0038D0B0(*(float *)(moby + 0xF8)) * 0.2f;
            push[2] = 0.0f;
            func_L01_00446A70(lp[i], moby, 0x10000, pos, push, 1.0f);
        }
    }
    p[0x714] = 0;
    p[0x7AF] = 0;
    p[0x7AF] |= func_L09_003C8740(moby, pos, vel, hit, &contact, 0, &probe[0], fabs_asm(*(float *)(body + 0x138)), 0.2f, 1.5f);
    p[0x7AF] |= func_L09_003C8740(moby, pos, vel, hit, &contact, 1, &probe[1], fabs_asm(*(float *)(body + 0x138)), 0.2f, 1.5f) << 1;
    p[0x7AF] |= func_L09_003C8740(moby, pos, vel, hit, &contact, 2, &probe[2], fabs_asm(*(float *)(body + 0x138)), 0.2f, 1.5f) << 2;
    p[0x7AF] |= func_L09_003C8740(moby, pos, vel, hit, &contact, 3, &probe[3], fabs_asm(*(float *)(body + 0x138)), 0.2f, 1.5f) << 3;
    vec_add_ab(moby + 0x10, moby + 0x10, body + 0xC0);
    func_L09_003C8158(p);
    if (*(s16 *)(body + 0x128) != 0) {
        if (!reverse) {
            func_0038CE20(&tmp, &D_L09_001D9B60, -0.0015f);
            vec_add_ba(p + 0x660, p + 0x660, &tmp);
            vec_add_ab(p + 0x670, p + 0x670, &tmp);
        }
        if (++*(s16 *)(body + 0x12A) >= 18) {
            *(s16 *)(p + 0x71A) = 0;
        }
    } else {
        if (++*(s16 *)(p + 0x71A) > 1000) {
            *(s16 *)(p + 0x71A) = 1000;
        }
        if (*(s16 *)(body + 0x12A) >= 26) {
            *(float *)(p + 0x700) = *(float *)(prm + 0x84);
        }
        func_003C4138((float *)(p + 0x700), *(float *)(prm + 0x80), *(float *)(prm + 0x88) * 0.020000001f);
        *(s16 *)(body + 0x12A) = 0;
        *(float *)(p + 0x6DC) = *(float *)(moby + 0x18);
    }
    for (i = 0; i < 4; i++) {
        vec_sub_ba(&tmp, &D_L09_001DE8D0[i * 4], D_L09_001DE950);
        func_0038CE90(&delta, (vu0_v4 *)(p + 0x660) + i, &tmp);
        *(float *)(p + 0x650) = func_0038DAB8(*(float *)(p + 0x650), delta.x);
        *(float *)(p + 0x654) = func_0038DAB8(*(float *)(p + 0x654), delta.y);
        *(float *)(p + 0x658) = func_0038DAB8(*(float *)(p + 0x658), delta.z);
    }
    *(float *)(p + 0x650) -= *(float *)(p + 0x650) * 0.40000004f;
    if (fabs_asm(*(float *)(p + 0x650)) < 0.0005f) {
        *(float *)(p + 0x650) = 0.0f;
    }
    *(float *)(p + 0x654) -= *(float *)(p + 0x654) * 0.40000004f;
    if (fabs_asm(*(float *)(p + 0x654)) < 0.0005f) {
        *(float *)(p + 0x654) = 0.0f;
    }
    *(float *)(p + 0x658) -= *(float *)(p + 0x658) * 0.20000002f;
    if (fabs_asm(*(float *)(p + 0x658)) < 0.0005f) {
        *(float *)(p + 0x658) = 0.0f;
    }
    *(float *)(moby + 0xF0) = func_0038DAB8(*(float *)(moby + 0xF0), *(float *)(p + 0x650));
    if (fabs_asm(*(float *)(moby + 0xF0)) > 0.9f) {
        if (*(float *)(moby + 0xF0) < -0.9f) {
            *(float *)(moby + 0xF0) = -0.9f;
            if (*(float *)(p + 0x650) < 0.0f) {
                *(float *)(p + 0x650) = 0.0f;
            }
        } else if (*(float *)(moby + 0xF0) > 0.9f) {
            *(float *)(moby + 0xF0) = 0.9f;
            if (*(float *)(p + 0x650) > 0.0f) {
                *(float *)(p + 0x650) = 0.0f;
            }
        }
    }
    *(float *)(moby + 0xF4) = func_0038DAB8(*(float *)(moby + 0xF4), *(float *)(p + 0x654));
    if (fabs_asm(*(float *)(moby + 0xF4)) > 0.9f) {
        if (*(float *)(moby + 0xF4) < -0.9f) {
            *(float *)(moby + 0xF4) = -0.9f;
            if (*(float *)(p + 0x654) < 0.0f) {
                *(float *)(p + 0x654) = 0.0f;
            }
        } else if (*(float *)(moby + 0xF4) > 0.9f) {
            *(float *)(moby + 0xF4) = 0.9f;
            if (*(float *)(p + 0x654) > 0.0f) {
                *(float *)(p + 0x654) = 0.0f;
            }
        }
    }
    *(float *)(moby + 0xF8) = func_0038DAB8(*(float *)(moby + 0xF8), *(float *)(p + 0x658));
    if (moby[0x20] == 2) {
        cv = (vu0_v4 *)(D_001A4BE0 + 0x80);
        gs = D_001A4BE0;
        cv[0] = *(vu0_v4 *)(moby + 0x10);
        cv[1] = *(vu0_v4 *)(moby + 0xF0);
        *(vu0_v4 *)(*(u8 **)(gs + 0x25C0) + 0x10) = *(vu0_v4 *)(moby + 0x10);
        *(vu0_v4 *)(*(u8 **)(gs + 0x25C0) + 0xF0) = *(vu0_v4 *)(moby + 0xF0);
        *(vu0_v4 *)(gs + 0xD0) = *(vu0_v4 *)(moby + 0x10);
        *(float *)(gs + 0xD8) += 0.5f;
    }
    if (*(s32 *)(p + 0x7B0) != -1) {
        q = ((Moby *)D_L09_001E009C[*(s32 *)(p + 0x7B0)].f68)->f54;
        if (q != 0) {
            q->f98 = 0;
        }
    }
    if (moby[0x20] == 3) {
        gs = D_001A4BE0;
        *(s32 *)(*(u8 **)(gs + 0x25C0) + 0x9C) = 0;
        func_003C7C38(*(u8 **)(gs + 0x25C0));
    }
    for (i = 0; i < 7; i++) {
        if (list[i] != -1) {
            D_L09_001E009C[list[i]].f98 = 0;
        }
    }
}

#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L01_0044AF78 */
typedef struct {
    s32 v[6];
} T6_0044BB30;
typedef struct {
    u8 pad0[0x20];
    f32 r;
    f32 g;
    f32 b;
} L_0044BB30;
typedef struct {
    f32 origin[4];
    void *owner;
    s32 flags;
    u8 kind;
    u8 enabled;
    u16 uid;
    f32 damage;
    s32 reserved;
} Msg_0044AF78;
typedef struct {
    f32 vector[4];
    f32 random[4];
} Vecs_0044AF78;
typedef struct {
    u8 pad0[0x20];
    f32 shake;
    s32 pad24;
    s32 timer;
    s32 phase;
} Cam_0044AF78;
__asm__(".extern D_L01_001DFB50, 16");
extern f32 D_L01_001DFB50;
__asm__(".extern D_L01_001DFB4C, 16");
extern f32 D_L01_001DFB4C;
extern u8 D_L01_001E29C0[];
extern Cam_0044AF78 D_L01_001E2A40;
extern T6_0044BB30 D_L01_001D7BF8;
extern T6_0044BB30 D_L01_001D7C10;
extern L_0044BB30 D_L01_002E9C40;
extern L_0044BB30 D_L01_002E9C90;
extern u8 D_001A3190[];
extern f32 func_003824E0(f32, f32);
extern f32 func_00382538(void);
extern s32 func_00382468(s32);
extern s32 func_00382498(s32, s32);
extern void func_00382760(void *, f32, f32, f32);
extern u32 func_L01_00448D88(u32, s32);
extern void func_L01_00465738(void *, void *, s32, s32, s32, s32, s32, s32, s32, f32);
extern f32 func_0038CEA8(void *);
extern void func_0038CF68(void *, void *, f32);
extern void func_L01_0040E6B8(void *, void *, f32);
extern void func_L01_00446748(void *, void *, s32, f32);
extern s32 func_003D4D00(f32, void *, s32, void *, void *);
extern void *func_L01_002FB660(void *, void *, s32, s32, s32, s32);
extern void func_L01_00464690(u8 *, vu0_v4 *, s32, s32, f32, s32, s32, s32, s32, f32);
extern void func_L01_00464210(void *, void *, s32, s32, s32, f32);
extern void func_L01_002F9578(u8 *, u8 *, vu0_v4 *, f32, s32, s32, s32, s32, s32);
extern s32 func_0038DC20(void *, f32);
extern s32 func_003A52A0(s32, s32, void *);
extern void func_L01_003006C0(u8 *, u8 *, s32, s32);

void func_L01_0044AF78(u8 *owner, void *direction, f32 *position, f32 radius, f32 damage, s32 sparks,
                       s32 flashes, s32 smoke, f32 glow, f32 white, f32 cutoff, f32 scale, s32 sound,
                       f32 blast, s32 shake, s32 debris, s32 quality, u8 channels, s32 flags) {
    vu0_v4 drift;
    vu0_v4 delta;
    f32 distance;
    f32 load = D_L01_001DFB50 + D_L01_001DFB4C;

    *(vu0_q *)&drift = 0;
    drift.z = scale * 0.16000001f;
    if (quality == -1 && load > 1.7f) {
        quality = 1;
    }
    if (position == 0) {
        if (owner == 0) {
            return;
        }
        position = (f32 *)(owner + 0x10);
    }
    if (radius > 0.0f) {
    {
        Msg_0044AF78 msg;
        func_L01_00446748(&msg, owner, flags, damage);
        msg.kind = 2;
        msg.enabled = 1;
        msg.uid = *(u16 *)(owner + 0xAA);
        func_003D4D00(radius, position, 16, owner, &msg);
        }
    }
    {
        s32 i;
        for (i = 0; i < sparks; i++) {
        {
            vu0_v4 vector;
            f32 angle;
            f32 azimuth;
            f32 speed;
            s32 c1;
            s32 c2;
            s32 life;
            angle = func_003824E0(0.2617994f, 1.39626336f);
            azimuth = func_00382538();
            speed = func_003824E0(7.0f, 10.5f);
            func_00382760(&vector, scale * (speed * 0.020000001f), azimuth, angle);
            vector.z += 0.060000002f;
            c1 = func_L01_00448D88(0x4F007FFF, channels);
            c2 = func_L01_00448D88(0x1F00007F, channels);
            life = func_00382498(50, 100);
            func_L01_00465738(position, &vector, c1, c2, life - quality * 10, 1, -1, -1, 0, scale * 40000.0f);
            }
        }
    }
    vec_sub_ba(&delta, D_L01_001E29C0, position);
    distance = func_0038CEA8(&delta);
    if (debris) {
    {
        Vecs_0044AF78 v;
        s32 i;
        *(vu0_q *)v.random = 0;
        v.random[0] = func_003824E0(-1.0f, 1.0f);
        v.random[1] = func_003824E0(-1.0f, 1.0f);
        v.random[2] = func_003824E0(-1.0f, 1.0f);
        *(vu0_q *)v.vector = *(vu0_q *)v.random;
        if (distance < 14.0f) {
            delta.z += distance * 0.5f;
            func_0038CF68(v.vector, v.vector, distance / 5.0f * 0.020000001f);
            func_0038CF68(&delta, &delta, (distance + distance) * 0.020000001f);
            vec_add_ab(v.vector, v.vector, &delta);
            func_L01_0040E6B8(v.vector, v.vector, 0.20000002f);
            func_L01_002FB660(position, v.vector, func_00382498(50, 75), 0, 0, 0);
        }
        debris--;
        for (i = 0; i < debris; i++) {
            s32 special;
            f32 angle;
            f32 azimuth;
            f32 speed;
            s32 life;
            angle = func_003824E0(0.2617994f, 1.30899692f);
            azimuth = func_00382538();
            speed = func_003824E0(7.0f, 10.5f);
            func_00382760(v.random, scale * (speed * 0.020000001f), azimuth, angle);
            v.random[2] += 0.040000003f;
            {
                s32 rem = i % 3;
                s32 one = 1;
                s32 zero = 0;
                special = zero;
                if (rem == 0) {
                    special = one;
                }
            }
            life = func_00382498(50, 75);
            func_L01_002FB660(position, v.random, life, special, 0, 0);
        }
        }
    }
    {
        s32 count;
        f32 under;
        s32 i;
        if (distance < (f32)flashes * 2.0f) {
            count = (s32)distance / 2;
        } else {
            count = flashes;
        }
        under = 0.0f;
        if (distance < 7.0f) {
            under = 7.0f - distance;
        }
        for (i = 0; i < count; i++) {
        {
            T6_0044BB30 colors1;
            T6_0044BB30 colors2;
            f32 size;
            f32 big;
            s32 c1;
            s32 c2;
            size = func_003824E0(8.0f, 10.0f) * 0.020000001f;
            colors1 = D_L01_001D7BF8;
            colors2 = D_L01_001D7C10;
            size = size - under * 0.020000001f;
            c1 = func_00382468(6);
            size *= scale;
            c1 = func_L01_00448D88(colors1.v[c1], channels);
            c2 = func_L01_00448D88(colors2.v[func_00382468(6)], channels);
            big = scale * 400000.0f;
            {
                s32 life = func_00382498(12, 17) - quality * 3;
                s32 life2 = func_00382498(25, 37) - quality * 5;
                func_L01_00464690((u8 *)position, &drift, c1, c2, big, life, life2, 0, 0, size);
            }
            {
                s32 life = func_00382498(4, 8) - quality * 2;
                s32 life2 = func_00382498(12, 17) - quality * 3;
                func_L01_00464690((u8 *)position, &drift, 0x7FFFFFFF, 0xFFFFFF, big, life, life2, 0, 0, size * 0.5f);
            }
            }
        }
    }
    {
        s32 i;
        for (i = 0; i < smoke; i++) {
        {
            T6_0044BB30 colors1;
            T6_0044BB30 colors2;
            Vecs_0044AF78 v;
            f32 speed;
            s32 c1;
            s32 c2;
            colors1 = D_L01_001D7BF8;
            colors2 = D_L01_001D7C10;
            *(vu0_q *)v.random = 0;
            v.random[0] = func_003824E0(-1.0f, 1.0f);
            v.random[1] = func_003824E0(-1.0f, 1.0f);
            v.random[2] = func_003824E0(-1.0f, 1.0f);
            *(vu0_q *)v.vector = *(vu0_q *)v.random;
            speed = func_003824E0(0.0f, 3.0f);
            func_0038CF68(v.vector, v.vector, scale * (speed * 0.020000001f));
            c1 = func_L01_00448D88(colors1.v[func_00382468(6)], channels);
            c2 = func_L01_00448D88(colors2.v[func_00382468(6)], channels);
            func_L01_00464210(position, v.vector, c1, c2, func_00382498(25, 37) - quality * 5, 200000.0f);
            }
        }
    }
    if (owner && glow > 0.0f) {
        s32 r = 150, g = 150, b = 150, r2 = 127, g2 = 127, b2 = 0;
        if (channels) {
            if (!(channels & 4)) {
                r = 70;
                b = 70;
                r2 = 60;
            } else {
                r = 35;
                g = 0;
                b = 250;
                r2 = 32;
                g2 = 0;
                b2 = 100;
            }
        }
        if (D_L01_001DFB4C < 0.95f && cutoff < distance) {
            func_L01_002F9578(owner, (u8 *)position, &drift, glow, 13, r, g, b, 32);
            func_L01_002F9578(owner, (u8 *)position, &drift, glow, 18, r2 & 255, g2 & 255, b2 + 80, 32);
        }
        func_L01_002F9578(owner, (u8 *)position, &drift, glow, 25, r2 & 255, g2 & 255, b2, 48);
    }
    if (owner && white > 0.0f) {
        func_L01_002F9578(owner, (u8 *)position, &drift, white, 22, 255, 255, 255, 32);
    }
    if (shake) {
    {
        vu0_v4 vector;
        *(vu0_q *)&vector = *(vu0_q *)position;
        vector.w = 2.0f;
        if (func_0038DC20(&vector, 10.0f) != -1) {
            Cam_0044AF78 *camera = &D_L01_001E2A40;
            if (distance < 20.0f) {
                camera->shake = 0.4f - distance * 0.0175f;
            } else {
                camera->shake = 0.050000012f;
            }
            {
                Cam_0044AF78 *state = &D_L01_001E2A40;
                state->timer = 21;
                state->phase = 0;
            }
        }
        }
    }
    if (owner && sound != -1) {
        s32 h = func_003A52A0(sound, 0, owner);
        if (h != -1) {
            u8 *e;
            *(vu0_q *)(D_001A3190 + (h << 7)) = *(vu0_q *)position;
            e = D_001A3190 - 0xE0 + (h << 7);
            *(s32 *)(e + 0x118) = 0;
            *(s32 *)(e + 0xDC) = 0;
        }
    }
    if (blast != 0.0f && quality == 0) {
    {
        vu0_v4 vector;
        *(vu0_q *)&vector = *(vu0_q *)position;
        vector.w = blast;
        if (func_0038DC20(&vector, 100.0f) != -1) {
            if (blast > 0.0f) {
                L_0044BB30 *effect = &D_L01_002E9C40;
                effect->g = blast;
                effect->b = blast;
                effect->r = blast;
            } else {
                L_0044BB30 *effect = &D_L01_002E9C40;
                effect->g = 15.0f;
                effect->b = 15.0f;
                effect->r = 15.0f;
            }
            if (channels) {
                func_L01_003006C0((u8 *)&D_L01_002E9C90, (u8 *)position, 0, 0);
            } else {
                func_L01_003006C0((u8 *)&D_L01_002E9C40, (u8 *)position, 0, 0);
            }
        }
        }
    }
}
/* localdecomp:end func_L01_0044AF78 */

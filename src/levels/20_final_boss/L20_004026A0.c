#include "common.h"

/* localdecomp:start func_L20_004026A0 */
#include "vu0.h"
typedef struct {
    u8 pad0[0x24];
    f32 scale;
    s16 n1max, n1min;
    s16 n2max, n2min;
    f32 f30;
    f32 f34;
    u8 pad38[0x40 - 0x38];
    s32 i40;
    s32 i44;
    u8 pad48[0x4C - 0x48];
    s16 chance;
    u8 pad4E[2];
    s16 timer;
} S_004026A0;
extern u8 D_00220258[];
extern u8 *func_003C24B0(s32, s32);
extern void func_L20_00402598(void *, void *);
extern s32 func_00382498(s32, s32);
extern f32 func_003824E0(f32, f32);
extern void func_L01_0044FB80(s32, s32, f32, f32, f32);
extern void func_0038CF68(void *, void *, f32);
extern u8 *func_L01_00475C60(void *, void *, s32, s32, s32, s32, s32, f32, f32, f32);
extern s32 func_00382468(s32);
extern f32 func_L01_00443A18(f32, f32);
extern u8 *func_L01_004713C8(void *, void *, s32, u32, s32, s32, s32, f32, f32, f32, s32);
extern void func_L20_004024E8(void *, void *);
extern void func_L01_004450F0(void *, s32, s32);

void *func_L20_004026A0(void *arg) {
    S_004026A0 *a = arg;
    u8 *m = func_003C24B0(0x1F8C, 0x30);
    if (a != 0 && m != 0) {
        vu0_v4 pos;
        vu0_v4 dir;
        f32 spd;
        s32 n;
        s32 i;
        s32 j;
        u8 *p;
        func_L20_00402598(m, a);
        n = func_00382498(a->n1min, a->n1max);
        spd = a->scale * func_003824E0(0.0f, 0.015f);
        for (i = 0; i < n; i++) {
            s32 k = (func_00382498(0x50, 0x64) * 5 + 2) / 6;
            f32 r = func_003824E0(0.9f, 1.5f);
            f32 s = a->scale * r;
            f32 d = a->scale * a->f30;
            f32 s2;
            f32 yaw;
            pos = *(vu0_v4 *)(m + 0x10);
            yaw = func_003824E0(-3.1415927f, 3.1415927f);
            s2 = s + s;
            func_L01_0044FB80((s32)&pos, (s32)&pos, d, yaw, func_003824E0(-3.1415927f, 3.1415927f));
            vec_sub_ab(&dir, &pos, m + 0x10);
            func_0038CF68(&dir, &dir, spd);
            p = func_L01_00475C60(&pos, &dir, k, func_00382498(-1, 1), a->i40, 0, 0, s * 210000.0f, s2 * 210000.0f, 0.0f);
            if (p != 0) {
                u8 *g = D_00220258;
                p[9] = 0xF2;
                p[2] = (*(u8 **)(g + 0x184))[3];
                if (a->chance > 0 && func_00382468(a->chance) == 0) {
                    p[3] = 0x44;
                }
            }
        }
        n = func_00382498(a->n2min, a->n2max);
        for (j = 0; j < n; j++) {
            f32 d;
            f32 yaw;
            s32 life;
            s32 k;
            pos = *(vu0_v4 *)(m + 0x10);
            d = a->scale * a->f30;
            yaw = func_003824E0(-3.1415927f, 3.1415927f);
            func_L01_0044FB80((s32)&pos, (s32)&pos, d, yaw, func_003824E0(-3.1415927f, 3.1415927f));
            vec_sub_ab(&dir, &pos, m + 0x10);
            func_0038CF68(&dir, &dir, a->scale * func_003824E0(0.15f, 0.3f));
            life = func_L01_00443A18(2.0f, 5.0f);
            k = (func_00382498(0x1E, 0x28) * 5 + 2) / 6;
            p = func_L01_004713C8(&pos, &dir, k, a->i44, life, 0x7F, 0x7F, a->scale * (func_003824E0(0.1f, 0.2f) * 210000.0f), 0.0f, 0.0f, 1);
            if (p != 0) {
                p[9] = 0xF2;
            }
        }
        if (a->f34 > 0.0f) {
            func_L20_004024E8(m, a);
        }
        if (a->timer <= 0) {
            func_L01_004450F0(m, 2, -1);
        } else {
            func_L01_004450F0(m, 1, -1);
            *(u16 *)(m + 0x96) = a->timer;
        }
    }
    return m;
}
/* localdecomp:end func_L20_004026A0 */

/* localdecomp:start func_L20_00402AD0 */
#include "vu0.h"
typedef struct {
    vu0_v4 vel;
    s32 field10;
    f32 scale;
    u8 pad18[2];
    s16 chance;
    f32 distance;
    f32 period;
    f32 total;
    f32 fraction;
    f32 rate;
} State_00402AD0;
extern u8 D_00220258[] __attribute__((section(".sdata")));
void func_L20_00402AD0(u8 *obj, State_00402AD0 *s) {
    extern s32 func_00382498(s32, s32);
    extern f32 func_003824E0(f32, f32);
    extern void func_0038CF68(void *, void *, f32);
    extern f32 func_0038CEA8(void *);
    extern void func_003C4C18(void *, f32);
    extern u8 *func_L01_00475C60(void *, void *, s32, s32, s32, s32, s32, f32, f32, f32);
    extern s32 func_00382468(s32);
    vu0_v4 pos, step, spawn, dir;
    f32 amount, speed, distance, width, height, factor;
    s32 count, life, i;
    u8 *p;
    pos = *(vu0_v4 *)(obj + 0x10);
    vec_add_ab(obj + 0x10, obj + 0x10, &s->vel);
    amount = s->rate * (1.5f / s->period);
    count = amount;
    s->fraction += amount - (f32)count;
    if (s->fraction >= 1.0f) {
        s->fraction -= 1.0f;
        count++;
    }
    if (count > 0) {
        func_0038CF68(&step, s, s->period / (f32)count);
        distance = s->distance;
        speed = func_0038CEA8(&step);
        for (i = 0; i < count; i++) {
            vec_add_ab(&pos, &pos, &step);
            life = (func_00382498(90, 110) * 5 + 2) / 6;
            distance += speed;
            width = s->scale * func_003824E0(1.5f, 2.0f);
            factor = ((s->total - distance) / s->total) * 0.8f + 0.19999999f;
            spawn = pos;
            height = width + width;
            width *= factor;
            height *= factor;
            func_003C4C18(&pos, s->scale * 0.15f);
            qzero(&dir);
            p = func_L01_00475C60(&spawn, &dir, life, func_00382498(-1, 1), s->field10, 0, 0,
                                 width * 210000.0f, height * 210000.0f, 0.0f);
            if (p) {
                u8 *g = D_00220258;
                p[9] = 0xF2;
                p[2] = (*(u8 **)(g + 0x184))[3];
                if (s->chance > 0 && func_00382468(s->chance) == 0) p[3] = 0x44;
            }

        }
    }
}
/* localdecomp:end func_L20_00402AD0 */

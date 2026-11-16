#include "common.h"

/* NTSC-U counterpart of func_L39_00532698 (src/levels/shared/L39_00532550.c) */
#include "vu0.h"
extern void func_003886E8(void *, void *, f32);
extern void func_00388830(void *, void *, f32);

/* localdecomp:start func_L39_00532038 */
typedef struct {
    u8 pad0[0xAA];
    s16 hAA;
} M_00532698;

typedef struct {
    u8 pad0[0x18];
    M_00532698 *f18;
    u8 pad1C[0x4];
    vu0_v4 f20;
    u8 pad30[0x10];
    vu0_v4 f40;
} G_00532698;

typedef struct {
    u8 pad0[0x300];
    u8 b300;
    u8 pad301[7];
    f32 f308;
} S_00532698;

extern G_00532698 D_L39_0025F840;
extern s32 D_001A5FBC[];

extern f32 func_00388770(void *);
extern void func_003886E8(void *, void *, f32);
extern f32 func_00388730(void *, void *);
extern void func_00388830(void *, void *, f32);
extern f32 func_L01_00443D00(void *, void *, f32, s32, void *);
extern s32 func_003D00C0(void);
extern void func_L39_00664930(void *, u32, s32, s32);

s32 func_L39_00532038(u8 *a0, S_00532698 *s, vu0_v4 *pos, vu0_v4 *vel, vu0_v4 *out, s32 *hit, f32 max,
                      f32 a, f32 b) {
    vu0_v4 start;
    vu0_v4 v10;
    vu0_v4 dir;
    vu0_v4 p;
    vu0_v4 q;
    vu0_v4 v50;
    vu0_v4 n;
    f32 len;
    f32 t;
    f32 c;
    f32 d;

    c = b * 0.5f + 0.05f;
    p = *pos;
    start = *pos;
    *hit = 0;
    p.z += a + b;
    len = func_00388770(vel);
    if (len <= 0.0f) {
        dir = *(vu0_v4 *)(a0 + 0xD0);
    } else {
        func_003886E8(&dir, vel, 1.0f / len);
    }
    vec_add_ab(&q, &p, vel);
    t = func_L01_00443D00(&p, &q, b, 4, a0);
    if (t < 1.0f) {
        s32 k = func_003D00C0();
        if (D_L39_0025F840.f18 == 0 || D_L39_0025F840.f18->hAA != 0x10C4) {
            if (k == 13 || k == 3 || k == 11) {
                if (s->f308 > 0.0f) {
                    s->f308 = 0.0f;
                    func_L39_00664930(s, 0xFFFFFFFF, 6, D_001A5FBC[0]);
                }
            }
        }
        if (t >= 0.0f) {
            func_003886E8(&q, vel, t);
            vec_add_ab(&p, &p, &q);
            func_003886E8(&n, &D_L39_0025F840.f40, 0.01f);
            vec_add_ab(&p, &p, &n);
        }
        *out = *(vu0_v4 *)&D_L39_0025F840.f20;
        if (D_L39_0025F840.f40.z < 0.5f) {
            D_L39_0025F840.f40.z = 0.0f;
            func_00388830(&n, &D_L39_0025F840.f40, 1.0f);
        }
        d = func_00388730(vel, &n);
        func_003886E8(&v50, &n, d * -1.01f);
        vec_add_ab(vel, vel, &v50);
        len = func_00388770(vel);
        if (max < len) {
            func_003886E8(vel, vel, max / len);
        }
        func_003886E8(&v10, vel, 1.0f - t);
        vec_add_ab(&q, &p, &v10);
        t = func_L01_00443D00(&p, &q, b, 4, a0);
        if (t < 1.0f) {
            if (t >= 0.0f) {
                func_003886E8(&q, &v10, t);
                vec_add_ba(&p, &p, &q);
                func_003886E8(&n, &D_L39_0025F840.f40, 0.01f);
                vec_add_ab(&p, &p, &n);
            }
        } else {
            p = q;
        }
    } else if (t >= 1.0f) {
        p = q;
    }
    q = p;
    *pos = p;
    q.z -= a + c;
    t = func_L01_00443D00(&p, &q, c, 4, a0);
    if (t < 1.0f) {
        s32 k = func_003D00C0();
        if (D_L39_0025F840.f18 == 0 || D_L39_0025F840.f18->hAA != 0x10C4) {
            if (k == 13 || k == 3 || k == 11) {
                if (s->f308 > 0.0f) {
                    s->f308 = 0.0f;
                    func_L39_00664930(s, 0xFFFFFFFF, 6, D_001A5FBC[0]);
                }
            }
        }
        if (t >= 0.0f) {
            vec_sub_ba(&v10, &q, &p);
            func_003886E8(&q, &v10, t);
            vec_add_ab(pos, &p, &q);
        }
        func_00388830(&n, &D_L39_0025F840.f40, 1.0f);
        if (n.z > 0.5f) {
            s->b300 = 0;
        } else {
            s->b300 = 1;
        }
    } else {
        *pos = q;
        s->b300 = 1;
    }
    pos->z = pos->z + c - b;
    return 0;
}
/* localdecomp:end func_L39_00532038 */

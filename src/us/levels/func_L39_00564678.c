#include "common.h"

/* NTSC-U counterpart of func_L39_005651F0 (src/levels/shared/L39_00565008.c) */
/* localdecomp:start func_L39_00564678 */
#include "vu0.h"

typedef struct {
    vu0_v4 v0;
    vu0_v4 v10;
    vu0_v4 v20;
    u8 pad30[4];
    f32 f34;
    f32 f38;
    f32 f3C;
    u8 pad40[4];
    s32 f44;
    s32 f48;
    f32 f4C;
} P_005651F0;

typedef struct {
    u8 pad0[0x1A];
    u16 f1A;
    u8 pad1C[0x14];
    vu0_v4 v30;
} H_005651F0;

typedef struct {
    u8 pad0[0x18];
    u8 *f18;
    u8 pad1C[4];
    vu0_v4 v20;
} G_005651F0;

typedef struct {
    u8 pad0[0x2548];
    s32 team;
} T_005651F0;

extern f32 D_L39_0024B664;
__asm__(".extern D_L39_0024B664, 4");
extern u8 D_L39_00242AB0;
extern T_005651F0 *D_L39_0024CF1C;
extern G_005651F0 D_L39_0025F840;

extern s32 func_L39_005BC958(void *, s32, f32);
extern f32 func_L39_005B25C8_00564678(void);
extern u8 *func_L01_00466F98(void *, void *, s32, s32, s32, s32, f32, f32, f32, f32, f32);
extern void func_00388830(void *, void *, f32);
extern f32 func_00388800(void *, void *);
extern void func_L01_00443628(void *, void *, s32, void *, f32);
extern void func_L39_005FD658(s32);
extern s32 func_003CE740(void *, void *, s32, void *, void *);
extern void func_L39_005FD6D8(void);
extern s32 func_L01_00452F60(void *);
extern void func_L39_005651B8(void *, s32, s32, f32);
extern void func_L01_00452F40(void *, s32);
extern void func_L01_00443648(s32, f32, s32, s32, f32, f32, s32, s32, s32);
extern void func_L01_0031B820(u8 *);
extern void func_L01_004026A0(void *, void *);
/* level 39 calls func_L01_003500C0's place, level 45 another empty function */
extern void func_L01_0034F5E8_00564678(void *);
extern void func_003BD360(void *);

void func_L39_00564678(u8 *obj) {
    P_005651F0 *p = *(P_005651F0 **)(obj + 0x68);
    vu0_q seg[2];
    vu0_v4 dir;
    H_005651F0 hit;
    vu0_v4 back;
    f32 t;
    f32 s;
    f32 scale;
    s32 r;
    s32 last;
    f32 step;
    s32 team;
    G_005651F0 *g;
    vu0_v4 *pos;

    t = p->f38 + 1.0f;
    s = p->f3C;
    p->f38 = t;
    if (t > 32.0f) {
        s *= 1.0f - (t - 32.0f) / 6.0f;
    }
    scale = (s > 1.0f) ? s : 1.0f;
    if (t > 2.0f) {
        seg[0] = *(vu0_q *)&p->v10;
    } else {
        seg[0] = *(vu0_q *)&p->v0;
    }
    seg[1] = *(vu0_q *)&p->v10;
    ((f32 *)&seg[1])[3] = 0.5f;
    if (func_L39_005BC958(&seg[1], 0, D_L39_0024B664) != -1) {
        func_L01_00466F98(&p->v10, &D_L39_00242AB0, 4, 0x60, p->f44, (s32)func_L39_005B25C8_00564678(),
                          *(f32 *)(obj + 0x2C) * 210000.0f, 200.0f, 0.95f, 0.0f, 0.0f);
    }
    if (p->f38 < 15.0f) {
        p->f34 += p->f4C * 0.0166666675f;
        func_00388830(&p->v10, &p->v20, p->f34);
        func_00388830(&dir, &p->v20, 0.0666666701f);
        func_L01_00443628(&hit, obj, 0x10001, &dir, scale);
        hit.f1A = *(u16 *)(obj + 0xAA);
        vec_add_ba(&p->v10, &p->v0, &p->v10);
        func_00388830(&hit.v30, &p->v20, -(p->f4C * 0.0166666675f));
        vec_add_ab(&hit.v30, &hit.v30, &p->v10);
        team = -1;
        if (D_L39_0024CF1C != 0) {
            team = D_L39_0024CF1C->team;
        }
        func_L39_005FD658(team);
        r = func_003CE740(&p->v10, seg, 0x10, obj, &hit);
        func_L39_005FD6D8();
        if (r != 0 && (g = &D_L39_0025F840)->f18 != *(u8 **)(obj + 0xB8)) {
            last = g->f18 == 0;
            pos = &g->v20;
            *(vu0_q *)&p->v10 = *(vu0_q *)pos;
            if (func_L01_00452F60(obj) == 0) {
                func_L39_005651B8(pos, 0x14, p->f48, *(f32 *)(obj + 0x2C));
                func_L01_00452F40(obj, 1);
                if (last) {
                    func_L01_00443648((s32)obj, 0.75f, (s32)pos, 0x10001, scale, 1.0f, 0, 1, 0);
                }
            }
            func_003BD360(obj);
            return;
        }
        func_L01_004026A0(func_L01_0031B820, obj);
    } else if (p->f38 < 38.0f) {
        f32 d = func_00388800(p, &p->v10);
        step = p->f4C * 0.0166666675f;
        if (step < d) {
            p->f34 += step;
            func_00388830(&p->v10, &p->v20, p->f34);
            func_00388830(&dir, &p->v20, 0.0666666701f);
            func_L01_00443628(&hit, obj, 0x10001, &dir, scale);
            hit.f1A = *(u16 *)(obj + 0xAA);
            vec_add_ba(&p->v10, &p->v0, &p->v10);
            func_00388830(&hit.v30, &p->v20, -(p->f4C * 0.0166666675f));
            vec_add_ab(&hit.v30, &hit.v30, &p->v10);
            team = -1;
            if (D_L39_0024CF1C != 0) {
                team = D_L39_0024CF1C->team;
            }
            func_L39_005FD658(team);
            r = func_003CE740(&p->v10, seg, 0x10, obj, &hit);
            func_L39_005FD6D8();
            if (r != 0 && (g = &D_L39_0025F840)->f18 != *(u8 **)(obj + 0xB8)) {
                last = g->f18 == 0;
                if (g->f18 == 0 || *(s16 *)(g->f18 + 0xAA) != 0x1625) {
                    pos = &g->v20;
                    *(vu0_q *)&p->v10 = *(vu0_q *)pos;
                    if (func_L01_00452F60(obj) == 0) {
                        func_L39_005651B8(pos, 0x14, p->f48, *(f32 *)(obj + 0x2C));
                        func_L01_00452F40(obj, 1);
                        if (last) {
                            func_L01_00443648((s32)obj, 0.75f, (s32)pos, 0x10001, scale, 1.0f, 0, 1, 0);
                        }
                    }
                    func_003BD360(obj);
                    return;
                }
            }
            func_00388830(&back, &p->v20, p->f4C * 2.0f * 0.0166666675f);
            vec_add_ab(&p->v0, &p->v0, &back);
            func_L01_004026A0(func_L01_0031B820, obj);
        }
    } else {
        func_L01_0034F5E8_00564678(&p->v10);
        func_003BD360(obj);
        return;
    }
    *(vu0_q *)(obj + 0x10) = *(vu0_q *)&p->v0;
}
/* localdecomp:end func_L39_00564678 */

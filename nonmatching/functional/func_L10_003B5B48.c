/* functional: medium. Written from retail asm (no draft); compiles at level 10 (569 diff instrs, not byte-exact). Callee roles inferred from arg shapes: func_003824E0 randf(lo,hi), func_00382498/00382468 random ints, 0038CE20/0038CF68 vec*scalar. w lanes of D_001E1500/1510 (uninitialised stack in retail) are left unwritten; D_001E1510 = (max.x-min.x,0,0) because retail loads vf2 before storing the y/z midpoints. Snow/dust particle emitter, 4 slots of 0x30 bytes at D_002A1F20. */
#include "common.h"
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_3B5B48;
typedef struct {
    V4_3B5B48 pos;      /* D_002A1F20 + i*0x30 */
    V4_3B5B48 vel;      /* D_002A1F30 + i*0x30 */
    s32 life;           /* 0x20 */
    s32 delay;          /* 0x24 */
    s32 pad[2];
} Dust_3B5B48;

__asm__(".extern D_L10_001DEC58, 4");
extern f32 D_L10_001DEC58;
extern u8 D_L10_001E5F00[];
extern u8 *D_L10_001E0154;
extern u8 *D_L10_001E0158;
extern u8 D_L10_0023A300[];
extern u8 D_L10_0023BB34;
extern u8 D_L10_0021EB98[];
extern Dust_3B5B48 D_L10_002A1F20[4];
extern V4_3B5B48 D_L10_001E1500;
extern V4_3B5B48 D_L10_001E1510;
extern f32 func_003824E0(f32, f32);                      /* random float in [a, b] */
extern s32 func_00382498(s32, s32);                      /* random int */
extern s32 func_00382468(s32);                           /* random int below n */
extern f32 func_L01_00443A18(f32, f32);
extern void func_0038CE20(void *, void *, f32);          /* dst = src * s */
extern void func_0038CF68(void *, void *, f32);
extern void func_L01_0044FB80(void *, void *, f32, f32, f32);
extern u8 *func_L01_00475C60(void *, void *, s32, s32, s32, s32, f32, f32, f32, s32);
extern u8 *func_L01_004713C8(void *, void *, s32, u32, s32, s32, s32, f32, f32, f32, s32);
extern void func_003C4C18(f32 *, f32);
extern s32 func_L01_004AAC98(s32, s32, void *, s32);

void func_L10_003B5B48(void *arg) {
    V4_3B5B48 mn, mx, c, t, d;
    u8 *r;
    u8 *e;
    s32 st;
    s32 i, n, cnt, k, lt;
    f32 f, a, b, g, g2;
    Dust_3B5B48 *p;
    u8 *res;

    st = *(s32 *)(D_L10_001E5F00 + 0x34);
    if (st == 1) {
        cnt = 0;
        for (r = D_L10_001E0154; r < D_L10_001E0158; r += 0x20) {
            r[0x1C] = 0xFF;
            if (r[0x1D] == D_L10_0023A300[0x1834]) {
                cnt++;
            }
        }
        mx.x = -10000.0f; mx.y = -10000.0f; mx.z = -10000.0f;
        mn.x = 10000.0f;  mn.y = 10000.0f;  mn.z = 10000.0f;
        if (cnt != 0) {
            for (r = D_L10_001E0154; r < D_L10_001E0158; r += 0x20) {
                if (r[0x1D] != D_L10_0023BB34) {
                    continue;
                }
                c.x = *(f32 *)(r + 0); c.y = *(f32 *)(r + 4); c.z = *(f32 *)(r + 8);
                if (mx.x < c.x) mx.x = c.x;
                if (mx.y < c.y) mx.y = c.y;
                if (mx.z < c.z) mx.z = c.z;
                if (c.x < mn.x) mn.x = c.x;
                if (c.y < mn.y) mn.y = c.y;
                if (c.z < mn.z) mn.z = c.z;
            }
        }
        /* retail loads vf2 (max.x, max.y, max.z) before storing the midpoint into y/z, so the
           extent is (max.x - min.x, 0, 0); w words come from uninitialised stack and are left alone */
        D_L10_001E1510.x = mx.x - mn.x;
        D_L10_001E1510.y = 0.0f;
        D_L10_001E1510.z = 0.0f;
        D_L10_001E1500.x = mn.x;
        D_L10_001E1500.y = (mx.y + mn.y) * 0.5f;
        D_L10_001E1500.z = (mx.z + mn.z) * 0.5f;
        for (i = 0; i < 4; i++) {
            D_L10_002A1F20[i].life = 0;
            D_L10_002A1F20[i].delay = 0;
        }
    } else if ((u32)(st - 0x149) < 5) {
        D_L10_001DEC58 = (f32)(st - 0x149) / 5.0f;
    } else if ((u32)(st - 0x14E) < 10) {
        f = (f32)(0x157 - st) / 10.0f;
        D_L10_001DEC58 = f;
        if (1.0f < f) {
            D_L10_001DEC58 = 1.0f;
        }
    }

    if (*(s32 *)(D_L10_001E5F00 + 0x34) < 0x3B) {
        return;
    }

    for (i = 0; i < 4;) {
        p = &D_L10_002A1F20[i];
        if (p->life == 0 && p->delay == 0) {
            p->life = func_00382498(0x14, 0x19);
            p->delay = func_00382498(10, 5);
            f = func_003824E0(0.0f, 1.8f);
            func_0038CE20(&t, &D_L10_001E1510, f);
            p->pos.x = D_L10_001E1500.x + t.x;
            p->pos.y = D_L10_001E1500.y + t.y;
            p->pos.z = D_L10_001E1500.z + t.z;
            p->pos.w = D_L10_001E1500.w;
            p->vel.x = 0.0f; p->vel.y = 0.0f; p->vel.z = 0.0f; p->vel.w = 0.0f;
            a = func_003824E0(25.0f, 30.0f);
            b = func_003824E0(-3.1415927f, 3.1415927f);
            g = func_003824E0(-3.1415927f, 3.1415927f);
            func_L01_0044FB80(&p->vel, &p->vel, a, b, g);
            p->vel.x = 0.0f;
            p->pos.x += p->vel.x;
            p->pos.y += p->vel.y;
            p->pos.z += p->vel.z;
            f = func_003824E0(4.0f, 6.0f);
            func_0038CF68(&p->vel, &p->vel, f);
            n = func_00382498(0x14, 0x1E);
            g = func_003824E0(0.0f, 0.25f);   /* f30 */
            for (k = n; k > 0;) {
                s32 ra = func_00382498(0x5A, 0x78);
                lt = (ra * 5 + 2) / 6;
                a = func_003824E0(15.0f, 18.0f);      /* f22 */
                b = a + a;                            /* f23 */
                t = p->pos;
                f = func_003824E0(10.0f, 14.0f);
                g2 = func_003824E0(-3.1415927f, 3.1415927f);
                {
                    f32 h = func_003824E0(-3.1415927f, 3.1415927f);
                    func_L01_0044FB80(&t, &t, f, g2, h);
                }
                d.x = t.x - p->pos.x;
                d.y = t.y - p->pos.y;
                d.z = t.z - p->pos.z;
                d.w = t.w;
                func_0038CF68(&d, &d, g);
                d.z += func_003824E0(0.0f, 0.2f);
                res = func_L01_00475C60(&t, &d, lt, func_00382498(-1, 1), 0x7F407FFF, 0x1020FF,
                                        a * 210000.0f, b * 210000.0f, 0.0f, 0);
                if (res != 0) {
                    res[9] = 0xF2;
                    res[2] = (*(u8 **)(D_L10_0021EB98 + 0x184))[3];
                    if (func_00382468(2) == 0) {
                        res[3] = 0x44;
                    }
                }
                if (func_00382468(2) == 0) {
                    f = func_003824E0(1.5f, 3.0f);
                    func_0038CF68(&d, &d, f);
                    lt = (s32)func_L01_00443A18(2.0f, 5.0f);
                    ra = func_00382498(0x28, 0x41);
                    ra = (ra * 5 + 2) / 6;
                    f = func_003824E0(2.0f, 5.0f);
                    res = func_L01_004713C8(&t, &d, ra, 0x7F407FFF, lt, 0x7F, 0x7F,
                                            f * 210000.0f, 0.0f, 0.0f, 1);
                    if (res != 0) {
                        res[9] = 0xF2;
                        if (func_00382468(2) == 0) {
                            res[3] = 0x44;
                        }
                    }
                }
                k--;
            }
            func_L01_004AAC98(0, 0, arg, 0x1F7B);
            i++;
        } else if (p->life > 0) {
            p->life--;
            i++;
            if (p->life >= 0xB) {
                t = p->pos;
                d.x = 0.0f; d.y = 0.0f; d.z = 0.0f; d.w = 0.0f;
                func_003C4C18((f32 *)&d, 0.15f);
                d.z += func_003824E0(0.0f, 0.2f);
                lt = (func_00382498(0x32, 0x46) * 5 + 2) / 6;
                a = func_003824E0(16.0f, 20.0f);
                b = a + a;
                f = (f32)p->life / 20.0f * 0.8f + 0.2f;
                b = b * f;
                a = a * f;
                res = func_L01_00475C60(&t, &d, lt, func_00382498(-1, 1), 0x7F407FFF, 0x1020FF,
                                        a * 210000.0f, b * 210000.0f, 0.0f, 0);
                if (res != 0) {
                    res[9] = 0xF2;
                    res[2] = (*(u8 **)(D_L10_0021EB98 + 0x184))[3];
                    if (func_00382468(2) == 0) {
                        res[3] = 0x44;
                    }
                }
                p->pos.x = p->vel.x + p->pos.x;
                p->pos.y = p->vel.y + p->pos.y;
                p->pos.z = p->vel.z + p->pos.z;
                p->pos.w = p->vel.w;
            }
        } else {
            p->delay--;
            i++;
        }
    }
}

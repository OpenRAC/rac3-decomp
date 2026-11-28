/* func_L10_003B5B48 (Claude wave 14 r54, 2026-11-28). First draft kept here. */
/* PAL near miss (r54, wave 14): first draft of a fresh entry, the native port's functional C (nonmatching/functional)
 * in block form: 569 diff under the file's line. Retail has VU0 macro code (lqc2/vsub.xyz/vadd.xyz/sqc2 at 0x238, 0x3A4,
 * 0x430, 0x588, 0x8D0), which needs -mvu0-use-vf0-vf2: L10_003B5B48.c's line '-O2 -G8 -fopt-stack -mno-check-zero-division
 * @ps2as' has no VU0 class, so the function cannot match there; the existing line '-O2 -G8 -fopt-stack
 * -mno-check-zero-division @ps2as -mvu0-use-vf0-vf2' (L10_003B9570.c) on a cut 0x003B5B48-0x003B64C8 (the file's first
 * function; both ends 8-aligned) is the line to try, with the vector steps as vu0.h helpers. Not yet worked for bytes. */
#include "common.h"

/* localdecomp:start func_L10_003B5B48 */
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
/* localdecomp:end func_L10_003B5B48 */

/* The other form the notes name (Claude wave 14 r54, func_L10_003B5B48.cut.c): the draft for the line or declaration it needs, not compiled here. */
#if 0
/* PAL near miss (r54, wave 14) for the cut line '-O2 -G8 -fopt-stack -mno-check-zero-division @ps2as -mvu0-use-vf0-vf2'
 * (0x003B5B48-0x003B64C8) with divs '1 0 2': 567 diff, the retail control flow rewritten with vu0.h vec_sub_ab/vec_add_ba/
 * vec_add_ab for retail's VU0 steps and the +-9999.0f bounds; still misaligned from the prologue (retail keeps &D_L10_001E5F00
 * in a register and its high half in t2, the bound stores' order) and not worked further. */
#include "common.h"

/* localdecomp:start func_L10_003B5B48 */
#include "vu0.h"
typedef struct {
    vu0_v4 pos;     /* 0x00 */
    vu0_v4 vel;     /* 0x10 */
    s32 life;       /* 0x20 */
    s32 delay;      /* 0x24 */
    s32 pad28[2];
} Dust_003B5B48;

typedef struct {
    f32 x, y, z;
    u8 padC[0x10];
    u8 b1C;
    u8 b1D;
    u8 pad1E[2];
} Mark_003B5B48;

extern f32 D_L10_001DEC58;
__asm__(".extern D_L10_001DEC58, 4");
extern u8 D_L10_001E5F00[];
extern Mark_003B5B48 *D_L10_001E0154;
extern Mark_003B5B48 *D_L10_001E0158;
extern u8 D_L10_0023A300[];
extern u8 D_L10_0021EB98[];
extern Dust_003B5B48 D_L10_002A1F20[4];
extern vu0_v4 D_L10_001E1500;
extern vu0_v4 D_L10_001E1510;

void func_L10_003B5B48(void *arg) {
    extern f32 func_003824E0(f32, f32);
    extern s32 func_00382498(s32, s32);
    extern s32 func_00382468(s32);
    extern f32 func_L01_00443A18(f32, f32);
    extern void func_0038CE20(void *, void *, f32);
    extern void func_0038CF68(void *, void *, f32);
    extern void func_L01_0044FB80(void *, void *, f32, f32, f32);
    extern u8 *func_L01_00475C60(void *, void *, s32, s32, s32, s32, s32, f32, f32, f32);
    extern u8 *func_L01_004713C8(void *, void *, s32, f32, s32, s32, s32, s32, f32, f32, s32);
    extern void func_003C4C18(void *, f32);
    extern s32 func_L01_004AAC98(s32, s32, void *, s32);
    s32 st;
    s32 i;

    st = ((s32 *)D_L10_001E5F00)[13];
    if (st == 1) {
        vu0_v4 mn;
        vu0_v4 mx;
        vu0_v4 c;
        vu0_v4 center;
        vu0_v4 size;
        Mark_003B5B48 *r;
        s32 cnt;

        cnt = 0;
        for (r = D_L10_001E0154; r < D_L10_001E0158; r++) {
            r->b1C = 0xFF;
            if (r->b1D == D_L10_0023A300[0x1834]) {
                cnt++;
            }
        }
        mx.x = mx.y = mx.z = -9999.0f;
        mn.x = mn.y = mn.z = 9999.0f;
        if (cnt != 0) {
            for (r = D_L10_001E0154; r < D_L10_001E0158; r++) {
                if (r->b1D == D_L10_0023A300[0x1834]) {
                    c.x = r->x;
                    c.y = r->y;
                    c.z = r->z;
                    if (mx.x < c.x) mx.x = c.x;
                    if (mx.y < c.y) mx.y = c.y;
                    if (mx.z < c.z) mx.z = c.z;
                    if (c.x < mn.x) mn.x = c.x;
                    if (c.y < mn.y) mn.y = c.y;
                    if (c.z < mn.z) mn.z = c.z;
                }
            }
        }
        center = mx;
        size = mx;
        center.x = mn.x;
        vec_sub_ab(&D_L10_001E1510, &size, &center);
        center.y = (mx.y + mn.y) * 0.5f;
        center.z = (mx.z + mn.z) * 0.5f;
        D_L10_001E1500 = center;
        for (i = 0; i < 4; i++) {
            D_L10_002A1F20[i].life = 0;
            D_L10_002A1F20[i].delay = 0;
        }
    } else if ((u32)(st - 0x149) < 5) {
        D_L10_001DEC58 = (f32)(st - 0x149) / 5.0f;
    } else if ((u32)(st - 0x14E) < 10) {
        D_L10_001DEC58 = (f32)(0x157 - st) / 10.0f;
        if (1.0f < D_L10_001DEC58) {
            D_L10_001DEC58 = 1.0f;
        }
    }
    if (*(s32 *)(D_L10_001E5F00 + 0x34) < 0x3B) {
        return;
    }
    for (i = 0; i < 4; i++) {
        Dust_003B5B48 *p = &D_L10_002A1F20[i];
        vu0_v4 t;
        vu0_v4 d;
        u8 *res;
        s32 lt;
        f32 a;
        f32 b;

        if (p->life == 0 && p->delay == 0) {
            s32 n;
            s32 k;
            f32 g;

            p->life = func_00382498(20, 25);
            p->delay = func_00382498(10, 5);
            func_0038CE20(&t, &D_L10_001E1510, func_003824E0(0.0f, 1.8f));
            vec_add_ba(&p->pos, &D_L10_001E1500, &t);
            *(vu0_q *)&p->vel = 0;
            a = func_003824E0(25.0f, 30.0f);
            b = func_003824E0(-3.1415927f, 3.1415927f);
            func_L01_0044FB80(&p->vel, &p->vel, a, b, func_003824E0(-3.1415927f, 3.1415927f));
            p->vel.x = 0.0f;
            vec_add_ba(&p->pos, &p->pos, &p->vel);
            func_0038CF68(&p->vel, &p->vel, func_003824E0(4.0f, 6.0f));
            n = func_00382498(20, 30);
            g = func_003824E0(0.0f, 0.25f);
            for (k = 0; k < n; k++) {
                f32 s;
                f32 h;

                lt = (func_00382498(90, 120) * 5 + 2) / 6;
                a = func_003824E0(15.0f, 18.0f);
                b = a + a;
                t = D_L10_002A1F20[i].pos;
                s = func_003824E0(10.0f, 14.0f);
                h = func_003824E0(-3.1415927f, 3.1415927f);
                func_L01_0044FB80(&t, &t, s, h, func_003824E0(-3.1415927f, 3.1415927f));
                vec_sub_ab(&d, &t, &D_L10_002A1F20[i].pos);
                func_0038CF68(&d, &d, g);
                d.z += func_003824E0(0.0f, 0.2f);
                res = func_L01_00475C60(&t, &d, lt, func_00382498(-1, 1), 0x7F407FFF, 0x1020FF, 0,
                                        a * 210000.0f, b * 210000.0f, 0.0f);
                if (res != 0) {
                    res[9] = 0xF2;
                    res[2] = (*(u8 **)(D_L10_0021EB98 + 0x184))[3];
                    if (func_00382468(2) == 0) {
                        res[3] = 0x44;
                    }
                }
                if (func_00382468(2) == 0) {
                    s32 life2;

                    func_0038CF68(&d, &d, func_003824E0(1.5f, 3.0f));
                    lt = func_L01_00443A18(2.0f, 5.0f);
                    life2 = (func_00382498(40, 65) * 5 + 2) / 6;
                    res = func_L01_004713C8(&t, &d, life2, func_003824E0(2.0f, 5.0f) * 210000.0f, 0x7F407FFF, lt,
                                            0x7F, 0x7F, 0.0f, 0.0f, 1);
                    if (res != 0) {
                        res[9] = 0xF2;
                        if (func_00382468(2) == 0) {
                            res[3] = 0x44;
                        }
                    }
                }
            }
            func_L01_004AAC98(0, 0, arg, 0x1F7B);
        } else if (p->life > 0) {
            p->life--;
            if (p->life >= 11) {
                f32 f;

                t = p->pos;
                *(vu0_q *)&d = 0;
                func_003C4C18(&d, 0.15f);
                d.z += func_003824E0(0.0f, 0.2f);
                lt = (func_00382498(50, 70) * 5 + 2) / 6;
                a = func_003824E0(16.0f, 20.0f);
                b = a + a;
                f = (f32)p->life / 20.0f * 0.8f + 0.2f;
                b *= f;
                a *= f;
                res = func_L01_00475C60(&t, &d, lt, func_00382498(-1, 1), 0x7F407FFF, 0x1020FF, 0,
                                        a * 210000.0f, b * 210000.0f, 0.0f);
                if (res != 0) {
                    res[9] = 0xF2;
                    res[2] = (*(u8 **)(D_L10_0021EB98 + 0x184))[3];
                    if (func_00382468(2) == 0) {
                        res[3] = 0x44;
                    }
                }
                vec_add_ab(&D_L10_002A1F20[i].pos, &D_L10_002A1F20[i].vel, &D_L10_002A1F20[i].pos);
            }
        } else {
            p->delay--;
        }
    }
}
/* localdecomp:end func_L10_003B5B48 */
#endif

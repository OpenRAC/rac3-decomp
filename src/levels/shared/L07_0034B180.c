#include "common.h"

typedef int Q128_34B180 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_34B180;
typedef struct {
    s16 f0, f2, f4;
    u8 pad6[2];
    f32 f8, fC, f10, f14;
    s32 f18, f1C, f20, f24, f28, f2C, f30, f34, f38;
} V_34B180;
typedef struct {
    u8 pad0[0x10];
    f32 x, y, z;
    u8 pad1C[0x68 - 0x1C];
    V_34B180 *v;
    u8 pad6C[0xC0 - 0x6C];
    V4_34B180 q0;
    V4_34B180 q1;
} M_34B180;
typedef struct { f32 x, y; u8 pad[0x458]; } P_34B180;

/* localdecomp:start func_L07_0034B180 */
#include "vu0.h"


__asm__(".extern D_L07_001D66B0, 16");
extern u8 D_L07_001D66B0;

extern P_34B180 D_L07_001E1EC0[];
extern s32 D_001D52F0;
extern u8 *D_L07_0021EC98[];
extern u8 *D_L07_0021EE08[];
__asm__(".extern D_L07_001DD508, 4");
extern f32 D_L07_001DD508;
__asm__(".extern D_L07_001DD50C, 4");
extern f32 D_L07_001DD50C;
__asm__(".extern D_L07_001DD510, 4");
extern s32 D_L07_001DD510;

extern f32 func_0038D160(f32, f32);
extern f32 func_L01_00443A18(f32, f32);
extern s32 func_00382498(s32, s32);
extern f32 func_003824E0(f32, f32);
extern f32 func_0038DAB8(f32, f32);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern u8 *func_L01_0046FB40(void *, void *, s32, s32, s32, s32, s32, f32, f32, s32, f32);
extern u8 *func_L01_004713C8(void *, void *, s32, u32, s32, s32, s32, f32, f32, f32, s32);
extern void func_0038CE20(void *, void *, f32);
extern void func_003C4840(void *, void *, f32);
extern void func_0038D850(void *, void *, void *);
extern u8 *func_L01_00470668(void *, void *, s32, f32);
extern void func_L01_002F9578(f32, void *, void *, void *, s32, u8, u8, u8, u8);
extern void func_L01_0044AF78(void *, void *, void *, s32, s32, s32, f32, f32, f32, f32, s32, s32, s32, s32, s32, s32, f32, f32, f32);
extern u8 *func_L01_004669B0(void *, f32, f32, f32, f32, s32, void *, u32, s32);
extern void func_00382760(void *, f32, f32, f32);

void func_L07_0034B180(u8 *mb)
{
    M_34B180 *m = (M_34B180 *)mb;
    V_34B180 *v = m->v;
    V4_34B180 pos, vel, tmp;
    u8 *r0;
    f32 fa, fb, heading, speed;

    fa = D_L07_001DD508 * v->f14 * 210000.0f;
    fb = D_L07_001DD50C * v->f14 * 210000.0f;
    r0 = func_L01_0046FB40(&m->x, &D_L07_001D66B0, (D_L07_001DD510 * 5 + 2) / 6,
                           0x388EF7, 0, 0x64, 0, fa, fb, 0, 0.0f);
    if (r0 != 0) {
        r0[2] = D_L07_0021EE08[0][0];
    }
    r0 = func_L01_0046FB40(&m->x, &D_L07_001D66B0, (D_L07_001DD510 * 5 + 2) / 6,
                           0xF76300, 0, 0x64, 0, fa, fb, 0, 0.0f);
    if (r0 != 0) {
        r0[2] = D_L07_0021EE08[0][0];
    }
    {
        s32 j;
        for (j = 0; j < 2; j++) {
            r0 = func_L01_0046FB40(&m->x, &D_L07_001D66B0, (D_L07_001DD510 * 5 + 2) / 6,
                                   0xF78E38, 0, 0x7F, 0, fa, fb, 0, 0.0f);
            if (r0 != 0) {
                r0[2] = D_L07_0021EC98[0x5C][5];
            }
        }
    }
    {
        s32 j;
        for (j = 0; j < 2; j++) {
            r0 = func_L01_0046FB40(&m->x, &D_L07_001D66B0, (D_L07_001DD510 * 5 + 2) / 6,
                                   0xF78E38, 0, 0x7F, 0, fa, fb, 0, 0.0f);
            if (r0 != 0) {
                r0[2] = D_L07_0021EC98[0x5C][6];
            }
        }
    }
    {
        s32 i, n, r;
        f32 head, heading, mag;
        u8 *rr;
        for (i = 0; i < v->f20; i++) {
            P_34B180 *tab = D_L07_001E1EC0;
            P_34B180 *pl = &tab[D_001D52F0];
            head = func_0038D160(pl->x - m->x, pl->y - m->y);
            r = (s32)func_L01_00443A18(2.0f, 5.0f);
            n = func_00382498(30, 50);
            pos.x = m->x + func_L01_00443A18(0.0f, 0.1f) * v->f14;
            pos.y = m->y + func_L01_00443A18(0.0f, 0.1f) * v->f14;
            pos.z = m->z + func_L01_00443A18(0.0f, 0.1f) * v->f14;
            speed = func_003824E0(0.6f, 1.0f) * v->f14;
            mag = func_003824E0(9.0f, 12.0f) * v->f14;
            heading = func_0038DAB8(head, func_L01_00443A18(0.0f, 1.3962634f));
            mag = mag * 0.020000001f;
            vel.x = func_0038D098(heading) * mag;
            vel.y = func_0038D0B0(heading) * mag;
            vel.z = 0.0f;
            mag = func_003824E0(0.0f, 12.0f) * v->f14;
            vel.z = mag * 0.020000001f;
            func_L01_004713C8(&pos, &vel, (n * 5 + 2) / 6, 0xFF7F40,
                              r, 0x7F, 0x7F, speed * 210000.0f, v->f14 * 0.01f * 210000.0f, 0.0058400002f, 1);
            speed *= 6.0f;
            rr = func_L01_004713C8(&pos, &vel, (n * 5 + 2) / 6, 0xFF2000,
                                   -(r * 2), 0x30, 0x30, speed * 210000.0f,
                                   v->f14 * 0.02f * 210000.0f, 0.0058400002f, 0);
            if (rr != 0) {
                rr[2] = D_L07_0021EC98[0x35][0];
            }
        }
    }
    {
        s32 i, n, r;
        f32 head, heading, mag;
        for (i = 0; i < v->f24; i++) {
            P_34B180 *tab = D_L07_001E1EC0;
            P_34B180 *pl = &tab[D_001D52F0];
            head = func_0038D160(pl->x - m->x, pl->y - m->y);
            r = (s32)func_L01_00443A18(2.0f, 5.0f);
            n = func_00382498(30, 50);
            pos.x = m->x + func_L01_00443A18(0.0f, 0.1f) * v->f14;
            pos.y = m->y + func_L01_00443A18(0.0f, 0.1f) * v->f14;
            pos.z = m->z + func_L01_00443A18(0.0f, 0.1f) * v->f14;
            speed = func_003824E0(0.75f, 1.5f) * v->f14;
            mag = func_003824E0(9.0f, 12.0f) * v->f14;
            heading = func_0038DAB8(head, func_L01_00443A18(0.0f, 1.3962634f));
            mag = mag * 0.020000001f;
            vel.x = func_0038D098(heading) * mag;
            vel.y = func_0038D0B0(heading) * mag;
            vel.z = 0.0f;
            mag = func_003824E0(0.0f, 12.0f) * v->f14;
            vel.z = mag * 0.020000001f;
            func_L01_004713C8(&pos, &vel, (n * 5 + 2) / 6, 0xFF8F00,
                              r, 0x7F, 0x7F, speed * 210000.0f, v->f14 * 0.01f * 210000.0f, 0.0058400002f, 5);
        }
    }
    {
        s32 i, n, r;
        f32 head, heading, mag;
        for (i = 0; i < v->f28; i++) {
            P_34B180 *tab = D_L07_001E1EC0;
            P_34B180 *pl = &tab[D_001D52F0];
            head = func_0038D160(pl->x - m->x, pl->y - m->y);
            r = (s32)func_L01_00443A18(2.0f, 5.0f);
            n = func_00382498(30, 50);
            pos.x = m->x + func_L01_00443A18(0.0f, 0.1f) * v->f14;
            pos.y = m->y + func_L01_00443A18(0.0f, 0.1f) * v->f14;
            pos.z = m->z + func_L01_00443A18(0.0f, 0.1f) * v->f14;
            speed = func_003824E0(0.6f, 1.0f) * v->f14;
            mag = func_003824E0(9.0f, 12.0f) * v->f14;
            heading = func_0038DAB8(head, func_L01_00443A18(0.0f, 1.3962634f));
            mag = mag * 0.020000001f;
            vel.x = func_0038D098(heading) * mag;
            vel.y = func_0038D0B0(heading) * mag;
            vel.z = 0.0f;
            mag = func_003824E0(0.0f, 12.0f) * v->f14;
            vel.z = mag * 0.020000001f;
            func_L01_004713C8(&pos, &vel, (n * 5 + 2) / 6, 0xFF6430,
                              r, 0x7F, 0x7F, speed * 210000.0f, v->f14 * 2100.0f, 0.0058400002f, 3);
        }
    }
    {
        s32 i;
        f32 speed, qa, qb;
        for (i = 0; i < v->f30; i++) {
            u8 *rr;
            speed = func_003824E0(15.0f, 20.0f) * v->f14;
            func_0038CE20(&pos, &m->q0, speed * 0.020000001f);
            qa = func_L01_00443A18(0.2617994f, 1.3962634f);
            qb = func_L01_00443A18(0.2617994f, 1.3962634f);
            func_003C4840(&tmp, &m->q1, qa);
            func_0038D850(&vel, &pos, &tmp);
            func_003C4840(&tmp, &m->q0, qb);
            func_0038D850(&vel, &vel, &tmp);
            func_L01_00470668(&m->x, &vel, (func_00382498(20, 35) * 5 + 2) / 6,
                              0.0058400002f);
        }
    }
    if (v->f34 != 0) {
        *(Q128_34B180 *)&vel = 0;
        vel.z = v->f14 * 8.0f * 0.020000001f;
        pos = vel;
        func_L01_002F9578(v->f14 * 3.5f, mb, &m->x, &pos, 0xD,
                          0, 0, 0xFF, 0x28);
    }
    {
        s32 i, r;
        f32 speed, tilt, angle;

        r = 1;
        func_L01_0044AF78(mb, &D_L07_001D66B0, &m->x, 0, 0, 0, 0.0f, 0.0f, 0.0f, 0.0f,
                          -1, 0, 0, -1, 0, 0x1010001, 9.0f, 0.0f, v->f14 * 20.0f);
        {
            P_34B180 *tab = D_L07_001E1EC0;
            P_34B180 *pl = &tab[D_001D52F0];
            heading = func_0038D160(pl->x - m->x, pl->y - m->y);
        }
        for (i = 0; i < v->f2C; i++) {
            u8 *rr;
            r = -r;
            pos.x = m->x + func_L01_00443A18(0.0f, 1.0f) * v->f14;
            pos.y = m->y + func_L01_00443A18(0.0f, 1.0f) * v->f14;
            pos.z = m->z + func_L01_00443A18(0.0f, 1.0f) * v->f14;
            speed = func_003824E0(0.020000001f, 0.040000003f) * v->f14;
            tilt = func_L01_00443A18(0.0f, 1.3962634f);
            angle = func_0038DAB8(heading, func_L01_00443A18(0.0f, 1.5707964f));
            func_00382760(&vel, speed, angle, tilt);
            rr = func_L01_004669B0(&pos, 0.0f, 1.0f, 1.01f, v->f14 * 1.5f * 210000.0f,
                                   r, &vel, 0x7FFFA060, 0);
            if (rr != 0) {
                u8 *q = rr + 0x20;
                *(s16 *)(rr + 0xA) = (func_00382498(40, 70) * 5 + 2) / 6;
                rr[9] = 0x44;
                *(s32 *)(q + 4) = 3;
                *(f32 *)(q + 0x1C) = (func_00382498(1, 10) * 5 + 2) / 6;
                q[0xA] = 0x40;
                q[0xB] = rr[0xA];
            }
        }
    }
}
/* localdecomp:end func_L07_0034B180 */

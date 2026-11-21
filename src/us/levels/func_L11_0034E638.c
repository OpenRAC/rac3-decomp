#include "common.h"

/* NTSC-U counterpart of func_L11_0034F5E0 (src/levels/11_obani_moons/L11_0034F5E0.c) */
/* localdecomp:start func_L11_0034E638 */
typedef int Q128_34F5E0 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_34F5E0;

typedef struct {
    s16 f0, f2, f4;
    u8 pad6[2];
    f32 f8, fC, f10, f14;
    s32 f18, f1C, f20, f24, f28, f2C, f30, f34, f38;
} V_34F5E0;

typedef struct {
    u8 pad0[0x10];
    f32 x, y, z;
    u8 pad1C[0x68 - 0x1C];
    V_34F5E0 *v;
    u8 pad6C[0xC0 - 0x6C];
    V4_34F5E0 q0;
    V4_34F5E0 q1;
} M_34F5E0;

__asm__(".extern D_L11_001D66B0_0034E638, 16");
extern u8 D_L11_001D66B0_0034E638;
extern u8 D_L11_001E15C0_0034E638[];
extern u8 *D_L11_0021E558_0034E638[];
extern u8 *D_L11_0021E6C8_0034E638[];
__asm__(".extern D_L11_001DD358, 4");
extern f32 D_L11_001DD358;
__asm__(".extern D_L11_001DD35C, 4");
extern f32 D_L11_001DD35C;
__asm__(".extern D_L11_001DD360, 4");
extern s32 D_L11_001DD360;

extern f32 func_00388A28(f32, f32);
extern f32 func_L01_00440918(f32, f32);
extern s32 func_0037E208(s32, s32);
extern f32 func_0037E250(f32, f32);
extern f32 func_00389380(f32, f32);
extern f32 func_00388960(f32);
extern f32 func_00388978(f32);
extern u8 *func_L01_0046C468(void *, void *, s32, s32, s32, s32, s32, f32, f32, s32, f32);
extern u8 *func_L01_0046DCB8(void *, void *, s32, u32, s32, s32, s32, f32, f32, f32, s32);
extern void func_003886E8(void *, void *, f32);
extern void func_003BF2F8(void *, void *, f32);
extern void func_00389118(void *, void *, void *);
extern u8 *func_L01_0046CF70(void *, void *, s32, f32);
extern void func_L01_002F95A0(f32, void *, void *, void *, s32, u8, u8, u8, u8);
extern void func_L01_00447D00(void *, void *, void *, s32, s32, s32, f32, f32, f32, f32, s32, s32, s32, s32, s32, s32, f32, f32, f32);
extern u8 *func_L01_004633E8(void *, f32, f32, f32, f32, s32, void *, u32, s32);
extern void func_0037E4B8(void *, f32, f32, f32);

void func_L11_0034E638(u8 *mb)
{
    M_34F5E0 *m = (M_34F5E0 *)mb;
    V_34F5E0 *v = m->v;
    V4_34F5E0 pos, vel, tmp;
    u8 *r0;
    f32 fa, fb, heading, speed;

    fa = D_L11_001DD358 * v->f14 * 210000.0f;
    fb = D_L11_001DD35C * v->f14 * 210000.0f;
    r0 = func_L01_0046C468(&m->x, &D_L11_001D66B0_0034E638, D_L11_001DD360,
                           v->f38 | 0x7F000000, 0, 0x64, 0, fa, fb, 0, 0.0f);
    if (r0 != 0) {
        r0[2] = D_L11_0021E6C8_0034E638[0][0];
    }
    r0 = func_L01_0046C468(&m->x, &D_L11_001D66B0_0034E638, D_L11_001DD360,
                           v->f38, 0, 0x64, 0, fa, fb, 0, 0.0f);
    if (r0 != 0) {
        r0[2] = D_L11_0021E6C8_0034E638[0][0];
    }
    {
        s32 j;
        for (j = 0; j < 2; j++) {
            r0 = func_L01_0046C468(&m->x, &D_L11_001D66B0_0034E638, D_L11_001DD360,
                                   v->f38 | 0x7F000000, 0, 0x7F, 0, fa, fb, 0, 0.0f);
            if (r0 != 0) {
                r0[2] = D_L11_0021E558_0034E638[0x5C][5];
            }
        }
    }
    {
        s32 j;
        for (j = 0; j < 2; j++) {
            r0 = func_L01_0046C468(&m->x, &D_L11_001D66B0_0034E638, D_L11_001DD360,
                                   v->f38 | 0x7F000000, 0, 0x7F, 0, fa, fb, 0, 0.0f);
            if (r0 != 0) {
                r0[2] = D_L11_0021E558_0034E638[0x5C][6];
            }
        }
    }
    {
        s32 i, n, r;
        f32 head, heading, mag;
        u8 *rr;
        for (i = 0; i < v->f20; i++) {
            u8 *hp = D_L11_001E15C0_0034E638;
            head = func_00388A28(*(f32 *)(hp + 0x140) - m->x,
                                 *(f32 *)(hp + 0x144) - m->y);
            r = (s32)func_L01_00440918(2.0f, 5.0f);
            n = func_0037E208(30, 50);
            pos.x = m->x + func_L01_00440918(0.0f, 0.1f) * v->f14;
            pos.y = m->y + func_L01_00440918(0.0f, 0.1f) * v->f14;
            pos.z = m->z + func_L01_00440918(0.0f, 0.1f) * v->f14;
            speed = func_0037E250(0.6f, 1.0f) * v->f14;
            mag = func_0037E250(9.0f, 12.0f) * v->f14;
            heading = func_00389380(head, func_L01_00440918(0.0f, 1.3962634f));
            mag = mag * 0.016666668f;
            vel.x = func_00388960(heading) * mag;
            vel.y = func_00388978(heading) * mag;
            vel.z = 0.0f;
            mag = func_0037E250(0.0f, 12.0f) * v->f14;
            vel.z = mag * 0.016666668f;
            func_L01_0046DCB8(&pos, &vel, n, v->f38,
                              r, 0x7F, 0x7F, speed * 210000.0f, v->f14 * 0.01f * 210000.0f, 0.0040555559f, 1);
            speed *= 6.0f;
            rr = func_L01_0046DCB8(&pos, &vel, n, v->f38 & 0xFFFFFF,
                                   -(r * 2), 0x30, 0x30, speed * 210000.0f,
                                   v->f14 * 0.02f * 210000.0f, 0.0040555559f, 0);
            if (rr != 0) {
                rr[2] = D_L11_0021E558_0034E638[0x35][0];
            }
        }
    }
    {
        s32 i, n, r;
        f32 head, heading, mag;
        for (i = 0; i < v->f24; i++) {
            u8 *hp = D_L11_001E15C0_0034E638;
            head = func_00388A28(*(f32 *)(hp + 0x140) - m->x,
                                 *(f32 *)(hp + 0x144) - m->y);
            r = (s32)func_L01_00440918(2.0f, 5.0f);
            n = func_0037E208(30, 50);
            pos.x = m->x + func_L01_00440918(0.0f, 0.1f) * v->f14;
            pos.y = m->y + func_L01_00440918(0.0f, 0.1f) * v->f14;
            pos.z = m->z + func_L01_00440918(0.0f, 0.1f) * v->f14;
            speed = func_0037E250(0.75f, 1.5f) * v->f14;
            mag = func_0037E250(9.0f, 12.0f) * v->f14;
            heading = func_00389380(head, func_L01_00440918(0.0f, 1.3962634f));
            mag = mag * 0.016666668f;
            vel.x = func_00388960(heading) * mag;
            vel.y = func_00388978(heading) * mag;
            vel.z = 0.0f;
            mag = func_0037E250(0.0f, 12.0f) * v->f14;
            vel.z = mag * 0.016666668f;
            func_L01_0046DCB8(&pos, &vel, n, v->f38 & 0xFFFFFF,
                              r, 0x7F, 0x7F, speed * 210000.0f, v->f14 * 0.01f * 210000.0f, 0.0040555559f, 5);
        }
    }
    {
        s32 i, n, r;
        f32 head, heading, mag;
        for (i = 0; i < v->f28; i++) {
            u8 *hp = D_L11_001E15C0_0034E638;
            head = func_00388A28(*(f32 *)(hp + 0x140) - m->x,
                                 *(f32 *)(hp + 0x144) - m->y);
            r = (s32)func_L01_00440918(2.0f, 5.0f);
            n = func_0037E208(30, 50);
            pos.x = m->x + func_L01_00440918(0.0f, 0.1f) * v->f14;
            pos.y = m->y + func_L01_00440918(0.0f, 0.1f) * v->f14;
            pos.z = m->z + func_L01_00440918(0.0f, 0.1f) * v->f14;
            speed = func_0037E250(0.6f, 1.0f) * v->f14;
            mag = func_0037E250(9.0f, 12.0f) * v->f14;
            heading = func_00389380(head, func_L01_00440918(0.0f, 1.3962634f));
            mag = mag * 0.016666668f;
            vel.x = func_00388960(heading) * mag;
            vel.y = func_00388978(heading) * mag;
            vel.z = 0.0f;
            mag = func_0037E250(0.0f, 12.0f) * v->f14;
            vel.z = mag * 0.016666668f;
            func_L01_0046DCB8(&pos, &vel, n, v->f38 & 0xFFFFFF,
                              r, 0x7F, 0x7F, speed * 210000.0f, v->f14 * 2100.0f, 0.0040555559f, 3);
        }
    }
    {
        s32 i;
        f32 speed, qa, qb;
        for (i = 0; i < v->f30; i++) {
            u8 *rr;
            speed = func_0037E250(15.0f, 20.0f) * v->f14;
            func_003886E8(&pos, &m->q0, speed * 0.016666668f);
            qa = func_L01_00440918(0.2617994f, 1.3962634f);
            qb = func_L01_00440918(0.2617994f, 1.3962634f);
            func_003BF2F8(&tmp, &m->q1, qa);
            func_00389118(&vel, &pos, &tmp);
            func_003BF2F8(&tmp, &m->q0, qb);
            func_00389118(&vel, &vel, &tmp);
            rr = func_L01_0046CF70(&m->x, &vel, func_0037E208(20, 35),
                                   0.0040555559f);
            if (rr != 0) {
                s32 flag = v->f38 | 0x7F000000;
                *(s32 *)(rr + 4) = flag;
                *(s32 *)(rr + 0xC) = flag;
            }
        }
    }
    if (v->f34 != 0) {
        *(Q128_34F5E0 *)&vel = 0;
        vel.z = v->f14 * 8.0f * 0.016666668f;
        pos = vel;
        func_L01_002F95A0(v->f14 * 3.5f, mb, &m->x, &pos, 0x10,
                          v->f38, *(u8 *)((u8 *)v + 0x39), *(u8 *)((u8 *)v + 0x3A), 0x2D);
    }
    {
        s32 i, r;
        f32 speed, tilt, angle;

        r = 1;
        func_L01_00447D00(mb, &D_L11_001D66B0_0034E638, &m->x, 0, 0, 0, 0.0f, 0.0f, 0.0f, 0.0f,
                          -1, 0, 0, -1, 0, 0x1010001, 9.0f, 0.0f, v->f14 * 20.0f);
        {
            u8 *hp = D_L11_001E15C0_0034E638;
            heading = func_00388A28(*(f32 *)(hp + 0x140) - m->x,
                                    *(f32 *)(hp + 0x144) - m->y);
        }
        for (i = 0; i < v->f2C; i++) {
            u8 *rr;
            r = -r;
            pos.x = m->x + func_L01_00440918(0.0f, 1.0f) * v->f14;
            pos.y = m->y + func_L01_00440918(0.0f, 1.0f) * v->f14;
            pos.z = m->z + func_L01_00440918(0.0f, 1.0f) * v->f14;
            speed = func_0037E250(0.016666668f, 0.033333335f) * v->f14;
            tilt = func_L01_00440918(0.0f, 1.3962634f);
            angle = func_00389380(heading, func_L01_00440918(0.0f, 1.5707964f));
            func_0037E4B8(&vel, speed, angle, tilt);
            rr = func_L01_004633E8(&pos, 0.0f, 1.0f, 1.01f, v->f14 * 1.5f * 210000.0f,
                                   r, &vel, v->f38 | 0x7F0000, 0);
            if (rr != 0) {
                u8 *q = rr + 0x20;
                *(s16 *)(rr + 0xA) = func_0037E208(40, 70);
                rr[9] = 0x44;
                *(s32 *)(q + 4) = 3;
                *(f32 *)(q + 0x1C) = func_0037E208(1, 10);
                q[0xA] = 0x40;
                q[0xB] = rr[0xA];
            }
        }
    }
}
/* localdecomp:end func_L11_0034E638 */

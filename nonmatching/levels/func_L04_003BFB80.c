/* NTSC-U draft (2026-11-14, Codex worker): C of func_L04_003BDDF8, the NTSC-U twin of func_L04_003BFB80, with NTSC-U names
 * and addresses. Byte-exact on NTSC-U with "-O2 -G8 -fopt-stack -mno-check-zero-division" (src/levels/04_marcadia/L04_003BFB80.c's line: "-O2 -G8 -fopt-stack -mno-check-zero-division").
 */
#include "common.h"

/* localdecomp:start func_L04_003BDDF8 */
typedef int Q_3BDDF8 __attribute__((mode(TI)));
typedef union { u8 b[0x200]; u16 h[0x100]; s32 i[0x80]; f32 f[0x80]; void *p[0x80]; Q_3BDDF8 q[0x20]; } O_3BDDF8;
typedef union { f32 f[4]; Q_3BDDF8 q; } V_3BDDF8;
extern s32 D_00142C28[];
extern u8 D_001426E0[];
extern u8 D_001D5471[];
extern u8 D_L04_001E93C0[];
extern s32 D_001D6694_sda;
extern s32 D_L04_001DFBB8[];
extern u8 *D_L04_001DFE1C[];
extern u8 D_001A4C60[];
extern Q_3BDDF8 D_001A4CC0[];
extern u8 D_L04_001E28C0[];
extern void func_003BD360(void *);
extern s32 func_L04_0046C8D0(void *, s32, f32);
extern void func_L01_0047BB50(void *);
extern s32 func_0038E2E8(void *, s32);
extern s32 func_0038E440(void *);
extern void func_L01_00441FB8(void *, s32, s32);
extern s32 func_L01_004B6C68(void);
extern void func_L01_00438430(void *);
extern void func_L01_00417F60(s32, s32);
extern void func_L01_0044C9C8(s32, s32);
extern void func_L01_00449A50(s32);
extern void func_00399F90(void);
extern void func_L01_00452F40(void *, s32);
extern void *func_L01_00438468(s32, s32);
extern void func_L01_0049FDB0(void *, void *);
extern s32 func_00388398(s32 *);
extern f32 func_0037E250(f32, f32);
extern void func_003BE4F0(void *, s32, s32, s32);
extern f32 func_00388800(void *, void *);
extern f32 func_00388A28(f32, f32);
extern f32 func_00389468(f32, f32);
extern f32 func_00388770(void *);
extern f32 func_00389380(f32, f32);
extern void func_0037E4B8(void *, f32, f32, f32);
extern f32 func_003893C8(f32, f32);
extern f32 func_003887A0(void *);
extern f32 func_L01_0040C018(void *, void *);
extern void func_L01_00444188(void *);
extern void func_L01_0044B5C8(void *, void *, s32, f32, f32);

void func_L04_003BDDF8(O_3BDDF8 *m) {
    V_3BDDF8 target, pos, diff;
    O_3BDDF8 *v = m->p[0x68/4];
    s32 aim = 0;
    f32 speed = 0.02f;
    f32 yaw, pitch;
    switch (m->b[0x20]) {
    case 0:
        if (D_00142C28[0] & 0x200) {
            func_003BD360(m);
            return;
        }
        func_L01_00441FB8(m, 1, -1);
        break;
    case 1:
        if (func_L04_0046C8D0(m, 10, 2.5f)) {
            func_L01_0047BB50(m);
            if (func_0038E2E8(D_L04_001E93C0, 0x89)) {
                D_001426E0[10] = 1;
                D_001426E0[17] = 1;
                func_0038E440(D_L04_001E93C0);
                func_L01_00441FB8(m, 2, -1);
            }
        }
        break;
    case 2:
        if (D_001D6694_sda == 2) {
            m->b[0x31] = 0;
            m->h[0x34/2] |= 1;
        }
        D_L04_001DFBB8[0] = 1;
        if (!func_L01_004B6C68()) {
            func_L01_00438430(v->p[0x124/4]);
            func_L01_00417F60(0xC9B, 0x5E);
            func_L01_0044C9C8(0x1F, 0);
            func_L01_00449A50(0x1F);
            func_00399F90();
            func_L01_00452F40(D_L04_001DFE1C[0] + (v->i[0x128/4] << 8), 1);
            ((void (*)(s32))((O_3BDDF8 *)func_L01_00438468(0x19E1, 0x6C))->p[0x68/4])(10);
            func_L01_0049FDB0(D_001A4C60, D_001A4C60 + 0x10);
            D_L04_001DFBB8[0] = 0;
            m->b[0x31] = 1;
            m->h[0x34/2] &= 0xFFFE;
            func_L01_00441FB8(m, 3, -1);
        }
        break;
    }
    if (m->b[0x20] != 0) {
        if (m->b[0x43] == 5 && func_00388398(&v->i[0x11C/4])) {
            v->i[0x11C/4] = func_0037E250(1200.0f, 2400.0f);
            if (m->b[0x43] != 5) func_003BE4F0(m, 5, 0, 10);
        } else if ((m->b[0x60] & 2) && m->b[0x43] != 5) {
            func_003BE4F0(m, 5, 0, 10);
        }
    }
    if (m->b[0x43] == 0) {
        O_3BDDF8 *hero = (O_3BDDF8 *)(D_001A4C60 - 0x80);
        aim = 1;
        if (func_00388800(&m->q[1], D_001A4C60) < 8.0f &&
            func_00389468(m->f[0xF8/4], func_00388A28(hero->f[0xE0/4] - m->f[0x10/4], hero->f[0xE4/4] - m->f[0x14/4])) < 1.5707964f) {
            if (func_00388770(D_001A4C60 + 0x90) > 0.01f) v->i[0x114/4] = 120;
            else func_00388398(&v->i[0x114/4]);
        } else if (v->i[0x114/4]) {
            v->i[0x114/4] = 0;
            v->q[0x100/16] = D_001A4CC0[0];
        }
        if (func_00388398(&v->i[0x118/4])) {
            v->i[0x118/4] = func_0037E250(180.0f, 300.0f);
            yaw = func_00389380(m->f[0xF8/4], func_0037E250(-90.0f, 90.0f) * 0.017453292f);
            pitch = func_0037E250(0.0f, 30.0f);
            func_0037E4B8(&v->q[0x100/16], 6.0f, yaw, pitch * 0.017453292f);
            __asm__("lqc2 $vf1, %1\n\tlqc2 $vf2, %2\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0"
                    : "=m"(v->q[0x100/16]) : "m"(v->q[0x100/16]), "m"(m->q[1]) : "vf1", "vf2");
        }
        if (v->i[0x114/4]) {
            speed = 0.04f;
            target.q = D_001A4CC0[0];
        } else target.q = v->q[0x100/16];
    }
    if (aim) {
        pos.q = m->q[1];
        pos.f[2] += 2.0f;
        __asm__("lqc2 $vf1, %1\n\tlqc2 $vf2, %2\n\tvsub.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0"
                : "=m"(diff) : "m"(target), "m"(pos) : "vf1", "vf2");
        yaw = func_003893C8(func_00388A28(diff.f[0], diff.f[1]), m->f[0xF8/4]);
        pitch = -func_00388A28(func_003887A0(&diff), diff.f[2]);
        if (yaw > 1.5707964f) yaw = 1.5707964f;
        else if (yaw < -1.5707964f) yaw = -1.5707964f;
        if (pitch > 0.5235988f) pitch = 0.5235988f;
        else if (pitch < -0.5235988f) pitch = -0.5235988f;
        v->f[0x64/4] = pitch;
        v->f[0x68/4] = yaw * 0.6f;
        v->f[0xE8/4] = yaw * 0.4f;
    }
    if (m->b[0x31] && func_L01_0040C018(D_L04_001E28C0, &m->q[1]) < 576.0f) {
        func_L01_00444188(m);
        m->b[0x6F] = 22;
    }
    if (D_001D5471[0]) v->f[0x70/4] = 2.75f;
    func_L01_0044B5C8(m, v, 0, speed, 0.3f);
    func_L01_0044B5C8(m, (u8 *)v + 0x80, 1, speed, 0.3f);
}
/* localdecomp:end func_L04_003BDDF8 */

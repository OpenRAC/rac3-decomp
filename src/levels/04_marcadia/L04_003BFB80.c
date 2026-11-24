#include "common.h"

/* localdecomp:start func_L04_003BFB80 */
typedef int Q_3BFB80 __attribute__((mode(TI)));
typedef union { u8 b[0x200]; u16 h[0x100]; s32 i[0x80]; f32 f[0x80]; void *p[0x80]; Q_3BFB80 q[0x20]; } O_3BFB80;
typedef union { f32 f[4]; Q_3BFB80 q; } V_3BFB80;
extern s32 D_00142C28[];
extern u8 D_001426E0[];
extern u8 D_001D5470[8];
__asm__(".extern D_001D5470, 16");
extern u8 D_L04_001E9340[];
extern s32 D_L04_001D6694;
__asm__(".extern D_L04_001D6694, 4");
extern s32 D_L04_001DFB30[2];
__asm__(".extern D_L04_001DFB30, 16");
extern u8 *D_L04_001DFD98[2];
__asm__(".extern D_L04_001DFD98, 16");
extern u8 D_001A4C60[];
extern Q_3BFB80 D_001A4CC0[];
extern u8 D_L04_001E2840[];
extern void func_003C2880(void *);
extern s32 func_L04_0046FFA0(void *, s32, f32);
extern void func_L01_0047F3B0(void *);
extern s32 func_00392B20(void *, s32);
extern s32 func_00392C78(void *);
extern void func_L01_004450F0(void *, s32, s32);
extern s32 func_L01_004BA800(void);
extern void func_L01_0043B510(void *);
extern void func_L01_0041A5B0(s32, s32);
extern void func_L01_0044FC48(s32, s32);
extern void func_L01_0044CCC8(s32);
extern void func_0039EF28(void);
extern void func_L01_00456230(void *, s32);
extern void *func_L01_0043B548(s32, s32);
extern void func_L01_004A3610(void *, void *);
extern s32 func_0038CAD0(s32 *);
extern f32 func_003824E0(f32, f32);
extern void func_003C3A10(void *, s32, s32, s32);
extern f32 func_0038CF38(void *, void *);
extern f32 func_0038D160(f32, f32);
extern f32 func_0038DBA0(f32, f32);
extern f32 func_0038CEA8(void *);
extern f32 func_0038DAB8(f32, f32);
extern void func_00382760(void *, f32, f32, f32);
extern f32 func_0038DB00(f32, f32);
extern f32 func_0038CED8(void *);
extern f32 func_L01_0040E548(void *, void *);
extern void func_L01_004472C0(void *);
extern void func_L01_0044E850(void *, void *, s32, f32, f32);

void func_L04_003BFB80(O_3BFB80 *m) {
    V_3BFB80 target, pos, diff;
    O_3BFB80 *v = m->p[0x68/4];
    s32 aim;
    f32 speed;
    f32 turn;
    f32 yaw, pitch, yaw2;
    switch (m->b[0x20]) {
    case 0:
        if (D_00142C28[0] & 0x200) {
            func_003C2880(m);
            return;
        }
        func_L01_004450F0(m, 1, -1);
        break;
    case 1:
        if (func_L04_0046FFA0(m, 10, 2.5f)) {
            func_L01_0047F3B0(m);
            if (func_00392B20(D_L04_001E9340, 0x89)) {
                D_001426E0[17] = 1;
                D_001426E0[10] = 1;
                func_00392C78(D_L04_001E9340);
                func_L01_004450F0(m, 2, -1);
            }
        }
        break;
    case 2:
        if (D_L04_001D6694 == 2) {
            m->b[0x31] = 0;
            m->h[0x34/2] |= 1;
        }
        D_L04_001DFB30[2] = 1;
        if (!func_L01_004BA800()) {
            func_L01_0043B510(v->p[0x124/4]);
            func_L01_0041A5B0(0xC9B, 0x5E);
            func_L01_0044FC48(0x1F, 0);
            func_L01_0044CCC8(0x1F);
            func_0039EF28();
            func_L01_00456230(D_L04_001DFD98[1] + (v->i[0x128/4] << 8), 1);
            ((s32 (*)(s32))((O_3BFB80 *)func_L01_0043B548(0x19E1, 0x6C))->p[0x68/4])(10);
            func_L01_004A3610(D_001A4C60, D_001A4C60 + 0x10);
            D_L04_001DFB30[2] = 0;
            m->b[0x31] = 1;
            m->h[0x34/2] &= 0xFFFE;
            func_L01_004450F0(m, 3, -1);
        }
        break;
    }
    if (m->b[0x20] != 0) {
        if (m->b[0x43] == 5 && func_0038CAD0(&v->i[0x11C/4])) {
            v->i[0x11C/4] = (func_003824E0(1200.0f, 2400.0f) * 5.0f + 2.0f) / 6.0f;
            if (m->b[0x43] != 5) func_003C3A10(m, 5, 0, 8);
        } else if ((m->b[0x60] & 2) && m->b[0x43] != 5) {
            func_003C3A10(m, 5, 0, 8);
        }
    }
    speed = 0.02f;
    turn = 0.3f;
    aim = 0;
    if (m->b[0x43] == 0) {
        aim = 1;
        if (func_0038CF38(&m->q[1], D_001A4C60) < 8.0f &&
            func_0038DBA0(m->f[0xF8/4], func_0038D160(((O_3BFB80 *)(D_001A4C60 - 0x80))->f[0xE0/4] - m->f[0x10/4], ((O_3BFB80 *)(D_001A4C60 - 0x80))->f[0xE4/4] - m->f[0x14/4])) < 1.5707964f) {
            if (func_0038CEA8(D_001A4C60 + 0x90) > 0.01f) v->i[0x114/4] = 100;
            else func_0038CAD0(&v->i[0x114/4]);
        } else if (v->i[0x114/4]) {
            v->i[0x114/4] = 0;
            v->q[0x100/16] = D_001A4CC0[0];
        }
        if (func_0038CAD0(&v->i[0x118/4])) {
            v->i[0x118/4] = (func_003824E0(180.0f, 300.0f) * 5.0f + 2.0f) / 6.0f;
            yaw = func_0038DAB8(m->f[0xF8/4], func_003824E0(-90.0f, 90.0f) * 0.017453292f);
            pitch = func_003824E0(0.0f, 30.0f);
            func_00382760(&v->q[0x100/16], 6.0f, yaw, pitch * 0.017453292f);
            __asm__("lqc2 $vf1, %1\n\tlqc2 $vf2, %2\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0"
                    : "=m"(v->q[0x100/16]) : "m"(v->q[0x100/16]), "m"(m->q[1]) : "vf1", "vf2");
        }
        if (v->i[0x114/4]) {
            speed = 0.04f;
            turn = 0.3f;
            target.q = D_001A4CC0[0];
        } else target.q = v->q[0x100/16];
    }
    if (aim) {
        pos.q = m->q[1];
        pos.f[2] += 2.0f;
        __asm__("lqc2 $vf1, %1\n\tlqc2 $vf2, %2\n\tvsub.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0"
                : "=m"(diff) : "m"(target), "m"(pos) : "vf1", "vf2");
        yaw2 = func_0038DB00(func_0038D160(diff.f[0], diff.f[1]), m->f[0xF8/4]);
        pitch = -func_0038D160(func_0038CED8(&diff), diff.f[2]);
        if (yaw2 > 1.5707964f) yaw2 = 1.5707964f;
        else if (yaw2 < -1.5707964f) yaw2 = -1.5707964f;
        if (pitch > 0.5235988f) pitch = 0.5235988f;
        else if (pitch < -0.5235988f) pitch = -0.5235988f;
        v->f[0x64/4] = pitch;
        v->f[0x68/4] = yaw2 * 0.6f;
        v->f[0xE8/4] = yaw2 * 0.4f;
    }
    if (m->b[0x31] && func_L01_0040E548(D_L04_001E2840, &m->q[1]) < 576.0f) {
        func_L01_004472C0(m);
        m->b[0x6F] = 22;
    }
    if (D_001D5470[1]) v->f[0x70/4] = 2.75f;
    func_L01_0044E850(m, v, 0, speed * 1.44f, turn * 1.44f);
    func_L01_0044E850(m, (u8 *)v + 0x80, 1, speed * 1.44f, turn * 1.44f);
}
/* localdecomp:end func_L04_003BFB80 */

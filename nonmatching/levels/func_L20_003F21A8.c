/*
 * PAL reconstruction from the owner's retail ELF, 2026-11-16.
 * Owning file: src/levels/20_final_boss/L20_003F1A78.c.
 * Flags: -O2 -G8 -fopt-stack -mno-check-zero-division @ps2as.
 * Stock check.py: 29 differing instructions, 5 candidate compiles.
 * Stopped: three distinct formulations emitted identical wrong bytes.
 * Remaining: initial quadword-load schedule and s0/s1 allocation, including
 * the corresponding restore order. The extra unused vector-sized stack area
 * reproduces the frame size, but its original source purpose is unknown.
 * No full build verification; keep INCLUDE_ASM.
 */
#include "common.h"
typedef int Q_3F21A8 __attribute__((mode(TI)));
typedef struct { f32 x,y,z,w; } __attribute__((aligned(16))) V_3F21A8;
typedef struct { Q_3F21A8 a,b; s32 flag; u8 pad[8]; void *owner; } P_3F21A8;
typedef struct { u8 pad[0x10]; Q_3F21A8 pos; u8 pad20[0x48]; P_3F21A8 *vars; u8 pad6C[0x88]; f32 pitch,yaw; } M_3F21A8;
extern u8 *func_003C24B0(s32, s32);
extern void func_L01_00456160(void *, void *);
extern void func_L01_0044A7D0(void *);
extern f32 func_L01_00443A18(f32, f32);
extern f32 func_0038DAB8(f32, f32);
extern f32 func_0038CED8(void *);
extern f32 func_0038D160(f32, f32);
extern s32 func_00382468(s32);
M_3F21A8 *func_L20_003F21A8(void *parent, V_3F21A8 *pos, V_3F21A8 *dir, void *arg3) {
    V_3F21A8 a, b;
    u8 spare[0x10];
    V_3F21A8 *bp = &b;
    M_3F21A8 *m;
    P_3F21A8 *p;
    b = *dir;
    a = *pos;
    m = (M_3F21A8 *)func_003C24B0(0x1D85, 0x70);
    if (m != 0) {
        func_L01_00456160(m, parent);
        m->pos = *(Q_3F21A8 *)&a;
        func_L01_0044A7D0(m);
        p = m->vars;
        p->a = *(Q_3F21A8 *)&b;
        p->b = *(Q_3F21A8 *)&b;
        ((V_3F21A8 *)&p->a)->z = func_0038DAB8(((V_3F21A8 *)&p->a)->z, func_L01_00443A18(2.0f, 25.0f) * 0.0174532924f);
        m->pitch = -func_0038D160(func_0038CED8(bp), bp->z);
        m->yaw = func_0038D160(b.x, bp->y);
        p->owner = arg3;
        { s32 r = func_00382468(30);
        if (r != 0) {
            func_00382468(2);
            r = -1;
        } else r = 1;
        p->flag = r;
        }
    }
    return m;
}

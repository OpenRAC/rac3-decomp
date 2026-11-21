/* functional: high. Fires a multiplayer-menu object's shot: computes the muzzle matrix (func_003C2EC0), traces a 120-unit ray forward (via func_003D4D00 / func_003D3CB0), aims at the hit point, the locked target (D_L39_0025F758) or the hit enemy (with the 0x37 licence-byte decode check, which adds lead-time compensation from func_0038CF00 / speed), scales the direction by the state's speed, then spawns either the big projectile (func_L39_00561D28, when the state's flag at 0x230 is set) or the small one (func_L39_00565750 with colours from the gp-relative table). Finally resets the fire timer from the state's period. Written from the PAL disassembly. */
#include "common.h"
#include "vu0.h"

typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_0055F3C0;

extern s32 D_L39_0024B3E4;
extern s32 D_L39_0024B3E8;
extern s32 D_L39_0024B3EC;
extern s32 D_L39_0024B3F0;
extern s32 D_L39_0024B3F4;
extern s32 D_L39_0024B3F8;
extern s32 D_L39_0025F758 __attribute__((section(".data")));
extern vu0_v4 D_L39_0025F760;
extern u8 D_L39_004997E0[];
extern s32 func_0038CAD0(void *);
extern void func_L01_004450F0(void *, s32, s32);
extern void func_003C2EC0(void *, s32, void *);
extern void func_0038CF68(void *, void *, f32);
extern void func_0038CE20(void *, void *, f32);
extern f32 func_0038CF00(void *, void *);
extern s32 func_003D4D00(void *, s32, void *, void *, f32);
extern s32 func_003D3CB0(void *, void *, s32, s32, s32);
extern u8 *func_L39_0061D7B0(void *);
extern s32 func_L39_0055D7F8(void *);
extern u8 *func_L39_00561D28(s32, void *, void *, s32, s32, f32, s32, f32, s32, f32);
extern void func_L39_00565750(u8 *, void *, void *, s32, s32, f32, f32, f32);

void func_L39_0055F3C0(u8 *self) {
    u8 *g = *(u8 **)(self + 0x68);
    V_0055F3C0 m[4];
    V_0055F3C0 a40;
    V_0055F3C0 a50;
    V_0055F3C0 dir;
    V_0055F3C0 t70;
    u8 *dirp;
    u8 *q;
    u8 *e;
    s32 *tgt;
    s32 hit;
    s32 n;
    s32 k;
    s32 lim;
    s32 cnt;
    s32 gate;
    s32 c7;
    s32 c8;
    u32 w0;
    u32 w1;
    f32 fd;
    f32 fs;
    f32 f13;

    if (func_0038CAD0(g + 0x228) == 0) {
        return;
    }
    if (*(s32 *)(g + 0x220) == 0) {
        return;
    }
    func_L01_004450F0(self, 5, -1);
    func_003C2EC0(self, 1, m);
    func_0038CF68(&a50, &m[1], -2.0f);
    vec_add_ab(&a50, &a50, &m[3]);
    func_0038CF68(&a40, &m[1], -120.0f);
    vec_add_ab(&a40, &a40, &m[3]);
    *(s32 *)(self + 0x98) = 0;
    dirp = (u8 *)&dir;
    hit = func_003D4D00(&m[3], 1, 0, 0, 1.5f);
    tgt = 0;
    if (hit != 0) {
        tgt = (s32 *)D_L39_0025F758;
        if (tgt != 0 && (s32)tgt == *(s32 *)(g + 0x220)) {
            /* the locked target id is an object pointer here: aim at its position */
            t70.x = 0.0f;
            t70.y = 0.0f;
            t70.z = 0.0f;
            t70.w = 0.0f;
            t70.x = *(f32 *)tgt * 0.0009765625f;
            t70.y = *(f32 *)((u8 *)tgt + 4) * 0.0009765625f;
            t70.z = *(f32 *)((u8 *)tgt + 8) * 0.0009765625f;
            vec_sub_ab(&dir, &t70, &m[3]);
            goto fire;
        }
    }
    if (func_003D3CB0(&a50, &a40, 0, 0, 0) == 0) {
        vec_sub_ab(&dir, &a40, &m[3]);
        goto fire;
    }
    vec_sub_ab(&dir, &D_L39_0025F760, &m[3]);
    q = 0;
    e = func_L39_0061D7B0((void *)*(s32 *)(g + 0x220));
    if (e != 0) {
        if ((e[3] & 0xF) == 0) {
            q = e;
        }
    }
    if (q != 0) {
        u8 *c = q + 0x19E4;
        if (*c == 0) {
            w1 = 0;
        } else {
            s32 nn = *c;
            s32 kk = ((u32)c - nn) & 7;
            s32 mm = nn + 1;
            u8 *d = (u8 *)&t70;
            s32 ci;
            for (ci = 0; ci < 40; ci += 5) {
                *d++ = D_L39_004997E0[mm + ((kk + ci) & 7) * 255];
            }
            w0 = *(u32 *)&t70 ^ (u32)c;
            w1 = *((u32 *)&t70 + 1) ^ w0;
            *(u32 *)&t70 = w0;
            *((u32 *)&t70 + 1) = w1;
        }
        if ((w1 ^ 0x37) == 0) {
            fd = func_0038CF00(&a50, q + 0xA0);
            fs = *(f32 *)(g + 0x23C) * 0.020000001f;
            func_0038CE20(&t70, q + 0x20, (fd / fs) * 0.060000002f);
            vec_add_ab(&t70, &D_L39_0025F760, &t70);
            vec_sub_ab(&dir, &t70, &m[3]);
        }
    }
fire:
    func_0038CF68(&dir, &dir, *(f32 *)(g + 0x23C) * 0.020000001f);
    *(s32 *)(self + 0x98) = *(s32 *)(*(u8 **)(self + 0x24) + 0x10);
    if (*(s32 *)(g + 0x230) != 0) {
        lim = *(s32 *)(g + 0x248);
        if (func_L39_0055D7F8((void *)*(s32 *)(g + 0x220)) != 0) {
            fs = *(f32 *)(g + 0x23C);
            n = (s32)(*(f32 *)(g + 0x25C) / fs * 50.0f) + 0x11;
        } else {
            fs = *(f32 *)(g + 0x23C);
            n = (s32)(*(f32 *)(g + 0x250) / fs * 50.0f) + 8;
        }
        f13 = (f32)*(s32 *)(g + 0x244);
        f13 = f13 * 0.017453292f;
        f13 = f13 * 0.020000001f;
        cnt = n;
        if (!(lim < n)) {
            cnt = lim;
        }
        func_L39_00561D28((s32)self, &m[3], &dir, *(s32 *)(g + 0x234), 0x80FFFFFF, 3.0f,
                          *(s32 *)(g + 0x220), f13, cnt, *(f32 *)(g + 0x240));
    } else {
        c7 = D_L39_0024B3E4;
        c8 = D_L39_0024B3F0;
        if (*(s32 *)(g + 0x22C) == 0) {
            c7 = D_L39_0024B3E8;
            c8 = D_L39_0024B3F4;
        } else if (*(s32 *)(g + 0x22C) == 1) {
            c7 = D_L39_0024B3EC;
            c8 = D_L39_0024B3F8;
        }
        t70 = m[3];
        func_L39_00565750(self, &t70, &dir, c7, c8, (f32)*(s32 *)(g + 0x234), 1.0f, 25.0f);
    }
    *(s32 *)(g + 0x228) = (*(s32 *)(g + 0x238) * 5 + 2) / 6;
}

#include "common.h"
/* localdecomp:start func_L39_005B8978 */
#include "vu0.h"
typedef struct { s32 v[6]; } Tab_005B8978;
typedef struct { f32 dir[4]; f32 rnd[4]; } __attribute__((aligned(16))) Vecs_005B8978;
typedef struct { f32 v[4]; } __attribute__((aligned(16))) Vec_005B8978;
typedef struct { vu0_v4 v0; u8 pad10[8]; u8 f18; u8 f19; u16 f1A; u8 pad1C[0x14]; } Dmg_005B8978;
typedef struct {
    u8 pad0[0x20];
    f32 f20;
    u8 pad24[4];
    s32 f28;
    s32 f2C;
} Cam_005B8978;
typedef struct {
    u8 pad0[0x20];
    f32 f20;
    f32 f24;
    f32 f28;
} Shake_005B8978;
typedef struct {
    u8 pad0[0x1C];
    s32 f1C;
    vu0_v4 pos;
    u8 pad30[0x28];
    s32 f58;
    u8 pad5C[0x24];
} Slot_005B8978;

extern f32 D_L39_0024BB48;
extern f32 D_L39_0024BB4C;
extern vu0_v4 D_L39_0024DE00;
extern s32 *D_L39_00241120;
extern Tab_005B8978 D_L39_00243278;
extern Tab_005B8978 D_L39_00243290;
extern Cam_005B8978 D_L39_0024DE80;
extern Shake_005B8978 D_L39_004996F0;
extern Shake_005B8978 D_L39_00499740;
typedef struct {
    u8 pad0[0xC0];
    Slot_005B8978 slots[1];
} Slots_005B8978;
extern Slots_005B8978 D_001FE020;

extern void func_L01_00446748(void *, void *, s32, f32);
extern void func_003D4D00(f32, void *, s32, void *, void *);
extern f32 func_L39_005B4410(f32, f32);
extern f32 func_L39_005B44C8(void);
extern s32 func_L39_005B4398(s32);
extern s32 func_L39_005B43C8(s32, s32);
extern void func_00382760(void *, f32, f32, f32);
extern s32 func_L01_00448D88(s32, u8);
extern void *func_L39_005C7B40(void *, void *, s32, s32, f32, s32, s32, s32, s32, s32);
extern void func_L39_005C6E90(void *, void *, s32, s32, f32, s32, s32, f32, s32, s32);
extern void func_L01_00464210(void *, void *, s32, s32, s32, f32);
extern f32 func_0038CEA8(void *);
extern void func_0038CF68(void *, void *, f32);
extern void func_L01_0040E6B8(void *, void *, f32);
extern void *func_L01_002FB660(void *, void *, s32, s32, s32, s32);
extern void func_L01_002F9578(void *, void *, void *, f32, s32, s32, s32, s32, s32);
extern s32 func_0038DC20(void *, f32);
extern s32 func_L39_005F33E0(s32, s32, void *);
extern void func_L01_003006C0(void *, void *, s32, s32);

void func_L39_005B8978(u8 *obj, s32 a1, vu0_v4 *pos, s32 nSparks, s32 nSmoke, s32 nDebris, s32 idArg, s32 aC,
                       s32 nExtra, s32 mode, u8 col, s32 flags, f32 fDur, f32 fArg, f32 fRange, f32 fSize2,
                       f32 fFlashDist, f32 scale, f32 fShake) {
    vu0_v4 zero;
    vu0_v4 d;
    f32 dist;
    f32 fade;
    f32 smokeF;
    f32 total;
    s32 n;
    s32 i;
    s32 k;

    total = D_L39_0024BB4C + D_L39_0024BB48;
    *(vu0_q *)&zero = 0;
    zero.z = scale * 0.16000001132f;
    if (mode == -1) {
        if (1.7f < total) {
            mode = 1;
        }
    }
    if (!(*D_L39_00241120 < 3)) {
        mode = 1;
    }
    if (pos == 0) {
        if (obj == 0) {
            return;
        }
        pos = (vu0_v4 *)(obj + 0x10);
    }

    if (0.0f < fDur) {
        Dmg_005B8978 ev;
        {
        func_L01_00446748(&ev, obj, flags, fArg);
        ev.f18 = 2;
        ev.f19 = 1;
        ev.f1A = *(u16 *)(obj + 0xAA);
        func_003D4D00(fDur, pos, 0x10, obj, &ev);
        }
    }

    if (nSparks > 0) {
        Vec_005B8978 vel;
        f32 a, b, c;
        s32 c0, c1, life;
        do {
            nSparks--;
            a = func_L39_005B4410(0.2617994f, 1.3962634f);
            b = func_L39_005B44C8();
            c = func_L39_005B4410(7.0f, 10.5f) * 0.020000001f;
            func_00382760(&vel, scale * c, b, a);
            vel.v[2] += 0.060000002f;
            c0 = func_L01_00448D88(0x4F007FFF, col);
            c1 = func_L01_00448D88(0x1F00007F, col);
            life = func_L39_005B43C8(0x32, 0x64) - mode * 10;
            func_L39_005C7B40(pos, &vel, c0, c1, scale * 40000.0f, life, 1, -1, -1, 0);
        } while (nSparks != 0);
    }

    vec_sub_ba(&d, &D_L39_0024DE00, pos);
    dist = func_0038CEA8(&d);

    if (nExtra != 0) {
        {
        Vecs_005B8978 v;
        f32 a, b, c;
        s32 j;
        *(vu0_q *)v.rnd = 0;
        v.rnd[0] = func_L39_005B4410(-1.0f, 1.0f);
        v.rnd[1] = func_L39_005B4410(-1.0f, 1.0f);
        v.rnd[2] = func_L39_005B4410(-1.0f, 1.0f);
        *(vu0_q *)v.dir = *(vu0_q *)v.rnd;
        if (dist < 14.0f) {
            d.z += dist * 0.5f;
            func_0038CF68(v.dir, v.dir, dist / 5.0f * 0.020000001f);
            func_0038CF68(&d, &d, (dist + dist) * 0.020000001f);
            vec_add_ab(v.dir, v.dir, &d);
            func_L01_0040E6B8(v.dir, v.dir, 0.20000002f);
            func_L01_002FB660(pos, v.dir, func_L39_005B43C8(0x32, 0x4B), 0, 0, 0);
        }
        nExtra--;
        for (j = 0; j < nExtra; j++) {
            a = func_L39_005B4410(0.2617994f, 1.3089969f);
            b = func_L39_005B44C8();
            c = func_L39_005B4410(7.0f, 10.5f) * 0.020000001f;
            func_00382760(v.rnd, scale * c, b, a);
            v.rnd[2] += 0.040000003f;
            k = 0;
            if (j % 3 == 0) {
                k = 1;
            }
            func_L01_002FB660(pos, v.rnd, func_L39_005B43C8(0x32, 0x4B), k, 0, 0);
        }
        }
    }

    smokeF = nSmoke;
    n = nSmoke;
    if (dist < smokeF + smokeF) {
        n = (s32)dist / 2;
    }
    fade = 0.0f;
    if (dist < 7.0f) {
        fade = 7.0f - dist;
    }
    for (i = 0; i < n; i++) {
        Tab_005B8978 tabA;
        Tab_005B8978 tabB;
        f32 a, b;
        s32 c0, c1, life, life2;
            a = func_L39_005B4410(8.0f, 10.0f) * 0.020000001f;
            tabA = D_L39_00243278;
            tabB = D_L39_00243290;
            a -= fade * 0.020000001f;
            c0 = func_L01_00448D88(tabA.v[func_L39_005B4398(6)], col);
            a *= scale;
            c1 = func_L01_00448D88(tabB.v[func_L39_005B4398(6)], col);
            b = scale * 400000.0f;
            life = func_L39_005B43C8(0xC, 0x11) - mode * 3;
            func_L39_005C6E90(pos, &zero, c0, c1, b, life, func_L39_005B43C8(0x19, 0x25) - mode * 5, a, 0, 0);
            life2 = func_L39_005B43C8(4, 8) - mode * 2;
            func_L39_005C6E90(pos, &zero, 0x7FFFFFFF, 0xFFFFFF, b, life2, func_L39_005B43C8(0xC, 0x11) - mode * 3,
                              a * 0.5f, 0, 0);
    }

    for (i = 0; i < nDebris; i++) {
        Tab_005B8978 tabA;
        Tab_005B8978 tabB;
        vu0_v4 vel;
        vu0_v4 rnd;
        f32 c;
        s32 c0, c1, life;
            tabA = D_L39_00243278;
            tabB = D_L39_00243290;
            *(vu0_q *)&rnd = 0;
            rnd.x = func_L39_005B4410(-1.0f, 1.0f);
            rnd.y = func_L39_005B4410(-1.0f, 1.0f);
            rnd.z = func_L39_005B4410(-1.0f, 1.0f);
            vel = rnd;
            c = func_L39_005B4410(0.0f, 3.0f) * 0.020000001f;
            func_0038CF68(&vel, &vel, scale * c);
            c0 = func_L01_00448D88(tabA.v[func_L39_005B4398(6)], col);
            c1 = func_L01_00448D88(tabB.v[func_L39_005B4398(6)], col);
            life = func_L39_005B43C8(0x19, 0x25) - mode * 5;
            func_L01_00464210(pos, &vel, c0, c1, life, 200000.0f);
    }

    if (obj != 0 && 0.0f < fRange) {
        u8 r0 = 0x96;
        u8 g0 = 0x96;
        u8 b0 = 0x96;
        s32 r1 = 0x7F;
        s32 g1 = 0x7F;
        u8 b1 = 0;
        if (col != 0) {
            if (!(col & 4)) {
                r0 = 0x46;
                b0 = 0x46;
                r1 = 0x3C;
            } else {
                r0 = 0x23;
                g0 = 0;
                b0 = 0xFA;
                r1 = 0x20;
                g1 = 0;
                b1 = 0x64;
            }
        }
        if (D_L39_0024BB48 < 0.95f && fFlashDist < dist) {
            func_L01_002F9578(obj, pos, &zero, fRange, 0xD, r0, g0, b0, 0x20);
            func_L01_002F9578(obj, pos, &zero, fRange, 0x12, (u8)r1, (u8)g1, b1 + 0x50, 0x20);
        }
        func_L01_002F9578(obj, pos, &zero, fRange, 0x19, (u8)r1, (u8)g1, b1, 0x30);
    }
    if (obj != 0 && 0.0f < fSize2) {
        func_L01_002F9578(obj, pos, &zero, fSize2, 0x16, 0xFF, 0xFF, 0xFF, 0x20);
    }

    if (aC != 0) {
        Vec_005B8978 p;
        p = *(Vec_005B8978 *)pos;
        p.v[3] = 2.0f;
        if (func_0038DC20(&p, 10.0f) != -1) {
            Cam_005B8978 *cam = &D_L39_0024DE80;
            if (dist < 20.0f) {
                cam->f20 = 0.4f - dist * 0.0175f;
            } else {
                cam->f20 = 0.050000012f;
            }
            D_L39_0024DE80.f28 = 0x15;
            D_L39_0024DE80.f2C = 0;
        }
    }

    if (obj != 0 && idArg != -1) {
        s32 slot = func_L39_005F33E0(idArg, 0, obj);
        if (slot != -1) {
            *(vu0_q *)&D_001FE020.slots[slot].pos = *(vu0_q *)pos;
            D_001FE020.slots[slot].f58 = 0;
            D_001FE020.slots[slot].f1C = 0;
        }
    }

    if (fShake != 0.0f && mode == 0) {
        Vec_005B8978 p;
        p = *(Vec_005B8978 *)pos;
        p.v[3] = fShake;
        if (func_0038DC20(&p, 100.0f) != -1) {
            if (0.0f < fShake) {
                D_L39_004996F0.f24 = fShake;
                D_L39_004996F0.f28 = fShake;
                D_L39_004996F0.f20 = fShake;
            } else {
                D_L39_004996F0.f24 = 15.0f;
                D_L39_004996F0.f28 = 15.0f;
                D_L39_004996F0.f20 = 15.0f;
            }
            if (col != 0) {
                func_L01_003006C0(&D_L39_00499740, pos, 0, 0);
            } else {
                func_L01_003006C0(&D_L39_004996F0, pos, 0, 0);
            }
        }
    }
}
/* localdecomp:end func_L39_005B8978 */


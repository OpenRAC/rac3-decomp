/* functional: high. Death/despawn effect for a player's pawn (rac3 multiplayer menu): resets the player's pad-lock state, snaps the pawn to the ground, runs the licence check via the obfuscated byte decode, then spawns three particle bursts and finishes via func_L39_00556C78 and func_003C2880. Written from the PAL disassembly with the matched sibling func_L39_005287B0's callee names; not byte-matched. */
#include "common.h"
#include "vu0.h"

typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_00556638;
typedef struct { u8 pad0[0x140]; f32 x; f32 y; } T_00556638;
typedef struct { u8 pad0[0x14]; u8 *vt; } P14_00556638;

extern u8 *D_L39_0024CE20[8];
extern vu0_v4 D_L39_0025F770;
extern u8 D_L39_004997E0[];
extern T_00556638 D_L39_0024DCC0;
extern f32 func_L01_00446E38(void *, void *, s32, void *, f32);
extern void func_L39_00628760(void *);
extern u8 *func_00382348(void *);
extern void func_L39_00637EC8(void *, void *, void *, s32, s32, s32, s32);
extern void func_L39_00628038(void *, s32);
extern f32 func_L39_005B4410(f32, f32);
extern f32 func_L39_005B44C8(void);
extern f32 func_L39_005B4468(f32, f32);
extern void func_00382760(void *, f32, f32, f32);
extern s32 func_L39_005B43C8(s32, s32);
extern void func_L39_005C8CA8(void *, void *, s32, s32, s32, f32);
extern f32 func_0038D160(f32, f32);
extern f32 func_0038DAB8(f32, f32);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern void func_L01_004749C8(void *, void *, s32);
extern void func_L01_003D6158(void *, s32, s32, s32, s32, f32, f32);
extern void func_L39_0051AE58(void *, void *, void *);
extern void func_L39_00556C78(void *);
extern void func_003C2880(void *);

void func_L39_00556638(u8 *self, s32 a1, s32 a2) {
    V_00556638 b;
    V_00556638 a;
    u8 *p;
    u8 *q;
    f32 r0, r1, r2, s, ang;
    s32 i;
    s32 ok;
    u32 w0, w1;

    p = D_L39_0024CE20[*(s32 *)(*(u8 **)(self + 0x68) + 0x9C)];
    if (p != 0) {
        *(s32 *)(p + 0x2458) = 0;
        if (p[0x1A14] != 0) {
            b = *(V_00556638 *)(self + 0x10);
            a = *(V_00556638 *)(self + 0x10);
            a.z += 2.0f;
            b.z -= 0.5f;
            if (func_L01_00446E38(&a, &b, 0x80, self, *(f32 *)(p + 0x1F4)) < 1.0f) {
                *(vu0_v4 *)(self + 0x10) = D_L39_0025F770;
            }
            *(vu0_v4 *)(p + 0xA0) = *(vu0_v4 *)(self + 0x10);
            *(vu0_v4 *)(p + 0xB0) = *(vu0_v4 *)(self + 0xF0);
        }
        if (a1 != 0) {
            func_L39_00628760(p);
            q = func_00382348(*(void **)(p + 0x2524));
            if (q != 0) {
                q[0xE] = 1;
            }
            if (p[0x1A14] != 0) {
                p[0x1A0A] = 1;
                func_L39_00637EC8(p, self + 0x10, self + 0xF0, 0, 1, 1, 0);
            }
        } else {
            ok = 0;
            if (*(u8 **)(p + 0x2530) != 0 && (*(u8 **)(p + 0x2530))[0x27B] != 0) {
                u8 *e = p + 0x19E4;
                if (*e == 0) {
                    w1 = 0;
                } else {
                    s32 n = *e;
                    s32 k = ((u32)e - n) & 7;
                    s32 m = n + 1;
                    u8 *d = (u8 *)&b;
                    for (i = 0; i < 40; i += 5) {
                        *d++ = D_L39_004997E0[m + ((k + i) & 7) * 255];
                    }
                    w0 = *(u32 *)&b ^ (u32)e;
                    w1 = *((u32 *)&b + 1) ^ w0;
                    *(u32 *)&b = w0;
                    *((u32 *)&b + 1) = w1;
                }
                if ((w1 ^ 0x31) == 0) {
                    ok = 1;
                }
            }
            if (ok != 0) {
                func_L39_00628038(p, 0);
                (*(void (**)(void *, s32, s32, s32, s32))(*(u8 **)(p + 0x14) + 0x34))(p, 0x76, 0, 1, 0);
                if (p[0x1A14] == 0) {
                    p[0x1A0A] = 2;
                }
            }
        }
    }
    for (i = 0; i < 15; i++) {
        r0 = func_L39_005B4410(0.0f, 0.37f);
        r1 = func_L39_005B44C8();
        r2 = func_L39_005B44C8();
        func_00382760(&a, r0, r1, r2);
        s = func_L39_005B4410(0.35f, 0.6f);
        a.z += s;
        vec_add_ba(&a, &a, self + 0x10);
        r0 = func_L39_005B4410(0.0030000003f, 0.024000002f);
        r1 = func_L39_005B44C8();
        r2 = func_L39_005B44C8();
        func_00382760(&b, r0, r1, r2);
        func_L39_005C8CA8(&a, &b, 0x4F7F7F7F, 0x202020, func_L39_005B43C8(0x19, 0x2F), 150000.0f);
    }
    for (i = 0; i < 20; i++) {
        ang = func_0038D160(D_L39_0024DCC0.x - *(f32 *)(self + 0x10), D_L39_0024DCC0.y - *(f32 *)(self + 0x14));
        func_L39_005B4468(1.0f, 2.0f);
        b.x = *(f32 *)(self + 0x10) + func_L39_005B4468(0.0f, 0.15f);
        b.y = *(f32 *)(self + 0x14) + func_L39_005B4468(0.0f, 0.15f);
        b.z = *(f32 *)(self + 0x18) + func_L39_005B4468(0.0f, 0.15f);
        s = func_L39_005B4410(3.0f, 7.0f) * 0.020000001f;
        ang = func_0038DAB8(ang, func_L39_005B4468(0.0f, 2.6179938f));
        a.x = func_0038D098(ang) * s;
        a.y = func_0038D0B0(ang) * s;
        a.z = 0.0f;
        a.z = func_L39_005B4410(5.0f, 10.0f) * 0.020000001f;
        func_L01_004749C8(&b, &a, 0x8E);
    }
    func_L01_003D6158(self, 0x4E, 0x4F, 10, 1, 1.5f, 1.2f);
    for (i = 0; i < 10; i++) {
        r0 = func_L39_005B4410(0.0f, 0.35f);
        r1 = func_L39_005B44C8();
        r2 = func_L39_005B44C8();
        func_00382760(&a, r0, r1, r2);
        a.z += 0.25f;
        vec_add_ba(&a, &a, self + 0x10);
        r0 = func_L39_005B4410(0.060000002f, 0.120000005f);
        r1 = func_L39_005B44C8();
        func_00382760(&b, r0, r1, 1.2217305f);
        b.z = func_L39_005B4410(3.0f, 5.0f) * 0.020000001f;
        func_L39_0051AE58(self, &a, &b);
    }
    func_L39_00556C78(self);
    func_003C2880(self);
}

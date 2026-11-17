#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L22_003B6D30 */
extern f32 func_0038D160(f32, f32);
extern f32 func_0038DBA0(f32, f32);
extern f32 func_L01_0040E548(void *, void *);
typedef struct { u8 p0[0x80]; f32 x; f32 y; u8 p1[0x25C0 - 0x88]; u8 *hero; } G_003B6D30;
extern G_003B6D30 D_1A4BE0;
typedef struct { u8 p[0x30]; f32 x; f32 y; u8 q[0x48]; } R_003B6D30;
extern R_003B6D30 *D_L22_001DFE80;
__asm__(".extern D_L22_001DFE80, 16");

s32 func_L22_003B6D30(u8 *self, u8 *other) {
    u8 *p;
    u8 *hero;
    f32 a;
    s32 r;
    s32 r2;

    p = *(u8 **)(self + 0x68);
    if (other == 0 || self == 0 || *(s32 *)(p + 0x460) != 0) {
        return 0;
    }
    hero = D_1A4BE0.hero;
    if (hero == 0) {
        return 0;
    }
    if (*(s16 *)(hero + 0xAA) != 0x173B && *(s16 *)(hero + 0xAA) != 0x1A4E) {
        return 0;
    }
    if (*(s32 *)(p + 0x4C0) > 0 && *(s32 *)(p + 0x4A0) == 0) {
        r = 0;
        a = func_0038D160(D_L22_001DFE80[*(s32 *)(p + 0x4B8)].x - *(f32 *)(self + 0x10), D_L22_001DFE80[*(s32 *)(p + 0x4B8)].y - *(f32 *)(self + 0x14));
        if (func_0038DBA0(func_0038D160(D_1A4BE0.x - *(f32 *)(self + 0x10),
                                        D_1A4BE0.y - *(f32 *)(self + 0x14)), a) < 2.0943952f) {
            if (func_L01_0040E548(other + 0x10, self + 0x10) < 25.0f) {
                if (other[0x43] == 0x12 || other[0x43] == 0x17) {
                    r = 1;
                }
            }
        }
        return r;
    }
    r2 = 0;
    if (func_L01_0040E548(other + 0x10, self + 0x10) < 25.0f) {
        if (other[0x43] == 0x12 || other[0x43] == 0x17) {
            r2 = 1;
        }
    }
    return r2;
}
/* localdecomp:end func_L22_003B6D30 */

/* localdecomp:start func_L22_003B6EE8 */
#include "vu0.h"

typedef struct { u8 pad[0x30]; vu0_q v; u8 pad2[0x40]; } E_003B6EE8;
extern E_003B6EE8 *D_L22_001DFE80_003B6EE8;
extern vu0_v4 D_L22_001E2A80[];
extern s32 D_001D52FC;
__asm__(".extern D_001D52FC, 4");
extern f32 func_0038D160(f32, f32);
extern f32 func_L05_00441508(f32, f32, f32);
extern void func_L01_00511A40(void *, s32, f32);
extern void func_003C4098(void *, void *, void *, f32);
extern f32 func_0038CF38(void *, void *);
extern void func_L01_003EB438(s32, void *, void *, s32, s32, s32);
extern void func_L01_003EB350(s32, void *);
extern void func_L01_003EB3C0(s32, void *);
extern void func_L22_003F21E8(s32, f32, f32, f32, f32, f32, f32);
extern void func_L22_003B7380(void *);
extern void func_L22_003B8100(void *);
extern void func_L01_00460200(f32);
extern void func_L01_003EB5E0(s32, s32);
extern void func_L01_005003D0(s32, s32);
extern void func_L01_003F1740(void *);
extern void func_L01_004606A8(s32);
extern void func_L01_004450F0(void *, s32, s32);

void func_L22_003B6EE8(u8 *a0, s32 a1) {
    u8 *pv = *(u8 **)(a0 + 0x68);
    vu0_v4 v0 __attribute__((aligned(16)));
    vu0_v4 v1 __attribute__((aligned(16)));
    vu0_v4 v2 __attribute__((aligned(16)));
    vu0_v4 rot __attribute__((aligned(16)));
    vu0_v4 out __attribute__((aligned(16)));
    f32 a, b, d;

    if (a0[0x95] != 5) {
        return;
    }
    if (a1 != 0) {
        *(vu0_q *)&v0 = D_L22_001DFE80_003B6EE8[*(s32 *)(pv + 0x4B4)].v;
        *(vu0_q *)&v1 = D_L22_001DFE80_003B6EE8[*(s32 *)(pv + 0x4B8)].v;
        *(vu0_q *)&v2 = D_L22_001DFE80_003B6EE8[*(s32 *)(pv + 0x4BC)].v;
        a = func_0038D160(v0.x - v1.x, v0.y - v1.y);
        b = func_0038D160(v2.x - v1.x, v2.y - v1.y);
        a = func_L05_00441508(a, b, 0.25f);
        func_L01_00511A40(&v1, 0, a);
        func_003C4098(&out, &v0, &v1, 0.5f);
        qzero(&rot);
        out.z += 0.25f;
        d = func_0038CF38(&v2, &out);
        rot.y = -func_0038D160(d, out.z - v2.z);
        rot.z = func_0038D160(out.x - v2.x, out.y - v2.y);
        func_L01_003EB438(0, &D_L22_001E2A80[0], &D_L22_001E2A80[1], 0, 0, 0);
        func_L01_003EB350(0, &v2);
        func_L01_003EB3C0(0, &rot);
        func_L22_003F21E8(0, 0.75f, 0.025f, 0.1f, 0.5f, 0.015f, 0.017453292f);
        func_L22_003B7380(a0);
        func_L22_003B8100(a0);
        func_L01_00460200(0.5f);
    } else {
        func_L01_003EB5E0(0, 2);
        func_L01_005003D0(0x51, 1);
        func_L01_003F1740(a0);
        func_L01_004606A8(D_001D52FC);
        func_L01_004450F0(a0, 4, 1);
        func_L01_00460200(1.0f);
    }
}
/* localdecomp:end func_L22_003B6EE8 */

/* localdecomp:start func_L22_003B7150 */
extern void func_003D9508(void *, s32, u32, s32, f32, f32, f32);

void func_L22_003B7150(u8 *a0) {
    vu0_v4 v;
    u8 *s;
    f32 t = *(f32 *)(a0 + 0xC) / 500.0f;

    *(vu0_q *)&v = *(vu0_q *)(a0 + 0x10);
    v.z += t;
    s = *(u8 **)(a0 + 0x68);
    if (*(s32 *)(s + 0x46C) >= 0) {
        func_003D9508(&v, *(s32 *)(s + 0x46C) + 100, 0x7F7F7F7F, 0, 0.3f, 0.08f, 0.0f);
    }
}
/* localdecomp:end func_L22_003B7150 */

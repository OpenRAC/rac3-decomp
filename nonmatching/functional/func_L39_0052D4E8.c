/* functional: medium. Per-frame weapon/aim step of the multiplayer controller: finds a target (func_L39_006472D0), builds the shot origin/direction, spawns the shot with func_L07_003CAE10 when the fire buttons are down and the cooldown (+0x716) is zero, flips the muzzle side (b2FE) and ticks the cooldown. Raw offsets, no struct layout known; the retail else-path passes the gp global D_L39_0024AB3C in f12 left over from the delay slot, written explicitly */
#include "vu0.h"
/* this file has no -mvu0 flag: plain C xyz vector helpers (w of the destination is kept, as vadd.xyz/vsub.xyz do) */
static void v_add(void *d, void *a, void *b) {
    f32 *D = d, *A = a, *B = b;
    D[0] = A[0] + B[0];
    D[1] = A[1] + B[1];
    D[2] = A[2] + B[2];
}
static void v_sub(void *d, void *a, void *b) {
    f32 *D = d, *A = a, *B = b;
    D[0] = A[0] - B[0];
    D[1] = A[1] - B[1];
    D[2] = A[2] - B[2];
}
extern u8 *func_L39_006472D0(void *, void *, void *, s32, f32, f32, f32, f32, f32);
extern void func_0038CE20(void *, void *, f32);
extern void func_0038D000(void *, void *, void *);
extern f32 func_0038CF00(void *, void *);
extern u8 *func_00382348(void *);
extern void func_L01_003F6F20(s32, void *, u32, void *, s32, s32, s32, f32, f32, f32, f32, f32, f32, f32);
extern f32 func_0038CEA8(void *);
extern u8 *func_L39_0061D7B0(void *);
extern u8 *func_L39_00668620(void *);
extern void func_00382760(void *, f32, f32, f32);
extern u8 *func_L07_003CAE10(void *, void *, void *, s32, void *, s32, u32, f32, f32);
extern s32 func_L39_005F33E0(s32, s32, void *);
extern void func_L01_003F1F20(s32, s32);
extern s32 func_L39_0066E010(void *, s32, void *, void *, s32);
extern s32 func_0038CB00(void *);
extern vu0_v4 D_L39_0024ABF0[];
__asm__(".extern D_L39_0024ABF0, 16");
__asm__(".extern D_L39_0024AB3C, 4");
__asm__(".extern D_L39_0024AB38, 4");
__asm__(".extern D_L39_0024ABD4, 4");
__asm__(".extern D_L39_0024ABD0, 4");
extern f32 D_L39_0024AB3C;
extern s32 D_L39_0024AB38;
extern f32 D_L39_0024ABD4;
extern s32 D_L39_0024ABD0;

typedef struct { u8 pad0[0x68]; u8 *x68; } O_0052D4E8;

void func_L39_0052D4E8(O_0052D4E8 *o) {
    u8 *self = (u8 *)o;
    u8 *s = o->x68;
    u8 *q = *(u8 **)(s + 0x6D0);
    u8 *g = *(u8 **)(q + 0x2D8);
    u8 *r;
    u8 *e;
    u8 *hit;
    u8 *c;
    u8 *p;
    f32 f21;
    f32 f20;
    f32 len;
    s32 t;
    vu0_v4 v0 __attribute__((aligned(16)));
    vu0_v4 v10 __attribute__((aligned(16)));
    vu0_v4 v20 __attribute__((aligned(16)));
    vu0_v4 v30 __attribute__((aligned(16)));
    vu0_v4 v40 __attribute__((aligned(16)));
    u32 flag;

    if (g[0x1A14] == 0) {
        return;
    }
    if (*(s16 *)(g + 0x320) > 0) {
        return;
    }
    if (*(f32 *)(q + 0x308) <= 0.0f) {
        return;
    }
    t = self[0xBC];
    if (t == 0xA || t == 0xB || t == 7 || t == 8) {
        return;
    }
    r = *(u8 **)(q + 0x2D0);
    *(s32 *)(r + 0x98) = 0;
    *(vu0_q *)&v20 = *(vu0_q *)(*(u8 **)(q + 0x2D0) + 0xC0);
    func_0038CE20(&v0, *(u8 **)(q + 0x2D0) + 0xE0, 0.5f);
    v_add(&v0, &v0, *(u8 **)(q + 0x2D0) + 0x10);
    e = func_L39_006472D0(g, &v0, &v20, 1, 0.0872664601f, 0.17453292f, 70.0f, 0.69813168f, 0.261799395f);
    r = *(u8 **)(q + 0x2D0);
    *(s32 *)(r + 0x98) = *(s32 *)(*(u8 **)(r + 0x24) + 0x10);
    func_0038D000(&v0, &D_L39_0024ABF0[q[0x2FE]], self + 0xC0);
    v_add(&v0, &v0, self + 0x10);
    if (e != 0) {
        f21 = 0.1f;
        f20 = func_0038CF00(*(u8 **)(g + 0x2530), e + 0x10) / 150.0f;
        c = func_00382348(e);
        if (c != 0) {
            f21 = *(f32 *)(c + 0x10);
        }
        func_0038CE20(&v30, e + 0xE0, f21);
        v_add(&v30, e + 0x10, &v30);
        v30.w = ((f32 *)(e + 0x10))[3];
        if (g[0x1A14] != 0) {
            func_L01_003F6F20(g[0x24C9], *(u8 **)(q + 0x2D0), 0xFF0FFF0F, &v30, 0x26, -1, 4,
                              fabs_asm(0.9f - f20 * 0.65f), 0.0f, 90.0f, 0.5f, 0.5f, 40.0f, 40.0f);
        }
        v_sub(&v10, &v30, &v0);
        len = func_0038CEA8(&v10);
        qzero(&v40);
        c = func_L39_0061D7B0(e);
        if (c != 0 && (c[3] & 0xF) != 0) {
            c = 0;
        }
        if (c != 0) {
            *(vu0_q *)&v40 = *(vu0_q *)(c + 0x140);
            v40.z += 0.015f;
        } else {
            s16 h = *(s16 *)(e + 0xAA);
            if (h < 0x1080 && h >= 0x107C) {
                p = func_L39_00668620(e);
                *(vu0_q *)&v40 = *(vu0_q *)(p + 0x270);
            }
        }
        if (0.0f < len) {
            func_0038CE20(&v40, &v40, D_L39_0024AB3C / len);
            func_0038CE20(&v10, &v10, (*(f32 *)(q + 0x310) + 1.8f) / len);
        } else {
            func_0038CE20(&v40, &v40, D_L39_0024AB3C);
            func_0038CE20(&v10, &v10, *(f32 *)(q + 0x310) + 1.8f);
        }
        v_add(&v10, &v10, &v40);
    } else {
        r = *(u8 **)(q + 0x2D0);
        func_00382760(&v10, *(f32 *)(q + 0x310) + 1.8f, *(f32 *)(r + 0xF8), -(*(f32 *)(r + 0xF4) + 0.03f));
    }
    p = *(u8 **)(g + 0x2534);
    if ((*(s32 *)(p + 0x1A0) & 0x28) != 0 && *(s16 *)(s + 0x716) <= 0) {
        flag = 0x80000000;
        hit = func_L07_003CAE10(&v0, &v10, self, 1, &flag, *(s32 *)(g + 0x2544), -1, 6.0f, D_L39_0024ABD4);
        func_L39_005F33E0(3, 0, self);
        func_L01_003F1F20(D_L39_0024AB38, *(s32 *)(g + 0x2534));
        if (hit != 0) {
            *(s32 *)(hit + 0x90) = *(s32 *)g;
            t = func_L39_0066E010(g, 6, hit, e, 0);
            *(s32 *)(*(u8 **)(hit + 0x68) + 0x44) = t;
            *(s32 *)(*(u8 **)(hit + 0x68) + 0x24) = 0x32;
            *(f32 *)(*(u8 **)(hit + 0x68) + 0x28) = 0.016666668f;
            q[0x2FE] ^= 1;
            *(s16 *)(s + 0x716) = (D_L39_0024ABD0 * 5 + 2) / 6;
        }
    }
    func_0038CB00(s + 0x716);
}

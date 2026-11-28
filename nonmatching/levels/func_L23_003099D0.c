/* func_L23_003099D0, near miss (k8 split task, 2026-11-28): 104 words differ, 59 once the self/counter
 * ($s4/$s5) and &vA0/&vB0 ($s7/$fp) swaps are discounted. Written as its own file, the cut it needs:
 * src/levels/23_holostar_studios_clank/L23_003099D0.c (0x003099D0-0x0030A6F8, the last function of
 * L23_003098F8.c) with the line "-mvu0-use-vf0-vf2 -O2 -G8 -fopt-stack -mno-check-zero-division @ps2as"
 * (the whole file cannot take it: func_L23_003098F8 42 diff, func_L23_003099A8 10 diff under it).
 * From wave 13c's 322: the vadd stored twice is vec_add_ab_q/vec_add_ba_q below (the sum handed back
 * and stored again by the compiler); D_L23_001D6170..6178 are one small-data struct (globals.md "Small
 * data at an offset": its +4/+8 fields stay out of delay slots, as retail's); func_L23_004450E0 takes
 * ints (no second andi); the colour is (r << 16) | (0x7F000000 | (g << 8)) | lo through a local; the min
 * is a ternary in the call; state 1 addresses self + 0x10 directly instead of through a pos local.
 * Left: register allocation only, at close priorities (tools/regalloc.py): self (refs 27, live 472,
 * 0.229) loses $s4 to the k loop's hoisted &vA0 (refs 7, live 60, 0.233), and slot (refs 7, live 198,
 * 0.071) loses $s1 to state 1's self + 0x10 (refs 6, live 122, 0.098), which also moves r/g/n and the
 * k counter in the x40 branch (0xA00-0xAA8) and the scheduling there. Tried without effect: a do-while
 * or block-scoped k, &v->vel for v, other spellings of the vadd's pointers; sharing one counter between
 * the loops is worse (142, 178). */
#include "common.h"

#include "vu0.h"
#include "structs/hero.h"
/* vec_add_ab/vec_add_ba that also return the sum in its VU0 register, so that the caller stores it a
 * second time with a plain vu0_q assignment, which the compiler emits as its own sqc2 (and may put in
 * a delay slot, as retail's 0x30A1DC bc1t slot has it). The same helper is file-local in
 * L24_0034ED28.c (vadd1_ab/ba_34ED28) and L24_0034E6F8.c (vaddto_q_34E6F8); it belongs in
 * include/vu0.h once this function lands. */
static __inline__ vu0_q vec_add_ab_q(void *d, void *a, void *b) {
    vu0_q qa, qb, qr;
    __asm__("lqc2 %0, %1" : "=j"(qa) : "m"(*(vu0_v4 *)a));
    __asm__("lqc2 %0, %1" : "=j"(qb) : "m"(*(vu0_v4 *)b));
    __asm__("vadd.xyz %0, %1, %2" : "=j"(qr) : "j"(qa), "j"(qb));
    __asm__("sqc2 %1, %0" : "=m"(*(vu0_v4 *)d) : "j"(qr));
    return qr;
}
static __inline__ vu0_q vec_add_ba_q(void *d, void *a, void *b) {
    vu0_q qa, qb, qr;
    __asm__("lqc2 %0, %1" : "=j"(qb) : "m"(*(vu0_v4 *)b));
    __asm__("lqc2 %0, %1" : "=j"(qa) : "m"(*(vu0_v4 *)a));
    __asm__("vadd.xyz %0, %1, %2" : "=j"(qr) : "j"(qa), "j"(qb));
    __asm__("sqc2 %1, %0" : "=m"(*(vu0_v4 *)d) : "j"(qr));
    return qr;
}
typedef int u128_t __attribute__((mode(TI)));
extern s32 D_L23_001DC5F4;
extern s32 D_L23_001DC5F8;
extern void func_003C2880(s32);
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_99D0;
typedef struct {
    V4_99D0 vel;
    s32 x10;
    s32 x14;
    u8 pad18[0x2C - 0x18];
    s16 x2C;
    s16 x2E;
    u8 pad30[0x40 - 0x30];
    s16 x40;
} Vars_99D0;
typedef struct {
    f32 x0;
    f32 x4;
    u8 pad8[8];
    V4_99D0 pos;
} Fx_99D0;
extern struct Hero D_001A4BE0;
extern s32 D_L23_001DC5F0;
extern f32 D_L23_001DC5EC;
extern u8 D_L23_001D6160;
typedef struct { u8 on; u8 pad1[3]; s32 color; long x8; } S6170_99D0;
extern S6170_99D0 D_L23_001D6170 __attribute__((section(".sdata")));
extern s32 D_L23_001DEC40;
extern Fx_99D0 D_L23_001EFE00[];
extern u8 D_L23_001EC800[];
extern u8 *D_L23_0021ED58[];
extern struct { u8 pad[0x140]; f32 x140; f32 x144; } D_L23_001E1880;
__asm__(".extern D_L23_001DC5F0, 4");
__asm__(".extern D_L23_001DC5EC, 4");
__asm__(".extern D_L23_001DC5F4, 4");
__asm__(".extern D_L23_001DC5F8, 4");
__asm__(".extern D_L23_001D6160, 16");
__asm__(".extern D_L23_001D6170, 16");
__asm__(".extern D_L23_001DEC40, 16");
extern f32 func_003824E0(f32, f32);
extern s32 func_00382498(s32, s32);
extern void func_0038CF68(void *, void *, f32);
extern void func_L23_00449BD8(s32, void *, void *);
extern f32 func_0038D160(f32, f32);
extern f32 func_L01_00443A18(f32, f32);
extern f32 func_0038DAB8(f32, f32);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern u8 *func_L01_004713C8(void *, void *, s32, u32, s32, f32, f32, f32, s32, s32, s32);
extern s32 func_L01_00424B88(void *, s32, f32, f32);
extern void func_L01_00424D88(s32);
extern void func_003A4F28(s32);
extern s32 func_003D4D00(void *, s32, void *, s32, f32);
extern void func_L01_00447718(void *, void *, void *, s32, s32, s32, s32, s32, s32, f32, f32, f32);
extern s32 func_L01_003303B8(u8 *, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32,
                          s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern void func_L23_00448CD8(void *, int, int, int, float);
extern void func_00382580(void *, f32, f32);
extern void func_0038CE20(void *, void *, f32);
extern void func_003C4C18(void *, f32);
extern s32 func_00382468(s32);
extern u8 *func_L01_00465738(void *, void *, s32, s32, s32, s32, s32, s32, s32, f32);
extern void func_L23_004450E0(void *, s32, s32, s32, s32, f32, f32);

void func_L23_003099D0(u8 *self) {
    Vars_99D0 *v = *(Vars_99D0 **)(self + 0x68);
    s32 *slot = (*(u8 **)(self + 0xB8) == (u8 *)D_001A4BE0.hero_moby) ? &D_L23_001DC5F4 : &D_L23_001DC5F8;
    V4_99D0 v90, vA0, vB0;
    f32 sc, ang;
    s32 i, j, k;

    switch (self[0x20]) {
    case 0:
        if (v->x2E != 0) {
            if (D_001A4BE0.body_kind != 2 && v->x40 != 0) {
                goto off;
            }
            if (v->x10 == 0 && slot == &D_L23_001DC5F8) {
                D_L23_001D6170.on = 1;
                D_L23_001D6170.color = 0xFFFF00;
            }
            {
            s32 n = v->x10 + 1;
            sc = n * 0.039473683f;
            v->x10 = n;
            }
            if (1.0f < sc) {
                sc = 1.0f;
            }
            sc = sc * (sc * (v->x40 ? 15.0f : 10.0f));
            for (i = 0; i < (s32)sc; i++) {
                s32 lo, g, r;
                *(u128_t *)&vA0 = 0;
                vA0.x = func_003824E0(-1.0f, 1.0f);
                vA0.y = func_003824E0(-1.0f, 1.0f);
                vA0.z = func_003824E0(-1.0f, 1.0f);
                *(u128_t *)&v90 = *(u128_t *)&vA0;
                if (v->x40) {
                    lo = 0x4F;
                    g = 0xAF;
                    r = 0xFF;
                } else {
                    lo = 0x6F;
                    g = 0x1F;
                    r = 0xF;
                }
                g = func_00382498(lo, g);
                r = func_00382498(lo, r);
                if (r >= 0x100) {
                    r = 0xFF;
                }
                if (g >= 0x100) {
                    g = 0xFF;
                }
                func_0038CF68(&v90, &v90, func_003824E0(15.0f, 30.0f));
                *(vu0_q *)&vA0 = vec_add_ab_q(&v90, &v90, (V4_99D0 *)(self + 0x10));
                { u32 c = 0x7F000000 | (g << 8); func_L23_00449BD8((r << 16) | c | lo, &v90, self); }
            }
            *(u128_t *)&v90 = *(u128_t *)(self + 0x10);
            for (j = 3; j >= 0; j--) {
                s32 g;
                Fx_99D0 *e;
                ang = func_0038D160(D_001A4BE0.pos.x - D_L23_001E1880.x140, D_001A4BE0.pos.y - D_L23_001E1880.x144);
                func_L01_00443A18(1.0f, 2.0f);
                vA0.x = v90.x + func_003824E0(-0.45f, 0.45f);
                vA0.y = v90.y + func_003824E0(-0.45f, 0.45f);
                vA0.z = v90.z + func_003824E0(-0.45f, 0.45f);
                ang = func_0038DAB8(ang, func_L01_00443A18(0.0f, -6.2831855f));
                vB0.x = func_0038D098(ang) * 0.015000001f;
                vB0.y = func_0038D0B0(ang) * 0.015000001f;
                vB0.z = 0.0f;
                g = (func_00382498(10, 30) * 5 + 2) / 6;
                e = (Fx_99D0 *)func_L01_004713C8(&vA0, &vB0, g, 0x804020, func_00382498(-2, -4), 168000.0f, 105000.0f, 0.00080000004f, 0x7F, 0, 0);
                if (e) {
                    ((u8 *)e)[2] = *D_L23_0021ED58[23];
                }
            }
            if (v->x10 < 50) {
                s32 n, r;
                n = D_L23_001D6170.color;
                r = (u32)n >> 24;
                if (D_L23_001D6170.x8 == 0 && r == 0xFF) {
                    r = 0x25;
                }
                if (r++ >= 0x24) {
                    r = 0x25;
                }
                D_L23_001D6170.x8 = 0x1F00000042L;
                D_L23_001D6170.color = (n & 0xFFFF00) | (r << 24);
            } else {
                D_L23_001D6170.color = D_L23_001D6170.color | 0xFF000000;
            }
            if (v->x2C != -1) {
                s32 n, r, g;
                f32 f20, f21, f22;
                Fx_99D0 *e;
                D_L23_001EFE00[v->x2C].pos.x = ((V4_99D0 *)(self + 0x10))->x;
                D_L23_001EFE00[v->x2C].pos.y = ((V4_99D0 *)(self + 0x10))->y;
                D_L23_001EFE00[v->x2C].pos.z = ((V4_99D0 *)(self + 0x10))->z;
                n = v->x10;
                if (!(n < 51)) {
                    n = 50;
                }
                if (!(-1 < n)) {
                    n = 0;
                }
                D_L23_001EFE00[v->x2C].pos.w = n * 7.0f / 50.0f;
                f21 = v->x10 / 25.333334f;
                if (1.0f < f21) {
                    f21 = 1.0f;
                }
                {
                V4_99D0 *pp = &D_L23_001EFE00[v->x2C].pos;
                r = func_00382498(15, 47) & 0xFF;
                g = func_00382498(47, 63) & 0xFF;
                func_L23_004450E0(pp, r, g, func_00382498(63, 127) & 0xFF, 17, f21 * 4.0f * 210000.0f, 0.0f);
                }
                D_L23_001EFE00[v->x2C].x0 = func_003824E0(D_L23_001EFE00[v->x2C].x0 * 0.8f,
                                                         D_L23_001EFE00[v->x2C].pos.w * 2 / 7.0f);
                f22 = D_L23_001EFE00[v->x2C].x4 * 0.8f;
                f20 = D_L23_001EFE00[v->x2C].x0;
                D_L23_001EFE00[v->x2C].x4 = func_003824E0(f20 < f22 ? f20 : f22, f20);
            } else if ((D_L23_001DEC40 & 3) == 0) {
                v->x2C = func_L01_00424B88((V4_99D0 *)(self + 0x10), 0, 0.0f, 0.0f);
            }
            goto clear;
        }
    off:
        D_L23_001D6160 = 0;
        D_L23_001D6170.on = 0;
        v->x10 = 0;
        v->vel.x = func_0038D098(D_001A4BE0.rot.z) * 1.0000001f;
        v->vel.y = func_0038D0B0(D_001A4BE0.rot.z) * 1.0000001f;
        v->vel.z = 0;
        self[0x20] = 1;
        v->x14 = 0;
        goto clear;
    case 1:
    {
        f32 f21, f22, sz;
        s32 r, g, b, n;
        Fx_99D0 *e;
        f21 = v->x14 * 1.0000001f * 0.5f + 1.3f;
        v->x14 = v->x14 + 1;
        f22 = f21 + 3.5f;
        f21 = f21 * 0.5f;
        if (v->x2C != -1) {
            D_L23_001EFE00[v->x2C].pos.w *= 0.27999998f;
            if (D_L23_001EFE00[v->x2C].pos.w < 0.0001f) {
                func_L01_00424D88(v->x2C);
                v->x2C = -1;
            }
        }
        if (v->x14 < 43 && D_001A4BE0.body_kind == 2) {
            *(vu0_q *)&vA0 = vec_add_ba_q(((V4_99D0 *)(self + 0x10)), ((V4_99D0 *)(self + 0x10)), &v->vel);
            if (!(((V4_99D0 *)(self + 0x10))->x < 2.0f) && !(1021.0f < ((V4_99D0 *)(self + 0x10))->x) && !(((V4_99D0 *)(self + 0x10))->y < 2.0f) && !(1021.0f < ((V4_99D0 *)(self + 0x10))->y) &&
                !(((V4_99D0 *)(self + 0x10))->z < 2.0f) && !(1021.0f < ((V4_99D0 *)(self + 0x10))->z)) {
                goto ok;
            }
        }
        if (*(u8 **)(self + 0xB8) == (u8 *)D_001A4BE0.hero_moby && D_L23_001DC5F0 != -1) {
            func_003A4F28(D_L23_001DC5F0);
            D_L23_001DC5F0 = -1;
        }
        func_003C2880(*slot);
        *slot = 0;
        goto end;
    ok:
                if (v->x40) {
                    r = func_003D4D00(((V4_99D0 *)(self + 0x10)), 0x10, D_001A4BE0.hero_moby, 0, f21);
                    *(u128_t *)&vA0 = *(u128_t *)(self + 0x10);
                    func_L01_00447718(self, &vA0, D_L23_001EC800, r, 0, 0x10B0000, 2, 1, -1, D_L23_001DC5EC, 1.0f, 1.0f);
                    if (r != 0 && (D_L23_001DEC40 & 1)) {
                        func_L01_003303B8(self + 0x10, 0, 2, 2, 2, 5, 5, 0, 1.0f, 0.0f, 0.0f, 2.0f,
                                          0, 1, 0, 0, 0, 0, 0x1010000, 0, 0x388EF7, 0x63F7, 0x407FFF, 0x20FF, 0x8FFF, 0x3064FF, 0x7F60A0FF, 0x280000FF, 0x3064FF, 0);
                    }
                    sz = f22 * 0.3f * 210000.0f;
                    n = 42 - v->x14;
                    if (!(n < 5)) {
                        n = 4;
                    }
                    r = func_00382498(63, 127);
                    g = func_00382498(47, 63);
                    b = func_00382498(15, 47);
                    func_L23_00448CD8(self, (r << 16) | ((g << 8) | 0x4F000000) | b, n, -1, sz);
                    func_00382580(&v90, f22 * 0.020000001f, f22 * 2 * 0.020000001f);
                    for (k = 7; k >= 0; k--) {
                        func_0038CE20(&vA0, v, -0.120000005f);
                        func_003C4C18(&vA0, 0.3f);
                        vA0.z += 0.120000005f;
                        g = func_00382468(2) ? 0x7FFF7F40 : 0x7FFFDF80;
                        e = (Fx_99D0 *)func_L01_00465738(((V4_99D0 *)(self + 0x10)), &vA0, g, 0xFF0000, func_00382498(8, 17), 0, -1, -1, 0, 315000.0f);
                        if (e) {
                            *(f32 *)((u8 *)e + 0x2C) = 0.0024000001f;
                            ((u8 *)e)[2] = *D_L23_0021ED58[53];
                        }
                    }
                    goto clear;
                }
                r = func_003D4D00(((V4_99D0 *)(self + 0x10)), 0x10, *(void **)(self + 0xB8), 0, f21);
                *(u128_t *)&vA0 = *(u128_t *)(self + 0x10);
                func_L01_00447718(self, &vA0, D_L23_001EC800, r, 0, 0x10B0007, 2, 1, -1, D_L23_001DC5EC, 1.0f, 1.0f);
                if (r != 0 && (D_L23_001DEC40 & 1)) {
                    func_L01_003303B8(self + 0x10, 0, 2, 2, 2, 5, 5, 0, 1.0f, 0.0f, 0.0f, 2.0f,
                                      0, 1, 0, 0, 0, 0, 0x1010000, 0, 0x388EF7, 0x63F7, 0x407FFF, 0x20FF, 0x8FFF, 0x3064FF, 0x7F60A0FF, 0x280000FF, 0x3064FF, 0);
                }
                func_00382580(&v90, f22 * 0.020000001f, f22 * 2 * 0.020000001f);
                goto clear;
    }
    default:
        goto clear;
    }
clear:
    v->x2E = 0;
end:;
}

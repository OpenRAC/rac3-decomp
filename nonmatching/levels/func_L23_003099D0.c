/* Wave 13 (c44, 2026-11-28) replaces the earlier draft of this function (Regional matching study (2026-11-24)). */
/* Wave 13c (worker c44): the line this function needs is the file's line + -mvu0-use-vf0-vf2 @ps2as
 * ("-mvu0-use-vf0-vf2 -O2 -G8 -fopt-stack -mno-check-zero-division @ps2as"): under it this draft is 322 words
 * (aligned 127 of 842 retail words differ); under the file's own line it does not compile (vu0.h's "j"
 * helpers) and r26's plain-C rewrite is 733. Cut: 0x003099D0-0x0030A6F8 (8-aligned start, last function of
 * L23_003098F8.c); the whole file cannot take the line (func_L23_003098F8 42 diff, func_L23_003099A8 10
 * diff with it). Still blocked as the study says: retail stores one vadd result twice (sqc2 0x90/0xA0 at
 * 0x24C/0x254 and 0x10($s4)/0xA0 at 0x7F0/0x80C, the second in a bc1t delay slot), which needs a vu0.h
 * helper that hands back the VU0 result (maintainer decision); the current helpers cost an extra lqc2.
 */
/* Unlinked regional matching draft. PAL: 337 to 322 words with diagnostic vf2 and Ps2EeAs; VU add/store sequence and scheduling remain. */
#include "common.h"

/* PAL near miss: 322 differing words (prior draft: 337), with diagnostic
 * -mvu0-use-vf0-vf2 and @ps2as. The owning file flags are unchanged.
 * Legal C only: the hero struct (structs/hero.h, D_001A4BE0) for the lui %hi(D_1A4BE0) + 0x25C0/0x25E4 reads, .extern size hints, and the include/vu0.h helpers; no hardcoded addresses or new inline asm.
 * Blocker: retail does one vadd and stores the result twice (sqc2 at 0x309C18/0x309C20 and 0x30A1BC/0x30A1D8, the second in a bc1t delay slot). No vu0.h helper or pair of helpers does that, so each site costs an extra lqc2 and the second store moves. An exact match needs a two-destination helper in include/vu0.h (a maintainer decision). With raw multi-statement vu0 asm in that spot (not allowed) the best was 717 of 842 aligned, so even that does not match yet.
 * Found on the way: the mixed $gp/lui access of D_001D6160 and D_001DEC40 needs no alias (ps2as gives a load/store in a branch delay slot the $gp form); constants 0.039473683f, 0.27999998f, 0.0024000001f, 0.020000001f, +-0.120000005f and 315000.0f (not 313000); slot = (owner == hero_moby) ? &D_L23_001DC5F4 : &D_L23_001DC5F8.
 * P05: a typed local position pointer is used for state 1's repeated accesses.
 * The two-destination VU0 residual remains.
 * Earlier register-allocation study: with the loop-1 colour locals inside loop 1, one counter per loop, and a `pos` local scoped to state 1's body only, the prologue matches retail (slot $17, v $19, self $20, frame 0x140).
 * Left besides the blocker: D_L23_001D6174/6178 accesses land in delay slots where retail has nop (0x434, 0x488; the declarations in L23_00309798.c look right); sparkle block andi order (0x5A8); min block $f0->$f12 move (0x660); vf1/vf2 order in state 1's vadd (0x7F4); x40 branch rand scheduling (0xA2C-0xA98). */
#include "vu0.h"
#include "structs/hero.h"
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
extern u8 D_L23_001D6170;
extern s32 D_L23_001D6174;
extern long D_L23_001D6178;
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
__asm__(".extern D_L23_001D6174, 16");
__asm__(".extern D_L23_001D6178, 16");
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
extern void func_L23_004450E0(void *, u8, u8, u8, s32, f32, f32);

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
                D_L23_001D6170 = 1;
                D_L23_001D6174 = 0xFFFF00;
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
                vec_add_ab(&v90, &v90, (V4_99D0 *)(self + 0x10));
                *(u128_t *)&vA0 = *(u128_t *)&v90;
                func_L23_00449BD8(((r << 16) | ((g << 8) | 0x7F000000)) | lo, &v90, self);
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
                n = D_L23_001D6174;
                r = (u32)n >> 24;
                if (D_L23_001D6178 == 0 && r == 0xFF) {
                    r = 0x25;
                }
                if (r++ >= 0x24) {
                    r = 0x25;
                }
                D_L23_001D6178 = 0x1F00000042L;
                D_L23_001D6174 = (n & 0xFFFF00) | (r << 24);
            } else {
                D_L23_001D6174 = D_L23_001D6174 | 0xFF000000;
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
                if (f20 < f22) {
                    f22 = f20;
                }
                D_L23_001EFE00[v->x2C].x4 = func_003824E0(f22, f20);
            } else if ((D_L23_001DEC40 & 3) == 0) {
                v->x2C = func_L01_00424B88((V4_99D0 *)(self + 0x10), 0, 0.0f, 0.0f);
            }
            goto clear;
        }
    off:
        D_L23_001D6160 = 0;
        D_L23_001D6170 = 0;
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
        V4_99D0 *pos = (V4_99D0 *)(self + 0x10);
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
            vec_add_ba(pos, pos, &v->vel);
            vec_copy(&vA0, pos);
            if (!(pos->x < 2.0f) && !(1021.0f < pos->x) && !(pos->y < 2.0f) && !(1021.0f < pos->y) &&
                !(pos->z < 2.0f) && !(1021.0f < pos->z)) {
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
                    r = func_003D4D00(pos, 0x10, D_001A4BE0.hero_moby, 0, f21);
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
                        e = (Fx_99D0 *)func_L01_00465738(pos, &vA0, g, 0xFF0000, func_00382498(8, 17), 0, -1, -1, 0, 315000.0f);
                        if (e) {
                            *(f32 *)((u8 *)e + 0x2C) = 0.0024000001f;
                            ((u8 *)e)[2] = *D_L23_0021ED58[53];
                        }
                    }
                    goto clear;
                }
                r = func_003D4D00(pos, 0x10, *(void **)(self + 0xB8), 0, f21);
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

/* Wave 13 (r27, 2026-11-28) replaces the earlier draft of this function (NTSC-U draft of `func_L19_003AC958` (Claude wave C4)). */
#include "common.h"

/* func_L19_003AE5A8, first PAL draft (wave 13 r27). The old draft was the NTSC-U twin's C (func_L19_003AC958,
 * NTSC names, conflicting declarations: no count); this one is written from PAL's retail code: PAL constants
 * (rand 0..0x19, particle counts 8/0x11/5, 4/8/8, 2/5/3, timer 0x19, 0.12133334f), PAL catalogue names, the
 * file's own declarations (D_L19_001DF240, D_L19_001E8E60, func_003D3CB0 with its s32 5th argument,
 * func_003A4F28, func_0038CE20, func_L01_0040E570). Two inline helpers reproduce retail's addressing: the
 * hero base (retail derives it from the hero-position pointer, addiu -0x140, then reads 0x160/0x164) and the
 * slot record (offset 0xDC kept off the base). 319 naive diff only because two instructions are missing:
 * still differs (12 aligned lines): in both func_0038DBD8 colour calls gcc schedules mov.s f12 before the
 * lw a1 of D_L19_001DE5BC / D_L19_001DE5C4 and reorg puts that load in the jal delay slot (Ps2EeAs then
 * uses $gp); retail keeps the lui/lw before the call and mov.s in the slot; and move t0,v0 is scheduled
 * earlier before func_L01_00463378. Tried: colour temporaries, rand value through a variable (no change);
 * unsized arrays for the lui globals (gcc splits and hoists the lui into s-registers, much worse). */

/* localdecomp:start func_L19_003AE5A8 */
#include "vu0.h"
__asm__(".extern D_001DE5A8_sda, 4");
extern f32 D_001DE5A8_sda;
__asm__(".extern D_001DE5AC_sda, 4");
extern f32 D_001DE5AC_sda;
__asm__(".extern D_001DE5B0_sda, 4");
extern f32 D_001DE5B0_sda;
__asm__(".extern D_001DE5B8_sda, 4");
extern s32 D_001DE5B8_sda;
extern f32 D_L19_001DE5B4;
__asm__(".extern D_L19_001DE5B4, 16");
extern s32 D_L19_001DE5BC;
__asm__(".extern D_L19_001DE5BC, 16");
extern s32 D_L19_001DE5C0;
__asm__(".extern D_L19_001DE5C0, 16");
extern s32 D_L19_001DE5C4;
__asm__(".extern D_L19_001DE5C4, 16");
extern u8 D_L19_001E1F40[];
extern s32 D_001A71A0[];
extern u8 D_001A3190[];
extern u8 D_001A30B0[];
extern s32 func_00382498(s32, s32);
extern f32 func_003824E0(f32, f32);
extern void func_0038CF68(void *, void *, f32);
extern s32 func_0038DBD8(s32, s32, f32);
extern void func_L01_00463378(void *, void *, void *, s32, s32, s32, s32, s32, s32);
extern s32 func_003A52A0(s32, s32, void *);
extern void func_L01_00446748(void *, void *, s32, f32);
extern u8 *func_00382348(s32);
extern void func_L01_00466F50(void *, void *, s32, f32, f32);
extern s32 func_0038CAD0(void *);
extern void func_L01_00404808(void *, void *);
extern void func_L19_003AEC08(void);

/* the hero */
static __inline__ u8 *hero_003AE5A8(void) {
    return D_L19_001E1F40;
}

static __inline__ u8 *slotrec_003AE5A8(s32 i) {
    return D_001A30B0 + (i << 7);
}

void func_L19_003AE5A8(void *arg) {
    u8 *o = arg;
    u8 *s = *(u8 **)(o + 0x68);
    vu0_v4 v10;
    vu0_v4 v20;
    vu0_v4 v30[3];
    s32 hit;
    s32 slot;
    u8 *rec;
    f32 dist;

    if (o[0x20] == 3 && func_00382498(0, 0x19) < *(u16 *)(o + 0x96)) {
        vec_sub_ba(&v10, s + 0x60, o + 0x10);
        func_0038CF68(&v10, &v10, D_001DE5A8_sda);
        v10.x += func_003824E0(-D_001DE5AC_sda, D_001DE5AC_sda);
        v10.y += func_003824E0(-D_001DE5AC_sda, D_001DE5AC_sda);
        v10.z += func_003824E0(-D_001DE5AC_sda, D_001DE5AC_sda);
        v10.w = func_003824E0(D_001DE5B0_sda, D_L19_001DE5B4);
        func_0038CE20(&v20, &v10, 0.5f);
        v20.z -= 0.12133334f;
        func_L01_00463378(o + 0x10, &v10, &v20,
                          func_0038DBD8(D_001DE5B8_sda, D_L19_001DE5BC, func_003824E0(0.0f, 1.0f)),
                          func_0038DBD8(D_L19_001DE5C0, D_L19_001DE5C4, func_003824E0(0.0f, 1.0f)),
                          8, 0x11, 5, 0x1003C);
        slot = *(s32 *)(s + 8);
        if (slot != -1) {
            rec = D_001A30B0 + (slot << 7);
            if (*(u8 **)(rec + 0xDC) == o && rec[0xD0] != 0) {
                func_003A4F28(slot);
            }
        }
        *(s32 *)(s + 8) = -1;
        return;
    }
    hit = 0;
    dist = func_L01_0040E570(s + 0x40, D_L19_001E1F40 + 0x140);
    if (dist < 256.0f) {
        func_L01_00446748(v30, o, 0x110001, 10.0f);
        *(u16 *)((u8 *)v30 + 0x1A) = *(u16 *)(o + 0xAA);
        *(u128_t *)(s + 0x50) = *(u128_t *)(s + 0x60);
        if (func_003D3CB0(o + 0x10, s + 0x40, 0, o, o[0x20] != 3 ? (s32)v30 : 0) != 0) {
            *(u128_t *)(s + 0x60) = *(u128_t *)&D_L19_001E8E60;
            if (*(s32 *)((u8 *)&D_L19_001E8E60 - 8) == D_001A71A0[0] ||
                func_00382348(*(s32 *)((u8 *)&D_L19_001E8E60 - 8)) != 0) {
                hit = 1;
            }
        } else {
            *(u128_t *)(s + 0x60) = *(u128_t *)(s + 0x40);
        }
    } else {
        *(u128_t *)(s + 0x60) = *(u128_t *)(s + 0x40);
    }
    vec_sub_ba(&v10, s + 0x60, D_L19_001E1F40 + 0x140);
    if (*(s32 *)s != 3 && dist < 256.0f &&
        0.0f < *(f32 *)(hero_003AE5A8() + 0x160) * v10.x + *(f32 *)(hero_003AE5A8() + 0x164) * v10.y) {
        if (*(s32 *)s != 2) {
            qzero(&v20);
            func_L01_00466F50(s + 0x60, &v20, 0, -1.0f, 0.0f);
            if (dist < 128.0f) {
                vec_add_ab(&v30[0], s + 0x60, s + 0x50);
                func_0038CE20(&v30[0], &v30[0], 0.5f);
                func_L01_00466F50(&v30[0], &v20, 0, -1.0f, 0.0f);
            }
        }
        if (dist < 128.0f) {
            if (D_L19_001DF240 & 1) {
                qzero(&v20);
                v20.x = func_003824E0(-0.005f, 0.005f);
                v20.y = func_003824E0(-0.005f, 0.005f);
                qzero(&v30[0]);
                v20.z = 0.03f;
                v20.w = 0.1f;
                v30[0].x = v20.x * 0.5f;
                v30[0].y = v20.y * 0.5f;
                v30[0].z = 0.01f;
                v30[0].w = 0.4f;
                func_L01_00463378(s + 0x60, &v20, &v30[0], 0x75000000, 0x60404040, 4, 8, 8, -1);
            } else {
                qzero(&v20);
                v20.x = func_003824E0(-0.01f, 0.01f);
                v20.y = func_003824E0(-0.01f, 0.01f);
                qzero(&v30[0]);
                v20.z = 0.03f;
                v20.w = 0.1f;
                v30[0].x = v20.x * 0.5f;
                v30[0].y = v20.y * 0.5f;
                v30[0].z = 0.0f;
                v30[0].w = 0.2f;
                func_L01_00463378(s + 0x60, &v20, &v30[0], 0x7F0040FF, 0x40204060, 2, 5, 3, -1);
            }
        }
    }
    if (*(s32 *)(s + 8) < 0 || *(u8 **)(slotrec_003AE5A8(*(s32 *)(s + 8)) + 0xDC) != o) {
        *(s32 *)(s + 8) = func_003A52A0(0, 0xC, o);
    }
    if (*(s32 *)(s + 8) >= 0) {
        *(u128_t *)(D_001A3190 + (*(s32 *)(s + 8) << 7)) = *(u128_t *)(s + 0x60);
    }
    if (func_0038CAD0(s + 0x14) != 0 && hit != 0) {
        func_003A52A0(1, 0, o);
        *(s32 *)(s + 0x14) = 0x19;
    }
    func_L01_00404808((void *)func_L19_003AEC08, o);
}
/* localdecomp:end func_L19_003AE5A8 */

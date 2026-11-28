/* func_L01_00364180 (Claude wave 14 r70, 2026-11-28). First draft kept here. */
/* func_L01_00364180 (2148 B, 34 places): first PAL draft (wave 14 r70), from the functional C in
 * nonmatching/functional/ with the file's vu0.h helpers. 477 diff (wave10/p10 check, level 01, the file's
 * flags): the prologue, frame (0x190) and save order match; the strip loop's structure is retail's.
 * Forms taken from retail: phase and u share one variable (retail keeps both in $f21), the row lookup
 * index-first (D_001425C0[0x87] + D_L01_002C5600)->b1, the 0x90..0xCF temporaries as one vu0_v4 m[4]
 * (retail reuses that block as the rotation matrix), vec_sub_ba/vec_sub_ab chosen by retail's load order.
 * Left: the row lookup is fused into madd here (retail mult + addu), the j == 1 / j == 9 colour constants
 * are hoisted out of the strip loop (retail rematerialises them), 0.05f and u + 0.3f take $f22/$f23 the
 * other way round, the k + 1 counter and the address spill slots differ.
 * Declarations: func_L01_003660B0 and func_0038D328 are declared here with void * where the file's later
 * block uses S_38C110v/s128 (that typedef is defined after this function: it must move up, or these
 * prototypes take its type, before the block can land); D_L01_001DD7DC is s32 in a later block, so it is
 * read as *(f32 *)&D_L01_001DD7DC. */
#include "common.h"

/* localdecomp:start func_L01_00364180 */
#include "vu0.h"
typedef struct {
    vu0_v4 pos[4];
    s32 col[4];
    f32 uv[8];
    long w70, w78, w80, w88;
} Pkt_00364180;
typedef struct { u8 b0; u8 b1; u8 pad[0xEE]; } Row_00364180;
extern s32 D_L01_001DD760;
extern s32 D_L01_001DD764;
extern s32 D_L01_001DD768;
extern s32 D_L01_001DD76C;
extern s32 D_L01_001DD770;
extern f32 D_L01_001DD77C;
extern f32 D_L01_001DD780;
extern f32 D_L01_001DD784;
extern f32 D_L01_001DD7AC;
extern f32 D_L01_001DD7B0;
extern s32 D_L01_001DD7B4;
extern f32 D_L01_001DD7B8;
extern f32 D_L01_001DD7BC;
extern f32 D_L01_001DD7C0;
extern f32 D_L01_001DD7C4;
extern f32 D_L01_001DD7C8;
extern f32 D_L01_001DD7CC;
extern f32 D_L01_001DD7D0;
extern f32 D_L01_001DD7D4;
__asm__(".extern D_L01_001DD760, 4");
__asm__(".extern D_L01_001DD764, 4");
__asm__(".extern D_L01_001DD768, 4");
__asm__(".extern D_L01_001DD76C, 4");
__asm__(".extern D_L01_001DD770, 4");
__asm__(".extern D_L01_001DD77C, 4");
__asm__(".extern D_L01_001DD780, 4");
__asm__(".extern D_L01_001DD784, 4");
__asm__(".extern D_L01_001DD7AC, 4");
__asm__(".extern D_L01_001DD7B0, 4");
__asm__(".extern D_L01_001DD7B4, 4");
__asm__(".extern D_L01_001DD7B8, 4");
__asm__(".extern D_L01_001DD7BC, 4");
__asm__(".extern D_L01_001DD7C0, 4");
__asm__(".extern D_L01_001DD7C4, 4");
__asm__(".extern D_L01_001DD7C8, 4");
__asm__(".extern D_L01_001DD7CC, 4");
__asm__(".extern D_L01_001DD7D0, 4");
__asm__(".extern D_L01_001DD7D4, 4");
extern s32 D_L01_001DD7DC;
__asm__(".extern D_L01_001DD7DC, 4");
extern s32 D_L01_001D673C;
extern u8 D_001425C0[];
extern u8 *D_001A71A0[];
extern Row_00364180 D_L01_002C5600_00364180[];
extern s16 D_L01_001E1B10_00364180[];
extern f32 D_L01_001E1B30[];
extern vu0_v4 D_L01_001E29C0_00364180;
extern vu0_v4 D_L01_001E2DC0;
extern vu0_v4 D_L01_0028E3A0[];
extern vu0_v4 D_L01_0028E440[][20];

void func_L01_00364180(void)
{
    extern s32 func_00389598(s32);
    extern f32 func_003824E0(f32, f32);
    extern f32 func_0038DAB8(f32, f32);
    extern f32 func_0038D160(f32, f32);
    extern void func_0038CF68(void *, void *, f32);
    extern f32 func_0038CE68(void *, void *);
    extern f32 func_0038CED8(void *);
    extern s32 func_0038DC20(void *, f32);
    extern void func_L01_00363E68(void *position, s32 texture, f32 size, f32 offset, f32 angle, f32 stretch);
    extern void func_0038D328(void *, void *);
    extern void func_L01_003660B0(void *, void *, s32, s32, f32, f32, f32, f32, f32, f32);
    Pkt_00364180 p;
    vu0_v4 m[4];
    vu0_v4 rot;
    vu0_v4 dir;
    f32 u, unext, uprev, v, vnew, t;
    s32 j, k, k1, i, base, val;

    p.w78 = func_00389598(D_L01_001DD770);
    u = D_L01_001DD77C;
    p.w80 = 0x8000000260L;
    p.w88 = (long)D_L01_001DD760 | ((long)D_L01_001DD764 << 2) | ((long)D_L01_001DD768 << 4) |
            ((long)D_L01_001DD76C << 6) | 0x8000000000L;
    p.w70 = 0;
    t = u + 0.001f;
    D_L01_001DD77C = t;
    if (7.0f < t) {
        D_L01_001DD77C = t - 7.0f;
    }
    u = u + 0.3f;
    for (j = 1; j < 10; j++) {
        v = D_L01_001DD780;
        t = v + D_L01_001DD784;
        D_L01_001DD780 = t;
        if (7.0f < t) {
            D_L01_001DD780 = t - 7.0f;
        }
        base = ((D_001425C0[0x87] + D_L01_002C5600_00364180)->b1 < 2) ? 0x404040 : 0x406080;
        unext = u + 0.3f;
        for (k = 0; k < 20; k++) {
            k1 = (k + 1) % 20;
            p.pos[0] = D_L01_0028E440[j][k];
            p.pos[1] = D_L01_0028E440[j][k1];
            p.pos[2] = D_L01_0028E440[j - 1][k];
            p.pos[3] = D_L01_0028E440[j - 1][k1];
            vec_sub_ba(&m[0], &p.pos[0], &p.pos[1]);
            vec_sub_ba(&m[1], &p.pos[2], &p.pos[1]);
            func_0038CE90(&m[2], &m[1], &m[0]);
            vec_sub_ab(&m[3], &p.pos[1], &D_L01_001E29C0_00364180);
            if (0.0f <= func_0038CE68(&m[2], &m[3])) {
                v = v + 0.05f;
            } else {
                vnew = v + 0.05f;
                uprev = u - 0.3f;
                val = D_L01_001E1B10_00364180[j];
                for (i = 0; i < 2; i++) {
                    if (!(-1 < val)) {
                        val = 0;
                    }
                    if (!(val < 0x21)) {
                        val = 0x20;
                    }
                    p.col[i * 2 + 1] = (val << 24) | base;
                    p.col[i * 2] = (val << 24) | base;
                    val = D_L01_001E1B10_00364180[j - 1];
                }
                if (j == 1) {
                    p.col[2] = 0x20404040;
                    p.col[3] = 0x20404040;
                } else if (j == 9) {
                    p.col[0] = 0x404040;
                    p.col[1] = 0x404040;
                }
                p.uv[5] = v;
                p.uv[1] = v;
                p.uv[6] = uprev;
                p.uv[0] = u;
                p.uv[2] = u;
                p.uv[3] = vnew;
                p.uv[4] = uprev;
                p.uv[7] = vnew;
                v = vnew;
                func_003D2DA0(&p, 0, 0);
            }
        }
        u = unext;
    }
    func_003A9440(0x47, 0x5360B);
    t = *(f32 *)&D_L01_001DD7DC + 1.0f;
    *(f32 *)&D_L01_001DD7DC = t;
    if (30.0f < t && D_L01_001D673C == 0) {
        D_L01_001DD7B8 = func_0038DAB8(D_L01_001DD7B8, func_003824E0(-1.5f, -3.0f) * 0.017453292f);
        D_L01_001DD7BC = func_0038DAB8(D_L01_001DD7BC, func_003824E0(-3.5f, -6.0f) * 0.017453292f);
        D_L01_001DD7C0 = func_0038DAB8(D_L01_001DD7C0, func_003824E0(-1.5f, -6.5f) * 0.017453292f);
        D_L01_001DD7C4 = func_0038DAB8(D_L01_001DD7C4, func_003824E0(-3.5f, -6.0f) * 0.017453292f);
        D_L01_001DD7C8 = func_0038DAB8(D_L01_001DD7C8, func_003824E0(-4.5f, -6.0f) * 0.017453292f);
        D_L01_001DD7CC = func_0038DAB8(D_L01_001DD7CC, func_003824E0(-5.0f, -8.0f) * 0.017453292f);
        t = D_L01_001DD7D0 - 0.008f;
        D_L01_001DD7D0 = t;
        if (t < 0.7f) {
            D_L01_001DD7D0 = 1.7f;
        }
        t = D_L01_001DD7D4 - 0.008f;
        D_L01_001DD7D4 = t;
        if (t < 0.7f) {
            D_L01_001DD7D4 = 1.7f;
        }
        if (0.4f < func_0038CE68(&D_L01_001E2DC0, D_001A71A0[0] + 0xC0)) {
            func_L01_00363E68(&D_L01_0028E3A0[1], 0x36, 0.7f, 0.0f, D_L01_001DD7B8, 0.8f);
            func_L01_00363E68(&D_L01_0028E3A0[1], 0x36, 0.7f, 0.0f, D_L01_001DD7BC, 0.8f);
        }
        m[0] = D_L01_0028E3A0[4];
        m[0].w = 0.5f;
        if (func_0038DC20(&m[0], 96.0f) > 0) {
            func_L01_00363E68(&D_L01_0028E3A0[3], 0x36, 1.0f, 0.0f, D_L01_001DD7C0, 0.8f);
            func_L01_00363E68(&D_L01_0028E3A0[3], 0x36, 1.0f, 0.0f, D_L01_001DD7C4, 0.8f);
            func_L01_00363E68(&D_L01_0028E3A0[5], 0x36, 1.4f, 0.0f, D_L01_001DD7C8, 0.8f);
            func_L01_00363E68(&D_L01_0028E3A0[5], 0x36, 1.4f, 0.0f, D_L01_001DD7CC, 0.8f);
        }
    }
    D_L01_001DD7AC = func_0038DAB8(D_L01_001DD7AC, func_003824E0(-1.0f, -2.0f) * 0.017453292f);
    D_L01_001DD7B0 = func_0038DAB8(D_L01_001DD7B0, func_003824E0(-2.0f, -4.0f) * 0.017453292f);
    if (D_L01_001E1B10_00364180[1] > 0x20) {
        j = 1;
        do {
            f32 *angle = &D_L01_001E1B30[j];
            f32 s;
            f32 rnd;

            *angle = func_0038DAB8(*angle, func_003824E0(17.0f, 25.0f) * 0.017453292f);
            vec_sub_ba(&dir, &D_L01_0028E3A0[j], &D_L01_0028E3A0[j - 1]);
            func_0038CF68(&dir, &dir, 1.0f);
            rot.x = 0.0f;
            rot.y = func_0038D160(func_0038CED8(&dir), dir.z) + -1.5707964f;
            rot.z = func_0038D160(dir.x, dir.y);
            rot.w = 1.0f;
            func_0038D328(m, &rot);
            s = (f32)j * 0.17f + 0.35f;
            j++;
            rnd = func_003824E0(40.0f, 150.0f);
            func_L01_003660B0(&D_L01_0028E3A0[j - 1], m, D_L01_001DD7B4, 0x20604040, *angle, s, 15.0f, 35.0f,
                              D_L01_001DD7AC, rnd);
        } while (j < 10 && D_L01_001E1B10_00364180[j] > 0x20);
    }
}
/* localdecomp:end func_L01_00364180 */

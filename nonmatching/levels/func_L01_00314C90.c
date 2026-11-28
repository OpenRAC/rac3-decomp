/* func_L01_00314C90 (Claude wave 14 r54, 2026-11-28). First draft kept here. */
/* PAL near miss (r54, wave 14): first draft of a fresh entry (structure from the native port's functional C and the
 * matched siblings func_L01_00315350 / func_L01_00330820), 295 diff under the file's line. The spark burst of
 * func_L01_00314158's case 3: scratchpad hits (0x70000000, 0x20 per entry, as the siblings read it) or, with none,
 * the points of func_L01_00447938 fanned towards the camera; two func_L01_004713C8 sparks each. Still differs: our
 * loop.c hoists the &D_L01_001D66B0 argument into a callee-saved register (retail rebuilds it at each call), which adds
 * fp to the frame (0x1E0 vs 0x1D0) and shifts every register after; retail also keeps the else path's 6 and 210000.0f
 * in s3/f23 per iteration, the if path's hoisted (s5/f25), and uses a beql for the count test. */
#include "common.h"

/* localdecomp:start func_L01_00314C90 */
#include "vu0.h"
typedef struct { vu0_v4 a, b; } Scratch_00314C90;
typedef struct {
    u8 pad0[0x19];
    u8 b19;
} R_00314C90;
typedef struct {
    vu0_v4 pos;
    u8 pad10[0x450];
} Cam_00314C90;
extern u8 D_L01_001D66B0[];
extern u8 D_L01_00221098[];
extern s32 D_001D52F0;
extern Cam_00314C90 D_L01_001E2A40[];
extern f32 D_L01_001DC780;
__asm__(".extern D_L01_001DC780, 4");
extern s32 D_L01_001DC78C;
__asm__(".extern D_L01_001DC78C, 4");
extern s32 D_L01_001DC788;
__asm__(".extern D_L01_001DC788, 4");

void func_L01_00314C90(u8 *obj, Colors_00314158 *colors, f32 t) {
    extern R_00314C90 *func_L01_00448FF0(void *);
    extern s32 func_003C2B88(void *, s32);
    extern void func_00382580(void *, f32, f32);
    extern f32 func_L01_00443A18(f32, f32);
    extern f32 func_003824E0(f32, f32);
    extern s32 func_00382498(s32, s32);
    extern u8 *func_L01_004713C8(void *, void *, s32, f32, s32, s32, s32, s32, f32, f32, s32);
    extern void func_0038CDF8(void *, void *, void *, f32);
    extern s32 func_L01_00447938(void *, s32, void *, s32, f32);
    extern f32 func_0038D160(f32, f32);
    extern f32 func_0038DAB8(f32, f32);
    extern f32 func_0038D098(f32);
    extern f32 func_0038D0B0(f32);
    vu0_v4 a;
    vu0_v4 b;
    vu0_v4 c;
    vu0_v4 pts[16];
    R_00314C90 *r;
    s32 count;
    s32 k;
    s32 n;
    f32 size;
    u8 *p;
    u8 *g;

    r = func_L01_00448FF0(obj);
    if (r == 0) {
        return;
    }
    count = func_003C2B88(obj, 0);
    if (count != 0) {
        Scratch_00314C90 *e = (Scratch_00314C90 *)0x70000000;

        g = D_L01_00221098;
        for (k = 0; k < count; k++, e++) {
            if (e->b.w == 0.0f) {
                *(vu0_q *)&a = *(vu0_q *)&e->a;
                a.w = 1.0f;
                func_00382580(&b, 0.0f, e->a.w);
                vec_add_ab(&a, &a, &b);
                n = func_L01_00443A18(2.0f, 5.0f);
                size = func_003824E0(0.7f, 1.0f) * e->a.w;
                func_L01_004713C8(&a, D_L01_001D66B0, (func_00382498(10, 15) * 5 + 2) / 6, size * 210000.0f, 0x407FFF, n,
                                  0x7F, 0x7F, 0.01f * 210000.0f, -0.0012f, 1);
                n *= -2;
                p = func_L01_004713C8(&a, D_L01_001D66B0, (func_00382498(10, 15) * 5 + 2) / 6, (size *= 6.0f) * 210000.0f, 0x20FF, n,
                                      0x30, 0x30, 0.02f * 210000.0f, -0.0012f, 0);
                if (p != 0) {
                    p[2] = **(u8 **)(g + 0x198);
                }
            } else {
                *(vu0_q *)&a = *(vu0_q *)&e->a;
                *(vu0_q *)&b = *(vu0_q *)&e->b;
                a.w = 1.0f;
                b.w = 1.0f;
                func_0038CDF8(&c, &a, &b, func_003824E0(0.0f, 1.0f));
                c.x += func_003824E0(-e->a.w * 0.4f, e->a.w * 0.4f);
                c.y += func_003824E0(-e->a.w * 0.4f, e->a.w * 0.4f);
                c.z += func_003824E0(-e->a.w * 0.4f, e->a.w * 0.4f);
                n = func_L01_00443A18(2.0f, 5.0f);
                size = func_003824E0(0.7f, 1.0f) * e->a.w;
                p = func_L01_004713C8(&c, D_L01_001D66B0, (func_00382498(10, 15) * 5 + 2) / 6, size * 210000.0f, 0, n,
                                      0x4F, 0x4F, 0.01f * 210000.0f, -0.0012f, 1);
                n *= -2;
                if (p != 0) {
                    p[3] = 0x44;
                    p[2] = **(u8 **)(g + D_L01_001DC78C * 4);
                }
                p = func_L01_004713C8(&c, D_L01_001D66B0, (func_00382498(10, 15) * 5 + 2) / 6, size * 4.0f * 210000.0f, D_L01_001DC788, n,
                                      0x20, 0x10, 0.02f * 210000.0f, -0.0012f, 0);
                if (p != 0) {
                    p[2] = **(u8 **)(g + 0xD4);
                }
            }
        }
        return;
    }
    count = func_L01_00447938(obj, 0x10, pts, r->b19, D_L01_001DC780);
    {
        f32 ang;
        f32 speed;
        f32 dir;

        ang = func_0038D160(D_L01_001E2A40[D_001D52F0].pos.x - ((vu0_v4 *)(obj + 0x10))->x,
                            D_L01_001E2A40[D_001D52F0].pos.y - ((vu0_v4 *)(obj + 0x10))->y);
        for (k = 0; k < count; k++) {
            n = func_L01_00443A18(2.0f, 5.0f);
            size = func_003824E0(0.6f, 1.0f) * 0.1f;
            speed = func_003824E0(9.0f, 12.0f);
            dir = func_0038DAB8(ang, func_L01_00443A18(0.0f, 1.3962634f));
            speed *= 0.020000001f;
            a.x = func_0038D098(dir) * speed;
            a.y = func_0038D0B0(dir) * speed;
            a.z = 0.0f;
            a.z = func_003824E0(0.0f, 12.0f) * 0.020000001f;
            func_L01_004713C8(&pts[k], D_L01_001D66B0, (func_00382498(30, 50) * 5 + 2) / 6, size * 210000.0f, 0x407FFF, n,
                              0x7F, 0x7F, 0.01f * 210000.0f, 0.0012f, 1);
            g = D_L01_00221098;
            n *= -2;
            p = func_L01_004713C8(&pts[k], D_L01_001D66B0, (func_00382498(30, 50) * 5 + 2) / 6, (size *= 6.0f) * 210000.0f, 0x20FF, n,
                                  0x30, 0x30, 0.02f * 210000.0f, 0.0012f, 0);
            if (p != 0) {
                p[2] = **(u8 **)(g + 0xD4);
            }
        }
    }
}
/* localdecomp:end func_L01_00314C90 */

/* The other form the notes name (Claude wave 14 r54, func_L01_00314C90.b8.c): the draft for the line or declaration it needs, not compiled here. */
#if 0
/* PAL near variant (r54, wave 14), beside func_L01_00314C90.near.c: the same C with `extern u8 D_L01_001D66B0[8];`
 * (the form other L01 files use). cc1 then treats the symbol as $gp-sized and rebuilds its address at every call as
 * retail does, so the extra saved register and the 0x1E0 frame are gone (frame 0x1D0 as retail). 409 diff positional
 * under the file's line (429 vs 433 instructions, so every row after the count test is shifted), but 86 rows differ after
 * alignment (133 for the .near.c) and 27 by mnemonic. Still differs: retail tests the func_003C2B88 count in v1 (beql
 * with r->b19 in the delay slot, blez) and copies it to s4 for the loop, ours keeps one saved register (no beql); the
 * register numbering after that and a few delay-slot fills. */
#include "common.h"

/* localdecomp:start func_L01_00314C90 */
#include "vu0.h"
typedef struct { vu0_v4 a, b; } Scratch_00314C90;
typedef struct {
    u8 pad0[0x19];
    u8 b19;
} R_00314C90;
typedef struct {
    vu0_v4 pos;
    u8 pad10[0x450];
} Cam_00314C90;
extern u8 D_L01_001D66B0[8];
extern u8 D_L01_00221098[];
extern s32 D_001D52F0;
extern Cam_00314C90 D_L01_001E2A40[];
extern f32 D_L01_001DC780;
__asm__(".extern D_L01_001DC780, 4");
extern s32 D_L01_001DC78C;
__asm__(".extern D_L01_001DC78C, 4");
extern s32 D_L01_001DC788;
__asm__(".extern D_L01_001DC788, 4");

void func_L01_00314C90(u8 *obj, Colors_00314158 *colors, f32 t) {
    extern R_00314C90 *func_L01_00448FF0(void *);
    extern s32 func_003C2B88(void *, s32);
    extern void func_00382580(void *, f32, f32);
    extern f32 func_L01_00443A18(f32, f32);
    extern f32 func_003824E0(f32, f32);
    extern s32 func_00382498(s32, s32);
    extern u8 *func_L01_004713C8(void *, void *, s32, f32, s32, s32, s32, s32, f32, f32, s32);
    extern void func_0038CDF8(void *, void *, void *, f32);
    extern s32 func_L01_00447938(void *, s32, void *, s32, f32);
    extern f32 func_0038D160(f32, f32);
    extern f32 func_0038DAB8(f32, f32);
    extern f32 func_0038D098(f32);
    extern f32 func_0038D0B0(f32);
    vu0_v4 a;
    vu0_v4 b;
    vu0_v4 c;
    vu0_v4 pts[16];
    R_00314C90 *r;
    s32 count;
    s32 k;
    s32 n;
    f32 size;
    u8 *p;
    u8 *g;

    r = func_L01_00448FF0(obj);
    if (r == 0) {
        return;
    }
    count = func_003C2B88(obj, 0);
    if (count != 0) {
        Scratch_00314C90 *e = (Scratch_00314C90 *)0x70000000;

        g = D_L01_00221098;
        for (k = 0; k < count; k++, e++) {
            if (e->b.w == 0.0f) {
                *(vu0_q *)&a = *(vu0_q *)&e->a;
                a.w = 1.0f;
                func_00382580(&b, 0.0f, e->a.w);
                vec_add_ab(&a, &a, &b);
                n = func_L01_00443A18(2.0f, 5.0f);
                size = func_003824E0(0.7f, 1.0f) * e->a.w;
                func_L01_004713C8(&a, D_L01_001D66B0, (func_00382498(10, 15) * 5 + 2) / 6, size * 210000.0f, 0x407FFF, n,
                                  0x7F, 0x7F, 0.01f * 210000.0f, -0.0012f, 1);
                n *= -2;
                p = func_L01_004713C8(&a, D_L01_001D66B0, (func_00382498(10, 15) * 5 + 2) / 6, (size *= 6.0f) * 210000.0f, 0x20FF, n,
                                      0x30, 0x30, 0.02f * 210000.0f, -0.0012f, 0);
                if (p != 0) {
                    p[2] = **(u8 **)(g + 0x198);
                }
            } else {
                *(vu0_q *)&a = *(vu0_q *)&e->a;
                *(vu0_q *)&b = *(vu0_q *)&e->b;
                a.w = 1.0f;
                b.w = 1.0f;
                func_0038CDF8(&c, &a, &b, func_003824E0(0.0f, 1.0f));
                c.x += func_003824E0(-e->a.w * 0.4f, e->a.w * 0.4f);
                c.y += func_003824E0(-e->a.w * 0.4f, e->a.w * 0.4f);
                c.z += func_003824E0(-e->a.w * 0.4f, e->a.w * 0.4f);
                n = func_L01_00443A18(2.0f, 5.0f);
                size = func_003824E0(0.7f, 1.0f) * e->a.w;
                p = func_L01_004713C8(&c, D_L01_001D66B0, (func_00382498(10, 15) * 5 + 2) / 6, size * 210000.0f, 0, n,
                                      0x4F, 0x4F, 0.01f * 210000.0f, -0.0012f, 1);
                n *= -2;
                if (p != 0) {
                    p[3] = 0x44;
                    p[2] = **(u8 **)(g + D_L01_001DC78C * 4);
                }
                p = func_L01_004713C8(&c, D_L01_001D66B0, (func_00382498(10, 15) * 5 + 2) / 6, size * 4.0f * 210000.0f, D_L01_001DC788, n,
                                      0x20, 0x10, 0.02f * 210000.0f, -0.0012f, 0);
                if (p != 0) {
                    p[2] = **(u8 **)(g + 0xD4);
                }
            }
        }
        return;
    }
    count = func_L01_00447938(obj, 0x10, pts, r->b19, D_L01_001DC780);
    {
        f32 ang;
        f32 speed;
        f32 dir;

        ang = func_0038D160(D_L01_001E2A40[D_001D52F0].pos.x - ((vu0_v4 *)(obj + 0x10))->x,
                            D_L01_001E2A40[D_001D52F0].pos.y - ((vu0_v4 *)(obj + 0x10))->y);
        for (k = 0; k < count; k++) {
            n = func_L01_00443A18(2.0f, 5.0f);
            size = func_003824E0(0.6f, 1.0f) * 0.1f;
            speed = func_003824E0(9.0f, 12.0f);
            dir = func_0038DAB8(ang, func_L01_00443A18(0.0f, 1.3962634f));
            speed *= 0.020000001f;
            a.x = func_0038D098(dir) * speed;
            a.y = func_0038D0B0(dir) * speed;
            a.z = 0.0f;
            a.z = func_003824E0(0.0f, 12.0f) * 0.020000001f;
            func_L01_004713C8(&pts[k], D_L01_001D66B0, (func_00382498(30, 50) * 5 + 2) / 6, size * 210000.0f, 0x407FFF, n,
                              0x7F, 0x7F, 0.01f * 210000.0f, 0.0012f, 1);
            g = D_L01_00221098;
            n *= -2;
            p = func_L01_004713C8(&pts[k], D_L01_001D66B0, (func_00382498(30, 50) * 5 + 2) / 6, (size *= 6.0f) * 210000.0f, 0x20FF, n,
                                  0x30, 0x30, 0.02f * 210000.0f, 0.0012f, 0);
            if (p != 0) {
                p[2] = **(u8 **)(g + 0xD4);
            }
        }
    }
}
/* localdecomp:end func_L01_00314C90 */
#endif

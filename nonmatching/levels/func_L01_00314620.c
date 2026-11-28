/* func_L01_00314620 (Claude wave 14 r68, 2026-11-28). First draft kept here. */
/* wave 14 r68 (2026-11-28): first draft (fresh entry), from the retail assembly and the functional C: the file's prototype (func_L01_00314158 declares (u8 *, Colors_00314158 *, s32, f32, s32)), the scratchpad loop as the siblings 00315350/003155A8 write it (vec_add_ab, the spawn pair duplicated in both arms as retail has it, a for loop that loop.c reverses to retail's down counter), the second loop with n-- before the p test. 401 rows: retail's frame is 0x1E0 (this 0x1D0) because retail hoists the kind == 7 constant into s7 and so spills &b to sp+0x130; the register map (obj s0, c s1, kind s6, f22 = 1.0, f21 = 0.4) differs from this C's (obj s1, c s0, kind s7, f21, f20), which shifts every row. A named 'seven' local is propagated away (same 401). */
#include "common.h"

/* localdecomp:start func_L01_00314620 */
#include "vu0.h"
typedef struct { vu0_v4 a, b; } Scratch_00314620;
typedef struct { u8 pad0[0xD4]; u8 *w_D4; } G_00314620;
typedef struct { u8 pad0[0x19]; u8 b19; } R_00314620;
typedef struct { f32 x, y, z, w; u8 pad10[0x460 - 0x10]; } Cam_00314620;
extern u8 D_L01_001D66B0[] __attribute__((section(".sdata")));
extern G_00314620 D_L01_00221098;
extern Cam_00314620 D_L01_001E2A40[];
extern s32 D_001D52F0;
extern f32 D_L01_001DC780;
__asm__(".extern D_L01_001DC780, 4");
void func_L01_00314620(u8 *obj, Colors_00314158 *colors, s32 c, f32 t, s32 kind) {
    extern s32 func_003C2B88(void *, s32);
    extern void func_00382580(void *, f32, f32);
    extern f32 func_L01_00443A18(f32, f32);
    extern f32 func_003824E0(f32, f32);
    extern s32 func_00382498(s32, s32);
    extern u8 *func_L01_004713C8(void *, void *, s32, s32, s32, s32, s32, s32, f32, f32, f32);
    extern void func_0038CDF8(void *, void *, void *, f32);
    extern s32 func_00382468(s32);
    extern R_00314620 *func_L01_00448FF0(void *);
    extern s32 func_L01_00447938(void *, s32, void *, s32, f32);
    extern f32 func_0038D160(f32, f32);
    extern f32 func_0038DAB8(f32, f32);
    extern f32 func_0038D098(f32);
    extern f32 func_0038D0B0(f32);
    vu0_v4 a, b, d, pts[16];
    Scratch_00314620 *e;
    vu0_v4 *pos;
    R_00314620 *r;
    s32 n, i, spin, life;
    f32 size, speed, angle, heading;
    u8 *p;

    n = func_003C2B88(obj, 0);
    if (n != 0) {
        e = (Scratch_00314620 *)0x70000000;
        for (i = 0; i < n; i++, e++) {
            if (e->b.w == 0.0f) {
                *(vu0_q *)&a = *(vu0_q *)&e->a;
                a.w = 1.0f;
                func_00382580(&b, 0.0f, e->a.w);
                vec_add_ab(&a, &a, &b);
                spin = func_L01_00443A18(2.0f, 5.0f);
                size = func_003824E0(0.7f, 1.0f) * e->a.w;
                life = func_00382498(10, 15);
                func_L01_004713C8(&a, D_L01_001D66B0, (life * 5 + 2) / 6, colors->first, spin, 0x7F, 0x7F, 1,
                                  size * 210000.0f, 2100.0f, -0.0012f);
                spin = -(spin << 1);
                life = func_00382498(10, 15);
                size = size * 6.0f;
                p = func_L01_004713C8(&a, D_L01_001D66B0, (life * 5 + 2) / 6, colors->second, spin, 0x30, 0x30, 0,
                                      size * 210000.0f, 4200.0f, -0.0012f);
            } else {
                *(vu0_q *)&a = *(vu0_q *)&e->a;
                *(vu0_q *)&b = *(vu0_q *)&e->b;
                a.w = 1.0f;
                b.w = 1.0f;
                func_0038CDF8(&d, &a, &b, func_003824E0(0.0f, 1.0f));
                d.x += func_003824E0(-e->a.w * 0.4f, e->a.w * 0.4f);
                d.y += func_003824E0(-e->a.w * 0.4f, e->a.w * 0.4f);
                d.z += func_003824E0(-e->a.w * 0.4f, e->a.w * 0.4f);
                spin = func_L01_00443A18(2.0f, 5.0f);
                size = func_003824E0(0.7f, 1.0f) * e->a.w;
                life = func_00382498(10, 15);
                func_L01_004713C8(&d, D_L01_001D66B0, (life * 5 + 2) / 6, colors->first, spin, 0x7F, 0x7F, 1,
                                  size * 210000.0f, 2100.0f, -0.0012f);
                spin = -(spin << 1);
                life = func_00382498(10, 15);
                size = size * 6.0f;
                p = func_L01_004713C8(&d, D_L01_001D66B0, (life * 5 + 2) / 6, colors->second, spin, 0x30, 0x30, 0,
                                      size * 210000.0f, 4200.0f, -0.0012f);
            }
            if (p != 0) {
                p[2] = *D_L01_00221098.w_D4;
                if (kind == 7) p[3] = func_00382468(5) ? 0x44 : 0x48;
            }
        }
        return;
    }
    r = func_L01_00448FF0(obj);
    if (r != 0 && c == 0) c = r->b19;
    n = func_L01_00447938(obj, 0x10, pts, c, D_L01_001DC780);
    heading = func_0038D160(D_L01_001E2A40[D_001D52F0].x - *(f32 *)(obj + 0x10),
                            D_L01_001E2A40[D_001D52F0].y - *(f32 *)(obj + 0x14));
    if (n <= 0) return;
    pos = pts;
    do {
        spin = func_L01_00443A18(2.0f, 5.0f);
        size = func_003824E0(0.6f, 1.0f) * 0.1f;
        speed = func_003824E0(9.0f, 12.0f) * 0.020000001f;
        angle = func_0038DAB8(heading, func_L01_00443A18(0.0f, 1.3962634f));
        a.x = func_0038D098(angle) * speed;
        a.y = func_0038D0B0(angle) * speed;
        a.z = 0.0f;
        a.z = func_003824E0(0.0f, 12.0f) * 0.020000001f;
        life = func_00382498(0x1E, 0x32);
        func_L01_004713C8(pos, D_L01_001D66B0, (life * 5 + 2) / 6, colors->first, spin, 0x7F, 0x7F, 1,
                          size * 210000.0f, 2100.0f, 0.0012f);
        spin = -(spin << 1);
        life = func_00382498(0x1E, 0x32);
        size = size * 6.0f;
        p = func_L01_004713C8(pos, D_L01_001D66B0, (life * 5 + 2) / 6, colors->second, spin, 0x30, 0x30, 0,
                              size * 210000.0f, 4200.0f, 0.0012f);
        n--;
        if (p != 0) p[2] = *D_L01_00221098.w_D4;
        pos++;
    } while (n != 0);
}
/* localdecomp:end func_L01_00314620 */

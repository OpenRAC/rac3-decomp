/* func_L19_0035D2B8 (Claude wave 14 r61, 2026-11-28). Replaces the earlier draft of this function (NTSC-U draft of `func_L19_0035C238`). */
/* func_L19_0035D2B8 (PAL, level 19), near miss (wave 14 r61): 133 differences (wave10/p10 check, the file's line
   -mvu0-use-vf0-vf2 -O2 -G8 -fopt-stack -mno-check-zero-division @ps2as). The previous draft was the NTSC-U twin's C
   (func_L19_0035C238) and did not compile in this file; this is the PAL C: PAL callee names, the PAL timing
   (frames as (r * 5 + 2) / 6, the -0.0012f fade, 0.32000002f), the PAL second loop (func_00382348 test,
   func_0038CF68 normalize), the file's D_001A4BE0 type and vu0.h helpers, D_L19_001D66F0[8] (rebuilt at each use as
   in retail), the D_L19_0021EED8 base set in the loop (hoisted to retail's $s7), an incrementing first loop
   (reversed by gcc to retail's bnez) and a second-loop counter of its own.
   Left: retail hoists &b of the second branch's func_0038CDF8 call into $fp (ours computes it in place), its
   bc1fl takes the else branch's first lq into the likely slot (ours: bc1f), scale *= 6 stays after the second
   func_00382498 call (ours fills the first effect call's delay slot with it), and retail re-reads *list at every use
   in the hit loop with the radius in $s3 (with *list re-read here gcc's PRE hoists the callback's high half into a
   saved register: 205). */
#include "common.h"

/* localdecomp:start func_L19_0035D2B8 */
typedef int Q_35D2B8 __attribute__((mode(TI)));
extern G_35D238 D_001A4BE0;
extern u8 D_L19_0021EED8[];
extern u8 D_L19_001D66F0[8];
extern u8 *D_L19_001ECEC0[];
__asm__(".extern D_L19_001DD8E8, 4");
extern s32 D_L19_001DD8E8;
void func_L19_0035D7D0(u8 *obj);
void func_L19_0035D2B8(u8 *m, s32 *colors) {
    extern s32 func_003C2B88(void *, s32);
    extern void func_00382580(f32, f32, void *);
    extern f32 func_L01_00443A18(f32, f32);
    extern f32 func_003824E0(f32, f32);
    extern s32 func_00382498(s32, s32);
    extern u8 *func_L01_004713C8(void *, void *, s32, u32, s32, s32, s32, f32, f32, f32, s32);
    extern void func_0038CDF8(f32, void *, void *, void *);
    extern s32 func_003D4D00(f32, void *, s32, void *, s32);
    extern s32 func_00382348(void *);
    extern void func_0038CF68(void *, void *, f32);
    extern void func_L01_00446760(void *, void *, s32, void *, f32);
    extern void func_L01_00446978(void *, void *);
    extern void func_003C4138(f32, f32, void *);
    extern void func_L01_00404A10(void *, void *);
    vu0_v4 a, b, c;
    u8 hit[48] __attribute__((aligned(16)));
    vu0_v4 *v;
    u8 *fx, *obj, **list, *eed;
    s32 count, i, j, n, r;
    f32 scale;
    count = func_003C2B88(D_001A4BE0.x25C0, 0);
    if (count) {
        for (v = (vu0_v4 *)0x70000000, i = 0; i < count; i++, v += 2) {
            eed = D_L19_0021EED8;
            if (v[1].w == 0.0f) {
                a = *v;
                a.w = 1.0f;
                func_00382580(0.0f, v->w, &b);
                vec_add_ab(&a, &a, &b);
                n = (s32)func_L01_00443A18(2.0f, 5.0f);
                scale = func_003824E0(0.7f, 1.0f) * v->w;
                r = func_00382498(10, 15);
                func_L01_004713C8(&a, D_L19_001D66F0, (r * 5 + 2) / 6, colors[0], n, 127, 127, scale * 210000.0f, 2100.0f, -0.0012f, 1);
                n = -(n * 2);
                r = func_00382498(10, 15);
                scale *= 6.0f;
                fx = func_L01_004713C8(&a, D_L19_001D66F0, (r * 5 + 2) / 6, colors[1], n, 48, 48, scale * 210000.0f, 4200.0f, -0.0012f, 0);
            } else {
                a = *v;
                b = v[1];
                a.w = 1.0f;
                b.w = 1.0f;
                scale = func_003824E0(0.0f, 1.0f);
                func_0038CDF8(scale, &c, &a, &b);
                c.x += func_003824E0(-v->w * 0.4f, v->w * 0.4f);
                c.y += func_003824E0(-v->w * 0.4f, v->w * 0.4f);
                c.z += func_003824E0(-v->w * 0.4f, v->w * 0.4f);
                n = (s32)func_L01_00443A18(2.0f, 5.0f);
                scale = func_003824E0(0.7f, 1.0f) * v->w;
                r = func_00382498(10, 15);
                func_L01_004713C8(&c, D_L19_001D66F0, (r * 5 + 2) / 6, colors[0], n, 127, 127, scale * 210000.0f, 2100.0f, -0.0012f, 1);
                n = -(n * 2);
                r = func_00382498(10, 15);
                scale *= 6.0f;
                fx = func_L01_004713C8(&c, D_L19_001D66F0, (r * 5 + 2) / 6, colors[1], n, 48, 48, scale * 210000.0f, 4200.0f, -0.0012f, 0);
            }
            if (fx)
                fx[2] = **(u8 **)(eed + 0xD4);
        }
    }
    if (D_L19_001DD8E8 == 2) {
        f32 *radius = (f32 *)(*(u8 **)(m + 0x68) + 0x2C);
        count = func_003D4D00(*radius * 0.5f, m + 0x10, 0, m, 0);
        if (count > 0)
            for (list = D_L19_001ECEC0, j = count; j; j--, list++) {
                obj = *list;
                if ((func_00382348(obj) || (*(u16 *)(obj + 0x34) & 0x4000)) && obj != (u8 *)D_001A4BE0.x25C0) {
                    vec_sub_ab(&a, obj + 0x10, (u8 *)&D_001A4BE0 + 0xE0);
                    func_0038CF68(&a, &a, 2.0f);
                    func_L01_00446760(hit, m, 0x410000, &a, 2.0f);
                    *(Q_35D2B8 *)hit = *(Q_35D2B8 *)&a;
                    *(s32 *)(hit + 0x20) = 1;
                    *(f32 *)(hit + 0xC) = 5627.9248f;
                    hit[0x18] = 10;
                    hit[0x19] = 3;
                    *(u16 *)(hit + 0x1A) = *(u16 *)(obj + 0xAA);
                    *(void **)(hit + 0x10) = m;
                    func_L01_00446978(obj, hit);
                }
            }
        func_003C4138(16.0f, 0.32000002f, radius);
    }
    func_L01_00404A10(func_L19_0035D7D0, m);
}
/* localdecomp:end func_L19_0035D2B8 */

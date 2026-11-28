/* Wave 13 (r29, 2026-11-28) replaces the earlier draft of this function (shared-2 worker draft (2026-11-16); round 12 (s4) notes). */
/* func_L32_003B58D0, wave 13 (r29): plain C under its file's own line (-O2 -G8 -fopt-stack
   -mno-check-zero-division): 213 diff positional with an injected divs row 'func_L32_003B58D0 2'
   (wave10/p10/check.py, first placement); 29 words when both sides are aligned with difflib (the
   wave 12 r04 version was 216 positional / 47 aligned). Changed against the wave 12 version: the
   table byte is read as r = D_L32_001DEEC8[func_00382498(0, 2)]; *(D_0021FAEC[0] + r) (retail's
   v1/v0 registers); the core pointer is D_0021FAEC (the name level C uses); a0+0xA is converted
   into a local before the func_L03_0034B440 call; D_L32_001DEE90 is read into r right after that
   call (retail's early gp load and the join block's load order, both exact now); the tail is
   f21 = lo; f20 = f21 + D * x * hi * (1/256) (retail's mul before the jal and add.s f20,f21,f20 in
   its delay slot). Still differs: 6.2831855f and 0.2f become .lit4 gp loads where retail has
   lui/ori/mtc1 at (SN Ps2EeAs li.s: the file needs @ps2as on its line), so every word after
   +0x74 is shifted; mtc1 zero,f21 sits inside retail's VU0 sequence (one asm block cannot take it;
   the vu0.h helpers need -mvu0-use-vf0-vf2); addiu a0,1 is scheduled six insns early before
   func_L03_0034B440; r's register (v1) gives lw v1 + move a1 and f3/f1 for the a0+0x10 sum where
   retail loads a1 directly and uses f1/f0; the 1/256 constant is loaded before D_L32_001DEEAC.
   NEEDS divs row 'func_L32_003B58D0 2' and the line '-mvu0-use-vf0-vf2 -O2 -G8 -fopt-stack
   -mno-check-zero-division @ps2as' (or a file of its own with it). */
#include "common.h"

/* localdecomp:start func_L32_003B58D0 */
extern f32 D_L32_001DEEC0;
__asm__(".extern D_L32_001DEEC0, 4");
extern f32 D_L32_001DEEC4;
__asm__(".extern D_L32_001DEEC4, 4");
extern s32 D_L32_001DEEC8[2];
__asm__(".extern D_L32_001DEEC8, 8");
extern f32 D_L32_001DEED4;
__asm__(".extern D_L32_001DEED4, 4");
extern f32 D_L32_001DEED8;
__asm__(".extern D_L32_001DEED8, 4");
extern f32 D_L32_001DEEDC;
__asm__(".extern D_L32_001DEEDC, 4");
extern s32 D_L32_001DEE90;
__asm__(".extern D_L32_001DEE90, 4");
extern s32 D_L32_001DEE94;
__asm__(".extern D_L32_001DEE94, 4");
extern s32 D_L32_001DEE98;
__asm__(".extern D_L32_001DEE98, 4");
extern f32 D_L32_001DEEB0;
__asm__(".extern D_L32_001DEEB0, 4");
extern f32 D_L32_001DEEB4;
__asm__(".extern D_L32_001DEEB4, 4");
extern f32 D_L32_001DEEAC;
__asm__(".extern D_L32_001DEEAC, 4");
extern u8 *D_0021FAEC[];
typedef struct { f32 v[4]; } __attribute__((aligned(16))) V4_003B58D0;

void func_L32_003B58D0(u8 *a0, u8 *a1) {
    extern f32 func_003824E0(f32, f32);
    extern f32 func_0038DB48(f32);
    extern f32 func_0038D098(f32);
    extern f32 func_0038D0B0(f32);
    extern s32 func_L32_003B6618(void *);
    extern void func_003C2F58(void *, s32, void *);
    extern f32 func_0038CEA8(f32 *);
    extern void func_0038CF68(f32 *, f32 *, f32);
    extern s32 func_L30_0034DBA0(s32, s32);
    extern s32 func_00382498(s32, s32);
    extern s32 func_0038DBD8(f32, s32, s32);
    extern f32 func_L03_0034B440(s32, s32, s32, f32, f32, f32);
    extern f32 func_L03_0034B148(s32, s32, f32);
    extern f32 func_003C4088(f32, f32, f32);
    f32 vec[4] __attribute__((aligned(16)));
    u8 *m;
    u8 *n;
    u8 *v;
    f32 f20;
    f32 f21;
    f32 f22;
    f32 ang;
    f32 len;
    f32 cur;
    f32 vol;
    s32 r;
    f32 f0;

    if (a1 != 0) {
        m = *(u8 **)a1;
        n = *(u8 **)(a1 + 4);
        v = *(u8 **)(m + 0x68);
        if (m != 0 && v != 0 && n != 0) {
            if (*(u16 *)(a1 + 0xA) & 1) {
                f22 = func_003824E0(0.0f, D_L32_001DEEC0);
                ang = func_0038DB48(func_003824E0(0.0f, 6.2831855f));
                vec[0] = func_0038D098(ang) * f22;
                vec[2] = func_0038D0B0(ang) * f22;
                vec[1] = 0.0f;
                r = func_L32_003B6618(m);
                if (r == -2) {
                    *(s16 *)(a0 + 0xA) = 0;
                    return;
                }
                if (r == -1) {
                    func_003C2F58(m, 1, a0 + 0x10);
                } else {
                    func_003C2F58(m, r % 8 + 2, a0 + 0x10);
                }
                __asm__("lqc2 $vf1, %1\n\tlqc2 $vf2, %2\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0"
                        : "=m"(*(V4_003B58D0 *)(a0 + 0x10)) : "m"(*(V4_003B58D0 *)(a0 + 0x10)), "m"(*(V4_003B58D0 *)vec) : "vf1", "vf2");
                *(f32 *)(a0 + 0x14) = *(f32 *)(a0 + 0x14) + D_L32_001DEEDC;
                f0 = func_003824E0(0.0f, 1.0f);
                if (D_L32_001DEEC4 < f0) {
                    f0 = func_003824E0(D_L32_001DEED8, D_L32_001DEED4);
                    *(f32 *)(a1 + 0x10) = f0 * *(f32 *)(v + 0x140);
                    *(f32 *)(a1 + 0x14) = f0 * *(f32 *)(v + 0x148);
                } else {
                    len = func_0038CEA8((f32 *)(v + 0x140));
                    func_0038CF68(vec, vec, len * func_003824E0(0.0f, 0.2f));
                    *(f32 *)(a1 + 0x10) = *(f32 *)(v + 0x140) + vec[0];
                    *(f32 *)(a1 + 0x14) = *(f32 *)(v + 0x148) + vec[2];
                }
                *(s32 *)(a1 + 0x18) = func_L30_0034DBA0(D_L32_001DEE94, D_L32_001DEE98);
                *(f32 *)(a0 + 0xC) = func_003824E0(D_L32_001DEEB4, D_L32_001DEEB0);
                a0[3] = n[0x10];
                r = D_L32_001DEEC8[func_00382498(0, 2)];
                a0[2] = *(D_0021FAEC[0] + r);
                if (func_003824E0(0.0f, 1.0f) < 0.5f) {
                    a0[3] = 0x48;
                    *(f32 *)(a0 + 0xC) = *(f32 *)(a0 + 0xC) * 1.5f;
                } else {
                    a0[3] = 0x44;
                }
            }
            cur = (f32)*(s16 *)(a0 + 0xA);
            vol = func_L03_0034B440(1, 0, 0, cur, (f32)*(s16 *)(a1 + 8), 1.0f);
            r = D_L32_001DEE90;
            *(f32 *)(a0 + 0x10) = *(f32 *)(a0 + 0x10) + *(f32 *)(a1 + 0x10);
            *(f32 *)(a0 + 0x18) = *(f32 *)(a0 + 0x18) + *(f32 *)(a1 + 0x14);
            *(s32 *)(a0 + 4) = func_0038DBD8(vol, *(s32 *)(a1 + 0x18), r);
            f21 = (f32)(*(u16 *)(a1 + 0xE) & 0xFF);
            f20 = f21 + D_L32_001DEEAC * (f32)*(s16 *)(a1 + 8) * (f32)(*(u16 *)(a1 + 0xE) >> 8) * 0.00390625f;
            f0 = func_L03_0034B148(*(s16 *)(a0 + 0xA), *(s16 *)(a1 + 8), 0.0f);
            a0[8] = (s32)func_003C4088(f21, f20, f0);
            *(f32 *)(a0 + 0xC) = *(f32 *)(a0 + 0xC) * ((f32)*(s16 *)(a0 + 0xA) / (f32)(*(s16 *)(a0 + 0xA) + 1));
        }
    }
}
/* localdecomp:end func_L32_003B58D0 */

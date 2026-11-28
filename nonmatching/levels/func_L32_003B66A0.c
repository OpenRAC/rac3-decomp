/* func_L32_003B66A0 (Claude wave 14 r67, 2026-11-28). Replaces the earlier draft of this function (shared-2 worker draft (2026-11-16), round 11 update). */
/* Wave 14 r67: unchanged C from wave 12 r02 (174 diff under the file's own line, which cannot give retail's Ps2EeAs
 * li.s lui/ori/mtc1 constants nor the interleaved VU0 add). Line analysis: the nonmatching/ draft (j-form vec_add_ab)
 * is 2 diff under the existing line '-mvu0-use-vf0-vf2 -O2 -G8 -fopt-stack -mno-check-zero-division @ps2as'
 * (config/levels/text_parts.txt: L32_003B7190.c, L32_003B7BE8.c), build/codex/wr67/func_L32_003B66A0.cut0.log. The
 * file's other C function func_L32_003B6618 MATCHes under that line too (wr67/func_L32_003B6618.cutline.log), so the
 * whole file L32_003B6618.c could take it (func_L32_003B6A58 stays INCLUDE_ASM); a cut instead would be
 * 0x003B66A0-0x003B6A58 (both 8-aligned). The 2 diff left there: first func_L03_0034B148 call of the tail, retail lh a1 then
 * mov.s f12,f20 in the delay slot, here mov.s then lh a1 (sched: lh a1 depends on the vC copy-back sq, which gives it the
 * higher priority; 13 tail variants tried: 6 statement orders of copy-back/fs/fz, result local, s16 locals, literal 0.0f,
 * index forms: all 2). */
/* Wave 12 retry r02: first plain-C version that compiles with the file's own line (-O2 -G8 -fopt-stack
 * -mno-check-zero-division): 174 diff. The existing draft (2 diff with -mvu0-use-vf0-vf2 and @ps2as added) does not
 * compile there: vu0.h's vec_add_ab needs the vu0 flag. Changed against it: the a0+0x10 += vA add is one VU0 asm block
 * (lqc2/lqc2/vadd.xyz/sqc2, vf1/vf2 clobbered); callee prototypes inside the body; the TI typedef suffixed.
 * What differs is the line, not the C: without @ps2as the non-trivial floats 3.1415927f, 6.2831855f and 0.74f are .lit4
 * lwc1 off(gp) (retail lui at/ori at/mtc1, -2 words each) and the assembler puts a nop after each of the two
 * cvt.w.s/mfc1 (+1 word each), which shift every later word; the one block also loads a0+0x10 after the vA stores
 * (retail's helper form interleaves it, 4 words reordered). With both flags the draft's 2 diff remain (first
 * func_L03_0034B148 call of the tail: lh a1 / mov.s f12 order). */
#include "common.h"

/* localdecomp:start func_L32_003B66A0 */
typedef int Q_003B66A0 __attribute__((mode(TI)));
extern f32 D_L32_001DEF44; __asm__(".extern D_L32_001DEF44, 4");
extern f32 D_L32_001DEF4C; __asm__(".extern D_L32_001DEF4C, 4");
extern f32 D_L32_001DEF48; __asm__(".extern D_L32_001DEF48, 4");
extern f32 D_L32_001DEF1C; __asm__(".extern D_L32_001DEF1C, 4");
extern f32 D_L32_001DEF64; __asm__(".extern D_L32_001DEF64, 4");
extern f32 D_L32_001DEF60; __asm__(".extern D_L32_001DEF60, 4");
extern f32 D_L32_001DEF58; __asm__(".extern D_L32_001DEF58, 4");
extern f32 D_L32_001DEF68; __asm__(".extern D_L32_001DEF68, 4");
extern s32 D_L32_001DEF30; __asm__(".extern D_L32_001DEF30, 4");
extern s32 D_L32_001DEF2C; __asm__(".extern D_L32_001DEF2C, 4");
extern s32 D_L32_001DEF28; __asm__(".extern D_L32_001DEF28, 4");
extern s32 D_L32_001DEF24; __asm__(".extern D_L32_001DEF24, 4");
extern f32 D_L32_001DEF20; __asm__(".extern D_L32_001DEF20, 4");
extern f32 D_L32_001DEF50; __asm__(".extern D_L32_001DEF50, 4");
extern f32 D_L32_001DEF18; __asm__(".extern D_L32_001DEF18, 4");
extern u8 D_L32_001E9980[];

void func_L32_003B66A0(u8 *a0, u8 *a1) {
    extern f32 func_003824E0(f32, f32);
    extern f32 func_0038DB48(f32);
    extern f32 func_0038DAB8(f32, f32);
    extern f32 func_0038D098(f32);
    extern f32 func_0038D0B0(f32);
    extern f32 func_003C4088(f32, f32, f32);
    extern void func_003C2F58(void *, s32, void *);
    extern f32 func_L03_0034B148(s32, s32, f32);
    extern s32 func_0038DBD8(f32, s32, s32);
    extern s32 func_003D3CB0(void *, void *, s32, void *, s32);
    u8 *p;
    u8 *q;
    f32 f20, f21, f22, f23, f24, f25, f26, f27;
    f32 fs, fz;
    u16 v;
    f32 vC[4];
    f32 vA[4];
    f32 vB[4];
    if (a1 != 0) {
        p = *(u8 **)a1;
        q = *(u8 **)(a1 + 4);
        if (p != 0) if (q != 0) {
            v = *(u16 *)(a1 + 0xE);
            f25 = (f32)(v & 0xFF);
            f26 = D_L32_001DEF44 * (f32)*(s16 *)(a1 + 8) * (f32)(v >> 8) * 0.00390625f;
            f27 = func_003C4088(D_L32_001DEF4C, D_L32_001DEF48, (f32)*(u8 *)(a1 + 0xC) * 0.00390625f);
            if (*(u16 *)(a1 + 0xA) & 1) {
                f21 = 0.0f;
                f24 = 1.0f;
                f23 = func_0038DAB8(func_0038DB48(func_003824E0(-D_L32_001DEF1C, D_L32_001DEF1C)), 3.1415927f);
                f22 = func_003824E0(D_L32_001DEF64, D_L32_001DEF60);
                f20 = func_0038DB48(func_003824E0(f21, 6.2831855f));
                func_003C2F58(p, 0, a0 + 0x10);
                vA[0] = func_0038D098(f20) * D_L32_001DEF58;
                vA[2] = func_0038D0B0(f20) * D_L32_001DEF58;
                vA[1] = f21;
                __asm__("lqc2 $vf2, %1\n\tlqc2 $vf1, %2\n\tvadd.xyz $vf2, $vf2, $vf1\n\tsqc2 $vf2, %0"
                        : "=m"(*(Q_003B66A0 *)(a0 + 0x10))
                        : "m"(*(Q_003B66A0 *)(a0 + 0x10)), "m"(*(Q_003B66A0 *)vA)
                        : "vf1", "vf2");
                *(f32 *)(a0 + 0x14) += D_L32_001DEF68;
                vB[0] = func_0038D098(f23) * f22;
                vB[2] = func_0038D0B0(f23) * f22;
                *(f32 *)(a1 + 0x10) = vB[0];
                vB[1] = f21;
                *(f32 *)(a1 + 0x14) = vB[2];
                *(s32 *)(a1 + 0x18) = func_0038DBD8(func_003824E0(f21, f24), D_L32_001DEF30, D_L32_001DEF2C);
                *(s32 *)(a1 + 0x1C) = func_0038DBD8(func_003824E0(f21, f24), D_L32_001DEF28, D_L32_001DEF24);
            }
            *(f32 *)(a1 + 0x14) += D_L32_001DEF20;
            *(Q_003B66A0 *)vC = *(Q_003B66A0 *)(a0 + 0x10);
            vC[0] += *(f32 *)(a1 + 0x10);
            vC[2] += *(f32 *)(a1 + 0x14);
            if (func_003D3CB0(a0 + 0x10, vC, 1, p, 0) != 0) {
                u8 *g = D_L32_001E9980;
                if (*(s32 *)(g + 0x18) != 0) {
                    f32 z = vC[2];
                    f32 d = *(f32 *)(a1 + 0x10) * 0.74f;
                    vC[0] = *(f32 *)(a0 + 0x10) + d;
                    vC[2] = (*(f32 *)(a0 + 0x14) <= *(f32 *)(g + 0x24)) ? z - d : z + d;
                }
            }
            *(Q_003B66A0 *)(a0 + 0x10) = *(Q_003B66A0 *)vC;
            fs = f25 + f26;
            fz = 0.0f;
            *(f32 *)(a0 + 0xC) = func_003C4088(D_L32_001DEF50, f27, func_L03_0034B148(*(s16 *)(a0 + 0xA), *(s16 *)(a1 + 8), fz));
            *(s32 *)(a0 + 4) = func_0038DBD8(func_L03_0034B148(*(s16 *)(a0 + 0xA), *(s16 *)(a1 + 8), fz), *(s32 *)(a1 + 0x18), *(s32 *)(a1 + 0x1C));
            *(s32 *)(a0 + 4) = (*(s32 *)(a0 + 4) & 0xFFFFFF) + ((s32)(func_L03_0034B148(*(s16 *)(a1 + 8) - *(s16 *)(a0 + 0xA), *(s16 *)(a1 + 8), D_L32_001DEF18) * 128.0f) << 24);
            *(u8 *)(a0 + 8) = (s32)func_003C4088(f25, fs, func_L03_0034B148(*(s16 *)(a0 + 0xA), *(s16 *)(a1 + 8), fz));
        }
    }
}
/* localdecomp:end func_L32_003B66A0 */

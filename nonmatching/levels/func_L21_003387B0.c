/* func_L21_003387B0: 195 diff with the file's flags (needs --flags "-mvu0-use-vf0-vf2 ..." for vec_add_ba; frame size 0xA0 matches, structure matches). Differs: retail keeps 0.0 in $f23 (v.z and arg of func_003824E0) where mine folds to sw $zero; retail hoists &D_L21_001D66B0 into $fp and the D_L21_0021B860 base into $s7 after loop A (mine: $s6 at entry). Tried: no extra locals, zero var, do-while nest.
   Round 12: the file's line has `-mno-split-addresses`; compiling the same C in split mode (check.py --mode S, what the
   file's line would be without that flag) gives 161 diff instead of 195, the head then matches except `found`/`p` ($s0/$s1
   swapped) and f23. Retail's $f23 = 0.0 survives because the pseudo has more than one set; giving `zero` a second assignment
   (before the outer loop, at function entry, inside the inner loop) does not change the output (161 in split mode, 193-195
   in -mno-split-addresses mode): the single-set constant is still replaced by $zero / mtc1 at each use. In split mode
   five hoisted address pseudos are spilled by global allocation ($-1 in the -dlg table: the arg, two address bases, 128 and
   136), which is retail's $fp/$s7 hoists done differently. */
#include "common.h"

#include "vu0.h"
extern s32 func_L01_0043B568(s32, s32, s32);
extern f32 func_003824E0(f32, f32);
extern f32 func_00382538(void);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern f32 func_0038CF38(void *, void *);
extern f32 func_0038D160(f32, f32);
extern f32 func_003C3D30(void *, s32, s32, f32);
extern void func_L21_00337BF0(void *);
extern u8 D_001A4C60[];
extern u8 D_001A4BE0[];
__asm__(".extern D_L21_001D66B0, 16");
extern vu0_v4 D_L21_001D66B0;
extern u16 *D_L21_0021B860[];
extern u8 *D_L21_001DED9C;
__asm__(".extern D_L21_001DED9C, 16");
extern s32 D_L21_001DEDD8;
__asm__(".extern D_L21_001DEDD8, 4");
extern f32 D_L21_001DCF40;
__asm__(".extern D_L21_001DCF40, 4");

void func_L21_003387B0(void *arg0)
{
    u8 *s;
    u8 *r;
    u8 *e;
    u16 *p;
    s32 found;
    s32 hit;
    f32 zero;
    f32 a;
    f32 d;
    vu0_v4 v;
    vu0_v4 rot;

    s = *(u8 **)((u8 *)arg0 + 0x68);
    r = (u8 *)func_L01_0043B568(0x1C18, 0, 0x44);
    if (r == 0) return;
    if (s[0x7E] == 0) return;
    do {
        found = 0;
        for (p = D_L21_0021B860[*(s32 *)(s + 0x28)];
             (*(s32 *)(s + 0x28) & 0xFF) != 0xFF && *(s32 *)(s + 0x28) <= D_L21_001DEDD8 && p != 0 &&
             ((s16)p[-1] >= 0 || p == D_L21_0021B860[*(s32 *)(s + 0x28)]);
             p++) {
            e = D_L21_001DED9C + ((*p & 0x7FFF) << 8);
            if (e == 0) break;
            if (((s32 (*)(u8 *))(*(void **)(r + 0x1C)))(e) == 1) {
                found = 1;
                break;
            }
        }
        if (found == 0) break;
        zero = 0.0f;
        do {
            do {
                a = func_003824E0(zero, 4.0f);
                d = func_00382538();
                v.x = func_0038D098(d) * a;
                v.y = func_0038D0B0(d) * a;
                v.z = zero;
                vec_add_ba(&v, &v, &D_L21_001DCF40);
            } while (func_0038CF38(&v, D_001A4C60) < 0.6f);
            hit = 0;
            for (p = D_L21_0021B860[*(s32 *)(s + 0x28)];
                 (*(s32 *)(s + 0x28) & 0xFF) != 0xFF && *(s32 *)(s + 0x28) <= D_L21_001DEDD8 && p != 0 &&
                 ((s16)p[-1] >= 0 || p == D_L21_0021B860[*(s32 *)(s + 0x28)]);
                 p++) {
                u8 *m = D_L21_001DED9C + ((*p & 0x7FFF) << 8);
                if (m == 0) break;
                if (((s32 (*)(u8 *))(*(void **)(r + 0x1C)))(m) == 3) {
                    if (func_0038CF38(&v, m + 0x10) < 0.6f) {
                        hit = 1;
                        break;
                    }
                }
            }
        } while (hit);
        v.z = func_003C3D30(&v, 0, 0, 0.5f);
        rot = D_L21_001D66B0;
        {
            u8 *cam = *(u8 **)(D_001A4BE0 + 0x25C0);
            rot.z = func_0038D160(*(f32 *)(cam + 0x10) - *(f32 *)(e + 0x10),
                                  *(f32 *)(cam + 0x14) - *(f32 *)(e + 0x14));
        }
        ((void (*)(u8 *, s32, void *, void *))(*(void **)(r + 0xC)))(e, 3, &v, &rot);
        ((void (*)(u8 *, s32))(*(void **)(r + 0x18)))(e, 3);
        ((void (*)(u8 *, s32))(*(void **)(r + 0x10)))(e, 1);
        func_L21_00337BF0(arg0);
    } while (s[0x7E] != 0);
}

INCLUDE_ASM("asm/levels", func_L21_003387B0);

/* near miss (level 3, Starship Phoenix): 2 differences: in the delay slot of the jal to func_L01_00448890 retail has `move $a2,$zero; jal; mov.s $f12,$f0`, the C emits `mov.s $f12,$f0; jal; move $a2,$zero`; needs @ps2as (now set on L03_0039E470.c); zero-argument type, prototype order, indexing and inlined calls tried */
#include "common.h"

/* localdecomp:start func_L03_0039EE10 */
extern void func_L03_0032FAF0(f32 *out, f32 *in, f32 angle, f32 radius);
extern f32 func_0038D160(f32, f32);
extern void func_L01_00448890(u8 *a0, u8 *a1, f32 f12, f32 f13, f32 f14, f32 f15, s32 a2);
extern f32 func_0038DB00(f32, f32);
extern f32 func_L03_0032DC08(s32, void *, f32, f32 *);
extern s32 func_L01_0045A7A8(void *, f32 *, f32);
extern void func_L03_0032D6B8(void *);

void func_L03_0039EE10(u8 *a, f32 r) {
    u8 *b = a + 0xF8;
    u8 *s = *(u8 **)(a + 0x68);
    f32 t;
    f32 d;
    func_L03_0032FAF0((f32 *)(s + 0x2F0), (f32 *)(s + 0x130), *(f32 *)(s + 0x264), r);
    t = func_0038D160(*(f32 *)(s + 0x130) - *(f32 *)(a + 0x10), *(f32 *)(s + 0x134) - *(f32 *)(a + 0x14));
    func_L01_00448890(b, s + 0x204, t, *(f32 *)(s + 0x164), *(f32 *)(s + 0x168), *(f32 *)(s + 0x16C), 0);
    d = func_0038DB00(*(f32 *)(s + 0x260), *(f32 *)(s + 0x264));
    d = func_L03_0032DC08(*(s32 *)(s + 0x250), a, d * 0.15f, (f32 *)(s + 0x2F0));
    func_L01_0045A7A8(a, (f32 *)(s + 0x2F0), d);
    func_L03_0032D6B8(a);
}
/* localdecomp:end func_L03_0039EE10 */

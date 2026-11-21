/* PAL near miss (haiku-w5): 8 words differ with the file's flags. Retail computes brightness < 32 (slti) before the -0.00075f constant load, and loads color (lw) before the 0.025f constant with the and before the jal; every ordering tried (ternary, if/else, named constants, color placed earlier or later, masked argument) left 8 or more. The data alias D_L01_002C5600_004730F8 avoids the file's Stream_472F58 declaration of the same address (conflicting types otherwise). */
/* PAL near miss (Codex wave 8): near miss: 8 words differ with the file's flags.
 * Worker's note: 8 word differences; build/codex/w455/func_L01_004730F8.01.log. Comparison vs negative-float materialization order, mask-lui vs color load, and func_0038DBD8 argument delay slot. Signed color/explicit default and typed color-union forms preserve residual; ...
 */
#include "common.h"
/* localdecomp:start func_L01_004730F8 */
typedef struct { f32 x,y,z,w; } __attribute__((aligned(16))) V_004730F8;
extern u8 D_001425D1[];
typedef struct { u8 pad0; u8 kind; u8 pad[0xEE]; } Entry_004730F8;
extern Entry_004730F8 D_L01_002C5600_004730F8[];
void func_L01_004730F8(u8 *obj) {
    extern void func_L01_004CAB30(void *, void *);
    extern void func_0038CE20(void *, void *, f32);
    extern void func_L01_004C7D98(void *, void *);
    extern s32 func_0038DBD8(s32, s32, f32);
    extern void func_003CD250(u8 *);
    V_004730F8 noise;
    u8 *state;
    u8 *pos;
    s32 brightness;
    u32 color;
    f32 strength;
    func_L01_004CAB30(obj + 0x10, obj + 0x10);
    state = obj + 0x20;
    if (((Entry_004730F8 *)((D_001425D1[0] * 0xF0) + (s32)D_L01_002C5600_004730F8))->kind >= 4) *(s32 *)(state + 0x10) -= 2;
    else *(s32 *)(state + 0x10) -= 1;
    if (*(s32 *)(state + 0x10) < 0) *(s32 *)(state + 0x10) = 0;
    obj[8]++;
    pos = obj + 0x10;
    __asm__("lqc2 $vf2, %0\n\tlqc2 $vf1, %1\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0" : "+m"(*(V_004730F8 *)(obj + 0x10)) : "m"(*(V_004730F8 *)state) : "vf1", "vf2");
    *(f32 *)(obj + 0xC) += 1575.0f;
    func_0038CE20(state, state, 0.99f);
    func_L01_004C7D98(pos, &noise);
    brightness = obj[4];
    strength = brightness < 32 ? 0.0015f : -0.00075f;
    func_0038CE20(&noise, &noise, strength);
    __asm__("lqc2 $vf1, %0\n\tlqc2 $vf2, %1\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0" : "+m"(*(V_004730F8 *)state) : "m"(noise) : "vf1", "vf2");
    color = *(u32 *)(obj + 4);
    color &= 0xFFFFFF;
    color = func_0038DBD8(color, 0, 0.025f);
    *(s32 *)(obj + 4) = color | (*(s32 *)(state + 0x10) << 24);
    if (*(s32 *)(state + 0x10) == 0) func_003CD250(obj);
}
/* localdecomp:end func_L01_004730F8 */

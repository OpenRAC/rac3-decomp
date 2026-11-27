#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void (*D_001D9A40[2])(s32);
extern void (*D_001D9A40_00382B20[1])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
extern void func_0038CC88_00391678(void *, void *, s32) __asm__("func_0038CC88");
extern void func_003C5250(void *);
extern void func_003C5320(s32, s32, s32);
extern void func_003C5458(void *, s32, f32, f32);
/* --- end of declarations from other files --- */

/* declarations of 3C4B40.c's earlier functions */
extern f32 func_0038CEA8(s32 a);
extern void func_0038CF68(s32 a, s32 b, f32 x);
extern f32 func_003824E0(f32, f32);
extern void func_0038CE20(f32 *, void *, f32);
extern void func_003C4E80(void *a, void *b);
extern f32 func_003C50E8(s32 a, s32 b, s32 c);

/* localdecomp:start func_003C5250 */
extern void func_003C5180(void *);
 
void func_003C5250(void *p) {
    func_003C5180((u8 *)p + 0x10);
}
/* localdecomp:end func_003C5250 */

LINKER_REMNANT("asm/remnants", func_003C5270);

/* localdecomp:start func_003C5278 */
extern s32 D_001D5BEC[];
extern void func_003C5180_003C5278();
extern void func_0038CF68(s32, s32, f32);
void func_003C5278(void *a0, f32 *out, f32 *in, f32 f) {
    f32 v[4];
    if (D_001D5BEC[0] == 0) {
        out[2] = in[2] - f;
    } else {
        func_003C5180_003C5278(a0, v, 0);
        func_0038CF68((s32)v, (s32)v, f);
        __asm__ __volatile__(
            "lqc2 $vf1, 0(%1)\n"
            "lqc2 $vf2, 0(%2)\n"
            "vadd.xyz $vf1, $vf1, $vf2\n"
            "sqc2 $vf1, 0(%0)\n"
            : : "r"(out), "r"(in), "r"(v) : "memory");
    }
}
/* localdecomp:end func_003C5278 */

/* localdecomp:start func_003C52F8 */
extern void func_003C5278_003C52F8(void *);
 
void func_003C52F8(void *p) {
    func_003C5278_003C52F8((u8 *)p + 0x10);
}
/* localdecomp:end func_003C52F8 */

LINKER_REMNANT("asm/remnants", func_003C5318);

/* localdecomp:start func_003C5320 */
extern void func_0038CE20(f32 *, void *, f32);
extern void func_003C5370(s32, f32 *, s32);
void func_003C5320(s32 a, s32 b, s32 c) {
    f32 buf[4];
    ((void (*)(f32 *, f32))func_0038CE20)(buf, -1.0f);
    func_003C5370(a, buf, c);
}
/* localdecomp:end func_003C5320 */

extern void func_0038CE90(f32 *, f32 *, s32);
extern void func_0038D810(f32 *, f32 *);
extern void func_0038D5F0(s32, f32 *, s32);
extern void func_0038CC88(s32, f32 *, s32);
/* localdecomp:start func_003C5370 */
#include "vu0.h"

void func_003C5370(s32 a0, f32 *a1, s32 a2)
{
    float buf[12];
    float m[4];
    float q[4];
    float x;
    func_0038CF68(q, a1, 1.0f);
    func_0038CE90(m, q, (char *)a0 + 32);
    func_0038CE20(m, m, 0.5f);
    x = func_0038CEA8(m);
    m[3] = -sqrt_asm(1.0f - x * x);
    func_0038D810(m, buf);
    func_0038D5F0((void *)a0, buf, (void *)a0);
    if (a2 != 0)
        func_0038CC88((void *)a2, buf, 48);
}
/* localdecomp:end func_003C5370 */

LINKER_REMNANT("asm/remnants", func_003C5448);

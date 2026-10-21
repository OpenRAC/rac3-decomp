#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void (*D_001D9A40[2])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
extern void func_003C5810(void *, s32, f32, f32);
/* --- end of declarations from other files --- */

/* declarations of 3C4D90.c's earlier functions (tools/port_from_us.py) */
extern s32 func_003C4EF8_003C4F08(s16);
extern u32 D_001DA49C[];
extern u32 D_001DA4A4[];
extern f32 func_0038D288(s32 a);
extern void func_0038D348(s32 a, s32 b, f32 x);
extern f32 func_003828C0(f32, f32);
extern void func_0038D348(s32 a, s32 b, f32 x);
typedef int u128_3BF838 __attribute__((mode(TI)));
typedef struct { u128_3BF838 r[4]; } M_3BF838;
extern void func_0038D708();
extern void func_0038D990();
extern void func_0038DA20();
extern void func_003C4C60();
extern s32 func_0038D438(f32 *);
typedef struct { u8 pad[0x40]; } M_3BFAF8;
void func_0038D990(M_3BFAF8 *, void *);
void func_0038D3E0(void *, void *, M_3BFAF8 *);
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_3BFBA8;
typedef int Q_3BFBA8 __attribute__((mode(TI)));
extern f32 D_001D5C00;
extern void func_0038D200(f32 *, void *, f32);
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_3BFC18;
typedef int Q_3BFC18 __attribute__((mode(TI)));
extern s32 D_001D5BEC_003C5538;
extern s32 D_001D5BF0;
typedef struct { u8 p0[0xB0]; V4_3BFC18 v; } S_3BFC18;
extern S_3BFC18 D_001A4BE0;
extern void func_0038D200(f32 *, void *, f32);
extern void func_003C54C8(void *, void *, s32);

/* localdecomp:start func_003C5608 */
extern void func_003C5538(void *);
 
void func_003C5608(void *p) {
    func_003C5538((u8 *)p + 0x10);
}
/* localdecomp:end func_003C5608 */

LINKER_REMNANT("asm/boot_elf/remnants", func_003C5628);

/* localdecomp:start func_003C5630 */
extern s32 D_001D5BEC[];
extern void func_003C5538_003C5630();
extern void func_0038D348(s32, s32, f32);
void func_003C5630(void *a0, f32 *out, f32 *in, f32 f) {
    f32 v[4];
    if (D_001D5BEC[0] == 0) {
        out[2] = in[2] - f;
    } else {
        func_003C5538_003C5630(a0, v, 0);
        func_0038D348((s32)v, (s32)v, f);
        __asm__ __volatile__(
            "lqc2 $vf1, 0(%1)\n"
            "lqc2 $vf2, 0(%2)\n"
            "vadd.xyz $vf1, $vf1, $vf2\n"
            "sqc2 $vf1, 0(%0)\n"
            : : "r"(out), "r"(in), "r"(v) : "memory");
    }
}
/* localdecomp:end func_003C5630 */

/* localdecomp:start func_003C56B0 */
extern void func_003C5630_003C56B0(void *);
 
void func_003C56B0(void *p) {
    func_003C5630_003C56B0((u8 *)p + 0x10);
}
/* localdecomp:end func_003C56B0 */

LINKER_REMNANT("asm/boot_elf/remnants", func_003C56D0);

/* localdecomp:start func_003C56D8 */
extern void func_0038D200(f32 *, void *, f32);
extern void func_003C5728(s32, f32 *, s32);
void func_003C56D8(s32 a, s32 b, s32 c) {
    f32 buf[4];
    ((void (*)(f32 *, f32))func_0038D200)(buf, -1.0f);
    func_003C5728(a, buf, c);
}
/* localdecomp:end func_003C56D8 */

extern void func_0038D270(f32 *, f32 *, s32);
extern void func_0038DBF0(f32 *, f32 *);
extern void func_0038D9D0(s32, f32 *, s32);
extern void func_0038D068(s32, f32 *, s32);
INCLUDE_ASM("asm/boot_elf/nonmatchings/text", func_003C5728);

LINKER_REMNANT("asm/boot_elf/remnants", func_003C5800);

INCLUDE_ASM("asm/boot_elf/nonmatchings/text", func_003C5810);

INCLUDE_ASM("asm/boot_elf/nonmatchings/text", func_003C59D8);

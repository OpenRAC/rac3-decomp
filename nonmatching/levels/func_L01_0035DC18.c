/* PAL near miss (Codex wave 7): near miss: 10 words differ with the file's flags.
 * Worker's note: 10 instruction diffs; build/codex/w361/func_L01_0035DC18.a1.log; two prologue instructions swapped and four a0 moves placed after sqc2 instead of inside each VU sequence. Scalar TI, existing vector struct, and read-write memory operand formulations repeat the ...
 */
#include "common.h"
/* localdecomp:start func_L01_0035DC18 */
extern s32 D_L01_001DD6E8;
__asm__(".extern D_L01_001DD6E8, 4");
void func_L01_0035DC18(u8 *m) {
    extern s32 func_L01_004CB2D8(u8 *);
    extern void func_L01_004CAB30(void *, void *);
    extern f32 func_0038DAB8(f32, f32);
    extern void func_L01_0035E010(u8 *);
    extern void func_L01_0035E488(u8 *);
    extern f32 func_003824E0(f32, f32);
    extern void func_0038CF68(void *, void *, f32);
    extern u8 *func_L01_003C27E0(u8 *, void *);
    extern void func_L01_004450F0(void *, s32, s32);
    s128 position;
    u8 *agent;
    u8 *hero;
    if (func_L01_004CB2D8(m)) func_L01_004CAB30(m+0x10,m+0x10);
    switch (m[0x20]) {
    case 0:
        *(f32 *)(m+0xF0) = func_0038DAB8(*(f32 *)(m+0xF0),0.08377581089735031f);
        *(f32 *)(m+0xF4) = func_0038DAB8(*(f32 *)(m+0xF4),0.22689281404018402f);
        func_L01_0035E010(m);
        break;
    case 2:
        if (D_L01_001DD6E8 >= 8) goto finished;
        hero = D_001A4BE0;
        position = *(s128 *)(*(u8 **)(hero+0x25C0)+0xC0);
        func_0038CF68(&position,&position,func_003824E0(0.25f,0.75f));
        __asm__("lqc2 $vf2, %1\n\t"
                "lqc2 $vf1, %2\n\t"
                "vadd.xyz $vf1, $vf1, $vf2\n\t"
                "sqc2 $vf1, %0"
                : "=m"(position)
                : "m"(position), "m"(*(s128 *)(m+0x10))
                : "vf1", "vf2");
        agent = func_L01_003C27E0(m,&position);
        if (agent) *(s32 *)(agent+0xB8) = *(s32 *)(m+0xB8);
        D_L01_001DD6E8++;
        if (D_L01_001DD6E8 >= 8) goto finished;
        position = *(s128 *)(*(u8 **)(hero+0x25C0)+0xC0);
        func_0038CF68(&position,&position,-func_003824E0(0.25f,0.75f));
        __asm__("lqc2 $vf2, %1\n\t"
                "lqc2 $vf1, %2\n\t"
                "vadd.xyz $vf1, $vf1, $vf2\n\t"
                "sqc2 $vf1, %0"
                : "=m"(position)
                : "m"(position), "m"(*(s128 *)(m+0x10))
                : "vf1", "vf2");
        agent = func_L01_003C27E0(m,&position);
        if (agent) *(s32 *)(agent+0xB8) = *(s32 *)(m+0xB8);
        D_L01_001DD6E8++;
        if (D_L01_001DD6E8 >= 8) goto finished;
        position = *(s128 *)(*(u8 **)(hero+0x25C0)+0xD0);
        func_0038CF68(&position,&position,func_003824E0(0.25f,0.75f));
        __asm__("lqc2 $vf2, %1\n\t"
                "lqc2 $vf1, %2\n\t"
                "vadd.xyz $vf1, $vf1, $vf2\n\t"
                "sqc2 $vf1, %0"
                : "=m"(position)
                : "m"(position), "m"(*(s128 *)(m+0x10))
                : "vf1", "vf2");
        agent = func_L01_003C27E0(m,&position);
        if (agent) *(s32 *)(agent+0xB8) = *(s32 *)(m+0xB8);
        D_L01_001DD6E8++;
        if (D_L01_001DD6E8 >= 8) goto finished;
        position = *(s128 *)(*(u8 **)(hero+0x25C0)+0xD0);
        func_0038CF68(&position,&position,-func_003824E0(0.25f,0.75f));
        __asm__("lqc2 $vf2, %1\n\t"
                "lqc2 $vf1, %2\n\t"
                "vadd.xyz $vf1, $vf1, $vf2\n\t"
                "sqc2 $vf1, %0"
                : "=m"(position)
                : "m"(position), "m"(*(s128 *)(m+0x10))
                : "vf1", "vf2");
        agent = func_L01_003C27E0(m,&position);
        if (agent) *(s32 *)(agent+0xB8) = *(s32 *)(m+0xB8);
        D_L01_001DD6E8++;
finished:
        func_L01_004450F0(m,1,-1);
        break;
    case 1:
        func_L01_0035E488(m);
        break;
    }
}
/* localdecomp:end func_L01_0035DC18 */

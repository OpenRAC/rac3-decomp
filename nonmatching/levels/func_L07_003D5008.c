/* PAL near miss (Codex wave 8): near miss: 35 words differ with the file's flags.
 * Worker's note: 34 diff: build/codex/w400/func_L07_003D5008.05.log; fixed assembler emits gp literal instead of retail inline 0x3FA0D97C; VU sequence scheduling and loop constant order remain. No flag changes.
 */
#include "common.h"
/* localdecomp:start func_L07_003D5008 */
typedef int DI_003D5008 __attribute__((mode(DI)));
typedef struct { f32 x,y,z,w; } __attribute__((aligned(16))) Vec_003D5008;
void func_L07_003D5008(u8 *m) {
    extern u8 *func_003C24B0(s32, s32);
    extern f32 func_0038D098(f32);
    extern f32 func_0038D0B0(f32);
    extern f32 func_0038DAB8(f32, f32);
    extern void func_003C7C38(u8 *);
    extern void func_L07_003D5170(u8 *);
    Vec_003D5008 v;
    u8 *d, *n, **out;
    s32 i;
    f32 angle;
    s32 one, three;
    if (m[0x20] == 0) {
        d = *(u8 **)(m+0x68);
        angle = 0.0f;
        out = (u8 **)(d+0x10);
        i=4;
        do {
            one=1; three=3;
            n = func_003C24B0(0x1c24,0x80);
            if (n) {
                n[0x31]=one;
                *(u16 *)(n+0x32)=*(u16 *)(m+0x32);
                n[0x30]=m[0x30];
                *(DI_003D5008 *)(n+0x38)=*(DI_003D5008 *)(m+0x38);
                v.x=func_0038D098(angle)*6.0f;
                v.y=func_0038D0B0(angle)*6.0f;
                v.z=0.0f;
                __asm__("lqc2 $vf2, %1\n\tlqc2 $vf1, %2\n\tvadd.xyz $vf2, $vf2, $vf1\n\tsqc2 $vf2, %0"
                    : "=m"(*(Vec_003D5008 *)(n+0x10))
                    : "m"(*(Vec_003D5008 *)(m+0x10)), "m"(v) : "vf1", "vf2");
                *(u16 *)(n+0x34) |= 0x20;
                {
                    u8 *p=*(u8 **)(n+0x68);
                    *(f32 *)(n+0xf8)=angle;
                    *(u16 *)(n+0x7c)=three;
                    *(u8 **)(p+8)=p+0x30;
                    func_003C7C38(n);
                }
            }
            *out++=n;
            angle=func_0038DAB8(angle,1.2566371f);
        } while (--i >= 0);
        *(u16 *)(m+0x34) |= 0x41;
        *(void (**)(u8 *))(d+4)=func_L07_003D5170;
        func_L07_003D5170(m);
    }
}
/* localdecomp:end func_L07_003D5008 */

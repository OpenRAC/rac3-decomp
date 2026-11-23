/* PAL near miss (haiku-w1): 130 words differ with the file's flags (-O2 -G8 -fopt-stack -mno-check-zero-division @ps2as); the VU0 sequences need j-form operands (-mvu0-use-vf0-vf2 is not on the file line), and the one-block volatile-free asm with a memory clobber keeps the stores in order. */
#include "common.h"
/* localdecomp:start func_L01_004C8DD0 */
extern Vec4_004C4AD8 D_L01_001E21C0[];
extern Vec4_004C4AD8 D_L01_001E21D0;
extern Vec4_004C4AD8 D_L01_001E21E0;
extern Vec4_004C4AD8 D_L01_001E2420;
__asm__(".extern D_L01_001D6694, 4");
void func_L01_004C8DD0(void) {
    extern s32 func_L01_004BA800(void);
    extern void func_0038D890(Vec4_004C4AD8 *, Vec4_004C4AD8 *, Vec4_004C4AD8 *, f32);
    Vec4_004C4AD8 dir, a, b;
    u8 *p=(u8 *)&D_001A4BE0;
    s32 i;
    Vec4_004C4AD8 *extra=&D_L01_001E2420;
    s32 state=*(s32 *)(p+0x25C4);
    if (state==7 || state==11 || state==14 || state==20 || D_L01_001D6694==6) return;
    if (func_L01_004BA800()) return;
    if (*(s32 *)(p+0x25C4)==101 || *(s32 *)(p+0x25C4)==116) return;
    dir=*(Vec4_004C4AD8 *)((*(u8 **)(p+0x25C0))+0xD0);
    a=*(Vec4_004C4AD8 *)((*(u8 **)(p+0x25C0))+0xC0);
    func_0038CF68(&a,&a,-1.0f);
    __asm__("lqc2 $vf2, %1\n\tlqc2 $vf1, %2\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0"
      : "=m"(a) : "m"(a), "m"(*(Vec4_004C4AD8 *)(p+0x80)) : "vf1","vf2", "memory");
    b=*(Vec4_004C4AD8 *)((*(u8 **)(p+0x25C0))+0xC0);
    func_0038CF68(&b,&b,-0.5f);
    __asm__("lqc2 $vf2, %1\n\tlqc2 $vf1, %2\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0"
      : "=m"(b) : "m"(b), "m"(*(Vec4_004C4AD8 *)(p+0x80)) : "vf1","vf2", "memory");
    for(i=0;i<4;i++) {
        func_0038D890(&dir,&dir,(Vec4_004C4AD8 *)((*(u8 **)(p+0x25C0))+0xC0),0.6283185482f);
        if(i==0 || i==3) {
            func_0038CF68(&dir,&dir,1.475f);
            __asm__("lqc2 $vf1, %1\n\tlqc2 $vf2, %2\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0"
              : "=m"(D_L01_001E21C0[i]) : "m"(b), "m"(dir) : "vf1","vf2", "memory");
        } else if(i==1) {
            func_0038CF68(&dir,&dir,2.0f);
            __asm__("lqc2 $vf1, %1\n\tlqc2 $vf2, %2\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0"
              : "=m"(D_L01_001E21D0) : "m"(a), "m"(dir) : "vf1","vf2", "memory");
            if(*(s32 *)(p+0x16B0)==i) {
                func_0038CF68(&dir,&dir,0.8f);
                __asm__("lqc2 $vf1, %1\n\tlqc2 $vf2, %2\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0"
                  : "=m"(D_L01_001E2420) : "m"(a), "m"(dir) : "vf1","vf2", "memory");
            } else {
                *extra=D_L01_001E21D0;
            }
        } else if (i==2) {
            func_0038CF68(&dir,&dir,2.2f);
            __asm__("lqc2 $vf1, %1\n\tlqc2 $vf2, %2\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0"
              : "=m"(D_L01_001E21E0) : "m"(a), "m"(dir) : "vf1","vf2", "memory");
        }
    }
}

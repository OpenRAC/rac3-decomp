/* functional: high. 8 jals identical to retail, same instruction multiset; only reg alloc, float constant loads (lui/ori vs pool) and frame size differ; the always-0x50 alpha makes particle[3]=0x44 as in retail; VU0 sub/add via lqc2/vsub/vadd inline asm */
#include "common.h"
#include "vu0.h"
extern u8 *D_L01_00221098[];
extern u8 D_001A4EC0[];
extern s32 D_L01_001DDD80;
extern s32 D_L01_001DDD84;
void func_L01_00384F48(u8 *m, vu0_q *input) {
    extern void func_0038CF68(void *, void *, f32);
    extern void func_0038CE20(u128_384E68 *, u128_384E68 *, f32);
    extern f32 func_L01_00443A18(f32, f32);
    extern f32 func_003824E0(f32, f32);
    extern s32 func_00382498(s32, s32);
    extern u8 func_0013D3E0(void);
    extern u8 *func_L01_0046A610(void *, void *, s32, s32, s32, s32, f32, f32, f32, f32, f32);
    vu0_q v[4];
    f32 distance = *(f32 *)(*(u8 **)(m+0x68)+0x18);
    s32 count, spin, life, color, alpha;
    f32 size;
    u8 *particle;
    v[0]=*input;
    v[2]=v[0];
    count=(s32)(distance/0.1f)/4;
    __asm__("lqc2 $vf2, %1\n\tlqc2 $vf1, %2\n\tvsub.xyz $vf2, $vf2, $vf1\n\tsqc2 $vf2, %0" : "=m"(v[3]) : "m"(*(vu0_q *)(m+0x10)), "m"(v[0]) : "vf1", "vf2");
    func_0038CF68(&v[3],&v[3],distance/count);
    if (count>0) {
    s32 remaining=count;
    do {
        spin=(s32)func_L01_00443A18(1.0f,3.0f);
        func_0038CE20((u128_384E68 *)&v[1],(u128_384E68 *)D_001A4EC0,-(func_003824E0(0.2f,1.0f)*0.0200000014f));
        life=func_00382498(30,50);
        size=func_003824E0(200.0f,1000.0f);
        if (func_0013D3E0() & 2) { alpha=80; color=0x404040; }
        else { alpha=80; color=0x7F7F7F; }
        particle=func_L01_0046A610(&v[2],&v[1],(life*5+2)/6,alpha,color,spin,21000.0f,size,1.0f,0.0f,1.0f);
        __asm__("lqc2 $vf1, %0\n\tlqc2 $vf2, %1\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0" : "+m"(v[2]) : "m"(v[3]) : "vf1", "vf2");
        if (particle) {
            particle[2]=D_L01_00221098[D_L01_001DDD80][D_L01_001DDD84];
            particle[3]=alpha==64?0x48:0x44;
        }
    } while (--remaining);
    }
}

/* PAL near miss, 2026-11-16 (P05): measured with owning-file flags
 * -mvu0-use-vf0-vf2 -O2 -G8 -fopt-stack -mno-check-zero-division @ps2as.
 * Reconstructed from retail. Pointer-array declaration for the collision
 * object restores its lui/lw access; naming speed restores the frame
 * store's call delay slot. The contiguous second vector subtraction is
 * one real VU0 sequence. Residual: entry global loads, prologue scheduling
 * and first VU0/quadword-copy register ordering. No ordinary EE asm,
 * barriers, flag overrides or new transforms. Not promoted or full-built.
 */
#include "common.h"
#include "vu0.h"
extern vu0_v4 D_001A4CB0, D_L20_001E9BE0;
extern s32 D_L20_001DFD40;
extern s32 D_001DEBA8_sda;
__asm__(".extern D_001DEBA8_sda, 4");
extern u8 *D_L20_001E9BD8[];
extern void func_L01_0044C280(void *,void *,void *,s32,f32);
extern void func_0038CF68(void *,void *,f32);
extern void func_L01_004CB320(void);
extern void func_L01_004CB358(void);
extern s32 func_003D3CB0(void *,void *,s32,void *,s32);
extern void func_L01_0040A8C0(u128_t *,u128_t *,s32,s32,u32,u32,u32,u32,f32,f32,f32);
void func_L20_003CFE80(u8 *obj) {
    vu0_v4 a,b,d,e,hero;
    u8 *s;
    s32 hit;
    s32 frame;
    f32 speed;
    u8 *p;
    vec_copy(&hero,&D_001A4CB0);
    s=*(u8 **)(obj+0x68);
    frame=D_L20_001DFD40;
    *(vu0_q *)&a=*(vu0_q *)(obj+0x10);
    vec_sub_ba(&d,s+0xD50,&a);
    {
        __asm__("lqc2 $vf1, %1\n\tlqc2 $vf2, %2\n\tvsub.xyz $vf1, $vf2, $vf1\n\tsqc2 $vf1, %0"
            : "=m"(e) : "m"(a), "m"(hero) : "vf1", "vf2");
    }
    if (frame!=D_001DEBA8_sda)
        func_L01_0044C280(&d,&d,&e,0,0.06f);
    speed=*(f32 *)(s+0xD48)*60.0f;
    D_001DEBA8_sda=D_L20_001DFD40;
    func_0038CF68(&d,&d,speed);
    vec_add_ab(&d,&d,&a);
    func_L01_004CB320();
    hit=func_003D3CB0(&a,&d,2,obj,0);
    if (hit && (p=D_L20_001E9BD8[0])!=0 && *(s16 *)(p+0xAA)==0x186D && p[0x20]!=2 && p[0x20]!=5)
        p[0x20]=4;
    func_L01_004CB358();
    if(hit) {
        *(vu0_q *)&b=*(vu0_q *)&D_L20_001E9BE0;
        *(vu0_q *)(s+0xD50)=*(vu0_q *)&b;
    } else {
        *(vu0_q *)&b=*(vu0_q *)&d;
        *(vu0_q *)(s+0xD50)=*(vu0_q *)&b;
    }
    func_L01_0040A8C0((u128_t *)&a,(u128_t *)&b,14,0,0x4F802060,0x4F802060,0x4F802060,0x4F802060,*(f32 *)(s+0xD4C),1.0f,*(f32 *)(s+0xD40));
    func_L01_0040A8C0((u128_t *)&a,(u128_t *)&b,14,3,0x7FFFFFFF,0x7FFFFFFF,0x7FFFFFFF,0x7FFFFFFF,*(f32 *)(s+0xD4C)*0.5f,1.0f,-*(f32 *)(s+0xD40));
    *(vu0_q *)(s+0xD60)=*(vu0_q *)&b;
}

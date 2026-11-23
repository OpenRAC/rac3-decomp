/* functional: high. D_001DFB40 is read both gp-relative and by lui/lw in retail: same frame counter global. */
/* localdecomp:start func_L01_00474B48 */
#include "vu0.h"
typedef int Q_00474B48 __attribute__((mode(TI)));
extern u8 D_001A4C60[];
extern s32 D_001DFB40_sda;
extern s32 D_L01_001DFB40;
extern vu0_v4 D_L01_001E2880_00474B48;
__asm__(".extern D_001DFB40_sda,4");
__asm__(".extern D_L01_001DFB40,16");
/* The owner currently declares func_0038CF00 as void; retail consumes f0.
 * This draft requires that declaration's return type to be corrected. */
void func_L01_00474B48(u8 *p)
{
    extern void func_L01_004CAB30(void *,void *);
    extern void func_0038CE20(void *,void *,f32);
    extern f32 func_0038CF00(void *,void *);
    extern f32 func_003824E0(f32,f32);
    extern void func_0038CF68(void *,void *,f32);
    extern f32 func_0038DAB8(f32,f32);
    extern f32 func_0038D0B0(f32);
    extern s32 func_0038CB00(void *);
    extern void func_003CD250(u8 *);
    vu0_v4 delta,hero;
    u8 *s=p+0x20;
    u8 *pos=p+0x10;
    u8 *h;
    s32 frame;
    func_L01_004CAB30(pos,pos);
    func_0038CE20(s,s,0.9f);
    *(f32 *)(s+8)-=*(f32 *)(s+12);
    __asm__("lqc2 $vf2, %1\n\tlqc2 $vf1, %2\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0" : "=m"(*(vu0_v4 *)(pos)) : "m"(*(vu0_v4 *)(s)), "m"(*(vu0_v4 *)(pos)) : "vf1","vf2");
    func_L01_004CAB30(pos,pos);
    if(func_0038CF00(pos,D_001A4C60)<1.05f) {
        h=D_001A4C60-0x80;
        if(*(f32 *)(h+0x170)!=0.0f) {
            *(Q_00474B48 *)&hero=*(Q_00474B48 *)D_001A4C60;
            __asm__("lqc2 $vf1, %1\n\tlqc2 $vf2, %2\n\tvsub.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0" : "=m"(*(vu0_v4 *)(&delta)) : "m"(*(vu0_v4 *)(pos)), "m"(*(vu0_v4 *)(&hero)) : "vf1","vf2");
            func_0038CF68(&delta,&delta,*(f32 *)(h+0x170)*0.2f+func_003824E0(0.1f,2.0f)*0.020000001f*0.15f);
            p[8]+=(s32)((f32)*(s16 *)(s+0x16)**(f32 *)(h+0x170)*0.5f);
            __asm__("lqc2 $vf2, %1\n\tlqc2 $vf1, %2\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0" : "=m"(*(vu0_v4 *)(pos)) : "m"(*(vu0_v4 *)(&delta)), "m"(*(vu0_v4 *)(pos)) : "vf1","vf2");
            frame=D_L01_001DFB40;
        } else frame=D_001DFB40_sda;
    } else frame=D_L01_001DFB40;
    if(frame%10==0) {
        *(f32 *)(s+0x1c)=func_0038DAB8(*(f32 *)(s+0x1c),1.0f);
        func_0038CF68(&delta,&D_L01_001E2880_00474B48,func_0038D0B0(*(f32 *)(s+0x1c))*0.0075f);
        __asm__("lqc2 $vf1, %1\n\tlqc2 $vf2, %2\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0" : "=m"(*(vu0_v4 *)(s)) : "m"(*(vu0_v4 *)(s)), "m"(*(vu0_v4 *)(&delta)) : "vf1","vf2");
    }
    if(*(s16 *)(p+0xa)<*(s16 *)(s+0x14))
        *(s32 *)(p+4)=((s32)((f32)*(s16 *)(p+0xa)/(f32)*(s16 *)(s+0x14)*128.0f)<<24)|0x204040;
    else *(s32 *)(p+4)=0x4f204040;
    p[8]+=s[0x16];
    if(func_0038CB00(p+0xa)) func_003CD250(p);
}
/* localdecomp:end func_L01_00474B48 */

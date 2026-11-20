/* functional: high. addressing form only; the ring counter retail reads at gp-0x18B0 is level data (D_L01_001DB000; gp-0x19F0 in level 02, gp-0x1870 in 03), not a core sda slot, so it is named as level data. */
#include "common.h"
/* localdecomp:start func_L01_004C7A18 */
#include "vu0.h"
typedef struct {
    u8 pad0[0x18];
    s32 hit;
    s32 count;
    Vec4_004C4AD8 position;
    u8 pad30[0x10];
    Vec4_004C4AD8 normal;
} Hit_004C7A18;
extern S_4C4A18 D_001A4BE0;
extern s32 D_L01_001D6694;
__asm__(".extern D_L01_001D6694,16");
extern s32 D_001D673C_sda,D_001D6740_sda;
__asm__(".extern D_001D673C_sda,4\n.extern D_001D6740_sda,4");
extern s32 D_L01_001DB000[];
extern Hit_004C7A18 D_L01_001EAA00;
extern Vec4_004C4AD8 D_L01_001E29C0;
extern Vec4_004C4AD8 D_L01_001E1190;
extern Vec4_004C4AD8 D_L01_00251100[];
s32 func_L01_004C7A18(Vec4_004C4AD8 *start,Vec4_004C4AD8 *initialVelocity,
                      Vec4_004C4AD8 *outPosition,Vec4_004C4AD8 *outDirection,
                      void *skip,s32 *outHit,s32 *outIndex,f32 step) {
    extern s32 func_L01_004C85C8(u8 *,u128_4C4A18 *,f32,f32,f32);
    extern void func_L01_004C8688(s32,Vec4_004C4AD8 *,Vec4_004C4AD8 *);
    extern void func_L01_004C7D40(void *,void *,f32);
    extern s32 func_003D3CB0(void *,void *,s32,void *,s32);
    extern s32 func_003D5630(void);
    extern s32 func_0038CAD0(void *);
    extern void func_0038CE20(Vec4_004C4AD8 *,Vec4_004C4AD8 *,f32);
    extern void func_0038CF68(Vec4_004C4AD8 *,Vec4_004C4AD8 *,f32);
    extern void func_L01_004C8668(int);
    Vec4_004C4AD8 position,velocity,previous;
    u8 context[0x100] __attribute__((aligned(16)));
    s32 remaining;
    s32 result=0;
    s32 index,i;
    u8 *gbase=(u8 *)&D_001A4BE0;
    if (*(s32 *)(gbase+0x25C4)==0x74 || D_L01_001D6694) return 0;
    *(u128_4C4A18 *)(context+0x10)=*(u128_4C4A18 *)start;
    index=func_L01_004C85C8(context,0,1.0f,1.0f,1.0f);
    position=*start;
    velocity=*initialVelocity;
    remaining=250;
    previous=*start;
    while(!func_0038CAD0(&remaining)) {
        previous=position;
        for(i=9;i>=0;i--) {
            func_L01_004C8688(index,&velocity,0);
            __asm__("lqc2 $vf1,%1\n\tlqc2 $vf2,%2\n\tvadd.xyz $vf1,$vf1,$vf2\n\tsqc2 $vf1,%0"
              : "=m"(position) : "m"(position),"m"(velocity) : "vf1","vf2");
            *(u128_4C4A18 *)(context+0x10)=*(u128_4C4A18 *)&position;
            func_L01_004C7D40(&position,&velocity,step);
        }
        if (func_003D3CB0(&previous,&position,0x12,skip,0)) {
            s32 hitIndex=func_003D5630();
            if (D_L01_001EAA00.count>0 || hitIndex!=-1) {
                if (outIndex) *outIndex=hitIndex;
                *(u128_4C4A18 *)outPosition=*(u128_4C4A18 *)&D_L01_001EAA00.position;
                break;
            }
        }
        if (!D_001D673C_sda && !D_001D6740_sda && !D_001A4BE0.x368) {
            if (20.0f < fabs_asm(start->z-position.z)) {
                remaining=0;
                break;
            }
        }
    }
    if (remaining) {
        func_0038CE20(outDirection,&D_L01_001EAA00.normal,0.0009765625f);
        func_0038CF68(outDirection,outDirection,1.0f);
        if (outHit) *outHit=D_L01_001EAA00.hit;
        __asm__("lqc2 $vf1,%1\n\tlqc2 $vf2,%2\n\tvsub.xyz $vf1,$vf1,$vf2\n\tsqc2 $vf1,%0"
           : "=m"(previous) : "m"(*outPosition),"m"(D_L01_001E29C0) : "vf1","vf2");
        result=1;
        func_0038CE20(&previous,&previous,0.94f);
        __asm__("lqc2 $vf2,%2\n\tlqc2 $vf1,%1\n\tvadd.xyz $vf1,$vf1,$vf2\n\tsqc2 $vf1,%0"
          : "=m"(*outPosition) : "m"(previous),"m"(D_L01_001E29C0) : "vf1","vf2");
    }
    D_L01_001DB000[0]++;
    *(u128_4C4A18 *)&D_L01_00251100[D_L01_001DB000[0]%15]=*(u128_4C4A18 *)outDirection;
    qzero(&D_L01_001E1190);
    {
    s32 count;
    Vec4_004C4AD8 *v=D_L01_00251100;
    for(count=14;count>=0;count--,v++) {
        __asm__("lqc2 $vf1,%1\n\tlqc2 $vf2,%2\n\tvadd.xyz $vf2,$vf2,$vf1\n\tsqc2 $vf2,%0"
          : "=m"(D_L01_001E1190) : "m"(*v),"m"(D_L01_001E1190) : "vf1","vf2");
    }
    }
    func_0038CF68(outDirection,&D_L01_001E1190,1.0f);
    func_L01_004C8668(index);
    return result;
}
/* localdecomp:end func_L01_004C7A18 */

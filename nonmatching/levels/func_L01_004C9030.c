/* PAL near miss (haiku-w1): 160 words differ with the file's flags (-O2 -G8 -fopt-stack -mno-check-zero-division @ps2as); pure C, no VU0 block in the snippet; the residual is the outer-slot spill and register allocation, and the division padding that the divs_nops row would supply (not applied: config/ is not edited). */
#include "common.h"
/* localdecomp:start func_L01_004C9030 */
extern s32 D_L01_001E10E0[] __attribute__((section(".sdata")));
extern u8 D_L01_001D66B0[8];
typedef struct { u8 pad[0x164]; u8 *color; } Info_004C9030;
extern Info_004C9030 D_L01_00221098 __attribute__((section(".sdata")));
void func_L01_004C9030(void) {
    extern f32 func_L01_0040E548(void *, void *);
    extern void func_0038CF68(Vec4_004C4AD8 *, Vec4_004C4AD8 *, f32);
    extern void func_0038CE20(Vec4_004C4AD8 *, Vec4_004C4AD8 *, f32);
    extern u8 *func_L01_004713C8(void *, void *, s32, s32, s32, s32, s32, s32, f32, f32, f32);
    Vec4_004C4AD8 delta;
    s32 i, j, next, nexti, k;
    u8 *p, *q, *vars, *other, *effect;
    f32 distance, scale;
    for(i=0;i<6;i++) {
        if(!D_L01_001E10E0[i]) continue;
        for(j=0;j<6;j++) {
            if(i==j || !D_L01_001E10E0[j]) continue;
            distance=func_L01_0040E548((u8 *)D_L01_001E10E0[i]+0x10,(u8 *)D_L01_001E10E0[j]+0x10);
            if(distance>0.01f && distance<50.0f) {
                p=(u8 *)D_L01_001E10E0[i];
                q=(u8 *)D_L01_001E10E0[j];
                __asm__("lqc2 $vf1, %1\n\tlqc2 $vf2, %2\n\tvsub.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0"
                    : "=m"(delta) : "m"(*(Vec4_004C4AD8 *)(p+0x10)), "m"(*(Vec4_004C4AD8 *)(q+0x10)) : "vf1", "vf2");
                func_0038CF68(&delta,&delta,0.2f);
                scale=1.0f/distance;
                if(scale>0.75f) scale=0.75f;
                func_0038CE20(&delta,&delta,scale);
                q=(u8 *)D_L01_001E10E0[j];
                __asm__("lqc2 $vf2, %1\n\tlqc2 $vf1, %2\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0"
                    : "=m"(*(Vec4_004C4AD8 *)(q+0x10)) : "m"(delta), "m"(*(Vec4_004C4AD8 *)(q+0x10)) : "vf1", "vf2");
            }
            if(distance<0.01f) {
                q=(u8 *)((u8 **)D_L01_001E10E0)[j];
                p=(u8 *)((u8 **)D_L01_001E10E0)[i];
                other=*(u8 **)(q+0x68);
                vars=*(u8 **)(p+0x68);
                if(*(s32 *)(other+0x54)) continue;
                for(k=2;k>=0;k--) {
                    effect=func_L01_004713C8((u8 *)D_L01_001E10E0[i]+0x10,D_L01_001D66B0,17,0xFF1020,5,0,127,6,1050000.0f,42000.0f,0.0f);
                    if(effect) effect[2]=D_L01_00221098.color[0];
                }
                for(k=1;k>=0;k--) {
                    effect=func_L01_004713C8((u8 *)D_L01_001E10E0[i]+0x10,D_L01_001D66B0,17,0x7F7F7F,5,0,127,6,840000.0f,42000.0f,0.0f);
                    if(effect) effect[2]=D_L01_00221098.color[0];
                }
                *(f32 *)(vars+0x68)+=*(f32 *)(other+0x68)*0.5f;
                *(s32 *)(vars+0x34)=0;
                if(*(f32 *)(vars+0x68)>1.5f) *(f32 *)(vars+0x68)=1.5f;
                ((u8 *)D_L01_001E10E0[j])[0x20]=4;
                D_L01_001E10E0[j]=0;
            }
        }
    }
}

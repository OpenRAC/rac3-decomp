#include "common.h"
#include "vu0.h"
/* localdecomp:start func_L05_0035C3C0 */
extern void func_003BD9A0(void *,int,void *),func_003888F0(void *,void *,void *);
extern float func_00388A28(float,float),func_00389468(float,float),func_0037E2A8(void),func_00389380(float,float),func_00388978(float);
extern void func_003BEB58(void *,void *,void *,float),func_00388830(void *,void *,float),func_003886C0(void *,void *,void *,float);
extern int func_003CE740(void *,void *,int,void *,int);
extern void func_003D3FA0(void *,int,u32,int,float,float,float);
extern void func_L05_0035C828(void *,int,int,int,float,float);
extern vu0_v4 D_L05_001EA760;
extern vu0_v4 D_L05_00285AA0[];
extern u8 D_001DD7B0_sda[8];
__asm__(".extern D_001DD7B0_sda, 8");
extern float D_001DD76C_sda,D_001DD768_sda,D_001DD7A4_sda,D_001DD790_sda,D_001DD79C_sda;
extern int D_001DD794_sda,D_001DD798_sda;
extern u8 D_L05_001D66B0_0035C3C0;
__asm__(".extern D_001DD76C_sda, 4");
__asm__(".extern D_001DD768_sda, 4");
__asm__(".extern D_001DD7A4_sda, 4");
__asm__(".extern D_001DD790_sda, 4");
__asm__(".extern D_001DD79C_sda, 4");
__asm__(".extern D_001DD794_sda, 4");
__asm__(".extern D_001DD798_sda, 4");
static __inline__ void add_to_second(void *dst,void *a,void *b) {
    vu0_q qa,qb;
    __asm__("lqc2 %0, %1" : "=j"(qb) : "m"(*(vu0_v4 *)b));
    __asm__("lqc2 %0, %1" : "=j"(qa) : "m"(*(vu0_v4 *)a));
    __asm__("vadd.xyz %0, %0, %1" : "+j"(qb) : "j"(qa));
    __asm__("sqc2 %1, %0" : "=m"(*(vu0_v4 *)dst) : "j"(qb));
}
void func_L05_0035C3C0(u8 *o) {
    vu0_v4 m[4],v1,v2,v3,end,delta,start,offset,gravity,seed;
    u8 *p=*(u8 **)(o+0x68);
    int i;
    *(u32 *)(p+0x3dc)=0xffffffffU;
    for(i=0;i<3;i++) {
        float q;
        u8 *hit;
        func_003BD9A0(o,i+1,m);
        start=m[3];
        func_003888F0(&offset,D_001DD7B0_sda+i*16,m);
        vec_add_ab(&start,&start,&offset);
        if((*(unsigned long *)(o+0x40)&0xffff0000UL)!=0x05050000UL)return;
        if(func_00389468(*(float *)(o+0xf8),func_00388A28(*(float *)(*(u8 **)(p+0x230)+0x10)-*(float *)(o+0x10),*(float *)(*(u8 **)(p+0x230)+0x14)-*(float *)(o+0x14)))<0.17453292f) {
            q=((float)*(int *)(p+0x2e0)-D_001DD76C_sda)/D_001DD768_sda;
            if(q<0.0f)q=0.0f;
            seed=*(vu0_v4 *)(p+0x330);
            func_003BEB58(&gravity,&D_L05_001D66B0_0035C3C0,&seed,q);
            vec_sub_ba(&delta,p+0x220,&start);
            func_00388830(&delta,&delta,35.0f);
            vec_add_ba(&delta,&delta,&gravity);
            add_to_second(&end,&start,&delta);
        }else {
            start=m[3];
            func_00388830(&delta,&m[1],-35.0f);
            vec_add_ab(&end,&delta,&start);
        }
        if(func_003CE740(&start,&end,16,o,0)) {
            end=D_L05_001EA760;
            hit=*(u8 **)((u8 *)&D_L05_001EA760-8);
            if(hit) {
                if(*(u32 *)(p+0x3dc)==0xffffffffU || (u32)hit==*(u32 *)(p+0x3dc))*(u32 *)(p+0x3dc)=(u32)hit;
                else *(u32 *)(p+0x3dc)=0;
                func_003D3FA0(&D_L05_001EA760,57,0x4f2020ff,1,0.5f,0.24f,func_0037E2A8());
                func_003D3FA0(&D_L05_001EA760,49,0x6f808080,1,0.25f,0.24f,func_0037E2A8());
            }else {
                *(u32 *)(p+0x3dc)=0;
                func_003D3FA0(&D_L05_001EA760,57,0x3f2020ff,1,0.3f,0.24f,func_0037E2A8());
                func_003D3FA0(&D_L05_001EA760,49,0x4f808080,1,0.2f,0.24f,func_0037E2A8());
            }
        }
        D_L05_00285AA0[0]=start;
        func_003D3FA0(D_L05_00285AA0,49,0x153064ff,1,0.17f,0.0f,D_001DD7A4_sda);
        func_003886C0(&v1,&start,&end,0.05f);D_L05_00285AA0[1]=v1;
        D_001DD7A4_sda=func_00389380(D_001DD7A4_sda,0.017453294f);
        q=func_00388978(D_001DD7A4_sda);
        func_003886C0(&v2,&start,&end,((q*0.5f+0.5f)*0.4500000179f)+0.1f);D_L05_00285AA0[2]=v2;
        func_003886C0(&v3,&start,&end,0.66f);
        D_L05_00285AA0[3]=v3;D_L05_00285AA0[4]=end;
        func_L05_0035C828(D_L05_00285AA0,4,D_001DD794_sda,D_001DD798_sda,D_001DD790_sda,D_001DD79C_sda);
    }
    if(*(u32 *)(p+0x3dc)==0xffffffffU)*(u32 *)(p+0x3dc)=0;
}
/* localdecomp:end func_L05_0035C3C0 */

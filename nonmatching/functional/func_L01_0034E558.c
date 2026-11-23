/* functional: high. Near-miss draft (compiles under file flags); 19 diff words, scheduling only; draft logic verified */
/* localdecomp:start func_L01_0034E558 */
#include "structs/hero.h"
typedef struct { f32 x,y,z,w; } __attribute__((aligned(16))) V_0034E558;
extern struct Hero D_001A4BE0;
extern f32 D_001A4C70[];
extern s32 D_001DD44C_sda;
extern s32 D_001DD3F8_sda;
extern s32 D_001DD3FC_sda;
extern u8 D_L01_00283BA0[][160];
extern u8 D_L01_00283E20[][320];
extern V_0034E558 D_L01_001EAA20;
__asm__(".extern D_001DD44C_sda, 4");
__asm__(".extern D_001DD3F8_sda, 4");
__asm__(".extern D_001DD3FC_sda, 4");
u8 *func_L01_0034E558(u8 *owner,s32 unused,s128 *direction,u8 *parent,s32 joint)
{
    extern u8 *func_003C24B0(s32,s32);
    extern void func_0038D308(void *,void *);
    extern void func_003C2F58(void *,s32,void *);
    extern void func_0038CE20(f32 *,f32 *,f32);
    extern s32 func_003D3CB0(void *,void *,s32,void *,s32);
    extern void func_0038CF68(void *,void *,f32);
    extern void func_L01_0034E9E0(char *);
    V_0034E558 saved;
    V_0034E558 *savedp=&saved;
    s32 slot;
    V_0034E558 v;
    u8 *m,*p;
    *(s128 *)savedp=*direction;
    m=func_003C24B0(4501,128);
    if(m) {
        m[0x20]=1;
        m[0x30]=255;
        p=(u8 *)((Moby *)m)->vars;
        *(s32 *)(p+0x18)=-1;
        *(s16 *)(p+0x1E)=(D_001DD44C_sda*5+2)/6;
        func_0038D308(m+0xC0,D_001A4C70);
        slot=D_001DD3F8_sda;
        { u8 *a=D_L01_00283BA0[slot];
          u8 *b=D_L01_00283E20[slot];
          *(u8 **)(p+0)=a;
          *(u8 **)(p+4)=b; }
        if((u32)slot>=4)D_001DD3F8_sda=0;
        D_001DD3F8_sda=(D_001DD3F8_sda+1)%4;
        *(u8 **)(p+0x20)=owner;
        if(parent) {
            if(*(s16 *)(parent+0xAA)==6251) *(s32 *)(p+0x24)=0x800530;
            else *(s32 *)(p+0x24)=D_001DD3FC_sda;
        } else *(s32 *)(p+0x24)=D_001DD3FC_sda;
        *(s128 *)(p+0x30)=*(s128 *)savedp;
        if(parent && (*(s16 *)(parent+0xAA)==6222 || *(s16 *)(parent+0xAA)==6253)) {
            *(u8 **)(p+0x40)=parent;
            *(s32 *)(p+0x44)=joint;
            func_003C2F58(parent,joint,m+16);
        } else if(parent && *(s16 *)(parent+0xAA)==6251) {
            *(u8 **)(p+0x40)=parent;
            *(s128 *)(m+16)=*(s128 *)(parent+16);
        } else {
            func_0038CE20((f32 *)&v,(f32 *)((u8 *)D_001A4BE0.hero_moby+0xE0),0.75f);
            __asm__("lqc2 $vf1, %1\n\tlqc2 $vf2, %2\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0"
                : "=m"(*(V_0034E558 *)(m+16)) : "m"(D_001A4BE0.pos), "m"(v) : "vf1","vf2");
        }
        if(*(f32 *)(p+0x30)==0 && *(f32 *)(p+0x34)==0 && *(f32 *)(p+0x38)==0)
            *(s128 *)(p+0x30)=*(s128 *)(*(u8 **)(p+0x20)+16);
        if(func_003D3CB0(m+16,p+0x30,16,D_001A4BE0.hero_moby,0)) {
            __asm__("lqc2 $vf1, %1\n\tlqc2 $vf2, %2\n\tvsub.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0"
                : "=m"(v) : "m"(*(V_0034E558 *)(m+16)), "m"(D_L01_001EAA20) : "vf1","vf2");
            func_0038CF68(&v,&v,0.2f);
            __asm__("lqc2 $vf1, %1\n\tlqc2 $vf2, %2\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0"
                : "=m"(*(V_0034E558 *)(p+0x30)) : "m"(D_L01_001EAA20), "m"(v) : "vf1","vf2");
        }
        func_L01_0034E9E0((char *)m);
    }
    return m;
}
/* localdecomp:end func_L01_0034E558 */

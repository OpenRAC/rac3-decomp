/* functional: high. Structure, every branch, constant, offset and callee verified against PAL asm; callee call order identical to retail (jal sequence matches 1:1). Instruction scheduling and delay-slot filling differ (381 words, no reordering of side effects): the delay-slot store before func_L01_003F5E88 is written before the call. Level-01 draft from Codex wave 10 re-read function by function. */
#include "common.h"
/* localdecomp:start func_L01_003C27E0 */
#include "vu0.h"
typedef struct { u8 pad[0x30]; u8 b30,b31; s16 h32; } Init_003C27E0;
typedef struct { u8 pad[0x80]; f32 x,y; } Hero_003C27E0;
typedef struct {
    u8 pad0[0x1C]; void *settings; u8 pad20[0x10];
    f32 scale,f34,f38,f3C,f40; u8 pad44[0x18];
    f32 f5C,f60,f64; s32 flags,f6C; u8 pad70[0xCC];
    s32 mode; u8 *target; s32 f144; f32 f148; u8 pad14C[4];
    f32 f150; u8 pad154[4]; s32 f158; s16 f15C,f15E;
    u8 pad160[0x10]; u128_t v170,v180,v190,v1A0;
    u8 pad1B0[0x20]; u8 *attacked; u8 pad1D4[0x134];
    s32 f308,f30C; f32 f310,f314; s32 f318;
    u8 pad31C[0x20]; s32 f33C; u8 pad340[4]; s32 f344;
} Vars_003C27E0;
extern u8 D_001425C0[];
extern S_002C5640 D_L01_002C5600[];
extern s32 D_L01_001E2230;
extern vu0_v4 D_L01_001E29C0[];
extern u8 D_001A4BE0[];
extern vu0_q D_L01_001E21C0[] __attribute__((section(".sdata")));
u8 *func_L01_003C27E0(s32 unused, u128_t *position) {
    extern u8 *func_003C24B0(s32,s32);
    extern void func_L01_003F5E88(u8 *);
    extern void func_003A52A0(s32,s32,u8 *);
    extern f32 func_003824E0(f32,f32);
    extern void func_L01_003C3C50(u8 *);
    extern s32 func_L01_003C2E10(void);
    extern s32 func_L01_004572B0(u8 *,s32,s32 *);
    extern s32 func_L01_00457480(s32,s32);
    extern void func_L01_0045BD78(u8 *,f32,f32,f32,f32);
    extern s32 func_L01_003BEA60(Moby_003BD218 *);
    extern s32 func_L01_003BEAA0(void);
    extern void func_L01_004C7D98(u8 *,u8 *);
    extern void func_0038CF68(void *,void *,f32);
    extern void func_0038CE90(void *,void *,void *);
    extern void func_0038D570(void *,void *);
    extern void func_003C48A8(void *,void *);
    extern f32 func_0038D160(f32,f32);
    extern u8 *func_L01_00450010(void *,s32,f32,f32,f32,f32);
    extern void func_L01_004450F0(u8 *,s32,s32);
    extern void func_003C3A10(u8 *,s32,s32,s32);
    extern void func_L01_003C2E88(M_3C1AB8 *,f32);
    extern s32 func_L01_003C2E48(s32);
    extern void func_003C7C38(u8 *);
    vu0_v4 basis[3];
    u128_t matrix[4];
    s32 extra;
    u8 *m=func_003C24B0(0x1ADA,0x380);
    Vars_003C27E0 *v;
    s32 level;
    if(m) {
        ((Init_003C27E0 *)m)->b30=((Init_003C27E0 *)m)->h32=127;
        ((Init_003C27E0 *)m)->b31=1;
        v=*(Vars_003C27E0 **)(m+0x68);
        *(u128_t *)(m+0x10)=*position;
        func_L01_003F5E88(m);
        func_003A52A0(3,0,m);
        v->f148=func_003824E0(-50.0f,50.0f)*0.01745329238474369f;
        v->f158=22;
        v->settings=&v->scale;
        func_L01_003C3C50(m);
        if(D_L01_002C5600[D_001425C0[0x57]].unk1>=3) {
            if(func_L01_003C2E10()) v->mode=1;
        } else {
            *(u16 *)(m+0x34)&=~0x100;
            v->mode=0;
        }
        v->f15C=-1;
        v->f64=0.5f;
        v->f34=0.25f;
        v->scale=0.45f;
        v->f60=2.094395160675049f;
        v->f5C=0.003920000046491623f;
        v->f38=0.75f;
        v->f3C=1.0f;
        v->f40=1.57079637f;
        v->f310=func_003824E0(6.5f,8.0f);
        v->f314=func_003824E0(5.5f,6.5f);
        v->f6C=-1;
        level=D_L01_002C5600[D_001425C0[0x57]].unk1;
        if(level>0) {
            v->f308=func_L01_004572B0(m,0,&extra);
            v->f30C=func_L01_00457480(*(s16 *)(m+0xAA),v->f308);
        }
        if(level>=4) *(s16 *)(m+0x7C)=5;
        if((u32)(level-1)<3) *(s16 *)(m+0x7C)=9;
        else if(level==0) *(s16 *)(m+0x7C)=1;
        D_L01_001E2230=0;
        v->f15E=0;
        if(level==1) v->f15E=50;
        else if(level==2) v->f15E=50;
        else if(level==3) D_L01_001E2230=120;
        else if(level>=4) D_L01_001E2230=40;
        if(v->mode==1) v->flags|=4;
        else v->flags|=1;
        func_L01_0045BD78(m,0.0028000001329928637f,0.06000000238418579f,0.005026548635214567f,0.25132742524147034f);
        *(u32 *)(m+0x78)=0x80808080;
        v->f150=func_003824E0(0.02617993950843811f,0.06981317698955536f);
        v->f318=-1;
        if(func_L01_003BEA60((Moby_003BD218 *)m) || func_L01_003BEAA0()) {
            u8 *rotation;
            func_L01_004C7D98(m+0x10,(u8 *)&basis[0]);
            rotation=m+0xF0;
            func_0038CF68(&basis[0],&basis[0],-1.0f);
            vec_sub_ba(&basis[1],D_L01_001E29C0,m+0x10);
            func_0038CF68(&basis[1],&basis[1],1.0f);
            func_0038CE90(&basis[1],&basis[1],&basis[0]);
            func_0038CE90(&basis[2],&basis[1],&basis[0]);
            *(u128_t *)(m+0xC0)=*(u128_t *)&basis[2];
            *(u128_t *)(m+0xD0)=*(u128_t *)&basis[1];
            *(u128_t *)(m+0xE0)=*(u128_t *)&basis[0];
            *(u128_t *)(m+0xF0)=*(u128_t *)(m+0x10);
            func_0038D570(matrix,m+0xC0);
            func_003C48A8(matrix,rotation);
        } else {
            u8 *target;
            qzero(m+0xF0);
            *(f32 *)(m+0xF8)=func_0038D160(((Hero_003C27E0 *)D_001A4BE0)->x-*(f32 *)(m+0x10),((Hero_003C27E0 *)D_001A4BE0)->y-*(f32 *)(m+0x14));
            *(u128_t *)&basis[0]=*(u128_t *)(m+0x10);
            target=func_L01_00450010(&basis[0],0,0.3490658402442932f,25.0f,-1.0f,0.0872664600610733f);
            v->target=target;
            if(target && v->mode==0 && !(*(u16 *)(target+0x34)&2) && target[0x20]!=254 && target[0x20]!=253 && m[0x20]!=11 && *(s16 *)(target+0xAA)!=0x18AD) {
                v->attacked=target;
                func_L01_004450F0(m,5,-1);
                v->f344=350;
                func_003C3A10(m,3,0,8);
                *(f32 *)(m+0x48)=3.0f;
                v->attacked=v->target;
                v->v190=*(u128_t *)(v->target+0x10);
                v->v180=*(u128_t *)(v->target+0x10);
                v->v1A0=*(u128_t *)(v->target+0x10);
                func_L01_003C2E88((M_3C1AB8 *)m,12.0f);
                v->v170=*(u128_t *)(m+0x10);
                *(f32 *)(m+0xF8)=func_0038D160(*(f32 *)&v->v180-*(f32 *)(m+0x10),*((f32 *)&v->v180+1)-*(f32 *)(m+0x14));
            }
        }
        v->target=0;
        v->f144=0x683;
        *(s32 *)(m+0x98)=*(s32 *)(*(u8 **)(m+0x24)+0x10);
        if(v->mode==1) {
            if(m[0x43]!=9) func_003C3A10(m,9,0,0);
            *(f32 *)(m+0x48)=func_003824E0(0.75f,1.25f);
            v->f15C=func_L01_003C2E48((s32)m);
            func_L01_004450F0(m,16,-1);
            v->f33C=25;
            m[0x23]=0;
            *(u128_t *)(m+0x10)=D_L01_001E21C0[v->f15C];
        } else {
            func_L01_004450F0(m,3,-1);
            if(m[0x43]!=3) func_003C3A10(m,3,0,0);
        }
        func_003C7C38(m);
    }
    return m;
}
/* localdecomp:end func_L01_003C27E0 */

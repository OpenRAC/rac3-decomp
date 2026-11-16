/* NTSC-U draft (Codex wave 3): C of func_L04_004FC178, the NTSC-U twin of func_L04_00500298, with NTSC-U names and addresses (the two versions' code differs).
 * near miss: 249 words differ on NTSC-U with the file's flags (NTSC-U twin "func_L04_004FC178", whose code is not the PAL one).
 * Worker's note: 249 diff; best log w122/func_L04_004FC178.check1.log; permitted flags reverified once; literal pool vs retail inline 1/12 and 1/60 documented unlisted @ps2as blocker; retained prior best; register/base addressing differs; retail div nops 2 2 2 2
 */
#include "common.h"
/* localdecomp:start func_L04_004FC178 */
typedef struct {f32 x,y,z,w;} __attribute__((aligned(16))) Vec;
typedef int Quad __attribute__((mode(TI)));
extern u8 D_001A4BE0[];
extern Vec D_001A4CD0,D_001A4D70;
extern f32 func_00388960(f32),func_00388978(f32),func_003887A0(void *),func_L01_0050D430(void *),func_L01_004EC818(void *);
extern void func_00388880(void *,void *,f32),func_00388830(void *,void *,f32),func_L01_0050D530(void *,void *,f32),func_L01_0050D5B0(void *,void *,f32);
extern f32 func_00388730(void *,void *);
extern s32 func_L01_0045D358(s32,s32,s32,s32);
static __inline__ void sub(Vec *d,Vec *a,Vec *b) {
    __asm__("lqc2 $vf2, %1\n\tlqc2 $vf1, %2\n\tvsub.xyz $vf2, $vf2, $vf1\n\tsqc2 $vf2, %0" : "=m"(*d) : "m"(*a),"m"(*b) : "vf1","vf2");
}
static __inline__ void add(Vec *d,Vec *a,Vec *b) {
    __asm__("lqc2 $vf1, %1\n\tlqc2 $vf2, %2\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0" : "=m"(*d) : "m"(*a),"m"(*b) : "vf1","vf2");
}
void func_L04_004FC178(f32 amount) {
    Vec v,tmp,v2;
    u8 *h=D_001A4BE0;
    f32 angle,speed,dot,l1,l2,scale;
    s32 state=h[0x25F4];
    if(state==0) {
        angle=*(f32 *)(h+0x1A0);speed=*(f32 *)(h+0x1B0);
        if(*(s32 *)(h+0x25CC)==4 && *(s16 *)(h+0x4F4) && h[0x2A7]) speed=0.0833333358f;
        if(*(s16 *)(h+0x36A) && *(s32 *)(h+0x25C4)==14 && speed>0.0166666675f) speed=0.0166666675f;
        v.x=func_00388960(angle)*speed;
        v.y=func_00388978(angle)*speed;
        v.z=*(f32 *)(h+0xF8);
        dot=-(*(f32 *)(h+0xF0)*v.x + *(f32 *)(h+0xF4)*v.y);
        l1=func_003887A0(&v);l2=func_003887A0(h+0xF0);
        if(l1==0 || l2==0) dot=0;else dot=dot/l1/l2;
        if(*(s32 *)(h+0x25C4)==176) dot+=0.5f;else dot=(dot+1)*1.5f;
        if(dot>3) dot=3;if(dot<1) dot=1;
        amount*=dot;
        sub(&v,&v,&D_001A4CD0);
        if(amount<func_003887A0(&v)) func_00388880(&v,&v,amount);
        add(&D_001A4CD0,&D_001A4CD0,&v);
        *(Quad *)&tmp=*(Quad *)(h+0x9E0);
        *(f32 *)(h+0x1B4)=*(f32 *)(h+0x178)-func_L01_004EC818(&tmp);
    } else if(state>=1 && state<3) {
        tmp=D_001A4D70;speed=*(f32 *)((u8 *)&D_001A4D70+0x20);
        func_L01_0050D530(&v,&tmp,0);
        func_00388830(&v,&v,speed);
        func_L01_0050D530(&v2,(u8 *)&D_001A4D70-0xA0,0);
        dot=-func_00388730(&v2,&v);
        l1=func_L01_0050D430(&v);l2=func_L01_0050D430((u8 *)&D_001A4D70-0xA0);
        if(l1==0 || l2==0) dot=0;else dot=dot/l1/l2;
        dot=(dot+1)*1.5f;if(dot>3) dot=3;if(dot<1) dot=1;
        sub(&v,&v,&D_001A4CD0);
        func_L01_0050D530(&v,&v,0);
        amount*=dot;
        if(amount<func_L01_0050D430(&v)) func_L01_0050D5B0(&v,&v,amount);
        add(&D_001A4CD0,&D_001A4CD0,&v);
        *(f32 *)(h+0x1B4)=*(f32 *)(h+0x178);
    } else return;
    if(*(s16 *)(h+0x1434) || (*(s32 *)(h+0x16B0)==1 && func_L01_0045D358(40,2,0,0))) *(f32 *)(h+0x1B4)=*(f32 *)(h+0x174);
}
/* localdecomp:end func_L04_004FC178 */

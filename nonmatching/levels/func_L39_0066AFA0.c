/* NTSC-U draft (Codex wave 3): C of func_L39_00668698, the NTSC-U twin of func_L39_0066AFA0, with NTSC-U names and addresses (the two versions' code differs).
 * near miss: 12 words differ on NTSC-U with the file's flags (NTSC-U twin "func_L39_00668698", whose code is not the PAL one).
 * Worker's note: 12 diff; ten checks (two compiler errors, eight scored); best log sixth-06.log; remaining VU0 store/call-argument scheduling, callback addition order, final loop s1/s2 allocation; allowed flags reject vu0.h j-operand helper (sixth-03.log); retained one real ...
 */
#include "common.h"

/* localdecomp:start func_L39_00668698 */
typedef int Quad668698 __attribute__((mode(TI)));
typedef union { Quad668698 q; u32 w[4]; float f[4]; } Vec668698;
typedef struct {
    u8 pad0[0x1F0];
    Quad668698 previousPos, previousRot;
    u8 pad210[0x80];
    Quad668698 spawnPos, spawnRot;
    u8 pad2B0[0x20];
    u8 *model;
    int unknown2D4;
    u8 *owner, *other;
    u8 pad2E0[0xC];
    int stuck, respawn, delay;
    int flags;
    s16 type;
    u8 pad2FE[0xA];
    float health;
    u8 pad30C[8];
    float radius;
    int unknown318, timer1, timer2, active, unknown328, target, age;
    u8 pad334[0xC];
} Player668698;
typedef struct { void (*spawn)(u8 *); u8 pad4[0xC]; void (*update)(u8 *); u8 pad14[8]; } Kind668698;
typedef struct {u8 pad0[0x128];int context;u8 pad12C[0x3C];u8 running;u8 pad169[3];int event;} World668698;
extern World668698 D_001A5E50;
extern int D_001DAAE8_sda;
extern Player668698 D_L39_00337800[];
extern u8 D_L39_0033AC08[];
extern u8 D_L39_004998A0[];
extern u8 *D_L39_002638C0[];
extern u8 *D_L39_0024CF20[];
extern int func_00388398(int *);
extern void func_L39_006683A0(Player668698 *,int);
extern void func_L01_00438908(void *,int,int,int);
extern float func_00388730(void *,void *);
extern void func_L39_00664930(Player668698 *,u32,int,int);
extern int func_003CF790(void *,int,void *,int,float);
extern void func_L39_0061C568(void *,void *,int);
extern void func_L39_00666488(Player668698 *),func_L39_00667DB8(Player668698 *,int),func_L39_006669C8(Player668698 *,u8 *);
extern void func_L39_00664E28(Player668698 *,u8 *,int),func_L39_00664B10(Player668698 *,u8 *,int),func_L39_00625860(u8 *,int);
extern void func_L39_00667750(u8 *,int);

void func_L39_00668698(void) {
    Vec668698 a;
    u8 changed=0;
    int i,next,context;
    Player668698 *p;
    u8 *owner;
    int n,z;
    context=D_001A5E50.context;
    for(i=0;i<D_001DAAE8_sda;i++) {
        p=&D_L39_00337800[i];
        if(!p || !p->model)continue;
        p->age++;
        if(p->age>100)p->age=100;
        if(p->age>60 && p->health<=0.0f && p->active) {
            u8 state=p->model[0xBC];
            if(state!=9) if(state!=10) if(state!=11) if(state!=7) if(state!=8) {
                if(p->owner)*(s16 *)(p->owner+0x320)=2;
                if(p->other)*(s16 *)(p->owner+0x320)=2;
            }
        }
        if(D_001A5E50.running) {
            func_00388398(&p->timer1);
            func_00388398(&p->timer2);
        }
        p->target=-1;
        if(p->owner) {
            u8 *key=p->owner+0x19E4,*out;
            int index,offset,step;
            if(!*key)z=0;
            else {
                out=(u8 *)&a;index=*key+1;offset=((int)key-*key)&7;step=0;
                do {*out++=D_L39_004998A0[index+((offset+step)&7)*255];step+=5;}while(step<40);
                a.w[0]^=(u32)key;a.w[1]^=a.w[0];z=a.w[1];
            }
            if((z^49)!=0 && *(s16 *)(p->model+0xAA)!=0x10C2) {
                u8 *actor=p->owner;
                ((void (*)(void *,int,int,int,int))(*(void ***)(actor+0x14))[13])(actor,49,1,0,1);
                if(!(p->flags&0x4000000))p->owner[0x1A0A]=1;
            }
        }
        if(p->other) {
            u8 *key=p->other+0x19E4,*out;
            int index,offset,step;
            if(!*key)z=0;
            else {
                out=(u8 *)&a;index=*key+1;offset=((int)key-*key)&7;step=0;
                do {*out++=D_L39_004998A0[index+((offset+step)&7)*255];step+=5;}while(step<40);
                a.w[0]^=(u32)key;a.w[1]^=a.w[0];z=a.w[1];
            }
            if((z^49)!=0) {
                u8 *actor=p->other;
                ((void (*)(void *,int,int,int,int))(*(void ***)(actor+0x14))[13])(actor,49,1,0,1);
                if(!(p->flags&0x4000000))p->other[0x1A0A]=1;
            }
        }
        if(p->owner || p->other) {
            int n;
            if(p->owner)n=*(int *)(p->owner+0x2548);else n=*(int *)(p->other+0x2548);
            func_L39_006683A0(p,n);p->target=n;p->stuck=0;
        } else {
            if(p->flags&0x400) {
                if(p->flags&0x100){func_L39_006683A0(p,0);p->target=0;}
                else if(p->flags&0x200){func_L39_006683A0(p,1);p->target=1;}
            } else {
                if(p->type==0)*(int *)(p->model+0x78)=0x787878;
                else func_L01_00438908(p->model,128,128,128);
            }
            if(!p->model[0xBC]) {
                __asm__("lqc2 $vf1, %1\n\tlqc2 $vf2, %2\n\tvsub.xyz $vf2, $vf2, $vf1\n\tsqc2 $vf2, %0"
                    : "=m"(a) : "m"(*(Vec668698 *)(p->model+0x10)), "m"(p->spawnPos) : "vf1", "vf2");
                if(func_00388730(&a,&a)>10.0f) {
                    if(++p->stuck>7200){p->health=0.0f;func_L39_00664930(p,0xFFFFFFFF,6,D_001A5E50.event);}
                }
            }
        }
        if(p->model[0xBC]==7) {
            *(int *)(p->model+0x98)=0;
            *(u16 *)(p->model+0x34)|=0x41;
            func_00388398(&p->respawn);
            if(p->respawn<=0) {
                int count;
                count=func_003CF790(&p->spawnPos,1,0,0,p->radius*1.75f);
                if(count==0 || (count==1 && *(s16 *)(D_L39_002638C0[0]+0xAA)==0x1981)) {
                    *(Quad668698 *)(p->model+0x10)=p->spawnPos;
                    *(Quad668698 *)(p->model+0xF0)=p->spawnRot;
                    p->previousPos=p->spawnPos;p->previousRot=p->spawnRot;
                    { void (*spawn)(u8 *)=*(void (**)(u8 *))(D_L39_0033AC08+p->type*28);if(spawn)spawn(p->model); }
                    func_L39_0061C568((u8 *)p+0x20,p->model+0x10,D_001A5E50.context);
                    p->active=0;p->model[0xA8]=255;
                    p->flags|=8;if(p->flags&0x300)p->flags|=0x400;
                    *(int *)(p->model+0x98)=*(int *)(*(u8 **)(p->model+0x24)+0x10);
                    *(u16 *)(p->model+0x34)&=0xFFBE;
                    p->model[0xBC]=0;
                }
            }
        }else if(p->model[0xBC]==8) {
            *(int *)(p->model+0x98)=0;*(u16 *)(p->model+0x34)|=0x41;
        }else if(p->model[0xBC]!=10) {
            func_L39_00666488(p);func_L39_00667DB8(p,context);func_L39_006669C8(p,&changed);
            if(((Kind668698 *)D_L39_0033AC08)[p->type].update)
                ((void (*)(u8 *))*(u32 *)(p->type*28+D_L39_0033AC08+16))(p->model);
        }else if(*(u16 *)(p->model+0x96)>=181) {
            p->model[0xBC]=7;p->respawn=p->delay;*(u16 *)(p->model+0x96)=0;
            if(p->owner) {
                owner=p->owner;
                if(!(p->flags&0x4000000)) {
                    ((void (*)(void *,int,int,int,int))(*(void ***)(owner+0x14))[13])(owner,118,0,0,0);owner[0x1A0A]=1;
                }
                func_L39_00664E28(p,owner,0);
                if(!(p->flags&0x4000000)){func_L39_00625860(owner,0);owner[0x1A0A]=1;}
            }
            if(p->other) {
                owner=p->other;
                if(!(p->flags&0x4000000)) {
                    ((void (*)(void *,int,int,int,int))(*(void ***)(owner+0x14))[13])(owner,118,0,0,0);owner[0x1A0A]=1;
                }
                func_L39_00664B10(p,owner,0);
                if(!(p->flags&0x4000000)){func_L39_00625860(owner,0);owner[0x1A0A]=1;}
            }
        }
        (*(u16 *)(p->model+0x96))++;
    }
    {u8 **list=D_L39_0024CF20;int j=7;do {owner=*list++;j--;if(owner)func_L39_00667750(owner,changed);}while(j>=0);}
}
/* localdecomp:end func_L39_00668698 */

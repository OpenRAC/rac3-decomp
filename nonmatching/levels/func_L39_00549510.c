/* NTSC-U draft (Codex wave 3): C of func_L39_00548BE0, the NTSC-U twin of func_L39_00549510, with NTSC-U names and addresses (the two versions' code differs).
 * near miss: 380 words differ on NTSC-U with the file's flags (NTSC-U twin "func_L39_00548BE0", whose code is not the PAL one).
 * Worker's note: 151 diff retained; ten compiles; best log third-03.log via w127/nops.py in-memory row 1 1 0 (assembler naturally adds 0 1 1; retail total nops 1 2 1); NEEDS divs row review; health locals and typed table reduce aligned discrepancies but raw scores 208-352; ...
 */
#include "common.h"
#include "vu0.h"
/* localdecomp:start func_L39_00548BE0 */
typedef struct { vu0_v4 v; float timer; int p14[3]; u8 *target; int grace; float scale; s16 effect,count; u8 *last; int retry,active,sound; u8 *owner; float strength; int enabled; } P548;
extern u8 D_L39_004998A0[],D_L39_0049C950[],D_L39_0025F840[],D_L39_00470600[];
extern u8 *D_L39_002638C0[];
typedef struct { float a,b,c,pad; vu0_v4 pos; } Effect548;
extern Effect548 D_L39_002668C0[];
extern void func_L39_00619D58(void *,void *),func_L39_00548548(void *),func_L01_0040BB20(float *);
extern void func_L01_00441E00(void *,int,int,int,int),func_L39_006719D8(void *);
extern u32 func_L39_005FD580(void *,void *,int,float);
extern void func_L01_003F4D78(int,void *,u32,void *,int,int,int,float,float,float,float,float,float,float);
extern void func_003886E8(void *,void *,float);
extern u8 *func_L39_00644AA0(void *,void *,void *,int,float,float,float,float,float);
extern u8 *func_0037E0B8(void *);
extern int func_L39_00637548(void *),func_00388398(int *);
extern float func_003887C8(void *,void *);
extern u32 func_003894A0(u32,u32,float);
extern int func_L39_00670988(void *,int,int,void *);
extern void func_003BE4F0(void *,int,int,int);
extern int func_003CF790(void *,int,void *,int,float),func_L39_005B6970(void *);
extern void func_L39_005F0CE0(int,int,void *),func_L39_005487B8(void *),func_L39_00549708(void *,void *),func_L39_0061F5C0(void *,int);
extern int func_L01_003F0118(void *,int),func_L39_00646268(void *,int);
extern void func_L01_003F0338(int,int),func_003BDA38(void *,int,void *);
extern int func_L39_0059CF60(void *,float,float,float,float,float);
extern void func_003883C8(s16 *),func_L01_00421FE0(int);
void func_L39_00548BE0(u8 *o) {
    vu0_v4 a,b,c,d,e,f,g,h,i,j,k;
    P548 *p=*(P548 **)(o+0x68);
    u8 *owner,*target,*health,*data,*row;
    int n,x,z,state,ok; u32 color; float q,r,s,t;
    if(!o[0x20]) {
        func_L39_00619D58(o,&p->owner);o[0x20]=1;p->effect=-1;p->retry=5;p->sound=-1;p->count=0;p->target=0;p->last=0;p->active=0;
    }
    owner=p->owner;if(!owner)return;
    func_L39_00548548(o);func_L01_0040BB20(&p->timer);
    { u8 *key=owner+0x19e4; u8 *out; int offset,step,index;
      if(!*key)z=0;
      else { out=(u8 *)&a;index=*key+1;offset=((int)key-*key)&7;step=0;
        do { *out++=D_L39_004998A0[index+((offset+step)&7)*255];step+=5; }while(step<40);
        ((u32 *)&a)[0]^=(u32)key;((u32 *)&a)[1]^=((u32 *)&a)[0];z=((u32 *)&a)[1];
      }
    }
    if((z^1)==0)((void (*)(void *,int,int,int,int))(*(void ***)(owner+0x14))[13])(owner,29,0,0,1);
    if(o[0x42]==o[0x43] && (o[0x60]&2))func_L01_00441E00(o,1,0,2,0);
    if(*(int *)(owner+0x3e0))*(int *)(owner+0x1078)=*(int *)(owner+0x3e0);
    if(!owner[0x1a14])func_L39_006719D8(owner);
    p->strength=0;target=0;
    if(*(int *)(owner+0x1310)) {
        if(owner[0x1a14]) {
            float strength;
            if(!p->active){p->target=0;p->retry=5;}p->active=1;
            strength=(*(float *)(owner+0x1250)-0.85f)/0.1499999762f;
            if(strength>1.0f)strength=1.0f;else if(strength<0.0f)strength=0.0f;
            p->strength=strength;
            if(strength!=0.0f) {
                u32 color1=func_L39_005FD580(owner+0x1338,owner+0x133c,1,150.0f);
                if(owner[0x1a14])func_L01_003F4D78(owner[0x24c9],o,color1,0,39,-1,4,0.7f,0.0f,90.0f,0.5f,0.5f,40.0f,40.0f);
                target=*(u8 **)(owner+0x122c);
            } else {
                u32 color0=func_L39_005FD580(owner+0x1338,owner+0x133c,0,150.0f);
                if(owner[0x1a14])func_L01_003F4D78(owner[0x24c9],o,color0,0,39,-1,4,0.7f,0.0f,90.0f,0.5f,0.5f,40.0f,40.0f);
                target=0;
            }
        }
    } else if(owner[0x1a14]) {
        p->active=0;
        if(owner[0x1a08])func_003886E8(&b,o+0xd0,-1.0f);else b=*(vu0_v4 *)(owner+0x3b0);
        func_003886E8(&c,*(u8 **)(owner+0x2524)+0xe0,0.75f);
        vec_add_ab(&c,owner+0xa0,&c);
        target=func_L39_00644AA0(owner,&c,&b,0,0.3141592741f,0.2967059612f,75.0f,0.3141592741f,0.3141592741f);
        p->strength=0.5f;
    }
    if(owner[0x1a08]){func_003886E8(&b,o+0xd0,-1.0f);target=0;}
    if(p->target) {
        health=func_0037E0B8(p->target);data=p->target;
        if(!data || data[0x20]==254 || data[0x20]==253 || (health && *(float *)health<=0.0f) || !data[0x31] || (owner[0x1a08]&&!func_L39_00637548(owner))) {p->target=0;p->retry=5;}
        else if(target!=p->target){if(func_00388398(&p->grace)){p->target=0;p->retry=5;}}
        else {
            float distance,glow;
            p->grace=5;distance=func_003887C8(*(void **)(owner+0x2530),target+0x10)/150.0f;
            {u8 *hp=func_0037E0B8(target);p->scale=hp?*(float *)(hp+0x10):0.1f;}
            func_003886E8(&a,target+0xe0,p->scale);vec_add_ab(&a,target+0x10,&a);
            color=func_003894A0(0xff0fffff,0xff0f0fff,p->strength);
            glow=fabs_asm(0.9f-distance*0.65f);
            if(owner[0x1a14])func_L01_003F4D78(owner[0x24c9],o,color,&a,38,-1,4,glow,0.0f,90.0f,0.5f,0.5f,40.0f,40.0f);
            *(u8 **)(owner+0x1078)=target;
        }
    } else if(owner[0x1a14] && target==p->last) {
        if(func_00388398(&p->retry)) {
            p->target=target;p->grace=5;{u8 *hp=func_0037E0B8(target);p->scale=hp?*(float *)(hp+0x10):0.1f;}
        }
    } else p->retry=5;
    p->last=target;target=p->target;
    state=func_L39_00670988(owner+0x1a40,0,1,&d);
    if(state==8) {
        if(!o[0x43])func_003BE4F0(o,1,0,4);
        p->enabled=1;
        if(!target) {
            func_003886E8(&i,o+0xd0,-1.0f);vec_add_ab(&i,&i,o+0x10);
            func_003886E8(&j,o+0xc0,0.275f);vec_add_ab(&i,&i,&j);
            n=func_003CF790(&i,1,*(void **)(owner+0x2524),0,1.0f);
            if(n)for(x=0;x<n;x++) {
                target=D_L39_002638C0[x];health=func_0037E0B8(target);
                if(target[0x31] && *(s16 *)(target+0x32)>0 && target && target[0x20]!=254 && target[0x20]!=253 && *(s16 *)(target+0xaa)!=0xc87 && *(s16 *)(target+0xaa)!=0xecc && health && (*(float *)health>0.0f||func_L39_005B6970(target))) {
                    data=*(u8 **)(target+0x24);if(!data || data[0x46]!=5){target=*(u8 **)(D_L39_0025F840+0x18);p->target=target;break;}
                }
            }
        }
        func_L39_005F0CE0(0,0,o);p->count=15;func_L39_005487B8(o);func_L39_00549708(o,&d);func_L39_0061F5C0(owner,-1);
        func_003BE4F0(o,2,0,0);p->sound=func_L01_003F0118(D_L39_00470600,*(int *)(owner+0x2534));
        if(func_L39_00646268(owner,4))row=D_L39_0049C950+((s8 *)D_L39_0049C950)[0x221]*128;else row=D_L39_0049C950+0x200;
        p->timer=1.0f/(*(float *)(row+0x28));
    }else if(state==4 && p->enabled==1){func_L39_005F0CE0(1,0,o);p->enabled=0;}
    if((state!=8 || !owner[0x1a07]) && p->sound>=0){func_L01_003F0338(p->sound,*(int *)(owner+0x2534));p->sound=-1;}
    if(o[0x42]!=2 && p->count>0) {
        if(p->count>=13){q=(float)(15-p->count);s=q*0.3333333433f;t=(q*0.5f)*0.3333333433f;q=(q*0.8f)*0.3333333433f;}
        else{q=(float)p->count;s=q*0.08333333582f;t=(q*0.5f)*0.08333333582f;q=(q*0.8f)*0.08333333582f;}
        if(owner[0x1a08])func_003886E8(&j,o+0xd0,-1.0f);else j=*(vu0_v4 *)(owner+0x3b0);
        func_003BDA38(o,0,&i);vec_add_ba(&i,&i,&j);
        func_003886E8(&k,*(u8 **)(owner+0x2524)+0xe0,0.3f);vec_add_ab(&i,&i,&k);
        if(p->effect==-1)p->effect=func_L39_0059CF60(&i,8.0f,0.0f,s,q,t);
        else {Effect548 *ef=&D_L39_002668C0[p->effect];ef->pos=i;ef->c=t;ef->pos.w=8.0f;ef->a=s;ef->b=q;}
        func_003883C8(&p->count);
    } else if(p->effect!=-1){func_L01_00421FE0(p->effect);p->effect=-1;p->count=0;}
    if(o[0x43]==2){if(p->effect!=-1)func_L01_00421FE0(p->effect);p->effect=-1;p->count=0;}
}
/* localdecomp:end func_L39_00548BE0 */

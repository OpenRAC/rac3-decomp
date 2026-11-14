#include "common.h"
#include "vu0.h"
/* localdecomp:start func_L39_00570DF0 */
typedef vu0_v4 V;
typedef vu0_q Q;
typedef struct { char pad[0x20]; int state; s16 flag24,flag26; float rate,angle,yaw,d34,dist,along,height,turn; } Info;
typedef struct { V pos; int p10; float angle,yaw; Info *info; } Row;
typedef struct { char pad[0x84]; s16 index; char p86[14]; int id; } Obj;
typedef struct { s16 f0,f2; float f4,f8,fc,f10,f14,f18; char p1c[12]; float turn; } Sub20;
typedef struct { char v[16]; char pad[0xC0]; float height; } Sub60;
typedef struct { char a[16],b[16]; char p[12]; float dist,along; } Sub180;
typedef struct { char p[0x20]; V pos; int value; } Sub210;
typedef struct { V pos; char p10[16]; Sub20 s20; char p4c[0x14]; Sub60 s60; char p134[0x4C]; Sub180 s180; char p1b4[0x5C]; Sub210 s210; } Control;
typedef struct { char pad[0x30]; V pos; char p40[0x30]; Control *control; } Moby;
typedef struct { char pad[0x40]; V pos; char p50[0x30]; V dir; } Cam;
typedef struct { char pad[0x50]; Moby *moby; char p54[0xFC]; Cam cam; char pe0[0x280]; } Ent;
typedef struct {char p[0x1A0]; int mask;} Game;
extern Ent D_L39_0024DF80[];
extern Row *D_L39_0024B950;
__asm__(".extern D_L39_0024B950, 16");
extern Row *D_001E00C0_sda;
extern Game *D_L39_002412E4;
__asm__(".extern D_L39_002412E4, 16");
extern int D_001E03B4_sda;
extern int func_L39_00570BA8(Obj *),func_L01_003E6CA8(Obj *);
extern int func_L39_005C2098(int,int);
extern void func_L01_003E6C58(Obj *);
extern float func_00388A28(float,float),func_00389468(float,float),func_003893C8(float,float);
extern float func_00388730(void *,void *),func_00388770(void *);
extern void func_003886E8(void *,void *,float);
extern float func_00388978(float),func_00388960(float);
extern void func_L01_003E6D50(int,int,float,float),func_L01_003E6FF0(int),func_L01_003E6DA8(int,float,float),func_L01_003E6DF0(int,int,float,float);
extern void func_L01_003E6EC8(int,float),func_L01_003E6F00(int,int),func_L01_003E6E60(int,float,float,float);
void func_L39_00570DF0(Obj *o) {
    V pos,delta,temp,remainder;
    V *dir;
    Ent *ent=&D_L39_0024DF80[o->id];
    Info *info=D_L39_0024B950[o->index].info;
    Cam *cam=&ent->cam;
    float angle,dot,theta,tanvalue;
    if(func_L39_00570BA8(o)) {
        if(func_L01_003E6CA8(o)<=0) {
            if(info->state) info->flag26=1;
            info->state=0;
            return;
        }
        if((D_L39_002412E4->mask & func_L39_005C2098(4,0)) && D_001E03B4_sda>=11) {
            if(info->state) info->flag26=1;
            info->state=0;
            func_L01_003E6C58(o);
            return;
        }
    } else {
        if(info->state) info->flag26=1;
        info->state=0;
        func_L01_003E6C58(o);
        return;
    }
    if(info->state<2) {
        if(info->angle==0 && info->yaw==0) {
            info->angle=D_001E00C0_sda[o->index].angle;
            info->yaw=D_001E00C0_sda[o->index].yaw;
        }
        angle=func_00388A28(cam->pos.x-D_L39_0024B950[o->index].pos.x,cam->pos.y-D_L39_0024B950[o->index].pos.y);
        if(func_00389468(info->yaw,angle)>0.034906585f) info->turn=func_003893C8(info->yaw,angle);
        pos.x=D_L39_0024B950[o->index].pos.x;
        pos.y=D_L39_0024B950[o->index].pos.y;
        pos.z=D_L39_0024B950[o->index].pos.z;
        pos.w=0;
        dir=&cam->dir;
        vec_sub_ab(&delta,&pos,&cam->pos);
        dot=func_00388730(&delta,dir);
        func_003886E8(&temp,dir,dot);
        vec_sub_ab(&remainder,&delta,&temp);
        info->dist=func_00388770(&remainder);
        theta=info->angle;
        info->along=-dot;
        if(fabs_asm(theta)==1.57079637f) info->height=0;
        else {
            tanvalue=func_00388978(theta);
            tanvalue=tanvalue/func_00388960(theta);
            info->height=info->along-info->dist*tanvalue;
        }
        {
            Moby *m=ent->moby;
            Control *c;
            Q cameraPos;
            Sub180 *a; Sub20 *b; Sub60 *d; Sub210 *e;
            *(Q*)&m->pos=*(Q*)&pos;
            c=m->control;
            a=&c->s180;
            b=&c->s20;
            d=&c->s60;
            e=&c->s210;
            a->dist=info->dist; a->along=info->along;
            b->turn=info->turn; d->height=info->height;
            func_003886E8(&temp,&cam->dir,-a->along);
            vec_add_ba((char*)c+0xB0,&cam->pos,&temp);
            vec_sub_ba(&a->a,&pos,(char*)c+0xB0);
            *(Q*)((char*)c+0x190)=*(Q*)((char*)c+0x180);
            func_003886E8(&temp,&cam->dir,-d->height);
            vec_add_ab((char*)c+0xA0,&cam->pos,&temp);
            *(Q*)((char*)c+0x110)=*(Q*)((char*)c+0xA0);
            cameraPos=*(Q*)&cam->pos;
            *(Q*)((char*)c+0x60)=cameraPos;
            *(Q*)((char*)c+0xC0)=cameraPos;
            *(Q*)&c->pos=*(Q*)&m->pos;
            *(Q*)((char*)c+0x230)=*(Q*)&m->pos;
            e->value=0; b->f14=0;
            b->f4=d->height; b->f8=a->along; b->f2=0;
            b->f18=b->f14; b->f10=b->f14; b->fc=b->f14;
        }
    }
    if(++info->state>200)info->state=200;
    if(info->dist!=0) {func_L01_003E6D50(o->id,0,info->dist,0.003f);func_L01_003E6FF0(o->id);}
    if(info->along!=0)func_L01_003E6DA8(o->id,info->along,0.003f);
    if(info->height!=0)func_L01_003E6DF0(o->id,0,info->height,0.005f);
    if(info->rate!=0)func_L01_003E6EC8(o->id,info->rate*0.017453292f);
    if(info->flag24==0)func_L01_003E6F00(o->id,0);
    if(info->turn!=0)func_L01_003E6E60(o->id,info->turn,60,60);
}
/* localdecomp:end func_L39_00570DF0 */

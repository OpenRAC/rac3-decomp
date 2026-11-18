#include "common.h"
#include "vu0.h"

typedef int s128 __attribute__((mode(TI)));
typedef struct {
    u8 pad0[0x28];
    s32 w28;
} S_311A18m;
typedef struct {
    u8 pad0[0x10];
    s128 q10;
    u8 b20;
    u8 pad21[0x68 - 0x21];
    S_311A18m *p68;
    u8 pad6C[0xAA - 0x6C];
    s16 hAA;
} S_311A18;


/* localdecomp:start func_L01_00312DD8 */
typedef vu0_v4 V;
typedef vu0_q Q;
typedef struct { V axis,dir,pos; char p30[8]; int active; float size; int n0,n1; } Source;
typedef struct { V pos,dir; float f20,f24,f28,f2c,f30,f34,f38,f3c,f40,f44,f48,f4c; int f50,f54,f58,f5c,f60,color64,color68,color6c,mode,f74,type; Source *owner; } Particle;
extern Particle *D_L01_001E1734;
__asm__(".extern D_L01_001E1734, 16");
extern int func_00382498(int,int);
extern float func_00382538(void),func_003824E0(float,float),func_L01_00443A18(float,float);
extern void func_0038D890(void *,void *,void *,float),func_0038CF68(void *,void *,float);

Particle *func_L01_00312DD8(Source *source,int type,V *point,float angle) {
    V temp,temp2;
    int i,c0,c1,c2;
    Particle *p;
    for(i=0;i<320;i++) {
        if(D_L01_001E1734[i].owner)continue;
        switch(type) {
        case 0:
            if(++source->n0==150) {source->n0--;return 0;}
            break;
        case 1:
            if(++source->n1==150) {source->n1--;return 0;}
            break;
        }
        p=&D_L01_001E1734[i];
        p->owner=source;
        source->active++;
        p->f5c=p->f60=func_00382498(95,127);p->type=type;
        if(type==0) {
            func_0038D890(&p->dir,&source->dir,&source->axis,func_00382538());
            p->f3c=p->f38=source->size*func_003824E0(0,1.25f);
            p->f40=0;
            c0=func_00382498(0,13);
            p->color6c=(c0<<16)+(c0<<8)+c0;
            p->f48=p->f44=func_003824E0(0.25f,0.35f);
            p->f4c=func_003824E0(0.75f,1);
            p->f24=0;
            p->f58=p->f54=func_00382498(83,100);
            *(Q*)&p->pos=*(Q*)&p->owner->pos;
            func_0038CF68(&temp,&p->dir,func_003824E0(0.15f,0.75f));
            vec_add_ab(&p->pos,&temp,&p->pos);
            p->mode=2;p->f30=0;
        } else if(type==1) {
            func_0038D890(&p->dir,&source->dir,&source->axis,func_00382538());
            p->f40=p->f3c=p->f38=0.0f;
            c1=func_00382498(0,13);
            p->color6c=(c1<<16)+(c1<<8)+c1;
            p->f48=p->f44=func_003824E0(0.25f,0.5f);
            p->f4c=func_003824E0(1,1.5f);
            p->f24=func_003824E0(0.080000006f,0.10000001f);
            p->f58=p->f54=func_00382498(83,100);
            *(Q*)&p->pos=*(Q*)point;p->mode=2;p->f30=0;
        } else if(type==2) {
            func_0038D890(&p->dir,&source->dir,&source->axis,angle);
            p->f40=p->f3c=p->f38=0.0f;
            c2=func_00382498(1,10);
            p->color6c=(c2<<16)+(c2<<8)+c2;
            p->f48=p->f44=func_003824E0(0.15f,0.25f)*0.5f;
            p->f4c=func_003824E0(0.5f,0.8f)*1.15f;
            p->f24=0.07000001f;
            p->f58=p->f54=75;
            func_0038CF68(&temp,p->owner,0.2f);
            vec_add_ba(&p->pos,&p->owner->pos,&temp);
            func_0038CF68(&temp2,&p->dir,0.75f);
            vec_add_ab(&p->pos,&temp2,&p->pos);
            p->f30=func_L01_00443A18(0.06283186f,0.12566371f);
            p->mode=type;
        }
        p->color68=p->color64=0x103080;
        p->f20=0.00080000004f;
        p->f2c=p->f28=func_L01_00443A18(0.37699115f,0.4276057f);
        p->f34=func_00382538();
        p->f74=0;
        return p;
    }
    return 0;
}
/* localdecomp:end func_L01_00312DD8 */

INCLUDE_ASM("asm/levels", func_L01_00313270);

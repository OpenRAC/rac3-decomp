#include "common.h"

/* NTSC-U counterpart of func_L01_00312DD8 (src/levels/shared/L01_00312DD8.c) */
#include "vu0.h"

/* localdecomp:start func_L01_00312AE8 */
typedef vu0_v4 V;
typedef vu0_q Q;
typedef struct { V axis,dir,pos; char p30[8]; int active; float size; int n0,n1; } Source;
typedef struct { V pos,dir; float f20,f24,f28,f2c,f30,f34,f38,f3c,f40,f44,f48,f4c; int f50,f54,f58,f5c,f60,color64,color68,color6c,mode,f74,type; Source *owner; } Particle;
extern Particle *D_L01_001E17B4;
__asm__(".extern D_L01_001E17B4, 16");
extern int func_0037E208(int,int);
extern float func_0037E2A8(void),func_0037E250(float,float),func_L01_00440918(float,float);
extern void func_00389158(void *,void *,void *,float),func_00388830(void *,void *,float);

Particle *func_L01_00312AE8(Source *source,int type,V *point,float angle) {
    V temp,temp2;
    int i,c0,c1,c2;
    Particle *p;
    for(i=0;i<320;i++) {
        if(D_L01_001E17B4[i].owner)continue;
        switch(type) {
        case 0:
            if(++source->n0==150) {source->n0--;return 0;}
            break;
        case 1:
            if(++source->n1==150) {source->n1--;return 0;}
            break;
        }
        p=&D_L01_001E17B4[i];
        p->owner=source;
        source->active++;
        p->f5c=p->f60=func_0037E208(95,127);p->type=type;
        if(type==0) {
            func_00389158(&p->dir,&source->dir,&source->axis,func_0037E2A8());
            p->f3c=p->f38=source->size*func_0037E250(0,1.25f);
            p->f40=0;
            c0=func_0037E208(0,13);
            p->color6c=(c0<<16)+(c0<<8)+c0;
            p->f48=p->f44=func_0037E250(0.25f,0.35f);
            p->f4c=func_0037E250(0.75f,1);
            p->f24=0;
            p->f58=p->f54=func_0037E208(100,120);
            *(Q*)&p->pos=*(Q*)&p->owner->pos;
            func_00388830(&temp,&p->dir,func_0037E250(0.15f,0.75f));
            vec_add_ab(&p->pos,&temp,&p->pos);
            p->mode=2;p->f30=0;
        } else if(type==1) {
            func_00389158(&p->dir,&source->dir,&source->axis,func_0037E2A8());
            p->f40=p->f3c=p->f38=0.0f;
            c1=func_0037E208(0,13);
            p->color6c=(c1<<16)+(c1<<8)+c1;
            p->f48=p->f44=func_0037E250(0.25f,0.5f);
            p->f4c=func_0037E250(1,1.5f);
            p->f24=func_0037E250(0.0666666701f,0.0833333358f);
            p->f58=p->f54=func_0037E208(100,120);
            *(Q*)&p->pos=*(Q*)point;p->mode=2;p->f30=0;
        } else if(type==2) {
            func_00389158(&p->dir,&source->dir,&source->axis,angle);
            p->f40=p->f3c=p->f38=0.0f;
            c2=func_0037E208(1,10);
            p->color6c=(c2<<16)+(c2<<8)+c2;
            p->f48=p->f44=func_0037E250(0.15f,0.25f)*0.5f;
            p->f4c=func_0037E250(0.5f,0.8f)*1.15f;
            p->f24=0.0583333373f;
            p->f58=p->f54=90;
            func_00388830(&temp,p->owner,0.2f);
            vec_add_ba(&p->pos,&p->owner->pos,&temp);
            func_00388830(&temp2,&p->dir,0.75f);
            vec_add_ab(&p->pos,&temp2,&p->pos);
            p->f30=func_L01_00440918(0.0523598827f,0.104719765f);
            p->mode=type;
        }
        p->color68=p->color64=0x103080;
        p->f20=0.000555555569f;
        p->f2c=p->f28=func_L01_00440918(0.314159274f,0.356338084f);
        p->f34=func_0037E2A8();
        p->f74=0;
        return p;
    }
    return 0;
}
/* localdecomp:end func_L01_00312AE8 */

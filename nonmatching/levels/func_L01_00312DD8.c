/* NTSC-U draft (2026-11-14, Codex worker): C of func_L01_00312AE8, the NTSC-U twin of func_L01_00312DD8, with NTSC-U names
 * and addresses. Byte-exact on NTSC-U with "-O2 -G8 -fopt-stack -mno-check-zero-division -mno-split-addresses" (src/levels/shared/L01_00312DD8.c's line: "-O2 -G8 -fopt-stack -mno-check-zero-division -mno-split-addresses").
 */
#include "common.h"
#include "vu0.h"
/* localdecomp:start func_L01_00312AE8 */
typedef vu0_v4 V;
typedef vu0_q Q;
typedef struct { V axis,dir,pos; char p30[8]; int active; float size; int n0,n1; } Source;
typedef struct { V pos,dir; float f20,f24,f28,f2c,f30,f34,f38,f3c,f40,f44,f48,f4c; int f50,f54,f58,f5c,f60,color64,color68,color6c,mode,f74,type; Source *owner; } Particle;
extern Particle *D_L01_001E17B4;
__asm__(".extern D_L01_001E17B4, 16");
extern Particle *D_001E17B4_sda;
extern int func_0037E208(int,int);
extern float func_0037E2A8(void),func_0037E250(float,float),func_L01_00440918(float,float);
extern void func_00389158(void *,void *,void *,float),func_00388830(void *,void *,float);

/* Complete VU0 sequences use fixed VU clobbers because this file does not enable
 * the compiler's VU register allocator. All scalar instructions remain C. */
static __inline__ void add12(void *d,void *a,void *b) {
    __asm__("lqc2 $vf1,%1\n\tlqc2 $vf2,%2\n\tvadd.xyz $vf1,$vf1,$vf2\n\tsqc2 $vf1,%0"
        : "=m"(*(V*)d) : "m"(*(V*)a),"m"(*(V*)b) : "vf1","vf2");
}
static __inline__ void add21(void *d,void *a,void *b) {
    __asm__("lqc2 $vf2,%2\n\tlqc2 $vf1,%1\n\tvadd.xyz $vf1,$vf1,$vf2\n\tsqc2 $vf1,%0"
        : "=m"(*(V*)d) : "m"(*(V*)a),"m"(*(V*)b) : "vf1","vf2");
}
static __inline__ void add21r(void *d,void *a,void *b) {
    __asm__("lqc2 $vf2,%1\n\tlqc2 $vf1,%2\n\tvadd.xyz $vf2,$vf2,$vf1\n\tsqc2 $vf2,%0"
        : "=m"(*(V*)d) : "m"(*(V*)a),"m"(*(V*)b) : "vf1","vf2");
}

Particle *func_L01_00312AE8(Source *source,int type,V *point,float angle) {
    V temp,temp2;
    int i,color;
    Particle *p;
    for(i=0;i<320;i++) {
        if(D_L01_001E17B4[i].owner)continue;
        if(type==0) {
            if(++source->n0==150) {source->n0--;return 0;}
        }else if(type==1) {
            if(++source->n1==150) {source->n1--;return 0;}
        }
        p=&D_L01_001E17B4[i];
        p->owner=source;
        source->active++;
        p->f5c=func_0037E208(95,127);p->f60=p->f5c;p->type=type;
        if(type==0) {
            func_00389158(&p->dir,&source->dir,&source->axis,func_0037E2A8());
            p->f38=p->f3c=source->size*func_0037E250(0,1.25f);
            p->f40=0;
            color=func_0037E208(0,13);
            p->color6c=(color<<16)+(color<<8)+color;
            p->f44=p->f48=func_0037E250(0.25f,0.35f);
            p->f4c=func_0037E250(0.75f,1);
            p->f24=0;
            p->f54=p->f58=func_0037E208(100,120);
            *(Q*)&p->pos=*(Q*)&p->owner->pos;
            func_00388830(&temp,&p->dir,func_0037E250(0.15f,0.75f));
            add12(&p->pos,&temp,&p->pos);
            p->mode=2;p->f30=0;
        } else if(type==1) {
            func_00389158(&p->dir,&source->dir,&source->axis,func_0037E2A8());
            p->f38=0;p->f3c=0;p->f40=0;
            color=func_0037E208(0,13);
            p->color6c=(color<<16)+(color<<8)+color;
            p->f44=p->f48=func_0037E250(0.25f,0.5f);
            p->f4c=func_0037E250(1,1.5f);
            p->f24=func_0037E250(1.0f/15.0f,1.0f/12.0f);
            p->f54=p->f58=func_0037E208(100,120);
            *(Q*)&p->pos=*(Q*)point;p->mode=2;p->f30=0;
        } else if(type==2) {
            func_00389158(&p->dir,&source->dir,&source->axis,angle);
            p->f38=0;p->f3c=0;p->f40=0;
            color=func_0037E208(1,10);
            p->color6c=(color<<16)+(color<<8)+color;
            p->f44=p->f48=func_0037E250(0.15f,0.25f)*0.5f;
            p->f4c=func_0037E250(0.5f,0.8f)*1.15f;
            p->f24=0.05833333730697632f;
            p->f54=p->f58=90;
            func_00388830(&temp,p->owner,0.2f);
            add21(&p->pos,&p->owner->pos,&temp);
            func_00388830(&temp2,&p->dir,0.75f);
            add21r(&p->pos,&temp2,&p->pos);
            p->f30=func_L01_00440918(0.05235988274216652f,0.10471976548433304f);
            p->mode=type;
        }
        p->color64=p->color68=0x103080;
        p->f20=0.0005555555690079927f;
        p->f28=p->f2c=func_L01_00440918(0.3141592741012573f,0.3563380837440491f);
        p->f34=func_0037E2A8();
        p->f74=0;
        return p;
    }
    return 0;
}
/* localdecomp:end func_L01_00312AE8 */

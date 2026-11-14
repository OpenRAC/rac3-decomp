/* NTSC-U draft (2026-11-14, Codex worker): C of func_L39_0051DF48, the NTSC-U twin of func_L39_0051E370, with NTSC-U names
 * and addresses. Byte-exact on NTSC-U with "-O2 -G8 -fopt-stack -mno-check-zero-division -mno-split-addresses" when tried; not with src/levels/shared/L39_0051E200.c's current line.
 * Worker's note: 350 diff; best log first-06.log; VU0 real sequences; stack/register scheduling and literal pool vs inline constants differ 350 diff; permitted GNU assembler uses lit4 for 0.6666666865, 0.45, 0.001, 5627.925 and 0.04 while retail synthesizes inline; no flags_alt; VU0/register/address scheduling also 
 */
#include "common.h"
#include "vu0.h"
static __inline__ void vec_add_ab95(void *d, void *a, void *b) {
 __asm__("lqc2 $vf1, %1\n\tlqc2 $vf2, %2\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0" : "=m"(*(vu0_v4 *)d) : "m"(*(vu0_v4 *)a), "m"(*(vu0_v4 *)b) : "vf1", "vf2");
}
static __inline__ void vec_add_ba95(void *d, void *a, void *b) {
 __asm__("lqc2 $vf2, %2\n\tlqc2 $vf1, %1\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0" : "=m"(*(vu0_v4 *)d) : "m"(*(vu0_v4 *)a), "m"(*(vu0_v4 *)b) : "vf1", "vf2");
}
static __inline__ void vec_sub_ab95(void *d, void *a, void *b) {
 __asm__("lqc2 $vf1, %1\n\tlqc2 $vf2, %2\n\tvsub.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0" : "=m"(*(vu0_v4 *)d) : "m"(*(vu0_v4 *)a), "m"(*(vu0_v4 *)b) : "vf1", "vf2");
}
/* localdecomp:start func_L39_0051DF48 */
typedef struct { u8 pad[16]; vu0_v4 pos; u8 state; u8 p21[19]; u16 flags; u8 p36[50]; void *priv; u8 p6c[62]; s16 cls; } Obj;
typedef struct { vu0_v4 v; float phase; int timer; float speed; int alpha; int p20; int life; int handle; int damage; u8 *owner; u8 pad[12]; vu0_v4 dir; } Priv;
typedef struct { u8 pad[0x20]; float f; u8 p24[4]; int a,b; u8 p30[0x430]; } Row;
extern Row D_L39_0024DF80[];
extern u8 *D_L39_0024CF20[];
extern Obj *D_L39_002638C0[];
extern u8 D_L39_0049C950[], D_L39_0049CBD0[], D_L39_0051F250[];
extern float D_001DF114_sda, D_001DF110_sda;
extern int func_L01_00454168(int,int);
extern void func_003BD360(Obj *);
extern int func_L01_00453FC0(Obj *,int,void *);
extern void func_L01_00454190(int,int);
extern void func_L39_0051EB60(Obj *,void *);
extern int func_L39_005BC958(void *,int,float);
extern void func_00388830(void *,void *,float);
extern void func_L39_005FD658(int),func_L39_005FD6D8(void);
extern int func_003CF790(void *,int,Obj *,int,float);
extern int func_0037E0B8(Obj *),func_L01_004435E8(Obj *);
extern int func_003CE740(void *,void *,int,Obj *,int);
extern int func_L39_00646268(void *,int);
extern void func_L01_00443628(void *,Obj *,int,void *,float);
extern void func_L01_00443840(Obj *,void *);
extern int func_00388398(int *);
extern void func_L01_004026A0(void *,Obj *);
void func_L39_0051DF48(Obj *o) {
    vu0_v4 a,b,c,d,e;
    struct { vu0_v4 v; u8 pad[8]; u8 x,y; u16 cls; int p2c; int one; int p34; int damage; } hit;
    u8 scratch[16];
    Priv *p=o->priv;
    int n,id; Obj **it; float t; u8 *row;
    if(o->state && !func_L01_00454168(o->cls,p->handle)) { func_003BD360(o); return; }
    switch(o->state) {
    case 0:
        o->state=1; p->phase=0; p->timer=20; p->speed=0.6666666865f; p->alpha=127; p->life=111;
        p->handle=func_L01_00453FC0(o,0,scratch);
        func_L01_00454190(o->cls,p->handle);
        a=o->pos; a.z+=1.0f; func_L39_0051EB60(o,&o->pos);
        if(p->owner) { b=a; b.w=2.0f; if(func_L39_005BC958(&b,0,100.0f)!=-1) {
            D_L39_0024DF80[p->owner[0x24c9]].f=0.45f;
            D_L39_0024DF80[p->owner[0x24c9]].a=40;
            D_L39_0024DF80[p->owner[0x24c9]].b=0;
        }}
    case 1:
        p->life-=5; if(p->life<0)p->life=0;
        p->phase+=p->speed;
        func_00388830(&b,&p->dir,(1.0f-(float)p->timer/20.0f)*10.0f);
        vec_add_ab95(&b,&b,&o->pos);
        t=(1.0f-(float)p->timer/20.0f)*12.0f+0.001f;
        row=D_L39_0024CF20[*(int *)(p->owner+0x2544)]; id=-1; if(row)id=*(int *)(row+0x2548);
        func_L39_005FD658(id);
        n=func_003CF790(&b,0,o,0,t); func_L39_005FD6D8();
        if(n>0) { it=D_L39_002638C0; do {
            if((func_0037E0B8(*it)||((*it)->flags&0x4000)) &&
               ((p->owner && *it!=*(Obj **)(p->owner+0x2524)) || (*it)->cls==0x1068) && (*it)->cls!=0xa5a) {
                func_00388830(&c,&p->dir,-1.0f);
                vec_add_ba95(&d,&c,&o->pos); vec_add_ab95(&e,&c,&(*it)->pos);
                if((*it)->cls==0x1c57||(*it)->cls==0x1a63)vec_add_ab95(&e,&e,&c);
                if(func_L01_004435E8(*it)||!func_003CE740(&d,&e,2,*it,0)) {
                    if((*it)->cls==0x1e41 || !(4.0f < fabs_asm(o->pos.z-(*it)->pos.z))) {
                        vec_sub_ab95(&c,&(*it)->pos,&o->pos); func_00388830(&c,&c,1.0f);
                        func_00388830(&hit,&c,1.0f);
                        if(func_L39_00646268(p->owner,5))row=D_L39_0049C950+((s8 *)D_L39_0049CBD0)[0x21]*128;
                        else row=D_L39_0049C950+0x280;
                        func_L01_00443628(&hit,o,0x1030001,&c,*(float *)(row+0x34));
                        hit.v=c; hit.one=1; hit.v.w=5627.925f; hit.x=5; hit.y=3; hit.cls=(*it)->cls; hit.damage=p->damage;
                        func_L01_00443840(*it,&hit);
                    }
                }
            }
            --n; ++it;
        }while(n); }
        if(func_00388398(&p->timer)){o->state=2;p->timer=40;} break;
    case 2:
        p->phase+=p->speed; t=(float)p->timer/40.0f;
        if(func_00388398(&p->timer)) { if(p->alpha)p->alpha--;else {p->alpha=0;o->state=6;} }
        else p->alpha=(int)(t*127.0f);
        break;
    case 6: p->phase+=p->speed;func_003BD360(o);return;
    }
    D_001DF114_sda-=0.04f;
    if(D_001DF110_sda < -8.0f)D_001DF110_sda+=8.0f;
    if(D_001DF114_sda < -8.0f)D_001DF114_sda+=8.0f;
    func_L01_004026A0(D_L39_0051F250,o);
}
/* localdecomp:end func_L39_0051DF48 */

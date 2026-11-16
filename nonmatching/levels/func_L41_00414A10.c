/* NTSC-U draft (Codex wave 3): C of func_L41_00414160, the NTSC-U twin of func_L41_00414A10, with NTSC-U names and addresses (the two versions' code differs).
 * near miss: 66 words differ on NTSC-U with "-O2 -G8 -fopt-stack -mno-check-zero-division" (the file's line: "-O2 -G8 -fopt-stack -mno-check-zero-division @ps2as") (NTSC-U twin "func_L41_00414160", whose code is not the PAL one).
 * Worker's note: 66 diff (improved from 73); final vector copy/call scheduling fixed; eight checks, three formulations retain 66 diff; loop base/table address hoisting and lookup registers remain; best log w111/func_L41_00414160.05.log
 */
#include "common.h"
/* localdecomp:start func_L41_00414160 */
typedef unsigned int Q __attribute__((mode(TI)));
typedef struct P {char pad[112];int slots[5];int interval;char p88[8];int timer;int x94;int token;int x9c;int arg;int values[5];int xb8;int group;} P;
typedef struct O {char pad[16];Q pos;u8 state;char p21[15];u8 opacity;char p31[55];P *data;} O;
extern int func_L40_0053B018(int,void *,void *,void *);
extern void func_L41_003EFA30(void),func_L41_003EDD88(void),func_L41_003ED540(void);
extern u16 *D_L41_0028ECE0[];
extern int D_L41_00248818[];
extern int D_001DCF88_sda;
typedef struct { u8 bytes[256]; } M;
extern M *D_L41_002487DC[];
extern void func_L39_00619A68(void *,int);
extern int func_003CF790(float,void *,int,int,int);
extern int D_L41_0025BC58[];
extern u8 D_001A5E50[];
extern void func_L41_00414050(int *,int *);
extern int func_L41_00414130(P *);
extern int func_00388398(int *);
extern int func_L41_004140D0(O *);
extern int func_L41_003ED228(void *,int,int,int *,int,int,int);
void func_L41_00414160(O *o) {
 struct { Q q; } pos; P *p=o->data;int i;u16 *list;void *m;
 o->opacity=255;
 if(o->state==0) {
  for(i=0;i<5;i++) {p->slots[i]=0;p->values[i]=0;func_L40_0053B018(0x109d,func_L41_003EFA30,func_L41_003EDD88,func_L41_003ED540);}
  {int sentinel=255;u16 **base=D_L41_0028ECE0;
  list=base[p->group];
  if((p->group&255)!=sentinel && p->group<=D_L41_00248818[0] && list) {
   do {
    m=&D_L41_002487DC[0][*list&0x7fff];
    if(!m)break;
    func_L39_00619A68(m,-1);list++;
    if((p->group&255)==sentinel || p->group>D_001DCF88_sda || !list)break;
   }while((s16)list[-1]>=0 || list==base[p->group]);
  }
  }
  if(p->interval<=0)p->interval=30;
  if(func_003CF790(3.0f,&o->pos,1,0,0))p->token=D_L41_0025BC58[0];
  o->state=1;
 }
 if(D_001A5E50[0x168]) {
  for(i=0;i<5;i++)func_L41_00414050(&p->values[i],&p->slots[i]);
  if(func_L41_00414130(p))func_00388398(&p->timer);
  if(p->timer>0)return;
  if(func_L41_004140D0(o)) {
   if(func_003CF790(3.0f,&o->pos,1,p->token,0))return;
   pos.q=o->pos;func_L41_003ED228(&pos,p->group,-1,p->slots,-1,p->arg,-1);
  }else return;
 }
 p->timer=(int)((float)p->interval*60.0f);
}
/* localdecomp:end func_L41_00414160 */

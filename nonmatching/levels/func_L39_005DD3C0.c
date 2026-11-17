/* NTSC-U draft (2026-11-14, Codex worker): C of func_L39_005DAE18, the NTSC-U twin of func_L39_005DD3C0, with NTSC-U names
 * and addresses. Near miss on NTSC-U: 3 words differ with its file's flags.
 */
#include "common.h"
#include "vu0.h"
/* localdecomp:start func_L39_005DAE18 */
typedef unsigned int Q __attribute__((mode(TI)));
typedef union V {Q q;float f[4];} V;
typedef struct Pad {char p[452];int buttons;} Pad;
typedef struct State {char p[3168];int special,player;} State;
typedef struct Hero {char pad[9417];u8 id;char p24ca[106];Pad *padptr;char p2538[16];int team;char p254c[12];State *state;} Hero;
typedef struct Table {char pad[64];int special[8];int ids[8];char p80[40];int teams[8];char pc8[312];void *data;} Table;
typedef struct Lobby {char pad[524];Table *table;} Lobby;
extern Lobby D_L39_00352A40;
extern Table *D_L39_00352C4C[];
extern u8 *D_L39_0024C05C;__asm__(".extern D_L39_0024C05C, 16");
extern int D_L39_0024C500[];
extern void func_L39_005DACE8(Hero *,float *,float *);
extern int func_L08_004EA298(int);
extern void func_00388830(void *,void *,float);
extern void func_L01_0044E108(void *,float *,float *);
extern float func_00388730(void *,void *);
extern float func_00388990(float);
extern float func_L01_0040C018(void *,void *);
extern int func_L39_005DACB0(Hero *);
void func_L39_005DAE18(Hero *h) {
 V dir,origin,target,delta;int moving;int player,special;int i,cur;u8 *m;float best,angle,distance,dot,score;vu0_q va,vb;
 qzero(&dir);
 if(h->padptr->buttons&0x4000)dir.f[1]=1.0f;else if(h->padptr->buttons&0x1000)dir.f[1]=-1.0f;
 if(h->padptr->buttons&0x8000)dir.f[0]=-1.0f;else if(h->padptr->buttons&0x2000)dir.f[0]=1.0f;
 moving=0;if(dir.f[0]!=0.0f || dir.f[1]!=0.0f)moving=1;
 qzero(&origin);func_L39_005DACE8(h,&origin.f[0],&origin.f[1]);
 if(moving)D_L39_0024C500[h->id]=12;
 if(!moving) {
   if(!func_L08_004EA298(h->state->player))return;
   goto search;
 }
 func_00388830(&dir,&dir,1.0f);
 search:
 best=100000.0f;player=-1;special=-1;
 for(i=0;i<8;i++) {
  float dot,angle,distance,score;
  if(i==h->state->player)continue;
  if(D_L39_00352A40.table->ids[i]<0 || D_L39_00352A40.table->teams[i]!=h->team)continue;
  m=D_L39_0024C05C+D_L39_00352A40.table->ids[i]*256;
  if(func_L08_004EA298(i))continue;
  qzero(&target);func_L01_0044E108(m,&target.f[0],&target.f[1]);
  __asm__("lqc2 %0,%1":"=j"(va):"m"(*(vu0_v4 *)&target));
  __asm__("lqc2 %0,%1":"=j"(vb):"m"(*(vu0_v4 *)&origin));
  __asm__("vsub.xyz %0,%0,%1":"+j"(va):"j"(vb));
  __asm__("sqc2 %1,%0":"=m"(*(vu0_v4 *)&delta):"j"(va));
  func_00388830(&delta,&delta,1.0f);dot=func_00388730(&dir,&delta);
  if(dot>0.0f || moving==0) {
   angle=fabs_asm(1.570796371f-func_00388990(dot));
   distance=func_L01_0040C018(&origin,&target)*100.0f;
   angle*=100.0f;score=distance+distance*angle;
   if(player==-1 || score<best){best=score;player=i;}
  }
 }
 cur=h->state->special;
 if(cur==-1) {
  i=func_L39_005DACB0(h);
  m=D_L39_0024C05C+D_L39_00352C4C[0]->special[i]*256;
  qzero(&target);func_L01_0044E108(m,&target.f[0],&target.f[1]);
  vec_sub_ab(&delta,&target,&origin);
  func_00388830(&delta,&delta,1.0f);dot=func_00388730(&dir,&delta);
  if(0.0f<dot) {
   angle=fabs_asm(1.570796371f-func_00388990(dot));
   distance=func_L01_0040C018(&origin,&target)*100.0f;
   angle*=100.0f;score=distance+distance*angle;
   if(player==cur || score<best){special=i;player=-1;}
  }
 }
 if(func_L08_004EA298(h->state->player)){h->state->player=-1;h->state->special=special;}
 if(player!=-1){h->state->player=player;h->state->special=-1;}
 else if(special!=player){h->state->player=player;h->state->special=special;}
}
/* localdecomp:end func_L39_005DAE18 */

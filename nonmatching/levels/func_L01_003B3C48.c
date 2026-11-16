/* NTSC-U draft (Codex wave 3): C of func_L01_003B2450, the NTSC-U twin of func_L01_003B3C48, with NTSC-U names and addresses (the two versions' code differs).
 * near miss: 182 words differ on NTSC-U with the file's flags (NTSC-U twin "func_L01_003B2450", whose code is not the PAL one).
 * Worker's note: 182 diff; improved 185 to 182 by separate final-loop cursor lifetime; 4 checks; 02-03 same 182 diff; explicit group locals regress to 196; permitted no-split flags emit la full table base saved in s3 vs retail saved high base and addiu inside loops; ...
 */
#include "common.h"
/* localdecomp:start func_L01_003B2450 */
typedef struct Obj Obj;
typedef struct { char pad[0x58]; Obj *next; char p5c[4]; int time; } State;
struct Obj { char p0[0x20]; unsigned char state; char p21[0x47]; State *p; char p6c[0x94]; };
typedef struct { int zero,time; Obj *obj; int group; char p10[0x6c]; int timeout,timeout2,check,first,second,single,all,dead,other; float val; int count; float val2; int count2; } Cond;
extern int D_L01_001DFBC0[];
extern Obj *D_L01_001E009C[];
extern short *D_L01_0021DEA0[];
__asm__(".extern D_L01_0021DEA0, 16");
extern int D_001E00D8_sda;
extern Obj *D_001DE674_sda;
extern Obj *D_001E009C_sda;
extern char D_001A4C60[];
extern int func_L01_003B4368(Obj*),func_L01_003B4388(Obj*,int),func_L01_003B4710(Obj*),func_L01_003B4730(Obj*,int);
extern float func_L01_003B4480(Obj*,int,int,int,int),func_L01_003B4760(Obj*,int);
extern int func_L01_003B46F0(Obj*,int),func_L01_003B47C8(Obj*,int);
extern int func_L01_00453210(void*,int),func_L01_00452F60(Obj*),func_L01_00442998(int,int,int);
int func_L01_003B2450(void *unused,Cond *c) {
 Obj *o; State *init=c->obj->p; State *p; short *q; int n,n2,total,total2,ok;float sum,sum2,v;
 if(c->timeout && c->timeout*60<D_L01_001DFBC0[0]-c->time)return 1;
 if(c->timeout2 && c->timeout2*60<D_L01_001DFBC0[0]-init->time)return 1;
 if(c->first) {
 q=D_L01_0021DEA0[c->group];
 goto test0; do {
 o=(Obj*)((char*)D_L01_001E009C[0]+((q[0]&32767)<<8));if(!o)break;
 if(func_L01_003B4368(o) && func_L01_003B4388(o,1))return 1;
 q++; test0: if((c->group&255)==255 || c->group>D_001E00D8_sda || !q)break;
 }while(q[-1]>=0 || q==D_L01_0021DEA0[c->group]);
 }
 if(c->second) {
 q=D_L01_0021DEA0[c->group];
 goto test1; do {
 o=(Obj*)((char*)D_L01_001E009C[0]+((q[0]&32767)<<8));if(!o)break;
 if(func_L01_003B4710(o) && func_L01_003B4730(o,1))return 1;
 q++; test1: if((c->group&255)==255 || c->group>D_001E00D8_sda || !q)break;
 }while(q[-1]>=0 || q==D_L01_0021DEA0[c->group]);
 }
 o=D_001DE674_sda;
 if(o) {
 sum2=0;total=0;total2=0;n=0;n2=0;sum=0;
 do { p=o->p;
 if(func_L01_003B4368(o)) {
 if(c->val>=0) {v=func_L01_003B4480(o,1,1,0,0);if(v>=0){sum+=v;n++;}}
 else if(c->count>=0) {total+=func_L01_003B46F0(o,1);n++;}
 else if(func_L01_003B4388(o,1))return 1;
 } else if(func_L01_003B4710(o)) {
 if(c->val2>=0) {sum2+=func_L01_003B4760(o,1);n2++;}
 else if(c->count2<0) {if(func_L01_003B4730(o,1))return 1;}
 else {total2+=func_L01_003B47C8(o,1);n2++;}
 }
 o=p->next;
 }while(o);
 if(c->val>=0){if(n>=2)sum/=n;if(c->val<=sum)return 1;}else if(c->count>=0 && total>=c->count)return 1;
 if(c->val2>=0){if(n2>=2)sum2/=n2;if(c->val2<=sum2)return 1;}else if(c->count2>=0 && total2>=c->count2)return 1;
 }
 if(c->check!=-1 && func_L01_00453210(D_001A4C60,c->check))return 1;
 if(c->single!=-1 && func_L01_00452F60(D_001E009C_sda+c->single))return 1;
 if(c->all!=-1) {
 Obj *candidate; short *allq;
 ok=1;allq=D_L01_0021DEA0[c->all];
 goto test2; do {
 candidate=(Obj*)((char*)D_L01_001E009C[0]+((allq[0]&32767)<<8));if(!candidate)break;
 if(!func_L01_00452F60(candidate)){ok=0;break;}
 allq++; test2: if((c->all&255)==255 || c->all>D_001E00D8_sda || !allq)break;
 }while(allq[-1]>=0 || allq==D_L01_0021DEA0[c->all]);if(ok)return 1;
 }
 if(c->dead!=-1){Obj *candidate=D_001E009C_sda+c->dead;if(!candidate || candidate->state==254 || candidate->state==253)return 1;}
 if(c->other!=-1 && !func_L01_00442998(c->other,-1,0))return 1;
 return 0;
}
/* localdecomp:end func_L01_003B2450 */

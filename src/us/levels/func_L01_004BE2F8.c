#include "common.h"
/* localdecomp:start func_L01_004BE2F8 */
typedef struct S {char pad[56];int state;char p3c[1800];int active;char p748[40];int skip;int x774;int result;} S;
typedef struct I {int x0,x4,mode;char pc[8];int ready;char p18[144];int mode2;char pac[8];int ready2;char pb8[164];int count;int x160;int timer;int kind;} I;
extern S D_L01_00244740;
extern I D_00142430;
extern int D_001426A8[];
extern void func_L01_004BE628(void);
extern int func_L01_004BE2D0(void);
extern int func_L01_004BE190(int);
extern int func_L01_004BBAB8(void);
extern void func_L01_004B6E88(int);
void func_L01_004BE2F8(void) {
 int next;int message; int result;
 if(!D_L01_00244740.active){func_L01_004BE628();return;}
 switch(D_L01_00244740.state) {
 case 0:case 1:
  if(D_L01_00244740.skip){D_L01_00244740.state=6;break;}
  if(D_00142430.count<3 && D_00142430.timer<0 && D_00142430.mode==2 && D_00142430.ready && func_L01_004BE2D0()) {
   if(D_00142430.timer<0){D_00142430.kind=0;D_00142430.timer=24;}
   func_L01_004BE190(0x17f4);next=D_L01_00244740.state==1 ? 3 : 2;D_L01_00244740.state=next;
  }else {
   if(D_L01_00244740.state==1)func_L01_004BE190(0x17fc);
   D_L01_00244740.state=6;
  }break;
 case 2:case 3:
  if(D_00142430.count<3 && D_00142430.timer<0 && func_L01_004BE2D0()) {
   if(func_L01_004BBAB8())func_L01_004B6E88(0);
   if(D_L01_00244740.state==3){
    if(!(D_001426A8[0]&128))func_L01_004BE190(0x17fc);
    else if(!D_L01_00244740.result)func_L01_004BE190(0x1800);
   }
   result=D_L01_00244740.result;
   if(result==1)func_L01_004BE190(0x17ff);
   else if(result>=2)func_L01_004BE190(0x17fe);
   D_L01_00244740.state=6;
  }break;
 case 4:
  if(D_00142430.count<3 && D_00142430.timer<0) {
   if(D_00142430.mode2==2 && D_00142430.ready2){D_00142430.timer=24;D_00142430.kind=1;func_L01_004BE190(0x1b90);D_L01_00244740.state=5;}
   else D_L01_00244740.state=1;
  }break;
 case 6:break;
 case 5: {
  if(D_00142430.count<3 && D_00142430.timer<0 && func_L01_004BE2D0()) {
   if(func_L01_004BBAB8())func_L01_004B6E88(0);
   if(!(D_001426A8[0]&128))D_L01_00244740.state=1;
   else {
    S *s=&D_L01_00244740;
    if(s->result==0)message=0x1800;
    else if(s->result==1)message=0x17ff;
    else if(s->result>=2)message=0x17fe;
    else break;
    func_L01_004BE190(message);
    s->state=6;
   }
  }break;
 }
 }
}
/* localdecomp:end func_L01_004BE2F8 */

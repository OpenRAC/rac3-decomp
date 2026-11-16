/* PAL near miss (Codex wave 7): near miss: 190 words differ with the file's flags.
 * Worker's note: 166 diff with tested --divs 2 (not MATCH), try02.log; decoded switch table in .table.txt; fixed default assembler emits literal pools; void file signature func_L07_003A2380 retained (retail preserves v0 after calls); no cast workaround.
 */
#include "common.h"
/* localdecomp:start func_L07_003BB410 */
typedef struct State_003BB410 {
 u8 pad[0x94]; f32 last, ratio; u8 p9c[4]; s16 state; u16 fA2,flags; s16 timerA6,timerA8,timerAA,count;
} State_003BB410;
typedef struct Game_003BB410 {u8 pad[0x84];f32 time;u8 p88[0x27c8];s32 value;} Game_003BB410;
extern Game_003BB410 D_001A4BE0;
void func_L07_003BB410(void *arg)
{
 extern void func_L07_003A2380(s32,s32,s32,s32);
 extern s32 func_00382498(s32,s32);
 extern f32 func_003824E0(f32,f32);
 extern s32 func_00382468(s32);
 extern void func_L07_003BB768(s32);
 extern void func_L07_003BB7A8(void *);
 extern void func_L07_003BB840(void *);
 extern s32 func_L07_003BBAC8(s32);
 extern s32 func_L07_003A24C8(void);
 extern s32 func_0038CB00(void *);
 State_003BB410 *p=*(State_003BB410 **)((u8 *)arg+0x68);
 f32 r;
 {f32 ratio=(D_001A4BE0.time-220.0f)/280.0f;
 if(p->ratio<ratio)p->ratio=ratio;}
 if((f32)D_001A4BE0.value!=p->last){
  if((f32)D_001A4BE0.value<p->last){
   if((((*(u8 *)&p->flags^1)&1)!=0) && p->ratio>0.4821428656578064f){
    func_L07_003A2380(95,(s32)arg,0,100);p->flags|=1;
   }else if(!p->timerA6)func_L07_003BB840(arg);
   p->timerA6=2000;
  }
  p->last=D_001A4BE0.value;
 }
 if(p->count>=5){
  if(!p->timerAA){func_L07_003A2380(func_00382498(74,78)&255,(s32)arg,0,100);p->timerAA=2000;}
  p->count=0;
 }
 switch(func_L07_003BBAC8(p->state)){
 case 0:func_L07_003A2380(93,(s32)arg,0,100);break;
 case 1:if(func_003824E0(0.0f,1.0f)<0.9f)func_L07_003BB768((s32)arg);break;
 case 2:r=func_003824E0(0.0f,1.0f);if(r<0.5f)func_L07_003A2380(96,(s32)arg,0,100);else if(r<0.9f)func_L07_003BB768((s32)arg);break;
 case 3:r=func_003824E0(0.0f,1.0f);if(r<0.5f)func_L07_003A2380(func_00382498(111,114)&255,(s32)arg,0,100);else if(r<0.9f)func_L07_003BB768((s32)arg);break;
 case 4:r=func_003824E0(0.0f,1.0f);if(r<0.25f)func_L07_003A2380(94,(s32)arg,0,100);else if(r<0.9f)func_L07_003BB768((s32)arg);break;
 case 7:func_L07_003BB768((s32)arg);break;
 case 10:if(!(p->flags&8)){func_L07_003A2380(97,(s32)arg,0,100);p->flags|=8;}break;
 }
 if(!p->timerA8 && func_L07_003A24C8()>=150){func_L07_003BB7A8(arg);p->timerA8=func_00382468(50)+100;}
 func_0038CB00(&p->timerA6);func_0038CB00(&p->timerAA);func_0038CB00(&p->timerA8);
}
/* localdecomp:end func_L07_003BB410 */

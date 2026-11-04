#include "common.h"

typedef struct KeyObject_004CF498 {
 u8 pad[0x70];
 float keys[1];
} KeyObject_004CF498;

/* localdecomp:start func_L01_004CF498 */
extern f32 func_003AF2A0(f32, f32, f32, f32, f32);
extern void func_003AD590(u8 *p, s32 a);

void func_L01_004CF498(char *o, int advance)
{
 int hi, lo, i, playing;
 float t, clamped, *keys;
 if (!*(u8 *)(o+0x28)) return;
 lo=0;hi=0;
 if (*(int *)(o+0x1c)==1) {
  float value=*(float *)(o+0x18);
  if (advance) value+=*(float *)(o+0x24);
  *(float *)(o+0x18)=value;
  playing=1;
  if (value>1.0f) playing=0;
  *(u8 *)(o+0x28)=playing;
  clamped=!(value>1.0f)?value:1.0f;
  *(float *)(o+0x18)=clamped;
  value=clamped;
  for(i=0,keys=(float *)(o+0x70);i<*(int *)(o+0x84);i++) {
   int next=hi+1;
   if(next<*(int *)(o+0x84) && keys[hi]<=*(float *)(o+0x18)) {lo=hi;hi=next;} else break;
  }
 } else {
  float value=*(float *)(o+0x18);
  if(advance) value-=*(float *)(o+0x24);
  *(float *)(o+0x18)=value;
  playing=1;
  if (value<0.0f) playing=0;
  *(u8 *)(o+0x28)=playing;
  clamped=!(value<0.0f)?value:0.0f;
  *(float *)(o+0x18)=clamped;
  value=clamped;
  keys=(float *)(o+0x70);
  hi=*(int *)(o+0x84)-1;lo=hi;
  { int j; for(j=hi;j>0;j--) {
   int next=lo-1;
   if(next>=0 && *(float *)(o+0x18)<=((KeyObject_004CF498 *)o)->keys[lo]) {hi=lo;lo=next;} else break;
  }}
 }
 t=func_003AF2A0((*(float *)(o+0x18)-((KeyObject_004CF498 *)o)->keys[lo])/(((KeyObject_004CF498 *)o)->keys[hi]-((KeyObject_004CF498 *)o)->keys[lo]),0.0f,*(float *)o,*(float *)(o+12),1.0f);
 if(*(int *)(o+0x2c)) {
  char *target=*(char **)(o+0x80);char *vt=*(char **)target;
  ((void (*)(void *,int,void *,void *,float))*(void **)(vt+12))(target,*(int *)(o+0x2c),o+(lo*16+0x30),o+(hi*16+0x30),t);
 }
 if(!*(u8 *)(o+0x28)) {
  switch(*(int *)(o+0x20)) {
   case 0:break;
   case 1:func_003AD590((u8 *)o,*(int *)(o+0x1c));break;
   case 2:*(int *)(o+0x1c)=*(int *)(o+0x1c)==1?-1:1;func_003AD590((u8 *)o,*(int *)(o+0x1c));break;
  }
 }
}
/* localdecomp:end func_L01_004CF498 */

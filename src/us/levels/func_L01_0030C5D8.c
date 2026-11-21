#include "common.h"
#include "vu0.h"

/* NTSC-U counterpart of func_L01_0030C878 (src/levels/shared/L01_003068B8.c): the arc's kind is 20, not 17 */
/* localdecomp:start func_L01_0030C5D8 */
typedef struct {
 vu0_v4 a,b,position,attached;
 f32 angle[3],rate[3],size[3],angle2[3],rate2[3],size2[3];
 s32 kind;
 u8 *owner,*attachment;
 s32 timer,duration,finished;
} Arc_0030C5D8;
extern u8 *D_L01_001E17A4;
extern f32 func_0037E250(f32,f32);
extern f32 func_L01_00440918(f32,f32);
extern u8 *func_0037E0B8(u8 *);
extern void func_L01_0044E010(u8 *,f32 *,s32);
extern void func_003886E8(f32 *,f32 *,f32);
void func_L01_0030C5D8(u8 *m, u8 *attachment, s32 life) {
 vu0_v4 offset;
 Arc_0030C5D8 *base=(Arc_0030C5D8 *)D_L01_001E17A4;
 u8 *vars=*(u8 **)(m+0x68);
 Arc_0030C5D8 *p;
 u8 *obj;
 s32 i;
 for(i=0;i<12;i++) {
  p=&base[i];
  if(p->owner) continue;
  p->owner=m;
  (*(s32 *)(vars+0x1c))++;
  *(vu0_q *)&p->position=*(vu0_q *)(m+0x10);
  p->angle[0]=func_0037E250(-3.141592741f,3.141592741f);
  p->angle[1]=func_0037E250(-3.141592741f,3.141592741f);
  p->angle[2]=func_0037E250(-3.141592741f,3.141592741f);
  p->angle2[0]=func_0037E250(-3.141592741f,3.141592741f);
  p->angle2[1]=func_0037E250(-3.141592741f,3.141592741f);
  p->angle2[2]=func_0037E250(-3.141592741f,3.141592741f);
  p->rate[0]=func_L01_00440918(0.001f,0.05f);
  p->rate[1]=func_L01_00440918(0.001f,0.05f);
  p->rate[2]=func_L01_00440918(0.001f,0.05f);
  p->rate2[0]=func_L01_00440918(0.001f,0.05f);
  p->rate2[1]=func_L01_00440918(0.001f,0.05f);
  p->rate2[2]=func_L01_00440918(0.001f,0.05f);
  p->size[0]=func_0037E250(3.25f,6.75f);
  p->size[1]=func_0037E250(3.25f,6.75f);
  p->size[2]=func_0037E250(3.25f,6.75f);
  p->size2[0]=func_0037E250(1.25f,4.75f);
  p->size2[1]=func_0037E250(1.25f,4.75f);
  p->size2[2]=func_0037E250(1.25f,4.75f);
  qzero(&p->a);
  qzero(&p->b);
  p->timer=life;
  p->duration=life;
  p->attachment=attachment;
  p->finished=0;
  p->kind=20;
  obj=func_0037E0B8(attachment);
  if(obj) {
   func_L01_0044E010(attachment,(f32 *)&offset,1);
   func_003886E8((f32 *)&offset,(f32 *)&offset,*(f32 *)(obj+0x10));
   vec_add_ba(&p->attached,&offset,attachment+0x10);
  } else {
   *(vu0_q *)&p->attached=*(vu0_q *)(attachment+0x10);
  }
  break;
 }
}
/* localdecomp:end func_L01_0030C5D8 */

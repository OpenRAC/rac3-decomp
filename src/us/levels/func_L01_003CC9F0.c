#include "common.h"
/* localdecomp:start func_L01_003CC9F0 */
typedef int Q_3CC9F0 __attribute__((mode(TI)));
typedef struct {char p0[16]; Q_3CC9F0 pos; s32 c20,c24,c28,c2c;char p30[0x90];s32 c0;void *c4;s32 c8,cc,d0;} Data_3CC9F0;
extern s32 D_L01_001DF0E0,D_L01_001DF0E4,D_L01_001DF0E8;
__asm__(".extern D_L01_001DF0E0, 4");
__asm__(".extern D_L01_001DF0E4, 4");
__asm__(".extern D_L01_001DF0E8, 4");
extern void func_003BDA38(void *,s32,void *);
extern s32 func_003894A0(s32,s32,f32);
extern void func_L01_0040A3D0(void *,s32);
void func_L01_003CC9F0(char *obj){
 Data_3CC9F0 *d=*(Data_3CC9F0**)(obj+0x68);
 f32 t;
 if(d->c4){
  func_003BDA38(d->c4,d->c8,d);
  *(Q_3CC9F0*)((char*)d+0x10)=*(Q_3CC9F0*)(obj+0x10);
  t=(f32)d->d0/(f32)D_L01_001DF0E8;
  d->c24=func_003894A0(0,D_L01_001DF0E0,t);
  d->c2c=func_003894A0(0,D_L01_001DF0E4,t);
  d->c20=func_003894A0(0,D_L01_001DF0E0,t);
  d->c28=func_003894A0(0,D_L01_001DF0E4,t);
  func_L01_0040A3D0(d,d->c0);
 }
}
/* localdecomp:end func_L01_003CC9F0 */

#include "common.h"
#include "vu0.h"
/* localdecomp:start func_L14_003537D8 */
typedef int Q_3537D8 __attribute__((mode(TI)));
extern int D_L14_001DF240_003537D8;
extern int D_L14_001D67B8_003537D8;
extern unsigned char D_L14_001D66B0_003537D8;
typedef struct { int first,count; char pad[8]; vu0_v4 v[200]; } Table_3537D8;
extern Table_3537D8 D_L14_00284820;
extern char D_L14_002856A0_003537D8[];
extern void func_L14_00353B70(void*);
extern void func_L01_004026A0(void*,void*);
extern void func_L14_003F5610(void*,int,int,int,float,float,float);
extern void func_L01_0044DB68(void*,void*,float,float,float);
extern void func_003886E8(void*,void*,float);
extern void func_003888C8(void*,void*,void*);
extern s32 func_L01_00444358(void *, s32, s32);
extern s32 func_0039FE80(s32, s32, void *);
extern void func_L01_0044ED60(void *, s32, u8 *, f32, f32, f32, f32, s32, f32, f32, s32, s32, s32, s32, f32, f32, s32, s32);
extern void func_L02_003E0520(void *, void *, f32, void *, s32, s32, f32, f32, f32, f32, s32);
extern s32 func_L01_0032FE90(void *, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32,
                              s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern void func_L01_0044EBF8(void *, s32, f32);
extern void func_L01_00456960(s32);
extern void func_003BD360(void *);


void func_L14_003537D8(unsigned char *a0) {
 vu0_v4 b,a,offset,temp;
 int i;
 if(!D_L14_001DF240_003537D8) {
  func_L14_003F5610(D_L14_002856A0_003537D8,0x90000000,20,1,0.4f,0.9f,1.5f);
 }
 if(a0[0x31]) {
  for(i=1;i<D_L14_00284820.count;i++) {
   func_L01_0044DB68(a0,&offset,0.0f,-4.0f,5.7f);
   vec_add_ba(&b,&D_L14_00284820.v[i-1],&offset);
   vec_add_ba(&a,&D_L14_00284820.v[i],&offset);
   if(i>=3) {
    __asm__("lqc2 vf1,%3\n\tlqc2 vf2,%4\n\tvadd.xyz vf2,vf2,vf1\n\t"
            "lqc2 vf1,%5\n\tsqc2 vf1,%2\n\tsqc2 vf2,%0\n\t"
            "lqc2 vf1,%0\n\tlqc2 vf2,%2\n\tvadd.xyz vf1,vf1,vf2\n\tsqc2 vf1,%1"
            : "=m"(b),"=m"(a),"=m"(temp)
            : "m"(offset),"m"(D_L14_00284820.v[i+120]),"m"(D_L14_00284820.v[i+60])
            : "vf1","vf2");
   }
  }
  func_L01_004026A0(func_L14_00353B70,a0);
 }
 if(func_L01_00444358(a0,-1,0)) {
  func_0039FE80(0,0,a0);
  func_L01_0044ED60(a0,0x7f,&D_L14_001D66B0_003537D8,3.0f,6.0f,3.0f,6.0f,0xff,-1.0f,-1.0f,0xb4,0,0,0x23,1.0f,1.0f,0,3);
  *(Q_3537D8 *)&b=0;
  b.y=-4.0f;
  b.z=5.4f;
  func_003886E8(&b,&b,4.099873f);
  *(Q_3537D8 *)&a=0;
  a.z=-0.116666675f;
  func_L02_003E0520(a0,&b,0.1f,&a,20,0,0.15f,1.5f,20.0f,1.0f,0);
  func_003886E8(&b,&b,*(float *)(a0+0x2c));
  func_003888C8(&b,&b,a0+0xc0);
  vec_add_ab(&b,&b,a0+0x10);
  func_L01_0032FE90(&b,0,0,0,0,2,5,0,0.70000005f,0.0f,0.0f,0.0f,
    0,1,0,0,0,0,0x1000000,0,0x27B2F3,0xBDFFF,0,0,0,0,0x7F27B2F3,0x280BDFFF,0,0);
  D_L14_001D67B8_003537D8=D_L14_001D67B8_003537D8+1;
  if(D_L14_001D67B8_003537D8>=100)func_L01_00456960(17);
  func_L01_0044EBF8(a0,1,0.0f);
  func_003BD360(a0);
 }
}
/* localdecomp:end func_L14_003537D8 */

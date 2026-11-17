/* PAL near miss (Codex wave 6): near miss: 130 words differ with the file's flags.
 * Worker's note: 131 diff w288/func_L01_003612E0.05.log; file declares func_003A9440(s32,s32) but retail passes 0xFF9000000260 and 0x8000000048/41; retained contract-compatible truncation plus loop/register differences
 */
#include "common.h"
/* localdecomp:start func_L01_003612E0 */
extern f32 D_L01_0028C6B0[][3];
extern s32 D_L01_0028C8A8[];
extern f32 D_L01_0028C950[][2];
void func_L01_003612E0(s128 *matrix,f32 degrees,f32 r1,f32 r2,s32 texture,f32 unused,s32 colour,s32 blend) {
 extern void func_003A9440(s32,s32);
 extern s32 func_00389598(s32);
 extern void func_0038C750(void);
 extern f32 func_0038DB48(f32);
 extern f32 func_0038D098(f32);
 extern void func_00382760(void *,f32,f32,f32);
 extern void func_0038D028(void *,void *,void *);
 extern void func_003D3A24(s32,void *,void *,void *,s32);
 S_38C110v v,out;
 f32 step,angle,t,rad,denom;

 s32 i;
 func_003A9440(8,0);
 func_003A9440(20,(s32)0xFF9000000260UL);
 func_003A9440(71,0x513F1);
 func_003A9440(6,func_00389598(texture));
 if(blend)func_003A9440(66,(s32)0x8000000048UL);
 else func_003A9440(66,(s32)0x8000000041UL);
 rad=0.017453292f;
 func_0038C750();
 denom=20.0f;
 step=degrees*rad/denom;
 for(i=0;i<42;i+=2) {
  t=i/2;
  angle=func_0038DB48(t*step);
  func_0038D098(angle);
  t/=denom;
  D_L01_0028C8A8[i]=colour;D_L01_0028C8A8[i+1]=colour;
  D_L01_0028C950[i][0]=t;
  D_L01_0028C950[i][1]=0;
  D_L01_0028C950[i+1][0]=t;
  D_L01_0028C950[i+1][1]=1.0f;
  func_00382760(&v,1.0f,angle,r1*rad);
  v.w=1.0f;
  func_0038D028(&out,&v,matrix);
  D_L01_0028C6B0[i][0]=out.x;D_L01_0028C6B0[i][1]=out.y;D_L01_0028C6B0[i][2]=out.z;
  func_00382760(&v,1.0f,angle,r2*rad);
  v.w=1.0f;
  func_0038D028(&out,&v,matrix);
  D_L01_0028C6B0[i+1][0]=out.x;D_L01_0028C6B0[i+1][1]=out.y;D_L01_0028C6B0[i+1][2]=out.z;
 }
 func_003D3A24(42,D_L01_0028C6B0,D_L01_0028C8A8,D_L01_0028C950,1);
}
/* localdecomp:end func_L01_003612E0 */

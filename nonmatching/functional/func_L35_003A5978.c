/* functional: high. Existing near-miss draft re-verified line by line against PAL asm (matrix fill, two moby copies, three vertex-strip loops, all gp globals/offsets/order). Compiles under the file's own flags; not byte-identical (245 diffs: allocation/scheduling). */
#include "common.h"
#include "vu0.h"
typedef struct State_003A5978 {
 u8 pad[0x48]; f32 depth; u8 p4c[4];f32 f50;u8 p54[4];f32 f58;u8 p5c[4];
 f32 (*matrix)[4];s32 f64;vu0_v4 *vertices;s32 f6c; s32 index70,index74;
} State_003A5978;
extern u8 D_001A4BE0[];
extern f32 D_L35_001DEAC4;
extern f32 D_L35_001DEACC;
extern f32 D_L35_001DEABC;
extern f32 D_L35_001DEAC8;
extern f32 D_L35_001DEAC0;
extern f32 D_L35_001DEAD0;
extern s32 D_L35_001DEAB8;
extern s32 D_L35_001DEAB0;
extern s32 D_L35_001DEAB4;
extern u8 *D_L35_001DF89C[];
extern vu0_v4 D_L35_001E2500[];
void func_L35_003A5978(void *arg)
{
 extern void func_L30_0034CDC0(f32 *,f32 *,f32 *,f32 *,f32);
 extern void func_L35_003A5878(void *,f32,f32);
 extern f32 func_0038DB48(f32);
 extern f32 func_0038D098(f32);
 extern f32 func_003C4088(f32,f32,f32);
 f32 left,right,top,bottom;
 State_003A5978 *s=*(State_003A5978 **)((u8 *)arg+0x68);
 s32 i=0,j,k;
 f32 center;
 u8 *m;
 func_L30_0034CDC0(&left,&right,&top,&bottom,1.0f);
 center=(left+right)*0.5f;
 qzero(s->matrix[0]);
 s->matrix[0][0]=fabs_asm(right-center);
 qzero(s->matrix[1]);
 s->matrix[1][1]=fabs_asm(D_L35_001DEAC4)*0.5f;
 qzero(s->matrix[2]);
 s->matrix[2][2]=D_L35_001DEACC*0.5f;
 s->matrix[3][0]=center;
 s->matrix[3][1]=*(f32 *)(D_001A4BE0+0x84)+D_L35_001DEABC+D_L35_001DEAC4*0.5f;
 s->matrix[3][2]=s->depth;
 s->matrix[3][3]=1.0f;
 qzero(s->matrix[4]);s->matrix[4][0]=1.0f/s->matrix[0][0];
 qzero(s->matrix[5]);s->matrix[5][1]=1.0f/s->matrix[1][1];
 qzero(s->matrix[6]);s->matrix[6][2]=1.0f/s->matrix[2][2];
 qzero(s->matrix[7]);
 m=D_L35_001DF89C[0]+s->index74*0x100;
 *(vu0_q *)(m+0x10)=*(vu0_q *)D_L35_001E2500;
 *(f32 *)(m+0x18)-=1.0f;
 m=D_L35_001DF89C[0]+s->index70*0x100;
 *(vu0_q *)(m+0x10)=*(vu0_q *)D_L35_001E2500;
 *(f32 *)(m+0x18)-=1.0f;
 func_L35_003A5878(m,s->f58,s->f50);
 for(;i<D_L35_001DEAB8;i+=2){
  f32 ratio=(f32)i/D_L35_001DEAB4;
  s->vertices[i+1].x=left-5.0f;
  s->vertices[i+1].y=*(f32 *)(D_001A4BE0+0x84)+8.0f+D_L35_001DEAC8*ratio;
  s->vertices[i+1].z=s->depth;
  *(vu0_q *)&s->vertices[i+2]=*(vu0_q *)&s->vertices[i+1];
  s->vertices[i+2].x=right+5.0f;
 }
 for(j=0;j<D_L35_001DEAB0;j+=2){
  s32 n=D_L35_001DEAB8+j;
  s->vertices[n+1].x=left;
  s->vertices[n+1].y=*(f32 *)(D_001A4BE0+0x84)+D_L35_001DEABC+D_L35_001DEAC8+(D_L35_001DEAC0-D_L35_001DEAC8)*(f32)j/D_L35_001DEAB0;
  s->vertices[n+1].z=s->depth+(D_L35_001DEAC0-D_L35_001DEAC8)*(1.0f-func_0038D098(func_0038DB48((f32)j*1.5707963705062866f/D_L35_001DEAB0)));
  *(vu0_q *)&s->vertices[n+2]=*(vu0_q *)&s->vertices[n+1];
  s->vertices[n+2].x=right;
 }
 for(k=0;k<D_L35_001DEAB4;k+=2){
  s32 n=D_L35_001DEAB8+D_L35_001DEAB0+k;
  f32 ratio=(f32)k/(D_L35_001DEAB4-2);
  s->vertices[n+1].x=left;
  s->vertices[n+1].y=*(f32 *)(D_001A4BE0+0x84)+D_L35_001DEABC+D_L35_001DEAC0;
  s->vertices[n+1].z=func_003C4088(s->depth+D_L35_001DEAC0-D_L35_001DEAC8,top-D_L35_001DEAD0,ratio);
  *(vu0_q *)&s->vertices[n+2]=*(vu0_q *)&s->vertices[n+1];
  s->vertices[n+2].x=right;
 }
}

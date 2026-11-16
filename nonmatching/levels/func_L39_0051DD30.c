/* NTSC-U draft (Codex wave 3): C of func_L39_0051D918, the NTSC-U twin of func_L39_0051DD30, with NTSC-U names and addresses (the two versions' code differs).
 * near miss: 197 words differ on NTSC-U with the file's flags (NTSC-U twin "func_L39_0051D918", whose code is not the PAL one).
 * Worker's note: 197 diff; signed decoder words remove zero extension and int flag plus u8 test retains mask; conditional-move instead of retail branch remains, shifts later body; ten allowed checks; best log func_L39_0051D918.07.log
 */
#include "common.h"
#include "vu0.h"
/* localdecomp:start func_L39_0051D918 */
extern u8 *D_L39_0024CF20[1];
extern vu0_v4 D_L39_0025F870;
extern u8 D_L39_004998A0[];
typedef struct {u8 pad[0x140];float x,y;} Hero;
extern Hero D_L39_0024DDC0;
extern int D_L39_0024D590;
extern float func_L01_00443D00(void *,void *,int,void *,float);
extern void func_L39_00625F88(void *),func_L39_00635680(void *,void *,void *,int,int,int,int),func_L39_00625860(void *,int);
extern u8 *func_0037E0B8(int);
extern float func_L39_005B2510(float,float),func_L39_005B25C8(void),func_L39_005B2568(float,float),func_00388A28(float,float),func_00389380(float,float),func_00388960(float),func_00388978(float);
extern int func_L39_005B24C8(int,int);
extern void func_0037E4B8(void *,float,float,float);
extern void func_L39_005C6980(void *,void *,int,int,float,int),func_L39_005D04C0(void *,void *,int),func_L39_0051DE40(void *),func_003BD360(void *);
void func_L39_0051D918(u8 *m,int die) {
 union {vu0_v4 tmp; s32 buf[2];} work; vu0_v4 pos;
 u8 *v=*(u8 **)(m+0x68), *g=D_L39_0024CF20[*(int *)(v+0x9c)];
 int i;
 float b,a,c,angle;
 if(g) {
  *(int *)(g+0x2458)=0;
  if(g[0x1a14]) {
   pos=*(vu0_v4 *)(m+0x10);work.tmp=*(vu0_v4 *)(m+0x10);pos.z+=2.0f;
   if(func_L01_00443D00(&pos,&work.tmp,0,m,*(float *)(g+0x1f4))<1.0f) *(vu0_v4 *)(m+0x10)=D_L39_0025F870;
   *(vu0_v4 *)(g+0xa0)=*(vu0_v4 *)(m+0x10);*(vu0_v4 *)(g+0xb0)=*(vu0_v4 *)(m+0xf0);
  }
  if(die) {
   u8 *o;
   func_L39_00625F88(g);o=func_0037E0B8(*(int *)(g+0x2524));if(o) o[14]=1;
   if(g[0x1a14]) {g[0x1a0a]=1;func_L39_00635680(g,m+0x10,m+0xf0,0,1,1,0);}
  } else {
   int flag=0;u8 *source=*(u8 **)(g+0x2530);
   if(source && source[0x27b]) {
    u8 *p=g+0x19e4,*d;long x=0;long t=*p;
    if(t) {
     int n=*p,k=((int)p-n)&7,j,base=n+1;d=(u8 *)work.buf;
     for(j=0;j<40;j+=5) *d++=D_L39_004998A0[base+((k+j)&7)*255];
     work.buf[0]^=(s32)p;work.buf[1]^=work.buf[0];x=work.buf[1];
    }
    if((x^0x31)==0) flag=1;
   }
   if((u8)flag) {
    *(vu0_v4 *)(g+0xa0)=*(vu0_v4 *)(m+0x10);*(vu0_v4 *)(g+0xb0)=*(vu0_v4 *)(m+0xf0);
    func_L39_00625860(g,0);
    ((void (*)(void *,int,int,int,int))*(void **)(*(u8 **)(g+0x14)+0x34))(g,118,0,1,0);
    if(!g[0x1a14]) g[0x1a0a]=2;
   }
  }
 }
 for(i=0;i<33-D_L39_0024D590;i++) {
  a=func_L39_005B2510(0.0f,0.37f);b=func_L39_005B25C8();c=func_L39_005B25C8();func_0037E4B8(&pos,a,b,c);
  pos.z+=func_L39_005B2510(0.35f,0.6f);vec_add_ba(&pos,&pos,m+0x10);
  a=func_L39_005B2510(0.00166666682f,0.0166666675f);b=func_L39_005B25C8();c=func_L39_005B25C8();func_0037E4B8(&work.tmp,a,b,c);
  func_L39_005C6980(&pos,&work.tmp,0x4f20507f,0x102f,150000.0f,func_L39_005B24C8(30,57));
 }
 for(i=0;i<50-D_L39_0024D590;i++) {
  angle=func_00388A28(D_L39_0024DDC0.x-*(float *)(m+0x10),D_L39_0024DDC0.y-*(float *)(m+0x14));
  func_L39_005B2568(1.0f,2.0f);
  work.tmp.x=*(float *)(m+0x10)+func_L39_005B2568(0.0f,0.15f);
  work.tmp.y=*(float *)(m+0x14)+func_L39_005B2568(0.0f,0.15f);
  work.tmp.z=*(float *)(m+0x18)+func_L39_005B2568(0.0f,0.15f);
  angle=func_00389380(angle,func_L39_005B2568(0.0f,-1.57079637f));
  pos.x=func_00388960(angle)*0.13333334f;pos.y=func_00388978(angle)*0.13333334f;pos.z=0.15f;
  func_L39_005D04C0(&work.tmp,&pos,300);
 }
 func_L39_0051DE40(m);func_003BD360(m);
}
/* localdecomp:end func_L39_0051D918 */

/* NTSC-U draft (2026-11-14, Codex worker): C of func_L09_003BE400, the NTSC-U twin of func_L09_003BFC90, with NTSC-U names
 * and addresses. Byte-exact on NTSC-U with "-mvu0-use-vf0-vf2 -O2 -G8 -fopt-stack -mno-check-zero-division" (src/levels/09_tyhrranosis/L09_003B8580.c's line: "-mvu0-use-vf0-vf2 -O2 -G8 -fopt-stack -mno-check-zero-division").
 */
#include "common.h"
/* localdecomp:start func_L09_003BE400 */
extern int func_L01_0044AF40(void *,float);
extern float func_0037E250(float,float);
extern float func_L01_00440918(float,float);
extern int func_0037E208(int,int);
extern int func_0037E1D8(int);
extern void func_003BDA38(void *,int,void *);
extern u8 *func_L01_0046C468(void *,void *,int,int,int,int,int,int,float,float,float);
extern int D_001DE738_sda,D_001DE73C_sda,D_001DE734_sda,D_001DE760_sda;
extern float D_001DE740_sda,D_001DE744_sda,D_001DE748_sda,D_001DE74C_sda,D_001DE750_sda,D_001DE758_sda,D_001DE730_sda;
extern u8 D_L09_00220098[];
typedef struct { u8 pad[32];float rate;int pad24,timer,count; } G96f;
extern G96f D_L09_001E2C00;
__asm__(".extern D_L09_001E2C00, 0");
void func_L09_003BE400(void *m,int mode,float first,float second) {
    int primary=0,active;
    int count,life,sign;
    float min1,max1,min2,max2,size,lo,hi;
    float vel[3];
    float pos[4];
    u8 *p;
    if(func_L01_0044AF40(m,first)) { primary=1; active=1; }
    else active=func_L01_0044AF40(m,second)!=0;
    if(active) {
    count=mode?D_001DE73C_sda:D_001DE738_sda;
    min1=mode?D_001DE744_sda:D_001DE740_sda;
    max1=mode?D_001DE74C_sda:D_001DE748_sda;
    min2=mode?D_001DE744_sda:D_001DE750_sda;
    max2=mode?D_001DE74C_sda:D_001DE758_sda;
    if(count>0) do {
        size=func_0037E250(min1,max1)*210000.0f;
        lo=min2*0.016666668f;
        hi=max2*0.016666668f;
        vel[0]=func_L01_00440918(lo,hi);
        vel[1]=func_L01_00440918(lo,hi);
        vel[2]=func_0037E250(0.25f,0.8f)*0.016666668f;
        func_003BDA38(m,primary?52:53,pos);
        pos[0]+=func_L01_00440918(0,0.6f);
        pos[1]+=func_L01_00440918(0,0.6f);
        pos[2]+=func_L01_00440918(0,0.2f);
        life=func_0037E208(35,120);
        sign=func_0037E1D8(2)?1:-1;
        p=func_L01_0046C468(pos,vel,life,D_001DE760_sda,sign,50,0,0,size,size,0);
        if(p) {
            p[3]=0x44;
            p[2]=**(u8 **)(D_L09_00220098+0x5C);
        }
    } while(--count);
    if(mode) {
        D_L09_001E2C00.rate=D_001DE730_sda;
        D_L09_001E2C00.timer=D_001DE734_sda;
        D_L09_001E2C00.count=0;
    }
    }
}
/* localdecomp:end func_L09_003BE400 */

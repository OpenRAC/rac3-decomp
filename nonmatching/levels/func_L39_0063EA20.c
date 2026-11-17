/* NTSC-U draft (2026-11-14, Codex worker): C of func_L39_0063C1D8, the NTSC-U twin of func_L39_0063EA20, with NTSC-U names
 * and addresses. Byte-exact on NTSC-U with "-O2 -G8 -fopt-stack -mno-check-zero-division" when tried; not with src/levels/shared/L39_0063E9E8.c's current line.
 * Worker's note: 80 diff; documented inline-literal assembler mismatch: allowed flags emit lwc1 pool for 0.005f versus retail lui/ori/mtc1; aligned remaining differences only affected branch displacements and missing two words; see sixth-literal-evidence.txt; no unlisted flags tried; best log sixth-02.log 80 diff re
 */
#include "common.h"
#include "vu0.h"
/* localdecomp:start func_L39_0063C1D8 */
typedef struct {
    u8 reserved0;u8 active;u8 reserved2[14];
    vu0_v4 transform[3];
    float angles[4],rates[4];
    vu0_v4 acceleration;
    u8 reserved70[0x30];s16 joint,selector;
    float gain,damping,scale;
} JointC1D8;
extern void *func_L39_0063C1A0(void *,int);
extern void func_003BD778(void *,void *),func_L01_00437350(void *,int,void *),func_003BEA80(void *,void *);
extern float func_L01_004455F0(void *,float,void *,float,float,float,int);
void func_L39_0063C1D8(void *owner,JointC1D8 *p) {
    void *model=func_L39_0063C1A0(owner,p->selector);
    if(!model)return;
    if(p->acceleration.x==0.0f && p->acceleration.y==0.0f && p->acceleration.z==0.0f && p->scale==1.0f && fabs_asm(p->angles[0])<0.005f && fabs_asm(p->angles[1])<0.005f && fabs_asm(p->angles[2])<0.005f) {
        if(p->active)func_003BD778(model,p);
    }else {
        func_L01_004455F0(&p->angles[0],p->acceleration.x,&p->rates[0],p->gain,p->damping,0.0f,2);
        func_L01_004455F0(&p->angles[1],p->acceleration.y,&p->rates[1],p->gain,p->damping,0.0f,2);
        func_L01_004455F0(&p->angles[2],p->acceleration.z,&p->rates[2],p->gain,p->damping,0.0f,2);
        if(!p->active)func_L01_00437350(model,p->joint,p);
        func_003BEA80(p->transform,p->angles);
        p->transform[1].x=p->scale;p->transform[1].y=p->scale;p->transform[1].z=p->scale;
    }
    qzero(&p->acceleration);
    p->scale=1.0f;
}
/* localdecomp:end func_L39_0063C1D8 */

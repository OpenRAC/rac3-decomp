/* NTSC-U draft (Codex wave 3): C of func_L01_004BDC90, the NTSC-U twin of func_L01_004C1838, with NTSC-U names and addresses (the two versions' code differs).
 * near miss: 287 words differ on NTSC-U with the file's flags (NTSC-U twin "func_L01_004BDC90", whose code is not the PAL one).
 * Worker's note: 287 diff; allowed default assembler emits literal-pool lwc1 where retail uses inline lui/ori/mtc1 float literals; flag block verified once; no unlisted flags; jump table decoded fresh in .switch.txt; best log func_L01_004BDC90.check01.log
 */
#include "common.h"
/* localdecomp:start func_L01_004BDC90 */
extern int D_L01_001E0FE0[],D_L01_002447D0[],D_L01_001E0FD0[],D_L01_001E0FF0[],D_L01_001E0FF4[],D_L01_001E0FD8[];
extern float D_L01_001E0FD4[],D_L01_001E0FE8[],D_L01_001E0FEC[],D_L01_001E0FDC[];
extern void *D_L01_001E0FB8[],*D_L01_001E0FBC[],*D_L01_001E0FC0[],*D_L01_001E0FC4[],*D_L01_001E0FC8[],*D_L01_001E0FCC[],*D_001D52FC[];
extern char D_L01_00244740[];
extern void *func_003B46F0(int);
extern void func_L01_00495978(void *,int),func_L01_00512D70(void *,int),func_L01_00512480(void *,float,float),func_L01_00513548(void *,float,float),func_L01_00512FE8(void *,char *);
extern char *func_0037DF98(int);
int func_L01_004BDC90(void) {
    int result=0,full,visible; float width,height,alpha,pad;
    switch(D_L01_001E0FE0[0]) {
    case 1: func_L01_00495978(func_003B46F0(0),0); break;
    case 3: D_L01_002447D0[0]=0; func_L01_00495978(func_003B46F0(0),1);
        result=*(int *)((char *)D_001D52FC[0]+0x1a4)&D_L01_001E0FF0[0]; if(result) D_L01_001E0FE0[0]=4; break;
    case 2: func_L01_00495978(func_003B46F0(0),1); D_L01_001E0FD4[0]+=0.116666675f; D_L01_002447D0[0]=0; D_L01_001E0FD0[0]=1;
        if(D_L01_001E0FD4[0]>1.0f) D_L01_001E0FD4[0]=1.0f; else if(D_L01_001E0FD4[0]<0.0f) D_L01_001E0FD4[0]=0.0f;
        if(D_L01_001E0FD4[0]==1.0f) D_L01_001E0FE0[0]=3; break;
    case 0: break;
    case 4: *(int *)(D_L01_00244740+0x90)=0; func_L01_00495978(func_003B46F0(0),1); D_L01_001E0FD4[0]-=0.116666675f; D_L01_001E0FD0[0]=-1;
        if(D_L01_001E0FD4[0]>1.0f) D_L01_001E0FD4[0]=1.0f; else if(D_L01_001E0FD4[0]<0.0f) D_L01_001E0FD4[0]=0.0f;
        if(D_L01_001E0FD4[0]==0.0f) {D_L01_001E0FE0[0]=1; *(int *)(D_L01_00244740+0x90)=0x80;} break;
    }
    full=D_L01_001E0FD4[0]>=1.0f; visible=D_L01_001E0FD4[0]>0.0f;
    func_L01_00512D70(D_L01_001E0FB8[0],full); func_L01_00512D70(D_L01_001E0FBC[0],full&D_L01_001E0FF4[0]);
    func_L01_00512D70(D_L01_001E0FC0[0],visible); func_L01_00512D70(D_L01_001E0FC4[0],visible); func_L01_00512D70(D_L01_001E0FC8[0],visible); func_L01_00512D70(D_L01_001E0FCC[0],visible);
    width=D_L01_001E0FE8[0]; height=D_L01_001E0FEC[0]; alpha=D_L01_001E0FD4[0]; pad=D_L01_001E0FDC[0];
    if(full) {
        func_L01_00512480(D_L01_001E0FB8[0],0.5f,0.29f-(float)D_L01_001E0FF4[0]*0.03f);
        func_L01_00513548(D_L01_001E0FB8[0],width,height);
        func_L01_00512FE8(D_L01_001E0FB8[0],func_0037DF98(D_L01_001E0FD8[0]));
        func_L01_00512480(D_L01_001E0FBC[0],0.5f,height*0.5f+0.3f-0.02f);
    }
    if(visible) {
        func_L01_00512480(D_L01_001E0FC0[0],0.5f,0.3f);
        height=(height+pad)*alpha; width=(width+pad)*alpha;
        func_L01_00513548(D_L01_001E0FC0[0],width,height);
        func_L01_00512480(D_L01_001E0FC4[0],0.5f,0.3f); func_L01_00513548(D_L01_001E0FC4[0],width,height);
        func_L01_00512480(D_L01_001E0FC8[0],0.5f,0.3f); func_L01_00513548(D_L01_001E0FC8[0],width+0.015f,height+0.015f);
    }
    return result;
}
/* localdecomp:end func_L01_004BDC90 */

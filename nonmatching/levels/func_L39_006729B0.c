/* NTSC-U draft (Codex wave 3): C of func_L39_00670060, the NTSC-U twin of func_L39_006729B0, with NTSC-U names and addresses (the two versions' code differs).
 * near miss: 13 words differ on NTSC-U with the file's flags (NTSC-U twin "func_L39_00670060", whose code is not the PAL one).
 * Worker's note: 13 diff; best reproduced; float-last callee spelling and explicit integer-index address give identical output (01/05/08), stop rule reached; explicit pointer variants 113/125 diff, full Stats columns 137, byte offset iterator 92; preheader base, final array ...
 */
#include "common.h"
/* localdecomp:start func_L39_00670060 */
extern int func_L39_0066FDB0(void);
extern void func_L39_0066FED8(int,void*,int);
extern void func_L39_0066FF48(float,int,void*);
extern int func_L39_0066FFE0(float,void*,int);
typedef struct { short counts[25]; short pad; float a[25]; unsigned char rest[0x1c4-0x98]; float x[5]; int state; } Stats;
extern Stats D_001A6F10;
extern float D_001A6FA8[], D_001A700C[], D_001A7070[];
typedef struct { unsigned char first[22]; unsigned char tail[106]; } Label;
extern Label D_L39_0049C96E[];
extern unsigned char  D_L39_0024ACE4, D_L39_0024ACEC, D_L39_0024AFE8, D_L39_0024AEA4, D_L39_0024ABF0;
void func_L39_00670060(void) {
int i;

if(func_L39_0066FDB0()==D_001A6F10.state){
short *counts=D_001A6F10.counts;
unsigned char *last=D_L39_0049C96E[0].tail;
for(i=0;i<25;last+=128,i++,counts++){
if(*counts>0)func_L39_0066FED8(i,D_L39_0049C96E[i].first,*counts);
if(D_001A6F10.a[i]>0.0f)func_L39_0066FF48(D_001A6F10.a[i],i,D_L39_0049C96E[i].first+6);
if(D_001A6FA8[i]>0.0f)func_L39_0066FF48(D_001A6FA8[i],i,D_L39_0049C96E[i].first+10);
if(D_001A700C[i]>0.0f)func_L39_0066FF48(D_001A700C[i],i,D_L39_0049C96E[i].first+18);
if(D_001A7070[i]>0.0f)func_L39_0066FF48(D_001A7070[i],i,last);
}
if(D_001A6F10.x[0]>0.0f)func_L39_0066FFE0(D_001A6F10.x[0],&D_L39_0024ACE4,0x107c);
if(D_001A6F10.x[1]>0.0f)func_L39_0066FFE0(D_001A6F10.x[1],&D_L39_0024ACEC,0x107c);
if(D_001A6F10.x[2]>0.0f)func_L39_0066FFE0(D_001A6F10.x[2],&D_L39_0024AFE8,0x107e);
if(D_001A6F10.x[3]>0.0f)func_L39_0066FFE0(D_001A6F10.x[3],&D_L39_0024AEA4,0x107e);
if(D_001A6F10.x[4]>0.0f)func_L39_0066FFE0(D_001A6F10.x[4],&D_L39_0024ABF0,0x10c2);
}
}
/* localdecomp:end func_L39_00670060 */

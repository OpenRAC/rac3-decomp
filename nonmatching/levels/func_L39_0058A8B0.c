/* NTSC-U draft (Codex wave 3): C of func_L39_00589740, the NTSC-U twin of func_L39_0058A8B0, with NTSC-U names and addresses (the two versions' code differs).
 * near miss: 115 words differ on NTSC-U with the file's flags (NTSC-U twin "func_L39_00589740", whose code is not the PAL one).
 * Worker's note: 115 diff; reproduced best; assignment-expression color and negated-difference rewrites give identical 115-diff output (01/03/04), stop rule reached; moving remaining into else gives 133; alpha reassociation, likely branch and color scheduling remain; best log ...
 */
#include "common.h"
/* localdecomp:start func_L39_00589740 */
typedef struct {unsigned char pad[0x34]; int time; unsigned char pad38[0x4c-0x38]; unsigned char *text;} State;
typedef struct {unsigned char pad[6]; unsigned char enabled; unsigned char pad7[0xad-7]; unsigned char flag; unsigned char padAE[6]; unsigned int reserved:24; unsigned int mode:8;} Config;
extern State D_L39_0025CFC0;
extern Config D_001A5990;
extern int D_L39_00240484;
extern int func_0038C628(int,int,unsigned int,unsigned char*,int);
extern int func_0038C778(int,int,unsigned int,unsigned char*,int);
extern void func_0038C888(unsigned short*,int,int,int,int,int,int,int,int);
extern int func_0038C8F8(unsigned short*,unsigned int,unsigned char*,int);
extern unsigned int func_00120884(unsigned char*);
extern void func_00387C78(int,int,int,int,int,int);
void func_L39_00589740(void){
unsigned short metrics[16];
typedef struct { short start,end,offsets[7]; } Row;
Row *row,*end;
unsigned char *str;

int idx,y,remaining;

if(D_L39_0025CFC0.text){
idx=0;
if(D_001A5990.mode==5)idx=D_001A5990.mode-2;
else if(D_001A5990.mode==4)idx=D_001A5990.mode;
else if(D_001A5990.mode>=2 && D_001A5990.mode<=5)idx=D_001A5990.mode-1;
end=(Row*)(D_L39_0025CFC0.text+*(short*)(D_L39_0025CFC0.text+4));
row=(Row*)D_L39_0025CFC0.text;
y=208;
for(;row<end;row++){
if(D_L39_0025CFC0.time>=row->start && row->end>=D_L39_0025CFC0.time){

if(!D_001A5990.enabled && D_L39_0025CFC0.text[row->offsets[idx]]!='*')continue;
remaining=row->end-D_L39_0025CFC0.time;
if(D_L39_0025CFC0.text[row->offsets[idx]]=='*'){
int x; unsigned int color=0xb0000000;
x=64;
if(D_L39_0025CFC0.text[row->offsets[idx]+1]!='*')x=D_L39_00240484-200;
else if(D_001A5990.flag)x=24;
if(row->end-D_L39_0025CFC0.time<18)color=(row->end-(D_L39_0025CFC0.time-1))<<27;
else if(D_L39_0025CFC0.time-row->start<18)color=(D_L39_0025CFC0.time-(row->start-1))<<27;
if(D_L39_0025CFC0.text[row->offsets[idx]+1]!='*'){func_0038C628(256,y,color|0xe0e0e0,D_L39_0025CFC0.text+row->offsets[idx]+1,-1);y+=20;}
else func_0038C778(32,x,color|0xe0e0e0,D_L39_0025CFC0.text+row->offsets[idx]+2,-1);
}else{
int x,alpha,half,h,w,hpad,wpad; unsigned int color;
x=D_L39_00240484-100;if(D_001A5990.flag)x=D_L39_00240484-54;
alpha=128;
if(remaining<8)alpha=(row->end-(D_L39_0025CFC0.time-1))<<4;
else if(D_L39_0025CFC0.time-row->start<8)alpha=(D_L39_0025CFC0.time-(row->start-1))<<4;
func_0038C888(metrics,200,420,40,472,256,x,18,7);
half=alpha>>1;
color=(alpha+half)|((alpha+half)<<8)|((alpha+half)<<16)|(alpha<<24);
func_0038C8F8(metrics,color,D_L39_0025CFC0.text+row->offsets[idx],-1);
metrics[5]-=4;
h=(short)metrics[7]>>1;w=(short)metrics[6]>>1;
hpad=h+5;wpad=w+10;
if(D_L39_00240484-20<(short)metrics[5]+hpad)metrics[5]=D_L39_00240484-(h+25);
metrics[9]&=0xfffb;
if(func_00120884(D_L39_0025CFC0.text+row->offsets[idx])<150){
func_00387C78((short)metrics[5]-hpad,(short)metrics[5]+hpad,256-wpad,w+266,half+(alpha>>2),0x40404);
func_0038C8F8(metrics,color,D_L39_0025CFC0.text+row->offsets[idx],-1);
}
return;
}
}
}
}
}
/* localdecomp:end func_L39_00589740 */

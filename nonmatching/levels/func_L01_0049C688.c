/* NTSC-U draft (2026-11-14, Codex worker): C of func_L01_00498E28, the NTSC-U twin of func_L01_0049C688, with NTSC-U names
 * and addresses. Byte-exact on NTSC-U with "-O2 -G8 -fopt-stack -mno-check-zero-division" (src/levels/shared/L01_0049BE80.c's line: "-O2 -G8 -fopt-stack -mno-check-zero-division").
 */
#include "common.h"
/* localdecomp:start func_L01_00498E28 */
typedef struct { int value; char pad[16]; unsigned char active; char tail[3]; } Row_498E28;
extern Row_498E28 D_L01_002EC3B8[];
extern char D_L01_002EC628[];
extern float D_L01_001DC128[];
extern int D_001D94A8_sda,D_001D94A4_sda,D_001D94A0_sda,D_001D9498_sda;
extern void func_L01_00499898(void);
extern int func_0037DF98(int);
extern int func_00389D18(int,int,float);
extern float func_003BEB48(float,float,float);
extern void func_003B3DB8(int,int,int,int,int,int,int,int,int,int,int,int,int,int,float);
extern void func_L01_00513548(int,float,float);
extern void func_L01_004991C8(void*);
extern void func_003E2DE0(int,int);
extern int func_003AED40(int);
extern void func_003E31A8(int,int);
extern void func_L01_005131A0(int,int);
extern void func_L01_004994A8(void);
extern void func_L01_00499A88(void);
extern int func_003B46F0(int);
extern void func_L01_00494E68(int,int);
extern void func_L01_00512D70(int,int);
extern void func_003E3250(int,int,int);
void func_L01_00498E28(void) {
 int i=0,flag=0,index;
 float scale=0.0f,start=0.0f,ratio,value;
 func_L01_00499898();
 ratio=(float)func_00389D18(func_0037DF98(451),-1,1.2f)/D_L01_001DC128[0];
 if(ratio>0.49f) {flag=1;scale=0.58800006f/ratio;ratio=0.49f;}
 value=func_003BEB48(6.0f,11.0f,(ratio-start)/0.49f);
 if(value>11.0f) value=11.0f;
 else if(value<6.0f) value=6.0f;
 func_003B3DB8(16,0xD000B,0xD0000,0xD0001,0xD0002,0xD0003,0xD0004,0xD0005,0xD0008,func_0037DF98(451),0xD0006,0x124,0xD0007,0xCD5,value);
 if(flag) func_L01_00513548(0xD0005,scale,scale);
 func_L01_004991C8(D_L01_002EC628);
 func_003E2DE0(17,0x4E0000);
 func_003E31A8(0x4E0003,func_003AED40(1));
 func_L01_005131A0(0x4E0003,0);
 func_L01_004994A8();
 func_L01_00499A88();
 D_001D94A8_sda=-1;
 index=-1;
 if(D_L01_002EC3B8[i].value) {
  do {
   if(D_L01_002EC3B8[i].active) index=i;
   i++;
  } while(D_L01_002EC3B8[i].value && index<0);
  D_001D94A8_sda=index;
 }
 if(D_001D94A8_sda<0 && D_001D94A0_sda) D_001D94A8_sda=0;
 if(D_001D94A4_sda>=0) func_L01_00494E68(func_003B46F0(0),D_001D94A4_sda);
 D_001D9498_sda=-1;
 D_001D94A4_sda=-1;
 func_L01_00512D70(0x4E0003,0);
 func_003E3250(0x4E0003,1,10);
}
/* localdecomp:end func_L01_00498E28 */

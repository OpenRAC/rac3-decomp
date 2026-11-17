/* NTSC-U draft (2026-11-14, Codex worker): C of func_L03_003C2C08, the NTSC-U twin of func_L03_003C4A58, with NTSC-U names
 * and addresses. Byte-exact on NTSC-U with "-O2 -G8 -fopt-stack -mno-check-zero-division" when tried; not with src/levels/shared/L03_003C4A58.c's current line.
 * Worker's note: 215 diff; flags blocker: GNU .lit4 loads vs retail inline lui/ori/mtc1 for rotation increments, pi/2 and 0.35; no alternative allowed; best log w102/func_L03_003C2C08.01.log
 */
#include "common.h"
/* localdecomp:start func_L03_003C2C08 */
typedef int Q_2C08 __attribute__((mode(TI)));
typedef union { u8 b[0x100]; u16 h[0x80]; int i[0x40]; float f[0x40]; Q_2C08 q[0x10]; void *p[0x40]; } M_2C08;
typedef union { Q_2C08 q; float f[4]; } V_2C08;
extern int D_001D545C_sda;
extern u8 D_00142795[];
extern float D_L03_001E92A8[];
extern float D_001DEDA0_sda;
extern u8 D_001A4C60[];
extern u8 D_001CCFD0[];
extern u8 D_001A4BE0[];
extern int D_L03_001DF738[];
extern int D_001DF35C_sda;
extern u8 D_001A7E18[];
extern int func_003CE740(void *,void *,int,void *,int);
extern float func_0037E2A8(void);
extern void func_L01_00441FB8(void *,int,int);
extern float func_003887C8(void *,void *);
extern void func_L03_003C2708(void *);
extern float func_00389380(float,float);
extern void func_L03_003C2450(void *);
extern void func_L01_0044B860(void *,void *,void *,float,float,float);
extern void func_0039C710(void);
extern void func_L03_003C2A00(void *);
extern void func_003BE4F0(void *,int,int,int);
extern void func_L01_0050BB98(int,int,float);
extern int func_00388398(void *);
extern void func_L01_004F12C0(void *,void *,int,int);
extern void func_L01_003E9730(int,int);
extern int func_0039FE80(int,int,void *);
extern void func_L03_003C3098(void *,int);
extern void func_L01_0044ECE0(int,int,int);
extern void func_00399F90(void);
extern void func_00399C90(int,int);
extern void func_L01_00417F60(int,int);
extern void func_L01_004A6DF8(void *,int);
extern void func_003BD360(void *);
void func_L03_003C2C08(M_2C08 *m) {
 V_2C08 bottom,top;
 u8 *s=m->p[0x68/4];
 int i;
 if(!s)return;
 if(D_001D545C_sda!=3) {
  if(m->b[0x20]==0) {
   if(D_00142795[0]) {func_003BD360(m);return;}
   *(Q_2C08 *)(s+0x20)=m->q[1];
   *(float *)(s+0x2C)=m->f[0xF8/4];
   top.q=m->q[1];bottom.q=m->q[1];
   top.f[2]+=1.0f; bottom.f[2]-=1.0f;
   if(func_003CE740(&top,&bottom,2,m,0))m->f[6]=D_L03_001E92A8[0]+0.5f;
   m->f[0xF0/4]=func_0037E2A8();m->f[0xF4/4]=func_0037E2A8();m->f[0xF8/4]=func_0037E2A8();m->f[0xFC/4]=func_0037E2A8();
   *(float *)(s+8)=m->f[6];
   func_L01_00441FB8(m,1,-1);
  } else if(m->b[0x20]==1) {
   if(func_003887C8(D_001A4C60,&m->q[1])<=D_001DEDA0_sda)func_L03_003C2708(m);
  }
  if(m->b[0x20]==1) {
   m->f[0xF0/4]=func_00389380(m->f[0xF0/4],0.03490658849477768f);
   m->f[0xF4/4]=func_00389380(m->f[0xF4/4],0.01163552887737751f);
   m->f[0xF8/4]=func_00389380(m->f[0xF8/4],0.005817764438688755f);
   m->f[0xFC/4]=func_00389380(m->f[0xFC/4],0.02617994137108326f);
   func_L03_003C2450(m);
   func_L01_0044B860(m,s,s+4,0.25f,0.02327105775475502f,*(float *)(s+8));
   m->h[0x96/2]=0;
  } else if(m->b[0x20]==2) {
   if(*(s16 *)(D_001CCFD0+0x76)==0 && *(s16 *)(D_001CCFD0+0x9E)==3 && *(s16 *)(D_001CCFD0+0x98)<7000)func_0039C710();
   D_L03_001DF738[0]=1;
   *(s16 *)(D_001A4BE0+0x1DC)=3;
   func_L03_003C2A00(m);
   m->q[1]=*(Q_2C08 *)(D_001A4BE0+0x80);
   m->q[15]=*(Q_2C08 *)(D_001A4BE0+0x90);
   if(m->b[0x42]==1 && (m->b[0x60]&2)) {
    if(m->b[0x43])func_003BE4F0(m,0,0,0);
    m->b[0x31]=0;
    m->h[0x34/2]|=1;
    for(i=3;i>=0;i--)func_L03_003C2450(m);
   }
   if(*(int *)(D_001A4BE0+0xC08)&2)func_L01_0050BB98(0,0,30.0f);
   if(m->b[0x42]==0 && func_00388398(s+0x7C)) {
    D_001DF35C_sda=0;
    func_L01_004F12C0(D_001A4BE0+0x80,D_001A4BE0+0x90,0,0);
    func_L01_003E9730(0,0);
    func_0039FE80(0,0,m);
    func_L03_003C3098(&m->q[1],10);
    func_L01_0044ECE0(4780,500,0);
    D_00142795[0]=1;
    func_00399F90();
    func_00399C90(0,-1);
    if(*(u16 *)(D_001A7E18+0xC540)==0)func_L01_00417F60(4208,223);
    m->i[0x98/4]=0;
    m->h[0x34/2]=(m->h[0x34/2]|0x41)&0xEFFF;
    func_L01_004A6DF8(m,1);
    func_003BD360(m);
   }
  }
 } else if(m->b[0x20]==0) {
  m->b[0x20]=1;
  if(D_00142795[0]==0) {
   m->i[0x98/4]=0;
   m->h[0x34/2]=(m->h[0x34/2]|0x41)&0xEFFF;
   func_L01_004A6DF8(m,1);
  } else {
   u8 *p;
   m->f[0xF4/4]=func_00389380(m->f[0xF4/4],1.5707963705062866f);
   m->f[6]+=0.35f;
   m->h[0x34/2]&=0xFFBE;
   p=m->p[0x24/4];
   m->h[0x34/2]|=*(u16 *)(p+0x44)&0x1000;
   m->i[0x98/4]=*(int *)(p+0x10);
  }
 }
}
/* localdecomp:end func_L03_003C2C08 */

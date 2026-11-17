/* NTSC-U draft (2026-11-14, Codex worker): C of func_L39_0063D538, the NTSC-U twin of func_L39_0063FDA8, with NTSC-U names
 * and addresses. Byte-exact on NTSC-U with "-O2 -G8 -fopt-stack -mno-check-zero-division" (src/levels/shared/L39_0063EE68.c's line: "-O2 -G8 -fopt-stack -mno-check-zero-division").
 */
#include "common.h"
/* localdecomp:start func_L39_0063D538 */
typedef union { u8 b[8]; u16 h[4]; u32 w[2]; } Buffer;
typedef struct { u8 p0[4]; s16 primary,secondary; u8 p8[3]; u8 tag; u8 pc[0x12]; s16 enabled; u8 p20; s8 alternate; u8 p22[6]; float rate; u8 p2c[0x54]; } Item;
extern u8 D_L39_00480820[], D_L39_00483AC0[], D_L39_0049AB80[];
extern u8 D_L39_004998A0[], D_L39_004998A1[];
extern s32 D_L39_0024BAC8[];
extern s32 D_L39_002412AC[];
extern Item D_L39_0049C950[];
extern int func_L39_00646268(void *,int);
extern u8 *func_003BCFB0(int,int);
extern void func_003BD360(void *);
extern void func_003BE4F0(void *,int,int,int);
static __inline__ Item *item(u8 *g,int n) {
 if(func_L39_00646268(g,n))return &D_L39_0049C950[D_L39_0049C950[n].alternate];
 return &D_L39_0049C950[n];
}
void func_L39_0063D538(u8 *g) {
 Buffer buf; u8 *o; int n,elapsed; u8 *q,*hk,*d; u32 key; s32 k,m,i;
 if(!*(void **)(g+0x450) && *(s32 *)(g+0x464)<D_L39_0024BAC8[0] &&
     (!({
 u8 *q=g+0x1A19; u32 r;
 if(*q==0) r=0;
 else {
  s32 n=*q; s32 k=((u32)q-n)&7; s32 m=n+1; s32 i; u8 *d=buf.b; u32 a,t;
  for(i=0;i<24;i+=3) *d++=D_L39_00480820[m+((k+i)&7)*193];
  a=buf.w[0]^(u32)q; buf.w[0]=a; t=buf.w[1]^a;
  r=t>>16; r=r/(((t^r)<<16)+1); buf.w[1]=r;
 } r;
}) || ({
 u8 *q=g+0x1A1F; u32 r;
 if(*q==0) r=0;
 else {
  s32 n=*q; s32 k=((u32)q-n)&7; s32 m=n+1; s32 i; u8 *d=buf.b; u32 a,t;
  for(i=0;i<24;i+=3) *d++=D_L39_00480820[m+((k+i)&7)*193];
  a=buf.w[0]^(u32)q; buf.w[0]=a; t=buf.w[1]^a;
  r=t>>16; r=r/(((t^r)<<16)+1); buf.w[1]=r;
 } r;
})==({
 u8 *q=g+0x1A19; u32 r;
 if(*q==0) r=0;
 else {
  s32 n=*q; s32 k=((u32)q-n)&7; s32 m=n+1; s32 i; u8 *d=buf.b; u32 a,t;
  for(i=0;i<24;i+=3) *d++=D_L39_00480820[m+((k+i)&7)*193];
  a=buf.w[0]^(u32)q; buf.w[0]=a; t=buf.w[1]^a;
  r=t>>16; r=r/(((t^r)<<16)+1); buf.w[1]=r;
 } r;
}))) {
  n=({
 u8 *q=g+0x1A1F; u32 r;
 if(*q==0) r=0;
 else {
  s32 n=*q; s32 k=((u32)q-n)&7; s32 m=n+1; s32 i; u8 *d=buf.b; u32 a,t;
  for(i=0;i<24;i+=3) *d++=D_L39_00480820[m+((k+i)&7)*193];
  a=buf.w[0]^(u32)q; buf.w[0]=a; t=buf.w[1]^a;
  r=t>>16; r=r/(((t^r)<<16)+1); buf.w[1]=r;
 } r;
});
  if(!n)n=*(s32 *)(g+0x18D0)?*(s32 *)(g+0x18D0):10;
  *(s32 *)(g+0x478)=n;
  o=func_003BCFB0(item(g,n)->primary,128);
  if(o) {
   *(s16 *)(o+0x32)=255; o[0x31]=1;
   *(long *)(o+0x38)=*(long *)(*(u8 **)(g+0x2524)+0x38);
   *(void **)(o+0xB8)=*(void **)(g+0x2524);
   if(g[0x1A14]==0)o[0x62]=0;
   if(*(u8 **)(o+0x24) && (*(u8 **)(o+0x24))[6])o[0x63]=16;
   *(void **)(g+0x450)=o; *(s32 *)(g+0x474)=2; g[0x468]=0;
   elapsed=D_L39_002412AC[0] - ({
 u8 *q=g+n+0x1A42; u32 r;
 if(*q==0) r=0;
 else {
  s32 n=*q; s32 k=((u32)q-n)&7; s32 m=n+1; s32 i; u8 *d=buf.b; u32 a,t;
  for(i=0;i<40;i+=5) *d++=D_L39_0049AB80[m+((k+i)&7)*193];
  a=buf.w[0]^(u32)q; buf.w[0]=a; t=buf.w[1]^a;
  r=t; buf.w[1]=r;
 } r;
});
   if(elapsed>=0) {
    if((int)((1.0f/item(g,n)->rate)*60.0f)<elapsed) *(float *)(g+0x328)=0;
    else *(float *)(g+0x328)=((int)((1.0f/item(g,n)->rate)*60.0f)-elapsed)*0.016666668f;
   }
   g[0x1A0D]=0; g[0x458]=0; if(g[0x1A14])*(s16 *)(g+0x1DAC)=0;
   if(item(g,n)->enabled && (({
 u8 *q=g+n+0x1A52; u32 r;
 if(*q==0) r=0;
 else {
  s32 n=*q; s32 k=((u32)q-n)&7; s32 m=n+1; s32 i; u8 *d=buf.b; u32 a,t;
  for(i=0;i<24;i+=3) *d++=D_L39_00483AC0[m+((k+i)&7)*209];
  a=buf.w[0]^(u32)q; buf.w[0]=a; t=buf.w[1]^a;
  r=t>>16; r=r/(((t^r)<<16)+1); buf.w[1]=r;r=buf.h[2];
 } r;
})<<16)==0)g[0x468]=255;
   if(n==10) {
    *(void **)(o+0x90)=*(void **)g; *(s32 *)(g+0x474)=2; *(s32 *)(g+0x460)=128;
    func_003BE4F0(o,1,0,1);
   }else *(s32 *)(g+0x460)=32;
   n=*(s32 *)(g+0x478);
   {
    u8 tag=item(g,n)->tag;
    q=g+0x1A17; hk=q;
    if(*q==0)*q=++D_L39_004998A0[0];
    else { s32 t=*q; *q=D_L39_004998A1[0]; D_L39_004998A1[0]=t; }
    buf.b[4]=tag;
    key=((u32 *)D_L39_004998A0)[((u32)hk*D_L39_0024BAC8[0])%510];
    k=((u32)q-*q)&7;
    buf.w[1]=((buf.w[1]&0xFFFF)|(buf.w[1]<<16))^key;
    buf.w[0]=(u32)q^key;
    m=*q+1;d=buf.b;
    for(i=0;i<24;i+=3)D_L39_004998A0[m+((k+i)&7)*255]=*d++;
   }
  }
 }
 if(*(void **)(g+0x4F0)) {func_003BD360(*(void **)(g+0x4F0));*(void **)(g+0x4F0)=0;}
 if(!*(void **)(g+0x4A0)) {
  n=*(s32 *)(g+0x18D4); *(s32 *)(g+0x4C8)=n;
  if(n) {
   o=func_003BCFB0(item(g,n)->primary,128);
   if(o) {
    *(s16 *)(o+0x32)=128; o[0x31]=1;
    *(long *)(o+0x38)=*(long *)(*(u8 **)(g+0x2524)+0x38);
    *(s32 *)(o+0x64)=0;
    if(*(u8 **)(o+0x24) && (*(u8 **)(o+0x24))[6])o[0x63]=16;
    *(void **)(g+0x4A0)=o; *(s32 *)(g+0x4C4)=2;
   }
   n=*(s32 *)(g+0x4C8); o=func_003BCFB0(item(g,n)->secondary,128);
   if(o) {
    *(s16 *)(o+0x32)=128; o[0x31]=1;
    *(long *)(o+0x38)=*(long *)(*(u8 **)(g+0x2524)+0x38);
    *(s32 *)(o+0x64)=0;
    if(*(u8 **)(o+0x24) && (*(u8 **)(o+0x24))[6])o[0x63]=16;
    *(void **)(g+0x4A4)=o; *(s32 *)(g+0x4C4)=2;
   }
  }
 }
}
/* localdecomp:end func_L39_0063D538 */

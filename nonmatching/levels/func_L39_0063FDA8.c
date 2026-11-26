/* k4 Sonnet first pass (b): func_L39_0063FDA8, 2284 B (0x8EC), 15 places (39:0063FDA8 ... 53:00517E28).
 * near miss: 354 diff of 571 instructions with the file's own flags ("-O2 -G8 -fopt-stack -mno-check-zero-division", no @ps2as;
 * --all-modes: S/default 354, S/ps2as 392, N 559, so @ps2as is NOT what this one needs; no flag change requested).
 * Source: the NTSC-U draft (byte-exact on NTSC-U, func_L39_0063D538) ported to PAL names/addresses (D_L39_00480760, 00483A00,
 *   0049AAC0, 0049C890, 004997E0/E1, 0024B9C8, 0024112C; func_00648AE0 item test, func_005AA140 alloc, func_005AA510 free,
 *   func_005B4AE8; table strides 193/209/255 and %510 are the same in PAL, constants 0xC1, 0xD1, 0xFF, 0x1FE).
 * The code shape, branches and instruction counts line up (the same jal order, the same loops); what differs is register
 *   allocation from the first lines: retail keeps g in $s1 and n in $s0 ($s2 o, $s3 elapsed, $s4 n<<7 hoisted, $s7 = &D_0049C890
 *   hoisted, $fp = &D_004997E0 hoisted); ours puts g in $s0, so the prologue saves ($s1 then $s0), the first lw order and
 *   every later s-register differ. The 5 get-inlines also differ in $v0/$v1/$a0 numbering (xor/srl/divu chain).
 * Declaration order of the locals changed nothing (3 orders tried). The statement-expression form of the draft is NTSC's; the PAL
 *   original probably used static inline helpers (as func_L40_00434418 now does: shared aligned buffer, helper with slot+size+step,
 *   operand order such as ~(a|w1) and [m + o] mattered a lot there).
 * Next steps: rewrite the 7 get-inlines and the one set-inline as static __inline__ helpers taking (u8 *q, Buffer *buf) like
 *   L40_00434418.c / L39_006D8E90.c; give the helper the 0xC1/0xD1/0xFF strides as parameters; then retry the item() helper
 *   (hoisted $s7 base suggests one table pointer variable).
 * Flags/profile: the file's line. Confidence in the port itself: high (calls, offsets, constants checked by the diff listing).
 */
#include "common.h"

/* localdecomp:start func_L39_0063FDA8 */
typedef union { u8 b[8]; u16 h[4]; u32 w[2]; } Buffer;
typedef struct { u8 p0[4]; s16 primary,secondary; u8 p8[3]; u8 tag; u8 pc[0x12]; s16 enabled; u8 p20; s8 alternate; u8 p22[6]; float rate; u8 p2c[0x54]; } Item;
extern u8 D_L39_00480760[], D_L39_00483A00[], D_L39_0049AAC0[];
extern u8 D_L39_004997E0[], D_L39_004997E1[];
extern s32 D_L39_0024B9C8[];
extern s32 D_L39_0024112C[];
extern Item D_L39_0049C890[];
extern int func_L39_00648AE0(void *,int);
extern u8 *func_005AA140(int,int);
extern void func_005AA510(void *);
extern void func_005B4AE8(void *,int,int,int);
static __inline__ Item *item(u8 *g,int n) {
 if(func_L39_00648AE0(g,n))return &D_L39_0049C890[D_L39_0049C890[n].alternate];
 return &D_L39_0049C890[n];
}
void func_L39_0063FDA8(u8 *g) {
 Buffer buf; u8 *o; int n,elapsed; u8 *q,*hk,*d; u32 key; s32 k,m,i;
 if(!*(void **)(g+0x450) && *(s32 *)(g+0x464)<D_L39_0024B9C8[0] &&
     (!({
 u8 *q=g+0x1A19; u32 r;
 if(*q==0) r=0;
 else {
  s32 n=*q; s32 k=((u32)q-n)&7; s32 m=n+1; s32 i; u8 *d=buf.b; u32 a,t;
  for(i=0;i<24;i+=3) *d++=D_L39_00480760[m+((k+i)&7)*193];
  a=buf.w[0]^(u32)q; buf.w[0]=a; t=buf.w[1]^a;
  r=t>>16; r=r/(((t^r)<<16)+1); buf.w[1]=r;
 } r;
}) || ({
 u8 *q=g+0x1A1F; u32 r;
 if(*q==0) r=0;
 else {
  s32 n=*q; s32 k=((u32)q-n)&7; s32 m=n+1; s32 i; u8 *d=buf.b; u32 a,t;
  for(i=0;i<24;i+=3) *d++=D_L39_00480760[m+((k+i)&7)*193];
  a=buf.w[0]^(u32)q; buf.w[0]=a; t=buf.w[1]^a;
  r=t>>16; r=r/(((t^r)<<16)+1); buf.w[1]=r;
 } r;
})==({
 u8 *q=g+0x1A19; u32 r;
 if(*q==0) r=0;
 else {
  s32 n=*q; s32 k=((u32)q-n)&7; s32 m=n+1; s32 i; u8 *d=buf.b; u32 a,t;
  for(i=0;i<24;i+=3) *d++=D_L39_00480760[m+((k+i)&7)*193];
  a=buf.w[0]^(u32)q; buf.w[0]=a; t=buf.w[1]^a;
  r=t>>16; r=r/(((t^r)<<16)+1); buf.w[1]=r;
 } r;
}))) {
  n=({
 u8 *q=g+0x1A1F; u32 r;
 if(*q==0) r=0;
 else {
  s32 n=*q; s32 k=((u32)q-n)&7; s32 m=n+1; s32 i; u8 *d=buf.b; u32 a,t;
  for(i=0;i<24;i+=3) *d++=D_L39_00480760[m+((k+i)&7)*193];
  a=buf.w[0]^(u32)q; buf.w[0]=a; t=buf.w[1]^a;
  r=t>>16; r=r/(((t^r)<<16)+1); buf.w[1]=r;
 } r;
});
  if(!n)n=*(s32 *)(g+0x18D0)?*(s32 *)(g+0x18D0):10;
  *(s32 *)(g+0x478)=n;
  o=func_005AA140(item(g,n)->primary,128);
  if(o) {
   *(s16 *)(o+0x32)=255; o[0x31]=1;
   *(long *)(o+0x38)=*(long *)(*(u8 **)(g+0x2524)+0x38);
   *(void **)(o+0xB8)=*(void **)(g+0x2524);
   if(g[0x1A14]==0)o[0x62]=0;
   if(*(u8 **)(o+0x24) && (*(u8 **)(o+0x24))[6])o[0x63]=16;
   *(void **)(g+0x450)=o; *(s32 *)(g+0x474)=2; g[0x468]=0;
   elapsed=D_L39_0024112C[0] - ({
 u8 *q=g+n+0x1A42; u32 r;
 if(*q==0) r=0;
 else {
  s32 n=*q; s32 k=((u32)q-n)&7; s32 m=n+1; s32 i; u8 *d=buf.b; u32 a,t;
  for(i=0;i<40;i+=5) *d++=D_L39_0049AAC0[m+((k+i)&7)*193];
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
  for(i=0;i<24;i+=3) *d++=D_L39_00483A00[m+((k+i)&7)*209];
  a=buf.w[0]^(u32)q; buf.w[0]=a; t=buf.w[1]^a;
  r=t>>16; r=r/(((t^r)<<16)+1); buf.w[1]=r;r=buf.h[2];
 } r;
})<<16)==0)g[0x468]=255;
   if(n==10) {
    *(void **)(o+0x90)=*(void **)g; *(s32 *)(g+0x474)=2; *(s32 *)(g+0x460)=128;
    func_005B4AE8(o,1,0,1);
   }else *(s32 *)(g+0x460)=32;
   n=*(s32 *)(g+0x478);
   {
    u8 tag=item(g,n)->tag;
    q=g+0x1A17; hk=q;
    if(*q==0)*q=++D_L39_004997E0[0];
    else { s32 t=*q; *q=D_L39_004997E1[0]; D_L39_004997E1[0]=t; }
    buf.b[4]=tag;
    key=((u32 *)D_L39_004997E0)[((u32)hk*D_L39_0024B9C8[0])%510];
    k=((u32)q-*q)&7;
    buf.w[1]=((buf.w[1]&0xFFFF)|(buf.w[1]<<16))^key;
    buf.w[0]=(u32)q^key;
    m=*q+1;d=buf.b;
    for(i=0;i<24;i+=3)D_L39_004997E0[m+((k+i)&7)*255]=*d++;
   }
  }
 }
 if(*(void **)(g+0x4F0)) {func_005AA510(*(void **)(g+0x4F0));*(void **)(g+0x4F0)=0;}
 if(!*(void **)(g+0x4A0)) {
  n=*(s32 *)(g+0x18D4); *(s32 *)(g+0x4C8)=n;
  if(n) {
   o=func_005AA140(item(g,n)->primary,128);
   if(o) {
    *(s16 *)(o+0x32)=128; o[0x31]=1;
    *(long *)(o+0x38)=*(long *)(*(u8 **)(g+0x2524)+0x38);
    *(s32 *)(o+0x64)=0;
    if(*(u8 **)(o+0x24) && (*(u8 **)(o+0x24))[6])o[0x63]=16;
    *(void **)(g+0x4A0)=o; *(s32 *)(g+0x4C4)=2;
   }
   n=*(s32 *)(g+0x4C8); o=func_005AA140(item(g,n)->secondary,128);
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
/* localdecomp:end func_L39_0063FDA8 */

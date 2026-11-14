#include "common.h"
#include "vu0.h"
/* localdecomp:start func_L39_0066B7F8 */
extern u8 *func_L39_0066B638(void);
extern u8 *func_L39_00619838(u32);
extern void *func_L39_00665D00(u32);
extern void *func_L39_006698E8(u32);
extern s32 D_L39_002412E0;
extern s32 D_L39_0024072C;
extern u8 D_001A5E50[];
extern s32 func_00197588(s32);
extern void func_0014AD08(s32,s32,s32,s32,s32,void *);
typedef struct { float xyz[3]; s32 tick; u32 a,b; s32 id; u8 type; } Packet;
s32 func_L39_0066B7F8(u32 a,u32 b,s32 type,s32 net,s32 id,s32 tick,s32 value,float *pos) {
 Packet packet;
 u8 *p;
 if(type>=5) {
 p=func_L39_0066B638();
 if(p) {
 *(short *)(p+0x34)=type;
 *(s32 *)(p+0x64)=net;
 if(pos) {
  float *dst=(float *)(p+0x10);
  dst[0]=pos[0]; dst[1]=pos[1]; dst[2]=pos[2]; dst[3]=0;
 } else qzero(p+0x10);
 *(u32 *)(p+0x54)=a;
 if(((a>>24)&15)==0) {
  u8 *o=func_L39_00619838(a);
  *(void **)(p+0x4c)=o;
  if(o) *(s32 *)(p+0x2c)=*(s32 *)(o+0x2524);
  else *(s32 *)(p+0x2c)=0;
 }
 *(u32 *)(p+0x50)=b;
 *(s32 *)(p+0x40)=0; *(s32 *)(p+0x44)=0; *(s32 *)(p+0x48)=0;
 if(((b>>24)&15)==0) *(void **)(p+0x40)=func_L39_00619838(b);
 else if(((b>>24)&15)==3) *(void **)(p+0x44)=func_L39_00665D00(b);
 else if(((b>>24)&15)==2) *(void **)(p+0x48)=func_L39_006698E8(b);
 *(s32 *)(p+0x60)=0; *(s32 *)(p+0x5c)=0x106d;
 if(net) {
  u8 *g=D_001A5E50;
  *(s32 *)(p+0x38)=D_L39_002412E0;
  *(s32 *)(p+0x28)=value;
  *(short *)(p+0x36)=0;
  *(s32 *)(p+0x3c)=*(s32 *)(g+0x128);
  *(s32 *)(p+0x58)=func_00197588(1);
  { float *src=(float *)(p+0x10);
  packet.type=type;
  packet.id=*(s32 *)(p+0x58); packet.a=a; packet.b=b;
  packet.xyz[0]=src[0];
  packet.xyz[1]=src[1];
  packet.xyz[2]=src[2];
  packet.tick=*(s32 *)(g+0x128);
  if(!*(s32 *)(g+0x170)) func_0014AD08(g[0x7d4],*(s32 *)(g+4),-1,D_L39_0024072C,32,&packet);
  }
 } else {
  *(s32 *)(p+0x3c)=tick;
  *(short *)(p+0x36)=1;
  *(s32 *)(p+0x58)=id;
  *(s32 *)(p+0x38)=0;
 }
 return *(s32 *)(p+0x58);
 }
 }
 return -1;
}
/* localdecomp:end func_L39_0066B7F8 */

#include "common.h"
/* localdecomp:start func_L07_003C5AD8 */
typedef struct { f32 x,y,z,w; } __attribute__((aligned(16))) V_3C5AD8;
typedef union {u8 b[0x500];s16 h[0x280];u16 uh[0x280];s32 i[0x140];u32 u[0x140];f32 f[0x140];void *p[0x140];V_3C5AD8 v[0x50];} O_3C5AD8;
extern u8 *D_L07_001DF41C_003C5AD8, *D_L07_001DF500;
extern s32 *D_L07_0021D2C0[];
extern u8 D_L07_003C8268[],D_L07_003C8378[];
extern void func_L07_003C64C8(void *),func_L07_003C6718(void *);
extern s32 func_L01_00452EC8(void *),func_L07_003C6FA0(void *),func_003883C8(void *);
extern void func_L07_003C6D58(void *,s32);
extern void func_L01_00407180(void *,void *,void *,s32,s32,s32,s32,s32,u32,u32);
extern void func_L07_003C7050(void *),func_L07_003C70C8(void *),func_L07_003C7158(void *),func_L07_003C72D0(void *),func_L07_003C7110(void *),func_L07_003C71A0(void *),func_L07_003C71E0(void *),func_L07_003C7270(void *);
extern void func_L07_003C7AC8(void *,s32,s32);
extern s32 func_L01_00458AE0(void *,s32);
extern s32 func_L01_004576E8(void *);
extern s32 func_L01_00451078(void *,void *);
extern void func_L07_003C7338(void *,f32),func_L07_003C7638(void *,void *,f32);
extern f32 func_00388A28(f32,f32),func_L01_0040C040(void *,void *),func_00388800(void *,void *),func_00389468(f32,f32);
extern void func_L07_003C7790(void *,void *),func_L01_00457708(void *,f32);
extern s32 func_L01_00457440(void *,void *),func_L07_003B9638(void *);
extern s32 func_0039FE80(s32,s32,void *);
extern void func_L07_003C73A0(void *),func_L07_003C77E8(void *,void *),func_L07_003C7E20(void *),func_L07_003C7DC0(void *,void *,f32,f32),func_L07_003C78C0(void *),func_L07_003C7FE0(void *);
extern void func_L01_00402498(void *,void *),func_L07_003C7738(void *);
extern f32 func_L07_003C7B68(void *);
extern void func_L07_003C7D00(void *,void *,f32),func_003886C0(void *,void *,void *,f32),func_L07_003C6B50(void *,void *);
void func_L07_003C5AD8(O_3C5AD8 *m) {
 O_3C5AD8 *p;V_3C5AD8 old,tmp;f32 radius,angle,dist,t;
 if(m->b[0x20]==1)return;
 if(!m->b[0x20])func_L07_003C64C8(m);
 func_L07_003C6718(m);p=m->p[0x68/4];old=m->v[0x10/16];
 switch(m->b[0x20]) {
 case 2:
  if(func_L01_00452EC8(m))p->uh[0x4C6/2]=p->uh[0x4C4/2];
  if(func_L07_003C6FA0(m)&&func_003883C8(p->b+0x4C6))func_L07_003C6D58(m,3);break;
 case 3:
  {u8 *r=D_L07_001DF41C_003C5AD8+(p->i[0x4C0/4]<<8);
  func_L01_00407180(m,r+0x10,r+0xF0,0,2,3,45,45,0x00FF8040,0x008F1010);}
  p->v[0x440/16]=m->v[0x10/16];func_L07_003C7050(m);break;
 case 4:
  if(func_L01_00452EC8(m))func_L07_003C7AC8(m,p->i[0x4A8/4],2);
  if(func_L07_003C6FA0(m))func_L07_003C7158(m);
  else if(func_L01_00458AE0(m,p->i[0x4A8/4]))func_L07_003C6D58(m,4);break;
 case 5:
  func_L01_004576E8(m);if(func_L07_003C6FA0(m))func_L07_003C7158(m);break;
 case 6:
  if(func_L01_00452EC8(m))func_L07_003C7AC8(m,p->i[0x4AC/4],1);
  if(func_L07_003C6FA0(m))func_L07_003C6D58(m,10);
  else if(func_L01_00458AE0(m,p->i[0x4AC/4]))func_L07_003C70C8(m);break;
 case 7:
  if(func_L07_003C6FA0(m))func_L07_003C72D0(m);break;
 case 8:
  func_L01_004576E8(m);
  if(func_L01_00451078(m,p->b+0x70)&2) {
   if(p->i[0x4B8/4]==-1&&p->i[0x4B0/4]==-1)func_L07_003C6D58(m,9);else func_L07_003C72D0(m);
  }break;
 case 9:
  if(func_L01_00452EC8(m))p->h[0x4C6/2]=300;
  if(func_L07_003C6FA0(m))func_L07_003C7158(m);
  else if(func_003883C8(p->b+0x4C6))func_L07_003C7110(m);break;
 case 10:
  if(func_L01_00452EC8(m))func_L07_003C7AC8(m,p->i[0x4AC/4],0);
  if(!func_L07_003C6FA0(m))func_L07_003C6D58(m,9);
  else if(func_L01_00458AE0(m,p->i[0x4AC/4]))func_L07_003C71A0(m);break;
 case 11:
  if(func_L01_00452EC8(m)){O_3C5AD8 *sub=(O_3C5AD8 *)(p->b+0x150);sub->u[0x38/4]|=0x10;}
  radius=p->f[0x4CC/4]+(p->f[0x4D0/4]-p->f[0x4CC/4])*0.6000000238418579f;
  func_L07_003C7338(m,p->f[0x4CC/4]+(p->f[0x4D0/4]-p->f[0x4CC/4])*0.5f);
  angle=func_00388A28(p->f[0x130/4]-m->f[0x10/4],p->f[0x134/4]-m->f[0x14/4]);
  func_L07_003C7638(m,&old,angle);func_L07_003C7790(m,p->b+0x130);
  if(!func_L07_003C6FA0(m))func_L07_003C6D58(m,9);
  else if(func_003883C8(p->b+0x4D4)) {
   if (!(func_L01_0040C040(m->b+0x10,p->b+0x130)<radius*radius)) break;goto select;
  }break;
 case 12:
  if(!func_L07_003C6FA0(m))func_L07_003C6D58(m,9);
  else {
   if(p->i[0x1D0/4]>=11)p->b[0x4DD]=1;
   if(p->b[0x4DD]||(func_L01_00457440(m,p->b+0x440)&0x80))func_L07_003C6D58(m,13);
  }break;
 case 13:
  if(!func_L07_003C6FA0(m)) {func_L07_003C6D58(m,9);break;}
  angle=func_00388A28(p->f[0x130/4]-m->f[0x10/4],p->f[0x134/4]-m->f[0x14/4]);
  func_L01_00457708(m,angle);dist=func_00388800(m->b+0x10,p->b+0x130);
  if(func_003883C8(p->b+0x4D4)&&p->f[0x4CC/4]<dist&&dist<p->f[0x4D0/4]) {
   if(func_00389468(angle,m->f[0xF8/4])<0.4363323152065277f) {
select:
   p->h[0x460/2]=func_L07_003B9638(m);if(p->h[0x460/2]<=0)func_L07_003C71E0(m);
   }
  }break;
 case 14:case 18:
  func_L01_004576E8(m);if(m->b[0x60]&2)func_L07_003C6D58(m,m->b[0x20]+1);break;
 case 15:case 19:
  if(func_L01_00452EC8(m)){func_0039FE80(2,0,m);p->h[0x4C6/2]=30;}
  func_L01_004576E8(m);func_L07_003C73A0(m);func_L07_003C77E8(m,p->b+0x470);func_L07_003C7E20(m);
  if(func_003883C8(p->b+0x4C6))func_L07_003C6D58(m,m->b[0x20]+1);break;
 case 16:case 20:
  if(func_L01_00452EC8(m)){p->i[0x488/4]=0;p->h[0x4C6/2]=30;func_0039FE80(1,0,m);}
  func_L01_004576E8(m);func_L07_003C77E8(m,p->b+0x470);
  func_L07_003C7DC0(p->b+0x488,p->b+0x48C,0.10000000149011612f,0.1599999964237213f);
  func_L07_003C78C0(m);func_L07_003C7FE0(m);func_L01_00402498(D_L07_003C8268,m);
  if(func_003883C8(p->b+0x4C6))func_L07_003C6D58(m,m->b[0x20]+1);break;
 case 17:case 21:
  func_L01_004576E8(m);if(m->b[0x60]&2)func_L07_003C7270(m);break;
 case 22:
  func_L01_004576E8(m);if(m->b[0x60]&2)func_L07_003C71A0(m);break;
 case 23:
  if(!func_L07_003C6FA0(m))goto fail7;
  else if(func_L01_00457440(m,D_L07_001DF500+(p->i[0x4B8/4]<<7)+0x30)&0x80)func_L07_003C6D58(m,24);break;
 case 24:
  if(func_L01_00452EC8(m)){p->i[0x488/4]=0;p->f[0x4C8/4]=m->f[0xF8/4];}
  if(!func_L07_003C6FA0(m))goto fail7;
  func_L07_003C7DC0(p->b+0x488,p->b+0x48C,0.009999999776482582f,0.1599999964237213f);func_L01_00402498(D_L07_003C8378,m);func_L01_004576E8(m);
  goto velocity;
 case 25:
  if(func_L01_00452EC8(m)) {
   {O_3C5AD8 *sub=(O_3C5AD8 *)(p->b+0x150);sub->u[0x38/4]|=0x10;}func_L07_003C7AC8(m,p->i[0x4B0/4],2);
   if(m->b[0x94]!=m->b[0x20]) {
    p->i[0x488/4]=0;p->f[0x4C8/4]=m->f[0xF8/4];
    if(m->b[0x94]!=m->b[0x20])func_0039FE80(1,0,m);
   }
  }
  if(!func_L07_003C6FA0(m))goto fail7;
  func_L07_003C7DC0(p->b+0x488,p->b+0x48C,0.009999999776482582f,0.1599999964237213f);func_L01_00402498(D_L07_003C8378,m);
  if(func_L01_00458AE0(m,p->i[0x4B0/4]))func_L07_003C6D58(m,25);
  func_L07_003C7638(m,&old,m->f[0xF8/4]);
velocity:
  func_L07_003C7738(m);t=p->f[0x4BC/4]*0.01745329238474369f;p->f[0x3A0/4]=t;p->f[0x320/4]=-t;break;
fail7:
  func_L07_003C6D58(m,7);break;
 case 26:
  if(func_L01_00452EC8(m)) {
   {O_3C5AD8 *sub=(O_3C5AD8 *)(p->b+0x150);sub->u[0x38/4]|=0x10;}func_L07_003C7AC8(m,p->i[0x4B0/4],2);
   if(m->b[0x94]!=m->b[0x20]) {
    p->i[0x488/4]=0;t=func_L07_003C7B68(m);func_L07_003C7D00(D_L07_0021D2C0[p->i[0x4B4/4]],p->b+0x470,t*(f32)*D_L07_0021D2C0[p->i[0x4B4/4]]);
    if(m->b[0x94]!=m->b[0x20])func_0039FE80(1,0,m);
   }
  }
  if(func_L07_003C6FA0(m)) {
  t=func_L07_003C7B68(m);func_L07_003C7D00(D_L07_0021D2C0[p->i[0x4B4/4]],&tmp,t*(f32)*D_L07_0021D2C0[p->i[0x4B4/4]]);
  func_003886C0(p->b+0x470,p->b+0x470,&tmp,0.10000000149011612f);
  func_L07_003C7DC0(p->b+0x488,p->b+0x48C,0.009999999776482582f,0.1599999964237213f);func_L07_003C78C0(m);func_L07_003C7FE0(m);func_L01_00402498(D_L07_003C8268,m);
  if(func_L01_00458AE0(m,p->i[0x4B0/4]))func_L07_003C6D58(m,26);
  func_L07_003C7638(m,&old,m->f[0xF8/4]);func_L07_003C7790(m,p->b+0x470);func_L07_003C77E8(m,p->b+0x470);
  } else func_L07_003C6D58(m,7);break;
 }
 func_L07_003C6B50(m,&old);
}
/* localdecomp:end func_L07_003C5AD8 */

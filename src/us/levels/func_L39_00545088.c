#include "common.h"
#include "vu0.h"
/* localdecomp:start func_L39_00545088 */
extern u8 D_L39_0024DF80[];
extern u8 *D_001D5A54_sda_00545088,*D_001D5F30_sda_00545088;
extern int D_001DF738_sda;
extern void func_003886E8(void *,void *,float);
extern void func_L01_003F4D78(int,void *,u32,void *,int,int,int,float,float,float,float,float,float,float);
extern int func_L01_003EFFE0(int,int);
extern void func_L39_00544EB0(void *,void *,u32);
extern int func_003883C8(void *);
void func_L39_00545088(u8 *m) {
 vu0_v4 pos;
 u8 *v=*(u8 **)(m+0x68);
 u8 *g=D_L39_0024DF80,*pad=D_001D5A54_sda_00545088,*o;
 int player=0;
 o=*(u8 **)(v+0x384);
 if(o && *(u8 **)(o+0x2d8)) {
  u8 *p=*(u8 **)(o+0x2d8);
  pad=*(u8 **)(p+0x2534);g=*(u8 **)(p+0x2530);player=p[0x24c9];
 }
 *(int *)(m+0x98)=0;
 func_003886E8(&pos,g+0x380,250.0f);
 vec_add_ab(&pos,&pos,m+0x10);
 func_L01_003F4D78(player,m,0xff0fff0f,&pos,35,-1,4,1.0f,0.0f,90.0f,0.5f,0.5f,40.0f,40.0f);
 if(*(int *)(v+0x3d4)>0) {
  (*(int *)(v+0x3e4))++;
  if(*(int *)(v+0x3e4)>10) *(int *)(v+0x3e4)=10;
 } else *(int *)(v+0x3e4)=0;
 if((*(int *)(pad+0x1a0)&0x28) && *(u8 **)(v+0x384) && *(u8 **)(*(u8 **)(v+0x384)+0x2d8)
    && *(short *)(*(u8 **)(*(u8 **)(v+0x384)+0x2d8)+0x320)==0 && *(short *)(v+0x37e)==0
    && *(int *)(v+0x3d4)>0 && *(int *)(v+0x3e4)>=3) {
  if(!*(s8 *)(D_001D5F30_sda_00545088+0x19b)) (*(int *)(v+0x3d4))--;
  *(int *)(v+0x3d8)=25;
  if(*(u8 **)(v+0x384) && *(u8 **)(*(u8 **)(v+0x384)+0x2d8)) {
   u8 *p=*(u8 **)(*(u8 **)(v+0x384)+0x2d8);
   if(p[0x1a14]) func_L01_003EFFE0(D_001DF738_sda,(int)*(u8 **)(p+0x2534));
  }
  func_L39_00544EB0(m,&pos,0xffffffff);
 }
 func_003883C8(v+0x37e);
 if(--*(int *)(v+0x3d8)<=0 && *(int *)(v+0x3d4)<8) {
  *(int *)(v+0x3d8)=25;(*(int *)(v+0x3d4))++;
 }
 *(int *)(m+0x98)=*(int *)(*(u8 **)(m+0x24)+0x10);
}
/* localdecomp:end func_L39_00545088 */

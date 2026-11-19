/* functional: medium. From the repo first-reconstruction draft (not a verified port) re-checked here: the retail jal sequence matches the draft call for call (45 calls, loops included), the set of 41 gp slots is identical to the asm's, and every float/int constant in the asm (0.02, 0.05, 0.4, 0.7, 1.25, 1.5, 2.0, 7.0, 100.0, 210000.0, -0.002, -0.14835, 0.04363, 0x1C7E, 0x44/0x48, /6, 30, 0x7F) is in the C. Not checked: block-level operand order (537 diff words, scheduling) and the vector-op operand order in the VU helper calls. */
#include "common.h"
#include "vu0.h"
extern u8 D_L30_001DD974;
__asm__(".extern D_L30_001DD974, 1");
extern u8 D_L30_001DD975;
__asm__(".extern D_L30_001DD975, 1");
extern u8 D_L30_001DD976;
__asm__(".extern D_L30_001DD976, 1");
extern u8 D_L30_001DD977;
__asm__(".extern D_L30_001DD977, 1");
extern u8 D_L30_001DD979;
__asm__(".extern D_L30_001DD979, 1");
extern f32 D_L30_001DD860;
__asm__(".extern D_L30_001DD860, 4");
extern f32 D_L30_001DD864;
__asm__(".extern D_L30_001DD864, 4");
extern f32 D_L30_001DD8A0;
__asm__(".extern D_L30_001DD8A0, 4");
extern f32 D_L30_001DD8A4;
__asm__(".extern D_L30_001DD8A4, 4");
extern f32 D_L30_001DD97C;
__asm__(".extern D_L30_001DD97C, 4");
extern f32 D_L30_001DD980;
__asm__(".extern D_L30_001DD980, 4");
extern f32 D_L30_001DD984;
__asm__(".extern D_L30_001DD984, 4");
extern f32 D_L30_001DD988;
__asm__(".extern D_L30_001DD988, 4");
extern f32 D_L30_001DD998;
__asm__(".extern D_L30_001DD998, 4");
extern f32 D_L30_001DD99C;
__asm__(".extern D_L30_001DD99C, 4");
extern f32 D_L30_001DD9A0;
__asm__(".extern D_L30_001DD9A0, 4");
extern f32 D_L30_001DD9A4;
__asm__(".extern D_L30_001DD9A4, 4");
extern f32 D_L30_001DD9AC;
__asm__(".extern D_L30_001DD9AC, 4");
extern f32 D_L30_001DD9B0;
__asm__(".extern D_L30_001DD9B0, 4");
extern f32 D_L30_001DD9B4;
__asm__(".extern D_L30_001DD9B4, 4");
extern f32 D_L30_001DD9B8;
__asm__(".extern D_L30_001DD9B8, 4");
extern f32 D_L30_001DD9C4;
__asm__(".extern D_L30_001DD9C4, 4");
extern f32 D_L30_001DD9C8;
__asm__(".extern D_L30_001DD9C8, 4");
extern f32 D_L30_001DD9CC;
__asm__(".extern D_L30_001DD9CC, 4");
extern f32 D_L30_001DD9E0;
__asm__(".extern D_L30_001DD9E0, 4");
extern f32 D_L30_001DD9E4;
__asm__(".extern D_L30_001DD9E4, 4");
extern f32 D_L30_001DD9E8;
__asm__(".extern D_L30_001DD9E8, 4");
extern f32 D_L30_001DD9EC;
__asm__(".extern D_L30_001DD9EC, 4");
extern f32 D_L30_001DDA30;
__asm__(".extern D_L30_001DDA30, 4");
extern f32 D_L30_001DDA34;
__asm__(".extern D_L30_001DDA34, 4");
extern s32 D_L30_001DD868;
__asm__(".extern D_L30_001DD868, 4");
extern s32 D_L30_001DD98C;
__asm__(".extern D_L30_001DD98C, 4");
extern s32 D_L30_001DD990;
__asm__(".extern D_L30_001DD990, 4");
extern s32 D_L30_001DD994;
__asm__(".extern D_L30_001DD994, 4");
extern s32 D_L30_001DD9A8;
__asm__(".extern D_L30_001DD9A8, 4");
extern s32 D_L30_001DD9BC;
__asm__(".extern D_L30_001DD9BC, 4");
extern s32 D_L30_001DD9C0;
__asm__(".extern D_L30_001DD9C0, 4");
extern s32 D_L30_001DD9D0;
__asm__(".extern D_L30_001DD9D0, 4");
extern s32 D_L30_001DD9D4;
__asm__(".extern D_L30_001DD9D4, 4");
extern s32 D_L30_001DD9D8;
__asm__(".extern D_L30_001DD9D8, 4");
extern s32 D_L30_001DD9F0;
__asm__(".extern D_L30_001DD9F0, 4");
extern s32 D_L30_001DD9F4;
__asm__(".extern D_L30_001DD9F4, 4");
extern s32 D_L30_001DD9F8;
__asm__(".extern D_L30_001DD9F8, 4");
extern s32 D_L30_001DD9FC;
__asm__(".extern D_L30_001DD9FC, 4");
extern s32 D_L30_001DDA20;
__asm__(".extern D_L30_001DDA20, 4");
extern s32 D_L30_001DDA24;
__asm__(".extern D_L30_001DDA24, 4");
extern s32 D_L30_001DDA28;
__asm__(".extern D_L30_001DDA28, 4");
extern s32 D_L30_001DDA2C;
__asm__(".extern D_L30_001DDA2C, 4");
typedef struct { u8 p0[0x18]; f32 angle; s32 count; } Vars_352208;
typedef struct { u8 p0[0x10]; vu0_v4 pos; u8 p20[0x48]; Vars_352208 *vars; } Obj_352208;
typedef struct {
 u8 p0[0x80]; vu0_v4 pos; u8 p90[0x80]; vu0_v4 vel; u8 p120[0x1A04];
 u8 *weapon; u8 p1B28[0xA98]; u8 *moby;
} Hero_352208;
extern Hero_352208 D_001A4BE0;
extern s32 D_L30_001DF2C0;
extern f32 D_L30_001E2248;
extern vu0_v4 D_L30_001E2110,D_L30_001E9040;
extern u8 D_L30_001E2120[];
extern u8 *D_L30_0021F204;
extern u8 *D_L30_0021F098[];
extern u8 D_L30_001D66B0[8];
extern f32 func_L30_004E6988(void);
extern void func_003C2F58(void *,s32,void *);
extern f32 func_003824E0(f32,f32);
extern f32 func_0038DB48(f32);
extern f32 func_0038DAB8(f32,f32);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern void func_0038CF68(void *,void *,f32);
extern void func_L30_003B92B0(void *,void *);
extern void func_L30_0034CB68(void *,void *,s32,s32,void *,s32,f32,f32);
extern s32 func_L01_003FB640(void *,s32,void *,f32);
extern void func_0038CE20(void *,void *,f32);
extern s32 func_00382498(s32,s32);
extern u8 *func_L01_004708C8(void *,void *,u32,u32,s32,s32,s32,s32,s32,f32,f32);
extern u8 *func_L01_0046FB40(void *,void *,s32,u32,s32,s32,s32,s32,f32,f32,f32);
extern s32 func_00382468(s32);
extern void func_0038D890(void *,void *,void *,f32);
extern f32 func_L01_00443A18(f32,f32);
extern void func_L30_00351D10(void *,void *,void *);
extern void func_L30_00352050(s32,void *,void *);
void func_L30_00352208(void *arg) {
 Obj_352208 *m=arg; Vars_352208 *v=m->vars;
 vu0_v4 dir,pos,scaled,pos2,vel,heroVel,burstPos,burstVel,rot;
 vu0_v4 posA,velA,dirB,velB,posC,dirC,velC,off;
 f32 ratio=(f32)v->count/(f32)D_L30_001DD868;
 f32 angle,speed,scale,life,size; s32 i,j,count,randn; u8 *p;
 if(ratio>1.0f) ratio=1.0f;
 if(!D_001A4BE0.weapon || *(s16 *)(D_001A4BE0.weapon+0xAA)!=0x1C7E) return;
 v->angle=func_L30_004E6988();
 func_003C2F58(D_001A4BE0.weapon,1,&m->pos);
 angle=func_0038DAB8(func_0038DB48(func_003824E0(-D_L30_001DD864,D_L30_001DD864)),v->angle);
 speed=func_003824E0(D_L30_001DD8A4,D_L30_001DD8A0);
 dir.x=func_0038D098(angle)*speed;
 dir.z=func_0038D0B0(angle)*speed;
 *(vu0_q *)&pos=*(vu0_q *)&m->pos;
 pos.y=100.0f; dir.y=0;
 if(D_001A4BE0.pos.z<D_L30_001E2248-1.0f) pos.z+=D_L30_001DDA34;
 func_0038CF68(&scaled,&dir,ratio*7.0f);
 *(vu0_q *)&pos2=*(vu0_q *)&pos;
 pos2.z-=D_L30_001DDA30;
 scale=func_003824E0(D_L30_001DD9E0,D_L30_001DD9E4);
 func_0038CF68(&vel,&dir,scale*0.0200000014f);
 *(vu0_q *)&heroVel=*(vu0_q *)&D_001A4BE0.vel;
 heroVel.z=0;
 vec_add_ab(&vel,&vel,&heroVel);
 if(D_L30_001DF2C0%D_L30_001DDA20==0 || v->count==1) {
  func_L30_003B92B0(&m->pos,&vel);
  func_L30_0034CB68(m,&dir,0,-1,&pos2,0,D_L30_001DD860,2.0f);
 }
 if(D_L30_001DD979 && func_L01_003FB640(&scaled,0,D_001A4BE0.moby,1.25f)) {
  func_0038CE20(&burstVel,&D_L30_001E2110,0.05f);
  func_0038CF68(&burstPos,&D_L30_001E9040,0.05f);
  vec_add_ab(&burstPos,&D_L30_001E9040,&burstPos);
  life=func_003824E0(0.4f,0.7f)*210000.0f;
  count=func_00382498(8,17);
  p=func_L01_004708C8(&burstPos,D_L30_001D66B0,0x4F5050FF,0x102434EE,count,1,-1,-1,1,life,1.5f);
  if(p) p[2]=*D_L30_0021F204;
 }
 *(vu0_q *)&rot=*(vu0_q *)(D_001A4BE0.moby+0xE0);
 func_0038CE20(&rot,&rot,D_L30_001DD984);
 *(vu0_q *)&burstPos=*(vu0_q *)&pos;
 scale=func_003824E0(D_L30_001DD998,D_L30_001DD99C);
 func_0038CF68(&burstVel,&dir,scale*0.0200000014f);
 vec_sub_ab(&burstVel,&burstVel,&rot);
 vec_add_ab(&burstPos,&burstPos,&heroVel);
 for(i=0;i<D_L30_001DD9F0;i++) {
  if(D_L30_001DD974) func_L01_0046FB40(&burstPos,&burstVel,(D_L30_001DD994*5+2)/6,0x808080,30,D_L30_001DD98C,D_L30_001DD990,0,D_L30_001DD97C*210000.0f,D_L30_001DD980*210000.0f,D_L30_001DD988);
 }
 *(vu0_q *)&posA=*(vu0_q *)&pos;
 *(vu0_q *)&velA=*(vu0_q *)&burstVel;
 for(j=0;j<D_L30_001DD9F4;j++) {
  if(D_L30_001DD975) {
   p=func_L01_0046FB40(&posA,&velA,(D_L30_001DD9D0*5+2)/6,0x800000,30,D_L30_001DD9D4,D_L30_001DD9D8,0,D_L30_001DD9C4*210000.0f,D_L30_001DD9CC*210000.0f,D_L30_001DD9C8);
   if(p) {
    p[2]=*D_L30_0021F098[0x17];
    p[3]=func_00382468(2)?0x44:0x48;
   }
  }
 }
 *(vu0_q *)&dirB=*(vu0_q *)&dir;
 *(vu0_q *)&velB=*(vu0_q *)&vel;
 for(i=0;i<D_L30_001DD9F8;i++) {
  dirB.x=func_0038D098(v->angle)*speed;
  dirB.z=func_0038D0B0(v->angle)*speed;
  scale=func_003824E0(D_L30_001DD9E0*D_L30_001DD9E8,D_L30_001DD9E4*D_L30_001DD9E8);
  dirB.y=0;
  func_0038CF68(&velB,&dirB,scale*0.0200000014f);
  angle=func_003824E0(-0.14835298f,0.04363323f);
  func_0038D890(&velB,&velB,&D_L30_001E2120,angle);
  if(D_L30_001DD976) {
   count=(D_L30_001DD9A8*5+2)/6;
   randn=func_00382468(30);
   life=D_L30_001DD9A0*210000.0f; size=D_L30_001DD9A4*210000.0f;
   scale=func_L01_00443A18(-0.002f,0.0f);
   p=func_L01_0046FB40(&pos,&velB,count,0x808080,randn,0x7F,0,0,life,size,scale);
   if(p) {
    if(func_00382468(4)) {
     p[2]=D_L30_0021F098[0x5B][4];
     p[3]=func_00382468(4)?0x44:0x48;
    } else {
     p[3]=0x48; p[2]=D_L30_0021F098[0x5B][0];
    }
   }
  }
 }
 *(vu0_q *)&dirC=*(vu0_q *)&dir;
 *(vu0_q *)&velC=*(vu0_q *)&vel;
 dirC.x=func_0038D098(v->angle)*speed;
 dirC.z=func_0038D0B0(v->angle)*speed;
 scale=func_003824E0(D_L30_001DD9E0*D_L30_001DD9EC,D_L30_001DD9E4*D_L30_001DD9EC);
 dirC.y=0;
 func_0038CF68(&velC,&dirC,scale*0.0200000014f);
 func_0038CE20(&off,&D_L30_001E2120,D_L30_001DD9B8);
 vec_add_ab(&velC,&velC,&off);
 func_0038CE20(&off,&D_L30_001E2120,D_L30_001DD9B4);
 vec_add_ab(&posC,&off,&pos);
 for(i=0;i<D_L30_001DD9FC;i++) {
  if(D_L30_001DD977) {
   count=(D_L30_001DD9BC*5+2)/6; life=D_L30_001DD9AC*210000.0f; size=D_L30_001DD9B0*210000.0f;
   scale=func_L01_00443A18(-0.002f,0.0f);
   p=func_L01_0046FB40(&posC,&velC,count,D_L30_001DDA2C,30,D_L30_001DD9C0,D_L30_001DD9D8,0,life,size,scale);
   if(p) {
    p[3]=func_00382468(8)?0x48:0x44;
    p[2]=D_L30_0021F098[D_L30_001DDA24][D_L30_001DDA28];
   }
  }
 }
 func_L30_00351D10(m,&pos,&velB);
 func_L30_00352050((s32)m,&pos,&velB);
}

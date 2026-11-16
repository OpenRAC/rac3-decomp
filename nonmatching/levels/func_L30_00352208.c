/* P06 wave 3 first reconstruction from PAL retail; far from a match.
 * File flags: -mvu0-use-vf0-vf2 -O2 -G8 -fopt-stack
 * -mno-check-zero-division @ps2as.
 * Stock check.py: 537 positional differing words. Parameter spill/retention,
 * register allocation, VU0 operand-load order, per-loop counter lifetimes,
 * constant precision, and instruction scheduling still need work.
 * Existing shared VU0 helpers only; no ordinary EE inline assembly.
 * This is an initial reconstruction, not a verified semantic port.
 * INCLUDE_ASM remains in the owner and all shared placements.
 */
#include "common.h"
#include "vu0.h"
extern u8 D_001DD974_sda;
__asm__(".extern D_001DD974_sda, 1");
extern u8 D_001DD975_sda;
__asm__(".extern D_001DD975_sda, 1");
extern u8 D_001DD976_sda;
__asm__(".extern D_001DD976_sda, 1");
extern u8 D_001DD977_sda;
__asm__(".extern D_001DD977_sda, 1");
extern u8 D_001DD979_sda;
__asm__(".extern D_001DD979_sda, 1");
extern f32 D_001DD860_sda;
__asm__(".extern D_001DD860_sda, 4");
extern f32 D_001DD864_sda;
__asm__(".extern D_001DD864_sda, 4");
extern f32 D_001DD8A0_sda;
__asm__(".extern D_001DD8A0_sda, 4");
extern f32 D_001DD8A4_sda;
__asm__(".extern D_001DD8A4_sda, 4");
extern f32 D_001DD97C_sda;
__asm__(".extern D_001DD97C_sda, 4");
extern f32 D_001DD980_sda;
__asm__(".extern D_001DD980_sda, 4");
extern f32 D_001DD984_sda;
__asm__(".extern D_001DD984_sda, 4");
extern f32 D_001DD988_sda;
__asm__(".extern D_001DD988_sda, 4");
extern f32 D_001DD998_sda;
__asm__(".extern D_001DD998_sda, 4");
extern f32 D_001DD99C_sda;
__asm__(".extern D_001DD99C_sda, 4");
extern f32 D_001DD9A0_sda;
__asm__(".extern D_001DD9A0_sda, 4");
extern f32 D_001DD9A4_sda;
__asm__(".extern D_001DD9A4_sda, 4");
extern f32 D_001DD9AC_sda;
__asm__(".extern D_001DD9AC_sda, 4");
extern f32 D_001DD9B0_sda;
__asm__(".extern D_001DD9B0_sda, 4");
extern f32 D_001DD9B4_sda;
__asm__(".extern D_001DD9B4_sda, 4");
extern f32 D_001DD9B8_sda;
__asm__(".extern D_001DD9B8_sda, 4");
extern f32 D_001DD9C4_sda;
__asm__(".extern D_001DD9C4_sda, 4");
extern f32 D_001DD9C8_sda;
__asm__(".extern D_001DD9C8_sda, 4");
extern f32 D_001DD9CC_sda;
__asm__(".extern D_001DD9CC_sda, 4");
extern f32 D_001DD9E0_sda;
__asm__(".extern D_001DD9E0_sda, 4");
extern f32 D_001DD9E4_sda;
__asm__(".extern D_001DD9E4_sda, 4");
extern f32 D_001DD9E8_sda;
__asm__(".extern D_001DD9E8_sda, 4");
extern f32 D_001DD9EC_sda;
__asm__(".extern D_001DD9EC_sda, 4");
extern f32 D_001DDA30_sda;
__asm__(".extern D_001DDA30_sda, 4");
extern f32 D_001DDA34_sda;
__asm__(".extern D_001DDA34_sda, 4");
extern s32 D_001DD868_sda;
__asm__(".extern D_001DD868_sda, 4");
extern s32 D_001DD98C_sda;
__asm__(".extern D_001DD98C_sda, 4");
extern s32 D_001DD990_sda;
__asm__(".extern D_001DD990_sda, 4");
extern s32 D_001DD994_sda;
__asm__(".extern D_001DD994_sda, 4");
extern s32 D_001DD9A8_sda;
__asm__(".extern D_001DD9A8_sda, 4");
extern s32 D_001DD9BC_sda;
__asm__(".extern D_001DD9BC_sda, 4");
extern s32 D_001DD9C0_sda;
__asm__(".extern D_001DD9C0_sda, 4");
extern s32 D_001DD9D0_sda;
__asm__(".extern D_001DD9D0_sda, 4");
extern s32 D_001DD9D4_sda;
__asm__(".extern D_001DD9D4_sda, 4");
extern s32 D_001DD9D8_sda;
__asm__(".extern D_001DD9D8_sda, 4");
extern s32 D_001DD9F0_sda;
__asm__(".extern D_001DD9F0_sda, 4");
extern s32 D_001DD9F4_sda;
__asm__(".extern D_001DD9F4_sda, 4");
extern s32 D_001DD9F8_sda;
__asm__(".extern D_001DD9F8_sda, 4");
extern s32 D_001DD9FC_sda;
__asm__(".extern D_001DD9FC_sda, 4");
extern s32 D_001DDA20_sda;
__asm__(".extern D_001DDA20_sda, 4");
extern s32 D_001DDA24_sda;
__asm__(".extern D_001DDA24_sda, 4");
extern s32 D_001DDA28_sda;
__asm__(".extern D_001DDA28_sda, 4");
extern s32 D_001DDA2C_sda;
__asm__(".extern D_001DDA2C_sda, 4");
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
 f32 ratio=(f32)v->count/(f32)D_001DD868_sda;
 f32 angle,speed,scale,life,size; s32 i,j,count,randn; u8 *p;
 if(ratio>1.0f) ratio=1.0f;
 if(!D_001A4BE0.weapon || *(s16 *)(D_001A4BE0.weapon+0xAA)!=0x1C7E) return;
 v->angle=func_L30_004E6988();
 func_003C2F58(D_001A4BE0.weapon,1,&m->pos);
 angle=func_0038DAB8(func_0038DB48(func_003824E0(-D_001DD864_sda,D_001DD864_sda)),v->angle);
 speed=func_003824E0(D_001DD8A4_sda,D_001DD8A0_sda);
 dir.x=func_0038D098(angle)*speed;
 dir.z=func_0038D0B0(angle)*speed;
 *(vu0_q *)&pos=*(vu0_q *)&m->pos;
 pos.y=100.0f; dir.y=0;
 if(D_001A4BE0.pos.z<D_L30_001E2248-1.0f) pos.z+=D_001DDA34_sda;
 func_0038CF68(&scaled,&dir,ratio*7.0f);
 *(vu0_q *)&pos2=*(vu0_q *)&pos;
 pos2.z-=D_001DDA30_sda;
 scale=func_003824E0(D_001DD9E0_sda,D_001DD9E4_sda);
 func_0038CF68(&vel,&dir,scale*0.0200000014f);
 *(vu0_q *)&heroVel=*(vu0_q *)&D_001A4BE0.vel;
 heroVel.z=0;
 vec_add_ab(&vel,&vel,&heroVel);
 if(D_L30_001DF2C0%D_001DDA20_sda==0 || v->count==1) {
  func_L30_003B92B0(&m->pos,&vel);
  func_L30_0034CB68(m,&dir,0,-1,&pos2,0,D_001DD860_sda,2.0f);
 }
 if(D_001DD979_sda && func_L01_003FB640(&scaled,0,D_001A4BE0.moby,1.25f)) {
  func_0038CE20(&burstVel,&D_L30_001E2110,0.05f);
  func_0038CF68(&burstPos,&D_L30_001E9040,0.05f);
  vec_add_ab(&burstPos,&D_L30_001E9040,&burstPos);
  life=func_003824E0(0.4f,0.7f)*210000.0f;
  count=func_00382498(8,17);
  p=func_L01_004708C8(&burstPos,D_L30_001D66B0,0x4F5050FF,0x102434EE,count,1,-1,-1,1,life,1.5f);
  if(p) p[2]=*D_L30_0021F204;
 }
 *(vu0_q *)&rot=*(vu0_q *)(D_001A4BE0.moby+0xE0);
 func_0038CE20(&rot,&rot,D_001DD984_sda);
 *(vu0_q *)&burstPos=*(vu0_q *)&pos;
 scale=func_003824E0(D_001DD998_sda,D_001DD99C_sda);
 func_0038CF68(&burstVel,&dir,scale*0.0200000014f);
 vec_sub_ab(&burstVel,&burstVel,&rot);
 vec_add_ab(&burstPos,&burstPos,&heroVel);
 for(i=0;i<D_001DD9F0_sda;i++) {
  if(D_001DD974_sda) func_L01_0046FB40(&burstPos,&burstVel,(D_001DD994_sda*5+2)/6,0x808080,30,D_001DD98C_sda,D_001DD990_sda,0,D_001DD97C_sda*210000.0f,D_001DD980_sda*210000.0f,D_001DD988_sda);
 }
 *(vu0_q *)&posA=*(vu0_q *)&pos;
 *(vu0_q *)&velA=*(vu0_q *)&burstVel;
 for(j=0;j<D_001DD9F4_sda;j++) {
  if(D_001DD975_sda) {
   p=func_L01_0046FB40(&posA,&velA,(D_001DD9D0_sda*5+2)/6,0x800000,30,D_001DD9D4_sda,D_001DD9D8_sda,0,D_001DD9C4_sda*210000.0f,D_001DD9CC_sda*210000.0f,D_001DD9C8_sda);
   if(p) {
    p[2]=*D_L30_0021F098[0x17];
    p[3]=func_00382468(2)?0x44:0x48;
   }
  }
 }
 *(vu0_q *)&dirB=*(vu0_q *)&dir;
 *(vu0_q *)&velB=*(vu0_q *)&vel;
 for(i=0;i<D_001DD9F8_sda;i++) {
  dirB.x=func_0038D098(v->angle)*speed;
  dirB.z=func_0038D0B0(v->angle)*speed;
  scale=func_003824E0(D_001DD9E0_sda*D_001DD9E8_sda,D_001DD9E4_sda*D_001DD9E8_sda);
  dirB.y=0;
  func_0038CF68(&velB,&dirB,scale*0.0200000014f);
  angle=func_003824E0(-0.14835298f,0.04363323f);
  func_0038D890(&velB,&velB,&D_L30_001E2120,angle);
  if(D_001DD976_sda) {
   count=(D_001DD9A8_sda*5+2)/6;
   randn=func_00382468(30);
   life=D_001DD9A0_sda*210000.0f; size=D_001DD9A4_sda*210000.0f;
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
 scale=func_003824E0(D_001DD9E0_sda*D_001DD9EC_sda,D_001DD9E4_sda*D_001DD9EC_sda);
 dirC.y=0;
 func_0038CF68(&velC,&dirC,scale*0.0200000014f);
 func_0038CE20(&off,&D_L30_001E2120,D_001DD9B8_sda);
 vec_add_ab(&velC,&velC,&off);
 func_0038CE20(&off,&D_L30_001E2120,D_001DD9B4_sda);
 vec_add_ab(&posC,&off,&pos);
 for(i=0;i<D_001DD9FC_sda;i++) {
  if(D_001DD977_sda) {
   count=(D_001DD9BC_sda*5+2)/6; life=D_001DD9AC_sda*210000.0f; size=D_001DD9B0_sda*210000.0f;
   scale=func_L01_00443A18(-0.002f,0.0f);
   p=func_L01_0046FB40(&posC,&velC,count,D_001DDA2C_sda,30,D_001DD9C0_sda,D_001DD9D8_sda,0,life,size,scale);
   if(p) {
    p[3]=func_00382468(8)?0x48:0x44;
    p[2]=D_L30_0021F098[D_001DDA24_sda][D_001DDA28_sda];
   }
  }
 }
 func_L30_00351D10(m,&pos,&velB);
 func_L30_00352050((s32)m,&pos,&velB);
}

/* NTSC-U draft (Codex wave 3): C of func_L09_004054C8, the NTSC-U twin of func_L09_00407670, with NTSC-U names and addresses (the two versions' code differs).
 * near miss: 379 words differ on NTSC-U with "-O2 -G8 -fopt-stack -mno-check-zero-division" (the file's line: "-O2 -G8 -fopt-stack -mno-check-zero-division -mvu0-use-vf0-vf2 @ps2as") (NTSC-U twin "func_L09_004054C8", whose code is not the PAL one).
 * Worker's note: 379 diff; best log func_L09_004054C8.01.log; allowed flags verified once; documented inline-literal assembler mismatch lwc1 f13,-0x4000(gp) versus retail lui/ori/mtc1 0x3ABEA2F2; @ps2as is not permitted; frame/layout also differ
 */
#include "common.h"
#include "vu0.h"
typedef union {struct {f32 x,y,z,w;}; int q __attribute__((mode(TI)));} V_4054C8 __attribute__((aligned(16)));
extern char D_001A4BE0[];
extern char *D_L09_001DF904[];
extern V_4054C8 D_L09_002BBD90[],D_L09_002BBD80[];
extern char D_L09_001E2C00[],D_L09_001E9940[];
extern f32 D_L09_001DF7B8;
extern void func_L01_00445168(f32 *,f32 *,f32,f32,f32,f32);
extern f32 func_00388978(f32),func_00388960(f32);
extern void func_003886E8(void *,void *,f32);
extern void func_00388758(void *,void *,void *);
extern void func_00388830(void *,void *,f32);
extern void func_003888F0(void *,void *,void *);
extern void func_003886C0(void *,void *,void *,f32);
extern char *func_0037E0B8(void *);
extern s32 func_003CE740(void *,void *,s32,void *,s32);
extern s32 func_L01_003F9498(void *,s32,s32,f32);
static __inline__ void add4054(void *d,void *a,void *b){__asm__("lqc2 $vf1,%1\n\tlqc2 $vf2,%2\n\tvadd.xyz $vf1,$vf1,$vf2\n\tsqc2 $vf1,%0":"=m"(*(V_4054C8*)d):"m"(*(V_4054C8*)a),"m"(*(V_4054C8*)b):"vf1","vf2");}
static __inline__ void sub4054(void *d,void *a,void *b){__asm__("lqc2 $vf2,%2\n\tlqc2 $vf1,%1\n\tvsub.xyz $vf1,$vf1,$vf2\n\tsqc2 $vf1,%0":"=m"(*(V_4054C8*)d):"m"(*(V_4054C8*)a),"m"(*(V_4054C8*)b):"vf1","vf2");}
/* localdecomp:start func_L09_004054C8 */
void func_L09_004054C8(char *obj){
 V_4054C8 off,eye,dir,pos,old,tmp;
 V_4054C8 mat[2],a,b,c;
 char *table=*(char**)(*(char**)D_L09_001DF904+*(s16*)(obj+0x84)*32+0x1c);
 s32 idx=*(s32*)(obj+0x94),special=0;
 char *target,*data,*state,*ctx;
 f32 angle=0.0f,extra=0.0f,bias=0.0f;
 dir.q=0;dir.z=1.0f;dir.w=1.0f;
 ctx=*(char**)(D_001A4BE0+0xbf8);
 *(s32*)(ctx+0x98)=0;
 qzero(&off);
 target=*(char**)(table+0x20+idx*4);
 if(target){
  if(*(s16*)(target+0xaa)==0x107e){
   data=*(char**)(target+0x68);
   dir=*(V_4054C8*)(data+0x3c0);
   angle=*(f32*)(data+0x350);
   off=D_L09_002BBD90[0];
  }else if(*(s16*)(target+0xaa)==0x107c || *(s16*)(target+0xaa)==0x1a17){
   f32 desired=0.0f;
   data=*(char**)(target+0x68);special=1;extra=0.0f;
   state=*(char**)(data+0x6d0);
   if(*(s16*)(target+0xaa)==0x1a17){off.x=7.0f;off.y=0.0f;off.z=2.5f;off.w=1.0f;}
   else off=D_L09_002BBD80[*(s16*)(state+0x124)];
   if(*(s16*)(state+0x128)){desired=15.0f;extra=1.5f;}
   bias=0.0f;
   func_L01_00445168((f32*)(table+0x60+idx*4),(f32*)(table+0x70+idx*4),desired,0.0014544411096721888f,0.019392548128962517f,bias);
   func_L01_00445168((f32*)(table+0x80+idx*4),(f32*)(table+0x90+idx*4),extra,0.0035000001080334187f,0.1f,bias);
   extra=*(f32*)(table+0x80+idx*4);
   angle=*(f32*)(table+0x60+idx*4)*0.01745329238474369f;
   ++*(s32*)(table+0x100+idx*4);
   if(!*(u8*)(data+0x713)&&*(f32*)(*(char**)(data+0x720)+0xc)*(1.0f/60.0f)<*(f32*)(state+0x138)&&*(s32*)(table+0x100+idx*4)<50){
    if(*(s16*)(state+0x128))*(f32*)(table+0xc0+idx*4)=-1.25f;
    else *(f32*)(table+0xc0+idx*4)=-0.5f;
   }else *(f32*)(table+0xc0+idx*4)=-1.5f;
   if(*(f32*)(table+0xa0+idx*4)==D_L09_001DF7B8)*(s32*)(table+0x100+idx*4)=0;
   bias=*(f32*)(table+0xc0+idx*4);
  }
 }else target=*(char**)(D_L09_001E2C00+*(s32*)(obj+0x94)*0x460+0x240);
 pos=*(V_4054C8*)(target+0x10);
 if(special){
  func_L01_00445168((f32*)(table+0xe0+*(s32*)(obj+0x94)*4),(f32*)(table+0xf0+*(s32*)(obj+0x94)*4),pos.z,0.1111111119389534f,0.0416666679084301f,0.0f);
  pos.z=*(f32*)(table+0xe0+*(s32*)(obj+0x94)*4);
 }else *(f32*)(table+0xe0+*(s32*)(obj+0x94)*4)=pos.z;
 off.x+=extra+bias;
 data=*(char**)(obj+0x70);old=*(V_4054C8*)(obj+0x30);
 if(angle!=0.0f){
  f32 sn=func_00388978(angle),cs=func_00388960(angle);
  tmp=off;
  off.z=sn*tmp.x+cs*tmp.z;off.y=tmp.y;off.x=cs*tmp.x-sn*tmp.z;
 }
 func_003886E8(&mat[0],target+0xc0,-1.0f);
 a=dir;b=pos;
 func_00388758(&mat[1],&mat[0],&dir);
 func_00388830(&mat[1],&mat[1],1.0f);
 func_00388758(&mat[0],&a,&mat[1]);
 func_003888F0(&tmp,&off,&mat[0]);
 sub4054(&c,&tmp,&pos);
 func_003886C0(data+0x70,data+0x70,&c,0.04500000178813934f);
 dir=*(V_4054C8*)(data+0x70);
 add4054(obj+0x30,&pos,&dir);
 qzero(&eye);
 ctx=func_0037E0B8(target);
 if(ctx)func_003886E8(&eye,target+0xe0,*(f32*)(ctx+0x10));
 add4054(&eye,&eye,&pos);
 special=0;
 if(func_003CE740(&eye,obj+0x30,4,target,0)){
  if(!*(char**)(D_L09_001E9940+0x18)||*(s16*)(*(char**)(D_L09_001E9940+0x18)+0xaa)==0x1ad6){
   sub4054(&tmp,&eye,D_L09_001E9940+0x20);
   func_00388830(&dir,&tmp,0.02f);special=1;
   add4054(obj+0x30,D_L09_001E9940+0x20,&dir);
  }
 }
 if(!special && func_003CE740(&old,obj+0x30,4,0,0)){
  if(!*(char**)(D_L09_001E9940+0x18)||*(s16*)(*(char**)(D_L09_001E9940+0x18)+0xaa)==0x1ad6){
   sub4054(&tmp,&old,D_L09_001E9940+0x20);
   func_00388830(&dir,&tmp,0.02f);
   add4054(obj+0x30,D_L09_001E9940+0x20,&dir);
  }
 }
 if(func_L01_003F9498(obj+0x30,4,0,0.25f)){
  if(!*(char**)(D_L09_001E9940+0x18))*(V_4054C8*)(obj+0x30)=*(V_4054C8*)(D_L09_001E9940+0x30);
  if(*(char**)(D_L09_001E9940+0x18)&&*(s16*)(*(char**)(D_L09_001E9940+0x18)+0xaa)==0x1ad6){
   V_4054C8 push;
   func_00388830(&push,D_L09_001E9940+0x40,1.0f);
   func_003886E8(&push,&push,0.25f);
   add4054(obj+0x30,obj+0x30,&push);
  }
 }
 ctx=*(char**)(D_001A4BE0+0xbf8);
 *(s32*)(ctx+0x98)=*(s32*)(*(char**)(ctx+0x24)+0x10);
}
/* localdecomp:end func_L09_004054C8 */

/* NTSC-U draft (Codex wave 3): C of func_L05_00358B60, the NTSC-U twin of func_L05_00359C78, with NTSC-U names and addresses (the two versions' code differs).
 * near miss: 21 words differ on NTSC-U with the file's flags (NTSC-U twin "func_L05_00358B60", whose code is not the PAL one).
 * Worker's note: 21 diff; 7 checks; six float register assignments and nine argument-setup positions remain; direct calls, local transition variable and inline helper rewrites produce identical wrong bytes; constant/store reorders worsen; best log func_L05_00358B60.check01.log
 */
#include "common.h"
/* localdecomp:start func_L05_00358B60 */
typedef struct { float x,y,z,w; } __attribute__((aligned(16))) V4_358B60;
typedef int Pair_358B60 __attribute__((mode(DI)));
typedef struct Moby_358B60 Moby_358B60;
typedef struct State_358B60 State_358B60;
typedef struct { char pad[0x24]; float scale; } Model_358B60;
struct State_358B60 {
 char pad0[48];
 float f30;
 short f34;
 char pad36[3];
 unsigned char f39;
 char pad3A[4];
 unsigned char f3E;
 unsigned char f3F;
 float f40;
 char pad44[20];
 unsigned char f58;
 char pad59[1];
 unsigned char f5A;
 char pad5B[21];
 float f70;
 float f74;
 float f78;
 float f7C;
 float f80;
 char pad84[24];
 float f9C;
 float fA0;
 char padA4[4];
 int fA8;
 int fAC;
 char padB0[192];
 unsigned char f170;
 unsigned char f171;
 unsigned char f172;
 char pad173[9];
 float f17C;
 float f180;
 float f184;
 float f188;
 float f18C;
 float f190;
 float f194;
 short f198;
 char pad19A[2];
 float f19C;
 char pad1A0[8];
 unsigned char f1A8;
 unsigned char f1A9;
 char pad1AA[14];
 float f1B8;
 float f1BC;
 char pad1C0[12];
 unsigned char f1CC;
 unsigned char f1CD;
 unsigned char f1CE;
 unsigned char f1CF;
 char pad1D0[7];
 unsigned char f1D7;
 unsigned char f1D8;
 unsigned char f1D9;
 char pad1DA[1];
 unsigned char f1DB;
 int f1DC;
 char pad1E0[96];
 Moby_358B60 * f240;
 char pad244[284];
 V4_358B60 f360;
 char pad370[24];
 int f388;
 int f38C;
 char pad390[4];
 int f394;
 char pad398[4];
 int f39C;
 int f3A0;
 int f3A4;
 int f3A8;
 int f3AC;
 char pad3B0[4];
 float f3B4;
 short f3B8;
 char pad3BA[14];
 int f3C8;
 char pad3CC[14];
 short f3DA;
 char pad3DC[16];
 Moby_358B60 * f3EC;
 char pad3F0[6];
 short f3F6;
 char pad3F8[4];
 int f3FC;
 char pad400[4];
 int f404;
 char pad408[6];
 short f40E;
};
struct Moby_358B60 {
 char pad0[0x10]; V4_358B60 position;
 char pad20[4]; Model_358B60 *model;
 char pad28[4]; float scale;
 unsigned char type,active; unsigned short classid,flags;
 char pad36[2]; Pair_358B60 packed;
 char pad40[0x28]; State_358B60 *state;
 char pad6c[0x10]; short anim;
 char pad7e[0x1a]; int update;
 char pad9c[0x1c]; Moby_358B60 *parent;
 char padbc[0x34]; V4_358B60 rotation;
};
extern char *D_L05_001DF84C;
extern void func_L01_00458A70(void*,float,float,float,float);
extern Moby_358B60 *func_003BCFB0(int,int);
extern void func_003BD360(void*);
extern void func_003C26C8(void*);
extern void func_00388BD0(void*,void*);
extern void func_L05_00359D90(void*);
extern void func_L01_00441FB8(void*,int,int);
extern void func_L05_00359930(void*,int,int,int);
extern void func_L01_004A6DF8(void*,int);
extern void func_003BE4F0(void*,int,int,int);
int func_L05_00358B60(Moby_358B60 *m) {
 State_358B60 *s=m->state;
 Moby_358B60 *child;
 s->f170=6;
 s->f1A8=3;
 s->f171=16;
 s->f172=17;
 s->f190=0.6875f;
 s->f194=0.9375f;
 s->f19C=0.150000006f;
 s->f17C=0.25f;
 s->f180=0.01666666754f;
 s->f184=0.004166666884f;
 s->f188=0.01805555634f;
 s->f18C=0.000555555569f;
 s->f1DB=27;
 s->f1CD=12;
 s->f1CF=12;
 s->f1BC=0.5f;
 s->f1B8=0.200000003f;
 s->fAC=s->f404;
 s->f1DC=s->f404;
 s->f74=0.3125f;
 s->f7C=2.1875f;
 s->f80=1.658062816f;
 s->f1CC=6;
 s->f1CE=6;
 s->f70=0.6875f;
 s->f1D7=1;
 s->f1D8=0;
 s->f1D9=0;
 s->f198=0;
 s->f1A9=1;
 s->f78=1.25f;
 s->fA0=0.8726646304f;
 s->f9C=0.002722222358f;
 func_L01_00458A70(m,0.008333333768f,0.125f,0.01454441063f,0.14544411f);
 s->f58=20;
 s->f5A=14;
 if(!s->f34) {s->f34=10;s->f30=10.0f;}
 s->f3E=1;
 s->f39=0;
 s->f3F=0;
 s->f40=1.6f;
 child=func_003BCFB0(0x1610,0x80);
 s->f3EC=child;
 if(!child) {func_003BD360(m);return 1;}
 if(s->f40E)child->flags &=0xfbff;
 s->f3EC->parent=m;
 s->f3EC->position=m->position;
 s->f3EC->rotation=m->rotation;
 s->f3EC->packed=m->packed;
 func_003C26C8(s->f3EC);
 s->f3EC->classid=m->classid;
 s->f3EC->type=m->type;
 s->f3EC->flags|=0x100;
 s->f3EC->position=m->position;
 s->f3EC->rotation=m->rotation;
 func_00388BD0((char *)s->f3EC+0xc0,&s->f3EC->rotation);
 s->f240=s->f3EC;
 s->f3EC->anim=7;
 s->f3F6=1;
 m->scale=m->model->scale*1.25f;
 s->f3EC->scale=s->f3EC->model->scale*1.25f;
 if(s->f38C!=-1) {
  char *p=D_L05_001DF84C+s->f38C*0x30;
  if(*(short *)(p+0x32)==1) {
   int value=**(int **)(p+0x40);
   s->f38C=-1;
   s->f388=value;
  }
 }
 func_L05_00359D90(m);
 if(s->f3B8) {
  s->f360=m->position;
  s->f3B4=m->rotation.z;
  func_L01_00441FB8(m,7,4);
 } else if(s->f3A4!=-1) {
  func_L01_00441FB8(m,3,4);
 } else if(s->f3A8!=-1) {
  if(s->f3AC) {
   func_L01_00441FB8(m,4,4);
   s->f3EC->flags|=2;
   s->f3EC->flags|=4;
  } else {
   func_L01_00441FB8(m,5,4);
   s->f39C=0;
  }
 } else {
  if(!s->f3A0)goto hidden;
  func_L01_00441FB8(m,7,0);
  func_L05_00359930(m,2,0,0);
 }
 m->update=0;
 m->flags=(m->flags|0x41)&0xefff;
 func_L01_004A6DF8(m,1);
 s->f3EC->flags|=0x41;
 s->f3EC->flags&=0xefff;
 s->f3EC->update=0;
 func_L01_004A6DF8(s->f3EC,1);
 s->f3EC->flags|=2;
 s->f3EC->flags|=4;
 goto configured;
hidden:
 func_L01_00441FB8(m,1,0);
 func_L05_00359930(m,0,0,0);
configured:
 if(s->f3C8) {
  m->update=0;
  m->flags=(m->flags|0x41)&0xefff;
  func_L01_004A6DF8(m,1);
  s->f3EC->flags|=0x41;
  s->f3EC->flags&=0xefff;
  s->f3EC->update=0;
  func_L01_004A6DF8(s->f3EC,1);
  m->flags|=6;
  s->f3EC->flags|=2;
  s->f3EC->flags|=4;
 }
 if(s->f3DA) {
  s->fA8|=4;
  s->f78=0.7f;
  s->f7C=0.7f;
  m->flags|=0x100;
  s->f80=12.566371f;
  s->fA8|=1;
 }
 if(s->f3FC) {
  s->f394=1;
  s->f1BC=1.0f;
  s->f1B8=0.2f;
  func_003BE4F0(m,19,0,0);
  func_003BE4F0(s->f3EC,2,0,0);
  func_003BE4F0(m,19,0,1);
  func_003BE4F0(s->f3EC,2,0,1);
  s->fA8|=0x414;
 }
 return 0;
}
/* localdecomp:end func_L05_00358B60 */

/* PAL port (Promises, 2026-11-21, task #2810) of the NTSC-U draft above: 19 differences (tools/check.py, level 05)
 * with its file's flags and context (395 for the plain port). Callees moved to PAL by call order (func_L01_0045BD78,
 * func_003C24B0, func_003C2880, func_003C7C38, func_0038D308, func_L05_0035AEC8, func_L01_004450F0,
 * func_L05_0035AA68, func_L01_004AA7E8, func_003C3A10; table D_L05_001DF7CC), PAL's 50 Hz constants, and one
 * statement NTSC-U does not have: s->f3C0 = (s->f3C0 * 5 + 2) / 6. A statement-order hill-climb over the 34
 * initialising stores took it from 60 to 36 (2026-11-21). 2026-11-22 (task #2933, on 45baf7e5): the declarations
 * that PR #132's func_L05_003560C8 block gives the file (D_L05_001DF7CC as u8 *, func_L01_0045BD78,
 * func_L01_004AA7E8 and func_L05_0035AEC8 with Mo_60C8 *, func_L05_0035AA68 K&R) are used here, so the block
 * compiles in its file (casts to Mo_60C8 * at the four calls); a further climb over the same statements, now with
 * the division among them, took it from 36 to 19 (seven seeds, about 5,000 compiles; the last two seeds,
 * 1,400 compiles, found nothing below 19). Still differs: the order of the first constant loads and stores (10),
 * and the argument-setup order before three calls (9: retail sets $a2 = 4 in the beqz delay slot for both of the
 * first two func_L01_004450F0 calls, and $a2/$a3 before $a0/$a1 for func_L05_0035AA68(m, 2, 0, 0)), which the
 * NTSC-U draft also has; a named-constant local for the 4, locals for the zeros and the a0 parameter in place of
 * m give the same 19 bytes. 2026-11-23 (task #2966, upstream bbf261a1): still 19. gcc's -da dumps: the moves are
 * expanded in parameter order and keep it through sched1 and sched2 (they tie), so reorg puts `move $a0` into the
 * beqz delay slot where retail has `addiu $a2, $zero, 4`; a prototype for func_L05_0035AA68, a block-local
 * prototype for func_L01_004450F0, (s32)0 casts and a call through a function pointer all give 19.
 * CLOSEOUT attempt 1 of 2 (task #3035, upstream 242c17bd): still 19 at levels 05, 10, 14 and 17. -fsched-verbose-5
 * shows the three argument moves before the f3B8 call tie in sched1 and sched2 (prio 3, one dependent, the call),
 * so LUID decides and they keep the expand order a0, a1, a2; retail's order (a2 first, then a2/a3 before a0/a1 for
 * func_L05_0035AA68) needs the a2/a3 moves created first. These give the same bytes (19): a static inline wrapper
 * (m, st) for each of the two callees, a local for the 4 in the f3B8 block, an alias local for m in that block, and
 * both callees declared s32 under suffix aliases with the result kept in a local. */
/* localdecomp:start func_L05_00359C78 */
typedef struct { float x,y,z,w; } __attribute__((aligned(16))) V4_359C78;
typedef int Pair_359C78 __attribute__((mode(DI)));
typedef struct Moby_359C78 Moby_359C78;
typedef struct State_359C78 State_359C78;
typedef struct { char pad[0x24]; float scale; } Model_359C78;
struct State_359C78 {
 char pad0[48];
 float f30;
 short f34;
 char pad36[3];
 unsigned char f39;
 char pad3A[4];
 unsigned char f3E;
 unsigned char f3F;
 float f40;
 char pad44[20];
 unsigned char f58;
 char pad59[1];
 unsigned char f5A;
 char pad5B[21];
 float f70;
 float f74;
 float f78;
 float f7C;
 float f80;
 char pad84[24];
 float f9C;
 float fA0;
 char padA4[4];
 int fA8;
 int fAC;
 char padB0[192];
 unsigned char f170;
 unsigned char f171;
 unsigned char f172;
 char pad173[9];
 float f17C;
 float f180;
 float f184;
 float f188;
 float f18C;
 float f190;
 float f194;
 short f198;
 char pad19A[2];
 float f19C;
 char pad1A0[8];
 unsigned char f1A8;
 unsigned char f1A9;
 char pad1AA[14];
 float f1B8;
 float f1BC;
 char pad1C0[12];
 unsigned char f1CC;
 unsigned char f1CD;
 unsigned char f1CE;
 unsigned char f1CF;
 char pad1D0[7];
 unsigned char f1D7;
 unsigned char f1D8;
 unsigned char f1D9;
 char pad1DA[1];
 unsigned char f1DB;
 int f1DC;
 char pad1E0[96];
 Moby_359C78 * f240;
 char pad244[284];
 V4_359C78 f360;
 char pad370[24];
 int f388;
 int f38C;
 char pad390[4];
 int f394;
 char pad398[4];
 int f39C;
 int f3A0;
 int f3A4;
 int f3A8;
 int f3AC;
 char pad3B0[4];
 float f3B4;
 short f3B8;
 char pad3BA[6];
 int f3C0;
 char pad3C4[4];
 int f3C8;
 char pad3CC[14];
 short f3DA;
 char pad3DC[16];
 Moby_359C78 * f3EC;
 char pad3F0[6];
 short f3F6;
 char pad3F8[4];
 int f3FC;
 char pad400[4];
 int f404;
 char pad408[6];
 short f40E;
};
struct Moby_359C78 {
 char pad0[0x10]; V4_359C78 position;
 char pad20[4]; Model_359C78 *model;
 char pad28[4]; float scale;
 unsigned char type,active; unsigned short classid,flags;
 char pad36[2]; Pair_359C78 packed;
 char pad40[0x28]; State_359C78 *state;
 char pad6c[0x10]; short anim;
 char pad7e[0x1a]; int update;
 char pad9c[0x1c]; Moby_359C78 *parent;
 char padbc[0x34]; V4_359C78 rotation;
};
extern Moby_359C78 *func_003C24B0(int,int);
extern void func_003C7C38(void*);
extern void func_0038D308(void*,void*);
s32 func_L05_00359C78(u8 *a0) {
 Moby_359C78 *m=(Moby_359C78 *)a0;
 State_359C78 *s=m->state;
 Moby_359C78 *child;
 s->f1A8=3;
 s->f3C0=(s->f3C0*5+2)/6;
 s->f171=16;
 s->f1CE=6;
 s->f1D7=1;
 s->f190=0.6875f;
 s->fAC=s->f404;
 s->f194=0.9375f;
 s->f1D8=0;
 s->f17C=0.30000001192092896f;
 s->f180=0.020000001415610313f;
 s->f184=0.006000000052154064f;
 s->f172=17;
 s->f188=0.026000000536441803f;
 s->f18C=0.000800000037997961f;
 s->f1D9=0;
 s->f198=0;
 s->f1DB=27;
 s->f1BC=0.5f;
 s->f1A9=1;
 s->f1CC=6;
 s->f1CD=12;
 s->f1CF=12;
 s->f1B8=0.200000003f;
 s->f78=1.25f;
 s->f19C=0.150000006f;
 s->f170=6;
 s->f1DC=s->f404;
 s->f70=0.6875f;
 s->f74=0.3125f;
 s->f7C=2.1875f;
 s->f80=1.658062816f;
 s->fA0=0.8726646304f;
 s->f9C=0.003920000046491623f;

 func_L01_0045BD78((Mo_60C8 *)m,0.012000000104308128f,0.15000000596046448f,0.020943952724337578f,0.1745329350233078f);
 s->f58=20;
 s->f5A=14;
 if(!s->f34) {s->f34=10;s->f30=10.0f;}
 s->f3E=1;
 s->f39=0;
 s->f3F=0;
 s->f40=1.6f;
 child=func_003C24B0(0x1610,0x80);
 s->f3EC=child;
 if(!child) {func_003C2880(a0);return 1;}
 if(s->f40E)child->flags &=0xfbff;
 s->f3EC->parent=m;
 s->f3EC->position=m->position;
 s->f3EC->rotation=m->rotation;
 s->f3EC->packed=m->packed;
 func_003C7C38(s->f3EC);
 s->f3EC->classid=m->classid;
 s->f3EC->type=m->type;
 s->f3EC->flags|=0x100;
 s->f3EC->position=m->position;
 s->f3EC->rotation=m->rotation;
 func_0038D308((char *)s->f3EC+0xc0,&s->f3EC->rotation);
 s->f240=s->f3EC;
 s->f3EC->anim=7;
 s->f3F6=1;
 m->scale=m->model->scale*1.25f;
 s->f3EC->scale=s->f3EC->model->scale*1.25f;
 if(s->f38C!=-1) {
  u8 *p=D_L05_001DF7CC+s->f38C*0x30;
  if(*(short *)(p+0x32)==1) {
   int value=**(int **)(p+0x40);
   s->f38C=-1;
   s->f388=value;
  }
 }
 func_L05_0035AEC8((Mo_60C8 *)m);
 if(s->f3B8) {
  s->f360=m->position;
  s->f3B4=m->rotation.z;
  func_L01_004450F0(m,7,4);
 } else if(s->f3A4!=-1) {
  func_L01_004450F0(m,3,4);
 } else if(s->f3A8!=-1) {
  if(s->f3AC) {
   func_L01_004450F0(m,4,4);
   s->f3EC->flags|=2;
   s->f3EC->flags|=4;
  } else {
   func_L01_004450F0(m,5,4);
   s->f39C=0;
  }
 } else {
  if(!s->f3A0)goto hidden;
  func_L01_004450F0(m,7,0);
  func_L05_0035AA68(m,2,0,0);
 }
 m->update=0;
 m->flags=(m->flags|0x41)&0xefff;
 func_L01_004AA7E8((Mo_60C8 *)m,1);
 s->f3EC->flags|=0x41;
 s->f3EC->flags&=0xefff;
 s->f3EC->update=0;
 func_L01_004AA7E8((Mo_60C8 *)s->f3EC,1);
 s->f3EC->flags|=2;
 s->f3EC->flags|=4;
 goto configured;
hidden:
 func_L01_004450F0(m,1,0);
 func_L05_0035AA68(m,0,0,0);
configured:
 if(s->f3C8) {
  m->update=0;
  m->flags=(m->flags|0x41)&0xefff;
  func_L01_004AA7E8((Mo_60C8 *)m,1);
  s->f3EC->flags|=0x41;
  s->f3EC->flags&=0xefff;
  s->f3EC->update=0;
  func_L01_004AA7E8((Mo_60C8 *)s->f3EC,1);
  m->flags|=6;
  s->f3EC->flags|=2;
  s->f3EC->flags|=4;
 }
 if(s->f3DA) {
  s->fA8|=4;
  s->f78=0.7f;
  s->f7C=0.7f;
  m->flags|=0x100;
  s->f80=12.566371f;
  s->fA8|=1;
 }
 if(s->f3FC) {
  s->f394=1;
  s->f1BC=1.0f;
  s->f1B8=0.2f;
  func_003C3A10(m,19,0,0);
  func_003C3A10(s->f3EC,2,0,0);
  func_003C3A10(m,19,0,1);
  func_003C3A10(s->f3EC,2,0,1);
  s->fA8|=0x414;
 }
 return 0;
}
/* localdecomp:end func_L05_00359C78 */

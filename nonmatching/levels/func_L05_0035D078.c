/* NTSC-U draft (2026-11-14, Codex worker): C of func_L05_0035BEB0, the NTSC-U twin of func_L05_0035D078, with NTSC-U names
 * and addresses. Near miss on NTSC-U: 10 words differ with its file's flags.
 */
#include "common.h"
/* localdecomp:start func_L05_0035BEB0 */
typedef int Q_BEB0 __attribute__((mode(TI)));
typedef struct {
 u8 pad000[0x30];
 float f030;
 s16 f034;
 u8 pad036[0x3];
 u8 f039;
 u8 pad03a[0x4];
 u8 f03e;
 u8 f03f;
 float f040;
 u8 pad044[0x14];
 u8 f058;
 u8 pad059[0x1];
 u8 f05a;
 u8 pad05b[0x15];
 float f070;
 float f074;
 float f078;
 float f07c;
 float f080;
 u8 pad084[0x18];
 float f09c;
 float f0a0;
 u8 pad0a4[0xcc];
 u8 f170;
 u8 f171;
 u8 f172;
 u8 pad173[0x3];
 u8 f176;
 u8 pad177[0x5];
 float f17c;
 float f180;
 float f184;
 float f188;
 float f18c;
 float f190;
 float f194;
 s16 f198;
 u8 pad19a[0x2];
 float f19c;
 u8 pad1a0[0x8];
 u8 f1a8;
 u8 f1a9;
 u8 pad1aa[0xe];
 float f1b8;
 float f1bc;
 u8 pad1c0[0xc];
 u8 f1cc;
 u8 f1cd;
 u8 f1ce;
 u8 f1cf;
 u8 pad1d0[0x2];
 u8 f1d2;
 u8 f1d3;
 u8 pad1d4[0x3];
 u8 f1d7;
 u8 f1d8;
 u8 f1d9;
 u8 f1da;
 u8 f1db;
 u8 pad1dc[0x1c4];
 s32 f3a0;
 u8 pad3a4[0xc];
 Q_BEB0 f3b0;
} Data_BEB0;
extern float D_001DD7F0_sda;
__asm__(".extern D_001DD7F0_sda, 4");
extern void func_L01_00458A70(void *,float,float,float,float);
extern void func_L01_00441FB8(void *,int,int);
extern void func_003BE4F0(void *,int,int,int);
s32 func_L05_0035BEB0(u8 *m) {
 float half_time=0.5f, short_time=0.20000000298023224f, long_time=0.4000000059604645f;
 Data_BEB0 *d=*(Data_BEB0 **)(m+0x68);
 d->f170=13;
 d->f171=10;
 d->f172=11;
 d->f17c=0.2666666805744171f;
 d->f180=0.10000000894069672f;
 d->f184=0.006111111491918564f;
 d->f188=0.010277777910232544f;
 d->f18c=0.011111111380159855f;
 d->f1a8=3;
 d->f176=12;
 d->f1cd=12;
 d->f1d8=3;
 d->f1cf=12;
 d->f1d9=3;
 d->f194=d->f190=half_time;
 d->f1ce=d->f1cc=6;
 d->f1d2=8;
 d->f1d3=15;
 d->f1da=2;
 d->f1db=17;
 d->f1bc=d->f19c=long_time;
 d->f070=0.699999988079071f;
 d->f074=d->f1b8=short_time;
 d->f078=0.75f;
 d->f1d7=0;
 d->f198=0;
 d->f1a9=1;
 d->f07c=1.0f;
 d->f080=1.483529806137085f;
 d->f0a0=0.3490658402442932f;
 d->f09c=0.0027222223579883575f;
 func_L01_00458A70(m,0.006666666828095913f,0.125f,0.0069813174195587635f,0.20943953096866608f);
 d->f058=20; d->f05a=14;
 d->f3b0=*(Q_BEB0 *)(m+0x10);
 if(d->f034==0) { d->f034=8; d->f030=8.0f; }
 d->f039=1; d->f03e=1; d->f03f=0; d->f040=1.0f;
 *(float *)(m+0x2c)*=D_001DD7F0_sda;
 func_L01_00441FB8(m,1,0);
 if(m[0x43]) func_003BE4F0(m,0,0,0);
 if(d->f3a0!=-1) {
  func_L01_00441FB8(m,2,-1);
  if(m[0x43]!=3) func_003BE4F0(m,3,0,0);
 }
 return 0;
}
/* localdecomp:end func_L05_0035BEB0 */

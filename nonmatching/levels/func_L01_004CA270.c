/* PAL near miss (Codex wave 6): near miss: 16 words differ with the file's flags.
 * Worker's note: 16 diff in final quadword-copy/register-allocation block; best w288/func_L01_004CA270.05.log; three alternative copy wordings reproduce same 17-diff variant
 */
#include "common.h"
/* localdecomp:start func_L01_004CA270 */
typedef int Q_004CA270 __attribute__((mode(TI)));
typedef struct {u8 pad[8];s32 slot;u8 pC[4];s32 id;u8 p14[0xF0-0x14];} R_004CA270;
typedef struct { f32 x,y,z,w; } __attribute__((aligned(16))) V_004CA270;
typedef struct { u8 p[0x1200];s32 parts[7][20];u8 gap[0x2614-0x1430];s32 slots[7]; } H_004CA270;
extern short D_L01_001E110A;
extern Ent_004C4F88 D_L01_002C5600[];
extern S_4C4A18 D_001A4BE0;
extern s32 D_001D4C40[];
u8 *func_L01_004CA270(u8 *old) {
 extern void func_L01_004C99A0(void);
 extern void func_003C2880(void *);
 extern s32 func_0039AC08(s32);
 extern void func_0039AA38(s32);
 extern void func_003A2750(s32);
 extern void func_L01_0042D110(s32);
 extern u8 *func_L01_004C98A8(s32,s32,s32);
 s32 item=D_L01_001E110A;
 V_004CA270 pos,rot;
 u8 *m;
 Q_004CA270 q;
 *(Q_004CA270 *)&pos=*(Q_004CA270 *)(old+0x10);
 *(Q_004CA270 *)&rot=*(Q_004CA270 *)(old+0xF0);
 if(item==0xA7 || item==0xC0 || item==0xC1 || item==0xC2 || item==0xC3 || item==0xC4 || item==0xC5)func_L01_004C99A0();
 else {
  R_004CA270 *r;
  func_003C2880(old);
  r=&((R_004CA270 *)D_L01_002C5600)[item];
  if(!func_0039AC08(r->id)) {func_0039AA38(r->id);func_003A2750(1);}
  func_L01_0042D110(r->id);
 }
 if((u32)(item-0x57)<8)m=func_L01_004C98A8(0x1ADA,0,0);
 else m=func_L01_004C98A8(((R_004CA270 *)D_L01_002C5600)[item].id,-1,0);
 if(m) {
  s32 slot;
  q=*(Q_004CA270 *)&pos;
  *(Q_004CA270 *)(m+0x10)=q;
  q=*(Q_004CA270 *)&rot;
  *(Q_004CA270 *)(m+0xF0)=q;
  slot=((R_004CA270 *)D_L01_002C5600)[item].slot;
  D_001D4C40[slot]=0;
  (*(H_004CA270 *)&D_001A4BE0).parts[slot][0]=0;
  (*(H_004CA270 *)&D_001A4BE0).slots[slot]=0;
 }
 return m;
}
/* localdecomp:end func_L01_004CA270 */

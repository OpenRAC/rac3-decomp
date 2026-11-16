/* NTSC-U draft (Codex wave 3): C of func_L01_003A2A38, the NTSC-U twin of func_L01_003A4180, with NTSC-U names and addresses (the two versions' code differs).
 * near miss: 55 words differ on NTSC-U with the file's flags (NTSC-U twin "func_L01_003A2A38", whose code is not the PAL one).
 * Worker's note: 55 diff; confirmed allowed-flags inline-literal assembler blocker: 0.03f and 0.3f emit lwc1 gp rather than retail lui/ori/mtc1; allocation also differs; best log w120/func_L01_003A2A38.01.log
 */
#include "common.h"
/* localdecomp:start func_L01_003A2A38 */
typedef int Q_A2A38 __attribute__((mode(TI)));
typedef struct Object_A2A38 Object_A2A38;
struct Object_A2A38 {
 u8 pad0[0x20]; u8 state; u8 pad21[0x68-0x21]; u8 *vars;
 u8 pad6c[0x96-0x6C]; u16 counter; int token;
 u8 pad9c[0xAA-0x9C]; short type; u8 padac[0xB8-0xAC];
 Object_A2A38 *parent;
};
extern void func_003BDA38(void *,int,void *);
extern void func_003C26C8(void *);
extern void func_L01_0044B5C8(void *,void *,int,float,float);
extern int func_00388398(void *);
extern int func_003883C8(void *);
extern void func_L01_0044EB78(void *,void *,int,int,float);
void func_L01_003A2A38(Object_A2A38 *obj) {
 Q_A2A38 pos;
 u8 *p=obj->vars;
 Object_A2A38 **slot=(Object_A2A38 **)(p+0x2F0);
 int i;
 for(i=0;i<2;i++,slot++) {
  Object_A2A38 *child=*slot;
  if(child && child->type==0x1939 && child->parent==obj && child->state!=254 && child->state!=253) {
   u8 *v=child->vars;
   if(i)func_003BDA38(obj,3,&pos);
   else func_003BDA38(obj,2,&pos);
   *(Q_A2A38 *)(v+0x20)=pos;
  } else *slot=0;
 }
 slot=(Object_A2A38 **)(p+0x3F0);
 for(i=7;i>=0;i--,slot++) {
  if(*slot) {
   (*slot)->token=0;
   func_003C26C8(*slot);
  }
 }
 func_L01_0044B5C8(obj,p+0x300,4,0.03f,0.3f);
 func_00388398(p+0x2E0);
 func_003883C8(p+0x2E4);
 if(obj->counter<65535)obj->counter++;
 func_L01_0044EB78(obj,p+0x250,5,1,2.5f);
}
/* localdecomp:end func_L01_003A2A38 */

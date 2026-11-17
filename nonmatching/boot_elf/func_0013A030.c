/* PAL near miss (Codex wave 7): near miss: 5 words differ with the file's flags.
 * Worker's note: 5 instruction differences, size unchanged; build/codex/w376/13A030-07.log. Improved initial command from prior 7 diffs while preserving file s32 callee signatures. Remaining +0x34/+0x3C/+0x40/+0x44/+0x48: second-command scheduling/register allocation. Three ...
 */
#include "common.h"
/* localdecomp:start func_0013A030 */
typedef struct Device_0013A030 { u8 pad[0x868]; s32 handle; } Device_0013A030;
extern char D_00152240[];
void func_0013A030(void *s)
{
 extern s32 func_0013A0F8();
 extern s32 func_00135D50(s32,s32 *);
 extern s32 func_00124920(void);
 extern s32 func_00124970(void);
 struct {s32 value;u8 pad[28];} command;
 Device_0013A030 *device=s;
 s32 state;
 s32 first_handle;
 if (func_0013A0F8(s,(s32)D_00152240)) {
  first_handle=device->handle;
  command.value=2;
 } else {
  first_handle=device->handle;
  command.value=2;
 }
 func_00135D50(first_handle,&command.value);
 {volatile u32 *ipu_ctrl=(u32 *)0x10002010;
 s32 handle=device->handle;
 *ipu_ctrl=0x40000000;
 command.value=3;
 func_00135D50(handle,&command.value);}
 state=func_00124920();
 {volatile u32 *d_enable_r=(u32 *)0x1000F520;
 volatile u32 *d_enable_w=(u32 *)0x1000F590;
 volatile u32 *d_ipu_from_chcr=(u32 *)0x1000B000;
 *d_enable_w=*d_enable_r|0x10000;
 *d_ipu_from_chcr=0;
 *d_enable_w=*d_enable_r&~0x10000;}
 if(state)func_00124970();
 {volatile u32 *d_ipu_from_qwc=(u32 *)0x1000B020; *d_ipu_from_qwc=0;}
}
/* localdecomp:end func_0013A030 */

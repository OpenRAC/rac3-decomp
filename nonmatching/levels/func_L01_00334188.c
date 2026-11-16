/* PAL near miss (Codex wave 8): near miss: 16 words differ with the file's flags.
 * Worker's note: 16 diff in w382/func_L01_00334188.04.log: level index a2/v1 and byte/flag temporaries swapped; inline ternary, explicit index local and integer table-address formulations produced identical wrong bytes
 */
#include "common.h"
/* localdecomp:start func_L01_00334188 */
extern s32 D_001D545C;
extern u8 D_0014275B;
extern f32 D_L01_001DAA30 __attribute__((section(".sdata")));
extern f32 D_L01_001DAA38 __attribute__((section(".sdata")));
extern f32 D_L01_002F1510[], D_L01_002F16F0[];
void func_L01_00334188(u8 *cfg,u8 *out) {
 s32 n;
 s32 level=D_001D545C;
 if(*(s8 *)(cfg+0x8e)!=-1) {
  *(s16 *)(out+0x34)=(s32)((f32)*(s8 *)(cfg+0x8e)*(level==7 && D_0014275B ? D_L01_001DAA30 : *(f32 *)((level<<2)+(s32)D_L01_002F1510)));
  *(f32 *)(out+0x30)=*(s8 *)(cfg+0x8e);
 }
 level=D_001D545C;
 n=(s32)(*(f32 *)(cfg+0x80)*(level==7 && D_0014275B ? D_L01_001DAA38 : *(f32 *)((level<<2)+(s32)D_L01_002F16F0)));
 if(n>255) n=255;
 out[0x44]=n;
}
/* localdecomp:end func_L01_00334188 */

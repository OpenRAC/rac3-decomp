/* PAL near miss: 21 diff, all register-only.
 * The instruction stream is identical to retail (same opcodes, same store
 * order, same delay slots); five block-local values sit in other registers
 * (hi(D_L01_001E64C0) t1/v1, counter a3/t0, old D_L01_001E1070 v1/a3,
 * 0x60000 t0/t1, base of D_L01_001EA940 v0/v1) and one pair of adjacent
 * addu's is swapped.  Nine formulations (struct pointer, s32*, u8* offsets,
 * H_003FE938 struct members, named intermediates/constants, named counter,
 * reordered statements, unsized externs) either compile to the same bytes or
 * to a worse store order.
 */
#include "common.h"
/* localdecomp:start func_L01_003FE938 */
extern s32 D_L01_001DF948;
extern s32 D_L01_001EA940[];
extern s32 D_L01_001E1070;
extern s32 D_001E1070_sda;
__asm__(".extern D_001E1070_sda, 4");
typedef struct { s32 start,end,limit,records,count,extra,result; } State_003FE938;
extern s32 D_L01_001E64C0[];
extern s32 D_L01_001D66A4;
extern s32 D_001D4BB4;
extern f32 D_L01_001DF950;
void func_L01_003FE938(void) {
 extern void func_003A92F0(s32);
 extern void func_0012C908(s32);
 extern void func_003A9108(void);
 extern void func_003A5430(void);
 State_003FE938 *p;
 func_003A92F0(1);
 func_0012C908(0);

 p = (State_003FE938 *)D_L01_001E64C0;
 D_L01_001DF948++;
 p->extra = D_L01_001E1070 - 0x60000;
 p->start = D_L01_001EA940[3] + 0x60000;
 p->end = D_L01_001EA940[4] + 0x60000;
 p->limit = p->start + 0xD0800;
 D_L01_001D66A4 = 0x2000;
 D_001E1070_sda = 0x60000;
 func_003A9108();
 func_003A5430();
 p->result = D_001D4BB4;
 D_L01_001DF950 = 1.0f;
}
/* localdecomp:end func_L01_003FE938 */

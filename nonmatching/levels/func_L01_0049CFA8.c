/* Near miss (b9-t1): 7 words differ (the idx/product registers of the loop's second half: retail keeps the  index in  and the product in ).
 * Needs L01_0049CF68.c's E_4999A0 typedef changed to:
 *   typedef struct { s32 w0; s32 w4; s32 w8; s32 *list; s32 state; u8 flag; u8 pad15[3]; } E_4999A0;
 * and func_003B9BD0 / func_003B9C58 declared (s32) as in the file's func_L01_0049D200.
 */
#include "common.h"
/* localdecomp:start func_L01_0049CFA8 */
extern s32 D_L01_001D9474;
extern s32 D_L01_001D9478;
extern u8 D_001EA7C0[];
extern E_4999A0 D_L01_002EC368[];
extern s32 func_003B9BD0(s32);
extern s32 func_003B9C58(s32);
extern void func_00392B20(u8 *, s32);
void func_L01_0049CFA8(void) {
    s32 i = 0;
    s32 st;
    if (D_L01_002EC368[D_L01_001D9478].flag != 0) {
        st = D_L01_002EC368[D_L01_001D9478].state;
        if (st != 1) {
            if (st < 2) {
                if (st == 0) {
            D_L01_001D9474 = func_003B9C58(func_003B9BD0(0));
            func_00392B20(D_001EA7C0, (s32)D_L01_002EC368[D_L01_001D9478].list);
            func_L01_0049CF68();
                }
            }
        } else {
            D_L01_001D9474 = func_003B9C58(func_003B9BD0(0));
            if (D_L01_002EC368[D_L01_001D9478].list[0] != 0) {
                do {
                    func_00392B20(D_001EA7C0, D_L01_002EC368[D_L01_001D9478].list[i]);
                    i++;
                } while (D_L01_002EC368[D_L01_001D9478].list[i] != 0);
            }
            func_L01_0049CF68();
        }
    }
}
/* localdecomp:end func_L01_0049CFA8 */

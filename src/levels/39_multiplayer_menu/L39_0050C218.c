#include "common.h"

/* localdecomp:start func_L39_0050C218 */
extern s8 D_L39_00453D68[];

s8 *func_L39_0050C218(void) {
    return (D_L39_00453D68[0] == 0) ? 0 : D_L39_00453D68;
}
/* localdecomp:end func_L39_0050C218 */

/* localdecomp:start func_L39_0050C230 */
extern s8 D_L39_00453D68[];
extern void func_L30_003C2D78(int, int, s8 *);
void func_L39_0050C230(int a0, int a1, s8 *a2)
{
    if (!a2) {
        a2 = D_L39_00453D68[0] ? D_L39_00453D68 : 0;
    }
    func_L30_003C2D78(a0, a1, a2);
}
/* localdecomp:end func_L39_0050C230 */

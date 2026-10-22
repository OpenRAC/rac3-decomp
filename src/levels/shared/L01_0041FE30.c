#include "common.h"

/* localdecomp:start func_L01_0041FE30 */
extern void func_L01_0041C9E8(void);
extern s32 D_L01_001D69F8;
extern s32 D_L01_001D6A00[];
extern s32 D_L01_001D69FC[];
void func_L01_0041FE30(void) {
    func_L01_0041C9E8();
    D_L01_001D69F8 = 1;
    D_L01_001D6A00[0] = -1;
    D_L01_001D69FC[0] = 0;
}
/* localdecomp:end func_L01_0041FE30 */

/* localdecomp:start func_L01_0041FE68 */
extern s32 D_L01_001D69F8;

void func_L01_0041FE68(void) {
    if (D_L01_001D69F8 != 0) {
        D_L01_001D69F8 -= 1;
    }
}
/* localdecomp:end func_L01_0041FE68 */
